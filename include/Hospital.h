#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <string>
#include <vector>

#include "Ambulance.h"

class Hospital
{
private:
    int hospitalId;
    std::string name;
    int locationNode;
    std::vector<Ambulance> ambulances;

public:
    // Constructors
    Hospital();

    Hospital(
        int hospitalId,
        const std::string& name,
        int locationNode
    );

    // Getters
    int getHospitalId() const;
    const std::string& getName() const;
    int getLocationNode() const;
    const std::vector<Ambulance>& getAmbulances() const;

    // Setters
    void setHospitalId(int hospitalId);
    void setName(const std::string& name);
    void setLocationNode(int locationNode);

    // Ambulance Management
    void addAmbulance(const Ambulance& ambulance);

    // Display
    void displayInfo() const;
};

#endif