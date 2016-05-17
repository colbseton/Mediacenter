#ifndef TOOLS_H
#define TOOLS_H

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <ctime>
#include <algorithm>

std::vector<std::string> split(const std::string& str, char delim);

int compareStrLow(std::string, std::string);

void get_input(std::string& input);

#endif  //TOOLS_H