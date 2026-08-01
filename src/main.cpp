#include <iostream>

#include "../include/Patient.h"
#include "../include/Emergency.h"

int main()
{
    Patient patient(
        101,
        "John Doe",
        2,
        5,
        "01712345678"
    );

    Emergency emergency(
        1,
        patient,
        5,
        "Pending"
    );

    emergency.displayInfo();

    return 0;
}