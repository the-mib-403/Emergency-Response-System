#include "../include/Ambulance.h"
#include <iostream>

// Default Constructor
Ambulance::Ambulance()
    : ambulanceId(0),
      hospitalId(0),
      currentNode(0),
      available(true)
{
}

// Parameterized Constructor
Ambulance::Ambulance(
    int ambulanceId,
    int hospitalId,
    int currentNode,
    bool available
)
    : ambulanceId(ambulanceId),
      hospitalId(hospitalId),
      currentNode(currentNode),
      available(available)
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

// Display
void Ambulance::displayInfo() const
{
    std::cout << "\n----- Ambulance Information -----\n";
    std::cout << "Ambulance ID : " << ambulanceId << '\n';
    std::cout << "Hospital ID  : " << hospitalId << '\n';
    std::cout << "Current Node : " << currentNode << '\n';
    std::cout << "Status       : "
              << (available ? "Available" : "Busy") << '\n';
}