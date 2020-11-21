#pragma once

enum ObservedAction {
	ACTIVATE,
	SUBJECT_DEATH
};
class Observer
{
public:
	virtual void Notification(ObservedAction ObserverEvent) = 0;

};

