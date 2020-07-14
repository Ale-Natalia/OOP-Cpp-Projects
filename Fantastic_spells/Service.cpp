#include "Service.h"
#include "Exceptions.h"
#include <Windows.h>
#include <algorithm>

std::vector<TElement> Service::getAllTasksInRepository() const
{
	return this->repository->getElements();
}

std::vector<TElement> Service::getAllMirrorImageTasks() const
{
	return this->mylist->getElements();
}

std::vector<TElement> Service::listFiltered(std::string type, std::string timesPerformed)
{
	int timesPerformed_int = this->validator->validateInteger(timesPerformed);
	std::vector<TElement> tasks = this->getAllTasksInRepository();
	std::vector<TElement> filteredList(tasks.size());
	auto filterIterator = std::copy_if(tasks.begin(), tasks.end(), filteredList.begin(), [&](TElement task) {return (type == task.getType() && task.getTimesPerformed() < timesPerformed_int);});
	return filteredList;
}

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

	this->clearRedoRepoStack();
	std::unique_ptr<ActionAdd> addAction = std::make_unique<ActionAdd>(ActionAdd{ task, this->repository });
	this->undoStackRepository.push(std::move(addAction));
}

void Service::updateTaskService(const std::string& title, const std::string& type, const std::string& lastPerformed, const std::string& timesPerformed, const std::string& vision) {
	if (this->mode != "A")
	{
		throw ModeError("Peasant, art thee trying to achieve'th what was not meante'th for thee?\n");
	}
	Date lastPerformed_date = validator->validateDate(lastPerformed);
	int timesPerformed_int = validator->validateInteger(timesPerformed);
	Task task = Task(title, type, lastPerformed_date, timesPerformed_int, vision);
	TElement oldElement = this->repository->updateElement(task);
	
	int elementInMylist = this->mylist->searchElementByTitle(title);
	if (elementInMylist != -1)
		this->mylist->updateElement(task);

	this->clearRedoRepoStack();
	std::unique_ptr<ActionUpdate> updateAction = std::make_unique<ActionUpdate>(ActionUpdate{ oldElement, task, this->repository });
	this->undoStackRepository.push(std::move(updateAction));
}

void Service::deleteTaskService(const std::string& title)
{
	if (this->mode != "A")
	{
		throw ModeError("Peasant, art thee trying to achieve'th what was not meante'th for thee?\n");
	}
	Task task = Task(title, "", Date(), 0, "");
	TElement deletedElement = this->repository->deleteElement(task);
	
	int elementInMylist = this->mylist->searchElementByTitle(title);
	if (elementInMylist != -1)
		this->mylist->deleteElement(task);

	this->clearRedoRepoStack();
	std::unique_ptr<ActionDelete> deleteAction = std::make_unique<ActionDelete>(ActionDelete{ deletedElement, this->repository });
	this->undoStackRepository.push(std::move(deleteAction));
}

void Service::undoRepo()
{
	if (this->mode != "A")
	{
		throw ModeError("Peasant, art thee trying to achieve'th what was not meante'th for thee?\n");
	}
	if (this->undoStackRepository.empty())
		throw UndoError("No more undos are possible!\n");
	std::unique_ptr<Action> lastAction = std::move(this->undoStackRepository.top());
	lastAction->executeUndo();
	this->undoStackRepository.pop();
	this->redoStackRepository.push(std::move(lastAction));
}

void Service::redoRepo()
{
	if (this->mode != "A")
	{
		throw ModeError("Peasant, art thee trying to achieve'th what was not meante'th for thee?\n");
	}
	if (this->redoStackRepository.empty())
		throw UndoError("No more redos are possible!\n");
	std::unique_ptr<Action> lastUndoneAction = std::move(this->redoStackRepository.top());
	lastUndoneAction->executeRedo();
	this->redoStackRepository.pop();
	this->undoStackRepository.push(std::move(lastUndoneAction));
}

void Service::clearRedoRepoStack()
{
	while (!this->redoStackRepository.empty()) {
		this->redoStackRepository.pop();
	}
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

int Service::getMirrorImageSize() const
{
	return this->mylist->getSize();
}

Repository* Service::getMylist() const
{
	return this->mylist;
}

Repository* Service::getRepo() const
{
	return this->repository;
}

void Service::openMylist()
{
	if (this->mode != "B")
	{
		throw ModeError("Master, this filthy chore was not meante'th for thy gentle hands!?\n");
	}
	FileRepository* pointerToMylist = dynamic_cast<FileRepository*>(this->mylist);
	//this->servantMirrorImage.mylist();
	if (pointerToMylist == NULL)
		throw InvalidInputError("Mylist is stored inmemory!");
	std::string filename = pointerToMylist->getFilename();
	std::wstring temporarywstring = std::wstring(filename.begin(), filename.end());
	LPCWSTR wstring = temporarywstring.c_str();
	if (filenameEnding(filename, ".csv") || filenameEnding(filename, ".txt"))
		ShellExecute(0, L"open", L"C:\\Windows\\system32\\notepad.exe", wstring, 0, SW_SHOW);
		//ShellExecute(0, L"open", L"C:\\Program Files (x86)\\Microsoft Office\\root\\Office16\\EXCEL.EXE", wstring, 0, SW_SHOW);
	else if (filenameEnding(filename, ".html"))
		ShellExecute(0, L"open", L"C:\\Program Files (x86)\\Google\\Chrome\\Application\\Chrome.exe", wstring, 0, SW_SHOW);
}

void Service::openRepo()
{
	if (this->mode != "A")
		throw ModeError("Peasant, art thee trying to achieve'th what was not meante'th for thee?\n");
	FileRepository* pointerToRepo = dynamic_cast<FileRepository*>(this->repository);
	if (pointerToRepo == NULL)
		throw InvalidInputError("Repo is stored inmemory!");
	std::string filename = pointerToRepo->getFilename();
	std::wstring temporarywstring = std::wstring(filename.begin(), filename.end());
	LPCWSTR wstring = temporarywstring.c_str();
	if (filenameEnding(filename, ".csv") || filenameEnding(filename, ".txt"))
		ShellExecute(0, L"open", L"C:\\Windows\\system32\\notepad.exe", wstring, 0, SW_SHOW);
		//ShellExecute(0, L"open", L"C:\\Program Files (x86)\\Microsoft Office\\root\\Office16\\EXCEL.EXE", wstring, 0, SW_SHOW);
	else if (filenameEnding(filename, ".html"))
		ShellExecute(0, L"open", L"C:\\Program Files (x86)\\Google\\Chrome\\Application\\Chrome.exe", wstring, 0, SW_SHOW);
}

bool Service::saveTask(const std::string& title)
{
	if (this->mode != "B")
	{
		throw ModeError("Master, this filthy chore was not meante'th for thy gentle hands!?\n");
	}
	TElement task;
	int positionOfTask = this->repository->searchElementByTitle(title);
	if (positionOfTask == -1)
	{
		throw RepoError("This chore does not exist!\n");
	}
	TElement savedElement = this->repository->getElements()[positionOfTask];
	if (this->mylist->searchElementByTitle(title) != -1)
	{
		throw RepoError("Chore already in mylist!");
	}
	this->mylist->addElement(savedElement);
	this->clearRedoMylistStack();
	std::unique_ptr<ActionAdd> addAction = std::make_unique<ActionAdd>(ActionAdd{ savedElement, this->mylist });
	this->undoStackMylist.push(std::move(addAction));
	return true;
}

TElement Service::nextTask()
{
	if (this->mode != "B")
	{
		throw ModeError("Master, this filthy chore was not meante'th for thy gentle hands!?\n");
	}
	TElement task = this->getCurrentMirrorImage();

	std::vector<TElement> elements;
	elements = this->repository->getElements();
	int numberOfElements = elements.size();

	if (this->current == numberOfElements - 1)
		this->begin();
	else
		this->current++;

	return task;
}

void Service::undoMylist()
{
	if (this->mode != "B")
	{
		throw ModeError("Master, this filthy chore was not meante'th for thy gentle hands!?\n");
	}
	if (this->undoStackMylist.empty())
		throw UndoError("No more undos are possible!\n");
	std::unique_ptr<Action> lastAction = std::move(this->undoStackMylist.top());
	lastAction->executeUndo();
	this->undoStackMylist.pop();
	this->redoStackMylist.push(std::move(lastAction));
}

void Service::redoMylist()
{
	if (this->mode != "B")
	{
		throw ModeError("Master, this filthy chore was not meante'th for thy gentle hands!?\n");
	}
	if (this->redoStackMylist.empty())
		throw UndoError("No more redos are possible!\n");
	std::unique_ptr<Action> lastUndoneAction = std::move(this->redoStackMylist.top());
	lastUndoneAction->executeRedo();
	this->redoStackMylist.pop();
	this->undoStackMylist.push(std::move(lastUndoneAction));
}

void Service::clearRedoMylistStack()
{
	while (!this->redoStackMylist.empty()) {
		this->redoStackMylist.pop();
	}
}

void Service::begin()
{
	this->current = 0;
}

TElement Service::getCurrentMirrorImage()
{
	std::vector<TElement> elements;
	elements = this->repository->getElements();
	return elements[this->current];
}


std::string Service::getCustodianFilename()
{
	
	FileRepository* pointerToFileRepository = dynamic_cast<FileRepository*>(this->repository);
	return pointerToFileRepository->getFilename();
	//return this->repository->getFilename();
	
	//return "";
}

void Service::setCustodianFilename(const std::string& filename)
{
	
	delete this->repository;
	FileRepository* newRepository = this->createRepoBasedOnExtension(filename);
	this->repository = newRepository;
	auto* pointerToFileRepository = dynamic_cast<FileRepository*>(this->repository);
	pointerToFileRepository->setFilename(filename);
	//this->servantMirrorImage->setCustodianFilename(filename);
	
}

std::string Service::getServantFilename()
{
	
	FileRepository* pointerToFileRepository = dynamic_cast<FileRepository*>(this->repository);
	return pointerToFileRepository->getFilename();
	//return this->servantMirrorImage.getServantFilename();
	
	//return "";
}

void Service::setServantFilename(const std::string& filename)
{
	
	delete this->mylist;
	FileRepository* newRepository = this->createRepoBasedOnExtension(filename);
	this->mylist = newRepository;
	auto* pointerToFileRepository = dynamic_cast<FileRepository*>(this->mylist);
	pointerToFileRepository->setFilename(filename);
	//this->servantMirrorImage.setServantFilename(filename);
	
}


void Service::setMode(const std::string& mode)
{
	if (!(mode == "A" || mode == "B"))
	{
		throw ModeError("This mode sounds strange to my humble ears!\n");
	}
	this->mode = mode;
}

void Service::configRepos(const std::string& filename)
{
	std::vector<std::string> repoTypes = readConfigurationFile(filename);
	std::string repoFile = repoTypes[0];
	std::string mylistFile = repoTypes[1];
	if (repoFile != "inmemory")
	{
		this->setCustodianFilename(repoFile);
	}
	if (mylistFile != "inmemory")
	{
		this->setServantFilename(mylistFile);
	}

}


std::vector<std::pair<std::string, int>> Service::typeStatistics()
{
	std::vector<std::pair<std::string, int>> types;
	std::vector<TElement> elementsInRepo = this->repository->getElements();
	for (auto& element : elementsInRepo) {
		bool typeFound = false;
		std::string type = element.getType();
		for (const std::pair<std::string, int>& typeNumberPair : types) {
			if (typeNumberPair.first == type) {
				int typeFrequency = typeNumberPair.second + 1;
				int index = &typeNumberPair - &types[0];
				types.erase(types.begin() + index);
				std::pair<std::string, int> newTypeNumberPair{ type, typeFrequency };
				types.push_back(newTypeNumberPair);
				typeFound = true;
				break;
			}
			if (!typeFound) {
				std::pair<std::string, int> newTypeNumberPair{ type, 1 };
				types.push_back(newTypeNumberPair);
			}
		}
	}
	return types;
}


Service::~Service()
{
	//delete this->repository;
	//delete this->mylist;
}
