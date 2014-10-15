#ifndef HAREA_H_INCLUDED
#define HAREA_H_INCLUDED

#include "Area.h"

class HArea : public Area
{
    public:
        HArea();
        ~HArea();
        void render( bool update );
};

#endif // HAREA_H_INCLUDED
