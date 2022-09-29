#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Thinary_AHT10.h>
#include <Bounce2.h>
#include <BMI160Gen.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define NUMFLAKES     10 // Number of snowflakes in the animation example

#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16

AHT10Class AHT10;

Bounce button1 = Bounce();

Bounce button2 = Bounce();

void setup() {
  Serial.begin(9600);

  BMI160.begin(BMI160GenClass::I2C_MODE, 0x69); // Begin I2C mode and refer to the memory location

  // Set the accelerometer range to 250 degrees/second
  BMI160.setGyroRange(250);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }

  Wire.begin();
  if (AHT10.begin(eAHT10Address_Low))
    Serial.println("Init AHT10 Sucess.");
  else
    Serial.println("Init AHT10 Failure.");

  // Setup the first button with an internal pull-up :
  pinMode(4, INPUT_PULLUP);
  // After setting up the button, setup the Bounce instance :
  button1.attach(4);
  button1.interval(10);// interval in ms


  // Setup the first button with an internal pull-up :
  pinMode(5, INPUT_PULLUP);
  // After setting up the button, setup the Bounce instance :
  button2.attach(5);
  button2.interval(10); // interval in ms

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.clearDisplay();
  display.display();
}

void writeString(char* text) {
  char* c = text;
  while (*c) {
    display.write(*c);
    c++;
  }
}

void writeFloatString(float n) {
  char buffer[128];
  dtostrf(n, 4, 2, buffer);
  writeString(buffer);
}

void loop() {

  display.clearDisplay();

  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(WHITE); // Draw white text
  display.setCursor(0, 0);     // Start at top-left corner
  display.cp437(true);         // Use full 256 char 'Code Page 437' font

  int count = 0;

  int gxRaw, gyRaw, gzRaw;         // initalize variables to store raw gyro values
  float gx, gy, gz;
  float x, y, z;

#define NUMBER_OF_STATES 3
  int state = 0;

  while (1) {

    button1.update();
    button2.update();

    if (button1.fell()) {
      state = state + 1;
      if (state >= NUMBER_OF_STATES) {
        state = NUMBER_OF_STATES - 1;
      }
      Serial.println(state);
    }

    if (button2.fell()) {
      state = state - 1;
      if (state <  0) {
        state = 0;
      }
      Serial.println(state);
    }

    if (count == 0) {
      display.clearDisplay();
      display.setCursor(0, 0);


      switch (state) {
        case 0: {
            float temperature = AHT10.GetTemperature();
            writeString("TEMPERATURE = ");
            writeFloatString(temperature);

            display.setCursor(0, 12);

            float humidity = AHT10.GetHumidity();
            writeString("HUMIDITY = ");
            writeFloatString(humidity);
          };
          break;

        case 1: {

            // read raw gyro measurements from device
            BMI160.readGyro(gxRaw, gyRaw, gzRaw);

            // convert the raw gyro data to degrees/second
            gx = convertRawGyro(gxRaw);
            gy = convertRawGyro(gyRaw);
            gz = convertRawGyro(gzRaw);

            writeString("gX = ");
            writeFloatString(gx);

            display.setCursor(0, 12);
            writeString("gY = ");
            writeFloatString(gy);

            display.setCursor(0, 24);
            writeString("gZ = ");
            writeFloatString(gz);

            delay(100);
          };
          break;

        case 2: {
            x = convertRawAcc(BMI160.getAccelerationX());
            writeString("aX = ");
            writeFloatString(x);

            display.setCursor(0, 12);
            y = convertRawAcc(BMI160.getAccelerationY());
            writeString("aY = ");
            writeFloatString(y);

            display.setCursor(0, 24);
            z = convertRawAcc(BMI160.getAccelerationZ());
            writeString("aZ = ");
            writeFloatString(z);

            delay(100);
          };
          break;
      }

      display.display();
    }
    count = (count + 1) % 100;

  }

}


float convertRawGyro(int gRaw) {
  // since we are using 250 degrees/seconds range
  // -250 maps to a raw value of -32768
  // +250 maps to a raw value of 32767

  float g = (gRaw * 250.0) / 32768.0;

  return g;
}

float convertRawAcc(int aRaw) {

  float g = aRaw * 0.061 / 1000.0;

  return g;
}
