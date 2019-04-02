#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPointer>

class Table;
class TableIOMapper;
class SingleTableView;

typedef QPointer<Table> TablePtr;
typedef QPointer<TableIOMapper> TableMapperPtr;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void newDB();
    void openDB();
    void editSignalingTable();
    void editDeparturesTypeTable();
    void showSignalingForm();

private:
    Ui::MainWindow *ui;

    bool connectDB(const QString &dbName);
    bool createDB(const QString &dbName);
    void createModel();
    void setupView();
    void deleteModel();

    QString dbName;

    TablePtr mainTable;
    TableMapperPtr mainMapper;

    TablePtr signalingTable;
    TableMapperPtr signalingMapper;
    SingleTableView *signalingTableView;

    TablePtr departuresTypeTable;
    TableMapperPtr departuresTypeMapper;
    SingleTableView *departuresTypeView;

};

#endif // MAINWINDOW_H
