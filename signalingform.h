#ifndef SIGNALINGFORM_H
#define SIGNALINGFORM_H

#include <QDialog>

namespace Ui {
class SignalingForm;
}

class SignalingForm : public QDialog
{
    Q_OBJECT

public:
    explicit SignalingForm(QWidget *parent = 0);
    ~SignalingForm();

private:
    Ui::SignalingForm *ui;
};

#endif // SIGNALINGFORM_H
