#ifndef TRAININGFORM_H
#define TRAININGFORM_H

#include <QDialog>

namespace Ui {
class TrainingForm;
}

class QSqlRelationalTableModel;
class QDataWidgetMapper;

class TrainingForm : public QDialog
{
    Q_OBJECT

public:
    explicit TrainingForm(QWidget *parent = 0);
    ~TrainingForm();

signals:
    void modelChanged();

private slots:
    void addTrainingDeparture();
    void resizeLineEditAddress();

private:
    Ui::TrainingForm *ui;

    QSqlRelationalTableModel *m_model;
    QDataWidgetMapper *m_mapper;

    void createModel();
};

#endif // TRAININGFORM_H
