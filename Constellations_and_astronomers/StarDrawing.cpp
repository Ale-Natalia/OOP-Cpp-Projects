#include "StarDrawing.h"
#include <cmath>

StarDrawing::StarDrawing(std::string starName, Repository<Item>* repo, QWidget* parent)
{
	this->mainStarName = starName;
	this->repo = repo;
	//this->drawAllStars();
}

StarDrawing::~StarDrawing()
{
	//delete this->mainStar;
	delete this->repo;
}

QSize StarDrawing::sizeHint() const
{
	return QSize{ 600, 400 };
}

void StarDrawing::drawAllStars()
{
	int numberOfStars = this->repo->getSize();
	Star mainStar = this->repo->getElements()[this->repo->searchElementByName(this->mainStarName)];
	std::string constellation = mainStar.getConstellation();
	std::vector<Item> stars = this->repo->getElements();
	for (auto& star : stars) {
		if (star.getConstellation() == constellation) {
			if (star == mainStar) {
				this->drawMainStar(&mainStar);
			}
			else {
				this->drawOtherStar(&star);
			}
		}
	}
}

void StarDrawing::drawMainStar(Star* star)
{
	QPainter painter{ this };
	
	QPen pen(Qt::red, 1, Qt::SolidLine, Qt::RoundCap);
	painter.setPen(pen);
	QBrush brush(Qt::red, Qt::FDiagPattern);
	painter.drawEllipse(xStar(star), yStar(star), star->getDiameter(), star->getDiameter());

}

void StarDrawing::drawOtherStar(Star* star)
{
	QPainter painter{ this };

	QPen pen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap);
	painter.setPen(pen);
	QBrush brush(Qt::black, Qt::FDiagPattern);
	painter.drawEllipse(xStar(star), yStar(star), star->getDiameter(), star->getDiameter());
}

int StarDrawing::xStar(Star* star)
{
	int RA = star->getRA();
	int Dec = star->getDec();
	return RA;
}

int StarDrawing::yStar(Star* star)
{
	int RA = star->getRA();
	int Dec = star->getDec();
	int hypothenuse = RA / cos(Dec*3.1415/180);
	return sin(Dec * 3.1415 / 180) * hypothenuse;
}

void StarDrawing::paintEvent(QPaintEvent* event)
{
	this->drawAllStars();
}
