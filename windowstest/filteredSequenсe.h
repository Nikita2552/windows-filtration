#pragma once
#include "interfaceDecorator.h"
#include "interfaceFactoryMethod.h"
#include "dataSequen�e.h"
#include <vector>

using namespace std;

class filteredSequence :
    public interfaceDecorator, interfaceFactoryProduct
{
public:
    filteredSequence(dataSequen�e* vec);
    ~filteredSequence();

    vector<float> getDataSequence();    
    vector<float> testOperation();

private:
    dataSequen�e* _vec;
};

