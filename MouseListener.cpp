#include "MouseListener.h"
#include <cstdio>

MouseListener::MouseListener()
    : m_position( new MousePosition )
{
    m_position->_x = 0;
    m_position->_y = 0;
}

MouseListener::~MouseListener()
{
    delete m_position;
}

void MouseListener::setMousePosition( int &x, int &y )
{
    m_position->_x = x;
    m_position->_y = y;
}

MousePosition MouseListener::getMousePosition()
{
    return *m_position;
}
