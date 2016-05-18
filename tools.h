#ifndef TOOLS_H
#define TOOLS_H

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm> // std::transform

std::vector<std::string> split(const std::string& str, char delim);

int compareStrLow(std::string, std::string);

void get_input(std::string& input);

template<typename T>
void myClearFree(std::vector<T*>& vec) {
    for(auto it : vec) {
        delete it;
    }

    vec.clear();
}

#endif  //TOOLS_H