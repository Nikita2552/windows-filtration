#include "exampleMemento.h"

interfaceMemento::~interfaceMemento()
{

}

exampleMemento::exampleMemento(wstring graphimg, vector<float> graph): graphicimg_(graphimg), graphic_(graph)
{

}

wstring exampleMemento::getImg()
{
	return graphicimg_;
}

vector<float> exampleMemento::getGraphData()
{
	return graphic_;
}

wstring exampleMemento::getDate()
{
	return date;
}

interfaceOriginator::~interfaceOriginator()
{

}

careTaker::careTaker(interfaceOriginator* originator) : originator_(originator)
{

}

careTaker::~careTaker()
{
	for (auto mem : mementos_)
	{
		delete mem;
	}
}

void careTaker::backup()
{    
    mementos_.push_back(originator_->save());
}

void careTaker::undo()
{
    if (!mementos_.size())
    {
        return;
    }

    exampleMemento* memento = mementos_.back();
    mementos_.pop_back();    
    try
    {
        originator_->restore(memento);
    }
    catch (...)
    {
        undo();
    }
}
void careTaker::showHistory() const {
    for (exampleMemento* memento : this->mementos_)
    {
        //показать историю каким то образом через memento->getGraphData()
    }
}