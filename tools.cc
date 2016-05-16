#include "tools.h"


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

int compareStrLow(string s1, string s2) {
    /* lowers all the characters and 
       find a sub-str in s2, no side effect
    */

    transform(s1.begin(), s1.end(), s1.begin(), 
              [](unsigned char c) { return tolower(c); } );

    transform(s2.begin(), s2.end(), s2.begin(), 
              [](unsigned char c) { return tolower(c); } );

    return ( s1.find(s2.c_str()) != string::npos );
}