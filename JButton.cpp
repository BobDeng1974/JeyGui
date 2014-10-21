#include "JButton.h"

JButton::JButton( uShort maxWidth, uShort maxHeight, std::string *text, JTextureButton *texture )
    : Component( maxWidth, maxHeight ), m_text( text ), m_txtr( texture ), m_border( 0 )
{
}

JButton::~JButton()
{
}

void JButton::render( bool update, SDL_Renderer *renderer )
{
    JButtonState state = MOUSE_OUT;
    if( (m_mListnr != NULL) && isMouseOver() )
    {
        state = MOUSE_OVER;
    }

    if( update )
        m_txtr->getJTexture( state )->setDimension( m_x+m_border, m_y+m_border, m_width-m_border*2, m_height-m_border*2 );

    m_txtr->getJTexture( state )->render( update, renderer );
    // TODO draw text
}

void JButton::setEmptyBorder( uShort border )
{
    m_border = border;
}
