/**
 * @file chainlink.cpp
 * @brief Definitions of content conatained in chainlink header file
 * @author Adolfo Hernandez
 * @date 2023-11-19
 */
#include "chainlink.h" // Chainlink header dependency

namespace project 
{
    /**
     * @brief Constructor for Link class, values initalize member variables
     * @param length: User input length.
     * @param angle: User input angle.
    */
    Link::Link(const double length, const double angle) :
        _linkLength{ length }, 
        _linkAngle{ angle }, 
        _nextLink(nullptr) {}

    /**
     * @brief Gets next chain in simulation, this is returned as nullptr if no address exists for the chain, meaning you are at the origin. 
     * @return Link* Points to the next link 
    */
    Link* Link::getNextLink() const
        {
            return _nextLink;
        }

    /**
     * @brief Sets new link to chain.
     * @param next: Is a new pointer correlated with a new link.
    */
    void Link::setNextLink(Link* next)
        {
            _nextLink = next;
        }

    ///I ENDED HERE 
} // End of project namespace