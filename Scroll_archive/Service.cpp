#include "Service.h"
#include "Exceptions.h"
#include <Windows.h>
#include <algorithm>

std::vector<TElement> Service::getAllElementsInRepository() const
{
	return this->repository->getElements();
}

TElement Service::search(const std::string& name)const
{
	std::vector<TElement> elements = this->getAllElementsInRepository();
	int position = this->repository->searchElementByTitle(name);
	if (position == -1)
		throw RepoError("Element not found!");
	return elements[position];
}


std::vector<TElement> Service::matchElements(const std::string& wordToMatch) const
{
	std::vector<TElement> matchList;
	std::vector<TElement> elements = this->getAllElementsInRepository();
	for (auto& element : elements) {
		bool matches = false;
		if (element.getName().find(wordToMatch) < element.getName().size()) {
			matches = true;
			matchList.push_back(element);
			continue;
		}
		std::vector<std::string> keywords = element.getKeywords();
		for (auto& keyword : keywords) {
			if (keyword.find(wordToMatch) < keyword.size()) {
				matches = true;
				matchList.push_back(element);
				break;
			}
		}
	}
	return matchList;
}

TElement Service::bestMatching(const std::string& wordToMatch) const
{
	//std::vector<TElement> matchList;
	std::vector<TElement> elements = this->getAllElementsInRepository();
	TElement bestElement;
	float wordToMatchLength = wordToMatch.size() * 1.0;
	float bestRatio = 0.0;
	for (auto& element : elements) {
		bool matches = false;
		float currentRatio = 0.0;
		int nameSize = element.getName().size();
		if (element.getName().find(wordToMatch) < element.getName().size()) {
			matches = true;
			currentRatio = wordToMatchLength / nameSize;
			if (currentRatio > bestRatio) {
				bestRatio = currentRatio;
				bestElement = element;
			}
		}
		std::vector<std::string> keywords = element.getKeywords();
		for (auto& keyword : keywords) {
			if (keyword.find(wordToMatch) < keyword.size()) {
				matches = true;
				int nameSize = keyword.size();
				currentRatio = wordToMatchLength / nameSize;
				if (currentRatio > bestRatio){
					bestRatio = currentRatio;
					bestElement = element;
				}
			}
		}
	}
	return bestElement;
}


/*
void Service::addTaskService(const std::string& title, const std::string& type, const std::string& lastPerformed, const std::string& timesPerformed, const std::string& vision)
{
	if (this->mode != "A")
	{
		throw ModeError("Peasant, art thee trying to achieve'th what was not meante'th for thee?\n");
	}
	Date lastPerformed_date = validator->validateDate(lastPerformed);
	int timesPerformed_int = validator->validateInteger(timesPerformed);
	Task task = validator->validateTask(title, type, lastPerformed_date, timesPerformed_int, vision);
	this->repository->addElement(task);
}

void Service::updateTaskService(const std::string& title, const std::string& type, const std::string& lastPerformed, const std::string& timesPerformed, const std::string& vision) {
	if (this->mode != "A")
	{
		throw ModeError("Peasant, art thee trying to achieve'th what was not meante'th for thee?\n");
	}
	Date lastPerformed_date = validator->validateDate(lastPerformed);
	int timesPerformed_int = validator->validateInteger(timesPerformed);
	Task task = Task(title, type, lastPerformed_date, timesPerformed_int, vision);
	this->repository->updateElement(task);
}
*/

void Service::deleteElementService(const std::string& name)
{
	Document element;
	this->repository->deleteElement(element);
}

std::vector<TElement> Service::filter(const std::string& category)
{
	std::vector<TElement> filteredList;
	std::vector<TElement> elements = this->getAllElementsInRepository();
	for (auto element : elements) {
		//if (element.getCategory() == category)
			//filteredList.push_back(element);
	}
	return filteredList;
}


FileRepository* Service::createRepoBasedOnExtension(const std::string& filename)
{
	if (filenameEnding(filename, ".csv") || filenameEnding(filename, ".txt"))
		return new CSVRepo;
	else if (filenameEnding(filename, ".html"))
		//return new CSVRepo;
		return new HTMLRepo;
	else
		throw InvalidInputError("File extension must be .csv, .txt, .html");
}


int Service::getRepoSize() const
{
	return this->repository->getSize();
}

std::string Service::getRepoFilename()
{

	FileRepository* pointerToFileRepository = dynamic_cast<FileRepository*>(this->repository);
	return pointerToFileRepository->getFilename();
	//return this->repository->getFilename();

	//return "";
}

void Service::setRepoFilename(const std::string& filename)
{

	delete this->repository;
	FileRepository* newRepository = this->createRepoBasedOnExtension(filename);
	this->repository = newRepository;
	auto* pointerToFileRepository = dynamic_cast<FileRepository*>(this->repository);
	pointerToFileRepository->setFilename(filename);
	//this->servantMirrorImage->setCustodianFilename(filename);

}


Service::~Service()
{
	//delete this->repository;
	//delete this->mylist;
}