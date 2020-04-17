#pragma once

#include<random>
#include <QObject>
#include<QGraphicsScene>
#include <QGraphicsItem>
#include<QTimer>

class Snake;

class GameController : public QObject
{
	Q_OBJECT

public:
	GameController(QGraphicsScene *scene,QObject *parent=nullptr);
	~GameController();

	void pause();
	void resume();

private:
	void init();
	QPointF randomCoordinate();
	void newFood();

	QTimer timer;
	QGraphicsScene *theScene;
	Snake *theSnake;

	std::default_random_engine e;
	std::uniform_real_distribution<double>dw;
	std::uniform_real_distribution<double>dh;

private slots:
	void on_eatFood(QGraphicsItem*food);
	void on_eatItself();
};
