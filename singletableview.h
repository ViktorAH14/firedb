#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QDialog>

namespace Ui {
class TableView;
}

class SingleTableView : public QDialog
{
    Q_OBJECT

public:
    explicit SingleTableView(QWidget *parent = 0);
    ~SingleTableView();

private slots:
    void addRow();
    void save();
    void deleteRow();

private:
    Ui::TableView *ui;
};

#endif // TABLEVIEW_H
