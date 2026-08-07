#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include <string>

#include "Hospital.h"
#include "Ambulance.h"
#include "Emergency.h"

class FileManager
{
public:
    // Hospital
    void saveHospitals(const std::vector<Hospital> &hospitals) const;
    void loadHospitals(std::vector<Hospital> &hospitals) const;

    // Ambulance
    void saveAmbulances(const std::vector<Ambulance> &ambulances) const;
    void loadAmbulances(std::vector<Ambulance> &ambulances) const;

    // Emergency
    void saveEmergencies(const std::vector<Emergency> &emergencies) const;
    void loadEmergencies(std::vector<Emergency> &emergencies) const;

    // History
    void saveHistory(
        const Emergency &emergency,
        const Hospital &hospital,
        const Ambulance &ambulance) const;
};

#endif