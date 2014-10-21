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

/* déchéterie */

class LTimer
{
    public:
		//Initializes variables
		LTimer();

		//The various clock actions
		void start();

		//Gets the timer's time
		Uint32 getTicks();

		//Checks the status of the timer

    private:
		//The clock time when the timer started
		Uint32 mStartTicks;

		//The ticks stored when the timer was paused
		Uint32 mPausedTicks;

		//The timer status
		bool mPaused;
		bool mStarted;
};



LTimer::LTimer()
{
    //Initialize the variables
    mStartTicks = 0;
    mPausedTicks = 0;

    mPaused = false;
    mStarted = false;
}

void LTimer::start()
{
    //Start the timer
    mStarted = true;

    //Unpause the timer
    mPaused = false;

    //Get the current clock time
    mStartTicks = SDL_GetTicks();
	mPausedTicks = 0;
}


Uint32 LTimer::getTicks()
{
	//The actual timer time
	Uint32 time = 0;

    //If the timer is running
    if( mStarted )
    {
        //If the timer is paused
        if( mPaused )
        {
            //Return the number of ticks when the timer was paused
            time = mPausedTicks;
        }
        else
        {
            //Return the current time minus the start time
            time = SDL_GetTicks() - mStartTicks;
        }
    }

    return time;
}

/* ______________________________________________*/

using namespace std;

int main( int agrc, char* argv[] )
{
    JeyGui* jGui = new JeyGui;
    if( jGui->isWorking() )
    {
        Window* window = jGui->createWindow( "jGui", 100, 100, 400, 400 );
        if( window == NULL )
        {
            return JEYGUI_WINDOW_INITIALIZATION;
        }
        else
        {
            Area *lyrOne = new HArea;
            window->setArea( lyrOne );

            ComponentFactory *cFact = jGui->createComponentFactory();

            std::string txtr[MOUSE_TOTAL_STATE];
            txtr[MOUSE_OUT] = "defaut_button_texture_out.png";
            txtr[MOUSE_OVER] = "defaut_button_texture_over.png";
            txtr[MOUSE_DOWN] = "defaut_button_texture_down.png";
            txtr[MOUSE_UP] = "defaut_button_texture_up.png";

            JTextureButton *txtrBut = cFact->loadTextureButton( txtr );

            std::string *text = new std::string( "text" );
            JButton *b = cFact->createJButton( text, txtrBut );
            JButton *b2 = cFact->createJButton( text, txtrBut );
            JButton *b3 = cFact->createJButton( text, txtrBut );
            b->setEmptyBorder( 0 );

            lyrOne->add( b, 3 );
            lyrOne->add( b2, 3 );
            lyrOne->add( b3, 3 );
            lyrOne->add( cFact->createJColor(0x33, 0x99, 0x00, 0x00), 3 );

            window->show();

            LTimer fpsTimer;
            int countedFrames = 0;
            fpsTimer.start();
            do
            {
                //Calculate and correct fps
                float avgFPS = countedFrames / ( fpsTimer.getTicks() / 1000.f );
                if( avgFPS > 2000000 )
                {
                    avgFPS = 0;
                }
                countedFrames++;
                std::cout << avgFPS << std::endl;
            } while( jGui->loop() );
        }
    }
    else
    {
        return JEYGUI_CORE_INITIALIZATION;
    }

    return 0;
}
