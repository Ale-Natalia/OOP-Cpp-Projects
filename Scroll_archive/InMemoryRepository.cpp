#include "InMemoryRepository.h"
#include "Exceptions.h"

int InMemoryRepository::searchElementByTitle(const std::string& title)
{
	int size = this->elements.size();
	for (auto& element : this->elements)
	{
		if (element.getName() == title)
		{
			int index = &element - &this->elements[0];
			return index;
		}
	}
	return -1;
}

void InMemoryRepository::addElement(const TElement& element)
{
	int positionOfElement = this->searchElementByTitle(element.getName());
	if (positionOfElement != -1)
	{
		throw RepoError(std::string("ELement already in repo!\n"));
	}
	this->elements.push_back(element);
}

void InMemoryRepository::deleteElement(const TElement& element)
{
	int positionOfElement = this->searchElementByTitle(element.getName());
	if (positionOfElement == -1)
	{
		throw RepoError(std::string("ELement not in repo!\n"));
	}
	this->elements.erase(this->elements.begin() + positionOfElement);
}

void InMemoryRepository::updateElement(const TElement& element)
{
	int positionOfElement = this->searchElementByTitle(element.getName());
	if (positionOfElement == -1)
	{
		throw RepoError(std::string("ELement not in repo!\n"));
	}
	//this->elements[positionOfElement].setCategory(element.getCategory());
	this->elements[positionOfElement].setName(element.getName());
}

int InMemoryRepository::getSize()
{
	return this->elements.size();
}
