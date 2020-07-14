#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

//tokenizes a given string wrt a delimiter
std::vector<std::string> tokenize(const std::string& str, char delimiter);

//joins the strings in a vector from start position to end position in a single string, with a given delimiter
std::string join(std::vector<std::string> parts, int startPosition, int endPosition, char delimiter);

//removes the comma from the end of an input word or raises an error if there is no comma
void removeComma(std::string& inputWord);

//returns the substring from first character to last character
//position is negative, it represents the offset from the end of the string (-1 = last character)
std::string substring(std::string string, int startPosition, int endPosition);

//turns a given string to lowercase
std::string stringToLower(const std::string& inputString);

//checks whether a filename has the given ending
bool filenameEnding(std::string filename, std::string validEnding);

std::string htmlBodyBeginning();

std::string htmlBodyEnd();