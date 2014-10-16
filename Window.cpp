#include "Window.h"

Window::Window( SDL_Window *window, SDL_Renderer *renderer )
    : m_sdlWin( window ), m_renderer( renderer )
{
}

Window::~Window()
{

}

void Window::setArea( Area* area)
{
    m_area = area;

    int *x = new int, *y = new int;
    SDL_GetWindowSize( m_sdlWin, x, y );
    m_area->setDimension( 0, 0, (uShort)*x, (uShort)*y );
    delete x;
    x = 0;
    delete y;
    y = 0;
}

void Window::render( bool update )
{
    if( update || !m_init )
    {
        m_area->render( true, m_renderer );
        m_init = true;
    }
    else
    {
        m_area->render( false, m_renderer );
    }
}

void Window::show()
{
    if( !m_init )
        this->render( true );
    SDL_ShowWindow( m_sdlWin );
}

void Window::hide()
{
    SDL_HideWindow( m_sdlWin );
}
