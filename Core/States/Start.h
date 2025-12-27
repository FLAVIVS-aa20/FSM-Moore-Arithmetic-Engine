#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include "AbstractClass.h"
#include "Context.h"
#include "StateType.h"

class clsS : public clsAbstractClass {
public:
    clsStateType HandleInput(std::string Token, clsContext &ctx) override;
};