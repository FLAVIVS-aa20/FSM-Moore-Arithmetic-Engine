#pragma once
#ifdef FSMCALCULATORDLL_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

extern "C" {
    struct Context;

    DLL_API Context* CreateContext();
    DLL_API void HandleInput(Context* ctx, const char* token);
    DLL_API const char* GetDisplay(Context* ctx);
    DLL_API void DeleteContext(Context* ctx);
}
