#include "../include/FileManager.h"

#include <fstream>
#include <iostream>

// ==========================
// Save Hospitals
// ==========================

void FileManager::saveHospitals(const std::vector<Hospital>& hospitals) const
{
    std::ofstream outFile("data/hospitals.txt");

    if (!outFile)
    {
        std::cout << "Error opening hospitals.txt\n";
        return;
    }

    for (const auto& hospital : hospitals)
    {
        outFile
            << hospital.getHospitalId() << ' '
            << hospital.getName() << ' '
            << hospital.getLocationNode() << '\n';
    }

    outFile.close();
}

// ==========================
// Load Hospitals
// ==========================

void FileManager::loadHospitals(std::vector<Hospital>& hospitals) const
{
    std::ifstream inFile("data/hospitals.txt");

    if (!inFile)
    {
        return;
    }

    hospitals.clear();

    int hospitalId;
    int locationNode;
    std::string name;

    while (inFile >> hospitalId >> name >> locationNode)
    {
        hospitals.push_back(
            Hospital(
                hospitalId,
                name,
                locationNode
            )
        );
    }

    inFile.close();
}

// ==========================
// Save Ambulances
// ==========================

void FileManager::saveAmbulances(
    const std::vector<Ambulance>& ambulances
) const
{
    std::ofstream outFile("data/ambulances.txt");

    if (!outFile)
    {
        std::cout << "Error opening ambulances.txt\n";
        return;
    }

    for (const auto& ambulance : ambulances)
    {
        outFile
            << ambulance.getAmbulanceId() << ' '
            << ambulance.getHospitalId() << ' '
            << ambulance.getCurrentNode() << ' '
            << ambulance.isAvailable() << '\n';
    }

    outFile.close();
}

// ==========================
// Load Ambulances
// ==========================

void FileManager::loadAmbulances(
    std::vector<Ambulance>& ambulances
) const
{
    std::ifstream inFile("data/ambulances.txt");

    if (!inFile)
    {
        return;
    }

    ambulances.clear();

    int ambulanceId;
    int hospitalId;
    int currentNode;
    bool available;

    while (inFile
           >> ambulanceId
           >> hospitalId
           >> currentNode
           >> available)
    {
        ambulances.push_back(
            Ambulance(
                ambulanceId,
                hospitalId,
                currentNode,
                available
            )
        );
    }

    inFile.close();
}

// ==========================
// Save Emergencies
// ==========================

void FileManager::saveEmergencies(
    const std::vector<Emergency>& emergencies
) const
{
    std::ofstream outFile("data/emergencies.txt");

    if (!outFile)
    {
        std::cout << "Error opening emergencies.txt\n";
        return;
    }

    for (const auto& emergency : emergencies)
    {
        outFile
            << emergency.getEmergencyId() << ' '
            << emergency.getPatient().getPatientId() << ' '
            << emergency.getPriority() << ' '
            << emergency.getStatus() << '\n';
    }

    outFile.close();
}

// ==========================
// Load Emergencies
// ==========================

void FileManager::loadEmergencies(
    std::vector<Emergency>& emergencies
) const
{
    emergencies.clear();

    // Will be implemented in Version 1.1
}