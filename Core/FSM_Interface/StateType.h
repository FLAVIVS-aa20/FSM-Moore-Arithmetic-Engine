#pragma once
#include <iostream>


enum class clsStateType {
    Start,
    Accumulate,
    OperatorWait,
    Error,
    Compute
};
