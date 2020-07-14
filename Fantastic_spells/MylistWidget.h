#pragma once
#include <QWidget>
#include <qlayout.h>
#include "MylistTableModel.h"
#include <qtableview.h>
#include "Observer.h"

class MylistWidget : public QWidget, public Observer {
private:
	MylistTableModel* model;
	QTableView* tableView;
	QVBoxLayout* layout;
	Observable* observable;
public:
	MylistWidget(MylistTableModel* model, Observable* observable, QWidget* parent = Q_NULLPTR);
	~MylistWidget();
	void update() override;

	void beginAddRow();
	void endAddRow();
	void beginRemoveRow();
	void endRemoveRow();
};