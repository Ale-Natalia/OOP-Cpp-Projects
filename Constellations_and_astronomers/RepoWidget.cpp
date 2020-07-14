#include "RepoWidget.h"

/*
RepoWidget::RepoWidget(RepoTableModel* model, Observable* observable, QWidget* parent)
{
	this->observable = observable;
	this->observable->addObserver(this);

	this->model = model;
	this->tableView = new QTableView;
	this->tableView->setModel(model);
	this->layout = new QVBoxLayout(this);
	this->layout->addWidget(this->tableView);
}

RepoWidget::~RepoWidget()
{
	this->observable->removeObserver(this);
}

void RepoWidget::update()
{
	this->tableView->viewport()->update();
}

void RepoWidget::setModel(QAbstractTableModel* model)
{
	this->tableView->setModel(model);
}

void RepoWidget::beginAddRow()
{
	this->model->beginAddRow();
}

void RepoWidget::endAddRow()
{
	this->model->endAddRow();
}

void RepoWidget::beginRemoveRow()
{
	this->model->beginDeleteRow();
}

void RepoWidget::endRemoveRow()
{
	this->model->endDeleteRow();
}

QTableView* RepoWidget::getTableView()
{
	return this->tableView;
}
*/