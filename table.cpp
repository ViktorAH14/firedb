#include "table.h"

#include <QSqlRelationalTableModel>
#include <QSqlDatabase>
#include <QSqlRelationalDelegate>
#include <QStringList>
#include <QSqlRelation>
#include <QStyleOption>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>

Table::Table(QSqlDatabase *db, const QString &TableName)
{
    m_model = new QSqlRelationalTableModel(0);
    m_model->setTable(TableName);
    names = new QStringList;
}

Table::~Table()
{
    delete m_model;
    delete names;
}

bool Table::openTable()
{
    m_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    if (!m_model->select())
        return false;
    names->clear();
    for (int i = 0; i < m_model->columnCount(); i++)
        names->append(m_model->headerData(i, Qt::Horizontal).toString());
    return true;
}

int Table::rowsCount()
{
    return m_model->rowCount();
}

int Table::lastRow()
{
    return m_model->rowCount();
}

int Table::columnIndex(const QString &column)
{
    return m_model->fieldIndex(column);
}

bool Table::setTableValue(int row, const QString &FieldName, const QVariant &value)
{
    return setTableValue(row, m_model->fieldIndex(FieldName), value);
}

bool Table::setTableValue(int row, int column, const QVariant &value)
{
    return m_model->setData(m_model->index(row, column), value);
}

QVariant Table::getTableValue(int row, const QString &FieldName)
{
    return getTableValue(row, m_model->fieldIndex(FieldName));
}

QVariant Table::getTableValue(int row, int column)
{
    return m_model->data(m_model->index(row, column));
}

void Table::setTableColumnName(int index, const QString &name)
{
    m_model->setHeaderData(index, Qt::Horizontal, name);
}

void Table::renameColumn(const QString &OldName, const QString &NewName)
{
    this->setTableColumnName(names->indexOf(OldName), NewName);
}

bool Table::save()
{
    if (!m_model->submitAll()) {
        QMessageBox::critical(0, trUtf8("Error"), m_model->lastError().text());//NOTE check
        return false;
    }

    return true;
}

bool Table::newRow()
{
    m_model->submitAll();
    m_model->setFilter("");
    m_model->select();
    if (!m_model->insertRow(lastRow())) {
        return false;
    }

    return true;
}

void Table::deleteRow(int row)
{
    if (!m_model->removeRow(row)) {
        QMessageBox::critical(0, trUtf8("Error"), m_model->lastError().text());
    }
}

QString Table::getColumnName(int column)
{
    return names->value(column);
}

void Table::addRelation(int column, const QString &ExtTable, const QString &ExtKey, const QString &ExtDisplay)
{
    QSqlRelation rel(ExtTable, ExtKey, ExtDisplay);
    m_model->setRelation(column, rel);
}

void Table::addRelation(const QString &column, const QString &ExtTable, const QString &ExtKey, const QString &ExtDisplay)
{
    addRelation(this->columnIndex(column), ExtTable, ExtKey, ExtDisplay);
}

void Table::canselChanges()
{
    m_model->revertAll();
}

bool Table::selectRows(const QString &where)
{
    m_model->setFilter(where);
    m_model->select();
    return (m_model->rowCount() > 0);
}
