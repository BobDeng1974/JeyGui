#include <stdio.h>

#include <SDL.h>
#include <SDL_Image.h>

#include "JeyGui.h"

JeyGui::JeyGui()
{
    printf( "JeyGui made with SDL by JeyJer.\n" );
    if( loadSDL() )
    {
        SDL_DisplayMode current;
        int monitorAvailable = SDL_GetCurrentDisplayMode( 0, &current );

        if( monitorAvailable == 0 )
        {
            printf( "Moniteur[0](%d,%d)px, @%dHz.\n", current.w, current.h, current.refresh_rate );
            m_refreshRate = current.refresh_rate;
            m_widthScreen = current.w-50;
            m_heightScreen = current.h-50;
            m_isWorking = true;
        }
        else
        {
            printf( "Aucun écran disponible: %s\n", SDL_GetError());
            m_isWorking = false;
        }
    }
    else
    {
        m_isWorking = false;
    }
}

JeyGui::~JeyGui()
{
}

bool JeyGui::loadSDL()
{
    bool success = true;

    if( SDL_Init(SDL_INIT_VIDEO) < 0 )
    {
        printf( "Impossible de charger le moteur SDL : %s", SDL_GetError() );
        success = false;
    }
    else
    {
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}
    }


    return success;
}

Window* JeyGui::createWindow( std::string title )
{
    // automatically calculating window size
    int widthFormat = 4, heightFormat = 3;
    if( (m_widthScreen/m_heightScreen) >= 1.6 ) // screen 16:9
    {
        widthFormat = 16;
        heightFormat = 9;
    }

    printf( "Screen format : %d:%d\n\n", widthFormat, heightFormat );

    m_widthRcmd = m_widthScreen;
    m_heightRcmd = m_widthScreen/widthFormat * heightFormat;
    m_yRcmd = (m_heightScreen-m_heightRcmd+50) / 2;
    m_xRcmd = (m_widthScreen-m_widthRcmd+50) / 2;

    return createWindow( title.data(), m_xRcmd, m_yRcmd ,m_widthRcmd, m_heightRcmd );
}

Window* JeyGui::createWindow( std::string title, uShort width, uShort height, uShort x, uShort y )
{
    m_sdlWin = SDL_CreateWindow(
        title.data(), m_xRcmd, m_yRcmd ,m_widthRcmd, m_heightRcmd, SDL_WINDOW_HIDDEN
    );
    if( m_sdlWin == NULL )
    {
        printf( "Impossible de creer une fenetre : %s", SDL_GetError() );
        m_isWorking = false;
    }
    else
    {
        createRenderer( m_sdlWin );
        m_window = new Window( m_sdlWin, m_renderer );
    }

    return m_window;
}

ComponentFactory* JeyGui::createComponentFactory()
{
    return new ComponentFactory( m_renderer );
}

void JeyGui::createRenderer( SDL_Window *win )
{
    m_renderer = SDL_CreateRenderer( win, -1, SDL_RENDERER_ACCELERATED );
    if( m_renderer == NULL )
    {
        printf( "Impossible de charger le moteur de rendu: %s\n", SDL_GetError() );
        m_isWorking = false;
    }
    else
    {
        //Initialize renderer color
        SDL_SetRenderDrawColor( m_renderer, 0xFF, 0xFF, 0xFF, 0x00 );

        //Initialize PNG loading
        if( !( IMG_Init( IMG_INIT_PNG ) & IMG_INIT_PNG ) )
        {
            printf( "Erreur lors du chargement de SDL_Image: %s\n", IMG_GetError() );
            m_isWorking = false;
        }
    }
}

bool JeyGui::loop()
{
    bool running = true;
    SDL_Event e;

    while( SDL_PollEvent(&e) )
    {
        if( e.type == SDL_QUIT )
        {
            running = false;
        }
    }

    if( running == true )
    {
        SDL_SetRenderDrawColor( m_renderer, 0xFF, 0xFF, 0xFF, 0x00 );
        SDL_RenderClear( m_renderer );

        m_window->render( true );
        SDL_RenderPresent( m_renderer );
    }
    else
    {
        free();
    }

    return running;
}

void JeyGui::free()
{
    SDL_DestroyWindow( m_sdlWin );
    m_sdlWin = 0;
    printf( "\n[jGui] Window destroys.\n" );
    SDL_DestroyRenderer( m_renderer );
    m_renderer = 0;
    printf( "[jGui] Renderer destroys.\n" );
}

bool JeyGui::isWorking()
{
    return m_isWorking;
}

