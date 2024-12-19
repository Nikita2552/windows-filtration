#pragma once
#include <vector>

using namespace std;

class interfaceSubclassSandbox
{
public:
	virtual vector<float> getAll() = 0; //ќбъ€вл€ем метод, через который будут вызыватьс€ другие методы класса в определЄнной последовательности
};

