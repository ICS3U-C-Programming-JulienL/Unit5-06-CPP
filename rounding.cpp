// Copyright (c) 2023 Julien Lamoureux All rights reserved.

// Created By: Julien Lamoureux
// Date: December 6, 2023
// This program rounds your number to the desired decimal places

#include <iostream>
#include <cmath>

void roundDecimal(float &decNumValueFloat, int numPlacesInt) {
    // multiply decNum by 10^numPlacesInt, and add 0.5
    decNumValueFloat = (decNumValueFloat * pow(10, numPlacesInt)) + 0.5;

    // convert decNum to an int
    decNumValueFloat = floor(decNumValueFloat);

    // divide decNum by 10^numPlacesInt
    decNumValueFloat = decNumValueFloat / pow(10, numPlacesInt);
}

int main() {
    // declare variables
    std::string decNumValue, numPlacesStr;
    int numPlacesInt;
    float decNumValueFloat;

    // get decimal number
    std ::cout << "Enter your decimal number:" << std::endl;
    std::cin >> decNumValue;

    // get the desired number of places to be rounded to
    std ::cout << "How many decimal places do you want it rounded to:"
    << std::endl;
    std::cin >> numPlacesStr;

    // if decNumValue is a float then...
    try {
        // convert decNumValue to a float
        decNumValueFloat = std::stof(decNumValue);
          try {
              // convert numPlacesStr to an it
              numPlacesInt = std::stoi(numPlacesStr);

              // call the round decimal function
              roundDecimal(decNumValueFloat, numPlacesInt);

              // display the rounded decimal
              std::cout << "Your rounded answer is "
              << decNumValueFloat << std::endl;
          } catch (std::invalid_argument) {
              // if numPlaces cannot become an int, tell them to enter one
              std::cout << numPlacesStr <<
              "is not a valid integer" << std::endl;
          }
    } catch (std::invalid_argument) {
        // if decNumValue cannot become an int, tell the user to enter one
        std::cout << decNumValue <<
        " is not a valid decimal number " << std::endl;
    }
}

