#include "tools.h"

#include <limits>

using namespace std;

void get_input(string& input) {
    cout << "> ";
    getline(cin, input);
}

vector<string> split(const string& str, char delim) { 
    stringstream str_c(str);
    vector<string> res; 
    string val; 

    while (getline(str_c, val, delim)) 
        res.push_back(val); 
    
    return res; 
}  
