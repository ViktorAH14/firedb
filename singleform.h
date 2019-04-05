#ifndef SINGLEFORM_H
#define SINGLEFORM_H

#include <QDialog>

namespace Ui {
class SingleForm;
}

class QSqlTableModel;

class SingleForm : public QDialog
{
    Q_OBJECT

public:
    explicit SingleForm(const QString &tableName, const QString &columnName, QWidget *parent = 0);
    ~SingleForm();

signals:
    void modelChanged();

private slots:
    void addRow();
    void saveRecord();
    void deleteRecord();

private:
    Ui::SingleForm *ui;

    QSqlTableModel *m_model;
    QString m_tableName;
    QString m_columnName;

    void createModel();
    void setupView();
};

#endif // SINGLEFORM_H
