#include "GUI.h"
#include "Service.h"
#include "Exceptions.h"
#include <QtWidgets/QMainWindow>

void GUI::initializeGUI()
{
	this->list = new QListWidget();

	//this->inputCategory = new QLineEdit();
	this->inputName = new QLineEdit();
	this->inputModify = new QLineEdit();

	this->inputForm = new QFormLayout();
	//this->inputForm->addRow("Category:", this->inputCategory);
	this->inputForm->addRow("Name:", this->inputName);
	this->inputForm->addRow("Search by keywords/name:", this->inputModify);
	
	this->addButton = new QPushButton("Add");
	this->updateButton = new QPushButton("Update");
	this->deleteButton = new QPushButton("Delete");
	this->filterButton = new QPushButton("Filter");
	this->listallButton = new QPushButton("List");

	this->buttonsLayout = new QGridLayout();
	this->buttonsLayout->addWidget(this->addButton, 0, 1);
	this->buttonsLayout->addWidget(this->updateButton, 0, 2);
	this->buttonsLayout->addWidget(this->deleteButton, 1, 1);
	this->buttonsLayout->addWidget(this->filterButton, 1, 2);
	this->buttonsLayout->addWidget(this->listallButton, 0, 3);

	this->mainWindow = new QVBoxLayout();
	this->mainWindow->addWidget(this->list);
	this->mainWindow->addLayout(this->inputForm);
	this->mainWindow->addLayout(this->buttonsLayout);

	this->searchButton = new QPushButton("Show best matching");
	this->consumableParts = new QLabel();
	this->secWindow = new QVBoxLayout();
	this->secWindow->addWidget(this->searchButton);
	this->secWindow->addWidget(this->consumableParts);

	this->thirdList = new QListWidget();
	this->thirdWindow = new QVBoxLayout();
	this->thirdWindow->addWidget(this->thirdList);
	

	//main app
	this->mainwindow_app = new QHBoxLayout(this);
	this->mainwindow_app->addLayout(this->mainWindow);
	this->mainwindow_app->addLayout(this->secWindow);
	this->mainwindow_app->addLayout(this->thirdWindow);
	//this->mainwindow_app->addLayout(this->window_middle);
	//this->mainwindow_app->addLayout(this->mainWindow_mylist);
	//this->mainwindow_app->addLayout(this->analysisWindow);
}

void GUI::connectSignalsAndSlots()
{
	QObject::connect(this->list, &QListWidget::itemSelectionChanged, [this]() {
		int selectedIndex = this->getSelectedIndex();
		if (selectedIndex < 0)
			return;

		TElement element = this->service.getAllElementsInRepository()[selectedIndex];
		});
	QObject::connect(this->list, &QListWidget::itemClicked, this, &GUI::populate);
	QObject::connect(this->addButton, &QPushButton::clicked, this, &GUI::addTask);
	QObject::connect(this->updateButton, &QPushButton::clicked, this, &GUI::updateTask);
	QObject::connect(this->deleteButton, &QPushButton::clicked, this, &GUI::deleteTask);
	QObject::connect(this->filterButton, &QPushButton::clicked, this, &GUI::filter);
	QObject::connect(this->listallButton, &QPushButton::clicked, this, &GUI::populate);
	QObject::connect(this->searchButton, &QPushButton::clicked, this, &GUI::populate_thirdList);
	
	QObject::connect(this->inputModify, &QLineEdit::textChanged, this, &GUI::populate_accordingToModified);
	/*
	QObject::connect(this->saveButton, &QPushButton::clicked, this, &GUI::save);
	QObject::connect(this->nextButton, &QPushButton::clicked, this, &GUI::next);
	QObject::connect(this->openMylistButton, &QPushButton::clicked, this, &GUI::openMylist);

	QObject::connect(this->modeButton, &QPushButton::clicked, this, &GUI::setMode);
	QObject::connect(this->repoLocationButton, &QPushButton::clicked, this, &GUI::updateRepoFile);
	QObject::connect(this->repoLocation_mylistButton, &QPushButton::clicked, this, &GUI::updateMylistFile);
	*/
}


void GUI::populate()
{
	this->list->clear();

	auto elements = this->service.getAllElementsInRepository();
	for (auto& element : elements)
	{
		this->list->addItem(QString::fromStdString(element.toString()));
		//qDebug() << QString::fromStdString(task.toString());
	}
}



void GUI::populate_thirdList()
{
	this->thirdList->clear();

	std::string wordToMatch = this->inputModify->text().toStdString();

	auto element = this->service.bestMatching(wordToMatch);

	this->thirdList->addItem(QString::fromStdString(element.toStringContent()));
}

int GUI::getSelectedIndex()
{
	QModelIndexList selectedIndexes = this->list->selectionModel()->selectedIndexes();
	if (selectedIndexes.size() == 0)
		return -1;
	int selectedIndex = selectedIndexes.at(0).row();
	return selectedIndex;
}

void GUI::setSelectedIndex(const int& index)
{
	this->list->item(index)->setSelected(true);
}

void GUI::addTask()
{
	/*
	bool exceptionRaised = false;
	std::string title = this->inputTitle->text().toStdString();
	std::string type = this->inputType->text().toStdString();
	std::string lastPerformed = this->inputLastPerformed->text().toStdString();
	std::string timesPerformed = this->inputTimesPerformed->text().toStdString();
	std::string vision = this->inputVision->text().toStdString();
	try {
		this->service.addTaskService(title, type, lastPerformed, timesPerformed, vision);
	}
	catch (Exception & error)
	{
		exceptionRaised = true;
		QMessageBox::critical(this, QString::fromStdString(std::string("Error")), QString::fromStdString(error.message), 0, 0);
	}
	if (!exceptionRaised) {
		this->populate();
		this->clearFields();
	}
	*/
}

void GUI::updateTask()
{
	/*
	bool exceptionRaised = false;
	std::string title = this->inputTitle->text().toStdString();
	std::string type = this->inputType->text().toStdString();
	std::string lastPerformed = this->inputLastPerformed->text().toStdString();
	std::string timesPerformed = this->inputTimesPerformed->text().toStdString();
	std::string vision = this->inputVision->text().toStdString();
	try {
		this->service.updateTaskService(title, type, lastPerformed, timesPerformed, vision);
	}
	catch (Exception & error)
	{
		QMessageBox::critical(this, QString::fromStdString(std::string("Error")), QString::fromStdString(error.message), 0, 0);
	}
	this->populate();
	this->clearFields();
	*/
}

void GUI::deleteTask()
{
	bool exceptionRaised = false;
	std::string name = this->inputName->text().toStdString();
	try {
		this->service.deleteElementService(name);
	}
	catch (Exception & error)
	{
		QMessageBox::critical(this, QString::fromStdString(std::string("Error")), QString::fromStdString(error.message), 0, 0);
	}
	this->populate();
	this->clearFields();
}

void GUI::filter()
{
	std::string category = this->inputName->text().toStdString();
	std::vector<TElement> filteredList = this->service.filter(category);
	this->list->clear();
	for (auto& element : filteredList)
	{
		this->list->addItem(QString::fromStdString(element.toString()));
		//qDebug() << QString::fromStdString(task.toString());
	}
}

void GUI::clearRepoDisplay()
{
	this->list->clear();
}


void GUI::clearFields()
{
	this->inputModify->clear();
	this->inputName->clear();
	//this->inputQuantity->clear();
}

void GUI::clearFields_middle()
{
	//this->inputRepoLocation->clear();
	//this->inputRepoLocation_mylist->clear();
}



void GUI::populate_accordingToModified()
{
	this->list->clear();
	std::vector<TElement> elements;
	std::string wordToMatch = this->inputModify->text().toStdString();
	if (wordToMatch == "")
		elements = this->service.getAllElementsInRepository();
	else
		elements = this->service.matchElements(wordToMatch);
	for (auto& element : elements) {
		this->list->addItem(QString::fromStdString(element.toString()));
	}
}

