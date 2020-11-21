#pragma once
#include<list>
#include"Observer.h"

class Subject
{
	std::list<Observer*> observers;
public:
	virtual ~Subject() = 0;
	void Attach(Observer* addingTo) { observers.push_front(addingTo); };
	void Detach(Observer* takingAway) { observers.pop_back(); };
	void NotifyObservers(ObservedAction ObservedEvent);

	void Clear();
};

