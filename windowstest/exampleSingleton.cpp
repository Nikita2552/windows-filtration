#include "exampleSingleton.h"

exampleSingleton* exampleSingleton::singleton_ = nullptr;

exampleSingleton::exampleSingleton()
{

}

exampleSingleton* exampleSingleton::GetInstance()
{
    if (singleton_ == nullptr)
    {
        singleton_ = new exampleSingleton();
    }

    return singleton_;
}