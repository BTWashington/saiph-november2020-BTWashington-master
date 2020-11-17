#pragma once
#include "BaseCommand.h"


class HeadingCommand : BaseCommand
{
private:
	float _heading;
public:
	// Accessor
	float GetHeading() { return _heading; }
	// Mutator
	void SetHeading(float heading) { _heading = heading; }

	// override on the execute method
	void ExecuteTimeDelay() { SetHeading(_heading); };
};

