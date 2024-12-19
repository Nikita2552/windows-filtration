#pragma once
#include "interfaceView.h"
#include "interfaceWidget.h"
#include "interfaceObserver.h"
#include "exampleMemento.h"
#include "editModel.h"
#include "globals.h"
#include "framework.h"
#include <string>

using namespace std;

class editView :
    public interfaceView, public interfaceWidget, public interfaceObserver, public interfaceOriginator
{
public:
    editView(HWND hwnd, int id_myedit, wstring editname, elementPlace eplace, editModel *model);
    ~editView();

    int getID();
    wstring getText();
    void setText(wstring str);

    virtual void update();
    virtual exampleMemento* save();
    virtual void restore(exampleMemento* memento);

private:
    HWND hWnd{};
    HWND hEdit{};
    wstring editName;
    int ID_MYEDIT;
    elementPlace place;
    editModel* _model;
};