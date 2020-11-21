#pragma once

#include "Ship.h"
#include "BaseCommand.h"



class MotherShip :
    public Ship
{
    // Constructor -> Overloaded
    MotherShip(const Ship&):Ship:: {}
    // Destructor
    ~MotherShip() {
        ~ViewManager();

    };
    // Assignment Operator

    // Vector of ship pointers to the MotherShip class
    std::vector<Ship*> MotherFleet;
    std::vector<BaseCommand*> BseCmd;

public:
    // Public method for adding a passed in "shadow"(ship) pointer to this container

    void AddingShipToMotherFleet(Ship* shadow) 
    {
        MotherFleet.push_back(shadow);
    };

    // Heatbeat "update" method
    void Heartbeat(float _delta);

};

