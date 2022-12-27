#include "common.h"
#include "m.h"


using namespace std;

vector<instruction> _m2(vector<road_act> d){
    //TODO
    //grab a_mtx from d
    //convert it to instructions
    instruction _temp_instruction;
    _temp_instruction.w = 0;
    _temp_instruction.t = 1;
    vector<instruction> temp = {_temp_instruction}; 
    return temp;  //XXX REMOVE LEFT
}