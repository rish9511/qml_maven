#include "jsonparser.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

#include "eic.h"
#include "elmavenmodel.h"

JsonParser::JsonParser(ElMavenModel* model):
    jsonDoc(nullptr),
    model(model)
{
    jsonDoc = new QJsonDocument;
}

void JsonParser::loadJsonDoc(const QString& jsonFile)
{
    QFile fStream(jsonFile);
    if(fStream.open(QIODevice::ReadOnly)) {
        *jsonDoc = QJsonDocument::fromJson(fStream.readAll());
    }

    if(jsonDoc->isNull()) {
        qDebug() << "not a valid document";
        return;
    }

    parse(jsonDoc);
}

void JsonParser::parse(QJsonDocument* doc)
{
    QJsonObject jsonObj = doc->object();
    QJsonArray jArr = jsonObj.value("groups").toArray();
    for(auto it=jArr.begin(); it!=jArr.end(); it++) {
        QJsonObject childObject = QJsonValue(*it).toObject();
        for(const QString& key: childObject.keys()) {
            if(key == "peaks") {
                parsePeaks(childObject.value("peaks"));
            }
        }
    }

}


void JsonParser::parsePeaks(const QJsonValue& value)
{
    QJsonArray jArr = value.toArray();
    for(auto it=jArr.begin(); it!=jArr.end(); it++) {
        QJsonObject childObject = QJsonValue(*it).toObject();
        EIC* eic = new EIC;
        for(const QString& key: childObject.keys()) {
            if(key ==  "eic") {
                parseEic(childObject.value("eic"), eic);
            }
        }
        model->addEic(eic);
    }
}

void JsonParser::parseEic(const QJsonValue& value, EIC* eic)
{
    QJsonObject jObj = value.toObject();
    for(auto it=jObj.begin(); it!=jObj.end(); it++) {
        QJsonArray jArr = it.value().toArray();
        for(auto it2=jArr.begin(); it2!=jArr.end(); it2++) {
           if(it.key() == "rt")
               eic->addRt(QJsonValue(*it2).toDouble());
           if(it.key() == "intensity")
               eic->addIntensity(QJsonValue(*it2).toDouble());
       }
    }
}
