#ifndef COMPONENTFACTORY_H
#define COMPONENTFACTORY_H

#include <string>
#include <SDL.h>

#include "JColor.h"
#include "JTexture.h"
#include "JButton.h"
#include "JTextureButton.h"
#include "MouseListener.h"
#include "define_base.h"

class JeyGui;

struct TextureParam
{
    uShort _width;
    uShort _height;
    SDL_Texture *_txtr;

    TextureParam( uShort width, uShort height, SDL_Texture *txtr )
        : _width( width ), _height( height ), _txtr( txtr )
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
        MouseListener *m_mListnr;
        JeyGui *m_jGui;

        TextureParam* loadSdlTexture( std::string path );
    public:
        ComponentFactory( SDL_Renderer *renderer, MouseListener *mListnr, JeyGui *jGui );
        ~ComponentFactory();
        JTexture* loadTexture( std::string path );
        JTextureButton* loadTextureButton( std::string *path );
        JButton* createJButton( std::string *text, uShort maxWidth, uShort maxHeight );
        JButton* createJButton( std::string *text, JTextureButton *texture, uShort maxWidth = 0, uShort maxHeight = 0 );
        JColor* createJColor( Uint8 r, Uint8 g, Uint8 b, Uint8 a, uShort maxWidth = 0, uShort maxHeight = 0 );
};

#endif // COMPONENTFACTORY_H
