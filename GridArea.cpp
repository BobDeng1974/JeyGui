#include "GridArea.h"

#include "define_base.h"

GridArea::GridArea( uChar raw, uChar column )
    : m_raw( raw ), m_column( column )
{
}

GridArea::~GridArea()
{
}

void GridArea::render( bool update, SDL_Renderer *renderer )
{
    if( update )
    {
        uShort width = (m_width/m_column), height = (m_height/m_raw);

        ToolWrapper *tool = 0;
        for( unsigned int i = 0; i < m_lTool.size(); ++i )
        {
            tool = m_lTool.at(i);
            //printf( "X:%d, Y:%d, W:%d, H:%d\n", m_x + (tool->_column*width), m_y + (tool->_raw*height), width, height );
            tool->_t->setDimension( m_x + (tool->_column*width), m_y + (tool->_raw*height), width, height );

            if( (tool->_t->getWidth() != width) ||
                    (tool->_t->getHeight() != height) )
            {
                // TODO recenter
                //tool->_t->setDimension( m_x + (tool->_column*width), m_y + (tool->_raw*height) );
            }
            tool->_t->render( update, renderer );
        }
    }
    else
    {
        for( unsigned int i = 0; i < m_lTool.size(); ++i )
        {
            m_lTool.at(i)->_t->render( update, renderer );
        }
    }
}
