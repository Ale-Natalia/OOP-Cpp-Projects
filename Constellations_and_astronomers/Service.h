#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "Domain.h"
#include "Repository.h"
#include "CSVRepo.h"
#include "Observer.h"
#include "StringFunctions.h"
#include "Exceptions.h"
#include <cassert>

typedef Star Item;

class Service : public Observable {
private:
	Repository<Item>* repository;
	std::string itemFile;
public:
	Service() { this->repository = new CSVRepo<Item>(); }
	Service(std::string itemFile) {
		this->itemFile = itemFile;
		this->repository = new CSVRepo<Item>(itemFile);
		this->notify();
	}
	Service(Service* service) {
		this->itemFile = service->itemFile;
		this->repository = service->repository;
		this->notify();
	}
	~Service() {  }

	Repository<Item>* getRepo();

	std::vector<Item> getAllItems();
	std::vector<Item> getAllItemsOfUser(User* user);

	//adds a constellation with the given data if valid and notifies the observer
	//throws exception if the name is empty, there is another star with the same name, or the diameter is <= 0
	void add(std::string name, std::string constellation, int RA, int Dec, int DA);

	//sorts stars by constellation
	std::vector<Item> sortStarsByConstellation(std::vector<Item> stars)const;

	//ID or name matches returned
	std::vector<Item> matchElements(const std::string& wordToMatch);

	int getNumberOfItemsForUser(User* user) { return 0; };
	//int getNumberOfStudentsWithNoTeacher();

	//void addCoordinatorToStudent(Astronomer* astronomer, Student* student);
	//void updateStudentEmail(Student* student, std::string email);
	//void updateStudentThesisTitle(Student* student, std::string thesisTitle);
};

/*
void testAddValid();
void testAddInvalidElementInRepo();
void testAddInvalidEmptyTitle();
void testAddInvalidNegativeDiameter();
*/