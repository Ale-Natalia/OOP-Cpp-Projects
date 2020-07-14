#include "CSVRepo.h"
#include "Exceptions.h"

int CSVRepo::searchElementByTitle(const std::string& title)
{
	std::ifstream file(this->filename);
	TElement element;
	int index = 0;
	while (file >> element)
	{
		if (element.getTitle() == title)
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
	int positionOfElement = this->searchElementByTitle(element.getTitle());
	if (positionOfElement != -1)
	{
		throw RepoError(std::string("ELement already in repo!\n"));
	}
	std::ofstream file(this->filename, std::ios::app);
	file << element;
	file.close();
	this->notify();
}

TElement CSVRepo::updateElement(const TElement& element)
{
	std::ifstream file(this->filename);
	TElement elementToRead;
	std::vector<TElement> elements;
	int index = 0;
	int indexToUpdate = -1;
	TElement oldElement;
	while (file >> elementToRead)
	{
		if (elementToRead.getTitle() == element.getTitle())
		{
			indexToUpdate = index;
			oldElement = elementToRead;
			elementToRead.setType(element.getType());
			elementToRead.setLastPerformed(element.getLastPerformed());
			elementToRead.setTimesPerformed(element.getTimesPerformed());
			elementToRead.setVision(element.getVision());
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
}

TElement CSVRepo::deleteElement(const TElement& element)
{
	std::ifstream file(this->filename);
	TElement elementToRead;
	TElement deletedElement;
	std::vector<TElement> elements;
	int index = 0;
	int indexToDelete = -1;
	while (file >> elementToRead)
	{
		if (elementToRead.getTitle() == element.getTitle())
		{
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
