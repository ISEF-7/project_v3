#pragma once
#include "m.h"

using namespace std;

class location;
enum trafficlightstate {RED, ORANGE, GREEN};
enum pedestrianstate {STOP, GO};
class node{
  float angle;
  //trafficlightstate trafficlightstate; TODO
  //pedestrianstate pedestrianstate; TODO
};

class road{
  float length;
  float speed_limit;
};

extern vector<vector<float>> l_mtx_data;
extern vector<vector<float>> a_mtx_data;
extern vector<float> s_mtx_data;

vector<vector<float>> convert_f_TO_rd(string file);
vector<road_act> shortestpath_algo(vector<vector<float>> mtx);