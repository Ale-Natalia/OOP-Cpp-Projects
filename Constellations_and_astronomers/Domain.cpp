#include "Domain.h"
#include "StringFunctions.h"

std::istream& operator>>(std::istream& is, Star& star)
{

	std::string line;
	getline(is, line);

	std::vector<std::string> starAttributes = tokenize(line, ',');
	if (starAttributes.size() != 5)
		return is;
	star.name = starAttributes[0];
	star.constellation = starAttributes[1];
	star.RA = std::stoi(starAttributes[2]);
	star.Dec = std::stoi(starAttributes[3]);
	star.diameter = std::stoi(starAttributes[4]);
	return is;
}

std::ostream& operator<<(std::ostream& os, const Star& star)
{
	os << star.name << "," << star.constellation << "," << star.RA << "," << star.Dec << "," << star.diameter << "\n";
	return os;
}

void Star::operator=(const Star& star)
{
	this->name = star.name;
	this->constellation = star.constellation;
	this->RA = star.RA;
	this->Dec = star.Dec;
	this->diameter = star.diameter;
}

bool Star::operator==(const Star& star)
{
	return this->name == star.name;
}

std::string Star::toString()
{
	return this->name + "," + this->constellation + "," + std::to_string(this->RA) + "," + std::to_string(this->Dec) + "," + std::to_string(this->diameter) + "\n";
}


std::istream& operator>>(std::istream& is, User& user)
{
	std::string line;
	getline(is, line);

	std::vector<std::string> userAttributes = tokenize(line, ',');
	if (userAttributes.size() != 2)
		return is;
	user.setName(userAttributes[0]);
	user.setConstellation(userAttributes[1]);
	return is;
}

std::ostream& operator<<(std::ostream& os, const User& user)
{
	os << user.name << " " << user.constellation << "\n";
	return os;
}


void User::operator=(const User& user)
{
	this->name = user.name;
	this->constellation = user.constellation;
}

bool User::operator==(const User& user)
{
	return this->name == user.name;
}
