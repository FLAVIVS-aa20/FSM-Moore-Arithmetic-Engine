#pragma once
#include "Compute.h"
#include "Context.h"

using namespace std;

clsStateType clsCompute::HandleInput(std::string Token, clsContext &ctx){
            if (Token.empty() || Token == " ") {
                return clsStateType::Error;
            }

            for(char T : Token){
                if(std::isdigit(static_cast<unsigned char>(T))){
                    ctx.buildingnumber += T;
                    return clsStateType::Accumulate;
                }
                else if(T == 'C' || T == 'c'){
                     ctx.buildingnumber = "";
                     ctx.operand1 = 0;
                     ctx.lastnumber = 0;
                     ctx.operatorChar = '0';
                     ctx.equal = '0';
                     return clsStateType::Start;
                }
                else if(T == '='){
                    ctx.equal = T;
                    return clsStateType::Compute;
                }
                else if((T == '+') || (T == '-') || (T == '*') || (T == '/'))
                {
                    if(!ctx.buildingnumber.empty()) ctx.lastnumber = std::stoi(ctx.buildingnumber);
                    ctx.buildingnumber = "";
                    ctx.operatorChar = T;
                    return clsStateType::OperatorWait;
                }
                else{
                    return clsStateType::Error;
                }
            }
            return clsStateType::Error;
}