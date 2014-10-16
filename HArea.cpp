#include "HArea.h"

HArea::HArea()
{
}

HArea::~HArea()
{
}

void HArea::render( bool update, SDL_Renderer *renderer )
{
    if( update )
    {
        uShort indicatorX = m_x, widthMiss = 0;
        ToolWrapper* tool = 0;
        for( unsigned int i = 0; i < m_lTool.size(); ++i )
        {
            tool = m_lTool.at(i);

            // Set tool dim&pos
            float percent = tool->_stretch/(float)m_totalStretch*100;
            uShort widthFill = m_width * (percent/100.) + widthMiss;
            tool->_t->setDimension( indicatorX, m_y, widthFill, m_height );

            // Check if the tool didn't keep his dimension, then center it...
            if( (tool->_t->getWidth() != widthFill) ||
                    (tool->_t->getHeight() != m_height) )
            {
                widthMiss = (widthFill - tool->_t->getWidth());
                tool->_t->setDimension( indicatorX, (m_y + (m_height - tool->_t->getHeight()) / 2) );
                indicatorX += widthFill - widthMiss;
            }
            else
            {
                indicatorX += widthFill;
                widthMiss = 0;
            }
            tool->_t->render( update, renderer );
        }
        if( widthMiss != 0 )
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
