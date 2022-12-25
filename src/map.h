#pragma once
#include "m.h"

using namespace std;

class location{
  public:
    string name;
    int node_position;
};

class node : location{
  public:

};

class road{
  public:
    vector<node> body;
    float length;
    vector<int> lanes;
    float speedLimit; 
};

struct l_a{ //NOTE clockwise angle's initial side is the segment itself
  float angle;
  float length;
};

struct roadData{
  vector<vector<l_a>> la_mtx_data;
  vector<vector<float>> l_mtx_data;
  vector<vector<float>> a_mtx_data;
  location i_location;
  location destination;
  string fileDir;
};

roadData convert_f_TO_rd(File sdFILE);
vector<road_act> shortestpath_algo(roadData rd);