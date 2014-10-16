#ifndef WINDOW_H
#define WINDOW_H

#include <stdio.h>

#include <SDL.h>

#include "Area.h"
#include "define_base.h"

class Window
{
    private:
        SDL_Window *m_sdlWin;
        SDL_Renderer *m_renderer;
        Area *m_area;
        bool m_init;

    public:
        Window( SDL_Window *window, SDL_Renderer *renderer );
        ~Window();

        void setArea( Area* area );
        void render( bool update );

        void show();
        void hide();
};

#endif // WINDOW_H
