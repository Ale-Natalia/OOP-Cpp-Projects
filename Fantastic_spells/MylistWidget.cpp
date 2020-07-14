#include "MylistWidget.h"

MylistWidget::MylistWidget(MylistTableModel* model, Observable* observable, QWidget* parent)
{
	this->observable = observable;
	this->observable->addObserver(this);

	this->model = model;
	this->tableView = new QTableView;
	this->tableView->setModel(model);
	this->layout = new QVBoxLayout(this);
	this->layout->addWidget(this->tableView);
}

MylistWidget::~MylistWidget()
{
	this->observable->removeObserver(this);
}

void MylistWidget::update()
{
	this->tableView->viewport()->update();
}

void MylistWidget::beginAddRow()
{
	this->model->beginAddRow();
}

void MylistWidget::endAddRow()
{
	this->model->endAddRow();
}

void MylistWidget::beginRemoveRow()
{
	this->model->beginDeleteRow();
}

void MylistWidget::endRemoveRow()
{
	this->model->endDeleteRow();
}
