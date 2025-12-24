#include "AC.h"
#include "Context.h"
#include <string>
using namespace std;

clsStateType clsAC::HandleInput(std::string Token, clsContext &ctx){
            if(Token.empty() || Token == " "){
                return clsStateType::Error;
            }
            for(char C : Token){

                if((C == '+') || (C == '-') || (C == '*') || (C == '/'))
                {
                    ctx.operand1 = std::stoi(ctx.buildingnumber);
                    ctx.buildingnumber = "";
                    ctx.operatorChar = C;
                    return clsStateType::OperatorWait;
                }
                else if(C == '='){
                    int operand2 = std::stoi(ctx.buildingnumber);
                    if(ctx.operatorChar == '/' && operand2 == 0) return clsStateType::Error;
                    ctx.buildingnumber = "";
                    ctx.equal = C;
                    ctx.lastnumber = ctx.compute(ctx.operand1, ctx.operatorChar, operand2);
                    return clsStateType::Compute;
                }
                else if(isdigit(static_cast<unsigned char>(C)))
                {
                    ctx.buildingnumber += C;
                    return clsStateType::Accumulate;
                    
                }
                else
                {
                    return clsStateType::Error;
                }
            }

            return clsStateType::Error;
    }