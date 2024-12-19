#include "filteredSequenñe.h"

filteredSequence::filteredSequence(dataSequenñe* vec)
{
	_vec = vec;
}

filteredSequence::~filteredSequence()
{
	
}

vector<float> filteredSequence::getDataSequence()
{
	vector <float> ret = _vec->getDataSequence();

	unsigned int i = 0;
	while (i < ret.size())
	{
		ret[i] /= 5;
		i++;
	}

	return ret;
}

vector<float> filteredSequence::testOperation()
{
	return getDataSequence();
}
