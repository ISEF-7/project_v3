#pragma once

#include <Arduino.h>
#include <ArduinoSTL.h> //https://registry.platformio.org/libraries/mike-matera/ArduinoSTL 
#include <ArduinoJson.h> //https://registry.platformio.org/libraries/bblanchon/ArduinoJson 
#include <Thread.h> //https://registry.platformio.org/libraries/ivanseidel/Thread
#include <StaticThreadController.h> //https://registry.platformio.org/libraries/ivanseidel/Thread
#include <ThreadController.h> //https://registry.platformio.org/libraries/ivanseidel/Thread
#include <RPLidar.h> //https://github.com/robopeak/rplidar_arduino
#include <Servo.h> //https://registry.platformio.org/libraries/arduino-libraries/Servo

#include "map.h"
#include "m.h"
#include "l.h"
#include "slam.h"

#define nameof(x) #x

#ifndef NULL
#define NULL 0x00000000
#endif

// #ifndef sizeof
// #define sizeof(type) ((char *)(&type+1)-(char*)(&type))
// #endif

using namespace std;
