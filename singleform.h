#ifndef SINGLEFORM_H
#define SINGLEFORM_H

#include <QDialog>

namespace Ui {
class SingleForm;
}

class QSqlRelationalTableModel;
class QDataWidgetMapper;

class SingleForm : public QDialog
{
    Q_OBJECT

public:
    explicit SingleForm(const QString &depType, QWidget *parent = 0);
    ~SingleForm();

signals:
    void modelChanged();

private slots:
    void addSignalingDeparture();

private:
    Ui::SingleForm *ui;

    QSqlRelationalTableModel *m_model;
    QDataWidgetMapper *m_mapper;
    QString m_depType;

    void createModel();

};

#endif // SINGLEFORM_H
