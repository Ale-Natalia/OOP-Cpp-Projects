#pragma once
#include "Service.h"
#include "GUI.h"
#include "Repository.h"
#include "CSVRepo.h"
//#include "AnalysisWindow.h"
#include <QtWidgets/QApplication>

class Startup {
private:
	std::vector<User*> users;
	std::vector<GUI*> guis;
	//AnalysisWindow* analysisWindow;
	Service* service;
	RepoTableModel<Item>* tableModel;
	std::string starFile;
	std::string userFile;
public:
	Startup(std::string userFile, std::string starFile) {
		this->userFile = userFile;
		this->starFile = starFile;
		this->readUsersFile();
		this->createService();
		this->tableModel = new RepoTableModel<Item>(this->service->getRepo());
		this->createAllUserGUIs();
		//this->createAnalysisWindow();
	}
	~Startup() {
		for (auto& gui : guis) {
			delete gui;
		}
		for (auto& user : users) {
			delete user;
		}
	}
	User* readUser(std::istream& is);
	void readUsersFile();
	//void createTeacherService(Teacher* teacher);
	//void createAllTeacherServices();
	void createService();
	void createUserGUI(User* user);
	void createAllUserGUIs();
	//void createAnalysisWindow();
};