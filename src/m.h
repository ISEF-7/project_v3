#pragma once

using namespace std;

struct road_act{
    float l;
    float next_turndeg;
    float speed;
    //int lane; TODO
};

class instruction{
    public:
        float w;
        float t;
};
vector<instruction> _m1(vector<road_act> d);
vector<instruction> _m2(vector<road_act> d);