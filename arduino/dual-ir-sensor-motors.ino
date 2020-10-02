// Sensor pins
const int sensor1 = 1;
const int sensor2 = 2;

// Left motor pins
const int PWM_L = 6;
const int IN1_L = 7;
const int IN2_L = 8;

// Right motor pins
const int PWM_R = 11;
const int IN1_R = 9;
const int IN2_R = 10;

void rr(){
  digitalWrite(IN1_R, HIGH);
  digitalWrite(IN2_R, LOW);
}
void rl(){
  digitalWrite(IN1_R, LOW);
  digitalWrite(IN2_R, HIGH);
}
void lr(){
  digitalWrite(IN1_L, LOW);
  digitalWrite(IN2_L, HIGH);
}
void ll(){
  digitalWrite(IN1_L, HIGH);
  digitalWrite(IN2_L, LOW);
}

void setup() {
  // Sensors
  pinMode(sensor1, INPUT); 
  pinMode(sensor2, INPUT); 
  
  // Left motor
  pinMode(PWM_L,OUTPUT);
  pinMode(IN1_L,OUTPUT);
  pinMode(IN2_L,OUTPUT);
  
  // Right motor
  pinMode(PWM_L,OUTPUT);
  pinMode(IN1_L,OUTPUT);
  pinMode(IN2_L,OUTPUT);
}

void loop() {
  int SensorState1 = digitalRead(sensor1);
  int SensorState2 = digitalRead(sensor2);

  if(SensorState1 == 0 && SensorState2 == 1){
    rr();
    lr();
    analogWrite(PWM_R, 120);
    analogWrite(PWM_L, 120);
    delay(20);
  } else if(SensorState1 == 1 && SensorState2 == 0){
    rl();
    ll();
    analogWrite(PWM_R, 120);
    analogWrite(PWM_L, 120);
    delay(20);
  } else if( SensorState1 == 0 && SensorState2 == 0){
    rr();
    ll();
    analogWrite(PWM_R, 255);
    analogWrite(PWM_L, 255);
    delay(20);
  } else{
    digitalWrite(IN1_R, LOW);
    digitalWrite(IN2_R, LOW);
    digitalWrite(IN1_L, LOW);
    digitalWrite(IN2_L, LOW);
  }
}
