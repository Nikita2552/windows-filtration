#pragma once
#include "interfaceDecorator.h"
#include "interfaceFactoryMethod.h"
#include "dataSequenñe.h"
#include <vector>

using namespace std;

class filteredSequence :
    public interfaceDecorator, interfaceFactoryProduct
{
public:
    filteredSequence(dataSequenñe* vec);
    ~filteredSequence();

    vector<float> getDataSequence();    
    vector<float> testOperation();

private:
    dataSequenñe* _vec;
};

