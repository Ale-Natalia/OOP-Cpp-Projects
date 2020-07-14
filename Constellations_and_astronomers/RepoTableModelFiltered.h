#pragma once
#pragma once
#include <qabstractitemmodel.h>
#include "Repository.h"
#include "RepoTableModel.h"
#include "Domain.h"
#include <QStyledItemDelegate>
#include <qlabel.h>

typedef Star Item;

template <typename TElement>
class RepoTableModelFiltered : public RepoTableModel<TElement> {
private:
	Repository<TElement>* repository;
	std::string constellation;

public:
	RepoTableModelFiltered(Repository<TElement>* repo, std::string constellation) : repository{ repo }, constellation{ constellation } {}

	int rowCount(const QModelIndex& parent = QModelIndex())const {
		int count = 0;
		for (auto& element : this->repository->getElements()) {
			if (element.getConstellation() == this->constellation)
				count++;
		}
		return count;
	};
	//int columnCount(const QModelIndex& parent = QModelIndex())const;
	
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const {
		int row = index.row();
		int column = index.column();
		std::vector<Item> filteredElements;
		for (auto& element : this->repository->getElements()) {
			if (element.getConstellation() == this->constellation)
				filteredElements.push_back(element);
		}
		Item currentElement = filteredElements[row];

		if (role == Qt::DisplayRole) {
			switch (column) {
			case 0:
				return QString::fromStdString(currentElement.getName());
			case 1:
				return QString::fromStdString(currentElement.getConstellation());
			case 2:
				return QString::number(currentElement.getRA());
			case 3:
				return QString::number(currentElement.getDec());
			case 4:
				return QString::number(currentElement.getDiameter());
			default:
				break;
			}
		}
		return QVariant();
	};
	//QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

	//bool addRow(int row, const QModelIndex& parent = QModelIndex());
	//bool beginAddRow();
	//bool endAddRow();
	//bool beginDeleteRow();
	//bool endDeleteRow();

	//Repository* getRepo();
	std::string getConstellation() {return this->constellation};
};