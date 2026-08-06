#include "../include/EmergencySystem.h"

#include <iostream>
#include <limits>

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

Hospital *EmergencySystem::findNearestHospital(int patientLocation)
{
    if (hospitals.empty())
    {
        return nullptr;
    }

    std::vector<int> distance = cityGraph.dijkstra(patientLocation);

    Hospital *nearestHospital = nullptr;
    int minimumDistance = std::numeric_limits<int>::max();

    for (auto &hospital : hospitals)
    {
        int hospitalNode = hospital.getLocationNode();

        if (distance[hospitalNode] < minimumDistance)
        {
            minimumDistance = distance[hospitalNode];
            nearestHospital = &hospital;
        }
    }

    return nearestHospital;
}

Ambulance *EmergencySystem::findAvailableAmbulance(int hospitalId)
{
    for (auto &ambulance : ambulances)
    {
        if (ambulance.getHospitalId() == hospitalId &&
            ambulance.isAvailable())
        {
            return &ambulance;
        }
    }

    return nullptr;
}

void EmergencySystem::dispatchAmbulance()
{
    if (emergencies.empty())
    {
        std::cout << "\nNo emergency requests available.\n";
        return;
    }

    int emergencyId;

    std::cout << "\n========== Dispatch Ambulance ==========\n";
    std::cout << "Enter Emergency ID : ";
    std::cin >> emergencyId;

    Emergency *selectedEmergency = nullptr;

    for (auto &emergency : emergencies)
    {
        if (emergency.getEmergencyId() == emergencyId)
        {
            selectedEmergency = &emergency;
            break;
        }
    }

    if (selectedEmergency == nullptr)
    {
        std::cout << "\nEmergency not found.\n";
        return;
    }

    if (selectedEmergency->getStatus() == "Assigned")
    {
        std::cout << "\nThis emergency has already been assigned.\n";
        return;
    }

    int patientLocation =
        selectedEmergency->getPatient().getLocation();

    Hospital *hospital =
        findNearestHospital(patientLocation);

    if (hospital == nullptr)
    {
        std::cout << "\nNo hospital found.\n";
        return;
    }

    std::cout << "\nNearest Hospital Found\n";
    hospital->displayInfo();

    Ambulance *ambulance =
        findAvailableAmbulance(
            hospital->getHospitalId());

    if (ambulance == nullptr)
    {
        std::cout << "\nNo available ambulance found.\n";
        return;
    }

    std::cout << "\nAvailable Ambulance Found\n";
    ambulance->displayInfo();

    ambulance->setAvailable(false);

    selectedEmergency->setStatus("Assigned");

    saveData();

    std::cout << "\n========== Dispatch Summary ==========\n";

    std::cout << "Emergency ID     : "
              << selectedEmergency->getEmergencyId() << '\n';

    std::cout << "Patient Name     : "
              << selectedEmergency->getPatient().getName() << '\n';

    std::cout << "Patient Location : "
              << selectedEmergency->getPatient().getLocation() << '\n';

    std::cout << "Hospital         : "
              << hospital->getName() << '\n';

    std::cout << "Ambulance ID     : "
              << ambulance->getAmbulanceId() << '\n';

    std::cout << "Emergency Status : "
              << selectedEmergency->getStatus() << '\n';

    std::cout << "Ambulance Status : Busy\n";

    std::cout << "\nDispatch Completed Successfully!\n";
}

void EmergencySystem::run()
{
    int choice;

    do
    {
        std::cout << "\n=====================================\n";
        std::cout << "     EMERGENCY RESPONSE SYSTEM\n";
        std::cout << "=====================================\n";

        std::cout << "1. Register Emergency\n";
        std::cout << "2. Show Emergencies\n";
        std::cout << "3. Show Hospitals\n";
        std::cout << "4. Show Ambulances\n";
        std::cout << "5. Dispatch Ambulance\n";
        std::cout << "6. Exit\n";

        std::cout << "\nEnter Choice : ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            registerEmergency();
            break;

        case 2:
            showEmergencies();
            break;

        case 3:
            showHospitals();
            break;

        case 4:
            showAmbulances();
            break;

        case 5:
            dispatchAmbulance();
            break;

        case 6:
            saveData();
            std::cout << "\nSaving data...\n";
            std::cout << "Thank you for using the system.\n";
            break;

        default:
            std::cout << "\nInvalid choice! Please try again.\n";
        }

        if (choice != 6)
        {
            std::cout << "\nPress Enter to continue...";
            std::cin.ignore();
            std::cin.get();
        }

    } while (choice != 6);
}