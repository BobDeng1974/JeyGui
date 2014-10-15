#include "JColor.h"
#include <cstdio>

JColor::JColor( uShort maxWidth, uShort maxHeight, SDL_Renderer *renderer,
                    Uint8 r, Uint8 g, Uint8 b, Uint8 a  )
    : Component( maxWidth, maxHeight, renderer ),  m_r( r ), m_g( g ), m_b( b ), m_a( a )
{
    m_renderer = renderer;
}

JColor::~JColor()
{
}

void JColor::render( bool update )
{
    //printf( "x:%d, y:%d, w:%d, h:%d\n", m_x, m_y, m_width, m_height );
    SDL_Rect fillRect = { m_x, m_y, m_width, m_height };
    SDL_SetRenderDrawColor( m_renderer, m_r, m_g, m_b, m_a );
    SDL_RenderFillRect( m_renderer, &fillRect );
}
