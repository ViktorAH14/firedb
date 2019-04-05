#include "singleform.h"
#include "ui_singleform.h"

#include <QSqlTableModel>
#include <QMessageBox>

SingleForm::SingleForm(const QString &tableName, const QString &columnName, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SingleForm)
{
    ui->setupUi(this);
    m_tableName = tableName;
    m_columnName = columnName;
    createModel();
    setupView();
}

SingleForm::~SingleForm()
{
    delete ui;
}

void SingleForm::addRow()
{
    m_model->insertRow(m_model->rowCount(QModelIndex()));
    ui->tableView->setFocus();
    ui->tableView->setCurrentIndex(QModelIndex(m_model->index(m_model->rowCount() - 1, 1)));
}

void SingleForm::saveRecord()
{
    if (!m_model->submitAll()) {
        QMessageBox::critical(this, trUtf8("Critical"), trUtf8("Unable to save record"));
    } else {
        emit modelChanged();
        ui->tableView->setFocus();
        ui->tableView->setCurrentIndex(QModelIndex(m_model->index(m_model->rowCount() - 1, 1)));
    }
}

void SingleForm::deleteRecord()
{
    int row = ui->tableView->currentIndex().row();
    m_model->removeRow(row);
}

void SingleForm::createModel()
{
    m_model = new QSqlTableModel(this);
    m_model->setTable(m_tableName);
    m_model->setHeaderData(1, Qt::Horizontal, m_columnName);
    m_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    m_model->select();
}

void SingleForm::setupView()
{
    ui->tableView->setModel(m_model);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->hideColumn(0);
}
