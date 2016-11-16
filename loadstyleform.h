#ifndef LOADSTYLEFORM_H
#define LOADSTYLEFORM_H

#include <QDialog>

namespace Ui {
class LoadStyleForm;
}

class LoadStyleForm : public QDialog
{
    Q_OBJECT

public:
    explicit LoadStyleForm(QWidget *parent = 0);
    ~LoadStyleForm();

private slots:
    void on_pushButton_cancel_clicked();

    void on_pushButton_loadStyle_clicked();

private:
    Ui::LoadStyleForm *ui;
};

#endif // LOADSTYLEFORM_H
