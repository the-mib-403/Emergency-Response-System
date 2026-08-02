#ifndef EMERGENCYSYSTEM_H
#define EMERGENCYSYSTEM_H

#include <vector>

#include "Graph.h"
#include "Hospital.h"
#include "Ambulance.h"
#include "Emergency.h"
#include "FileManager.h"

class EmergencySystem
{
private:
    Graph cityGraph;

    std::vector<Hospital> hospitals;
    std::vector<Ambulance> ambulances;
    std::vector<Emergency> emergencies;

    FileManager fileManager;

public:
    // Constructor
    EmergencySystem();

    // System Initialization
    void initialize();

    // Data Management
    void saveData();
    void loadData();

    // Hospital Management
    void addHospital();
    void showHospitals() const;

    // Ambulance Management
    void showAmbulances() const;

    // Emergency Management
    void registerEmergency();
    void showEmergencies() const;

    // Ambulance Dispatch
    void dispatchAmbulance();

    // Main Menu
    void run();
};

#endif