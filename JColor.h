#ifndef JCOLOR_H
#define JCOLOR_H

#include <SDL.h>

#include "Component.h"
#include "define_base.h"

class JColor : public Component
{
    private:
        Uint8 m_r;
        Uint8 m_g;
        Uint8 m_b;
        Uint8 m_a;
    public:
        JColor( uShort maxWidth, uShort maxHeight, Uint8 r, Uint8 g, Uint8 b, Uint8 a );
        ~JColor();
        void render( bool update, SDL_Renderer *renderer );
};

#endif // JCOLOR_H
