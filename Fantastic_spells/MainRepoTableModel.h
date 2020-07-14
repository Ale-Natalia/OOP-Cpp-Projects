#pragma once
#include <qabstractitemmodel.h>
#include "Repository.h"
#include "InMemoryRepository.h"

class MainRepoTableModel :public QAbstractTableModel {
private:
	Repository* repository;

public:
	MainRepoTableModel(Repository& repo) : repository { &repo } {}

	int rowCount(const QModelIndex& parent = QModelIndex())const;
	int columnCount(const QModelIndex& parent = QModelIndex())const;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
};