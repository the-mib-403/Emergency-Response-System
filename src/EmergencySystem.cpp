#include "../include/EmergencySystem.h"

#include <iostream>

// Constructor
EmergencySystem::EmergencySystem()
{
}

// Initialize System
void EmergencySystem::initialize()
{
    fileManager.loadHospitals(hospitals);
    fileManager.loadAmbulances(ambulances);

    cityGraph = Graph(6);

    cityGraph.addEdge(0, 1, 5);
    cityGraph.addEdge(0, 2, 8);
    cityGraph.addEdge(1, 3, 4);
    cityGraph.addEdge(2, 3, 6);
    cityGraph.addEdge(2, 4, 3);
    cityGraph.addEdge(3, 5, 7);
    cityGraph.addEdge(4, 5, 2);
}

// Save Data
void EmergencySystem::saveData()
{
    fileManager.saveHospitals(hospitals);
    fileManager.saveAmbulances(ambulances);
    fileManager.saveEmergencies(emergencies);
}

// Load Data
void EmergencySystem::loadData()
{
    fileManager.loadHospitals(hospitals);
    fileManager.loadAmbulances(ambulances);
    fileManager.loadEmergencies(emergencies);
}

void EmergencySystem::showHospitals() const
{
    if (hospitals.empty())
    {
        std::cout << "\nNo hospitals available.\n";
        return;
    }

    std::cout << "\n========== Hospitals ==========\n";

    for (const auto &hospital : hospitals)
    {
        hospital.displayInfo();
    }
}

void EmergencySystem::showAmbulances() const
{
    if (ambulances.empty())
    {
        std::cout << "\nNo ambulances available.\n";
        return;
    }

    std::cout << "\n========== Ambulances ==========\n";

    for (const auto &ambulance : ambulances)
    {
        ambulance.displayInfo();
    }
}

void EmergencySystem::registerEmergency()
{
    int patientId = emergencies.size() + 1;
    int emergencyId = emergencies.size() + 1;

    std::string name;
    std::string phone;
    int location;
    int severity;

    std::cout << "\n========== Register Emergency ==========\n";

    std::cout << "Patient Name : ";
    std::getline(std::cin >> std::ws, name);

    std::cout << "Phone Number : ";
    std::getline(std::cin, phone);

    std::cout << "Location Node : ";
    std::cin >> location;

    std::cout << "Severity (1-5) : ";
    std::cin >> severity;

    Patient patient(
        patientId,
        name,
        location,
        severity,
        phone
    );

    Emergency emergency(
        emergencyId,
        patient,
        severity,
        "Pending"
    );

    emergencies.push_back(emergency);

    std::cout << "\nEmergency Registered Successfully!\n";
    std::cout << "Emergency ID : " << emergencyId << '\n';
}