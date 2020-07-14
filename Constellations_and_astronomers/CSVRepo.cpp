#include "CSVRepo.h"
#include "Exceptions.h"

/*
template <typename TElement>
int CSVRepo<TElement>::searchElementByName(const std::string& name)
{
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
}

template <typename TElement>
int CSVRepo<TElement>::searchElement(const TElement& element)
{
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
}

template <typename TElement>
void CSVRepo<TElement>::addElement(const TElement& element)
{
	int positionOfElement = this->searchElement(element);
	if (positionOfElement != -1)
	{
		throw RepoError(std::string("ELement already in repo!\n"));
	}
	std::ofstream file(this->filename, std::ios::app);
	file << element;
	file.close();
	this->notify();
}

template <typename TElement>
TElement CSVRepo<TElement>::updateElement(const TElement& element)
{
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
}

template <typename TElement>
TElement CSVRepo<TElement>::deleteElement(const TElement& element)
{
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
}

template <typename TElement>
std::vector<TElement> CSVRepo<TElement>::getElements()
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

template <typename TElement>
int CSVRepo<TElement>::getSize()
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
*/