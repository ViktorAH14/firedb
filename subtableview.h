#ifndef SUBTABLEVIEW_H
#define SUBTABLEVIEW_H

#include <QDialog>

namespace Ui {
class SubTableView;
}

class QSqlTableModel;

class SubTableView : public QDialog
{
    Q_OBJECT

public:
    explicit SubTableView(const QString &tableName, const QString &columnName, QWidget *parent = 0);
    ~SubTableView();

signals:
    void modelChanged();

private slots:
    void addRow();
    void saveRecord();
    void deleteRecord();

private:
    Ui::SubTableView *ui;

    QSqlTableModel *m_model;
    QString m_tableName;
    QString m_columnName;

    void createModel();
    void setupView();
};

#endif // SUBTABLEVIEW_H
