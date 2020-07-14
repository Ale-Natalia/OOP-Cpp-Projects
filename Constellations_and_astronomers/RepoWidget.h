#pragma once
#pragma once
#include <QWidget>
#include <qlayout.h>
#include "RepoTableModel.h"
#include <qtableview.h>
#include "Observer.h"
#include <qabstractitemmodel.h>

template <typename TElement>
class RepoWidget : public QWidget, public Observer {
private:
	RepoTableModel<TElement>* model;
	QTableView* tableView;
	QVBoxLayout* layout;
	Observable* observable;
public:
	RepoWidget(RepoTableModel <TElement>* model, Observable* observable, QWidget* parent = Q_NULLPTR) {
		this->observable = observable;
		this->observable->addObserver(this);

		this->model = model;
		this->tableView = new QTableView;
		this->tableView->setModel(model);
		this->layout = new QVBoxLayout(this);
		this->layout->addWidget(this->tableView);
	};

	~RepoWidget() {
		this->observable->removeObserver(this);
	};

	void update() override {
		this->tableView->viewport()->update();
	};

	void setModel(QAbstractTableModel* model) { this->tableView->setModel(model); };
	void beginAddRow() { this->model->beginAddRow(); };
	void endAddRow() { this->model->endAddRow(); };
	void beginRemoveRow() { this->model->beginDeleteRow(); };
	void endRemoveRow() { this->model->endDeleteRow(); };
	QTableView* getTableView() { return this->tableView; };
};