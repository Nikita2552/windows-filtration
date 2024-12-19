#pragma once
#include  "buttonView.h"
#include "globals.h"
#include "framework.h"
#include <vector>

using namespace std;

class interfaceFactoryProduct
{
public:
	virtual  ~interfaceFactoryProduct();
	virtual vector<float> testOperation() = 0;

};

class interfaceFactoryCreator
{
public:
	virtual ~interfaceFactoryCreator();
	virtual interfaceFactoryProduct* factoryMethod() = 0;

	float creatorTestOperation();
};



