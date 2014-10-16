#include <iostream>
#include <string>

#include "JeyGui.h"
#include "Window.h"
#include "VArea.h"
#include "HArea.h"
#include "GridArea.h"
#include "JTexture.h"
#include "JScene.h"
#include "JButton.h"
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
            Area *lyrOne = new HArea;
            window->setArea( lyrOne );

            ComponentFactory *cFact = jGui->createComponentFactory();

            Area *lyrTwo = new VArea;

            lyrOne->add( lyrTwo, 4 );
            lyrOne->add( cFact->createJColor(0x71, 0x33, 0x00, 0x00), 1 );

            JTexture *t = cFact->loadTexture( "foo.png" );
            t->setDimension( 100, 100 );

            JScene *jScn = new JScene;
            jScn->add( t, 0 );

            JTextureButton *txtrBut = cFact->loadTextureButton( "button_texture.png" );

            std::string *text = new std::string("text");
            JButton *b = cFact->createJButton( text, txtrBut );
            b->setEmptyBorder( 15 );
            Area *lyrThree = new HArea;
            lyrTwo->add( lyrThree, 1 );
            lyrTwo->add( jScn, 5 );

            lyrThree->add( b, 1 );
            lyrThree->add( cFact->createJColor(0x33, 0x99, 0x00, 0x00), 9 );

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
