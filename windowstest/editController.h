#pragma once
#include "interfaceWidget.h"
#include "interfaceController.h"
#include "editModel.h"
class editController :
    public interfaceWidget, public interfaceController
{
public:
	editController(editModel* model);
	~editController();

	void startTest();

private:
	editModel* _model;
};

