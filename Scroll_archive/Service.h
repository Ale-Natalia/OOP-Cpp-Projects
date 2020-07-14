#pragma once
#include "Repository.h"
#include "InMemoryRepository.h"
#include "FileRepository.h"
#include "CSVRepo.h"
#include "HTMLRepo.h"
#include "Validator.h"
#include "FileFunctions.h"
#include <utility>
#include <vector>
#include <string>
#include "StringFunctions.h"

class Service {
private:
	Repository* repository;
	Validator* validator;

	static FileRepository* createRepoBasedOnExtension(const std::string& filename);
public:
	Service() { this->repository = new InMemoryRepository, this->validator = new Validator; };
	~Service();


	int getRepoSize() const;

	std::vector<TElement> getAllElementsInRepository() const;

	TElement search(const std::string& name)const;



	

	//returns a vector of elements whose names/keywords match a given word
	std::vector<TElement> matchElements(const std::string& wordToMatch)const;

	//returns the element whose name/keywords match best a given word
	TElement bestMatching(const std::string& wordToMatch)const;

	//CUSTODIAN OPERATIONS

	/*
		adds an element
		throws error if element already in repo/invalid
	*/
	//void addTaskService(const std::string& title, const std::string& type, const std::string& lastPerformed, const std::string& timesPerformed, const std::string& vision);

	/*
		updates the info of a given task
		throws error if element not already in repo/invalid
	*/
	//void updateTaskService(const std::string& title, const std::string& type, const std::string& lastPerformed, const std::string& timesPerformed, const std::string& vision);

	/*
		removes an element from the repository
		throws error if element not already in repo/invalid
	*/
	void deleteElementService(const std::string& name);

	std::vector<TElement> filter(const std::string& category);

	//returns a vector of all families, each only once
	//std::vector<std::string> getFamilies()const;

	//return respo filename
	std::string getRepoFilename();

	//sets the repo filename
	void setRepoFilename(const std::string& filename);

	//returns a vector of pairs type: number of items with given type
	//std::vector<std::pair<std::string, int>> typeStatistics();
};