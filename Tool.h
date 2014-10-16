#ifndef TOOL_H_INCLUDED
#define TOOL_H_INCLUDED

#include <SDL.h>

#include "define_base.h"

class Tool
{
    protected:
        uShort m_x;
        uShort m_y;
        uShort m_width;
        uShort m_height;
        uShort m_maxWidth;
        uShort m_maxHeight;
    public:
        Tool( uShort maxWidth, uShort maxHeight );
        ~Tool();

        virtual void render( bool update, SDL_Renderer *renderer ) = 0;
        void setDimension( uShort x, uShort y );
        void setDimension( uShort x, uShort y, uShort width, uShort height );

        uShort getWidth();
        uShort getHeight();
};

#endif // TOOL_H_INCLUDED
