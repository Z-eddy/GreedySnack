#pragma once

#include <QObject>
#include<QGraphicsScene>
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

	QTimer timer;
	QGraphicsScene *theScene;
	Snake *theSnake;
};
