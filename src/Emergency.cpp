#include "../include/Emergency.h"
#include <iostream>

// Default Constructor
Emergency::Emergency()
    : emergencyId(0),
      priority(0),
      status("Pending")
{
}

// Parameterized Constructor
Emergency::Emergency(
    int emergencyId,
    const Patient& patient,
    int priority,
    const std::string& status
)
    : emergencyId(emergencyId),
      patient(patient),
      priority(priority),
      status(status)
{
}

// Getters
int Emergency::getEmergencyId() const
{
    return emergencyId;
}

const Patient& Emergency::getPatient() const
{
    return patient;
}

int Emergency::getPriority() const
{
    return priority;
}

const std::string& Emergency::getStatus() const
{
    return status;
}

// Setters
void Emergency::setEmergencyId(int emergencyId)
{
    this->emergencyId = emergencyId;
}

void Emergency::setPatient(const Patient& patient)
{
    this->patient = patient;
}

void Emergency::setPriority(int priority)
{
    this->priority = priority;
}

void Emergency::setStatus(const std::string& status)
{
    this->status = status;
}

// Display
void Emergency::displayInfo() const
{
    std::cout << "\n===== Emergency Information =====\n";
    std::cout << "Emergency ID : " << emergencyId << '\n';

    patient.displayInfo();

    std::cout << "\nPriority     : " << priority << '\n';
    std::cout << "Status       : " << status << '\n';
}