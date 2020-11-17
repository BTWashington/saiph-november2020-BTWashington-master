#pragma once

#include "Ship.h"



class MotherShip :
    public Ship
{
    // Constructor -> Overloaded
    MotherShip(const Ship&):Ship:: {}
    ~MotherShip() {};
    // Vector of ship pointers to the MotherShip class
    std::vector<Ship*> MotherFleet;

public:
    // Public method for adding a passed in "shadow"(ship) pointer to this container

    void AddingShipToMotherFleet(Ship* shadow) 
    {
        MotherFleet.push_back(shadow);
    };

    void Heartbeat(float _delta);

};

