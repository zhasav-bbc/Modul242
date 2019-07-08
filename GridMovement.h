/* GridMovement.h und GridMovement.cpp stellen Funktionen bereit, damit
der Zumo ganz simpel die schwarzen Streifen verfolgen kann.
*/

#pragma once

#include <Wire.h>
#include <Zumo32U4.h>

// Motorgeschwindigkeit bei gerader Fahrweise
const uint16_t straightSpeed = 200;

// Verzögerung beim Wenden
const uint16_t intersectionDelay = 130;

// Motorgeschwindigkeit beim Drehen
const uint16_t turnSpeed = 200;

// Motorgeschwindigkeit beim Kalibrieren.
const uint16_t calibrationSpeed = 200;

// Erkennung von Linien.
const uint16_t sensorThreshold = 200;

// Erkennung vom Ende des Labyrinths.
const uint16_t sensorThresholdDark = 600;

// Anzahl Liniesensore, die benutzt werden.
const uint8_t numSensors = 5;

const int32_t gyroAngle45 = 0x20000000;

void printBar(uint8_t barHeight);
uint16_t readSensors();
bool aboveLine(uint8_t sensorIndex);
bool aboveLineDark(uint8_t sensorIndex);
bool aboveDarkSpot();
extern uint16_t lineSensorValues[numSensors];
void turn(char dir);
void followSegment();
void driveToIntersectionCenter();
void driveToIntersectionCenter(bool * foundLeft, bool * foundStraight, bool * foundRight);
void gridMovementSetup();

extern L3G gyro;
extern Zumo32U4ButtonA buttonA;
extern Zumo32U4Motors motors;
extern Zumo32U4LCD lcd;
extern Zumo32U4LineSensors lineSensors;
