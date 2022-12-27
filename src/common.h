#pragma once

#include <Arduino.h>
#include <ArduinoSTL.h> //https://registry.platformio.org/libraries/mike-matera/ArduinoSTL 
#include <ArduinoJson.h> //https://registry.platformio.org/libraries/bblanchon/ArduinoJson 
#include <Thread.h> //https://registry.platformio.org/libraries/ivanseidel/Thread
#include <StaticThreadController.h> //https://registry.platformio.org/libraries/ivanseidel/Thread
#include <ThreadController.h> //https://registry.platformio.org/libraries/ivanseidel/Thread
#include <RPLidar.h> //https://github.com/robopeak/rplidar_arduino
#include <Servo.h> //https://registry.platformio.org/libraries/arduino-libraries/Servo
#include "SdFat.h" //https://registry.platformio.org/libraries/greiman/SdFat
#include <LinkedList.h> //https://registry.platformio.org/libraries/ivanseidel/LinkedList/installation

#define nameof(x) #x

using namespace std;
