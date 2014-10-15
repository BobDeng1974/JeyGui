#ifndef TOOLWRAPPER_H_INCLUDED
#define TOOLWRAPPER_H_INCLUDED

#include "define_base.h"

struct ToolWrapper
{
    Tool *_t;
    uInt _stretch;
    uChar _raw;
    uChar _column;

    ToolWrapper( Tool *t, uInt stretch, uChar raw = 0, uChar column = 0)
        : _t( t ), _stretch( stretch ), _raw( raw ), _column( column )
    {
    }
};

#endif // TOOLWRAPPER_H_INCLUDED
