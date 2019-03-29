#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>

class QSqlQuery;

class DBCreator : public QObject
{
    Q_OBJECT
public:
    explicit DBCreator(QObject *parent = 0);
    ~DBCreator();

signals:

public slots:
    bool newDeparturesDB();

private:
    bool createDeparturesDB();
    bool checkExec(QSqlQuery query);
    bool createDeparturesTypeTable(QSqlQuery query);
    bool createAssitingTable(QSqlQuery query);
    bool createFireSafetyTable(QSqlQuery query);
    bool createOwerTable(QSqlQuery query);
    bool createTrainingTypeTable(QSqlQuery query);
    bool createTrainingTable(QSqlQuery query);
    bool createFalseDepartureTable(QSqlQuery query);
    bool createTypeUnuccountingFireTable(QSqlQuery query);
    bool createUnuccountingFireTable(QSqlQuery query);
    bool createSignalingTable(QSqlQuery query);
    bool createDistrictsTable(QSqlQuery query);
    bool createFireResistanceTable(QSqlQuery query);
    bool createCauseFireTable(QSqlQuery query);
    bool createTypeObjectTable(QSqlQuery query);
    bool createOwnTypeTable(QSqlQuery query);
    bool createVentilationTypeTable(QSqlQuery query);
    bool createHeatingTypeTable(QSqlQuery query);
    bool createFireTable(QSqlQuery query);
    bool createVictimsFireTable(QSqlQuery query);
    bool createDeadFireTable(QSqlQuery query);
    bool createRatingTable(QSqlQuery query);
    bool createFireExtinguisherTable(QSqlQuery query);
    bool createInternalWaterSupplyTable(QSqlQuery query);
    bool createHydrantTable(QSqlQuery query);
    bool createFirePondTable(QSqlQuery query);
    bool createNaturalFireReservoirTable(QSqlQuery query);
    bool createStateFireServiceTable(QSqlQuery query);
    bool createDepartmentalFireBrigadeTable(QSqlQuery query);
    bool createVoluntaryFireBrigadeTable(QSqlQuery query);
    bool createLocalFireBrigadeTable(QSqlQuery query);
    bool createPrivateFireBrigadeTable(QSqlQuery query);
    bool createPopulationOrganizationTable(QSqlQuery query);
    bool createOperationalHeadquartersTable(QSqlQuery query);
    bool createFireDestroyedTable(QSqlQuery query);
    bool createFireDamagedTable(QSqlQuery query);
    bool createSavedTable(QSqlQuery query);
    bool createBarrelTypeTable(QSqlQuery query);
    bool createBarrelsTable(QSqlQuery query);
    bool createGDZSTable(QSqlQuery query);
    bool createFireAutomaticsTable(QSqlQuery query);
    bool createOperationalDocTable(QSqlQuery query);
    bool createInvestigativeTeamTable(QSqlQuery query);
    bool createTypeTrafficAccidentTable(QSqlQuery query);
    bool createAccidentAlertTable(QSqlQuery query);
    bool createSourceInfTable(QSqlQuery query);
    bool createSecondDamagedFactorsTable(QSqlQuery query);
    bool createTrafficAccidentTable(QSqlQuery query);
    bool createVehicleTypeTable(QSqlQuery query);
    bool createVehiclesTable(QSqlQuery query);
    bool createVictimsAccidentTable(QSqlQuery query);
    bool createDeadAccidentTable(QSqlQuery query);
    bool createTypeASRTable(QSqlQuery query);
    bool createASRTable(QSqlQuery query);
    bool createExistingASFTable(QSqlQuery query);
    bool createASFTable(QSqlQuery query);
    bool createTypeInstrumentTable(QSqlQuery query);
    bool createInstrumentTable(QSqlQuery query);

    QSqlDatabase db;
};

#endif // DATABASE_H
