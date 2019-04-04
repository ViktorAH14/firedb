#ifndef SIGNALINGFORM_H
#define SIGNALINGFORM_H

#include <QDialog>

namespace Ui {
class SignalingForm;
}

class QSqlRelationalTableModel;
class QDataWidgetMapper;

class SignalingForm : public QDialog
{
    Q_OBJECT

public:
    explicit SignalingForm(QWidget *parent = 0);
    ~SignalingForm();

private slots:
    void addSignalingDeparture();

private:
    Ui::SignalingForm *ui;

    QSqlRelationalTableModel *m_model;
    QDataWidgetMapper *m_mapper;

    void createModel();

};

#endif // SIGNALINGFORM_H
