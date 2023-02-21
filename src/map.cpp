#include "common.h"

using namespace std;

vector<road_act> actonslist;
class node{
  public:
    int node_position;
    string name;
    float angle;
    //trafficlightstate trafficlightstate; TODO
    //pedestrianstate pedestrianstate; TODO
};
class road{
  public:
    vector<node> body;
    float length;
    //vector<int> lanes;
    float speedLimit; 
};
//TODO later add SD file reading
int test(){
  int x = 3;
  return x;
}
vector<vector<int>> test31(){
    return {{10,5,3,3}};
}
vector<vector<float>> test2(){
  return {{3,5},{1,3}};
}
bool check (vector<vector<float>> vec, int _square){ //CHECKED
  for (int i = 0; i < _square; i++){
    if (vec[i][i] != 0 || vec[i][i] != 0){
      return false;
    }
  }
  for (int i =0; i < _square; i++){
    for (int j = 0; j < _square; j++){
      if (vec[i][j] != vec[j][i] || vec[i][j] != vec[j][i]){
        return false;
      }
    }
  }
  return true;
}
int ascii(int c){ //CHECKED
    return c-48;
}
float toFloat(string s, int base){ //CHECKED
    int l = s.length();
    bool is_dec = false;
    int dec_ind=0;
    for (int v=0; v<l;v++){
        if(s.at(v) == '.'){
            dec_ind = v;
            is_dec = true;
        }
    }
    if (is_dec == true){
        int left = 0;
        float right = 0;
        for(int i=0; i<dec_ind; i++){
            int a = pow(base,dec_ind-i-1)*ascii(s.at(i));
            left = left + a;
        }
        for(int j=dec_ind+1; j<l;j++){
            float b = pow(pow(base,j-dec_ind),-1)*ascii(s.at(j));
            right = right + b;
        }
        float sum = left + right;
        return sum;
    }
    else{
        int mid = 0;
        for(int k=0; k<l; k++){
            int m = pow(base,l-k-1)*ascii(s.at(k));
            mid = mid + m;
        }
        return mid;
    }
}
vector<vector<float>> convert_f_TO_2d(string str){  //CHECKED 
  vector<vector<float>> rd;
  int size=0;
  bool size_def = false;
  vector<float> push;
  float minipush;
  string stringdigits;
  for (int i = 0;i<str.length();i++){
    if (str[i] != ' ' && str[i] != '%'){
      stringdigits.push_back(str[i]);
    }
    if (str[i] == ' '){
      minipush = toFloat(stringdigits,10);
      stringdigits = "";
      push.push_back(minipush);
      minipush = 0;
    }
    if (str[i] == '%'){
      size = i + 1;
      size_def = true;
      rd.push_back(push);
      push.clear();
    }
  }
  if (check(rd, size) == true){return rd;}
  //else{cout << "conv[f,r/a] err"; return;}
}

vector<float> convert_f_TO_1d(string str){ //CHECKED
  vector<float> s;
  float minipush;
  string stringdigits;
  for (int i=0;i<str.length();i++){
    if (str.at(i) != ' ' && str.at(i) != '%'){
        stringdigits = stringdigits + str.at(i);
    }
    else if (str.at(i) == ' ' || str.at(i) == '%'){
        minipush = toFloat(stringdigits,10);
        s.push_back(minipush);
        stringdigits = "";
    }
  }
  return s;
  //else{cout << "conv[f,s] err"; return ;}
}
vector<string> div(string str){ //CHECKED
  int ind_a;
  int ind_b;
  int ind_c;
  vector<string> ret_vec;
  for(unsigned int i = 0; i<str.length();i++){
    int count=0;
    if(str.at(i) == '|'){
      count++;
      if (count == 1){
        ind_a = i;
      }
      if (count == 2){
        ind_b = i;
      }
      if (count == 3){
        ind_c = i;
      }
    }
  }
  ret_vec = {str.substr(0,ind_a-1),str.substr(ind_a+1,ind_b-ind_a-1),str.substr(ind_b+1,ind_c-ind_a)};
}
vector<road_act> shortestpath_algo(vector<vector<float>> l_mtx, vector<vector<float>> a_mtx, vector<float> s_mtx){
    //TODO shortestpath algorithm
    //grab l_mtx
    //dijstrka func d d(l_mtx)
    //return [ merge d(l_mtx), (a_mtx), and (s_mtx) into road_act vector (l,a,s) structure ]1111
}