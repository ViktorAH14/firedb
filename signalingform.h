#ifndef SIGNALINGFORM_H
#define SIGNALINGFORM_H

#include <QDialog>

namespace Ui {
class SignalingForm;
}

class TableIOMapper;

typedef QPointer<TableIOMapper> MapperPtr;

class SignalingForm : public QDialog
{
    Q_OBJECT

public:
    explicit SignalingForm(QWidget *parent = 0);
    ~SignalingForm();

    void setMapper(TableIOMapper *mapper);

private:
    Ui::SignalingForm *ui;
    MapperPtr mapper;
};

#endif // SIGNALINGFORM_H
