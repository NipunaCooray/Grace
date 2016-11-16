#ifndef SETUPFORM_H
#define SETUPFORM_H

#include <QDialog>
#include "keyboard.h"

namespace Ui {
class SetupForm;
}

class SetupForm : public QDialog
{
    Q_OBJECT

public:
    explicit SetupForm(QWidget *parent = 0);
    ~SetupForm();

private slots:
    void on_pushButton_back_clicked();

    void on_pushButton_save_clicked();

    void run_keyboard_lineEdit();

private:
    Ui::SetupForm *ui;
    Keyboard *lineEditkeyboard;
};

#endif // SETUPFORM_H
