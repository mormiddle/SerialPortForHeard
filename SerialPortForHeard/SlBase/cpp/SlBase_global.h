#pragma once

#include <QtCore/qglobal.h>

#if defined(SLBASE_LIBRARY)
#  define SLBASE_EXPORT Q_DECL_EXPORT
#else
#  define SLBASE_EXPORT Q_DECL_IMPORT
#  pragma comment(lib, "SlBase.lib")
#endif

#define SlDelete(h) {if(h) {delete h; h = NULL;}}
#define SlFree(h) {if(h) {free(h); h = NULL;}}

#define Between(v, a, b) ( (v) >= (a) && (v) <= (b))
#define BetweenAuto(v, a, b) ( (a) < (b) ? Between(v, a, b) : Between(v, b, a))

#ifndef Swap
#define Swap(a, b) { auto_t = a; a = b; b = _t;}
//swap when a > b
#define SwapAuto(a, b) {if(a > b) Swap(a, b);}
#endif

#define GetValByRange(v, a, b) ( (v) < (a) ? (a) : ( (v) > (b) ? (b) : (v)))
#define AdjustValByRange(v, a, b) if(v < (a)) {v = (a);} else{if(v > (b)) {v = (b);}}

#define Sl_POINT
#ifdef Sl_POINT
typedef struct
{
    int x;
    int y;
}POINT;
#endif


