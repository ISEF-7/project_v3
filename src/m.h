#pragma once

#include "common.h"

struct road_act{
    float speed;
    int lane;
    float next_turndeg;
};

class instruction{
    public:
        float w;
        float t;
};

extern int pin_m_1;
extern int pin_m_2;

vector<instruction> _m1(vector<road_act> d);
vector<instruction> _m2(vector<road_act> d);