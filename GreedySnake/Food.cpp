#include "Food.h"
#include<QRectF>
#include<QPainterPath>
#include<QPainter>
#include"Information.h"

static const int WIDGETW{ Information::value({"FoodSize","width"}).toInt() };
static const int h{ Information::value({"FoodSize","height"}).toInt() };
static const qreal r{ Information::value({"FoodSize","radius"}).toDouble() };
static const int ITEMTYPE{ Information::value({"Type","ItemType"}).toInt() };
static const int FOODTYPE{ Information::value({"Type","FoodType"}).toInt() };

Food::Food(qreal x, qreal y, QGraphicsItem *parent)
	: QGraphicsItem(parent)
{
	this->setPos(x, y);
	this->setData(ITEMTYPE, FOODTYPE);
}

Food::~Food()
{
}

QRectF Food::boundingRect() const
{
	return QRectF(-WIDGETW, -h, 2 * WIDGETW, 2 * h);
}

QPainterPath Food::shape() const
{
	QPainterPath path;
	path.addEllipse(WIDGETW / 2, h / 2, r, r);
	return path;
}

void Food::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget /*= nullptr*/)
{
	painter->save();

	painter->setRenderHint(QPainter::Antialiasing, true);
	painter->fillPath(shape(), Qt::red);

	painter->restore();
}
