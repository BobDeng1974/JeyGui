#include <cstdio>

#include "JTexture.h"

JTexture::JTexture()
    : Component( 0, 0 ), m_txtr( NULL )
{
}

JTexture::JTexture( uShort maxWidth, uShort maxHeight, SDL_Texture *texture, uShort widthTxtr, uShort heightTxtr )
    : Component( maxWidth, maxHeight ), m_txtr( texture ), m_widthTxtr( widthTxtr ), m_heightTxtr( heightTxtr )
{
}

JTexture::~JTexture()
{
    SDL_DestroyTexture( m_txtr );
    m_txtr = 0;
}

void JTexture::render( bool update, SDL_Renderer *renderer )
{
    if( m_txtr != NULL )
	{
        SDL_Rect renderQuad = { m_x, m_y, m_width, m_height };
        SDL_RenderCopy( renderer, m_txtr, NULL, &renderQuad );
	}
	else
    {
        printf( "[jGui] Texture inexistante, affichage impossible..." );
    }
}
