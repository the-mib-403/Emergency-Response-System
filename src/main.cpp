#include <iostream>
#include "../include/Patient.h"

int main()
{
    Patient patient(
        101,
        "John Doe",
        2,
        5,
        "01712345678"
    );

    patient.displayInfo();

    return 0;
}