#include <QApplication>
#include <QQmlApplicationEngine>

#include "eic_bridge.h"
#include "jsonparser.h"
#include "elmavenmodel.h"

#include <iostream>

ElMavenModel elMavModel;

void init()
{
    // json parser
    static JsonParser parserObj(&elMavModel);
    parserObj.loadJsonDoc(QString("/home/grishabh/maven_repo/eic_data.json"));

    static EICBridge eicBridge(nullptr,&elMavModel);
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qmlRegisterType<EICBridge>("elmaven.core.eic", 1, 0, "EIC");

    init();

    std::cout << "size of eics : " << elMavModel.getEics().size() << std::endl;

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
