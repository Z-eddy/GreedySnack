#pragma once

#include <QtWidgets/QMainWindow>
#include<QGraphicsScene>
#include<QGraphicsView>

class GameController;
namespace Ui { class GreedySnackClass; }

class GreedySnack : public QMainWindow
{
	Q_OBJECT

public:
	GreedySnack(QWidget *parent = Q_NULLPTR);

private:
	void init();
		void initGraph();

	QGraphicsScene *theScene;
	QGraphicsView *theView;
	GameController *game;
};
