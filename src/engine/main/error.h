


//==============================================================================
#ifndef ERROR_H
#define ERROR_H
//==============================================================================

typedef struct
{
	int image_w;
	int image_h;
	int texture_w;
	int texture_h;
	GLuint texture_id;

}texture_STRUCT;


typedef struct
{
	char text[128];
	int x;
	int y;
	int width;
	//SDL_Color color;

}DEBUG_overlay_STRUCT;


//================
//defines
//================



//================
//variables
//================

extern bool error_console_on;
extern char* error_messages[128];
extern int error_array[128];

extern DEBUG_overlay_STRUCT* DEBUG_overlays[128];

extern char error_message[1024];
extern char sdlerror[1024];
extern char lastsdlerror[1024];


//================
//prototypes
//================

void ERROR_init_error_console();

void DEBUG_delete_overlay(DEBUG_overlay_STRUCT* overlay);
DEBUG_overlay_STRUCT* DEBUG_make_overlay(const char* text, int x, int y);
void DEBUG_update_overlay(DEBUG_overlay_STRUCT* overlay, const char* text, int, int);
void DEBUG_draw_overlays();

void ERROR_check_SDL_and_GL_errors(const char* error_string);
void gl_check_errors(int val);
void error_console(const char* error_string);
void ERROR_set_error(const char* error_string);
void ERROR_draw_error_console();





//==============================================================================
#endif
//==============================================================================
