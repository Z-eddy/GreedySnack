#include "GreedySnack.h"
#include<QPixmap>
#include<QBrush>
#include<QPainter>

GreedySnack::GreedySnack(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setCentralWidget(ui.graphicsView);
	this->resize(800, 600);
	this->init();
}

void GreedySnack::init()
{
	this->initGraph();
}

void GreedySnack::initGraph()
{
	theScene = new QGraphicsScene(this);
	ui.graphicsView->setScene(theScene);
	//��������
	const int w{ 20 }, h{ 20 };
	QPixmap pixmap(w, h);
	QPainter painter{ &pixmap };
	painter.setBrush(QBrush{ Qt::gray });
	painter.drawRect(0, 0, w, h);
	//theScene->setBackgroundBrush(QBrush{ pixmap });
	theScene->setBackgroundBrush(QBrush{ pixmap });//���õ���view��scene
}
