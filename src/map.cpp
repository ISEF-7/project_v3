#include "common.h"
#include "map.h"
#include "m.h"
#include <limits.h>

using namespace std;

vector<road_act> actonslist;

vector<vector<l_a>> convert_f_TO_rd(File sdFILE){
    //TODO convert algorithm
}

float** grab_length(vector<vector<l_a>> mtx, string grab){
    int size = mtx.size();
    float l_mtx[size][size];
    for(unsigned i=0; i<size; i++ ){
        for (unsigned j=0; j<size; j++){
            if (grab == "length"){
            l_mtx[i][j] = mtx[i][j].length;
            }
            if (grab == "angle"){
            l_mtx[i][j] = mtx[i][j].angle;
            }
        }
    }
}


vector<road_act> shortestpath_algo(vector<vector<l_a>> mtx){
    //TODO shortestpath algorithm
    //grab l_mtx
    //dijstrka func d d(l_mtx)
    //return [ merge d(l_mtx) and (a_mtx) into road_act vector (l,a) structure 
}