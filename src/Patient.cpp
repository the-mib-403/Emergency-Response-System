#include "../include/Patient.h"
#include <iostream>

// Default Constructor
Patient::Patient()
{
    patientId = 0;
    name = "";
    location = 0;
    severity = 1;
    phone = "";
}

// Parameterized Constructor
Patient::Patient(
    int patientId,
    const std::string& name,
    int location,
    int severity,
    const std::string& phone
)
{
    this->patientId = patientId;
    this->name = name;
    this->location = location;
    this->severity = severity;
    this->phone = phone;
}

// Getters
int Patient::getPatientId() const
{
    return patientId;
}

const std::string& Patient::getName() const
{
    return name;
}

int Patient::getLocation() const
{
    return location;
}

int Patient::getSeverity() const
{
    return severity;
}

const std::string& Patient::getPhone() const
{
    return phone;
}

// Setters
void Patient::setPatientId(int patientId)
{
    this->patientId = patientId;
}

void Patient::setName(const std::string& name)
{
    this->name = name;
}

void Patient::setLocation(int location)
{
    this->location = location;
}

void Patient::setSeverity(int severity)
{
    this->severity = severity;
}

void Patient::setPhone(const std::string& phone)
{
    this->phone = phone;
}

// Display Information
void Patient::displayInfo() const
{
    std::cout << "\n----- Patient Information -----\n";
    std::cout << "ID       : " << patientId << '\n';
    std::cout << "Name     : " << name << '\n';
    std::cout << "Location : " << location << '\n';
    std::cout << "Severity : " << severity << '\n';
    std::cout << "Phone    : " << phone << '\n';
}