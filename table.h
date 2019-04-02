#ifndef TABLE_H
#define TABLE_H

#include <QObject>
#include <QString>
#include <QVariant>
#include <QWidget>

class QSqlRelationalTableModel;
class QSqlDatabase;
class QStringList;

class Table : public QObject
{
    Q_OBJECT
public:
    Table(QSqlDatabase *db, const QString &TableName);
    ~Table();

    bool openTable();
    int rowsCount();
    int lastRow();
    int columnIndex(const QString &column);
    bool setTableValue(int row, const QString &FieldName, const QVariant &value);
    bool setTableValue(int row, int column, const QVariant &value);
    QVariant getTableValue(int row, const QString &FieldName);
    QVariant getTableValue(int row, int column);
    void setTableColumnName(int index, const QString &name);
    void renameColumn(const QString &OldName, const QString &NewName);
    bool save();
    bool newRow();
    void deleteRow(int row);
    QString getColumnName(int column);
    void addRelation(int column, const QString &ExtTable, const QString &ExtKey, const QString &ExtDisplay);
    void addRelation(const QString &column, const QString &ExtTable, const QString &ExtKey, const QString &ExtDisplay);
    void canselChanges();
    bool selectRows(const QString &where);

protected:
    friend class TableIOMapper;

    QSqlRelationalTableModel *m_model;
    QStringList *names;
};

#endif // TABLE_H
