#include "LabTest2.h"
#include <QtWidgets/QApplication>

#include "Service.h"
#include "GUI.h"
#include <QtWidgets/QApplication>
#include <QHBoxLayout>
#include <qlabel.h>
#include <qlistwidget.h>

int main(int argc, char* argv[])
{
	test_delete_elementNotInRepo();
	test_delete_valid();

	QApplication a{ argc, argv };

	Service service{};
	service.setRepoFilename("test2file.txt");
	GUI gui{ service };

	gui.show();

	return a.exec();
}

