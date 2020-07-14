#include "MainRepoTableModel.h"

int MainRepoTableModel::rowCount(const QModelIndex& parent) const
{
	return this->repository->getSize();
}

int MainRepoTableModel::columnCount(const QModelIndex& parent) const
{
	int numberOfAttributes = 5;
	return numberOfAttributes;
}

QVariant MainRepoTableModel::data(const QModelIndex& index, int role) const
{
	return QVariant();
}
