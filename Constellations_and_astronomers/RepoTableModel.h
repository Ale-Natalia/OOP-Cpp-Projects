#pragma once
#include <qabstractitemmodel.h>
#include "Repository.h"
#include "Domain.h"
#include <QStyledItemDelegate>
#include <qlabel.h>

typedef Star Item;

template <typename TElement>
class RepoTableModel : public QAbstractTableModel {
private:
	Repository<TElement>* repository;;

public:
	RepoTableModel() {
		this->repository = NULL;
	}
	RepoTableModel(Repository<TElement>* repo) : repository{ repo } {
	}

	virtual int rowCount(const QModelIndex& parent = QModelIndex())const { return this->repository->getSize(); };
	
	int columnCount(const QModelIndex& parent = QModelIndex())const {
		int numberOfAttributes = 5;
		return numberOfAttributes;
	};
	
	virtual QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const {
		int row = index.row();
		int column = index.column();
		TElement currentElement = this->repository->getElements()[row];

		if (role == Qt::DisplayRole || role == Qt::EditRole) {
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
	
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const {
		if (role == Qt::DisplayRole) {
			if (orientation == Qt::Horizontal) {
				switch (section) {
				case 0:
					return QString("Name");
				case 1:
					return QString("Constellation");
				case 2:
					return QString("RA");
				case 3:
					return QString("Dec");
				case 4:
					return QString("Diameter");
				default:
					break;
				}
			}
		}
		return QVariant();
	};

	bool setData(const QModelIndex& index, const QVariant& value, int role) {
		if (role != Qt::EditRole)
			return false;

		int row = index.row();
		int column = index.column();

		TElement currentElement = this->repository->getElements()[row];

		switch (column) {
		case 0:
			break;
		case 1:
		{
			std::string constellation = value.toString().toStdString();
			TElement newElement = currentElement;
			newElement.setConstellation(constellation);
			this->repository->updateElement(newElement);
			//currentElement.setName(name);
			break;
		}
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		default:
			break;
		}

		return true;
	};

	Qt::ItemFlags flags(const QModelIndex& index) const {
		int column = index.column();
		if (column == 1)
			return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
		else
			return Qt::ItemIsSelectable | Qt::ItemIsEnabled;
	};

	bool addRow(int row, const QModelIndex& parent = QModelIndex()) {
		int rowi = this->rowCount(parent) + 1;
		beginInsertRows(parent, rowi, rowi);
		endInsertRows();
		emit dataChanged(createIndex(rowi, 0), createIndex(rowi, 5));
		//return false;
		return true;
	};

	bool beginAddRow() {
		int row = this->rowCount(QModelIndex());
		beginInsertRows(QModelIndex(), row, row);
		return true;
	};

	bool endAddRow() {
		endInsertRows();
		return true;
	};

	bool beginDeleteRow() {
		int row = this->rowCount(QModelIndex()) - 1;
		beginRemoveRows(QModelIndex(), row, row);
		return true;
	};

	bool endDeleteRow() {
		endRemoveRows();
		return true;
	};

	Repository<TElement>* getRepo() { return this->repository; };
};