/**
 * Arduino Stepper Tests
 * Designed to be driver agnostic, includes other functions to make life easier. 
 * Control is via a simple serial interpreter.
 * 
 * Supported stepper drivers:
 * * A4982 Stepper Driver   using the BasicStepperDriver library made by Laurentiu Badea
 * * Arduino Stepper w/ support for Unipolar and Bipolar steppers (https://arduino.cc/en/reference/stepper)
 * 
 * Additional implementations - code can easily be transfered to other application
 * * Configurable ramp-up/ ramp-down movement (@TODO)
 * * Rotation to linear movement (@TODO)
 */

#include "Configuration.h" // Default values & configuration file
#include "Debug.h"         // Debug macros
#include "Helpers.h"       // Helper functions to make life easier
#include "SimpleStepper.h" // Driver agnostic stepper library interface

/** Select stepper driver in Configuration.h */

/** Configure stepper using A4982 driver */
BasicStepperDriver stepper(STEPS_PER_REVOLUTION, DIR_PIN, STEP_PIN, ENABLE_PIN);

/** Configure stepper using Arduino driver */
//Stepper stepper(STEPS_PER_REVOLUTION, H_BRIDGE_P1, H_BRIDGE_P2, H_BRIDGE_P3, H_BRIDGE_P4);

/** Arduino setup method */
void setup()
{
    Serial.begin(115200);
    Serial.println("Starting...");

    // Set default speed & microsteps
    SimpleStepper::setSpeed(stepper, DEFAULT_STEPPER_RPM);
    SimpleStepper::setMicrostepsPerRevolution(stepper, DEFAULT_REVOLUTIONS_PER_MILLIMETER);
}

/** Arduino loop method - Wait for serial data */
void loop()
{
    /** Send serial data to a simple interpretter */
    while (Serial.available() > 0)
    {
        String str = Serial.readString();
        serialInterpreter(str);
    }
}

/**
 * Takes an input in format "cmd,value" and translates to a stepper function
 * 
 * @param input     String in format "cmd,value"
 */
void serialInterpreter(String input)
{
    char command = splitString(input, ',', 0).charAt(0);
    long value = atol(splitString(input, ',', 1).c_str());

    switch (command)
    {
    // Stepper move (steps long)
    case 'm':
        SimpleStepper::step(stepper, value);
        break;
    // Stepper Enable (true/false bool)
    case 'e':
        SimpleStepper::enable(stepper, (bool)value);
        break;
    // Stepper Set microsteps (int)
    case 'u':
        SimpleStepper::setMicrostepsPerRevolution(stepper, value);
        break;
    // Set speed
    case 's':
        SimpleStepper::setSpeed(stepper, value);
        break;
    // Change algorithm @TODO
    case 'a':
        Serial.println("Not implemented @TODO");
        break;
    default:
        Serial.println("Unsupported command");
        break;
    }
}