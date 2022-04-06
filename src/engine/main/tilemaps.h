

//==============================================================================
#ifndef TILEMAPS_H
#define TILEMAPS_H
//==============================================================================


//================
//defines
//================

#define METATILE_SIZE 128
#define METATILES_POSSIBLE ((((1920/2+METATILE_SIZE)/METATILE_SIZE)+2)*(((1080/2+METATILE_SIZE)/METATILE_SIZE)+2))


//================
//variables
//================

extern bool AUX_bg_is_on[4];
extern bool bg_is_on[4];


extern GLuint GLTex_bg[4];
extern int bg_texture_size_x[4];
extern int bg_texture_size_y[4];



extern GLuint GLTex_AUX_bg[4];
extern int AUX_bg_texture_size_x[4];
extern int AUX_bg_texture_size_y[4];
extern int AUX_bg_x[4];
extern int AUX_bg_y[4];
extern float AUX_bg_zoom[4];


extern GLuint GLTex_map_metatile[4*METATILES_POSSIBLE];//6 onscreen max
		//so metatile size has to be bigger than 640/2. lets say 512x512

extern int metatile_x[4*METATILES_POSSIBLE];
extern int metatile_y[4*METATILES_POSSIBLE];
extern bool metatile_used[4*METATILES_POSSIBLE];

extern bool metatile_map;

extern unsigned short GAME_temp_TILESET_PALETTE[256];

extern unsigned short temp_palette[256]; //used for modified palettes
extern unsigned short clear_palette[256]; //always filled with 0



//================
//prototypes
//================




void HARDWARE_load_bg_palette(int* palette);
void HARDWARE_delete_all_bg_data();
void HARDWARE_reload_bg_textures();


void HARDWARE_load_metatile(int bg_layer, int MAP_width_pixels, int MAP_height_pixels, int clipx, int clipy, char* name);
void HARDWARE_load_map(int bg_layer, void* MAP_data, int width, int height);
void create_needed_metatiles(int bg);
void delete_all_metatiles();
void delete_bg_metatiles(int bg);


void HARDWARE_load_AUX_map_to_xy_xy(int bg_layer, unsigned short* MAP_data, unsigned char* tileset_data, unsigned short* palette_data,int pwidth,int pheight,int from_x,int from_y, float zoom, int transparent);
void HARDWARE_delete_AUX_bg( int bg_layer);
void HARDWARE_set_AUX_map_xy(int bg_layer, int x, int y);


//==============================================================================
#endif
//==============================================================================
