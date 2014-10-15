#ifndef GRIDAREA_H_INCLUDED
#define GRIDAREA_H_INCLUDED

#include "Area.h"

#include "define_base.h"

class GridArea : public Area
{
    private:
        uChar m_raw;
        uChar m_column;
    public:
        GridArea( uChar raw, uChar column );
        ~GridArea();
        void render( bool update );
};

#endif // GRIDAREA_H_INCLUDED
