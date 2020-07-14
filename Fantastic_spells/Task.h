#pragma once
#include <iostream>
#include <string>
#include "Date.h"

class Task
{
private:
	std::string title;
	std::string type;
	Date lastPerformed;
	int timesPerformed;
	std::string vision;
public:
	//default constructor for a Task
	Task();

	//constructor with parameters
	Task(const std::string& title, const std::string& type, const Date& lastPerformed, const int& timesPerformed, const std::string& vision);

	//copy constructor for a Task
	//Task(const Task& task);

	std::string getTitle() const { return this->title; }

	std::string getType() const { return this->type; }

	Date getLastPerformed() const { return this->lastPerformed; }

	int getTimesPerformed() const { return this->timesPerformed; }

	std::string getVision() const { return this->vision; }

	void setTitle(std::string newTitle) { this->title = newTitle; }

	void setType(std::string newType) { this->type = newType; }

	void setLastPerformed(Date newLastPerformed) { this->lastPerformed = newLastPerformed; }

	void setTimesPerformed(int newTimesPerformed) { this->timesPerformed = newTimesPerformed; }

	void setVision(std::string newVision) { this->vision = newVision; }

	//returns a string with the data of the Task
	std::string toString() const;

	//returns a string creating a line with the given data in a html table
	std::string toHTMLline() const;

	friend std::istream& operator>>(std::istream& is, Task& task);
	friend std::ostream& operator<<(std::ostream& os, const Task& task);
};