#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainModel;

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

private:
    Ui::MainWindow *ui;

    bool connectDB(const QString &dbName);
    bool createDB(const QString &dbName);
    void createModel();
    void setupView();

    QString dbName;
    MainModel *mainmodel;

};

#endif // MAINWINDOW_H
