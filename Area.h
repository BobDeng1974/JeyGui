#ifndef AREA_H_INCLUDED
#define AREA_H_INCLUDED

#include <vector>
#include <cstdio>
#include <SDL.h>

#include "Tool.h"
#include "ToolWrapper.h"

#include "define_base.h"

class Area : public Tool
{
    protected:
        std::vector<ToolWrapper*> m_lTool;
        uInt m_totalStretch;
    public:
        Area();
        ~Area();
        void add( Tool *tool, uInt stretch, uChar raw = 0, uChar column = 0 );
        virtual void render( bool update, SDL_Renderer *renderer ) = 0;
        void setDimension( uShort x, uShort y );
        void setDimension( uShort x, uShort y, uShort width, uShort height );
};

#endif // AREA_H_INCLUDED
