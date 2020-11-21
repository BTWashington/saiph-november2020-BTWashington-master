#pragma once
#include "Observer.h"
class StickyBomb :
    public Observer
{
    void Notification(ObservedAction ObserverEvent);
};

