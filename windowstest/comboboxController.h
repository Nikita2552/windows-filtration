#pragma once
#include "interfaceController.h"
#include "interfaceWidget.h"
#include "comboboxModel.h"
class comboboxController :
    public interfaceController, public interfaceWidget
{
public:
	comboboxController(comboboxModel* model);
	~comboboxController();

	void startTest();

private:
	comboboxModel* _model;
};

