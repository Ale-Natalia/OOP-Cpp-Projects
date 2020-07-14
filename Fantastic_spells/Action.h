#pragma once
#include "Repository.h"

class Action {
public:
	virtual ~Action(){};
	virtual void executeUndo() = 0;
	virtual void executeRedo() = 0;
};

class ActionAdd : public Action {
private:
	TElement addedElement;
	Repository* repo;
public:
	ActionAdd(TElement element, Repository* repository) : addedElement{element}, repo{repository} {}
	void executeUndo() override;
	void executeRedo() override;
};

class ActionDelete : public Action {
private:
	TElement deletedElement;
	Repository* repo;
public:
	ActionDelete(TElement element, Repository* repository) : deletedElement{ element }, repo{ repository } {}
	void executeUndo() override;
	void executeRedo() override;
};

class ActionUpdate : public Action {
private:
	TElement oldElement;
	TElement newElement;
	Repository* repo;
public:
	ActionUpdate(TElement oldElement, TElement newElement, Repository* repository) : oldElement{ oldElement }, newElement{ newElement }, repo{ repository } {}
	void executeUndo() override;
	void executeRedo() override;
};
