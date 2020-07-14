#include "StringFunctions.h"
#include "Exceptions.h"
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

std::vector<std::string> tokenize(const std::string& str, char delimiter)
{
	std::vector<std::string> result;
	std::stringstream ss(str);
	std::string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);
	return result;
}

std::string join(std::vector<std::string> parts, int startPosition, int endPosition, char delimiter)
{
	std::string result = "";
	for (std::vector<std::string>::iterator iterator = parts.begin() + startPosition; iterator != parts.begin() + endPosition; iterator++)
		result += *iterator + delimiter;
	result += *(parts.begin() + endPosition);
	return result;
}

void removeComma(std::string& inputWord)
{
	if (inputWord[inputWord.length() - 1] == ',')
		inputWord.erase(inputWord.end() - 1);
	else
		//raise exception
		throw InvalidInputError("You seem to have forgotten some commas there, young folk!\n");
}

std::string substring(std::string string, int startPosition, int endPosition)
{
	std::string result = "";
	std::string::iterator end_iterator;
	std::string::iterator start_iterator;
	if (startPosition >= 0)
		start_iterator = string.begin() + startPosition;
	else if (startPosition < 0)
		start_iterator = string.end() + startPosition;
	if (endPosition > 0)
		end_iterator = string.begin() + endPosition;
	else if (endPosition <= 0)
		end_iterator = string.end() + endPosition;
	for (std::string::iterator iterator = start_iterator; iterator != end_iterator; iterator++)
		result += *iterator;
	return result;
}

bool filenameEnding(std::string filename, std::string validEnding)
{
	int extensionLength = validEnding.size();
	std::string actualExtension = "";
	for (std::string::iterator iterator = filename.end() - extensionLength; iterator != filename.end(); iterator++)
		actualExtension += *iterator;
	if (actualExtension != validEnding)
		return false;
}

std::string htmlBodyBeginning()
{
	return "<!DOCTYPE html>\n<html>\n<head>\n<title>MyList</title>\n</head>\n<body>\n<table border = \"1\">\n<tr>\n<td>Title</td>\n<td>Type</td>\n<td>LastPerformed</td>\n<td>TimesPerformed</td>\n<td>Vision</td>\n</tr>\n";
}

std::string htmlBodyEnd()
{
	return "</table>\n</body>\n</html>";
}