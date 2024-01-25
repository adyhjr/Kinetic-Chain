/**
 * @file chainlink.h
 * @brief Base class containing attributes of simulated chain link
 * @author Adolfo Hernandez
 * @date 2023-11-19
 */
// Header guards -- CHAINLINK_H is the unique identifier
#ifndef CHAINLINK_H
#define CHAINLINK_H

// Project namespace declared to encapsulate Link class
namespace project
{

    class Link
    {
    private:

        const double _linkLength; // Private base class member for link length
        const double _linkAngle; // Private base class member for link angle
        Link* _nextLink; // Private base class pointer 

    public:

    // Constructor for Link base class, defined in chainlink.cpp
        Link(const double length, const double angle);
    
    // Function returns _nextlink
        Link* getNextLink() const;

    // Functions sets memory of _nextLink to next
        void setNextLink(Link* next);

    double getLinkLength() const { return _linkLength; }
    
    double getLinkAngle () const { return _linkAngle; }

    };



}; // End of project namespace


// End of header gaurd
#endif //CHAINLINK_H
