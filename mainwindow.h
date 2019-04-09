#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class SingleTableView;


namespace Ui {
class MainWindow;
}

class QSqlTableModel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void newDB();
    void openDB();
    void sortData();

    void showSignalingForm();
    void showFalseDepForm();
    void showAssistingForm();
    void showFireSafetyForm();
    void showOwerForm();
    void showTrainingForm();
    void showUnuccountingFireForm();

    void showAccidentAlertTable();
    void showBarrelTypeTable();
    void showCauseFireTable();
    void showDepTypeTable();
    void showDistrictsTable();
    void showExistingASFTable();
    void showFireResistanceTable();
    void showHeatingTypeTable();
    void showOwnTypeTable();
    void showSecondDamagedFactorsTable();
    void showSourceInfTable();
    void showRatingTable();
    void showTrainingTypeTable();
    void showTypeASRTable();
    void showTypeInstrumentTable();
    void showTypeObjectTable();
    void showTypeUnuccountingFireTable();
    void showTypeTrafficAccidentTable();
    void showVehicleTypeTable();
    void showVentilationTypeTable();

    void updateModel();

private:
    Ui::MainWindow *ui;

    bool connectDB(const QString &dbName);
    bool createDB(const QString &dbName);
    void createModel();
    void setupView();

    QString dbName;
    QSqlTableModel *m_model;
};

#endif // MAINWINDOW_H
