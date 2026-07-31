#ifndef PATIENT_H
#define PATIENT_H

#include <string>

class Patient
{
private:
    int patientId;
    std::string name;
    int location;
    int severity;
    std::string phone;

public:
    Patient();

    Patient(
        int patientId,
        const std::string& name,
        int location,
        int severity,
        const std::string& phone
    );

    int getPatientId() const;
    const std::string& getName() const;
    int getLocation() const;
    int getSeverity() const;
    const std::string& getPhone() const;

    void setPatientId(int patientId);
    void setName(const std::string& name);
    void setLocation(int location);
    void setSeverity(int severity);
    void setPhone(const std::string& phone);

    void displayInfo() const;
};

#endif