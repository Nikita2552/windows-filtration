#pragma once

template<typename T>
class interfaceHandler
{
public:
	virtual interfaceHandler* setNext(interfaceHandler* next) = 0;
	virtual T Handle(T request) = 0;
};

template<typename T>
class interfaceChainOfCommand :
	public interfaceHandler<T>  
{
public:
	interfaceHandler<T>* setNext(interfaceHandler<T>* next);
	T Handle(T request);	

private:
	interfaceHandler<T>* nextHandler;
};

template<typename T>
interfaceHandler<T>* interfaceChainOfCommand<T>::setNext(interfaceHandler<T>* next)
{
	nextHandler = next;
}

template<typename T>
T interfaceChainOfCommand<T>::Handle(T request)
{
	if (this->nextHandler)
	{
		return this->nextHandler->Handle(request);
	}
	return {};
}