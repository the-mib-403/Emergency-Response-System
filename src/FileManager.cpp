#include "../include/FileManager.h"

#include <fstream>
#include <iostream>

// ==========================
// Save Hospitals
// ==========================

void FileManager::saveHospitals(
    const std::vector<Hospital> &hospitals) const
{
    std::ofstream outFile("data/hospitals.txt");

    if (!outFile)
    {
        std::cout << "Error opening hospitals.txt\n";
        return;
    }

    outFile << "# HospitalID Name LocationNode\n";

    for (const auto &hospital : hospitals)
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

void FileManager::loadHospitals(
    std::vector<Hospital> &hospitals) const
{
    std::ifstream inFile("data/hospitals.txt");

    if (!inFile)
    {
        return;
    }

    hospitals.clear();

    std::string line;

    // Skip header
    std::getline(inFile, line);

    int hospitalId;
    int locationNode;
    std::string name;

    while (inFile >> hospitalId >> name >> locationNode)
    {
        hospitals.push_back(
            Hospital(
                hospitalId,
                name,
                locationNode));
    }

    inFile.close();
}

// ==========================
// Save Ambulances
// ==========================

void FileManager::saveAmbulances(
    const std::vector<Ambulance> &ambulances) const
{
    std::ofstream outFile("data/ambulances.txt");

    if (!outFile)
    {
        std::cout << "Error opening ambulances.txt\n";
        return;
    }

    outFile << "# AmbulanceID HospitalID CurrentNode Available AssignedEmergencyID\n";

    for (const auto &ambulance : ambulances)
    {
        outFile
            << ambulance.getAmbulanceId() << ' '
            << ambulance.getHospitalId() << ' '
            << ambulance.getCurrentNode() << ' '
            << ambulance.isAvailable() << ' '
            << ambulance.getAssignedEmergencyId() << '\n';
    }

    outFile.close();
}

// ==========================
// Load Ambulances
// ==========================

void FileManager::loadAmbulances(
    std::vector<Ambulance> &ambulances) const
{
    std::ifstream inFile("data/ambulances.txt");

    if (!inFile)
    {
        return;
    }

    ambulances.clear();
    std::string line;

    // Skip header
    std::getline(inFile, line);

    int ambulanceId;
    int hospitalId;
    int currentNode;
    bool available;
    int assignedEmergencyId;

    while (inFile >> ambulanceId >> hospitalId >> currentNode >> available >> assignedEmergencyId)
    {
        ambulances.push_back(
            Ambulance(
                ambulanceId,
                hospitalId,
                currentNode,
                available,
                assignedEmergencyId));
    }

    inFile.close();
}

// ==========================
// Save Emergencies
// ==========================

void FileManager::saveEmergencies(
    const std::vector<Emergency> &emergencies) const
{
    std::ofstream outFile("data/emergencies.txt");

    if (!outFile)
    {
        std::cout << "Error opening emergencies.txt\n";
        return;
    }
    outFile << "# EmergencyID PatientID Name Location Severity Phone Priority Status\n";
    for (const auto &emergency : emergencies)
    {
        const Patient &patient = emergency.getPatient();

        outFile
            << emergency.getEmergencyId() << ' '
            << patient.getPatientId() << ' '
            << patient.getName() << ' '
            << patient.getLocation() << ' '
            << patient.getSeverity() << ' '
            << patient.getPhone() << ' '
            << emergency.getPriority() << ' '
            << emergency.getStatus() << '\n';
    }

    outFile.close();
}

// ==========================
// Load Emergencies
// ==========================

void FileManager::loadEmergencies(
    std::vector<Emergency> &emergencies) const
{
    std::ifstream inFile("data/emergencies.txt");

    if (!inFile)
    {
        return;
    }

    emergencies.clear();
    std::string line;

    // Skip header
    std::getline(inFile, line);

    int emergencyId;
    int patientId;
    std::string name;
    int location;
    int severity;
    std::string phone;
    int priority;
    std::string status;

    while (inFile >> emergencyId >> patientId >> name >> location >> severity >> phone >> priority >> status)
    {
        Patient patient(
            patientId,
            name,
            location,
            severity,
            phone);

        Emergency emergency(
            emergencyId,
            patient,
            priority,
            status);

        emergencies.push_back(emergency);
    }

    inFile.close();
}

// ==========================
// Save Dispatch History
// ==========================

void FileManager::saveHistory(
    const Emergency &emergency,
    const Hospital &hospital,
    const Ambulance &ambulance) const
{
    std::ofstream outFile("data/history.txt", std::ios::app);

    if (!outFile)
    {
        std::cout << "Error opening history.txt\n";
        return;
    }

    const Patient &patient = emergency.getPatient();

    outFile << "=========================================\n";
    outFile << "Emergency ID : " << emergency.getEmergencyId() << '\n';
    outFile << "Patient      : " << patient.getName() << '\n';
    outFile << "Phone        : " << patient.getPhone() << '\n';
    outFile << "Location     : " << patient.getLocation() << '\n';
    outFile << "Severity     : " << patient.getSeverity() << '\n';
    outFile << '\n';
    outFile << "Hospital     : " << hospital.getName() << '\n';
    outFile << "Ambulance ID : " << ambulance.getAmbulanceId() << '\n';
    outFile << '\n';
    outFile << "Status       : " << emergency.getStatus() << '\n';
    outFile << "=========================================\n\n";

    outFile.close();
}