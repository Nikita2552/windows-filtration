#pragma once
#include "interfaceObserver.h"
#include <vector>

using namespace std;

class interfaceObservable
{
public:
	void addObserver(interfaceObserver* observer);
	void removeObserver(unsigned int i);
	void notifyUpdate();
public:
	vector<interfaceObserver*> _observers;
};

