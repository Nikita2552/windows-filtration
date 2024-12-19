#pragma once
#include "interfaceObservable.h"
#include "interfaceWidget.h"
#include "interfaceModel.h"
#include <vector>

using namespace std;

class buttonModel :
    public interfaceObservable, public interfaceWidget, public interfaceModel
{
public:
    vector<float> getTestData();
    void setTestData(vector<float> data);

private:
    vector<float> buttonData;
};

