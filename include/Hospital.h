#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <string>

class Hospital
{
private:
    int hospitalId;
    std::string name;
    int locationNode;

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

    // Setters
    void setHospitalId(int hospitalId);
    void setName(const std::string& name);
    void setLocationNode(int locationNode);

    // Display
    void displayInfo() const;
};

#endif