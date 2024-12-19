#pragma once
#include "interfaceController.h"
#include "interfaceWidget.h"
#include "radiobuttonModel.h"
class radiobuttonController :
    public interfaceController, public interfaceWidget
{
public:
	radiobuttonController(radiobuttonModel* model);
	~radiobuttonController();

	void startTest();

private:
	radiobuttonModel* _model;

};

