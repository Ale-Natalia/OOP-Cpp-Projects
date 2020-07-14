#pragma once
#include "FileRepository.h"
#include <vector>
#include "Domain.h"
#include <iostream>

typedef Document TElement;

class CSVRepo : public FileRepository {
public:
	CSVRepo() {
		this->filename = "goblin.txt";
		std::fstream file;
		file.open(this->filename, std::fstream::in | std::fstream::out | std::fstream::app);
		file.close();
	};

	CSVRepo(const std::string& filename)
	{
		this->filename = filename;
		std::fstream file;
		file.open(this->filename, std::fstream::in | std::fstream::out | std::fstream::app);
		file.close();
	};
	/*
	searches for an element with the given title in the repository
	returns the position if the element was found
	returns -1 if the element does not exist
	*/
	int searchElementByTitle(const std::string& title)override;

	/*
		adds an element to the repository
		throws error if invalid
	*/
	void addElement(const TElement& element)override;

	/*
		updates the info of a given element from the repository
		throws error if invalid
	*/
	void updateElement(const TElement& element)override;

	/*
		removes an element from the repository
		throws error if invalid
	*/
	void deleteElement(const TElement& element)override;

	//getter for all the elements in the repository
	std::vector<TElement> getElements() const override;

	//getter for the size of the dynamic vector in the repo
	int getSize()override;

};

void test_delete_valid();
void test_delete_elementNotInRepo();