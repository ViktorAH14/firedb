#include "dbcreator.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

DBCreator::DBCreator(QObject *parent) : QObject(parent)
{

}

DBCreator::~DBCreator()
{

}

bool DBCreator::newDeparturesDB()
{
    if (!createDeparturesDB()) {
        return false;
    }

    return true;
}

bool DBCreator::createDeparturesDB()
{
    QSqlQuery query;
    query.prepare("PRAGMA foreign_keys = ON;");
    checkExec(query);
    createDeparturesTypeTable(query);
    createAssitingTable(query);
    createFireSafetyTable(query);
    createOwerTable(query);
    createTrainingTypeTable(query);
    createTrainingTable(query);
    createFalseDepartureTable(query);
    createTypeUnuccountingFireTable(query);
    createUnuccountingFireTable(query);
    createSignalingTable(query);
    createDistrictsTable(query);
    createFireResistanceTable(query);
    createCauseFireTable(query);
    createTypeObjectTable(query);
    createOwnTypeTable(query);
    createVentilationTypeTable(query);
    createHeatingTypeTable(query);
    createFireTable(query);
    createVictimsFireTable(query);
    createDeadFireTable(query);
    createRatingTable(query);
    createFireExtinguisherTable(query);
    createInternalWaterSupplyTable(query);
    createHydrantTable(query);
    createFirePondTable(query);
    createNaturalFireReservoirTable(query);
    createStateFireServiceTable(query);
    createDepartmentalFireBrigadeTable(query);
    createVoluntaryFireBrigadeTable(query);
    createLocalFireBrigadeTable(query);
    createPrivateFireBrigadeTable(query);
    createPopulationOrganizationTable(query);
    createOperationalHeadquartersTable(query);
    createFireDestroyedTable(query);
    createFireDamagedTable(query);
    createSavedTable(query);
    createBarrelTypeTable(query);
    createBarrelsTable(query);
    createGDZSTable(query);
    createFireAutomaticsTable(query);
    createOperationalDocTable(query);
    createInvestigativeTeamTable(query);
    createTypeTrafficAccidentTable(query);
    createAccidentAlertTable(query);
    createSourceInfTable(query);
    createSecondDamagedFactorsTable(query);
    createTrafficAccidentTable(query);
    createVehicleTypeTable(query);
    createVehiclesTable(query);
    createVictimsAccidentTable(query);
    createDeadAccidentTable(query);
    createTypeASRTable(query);
    createASRTable(query);
    createExistingASFTable(query);
    createASFTable(query);
    createTypeInstrumentTable(query);
    createInstrumentTable(query);
    createMainView(query);

    return true;
}

bool DBCreator::checkExec(QSqlQuery query)
{
    if (!query.exec()) {
        qDebug() << "Error " << query.lastError().text();
        return false;
    }
    return true;
}

bool DBCreator::createDeparturesTypeTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE DeparturesType("
                  "DepTypeID    INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "DepType      TEXT    NOT NULL    UNIQUE)");
    checkExec(query);

    return true;
}

bool DBCreator::createAssitingTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE Assisting("
                  "AssistingID  INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "DepTypeID    INTEGER NOT NULL, "
                  "Address      TEXT    NOT NULL, "
                  "DepDate      TEXT    NOT NULL, "
                  "DepTime      TEXT    NOT NULL, "
                  "ArrivalDate  TEXT    NOT NULL, "
                  "ArrivalTime  TEXT    NOT NULL, "
                  "ReturnDate   TEXT    NOT NULL, "
                  "ReturnTime   TEXT    NOT NULL, "
                  "Description  TEXT    NOT NULL, "
                  "FOREIGN KEY(DepTypeID)   REFERENCES  DeparturesType(DepTypeID))");
    checkExec(query);

    return true;
}

bool DBCreator::createFireSafetyTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE FireSafety("
                  "FireSafetyID INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "DepTypeID    INTEGER NOT NULL, "
                  "Address      TEXT    NOT NULL, "
                  "DepDate      TEXT    NOT NULL, "
                  "DepTime      TEXT    NOT NULL, "
                  "ArrivalDate  TEXT    NOT NULL, "
                  "ArrivalTime  TEXT    NOT NULL, "
                  "ReturnDate   TEXT    NOT NULL, "
                  "ReturnTime   TEXT    NOT NULL, "
                  "Description  TEXT    NOT NULL, "
                  "FOREIGN KEY(DepTypeID) REFERENCES DeparturesType(DepTypeID))");
    checkExec(query);

    return true;
}

bool DBCreator::createOwerTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE Ower("
                  "OwerID       INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "DepTypeID    INTEGER NOT NULL, "
                  "Address      TEXT    NOT NULL, "
                  "DepDate      TEXT    NOT NULL, "
                  "DepTime      TEXT    NOT NULL, "
                  "ArrivalDate  TEXT    NOT NULL, "
                  "ArrivalTime  TEXT    NOT NULL, "
                  "ReturnDate   TEXT    NOT NULL, "
                  "ReturnTime   TEXT    NOT NULL, "
                  "Description  TEXT    NOT NULL, "
                  "FOREIGN KEY(DepTypeID) REFERENCES DeparturesType(DepTypeID))");
    checkExec(query);

    return true;
}

bool DBCreator::createTrainingTypeTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE TrainingType("
                  "TrainingTypeID   INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "TrainingType     TEXT    NOT NULL    UNIQUE)");
    checkExec(query);

    return true;
}

bool DBCreator::createTrainingTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE Training("
                  "TrainingID       INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "DepTypeID        INTEGER NOT NULL, "
                  "TrainingTypeID   INTEGER NOT NULL, "
                  "Address          TEXT    NOT NULL, "
                  "DepDate          TEXT    NOT NULL, "
                  "DepTime          TEXT    NOT NULL, "
                  "ArrivalDate      TEXT    NOT NULL, "
                  "ArrivalTime      TEXT    NOT NULL, "
                  "ReturnDate       TEXT    NOT NULL, "
                  "ReturnTime       TEXT    NOT NULL, "
                  "Description      TEXT    NOT NULL, "
                  "FOREIGN KEY(DepTypeID) REFERENCES DeparturesType(DepTypeID), "
                  "FOREIGN KEY(TrainingTypeID) REFERENCES TrainingType(TrainingTypeID))");
    checkExec(query);

    return true;
}

bool DBCreator::createFalseDepartureTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE FalseDeparture("
                  "FalseID      INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "DepTypeID    INTEGER NOT NULL, "
                  "Address      TEXT    NOT NULL, "
                  "DepDate      TEXT    NOT NULL, "
                  "DepTime      TEXT    NOT NULL, "
                  "ArrivalDate  TEXT    NOT NULL, "
                  "ArrivalTime  TEXT    NOT NULL, "
                  "ReturnDate   TEXT    NOT NULL, "
                  "ReturnTime   TEXT    NOT NULL, "
                  "Description  TEXT    NOT NULL, "
                  "FOREIGN KEY(DepTypeID)   REFERENCES DeparturesType(DepTypeID))");
    checkExec(query);

    return true;
}

bool DBCreator::createTypeUnuccountingFireTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE TypeUnuccountingFire("
                  "TypeUnuccountingFireID   INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "TypeUnuccountingFire     TEXT    NOT NULL    UNIQUE)");
    checkExec(query);

    return true;
}

bool DBCreator::createUnuccountingFireTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE UnuccountingFire("
                  "UnnccountingFireID       INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "DepTypeID                INTEGER NOT NULL, "
                  "TypeUnuccountingFireID   INTEGER NOT NULL, "
                  "Address                  TEXT    NOT NULL, "
                  "Reported                 TEXT    NOT NULL, "
                  "DepDate                  TEXT    NOT NULL, "
                  "DepTime                  TEXT    NOT NULL, "
                  "ArrivalDate              TEXT    NOT NULL, "
                  "ArrivalTime              TEXT    NOT NULL, "
                  "FirstBarrelDate          TEXT    NOT NULL, "
                  "FirstBarrelTime          TEXT    NOT NULL, "
                  "LocDate                  TEXT    NOT NULL, "
                  "LocTime                  TEXT    NOT NULL, "
                  "MitigationDate           TEXT    NOT NULL, "
                  "MitigationTime           TEXT    NOT NULL, "
                  "ReturnDate               TEXT    NOT NULL, "
                  "ReturnTime               TEXT    NOT NULL, "
                  "Description              TEXT    NOT NULL, "
                  "FOREIGN KEY(DepTypeID)   REFERENCES DeparturesType(DepTypeID), "
                  "FOREIGN KEY(TypeUnuccountingFireID)  REFERENCES TypeUnuccountingFire(TypeUnuccountingFireID))");
    checkExec(query);

    return true;
}

bool DBCreator::createSignalingTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE Signaling("
                  "SignalingID  INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "DepTypeID    INTEGER NOT NULL, "
                  "Address      TEXT    NOT NULL, "
                  "DepDate      TEXT    NOT NULL, "
                  "DepTime      TEXT    NOT NULL, "
                  "ArrivalDate  TEXT    NOT NULL, "
                  "ArrivalTime  TEXT    NOT NULL, "
                  "ReturnDate   TEXT    NOT NULL, "
                  "ReturnTime   TEXT    NOT NULL, "
                  "Description  TEXT    NOT NULL, "
                  "FOREIGN KEY(DepTypeID)   REFERENCES DeparturesType(DepTypeID))");
    checkExec(query);

    return true;
}

bool DBCreator::createDistrictsTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE Districts("
                  "DistrictID   INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "District     TEXT    NOT NULL    UNIQUE)");
    checkExec(query);

    return true;
}

bool DBCreator::createFireResistanceTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE FireResistance("
                  "ResistanceID INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "Resistance   TEXT    NOT NULL    UNIQUE)");
    checkExec(query);

    return true;
}

bool DBCreator::createCauseFireTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE CauseFire("
                  "CauseID  INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "Cause    TEXT    NOT NULL    UNIQUE)");
    checkExec(query);

    return true;
}

bool DBCreator::createTypeObjectTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE TypeObject("
                  "TypeObjectID INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "TypeObject   TEXT    NOT NULL    UNIQUE)");
    checkExec(query);

    return true;
}

bool DBCreator::createOwnTypeTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE OwnType("
                  "QwnTypeID    INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "OwnType      TEXT    NOT NULL    UNIQUE)");
    checkExec(query);

    return true;
}

bool DBCreator::createVentilationTypeTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE VentilationType("
                  "VentilationTypeID    INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "VentilationType      TEXT    NOT NULL    UNIQUE)");
    checkExec(query);

    return true;
}

bool DBCreator::createHeatingTypeTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE HeatingType("
                  "HeatingTypeID    INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "HeatingType      TEXT    NOT NULL    UNIQUE)");
    checkExec(query);

    return true;
}

bool DBCreator::createFireTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE Fire("
                  "FireID           INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "DepTypeID            INTEGER NOT NULL, "
                  "ReportedFullName     TEXT    NOT NULL, "
                  "ReprtedPhone         TEXT    NOT NULL, "
                  "ReportedPoliceDate   TEXT    NOT NULL, "
                  "ReportedPoliceTime   TEXT    NOT NULL, "
                  "PoliceFullName       TEXT    NOT NULL, "
                  "DetectionDate        TEXT    NOT NULL, "
                  "DetectionTime        TEXT    NOT NULL, "
                  "DetectionArea        INTEGER NOT NULL, "
                  "DistrictID           INTEGER NOT NULL, "
                  "Address              TEXT    NOT NULL, "
                  "TypeObjectID         INTEGER NOT NULL, "
                  "OwnTypeID            INTEGER NOT NULL, "
                  "TotalNumPeopleObj    INTEGER NOT NULL    DEFAULT 0, "
                  "ChildrenNumObj       INTEGER NOT NULL    DEFAULT 0, "
                  "NumPersonnelObj      INTEGER NOT NULL    DEFAULT 0, "
                  "AutoCallObj          TEXT    NOT NULL    DEFAULT 'нет', "
                  "SecurityTypeObj      TEXT    NOT NULL    DEFAULT 'нет', "
                  "SecurityPhoneObj     TEXT    NOT NULL    DEFAULT 'не установлен', "
                  "Owner                TEXT    NOT NULL    DEFAULT 'не установлен', "
                  "CharacteristicsObj   TEXT    NOT NULL, "
                  "ProportionsObj       TEXT    NOT NULL, "
                  "NumLevelObj          INTEGER NOT NULL    DEFAULT 1, "
                  "ResistanceID         INTEGER NOT NULL, "
                  "CockloftObj          TEXT    NOT NULL    DEFAULT 'да', "
                  "CellarObj            TEXT    NOT NULL    DEFAULT 'да', "
                  "StaircaseObj         INTEGER NOT NULL    DEFAULT 0, "
                  "VentilationTypeID    INTEGER NOT NULL, "
                  "HeatingTypeID        INTEGER NOT NULL, "
                  "ElectroficationObj   TEXT    NOT NULL    DEFAULT 'да', "
                  "GasificationObj      TEXT    NOT NULL    DEFAULT 'да', "
                  "AKHOV                TEXT    NOT NULL    DEFAULT 'нет', "
                  "FireSource           TEXT    NOT NULL    DEFAULT 'устанавливается', "
                  "FloorFireSource      INTEGER NOT NULL    DEFAULT 1, "
                  "CauseID              INTEGER NOT NULL, "
                  "Culprit              TEXT    NOT NULL    DEFAULT 'устанавливается', "
                  "SavedPeople          INTEGER NOT NULL    DEFAULT 0, "
                  "SavedChildren        INTEGER NOT NULL    DEFAULT 0, "
                  "MaterialDamaged      TEXT    NOT NULL    DEFAULT 'устанавливается', "
                  "SavedMaterialValues  TEXT    NOT NULL    DEFAULT 'устанавливается', "
                  "DepDate              TEXT    NOT NULL, "
                  "DepTime              TEXT    NOT NULL, "
                  "DepArea              INTEGER NOT NULL, "
                  "ArrivalDate          TEXT    NOT NULL, "
                  "ArrivalTime          TEXT    NOT NULL, "
                  "FirstArrivalArea     INTEGER NOT NULL, "
                  "FirstBarrelDate      TEXT    NOT NULL, "
                  "FiratBarrelTime      TEXT    NOT NULL, "
                  "FirstBarrelArea      INTEGER NOT NULL, "
                  "LocDate              TEXT    NOT NULL, "
                  "LocTime              TEXT    NOT NULL, "
                  "LocArea              INTEGER NOT NULL, "
                  "BurnDate             TEXT    NOT NULL, "
                  "BurnTime             TEXT    NOT NULL, "
                  "BurnArea             INTEGER NOT NULL, "
                  "MitigationDate       TEXT    NOT NULL, "
                  "MitigationTime       TEXT    NOT NULL, "
                  "MitigationArea       INTEGER NOT NULL, "
                  "ReturnDate           TEXT    NOT NULL, "
                  "ReturnTime           TEXT    NOT NULL, "
                  "ConsumedWater        INTEGER NOT NULL, "
                  "TotalFoaming         INTEGER NOT NULL    DEFAULT 0, "
                  "Wetting              INTEGER NOT NULL    DEFAULT 0, "
                  "PrimaryResource      INTEGER NOT NULL    DEFAULT 'не отмечено', "
                  "ProblematicIssues    TEXT    NOT NULL    DEFAULT 'не отмечено', "
                  "FOREIGN KEY(DepTypeID)           REFERENCES DeparturesType(DepTypeID), "
                  "FOREIGN KEY(DistrictID)          REFERENCES Districts(DistrictID), "
                  "FOREIGN KEY(ResistanceID)        REFERENCES FireResistance(ResistanceID), "
                  "FOREIGN KEY(CauseID)             REFERENCES CauseFire(CauseID), "
                  "FOREIGN KEY(TypeObjectID)        REFERENCES TypeObject(TypeObjectID), "
                  "FOREIGN KEY(OwnTypeID)           REFERENCES OwnType(OwnTypeID), "
                  "FOREIGN KEY(VentilationTypeID)   REFERENCES VentilationType(VentilationTypeID), "
                  "FOREIGN KEY(HeatingTypeID)       REFERENCES HeatingType(HeatingTypeID))");
    checkExec(query);

    return true;
}

bool DBCreator::createVictimsFireTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE VictimsFire("
                  "VictimsFireID    INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "FireID           INTEGER NOT NULL, "
                  "FullName         TEXT    NOT NULL, "
                  "Birthday         TEXT    NOT NULL    DEFAULT 'устанавливается', "
                  "Adress           TEXT    NOT NULL    DEFAULT 'устанавливается', "
                  "Creer            TEXT    NOT NULL    DEFAULT 'устанавливается', "
                  "SocialStatus     TEXT    NOT NULL    DEFAULT 'не определён', "
                  "DetectionTime    TEXT    NOT NULL, "
                  "Trauma           TEXT    NOT NULL    DEFAULT 'устанавливается', "
                  "FOREIGN KEY(FireID)  REFERENCES Fire(FireID))");
    checkExec(query);

    return true;
}

bool DBCreator::createDeadFireTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE DeadFire("
                  "DeadFireID       INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "FireID           INTEGER NOT NULL, "
                  "FullName         TEXT    NOT NULL    DEFAULT 'устанавливается', "
                  "Birthday         TEXT    NOT NULL    DEFAULT 'устанавливается', "
                  "Adress           TEXT    NOT NULL    DEFAULT 'устанавливается', "
                  "Creer            TEXT    NOT NULL    DEFAULT 'устанавливается', "
                  "SocialStatus     TEXT    NOT NULL    DEFAULT 'устанавливается', "
                  "DetectionTime    TEXT    NOT NULL    DEFAULT 'не отмечено', "
                  "Description      TEXT    NOT NULL    DEFAULT 'не отмечено', "
                  "FOREIGN KEY(FireID)  REFERENCES  Fire(FireID))");
    checkExec(query);

    return true;
}

bool DBCreator::createRatingTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE Rating("
                  "RatingID INTEGER PRIMATY KEY AUTOINCRAMANT, "
                  "Rating   TEXT    NOT NULL    UNIQUE)");
    checkExec(query);

    return true;
}

bool DBCreator::createFireExtinguisherTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE FireExtinguisher("
                  "FireExtinguisherID   INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "FireID               INTEGER NOT NULL, "
                  "RatingID             INTEGER NOT NULL, "
                  "Number               INTEGER NOT NULL    DEFAULT 1, "
                  "Position             TEXT    NOT NULL, "
                  "FullName             TEXT    NOT NULL, "
                  "FOREIGN KEY(FireID)      REFERENCES  Fire(FireID), "
                  "FOREIGN KEY(RatingID)    REFERENCES  Rating(RaingID))");
    checkExec(query);

    return true;
}

bool DBCreator::createInternalWaterSupplyTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE InternalWaterSuplly("
                  "InternalWaterSapplyID    INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "FireID                   INTEGER NOT NULL, "
                  "Diameter                 INTEGER NOT NULL    DEFAULT 51, "
                  "Pressure                 TEXT    NOT NULL    DEFAULT '2.0', "
                  "Amount                   INTEGER NOT NULL, "
                  "FOREIGN KEY(FireID)  REFERENCES  Fire(FireID))");
    checkExec(query);

    return true;
}

bool DBCreator::createHydrantTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE Hydrant("
                  "HydrantID    INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "FireID       INTEGER NOT NULL, "
                  "HydrantType  TEXT    NOT NULL    DEFAULT 'К-', "
                  "Diameter     INTEGER NOT NULL    DEFAULT 150, "
                  "Pressure     TEXT    NOT NULL    DEFAULT '2.0', "
                  "Distance     INTEGER NOT NULL, "
                  "FOREIGN KEY(FireID)  REFERENCES  Fire(FireID))");
    checkExec(query);

    return true;
}

bool DBCreator::createFirePondTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE FirePond("
                  "FirePondID   INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "FireID       INTEGER NOT NULL, "
                  "Volume       INTEGER NOT NULL, "
                  "Distance     INTEGER NOT NULL, "
                  "FOREIGN KEY(FireID)  REFERENCES  Fire(FireID))");
    checkExec(query);

    return true;
}

bool DBCreator::createNaturalFireReservoirTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE NaturalFireReservoir("
                  "NaturalFireReservoirID   INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "FireID                   INTEGER NOT NULL, "
                  "Pier                     TEXT    NOT NULL    DEFAULT 'нет', "
                  "Distance                 INTEGER NOT NULL, "
                  "FOREIGN KEY(FireID)  REFERENCES  Fire(FireID))");
    checkExec(query);

    return true;
}

bool DBCreator::createStateFireServiceTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE StateFireService("
                  "StateFireDerviceID   INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "FireID               INTEGER NOT NULL, "
                  "Distanse             INTEGER NOT NULL, "
                  "ReportedDate         TEXT    NOT NULL, "
                  "ReportedTime         TEXT    NOT NULL, "
                  "ReportedArea         INTEGER NOT NULL, "
                  "ArrivalDate          TEXT    NOT NULL, "
                  "ArrivalTime          TEXT    NOT NULL, "
                  "ArrivalArea          INTEGER NOT NULL, "
                  "Texnique             TEXT    NOT NULL, "
                  "NumPersonnel         INTEGER NOT NULL, "
                  "FOREIGN KEY(FireID)  REFERENCES  Fire(FireID))");
    checkExec(query);

    return true;
}

bool DBCreator::createDepartmentalFireBrigadeTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE DepartmentalFireBrigade("
                  "DepartmentalFireBrigadeID    INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "FireID                       INTEGER NOT NULL, "
                  "Distance                     INTEGER NOT NULL, "
                  "ReportedDate                 TEXT    NOT NULL, "
                  "ReportedTime                 TEXT    NOT NULL, "
                  "ReportedArea                 INTEGER NOT NULL, "
                  "ArrivalDate                  TEXT    NOT NULL, "
                  "ArrivalTime                  TEXT    NOT NULL, "
                  "ArrivalArea                  INTEGER NOT NULL, "
                  "Texnique                     TEXT    NOT NULL, "
                  "NumPersonnel                 INTEGER NOT NULL, "
                  "FOREIGN KEY(FireID)  REFERENCES  Fire(FireID))");
    checkExec(query);

    return true;
}

bool DBCreator::createVoluntaryFireBrigadeTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE VoluntaryFireBrigade("
                  "VoluntaryFireBrigadeID   INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "FireID                   INTEGER NOT NULL, "
                  "Distance                 INTEGER NOT NULL, "
                  "ReportedDate             TEXT    NOT NULL, "
                  "ReportedTime             TEXT    NOT NULL, "
                  "ReportedArea             INTEGER NOT NULL, "
                  "ArrivalDate              TEXT    NOT NULL, "
                  "ArrivalTime              TEXT    NOT NULL, "
                  "ArrivalArea              INTEGER NOT NULL, "
                  "Texnique                 TEXT    NOT NULL, "
                  "NumPersonnel             INTEGER NOT NULL, "
                  "FOREIGN KEY(FireID)  REFERENCES  Fire(FireID))");
    checkExec(query);

    return true;
}

bool DBCreator::createLocalFireBrigadeTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE LocalFireBrigade("
                  "LocalFireBrigadeID   INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "FireID               INTEGER NOT NULL, "
                  "Distance             INTEGER NOT NULL, "
                  "ReportedDate         TEXT    NOT NULL, "
                  "ReportedTime         TEXT    NOT NULL, "
                  "ReportedArea         INTEGER NOT NULL, "
                  "ArrivalDate          TEXT    NOT NULL, "
                  "ArrivalTime          TEXT    NOT NULL, "
                  "ArrivalArea          INTEGER NOT NULL, "
                  "Texnique             TEXT    NOT NULL, "
                  "NumPersonnel         INTEGER NOT NULL, "
                  "FOREIGN KEY(FireID)  REFERENCES  Fire(FireID))");
    checkExec(query);

    return true;
}

bool DBCreator::createPrivateFireBrigadeTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE PrivateFireBrigade("
                  "PrivateFireBrigadeID INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "FireID               INTEGER NOT NULL, "
                  "Distance             INTEGER NOT NULL, "
                  "ReportedDate         TEXT    NOT NULL, "
                  "ReportedTime         TEXT    NOT NULL, "
                  "ReportedArea         INTEGER NOT NULL, "
                  "ArrivalDate          TEXT    NOT NULL, "
                  "ArrivalTime          TEXT    NOT NULL, "
                  "ArrivalArea          INTEGER NOT NULL, "
                  "Texnique             TEXT    NOT NULL, "
                  "NumPersonnel         INTEGER NOT NULL, "
                  "FOREIGN KEY(FireID)  REFERENCES  Fire(FireID))");
    checkExec(query);

    return true;
}

bool DBCreator::createPopulationOrganizationTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE PopulationOrganization("
                  "PopulationOrganizationID INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "FireID                   INTEGER NOT NULL, "
                  "Texnique                 TEXT    NOT NULL, "
                  "NumPersonnel             INTEGER NOT NULL, "
                  "FOREIGN KEY(FireID)  REFERENCES  Fire(FireID))");
    checkExec(query);

    return true;
}

bool DBCreator::createOperationalHeadquartersTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE OperationalHeadquarters("
                  "OperationalHeadquartersID    INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "FireID                       INTEGER NOT NULL, "
                  "DateCreation                 TEXT    NOT NULL, "
                  "TimeCreation                 TEXT    NOT NULL, "
                  "FireArea                     INTEGER NOT NULL, "
                  "FOREIGN KEY(FireID)  REFERENCES  Fire(FireID))");
    checkExec(query);

    return true;
}

bool DBCreator::createFireDestroyedTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE FireDestroyed("
                  "FireDestroyedID  INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "FireID           INTEGER NOT NULL, "
                  "Building         INTEGER NOT NULL    DEFAULT 0, "
                  "FloorSpace       INTEGER NOT NULL    DEFAULT 0, "
                  "Texnique         INTEGER NOT NULL    DEFAULT 0, "
                  "Grain            INTEGER NOT NULL    DEFAULT 0, "
                  "Forage           INTEGER NOT NULL    DEFAULT 0, "
                  "Cereal           INTEGER NOT NULL    DEFAULT 0, "
                  "Cattle           INTEGER NOT NULL    DEFAULT 0, "
                  "Poultry          INTEGER NOT NULL    DEFAULT 0, "
                  "FOREIGN KEY(FireID)  REFERENCES  Fire(FireID))");
    checkExec(query);

    return true;
}

bool DBCreator::createFireDamagedTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE FireDamaged("
                  "FireDamagesID    INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "FireID           INTEGER NOT NULL, "
                  "Building         INTEGER NOT NULL    DEFAULT 0, "
                  "FloorSpace       INTEGER NOT NULL    DEFAULT 0, "
                  "Texnique         INTEGER NOT NULL    DEFAULT 0, "
                  "Grain            INTEGER NOT NULL    DEFAULT 0, "
                  "Forage           INTEGER NOT NULL    DEFAULT 0, "
                  "Cereal           INTEGER NOT NULL    DEFAULT 0, "
                  "Cattle           INTEGER NOT NULL    DEFAULT 0, "
                  "Poultry          INTEGER NOT NULL    DEFAULT 0, "
                  "FOREIGN KEY(FireID)  REFERENCES  Fire(FireID))");
    checkExec(query);

    return true;
}

bool DBCreator::createSavedTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE Saved("
                  "SavedID      INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "FireID       INTEGER NOT NULL, "
                  "Building     INTEGER NOT NULL    DEFAULT 0, "
                  "FloorSpace   INTEGER NOT NULL    DEFAULT 0, "
                  "Texnique     INTEGER NOT NULL    DEFAULT 0, "
                  "Grain        INTEGER NOT NULL    DEFAULT 0, "
                  "Forage       INTEGER NOT NULL    DEFAULT 0, "
                  "Cereal       INTEGER NOT NULL    DEFAULT 0, "
                  "Cattle       INTEGER NOT NULL    DEFAULT 0, "
                  "Poultry      INTEGER NOT NULL    DEFAULT 0, "
                  "FOREIGN KEY(FireID)   REFERENCES  Fire(FireID))");
    checkExec(query);

    return true;
}

bool DBCreator::createBarrelTypeTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE BarrelType("
                  "BarrelTypeID INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "BarrelType   TEXT    UNIQUE)");
    checkExec(query);

    return true;
}

bool DBCreator::createBarrelsTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE Barrels("
                  "BarrelsID    INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "FireID       INTEGER NOT NULL, "
                  "BarrelTypeID INTEGER NOT NULL, "
                  "NumBarrels   INTEGER NOT NULL    DEFAULT 1, "
                  "FOREIGN KEY(FireID)          REFERENCES  Fire(FireID), "
                  "FOREIGN KEY(BarrelTypeID)    REFERENCES  BarrelType(BarrelTypeID))");
    checkExec(query);

    return true;
}

bool DBCreator::createGDZSTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE GDZS("
                  "GDZSID           INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "FireID           INTEGER NOT NULL, "
                  "Commander        TEXT    NOT NULL, "
                  "InclusionDate    TEXT    NOT NULL, "
                  "InclusionTime    TEXT    NOT NULL, "
                  "OffDate          TEXT    NOT NULL, "
                  "OffTime          TEXT    NOT NULL, "
                  "FOREIGN KEY(FireID)  REFERENCES  Fire(FireID))");
    checkExec(query);

    return true;
}

bool DBCreator::createFireAutomaticsTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE FireAutomatics("
                  "FireAutomaticsID INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "FireID           INTEGER NOT NULL, "
                  "Availability     TEXT    NOT NULL    DEFAULT 'нет', "
                  "Type             TEXT    NOT NULL    DEFAULT 'не отмечено', "
                  "Efficiency       TEXT    NOT NULL    DEFAULT 'не отмечено', "
                  "FOREIGN KEY(FireID)  REFERENCES  Fire(FireID))");
    checkExec(query);

    return true;
}

bool DBCreator::createOperationalDocTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE OperationalDoc("
                  "OperationalDocID INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "FireID           INTEGER NOT NULL, "
                  "ApprovalDate     TEXT    NOT NULL, "
                  "FullNamedWorked  TEXT    NOT NULL, "
                  "WorkedDate       TEXT    NOT NULL, "
                  "FOREIGN KEY(FireID)  REFERENCES  Fire(FireID))");
    checkExec(query);

    return true;
}

bool DBCreator::createInvestigativeTeamTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE InvestigativeTeam("
                  "InvestigativeTeamID  INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "FireID               INTEGER NOT NULL, "
                  "Header               TEXT    NOT NULL    DEFAULT 'не отмечено', "
                  "GPS                  TEXT    NOT NULL    DEFAULT 'не отмечено', "
                  "OVD                  TEXT    NOT NULL    DEFAULT 'не отмечено', "
                  "Prosecutor           TEXT    NOT NULL    DEFAULT 'не отмечено', "
                  "FOREIGN KEY(FireID)  REFERENCES  Fire(FireID))");
    checkExec(query);

    return true;
}

bool DBCreator::createTypeTrafficAccidentTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE TypeTrafficAccident("
                  "TypeTrafficAccidentID    INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "TypeTrafficAccident      TEXT    NOT NULL    UNIQUE)");
    checkExec(query);

    return true;
}

bool DBCreator::createAccidentAlertTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE AccidentAlert("
                  "AccidentAlertID  INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "AccidentAlert    TEXT    NOT NULL    UNIQUE)");
    checkExec(query);

    return true;
}

bool DBCreator::createSourceInfTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE SourceInf("
                  "SourceInfID  INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "SourceInf    TEXT    NOT NULL    UNIQUE)");
    checkExec(query);

    return true;
}

bool DBCreator::createSecondDamagedFactorsTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE SecondDamagedFactors("
                  "SecondDamagedFactorsID   INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "SecondDamagedFactors     TEXT    NOT NULL    UNIQUE)");
    checkExec(query);

    return true;
}

bool DBCreator::createTrafficAccidentTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE TrafficAccident("
                  "TrafficAccidentID        INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "DepTypeID                INTEGER NOT NULL, "
                  "TrafficAccidentDate      TEXT    NOT NULL, "
                  "TrafficAccidentTime      TEXT    NOT NULL, "
                  "TypeAccidentID           INTEGER NOT NULL, "
                  "Address                  TEXT    NOT NULL, "
                  "Highway                  TEXT    NOT NULL, "
                  "Kilometer                TEXT    NOT NULL, "
                  "Region                   TEXT    NOT NULL, "
                  "Locality                 TEXT    NOT NULL, "
                  "Street                   TEXT    NOT NULL, "
                  "House                    TEXT    NOT NULL, "
                  "OtherInformation         TEXT    NOT NULL, "
                  "ReportedDate             TEXT    NOT NULL, "
                  "ReportedTime             TEXT    NOT NULL, "
                  "DepDate                  TEXT    NOT NULL, "
                  "DepTime                  TEXT    NOT NULL, "
                  "ArrivalDate              TEXT    NOT NULL, "
                  "ArrivalTime              TEXT    NOT NULL, "
                  "OffDate                  TEXT    NOT NULL, "
                  "OffTime                  TEXT    NOT NULL, "
                  "ReturnDate               TEXT    NOT NULL, "
                  "ReturnTime               TEXT    NOT NULL, "
                  "AccidentAlertID          INTEGER NOT NULL, "
                  "SourceInfID              INTEGER NOT NULL, "
                  "UnlockPiople             INTEGER NOT NULL, "
                  "SavedPeople              INTEGER NOT NULL, "
                  "FirstAid                 INTEGER NOT NULL, "
                  "SecondDamagedFactorsID   INTEGER NOT NULL, "
                  "DescriptionAccident      TEXT    NOT NULL, "
                  "DescriptionRescue        TEXT    NOT NULL, "
                  "FOREIGN KEY(DepTypeID)               REFERENCES  DeparturesType(DepType), "
                  "FOREIGN KEY(TypeAccidentID)          REFERENCES  TypeTrefficAccident(TypeTrafficAccident), "
                  "FOREIGN KEY(AccidentAlertID)         REFERENCES  AccidentAlert(AccidentAlert), "
                  "FOREIGN KEY(SourceInfID)             REFERENCES  SourceInf(SourceInf), "
                  "FOREIGN KEY(SecondDamagedFactorsID)  REFERENCES  SecondDamagedFactors(SecondDamagedFactors))");
    checkExec(query);

    return true;
}

bool DBCreator::createVehicleTypeTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE VehicleType("
                  "VehicleTypeID    INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "VehicleType      TEXT    NOT NULL    UNIQUE)");
    checkExec(query);

    return true;
}

bool DBCreator::createVehiclesTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE Vehicles("
                  "VehiclesID           INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "TrafficAccidentID    INTEGER NOT NULL, "
                  "VehicleTypeID       INTEGER NOT NULL, "
                  "Model                TEXT    NOT NULL    DEFAULT 'устанавливается', "
                  "LicensePlate         TEXT    NOT NULL    DEFAULT 'устанавливается', "
                  "PeopleNum            INTEGER NOT NULL    DEFAULT 0, "
                  "RescueOperations     TEXT    NOT NULL    DEFAULT 'да', "
                  "FOREIGN KEY(TrafficAccidentID)   REFERENCES  TrafficAccident(TrafficAccidentID), "
                  "FOREIGN KEY(VehicleTypeID)       REFERENCES  VehicleType(VehicleType))");
    checkExec(query);

    return true;
}

bool DBCreator::createVictimsAccidentTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE VictimsAccident("
                  "VictimsAccidentID    INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "TrafficAccidentID    INTEGER NOT NULL, "
                  "FullName             TEXT    NOT NULL    DEFAULT 'устанавливается', "
                  "Birthday             TEXT    NOT NULL    DEFAULT 'устанавливается', "
                  "Address              TEXT    NOT NULL    DEFAULT 'устанавливается', "
                  "Career               TEXT    NOT NULL    DEFAULT 'устанавливается', "
                  "SocialStatus         TEXT    NOT NULL    DEFAULT 'устанавливается', "
                  "Trauma               TEXT    NOT NULL    DEFAULT 'устанавливается', "
                  "FOREIGN KEY(TrafficAccidentID)   REFERENCES  TrafficAccident(TrafficAccidentID))");
    checkExec(query);

    return true;
}

bool DBCreator::createDeadAccidentTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE DeadAccident("
                  "DeadAccidenID        INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "TrafficAccidentID    INTEGER NOT NULL, "
                  "FullName             TEXT    NOT NULL    DEFAULT 'устанавливается', "
                  "Birthday             TEXT    NOT NULL    DEFAULT 'устанавливается', "
                  "Address              TEXT    NOT NULL    DEFAULT 'устанавливается', "
                  "Career               TEXT    NOT NULL    DEFAULT 'устанавливается', "
                  "SocialStatus         TEXT    NOT NULL    DEFAULT 'устанавливается', "
                  "Description          TEXT    NOT NULL    DEFAULT 'нет', "
                  "FOREIGN KEY(TrafficAccidentID)   REFERENCES  TrafficAccident(TrafficAccidentID))");
    checkExec(query);

    return true;
}

bool DBCreator::createTypeASRTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE TypeASR("
                  "TypeASRID    INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "TypeASR      TEXT    NOT NULL    UNIQUE)");
    checkExec(query);

    return true;
}

bool DBCreator::createASRTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE ASR("
                  "ASRID                INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "TrafficAccidentID    INTEGER NOT NULL, "
                  "TypeASRID            INTEGER NOT NULL, "
                  "Description          TEXT    NOT NULL    DEFAULT 'нет', "
                  "ASR                  TEXT    NOT NULL    DEFAULT 'не проводились', "
                  "FOREIGN KEY(TrafficAccidentID)   REFERENCES  TrafficAccident(TrafficAccidentID), "
                  "FOREIGN KEY(TypeASRID)           REFERENCES  TypeASR(TypeASR))");
    checkExec(query);

    return true;
}

bool DBCreator::createExistingASFTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE ExistingASF("
                  "ExistingASFID    INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "ExistingASF      TEXT    NOT NULL    UNIQUE)");
    checkExec(query);

    return true;
}

bool DBCreator::createASFTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE ASF("
                  "ASFID                INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "TrafficAccidentID    INTEGER NOT NULL, "
                  "ExistingASFID        INTEGER NOT NULL, "
                  "Vehicle              TEXT    NOT NULL, "
                  "InitSpeed            INTEGER NOT NULL, "
                  "EndSpeed             INTEGER NOT NULL, "
                  "NumRescuers          INTEGER NOT NULL, "
                  "FOREIGN KEY(TrafficAccidentID)   REFERENCES  TrafficAccident(TrafficAccidentID), "
                  "FOREIGN KEY(ExistingASFID)       REFERENCES  ExistingASF(ExistingASF))");
    checkExec(query);

    return true;
}

bool DBCreator::createTypeInstrumentTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE TypeInstrument("
                  "TypeInstrumentID INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "TypeInstrument   TEXT    NOT NULL UNIQUE)");
    checkExec(query);

    return true;
}

bool DBCreator::createInstrumentTable(QSqlQuery query)
{
    query.prepare("CREATE TABLE Instrument("
                  "InstrumentID     INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "TypeInstrumentID INTEGER NOT NULL, "
                  "Instrument       TEXT    NOT NULL, "
                  "FOREIGN KEY(TypeInstrumentID)    REFERENCES  TypeInsrument(TypeInstrumentID))");
    checkExec(query);

    return true;
}

bool DBCreator::createMainView(QSqlQuery query)
{
    query.prepare("CREATE VIEW Main  AS "
                  "SELECT DepDate, DepTime, DepType, Address, ArrivalDate, ArrivalTime, ReturnDate, ReturnTime FROM Fire "
                  "INNER JOIN DeparturesType USING (DepTypeID) UNION "
                  "SELECT DepDate, DepTime, DepType, Address, ArrivalDate, ArrivalTime, ReturnDate, ReturnTime FROM UnuccountingFire "
                  "INNER JOIN DeparturesType USING (DepTypeID) UNION "
                  "SELECT DepDate, DepTime, DepType, Address, ArrivalDate, ArrivalTime, ReturnDate, ReturnTime FROM TrafficAccident "
                  "INNER JOIN DeparturesType USING (DepTypeID) UNION "
                  "SELECT DepDate, DepTime, DepType, Address, ArrivalDate, ArrivalTime, ReturnDate, ReturnTime FROM Signaling "
                  "INNER JOIN DeparturesType USING (DepTypeID) UNION "
                  "SELECT DepDate, DepTime, DepType, Address, ArrivalDate, ArrivalTime, ReturnDate, ReturnTime FROM Training "
                  "INNER JOIN DeparturesType USING (DepTypeID) UNION "
                  "SELECT DepDate, DepTime, DepType, Address, ArrivalDate, ArrivalTime, ReturnDate, ReturnTime FROM FalseDeparture "
                  "INNER JOIN DeparturesType USING (DepTypeID) UNION "
                  "SELECT DepDate, DepTime, DepType, Address, ArrivalDate, ArrivalTime, ReturnDate, ReturnTime FROM Assisting "
                  "INNER JOIN DeparturesType USING (DepTypeID) UNION "
                  "SELECT DepDate, DepTime, DepType, Address, ArrivalDate, ArrivalTime, ReturnDate, ReturnTime FROM FireSafety "
                  "INNER JOIN DeparturesType USING (DepTypeID) UNION "
                  "SELECT DepDate, DepTime, DepType, Address, ArrivalDate, ArrivalTime, ReturnDate, ReturnTime FROM Ower "
                  "INNER JOIN DeparturesType USING (DepTypeID)");
    checkExec(query);

    return true;
}

