
/**
 * @file chains.h
 * @brief Header file containng SubChain class
 * @author Adolfo Hernandez
 * @date 2023-11-19
 */

#include "chainlink.h" // Link class dependency

// Start of headers guards
#ifndef CHAINS_H
#define CHAINS_H 

#include <vector> // Contains vector container used for storing coordinates
#include <utility> // Used for using values in vector as pairs
#include <iostream> // Basic input/output functionality

// Subchain class encapsulated with project namespace
namespace project 
{
    const double cBaseAngleAndPosition = 0.0; // Constant to denote base angle and origin coordinates
    const double cStraightAngle = 180.0; // Constant to denote the angle of a straight line -- 180 degrees

/**
 * @class Subchain
 * @brief Contains functionality for each link
*/
    class SubChain 
    {
        private:

        Link* _originChain; // Points to the first link in the chain.

        std::vector<std::pair<double, double>> _chainPosition; // Contains paired positions of links 

        /**
         * @brief Calculates positions of links in chain
         * @param _memoryLocation: Address where the link is starting
         * @param x: X coordinate
         * @param y: Y coordinate
         * @param _totalAngle: The total angle of the following link
        */
        void calculatePositions(Link* _memoryLocation, double x, double y, double _totalAngle);

        public:
        /**
         * 
         * @brief Construtor, defined in chains.cpp -- intializes _originChain with nullptr memory addresss
         */
        SubChain();

        /**
         * @brief Provides accesss of private members of SubChain class
        */
        friend void printChainDetails(const SubChain& chain);

        /*
        * @brief appends a link with length and angle
        * @param length: User length
        * @param angle: User angle
        */
        void appendChain(double length, double angle);

        /**
         * @brief deletion of created memory 
        */
        void deleteChain();

        /**
         * @brief calculations for each link
        */
        void startCalculation();        
    };
}
// End of project namespace
#endif //CHAINS_H   