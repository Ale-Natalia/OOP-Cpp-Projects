#include "Action.h"

void ActionAdd::executeUndo()
{
	this->repo->deleteElement(this->addedElement);
}

void ActionAdd::executeRedo()
{
	this->repo->addElement(this->addedElement);
}

void ActionDelete::executeUndo()
{
	this->repo->addElement(this->deletedElement);
}

void ActionDelete::executeRedo()
{
	this->repo->deleteElement(this->deletedElement);
}

void ActionUpdate::executeUndo()
{
	this->repo->updateElement(this->oldElement);
}

void ActionUpdate::executeRedo()
{
	this->repo->updateElement(this->newElement);
}
