#ifndef COMPONENT_H_INCLUDED
#define COMPONENT_H_INCLUDED

#include <SDL.h>

#include "Tool.h"
#include "define_base.h"

class Component : public Tool
{
    protected:
        SDL_Renderer *m_renderer;
    public:
        Component( uShort maxWidth, uShort maxHeight, SDL_Renderer* renderer );
        ~Component();
        virtual void render( bool update ) = 0;
};

#endif // COMPONENT_H_INCLUDED
