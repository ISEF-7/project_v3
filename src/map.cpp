#include "common.h"
#include "map.h"
#include "m.h"
#include <limits.h>
using namespace std;

#include <iostream> 

enum la {l,a};

vector<road_act> actonslist;
File MyReadFile;
class node{
  public:
    int node_position;
    string name;
};
class road{
  public:
    vector<node> body;
    float length;
    vector<int> lanes;
    float speedLimit; 
};
string readFile(string s){ //TODO later add SD file reading
  return s;
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

vector<vector<float>> convert_f_TO_rd(string file, la which){
  string w;
  if (which == 0){
    w = "length";
  }
  else if (which == 1){
    w = "angle";
  }
  StaticJsonDocument<200> doc; //size https://arduinojson.org/v6/assistant/#/step1 
  DeserializationError error = deserializeJson(doc, file); //XXX see how to copy file to doc
  if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.f_str());
    return;
  }
  int square = sizeof(doc[w])/(sizeof(doc[w][0]));
  vector<vector<float>> rd;
  for (int i = 0; i < square; i++){
    vector<float> v;
    v.clear(); //TODO make separate code for (square choose 2) * (square choose 2) matrix for angles
    for (int j = 0; j < square; i++){
      float iter {doc[w][i][j]};
      v.push_back(iter);
    }
    rd.push_back(v);
  }
  if (check(rd, square) == true){return rd;}
  else{cout << "conv[f,r/a] err"; return;}
}

vector<float> convert_f_TO_s(string file){
  string w = "speed_limit";
  StaticJsonDocument<200> doc; //size https://arduinojson.org/v6/assistant/#/step1
  DeserializationError error = deserializeJson(doc, file);
  if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.f_str());
    return;
  }
  int line = sizeof(doc[w])/(sizeof(doc[w][0]));
  vector<float> s;
  for (int i = 0; i < line; i++){
    vector<float> v;
    v.push_back(doc[w][i]);
  }
  if (check(s, line) == true){return s;}
  else{cout << "conv[f,s] err"; return;}
}

vector<road_act> shortestpath_algo(vector<vector<float>> l_mtx, vector<vector<float>> a_mtx, vector<float> s_mtx){
    //TODO shortestpath algorithm
    //grab l_mtx
    //dijstrka func d d(l_mtx)
    //return [ merge d(l_mtx), (a_mtx), and (s_mtx) into road_act vector (l,a,s) structure ]
}