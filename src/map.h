#pragma once
#include "m.h"

using namespace std;

class location;
enum trafficlightstate {RED, ORANGE, GREEN};
enum pedestrianstate {STOP, GO};
class node;
class road;

int test();
vector<vector<float>> test2();
vector<vector<int>> test31();

vector<vector<float>> convert_f_TO_2d(string str);
vector<float> convert_f_TO_1d(string str);
vector<string> div(string str);
vector<road_act> shortestpath_algo(vector<vector<float>> mtx);