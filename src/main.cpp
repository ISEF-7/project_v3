#include "common.h"
#include <functional>

//define pins
#define pin_L 0 //TODO set the values
#define pin_m_1 0
#define pin_m_2 0
//#define blahblahblah (someint)

using namespace std;

///////

class Hub{
  public:
    const int Pin_l = pin_L; 
    const int Pin_m_1 = pin_m_1;
    const int Pin_m_2 = pin_m_2;
};
void hub_moduleCheck(Hub h){}

void boot_hub(Hub h){
  cout << "Booting hub...";
  hub_moduleCheck(h);
  
  //TODO object configuration
}

ThreadController controll = ThreadController();
/*
//main protothread
pt ptMain;
int MainThread(struct pt* pt){
    PT_BEGIN(pt);
    for(;;){
      //TODO main thread execution
    }
    PT_END(pt);
}
*/

//thread for interupting main thread and executing SLAM protocol
/*
pt ptSLAM;
int SLAMThread(struct pt* pt){
  PT_BEGIN(pt);
    for(;;){
      //TODO main thread execution
    }
  PT_END(pt);
}
*/
///////

short completePercent;

RPLidar l;
RPLidar* L = &l;
bool lstatus;

Servo m1;
Servo* M1 = &m1;
bool m1status;

Servo m2;
Servo* M2 = &m2;
bool m2status;

Hub hub;
Hub* HUB = &hub;
bool status;

///////
void shutdown(Servo obj){if (&obj == &m1){m1status = false;}if (&obj == &m2){m2status = false;}}
void shutdown(RPLidar obj){if (&obj == &l){lstatus = false;}} 
void shutdown(Hub obj){if (&obj == &hub){status = false;}}

void servo_moduleCheck(Servo servo){
  //XXX test if comparing objects by runtime memory address works, alternative is to do nested classes, and the base class has the name
  if (&servo == &m1){
    if (m1.attached() == true){
      cout << "Servo m1: OK";
    }
    else{
      cout << "Servo m1: ERR";
      shutdown(servo);
    }
  }
  if (&servo == &m2){
    if (m2.attached() == true){
      cout << "Servo m2:" "OK";
    }
    else{
       cout << "Servo m2:" "ERR";
       shutdown(servo);
    }
  }
}
void boot_servo(vector<Servo> servolist){
  for (int i=0; (unsigned)i<servolist.size(); i++){
    cout << "Booting Servo m" << i << " ...";
    servo_moduleCheck(servolist.at(i));
  };
}

void lidar_moduleCheck(RPLidar lidar){
  rplidar_response_device_info_t info;
  if (IS_OK(lidar.getDeviceInfo(info, 100)) == true && IS_OK(lidar.waitPoint()) == true){cout<< "RPLidar l: OK";} //XXX check lidar variables
  else{
    cout << "RPLidar l: ERR"; 
    shutdown(lidar);
  }
}
void boot_lidar(RPLidar lidar){
  cout << "Booting RPLidar...";
  lidar_moduleCheck(lidar);
  //TODO object configuration
}


void setup() {
  cout << "SETUP ///////";
  cout << "Booting";
  boot_hub(hub);
  boot_lidar(l);
  boot_servo({m1,m2});
}

void loop() {
  
}