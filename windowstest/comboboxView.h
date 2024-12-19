#pragma once
#include "interfaceView.h"
#include "interfaceWidget.h"
#include "interfaceObserver.h"
#include "comboboxModel.h"
#include "globals.h"
#include "framework.h"
#include <string>

using namespace std;

class comboboxView :
    public interfaceView, public interfaceWidget, public interfaceObserver
{
public:
    comboboxView(HWND hwnd, int id_mycombobox, wstring comboboxname, elementPlace eplace, comboboxModel* model);
    ~comboboxView();

    int getID();
    wstring getText();
    void setText(wstring str);

    virtual void update();

private:
    HWND hWnd{};
    HWND hCombo{};
    wstring comboboxName;
    int ID_MYCOMBOBOX;
    elementPlace place;
    comboboxModel* _model;
};

