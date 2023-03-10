#pragma once
#include "m.h"

using namespace std;

class location;

class node;

class road;

struct l_a{ //NOTE clockwise angle's initial side is the segment itself
  float angle;
  float length;
};

extern vector<vector<l_a>> la_mtx_data;
extern SdFat sd;
extern File file;

vector<vector<l_a>> convert_f_TO_rd(string sdFILE);
vector<road_act> shortestpath_algo(vector<vector<l_a>> mtx);