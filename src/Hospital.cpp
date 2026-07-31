#include "../include/Hospital.h"
#include <iostream>

// Default Constructor
Hospital::Hospital()
    : hospitalId(0),
      name(""),
      locationNode(0)
{
}

// Parameterized Constructor
Hospital::Hospital(
    int hospitalId,
    const std::string& name,
    int locationNode
)
    : hospitalId(hospitalId),
      name(name),
      locationNode(locationNode)
{
}

// Getters
int Hospital::getHospitalId() const
{
    return hospitalId;
}

const std::string& Hospital::getName() const
{
    return name;
}

int Hospital::getLocationNode() const
{
    return locationNode;
}

const std::vector<Ambulance>& Hospital::getAmbulances() const
{
    return ambulances;
}

// Setters
void Hospital::setHospitalId(int hospitalId)
{
    this->hospitalId = hospitalId;
}

void Hospital::setName(const std::string& name)
{
    this->name = name;
}

void Hospital::setLocationNode(int locationNode)
{
    this->locationNode = locationNode;
}

// Ambulance Management
void Hospital::addAmbulance(const Ambulance& ambulance)
{
    ambulances.push_back(ambulance);
}

// Display
void Hospital::displayInfo() const
{
    std::cout << "\n----- Hospital Information -----\n";
    std::cout << "Hospital ID   : " << hospitalId << '\n';
    std::cout << "Name          : " << name << '\n';
    std::cout << "Location Node : " << locationNode << '\n';
    std::cout << "Ambulances    : " << ambulances.size() << '\n';
}