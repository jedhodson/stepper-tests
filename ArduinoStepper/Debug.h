/**
 * Debug.h
 * Macros for debugging
 */

#ifndef DEBUG_H
#define DEBUG_H

/** If debug is enabled, write DEBUG_LOG messages to serial console */
#ifdef DEBUG
#define DEBUG_LOG(msg) Serial.println(msg)
#else
#define DEBUG_LOG(msg)
#endif

#endif