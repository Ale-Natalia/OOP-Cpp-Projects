#include "Validator.h"
#include <exception>
#include "StringFunctions.h"
#include "Exceptions.h"

/*
Date Validator::validateDate(std::string date)
{
	int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	std::vector<std::string> parts;
	parts = tokenize(date, '-');
	if (parts.size() != 3)
		throw InvalidInputError("Date must be month-day-year\n");
	int month = this->validateInteger(parts[0]);
	int day = this->validateInteger(parts[1]);
	int year = this->validateInteger(parts[2]);
	if (month == 0 || month > 12)
	{
		throw InvalidInputError("Month must be 1-12\n");
	}
	if (day == 0)
	{
		throw InvalidInputError("Day must be positive\n");
	}
	if (day > daysInMonth[month] && !(year % 4 == 0 && month == 2 && day == 29))
	{
		throw InvalidInputError("There can't be as many days in this month of the rat's year\n");
	}
	return Date(month, day, year);
}
*/

int Validator::validateInteger(std::string integer)
{
	try
	{
		int result = stoi(integer);
		return result;
	}
	catch (std::exception&)
	{
		throw InvalidInputError("This is not an integer!\n");
	}
}

