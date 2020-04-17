#include "Information.h"
#include<QFile>
#include<QByteArray>
#include<QJsonDocument>
#include<QJsonObject>

//进入下一层的嵌套结构
static QJsonObject tear(const QString&key, const QJsonObject&item) {
	return item[key].toObject();
}

Information::Information()
{
}

Information::~Information()
{

}

QJsonValue Information::value(const QVector<QString>&info)
{
	//get QJsonObject from file
	QFile file{ "information.json" };
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))return QJsonValue{};//文件打开失败返回
	QByteArray data{ file.readAll() };
	QJsonDocument doc{ QJsonDocument::fromJson(data) };
	QJsonObject obj{ doc.object() };
	//read paras
	const int objDeep{ info.size() };
	if (objDeep == 0)return QJsonValue{};//输入参数为0返回
	QJsonObject temp;
	if (objDeep > 1) {//嵌套层数大于1时
		for (int i{ 0 }; i != objDeep - 1; ++i) {
			obj = tear(info[i], obj);
		}
		return obj[info.back()];
	}
	else {
		return obj[info.front()];
	}
}