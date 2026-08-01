#ifndef EMERGENCY_H
#define EMERGENCY_H

#include <string>

#include "Patient.h"

class Emergency
{
private:
    int emergencyId;
    Patient patient;
    int priority;
    std::string status;

public:
    // Constructors
    Emergency();

    Emergency(
        int emergencyId,
        const Patient& patient,
        int priority,
        const std::string& status
    );

    // Getters
    int getEmergencyId() const;
    const Patient& getPatient() const;
    int getPriority() const;
    const std::string& getStatus() const;

    // Setters
    void setEmergencyId(int emergencyId);
    void setPatient(const Patient& patient);
    void setPriority(int priority);
    void setStatus(const std::string& status);

    // Display
    void displayInfo() const;
};

#endif