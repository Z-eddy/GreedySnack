#pragma once

#include <QtWidgets/QMainWindow>
#include<QGraphicsScene>
#include "ui_GreedySnack.h"

class GreedySnack : public QMainWindow
{
	Q_OBJECT

public:
	GreedySnack(QWidget *parent = Q_NULLPTR);

private:
	void init();
		void initGraph();

	Ui::GreedySnackClass ui;
	QGraphicsScene *theScene;
};
