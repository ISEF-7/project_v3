#include "common.h"
#include "map.h"
#include "m.h"
#include <limits.h>

using namespace std;

vector<road_act> actonslist;

class node{
  public:
    int node_position;
    string name;
};
class road{
  public:
    vector<node> body;
    float length;
    vector<int> lanes;
    float speedLimit; 
};


vector<vector<l_a>> convert_f_TO_rd(File sdFILE){
    //TODO convert algorithm
}

vector<vector<float>> grab_length(vector<vector<l_a>> mtx, string grab){
    int size = mtx.size();
    vector<vector<float>> new_mtx;
    for(unsigned i=0; i<(unsigned)size; i++ ){
        for (unsigned j=0; j<size; j++){
            if (grab == "length"){
            new_mtx[i][j] = mtx[i][j].length;
            }
            if (grab == "angle"){
            new_mtx[i][j] = mtx[i][j].angle;
            }
        }
    }
    return new_mtx;
}

/*
convt_vect_array(vector<vector<float>> vect){ //TODO MAKE FUCNTION FOR CONVERTING 2D VECTOR INTO 2D ARRAY 

}
*/


vector<road_act> shortestpath_algo(vector<vector<l_a>> mtx){
    //TODO shortestpath algorithm
    //grab l_mtx
    //dijstrka func d d(l_mtx)
    //return [ merge d(l_mtx) and (a_mtx) into road_act vector (l,a) structure 
}