#pragma once
#include "interfaceView.h"
#include "interfaceWidget.h"
#include "interfaceObserver.h"
#include "radiobuttonModel.h"
#include "globals.h"
#include "framework.h"
#include <string>

using namespace std;

class radiobuttonView :
    public interfaceView, public interfaceWidget, public interfaceObserver
{
public:
    radiobuttonView(HWND hwnd, int id_myradiobutton, wstring radiobuttonname, elementPlace eplace, radiobuttonModel* model);
    ~radiobuttonView();

    int getID();
    wstring getText();
    void setText(wstring str);

    virtual void update();

private:
    HWND hWnd{};
    HWND hRadio{};
    wstring radiobuttonName;
    int ID_MYRADIOBUTTON;
    elementPlace place;
    radiobuttonModel* _model;
};

