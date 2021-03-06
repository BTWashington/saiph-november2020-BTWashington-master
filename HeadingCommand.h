#pragma once
#include "BaseCommand.h"
#include "MotherShip.h"


class HeadingCommand : BaseCommand
{
private:
	float _heading;
public:
	// Accessor
	float GetHeading() { return _heading; }
	// Mutator
	void SetHeading(float heading) { _heading = heading; }

	// Override on the execute method
	void ExecuteTimeDelay(float _delta) {  };
};

