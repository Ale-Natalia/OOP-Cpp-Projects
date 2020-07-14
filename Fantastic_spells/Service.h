#pragma once
#include "Repository.h"
#include "InMemoryRepository.h"
#include "FileRepository.h"
#include "CSVRepo.h"
#include "HTMLRepo.h"
#include "Validator.h"
#include "FileFunctions.h"
#include "Action.h"
#include <utility>
#include <stack>
#include <memory>

class Service {
private:
	Repository* repository;
	Repository* mylist;
	Validator* validator;
	std::string mode;
	int current;

	std::stack<std::unique_ptr<Action>> undoStackRepository;
	std::stack<std::unique_ptr<Action>> redoStackRepository;
	std::stack<std::unique_ptr<Action>> undoStackMylist;
	std::stack<std::unique_ptr<Action>> redoStackMylist;

	static FileRepository* createRepoBasedOnExtension(const std::string& filename);
public:
	Service() { this->repository = new InMemoryRepository, this->mylist = new InMemoryRepository, this->validator = new Validator, this->mode = "A", this->current = 0; };
	~Service();

	//creates the repos according to a config file
	void configRepos(const std::string& filename);

	std::string getMode() const { return mode; }

	int getRepoSize() const;

	int getMirrorImageSize() const;

	Repository* getMylist() const;

	Repository* getRepo() const;

	std::vector<TElement> getAllTasksInRepository() const;

	std::vector<TElement> getAllMirrorImageTasks() const;

	std::vector<TElement> listFiltered(std::string type, std::string timesPerformed);

	/*
		sets the mode
		throws exception if invalid
	*/
	void setMode(const std::string& mode);

	//CUSTODIAN OPERATIONS

	/*
		adds a task
		returns the position if the element already exists
		throws error if the element was added or if not admin mode
	*/
	void addTaskService(const std::string& title, const std::string& type, const std::string& lastPerformed, const std::string& timesPerformed, const std::string& vision);

	/*
		updates the info of a given task
		returns the position if the element was updated
		throws error if the element does not exist or if not admin mode
	*/
	void updateTaskService(const std::string& title, const std::string& type, const std::string& lastPerformed, const std::string& timesPerformed, const std::string& vision);

	/*
		removes an element from the repository
		throws error if the element does not exist or if not admin mode
	*/
	void deleteTaskService(const std::string& title);

	/*
		undoes the last operation from mode A
		throws an error if no more undos are possible or if not admin mode
	*/
	void undoRepo();

	/*
		redoes the last undone operation from mode A
		throws an error if no more redos are possible or if not admin mode
	*/
	void redoRepo();

	//clears the redo stack for mode A
	void clearRedoRepoStack();

	//SERVANT OPERATIONS

	/*
		adds a task to the mirror image container
		returns true if it was added
		returns false if it was updated
		throws error if the element does not exist
		throws error if not servant mode (B)
	*/
	bool saveTask(const std::string& title);

	/*
		iterates to next task
		returns the current task (in order for it to be shown)
		returns an empty task if not servant mode
	*/
	TElement nextTask();

	/*
		undoes the last operation from mode B
		throws an error if no more undos are possible or if not mode B
	*/
	void undoMylist();

	/*
		redoes the last undone operation from mode B
		throws an error if no more redos are possible or if not mode B
	*/
	void redoMylist();

	//clears the redo stack for mode B
	void clearRedoMylistStack();


	// starts the viewing of the mirror image
	void begin();

	//returns the current mirror image
	TElement getCurrentMirrorImage();

	//returns the repo filename
	std::string getCustodianFilename();

	//sets the repo filename
	void setCustodianFilename(const std::string& filename);

	//returns the mirror image filename
	std::string getServantFilename();

	//sets the mirror image filename
	void setServantFilename(const std::string& filename);

	//opens mylist with the right app
	void openMylist();

	//opens repo with the right app
	void openRepo();

	//returns a vector of pairs type: number of items with given type
	std::vector<std::pair<std::string, int>> typeStatistics();
};