// This file contains a lot of hate that built up while writing code in this awful language.

import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    // Ask the user to enter a material:
    System.out.print("Enter material: ");

    // Start a new scanner and read the data to material and then make sure to close the scanner. Way too over complicated and useless, but this is what we have to work with in this stupid language.
    Scanner scanner = new Scanner(System.in);
    String material = scanner.next();
    scanner.close();

    // Initialize strength and weight with zero because Java is fucking stupid.
    byte strength = 0;
    float weight = 0;

    // Convert material string to lower case, probably thye only thing I like with Java...
    material = material.toLowerCase();

    // Create a switch statement for material where we add values to strength and weight. Because Java is stupid, we need to break each case manually...
    switch (material) {
    case "cfrp":
      strength = 50;
      weight = 3.5F;
      break;
    case "titanium":
      strength = 55;
      weight = 6.2F;
      break;
    case "nylon":
      strength = 20;
      weight = 3.0F;
      break;
    default:
      System.exit(0);
    }

    // Calculate the effectiveness of the material using separate function.
    float value = effectiveness(strength, weight);
    System.out.print("The effective value for your material is: ");
    System.out.println(value);
  }

  // Because Java is Java, we need to write about five times more shit than necessary.
  public static float effectiveness(byte strength, float weight) {
    return strength / weight;
  }
}