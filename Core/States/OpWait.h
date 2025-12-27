#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include "StateType.h"
#include "AbstractClass.h"
#include "Context.h"

class clsOpWait : public clsAbstractClass{

    public:
        clsStateType HandleInput(std::string Token, clsContext &ctx) override;
};