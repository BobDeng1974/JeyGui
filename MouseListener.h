#ifndef MOUSELISTENER_H_INCLUDED
#define MOUSELISTENER_H_INCLUDED

#include "MousePosition.h"
#include "define_base.h"

class MouseListener
{
    private:
        MousePosition *m_position;
    public:
        MouseListener();
        ~MouseListener();
        void setMousePosition( int &x, int &y );
        MousePosition getMousePosition();
};

#endif // MOUSELISTENER_H_INCLUDED
