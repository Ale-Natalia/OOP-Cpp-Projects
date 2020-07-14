#pragma once

#include "Service.h"
#include "MylistWidget.h"
#include <QtWidgets/QMainWindow>
#include <QListWidget>
#include <qshortcut.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qformlayout.h>
#include <qmessagebox.h>
#include <qdebug.h>
#include <QtWidgets/QApplication>
//#include <QtCharts/QChartView>
//#include <QtCharts/QBarSeries>
//#include <QtCharts/QBarSet>
//#include <QtCharts/QLegend>
//#include <QtCharts/QBarCategoryAxis>
//#include <QValueAxis>

//using namespace QtCharts;
//QT_CHARTS_USE_NAMESPACE

class GUI : public QWidget {
private:
	Service* service;
	MylistWidget* mylistTable;
	MylistWidget* repoTable;

	//mode A
	QListWidget* list;
	QLineEdit* inputTitle;
	QLineEdit* inputType;
	QLineEdit* inputLastPerformed;
	QLineEdit* inputTimesPerformed;
	QLineEdit* inputVision;

	QPushButton* addButton;
	QPushButton* updateButton;
	QPushButton* deleteButton;
	QPushButton* undoButton;
	QPushButton* redoButton;
	QPushButton* listallButton;
	QPushButton* openRepoButton;

	QFormLayout* inputForm;
	QGridLayout* buttonsLayout;
	QVBoxLayout* mainWindow;

	//mode B
	QListWidget* mylist;
	QListWidget* nextElement;
	QLineEdit* inputTitle_mylist;

	QPushButton* saveButton;
	QPushButton* nextButton;
	QPushButton* undoMylistButton;
	QPushButton* redoMylistButton;
	QPushButton* filterButton;
	QPushButton* openMylistButton;
	
	QFormLayout* inputForm_mylist;
	QGridLayout* buttonsLayout_mylist;
	QVBoxLayout* mainWindow_mylist;

	//common elements
	QPushButton* modeButton;
	QLineEdit* inputRepoLocation;
	QLineEdit* inputRepoLocation_mylist;
	QPushButton* repoLocationButton;
	QPushButton* repoLocation_mylistButton;
	QPushButton* openMylistWindow;
	QPushButton* openRepoWindow;

	QFormLayout* locations;
	QVBoxLayout* window_middle;

	QVBoxLayout* mylistWindow;

	//new window for mode B

	//analysis
	//QBarSeries* barSeries;
	//QChart* chart;
	//QHBoxLayout* analysisWindow;
	//QPushButton* updateAnalysisButton;
	//QChartView* chartView;

	//main app
	QHBoxLayout* mainwindow_app;
	QShortcut* undoShortcut;
	QShortcut* redoShortcut;

	//void createBarchart();

	void addTask();
	void updateTask();
	void deleteTask();
	void undoRepo();
	void redoRepo();

	void updateRepoFile();
	void updateMylistFile();

	void undoAccordingToMode();
	void redoAccordingToMode();

	void save();
	void next();
	void filter();
	void undoMylist();
	void redoMylist();
	void openMylist();
	void openRepo();
	void setMode();

	void clearRepoDisplay();
	void clearMylistDisplay();
	void clearFields();
	void clearFields_mylist();
	void clearFields_middle();

	void initializeGUI();
	void connectSignalsAndSlots();
	void populate();
	void populate_mylist();
	void populate_accordingToMode();

public:
	GUI(Service* service, MylistWidget* mylistTable, QWidget* parent = 0) : QWidget(parent), service{ service }, mylistTable{ mylistTable } {
		this->initializeGUI();
		this->connectSignalsAndSlots();
		this->populate_accordingToMode();
		//this->createBarchart();
	}

};