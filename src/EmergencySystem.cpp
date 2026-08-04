#include "../include/EmergencySystem.h"

#include <iostream>

// Constructor
EmergencySystem::EmergencySystem()
{
}

void EmergencySystem::initialize()
{
    loadData();

    cityGraph = Graph(6);

    cityGraph.addEdge(0, 1, 5);
    cityGraph.addEdge(0, 2, 8);
    cityGraph.addEdge(1, 3, 4);
    cityGraph.addEdge(2, 3, 6);
    cityGraph.addEdge(2, 4, 3);
    cityGraph.addEdge(3, 5, 7);
    cityGraph.addEdge(4, 5, 2);
}

void EmergencySystem::saveData()
{
    fileManager.saveHospitals(hospitals);
    fileManager.saveAmbulances(ambulances);
    fileManager.saveEmergencies(emergencies);
}

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

    std::cout << "\n========== Available Locations ==========\n";
    std::cout << "0. Mirpur\n";
    std::cout << "1. Dhanmondi\n";
    std::cout << "2. Uttara (Apollo Hospital)\n";
    std::cout << "3. Gulshan\n";
    std::cout << "4. Banani\n";
    std::cout << "5. Motijheel (Square Hospital)\n";

    std::cout << "\nEnter Location : ";
    std::cin >> location;
    while (location < 0 || location > 5)
    {
        std::cout << "Invalid location! Enter again: ";
        std::cin >> location;
    }

    std::cout << "\n========== Severity Levels ==========\n";
    std::cout << "1. Low\n";
    std::cout << "2. Moderate\n";
    std::cout << "3. Serious\n";
    std::cout << "4. Critical\n";
    std::cout << "5. Life Threatening\n";

    std::cout << "\nEnter Severity : ";
    std::cin >> severity;
    while (severity < 1 || severity > 5)
    {
        std::cout << "Invalid severity! Enter again: ";
        std::cin >> severity;
    }

    Patient patient(
        patientId,
        name,
        location,
        severity,
        phone);

    Emergency emergency(
        emergencyId,
        patient,
        severity,
        "Pending");

    emergencies.push_back(emergency);
    saveData();
    std::cout << "\nEmergency Registered Successfully!\n";
    std::cout << "Emergency ID : " << emergencyId << '\n';
}

void EmergencySystem::showEmergencies() const
{
    if (emergencies.empty())
    {
        std::cout << "\nNo emergency requests found.\n";
        return;
    }

    std::cout << "\n========== Emergency List ==========\n";

    for (const auto &emergency : emergencies)
    {
        emergency.displayInfo();
    }
}