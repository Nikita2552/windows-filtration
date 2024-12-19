#include "buttonController.h"

buttonController::buttonController(buttonModel* model)
{
	_model = model;
}

buttonController::~buttonController()
{

}

void buttonController::startTest()
{
	vector<float> testv
		{ 
			randomfromint(0, 100),
			randomfromint(0, 100),
			randomfromint(0, 100)
		};
	
	_model->setTestData(testv);
}

float randomfromint(int start, int end)
{
	return (float) (rand() % (end - start + 1) + start);
}
