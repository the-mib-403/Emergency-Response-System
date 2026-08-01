#include <iostream>
#include <vector>

#include "../include/FileManager.h"

int main()
{
    std::vector<Hospital> hospitals;

    hospitals.push_back(
        Hospital(
            1,
            "Apollo",
            2
        )
    );

    hospitals.push_back(
        Hospital(
            2,
            "Square",
            5
        )
    );

    FileManager fileManager;

    fileManager.saveHospitals(hospitals);

    std::cout << "Hospitals saved successfully.\n";

    return 0;
}