#include "buttonModel.h"

vector<float> buttonModel::getTestData()
{
	return buttonData;
}
	
void buttonModel::setTestData(vector<float> data)
{
	buttonData.clear();
	for (auto iter = data.begin(); iter < data.end(); iter++)
	{
		buttonData.push_back(*iter);
	}
	notifyUpdate();
}
