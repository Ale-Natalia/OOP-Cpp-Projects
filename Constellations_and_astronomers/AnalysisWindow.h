#pragma once
#include <qwidget.h>
#include <qlabel.h>
#include <qbuttongroup.h>
#include <qboxlayout.h>
#include <QtWidgets/QApplication>
#include <qwidget.h>
#include <qlistwidget.h>
#include <qlineedit.h>
#include <qformlayout.h>
#include <qpushbutton.h>
#include <qmessagebox.h>
#include "Observer.h"
#include "Service.h"
#include "Exceptions.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>

QT_CHARTS_USE_NAMESPACE

/*
class AnalysisWindow : public QMainWindow, public Observer {
private:
	Service* service;
	std::vector<Astronomer*> astronomers;

	//QWidget* analysisWindow;

	void drawAnalysis() {};
public:
	AnalysisWindow() {
		this->service = new Service();
	}
	AnalysisWindow(Service* service, std::vector<Astronomer*> astronomers) {
		this->service = service;
		this->astronomers = astronomers;
		this->drawAnalysis();
	}
	~AnalysisWindow() {
		delete service;
	}
	void update()override;
};
*/