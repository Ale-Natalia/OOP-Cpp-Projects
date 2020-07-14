#pragma once
#include <qwidget.h>
#include <qlabel.h>
#include <qbuttongroup.h>
#include <qboxlayout.h>
#include <qspinbox.h>
#include <QtWidgets/QApplication>
#include <qwidget.h>
#include <qlistwidget.h>
#include <qlineedit.h>
#include <qformlayout.h>
#include <qpushbutton.h>
#include <qcheckbox.h>
#include <qmessagebox.h>
#include "Observer.h"
#include "Domain.h"
#include "Service.h"
#include "Exceptions.h"
#include "RepoWidget.h"
#include "RepoTableModel.h"
#include "RepoTableModelFiltered.h"
#include "StarDrawing.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>


QT_CHARTS_USE_NAMESPACE

typedef Star Item;

class GUI : public QWidget, public Observer {
private:
	Service* service;
	User* user;
	Item* selectedStar;

	RepoTableModel<Item>* userModel;
	RepoTableModelFiltered<Item>* userFilteredModel;
	RepoTableModel<Item>* currentModel;
	RepoWidget<Item>* userTable;

	QListWidget* userList;
	QFormLayout* userForm;
	QPushButton* editDataButton;
	QPushButton* viewButton;
	QPushButton* answerButton;
	QVBoxLayout* userLayout;
	QCheckBox* checkBox;

	QSpinBox* spinBox;

	QLineEdit* inputName;
	QLineEdit* inputRA;
	QLineEdit* inputDec;
	QLineEdit* inputDiameter;

	QListWidget* allList;
	QFormLayout* allListForm;
	QLineEdit* inputSearch;
	QVBoxLayout* allLayout;

	QHBoxLayout* mainLayout;

	/*
	QWidget* editWindow;
	QVBoxLayout* editLayout;
	QListWidget* editList;
	QFormLayout* editForm;
	QLineEdit* inputThesisTitle;
	QLineEdit* inputEmail;
	QPushButton* saveButton;
	QPushButton* cancelButton;
	*/

	//visual statistic
	QWidget* analysisWindow;
	//QVBoxLayout* analysisLayout;


private:
	void initializeGUI();
	void populateUserList();
	void populateUserListComplete();
	void populateUserListAccordingly();
	void populateAllList();
	void connectSignalsAndSlots();

	int getSelectedIndexUserList();
	int getSelectedIndexAllList();
	void update()override;

	void setCoordinator();
	void addStar();
	void answer();
	void setSpin();
	void writeStarsToFileSorted();
	void openAnalysisWindow();


	void closeEvent(QCloseEvent* bar)
	{
		this->writeStarsToFileSorted();
	}

public:
	GUI(User* user, Service* service, RepoTableModel<Item>* model, RepoTableModelFiltered<Item>* filteredModel) {
		this->service = service;
		this->user = user;
		this->userModel = model;
		this->userFilteredModel = filteredModel;
		this->currentModel = this->userModel;
		this->initializeGUI();
		this->populateUserListComplete();
		this->connectSignalsAndSlots();
		//this->populateAllList();
	}
};