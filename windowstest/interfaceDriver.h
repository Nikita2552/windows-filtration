#pragma once
#include "interfaceSubclassSandbox.h"
#include <vector>

using namespace std;

class interfaceDriver :
	public interfaceSubclassSandbox
{
public:
	interfaceDriver();
	~interfaceDriver();

	virtual vector<float> getAll(); 
};

