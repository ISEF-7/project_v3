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

enum PROTOCOL {OFF_PROTOCOL = 0, ON_PROTOCOL = 1, BOOTING_PROTOCOL = 2, ROUTE_PROTOCOL = 3, SLAM_PROTOCOL = 4} SYS_STATUS;
enum STATUS {OK, ERR};

const bool TEST_PROTOCOL = true;

RPLidar l; RPLidar* L = &l; STATUS lstatus; //TODO restructure code by adding custom classes inherited from these builtin header classes 
Servo m1; Servo* M1 = &m1; STATUS m1status; 
Servo m2; Servo* M2 = &m2; STATUS m2status;

void shutdown(Servo obj){
  if (strcmp(nameof(obj), "m1") == 0){ //TEST if nameof() macro prints "obj" not the actual name of passed argument 
  //TODO add shutting down of specific modules
  }
  if (strcmp(nameof(obj), "m2") == 0){
  }
}
void shutdown(RPLidar obj){
  if (strcmp(nameof(obj),"l") == 0){ 
  }
}

//////

short completePercent = 0;

string hok = "Hub: OK\n";

string her = "Hub: ERR\n";
string hb = "Booting Hub";

string m1ok = "Servo m1: OK\n";
string m1er = "Servo m1: ERR\n";

string m2ok = "Servo m2:" "OK\n";
string m2er = "Servo m2:" "ERR\n";

string sb = "Booting Servo m";

string lok = "RPLidar l: OK\n";
string ler = "RPLidar l: ERR\n";
string lb = "Booting RPLidar";

string SETUP = "SETUP ///////\n";
string b = "booting";
string boot_results;

string SETUP_FINISH  = "SETUP Completed ///////\n";
string b_FINISH = "booting Completed";

string X = "X";
string hash = "#";
string dotdotdot = "...\n";
string exclamation_mark = "!\n";

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
    //const int mass; TODO set

    //const int wheel_diamter; TODO set
  void print_tick(int i){cout << tick << i;}
};

Hub hub; Hub* HUB = &hub; STATUS hubstatus;

void shutdown(Hub obj){
  if (strcmp(nameof(obj), "hub") == 0){
    SYS_STATUS = OFF_PROTOCOL;
  }
}
void hub_moduleCheck(Hub h){
  if (h.Pin_l == pin_L && h.Pin_m_1 == pin_m_1 && h.Pin_m_2 == pin_m_2){
    hubstatus = OK;
  }
  else{
    hubstatus = ERR;
    shutdown(h);
  }
}
void boot_hub(Hub h){
  //cout << hb << dotdotdot;
  hub_moduleCheck(h);
  if (hubstatus == OK && m1status == OK && m2status == OK && lstatus == OK){
    SYS_STATUS = ON_PROTOCOL;
  }
  else{
    SYS_STATUS = OFF_PROTOCOL;
  }
}

void servo_moduleCheck(Servo servo){ //TODO combine modulecheck and boot void functions to 2 singular functions
  if (strcmp(nameof(servo), "m1") == 0){
    if (m1.attached() == true){
      m1status = ERR;
    }
    else{
      m1status = ERR;
      shutdown(servo);
    }
  }
  if (strcmp(nameof(servo), "m2") == 0){
    if (m2.attached() == true){
      m2status = OK;
    }
    else{
      m2status = ERR;
      shutdown(servo);
    }
  }
}
void boot_servo(vector<Servo> servolist){
  for (unsigned int i = 0; i < servolist.size(); i++){
    if (i == 0){
      servolist.at(i).attach(pin_m_1);
    }
    else if (i == 1){
      servolist.at(i).attach(pin_m_2);
    }
    servo_moduleCheck(servolist.at(i));
  };
}

void lidar_moduleCheck(RPLidar lidar){
  rplidar_response_device_info_t info;
  if (IS_OK(lidar.getDeviceInfo(info, 100)) == true){
    lstatus = OK; 
  } //XXX check lidar variables
  else{
    lstatus = ERR;
    shutdown(lidar);
  }
}
void boot_lidar(RPLidar lidar){
  //cout << lb << dotdotdot;
  lidar_moduleCheck(lidar);
}

//TODO init threading

vector<vector<float>> l_mtx_data;
vector<vector<float>> a_mtx_data;
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
  //cout << i;
  //TODO
  Serial.println(millis());
}
Thread* t_m_2 = new Thread();
void m2_exec(){
  vector<instruction> m2i = MOTOR_2_INSTRUCTIONS;
  int i =0;
  i++;
 // cout << i;
  //TODO
  Serial.println(millis());
}

void LEDblink(int port, int delayms){
  digitalWrite(port, HIGH);
  delay(delayms);
  digitalWrite(port, LOW);
  delay(delayms);
}

//////
void setup(){
  delay(300);
  SYS_STATUS = ON_PROTOCOL;
  while (SYS_STATUS == ON_PROTOCOL){
    Serial.begin(9600); //baud rate

    cout << "\n";
    cout << SETUP;

    SYS_STATUS = BOOTING_PROTOCOL;

    pinMode(LED_BUILTIN, OUTPUT);
    for (int i = 1; i <= 5; i++){
      LEDblink(LED_BUILTIN, 500);
    }
    cout << b << dotdotdot;

    boot_lidar(l);
    //boot_servo({m1,m2}); //FIXME no printing with this line of code
    boot_hub(hub);

    // vector<vector<float>> l_mtx_data = convert_f_TO_rd(file);  //FIXME no printing with this line of code
    // vector<vector<float>> a_mtx_data = convert_f_TO_rd(file);  //FIXME no printing with this line of code
    // vector<vector<float>> s_mtx_data = convert_f_TO_rd(file);  //FIXME no printing with this line of code
    // vector<road_act> f = shortestpath_algo(l_mtx_data, a_mtx_data, s_mtx_data);  //FIXME no printing with this line of code
    // vector<instruction> MOTOR_1_INSTRUCTIONS = _m1(f);  //FIXME no printing with this line of code
    // vector<instruction> MOTOR_2_INSTRUCTIONS = _m2(f);  //FIXME no printing with this line of code

    // tmain->onRun(tmain_exec);
    // tlidar->onRun(tlidar_exec);

    // t_m_1->onRun(m1_exec);
    // t_m_2->onRun(m2_exec);


    // tc.add(tmain);
    // tc.add(tlidar);
    // tc.add(t_m_1);
    // tc.add(t_m_2);
  }
}
void loop() {
  // while (SYS_STATUS != OFF_PROTOCOL){
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
  // }
}