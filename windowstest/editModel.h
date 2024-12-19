#pragma once
#include "interfaceObservable.h"
#include "interfaceModel.h"
#include "interfaceWidget.h"
class editModel :
    public interfaceObservable, public interfaceWidget, public interfaceModel
{
};

