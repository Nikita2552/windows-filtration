#pragma once
#include "interfaceDecorator.h"
#include "interfaceFactoryMethod.h"
#include <vector>

using namespace std;

class dataSequen�e :
    public interfaceDecorator, interfaceFactoryCreator
{
public:
    dataSequen�e(vector<float> vec);
    ~dataSequen�e();

    vector<float> getDataSequence();

private:
    vector<float> _vec;
};

