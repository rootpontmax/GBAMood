#include "string.h"
#include "gbaregs.h"
#include "Graphics.h"
#include "../Game/VoxelGraphics.h"

#include <stdint.h>

#define VIDEOMODE_4    0x0004
#define BACKGROUND_2   0x0400
#define BACKGROUND_0   0x0100
#define BACKGROUND_1   0x0200
//#define ENABLE_OBJECTS 0x1000
//#define MAPPINGMODE_1D 0x0040


#define REG_DISPLAYCONTROL     *((volatile uint16_t*)(0x04000000))
//#define REG_BG0_CONTROL        *((volatile uint16_t*)(0x04000008))
//#define REG_BG1_CONTROL        *((volatile uint16_t*)(0x0400000A))
//#define REG_BG2_CONTROL        *((volatile uint16_t*)(0x0400000C))
//#define REG_BG3_CONTROL        *((volatile uint16_t*)(0x0400000E))



////////////////////////////////////////////////////////////////////////////////////////////////////
// typedef uint16_t Tile[32];
// typedef Tile TileBlock[256];
// typedef uint16_t ScreenBlock[1024];
////////////////////////////////////////////////////////////////////////////////////////////////////
// typedef struct SSpriteAttr
// {
// 	uint16_t attr0;
// 	uint16_t attr1;
// 	uint16_t attr2;
// 	uint16_t padding;
// } __attribute__((packed, aligned(4))) SSpriteAttr;
////////////////////////////////////////////////////////////////////////////////////////////////////
 
#define MEM_BG_PALETTE          ((uint16_t*)(CRAM_BG_ADDR)) // Background palette
//#define MEM_SP_PALETTE          ((uint16_t*)(CRAM_OBJ_ADDR)) // Sprite palette
#define MEM_VRAM                ((volatile uint32_t*)VRAM_START_ADDR)
//#define MEM_TILE                ((TileBlock*)VRAM_START_ADDR)
//#define MEM_SCREENBLOCKS        ((ScreenBlock*)VRAM_START_ADDR)
//#define MEM_OAM                 ((volatile SSpriteAttr *)0x07000000) // Object Attribute Memory
////////////////////////////////////////////////////////////////////////////////////////////////////
//volatile SSpriteAttr           *g_spriteAttribs[8];
//static const uint16_t           BLOCK_ATTR0 = 0x2000;
//static const uint16_t           BLOCK_ATTR1 = 0x0000;
////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////
uint16_t SetColor(uint16_t r, uint16_t g, uint16_t b)
{
	return (r & 0x1F) | (g & 0x1F) << 5 | (b & 0x1f) << 10;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
static void LoadPalette()
{
    memcpy(MEM_BG_PALETTE, g_palette01, 512); // 256 colors every is 2 bytes
    //memcpy(MEM_SP_PALETTE, g_tetrisPal, 256);
}
////////////////////////////////////////////////////////////////////////////////////////////////////
static void CreateVideoPageA()
{
    /*
    const size_t scanLineSize = SCREEN_SIZE_X / 4;
    for( int y = 0; y < SCREEN_SIZE_Y; ++y )
    {        
        const size_t vRamOffset = y * scanLineSize;
        uint32_t *pVideoRam = MEM_VRAM + vRamOffset;
        uint32_t *pBuffer = g_mapColor01;



        memcpy( pVideoRam, pBuffer, scanLineSize);

    }
    //*/
    //*
    const int BUFFER_SIZE = SCREEN_SIZE_X * SCREEN_SIZE_Y;   
    uint8_t buffer[BUFFER_SIZE];
    for( int y = 0; y < SCREEN_SIZE_Y; ++y )
    {
        for( int x = 0; x < SCREEN_SIZE_X; ++x )
        {
            const int offset = y * SCREEN_SIZE_X + x;
            const int color = ( y / 10 ) * 16 + ( x / 15 );
            const int pictureOffset = y * 2 * g_mapColor01_SIZE_X + x * 2;
            
            //buffer[offset] = 254;
            //buffer[offset] = (uint8_t)color;
            buffer[offset] = g_mapColor01[pictureOffset];

            
        }
    }    
    memcpy( MEM_VRAM, buffer, BUFFER_SIZE);
    //*/

}
////////////////////////////////////////////////////////////////////////////////////////////////////
void r_InitGraphics()
{
    LoadPalette();
    CreateVideoPageA();

    REG_DISPLAYCONTROL =  VIDEOMODE_4 | BACKGROUND_2;
    /*
    
    
    LoadTiles();
    //CreateBackground();
    CreateSplashScreen();
    CreateSprites();

    // Backgrounds control register
    //      FE-D-CBA98-7-6-54-32-10
    // Bg0: 00-0-01000-1-0-00-00-00
    REG_BG0_CONTROL = 0x0880;
    REG_DISPLAYCONTROL =  VIDEOMODE_0 | BACKGROUND_0 | ENABLE_OBJECTS | MAPPINGMODE_1D;
    */

   // Mode4: 240x160 8-bits per pixel.
   //REG_DISPLAYCONTROL =  VIDEOMODE_4 | BACKGROUND_2;
   
}
////////////////////////////////////////////////////////////////////////////////////////////////////
uint32_t *r_GetScreenBuffer()
{
    return MEM_VRAM;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
/*
static void ShowDigit(const int val, const int x, const int y, int divider)
{
    
    // Define digits of value
    int value = val;
    BOOL bHasValues = FALSE;
    int pos = 0;
    while( divider > 0 )
    {
        const int digit = value / divider;
        if( digit > 0 )
            bHasValues = TRUE;

        value -= digit * divider;

        if( bHasValues )
        {
            ShowBlockBackground(DIGIT_START + digit, pos + x, y);
            ++pos;
        }

        divider /= 10;

        // Show only zero
        if( divider <= 0 && !bHasValues )
            ShowBlockBackground(DIGIT_START + digit, pos + x, y);
    }
}
*/
////////////////////////////////////////////////////////////////////////////////////////////////////