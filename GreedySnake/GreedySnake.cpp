#include "GreedySnake.h"
#include<QPixmap>
#include<QBrush>
#include<QPainter>
#include<QOpenGLWidget>
#include "GameController.h"

GreedySnake::GreedySnake(QWidget *parent)
	: QMainWindow(parent),\
	theScene(new QGraphicsScene{this}),\
	theView(new QGraphicsView{theScene,this})
{
	this->setCentralWidget(theView);
	this->resize(800, 600);
	this->init();
}

void GreedySnake::init()
{
	this->initGraph();//��ʼ��view,scene
	game = new GameController{ theScene,this };//�����ȳ�ʼ��scene���ܳ�ʼ��
}

void GreedySnake::initGraph()
{
	theView->setViewport(new QOpenGLWidget);//ʹ��openGL����
	//��������
	const int w{ 20 }, h{ 20 };
	QPixmap pixmap(w, h);
	QPainter painter{ &pixmap };
	painter.setBrush(QBrush{ Qt::gray });
	painter.drawRect(0, 0, w, h);
	//theScene->setBackgroundBrush(QBrush{ pixmap });
	theView->setBackgroundBrush(QBrush{ pixmap });//���õ���view��scene
}
