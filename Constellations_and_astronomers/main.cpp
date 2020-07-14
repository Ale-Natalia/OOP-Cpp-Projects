#include "FinalExam_prep.h"
#include <QtWidgets/QApplication>
#include "Startup.h"

int main(int argc, char *argv[])
{
    //testAddValid();
    //testAddInvalidElementInRepo();
    //testAddInvalidEmptyTitle();
    //testAddInvalidNegativeDiameter();
    QApplication a(argc, argv);
    //FinalExam_prep w;
    //w.show();
    Startup* startup = new Startup("astronomers.txt", "stars.txt");
    return a.exec();
}
