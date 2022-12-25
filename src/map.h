#ifndef MAP_H
#define MAP_H


using namespace std;

class location{
  public:
    string name;
    int node_position;
};


class node : location{
  public:

};

class road{
  public:
    vector<node> body;
    float length;
    vector<int> lanes;
    float speedLimit; 
};



struct roadData{
  vector<vector<float>> lengthmtx_data;
  location i_location;
  location destination;
};

roadData shortestpathAlgorithm(){

}


#endif