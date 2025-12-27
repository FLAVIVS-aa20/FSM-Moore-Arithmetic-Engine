#include "Error.h"
clsStateType clsError::HandleInput(std::string Token, clsContext &ctx){

            if(Token.empty() || Token == " "){
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
                    ctx.operatorChar = '0';
                    ctx.lastnumber = 0;
                    return clsStateType::Start;
                }
                else {
                    return clsStateType::Error;
                }
            }
            return clsStateType::Error;
    }