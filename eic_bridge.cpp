#include "eic_bridge.h"
#include "elmavenmodel.h"
#include "eic.h"
#include <vector>

#include <QVector>
#include <QDebug>
#include <QString>

EICBridge::EICBridge(QObject *parent, ElMavenModel* model) :
    QObject(parent),
    model(model)
{
    const std::vector<EIC*> eics = model->getEics();
    for(EIC* e: eics) {
       for(const float& f: e->getRts()) {
           qDebug() << f;
           rts.push_back(QString::number(f));
       }

       for(const float& f: e->getIntensities()) {
           qDebug() << f;
           intensities.push_back(QString::number(f));
       }
    }
}
