#include "Date.h"

Date::Date() : month(0), day(0), year(0) {}

Date::Date(const int& month, const int& day, const int& year)
{
	this->month = month;
	this->day = day;
	this->year = year;
}

std::string Date::toString() const
{
	return std::to_string(this->month) + "-" + std::to_string(this->day) + "-" + std::to_string(this->year);
}

Date Date::fromString(const std::string givenString)
{
	std::vector<std::string> dateElements;
	dateElements = tokenize(givenString, '-');
	int month = std::stoi(dateElements[0], nullptr, 10);
	int day = std::stoi(dateElements[1], nullptr, 10);
	int year = std::stoi(dateElements[2], nullptr, 10);
	return Date(month, day, year);
}
