#pragma once
template<typename T>
class Event;
template<typename T>
class EventQueue;

template<typename T>
class EventQueue
{
public:
    ~EventQueue();

    unsigned int getSize();
    unsigned int getNum();

    void setEvent(T* event);
    T* getEvent();

    void clear();

    /* Запретить копирующие конструкторы, чтобы экземпляр класса был только один */
    EventQueue(EventQueue& other) = delete;
    void operator=(const EventQueue&) = delete;
    static EventQueue* GetInstance();

protected:
    EventQueue(unsigned int size = 10);
    static EventQueue* eventqueue_;

private:
    unsigned int quSize;
    unsigned int quNum;
    Event<T>* head;
    Event<T>* tail;

    //Добавление обвязки для паттерна "локализация данных"
    Event<T> *locdata;
    void createSimpleAllocator(unsigned int al);
    void deleteSimpleAllocator();
    void setElemToSimAlloc(Event<T> elem);
    void removeElemToSimAlloc(Event<T> elem);

};

template<typename T>
class Event
{
public:
    Event(T* data = nullptr);
    ~Event();

    Event<T>* getNext();
    void setNext(Event<T>* next);

    Event<T>* getPrev();
    void setPrev(Event<T>* prev);

    T* getData();

private:
    T* daEvent;
    Event<T>* nextEvent;
    Event<T>* prevEvent;    
};

template<typename T>
EventQueue<T>::EventQueue(unsigned int size) : quSize(size), quNum(0)
{
    tail = new Event<T>();
    head = new Event<T>();
    head->setNext(tail);
    tail->setPrev(head);
}

template<typename T>
EventQueue<T>::~EventQueue()
{
    clear();
    delete head;
    delete tail;
    delete locdata;
}

template<typename T>
unsigned int EventQueue<T>::getSize()
{
    return quSize;
}

template<typename T>
unsigned int EventQueue<T>::getNum()
{
    return quNum;
}

template<typename T>
void EventQueue<T>::setEvent(T* event)
{
    if (quNum < quSize)
    {
        Event<T>* eEvent = new Event<T>(event);
        Event<T>* nextEvent = head->getNext();

        eEvent->setNext(nextEvent);
        nextEvent->setPrev(eEvent);

        head->setNext(eEvent);
        eEvent->setPrev(head);

        quNum++;
    }
}

template<typename T>
T* EventQueue<T>::getEvent()
{
    if (quNum > 0)
    {
        Event<T>* eEvent = tail->getPrev();
        Event<T>* prevEvent = eEvent->getPrev();

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
void EventQueue<T>::clear()
{
    while (head->getNext()->getNext() != nullptr)
    {
        getEvent();
    }
}

/* Получение очереди, сделанной, как синглетон */
template<typename T>
EventQueue<T>* EventQueue<T>::GetInstance()
{
    if (eventqueue_ == nullptr)
    {
        eventqueue_ = new EventQueue<T>();
    }

    return eventqueue_;
}

template<typename T>
void EventQueue<T>::createSimpleAllocator(unsigned int al)
{
    locdata = new Event<T>[al];
}

template<typename T>
void EventQueue<T>::deleteSimpleAllocator()
{
    delete[] locdata;
}

template<typename T>
void EventQueue<T>::setElemToSimAlloc(Event<T> elem)
{
    int i = 0;
    while (i < quSize)
    {
        if (!locdata[i].getData())
        {
            locdata[i] = elem;
            return;
        }
        i++;
    }    
}

template<typename T>
void EventQueue<T>::removeElemToSimAlloc(Event<T> elem)
{
    int i = 0;
    while (i < quSize)
    {
        if (locdata[i] == elem)
        {
            delete locdata[i];
            return;
        }
        i++;
    }
}

template<typename T>
Event<T>::Event(T* data) : daEvent(data)
{

}

template<typename T>
Event<T>::~Event()
{
    delete daEvent;
}

template<typename T>
Event<T>* Event<T>::getNext()
{
    return nextEvent;
}

template<typename T>
void Event<T>::setNext(Event<T>* next)
{
    nextEvent = next;
}

template<typename T>
Event<T>* Event<T>::getPrev()
{
    return prevEvent;
}

template<typename T>
void Event<T>::setPrev(Event<T>* prev)
{
    prevEvent = prev;
}

template<typename T>
T* Event<T>::getData()
{
    return daEvent;
}

/* Объявление очереди, как синглетона */
template<typename T>
EventQueue<T>* EventQueue<T>::eventqueue_ = nullptr;
