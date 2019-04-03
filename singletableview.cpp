#include "singletableview.h"
#include "ui_tableview.h"

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

void SingleTableView::addRow()
{
}

void SingleTableView::save()
{
}

void SingleTableView::deleteRow()
{
}
