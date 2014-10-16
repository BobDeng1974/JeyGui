#ifndef COMPONENT_H_INCLUDED
#define COMPONENT_H_INCLUDED

#include <SDL.h>

#include "Tool.h"
#include "define_base.h"

class Component : public Tool
{
    public:
        Component( uShort maxWidth, uShort maxHeight );
        ~Component();
        virtual void render( bool update, SDL_Renderer *renderer ) = 0;
};

#endif // COMPONENT_H_INCLUDED
