#ifndef EICBRIDGE_H
#define EICBRIDGE_H

#include <QObject>
#include <QList>

class ElMavenModel;

class EICBridge : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QString> intensities MEMBER intensities)
    Q_PROPERTY(QList<QString> rts MEMBER rts)
    public:
        EICBridge() {}
        EICBridge(QObject* parent, ElMavenModel*  model);

        QList<QString> intensities;
        QList<QString> rts;

    private:
        ElMavenModel* model;

    signals:

    public slots:
};

#endif // EICBRIDGE_H
