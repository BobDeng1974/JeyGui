#include "Component.h"

Component::Component(  uShort maxWidth, uShort maxHeight, SDL_Renderer* renderer )
    : Tool( maxWidth, maxHeight ), m_renderer( renderer )
{
}

Component::~Component()
{

}
