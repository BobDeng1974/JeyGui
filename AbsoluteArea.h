#ifndef ABSOLUTEAREA_H_INCLUDED
#define ABSOLUTEAREA_H_INCLUDED

#include "Area.h"

class AbsoluteArea : public Area
{
    private:
        ToolWrapper *m_tool;
    public:
        AbsoluteArea();
        ~AbsoluteArea();
        void render( bool recalcul );
};

#endif // ABSOLUTEAREA_H_INCLUDED
