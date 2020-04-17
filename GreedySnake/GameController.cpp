#include "GameController.h"
#include "Food.h"
#include "Snake.h"

GameController::GameController(QGraphicsScene *scene,QObject *parent)
	: theScene(scene), QObject(parent), timer(this), theSnake(new Snake)
{
	init();
}

GameController::~GameController()
{
}

void GameController::pause()
{
	disconnect(&timer, &QTimer::timeout, theScene, &QGraphicsScene::advance);
}

void GameController::resume()
{
	connect(&timer, &QTimer::timeout, theScene, &QGraphicsScene::advance);
}

void GameController::init()
{
	timer.start(1000 / 33);

	Food *f0{ new Food{0,-50} };
	theScene->addItem(f0);
	theScene->addItem(theSnake);

	resume();
}
