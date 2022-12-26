#include "common.h"
#include "map.h"
#include "m.h"

using namespace std;


vector<instruction> _m1(vector<road_act> d){
    //TODO
    //grab l_mtx from d
    //convert it to instructions
    instruction temp_instruction;
    temp_instruction.w = 0;
    temp_instruction.t = 1;
    vector<instruction> temp = {temp_instruction};  
    return temp; //XXX REMOVE LEFT
}
