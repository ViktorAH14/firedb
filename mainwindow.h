#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class SingleTableView;


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

    QString dbName;

    SingleTableView *signalingTableView;

    SingleTableView *departuresTypeView;

};

#endif // MAINWINDOW_H
