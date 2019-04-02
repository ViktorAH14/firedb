#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QDialog>
//#include <QPointer>

namespace Ui {
class TableView;
}

class TableIOMapper;

typedef QPointer<TableIOMapper> MapperPtr;

class SingleTableView : public QDialog
{
    Q_OBJECT

public:
    explicit SingleTableView(QWidget *parent = 0);
    ~SingleTableView();

    void setMapper(TableIOMapper *mapper);

private slots:
    void addRow();
    void save();
    void deleteRow();

private:
    Ui::TableView *ui;
    MapperPtr mapper;
};

#endif // TABLEVIEW_H
