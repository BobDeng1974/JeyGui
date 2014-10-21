#include <cstdio>

#include "JTextureButton.h"

JTextureButton::JTextureButton( JTexture **txtrArr )
    : m_txtrArr( txtrArr )
{
}

JTextureButton::~JTextureButton()
{
}

JTexture* JTextureButton::getJTexture( JButtonState state )
{
    return m_txtrArr[state];
}
