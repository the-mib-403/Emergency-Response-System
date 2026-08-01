#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include <string>

#include "Hospital.h"
#include "Emergency.h"

class FileManager
{
public:
    // Hospital
    void saveHospitals(const std::vector<Hospital>& hospitals) const;
    void loadHospitals(std::vector<Hospital>& hospitals) const;

    // Emergency
    void saveEmergencies(const std::vector<Emergency>& emergencies) const;
    void loadEmergencies(std::vector<Emergency>& emergencies) const;
};

#endif