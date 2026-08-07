#ifndef AMBULANCE_H
#define AMBULANCE_H

class Ambulance
{
private:
    int ambulanceId;
    int hospitalId;
    int currentNode;
    bool available;

    int assignedEmergencyId;

public:
    // Constructors
    Ambulance();

    Ambulance(
        int ambulanceId,
        int hospitalId,
        int currentNode,
        bool available,
        int assignedEmergencyId = 0);

    // Getters
    int getAmbulanceId() const;
    int getHospitalId() const;
    int getCurrentNode() const;
    bool isAvailable() const;
    int getAssignedEmergencyId() const;

    // Setters
    void setAmbulanceId(int ambulanceId);
    void setHospitalId(int hospitalId);
    void setCurrentNode(int currentNode);
    void setAvailable(bool available);
    void setAssignedEmergencyId(int assignedEmergencyId);
    // Display
    void displayInfo() const;
};

#endif