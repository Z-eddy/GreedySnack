#pragma once

#include <QtWidgets/QMainWindow>
#include<QGraphicsScene>
#include<QGraphicsView>

class GameController;

class GreedySnake : public QMainWindow
{
	Q_OBJECT

public:
	GreedySnake(QWidget *parent = Q_NULLPTR);

private:
	void init();
		void initGraph();

	QGraphicsScene *theScene;
	QGraphicsView *theView;
	GameController *game;
};
