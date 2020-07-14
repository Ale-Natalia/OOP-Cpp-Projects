#include "Lab12_GUI.h"
#include <QtWidgets/QApplication>

#include "Service.h"
#include "MylistWidget.h"
#include "GUI.h"
#include <QtWidgets/QApplication>
#include <QHBoxLayout>
#include <qlabel.h>
#include <qlistwidget.h>

int main(int argc, char* argv[])
{

	QApplication a{ argc, argv };

	//CSVRepo repo{ "C:\\Users\\antud\\Documents\\lab8.txt" };
	//ServantMirrorImage servantMirrorImage{ "C:\\Users\\antud\\Documents\\lab8.txt", "C:\\Users\\antud\\Documents\\lab9.csv" };
	//Validator validator{};
	//Service service{ repo, servantMirrorImage, validator, "A" };
	Service* service = new Service{};
	service->configRepos("configRepos.txt");
	MylistTableModel* model = new MylistTableModel(service->getMylist());
	MylistWidget* mylistWidget = new MylistWidget(model, model->getRepo());

	//mylistWidget->show();

	GUI gui{ service, mylistWidget };

	gui.show();

	return a.exec();

	//UI ui{ service };
	//ui.run();
	//return 0;
}

