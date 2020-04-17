#pragma once

#include<random>
#include <QObject>
#include<QGraphicsScene>
#include <QGraphicsItem>
#include<QTimer>
#include<QKeyEvent>

class Snake;

class GameController : public QObject
{
	Q_OBJECT

public:
	GameController(QGraphicsScene *scene,QObject *parent=nullptr);
	~GameController();

	void pause();
	void resume();

	void eatFood(QGraphicsItem*food);
	void eatItself();
	virtual bool eventFilter(QObject *watched, QEvent *event) override;

private:
	void init();
	QPointF randomCoordinate();
	void newFood();
	void handleKeyPress(QKeyEvent *event);

	QTimer timer;
	QGraphicsScene *theScene;
	Snake *theSnake;

	std::default_random_engine e;
	std::uniform_real_distribution<double>dw;
	std::uniform_real_distribution<double>dh;
private slots:
	void gameOver();
};
