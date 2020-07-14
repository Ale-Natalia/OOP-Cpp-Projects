#pragma once
#include <qabstractitemmodel.h>
#include "Repository.h"
#include <QStyledItemDelegate>
#include <qlabel.h>

class MylistTableModel :public QAbstractTableModel {
private:
	Repository* repository;
	std::vector<std::string> pictures;

public:
	MylistTableModel(Repository* repo) : repository{ repo } {
		this->pictures.push_back("elephant.jpg");
		this->pictures.push_back("milk.jpg");
		this->pictures.push_back("iceberg.jpg");
		this->pictures.push_back("rain.jpg");
		this->pictures.push_back("cafea.jpg");
	}

	int rowCount(const QModelIndex& parent = QModelIndex())const;
	int columnCount(const QModelIndex& parent = QModelIndex())const;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

	bool addRow(int row, const QModelIndex& parent = QModelIndex());
	bool beginAddRow();
	bool endAddRow();
	bool beginDeleteRow();
	bool endDeleteRow();

	Repository* getRepo();
};