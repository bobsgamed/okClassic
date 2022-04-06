//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================
#ifndef CAPTION_H
#define CAPTION_H
//==============================================================================


struct CAPTION
{
	SPRITE* sprite[4];

	GFX* gfx[4];

	struct CAPTION** caption_pp;
	struct CAPTION* next;

	char* text;

	int chunks;
	int screen_x;
	int screen_y;
	int layer;
	float scale;
	int main_sprite_map_x;
	int main_sprite_map_y;

	int width;

	int time_left;
	int font_id;

	int color_bg;
	int color_txt;

	bool multiline;

	int actioncaptiontype;
	NPC* npc;
	int range_x;
	int range_y;

	int x_in_tile;
	int tile;
	int chunk;
	int line;
	int TEXT_length;
	int TEXT_string_position;

	int colors[3];
	int* font_pointer;
	int font_height;

};


//================
//defines
//================
#define CAPTION_CENTERED_OVER_SPRITE -1
#define CAPTION_CENTERED_SCREEN -2
#define CAPTION_CENTERED_X -3
#define CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES -2
#define CAPTION_STAY_ONSCREEN_UNTIL_MANUALLY_DELETE -1

//================
//variables
//================

extern CAPTION* first_CAPTION;
extern CAPTION* pause_CAPTION;
extern int caption_vbl_var;


//================
//prototypes
//================


void CAPTION_delete_caption(CAPTION* delete_caption);
void CAPTION_replace_text(CAPTION* caption,const char *text);
void CAPTION_make_caption(CAPTION**caption_pp,int screen, int x, int y, int seconds, const char *caption_text, int caption_font_id, int caption_text_color, int caption_bg_color, int layer, float zoom);
int CAPTION_get_pixel_length(const char* text,int font_id);

void CAPTION_vbl();
void CAPTION_main();





//==============================================================================
#endif
//==============================================================================

