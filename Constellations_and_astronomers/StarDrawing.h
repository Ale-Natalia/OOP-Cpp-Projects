#pragma once
#include <QtWidgets/QMainWindow>
#include <QPen>
#include <qpainter.h>
#include "Repository.h"
#include "Domain.h"

typedef Star Item;

class StarDrawing : public QWidget {
private:
	Repository<Item>* repo;
	std::string mainStarName;

public:
	StarDrawing(std::string starName, Repository<Item>* repo, QWidget* parent = NULL);
	~StarDrawing();
	QSize sizeHint() const Q_DECL_OVERRIDE;
	void drawAllStars();
	void drawMainStar(Star* star);
	void drawOtherStar(Star* star);
	int xStar(Star* star);
	int yStar(Star* star);

protected:
	void paintEvent(QPaintEvent* event) override;
};