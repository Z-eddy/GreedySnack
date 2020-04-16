#include "Food.h"
#include<QRectF>
#include<QPainterPath>
#include<QPainter>

static const int w{ 20 }, h{ 20 };
static const qreal r{ 15.0 };
Food::Food(qreal x, qreal y, QGraphicsItem *parent)
	: QGraphicsItem(parent)
{
	this->setPos(x, y);
}

Food::~Food()
{
}

QRectF Food::boundingRect() const
{
	return QRectF(-w, -h, 2 * w, 2 * h);
}

QPainterPath Food::shape() const
{
	QPainterPath path;
	path.addEllipse(w / 2, h / 2, r, r);
	return path;
}

void Food::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget /*= nullptr*/)
{
	painter->save();

	painter->setRenderHint(QPainter::Antialiasing, true);
	painter->fillPath(shape(), Qt::red);

	painter->restore();
}
