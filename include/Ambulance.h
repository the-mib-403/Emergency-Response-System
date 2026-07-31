#ifndef AMBULANCE_H
#define AMBULANCE_H

class Ambulance
{
private:
    int ambulanceId;
    int hospitalId;
    int currentNode;
    bool available;

public:
    // Constructors
    Ambulance();

    Ambulance(
        int ambulanceId,
        int hospitalId,
        int currentNode,
        bool available
    );

    // Getters
    int getAmbulanceId() const;
    int getHospitalId() const;
    int getCurrentNode() const;
    bool isAvailable() const;

    // Setters
    void setAmbulanceId(int ambulanceId);
    void setHospitalId(int hospitalId);
    void setCurrentNode(int currentNode);
    void setAvailable(bool available);

    // Display
    void displayInfo() const;
};

#endif