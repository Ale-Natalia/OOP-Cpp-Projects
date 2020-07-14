#pragma once
#include <iostream>
#include <string>
#include "StringFunctions.h"

class Date {
private:
	int year;
	int month;
	int day;

public:
	Date();

	Date(const int& month, const int& day, const int& year);

	std::string toString() const;

	static Date fromString(const std::string givenString);
};