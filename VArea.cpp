#include <cstdio>

#include "VArea.h"
#include "define_base.h"

VArea::VArea()
{
}

VArea::~VArea()
{
}

void VArea::render( bool update, SDL_Renderer *renderer )
{
    if( update )
    {
        uShort indicatorY = m_y, heightMiss = 0;
        ToolWrapper* tool = 0;
        for( unsigned int i = 0; i < m_lTool.size(); ++i )
        {
            tool = m_lTool.at(i);

            // Set tool dim&pos
            float percent = tool->_stretch/(float)m_totalStretch*100;
            uShort heightFill = m_height * (percent/100.) + heightMiss;
            tool->_t->setDimension( m_x, indicatorY, m_width, heightFill );

            // Check if the tool didn't keep his pos, then center it...
            if( (tool->_t->getWidth() != m_width) ||
                    (tool->_t->getHeight() != heightFill) )
            {
                heightMiss = (heightFill - tool->_t->getHeight());
                tool->_t->setDimension( (m_x + (m_width - tool->_t->getWidth()) / 2), indicatorY );
                indicatorY += heightFill - heightMiss;
            }
            else
            {
                indicatorY += heightFill;
                heightMiss = 0;
            }
            tool->_t->render( update, renderer );
        }
        if( heightMiss != 0 )
        {
            printf( "[jGui] JeyGuiException: une Area n'est pas full.\n" );
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
