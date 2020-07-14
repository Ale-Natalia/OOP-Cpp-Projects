#include "MylistTableModel.h"

int MylistTableModel::rowCount(const QModelIndex& parent) const
{
	return this->repository->getSize();
}

int MylistTableModel::columnCount(const QModelIndex& parent) const
{
	int numberOfAttributes = 5;
	return numberOfAttributes + 1;
}

QVariant MylistTableModel::data(const QModelIndex& index, int role) const
{
	int row = index.row();
	int column = index.column();
	TElement currentElement = this->repository->getElements()[row];

	if (role == Qt::DisplayRole) {
		switch (column) {
		case 0:
			return QString::fromStdString(currentElement.getTitle());
		case 1:
			return QString::fromStdString(currentElement.getType());
		case 2:
			return QString::fromStdString(currentElement.getLastPerformed().toString());
		case 3:
			return QString::number(currentElement.getTimesPerformed());
		case 4:
			return QString::fromStdString(currentElement.getVision());
		default:
			break;
		}
	}
	if (column == 5)
		if (role == Qt::DecorationRole) {
			int numberOfPictures = this->pictures.size();
			int picturePosition = currentElement.getTitle().size() % numberOfPictures;
			std::string pictureName = this->pictures[picturePosition];
			QPixmap picture = QPixmap(QString::fromStdString(pictureName));

			return picture;
		}
	return QVariant();
}

QVariant MylistTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole) {
		if (orientation == Qt::Horizontal) {
			switch (section) {
			case 0:
				return QString("Title");
			case 1:
				return QString("Type");
			case 2:
				return QString("Last Performed");
			case 3:
				return QString("Times Performed");
			case 4:
				return QString("Vision");
			case 5:
				return QString("Picture");
			default:
				break;
			}
		}
	}
	return QVariant();
}

bool MylistTableModel::addRow(int row, const QModelIndex& parent)
{
	int rowi = this->rowCount(parent) + 1;
	beginInsertRows(parent, rowi, rowi);
	endInsertRows();
	emit dataChanged(createIndex(rowi, 0), createIndex(rowi, 5));
	//return false;
	return true;
}

bool MylistTableModel::beginAddRow()
{
	int row = this->rowCount(QModelIndex());
	beginInsertRows(QModelIndex(), row, row);
	return true;
}

bool MylistTableModel::endAddRow()
{
	endInsertRows();
	return true;
}

bool MylistTableModel::beginDeleteRow()
{
	int row = this->rowCount(QModelIndex())- 1;
	beginRemoveRows(QModelIndex(), row, row);
	return true;
}

bool MylistTableModel::endDeleteRow()
{
	endRemoveRows();
	return true;
}

Repository* MylistTableModel::getRepo()
{
	return this->repository;
}
