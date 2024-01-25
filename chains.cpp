/**
 * @file chains.cpp
 * @brief Definitions of functions within SubChain class.
 * @author Adolfo Hernandez
 * @date 2023-11-19
 */
#include "chains.h" //  Subchain header dependency
#include <cmath> // To include trigonometric functionality

// Prototypes for SubChain class encapsulated within namespace
namespace project 
{
/**
 *  @brief SubChain constructor intializing _originChain with a nullptr memory address.
 **/
SubChain::SubChain() : _originChain(nullptr) {}

/** 
 * @brief Function to print the details of the chain
 * @param chain: Refernce to object values used to be printed
 **/
void printChainDetails(const SubChain& chain) {
    if (chain._originChain == nullptr) {
        std::cout << "The chain is empty." << std::endl;
        return;
    }

    const Link* memoryLocation = chain._originChain;
    double x = cBaseAngleAndPosition, y = cBaseAngleAndPosition, totalAngle = cBaseAngleAndPosition; // Variables denoted by constant defined in class header

    for (const auto& coordinate : chain._chainPosition) {
            std::cout << "Link starts at: " << "(" << x << ", " << y << ") "
                      << "With relative angle: " << memoryLocation->getLinkAngle() << " degrees. \n";

                        totalAngle += memoryLocation->getLinkAngle();

            std::cout << "Link ends at: " << "(" << coordinate.first << ", " << coordinate.second << ") " 
                      << "With absolute angle: " << totalAngle <<
            std::endl;

            x = coordinate.first;
            y = coordinate.second; 
            memoryLocation = memoryLocation->getNextLink();  
   
        }   
}

/**
 * @brief Appends new link to complete chain
 * @param length: User input length
 * @param angle: User input length 
*/
void SubChain::appendChain(double length, double angle) 
        {
            Link* newChainLink = new Link(length, angle); // Manuel memory management for chain link. Will need to be deleted. 

            


            if (_originChain == nullptr) // Reference logic to origin link denoted as nullptr in base class
            {
               _originChain = newChainLink;
            } else {
                Link* currentChain = _originChain;
                
                while (currentChain->getNextLink() != nullptr) // Logic to set new chain link memory
                {
                    currentChain = currentChain->getNextLink();
                }
                currentChain->setNextLink(newChainLink); 

            }
        }

/**
 * @brief Calculates positions of links in chain
 * @param _memoryLocation: Address where the link is starting
 * @param x: X coordinate
 * @param y: Y coordinate
 * @param _totalAngle: The total angle of the following link
*/
void SubChain::calculatePositions(Link* _memoryLocation, double x, double y, double _totalAngle) 
        {
        if (_memoryLocation == nullptr) return; // Origin memory position of nullptr
        
        _totalAngle += _memoryLocation->getLinkAngle(); // Accumlation of complete angle
        auto radianAngle = _totalAngle * M_PI / cStraightAngle; // Conversion to radians 

        
        x += _memoryLocation->getLinkLength() * cos(radianAngle); // Calculations for positions
        y += _memoryLocation->getLinkLength() * sin(radianAngle);

        
       _chainPosition.push_back(std::make_pair(x, y)); // Append position to paired vector as coordinates

        
        calculatePositions(_memoryLocation->getNextLink(), x, y, _totalAngle); // Recursive call to itself
        
        }

/** 
 * @brief Used to delete memory that has been created, or in this case each link created.
*/
void SubChain::deleteChain() 
        {
            Link* currentChain = _originChain;

            // While chain is not at its origin nullptr position, manually delete memory
            while (currentChain != nullptr) 
            { 
                Link* next = currentChain->getNextLink();
                delete currentChain;
                currentChain = next;
            }
            _originChain = nullptr; // We reset the chain to its nullptr address
        }      

/**
 * @brief Used to calculate the outputs for each link
*/
void SubChain::startCalculation() {
        _chainPosition.clear();
        if (_originChain != nullptr) {
            calculatePositions(_originChain, cBaseAngleAndPosition, cBaseAngleAndPosition, cBaseAngleAndPosition);  
        } 
}

} //End of project namespace
