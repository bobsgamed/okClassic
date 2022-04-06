//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================
#ifndef MAP_H
#define MAP_H
//==============================================================================


//================
//defines
//================

/*
#ifndef MAP_bobsgame_TOWNTown
#define MAP_bobsgame_TOWNTown 999
#endif

#ifndef MAP_bobsgame_INTROAttic
#define MAP_bobsgame_INTROAttic 998
#endif

#ifndef MAP_bobsgame_SCHOOLPlayground
#define MAP_bobsgame_SCHOOLPlayground 997
#endif

#ifndef MAP_bobsgame_INTROTown
#define MAP_bobsgame_INTROTown 996
#endif
*/

//================
//variables
//================


extern bool MAP_just_loaded;

extern int MAP_cam_x;
extern int MAP_cam_y;

extern int MAP_fx_border_width;
extern int MAP_fx_border_height;

extern int HARDWARE_map_id;

extern int* HARDWARE_map_0;
extern int* HARDWARE_map_1;
extern int* HARDWARE_map_2;
extern int* HARDWARE_map_3;

extern int* HARDWARE_map_hit_layer; //was bool before condensed separate bins into 1 single bin
extern int* HARDWARE_map_fx_layer;


extern char HARDWARE_map_0_filename[256];
extern char HARDWARE_map_1_filename[256];
extern char HARDWARE_map_2_filename[256];
extern char HARDWARE_map_3_filename[256];


extern char HARDWARE_map_hit_layer_filename[256];
extern char HARDWARE_map_fx_layer_filename[256];
extern char HARDWARE_map_palette_filename[256];
extern char HARDWARE_map_tileset_filename[256];

extern void (*MAP_current_map_load_function)();
extern void (*MAP_current_map_run_function)(BOOL);
extern void (*MAP_current_map_stop_function)();
extern void (*MAP_current_map_vbl_function)();
extern void (*MAP_current_map_hbl_function)();

extern int HARDWARE_map_tileset_size;

extern int dont_load_palette;

extern int HARDWARE_map_width_tiles;
extern int HARDWARE_map_height_tiles;

extern int HARDWARE_map_width;
extern int HARDWARE_map_height;

extern int* HARDWARE_map_palette;
extern int* HARDWARE_map_tileset;

//================
//prototypes
//================


void MAP_set_map_cam_to_cameraman();
bool MAP_is_xyxy_within_screen_by_amt(int x,int y, int x2, int y2, int amt);
bool MAP_is_xy_within_screen_by_amt(int x,int y, int amt);
void load_bg_pals_based_on_time();
bool MAP_is_xy_within_screen_by_64px(int x,int y);

void MAP_change_map(int,int,int);

void MAP_main();





//==============================================================================
#endif
//==============================================================================
