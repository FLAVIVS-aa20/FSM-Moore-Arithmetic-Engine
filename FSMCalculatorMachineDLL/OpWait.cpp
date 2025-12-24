#include "OpWait.h"
#include <cctype>



clsStateType clsOpWait::HandleInput(std::string Token, clsContext &ctx){
            if(Token.empty() || Token == " " ){
                return clsStateType::Error;
            }

            for(char C : Token){
                if(std::isdigit(static_cast<unsigned char>(C))){
                    ctx.buildingnumber += C;
                    return clsStateType::Accumulate;
                }
                else if(C == '-' || C == '+'){
                    ctx.buildingnumber = C;
                    return clsStateType::Accumulate;
                }
                else{
                    return clsStateType::Error;
                }
            }
            return clsStateType::Error;
     }
