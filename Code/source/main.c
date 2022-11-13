//#include "Core/gbaregs.h"
//#include "Core/Input.h"
//#include "Core/Graphics.h"
#include "Core/Console.h"
//#include "Game/Game.h"

#include <gba.h>
//#include <gba_types.h>
//#include <gba_input.h>
//#include <gba_timers.h>

////////////////////////////////////////////////////////////////////////////////////////////////////
static void ProfilerStart()
{
	/*
	REG_TM2CNT_L = 0;
	REG_TM3CNT_L = 0;
	REG_TM2CNT_H = 0;
	REG_TM3CNT_H = 0;

    REG_TM3CNT_H = TMCNT_EN | TMCNT_CASCADE;
    REG_TM2CNT_H = TMCNT_EN;
	*/
}
////////////////////////////////////////////////////////////////////////////////////////////////////
static uint32_t ProfilerStop()
{
	REG_TM2CNT_H = 0;
	return ( REG_TM3CNT_L << 16 ) | REG_TM2CNT_L;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
inline void VSync()
{
	while( REG_VCOUNT >= 160 );
	while( REG_VCOUNT < 160 );
}
////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	r_InitGraphics();

	// CRAP
	//consoleDemoInit();
	//uint8_t *pScreenBuffer = r_GetScreenBuffer();
	//c_ConsoleLog(1, 10, 0/*76*/, "Hello world");//, 0);
	//c_ConsoleLog(2, 11, 0/*76*/, "Bye!");//, 0);


	//InitGraphics();
	for(;;)
	{}


	// end of CRAP

	/*
	ProfilerStart();
	for( ; ; )
	{
		PollHardwareButtons();
		if( WasKeyPressed( KEY_START ) || WasKeyPressed( KEY_A ) || WasKeyPressed( KEY_B ))
		{
			const uint32_t deltaTimeNS = ProfilerStop();
			srand(deltaTimeNS);
			break;
		}
	}
	*/

/*


	//InitGame();
	ProfilerStart();
	int frameCount = 0;
	uint32_t fpsTimeMS = 0;
	uint32_t realTimeMS = 0;
	uint32_t gameTimeMS = 0;
	for( ; ; )
	{
		const uint32_t deltaTimeNS = ProfilerStop() * 60;
		ProfilerStart();
		const uint32_t deltaTimeMS = deltaTimeNS / 1000000;
		fpsTimeMS += deltaTimeMS;
		realTimeMS += deltaTimeMS;

		VSync();

		while( gameTimeMS < realTimeMS )
		{
			//UpdateGameFixed( FIXED_TIME_STEP_MS );
			gameTimeMS += FIXED_TIME_STEP_MS;
		}

		if( fpsTimeMS > 1000 )
		{
			//ShowFPS(frameCount);
			frameCount = 0;
			fpsTimeMS -= 1000;
		}

		++frameCount;
	}
	*/

	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////