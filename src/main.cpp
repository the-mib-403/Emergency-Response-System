#include "../include/EmergencySystem.h"

int main()
{
    EmergencySystem system;

    system.initialize();

    system.showHospitals();
    system.showAmbulances();

    return 0;
}