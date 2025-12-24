#include "Start.h"
clsStateType clsS::HandleInput(std::string Token, clsContext &ctx){
        if (Token.empty() || Token == " ") {
            return clsStateType::Error;
        }

        for (char C : Token) {
            if (std::isdigit(static_cast<unsigned char>(C))) {
                ctx.buildingnumber += C;
                return clsStateType::Accumulate;
            } 
            else if(C == '+' || C == '-'){ // if the number was negetive
                
                    ctx.buildingnumber += C;
                    return clsStateType::Accumulate;
            }
            else{
                return clsStateType::Error;
            }
        }

        return clsStateType::Error;
}
