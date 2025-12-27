#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include "Context.h"
#include "StateType.h"
#include "AbstractClass.h"

class clsCompute : public clsAbstractClass
{
    public:

        clsStateType HandleInput(std::string Token, clsContext &ctx) override;

};