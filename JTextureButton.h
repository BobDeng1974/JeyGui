#ifndef JTEXTUREBUTTON_H_INCLUDED
#define JTEXTUREBUTTON_H_INCLUDED

#include <SDL.h>
#include "JTexture.h"

enum JButtonSide
{
    TOP_LEFT = 0,
    TOP = 1,
    TOP_RIGHT = 2,
    LEFT = 3,
    MIDDLE = 4,
    RIGHT = 5,
    BOTTOM_LEFT = 6,
    BOTTOM = 7,
    BOTTOM_RIGHT = 8,
    TOTAL_SIDE = 9,
};

class JTextureButton : public JTexture
{
    private:
        SDL_Rect* m_rectArray;
        uShort m_cell;
    public:
        JTextureButton( uShort maxWidth, uShort maxHeight, SDL_Texture *texture, uShort widthTxtr, uShort heightTxtr );
        ~JTextureButton();
        void render( bool update, SDL_Renderer *renderer );
};

#endif // JTEXTUREBUTTON_H_INCLUDED
