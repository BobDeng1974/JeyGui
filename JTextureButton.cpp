#include <cstdio>

#include "JTextureButton.h"

JTextureButton::JTextureButton( uShort maxWidth, uShort maxHeight, SDL_Texture *texture, uShort widthTxtr, uShort heightTxtr )
    : JTexture( maxWidth, maxHeight, texture, widthTxtr, heightTxtr )
{
    m_cell = m_widthTxtr/3;

    m_rectArray = new SDL_Rect[TOTAL_SIDE];

    m_rectArray[TOP_LEFT] = {0, 0, m_cell, m_cell };
    m_rectArray[TOP] = {m_cell, 0, m_cell, m_cell };
    m_rectArray[TOP_RIGHT] = {m_cell*2, 0, m_cell, m_cell };
    m_rectArray[LEFT] = {0, m_cell, m_cell, m_cell };
    m_rectArray[MIDDLE] = {m_cell, m_cell, m_cell, m_cell };
    m_rectArray[RIGHT] = {m_cell*2, m_cell, m_cell, m_cell };
    m_rectArray[BOTTOM_LEFT] = {0, m_cell*2, m_cell, m_cell };
    m_rectArray[BOTTOM] = {m_cell, m_cell*2, m_cell, m_cell };
    m_rectArray[BOTTOM_RIGHT] = {m_cell*2, m_cell*2, m_cell, m_cell };
}

JTextureButton::~JTextureButton()
{
}

void JTextureButton::render( bool update, SDL_Renderer *renderer )
{
    if( m_txtr != NULL )
	{
	    SDL_Rect rect;
	    int xLength;
	    int yLength;

        // Draw Corner
	    rect = { m_x, m_y, m_cell, m_cell };
        SDL_RenderCopy( renderer, m_txtr, &m_rectArray[TOP_LEFT], &rect );

	    rect.x = m_x + m_width - m_cell;
	    rect.y = m_y;
        SDL_RenderCopy( renderer, m_txtr, &m_rectArray[TOP_RIGHT], &rect );

	    rect.x = m_x;
	    rect.y = m_y + m_height - m_cell;
        SDL_RenderCopy( renderer, m_txtr, &m_rectArray[BOTTOM_LEFT], &rect );

	    rect.x = m_x + m_width - m_cell;
	    rect.y = m_y + m_height - m_cell;
        SDL_RenderCopy( renderer, m_txtr, &m_rectArray[BOTTOM_RIGHT], &rect );

        // Draw side
        for( int topX = m_x+m_cell; topX < m_width; topX+=m_cell )
        {
            rect.x = topX;
            rect.y = m_y;
            SDL_RenderCopy( renderer, m_txtr, &m_rectArray[TOP], &rect );
        }
        xLength = rect.x + m_cell;
        rect.x = m_x + m_width - m_cell * 2;
        rect.y = m_y;
        SDL_RenderCopy( renderer, m_txtr, &m_rectArray[TOP], &rect );

        for( int bottomX = m_x+m_cell; bottomX < m_width; bottomX+=m_cell )
        {
            rect.x = bottomX;
            rect.y = m_y + m_height - m_cell;
            SDL_RenderCopy( renderer, m_txtr, &m_rectArray[BOTTOM], &rect );
        }
        rect.x = m_x + m_width - m_cell * 2;
        rect.y = m_y + m_height - m_cell;
        SDL_RenderCopy( renderer, m_txtr, &m_rectArray[BOTTOM], &rect );

        for( int leftY = m_y+m_cell; leftY < m_height; leftY+=m_cell )
        {
            rect.x = m_x;
            rect.y = leftY;
            SDL_RenderCopy( renderer, m_txtr, &m_rectArray[LEFT], &rect );
        }
        yLength = rect.y + m_cell;
        rect.x = m_x;
        rect.y = m_y + m_height - m_cell * 2;
        SDL_RenderCopy( renderer, m_txtr, &m_rectArray[LEFT], &rect );

        for( int rightY = m_y+m_cell; rightY < m_height; rightY+=m_cell )
        {
            rect.x = m_x + m_width - m_cell;
            rect.y = rightY;
            SDL_RenderCopy( renderer, m_txtr, &m_rectArray[RIGHT], &rect );
        }
        rect.x = m_x + m_width - m_cell;
        rect.y = m_y + m_height - m_cell * 2;
        SDL_RenderCopy( renderer, m_txtr, &m_rectArray[RIGHT], &rect );

        // Draw middle
        for( int x = m_x+m_cell; x < xLength; x+=m_cell )
        {
            for( int y = m_y+m_cell; y < yLength; y+=m_cell )
            {
                rect.x = x;
                rect.y = y;
                SDL_RenderCopy( renderer, m_txtr, &m_rectArray[MIDDLE], &rect );
            }
            rect.x = x;
            rect.y = m_y + m_height - m_cell * 2;
            SDL_RenderCopy( renderer, m_txtr, &m_rectArray[MIDDLE], &rect );
        }
        /*for( int middleRight = m_y+m_cell; middleRight < m_height; middleRight+=m_cell )
        {
            rect.x = m_x + m_width - m_cell * 2;
            rect.y = middleRight;
            SDL_RenderCopy( renderer, m_txtr, &m_rectArray[MIDDLE], &rect );
        }*/

	}
	else
    {
        printf( "[jGui] Texture inexistante, affichage impossible..." );
    }
}
