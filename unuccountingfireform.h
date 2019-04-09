#ifndef UNUCCOUNTINGFIREFORM_H
#define UNUCCOUNTINGFIREFORM_H

#include <QDialog>

namespace Ui {
class UnuccountingFireForm;
}

class QSqlRelationalTableModel;
class QDataWidgetMapper;

class UnuccountingFireForm : public QDialog // TODO Rename unuccounting->unaccounting
{
    Q_OBJECT

public:
    explicit UnuccountingFireForm(QWidget *parent = 0);
    ~UnuccountingFireForm();

signals:
    void modelChanged();

private slots:
    void addUnuccountingFireDeparture();
    void resizeLineEditAddress();

private:
    Ui::UnuccountingFireForm *ui;

    QSqlRelationalTableModel *m_model;
    QDataWidgetMapper *m_mapper;

    void createModel();
};

#endif // UNUCCOUNTINGFIREFORM_H
