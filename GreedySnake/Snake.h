#pragma once

#include <QGraphicsItem>
#include<QVector>
#include<QPointf>

class Snake : public QGraphicsItem
{
public:
	Snake(QGraphicsItem *parent = nullptr);
	~Snake();

	virtual QRectF boundingRect() const override;
	virtual QPainterPath shape() const override;
	virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
	
private:
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

	QVector<QPointF> tail;//每个节点的左上角点,scene坐标
	QPointF head;//头坐标
};
