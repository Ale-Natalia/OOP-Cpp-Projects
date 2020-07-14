#include "GUI.h"
#include "Service.h"
#include "Exceptions.h"
#include <QtWidgets/QMainWindow>

void GUI::initializeGUI()
{
	MylistTableModel* repoModel = new MylistTableModel(this->service->getRepo());
	this->repoTable = new MylistWidget(repoModel, repoModel->getRepo());

	//mode A
	this->list = new QListWidget();

	this->inputTitle = new QLineEdit();
	this->inputType = new QLineEdit();
	this->inputLastPerformed = new QLineEdit();
	this->inputTimesPerformed = new QLineEdit();
	this->inputVision = new QLineEdit();

	this->inputForm = new QFormLayout();
	this->inputForm->addRow("Title:", this->inputTitle);
	this->inputForm->addRow("Type:", this->inputType);
	this->inputForm->addRow("Last Performed:", this->inputLastPerformed);
	this->inputForm->addRow("Times Performed:", this->inputTimesPerformed);
	this->inputForm->addRow("Vision:", this->inputVision);

	this->addButton = new QPushButton("Add");
	this->updateButton = new QPushButton("Update");
	this->deleteButton = new QPushButton("Delete");
	this->listallButton = new QPushButton("List");
	this->undoButton = new QPushButton("Undo");
	this->redoButton = new QPushButton("Redo");
	this->openRepoButton = new QPushButton("Open repo");

	this->buttonsLayout = new QGridLayout();
	this->buttonsLayout->addWidget(this->addButton, 0, 1);
	this->buttonsLayout->addWidget(this->updateButton, 0, 2);
	this->buttonsLayout->addWidget(this->deleteButton, 0, 3);
	this->buttonsLayout->addWidget(this->undoButton, 1, 1);
	this->buttonsLayout->addWidget(this->redoButton, 1, 3);
	this->buttonsLayout->addWidget(this->listallButton, 2, 1);
	this->buttonsLayout->addWidget(this->openRepoButton, 2, 3);

	this->mainWindow = new QVBoxLayout();
	this->mainWindow->addWidget(this->list);
	//this->mainWindow->addWidget(this->repoTable);
	this->mainWindow->addLayout(this->inputForm);
	this->mainWindow->addLayout(this->buttonsLayout);

	//mode B
	MylistTableModel* mylistTableModel = new MylistTableModel(this->service->getMylist());
	this->mylistTable = new MylistWidget(mylistTableModel, mylistTableModel->getRepo());

	this->mylist = new QListWidget();

	this->nextElement = new QListWidget();
	this->nextElement->setFixedHeight(this->nextElement->sizeHintForRow(0) + 30 * list->frameWidth());
	//this->nextElement->setWrapping(false);

	this->inputTitle_mylist = new QLineEdit();

	this->inputForm_mylist = new QFormLayout();
	this->inputForm_mylist->addRow("Title of task to save:", this->inputTitle_mylist);

	this->saveButton = new QPushButton("Save");
	this->nextButton = new QPushButton("Next");
	this->undoMylistButton = new QPushButton("Undo mylist");
	this->redoMylistButton = new QPushButton("Redo mylist");
	this->filterButton = new QPushButton("Filter");
	this->openMylistButton = new QPushButton("Open mylist");

	this->buttonsLayout_mylist = new QGridLayout();
	this->buttonsLayout_mylist->addWidget(this->saveButton, 0, 1);
	this->buttonsLayout_mylist->addWidget(this->nextButton, 0, 2);
	this->buttonsLayout_mylist->addWidget(this->undoMylistButton, 1, 1);
	this->buttonsLayout_mylist->addWidget(this->redoMylistButton, 1, 2);
	this->buttonsLayout_mylist->addWidget(this->filterButton, 2, 1);
	this->buttonsLayout_mylist->addWidget(this->openMylistButton, 2, 2);

	this->mainWindow_mylist = new QVBoxLayout();
	this->mainWindow_mylist->addWidget(this->mylist);
	this->mainWindow_mylist->addWidget(this->nextElement);
	this->mainWindow_mylist->addLayout(this->inputForm_mylist);
	this->mainWindow_mylist->addLayout(this->buttonsLayout_mylist);

	//common elements
	this->modeButton = new QPushButton();
	//this->modeButton->setText(this->modeButton->isChecked() ? "Switch to mode A" : "Switch to mode B");

	this->inputRepoLocation = new QLineEdit();
	this->inputRepoLocation_mylist = new QLineEdit();
	this->repoLocationButton = new QPushButton("Set repo location");
	this->repoLocation_mylistButton = new QPushButton("Set mylist location");
	this->openMylistWindow = new QPushButton("Open mylist window");
	this->openRepoWindow = new QPushButton("Open main repo window");

	this->inputForm_mylist = new QFormLayout();
	this->inputForm_mylist->addRow("Repo location:", this->inputRepoLocation);
	this->inputForm_mylist->addRow("Mylist location:", this->inputRepoLocation_mylist);

	this->window_middle = new QVBoxLayout();
	this->window_middle->addWidget(this->modeButton);
	this->window_middle->addLayout(this->inputForm_mylist);
	//QLabel* l = new QLabel;
	//QPixmap* pm = new QPixmap(QString("cafea2.jpg"));
	//pm->scaled(100, Qt::IgnoreAspectRatio);
	//l->setPixmap(*pm);
	//this->window_middle->addWidget(l);
	this->window_middle->addWidget(this->repoLocationButton);
	this->window_middle->addWidget(this->repoLocation_mylistButton);
	this->window_middle->addWidget(this->openRepoWindow);
	this->window_middle->addWidget(this->openMylistWindow);

	this->undoShortcut = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z), this);
	this->redoShortcut = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Y), this);

	
	//analysis
	/*
	this->barSeries = new QBarSeries();
	this->chart = new QChart();
	this->chartView = new QChartView();
	this->analysisWindow = new QHBoxLayout();
	this->updateAnalysisButton = new QPushButton("Update analysis");
	*/

	this->mylistWindow = new QVBoxLayout;
	//this->mylistWindow->addWidget(this->mylistTable);

	//main app
	this->mainwindow_app = new QHBoxLayout(this);
	this->mainwindow_app->addLayout(this->mainWindow);
	this->mainwindow_app->addLayout(this->window_middle);
	this->mainwindow_app->addLayout(this->mainWindow_mylist);
	//this->mainwindow_app->addLayout(this->analysisWindow);
}

void GUI::connectSignalsAndSlots()
{
	QObject::connect(this->addButton, &QPushButton::clicked, this, &GUI::addTask);
	QObject::connect(this->updateButton, &QPushButton::clicked, this, &GUI::updateTask);
	QObject::connect(this->deleteButton, &QPushButton::clicked, this, &GUI::deleteTask);
	QObject::connect(this->undoButton, &QPushButton::clicked, this, &GUI::undoRepo);
	QObject::connect(this->redoButton, &QPushButton::clicked, this, &GUI::redoRepo);
	QObject::connect(this->listallButton, &QPushButton::clicked, this, &GUI::populate_accordingToMode);
	QObject::connect(this->openRepoButton, &QPushButton::clicked, this, &GUI::openRepo);

	QObject::connect(this->saveButton, &QPushButton::clicked, this, &GUI::save);
	QObject::connect(this->nextButton, &QPushButton::clicked, this, &GUI::next);
	QObject::connect(this->undoMylistButton, &QPushButton::clicked, this, &GUI::undoMylist);
	QObject::connect(this->redoMylistButton, &QPushButton::clicked, this, &GUI::redoMylist);
	QObject::connect(this->filterButton, &QPushButton::clicked, this, &GUI::filter);
	QObject::connect(this->openMylistButton, &QPushButton::clicked, this, &GUI::openMylist);

	QObject::connect(this->modeButton, &QPushButton::clicked, this, &GUI::setMode);
	QObject::connect(this->repoLocationButton, &QPushButton::clicked, this, &GUI::updateRepoFile);
	QObject::connect(this->repoLocation_mylistButton, &QPushButton::clicked, this, &GUI::updateMylistFile);
	QObject::connect(this->openRepoWindow, &QPushButton::clicked, [this] {this->repoTable->show();});
	QObject::connect(this->openMylistWindow, &QPushButton::clicked, [this] {this->mylistTable->show();});

	QObject::connect(this->undoShortcut, &QShortcut::activated, this, &GUI::undoAccordingToMode);
	QObject::connect(this->redoShortcut, &QShortcut::activated, this, &GUI::redoAccordingToMode);
}

/*
void GUI::createBarchart()
{
	this->barSeries->clear();
	delete this->chart;
	this->chart = new QChart();
	std::vector<std::pair<std::string, int>> typesStatistics;
	std::vector<QBarSet*> barSets;
	//std::vector<std::string> categories;
	QStringList types;
	int numberOfBarSets = 0;
	for (const auto& typePair : typesStatistics) {
		const std::string type = typePair.first;
		QBarSet* newBarSet = new QBarSet(QString::fromStdString(type));
		int numberOfElementsWithType = typePair.second;
		newBarSet->append(numberOfElementsWithType);
		barSets.push_back(newBarSet);
		numberOfBarSets++;
		//categories.push_back(type);
		types.append(QString::fromStdString(type));
		this->barSeries->append(newBarSet);
	}
	this->chart->addSeries(this->barSeries);
	this->chart->setTitle("Types statistics");
	this->chart->setAnimationOptions(QChart::SeriesAnimations);
	
	QBarCategoryAxis* axisX = new QBarCategoryAxis();
	axisX->append(types);
	this->chart->addAxis(axisX, Qt::AlignBottom);
	this->barSeries->attachAxis(axisX);

	//QValueAxis* axisY = new QValueAxis();
	//axisY->setRange(0, 500);
	//chart->addAxis(axisY, Qt::AlignLeft);
	//this->barSeries->attachAxis(axisY);


	this->chart->legend()->setVisible(true);
	chart->legend()->setAlignment(Qt::AlignBottom);

	delete this->chartView;
	this->chartView = new QChartView(chart);
	this->chartView->setRenderHint(QPainter::Antialiasing);

	delete this->analysisWindow;
	this->analysisWindow = new QHBoxLayout();
	this->analysisWindow->addWidget(this->chartView);
	this->analysisWindow->addWidget(this->updateAnalysisButton);

	this->mainwindow_app->addLayout(this->analysisWindow);
}
*/

void GUI::populate()
{
	this->list->clear();

	auto tasks = this->service->getAllTasksInRepository();
	for (auto& task : tasks)
	{
		this->list->addItem(QString::fromStdString(task.toString()));
		//qDebug() << QString::fromStdString(task.toString());
	}
}

void GUI::populate_mylist()
{
	this->mylist->clear();

	auto tasks = this->service->getAllMirrorImageTasks();
	for (auto& task : tasks)
	{
		this->mylist->addItem(QString::fromStdString(task.toString()));
	}
}

void GUI::populate_accordingToMode()
{
	std::string mode = this->service->getMode();
	qDebug() << QString::fromStdString(mode);
	if (mode == "A")
	{
		this->populate();
		this->modeButton->setText("Switch to mode B");
	}
	else if (mode == "B")
	{
		this->populate_mylist();
		this->modeButton->setText("Switch to mode A");
	}
}

void GUI::addTask()
{
	bool exceptionRaised = false;
	std::string title = this->inputTitle->text().toStdString();
	std::string type = this->inputType->text().toStdString();
	std::string lastPerformed = this->inputLastPerformed->text().toStdString();
	std::string timesPerformed = this->inputTimesPerformed->text().toStdString();
	std::string vision = this->inputVision->text().toStdString();
	try {
		this->repoTable->beginAddRow();
		this->service->addTaskService(title, type, lastPerformed, timesPerformed, vision);
		this->repoTable->endAddRow();
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
}

void GUI::updateTask()
{
	bool exceptionRaised = false;
	std::string title = this->inputTitle->text().toStdString();
	std::string type = this->inputType->text().toStdString();
	std::string lastPerformed = this->inputLastPerformed->text().toStdString();
	std::string timesPerformed = this->inputTimesPerformed->text().toStdString();
	std::string vision = this->inputVision->text().toStdString();
	try {
		this->service->updateTaskService(title, type, lastPerformed, timesPerformed, vision);
	}
	catch (Exception & error)
	{
		QMessageBox::critical(this, QString::fromStdString(std::string("Error")), QString::fromStdString(error.message), 0, 0);
	}
	this->populate();
	this->clearFields();
}

void GUI::deleteTask()
{
	bool exceptionRaised = false;
	std::string title = this->inputTitle->text().toStdString();
	try {
		this->repoTable->beginRemoveRow();
		this->service->deleteTaskService(title);
		this->repoTable->endRemoveRow();
	}
	catch (Exception & error)
	{
		QMessageBox::critical(this, QString::fromStdString(std::string("Error")), QString::fromStdString(error.message), 0, 0);
	}
	this->populate();
	this->clearFields();
}

void GUI::undoRepo()
{
	try {
		this->repoTable->beginAddRow();
		this->repoTable->beginRemoveRow();
		int initialNumberOfRows = this->service->getRepoSize();
		this->service->undoRepo();
		int finalNumberOfRows = this->service->getRepoSize();
		if (finalNumberOfRows > initialNumberOfRows)
			this->repoTable->endAddRow();
		else if (finalNumberOfRows < initialNumberOfRows)
			this->repoTable->endRemoveRow();
	}
	catch (Exception & error)
	{
		QMessageBox::critical(this, QString::fromStdString(std::string("Error")), QString::fromStdString(error.message), 0, 0);
	}
	this->populate();
}

void GUI::redoRepo()
{
	try {
		this->repoTable->beginAddRow();
		this->repoTable->beginRemoveRow();
		int initialNumberOfRows = this->service->getRepoSize();
		this->service->redoRepo();
		int finalNumberOfRows = this->service->getRepoSize();
		if (finalNumberOfRows > initialNumberOfRows)
			this->repoTable->endAddRow();
		else if (finalNumberOfRows < initialNumberOfRows)
			this->repoTable->endRemoveRow();
	}
	catch (Exception & error)
	{
		QMessageBox::critical(this, QString::fromStdString(std::string("Error")), QString::fromStdString(error.message), 0, 0);
	}
	this->populate();
}

void GUI::filter()
{
	if (this->service->getMode() == "A")
	{
		QMessageBox::critical(this, QString::fromStdString(std::string("Error")), QString::fromStdString("Wrong mode"), 0, 0);
		return;
	}
	try {
		std::string type = this->inputType->text().toStdString();
		std::string timesPerformed = this->inputTimesPerformed->text().toStdString();
		std::vector<TElement> result = this->service->listFiltered(type, timesPerformed);
		this->clearRepoDisplay();
		for (auto& task : result)
		{
			if (task.getTitle() != "")
				this->list->addItem(QString::fromStdString(task.toString()));
		}
		this->inputType->clear();
		this->inputTimesPerformed->clear();
	}
	catch (Exception & error)
	{
		QMessageBox::critical(this, QString::fromStdString(std::string("Error")), QString::fromStdString(error.message), 0, 0);
	}
}

void GUI::undoMylist()
{
	try {

		this->mylistTable->beginAddRow();
		this->mylistTable->beginRemoveRow();
		int initialNumberOfRows = this->service->getMirrorImageSize();
		this->service->undoMylist();
		int finalNumberOfRows = this->service->getMirrorImageSize();
		if (finalNumberOfRows > initialNumberOfRows)
			this->mylistTable->endAddRow();
		else if (finalNumberOfRows < initialNumberOfRows)
			this->mylistTable->endRemoveRow();

		/*
		this->mylistTable->beginAddRow();
		this->mylistTable->beginRemoveRow();
		int initialNumberOfRows = this->service->getMirrorImageSize();
		this->service->undoMylist();
		int finalNumberOfRows = this->service->getMirrorImageSize();
		if (finalNumberOfRows > initialNumberOfRows)
			this->mylistTable->endAddRow();
		else if (finalNumberOfRows < initialNumberOfRows)
			this->mylistTable->endRemoveRow();
		*/
	}
	catch (Exception & error)
	{
		QMessageBox::critical(this, QString::fromStdString(std::string("Error")), QString::fromStdString(error.message), 0, 0);
	}
	this->populate_mylist();
}

void GUI::redoMylist()
{
	try {
		this->mylistTable->beginAddRow();
		this->mylistTable->beginRemoveRow();
		int initialNumberOfRows = this->service->getMirrorImageSize();
		this->service->redoMylist();
		int finalNumberOfRows = this->service->getMirrorImageSize();
		if (finalNumberOfRows > initialNumberOfRows)
			this->mylistTable->endAddRow();
		else if (finalNumberOfRows < initialNumberOfRows)
			this->mylistTable->endRemoveRow();
	}
	catch (Exception & error)
	{
		QMessageBox::critical(this, QString::fromStdString(std::string("Error")), QString::fromStdString(error.message), 0, 0);
	}
	this->populate_mylist();
}

void GUI::updateRepoFile()
{
	bool exceptionRaised = false;
	std::string repoFile = this->inputRepoLocation->text().toStdString();
	if (repoFile == "") {
		QMessageBox::critical(this, QString::fromStdString(std::string("Error")), QString::fromStdString("Empty input!"), 0, 0);
		return;
	}
		try {
		this->service->setCustodianFilename(repoFile);
	}
	catch (Exception & error)
	{
		QMessageBox::critical(this, QString::fromStdString(std::string("Error")), QString::fromStdString(error.message), 0, 0);
	}
	this->clearFields_middle();
	if (this->service->getMode() == "B")
	{
		this->clearMylistDisplay();
		this->populate_mylist();
	}
}

void GUI::updateMylistFile()
{
	bool exceptionRaised = false;
	std::string mylistFile = this->inputRepoLocation_mylist->text().toStdString();
	if (mylistFile == "") {
		QMessageBox::critical(this, QString::fromStdString(std::string("Error")), QString::fromStdString("Empty input!"), 0, 0);
		return;
	}
	try {
		this->service->setServantFilename(mylistFile);
	}
	catch (Exception & error)
	{
		QMessageBox::critical(this, QString::fromStdString(std::string("Error")), QString::fromStdString(error.message), 0, 0);
	}
	this->clearFields_middle();
	if (this->service->getMode() == "B")
	{
		this->clearMylistDisplay();
		this->populate_mylist();
	}
}

void GUI::undoAccordingToMode()
{
	if (this->service->getMode() == "A")
		this->undoRepo();
	else if (this->service->getMode() == "B")
		this->undoMylist();
}

void GUI::redoAccordingToMode()
{
	if (this->service->getMode() == "A")
		this->redoRepo();
	else if (this->service->getMode() == "B")
		this->redoMylist();
}

void GUI::save()
{
	bool exceptionRaised = false;
	std::string title = this->inputTitle_mylist->text().toStdString();
	if (title == "") {
		QMessageBox::critical(this, QString::fromStdString(std::string("Error")), QString::fromStdString("Empty title!"), 0, 0);
		return;
	}
	try {
		this->mylistTable->beginAddRow();
		bool added = this->service->saveTask(title);
		this->populate_mylist();
		this->inputTitle_mylist->clear();
		if (added)
			this->mylistTable->endAddRow();
	}
	catch (Exception & error) {
		exceptionRaised = true;
		QMessageBox::critical(this, QString::fromStdString(std::string("Error")), QString::fromStdString(error.message), 0, 0);
	}
}

void GUI::next()
{
	bool exceptionRaised = false;
	try {
		Task task = this->service->nextTask();
		QString task_qstring = QString::fromStdString(task.toString());
		this->nextElement->clear();
		this->nextElement->addItem(task_qstring);
	}
	catch (Exception & error)
	{
		exceptionRaised = true;
		QMessageBox::critical(this, QString::fromStdString(std::string("Error")), QString::fromStdString(error.message), 0, 0);
	}
}

void GUI::openMylist()
{
	try {
		this->service->openMylist();
	}
	catch (Exception & error) {
		QMessageBox::critical(this, QString::fromStdString(std::string("Error")), QString::fromStdString(error.message), 0, 0);
	}
}

void GUI::openRepo()
{
	try {
		this->service->openRepo();
	}
	catch (Exception & error) {
		QMessageBox::critical(this, QString::fromStdString(std::string("Error")), QString::fromStdString(error.message), 0, 0);
	}
}

void GUI::setMode()
{
	std::string currentMode = this->service->getMode();
	if (currentMode == "A") {
		this->service->setMode("B");
		this->clearRepoDisplay();
		this->populate_mylist();
		this->modeButton->setText("Switch to mode A");
	}
	else if (currentMode == "B") {
		this->service->setMode("A");
		this->clearMylistDisplay();
		this->populate();
		this->modeButton->setText("Switch to mode B");
	}
}

void GUI::clearRepoDisplay()
{
	this->list->clear();
}

void GUI::clearMylistDisplay()
{
	this->mylist->clear();
	this->nextElement->clear();
}

void GUI::clearFields()
{
	this->inputTitle->clear();
	this->inputType->clear();
	this->inputLastPerformed->clear();
	this->inputTimesPerformed->clear();
	this->inputVision->clear();
}

void GUI::clearFields_mylist()
{
	this->inputTitle_mylist->clear();
}

void GUI::clearFields_middle()
{
	this->inputRepoLocation->clear();
	this->inputRepoLocation_mylist->clear();
}

