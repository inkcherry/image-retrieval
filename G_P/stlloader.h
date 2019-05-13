#ifndef STLLOADER_H
#define STLLOADER_H


#include <QtCore/QObject>
#include <QObject>
#include <Qt3DCore/qentity.h>
#include <Qt3DCore/qtransform.h>
#include <QApplication>
#include <Qt3DExtras/Qt3DWindow>
#include <Qt3DRender/QCamera>
#include <Qt3DRender/QPointLight>
#include <Qt3DExtras/QOrbitCameraController>
#include <QIcon>
//该类维护一个3d模型对象，并提供常规接口
class stlloader : public QObject
{
    Q_OBJECT
public:
    QString path;
    explicit stlloader(Qt3DCore::QEntity *&rootEntity, Qt3DExtras::Qt3DWindow*&view,QString& path);
    Qt3DExtras::Qt3DWindow *view;
    ~stlloader();


signals:

public slots:
    void LoadSTL();
    void show();

private:
    Qt3DCore::QEntity *m_rootEntity;
    Qt3DCore::QEntity *m_partEntity;
};

#endif // STLLOADER_H
