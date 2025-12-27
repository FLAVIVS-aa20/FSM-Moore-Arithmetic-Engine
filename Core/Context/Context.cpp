#include "Context.h"
#include "Start.h"
#include "AC.h"
#include "OpWait.h"
#include "Compute.h"
#include "Error.h"
#include <string>
void clsContext::Reset() {
    buildingnumber = "";
    operand1 = 0;
    lastnumber = 0;
    operatorChar = '0';
    equal = '0';
    display = "0";
}

int clsContext::compute(int a, char op, int b){
    switch (op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
            default : return 0;
        }
}

void clsContext::SetCurrentState(clsAbstractClass* newState)
{
    currentState = newState;
}

void clsContext::HandleInput(std::string &Token)
{
    clsStateType next = currentState->HandleInput(Token, *this);
    Transition(next);

}

void clsContext::Transition(clsStateType nextState)
{

    if(currentState) delete currentState;
    
    switch (nextState)
    {
    case clsStateType::Start:
        SetCurrentState(new clsS());
        break;

    case clsStateType::Accumulate:
        SetCurrentState(new clsAC());
        break;

    case clsStateType::OperatorWait:
        SetCurrentState(new clsOpWait());
        break;

    case clsStateType::Compute:
        SetCurrentState(new clsCompute());
        break;

    case clsStateType::Error:
        SetCurrentState(new clsError());
        break;
    }
    enterState(nextState);
}



void clsContext::enterState(clsStateType next)
{
    switch(next){
        case clsStateType::Start:
            buildingnumber = "";
            operand1 = 0;
            lastnumber = 0;
            operatorChar = '0';
            equal = '0';
            display = "";
            break;

        case clsStateType::Accumulate:
            display = buildingnumber.empty() ? "0" : buildingnumber;
            break;

        case clsStateType::OperatorWait:
            (operatorChar == '0' ? display = "0" : display = std::string(1, operatorChar));
            break;

        case clsStateType::Error:
            display = "Error";
            break;

        case clsStateType::Compute:
            display = std::to_string(lastnumber);
            break;
    }
}

std::string clsContext::getdisplay(){
    return display;
}