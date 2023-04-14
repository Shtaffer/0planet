#include "cgame.h"

CGame::CGame()
{

}

CGalaxy* CGame::getGalaxy()
{
    return galaxy;
}

CGalaxy* CGame::generateGalaxy(CNumber &number)
{
    if(galaxy != nullptr)
    {
        delete galaxy;
        galaxy = nullptr;
    }

    galaxy = new CGalaxy(&number);

    return galaxy;
}

QString CGame::findByID(int id) ///TODO:  сделать нормально
{
    if(id < 0)
        return "Wrong ID!";

    if(galaxy == nullptr)
        return "There is no galaxy :(";

    if(galaxy->getID() == id)
        return "Galaxy " + galaxy->getName() + " found";

    for(auto sector : *galaxy->getSectors())
    {
        if(sector->getID() == id)
            return "Sector" + sector->getName() + " found at galaxy " + galaxy->getName();

        for(auto solar : *sector->getSolarSystems())
        {
            if(solar->getID() == id)
                return "Solar system " + solar->getName() + " found at sector " + sector->getName()
                        + " galaxy " + galaxy->getName();

            for(auto planet : *solar->getPlanets())
            {
                if(planet->getID() == id)
                    return "Planet " + planet->getName() + " found at solar system " + solar->getName()
                            + " sector " + sector->getName()
                            + " galaxy " + galaxy->getName();
            }

        }
    }


    return "Not found :(";
}

QString CGame::findByName(QString name)
{
    if(name == "")
        return "Wrong name!";

    if(galaxy == nullptr)
        return "There is no galaxy :(";

    if(galaxy->getName() == name)
        return "Galaxy found";

    for(auto sector : *galaxy->getSectors())
    {
        if(sector->getName() == name)
            return "Sector found at galaxy " + galaxy->getName();

        for(auto solar : *sector->getSolarSystems())
        {
            if(solar->getName() == name)
                return "Solar system found at sector " + sector->getName()
                        + " galaxy " + galaxy->getName();

            for(auto planet : *solar->getPlanets())
            {
                if(planet->getName() == name)
                    return "Planet found at solar system " + solar->getName()
                            + " sector " + sector->getName()
                            + " galaxy " + galaxy->getName();
            }

        }
    }


    return "Not found :(";
}

QGraphicsScene* CGame::draw()
{
    if(scene != nullptr)
    {
        scene->clear();
        scene->deleteLater();
    }


    scene = new QGraphicsScene();
    //ui->graphicsView->setScene(scene);


    QBrush greenBrush(Qt::green);
    QBrush blueBrush(Qt::blue);
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(2);

    // a gradient background
    qreal r = 1000;
    QRadialGradient gradient(0, 0, r);
    gradient.setColorAt(0.0, Qt::red);
    gradient.setColorAt(0.10, Qt::darkMagenta);
    gradient.setColorAt(0.3, Qt::darkBlue);
    gradient.setColorAt(1.0, Qt::black);
    gradient.setSpread(QGradient::PadSpread);
    scene->setBackgroundBrush(gradient);


    if(galaxy != nullptr)
    {
        scene->addEllipse(-10,-10, 20,20, QPen(Qt::black), QBrush(Qt::black));

        qreal x = 30;
        int i = 0;

        int colors[] = {Qt::yellow, Qt::darkYellow, Qt::red, Qt::darkRed};

        for(auto sector : *galaxy->getSectors())
        {
            QPen pen = QPen(Qt::black);
            QBrush brush = QBrush(Qt::yellow);

            for (auto solarSystem : *sector->getSolarSystems())
            {
                scene->addEllipse(x-5,-5, 10,10, pen, brush);
                int y = 10;

                for(auto planet : *solarSystem->getPlanets())
                {
                    //QBrush brush(Qt::blue);

                    scene->addEllipse(x-2, y-2, 4,4, pen, brush);
                    y += 5;
                }

                x += 10;
            }
            x += 10;
        }
    }




    /*rectangle = scene->addRect(0, 0, 300, 300, QPen(Qt::red));

    rectangle = scene->addRect(100, 0, 80, 100, outlinePen, blueBrush);
    rectangle->setFlag(QGraphicsItem::ItemIsMovable);

    // addEllipse(x,y,w,h,pen,brush)
    ellipse = scene->addEllipse(0, -100, 300, 60, outlinePen, greenBrush);
    ellipse->setFlag(QGraphicsItem::ItemIsMovable);

    text = scene->addText("Hello world", QFont("Arial", 20) );
    text->setFlag(QGraphicsItem::ItemIsMovable);*/

    return scene;
}
