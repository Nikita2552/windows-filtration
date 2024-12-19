#pragma once
#include "interfaceObservable.h"
#include "interfaceModel.h"
#include "interfaceWidget.h"
class comboboxModel :
    public interfaceModel, public interfaceWidget, public interfaceObservable
{
};

