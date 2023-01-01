#include "common.h"
#include "m.h"
#include "map.h"
#include "l.h"
#include "slam.h"

//define pins
#define pin_L 0 //TODO set the values
#define pin_m_1 1
#define pin_m_2 2


using namespace std;

enum PROTOCOL {ON_PROTOCOL, OFF_PROTOCOL, BOOTING_PROTOCOL, WAIT_PROTOCOL, ROUTE_PROTOCOL, SLAM_PROTOCOL} SYS_STATUS;

///////

RPLidar l; RPLidar* L = &l; bool lstatus; //FIXME there is a halting in all code before startup
Servo m1; Servo* M1 = &m1; bool m1status;
Servo m2; Servo* M2 = &m2; bool m2status;

void shutdown(Servo obj){
  if (strcmp(nameof(obj), "m1") == 0){ //TEST if nameof() macro prints "obj" not the actual name of passed argument
    m1status = false;
    SYS_STATUS = OFF_PROTOCOL;
  }
  if (strcmp(nameof(obj), "m2") == 0){
    m2status = false; 
    SYS_STATUS = OFF_PROTOCOL;
  }
}
void shutdown(RPLidar obj){
  if (strcmp(nameof(obj),"l") == 0){ 
    lstatus = false; 
    SYS_STATUS = OFF_PROTOCOL;
    }
} 

short completePercent;

string hok = "Hub: OK";

string her = "Hub: ERR";
string hb = "Booting Hub";

string m1ok = "Servo m1: OK";
string m1er = "Servo m1: ERR";

string m2ok = "Servo m2:" "OK";
string m2er = "Servo m2:" "ERR";

string sb = "Booting Servo m";

string lok = "RPLidar l: OK";
string ler = "RPLidar l: ERR";
string lb = "Booting RPLidar";

string SETUP = "SETUP ///////";
string b = "booting";

string dotdotdot = "...";

string tick = "Tick #";

//////

string file = "{ \"length\": [[,,], [,,], [,,]] \"angle\": [[,,], [,,], [,,]]}";
  //TODO later add SD file reading


class Hub{
  public:
    const int Pin_l = pin_L; 
    const int Pin_m_1 = pin_m_1;
    const int Pin_m_2 = pin_m_2;

    //const int width; TODO set
    //const int length; TODO set
    //const int height; TODO set

    //const int wheel_diamter; TODO set
  void print_tick(int i){cout << tick << i;}
};

Hub hub; Hub* HUB = &hub; bool hubstatus;

void shutdown(Hub obj){
  if (strcmp(nameof(obj), "hub") == 0){
    hubstatus = false;
    SYS_STATUS = OFF_PROTOCOL;
  }
}
void hub_moduleCheck(Hub h){
  if (h.Pin_l == pin_L && h.Pin_m_1 == pin_m_1 && h.Pin_m_2 == pin_m_2){
    cout<<hok;
  }
  else{
    cout<<her;
    shutdown(h);
  }
}
void boot_hub(Hub h){
  cout << hb << dotdotdot;
  hub_moduleCheck(h);
}

void servo_moduleCheck(Servo servo){ //TODO combine modulecheck and boot void functions to 2 singular functions
  if (strcmp(nameof(servo), "m1") == 0){
    if (m1.attached() == true){
      cout << m1ok;
    }
    else{
      cout << m1er;
      shutdown(servo);
    }
  }
  if (strcmp(nameof(servo), "m2") == 0){
    if (m2.attached() == true){
      cout << m2ok;
    }
    else{
       cout << m2er;
       shutdown(servo);
    }
  }
}
void boot_servo(vector<Servo> servolist){
  for (int i=0; (unsigned)i<servolist.size(); i++){
    cout << sb << i << dotdotdot;
    servo_moduleCheck(servolist.at(i));
  };
}

void lidar_moduleCheck(RPLidar lidar){
  rplidar_response_device_info_t info;
  if (IS_OK(lidar.getDeviceInfo(info, 100)) == true){cout<< lok;} //XXX check lidar variables
  else{
    cout << ler; 
    shutdown(lidar);
  }
}
void boot_lidar(RPLidar lidar){
  cout << lb << dotdotdot;
  lidar_moduleCheck(lidar);
}

//TODO init threading

vector<vector<l_a>> la_mtx_data;
vector<road_act> B;
vector<instruction> MOTOR_1_INSTRUCTIONS;
vector<instruction> MOTOR_2_INSTRUCTIONS;

/////////
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

void LEDblink(int port, int delayms){
  digitalWrite(port, HIGH);
  delay(delayms);
}

//////

void setup(){
  Serial.begin(9600); //baud rate

  cout << SETUP;
  cout << b;

  pinMode(LED_BUILTIN, OUTPUT);
  for (int i = 1; i <= 5; i++){
    LEDblink(LED_BUILTIN, 500);
  }
  // vector<vector<l_a>> la_mtx_data = convert_f_TO_rd(file);
  // vector<road_act> B = shortestpath_algo(la_mtx_data);
  // vector<instruction> MOTOR_1_INSTRUCTIONS = _m1(B);
  // vector<instruction> MOTOR_2_INSTRUCTIONS = _m2(B);

  // tmain->onRun(tmain_exec);
  // tlidar->onRun(tlidar_exec);

  // t_m_1->onRun(m1_exec);
  // t_m_2->onRun(m2_exec);


  // tc.add(tmain);
  // tc.add(tlidar);
  // tc.add(t_m_1);
  // tc.add(t_m_2);


  // boot_lidar(l);
  // boot_servo({m1,m2});
  // boot_hub(hub);
}

void loop() {

  // int i = 0;
  // hub.print_tick(++i);
  
  // if (tmain->shouldRun()){
  //   tmain->run();
  // }
  // if (tlidar->shouldRun()){
  //   tlidar->run();
  // }
  // if (t_m_1->shouldRun()){
  //   t_m_1->run();
  // }
  // if (t_m_2->shouldRun()){
  //   t_m_2->run();
  // }
}