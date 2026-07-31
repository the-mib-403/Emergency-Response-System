#include <iostream>
#include "../include/Patient.h"
#include "../include/Ambulance.h"

int main()
{
    Patient patient(
        101,
        "John Doe",
        2,
        5,
        "01712345678"
    );

    Ambulance ambulance(
        1,
        101,
        2,
        true
    );

    patient.displayInfo();
    ambulance.displayInfo();

    return 0;
}