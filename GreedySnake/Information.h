#pragma once
#include<QString>
#include<QVector>
#include<QJsonValueRef>
//必须搭配information.json使用
class Information
{
public:
	Information();
	~Information();

	static QJsonValue value(const QVector<QString>&info);
};
