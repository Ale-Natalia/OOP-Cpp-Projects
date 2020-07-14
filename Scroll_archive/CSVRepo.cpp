#include "CSVRepo.h"
#include "Exceptions.h"
#include <cassert>
#include "FileFunctions.h"

int CSVRepo::searchElementByTitle(const std::string& title)
{
	std::ifstream file(this->filename);
	TElement element;
	int index = 0;
	while (file >> element)
	{
		if (element.getName() == title)
		{
			file.close();
			return index;
		}
		index++;
	}
	file.close();
	return -1;
}

void CSVRepo::addElement(const TElement& element)
{
	int positionOfElement = this->searchElementByTitle(element.getName());
	if (positionOfElement != -1)
	{
		throw RepoError(std::string("ELement already in repo!\n"));
	}
	std::ofstream file(this->filename, std::ios::app);
	file << element;
	file.close();
}

void CSVRepo::updateElement(const TElement& element)
{
	std::ifstream file(this->filename);
	TElement elementToRead;
	std::vector<TElement> elements;
	int index = 0;
	int indexToUpdate = -1;
	while (file >> elementToRead)
	{
		if (elementToRead.getName() == element.getName())
		{
			indexToUpdate = index;
			//elementToRead.setCategory(element.getCategory());
			//elementToRead.setQuantity(element.getQuantity());
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
}

void CSVRepo::deleteElement(const TElement& element)
{
	std::ifstream file(this->filename);
	TElement elementToRead;
	std::vector<TElement> elements;
	int index = 0;
	int indexToDelete = -1;
	while (file >> elementToRead)
	{
		if (elementToRead.getName() == element.getName())
		{
			indexToDelete = index;
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
}

std::vector<TElement> CSVRepo::getElements() const
{
	std::vector<TElement> elements;
	std::ifstream file(this->filename);
	TElement element;
	while (file >> element)
	{
		elements.push_back(element);
	}
	file.close();
	return elements;
}

int CSVRepo::getSize()
{
	std::vector<TElement> elements;
	std::ifstream file(this->filename);
	TElement element;
	while (file >> element)
	{
		elements.push_back(element);
	}
	file.close();
	return elements.size();
}

/*
void test_delete_valid()
{
	std::string filename = "testfile.txt";
	CSVRepo repo{ filename };
	Item i1 = Item("Drink", "Milk", 1);
	Item i2 = Item("Drink", "Water", 1);
	Item i3 = Item("Drink", "Juice", 1);
	std::ofstream file;
	file.open(filename);
	clearFile(filename);
	file << i1 << i2 << i3;
	file.close();
	repo.deleteElement(i1);
	assert(repo.searchElementByTitle("Milk") == -1);
}

void test_delete_elementNotInRepo()
{
	std::string filename = "testfile.txt";
	CSVRepo repo{ filename };
	Item i1 = Item("Drink", "Milk", 1);
	Item i2 = Item("Drink", "Water", 1);
	Item i3 = Item("Drink", "Juice", 1);
	std::ofstream file;
	file.open(filename);
	clearFile(filename);
	file << i1 << i2;
	file.close();
	try {
		repo.deleteElement(i3);
		assert(false);
	}
	catch (Exception& error) {
		assert(error.message == std::string("ELement not in repo!\n"));
	}
}
*/