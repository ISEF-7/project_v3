#include "common.h"

//TODO SET SERIAL TO COM6

//define pins
#define pin_L 0 //TODO set the values
#define pin_m_1 0
#define pin_m_2 0
//#define blahblahblah (someint)

using namespace std;

///////

struct printData{  // to remove printing to increasing efficiency

  short completePercent; 

  string m1ok = "Servo m1: OK";
  string m1er = "Servo m1: ERR";

  string m2ok = "Servo m2:" "OK";
  string m2er = "Servo m2:" "ERR";

  string sb = "Booting Servo m";

  string lok = "RPLidar l: OK";
  string ler = "RPLidar l: ERR";
  string lb = "Booting RPLidar...";

  string SETUP = "SETUP ///////";
  string b = "booting";

  string dotdotdot = "...";

  string tick = "Tick #";
};


//////

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

//////

printData pdt; 
void print_tick(int i){cout << pdt.tick << i;}

ThreadController tc = ThreadController();

Thread tmain = Thread();
void tmainCB(){}

Thread tlidar = Thread();
void tlidarCB(){}

Thread servo_m_1 = Thread();
void m1CB(){}

Thread servo_m_2 = Thread();
void m2CB(){}

//TODO init threading

RPLidar l; RPLidar* L = &l; bool lstatus;
Servo m1; Servo* M1 = &m1; bool m1status;
Servo m2; Servo* M2 = &m2; bool m2status;
Hub hub; Hub* HUB = &hub; bool status;

///////

void shutdown(Servo obj){if (&obj == &m1){m1status = false;}if (&obj == &m2){m2status = false;}}
void shutdown(RPLidar obj){if (&obj == &l){lstatus = false;}} 
void shutdown(Hub obj){if (&obj == &hub){status = false;}}

void servo_moduleCheck(Servo servo){
  //XXX test if comparing objects by runtime memory address works, alternative is to do nested classes, and the base class has the name
  if (&servo == &m1){
    if (m1.attached() == true){
      cout << pdt.m1ok;
    }
    else{
      cout << pdt.m1er;
      shutdown(servo);
    }
  }
  if (&servo == &m2){
    if (m2.attached() == true){
      cout << pdt.m2ok;
    }
    else{
       cout << pdt.m2er;
       shutdown(servo);
    }
  }
}
void boot_servo(vector<Servo> servolist){
  for (int i=0; (unsigned)i<servolist.size(); i++){
    cout << pdt.sb << i << pdt.dotdotdot;
    servo_moduleCheck(servolist.at(i));
  };
}

void lidar_moduleCheck(RPLidar lidar){
  rplidar_response_device_info_t info;
  if (IS_OK(lidar.getDeviceInfo(info, 100)) == true && IS_OK(lidar.waitPoint()) == true){cout<< pdt.lok;} //XXX check lidar variables
  else{
    cout << pdt.ler; 
    shutdown(lidar);
  }
}
void boot_lidar(RPLidar lidar){
  cout << pdt.lb;
  lidar_moduleCheck(lidar);


}

//////

void setup() {
  cout << pdt.SETUP;
  cout << pdt.b;

  Serial.begin(9600); //baud rate

  boot_hub(hub);
  boot_lidar(l);
  boot_servo({m1,m2});


}

void loop() {
  tc.run();
}