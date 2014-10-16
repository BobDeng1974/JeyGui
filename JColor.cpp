#include "JColor.h"
#include <cstdio>

JColor::JColor( uShort maxWidth, uShort maxHeight, Uint8 r, Uint8 g, Uint8 b, Uint8 a  )
    : Component( maxWidth, maxHeight ),  m_r( r ), m_g( g ), m_b( b ), m_a( a )
{
}

JColor::~JColor()
{
}

void JColor::render( bool update, SDL_Renderer *renderer )
{
    SDL_Rect fillRect = { m_x, m_y, m_width, m_height };
    SDL_SetRenderDrawColor( renderer, m_r, m_g, m_b, m_a );
    SDL_RenderFillRect( renderer, &fillRect );
}
