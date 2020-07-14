#include "GUI.h"

void GUI::initializeGUI()
{
	this->selectedStar = new Star();

	//this->userModel = new RepoTableModel(this->service->getRepo());
	//this->userFilteredModel = new RepoTableModelFiltered(this->service->getRepo(), this->user->getConstellation());
	this->userTable = new RepoWidget<Item>(this->userModel, this->userModel->getRepo());

	this->userList = new QListWidget();
	this->allList = new QListWidget();

	this->userLayout = new QVBoxLayout();
	this->allLayout = new QVBoxLayout();

	this->userForm = new QFormLayout();
	this->editDataButton = new QPushButton("Add star");
	this->inputName = new QLineEdit();
	this->inputRA = new QLineEdit();
	this->inputDec = new QLineEdit();
	this->inputDiameter = new QLineEdit();
	this->checkBox = new QCheckBox();
	this->spinBox = new QSpinBox();
	this->spinBox->setRange(-1, 1);
	this->userForm->addRow("Name", this->inputName);
	this->userForm->addRow("Right Ascencion", this->inputRA);
	this->userForm->addRow("Declination", this->inputDec);
	this->userForm->addRow("Diameter", this->inputDiameter);
	this->userForm->addRow(this->editDataButton);
	this->userForm->addRow(this->checkBox);
	this->userForm->addRow(this->spinBox);
	this->userLayout->addWidget(this->userList);
	this->userLayout->addWidget(this->userTable);
	this->userLayout->addLayout(this->userForm);

	this->allListForm = new QFormLayout();
	this->inputSearch = new QLineEdit();
	this->viewButton = new QPushButton("View star");
	this->answerButton = new QPushButton("Answer");
	this->allListForm->addRow("Search by name/ID", this->inputSearch);
	this->allListForm->addRow(this->viewButton);
	this->allListForm->addRow(this->answerButton);

	this->allLayout->addWidget(this->allList);
	this->allLayout->addLayout(this->allListForm);

	this->mainLayout = new QHBoxLayout(this);
	this->mainLayout->addLayout(this->userLayout);
	this->mainLayout->addLayout(this->allLayout);

	/*
	//edit window
	this->editWindow = new QWidget();
	this->editLayout = new QVBoxLayout(this->editWindow);
	this->editWindow->setWindowTitle(QString::fromStdString(this->user->getName()));
	this->editList = new QListWidget();
	this->editForm = new QFormLayout();
	this->inputEmail = new QLineEdit();
	this->inputThesisTitle = new QLineEdit();
	this->saveButton = new QPushButton("Save");
	this->cancelButton = new QPushButton("Cancel");
	this->editForm->addRow("Email", this->inputEmail);
	this->editForm->addRow("Thesis title", this->inputThesisTitle);
	this->editForm->addRow(this->saveButton);
	this->editForm->addRow(this->cancelButton);
	this->editLayout->addWidget(this->editList);
	this->editLayout->addLayout(this->editForm);
	*/

	//analysis window
	this->analysisWindow = new QWidget();
	//this->analysisLayout = new QVBoxLayout(this->analysisWindow);
}

void GUI::connectSignalsAndSlots()
{
	QObject::connect(this->userList, &QListWidget::itemSelectionChanged, [this]() {
		int selectedIndex = this->getSelectedIndexUserList();
		if (selectedIndex < 0)
			return;
		Star selectedstr;
		if (this->checkBox->isChecked()) {
			selectedstr = this->service->getAllItemsOfUser(this->user)[selectedIndex];
		}
		else if (!this->checkBox->isChecked()) {
			selectedstr = this->service->getAllItems()[selectedIndex];
		}
		this->selectedStar->setName(selectedstr.getName());
		this->selectedStar->setConstellation(selectedstr.getConstellation());
		this->selectedStar->setRA(selectedstr.getRA());
		this->selectedStar->setDec(selectedstr.getDec());
		this->selectedStar->setDiameter(selectedstr.getDiameter());
		});
	QObject::connect(this->allList, &QListWidget::itemSelectionChanged, [this]() {
		int selectedIndex = this->getSelectedIndexAllList();
		if (selectedIndex < 0)
			return;
		Star selectedstr = this->service->matchElements(this->inputSearch->text().toStdString())[selectedIndex];
		this->selectedStar->setName(selectedstr.getName());
		this->selectedStar->setConstellation(selectedstr.getConstellation());
		this->selectedStar->setRA(selectedstr.getRA());
		this->selectedStar->setDec(selectedstr.getDec());
		this->selectedStar->setDiameter(selectedstr.getDiameter());
		});
	QObject::connect(this->inputSearch, &QLineEdit::textChanged, this, &GUI::populateAllList);
	QObject::connect(this->editDataButton, &QPushButton::clicked, this, &GUI::addStar);
	QObject::connect(this->checkBox, &QCheckBox::stateChanged, this, &GUI::populateUserListAccordingly);
	QObject::connect(this->viewButton, &QPushButton::clicked, this, &GUI::openAnalysisWindow);
	QObject::connect(this->answerButton, &QPushButton::clicked, this, &GUI::answer);
	QObject::connect(this->spinBox, qOverload<int>(&QSpinBox::valueChanged), this, &GUI::setSpin);
}

int GUI::getSelectedIndexUserList()
{
	QModelIndexList selectedIndexes = this->userList->selectionModel()->selectedIndexes();
	if (selectedIndexes.size() == 0)
		return -1;
	int selectedIndex = selectedIndexes.at(0).row();
	return selectedIndex;
}

int GUI::getSelectedIndexAllList()
{
	QModelIndexList selectedIndexes = this->allList->selectionModel()->selectedIndexes();
	if (selectedIndexes.size() == 0)
		return -1;
	int selectedIndex = selectedIndexes.at(0).row();
	return selectedIndex;
}


void GUI::populateUserList()
{
	this->userList->clear();
	auto stars = this->service->getAllItemsOfUser(this->user);
	for (auto& star : stars) {
		this->userList->addItem(QString::fromStdString(star.toString()));
	}
}

void GUI::populateUserListComplete()
{
	this->userList->clear();
	auto stars = this->service->getAllItems();
	for (auto& star : stars) {
		this->userList->addItem(QString::fromStdString(star.toString()));
	}
}

void GUI::populateUserListAccordingly()
{
	if (this->checkBox->isChecked()) {
		//this->userModel = this->userFilteredModel;
		this->userTable->setModel(this->userFilteredModel);
		this->currentModel = this->userFilteredModel;
		this->populateUserList();
	}
	else {
		this->userTable->setModel(this->userModel);
		this->currentModel = this->userModel;
		this->populateUserListComplete();
	}
}

void GUI::populateAllList()
{
	this->allList->clear();
	std::string matchString = this->inputSearch->text().toStdString();
	auto stars = this->service->matchElements(matchString);
	for (auto& star : stars) {
		this->allList->addItem(QString::fromStdString(star.toString()));
	}
}



void GUI::update()
{
	//this->populateTeacherList();
	this->populateAllList();
	this->populateUserListAccordingly();
	//this->userTable->update();
}

void GUI::setCoordinator()
{
	try {
		//this->service->addCoordinatorToStudent(this->teacher, this->selectedStudent);
	}
	catch (Exception error) {
		QMessageBox::critical(this, QString::fromStdString("Error"), QString::fromStdString(error.message), 0, 0);
	}
}

void GUI::addStar()
{
	try {
		std::string name = this->inputName->text().toStdString();
		int RA = std::stoi(this->inputRA->text().toStdString());
		int Dec = std::stoi(this->inputDec->text().toStdString());
		int diameter = std::stoi(this->inputDiameter->text().toStdString());
		
		this->currentModel->beginAddRow();
		if (this->currentModel != this->userModel) {
			this->userModel->beginAddRow();
		}
		this->service->add(name, this->user->getConstellation(), RA, Dec, diameter);
		this->currentModel->endAddRow();
		if (this->currentModel != this->userModel) {
			this->userModel->endAddRow();
		}
	}
	catch (Exception error) {
		QMessageBox::critical(this, QString::fromStdString("Error"), QString::fromStdString(error.message), 0, 0);
	}
}

void GUI::answer()
{
	//const QColor& color = QColor::red();
	this->userList->item(this->getSelectedIndexUserList())->setBackground(Qt::green);
	this->answerButton->setDisabled(true);
}

void GUI::setSpin()
{
	QMessageBox::critical(this, QString::fromStdString("Spinner value"), QString::fromStdString(std::to_string(this->spinBox->value())), 0, 0);
}

void GUI::writeStarsToFileSorted()
{
	//this->service->writeStarsSorted();
}

void GUI::openAnalysisWindow()
{
	if (this->userTable->getTableView()->selectionModel()->selectedIndexes().size() == 0) {
		return;
	}
	//this->selectedStar = this->userTable->getTableView()->selectionModel()->selectedIndexes()[0].data();
	std::string name = this->userTable->getTableView()->selectionModel()->selectedIndexes()[0].data().toString().toStdString();
	//this->selectedStar = this->service->matchElements(name)[0];
	QWidget* starWindow = new QWidget();
	StarDrawing* starDrawing = new StarDrawing(name, this->service->getRepo());
	QVBoxLayout* analysisLayout = new QVBoxLayout(starWindow);
	analysisLayout->addWidget(starDrawing);
	starWindow->setWindowTitle(QString::fromStdString(name));
	starWindow->show();
}
