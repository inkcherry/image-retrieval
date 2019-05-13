#include "stlloader.h"

#include <QUrl>
#include <Qt3DExtras/QPhongMaterial>
#include <Qt3DRender/QMesh>
stlloader::stlloader(Qt3DCore::QEntity *&rootEntity, Qt3DExtras::Qt3DWindow*&view,QString& path)  : m_rootEntity(rootEntity)
{
   this->path=path;
   this->view=view;
//   this->rootEntity = rootEntity;
}

stlloader::~stlloader()
{
}


//这个loadstl不显示是不会加载，显示的时候show（）调用loadstl
void stlloader::LoadSTL()
{
//    QUrl data = QUrl::fromLocalFile("C:/Users/Dimitrios/MyQtapps/STLloader/block1.stl");
    QUrl data = QUrl::fromLocalFile(path);
    Qt3DRender::QMesh *partMesh = new Qt3DRender::QMesh;
    partMesh->setSource(data);

    Qt3DCore::QTransform *partTransform = new Qt3DCore::QTransform();

    Qt3DExtras::QPhongMaterial *partMaterial = new Qt3DExtras::QPhongMaterial();
    partMaterial->setDiffuse(QColor(0, 200, 255));

    //part (STL model)
    m_partEntity = new Qt3DCore::QEntity(m_rootEntity);
    m_partEntity->addComponent(partMesh);
    m_partEntity->addComponent(partMaterial);
    m_partEntity->addComponent(partTransform);
}

void stlloader::show()
{




//    Qt3DExtras::Qt3DWindow *view= new Qt3DExtras::Qt3DWindow();
//    Qt3DCore::QEntity *rootEntity = new Qt3DCore::QEntity;

    Qt3DRender::QCamera *camera = view->camera();
    camera->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 1000.0f);
    camera->setPosition(QVector3D(0, 0, 320.0f));
    camera->setViewCenter(QVector3D(0, 0, 0));

    Qt3DExtras::QOrbitCameraController *camController = new Qt3DExtras::QOrbitCameraController(m_rootEntity);
    camController->setCamera(camera);

    Qt3DCore::QEntity *lightEntity = new Qt3DCore::QEntity(m_rootEntity);
    Qt3DRender::QPointLight *light = new Qt3DRender::QPointLight(lightEntity);
    light->setColor("white");
    light->setIntensity(1);
    lightEntity->addComponent(light);


    view->setRootEntity(m_rootEntity);
    QString tit=tr("医学三维影像查看器刘铭志");

    view->setTitle(tit);
    QIcon *ic=new QIcon(":/src/3dtit.png");
    view->setIcon(*ic);
    view->show();
}
