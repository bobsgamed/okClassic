
//==============================================================================
#ifndef RENDER_H
#define RENDER_H
//==============================================================================

//================
//defines
//================



//================
//variables
//================


//-----------------------------
//openGL variables
//-----------------------------
extern GLuint fb;
extern GLuint screen;
extern GLuint scalescreen;

//shader program
extern GLuint vert[2];
extern GLuint frag[2];
extern GLuint p[2];

extern unsigned char * rgba_fbo_data; //framebuffer array
extern unsigned char * filtered_rgba_fbo_data;

//-----------------------------
//render flags
//-----------------------------
extern int framebuffer;

extern int GLOBAL_bg_layer_enabled[4];
extern int GLOBAL_sprite_layer_enabled;

extern int fade_alpha;
extern int fade_layer;


extern int GLOBAL_FRAMEBUFFER_FILTER_TYPE;

extern int fade_vbl_counter;

extern SDL_Surface* SDLSurface_screen;

extern bool ZOOMlock;

extern float ZOOM;
extern float ZOOMto;

extern int HARDWARE_SCREEN_WIDTH_PIXELS;//640;//256
extern int HARDWARE_SCREEN_HEIGHT_PIXELS;//480;//192

extern int GAME_VIEWPORT_WIDTH_PIXELS;//256
extern int GAME_VIEWPORT_HEIGHT_PIXELS;//192

extern int SCREEN_WIDTH_TILES;//32
extern int SCREEN_HEIGHT_TILES;//24

//================
//prototypes
//================

void delete_unneeded_metatiles();
void create_needed_metatiles(int bg);
void render();
void set_zoom();

//==============================================================================
#endif
//==============================================================================
