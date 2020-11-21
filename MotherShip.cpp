#include "precompiled_header"
#include "MotherShip.h"
#include "VelocityCommand.h"

void MotherShip::Heartbeat(float _delta)
{
	MotherShip::SetHeading(_delta);
	if (!GetAfterburnerFlag())
		MotherShip::Heartbeat(VelocityCommand::ExecuteTimeDelay(_delta));

	else
		Ship::Heartbeat(_delta);
}

