#pragma once

#include "Service.h"
#include <QtWidgets/QMainWindow>
#include <QListWidget>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qformlayout.h>
#include <qmessagebox.h>
#include <qdebug.h>
#include <QtWidgets/QApplication>
#include <qlabel.h>

class GUI : public QWidget {
private:
	Service service;

	QListWidget* list;
	//QLineEdit* inputCategory;
	QLineEdit* inputName;
	QLineEdit* inputModify;

	QPushButton* addButton;
	QPushButton* updateButton;
	QPushButton* deleteButton;
	QPushButton* filterButton;
	QPushButton* searchButton;
	QPushButton* listallButton;

	QFormLayout* inputForm;
	QGridLayout* buttonsLayout;
	QVBoxLayout* mainWindow;

	QLabel* consumableParts;
	QVBoxLayout* secWindow;

	QVBoxLayout* thirdWindow;
	QListWidget* thirdList;
	
	//main app
	QHBoxLayout* mainwindow_app;

	//void createBarchart();

	int getSelectedIndex();
	void setSelectedIndex(const int& index);
	void addTask();
	void updateTask();
	void deleteTask();
	void filter();
	void clearRepoDisplay();
	void clearFields();
	void clearFields_middle();


	void populate_accordingToModified();

	void initializeGUI();
	void connectSignalsAndSlots();
	void populate();
	

	//shows the best matching document in the list on the right
	void populate_thirdList();

public:
	GUI(const Service& service, QWidget* parent = 0) : QWidget(parent), service{ service } {
		this->initializeGUI();
		this->connectSignalsAndSlots();
		this->populate();
	}

};