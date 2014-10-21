#include <cstdio>
#include <SDL_image.h>

#include "ComponentFactory.h"
#include "JeyGui.h"
#include "JButton.h"

ComponentFactory::ComponentFactory( SDL_Renderer *renderer, MouseListener *mListnr, JeyGui *jGui )
    : m_renderer( renderer ), m_mListnr( mListnr ), m_jGui( jGui )
{
}

ComponentFactory::~ComponentFactory()
{
}

JColor* ComponentFactory::createJColor( Uint8 r, Uint8 g, Uint8 b, Uint8 a, uShort maxWidth, uShort maxHeight )
{
    // TODO Notify JGui about this component
    return new JColor( maxWidth, maxHeight, r, g, b, a );
}

TextureParam* ComponentFactory::loadSdlTexture( std::string path )
{
    SDL_Texture* texture = NULL;
	SDL_Surface* rawImg = IMG_Load( path.c_str() );
    TextureParam *txtrPr = NULL;

	if( rawImg == NULL )
	{
		printf( "[jGui] Impossible de charger l'image: %s ! SDL_Image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		SDL_SetColorKey( rawImg, SDL_TRUE, SDL_MapRGB( rawImg->format, 0, 0xFF, 0xFF ) );

        texture = SDL_CreateTextureFromSurface( m_renderer, rawImg );
		if( texture == NULL )
		{
			printf( "[jGui] Impossible de convertir cette image vers une texture : %s ! SDL Error: %s\n",
                path.c_str(), SDL_GetError() );
		}
		else
		{
			printf( "[jGui] Ressource chargee : %s\n", path.c_str() );
            txtrPr = new TextureParam( rawImg->w, rawImg->h, texture );
		}
		SDL_FreeSurface( rawImg );
	}

    return txtrPr;
}

JTexture* ComponentFactory::loadTexture( std::string path )
{
    TextureParam *txtrPr = loadSdlTexture( path );

    JTexture *jTxtr = NULL;
    if( txtrPr != NULL )
    {
        jTxtr = new JTexture( 0, 0, txtrPr->_txtr, txtrPr->_width, txtrPr->_height);
        delete txtrPr;
    }

	return jTxtr;
}

JTextureButton* ComponentFactory::loadTextureButton( std::string *path )
{
    JTexture **jTxtrArr = new JTexture*[MOUSE_TOTAL_STATE];
    TextureParam *txtrPr = NULL;

    for( int i = 0; i < MOUSE_TOTAL_STATE; ++i )
    {
        txtrPr = loadSdlTexture( path[i] );

        if( txtrPr != NULL )
        {
            jTxtrArr[i] = new JTexture( 0, 0, txtrPr->_txtr, txtrPr->_width, txtrPr->_height );
            delete txtrPr;
        }
    }
    // TODO Notify JGui about this component
	return new JTextureButton( jTxtrArr );
}

JButton* ComponentFactory::createJButton( std::string *text, uShort maxWidth, uShort maxHeight )
{
    // TODO Notify JGui about this component
    // TODO Give default texture
    JButton *b = new JButton( maxWidth, maxHeight, text, NULL );
    m_jGui->addMouseListener( b );
    return b;
}

JButton* ComponentFactory::createJButton( std::string *text, JTextureButton *texture, uShort maxWidth, uShort maxHeight )
{
    // TODO Notify JGui about this component
    JButton *b = new JButton( maxWidth, maxHeight, text, texture );
    m_jGui->addMouseListener( b );
    return b;
}
