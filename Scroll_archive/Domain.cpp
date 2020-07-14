#include "Domain.h"
#include <vector>
#include "StringFunctions.h"

std::istream& operator>>(std::istream& is, Document& element)
{
	std::string line;
	getline(is, line);

	std::vector<std::string> tokens = tokenize(line, '|');
	if (tokens.size() != 3)
		return is;
	element.setName(substring(tokens[0], 0 , -1));
	element.setContent(substring(tokens[2], 1, 0));
	std::vector<std::string> parts;
	parts = tokenize(tokens[1], ',');
	int length = parts.size();
	for(int i = 0; i < length; i++)
		parts[i] = substring(parts[i], 1, 0);
	parts[length - 1] = substring(parts[length - 1], 0, -1);
	element.setKeywords(parts);

	return is;
}

std::ostream& operator<<(std::ostream& os, const Document& element)
{
	std::string partsStr = element.keywordsString();
	os << element.getName() << std::string(" | ") << partsStr << std::string(" | ") << element.getContent() << std::string("\n");
	return os;

}

std::string Document::toString() const
{
	std::string partsStr = this->keywordsString();
	//return this->getName() + std::string(" | ") + partsStr + std::string(" | ") + this->getContent() + std::string("\n");
	return this->getName() + std::string(" | ") + partsStr + std::string("\n");
}

std::string Document::toStringContent() const
{
	std::string partsStr = this->keywordsString();
	return this->getName() + std::string(" | ") + partsStr + std::string(" | ") + this->getContent() + std::string("\n");
}

std::string Document::keywordsString() const
{
	std::string partsStr = "";
	for (auto& part : this->keywords) {
		partsStr += part + ", ";
	}
	partsStr = substring(partsStr, 0, -2);
	return partsStr;
}
