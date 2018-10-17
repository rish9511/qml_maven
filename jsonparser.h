#ifndef JSONPARSER_H
#define JSONPARSER_H
#include <QString>
#include <QJsonValue>
class QFile;
class QJsonDocument;

class EIC;
class ElMavenModel;

class JsonParser
{
    public:
        JsonParser(ElMavenModel* model);
        void loadJsonDoc(const QString&);
        void parse(QJsonDocument* doc);
        void parsePeaks(const QJsonValue&);
        void parseEic(const QJsonValue&, EIC* eic);
    private:
        QJsonDocument* jsonDoc;
        ElMavenModel* model;
};

#endif // JSONPARSER_H
