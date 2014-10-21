#include "Tool.h"
#include <cstdio>

Tool::Tool( uShort maxWidth, uShort maxHeight )
    : m_maxWidth( maxWidth ), m_maxHeight( maxHeight )
{
    m_mListnr = NULL;
}

Tool::~Tool()
{
}

void Tool::setDimension( uShort x, uShort y )
{
    this->setDimension( x, y, 0, 0 );
}

void Tool::setDimension( uShort x, uShort y, uShort width, uShort height )
{

    m_x = x;
    m_y = y;
    m_width = width;
    m_height = height;

    if( (m_maxWidth != 0) && (width > m_maxWidth) )
    {
        m_width = m_maxWidth;
    }
    if( (m_maxHeight != 0) && (height > m_maxHeight) )
    {
        m_height = m_maxHeight;
    }
}

void Tool::setMouseListener( MouseListener *mListnr )
{
    m_mListnr = mListnr;
}

bool Tool::isMouseOver()
{
    if( m_mListnr == NULL )
        return false;

    MousePosition mPos = m_mListnr->getMousePosition();
    return ( (mPos._x >= m_x) && (mPos._x <= m_x+m_width) &&
        (mPos._y >= m_y) && (mPos._y <= m_y+m_height) );
}

uShort Tool::getWidth()
{
    return m_width;
}

uShort Tool::getHeight()
{
    return m_height;
}
