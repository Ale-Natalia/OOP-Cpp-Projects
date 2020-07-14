#pragma once
#include "FileRepository.h"

template <typename TElement>
class CSVRepo : public FileRepository<TElement> {
public:
	CSVRepo() {
		this->filename = "exam.txt";
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
	int searchElementByName(const std::string& name)override {
		std::ifstream file(this->filename);
		TElement element;
		int index = 0;
		while (file >> element)
		{
			if (element.getName() == name)
			{
				file.close();
				return index;
			}
			index++;
		}
		file.close();
		return -1;
	};

	/*
	searches for an element
	returns the position if the element was found
	returns -1 if the element does not exist
	*/
	int searchElement(const TElement& element)override {
		std::ifstream file(this->filename);
		TElement elementToRead;
		int index = 0;
		while (file >> elementToRead)
		{
			if (elementToRead == element)
			{
				file.close();
				return index;
			}
			index++;
		}
		file.close();
		return -1;
	};

	/*
		adds an element to the repository
		throws error if invalid
	*/
	void addElement(const TElement& element)override {
		int positionOfElement = this->searchElement(element);
		if (positionOfElement != -1)
		{
			throw RepoError(std::string("ELement already in repo!\n"));
		}
		std::ofstream file(this->filename, std::ios::app);
		file << element;
		file.close();
		this->notify();
	};

	/*
		updates the info of a given element from the repository
		throws error if invalid
	*/
	TElement updateElement(const TElement& element)override {
		std::ifstream file(this->filename);
		TElement elementToRead;
		std::vector<TElement> elements;
		int index = 0;
		int indexToUpdate = -1;
		TElement oldElement;
		while (file >> elementToRead)
		{
			if (elementToRead == element) {
				indexToUpdate = index;
				oldElement = elementToRead;
				elementToRead = element;
			}
			elements.push_back(elementToRead);
			index++;
		}
		file.close();
		if (indexToUpdate == -1)
		{
			throw RepoError(std::string("ELement not in repo!\n"));
		}
		std::ofstream fileWrite(this->filename);
		for (auto& element : elements)
		{
			fileWrite << element;
		}
		fileWrite.close();
		this->notify();
		return oldElement;
	};

	/*
		removes an element from the repository
		throws error if invalid
	*/
	TElement deleteElement(const TElement& element)override {
		std::ifstream file(this->filename);
		TElement elementToRead;
		TElement deletedElement;
		std::vector<TElement> elements;
		int index = 0;
		int indexToDelete = -1;
		while (file >> elementToRead)
		{
			if (elementToRead == element) {
				indexToDelete = index;
				deletedElement = elementToRead;
			}
			else
			{
				elements.push_back(elementToRead);
			}
			index++;
		}
		file.close();

		if (indexToDelete == -1)
		{
			throw RepoError(std::string("ELement not in repo!\n"));
		}

		std::ofstream fileWrite(this->filename);
		for (auto& element : elements)
		{
			fileWrite << element;
		}
		fileWrite.close();
		this->notify();
		return deletedElement;
	};

	//getter for all the elements in the repository
	std::vector<TElement> getElements() override {
		std::vector<TElement> elements;
		std::ifstream file(this->filename);
		TElement element;
		while (file >> element)
		{
			elements.push_back(element);
		}
		file.close();
		return elements;
	};

	//getter for the size of the dynamic vector in the repo
	int getSize()override {
		std::vector<TElement> elements;
		std::ifstream file(this->filename);
		TElement element;
		while (file >> element)
		{
			elements.push_back(element);
		}
		file.close();
		return elements.size();
	};

};