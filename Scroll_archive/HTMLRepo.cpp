#include "HTMLRepo.h"
#include "Exceptions.h"
#include <fstream>
#include <iostream>
#include <string>
#include "FileFunctions.h"

int HTMLRepo::searchElementByTitle(const std::string& givneTitle)
{
	/*
	std::ifstream file(this->filename);
	TElement elementToRead;
	int index = 0;
	int indexToUpdate = -1;
	std::string line_string;
	int numberOfUnnecessayLines = 15;
	for (int line = 0; line < numberOfUnnecessayLines; line++)
	{
		std::getline(file, line_string);
	}
	while (line_string == "<tr>")
	{
		int lastPositionOfBeginningOfLineToIgnore = 4;
		int firstPositionOfEndOfLineToIgnore = -5;
		std::string title;
		std::getline(file, title);
		title = substring(title, lastPositionOfBeginningOfLineToIgnore, firstPositionOfEndOfLineToIgnore);
		elementToRead.setTitle(title);
		std::string type;
		std::getline(file, type);
		type = substring(type, lastPositionOfBeginningOfLineToIgnore, firstPositionOfEndOfLineToIgnore);
		elementToRead.setType(type);
		std::string lastPerformed;
		std::getline(file, lastPerformed);
		lastPerformed = substring(lastPerformed, lastPositionOfBeginningOfLineToIgnore, firstPositionOfEndOfLineToIgnore);
		elementToRead.setLastPerformed(Date::fromString(lastPerformed));
		std::string timesPerformed;
		std::getline(file, timesPerformed);
		timesPerformed = substring(timesPerformed, lastPositionOfBeginningOfLineToIgnore, firstPositionOfEndOfLineToIgnore);
		elementToRead.setTimesPerformed(stoi(timesPerformed));
		std::string vision;
		std::getline(file, vision);
		vision = substring(vision, lastPositionOfBeginningOfLineToIgnore, firstPositionOfEndOfLineToIgnore);
		elementToRead.setVision(vision);
		std::getline(file, line_string); //</tr>
		std::getline(file, line_string); //<tr> - if a new task follows OR </table> if the table is done
		if (title == givneTitle)
		{
			file.close();
			return index;
		}
		index++;
	}
	file.close();
	*/
	return -1;
}


void HTMLRepo::addElement(const TElement& element)
{
	/*
	std::ifstream file(this->filename);
	TElement elementToRead;
	std::vector<TElement> elements;
	int index = 0;
	int indexToUpdate = -1;
	std::string line_string;
	int numberOfUnnecessayLines = 15;
	for (int line = 0; line < numberOfUnnecessayLines; line++)
	{
		std::getline(file, line_string);
	}
	while (line_string == "<tr>")
	{
		int lastPositionOfBeginningOfLineToIgnore = 4;
		int firstPositionOfEndOfLineToIgnore = -5;
		std::string title;
		std::getline(file, title);
		title = substring(title, lastPositionOfBeginningOfLineToIgnore, firstPositionOfEndOfLineToIgnore);
		elementToRead.setTitle(title);
		std::string type;
		std::getline(file, type);
		type = substring(type, lastPositionOfBeginningOfLineToIgnore, firstPositionOfEndOfLineToIgnore);
		elementToRead.setType(type);
		std::string lastPerformed;
		std::getline(file, lastPerformed);
		lastPerformed = substring(lastPerformed, lastPositionOfBeginningOfLineToIgnore, firstPositionOfEndOfLineToIgnore);
		elementToRead.setLastPerformed(Date::fromString(lastPerformed));
		std::string timesPerformed;
		std::getline(file, timesPerformed);
		timesPerformed = substring(timesPerformed, lastPositionOfBeginningOfLineToIgnore, firstPositionOfEndOfLineToIgnore);
		elementToRead.setTimesPerformed(stoi(timesPerformed));
		std::string vision;
		std::getline(file, vision);
		vision = substring(vision, lastPositionOfBeginningOfLineToIgnore, firstPositionOfEndOfLineToIgnore);
		elementToRead.setVision(vision);
		std::getline(file, line_string); //</tr>
		std::getline(file, line_string); //<tr> - if a new task follows OR </table> if the table is done
		if (title == element.getTitle())
		{
			file.close();
			throw RepoError("Element already in repo!");
		}
		elements.push_back(elementToRead);
		index++;
	}
	file.close();
	std::ofstream fileWrite(this->filename);
	fileWrite << htmlBodyBeginning();
	for (auto& element : elements)
	{
		fileWrite << element.toHTMLline();
	}
	if (indexToUpdate == -1)
		fileWrite << element.toHTMLline();
	fileWrite << htmlBodyEnd();
	fileWrite.close();*/
}

void HTMLRepo::updateElement(const TElement& element)
{
	/*
	std::ifstream file(this->filename);
	TElement elementToRead;
	std::vector<TElement> elements;
	int index = 0;
	int indexToUpdate = -1;
	std::string line_string;
	int numberOfUnnecessayLines = 15;
	for (int line = 0; line < numberOfUnnecessayLines; line++)
	{
		std::getline(file, line_string);
	}
	while (line_string == "<tr>")
	{
		int lastPositionOfBeginningOfLineToIgnore = 4;
		int firstPositionOfEndOfLineToIgnore = -5;
		std::string title;
		std::getline(file, title);
		title = substring(title, lastPositionOfBeginningOfLineToIgnore, firstPositionOfEndOfLineToIgnore);
		elementToRead.setTitle(title);
		std::string type;
		std::getline(file, type);
		type = substring(type, lastPositionOfBeginningOfLineToIgnore, firstPositionOfEndOfLineToIgnore);
		elementToRead.setType(type);
		std::string lastPerformed;
		std::getline(file, lastPerformed);
		lastPerformed = substring(lastPerformed, lastPositionOfBeginningOfLineToIgnore, firstPositionOfEndOfLineToIgnore);
		elementToRead.setLastPerformed(Date::fromString(lastPerformed));
		std::string timesPerformed;
		std::getline(file, timesPerformed);
		timesPerformed = substring(timesPerformed, lastPositionOfBeginningOfLineToIgnore, firstPositionOfEndOfLineToIgnore);
		elementToRead.setTimesPerformed(stoi(timesPerformed));
		std::string vision;
		std::getline(file, vision);
		vision = substring(vision, lastPositionOfBeginningOfLineToIgnore, firstPositionOfEndOfLineToIgnore);
		elementToRead.setVision(vision);
		std::getline(file, line_string); //</tr>
		std::getline(file, line_string); //<tr> - if a new task follows OR </table> if the table is done
		if (title == element.getTitle())
		{
			indexToUpdate = index;
			elementToRead.setType(element.getType());
			elementToRead.setLastPerformed(element.getLastPerformed());
			elementToRead.setTimesPerformed(element.getTimesPerformed());
			elementToRead.setVision(element.getVision());
		}
		elements.push_back(elementToRead);
		index++;
	}
	file.close();
	std::ofstream fileWrite(this->filename);
	fileWrite << htmlBodyBeginning();
	for (auto& element : elements)
	{
		fileWrite << element.toHTMLline();
	}
	if (indexToUpdate == -1)
		fileWrite << element.toHTMLline();
	fileWrite << htmlBodyEnd();
	fileWrite.close();
	*/
}

void HTMLRepo::deleteElement(const TElement& element)
{
	/*
	std::ifstream file(this->filename);
	TElement elementToRead;
	std::vector<TElement> elements;
	int index = 0;
	int indexToDelete = -1;
	std::string line_string;
	int numberOfUnnecessayLines = 15;
	for (int line = 0; line < numberOfUnnecessayLines; line++)
	{
		std::getline(file, line_string);
	}
	while (line_string == "<tr>")
	{
		int lastPositionOfBeginningOfLineToIgnore = 4;
		int firstPositionOfEndOfLineToIgnore = -5;
		std::string title;
		std::getline(file, title);
		title = substring(title, lastPositionOfBeginningOfLineToIgnore, firstPositionOfEndOfLineToIgnore);
		elementToRead.setTitle(title);
		std::string type;
		std::getline(file, type);
		type = substring(type, lastPositionOfBeginningOfLineToIgnore, firstPositionOfEndOfLineToIgnore);
		elementToRead.setType(type);
		std::string lastPerformed;
		std::getline(file, lastPerformed);
		lastPerformed = substring(lastPerformed, lastPositionOfBeginningOfLineToIgnore, firstPositionOfEndOfLineToIgnore);
		elementToRead.setLastPerformed(Date::fromString(lastPerformed));
		std::string timesPerformed;
		std::getline(file, timesPerformed);
		timesPerformed = substring(timesPerformed, lastPositionOfBeginningOfLineToIgnore, firstPositionOfEndOfLineToIgnore);
		elementToRead.setTimesPerformed(stoi(timesPerformed));
		std::string vision;
		std::getline(file, vision);
		vision = substring(vision, lastPositionOfBeginningOfLineToIgnore, firstPositionOfEndOfLineToIgnore);
		elementToRead.setVision(vision);
		std::getline(file, line_string); //</tr>
		std::getline(file, line_string); //<tr> - if a new task follows OR </table> if the table is done
		if (title == element.getTitle())
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
	std::ofstream fileWrite(this->filename);
	fileWrite << htmlBodyBeginning();
	for (auto& element : elements)
	{
		fileWrite << element.toHTMLline();
	}
	if (indexToDelete == -1)
		throw RepoError("Element not in repo!");
	fileWrite << htmlBodyEnd();
	fileWrite.close();
	*/
}

std::vector<TElement> HTMLRepo::getElements() const
{
	/*
	std::ifstream file(this->filename);
	TElement elementToRead;
	std::vector<TElement> elements;
	int index = 0;
	std::string line_string;
	int numberOfUnnecessayLines = 15;
	for (int line = 0; line < numberOfUnnecessayLines; line++)
	{
		std::getline(file, line_string);
	}
	while (line_string == "<tr>")
	{
		int lastPositionOfBeginningOfLineToIgnore = 4;
		int firstPositionOfEndOfLineToIgnore = -5;
		std::string title;
		std::getline(file, title);
		title = substring(title, lastPositionOfBeginningOfLineToIgnore, firstPositionOfEndOfLineToIgnore);
		elementToRead.setTitle(title);
		std::string type;
		std::getline(file, type);
		type = substring(type, lastPositionOfBeginningOfLineToIgnore, firstPositionOfEndOfLineToIgnore);
		elementToRead.setType(type);
		std::string lastPerformed;
		std::getline(file, lastPerformed);
		lastPerformed = substring(lastPerformed, lastPositionOfBeginningOfLineToIgnore, firstPositionOfEndOfLineToIgnore);
		elementToRead.setLastPerformed(Date::fromString(lastPerformed));
		std::string timesPerformed;
		std::getline(file, timesPerformed);
		timesPerformed = substring(timesPerformed, lastPositionOfBeginningOfLineToIgnore, firstPositionOfEndOfLineToIgnore);
		elementToRead.setTimesPerformed(stoi(timesPerformed));
		std::string vision;
		std::getline(file, vision);
		vision = substring(vision, lastPositionOfBeginningOfLineToIgnore, firstPositionOfEndOfLineToIgnore);
		elementToRead.setVision(vision);
		std::getline(file, line_string); //</tr>
		std::getline(file, line_string); //<tr> - if a new task follows OR </table> if the table is done
		elements.push_back(elementToRead);
		index++;
	}
	file.close();
	return elements;*/
	return std::vector<TElement>();
}

int HTMLRepo::getSize()
{
	/*
	std::ifstream file(this->filename);
	TElement elementToRead;
	int size = 0;
	std::string line_string;
	int numberOfUnnecessayLines = 15;
	for (int line = 0; line < numberOfUnnecessayLines; line++)
	{
		std::getline(file, line_string);
	}
	while (line_string == "<tr>")
	{
		int lastPositionOfBeginningOfLineToIgnore = 4;
		int firstPositionOfEndOfLineToIgnore = -5;
		std::string title;
		std::getline(file, title);
		title = substring(title, lastPositionOfBeginningOfLineToIgnore, firstPositionOfEndOfLineToIgnore);
		elementToRead.setTitle(title);
		std::string type;
		std::getline(file, type);
		type = substring(type, lastPositionOfBeginningOfLineToIgnore, firstPositionOfEndOfLineToIgnore);
		elementToRead.setType(type);
		std::string lastPerformed;
		std::getline(file, lastPerformed);
		lastPerformed = substring(lastPerformed, lastPositionOfBeginningOfLineToIgnore, firstPositionOfEndOfLineToIgnore);
		elementToRead.setLastPerformed(Date::fromString(lastPerformed));
		std::string timesPerformed;
		std::getline(file, timesPerformed);
		timesPerformed = substring(timesPerformed, lastPositionOfBeginningOfLineToIgnore, firstPositionOfEndOfLineToIgnore);
		elementToRead.setTimesPerformed(stoi(timesPerformed));
		std::string vision;
		std::getline(file, vision);
		vision = substring(vision, lastPositionOfBeginningOfLineToIgnore, firstPositionOfEndOfLineToIgnore);
		elementToRead.setVision(vision);
		std::getline(file, line_string); //</tr>
		std::getline(file, line_string); //<tr> - if a new task follows OR </table> if the table is done
		size++;
	}
	file.close();
	return size;*/
	return 0;
}
