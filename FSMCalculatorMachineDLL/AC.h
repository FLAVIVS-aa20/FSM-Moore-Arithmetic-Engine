#pragma once
#include <iostream>
#include "AbstractClass.h"
#include "StateType.h"
#include "Context.h"
namespace Accumulator {
    class clsAC : public clsAbstractClass {
        public:
            clsStateType HandleInput(std::string Token, clsContext& ctx) override;
    };
}
