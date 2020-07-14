#pragma once
#include <string>
#include <iostream>
#include <vector>

class Star {
private:
	std::string name;
	std::string constellation;
	int RA;
	int Dec;
	int diameter;
public:
	Star() {
		this->name = "";
		this->constellation = "";
		this->RA = 0;
		this->Dec = 0;
		this->diameter = 0;
	}
	Star(std::string name, std::string constellation, int RA, int Dec, int diameter) {
		this->name = name;
		this->constellation = constellation;
		this->RA = RA;
		this->Dec = Dec;
		this->diameter = diameter;
	}
	Star(const Star& star) {
		this->name = star.name;
		this->constellation = star.constellation;
		this->RA = star.RA;
		this->Dec = star.Dec;
		this->diameter = star.diameter;
	}
	~Star(){}

	std::string getName() const { return this->name; }
	std::string getConstellation() const { return this->constellation; }
	int getRA() const { return this->RA; }
	int getDec() const { return this->Dec; }
	int getDiameter() const { return this->diameter; }

	void setName(std::string name) { this->name = name; }
	void setConstellation(std::string constellation) { this->constellation = constellation; }
	void setRA(int RA) { this->RA = RA; }
	void setDec(int Dec) { this->Dec = Dec; }
	void setDiameter(int diameter) { this->diameter = diameter; }
	friend std::istream& operator>>(std::istream& is, Star& star);
	friend std::ostream& operator<<(std::ostream& os, const Star& student);

	void operator=(const Star& student);
	bool operator==(const Star& student);

	std::string toString();
};

class User {
private:
	std::string name;
	std::string constellation;
public:
	User() {
		this->name = "";
		this->constellation = "";
	}
	User(std::string name, std::string constellation) {
		this->name = name;
		this->constellation = constellation;
	}
	User(const User& user) {
		this->name = user.name;
		this->constellation = user.constellation;
	}
	~User(){}

	std::string getName() const { return this->name; }
	void setName(std::string name) { this->name = name; }
	std::string getConstellation() const { return this->constellation; }
	void setConstellation(std::string constellation) { this->constellation = constellation; }

	friend std::istream& operator>>(std::istream& is, User& user);
	friend std::ostream& operator<<(std::ostream& os, const User& user);

	void operator=(const User& user);
	bool operator==(const User& user);
};