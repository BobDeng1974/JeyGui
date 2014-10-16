#ifndef JBUTTON_H_INCLUDED
#define JBUTTON_H_INCLUDED

#include <string>
#include <SDL.h>

#include "Component.h"
#include "JTextureButton.h"
#include "define_base.h"

class JButton : public Component
{
    private:
        std::string *m_text;
        JTextureButton *m_txtr;
        uShort m_border;
    public:
        JButton( uShort maxWidth, uShort maxHeight, std::string *text, JTextureButton *texture );
        ~JButton();
        void render( bool update, SDL_Renderer *renderer );
        void setEmptyBorder( uShort border );
};

#endif // JBUTTON_H_INCLUDED
