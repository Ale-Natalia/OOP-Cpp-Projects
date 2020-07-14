#include "Task.h"
#include <string>
#include <sstream>
#include <vector>
#include "StringFunctions.h"

//Task::Task(std::string title, std::string type, std::string lastPerformed, int timesPerformed, std::string vision)
Task::Task() : title(""), type(""), lastPerformed(Date(1, 1, 0)), timesPerformed(0), vision("") {}

Task::Task(const std::string& title, const std::string& type, const Date& lastPerformed, const int& timesPerformed, const std::string& vision)
{
	this->title = title;
	this->type = type;
	this->lastPerformed = lastPerformed;
	this->timesPerformed = timesPerformed;
	this->vision = vision;
}

std::string Task::toString() const
{
	return this->getTitle() + " of type " + this->getType() + " last performed " + this->getLastPerformed().toString() + ", performed " + std::to_string(this->getTimesPerformed()) + " times, with the vision " + this->getVision();
}

std::string Task::toHTMLline() const
{
	return "<tr>\n<td>" + this->title + "</td>\n<td>" + this->type + "</td>\n<td>" + this->lastPerformed.toString() + "</td>\n<td>" + std::to_string(this->timesPerformed) + "</td>\n<td>" + this->vision + "</td>\n</tr>\n";
}

std::istream& operator>>(std::istream& is, Task& task)
{
	std::string line;
	getline(is, line);

	std::vector<std::string> tokens = tokenize(line, ',');
	if (tokens.size() != 5)
		return is;
	task.setTitle(tokens[0]);
	task.setType(tokens[1]);
	task.setLastPerformed(Date::fromString(tokens[2]));
	task.setTimesPerformed(std::stoi(tokens[3]));
	task.setVision(tokens[4]);

	return is;
}

std::ostream& operator<<(std::ostream& os, const Task& task)
{
	os << task.getTitle() << "," << task.getType() << "," << task.getLastPerformed().toString() << "," << std::to_string(task.getTimesPerformed()) << "," << task.getVision() << "\n";
	return os;
}
