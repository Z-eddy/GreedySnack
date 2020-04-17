#include "Information.h"
#include<QFile>
#include<QByteArray>
#include<QJsonDocument>
#include<QJsonObject>

//������һ���Ƕ�׽ṹ
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
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))return QJsonValue{};//�ļ���ʧ�ܷ���
	QByteArray data{ file.readAll() };
	QJsonDocument doc{ QJsonDocument::fromJson(data) };
	QJsonObject obj{ doc.object() };
	//read paras
	const int objDeep{ info.size() };
	if (objDeep == 0)return QJsonValue{};//�������Ϊ0����
	QJsonObject temp;
	if (objDeep > 1) {//Ƕ�ײ�������1ʱ
		for (int i{ 0 }; i != objDeep - 1; ++i) {
			obj = tear(info[i], obj);
		}
		return obj[info.back()];
	}
	else {
		return obj[info.front()];
	}
}