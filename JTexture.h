#ifndef JTEXTURE_H_INCLUDED
#define JTEXTURE_H_INCLUDED

#include <SDL.h>

#include "Component.h"
#include "define_base.h"

class JTexture : public Component
{
    protected:
        SDL_Texture *m_txtr;
        uShort m_widthTxtr;
        uShort m_heightTxtr;
    public:
        JTexture( uShort maxWidth, uShort maxHeight, SDL_Texture *texture, uShort m_widthTxtr, uShort m_heightTxtr );
        ~JTexture();
        virtual void render( bool update, SDL_Renderer *renderer );
};

#endif // JTEXTURE_H_INCLUDED
