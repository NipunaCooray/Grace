#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "edgedetect.h"
#include "serialreadwrite.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_loadStyle_clicked();



    void on_btn_close_clicked();

private:
    Ui::MainWindow *ui;



};

#endif // MAINWINDOW_H
