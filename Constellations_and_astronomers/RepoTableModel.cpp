#include "RepoTableModel.h"

/*
int RepoTableModel::rowCount(const QModelIndex& parent) const
{
	return this->repository->getSize();
}

int RepoTableModel::columnCount(const QModelIndex& parent) const
{
	int numberOfAttributes = 5;
	return numberOfAttributes;
}

QVariant RepoTableModel::data(const QModelIndex& index, int role) const
{
	int row = index.row();
	int column = index.column();
	Item currentElement = this->repository->getElements()[row];

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
}

QVariant RepoTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
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
}

bool RepoTableModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
	if(role != Qt::EditRole)
		return false;

	int row = index.row();
	int column = index.column();

	Item currentElement = this->repository->getElements()[row];
	
	switch (column) {
		case 0:
			break;
		case 1:
		{
			std::string constellation = value.toString().toStdString();
			Item newElement = currentElement;
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
}

Qt::ItemFlags RepoTableModel::flags(const QModelIndex& index) const
{
	int column = index.column();
	if (column == 1)
		return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
	else
		return Qt::ItemIsSelectable | Qt::ItemIsEnabled;
}

bool RepoTableModel::addRow(int row, const QModelIndex& parent)
{
	int rowi = this->rowCount(parent) + 1;
	beginInsertRows(parent, rowi, rowi);
	endInsertRows();
	emit dataChanged(createIndex(rowi, 0), createIndex(rowi, 5));
	//return false;
	return true;
}

bool RepoTableModel::beginAddRow()
{
	int row = this->rowCount(QModelIndex());
	beginInsertRows(QModelIndex(), row, row);
	return true;
}

bool RepoTableModel::endAddRow()
{
	endInsertRows();
	return true;
}

bool RepoTableModel::beginDeleteRow()
{
	int row = this->rowCount(QModelIndex()) - 1;
	beginRemoveRows(QModelIndex(), row, row);
	return true;
}

bool RepoTableModel::endDeleteRow()
{
	endRemoveRows();
	return true;
}

Repository<Item>* RepoTableModel::getRepo()
{
	return this->repository;
}
*/
