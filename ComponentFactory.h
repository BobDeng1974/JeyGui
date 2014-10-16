#ifndef COMPONENTFACTORY_H
#define COMPONENTFACTORY_H

#include <string>
#include <SDL.h>

#include "JColor.h"
#include "JTexture.h"
#include "JTextureButton.h"
#include "JButton.h"
#include "define_base.h"

struct TextureParam
{
    uShort _maxWidth;
    uShort _maxHeight;
    SDL_Texture *_txtr;

    TextureParam( uShort maxWidth, uShort maxHeight, SDL_Texture *txtr )
        : _maxWidth( maxWidth ), _maxHeight( maxHeight ), _txtr( txtr )
    {
    }

    ~TextureParam()
    {
        _txtr = 0;
    }
};

class ComponentFactory
{
    private:
        SDL_Renderer *m_renderer;

        TextureParam* loadSdlTexture( std::string path );
    public:
        ComponentFactory( SDL_Renderer *renderer );
        ~ComponentFactory();
        JTexture* loadTexture( std::string path );
        JTextureButton* loadTextureButton( std::string path );
        JButton* createJButton( std::string *text, uShort maxWidth, uShort maxHeight );
        JButton* createJButton( std::string *text, JTextureButton *texture = NULL, uShort maxWidth = 0, uShort maxHeight = 0 );
        JColor* createJColor( Uint8 r, Uint8 g, Uint8 b, Uint8 a, uShort maxWidth = 0, uShort maxHeight = 0 );
};

#endif // COMPONENTFACTORY_H
