#include "GreedySnake.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	GreedySnake w;
	w.show();
	return a.exec();
}
