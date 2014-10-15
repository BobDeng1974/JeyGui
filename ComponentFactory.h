#ifndef COMPONENTFACTORY_H
#define COMPONENTFACTORY_H

#include <SDL.h>

#include "JColor.h"
#include "define_base.h"

class ComponentFactory
{
    private:
        SDL_Renderer *m_renderer;
    public:
        ComponentFactory( SDL_Renderer *renderer );
        ~ComponentFactory();
        JColor* createJColor( Uint8 r, Uint8 g, Uint8 b, Uint8 a, uShort maxWidth = 0, uShort maxHeight = 0 );
};

#endif // COMPONENTFACTORY_H
