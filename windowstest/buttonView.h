#pragma once
#include "interfaceView.h"
#include "interfaceWidget.h"
#include "interfaceObserver.h"
#include "buttonModel.h"
#include "globals.h"
#include "framework.h"
#include <string>
#include <sstream>

using namespace std;

class buttonView :
    public interfaceView, public interfaceWidget, public interfaceObserver
{
public:    
    buttonView(HWND hwnd, int id_mybutton, wstring buttonname, elementPlace eplace, buttonModel *model);
    ~buttonView();

    int getID();
    wstring getText();
    void setText(wstring str);

    virtual void update();
    
private:
    HWND hWnd{};
    HWND hButton{};
    wstring buttonName;    
    int ID_MYBUTTON;
    elementPlace place;
    buttonModel* _model;
};

wstring convertfromfloat(float num);

