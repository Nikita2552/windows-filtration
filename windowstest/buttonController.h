#pragma once
#include "interfaceController.h"
#include "interfaceWidget.h"
#include "buttonModel.h"
#include "interfaceChainOfCommand.h"

class buttonController:
	public interfaceController, public interfaceWidget    
{
public:
	buttonController(buttonModel* model);
	~buttonController();

	void startTest();

private:
	buttonModel* _model;
};

float randomfromint(int start, int end);

/* Добавление шаблона "цепочка команд" */
template<typename T>
class buttonTempController :
	public buttonController, public interfaceChainOfCommand<T>
{
public:
	buttonTempController(T cri);
	~buttonTempController();

	T Handle(T request);
	void setCriterion(T cri);
	
private:
	T requ;
};

/* Задание критерия */
template<typename T>
buttonTempController<T>::buttonTempController(T cri)
{
	requ = cri;
}

template<typename T>
buttonTempController<T>::~buttonTempController()
{

}

template<typename T>
void buttonTempController<T>::setCriterion(T cri)
{
	requ = cri;
}

/* При вызове, если критерий соответствует запросу, выполняется обработчик.
Иначе - вызывается следующий за ним обработчик от родительского класса */
template<typename T>
T buttonTempController<T>::Handle(T request)
{
	if (requ == request)
	{
		this->startTest();
	}
	else
	{
		interfaceChainOfCommand<T>::Handle(request);
	}
	return{};
}

