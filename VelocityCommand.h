#pragma once
#include "BaseCommand.h"
class VelocityCommand :
    public BaseCommand
{
private:
    float _lowVelocity;    
    float _highVelocity;
public:
    // Accessors
    float GetLowVelocity() { return _lowVelocity; }    
    float GetHighVelocity() { return _highVelocity; }

    // Mutators
    void SetLowVelocity(float lowVel) { _lowVelocity = lowVel; }    
    void SetHighVelocity(float highVel) { _highVelocity = highVel; }

    // Override Virtual ExecuteTimeDelay
    void ExecuteTimeDelay(float _delta) {  };
    
};

