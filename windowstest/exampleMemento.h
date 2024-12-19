#pragma once
#include "framework.h"
#include <string>
#include <vector>

using namespace std;

class interfaceMemento;
class interfaceOriginator;
class exampleMemento;

/* ��������� ������ */
class interfaceMemento
{
public:
	virtual ~interfaceMemento();
	virtual wstring getImg() = 0;
	virtual vector<float> getGraphData() = 0;
	virtual wstring getDate() = 0;
};

/* ���������, ������� ������ ������������ ��� �������, �������� ��������� ������� � ������ ������� */
class interfaceOriginator
{
public:
	virtual ~interfaceOriginator();
	virtual exampleMemento* save() = 0;
	virtual void restore(exampleMemento* memento) = 0;
};

/* ���������� ������ ��� ���������� ��������� edit */
class exampleMemento :
	public interfaceMemento
{
public:
	exampleMemento(wstring graphimg, vector<float> graph);
	virtual wstring getImg();
	virtual vector<float> getGraphData();
	virtual wstring getDate();

private:
	wstring graphicimg_;
	vector<float> graphic_;
	wstring date;
};

class careTaker
{
public:
	careTaker(interfaceOriginator* originator);
	~careTaker();

	void backup();
	void undo();
	void showHistory() const;

private:
	vector<exampleMemento*> mementos_;
	interfaceOriginator* originator_;
};

//example: https://refactoringguru.cn/ru/design-patterns/memento/cpp/example