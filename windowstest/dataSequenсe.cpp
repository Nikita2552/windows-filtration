#include "dataSequen�e.h"

dataSequen�e::dataSequen�e(vector<float> vec)
{
	_vec = vec;
}

dataSequen�e::~dataSequen�e()
{

}

vector<float> dataSequen�e::getDataSequence()
{
	return _vec;
}
