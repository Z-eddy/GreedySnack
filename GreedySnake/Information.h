#pragma once
#include<QString>
#include<QVector>
#include<QJsonValueRef>
//�������information.jsonʹ��
class Information
{
public:
	Information();
	~Information();

	static QJsonValue value(const QVector<QString>&info);
};
