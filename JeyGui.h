#ifndef JEYGUI_H
#define JEYGUI_H

#include <string>

#include "Window.h"
#include "MouseListener.h"
#include "define_base.h"
#include "ComponentFactory.h"

class JeyGui
{
    private:
        // SDL member variables
        SDL_Renderer* m_renderer;
        SDL_Window *m_sdlWin;
        // primitive member variables
        Window* m_window;
        uShort m_xRcmd;
        uShort m_yRcmd;
        uShort m_widthRcmd;
        uShort m_heightRcmd;
        uShort m_widthScreen;
        uShort m_heightScreen;
        bool m_isWorking;
        uChar m_refreshRate;
        MouseListener *m_mListnr;
        // private functions
        void free();
        void createRenderer( SDL_Window *win );

    public:
        JeyGui();
        ~JeyGui();
        bool loadSDL();
        Window* createWindow( std::string title );
        Window* createWindow( std::string title, uShort width, uShort height, uShort x, uShort y );
        ComponentFactory* createComponentFactory();
        bool loop();
        void addMouseListener( Tool *tool );

        bool isWorking();
};

#endif // JEYGUI_H
