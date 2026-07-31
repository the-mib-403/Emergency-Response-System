#include <iostream>

#include "../include/Patient.h"
#include "../include/Ambulance.h"
#include "../include/Hospital.h"

int main()
{
    Patient patient(
        101,
        "John Doe",
        2,
        5,
        "01712345678"
    );

    Ambulance ambulance1(
        1,
        1,
        2,
        true
    );

    Ambulance ambulance2(
        2,
        1,
        2,
        true
    );

    Hospital hospital(
        1,
        "Apollo Hospital",
        2
    );

    hospital.addAmbulance(ambulance1);
    hospital.addAmbulance(ambulance2);

    patient.displayInfo();
    ambulance1.displayInfo();
    hospital.displayInfo();

    return 0;
}