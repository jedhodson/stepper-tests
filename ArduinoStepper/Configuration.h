/**
 * Configuration.h
 * Default values and configurations 
 */

#ifndef CONFIGURATION_H
#define CONFIGURATION_H

/** Enable debug mode */
#define DEBUG

/** Select stepper driver to use */
#define STEPPER_DRIVER_A4982
//#define STEPPER_DRIVER_ARDUINO

/** Pin map for stepper with the A4982 (RAMPS) driver */
#define STEP_PIN 54
#define DIR_PIN 55
#define ENABLE_PIN 38
#define CS_PIN 53

/** Pin map for stepper connected using Arduino stepper library */
#define H_BRIDGE_P1 2
#define H_BRIDGE_P2 3
#define H_BRIDGE_P3 4
#define H_BRIDGE_P4 5

/**  */
#define MICRO_STEPS 1

/** Stepper motor steps per revolution */
#define DEFAULT_STEPS_PER_REVOLUTION 200
int STEPS_PER_REVOLUTION = DEFAULT_STEPS_PER_REVOLUTION;

/** Stepper motor revolution per millimeter of linear movement */
#define DEFAULT_REVOLUTIONS_PER_MILLIMETER 1
int REVOLUTIONS_PER_MILLIMETER = DEFAULT_REVOLUTIONS_PER_MILLIMETER;

/** Default stepper speed (rpm) */
#define DEFAULT_STEPPER_RPM 60

#endif