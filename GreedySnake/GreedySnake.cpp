#include "GreedySnake.h"
#include<QPixmap>
#include<QBrush>
#include<QPainter>
#include<QOpenGLWidget>
#include "GameController.h"
#include "Information.h"

static const int WIDGETW{ Information::value({"MainWindowSize","width"}).toInt() };
static const int WIDGETH{ Information::value({"MainWindowSize","height"}).toInt() };
static const int GRIDW{ Information::value({"GridSize","width"}).toInt() };
static const int GRIDH{ Information::value({"GridSize","height"}).toInt() };

GreedySnake::GreedySnake(QWidget *parent)
	: QMainWindow(parent),\
	theScene(new QGraphicsScene{this}),\
	theView(new QGraphicsView{theScene,this})
{
	this->setCentralWidget(theView);
	this->resize(WIDGETW, WIDGETH);
	this->init();
}

void GreedySnake::init()
{
	this->initGraph();//初始化view,scene
	game = new GameController{ theScene,this };//必须先初始化scene才能初始化
}

void GreedySnake::initGraph()
{
	theView->setViewport(new QOpenGLWidget);//使用openGL绘制
	//背景网格
	const int w{ GRIDW }, h{ GRIDH };
	QPixmap pixmap(w, h);
	QPainter painter{ &pixmap };
	painter.setBrush(QBrush{ Qt::gray });
	painter.drawRect(0, 0, w, h);
	//theScene->setBackgroundBrush(QBrush{ pixmap });
	theView->setBackgroundBrush(QBrush{ pixmap });//设置的是view的scene
}
