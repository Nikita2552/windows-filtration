#pragma once

//Ќаивный одиночка - потоково-небезопасный
class exampleSingleton
{
protected:
	exampleSingleton();
	static exampleSingleton *singleton_;

public:
	exampleSingleton(exampleSingleton& other) = delete;
	void operator=(const exampleSingleton&) = delete;
	static exampleSingleton* GetInstance();
};
