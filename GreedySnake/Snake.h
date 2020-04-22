#pragma once

#include <QGraphicsItem>
#include<QVector>
#include<QPointf>

class GameController;

class Snake : public QGraphicsItem
{
public:
	Snake(GameController *controller,QGraphicsItem *parent = nullptr);
	~Snake();

	enum class MoveDirection { NoMove, Left, Right, Up, Down };

	virtual QRectF boundingRect() const override;
	virtual QPainterPath shape() const override;
	virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
	virtual void advance(int phase) override;

	void setLeftDir();
	void setRightDir();
	void setUpDir();
	void setDownDir();

private:
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void handleCollisions();//碰撞

	QVector<QPointF> tail;//每个节点的左上角点,scene坐标
	QPointF head;//头坐标
	GameController *theController;
	MoveDirection dirction;
	unsigned growing;
	unsigned speed;
	unsigned tickCounter;
};
