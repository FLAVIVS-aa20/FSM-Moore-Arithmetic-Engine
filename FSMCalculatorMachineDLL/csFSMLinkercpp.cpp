#define _CRT_SECURE_NO_WARNINGS
#include "csFSMLinkercpp.h"
#include <string>
#include <sstream>

struct Context {
    std::ostringstream display;
    double Current = 0;
    char LastOp = 0;
    bool Error = false;
};

extern "C" {

    DLL_API Context* CreateContext() {
        Context* ctx = new Context();
        ctx->display << "0";
        return ctx;
    }

    DLL_API void HandleInput(Context* ctx, const char* token) {
        if (!ctx || !token) return;
        std::string t(token);

        if (ctx->Error && t != "C") return;

        if (t == "C") {
            ctx->display.str("");
            ctx->display.clear();
            ctx->Current = 0;
            ctx->LastOp = 0;
            ctx->Error = false;
            ctx->display << "0";
        }
        else if (t == "-") {
            // unary minus (start of number)
            if (ctx->display.str().empty() || ctx->display.str() == "0") {
                ctx->display.str("");
                ctx->display << "-";
            }
            else {
                ctx->LastOp = '-';
                ctx->Current = std::stod(ctx->display.str());
                ctx->display.str("");
            }
        }
        else if (t == "+" || t == "*" || t == "/") {
            ctx->LastOp = t[0];
            ctx->Current = std::stod(ctx->display.str());
            ctx->display.str("");
        }
        else if (t == "=") {
            double val = std::stod(ctx->display.str());
            switch (ctx->LastOp) {
            case '+': ctx->Current += val; break;
            case '-': ctx->Current -= val; break;
            case '*': ctx->Current *= val; break;
            case '/':
                if (val != 0) ctx->Current /= val;
                else {
                    ctx->Error = true;
                    ctx->display.str("");
                    ctx->display << "Error";
                    return;
                }
                break;
            }
            if (!ctx->Error) {
                ctx->display.str("");
                ctx->display << ctx->Current;
            }
        }
        else {
            if (ctx->display.str() == "0") ctx->display.str("");
            ctx->display << t;
        }
    }

    DLL_API const char* GetDisplay(Context* ctx) {
        if (!ctx) return "0";
        static char buffer[64];
        strncpy_s(buffer, sizeof(buffer), ctx->display.str().c_str(), _TRUNCATE);
        return buffer;
    }

    DLL_API void DeleteContext(Context* ctx) {
        delete ctx;
    }

}
