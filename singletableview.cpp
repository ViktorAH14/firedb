#include "singletableview.h"
#include "ui_tableview.h"
#include "tableiomapper.h"

SingleTableView::SingleTableView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TableView)
{
    ui->setupUi(this);
}

SingleTableView::~SingleTableView()
{
    delete ui;
}

void SingleTableView::setMapper(TableIOMapper *mapper)
{
    this->mapper = mapper;
    mapper->setView(ui->tableView);
//    mapper->setColumnName(0, windowTitle());
    ui->tableView->resizeColumnsToContents();
//    ui->tableView->hideColumn(0);
}

void SingleTableView::addRow()
{
    if (!mapper.isNull()) {
        mapper->newRow();
        mapper->selectLastRow();
    }
}

void SingleTableView::save()
{
    if (!mapper.isNull()) {
        mapper->save();
    }
}

void SingleTableView::deleteRow()
{
    if (!mapper.isNull()) {
        mapper->deleteRow(ui->tableView->currentIndex().row());
    }
}
