#include "interfaceFactoryMethod.h"

interfaceFactoryProduct::~interfaceFactoryProduct()
{

}

interfaceFactoryCreator::~interfaceFactoryCreator()
{

}

float interfaceFactoryCreator::creatorTestOperation()
{
	interfaceFactoryProduct* prod = this->factoryMethod();
	vector<float> vec = prod->testOperation();

	float ret = 0;
	int i = 0;
	while (i < vec.size())
	{
		ret += vec[i];
		i++;
	}
	
	return ret;
}