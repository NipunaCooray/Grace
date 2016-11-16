#ifndef SLAVERUNFORM_H
#define SLAVERUNFORM_H

#include <QDialog>

namespace Ui {
class SlaveRunForm;
}

class SlaveRunForm : public QDialog
{
    Q_OBJECT

public:
    explicit SlaveRunForm(QWidget *parent = 0);
    ~SlaveRunForm();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::SlaveRunForm *ui;
};

#endif // SLAVERUNFORM_H
