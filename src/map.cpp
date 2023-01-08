#include "common.h"
#include "map.h"
#include "m.h"
#include <limits.h>
using namespace std;

#include <iostream> 

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

bool check (vector<vector<l_a>> vec, int _square){
  for (int i = 0; i < _square; i++){
    if (vec[i][i].length != 0 || vec[i][i].angle != 0){
      return false;
    }
  }
  for (int i =0; i < _square; i++){
    for (int j = 0; i < _square; j++){
      if (vec[i][j].length != vec[j][i].length || vec[i][j].angle != vec[j][i].angle){
        return false;
      }
    }
  }
  return true;
}

vector<vector<l_a>> convert_f_TO_rd(string file){ 
  StaticJsonDocument<200> doc; //size https://arduinojson.org/v6/assistant/#/step1
  DeserializationError error = deserializeJson(doc, file);
  if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.f_str());
    return;
  }
  int square = sizeof(doc["length"])/(sizeof(doc["length"][0]));
  vector<vector<l_a>> rd;
  for (int i = 0; i < square; i++){
    vector<l_a> v;
    v.clear(); //TODO make separate code for (square choose 2) * (square choose 2) matrix for angles
    for (int j = 0; j < square; i++){
      l_a iter {doc["length"][i][j],doc["angle"][i][j]};
      v.push_back(iter);
    }
    rd.push_back(v);
  }
  if (check(rd, square) == true){return rd;}
  else{return;}
}

vector<vector<float>> grab(vector<vector<l_a>> mtx, string grab){
    int size = mtx.size();
    vector<vector<float>> new_mtx;
    for(unsigned i=0; i<(unsigned)size; i++ ){
        for (unsigned j=0; j<size; j++){
            if (grab == "length"){
            new_mtx[i][j] = mtx[i][j].length;
            }
            if (grab == "angle"){
            new_mtx[i][j] = mtx[i][j].angle;
            }
        }
    }
    return new_mtx;
}
vector<road_act> shortestpath_algo(vector<vector<l_a>> mtx){
    //TODO shortestpath algorithm
    //grab l_mtx
    //dijstrka func d d(l_mtx)
    //return [ merge d(l_mtx) and (a_mtx) into road_act vector (l,a) structure 
}