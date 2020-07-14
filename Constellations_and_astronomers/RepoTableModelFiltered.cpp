#include "RepoTableModelFiltered.h"

/*
int RepoTableModelFiltered::rowCount(const QModelIndex& parent) const
{
	int count = 0;
	for (auto& element : this->repository->getElements()) {
		if (element.getConstellation() == this->constellation)
			count++;
	}
	return count;
}

QVariant RepoTableModelFiltered::data(const QModelIndex& index, int role) const
{
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
}

std::string RepoTableModelFiltered::getConstellation()
{
	return this->constellation;
}
*/