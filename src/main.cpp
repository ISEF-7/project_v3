#include "common.h"
#include "m.h"
#include "map.h"
#include "l.h"
#include "slam.h"

//TODO SET SERIAL TO COM6

//define pins
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

File workingFile;
vector<vector<l_a>> la_mtx_data = convert_f_TO_rd(workingFile);
vector<road_act> B = shortestpath_algo(la_mtx_data);
vector<instruction> MOTOR_1_INSTRUCTIONS = _m1(B);
vector<instruction> MOTOR_2_INSTRUCTIONS = _m2(B);

//////

printData pdt; 
void print_tick(int i){cout << pdt.tick << i;}

ThreadController tc = ThreadController();

Thread* tmain = new Thread();
void tmain_exec(){
	Serial.println(millis());

}

Thread* tlidar = new Thread();
void tlidar_exec(){
	Serial.println(millis());

}

Thread* t_m_1 = new Thread();
void m1_exec(){
  vector<instruction> m1i = MOTOR_1_INSTRUCTIONS;
  int i =0;
  i++;
  cout << i;
  //TODO
	Serial.println(millis());


}
Thread* t_m_2 = new Thread();
void m2_exec(){
  vector<instruction> m2i = MOTOR_2_INSTRUCTIONS;
  int i =0;
  i++;
  cout << i;
  //TODO
	Serial.println(millis());

}

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

void setup(){
  cout << pdt.SETUP;
  cout << pdt.b;

  tmain->onRun(tmain_exec);
  tlidar->onRun(tlidar_exec);

  t_m_1->onRun(m1_exec);
  t_m_2->onRun(m2_exec);



  tc.add(tmain);
  tc.add(tlidar);
  tc.add(t_m_1);
  tc.add(t_m_2);

  Serial.begin(9600); //baud rate

  boot_hub(hub);
  boot_lidar(l);
  boot_servo({m1,m2});

  
}

void loop() {
  /*
  int i = 0;
  print_tick(++i);
  */
  if (tmain->shouldRun()){
    tmain->run();
  }
  if (tlidar->shouldRun()){
    tlidar->run();
  }
  if (t_m_1->shouldRun()){
    t_m_1->run();
  }
  if (t_m_2->shouldRun()){
    t_m_2->run();
  }
}