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

	QVector<QPointF> tail;//ÿ���ڵ�����Ͻǵ�,scene����
	QPointF head;//ͷ����
};
