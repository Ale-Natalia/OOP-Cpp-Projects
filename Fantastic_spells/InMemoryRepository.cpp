#include "InMemoryRepository.h"
#include "Exceptions.h"

int InMemoryRepository::searchElementByTitle(const std::string& title)
{
	int size = this->elements.size();
	for (auto& element : this->elements)
	{
		if (element.getTitle() == title)
		{
			int index = &element - &this->elements[0];
			return index;
		}
	}
	return -1;
}

void InMemoryRepository::addElement(const TElement& element)
{
	int positionOfElement = this->searchElementByTitle(element.getTitle());
	if (positionOfElement != -1)
	{
		throw RepoError(std::string("ELement already in repo!\n"));
	}
	this->elements.push_back(element);
}

TElement InMemoryRepository::deleteElement(const TElement& element)
{
	int positionOfElement = this->searchElementByTitle(element.getTitle());
	if (positionOfElement == -1)
	{
		throw RepoError(std::string("ELement not in repo!\n"));
	}
	TElement deletedElement = this->elements[positionOfElement];
	this->elements.erase(this->elements.begin() + positionOfElement);
	return deletedElement;
}

TElement InMemoryRepository::updateElement(const TElement& element)
{
	int positionOfElement = this->searchElementByTitle(element.getTitle());
	TElement oldElement = this->elements[positionOfElement];
	if (positionOfElement == -1)
	{
		throw RepoError(std::string("ELement not in repo!\n"));
	}
	this->elements[positionOfElement].setType(element.getType());
	this->elements[positionOfElement].setLastPerformed(element.getLastPerformed());
	this->elements[positionOfElement].setTimesPerformed(element.getTimesPerformed());
	this->elements[positionOfElement].setVision(element.getVision());
	return oldElement;
}

int InMemoryRepository::getSize()
{
	return this->elements.size();
}
