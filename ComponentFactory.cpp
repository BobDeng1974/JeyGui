#include "ComponentFactory.h"
#include <iostream>

ComponentFactory::ComponentFactory( SDL_Renderer *renderer )
    : m_renderer( renderer )
{
}

ComponentFactory::~ComponentFactory()
{
}

JColor* ComponentFactory::createJColor( Uint8 r, Uint8 g, Uint8 b, Uint8 a, uShort maxWidth, uShort maxHeight )
{
    // TODO I don't remember... But I hope that you will remember soon....!!
    return new JColor( maxWidth, maxHeight, m_renderer, r, g, b, a );
}
