#include <iostream>

#include "JeyGui.h"
#include "Window.h"
#include "VArea.h"
#include "HArea.h"
#include "GridArea.h"
#include "define_base.h"

using namespace std;

int main( int agrc, char* argv[] )
{
    JeyGui* jGui = new JeyGui;
    if( jGui->isWorking() )
    {
        Window* window = jGui->createWindow( "jGui" );
        if( window == NULL )
        {
            return JEYGUI_WINDOW_INITIALIZATION;
        }
        else
        {
            Area *lyrOne = new VArea;

            window->setArea( lyrOne );

            ComponentFactory *cFact = jGui->createComponentFactory();

            Area *lyrThree = new GridArea( 10, 10);

            JColor *c1 = cFact->createJColor( 0xFF, 0x00, 0x00, 0x00 );
            JColor *c3 = cFact->createJColor( 0x00, 0x00, 0xFF, 0x00 );
            JColor *c4 = cFact->createJColor( 0x00, 0xFF, 0xFF, 0x00 );
            JColor *c5 = cFact->createJColor( 0x00, 0x00, 0xFF, 0x00 );
            JColor *c6 = cFact->createJColor( 0x00, 0xFF, 0xFF, 0x00 );

            Area *lyrTwo = new HArea;

            lyrOne->add( c1, 1 );
            lyrOne->add( lyrTwo, 2 );
            lyrOne->add( lyrThree, 1 );

            lyrTwo->add( c3, 1 );
            lyrTwo->add( c4, 1 );
            lyrTwo->add( c5, 1 );
            lyrTwo->add( c6, 1 );

            for( int i = 0; i < 10; i+=2 )
            {
                bool isWhite1 = true;
                bool isWhite2 = false;
                Uint8 c = 0xFF;
                for( int j = 0; j < 10; ++j )
                {
                    lyrThree->add( cFact->createJColor( c, c, c, c ), 1, i, j );
                    c = (isWhite1) ? 0x00 : 0xFF;
                    isWhite1 = !isWhite1;
                }
                c = 0x00;
                for( int j = 0; j < 10; ++j )
                {
                    lyrThree->add( cFact->createJColor( c, c, c, c ), 1, i+1, j );
                    c = (isWhite2) ? 0x00 : 0xFF;
                    isWhite2 = !isWhite2;
                }
            }

            window->show();
            do
            {
            } while( jGui->loop() );
        }
    }
    else
    {
        return JEYGUI_CORE_INITIALIZATION;
    }

    return 0;
}
