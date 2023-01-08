#include "common.h"
#include "map.h"
#include "m.h"
#include <limits>
#include <string>

using namespace std;

vector<road_act> actonslist;
File MyReadFile;
class node{
  public:
    int node_position;
    string name;
    float angle;
    //trafficlightstate trafficlightstate; TODO
    //pedestrianstate pedestrianstate; TODO
};
class road{
  public:
    vector<node> body;
    float length;
    //vector<int> lanes;
    float speedLimit; 
};
string readFile(File s){ //TODO later add SD file reading
  //return s;
}

bool check (vector<vector<float>> vec, int _square){
  for (int i = 0; i < _square; i++){
    if (vec[i][i] != 0 || vec[i][i] != 0){
      return false;
    }
  }
  for (int i =0; i < _square; i++){
    for (int j = 0; i < _square; j++){
      if (vec[i][j] != vec[j][i] || vec[i][j] != vec[j][i]){
        return false;
      }
    }
  }
  return true;
}
bool check (vector<float> vec, int _square){
  //NOTE no check needed
  return true;
}
float toFloat(string s){ //TODO make algo

}
vector<vector<float>> convert_f_TO_rd(string str){ 
  vector<vector<float>> rd;
  int size=0;
  bool size_def = false;
  vector<float> push;
  float minipush;
  string stringdigits;
  for (int i = 0;i<str.length();i++){
    if (str[i] != ' ' && str[i] != '|'){
      stringdigits.push_back(str[i]);
    }
    if (str[i] == ' '){
      minipush = toFloat(stringdigits); //get to float algorithm
      stringdigits = "";
      push.push_back(minipush);
      minipush = 0;
    }
    if (str[i] == '%'){
      size = i + 1;
      size_def = true;
      rd.push_back(push);
      push.clear();
    }
  }
  if (check(rd, size) == true){return rd;}
  else{cout << "conv[f,r/a] err"; return;}
}

// vector<float> convert_f_TO_s(string str){//FIXME fix
//   string w = "speed_limit";
//   vector<float> s;
//   int line;
//   int k;
//   for (int i;;i++){
//     float minipush;
//     String stringdigits = "";
//     if (str.at(i) != ' '){
//       stringdigits + str.at(i);
//     }
//     else if (str.at(i) == ' '){
//       minipush = toFloat(stringdigits);
//     }
//     k = i;
//   }
//   line = k+1;
//   if (check(s, line) == true){return s;}
//   else{cout << "conv[f,s] err"; return;}
// }

vector<road_act> shortestpath_algo(vector<vector<float>> l_mtx, vector<vector<float>> a_mtx, vector<float> s_mtx){
    //TODO shortestpath algorithm
    //grab l_mtx
    //dijstrka func d d(l_mtx)
    //return [ merge d(l_mtx), (a_mtx), and (s_mtx) into road_act vector (l,a,s) structure ]1111
}