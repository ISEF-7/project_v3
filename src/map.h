#pragma once
#include "m.h"

using namespace std;

class location;
enum trafficlightstate {RED, ORANGE, GREEN};
enum pedestrianstate {STOP, GO};
class node;
class road;

extern vector<vector<float>> l_mtx_data;
extern vector<vector<float>> a_mtx_data;
extern vector<float> s_mtx_data;

float toFloat(string s, int base);

vector<vector<float>> convert_f_TO_2d(string str);
vector<float> convert_f_TO_1d(string str);
vector<string> div(string str);
vector<road_act> shortestpath_algo(vector<vector<float>> mtx);