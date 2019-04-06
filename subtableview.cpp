#include "subtableview.h"
#include "ui_subtableview.h"

#include <QSqlTableModel>
#include <QMessageBox>

SubTableView::SubTableView(const QString &tableName, const QString &columnName, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SubTableView)
{
    ui->setupUi(this);
    m_tableName = tableName;
    m_columnName = columnName;
    createModel();
    setupView();
}

SubTableView::~SubTableView()
{
    delete ui;
}

void SubTableView::addRow()
{
    m_model->insertRow(m_model->rowCount(QModelIndex()));
    ui->tableView->setFocus();
    ui->tableView->setCurrentIndex(QModelIndex(m_model->index(m_model->rowCount() - 1, 1)));
}

void SubTableView::saveRecord()
{
    if (!m_model->submitAll()) {
        QMessageBox::critical(this, trUtf8("Critical"), trUtf8("Unable to save record"));
    } else {
        emit modelChanged();
        ui->tableView->setFocus();
        ui->tableView->setCurrentIndex(QModelIndex(m_model->index(m_model->rowCount() - 1, 1)));
    }
}

void SubTableView::deleteRecord()
{
    int row = ui->tableView->currentIndex().row();
    m_model->removeRow(row);
}

void SubTableView::createModel()
{
    m_model = new QSqlTableModel(this);
    m_model->setTable(m_tableName);
    m_model->setHeaderData(1, Qt::Horizontal, m_columnName);
    m_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    m_model->select();
}

void SubTableView::setupView()
{
    ui->tableView->setModel(m_model);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->hideColumn(0);
}
