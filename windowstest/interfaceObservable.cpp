#include "interfaceObservable.h"

void interfaceObservable::addObserver(interfaceObserver* observer)
{
	_observers.push_back(observer);
}

void interfaceObservable::removeObserver(unsigned int i)
{
    unsigned int size = (unsigned int) _observers.size();
    if (i < size)
    {
        auto iter = _observers.cbegin();
        _observers.erase(iter + i);
    }
}

void interfaceObservable::notifyUpdate()
{
    unsigned int size = (unsigned int) _observers.size();
    for (unsigned int i = 0; i < size; i++)
    {
        _observers[i]->update();
    }
}
