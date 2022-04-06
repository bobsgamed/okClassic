
//==============================================================================
#ifndef TITLESCREEN_H
#define TITLESCREEN_H
//==============================================================================





//================
//defines
//================



//================
//variables
//================


extern int TITLESCREEN_vbl_counter;
extern int intro_vbl_counter2;

extern int TITLESCREEN_running;


extern unsigned short* intro_top_palette;// =  NULL;
extern unsigned char* intro_top_tileset;// =  NULL;
extern unsigned short* intro_top_map;//     =  NULL;
extern int intro_top_tileset_size;// = 0;

extern unsigned short* intro_bottom_palette;// =  NULL;
extern unsigned char* intro_bottom_tileset;// =  NULL;
extern unsigned short* intro_bottom_map;//     =  NULL;
extern int intro_bottom_tileset_size;// = 0;

extern unsigned short intro_palette_1[256];
extern unsigned short intro_palette_0[256];

//================
//prototypes
//================


void title_screen();
void TITLESCREEN_vbl();
void load_title_screen();
void unload_title_screen();
void load_black_screen();
void unload_black_screen();
void load_bob_scene_2();
void load_bob_scene_3();




































//==============================================================================
#endif
//==============================================================================
