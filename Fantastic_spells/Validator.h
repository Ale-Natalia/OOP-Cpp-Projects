#pragma once
#include <string>
#include "Date.h"
#include "Task.h"

class Validator {
public:
	// returns the date from string or raises error if it is invalid
	Date validateDate(std::string date);

	//returns the int from the string or throws error if it is invalid
	int validateInteger(std::string integer);

	//returns the task from the string or raises an error if it is invalid
	Task validateTask(std::string title, std::string type, Date lastPerformed, int timesPerformed, std::string vision);
};