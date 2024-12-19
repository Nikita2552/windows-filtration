#pragma once
#include "interfaceFasade.h"
#include "buttonView.h"
#include "comboboxView.h"
#include "radiobuttonView.h"
#include "editView.h"
#include "listboxView.h"
#include "buttonModel.h"
#include "comboboxModel.h"
#include "radiobuttonModel.h"
#include "editModel.h"
#include "listboxModel.h"
#include "buttonController.h"
#include "comboboxController.h"
#include "radiobuttonController.h"
#include "editController.h"
#include "listboxController.h"
#include "globals.h"
class layerUI :
    public interfaceFasade
{
public:
    layerUI(HWND hwnd);
    ~layerUI();

    void update(int wmid);

private:
    HWND hWnd{};

    buttonView* testbutton;
    buttonView* testbutton2;
    comboboxView* testcombo;
    editView* testedit;
    radiobuttonView* radio0;
    radiobuttonView* radio1;
    radiobuttonView* radio2;
    listboxView* list;

    buttonModel* testbuttonm;
    buttonModel* testbutton2m;
    comboboxModel* testcombom;
    editModel* testeditm;
    radiobuttonModel* radio0m;
    radiobuttonModel* radio1m;
    radiobuttonModel* radio2m;
    listboxModel* listm;

    buttonController* testbuttonc;
    buttonController* testbutton2c;
    comboboxController* testcomboc;
    editController* testeditc;
    radiobuttonController* radio0c;
    radiobuttonController* radio1c;
    radiobuttonController* radio2c;
    listboxController* listc;    
};

