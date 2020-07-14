#include "Service.h"


Repository<Item>* Service::getRepo()
{
	return this->repository;
}

std::vector<Item> Service::getAllItems()
{
	return this->repository->getElements();
}

std::vector<Item> Service::getAllItemsOfUser(User* user)
{
	std::vector<Item> stars = this->repository->getElements();
	std::vector<Item> starsOfAstronomer;
	for (auto& star : stars) {
		if (star.getConstellation() == user->getConstellation()) {
			starsOfAstronomer.push_back(star);
		}
	}
	return starsOfAstronomer;
}

void Service::add(std::string name, std::string constellation, int RA, int Dec, int diameter)
{
	if (name == "")
		throw InvalidInputError("Empty name");
	if(diameter <= 0)
		throw InvalidInputError("Diameter must be positive");
	Star star = Star(name, constellation, RA, Dec, diameter);
	this->repository->addElement(star);
	this->notify();
}


std::vector<Item> Service::sortStarsByConstellation(std::vector<Item> stars)const
{
	std::vector<Item> _stars = this->repository->getElements();
	auto sortByRule = [](Item element1, Item element2) {
		return element1.getConstellation() <= element2.getConstellation();
	};
	std::sort(_stars.begin(), _stars.end(), sortByRule);
	return _stars;
}

/*
std::vector<TElement> Service::getAllStudentsOfTeacherSorted(Teacher* teacher)
{
	return this->sortStudentsByYear(this->getAllStudentsOfTeacher(teacher));
}
*/

std::vector<Item> Service::matchElements(const std::string& wordToMatch)
{
	if (wordToMatch == "")
		return std::vector<Item>();
	std::string wordToMatch_lowered = stringToLower(wordToMatch);
	std::vector<Item> matchList;
	std::vector<Item> elements = this->getAllItems();
	for (auto& element : elements) {
		bool matches = false;
		std::string name = stringToLower(element.getName());
		if (name.find(wordToMatch_lowered) < name.size()) {
			matches = true;
			matchList.push_back(element);
			continue;
		}
	}
	return matchList;
}

/*
void testAddValid()
{
	std::fstream file;
	file.open("addtest.txt", std::fstream::in | std::fstream::out | std::fstream::trunc);
	file.close();
	Repository<Item>* repo = new CSVRepo<Item>("addtest.txt");
	Star star = Star("Sun", "Alpha Centauri", 30, 30, 5);
	repo->addElement(star);
	assert(repo->searchElement(star) != -1);
}

void testAddInvalidElementInRepo()
{
	std::fstream file;
	file.open("addtest.txt", std::fstream::in | std::fstream::out | std::fstream::trunc);
	file.close();
	Repository<Item>* repo = new CSVRepo<Item>("addtest.txt");
	Star star = Star("Sun", "Alpha Centauri", 30, 30, 5);
	repo->addElement(star);
	try {
		repo->addElement(star);
		assert(false);
	}
	catch (Exception error) {
		assert(error.message == "ELement already in repo!\n");
	}
}

void testAddInvalidEmptyTitle()
{
	std::fstream file;
	file.open("addtest.txt", std::fstream::in | std::fstream::out | std::fstream::trunc);
	file.close();
	Repository<Item>* repo = new CSVRepo<Item>("addtest.txt");
	Service* service = new Service("addtest.txt");
	Star star = Star("", "Alpha Centauri", 30, 30, 5);
	try {
		service->add("", "Alpha Centauri", 30, 30, 5);
		assert(false);
	}
	catch (Exception error) {
		assert(error.message == "Empty name");
	}
}

void testAddInvalidNegativeDiameter()
{
	std::fstream file;
	file.open("addtest.txt", std::fstream::in | std::fstream::out | std::fstream::trunc);
	file.close();
	Repository<Item>* repo = new CSVRepo<Item>("addtest.txt");
	Service* service = new Service("addtest.txt");
	Star star = Star("Sun", "Alpha Centauri", 30, 30, 0);
	try {
		service->add("Sun", "Alpha Centauri", 30, 30, 0);
		assert(false);
	}
	catch (Exception error) {
		assert(error.message == "Diameter must be positive");
	}
}
*/