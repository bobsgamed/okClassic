//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================
#ifndef MISC_H
#define MISC_H
//==============================================================================




//================
//defines
//================

#define GBA 0 //240x160
#define NDS 1 //256x192
#define SDL 2 //640x480
#define PSP 3 //480x272
#define POCKETPC 4
#define IPHONE 5

#define MAX_AUDIO_CHANNELS 16
#define MAX_SPRITES 128

#define demobutton BUTTON_SELECT_HELD


#define BG_256X256 0
#define BG_512X256 1
#define BG_256X512 2
#define BG_512X512 3

#define OBJ_SIZE_8X8      0,0
#define OBJ_SIZE_16X16    0,1
#define OBJ_SIZE_32X32    0,2
#define OBJ_SIZE_64X64    0,3
#define OBJ_SIZE_16X8     1,0
#define OBJ_SIZE_32X8     1,1
#define OBJ_SIZE_32X16    1,2
#define OBJ_SIZE_64X32    1,3
#define OBJ_SIZE_8X16     2,0
#define OBJ_SIZE_8X32     2,1
#define OBJ_SIZE_16X32    2,2
#define OBJ_SIZE_32X64    2,3

#define SFX_BG0 1
#define SFX_BG1 2
#define SFX_BG2 4
#define SFX_BG3 8
#define SFX_OBJ 16
#define SFX_BD  32

#define SFX_NONE 0
#define SFX_ALPHA 1
#define SFX_BRIGHTINC 2
#define SFX_BRIGHTDEC 3

//================
//variables
//================



//================
//prototypes
//================



int HARDWARE_get_file_size(const char* name);
int HARDWARE_RGB(int r, int g, int b);
void HARDWARE_create_brightened_palette(int *pal, int *newpal, int bright);
void* HARDWARE_load_file(const char* name);
void HARDWARE_unload_file(void** data_pointer);
int power_of_two(int v);
int IsNPOT(int width, int height);
void adjust_color(int *pr, int *pg, int *pb);

int r(int lessthan);






//==============================================================================
#endif
//==============================================================================
