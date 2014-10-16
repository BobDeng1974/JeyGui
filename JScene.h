#ifndef JSCENE_H_INCLUDED
#define JSCENE_H_INCLUDED

#include <SDL.h>

#include "Area.h"

class JScene : public Area
{
    public:
        JScene();
        ~JScene();
        void render( bool update, SDL_Renderer *renderer );
};

#endif // JSCENE_H_INCLUDED
