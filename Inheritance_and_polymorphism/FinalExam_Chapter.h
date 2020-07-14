#pragma once
#include <string>

class Checker {
public:
	//Checker(){}
	virtual bool check(Section* s) = 0;
};

class TitleChecker : public Checker {
public:
	//TitleChecker() : Checker() {};
	bool check(Section* s)override {

	}
};

class Section {
protected:
	std::string title;
	std::string content;
	Checker* checker;
public:
	Section() {
		this->checker = NULL;
	}
	virtual void addSection(Section* s) = 0;
	void generate() {
		
	};
};
