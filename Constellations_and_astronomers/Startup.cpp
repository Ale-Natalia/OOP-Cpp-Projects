#include "Startup.h"
#include "RepoTableModel.h"

User* Startup::readUser(std::istream& is)
{
	User* user = new User();
	is >> *user;
	return user;
}

void Startup::readUsersFile()
{
	std::ifstream file(this->userFile);
	this->users.clear();
	User* user = new User();
	do {
		user = this->readUser(file);
		if(user->getName() != "")
			this->users.push_back(user);
	} while (user->getName() != "");
	file.close();
}

void Startup::createService()
{
	this->service = new Service(this->starFile);
}

void Startup::createUserGUI(User* user)
{
	RepoTableModelFiltered<Item>* filteredModel = new RepoTableModelFiltered<Item>(this->service->getRepo(), user->getConstellation());
	GUI* userWindow = new GUI(user, this->service, this->tableModel, filteredModel);
	const QString userName = QString::fromStdString(user->getName());
	userWindow->setWindowTitle(userName);
	userWindow->show();
	this->guis.push_back(userWindow);
	this->service->addObserver(userWindow);
}

void Startup::createAllUserGUIs()
{
	for (auto& user : this->users) {
		this->createUserGUI(user);
	}
}

/*
void Startup::createAnalysisWindow()
{
	this->analysisWindow = new AnalysisWindow(this->service, this->astronomers);
	this->analysisWindow->setWindowTitle("Analysis");
	this->analysisWindow->show();
	this->service->addObserver(this->analysisWindow);
}
*/