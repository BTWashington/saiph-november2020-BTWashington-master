#include "LevelState.h"

class BaseCommand
{
private:
	Ship* _targetShip;
	float _executeDelay;
public:
	// Accessors
	Ship* GetTargetSHip() { return _targetShip; }
	float GetExecuteDelay() { return _executeDelay; }
	
	// Mutators
	void SetTargetShip(Ship* target) { _targetShip = target; }
	void SetExecuteDelay(float executeDelay) { _executeDelay = executeDelay; }

	virtual void ExecuteTimeDelay() = 0 {};

};
