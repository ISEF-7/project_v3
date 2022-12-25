#ifndef M_H
#define M_H

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

LinkedList<instruction> _m1(road_act d);
LinkedList<instruction> _m2(road_act d);

#endif