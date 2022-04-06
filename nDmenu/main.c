//===============================================================================================
// nDmenu
// copyright 2011 robert pelloni
//===============================================================================================



//uncomment for mixer
#define MIX_ON

//uncomment for ttf
#define TTF_ON

#define GLES1

//==========================================================================
//includes
//==========================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

//#include "nD_types.h"


#include "SDL/SDL_image.h"

#include "SDL/SDL_types.h"
#include "SDL/SDL_config.h"
#include "SDL/SDL_error.h"
#include "SDL/SDL_events.h"
#include "SDL/SDL_framerate.h"
//#include "SDL/SDL_freetype.h"
#include "SDL/SDL_imageFilter.h"
#include "SDL/SDL_joystick.h"
#include "SDL/SDL_keyboard.h"
#include "SDL/SDL_keysym.h"
#include "SDL/SDL_loadso.h"
#include "SDL/SDL_main.h"
#include "SDL/SDL_mouse.h"
#include "SDL/SDL_mutex.h"
#include "SDL/SDL_name.h"
#include "SDL/SDL_quit.h"
//#include "SDL/SDL_gfxPrimitives.h"
//#include "SDL/SDL_gfxPrimitives_font.h"
//#include "SDL/SDL_rotozoom.h"
#include "SDL/SDL_rwops.h"
#include "SDL/SDL_thread.h"
#include "SDL/SDL_timer.h"

#include "inifile.h"



#ifdef TTF_ON
#include "SDL/SDL_ttf.h"
#endif

//#include "SDL/SDL_wiz_dev.h"



#include "smpeg/smpeg.h"
//#include "tremor/ivorbisfile.h"


//==========================================================================
//defines
//==========================================================================


#define GP2X_BUTTON_UP              (0)
#define GP2X_BUTTON_DOWN            (4)
#define GP2X_BUTTON_LEFT            (2)
#define GP2X_BUTTON_RIGHT           (6)
#define GP2X_BUTTON_UPLEFT          (1)
#define GP2X_BUTTON_UPRIGHT         (7)
#define GP2X_BUTTON_DOWNLEFT        (3)
#define GP2X_BUTTON_DOWNRIGHT       (5)
#define GP2X_BUTTON_CLICK           (18)
#define GP2X_BUTTON_A               (12)
#define GP2X_BUTTON_B               (13)
#define GP2X_BUTTON_X               (14)
#define GP2X_BUTTON_Y               (15)
#define GP2X_BUTTON_L               (10)
#define GP2X_BUTTON_R               (11)
#define GP2X_BUTTON_START           (8)
#define GP2X_BUTTON_SELECT          (9)
#define GP2X_BUTTON_VOLUP           (16)
#define GP2X_BUTTON_VOLDOWN         (17)

//#define WIZ_MMUHACKOFF	0x00040000
//#define WIZ_RAMTWEAKOFF	0x00080000
//#define WIZ_240X320	0x00100000
//#define WIZ_UPPERSURFACE 0x00200000
//#define WIZ_TEARING	0x00400000
//#define WIZ_VSYNCOFF	0x00800000

#define SCREEN_SIZE_X 320
#define SCREEN_SIZE_Y 240

#define CLOCKWISE 0
#define COUNTERCLOCKWISE 1

int rmask, gmask, bmask, amask;


#include "nD_GL.h"



/// INIFILE VARIABLES

/*

selection box on/off

label blinking on/off
label blinking speed

x value for selected cart item
x speed for selected cart item

key repeat delay
key repeat speed

max wheel acceleration factor


*/


///===============================================================================================
/// GLOBALS
///===============================================================================================

int bobsgame=0;



#define MAX_WHEEL_ITEMS 64

	typedef struct
	{
		int x;
		int y;
		texture_STRUCT* label_TEXTURE;
		texture_STRUCT* label_glow_TEXTURE;
		int slot;
		char name[256];
		SDL_Color color;

	}wheel_item_STRUCT;

	wheel_item_STRUCT wheel_item[MAX_WHEEL_ITEMS];


	//other---------------------------------

	SDL_Color white_COLOR = {255, 255, 255};
	SDL_Color black_COLOR = {0, 0, 0};
	SDL_Color red_COLOR = {255, 0, 0};
	SDL_Color green_COLOR = {0, 255, 0};
	SDL_Color blue_COLOR = {0, 0, 255};
	SDL_Color magenta_COLOR = {255, 0, 255};
	SDL_Color yellow_COLOR = {0, 127, 127};


	int selected_wheel_item=0;
	int wheel_spin_direction=2;
	int wheel_sound_queue=0;

	int loaded_wheel_items;

	//------------------------------------------
	//initialize button values
	//------------------------------------------

		SDL_Event event_EVENT;
		SDL_Joystick* joystick = NULL;

		int quit=0;
		int action_pressed=0;

		int button_held_ticks=0;

		int down_pressed=0;
		int right_pressed=0;
		int up_pressed=0;
		int left_pressed=0;

		int ticks_since_down_pressed=0;
		int ticks_since_right_pressed=0;
		int ticks_since_up_pressed=0;
		int ticks_since_left_pressed=0;

		int ticks_since_down_repeat=0;
		int ticks_since_right_repeat=0;
		int ticks_since_up_repeat=0;
		int ticks_since_left_repeat=0;



		int current_ticks=0;
		int last_ticks=0;
		int timer_ticks=0;
		int frames_total_count=0;
	//------------------------------------------

//===========================================================================================================================
void spin_wheel(int dir)
{//===========================================================================================================================
	if(dir==CLOCKWISE)
	{
		wheel_spin_direction=CLOCKWISE;
		selected_wheel_item++;
		if(selected_wheel_item>=loaded_wheel_items)selected_wheel_item=0;
		wheel_sound_queue++;

	}
	else
	if(dir==COUNTERCLOCKWISE)
	{
		wheel_spin_direction=COUNTERCLOCKWISE;
		selected_wheel_item--;
		if(selected_wheel_item<0)selected_wheel_item=loaded_wheel_items-1;
		wheel_sound_queue++;
	}
}

//===========================================================================================================================
void check_keys()
{//===========================================================================================================================


		//------------------------------------------
		//handle key input
		//------------------------------------------
			while(SDL_PollEvent(&event_EVENT))
			{
				if(event_EVENT.type == SDL_KEYDOWN)
				{

						if(event_EVENT.key.keysym.sym==SDLK_DOWN)
						{
							down_pressed=1;
							ticks_since_down_pressed=0;
							spin_wheel(CLOCKWISE);
						}
						if(event_EVENT.key.keysym.sym==SDLK_RIGHT)
						{
							right_pressed=1;
							ticks_since_right_pressed=0;
							spin_wheel(CLOCKWISE);
						}

						if(event_EVENT.key.keysym.sym==SDLK_UP)
						{
							up_pressed=1;
							ticks_since_up_pressed=0;
							spin_wheel(COUNTERCLOCKWISE);
						}
						if(event_EVENT.key.keysym.sym==SDLK_LEFT)
						{
							left_pressed=1;
							ticks_since_left_pressed=0;
							spin_wheel(COUNTERCLOCKWISE);
						}

						if(event_EVENT.key.keysym.sym==SDLK_ESCAPE)quit=1;
						if(event_EVENT.key.keysym.sym==SDLK_RETURN)action_pressed=1;
				}

				if(event_EVENT.type == SDL_JOYBUTTONDOWN)
				{
					if(event_EVENT.jbutton.button==GP2X_BUTTON_DOWN)
					{
						down_pressed=1;
						ticks_since_down_pressed=0;
						spin_wheel(CLOCKWISE);
					}
					if(event_EVENT.jbutton.button==GP2X_BUTTON_RIGHT)
					{
						right_pressed=1;
						ticks_since_right_pressed=0;
						spin_wheel(CLOCKWISE);
					}

					if(event_EVENT.jbutton.button==GP2X_BUTTON_UP)
					{
						up_pressed=1;
						ticks_since_up_pressed=0;
						spin_wheel(COUNTERCLOCKWISE);
					}
					if(event_EVENT.jbutton.button==GP2X_BUTTON_LEFT)
					{
						left_pressed=1;
						ticks_since_left_pressed=0;
						spin_wheel(COUNTERCLOCKWISE);
					}

					if(event_EVENT.jbutton.button==GP2X_BUTTON_Y)quit=1;
					if(event_EVENT.jbutton.button==GP2X_BUTTON_B)action_pressed=1;
				}

				if(event_EVENT.type == SDL_KEYUP)
				{
					if(event_EVENT.key.keysym.sym==SDLK_DOWN){down_pressed=0;}
					if(event_EVENT.key.keysym.sym==SDLK_RIGHT){right_pressed=0;}
					if(event_EVENT.key.keysym.sym==SDLK_UP){up_pressed=0;}
					if(event_EVENT.key.keysym.sym==SDLK_LEFT){left_pressed=0;}
				}
				if(event_EVENT.type == SDL_JOYBUTTONUP)
				{
					if(event_EVENT.jbutton.button==GP2X_BUTTON_DOWN){down_pressed=0;}
					if(event_EVENT.jbutton.button==GP2X_BUTTON_RIGHT){right_pressed=0;}
					if(event_EVENT.jbutton.button==GP2X_BUTTON_UP){up_pressed=0;}
					if(event_EVENT.jbutton.button==GP2X_BUTTON_LEFT){left_pressed=0;}
				}
			}
		//------------------------------------------

		//------------------------------------------
		//handle key repeat
		//------------------------------------------
			current_ticks = SDL_GetTicks();
			if(current_ticks>button_held_ticks)
			{
				if(down_pressed)
				{
					ticks_since_down_pressed+=current_ticks-button_held_ticks;
					if(ticks_since_down_pressed>400)
					{
						if(current_ticks>ticks_since_down_repeat+100)
						{
							ticks_since_down_repeat=current_ticks;
							spin_wheel(CLOCKWISE);
						}
					}
				}

				if(right_pressed)
				{
					ticks_since_right_pressed+=current_ticks-button_held_ticks;
					if(ticks_since_right_pressed>400)
					{
						if(current_ticks>ticks_since_right_repeat+100)
						{
							ticks_since_right_repeat=current_ticks;
							spin_wheel(CLOCKWISE);
						}
					}
				}

				if(up_pressed)
				{
					ticks_since_up_pressed+=current_ticks-button_held_ticks;
					if(ticks_since_up_pressed>400)
					{
						if(current_ticks>ticks_since_up_repeat+100)
						{
							ticks_since_up_repeat=current_ticks;
							spin_wheel(COUNTERCLOCKWISE);
						}
					}
				}

				if(left_pressed)
				{
					ticks_since_left_pressed+=current_ticks-button_held_ticks;
					if(ticks_since_left_pressed>400)
					{
						if(current_ticks>ticks_since_left_repeat+100)
						{
							ticks_since_left_repeat=current_ticks;
							spin_wheel(COUNTERCLOCKWISE);
						}
					}
				}
				button_held_ticks=current_ticks;
			}
		//------------------------------------------


}


///===========================================================================================================================
int main(int argc, char* args[])
{///===========================================================================================================================


	SDL_Init(SDL_INIT_EVERYTHING);
	joystick = SDL_JoystickOpen(0);

	init_gl();

	//------------------------------------------
	//load graphics
	//------------------------------------------

		//todo: might want to use this later for optimizing
		//cart_SURFACE = SDL_DisplayFormat(screen_SURFACE);




		//load wheel items

		//go in items folder

		//list folders

		//go in each folder

		//open ini file

		//find label.png

		//find screenshot.png

		//get info from ini file

		//play music.ogg

	//------------------------------------------


	//------------------------------------------
	//load wheel item textures
	//------------------------------------------

		texture_STRUCT* cart_TEXTURE;
		//texture_STRUCT* cart_2_TEXTURE;
		//texture_STRUCT* cart_black_TEXTURE;

		int mm=0;
		for(mm=0;mm<MAX_WHEEL_ITEMS;mm++)
		{
			wheel_item[mm].x=0;
			wheel_item[mm].y=0;
			wheel_item[mm].slot=0;
			wheel_item[mm].label_TEXTURE=NULL;
			strcpy(wheel_item[mm].name,"empty");
			wheel_item[mm].color=black_COLOR;
		}


		cart_TEXTURE = load_texture("data/wheel_item/round_black_bg.png");


		int cart_label_height=40;//37;//48;//cart_SURFACE->h; //size of cart image
		int cart_offset_x=6;//where the label "container" starts inside the cart png
		int cart_offset_y=6;//13;//where the label "container" starts inside the cart png
		//int cart_image_height=75;//the size of the label "container" in cart png


	//------------------------------------------
	//initialize wheel item labels / highlight values
	//------------------------------------------
		int highlight_ticks=0;
		int highlight_color=0;
		int highlight_dir=0;


		texture_STRUCT* labelfade_TEXTURE;
		labelfade_TEXTURE = load_texture("data/wheel_item/round_shiny_overlay.png");


		texture_STRUCT* selection_box_TEXTURE[15];

		int selection_box_on=1;

		selection_box_TEXTURE[0] = load_texture("data/wheel_item/round_selected_00.png");
		selection_box_TEXTURE[1] = load_texture("data/wheel_item/round_selected_01.png");
		selection_box_TEXTURE[2] = load_texture("data/wheel_item/round_selected_02.png");
		selection_box_TEXTURE[3] = load_texture("data/wheel_item/round_selected_03.png");
		selection_box_TEXTURE[4] = load_texture("data/wheel_item/round_selected_04.png");
		selection_box_TEXTURE[5] = load_texture("data/wheel_item/round_selected_05.png");
		selection_box_TEXTURE[6] = load_texture("data/wheel_item/round_selected_06.png");
		selection_box_TEXTURE[7] = load_texture("data/wheel_item/round_selected_07.png");
		selection_box_TEXTURE[8] = load_texture("data/wheel_item/round_selected_08.png");
		selection_box_TEXTURE[9] = load_texture("data/wheel_item/round_selected_09.png");
		selection_box_TEXTURE[10] = load_texture("data/wheel_item/round_selected_10.png");
		selection_box_TEXTURE[11] = load_texture("data/wheel_item/round_selected_11.png");
		selection_box_TEXTURE[12] = load_texture("data/wheel_item/round_selected_12.png");
		selection_box_TEXTURE[13] = load_texture("data/wheel_item/round_selected_13.png");
		selection_box_TEXTURE[14] = load_texture("data/wheel_item/round_selected_14.png");





	//------------------------------------------
	//set up wheel items
	//------------------------------------------


	loaded_wheel_items=3;


		wheel_item[0].label_TEXTURE = load_texture("data/items/gamestore/label_gamestore.png");
		wheel_item[0].label_glow_TEXTURE = load_texture("data/items/gamestore/label_gamestore.png");

		wheel_item[1].label_TEXTURE = load_texture("data/items/bobsgame/label_bobsgame.png");
		wheel_item[1].label_glow_TEXTURE = load_texture("data/items/bobsgame/label_bobsgame_glow.png");

		wheel_item[2].label_TEXTURE = load_texture("data/items/settings/label_settings.png");
		wheel_item[2].label_glow_TEXTURE = load_texture("data/items/settings/label_settings.png");

		strcpy(wheel_item[0].name,"Game Store");
		strcpy(wheel_item[1].name,"\"bob's game\"");
		strcpy(wheel_item[2].name,"Settings");

		wheel_item[0].color = red_COLOR;//SDL_MapRGB(screen_SURFACE->format, 255,0,0);
		wheel_item[1].color = green_COLOR;//SDL_MapRGB(screen_SURFACE->format, 0,255,0);
		wheel_item[2].color = yellow_COLOR;//SDL_MapRGB(screen_SURFACE->format,0,127,127);


	//------------------------------------------
	//initialize wheel movement values
	//------------------------------------------

		//int max_wheel_items_onscreen = (SCREEN_SIZE_Y/cart_label_height)+2;

		//since the middle label will be centered on screen, the topmost label y position will be offset, not zero
		//int first_cart_y = (((SCREEN_SIZE_Y/2)-(cart_label_height/2))%cart_label_height);

		///populate the wheel starting from the middle, so the first item is always selected.
		int first_cart_y = ((SCREEN_SIZE_Y/2)-(cart_label_height/2));

		float df=0;
		int wheel_spinning=0;


	//------------------------------------------
	//set initial y values in each cart struct
	//------------------------------------------

		for(mm=0;mm<loaded_wheel_items;mm++)
		{
			wheel_item[mm].y=first_cart_y+mm*cart_label_height;
			wheel_item[mm].slot=mm;
		}

	//------------------------------------------
	//initialize bg values
	//------------------------------------------

		texture_STRUCT* bg_TEXTURE;

		SDL_Rect bg_offset = {0,0,0,0};

		bg_offset.w = 384;//352;//bg_SURFACE->w;
		bg_offset.h = 320;//288;//bg_SURFACE->h;

		int bg_ticks=0;

		bg_TEXTURE = load_texture("data/bg/bg.png");

	//------------------------------------------
	//initialize bg glow values
	//------------------------------------------

		texture_STRUCT* bg_glow_TEXTURE[20];

		int bg_glow_amt=6;

		SDL_Rect bg_glow_offset[bg_glow_amt];
		int bg_glow_frame[bg_glow_amt];
		//int bg_glow_timer[bg_glow_amt];
		int bg_glow_ticks[bg_glow_amt];
		int bg_glow_started[bg_glow_amt];

		int bga=0;
		for(bga=0;bga<bg_glow_amt;bga++)
		{
			bg_glow_frame[bga]=0;
			bg_glow_ticks[bga]=1000+rand()%5000;
			//bg_glow_timer[bga]=0;//100+rand()%100;

			bg_glow_started[bga]=0;


			bg_glow_offset[bga].x=0;//64;//((rand()%6)*64);
			bg_glow_offset[bga].y=0;//64;//((rand()%5)*64);
			bg_glow_offset[bga].w=32;
			bg_glow_offset[bga].h=32;
		}

		bg_glow_started[0]=1;

		bg_glow_TEXTURE[0] = load_texture("data/bg/01.png");
		bg_glow_TEXTURE[1] = load_texture("data/bg/02.png");
		bg_glow_TEXTURE[2] = load_texture("data/bg/03.png");
		bg_glow_TEXTURE[3] = load_texture("data/bg/04.png");
		bg_glow_TEXTURE[4] = load_texture("data/bg/05.png");
		bg_glow_TEXTURE[5] = load_texture("data/bg/06.png");
		bg_glow_TEXTURE[6] = load_texture("data/bg/07.png");
		bg_glow_TEXTURE[7] = load_texture("data/bg/08.png");
		bg_glow_TEXTURE[8] = load_texture("data/bg/09.png");
		bg_glow_TEXTURE[9] = load_texture("data/bg/10.png");
		bg_glow_TEXTURE[10] = bg_glow_TEXTURE[9];
		bg_glow_TEXTURE[11] = bg_glow_TEXTURE[8];
		bg_glow_TEXTURE[12] = bg_glow_TEXTURE[7];
		bg_glow_TEXTURE[13] = bg_glow_TEXTURE[6];
		bg_glow_TEXTURE[14] = bg_glow_TEXTURE[5];
		bg_glow_TEXTURE[15] = bg_glow_TEXTURE[4];
		bg_glow_TEXTURE[16] = bg_glow_TEXTURE[3];
		bg_glow_TEXTURE[17] = bg_glow_TEXTURE[2];
		bg_glow_TEXTURE[18] = bg_glow_TEXTURE[1];
		bg_glow_TEXTURE[19] = bg_glow_TEXTURE[0];

	//------------------------------------------
	//initialize movie values
	//------------------------------------------

		texture_STRUCT* movie_border_TEXTURE[13];

		movie_border_TEXTURE[0] = load_texture("data/movie_border/movie_border_00.png");
		movie_border_TEXTURE[1] = load_texture("data/movie_border/movie_border_01.png");
		movie_border_TEXTURE[2] = load_texture("data/movie_border/movie_border_02.png");
		movie_border_TEXTURE[3] = load_texture("data/movie_border/movie_border_03.png");
		movie_border_TEXTURE[4] = load_texture("data/movie_border/movie_border_04.png");
		movie_border_TEXTURE[5] = load_texture("data/movie_border/movie_border_05.png");
		movie_border_TEXTURE[6] = load_texture("data/movie_border/movie_border_06.png");
		movie_border_TEXTURE[7] = load_texture("data/movie_border/movie_border_07.png");
		movie_border_TEXTURE[8] = load_texture("data/movie_border/movie_border_08.png");
		movie_border_TEXTURE[9] = load_texture("data/movie_border/movie_border_09.png");
		movie_border_TEXTURE[10] = load_texture("data/movie_border/movie_border_10.png");
		movie_border_TEXTURE[11] = load_texture("data/movie_border/movie_border_11.png");
		movie_border_TEXTURE[12] = load_texture("data/movie_border/movie_border_12.png");


		int movie_x=0;
		int movie_y=0;
		int movie_scroll_ticks=0;
		int movie_play_ticks=0;

		int direction_button_pressed=0;

		SDL_Surface* movie_YUV_SURFACE[4];
		SMPEG_Info movieInfo[4];
		SMPEG* movie[4];

		SDL_Surface* movie_RGBA_SURFACE = NULL;
		texture_STRUCT* movie_TEXTURE[2] = {NULL, NULL};

		int movieswapframe=0;
		int movie_frame_num=0;
		int movie_render_step=0;
		int movieswapframe_opposite=0;



		//movie[0] = SMPEG_new("data/movie/superbrobros_gameplay.mpg", 	&movieInfo[0], 0);
		movie[1] = SMPEG_new("data/movie/bobsgame_gameplay.mpg", 		&movieInfo[1], 0);
		//movie[2] = SMPEG_new("data/movie/splarkapuzzle_gameplay.mpg", 	&movieInfo[2], 0);
		//movie[3] = SMPEG_new("data/movie/yokoid_gameplay.mpg", 			&movieInfo[3], 0);


		int m=1;
		//for(m=0;m<4;m++)
		{
			SDL_Surface* tempSurface = SDL_CreateRGBSurface(SDL_SWSURFACE, movieInfo[m].width, movieInfo[m].height, 32, rmask, gmask, bmask, amask);
			movie_YUV_SURFACE[m] = SDL_DisplayFormat(tempSurface);
			SDL_FreeSurface(tempSurface);
			SMPEG_setdisplay(movie[m], movie_YUV_SURFACE[m], NULL, NULL);
		}

		//SMPEG_setdisplayregion(movie, 0, 0, movieInfo.width, movieInfo.height);
		//Uint8* keys;
		//SMPEG_play(movie);
		//SMPEG_loop(movie, 1);// Set the looping of hte movie
		//SMPEG_seek(movie, bytes);// Seek a number of bytes into the movie
		//SMPEG_setdisplayregion(movie, x, y, w, h);// Sets the region of the video to be shown
		//SMPEG_scaleXY(movie, w, h);// Scale the movie by the desired factors
		//SMPEG_scale(movie, factor);// Scale the movie by the desired factor
		//SMPEG_setvolume(movie, vol);// Set's the volume on a scale of 0 - 100
		//SMPEG_renderFrame(movie, frame);// Render some frame of the movie
		//SMPEG_renderFinal(movie, movieSurface, 0, 0);// Render the final frame of the movie
		//SMPEG_Info SMPEG_getinfo(movie, &movieInfo);
		//SMPEGstatus SMPEG_status(movie);//Get the current status of the movie, can be SMPEG_ERROR = -1, SMPEG_STOPPED, SMPEG_PLAYING

	//------------------------------------------



	//------------------------------------------
	//init font
	//------------------------------------------
		//font----------------------------------
		#ifdef TTF_ON

			TTF_Init();

			TTF_Font *font_bobsgame_8px = NULL;
			TTF_Font *font_bobsgame_16px = NULL;
			font_bobsgame_8px=TTF_OpenFont("data/bobsgame.ttf",8);
			font_bobsgame_16px=TTF_OpenFont("data/bobsgame.ttf",16);

			char text_Game[1024];
			char text_Author[1024];
			char text_TimePlayed[1024];
			char text_LastPlayed[1024];

			char text_Game_Label[1024];
			char text_Author_Label[1024];
			char text_TimePlayed_Label[1024];
			char text_LastPlayed_Label[1024];


			SDL_Surface* text_Game_SURFACE = NULL;// = TTF_RenderText_Solid(font,"hello",white_COLOR);
			SDL_Surface* text_Author_SURFACE = NULL;
			SDL_Surface* text_TimePlayed_SURFACE = NULL;
			SDL_Surface* text_LastPlayed_SURFACE = NULL;

			SDL_Surface* text_Game_Label_SURFACE = NULL;// = TTF_RenderText_Solid(font,"hello",white_COLOR);
			SDL_Surface* text_Author_Label_SURFACE = NULL;
			SDL_Surface* text_TimePlayed_Label_SURFACE = NULL;
			SDL_Surface* text_LastPlayed_Label_SURFACE = NULL;

			texture_STRUCT *text_Game_TEXTURE = NULL;// = load_texture_from_non_square_surface(font_SURFACE);
			texture_STRUCT *text_Author_TEXTURE = NULL;
			texture_STRUCT *text_TimePlayed_TEXTURE = NULL;
			texture_STRUCT *text_LastPlayed_TEXTURE = NULL;

			texture_STRUCT *text_Game_Label_TEXTURE = NULL;// = load_texture_from_non_square_surface(font_SURFACE);
			texture_STRUCT *text_Author_Label_TEXTURE = NULL;
			texture_STRUCT *text_TimePlayed_Label_TEXTURE = NULL;
			texture_STRUCT *text_LastPlayed_Label_TEXTURE = NULL;


			texture_STRUCT* infopanel_TEXTURE = load_texture("data/infopanel/infopanel.png");

			int infopanel_scroll_ticks=0;
			int infopanel_x=0;
			int infopanel_y=0;

			texture_STRUCT* infopanel_border_TEXTURE[8];

			infopanel_border_TEXTURE[0] = load_texture("data/infopanel/infopanel_border_00.png");
			infopanel_border_TEXTURE[1] = load_texture("data/infopanel/infopanel_border_01.png");
			infopanel_border_TEXTURE[2] = load_texture("data/infopanel/infopanel_border_02.png");
			infopanel_border_TEXTURE[3] = load_texture("data/infopanel/infopanel_border_03.png");
			infopanel_border_TEXTURE[4] = load_texture("data/infopanel/infopanel_border_04.png");
			infopanel_border_TEXTURE[5] = load_texture("data/infopanel/infopanel_border_05.png");
			infopanel_border_TEXTURE[6] = load_texture("data/infopanel/infopanel_border_06.png");
			infopanel_border_TEXTURE[7] = load_texture("data/infopanel/infopanel_border_07.png");


			//pulse colors
				//gradient between 0,255,0 and 133,0,255
				// +1, -2, +2

			SDL_Color fade_COLOR[256];

			int fade_r=0;
			int fade_g=255;
			int fade_b=0;

			int colorfadedirection=0;

				int l=0;
				for(l=0;l<256;l++)
				{
					if(colorfadedirection==0)
					{
						fade_r+=1;
						fade_g-=2;
						fade_b+=2;

						if(fade_r>255)fade_r=255;
						if(fade_g>255)fade_g=255;
						if(fade_b>255)fade_b=255;

						if(fade_r<0)fade_r=0;
						if(fade_g<0)fade_g=0;
						if(fade_b<0)fade_b=0;

						if(fade_b==255)colorfadedirection=1;

					}
					else
					if(colorfadedirection==1)
					{

						fade_r-=1;
						fade_g+=2;
						fade_b-=2;

						if(fade_r>255)fade_r=255;
						if(fade_g>255)fade_g=255;
						if(fade_b>255)fade_b=255;

						if(fade_r<0)fade_r=0;
						if(fade_g<0)fade_g=0;
						if(fade_b<0)fade_b=0;

						if(fade_g==255)colorfadedirection=0;
					}

					fade_COLOR[l].r = fade_r;
					fade_COLOR[l].g = fade_g;
					fade_COLOR[l].b = fade_b;
				}

		#endif
	//------------------------------------------


	//------------------------------------------
	//init sound
	//------------------------------------------

		//sound---------------------------------
		#ifdef MIX_ON
			Mix_Chunk* wheel_sound_WAV;
			Mix_Chunk* action_pressed_WAV;
			Mix_Chunk* welcome_WAV;
			Mix_Music* background_MUS = NULL;
		#endif

		#ifdef MIX_ON

		Mix_OpenAudio(22050, AUDIO_S16, 2, 1024);//MIX_DEFAULT_FORMAT
		Mix_AllocateChannels(16);

		action_pressed_WAV = Mix_LoadWAV("data/sfx/action_pressed.wav");
		wheel_sound_WAV = Mix_LoadWAV("data/sfx/wheel_turn.wav");
		welcome_WAV = Mix_LoadWAV("data/sfx/welcometobobsgame.wav");
		background_MUS = Mix_LoadMUS("data/sfx/bg.ogg");
		Mix_PlayMusic(background_MUS,-1);
		#endif
	//------------------------------------------




	///======================================================================
	while(quit==0) ///DO GAME LOOP
	{///======================================================================


		begin_render_loop();


		check_keys();

		static int action_fade=0;

		//------------------------------------------
		//do wheel sound
		//------------------------------------------
		#ifdef MIX_ON
		if(wheel_sound_queue>0)
		{
			Mix_PlayChannel(-1, wheel_sound_WAV, wheel_sound_queue-1);
			wheel_sound_queue=0;
		}
		if(action_pressed==1)
		{
			action_pressed=0;

			if(selected_wheel_item==1)
			{
				Mix_PlayChannel(-1, action_pressed_WAV, 0);
				action_fade=1;
			}
		}

		#endif
		//------------------------------------------

		//------------------------------------------
		//draw background png to temp surface
		//------------------------------------------
		//SDL_BlitSurface(bg_SURFACE,0,bg_temp_SURFACE,0);
		draw_texture(bg_TEXTURE,bg_offset.x,bg_offset.y);
		//------------------------------------------

		//------------------------------------------
		//draw background glow to temp surface
		//------------------------------------------
		int f=0;
		for(f=0;f<bg_glow_amt;f++)
		{
			if(bg_glow_frame[f]!=0)draw_texture(bg_glow_TEXTURE[bg_glow_frame[f]-1],bg_offset.x+bg_glow_offset[f].x,bg_offset.y+bg_glow_offset[f].y);
		}
		//------------------------------------------

		//------------------------------------------
		//draw temp surface to screen
		//------------------------------------------
		//SDL_BlitSurface(bg_temp_TEXTURE,&bg_offset,screen_TEXTURE,0);
		//------------------------------------------

		//------------------------------------------
		//set the bg glow frames
		//------------------------------------------
			current_ticks = SDL_GetTicks();
			for(f=0;f<bg_glow_amt;f++)
			{

				if(current_ticks>bg_glow_ticks[f]+20)//+bg_glow_timer[f])
				{
					bg_glow_ticks[f]=current_ticks;

					//get the previous glowtile
					int p=0;
					p=f+1;
					if(p>=bg_glow_amt)p=0;

					if(bg_glow_started[f]==0)
					{
						//if previous is at frame 9, set to started.
						if(bg_glow_frame[p]>20/bg_glow_amt)bg_glow_started[f]=1;
					}


					if(bg_glow_started[f]==1)
					{
						bg_glow_frame[f]++;
						if(bg_glow_frame[f]>=20)
						{
							bg_glow_frame[f]=0;

							//follow the previous tile for snake-like movement.
							if(rand()%2==0){bg_glow_offset[f].y=bg_glow_offset[p].y+32;bg_glow_offset[f].x=bg_glow_offset[p].x;}//down
							else{bg_glow_offset[f].x=bg_glow_offset[p].x+32;bg_glow_offset[f].y=bg_glow_offset[p].y;}//right
							//bg_glow_offset[f].y=bg_glow_offset[p].y-32;//up
							//bg_glow_offset[f].x=bg_glow_offset[p].x-32;//left

							//wrap around
							if(bg_glow_offset[f].x>32*12)bg_glow_offset[f].x=0;
							if(bg_glow_offset[f].x<0)bg_glow_offset[f].x=32*12;
							if(bg_glow_offset[f].y>32*10)bg_glow_offset[f].y=0;
							if(bg_glow_offset[f].y<0)bg_glow_offset[f].y=32*10;

							//pick a random tile
							//bg_glow_offset[f].x=((rand()%13)*32);
							//bg_glow_offset[f].y=((rand()%11)*32);

							//bg_glow_ticks[f]+=(500+rand()%2000);

						}
					}
				}
			}
		//------------------------------------------

		//------------------------------------------
		//set the bg scrolling
		//------------------------------------------
			current_ticks = SDL_GetTicks();
			if(current_ticks>bg_ticks+20)//10
			{
				bg_ticks=current_ticks;

				bg_offset.x--;
				bg_offset.y--;

				if(bg_offset.x<=-64||bg_offset.y<=-64)
				{
					bg_offset.x=0;
					bg_offset.y=0;

					//move the glow offsets when the bg loops
					for(f=0;f<bg_glow_amt;f++)
					{
						bg_glow_offset[f].x-=64;
						bg_glow_offset[f].y-=64;
						if(bg_glow_offset[f].x<0)bg_glow_offset[f].x+=12*32;
						if(bg_glow_offset[f].y<0)bg_glow_offset[f].y+=10*32;
					}
				}
			}



		static int show_movie=0;
		static int movie_selected=1;
		static int direction_button_unpressed=0;

		static int cart_slide_x=0;

		//------------------------------------------
		//check for direction buttons being pressed
		//------------------------------------------
		if(down_pressed==1||left_pressed==1||up_pressed==1||right_pressed==1)
		{
			direction_button_pressed=1;
			cart_slide_x=0;
		}
		else
		{
			if(direction_button_pressed==1)
			{
				direction_button_unpressed=1;
			}
			direction_button_pressed=0;
			if(cart_slide_x<10)cart_slide_x+=2;
			if(cart_slide_x>10)cart_slide_x=10;
		}

		//------------------------------------------
		//do movie scrolling
		//------------------------------------------
		current_ticks = SDL_GetTicks();
		if(current_ticks>movie_scroll_ticks)
		{
			movie_scroll_ticks=current_ticks;

			if(direction_button_pressed==0)
			{
				//slide up from bottom left
				//if(movie_x<0)movie_x+=16;
				//if(movie_y>240-movie_YUV_SURFACE[movie_selected]->h)movie_y-=16;
				//if(movie_x>0)movie_x=0;
				//if(movie_y<240-movie_YUV_SURFACE[movie_selected]->h)movie_y=240-movie_YUV_SURFACE[movie_selected]->h;

				//slide up from top left
				if(movie_x<0)movie_x+=16;
				if(movie_y<0)movie_y+=16;
				if(movie_x>0)movie_x=0;
				if(movie_y>0)movie_y=0;
			}

		}

		//------------------------------------------
		//play movie
		//------------------------------------------
		current_ticks = SDL_GetTicks();
		if(current_ticks>movie_play_ticks)
		{
			movie_play_ticks=current_ticks;
			//SDL_LockMutex(movie_MUTEX);



			//step 1: render a frame from mpeg stream to YUV surface
			if(movie_render_step==0&&movie_x==0&&movie_y==0)//240-movie_YUV_SURFACE[movie_selected]->h)
			{
				SMPEG_renderFrame(movie[movie_selected],movie_frame_num);
				movie_frame_num++;

				movie_render_step++;
				if(movie_render_step>=3)movie_render_step=0;
			}
			else
			//step 2: convert YUV surface to RGBA surface
			if(movie_render_step==1)
			{

				if(movie_RGBA_SURFACE==NULL)
				{
					movie_RGBA_SURFACE = SDL_CreateRGBSurface(SDL_SWSURFACE, power_of_two(movie_YUV_SURFACE[movie_selected]->w), power_of_two(movie_YUV_SURFACE[movie_selected]->h), 32, rmask, gmask, bmask, amask);
				}

				SDL_Rect area = {0,0,0,0};
				area.w = movie_YUV_SURFACE[movie_selected]->w;
				area.h = movie_YUV_SURFACE[movie_selected]->h;
				SDL_SetAlpha(movie_YUV_SURFACE[movie_selected], 0, 0);
				SDL_BlitSurface(movie_YUV_SURFACE[movie_selected], &area, movie_RGBA_SURFACE, NULL);

				movie_render_step++;
				if(movie_render_step>=3)movie_render_step=0;
			}
			else
			//step 3: convert RGBA surface to texture
			if(movie_render_step==2)
			{

				if(movieswapframe==0){movieswapframe=1;movieswapframe_opposite=0;}
				else {movieswapframe=0;movieswapframe_opposite=1;}

				movie_TEXTURE[movieswapframe] = load_texture_directly_from_square_surface(movie_RGBA_SURFACE);
				if(movie_TEXTURE[movieswapframe_opposite]!=NULL)delete_texture(movie_TEXTURE[movieswapframe_opposite]);

				movie_render_step++;
				if(movie_render_step>=3)movie_render_step=0;
			}
			//SDL_UnlockMutex(movie_MUTEX);
		}

		static int movie_border_frame=0;
		static int movie_border_ticks=0;

		//draw texture onto screen if it exists
		if(movie_TEXTURE[movieswapframe]!=NULL)
		if(glIsTexture(movie_TEXTURE[movieswapframe]->texture_id))
		{
			draw_texture(movie_TEXTURE[movieswapframe],movie_x+4,movie_y+4);
			draw_texture(movie_border_TEXTURE[movie_border_frame],movie_x,movie_y);
		}


		current_ticks = SDL_GetTicks();
		if(current_ticks>=movie_border_ticks+100)
		{
			movie_border_ticks=current_ticks;
			movie_border_frame++;
			if(movie_border_frame>12)movie_border_frame=0;
		}

		//if the wheel item changes, set the movie offscreen so it can slide back in
		if(direction_button_pressed==1 || show_movie==0)
		{

			infopanel_x=0-infopanel_TEXTURE->image_w;
			infopanel_y=(240-infopanel_TEXTURE->image_h)+infopanel_TEXTURE->image_w;

			movie_x=0-(movie_YUV_SURFACE[movie_selected]->w+8);
			movie_y=0-(movie_YUV_SURFACE[movie_selected]->w+8);//(240-movie_YUV_SURFACE[movie_selected]->h)+movie_YUV_SURFACE[movie_selected]->w;
			movie_render_step=0;
		}

		//if the direction button is let up, set the frame to 1 and render a new frame of the selected item movie
		//set step to 1 so it makes the rgba surface next loop
		if(direction_button_unpressed==1)
		{

			if(selected_wheel_item==1)show_movie=1;else show_movie=0;

			direction_button_unpressed=0;
			//movie_selected=selected_wheel_item%4;
			movie_frame_num=1;
			SMPEG_renderFrame(movie[movie_selected],movie_frame_num);
			if(movie_RGBA_SURFACE!=NULL){SDL_FreeSurface(movie_RGBA_SURFACE);movie_RGBA_SURFACE=NULL;}
			movie_render_step=1;
		}




		//------------------------------------------
		//do wheel movement
		//------------------------------------------
		current_ticks = SDL_GetTicks();
		if(current_ticks>=last_ticks+5) //limit move/render speed (slow it down for windows)
		{
			last_ticks=current_ticks;

			//------------------------------------------
			//this makes the wheel spin faster based on the distance of the selected item
			//------------------------------------------
			#ifdef BUILD_WIZ
			int wheel_speed_limit=2;//set amount of pixels per frame to move wheel (speed it up for wiz)
			int distance_multiplier=4;
			#else
			int wheel_speed_limit=1;//set amount of pixels per frame to move wheel (speed it up for wiz)
			int distance_multiplier=3;
			#endif

			//------------------------------------------
			//find current wheel item
			//------------------------------------------
				//int center_wheel_item=0;
				//int q=0;
				//for(q=0;q<loaded_wheel_items;q++)
				//{
					//if(SCREEN_SIZE_Y/2>=wheel_item[q].y&&SCREEN_SIZE_Y/2<=wheel_item[q].y+cart_label_height)
					//{center_wheel_item=q;break;}
				//}


			//------------------------------------------
			//find the distance in pixels for total travel of center wheel item to selected wheel item
			//------------------------------------------
				int distance=1;
				//distance = abs(selected_wheel_item-center_wheel_item);
				if(wheel_spin_direction==CLOCKWISE)
				{
					//if the selected item is below the midpoint, the distance is just the difference between the two
					if(wheel_item[selected_wheel_item].y>=(SCREEN_SIZE_Y/2)-(cart_label_height/2))
					{
						distance=wheel_item[selected_wheel_item].y-((SCREEN_SIZE_Y/2)-(cart_label_height/2));
					}//if its above it, it has to wrap back to the top and up from the bottom
					else if(wheel_item[selected_wheel_item].y<(SCREEN_SIZE_Y/2-(cart_label_height/2)))
					{
						distance=wheel_item[selected_wheel_item].y+cart_label_height+((SCREEN_SIZE_Y/2)+(cart_label_height/2));
					}
				}

				if(wheel_spin_direction==COUNTERCLOCKWISE)
				{
					//if the selected item is above the midpoint, the distance is just the difference between the twi
					if(wheel_item[selected_wheel_item].y<=SCREEN_SIZE_Y/2-(cart_label_height/2))
					{
						distance=((SCREEN_SIZE_Y/2)-(cart_label_height/2))-wheel_item[selected_wheel_item].y;
					}//if its below it, it has to wrap down to the bottom and from the top of the screen
					else if(wheel_item[selected_wheel_item].y>SCREEN_SIZE_Y/2-(cart_label_height/2))
					{
						distance=(SCREEN_SIZE_Y-wheel_item[selected_wheel_item].y)+(((SCREEN_SIZE_Y/2)-(cart_label_height/2))+cart_label_height);
					}
				}
				df = (float)distance/(float)cart_label_height;
			//------------------------------------------

			//------------------------------------------
			//do the wheel movement, speed is based on distance calculated above
			//------------------------------------------
			int wheel_speed_count=0;
			for(wheel_speed_count=0;wheel_speed_count<=wheel_speed_limit*(distance_multiplier*df);wheel_speed_count++)
			{
				//------------------------------------------
				//find the current center wheel item to set the wheel speed
				//------------------------------------------
					//for(q=0;q<loaded_wheel_items;q++)
					//{
						//if(SCREEN_SIZE_Y/2>=wheel_item[q].y&&SCREEN_SIZE_Y/2<=wheel_item[q].y+cart_label_height)
						//{center_wheel_item=q;break;}
					//}
				//------------------------------------------

				//------------------------------------------
				//find the distance in pixels for total travel of center wheel item to selected wheel item
				//------------------------------------------
					if(wheel_spin_direction==CLOCKWISE)
					{
						//if the selected item is below the midpoint, the distance is just the difference between the twi
						if(wheel_item[selected_wheel_item].y>=(SCREEN_SIZE_Y/2)-(cart_label_height/2))
						{
							distance=wheel_item[selected_wheel_item].y-((SCREEN_SIZE_Y/2)-(cart_label_height/2));
						}//if its above it, it has to wrap back to the top and up from the bottom
						else if(wheel_item[selected_wheel_item].y<(SCREEN_SIZE_Y/2-(cart_label_height/2)))
						{
							distance=wheel_item[selected_wheel_item].y+cart_label_height+((SCREEN_SIZE_Y/2)+(cart_label_height/2));
						}
					}

					if(wheel_spin_direction==COUNTERCLOCKWISE)
					{
						//if the selected item is above the midpoint, the distance is just the difference between the twi
						if(wheel_item[selected_wheel_item].y<=SCREEN_SIZE_Y/2-(cart_label_height/2))
						{
							distance=((SCREEN_SIZE_Y/2)-(cart_label_height/2))-wheel_item[selected_wheel_item].y;
						}//if its below it, it has to wrap down to the bottom and from the top of the screen
						else if(wheel_item[selected_wheel_item].y>SCREEN_SIZE_Y/2-(cart_label_height/2))
						{
							distance=(SCREEN_SIZE_Y-wheel_item[selected_wheel_item].y)+(((SCREEN_SIZE_Y/2)-(cart_label_height/2))+cart_label_height);
						}
					}
					df = (float)distance/(float)cart_label_height;
				//------------------------------------------


				//------------------------------------------
				//if the selected wheel item isnt centered on the wheel
				//------------------------------------------
				if(wheel_item[selected_wheel_item].y+(cart_label_height/2)!=SCREEN_SIZE_Y/2)
				{
					wheel_spinning=1;
					//------------------------------------------
					//move all the items up or down based on the direction the wheel is spinning
					//(this is so you can immediately change direction while the wheel is turning)
					//------------------------------------------
						int pixels=0;
						int c=0;
						if(wheel_spin_direction==CLOCKWISE)
						{
							pixels=-1;
							for(c=0;c<loaded_wheel_items;c++)wheel_item[c].y+=pixels;
						}
						if(wheel_spin_direction==COUNTERCLOCKWISE)
						{
							pixels=1;;
							for(c=0;c<loaded_wheel_items;c++)wheel_item[c].y+=pixels;
						}
					//------------------------------------------


					//if the wheel is going clockwise
					//find the bottom-most wheel item
					//if it is less than SCREEN_SIZE_Y-cartsizey
					//take the top one, set to bottom most + cart size y
					//or for neat slide effect, move it up until it is above 0-cartsizey
					//then set it to SCREEN_SIZE_Y and catch up to the bottom-most

					//if the wheel is going counterclockwise
					//find the topmost wheel item
					//if it is more than 0+cartsizey
					//take the bottom one, move it down until it is below SCREEN_SIZE_Y
					//then set it to 0-cartsize and catch up to the topmost

					//------------------------------------------
					//find topmost and bottommost
					//------------------------------------------
						int bottomy=0;
						int topy=SCREEN_SIZE_Y;
						int bottomc=0;
						int topc=SCREEN_SIZE_Y;

						for(c=0;c<loaded_wheel_items;c++)
						{
							if(wheel_item[c].y>bottomy){bottomy=wheel_item[c].y;bottomc=c;}
							if(wheel_item[c].y<topy){topy=wheel_item[c].y;topc=c;}
						}
					//------------------------------------------

					//if an item wraps off the screen, wrap it on the other side
					if(wheel_spin_direction==CLOCKWISE)
					{
						if(wheel_item[bottomc].y<SCREEN_SIZE_Y-cart_label_height
							&&
							wheel_item[topc].y<=0-cart_label_height)
						{
							//if there are more items than the screen can fit, append to the bottommost item, else just append to the bottom of the screen
							if(wheel_item[bottomc].y+cart_label_height>=SCREEN_SIZE_Y)
								wheel_item[topc].y=wheel_item[bottomc].y+cart_label_height;
							else wheel_item[topc].y=SCREEN_SIZE_Y;
						}
					}

					if(wheel_spin_direction==COUNTERCLOCKWISE)
					{
						if(wheel_item[topc].y>0
							&&
							wheel_item[bottomc].y>=SCREEN_SIZE_Y)
						{
							if(wheel_item[topc].y-cart_label_height<=0-cart_label_height)
								wheel_item[bottomc].y=wheel_item[topc].y-cart_label_height;
							else wheel_item[bottomc].y=0-cart_label_height;

						}
					}
				}
				else wheel_spinning=0;
			}
			//------------------------------------------
		}

		//SDL_FillRect(screen_TEXTURE,NULL,screen_fill_color);

		//zoomlabel_SURFACE = zoomSurface(label_SURFACE[(5+selected_wheel_item)%4], 2., 2., 0);
		//SDL_BlitSurface(zoomlabel_SURFACE,NULL,screen_SURFACE,&biglabeloffset);

#ifdef TTF_ON
		//strcpy(text,"Selected: ");
		//strcat(text,itoa(selected_wheel_item));


		//zoom in infopanel
		current_ticks = SDL_GetTicks();
		if(current_ticks>infopanel_scroll_ticks)
		{
			infopanel_scroll_ticks=current_ticks;

			if(direction_button_pressed==0)
			{
				//slide up from bottom left
				if(infopanel_x<0)infopanel_x+=16;
				if(infopanel_y>240-infopanel_TEXTURE->image_h)infopanel_y-=16;
				if(infopanel_x>0)infopanel_x=0;
				if(infopanel_y<240-infopanel_TEXTURE->image_h)infopanel_y=240-infopanel_TEXTURE->image_h;
			}
		}

		//animate border
		static int infopanel_border_frame=0;
		static int infopanel_border_ticks=0;

		//draw texture onto screen if it exists
		{
			draw_texture(infopanel_TEXTURE,infopanel_x,infopanel_y);
			draw_texture(infopanel_border_TEXTURE[infopanel_border_frame],infopanel_x,infopanel_y);
		}


		current_ticks = SDL_GetTicks();
		if(current_ticks>=infopanel_border_ticks+150)
		{
			infopanel_border_ticks=current_ticks;
			infopanel_border_frame++;
			if(infopanel_border_frame>7)infopanel_border_frame=0;
		}

		//sprint labels into char arrays
			sprintf(text_Game,"  %s",wheel_item[selected_wheel_item].name);
			sprintf(text_Author,"  \"bob\"");
			sprintf(text_TimePlayed,"  99:99");
			sprintf(text_LastPlayed,"  2011-07-01 12:01 AM");

			sprintf(text_Game_Label,"Game");
			sprintf(text_Author_Label,"Author");
			sprintf(text_TimePlayed_Label,"Time Played");
			sprintf(text_LastPlayed_Label,"Last Played");

		//if surface delete surface
			if(text_Game_SURFACE!=NULL){SDL_FreeSurface(text_Game_SURFACE);text_Game_SURFACE=NULL;}
			if(text_Author_SURFACE!=NULL){SDL_FreeSurface(text_Author_SURFACE);text_Author_SURFACE=NULL;}
			if(text_TimePlayed_SURFACE!=NULL){SDL_FreeSurface(text_TimePlayed_SURFACE);text_TimePlayed_SURFACE=NULL;}
			if(text_LastPlayed_SURFACE!=NULL){SDL_FreeSurface(text_LastPlayed_SURFACE);text_LastPlayed_SURFACE=NULL;}

			if(text_Game_Label_SURFACE!=NULL){SDL_FreeSurface(text_Game_Label_SURFACE);text_Game_Label_SURFACE=NULL;}
			if(text_Author_Label_SURFACE!=NULL){SDL_FreeSurface(text_Author_Label_SURFACE);text_Author_Label_SURFACE=NULL;}
			if(text_TimePlayed_Label_SURFACE!=NULL){SDL_FreeSurface(text_TimePlayed_Label_SURFACE);text_TimePlayed_Label_SURFACE=NULL;}
			if(text_LastPlayed_Label_SURFACE!=NULL){SDL_FreeSurface(text_LastPlayed_Label_SURFACE);text_LastPlayed_Label_SURFACE=NULL;}

		static int fadecolor1=0;
		static int fadecolor2=63;
		static int fadecolor3=127;
		static int fadecolor4=191;
		fadecolor1+=2;
		fadecolor2+=2;
		fadecolor3+=2;
		fadecolor4+=2;
		if(fadecolor1>255)fadecolor1=0;
		if(fadecolor2>255)fadecolor2=0;
		if(fadecolor3>255)fadecolor3=0;
		if(fadecolor4>255)fadecolor4=0;


		//render text onto surface
			text_Game_SURFACE=TTF_RenderText_Solid(font_bobsgame_8px,text_Game,wheel_item[selected_wheel_item].color);
			text_Author_SURFACE=TTF_RenderText_Solid(font_bobsgame_8px,text_Author,white_COLOR);
			text_TimePlayed_SURFACE=TTF_RenderText_Solid(font_bobsgame_8px,text_TimePlayed,white_COLOR);
			text_LastPlayed_SURFACE=TTF_RenderText_Solid(font_bobsgame_8px,text_LastPlayed,white_COLOR);

			text_Game_Label_SURFACE=TTF_RenderText_Solid(font_bobsgame_8px,text_Game_Label,fade_COLOR[fadecolor1]);
			text_Author_Label_SURFACE=TTF_RenderText_Solid(font_bobsgame_8px,text_Author_Label,fade_COLOR[fadecolor2]);
			text_TimePlayed_Label_SURFACE=TTF_RenderText_Solid(font_bobsgame_8px,text_TimePlayed_Label,fade_COLOR[fadecolor3]);
			text_LastPlayed_Label_SURFACE=TTF_RenderText_Solid(font_bobsgame_8px,text_LastPlayed_Label,fade_COLOR[fadecolor4]);

		//if texture delete texture
			if(text_Game_TEXTURE!=NULL){delete_texture(text_Game_TEXTURE);text_Game_TEXTURE=NULL;}
			if(text_Author_TEXTURE!=NULL){delete_texture(text_Author_TEXTURE);text_Author_TEXTURE=NULL;}
			if(text_TimePlayed_TEXTURE!=NULL){delete_texture(text_TimePlayed_TEXTURE);text_TimePlayed_TEXTURE=NULL;}
			if(text_LastPlayed_TEXTURE!=NULL){delete_texture(text_LastPlayed_TEXTURE);text_LastPlayed_TEXTURE=NULL;}

			if(text_Game_Label_TEXTURE!=NULL){delete_texture(text_Game_Label_TEXTURE);text_Game_Label_TEXTURE=NULL;}
			if(text_Author_Label_TEXTURE!=NULL){delete_texture(text_Author_Label_TEXTURE);text_Author_Label_TEXTURE=NULL;}
			if(text_TimePlayed_Label_TEXTURE!=NULL){delete_texture(text_TimePlayed_Label_TEXTURE);text_TimePlayed_Label_TEXTURE=NULL;}
			if(text_LastPlayed_Label_TEXTURE!=NULL){delete_texture(text_LastPlayed_Label_TEXTURE);text_LastPlayed_Label_TEXTURE=NULL;}

		//load texture from surface
			text_Game_TEXTURE=load_texture_from_non_square_surface(text_Game_SURFACE);
			text_Author_TEXTURE=load_texture_from_non_square_surface(text_Author_SURFACE);
			text_TimePlayed_TEXTURE=load_texture_from_non_square_surface(text_TimePlayed_SURFACE);
			text_LastPlayed_TEXTURE=load_texture_from_non_square_surface(text_LastPlayed_SURFACE);

			text_Game_Label_TEXTURE=load_texture_from_non_square_surface(text_Game_Label_SURFACE);
			text_Author_Label_TEXTURE=load_texture_from_non_square_surface(text_Author_Label_SURFACE);
			text_TimePlayed_Label_TEXTURE=load_texture_from_non_square_surface(text_TimePlayed_Label_SURFACE);
			text_LastPlayed_Label_TEXTURE=load_texture_from_non_square_surface(text_LastPlayed_Label_SURFACE);

		//draw texture

			draw_texture(text_Game_Label_TEXTURE,infopanel_x+6,infopanel_y+6+12*0);
			draw_texture(text_Game_TEXTURE,infopanel_x+6,infopanel_y+6+12*1);

			draw_texture(text_Author_Label_TEXTURE,infopanel_x+6,infopanel_y+6+12*2);
			draw_texture(text_Author_TEXTURE,infopanel_x+6,infopanel_y+6+12*3);

			draw_texture(text_TimePlayed_Label_TEXTURE,infopanel_x+6,infopanel_y+6+12*4);
			draw_texture(text_TimePlayed_TEXTURE,infopanel_x+6,infopanel_y+6+12*5);

			draw_texture(text_LastPlayed_Label_TEXTURE,infopanel_x+6,infopanel_y+6+12*6);
			draw_texture(text_LastPlayed_TEXTURE,infopanel_x+6,infopanel_y+6+12*7);






#endif

		SDL_Rect selection_box_offset = {0,0,0,0};

		//------------------------------------------
		//set the alpha value to fade the selected item in and out
		//------------------------------------------
		current_ticks = SDL_GetTicks();
#ifndef BUILD_WIZ
		if(current_ticks>highlight_ticks+20)
#endif
		{
			highlight_ticks=current_ticks;

			if(highlight_dir==1)
			{
				highlight_color-=32;
				if(highlight_color<=0){highlight_color=0;highlight_dir=0;}
			}
			else
			if(highlight_dir==0)
			{
				highlight_color+=32;
				if(highlight_color>=255){highlight_color=255;highlight_dir=1;}
			}
		}

		//------------------------------------------
		//draw each wheel item
		//------------------------------------------
			int c=0;
			for(c=0;c<loaded_wheel_items;c++)
			{

				//------------------------------------------
				//set position
				//------------------------------------------
				SDL_Rect cart_offset = {0,0,0,0};

				cart_offset.y = wheel_item[c].y;//(y%cart_size_y)+((c-1)*cart_size_y);
				cart_offset.x = (SCREEN_SIZE_X/2)+30-(40*sin((float)(((cart_offset.y+2))/66.)));

				//------------------------------------------
				//slide out selected item
				//------------------------------------------
				if(c==selected_wheel_item)
				{
					cart_offset.x-=cart_slide_x;

					selection_box_offset.x=cart_offset.x;
					selection_box_offset.y=cart_offset.y;
				}

				//------------------------------------------
				//draw item background graphic
				//------------------------------------------
				draw_texture(cart_TEXTURE,cart_offset.x,cart_offset.y);


				//------------------------------------------
				//draw wheel item label
				//------------------------------------------

				SDL_Rect label_offset = {0,0,0,0};

				label_offset.x = cart_offset.x+cart_offset_x;
				label_offset.y = cart_offset.y+cart_offset_y;

				draw_texture(wheel_item[c].label_TEXTURE,label_offset.x,label_offset.y);

				//------------------------------------------
				//draw shiny overlay
				//------------------------------------------

				SDL_Rect labelfade_offset = {0,0,0,0};

				labelfade_offset.x = label_offset.x;
				labelfade_offset.y = label_offset.y;

				if(c==selected_wheel_item)
				{

					if(selected_wheel_item==1)draw_texture_alpha(wheel_item[c].label_glow_TEXTURE,label_offset.x,label_offset.y,1.-(float)(highlight_color/255.));
					draw_texture_alpha(labelfade_TEXTURE,labelfade_offset.x,labelfade_offset.y,highlight_color/255.);
				}
				else
				{
					draw_texture(labelfade_TEXTURE,labelfade_offset.x,labelfade_offset.y);
				}
		}

		//------------------------------------------
		//draw selection box
		//------------------------------------------
		static int selection_box_frame=0;
		static int selection_box_ticks=0;

		if(selection_box_on==1)
		{
			draw_texture(selection_box_TEXTURE[selection_box_frame],selection_box_offset.x,selection_box_offset.y);

			current_ticks=SDL_GetTicks();
			if(current_ticks>selection_box_ticks+20)
			{
				selection_box_ticks=current_ticks;
				selection_box_frame++;
				if(selection_box_frame>14)selection_box_frame=0;
			}
		}

		//------------------------------------------
		//do fade out if selected item
		//------------------------------------------
			static int action_fade_color=0;

			if(action_fade==1)
			{
				action_fade_color=255;
				action_fade=2;
			}

			if(action_fade==2)//flash white, fade to transparent
			{

				fill_rect(0,0,320,240,255.,255.,255.,action_fade_color/255.0);
				action_fade_color-=16;
				if(action_fade_color<0)
				{
					action_fade_color=0;
					Mix_PlayChannel(-1, welcome_WAV, 0);
					action_fade=3;
				}
			}

			if(action_fade==3)//fade to white
			{

				fill_rect(0,0,320,240,255.,255.,255.,action_fade_color/255.0);
				action_fade_color+=8;
				if(action_fade_color>255)
				{
					action_fade_color=0;
					action_fade=4;
				}
			}

			if(action_fade==4)//fade from white to black, fade out music
			{
				fill_rect(0,0,320,240,255.,255.,255.,1);
				fill_rect(0,0,320,240,0.,0.,0.,action_fade_color/255.0);

				action_fade_color+=8;
				if(action_fade_color>255)
				{
					action_fade_color=0;

					#ifdef MIX_ON
					if(Mix_PlayingMusic())
					{
						Mix_FadeOutMusic(1000);
					}
					#endif

					action_fade=5;
				}
			}

			if(action_fade==5) //draw game title on black screen and wait
			{
				//fill black
				fill_rect(0,0,320,240,0.,0.,0.,1);
				//draw game title
				draw_texture(wheel_item[selected_wheel_item].label_TEXTURE,SCREEN_SIZE_X/2-wheel_item[selected_wheel_item].label_TEXTURE->image_w/2,SCREEN_SIZE_Y/2-wheel_item[selected_wheel_item].label_TEXTURE->image_h/2);

				//draw game title glow
				draw_texture_alpha(wheel_item[selected_wheel_item].label_glow_TEXTURE,SCREEN_SIZE_X/2-wheel_item[selected_wheel_item].label_TEXTURE->image_w/2,SCREEN_SIZE_Y/2-wheel_item[selected_wheel_item].label_TEXTURE->image_h/2,action_fade_color/255.);


				//set glow alpha
				static int fade_dir=0;
				if(fade_dir==0)
				{
					action_fade_color+=4;
					if(action_fade_color>255){action_fade_color=255;fade_dir=1;}
				}

				if(fade_dir==1)
				{
					action_fade_color-=4;
					if(action_fade_color<0){action_fade_color=0;fade_dir=0;}
				}



				static int fadeout_timer=0;
				if(fadeout_timer==0)fadeout_timer = SDL_GetTicks();

				if(SDL_GetTicks()>fadeout_timer+3000&&action_fade_color==0)
				{
					action_fade_color=0;
					action_fade=6;
				}
			}

			if(action_fade==6) //fade out game title to black
			{

				fill_rect(0,0,320,240,0.,0.,0.,1);
				draw_texture(wheel_item[selected_wheel_item].label_TEXTURE,SCREEN_SIZE_X/2-wheel_item[selected_wheel_item].label_TEXTURE->image_w/2,SCREEN_SIZE_Y/2-wheel_item[selected_wheel_item].label_TEXTURE->image_h/2);
				fill_rect(0,0,320,240,0.,0.,0.,action_fade_color/255.0);

				action_fade_color+=4;

				if(action_fade_color>255)
				{
					action_fade_color=0;
					action_fade=7;
				}
			}

			if(action_fade==7) //draw black, quit
			{

				fill_rect(0,0,320,240,0.,0.,0.,1);
				quit=1;
				bobsgame=1;

			}

		finish_render_loop();

		frames_total_count++;

		//#ifdef TTF_ON
		//SDL_FreeSurface(font_SURFACE);
		//#endif

		//SDL_Delay( 50 );
        //int ticks = SDL_GetTicks();
		//int tickspassed = ticks-timer_ticks;
		//timer_ticks=ticks;
		//int time=16-(tickspassed%16);
		//if(time>0)SDL_Delay(time);//Sleep()

	}



	//SMPEG_delete(movie[0]);
	SMPEG_delete(movie[1]);
	//SMPEG_delete(movie[2]);
	//SMPEG_delete(movie[3]);

	//SDL_FreeSurface(movie_YUV_SURFACE[0]);
	SDL_FreeSurface(movie_YUV_SURFACE[1]);
	//SDL_FreeSurface(movie_YUV_SURFACE[2]);
	//SDL_FreeSurface(movie_YUV_SURFACE[3]);

	SDL_FreeSurface(movie_RGBA_SURFACE);



int t=0;


if(cart_TEXTURE!=NULL){delete_texture(cart_TEXTURE);cart_TEXTURE=NULL;}

if(labelfade_TEXTURE!=NULL){delete_texture(labelfade_TEXTURE);labelfade_TEXTURE=NULL;}

for(t=0;t<15;t++)if(selection_box_TEXTURE[t]!=NULL){delete_texture(selection_box_TEXTURE[t]);selection_box_TEXTURE[t]=NULL;}

if(bg_TEXTURE!=NULL){delete_texture(bg_TEXTURE);bg_TEXTURE=NULL;}

for(t=0;t<10;t++)if(bg_glow_TEXTURE[t]!=NULL){delete_texture(bg_glow_TEXTURE[t]);bg_glow_TEXTURE[t]=NULL;}

for(t=0;t<13;t++)if(movie_border_TEXTURE[t]!=NULL){delete_texture(movie_border_TEXTURE[t]);movie_border_TEXTURE[t]=NULL;}

for(t=0;t<2;t++)if(movie_TEXTURE[t]!=NULL){delete_texture(movie_TEXTURE[t]);movie_TEXTURE[t]=NULL;}


if(infopanel_TEXTURE!=NULL){delete_texture(infopanel_TEXTURE);infopanel_TEXTURE=NULL;}

for(t=0;t<8;t++)if(infopanel_border_TEXTURE[t]!=NULL){delete_texture(infopanel_border_TEXTURE[t]);infopanel_border_TEXTURE[t]=NULL;}



	if(text_Game_TEXTURE!=NULL){delete_texture(text_Game_TEXTURE);text_Game_TEXTURE=NULL;}
	if(text_Author_TEXTURE!=NULL){delete_texture(text_Author_TEXTURE);text_Author_TEXTURE=NULL;}
	if(text_TimePlayed_TEXTURE!=NULL){delete_texture(text_TimePlayed_TEXTURE);text_TimePlayed_TEXTURE=NULL;}
	if(text_LastPlayed_TEXTURE!=NULL){delete_texture(text_LastPlayed_TEXTURE);text_LastPlayed_TEXTURE=NULL;}

	if(text_Game_Label_TEXTURE!=NULL){delete_texture(text_Game_Label_TEXTURE);text_Game_Label_TEXTURE=NULL;}
	if(text_Author_Label_TEXTURE!=NULL){delete_texture(text_Author_Label_TEXTURE);text_Author_Label_TEXTURE=NULL;}
	if(text_TimePlayed_Label_TEXTURE!=NULL){delete_texture(text_TimePlayed_Label_TEXTURE);text_TimePlayed_Label_TEXTURE=NULL;}
	if(text_LastPlayed_Label_TEXTURE!=NULL){delete_texture(text_LastPlayed_Label_TEXTURE);text_LastPlayed_Label_TEXTURE=NULL;}

	//if surface delete surface
	if(text_Game_SURFACE!=NULL){SDL_FreeSurface(text_Game_SURFACE);text_Game_SURFACE=NULL;}
	if(text_Author_SURFACE!=NULL){SDL_FreeSurface(text_Author_SURFACE);text_Author_SURFACE=NULL;}
	if(text_TimePlayed_SURFACE!=NULL){SDL_FreeSurface(text_TimePlayed_SURFACE);text_TimePlayed_SURFACE=NULL;}
	if(text_LastPlayed_SURFACE!=NULL){SDL_FreeSurface(text_LastPlayed_SURFACE);text_LastPlayed_SURFACE=NULL;}

	if(text_Game_Label_SURFACE!=NULL){SDL_FreeSurface(text_Game_Label_SURFACE);text_Game_Label_SURFACE=NULL;}
	if(text_Author_Label_SURFACE!=NULL){SDL_FreeSurface(text_Author_Label_SURFACE);text_Author_Label_SURFACE=NULL;}
	if(text_TimePlayed_Label_SURFACE!=NULL){SDL_FreeSurface(text_TimePlayed_Label_SURFACE);text_TimePlayed_Label_SURFACE=NULL;}
	if(text_LastPlayed_Label_SURFACE!=NULL){SDL_FreeSurface(text_LastPlayed_Label_SURFACE);text_LastPlayed_Label_SURFACE=NULL;}


	deinit_gl();

	//------------------------------------------
	//deinit sdl stuff
	//------------------------------------------
		if(joystick)
		{
			SDL_JoystickClose(joystick);
		}



		#ifdef TTF_ON
		TTF_CloseFont(font_bobsgame_8px);
		TTF_CloseFont(font_bobsgame_16px);
		#endif

		#ifdef MIX_ON
		if(Mix_PlayingMusic())
		{
			Mix_FadeOutMusic(1000);
			Mix_FreeMusic(background_MUS);
		}

		Mix_CloseAudio();

		Mix_FreeChunk(wheel_sound_WAV);
		Mix_FreeChunk(action_pressed_WAV);
		Mix_FreeChunk(welcome_WAV);

		#endif

		SDL_Quit();
	//------------------------------------------

	#ifdef BUILD_WIZ
		//start bob's game
		if(bobsgame)
		{

			chdir("/mnt/sd/game/bg");

			execl("/mnt/sd/game/bg/bg.gpe", "/mnt/sd/game/bg/bg.gpe", NULL);
		}
		else
		{

			chdir("/usr/gp2x");
			execl("/usr/gp2x/gp2xmenu", "/usr/gp2x/gp2xmenu", NULL);
		}
	#endif

	return 0;
}



