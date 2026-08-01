#include "../include/FileManager.h"

#include <fstream>
#include <iostream>

// Save Hospitals
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

// Load Hospitals
void FileManager::loadHospitals(std::vector<Hospital>& hospitals) const
{
    std::ifstream inFile("data/hospitals.txt");

    if (!inFile)
    {
        return;
    }

    int id;
    int location;
    std::string name;

    while (inFile >> id >> name >> location)
    {
        hospitals.push_back(
            Hospital(id, name, location)
        );
    }

    inFile.close();
}

// Save Emergencies
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

// Load Emergencies
void FileManager::loadEmergencies(
    std::vector<Emergency>& emergencies
) const
{
    // Will be implemented in v1.1
}