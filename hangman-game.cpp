#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    // Initialize array of possible answers
    std::string names[13] = {"Squat", "Dinner", "Laser", "Button",
                             "Explorer", "Empty", "Assist", "Number",
                             "Sunny", "Ranger", "Messy", "Nujabes", "Pointer"};

    // Initialize random seed for the rand function:
    // The random seed is initialized to a value
    // representing the current time (calling time)
    // to generate a different value every time the program is run.
    srand(time(NULL));

    // Generate random seed
    int randomIndex = std::rand() % 13;

    // Console output
    std::cout << names[randomIndex] << std::endl;

    return 0;
}