#include <iostream> // Basic output/input stream
#include <numeric> // Used in dataValidation function
#include "chainlink.h" // Link class header
#include "chains.h" // SubChain class header

// g++ -std=c++11 -o main main.cpp chainlink.cpp chains.cpp

// Function to validate input 
// Template to allow the input of different data types
template<typename T>
double dataValidate(T& val) {
    while(std::cin.fail()) {
        
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid Input, please try again: ";
        std::cin >> val;

    } return val;
} 

int main() {

    auto linkInput = 0; // Used to store link input from user
    auto lengthInput = 0.0; // Used to store length from user
    auto angleInput = 0.0; // Used to store angle input from user

    project::SubChain mainChain; // Object creation f

    std::cout << "Enter the number of links: ";// User input for links
    std::cin >> linkInput;
    dataValidate(linkInput);

    // For loop, iterates through each link
    for (int i = 0; i < linkInput; i++) {
        
        std::cout << "Enter length and angle (in degrees) for link " << (i + 1) << ". Length: ";
        std::cin >> lengthInput;
        dataValidate(lengthInput);
        std::cout << "Angle: ";
        std::cin >> angleInput;
        dataValidate(angleInput);

        mainChain.appendChain(lengthInput, angleInput);
    }

    mainChain.startCalculation(); // Calculations for each link

    printChainDetails(mainChain);   // Output for each link

    // Test chain deletion
    mainChain.deleteChain();

    return 0;
}


