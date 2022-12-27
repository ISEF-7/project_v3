#include "common.h"
#include "map.h"
#include "m.h"
#include <limits.h>

using namespace std;

vector<road_act> actonslist;
SdFat sd;
File sdFILE_path;

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

char line[40];
char* skipSpace(char* str) {
  while (isspace(*str)) str++;
  return str;
}
bool parseLine(char* str) {
  char* ptr;

  // Set strtok start of line.
  str = strtok(str, ",");
  if (!str) return false;

  // Print text field.
  Serial.println(str);

  // Subsequent calls to strtok expects a null pointer.
  str = strtok(nullptr, ",");
  if (!str) return false;

  // Convert string to long integer.
  int32_t i32 = strtol(str, &ptr, 0);
  if (str == ptr || *skipSpace(ptr)) return false;
  Serial.println(i32);

  str = strtok(nullptr, ",");
  if (!str) return false;

  // strtoul accepts a leading minus with unexpected results.
  if (*skipSpace(str) == '-') return false;

  // Convert string to unsigned long integer.
  uint32_t u32 = strtoul(str, &ptr, 0);
  if (str == ptr || *skipSpace(ptr)) return false;
  Serial.println(u32);

  str = strtok(nullptr, ",");
  if (!str) return false;

  // Convert string to double.
  double d = strtod(str, &ptr);
  if (str == ptr || *skipSpace(ptr)) return false;
  Serial.println(d);

  // Check for extra fields.
  return strtok(nullptr, ",") == nullptr;
}

vector<vector<l_a>> convert_f_TO_rd(string sdFILE_path){
    /*
    File file;
    if (!file.open(sdFILE_path, FILE_WRITE)){ //FIXME no matching function for call to 'File32::open(std::string&, int)'
    cout << "open failed";
    }
    file.rewind();
    while (file.available()) {
    int n = file.fgets(line, sizeof(line));
    if (n <= 0) {
      cout << "fgets failed";
    }
    if (line[n-1] != '\n' && n == (sizeof(line) - 1)) {
        cout << "line too long";
    }
    if (!parseLine(line)) {
      cout << "parseLine failed";
    }
    Serial.println();
    }
    */
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