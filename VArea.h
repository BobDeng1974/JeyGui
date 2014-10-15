#ifndef VAERA_H_INCLUDED
#define VAERA_H_INCLUDED

#include "Area.h"

class VArea : public Area
{
    public:
        VArea();
        ~VArea();
        void render( bool update );
};

#endif // VAERA_H_INCLUDED
