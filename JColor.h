#ifndef JCOLOR_H
#define JCOLOR_H

#include <SDL.h>

#include "Component.h"
#include "define_base.h"

class JColor : public Component
{
    private:
        SDL_Renderer *m_renderer;
        Uint8 m_r;
        Uint8 m_g;
        Uint8 m_b;
        Uint8 m_a;
    public:
        JColor( uShort maxWidth, uShort maxHeight, SDL_Renderer *renderer,
                    Uint8 r, Uint8 g, Uint8 b, Uint8 a );
        ~JColor();
        void render( bool update );
};

#endif // JCOLOR_H
