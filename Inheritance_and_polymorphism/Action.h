#pragma once
#include <string>
#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>
#include <memory>

//16:16

class Action {
public:
	Action() {};
	~Action() {};
	virtual void execute() = 0;
};

class CreateAction : public Action {
public:
	CreateAction() {}
	~CreateAction() {}
	void execute()override {
		std::cout << "Create file\n";
	}
};

class ExitAction : public Action {
public:
	ExitAction() {}
	~ExitAction() {}
	void execute()override {
		std::cout << "Exit application\n";
	}
};
//16:21 - 1p

class MenuItem {
protected:
	std::string text;
	Action* action;
public:
	MenuItem(){
		this->text = "";
		this->action = NULL;
	}
	MenuItem(std::string text, Action* action=NULL) {
		this->text = text;
		this->action = action;
	}
	void print() {
		std::cout << text;
	}
	void clicked() {
		this->print();
		if(this->action != NULL)
			this->action->execute();
	}
	virtual bool isVirtual() { return true; };
	~MenuItem() {
		delete action;
	}
};
//16:27

class Menu : public MenuItem {
private:
	std::vector<MenuItem*> menuItems;
public:
	Menu() : MenuItem() {}
	Menu(std::string text, Action* action=NULL) : MenuItem(text, action){}
	~Menu(){
		for (auto& item : menuItems) {
			delete item;
		}
	}

	void add(MenuItem* menuItem) {
		Menu* menuFromMenuItem = dynamic_cast<Menu*>(menuItem);
		if (menuFromMenuItem == NULL)
			this->menuItems.push_back(menuItem);
		else
			this->menuItems.push_back(menuFromMenuItem);
	}

	void print(){
		std::cout << text << "\n";
		for (auto& item : menuItems) {
			std::cout << "\t";
			Menu* menuFromMenuItem = dynamic_cast<Menu*>(item);
			if (menuFromMenuItem == NULL)
				item->print();
			else
				menuFromMenuItem->print();
			std::cout << "\n";
		}
	}
};
//16:32

class MenuBar {
private:
	std::vector<Menu*> menus;
public:
	MenuBar(){}
	~MenuBar(){
		for (auto& menu : menus) {
			delete menu;
		}
	}
	void add(Menu* menu) {
		this->menus.push_back(menu);
	}
	void print() {
		for (auto& menu : menus) {
			menu->print();
			std::cout << "\n";
		}
	}
};
//16:37

void simulateMenus() {
	CreateAction* actionC = new CreateAction();
	CreateAction* actionText = new CreateAction();
	MenuItem* C = new MenuItem("C++", actionC);
	MenuItem* Text = new MenuItem("Text", actionText);
	Menu* New = new Menu("New");
	New->add(C);
	New->add(Text);
	ExitAction* actionExit = new ExitAction();
	MenuItem* Exit = new MenuItem("Exit", actionExit);
	Menu* File = new Menu("File");
	File->add(New);
	File->add(Exit);
	Menu* About = new Menu("About");
	MenuBar* menuBar = new MenuBar();
	menuBar->add(File);
	menuBar->add(About);
	menuBar->print();
	
	//simulate File->New->C++ then Exit
	File->clicked();
	New->clicked();
	C->clicked();
	Exit->clicked();
}
//16:50