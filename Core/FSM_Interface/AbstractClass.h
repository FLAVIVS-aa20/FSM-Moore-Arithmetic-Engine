#pragma once
#include <iostream>
#include "StateType.h"
#include "Context.h"

class clsContext;

class clsAbstractClass{

    public:
        virtual clsStateType HandleInput(std::string Token, clsContext &ctx) = 0;
        virtual ~clsAbstractClass() = default;

};