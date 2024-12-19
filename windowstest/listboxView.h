#pragma once
#include "interfaceView.h"
#include "interfaceWidget.h"
#include "interfaceObserver.h"
#include "listboxModel.h"
#include "globals.h"
#include "framework.h"
#include <string>

using namespace std;

class listboxView :
    public interfaceView, public interfaceWidget, public interfaceObserver
{
public:
    listboxView(HWND hwnd, int id_mylistbox, wstring listboxname, elementPlace eplace, listboxModel* model);
    ~listboxView();

    int getID();    
    void addString(wstring str);
    wstring getActiveStringText();

    virtual void update();

private:
    HWND hWnd{};
    HWND hListbox{};
    wstring listboxName;
    int ID_MYLISTBOX;
    elementPlace place;
    listboxModel* _model;
};

