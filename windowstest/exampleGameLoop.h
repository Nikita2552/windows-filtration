#pragma once
#include "interfaceDriver.h"
#include "EventQueue.h"

class exampleGameLoop
{
public:
	exampleGameLoop();
	~exampleGameLoop();

	void init(); //���������������� �����
	void threadBody();

private:
	void getData();
	void operationsWithData();
	void updateData();
};



