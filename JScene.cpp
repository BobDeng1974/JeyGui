#include "JScene.h"

JScene::JScene()
{
}

JScene::~JScene()
{
}

void JScene::render( bool update, SDL_Renderer *renderer )
{
    for( unsigned int i = 0; i < m_lTool.size(); ++i )
    {
        m_lTool.at(i)->_t->render( update, renderer );
    }
}
