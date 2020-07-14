#include "AnalysisWindow.h"

/*
void AnalysisWindow::drawAnalysis()
{
	
	
	

	//![2]
	QBarSeries* series = new QBarSeries();
	QBarSet* barSet = new QBarSet("Number of students/teacher");
	*barSet << this->service->getNumberOfStudentsWithNoTeacher();
	for (auto& teacher : this->teachers) {
		*barSet << this->service->getNumberOfStudentsForTeacher(teacher);
	}
	series->append(barSet);
	//![2]

	//![3]
	QChart* chart = new QChart();
	chart->addSeries(series);
	chart->setTitle("Analysis");
	chart->setAnimationOptions(QChart::SeriesAnimations);
	//![3]

	//![4]
	QStringList categories;
	categories << "No teacher";
	for (auto& teacher : this->teachers) {
		categories << QString::fromStdString(teacher->getName());
	}
	//categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";
	QBarCategoryAxis* axisX = new QBarCategoryAxis();
	axisX->append(categories);
	chart->addAxis(axisX, Qt::AlignBottom);
	series->attachAxis(axisX);

	QValueAxis* axisY = new QValueAxis();
	axisY->setRange(0, 15);
	chart->addAxis(axisY, Qt::AlignLeft);
	series->attachAxis(axisY);
	//![4]

	//![5]
	chart->legend()->setVisible(true);
	chart->legend()->setAlignment(Qt::AlignBottom);
	//![5]

	//![6]
	QChartView* chartView = new QChartView(chart);
	chartView->setRenderHint(QPainter::Antialiasing);

	this->setCentralWidget(chartView);
}
*/

/*
void AnalysisWindow::update()
{
	this->drawAnalysis();
}
*/