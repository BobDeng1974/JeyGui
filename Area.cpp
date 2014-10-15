#include "Area.h"

Area::Area()
    : Tool( 0, 0 ), m_totalStretch(0)
{
}

Area::~Area()
{
}

void Area::add( Tool *tool, uInt stretch, uChar raw, uChar column )
{
    m_lTool.push_back( new ToolWrapper(tool, stretch, raw, column) );
    m_totalStretch += stretch;
}

void Area::setDimension( uShort x, uShort y )
{
    Tool::setDimension( x, y );
}

void Area::setDimension( uShort x, uShort y, uShort width, uShort height )
{
    Tool::setDimension( x, y, width, height );
}
