#pragma once
#include <string>
#include <vector>
#include <fstream>

void clearFile(const std::string& filename);

//returns a vector of strings
//the file format is of n lines, each containing the word "inmemory" or a filename
std::vector<std::string> readConfigurationFile(const std::string& filename);