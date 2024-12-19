#pragma once
#include "interfaceDecorator.h"
#include "interfaceFactoryMethod.h"
#include <vector>

using namespace std;

class dataSequenñe :
    public interfaceDecorator, interfaceFactoryCreator
{
public:
    dataSequenñe(vector<float> vec);
    ~dataSequenñe();

    vector<float> getDataSequence();

private:
    vector<float> _vec;
};

