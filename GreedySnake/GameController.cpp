#include "GameController.h"
#include<chrono>
#include "Food.h"
#include "Snake.h"
#include"Information.h"
using std::chrono::system_clock;

static const int WIDGETW{ Information::value({"MainWindowSize","width"}).toInt() };
static const int WIDGETH{ Information::value({"MainWindowSize","height"}).toInt() };

GameController::GameController(QGraphicsScene *scene,QObject *parent)
	: theScene(scene), QObject(parent), timer(this), theSnake(new Snake),\
	e(system_clock::now().time_since_epoch().count()),\
	dw(-WIDGETW/2,WIDGETW/2),dh(-WIDGETH/2,WIDGETH/2)
{
	init();
}

GameController::~GameController()
{
}

void GameController::pause()
{
	disconnect(&timer, &QTimer::timeout, theScene, &QGraphicsScene::advance);
	timer.stop();
}

void GameController::resume()
{
	connect(&timer, &QTimer::timeout, theScene, &QGraphicsScene::advance);
	timer.start();
}

void GameController::init()
{
	timer.start(1000 / 33);

	Food *f0{ new Food{0,-50} };
	theScene->addItem(f0);
	theScene->addItem(theSnake);

	resume();
}

QPointF GameController::randomCoordinate()
{
	qreal x{ dw(e) };
	qreal y{ dh(e) };
	return{ x,y };
}

void GameController::newFood()
{

}

void GameController::on_eatFood(QGraphicsItem*food)
{
	theScene->removeItem(food);
	delete food;

}
