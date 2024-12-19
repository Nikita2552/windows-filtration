#pragma once
#include "interfaceController.h"
#include "interfaceWidget.h"
#include "listboxModel.h"
class listboxController :
    public interfaceController, public interfaceWidget
{
public:
	listboxController(listboxModel* model);
	~listboxController();

	void startTest();

private:
	listboxModel* _model;
};

