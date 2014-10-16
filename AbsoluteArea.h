#ifndef ABSOLUTEAREA_H_INCLUDED
#define ABSOLUTEAREA_H_INCLUDED

#include <SDL.h>

#include "Area.h"

class AbsoluteArea : public Area
{
    private:
        ToolWrapper *m_tool;
    public:
        AbsoluteArea();
        ~AbsoluteArea();
        void render( bool update, SDL_Renderer *renderer );
};

#endif // ABSOLUTEAREA_H_INCLUDED
