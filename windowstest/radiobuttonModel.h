#pragma once
#include "interfaceObservable.h"
#include "interfaceModel.h"
#include "interfaceWidget.h"
class radiobuttonModel :
    public interfaceObservable, public interfaceWidget, public interfaceModel
{
};

