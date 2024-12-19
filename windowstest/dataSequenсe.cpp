#include "dataSequenñe.h"

dataSequenñe::dataSequenñe(vector<float> vec)
{
	_vec = vec;
}

dataSequenñe::~dataSequenñe()
{

}

vector<float> dataSequenñe::getDataSequence()
{
	return _vec;
}
