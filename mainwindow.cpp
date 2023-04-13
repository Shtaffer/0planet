#include "mainwindow.h"
#include "ui_mainwindow.h"


QVector<QRgb> owners{
                        qRgb(128,128,128),
                        qRgb(0,128,64),
                        qRgb(255,0,0),
                        qRgb(0,64,128)
                      };

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_Generate_clicked()
{
    double value = ui->doubleSpinBox->value();

    CNumber number(value);

    game.generateGalaxy(number);

    ui->listWidget_CGalaxy->clear();
    ui->listWidget_CSector->clear();
    ui->listWidget_CSolarSystem->clear();
    ui->listWidget_CPlanet->clear();
    ui->listWidget_Info->clear();
    ui->listWidget_CGalaxy->addItem("Galaxy " + game.getGalaxy()->getName());
}


void MainWindow::on_listWidget_CGalaxy_itemClicked(QListWidgetItem *item)
{
    ui->listWidget_CSector->clear();

    for(auto sector : *game.getGalaxy()->getSectors())
    {
        ui->listWidget_CSector->addItem("Sector " + sector->getName());
    }
}


void MainWindow::on_listWidget_CSector_itemClicked(QListWidgetItem *item)
{
    ui->listWidget_CSolarSystem->clear();
    ui->listWidget_CPlanet->clear();
    ui->listWidget_Info->clear();

    int index = ui->listWidget_CSector->currentRow();

    if(index < 0)
        return;

    CSector * sector = game.getGalaxy()->getSectors()->at(index);

    for(auto solarSystem : *sector->getSolarSystems())
    {
        ui->listWidget_CSolarSystem->addItem("Solar system " + solarSystem->getName());
    }
}


void MainWindow::on_listWidget_CSolarSystem_itemClicked(QListWidgetItem *item)
{
    ui->listWidget_CPlanet->clear();
    ui->listWidget_Info->clear();

    int index = ui->listWidget_CSector->currentRow();
    if(index < 0)
        return;

    CSector * sector = game.getGalaxy()->getSectors()->at(index);

    index = ui->listWidget_CSolarSystem->currentRow();
    if(index < 0)
        return;

    CSolarSystem * solarSystem = sector->getSolarSystems()->at(index);

    for(auto planet : *solarSystem->getPlanets())
    {
        QListWidgetItem *item = new QListWidgetItem("Planet " + planet->getName());
        //qDebug() << planet->getOwner() << owners[planet->getOwner()];
        item->setTextColor(owners[planet->getOwner()]);
        ui->listWidget_CPlanet->addItem(item);

        //ui->listWidget_CPlanet->addItem(planet->getName());
        //ui->listWidget_CPlanet->currentItem()->setBackgroundColor(QColor::fromRgb(0,128,64));

    }

}


void MainWindow::on_listWidget_CPlanet_itemClicked(QListWidgetItem *item)
{
    ui->listWidget_Info->clear();

    int index = ui->listWidget_CSector->currentRow();
    if(index < 0)
        return;

    CSector * sector = game.getGalaxy()->getSectors()->at(index);

    index = ui->listWidget_CSolarSystem->currentRow();
    if(index < 0)
        return;

    CSolarSystem * solarSystem = sector->getSolarSystems()->at(index);

    index = ui->listWidget_CPlanet->currentRow();
    if(index < 0)
        return;

    CPlanet * planet = solarSystem->getPlanets()->at(index);

    auto info = planet->getInfo();
    QString tmp = "";

    auto i = info.constBegin();
    while( i != info.constEnd())
    {
        tmp = i.key() + " : " + i.value().toString();
        ui->listWidget_Info->addItem(tmp);
        ++i;
    }


}


void MainWindow::on_pushButton_findByName_clicked()
{
    QString name = ui->lineEdit_find->text();
    ui->label_find->setText(game.findByName(name));
}

void MainWindow::on_pushButton_findByID_clicked()
{
    int id = ui->spinBox_find->value();
    ui->label_find->setText(game.findByID(id));
}


void MainWindow::on_pushButton_draw_clicked()
{
    ui->graphicsView->setScene(game.draw());

}


void MainWindow::on_pushButton_items_clicked()
{

}

