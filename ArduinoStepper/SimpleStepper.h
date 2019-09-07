/**
 * SimpleStepper.h
 * Create an abstract interface for controlling stepper motor classes
 * 
 * Functions:
 * * step: Move stepper x steps
 * * enable: Engage or disengage stepper motor
 * * setMicrostepsPerRevolution: Set the microsteps per revolution
 * * setSpeed: Set the target RPM
 */

#include "Configuration.h"
#include "Debug.h"

/** Load driver specific classes */
#ifdef STEPPER_DRIVER_A4982
#include "BasicStepperDriver.h"
#define STEPPER_DRIVER BasicStepperDriver
#endif
#ifdef STEPPER_DRIVER_ARDUINO
#include <Stepper.h>
#define STEPPER_DRIVER Stepper
#endif

/** Static class to interface with stepper driver */
class SimpleStepper {
    public:
        static void step(STEPPER_DRIVER _stepper, long steps);
        static void enable(STEPPER_DRIVER _stepper, bool _enable);
        static void setMicrostepsPerRevolution(STEPPER_DRIVER _stepper, int usteps);
        static void setSpeed(STEPPER_DRIVER _stepper, int rpm);
    private:
        SimpleStepper() {};
};

/**
 * Move stepper specific amount of steps
 * 
 * @param _stepper  Pass an object of the stepper motor defined to use
 * @param steps     Number of steps to move stepper
 */
void SimpleStepper::step(STEPPER_DRIVER _stepper, long steps) {
    DEBUG_LOG("SimpleStepper::step() Steps: " + (String)steps);

    #ifdef STEPPER_DRIVER_A4982
    _stepper.move(steps);
    #endif
    #ifdef STEPPER_DRIVER_ARDUINO
    _stepper.step(steps);
    #endif
}

/**
 * Enable or disable stepper
 * Only supported on A4982 Driver
 * 
 * @param _stepper  Pass an object of the stepper motor defined to use
 * @param _enable   Enable or disable the specified stepper
 */
void SimpleStepper::enable(STEPPER_DRIVER _stepper, bool _enable) {
    DEBUG_LOG("SimpleStepper::enable() Enable: " + (String)_enable);

    #ifdef STEPPER_DRIVER_A4982
    (_enable) ? _stepper.enable() : _stepper.disable();
    #endif
    #ifdef STEPPER_DRIVER_ARDUINO
    DEBUG_LOG("SimpleStepper::enable() Not implemented in Arduino Driver");
    #endif
} 

/**
 * Set the number of microsteps per revolution ???
 */
void SimpleStepper::setMicrostepsPerRevolution(STEPPER_DRIVER _stepper, int usteps) {
    DEBUG_LOG("SimpleStepper::setMicrostepsPerRevolution() Microsteps: " + (String)usteps);

    #ifdef STEPPER_DRIVER_A4982
    _stepper.setMicrostep(usteps);
    #endif
    #ifdef STEPPER_DRIVER_ARDUINO
    STEPS_PER_REVOLUTION = usteps;
    #endif
}

/**
 * Set speed of stepper in rotations per minute
 * 
 * @param _stepper  Pass an object of the stepper motor defined to use
 * @param rpm       Speed in RPM
 */
void SimpleStepper::setSpeed(STEPPER_DRIVER _stepper, int rpm) {
    DEBUG_LOG("SimpleStepper::setSpeed() Speed: " + (String)rpm);

    #ifdef STEPPER_DRIVER_A4982
    _stepper.setRPM(rpm);
    #endif
    #ifdef STEPPER_DRIVER_ARDUINO
    _stepper.setSpeed(rpm);
    #endif
}