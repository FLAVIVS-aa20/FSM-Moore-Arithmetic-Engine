#pragma once
#include "StateType.h"
#include <iostream>

class clsAbstractClass;

class clsContext {
    private:
    
        clsAbstractClass* currentState;

    public:

        clsContext() = default;
        ~clsContext() = default;
        
        std::string buildingnumber = "";
        int operand1 = 0;
        int lastnumber = 0;
        char operatorChar = '0';
        char equal = '0';
        std::string display = "";
        void Reset();

        void SetCurrentState(clsAbstractClass* newState);

        void HandleInput(std::string& token);

        void Transition(clsStateType next);

        int compute(int a, char c, int b);

        void enterState(clsStateType next);

        std::string getdisplay();

};