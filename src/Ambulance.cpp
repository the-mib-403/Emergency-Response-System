#include "../include/Ambulance.h"
#include <iostream>

// Default Constructor
Ambulance::Ambulance()
    : ambulanceId(0),
      hospitalId(0),
      currentNode(0),
      available(true),
      assignedEmergencyId(0)
{
}

// Parameterized Constructor
Ambulance::Ambulance(
    int ambulanceId,
    int hospitalId,
    int currentNode,
    bool available,
    int assignedEmergencyId
)
    : ambulanceId(ambulanceId),
      hospitalId(hospitalId),
      currentNode(currentNode),
      available(available),
      assignedEmergencyId(assignedEmergencyId)
{
}

// Getters
int Ambulance::getAmbulanceId() const
{
    return ambulanceId;
}

int Ambulance::getHospitalId() const
{
    return hospitalId;
}

int Ambulance::getCurrentNode() const
{
    return currentNode;
}

bool Ambulance::isAvailable() const
{
    return available;
}

int Ambulance::getAssignedEmergencyId() const
{
    return assignedEmergencyId;
}

// Setters
void Ambulance::setAmbulanceId(int ambulanceId)
{
    this->ambulanceId = ambulanceId;
}

void Ambulance::setHospitalId(int hospitalId)
{
    this->hospitalId = hospitalId;
}

void Ambulance::setCurrentNode(int currentNode)
{
    this->currentNode = currentNode;
}

void Ambulance::setAvailable(bool available)
{
    this->available = available;
}

void Ambulance::setAssignedEmergencyId(int assignedEmergencyId)
{
    this->assignedEmergencyId = assignedEmergencyId;
}

// Display
void Ambulance::displayInfo() const
{
    std::cout << "\n----- Ambulance Information -----\n";
    std::cout << "Ambulance ID          : " << ambulanceId << '\n';
    std::cout << "Hospital ID           : " << hospitalId << '\n';
    std::cout << "Current Node          : " << currentNode << '\n';
    std::cout << "Status                : "
              << (available ? "Available" : "Busy") << '\n';
    std::cout << "Assigned Emergency ID : "
              << assignedEmergencyId << '\n';
}