#include "Snake.h"
#include<QPainter>
#include<QPainterPath>
#include<QList>
#include"Information.h"

static const qreal BODYSIZE{ Information::value({"SnakeSize","bodySize"}).toDouble() };
static const int WIDGETW{ Information::value({"MainWindowSize","width"}).toInt() };
static const int WIDGETH{ Information::value({"MainWindowSize","height"}).toInt() };
static const int ITEMTYPE{ Information::value({"Type","ItemType"}).toInt() };
static const int FOODTYPE{ Information::value({"Type","FoodType"}).toInt() };

Snake::Snake(QGraphicsItem *parent)
	: QGraphicsItem(parent), growing(0), speed(10),\
	tickCounter(0),dirction(MoveDirection::NoMove)
{
}

Snake::~Snake()
{
}

QRectF Snake::boundingRect() const
{
	qreal minX{ head.x() };
	qreal minY{ head.y() };
	qreal maxX{ head.x() };
	qreal maxY{ head.y() };
	for (const auto &item : tail) {
		minX = minX > item.x() ? item.x() : minX;
		minY = minY > item.y() ? item.y() : minY;
		maxX = maxX < item.x() ? item.x() : maxX;
		maxY = maxY < item.y() ? item.y() : maxY;
	}

	const QPointF t{ this->mapFromScene(minX,minY) };
	const QPointF br{ this->mapFromScene(maxX + BODYSIZE,maxY + BODYSIZE) };
	QRectF bound{ t,br };
	return bound;
}

QPainterPath Snake::shape() const
{
	QPainterPath path;
	path.setFillRule(Qt::WindingFill);
	path.addRect(0, 0, BODYSIZE, BODYSIZE);//�ȼ���ͷ��
	for (const auto &item : tail) {
		const auto temp{ this->mapFromScene(item) };
		path.addRect(temp.x(),temp.y(),BODYSIZE,BODYSIZE);
	}
	return path;
}

void Snake::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget /*= nullptr*/)
{
	painter->save();

	painter->fillPath(shape(),Qt::yellow);

	painter->restore();
}

void Snake::advance(int phase)
{
	if (!phase)return;//advance�ĵ�һ��������
	if (dirction == MoveDirection::NoMove)return;
	if (++tickCounter%speed != 0)return;//����ʱ�ƶ�
	//body
	if (growing != 0) {//����һ��
		const auto bodyTail{ head };
		tail.push_back(bodyTail);
		--growing;
	}
	else {
		tail.takeFirst();
		tail.push_back(head);
	}
	//head
	switch (dirction) {
	case Snake::MoveDirection::NoMove:
		break;
	case Snake::MoveDirection::Left:
		moveLeft();
		break;
	case Snake::MoveDirection::Right:
		moveRight();
		break;
	case Snake::MoveDirection::Up:
		moveUp();
		break;
	case Snake::MoveDirection::Down:
		moveDown();
		break;
	default:
		break;
	}
	this->setPos(head);
	//��ײ���
	handleCollisions();
}

void Snake::moveLeft()
{
	head.rx() -= BODYSIZE;
	if (head.rx() < -WIDGETW / 2) {
		head.rx() = WIDGETW / 2;
	}
}

void Snake::moveRight()
{
	head.rx() += BODYSIZE;
	if (head.rx() > WIDGETW / 2) {
		head.rx() = -WIDGETW / 2;
	}
}

void Snake::moveUp()
{
	head.ry() -= BODYSIZE;
	if (head.ry() < -WIDGETH/2) {
		head.ry() = WIDGETH / 2;
	}
}

void Snake::moveDown()
{
	head.ry() += BODYSIZE;
	if (head.ry() > WIDGETH / 2) {
		head.ry() = -WIDGETH / 2;
	}
}

void Snake::handleCollisions()
{
	auto items{ this->collidingItems() };
	for (const auto&item : items) {
		if (item->data(ITEMTYPE) == FOODTYPE) {//��ײ��food
			emit eatFood(item);
			growing += 1;
		}
	}
	if (tail.contains(head)) {
		emit eatItself();
	}
}
