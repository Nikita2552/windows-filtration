#pragma once
template<typename T>
class exampleEvent;
template<typename T>
class exampleEventQueue;

template<typename T>
class exampleEventQueue
{
public:
    exampleEventQueue(unsigned int size = 10);
    ~exampleEventQueue();

    unsigned int getSize();
    unsigned int getNum();

    void setEvent(T* event);
    T* getEvent();

    void clear();

private:
    unsigned int quSize;
    unsigned int quNum;
    exampleEvent<T>* head;
    exampleEvent<T>* tail;
};

template<typename T>
class exampleEvent
{
public:
    exampleEvent(T* data = nullptr);
    ~exampleEvent();

    exampleEvent<T>* getNext();
    void setNext(exampleEvent<T>* next);

    exampleEvent<T>* getPrev();
    void setPrev(exampleEvent<T>* prev);

    T* getData();

private:
    T* daEvent;
    exampleEvent<T>* nextEvent;
    exampleEvent<T>* prevEvent;
};

template<typename T>
exampleEventQueue<T>::exampleEventQueue(unsigned int size) : quSize(size), quNum(0)
{
    tail = new exampleEvent<T>();
    head = new exampleEvent<T>();
    head->setNext(tail);
    tail->setPrev(head);
}

template<typename T>
exampleEventQueue<T>::~exampleEventQueue()
{
    clear();
    delete head;
    delete tail;
}

template<typename T>
unsigned int exampleEventQueue<T>::getSize()
{
    return quSize;
}

template<typename T>
unsigned int exampleEventQueue<T>::getNum()
{
    return quNum;
}

template<typename T>
void exampleEventQueue<T>::setEvent(T* event)
{
    if (quNum < quSize)
    {
        exampleEvent<T>* eEvent = new exampleEvent<T>(event);
        exampleEvent<T>* nextEvent = head->getNext();

        eEvent->setNext(nextEvent);
        nextEvent->setPrev(eEvent);

        head->setNext(eEvent);
        eEvent->setPrev(head);

        quNum++;
    }
}

template<typename T>
T* exampleEventQueue<T>::getEvent()
{
    if (quNum > 0)
    {
        exampleEvent<T>* eEvent = tail->getPrev();
        exampleEvent<T>* prevEvent = eEvent->getPrev();

        prevEvent->setNext(tail);
        tail->setPrev(prevEvent);

        eEvent->setNext(nullptr);
        eEvent->setPrev(nullptr);

        T* data = eEvent->getData();
        delete eEvent;
        quNum--;

        return data;
    }

    return new T();
}

template<typename T>
void exampleEventQueue<T>::clear()
{
    while (head->getNext()->getNext() != nullptr)
    {
        getEvent();
    }
}

template<typename T>
exampleEvent<T>::exampleEvent(T* data) : daEvent(data)
{

}

template<typename T>
exampleEvent<T>::~exampleEvent()
{
    delete daEvent;
}

template<typename T>
exampleEvent<T>* exampleEvent<T>::getNext()
{
    return nextEvent;
}

template<typename T>
void exampleEvent<T>::setNext(exampleEvent<T>* next)
{
    nextEvent = next;
}

template<typename T>
exampleEvent<T>* exampleEvent<T>::getPrev()
{
    return prevEvent;
}

template<typename T>
void exampleEvent<T>::setPrev(exampleEvent<T>* prev)
{
    prevEvent = prev;
}

template<typename T>
T* exampleEvent<T>::getData()
{
    return daEvent;
}

