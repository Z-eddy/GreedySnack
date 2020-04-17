#include "GameController.h"
#include<iostream>
#include<chrono>
#include "Food.h"
#include "Snake.h"
#include"Information.h"
using std::chrono::system_clock;
using std::cout;
using std::endl;
using std::ends;

static const int WIDGETW{ Information::value({"MainWindowSize","width"}).toInt() };
static const int WIDGETH{ Information::value({"MainWindowSize","height"}).toInt() };

GameController::GameController(QGraphicsScene *scene,QObject *parent)
	: theScene(scene), QObject(parent), timer(this), theSnake(new Snake{ this }), \
	e(system_clock::now().time_since_epoch().count()),\
	dw(-WIDGETW/2+50,WIDGETW/2-50),dh(-WIDGETH/2+50,WIDGETH/2-50)
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
	timer.start(1000 / 15);

	Food *f0{ new Food{0,-50} };
	theScene->addItem(f0);
	theScene->addItem(theSnake);
	theScene->installEventFilter(this);

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
	const auto shape{ theSnake->shape() };
	const auto itemPos{ randomCoordinate() };
	if (shape.contains(itemPos)) {
		newFood();
	}
	else {
		theScene->addItem(new Food{ itemPos.x(),itemPos.y() });
	}
}

void GameController::handleKeyPress(QKeyEvent *event)
{
	switch (event->key())
	{
	case Qt::Key_Left:
		theSnake->setLeftDir();
		break;
	case Qt::Key_Right:
		theSnake->setRightDir();
		break;
	case Qt::Key_Up:
		theSnake->setUpDir();
		break;
	case Qt::Key_Down:
		theSnake->setDownDir();
		break;
	default:
		break;
	}
}

void GameController::gameOver()
{
	theScene->clear();
	theSnake = new Snake(this);
	theScene->addItem(theSnake);
	newFood();
}

void GameController::eatFood(QGraphicsItem*food)
{
	theScene->removeItem(food);
	delete food;
	newFood();
}

void GameController::eatItself()
{
	QTimer::singleShot(0, this, SLOT(gameOver()));
}

bool GameController::eventFilter(QObject *watched, QEvent *event)
{
	if (event->type() == QEvent::KeyPress) {
		handleKeyPress(dynamic_cast<QKeyEvent*>(event));
		return true;
	}
	else {
		return QObject::eventFilter(watched, event);
	}
}
