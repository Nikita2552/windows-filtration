#pragma once
#include "interfaceObservable.h"
#include "interfaceModel.h"
#include "interfaceWidget.h"
class listboxModel :
    public interfaceModel, public interfaceWidget, public interfaceObservable
{
};

