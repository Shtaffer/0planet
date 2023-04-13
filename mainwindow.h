#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>

#include "cgame.h"
//#include "generators/CNumber.h"
//#include "generators/CName.h"
//#include "cgalaxy.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Generate_clicked();

    void on_listWidget_CGalaxy_itemClicked(QListWidgetItem *item);

    void on_listWidget_CSector_itemClicked(QListWidgetItem *item);

    void on_listWidget_CSolarSystem_itemClicked(QListWidgetItem *item);

    void on_listWidget_CPlanet_itemClicked(QListWidgetItem *item);

    void on_pushButton_findByName_clicked();

    void on_pushButton_findByID_clicked();

    void on_pushButton_draw_clicked();

    void on_pushButton_items_clicked();

private:
    Ui::MainWindow *ui;
    CGame game;

};
#endif // MAINWINDOW_H
