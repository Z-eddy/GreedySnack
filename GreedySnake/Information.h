#pragma once
#include<QString>
#include<QVector>
#include<QJsonValueRef>
//±ÿ–Î¥Ó≈‰information.json π”√
class Information
{
public:
	Information();
	~Information();

	static QJsonValue value(const QVector<QString>&info);
};
