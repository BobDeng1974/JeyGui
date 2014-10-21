#ifndef JTEXTUREBUTTON_H_INCLUDED
#define JTEXTUREBUTTON_H_INCLUDED

#include <string>
#include <SDL.h>

#include "component.h"
#include "JTexture.h"
#include "JButtonState.h"

class JTextureButton
{
    private:
        JTexture **m_txtrArr;
    public:
        JTextureButton( JTexture **txtrArr );
        ~JTextureButton();
        JTexture* getJTexture( JButtonState state );
};

#endif // JTEXTUREBUTTON_H_INCLUDED
