//==============================================================================
//Copyright 2003-2012 by Robert Pelloni.
//All Rights Reserved.
//==============================================================================



#include "../main.h"
//#include "tetrid.h"



int GAME_playing_tetrid=0;

float TETRID_aspectratio = 1.0f;//((float)(((float)(GAME_VIEWPORT_HEIGHT_PIXELS)/1.6f))/192.0f);
int TETRID_fromx = 0; //((GAME_VIEWPORT_WIDTH_PIXELS-(TETRID_aspectratio*256.0f))/2);
int TETRID_fromy = 0;//(GAME_VIEWPORT_HEIGHT_PIXELS/3.5f)+7-4;


int TETRID_extra_stage_level = 3;
int TETRID_extra_extra_stage_level =  4;
int TETRID_master_stage_level =  5;
int TETRID_credits_level = 9;

//background bg;
//playingfield pf;
//blocks b;
int TETRID_frames_since_last_pressed_A=0;
int TETRID_frames_since_last_pressed_B=0;
int TETRID_frames_since_last_pressed_RIGHT=0;
int TETRID_frames_since_last_pressed_LEFT=0;
int TETRID_frames_since_last_pressed_DOWN=0;
int TETRID_frames_since_last_pressed_R=0;
bool TETRID_can_press_A=0;
bool TETRID_can_press_B=0;
bool TETRID_can_press_RIGHT=0;
bool TETRID_can_press_LEFT=0;
bool TETRID_can_press_DOWN=0;
bool TETRID_can_press_R=0;
int TETRID_dead_x=0;
int TETRID_dead_y=0;
bool TETRID_dying=0;
int TETRID_current_score=0;
int TETRID_high_score=0;
int TETRID_teh_matrixxx=0;
int TETRID_background_color=0;
int TETRID_times_flashed=0;
int TETRID_line_to_flash[5]={0,0,0,0,0};
int TETRID_amt_of_lines_to_flash=0;
int TETRID_current_level=0;
int TETRID_flash_screen_amt=0;
bool TETRID_extra_stage_flash=0;
bool TETRID_extra_extra_stage_flash=0;
bool TETRID_master_stage_flash=0;
bool TETRID_credits=0;
bool TETRID_credit_screen_init=0;
bool TETRID_background_is_init=0;
bool TETRID_already_updating=0;
int TETRID_frames=0; //frame counter
int TETRID_vbl_count=0;

int TETRID_score_color_fade=0;


int TETRID_playing_field_offset_x=8;
int TETRID_playing_field_offset_y=1;

#define TETRID_PLAYINGFIELD_SIZE_X 12
#define TETRID_PLAYINGFIELD_SIZE_Y 20
#define TETRID_AMT_OF_PIECES 5

int TETRID_bg_layer = 1;


unsigned short* TETRID_palette =  NULL;
unsigned char* TETRID_tileset =   NULL;
unsigned short* TETRID_map     =   NULL;
unsigned short* TETRID_original_map     =   NULL;
int TETRID_tileset_size = 0;


//#include "gfx/master.pal.c"
//#include "gfx/scrollingbackground.raw.c"
//#include "gfx/scrollingbackground.map.c" //background 1, scrolling grey bricks, 32x32 tiles
//#include "gfx/playingfield.raw.c"
//#include "gfx/playingfield.map.c" //background 2, walls and tile sprites, 32x32 tiles
//#include "gfx/playingbackground.raw.c"
//#include "gfx/playingbackground.map.c" //background 3, scrolling playfield background, 32x32 tiles

int TETRID_scrollingbackground_map_x=0;
int TETRID_scrollingbackground_map_y=0;//used for scrolling background
int TETRID_scrollingplayingfield_map_x=0;
int TETRID_scrollingplayingfield_map_y=0;
int TETRID_playing_field_map_scroll_x=0;

bool TETRID_seeded=0;
int TETRID_seedframe=0;
bool TETRID_newframe=1;


//extern const unsigned char _binary_module_mod_start;
int TETRID_block_tile_row=0;
bool TETRID_can_make_new_piece=0;
int TETRID_current_piece=0;
int TETRID_current_rotation=0;
int TETRID_next_rotation=0;
int TETRID_next_piece=0;
int TETRID_max_rotations=0;
int TETRID_level_drop_speed=0;
int TETRID_current_location_x=0;
int TETRID_current_location_y=0;
int TETRID_tried_to_drop=0;
int TETRID_sliding=0;

int TETRID_playing_fast_music=0;

struct TETRID_block
{
	int color;
	int x;
	int y;

}TETRID_block[4];



struct TETRID_playing_field
{
	bool filled;
	int color;

}TETRID_playing_field[TETRID_PLAYINGFIELD_SIZE_X][TETRID_PLAYINGFIELD_SIZE_Y],TETRID_last_playing_field[TETRID_PLAYINGFIELD_SIZE_X][TETRID_PLAYINGFIELD_SIZE_Y];





//=========================================================================================================================
void TETRID_redraw_map()
{//=========================================================================================================================



	HARDWARE_delete_AUX_bg(2);
	HARDWARE_load_AUX_map_to_xy_xy(2,TETRID_map,TETRID_tileset,TETRID_palette,256,192,TETRID_fromx+TETRID_playing_field_map_scroll_x,TETRID_fromy,TETRID_aspectratio,0);


}


//=========================================================================================================================
void TETRID_set_tile(int screen,int layer, int x, int y, int index)
{//=========================================================================================================================

	//HARDWARE_set_32x32_map_tile(screen,layer,x,y,TETRID_map[index]);

	TETRID_map[(y*32)+x]=TETRID_original_map[index];


}


//=========================================================================================================================
int TETRID_get_gametoy_palette_color(int color)
{//=========================================================================================================================

/*
bg 110 143 45
txt 182 210 121
161 198 83
139 180 60
119 153 51
104 134 45
89 115 38
75 96 32
59 77 25
sideblocks 68 88 29
outline 39 50 16
*/

	int rgbcolor=0;

	switch(color)
	{
		case 0: rgbcolor=HARDWARE_RGB((int)(((110.0/256.0))*32.0),(int)(((143.0/256.0))*32.0),(int)(((45.0/256.0))*32.0));break;
		case 1: rgbcolor=HARDWARE_RGB((int)(((182.0/256.0))*32.0), (int)(((210.0/256.0))*32.0), (int)(((121.0/256.0))*32.0));break;
		case 2: rgbcolor=HARDWARE_RGB((int)(((161.0/256.0))*32.0), (int)(((198.0/256.0))*32.0), (int)(((83.0/256.0))*32.0));break;
		case 3: rgbcolor=HARDWARE_RGB((int)(((139.0/256.0))*32.0), (int)(((180.0/256.0))*32.0), (int)(((60.0/256.0))*32.0));break;
		case 4: rgbcolor=HARDWARE_RGB((int)(((119.0/256.0))*32.0), (int)(((153.0/256.0))*32.0), (int)(((51.0/256.0))*32.0));break;
		case 5: rgbcolor=HARDWARE_RGB((int)(((104.0/256.0))*32.0), (int)(((134.0/256.0))*32.0), (int)(((45.0/256.0))*32.0));break;
		case 6: rgbcolor=HARDWARE_RGB((int)(((89.0/256.0))*32.0), (int)(((115.0/256.0))*32.0), (int)(((38.0/256.0))*32.0));break;
		case 7: rgbcolor=HARDWARE_RGB((int)(((75.0/256.0))*32.0), (int)(((96.0/256.0))*32.0), (int)(((32.0/256.0))*32.0));break;
		case 8: rgbcolor=HARDWARE_RGB((int)(((59.0/256.0))*32.0), (int)(((77.0/256.0))*32.0), (int)(((25.0/256.0))*32.0));break;
		case 9: rgbcolor=HARDWARE_RGB((int)(((68.0/256.0))*32.0), (int)(((88.0/256.0))*32.0), (int)(((29.0/256.0))*32.0));break;
		case 10: rgbcolor=HARDWARE_RGB((int)(((39.0/256.0))*32.0), (int)(((50.0/256.0))*32.0), (int)(((16.0/256.0))*32.0));break;
		default:break;
	}
	return rgbcolor;

}


//=========================================================================================================================
void TETRID_scrollbackground()
{//=========================================================================================================================
	//called every VBL to make the background pretty
	//M_BG3SCRLX_SET(scrollingbackground_map_x);
	if(TETRID_scrollingbackground_map_x>6)TETRID_scrollingbackground_map_x=0;
	else TETRID_scrollingbackground_map_x++;
	//M_BG3SCRLY_SET(scrollingbackground_map_y);
	if(TETRID_scrollingbackground_map_y>6)TETRID_scrollingbackground_map_y=0;
	else TETRID_scrollingbackground_map_y++;
}
//=========================================================================================================================
void TETRID_scrollplayingbackground()
{//=========================================================================================================================
	//scroll the playing filed background
	if(TETRID_scrollingplayingfield_map_x<=0)TETRID_scrollingplayingfield_map_x=7;
	else TETRID_scrollingplayingfield_map_x--;
	//M_BG2SCRLX_SET(scrollingplayingfield_map_x);
	if(TETRID_scrollingplayingfield_map_y<=0)TETRID_scrollingplayingfield_map_y=7;
	else TETRID_scrollingplayingfield_map_y--;
	//M_BG2SCRLY_SET(scrollingplayingfield_map_y);
}
//=========================================================================================================================
void TETRID_shakeplayingfield()
{//=========================================================================================================================
	//called every VBL to make the background pretty
	//M_BG1SCRLX_SET(playing_field_map_x);

	static int dir=0;
	if(dir==0)
	{
		TETRID_playing_field_map_scroll_x++;
		if(TETRID_playing_field_map_scroll_x>3)
		{
			dir=1;
			TETRID_playing_field_map_scroll_x--;
		}
	}
	else
	{
		TETRID_playing_field_map_scroll_x--;
		if(TETRID_playing_field_map_scroll_x<-3)
		{
			dir=0;
			TETRID_playing_field_map_scroll_x++;
		}
	}


	HARDWARE_set_AUX_map_xy(2,TETRID_fromx+TETRID_playing_field_map_scroll_x,TETRID_fromy);
}


//=========================================================================================================================
void TETRID_redraw_playing_field()
{//=========================================================================================================================
	int x=0;
	int y=0;
	for (x=1; x<TETRID_PLAYINGFIELD_SIZE_X-1; x++)
	{
		for(y=0; y<TETRID_PLAYINGFIELD_SIZE_Y-1; y++)
		{//for x 0-9 and y 2-21 (excluding the top invisible lines
			if (
					(TETRID_playing_field[x][y].filled==1)
					//&&
					//(last_playing_field[x][y].filled==0)//IF THE SQUARE WASNT FILLED IN LAST TURN BUT IS NOW
				)
			{
				//THEN SET THE TILE TO BE FILLED IN WITH RANDOMLY SELECTED COLOR
				TETRID_set_tile(0,TETRID_bg_layer,TETRID_playing_field_offset_x+x,TETRID_playing_field_offset_y+y,TETRID_playing_field[x][y].color+((20+TETRID_block_tile_row)*32));

			}
			else
			{
				if(
					(TETRID_playing_field[x][y].filled==0)
					//&&(last_playing_field[x][y].filled==1)//IF THE SQUARE WAS FILLED IN LAST TURN BUT ISNT NOW
					)
					{ //THEN SET THE FILE TO BE FILLED IN THE NOTHING (erased)

						TETRID_set_tile(0,TETRID_bg_layer,TETRID_playing_field_offset_x+x,TETRID_playing_field_offset_y+y,0);


						TETRID_playing_field[x][y].color=bEMPTY;
					}
			}
		}
	}


	//TETRID_redraw_map();


	//return;
}


//=========================================================================================================================
void TETRID_check_for_fast_music()
{//=========================================================================================================================
	int x=0;
	int y=0;
	int anything_above_halfway=0;
	for (x=1; x<TETRID_PLAYINGFIELD_SIZE_X-1; x++)
	{
		for(y=0; y<TETRID_PLAYINGFIELD_SIZE_Y-1; y++)
		{//for x 0-9 and y 2-21 (excluding the top invisible lines
			if (TETRID_playing_field[x][y].filled==1)
			{
				if(y<TETRID_PLAYINGFIELD_SIZE_Y/2)
				{
					anything_above_halfway=1;
				}

			}
		}
	}
	if(anything_above_halfway==1||TETRID_extra_stage_flash||TETRID_extra_extra_stage_flash||TETRID_master_stage_flash)
	{
		if(TETRID_playing_fast_music==0)
		{
			TETRID_playing_fast_music=1;
			HARDWARE_play_music("tetrid_doublespeed",32);
			CAPTION_make_caption(&friend_tetrid_caption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,3,"Uh oh, be careful!",FONT_NORMAL_ID,WHITE,BLACK,1,1);
		}
	}
	else
	{

		if(TETRID_playing_fast_music==1)
		{
			TETRID_playing_fast_music=0;
			HARDWARE_play_music("tetrid",32);
		}

	}

	return;
}
//=========================================================================================================================
void TETRID_set_playing_field_colors()
{//=========================================================================================================================
	TETRID_playing_field[TETRID_current_location_x+TETRID_block[0].x][TETRID_current_location_y+TETRID_block[0].y].color=TETRID_block[0].color;
	TETRID_playing_field[TETRID_current_location_x+TETRID_block[1].x][TETRID_current_location_y+TETRID_block[1].y].color=TETRID_block[1].color;
	TETRID_playing_field[TETRID_current_location_x+TETRID_block[2].x][TETRID_current_location_y+TETRID_block[2].y].color=TETRID_block[2].color;
	//TETRID_playing_field[TETRID_current_location_x+TETRID_block[3].x][TETRID_current_location_y+TETRID_block[3].y].color=TETRID_block[3].color;

}


//=========================================================================================================================
void TETRID_set_block_colors(int type_of_piece)
{//=========================================================================================================================
	switch(type_of_piece)
	{
	case TBLOCK: {TETRID_max_rotations=3;
			TETRID_block[0].color=bBLUE;
			TETRID_block[1].color=bBLUE;
			TETRID_block[2].color=bBLUE;
			//TETRID_block[3].color=bBLUE;
			break;}
	case JBLOCK: {TETRID_max_rotations=3;
			TETRID_block[0].color=bYELLOW;
			TETRID_block[1].color=bYELLOW;
			TETRID_block[2].color=bYELLOW;
			//TETRID_block[3].color=bYELLOW;
			break;}
	case LBLOCK: {TETRID_max_rotations=3;
			TETRID_block[0].color=bRED;
			TETRID_block[1].color=bRED;
			TETRID_block[2].color=bRED;
			//TETRID_block[3].color=bRED;
			break;}
	case BACKZBLOCK: {TETRID_max_rotations=3;
			TETRID_block[0].color=bGREEN;
			TETRID_block[1].color=bGREEN;
			TETRID_block[2].color=bGREEN;
			//TETRID_block[3].color=bGREEN;
			break;}
	case ZBLOCK: {TETRID_max_rotations=1;
			TETRID_block[0].color=bORANGE;
			TETRID_block[1].color=bORANGE;
			TETRID_block[2].color=bORANGE;
			//TETRID_block[3].color=bORANGE;
			break;}
	case IBLOCK: {TETRID_max_rotations=1;
			TETRID_block[0].color=bPURPLE;
			TETRID_block[1].color=bPURPLE;
			TETRID_block[2].color=bPURPLE;
			//TETRID_block[3].color=bPURPLE;
			break;}
	/*case SQUAREBLOCK:{TETRID_max_rotations=0;
			TETRID_block[0].color=bPINK;
			TETRID_block[1].color=bPINK;
			TETRID_block[2].color=bPINK;
			//TETRID_block[3].color=bPINK;
			break;}*/
	default:break;
	}
}


//=========================================================================================================================
void TETRID_drop_piece()
{//=========================================================================================================================
	int TETRID_stop_dropping=0;
	do{
		TETRID_set_block_locations(TETRID_current_piece,TETRID_current_rotation);
		TETRID_playing_field[TETRID_current_location_x+TETRID_block[0].x][TETRID_current_location_y+TETRID_block[0].y].filled=0;
		TETRID_playing_field[TETRID_current_location_x+TETRID_block[1].x][TETRID_current_location_y+TETRID_block[1].y].filled=0;
		TETRID_playing_field[TETRID_current_location_x+TETRID_block[2].x][TETRID_current_location_y+TETRID_block[2].y].filled=0;
		//TETRID_playing_field[TETRID_current_location_x+TETRID_block[3].x][TETRID_current_location_y+TETRID_block[3].y].filled=0;

		TETRID_current_location_y++;
		if(
				(TETRID_playing_field[TETRID_current_location_x+TETRID_block[0].x][TETRID_current_location_y+TETRID_block[0].y].filled==0)
				&&(TETRID_playing_field[TETRID_current_location_x+TETRID_block[1].x][TETRID_current_location_y+TETRID_block[1].y].filled==0)
				&&(TETRID_playing_field[TETRID_current_location_x+TETRID_block[2].x][TETRID_current_location_y+TETRID_block[2].y].filled==0)
				//&&(TETRID_playing_field[TETRID_current_location_x+TETRID_block[3].x][TETRID_current_location_y+TETRID_block[3].y].filled==0)

				)
		{
			TETRID_playing_field[TETRID_current_location_x+TETRID_block[0].x][TETRID_current_location_y+TETRID_block[0].y].filled=1;
			TETRID_playing_field[TETRID_current_location_x+TETRID_block[1].x][TETRID_current_location_y+TETRID_block[1].y].filled=1;
			TETRID_playing_field[TETRID_current_location_x+TETRID_block[2].x][TETRID_current_location_y+TETRID_block[2].y].filled=1;
			//TETRID_playing_field[TETRID_current_location_x+TETRID_block[3].x][TETRID_current_location_y+TETRID_block[3].y].filled=1;

		}
		else //CANNOT MOVE IN DIRECTION, DO THIS
		{
			TETRID_current_location_y--;
			TETRID_set_block_locations(TETRID_current_piece,TETRID_current_rotation);
			TETRID_playing_field[TETRID_current_location_x+TETRID_block[0].x][TETRID_current_location_y+TETRID_block[0].y].filled=1;
			TETRID_playing_field[TETRID_current_location_x+TETRID_block[1].x][TETRID_current_location_y+TETRID_block[1].y].filled=1;
			TETRID_playing_field[TETRID_current_location_x+TETRID_block[2].x][TETRID_current_location_y+TETRID_block[2].y].filled=1;
			//TETRID_playing_field[TETRID_current_location_x+TETRID_block[3].x][TETRID_current_location_y+TETRID_block[3].y].filled=1;

			TETRID_stop_dropping=1;
			TETRID_can_make_new_piece=1;
			//********************NEW RANDOM PIECE
		}
		TETRID_set_playing_field_colors();//********************SET PLAYING FIELD COLORS

		whilefix();

	}while(TETRID_stop_dropping==0&&MAIN_QUIT==false);
}
//=========================================================================================================================
void TETRID_move_piece(int TETRID_direction)
{//=========================================================================================================================
	if(TETRID_direction==ROTATECCW){ if(TETRID_current_rotation==0)TETRID_next_rotation=TETRID_max_rotations;
		else TETRID_next_rotation=TETRID_current_rotation-1;
	}
	if(TETRID_direction==ROTATECW){ if(TETRID_current_rotation==TETRID_max_rotations)TETRID_next_rotation=0;
		else TETRID_next_rotation=TETRID_current_rotation+1;
	}
	TETRID_set_block_locations(TETRID_current_piece,TETRID_current_rotation);
	TETRID_playing_field[TETRID_current_location_x+TETRID_block[0].x][TETRID_current_location_y+TETRID_block[0].y].filled=0;
	TETRID_playing_field[TETRID_current_location_x+TETRID_block[1].x][TETRID_current_location_y+TETRID_block[1].y].filled=0;
	TETRID_playing_field[TETRID_current_location_x+TETRID_block[2].x][TETRID_current_location_y+TETRID_block[2].y].filled=0;
	//TETRID_playing_field[TETRID_current_location_x+TETRID_block[3].x][TETRID_current_location_y+TETRID_block[3].y].filled=0;

	if(TETRID_direction==ROTATECCW) TETRID_set_block_locations(TETRID_current_piece,TETRID_next_rotation);
	if(TETRID_direction==ROTATECW) TETRID_set_block_locations(TETRID_current_piece,TETRID_next_rotation);
	if(TETRID_direction==TETRID_DOWN) TETRID_current_location_y++;
	if(TETRID_direction==TETRID_RIGHT) TETRID_current_location_x++;
	if (TETRID_direction==TETRID_LEFT) TETRID_current_location_x--;
	if(
			(TETRID_playing_field[TETRID_current_location_x+TETRID_block[0].x][TETRID_current_location_y+TETRID_block[0].y].filled==0)
			&&(TETRID_playing_field[TETRID_current_location_x+TETRID_block[1].x][TETRID_current_location_y+TETRID_block[1].y].filled==0)
			&&(TETRID_playing_field[TETRID_current_location_x+TETRID_block[2].x][TETRID_current_location_y+TETRID_block[2].y].filled==0)
			//&&(TETRID_playing_field[TETRID_current_location_x+TETRID_block[3].x][TETRID_current_location_y+TETRID_block[3].y].filled==0)

		)
	{
		TETRID_playing_field[TETRID_current_location_x+TETRID_block[0].x][TETRID_current_location_y+TETRID_block[0].y].filled=1;
		TETRID_playing_field[TETRID_current_location_x+TETRID_block[1].x][TETRID_current_location_y+TETRID_block[1].y].filled=1;
		TETRID_playing_field[TETRID_current_location_x+TETRID_block[2].x][TETRID_current_location_y+TETRID_block[2].y].filled=1;
		//TETRID_playing_field[TETRID_current_location_x+TETRID_block[3].x][TETRID_current_location_y+TETRID_block[3].y].filled=1;

		if(TETRID_direction==ROTATECCW){TETRID_current_rotation=TETRID_next_rotation;HARDWARE_play_sound("whup",127,30000+rand()%20000,0);}
		if(TETRID_direction==ROTATECW){TETRID_current_rotation=TETRID_next_rotation;HARDWARE_play_sound("whup",127,30000+rand()%20000,0);}



	}
	else //CANNOT MOVE IN DIRECTION, DO THIS
	{
		if(TETRID_direction==TETRID_DOWN)TETRID_current_location_y--;
		if(TETRID_direction==TETRID_LEFT)TETRID_current_location_x++;
		if(TETRID_direction==TETRID_RIGHT)TETRID_current_location_x--;
		TETRID_set_block_locations(TETRID_current_piece,TETRID_current_rotation);
		TETRID_playing_field[TETRID_current_location_x+TETRID_block[0].x][TETRID_current_location_y+TETRID_block[0].y].filled=1;
		TETRID_playing_field[TETRID_current_location_x+TETRID_block[1].x][TETRID_current_location_y+TETRID_block[1].y].filled=1;
		TETRID_playing_field[TETRID_current_location_x+TETRID_block[2].x][TETRID_current_location_y+TETRID_block[2].y].filled=1;
		//TETRID_playing_field[TETRID_current_location_x+TETRID_block[3].x][TETRID_current_location_y+TETRID_block[3].y].filled=1;

		if(TETRID_direction==TETRID_DOWN)
		{
			if(TETRID_sliding>0)
			{
				TETRID_sliding--;
			}
			else
			{
				TETRID_can_make_new_piece=1;


				HARDWARE_play_sound("blocksmash",127,30000+rand()%20000,0);

			}
		}
	}
	TETRID_set_playing_field_colors(); //********************SET PLAYING FIELD COLORS
}




//=========================================================================================================================
void TETRID_query_keys()
{//=========================================================================================================================
	if((!BUTTON_A_HELD)||(TETRID_frames_since_last_pressed_A>=10))
	{
		TETRID_can_press_A=1;
	}
	else TETRID_frames_since_last_pressed_A++;

	if((!BUTTON_B_HELD)||(TETRID_frames_since_last_pressed_B>=10))
	{
		TETRID_can_press_B=1;
	}
	else TETRID_frames_since_last_pressed_B++;


	if((!BUTTON_RIGHT_HELD)||(TETRID_frames_since_last_pressed_RIGHT>=6))
	{
		TETRID_can_press_RIGHT=1;
	}
	else TETRID_frames_since_last_pressed_RIGHT++;


	if((!BUTTON_LEFT_HELD)||(TETRID_frames_since_last_pressed_LEFT>=6))
	{
		TETRID_can_press_LEFT=1;
	}
	else TETRID_frames_since_last_pressed_LEFT++;


	if((!BUTTON_DOWN_HELD)||(TETRID_frames_since_last_pressed_DOWN>=3))
	{
		TETRID_can_press_DOWN=1;
	}
	else TETRID_frames_since_last_pressed_DOWN++;


	if((!BUTTON_R_HELD)||(TETRID_frames_since_last_pressed_R>=10))
	{
		TETRID_can_press_R=1;
	}
	else TETRID_frames_since_last_pressed_R++;


	//END CHECK IF KEY WAS ALREADY PRESSED
	//BEGIN ACTUAL KEY CHECK
	if((BUTTON_A_HELD)&&(TETRID_can_press_A))
	{

		TETRID_sliding=1;
		TETRID_move_piece(ROTATECW);
		TETRID_can_press_A=0;
		TETRID_frames_since_last_pressed_A=0;
	}

	if((BUTTON_B_HELD)&&(TETRID_can_press_B))
	{

		TETRID_sliding=1;
		TETRID_move_piece(ROTATECCW);
		TETRID_can_press_B=0;
		TETRID_frames_since_last_pressed_B=0;
	}

	if((BUTTON_RIGHT_HELD)&&(TETRID_can_press_RIGHT))
	{
		HARDWARE_play_sound("tick",127,40000+rand()%20000,0);

		TETRID_sliding=1;
		TETRID_move_piece(TETRID_RIGHT);
		TETRID_can_press_RIGHT=0;
		TETRID_frames_since_last_pressed_RIGHT=0;
	}


	if((BUTTON_LEFT_HELD)&&(TETRID_can_press_LEFT))
	{
		HARDWARE_play_sound("tick",127,40000+rand()%20000,0);

		TETRID_sliding=1;
		TETRID_move_piece(TETRID_LEFT);
		TETRID_can_press_LEFT=0;
		TETRID_frames_since_last_pressed_LEFT=0;
	}


	if((BUTTON_DOWN_HELD)&&(TETRID_can_press_DOWN))
	{
		HARDWARE_play_sound("tick",127,40000+rand()%20000,0);

		if(TETRID_can_make_new_piece==0)
		TETRID_move_piece(TETRID_DOWN);
		TETRID_can_press_DOWN=0;
		TETRID_frames_since_last_pressed_DOWN=0;
	}


	if((BUTTON_R_HELD)&&(TETRID_can_press_R))
	{

		HARDWARE_play_sound("blocksmash",127,30000+rand()%20000,0);

		TETRID_drop_piece();
		TETRID_can_press_R=0;
		TETRID_frames_since_last_pressed_R=0;
	}

	//if(BUTTON_L_HELD)
	//{
		//if(BUTTON_Y_HELD)
		//if(BUTTON_SELECT_PRESSED)
		//TETRID_init_game();
		//TETRID_current_score+=10;
		//cheater=1;
	//}
}


//=========================================================================================================================
void TETRID_dead()
{//=========================================================================================================================
	//ham_SetBgPalColRGB(7,rand()%255,rand()%255,rand()%255);
	static int first_death=0;

	if(first_death==0)
	{
		first_death=1;
		HARDWARE_play_music("tetrid_death",32);

		CAPTION_make_caption(&friend_tetrid_caption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,3,"Aww.. Yuu sucks. Come on, let's see this.",FONT_NORMAL_ID,WHITE,BLACK,1,1);
	}
	else
	if(first_death==1)
	{
		first_death=0;
		HARDWARE_play_music("tetrid_death",32);

		CAPTION_make_caption(&friend_tetrid_caption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,3,"Yuu thinks there's some kind of trick?",FONT_NORMAL_ID,WHITE,BLACK,1,1);
	}

	TETRID_dying=1;
	if(TETRID_dead_y==-1)TETRID_dead_y=TETRID_PLAYINGFIELD_SIZE_Y-2;
	if(TETRID_dead_y>-2)
	if(TETRID_dead_x<TETRID_PLAYINGFIELD_SIZE_X-1)
	{
		TETRID_set_tile(0,TETRID_bg_layer,TETRID_playing_field_offset_x+TETRID_dead_x,TETRID_playing_field_offset_y+TETRID_dead_y,rand()%TETRID_AMT_OF_PIECES+(20+TETRID_block_tile_row)*32);

		//TETRID_redraw_map();

		TETRID_dead_x++;
		if(TETRID_dead_x==TETRID_PLAYINGFIELD_SIZE_X-1){TETRID_dead_x=1; TETRID_dead_y--;}
	}


	if(BUTTON_A_HELD)
	{
		//if(current_score>high_score)ham_SaveIntToRAM("high_score",current_score);
		//first_death=0;
		TETRID_dying=0;
		TETRID_current_score=0;
		TETRID_current_level=1;
		TETRID_update_score(0);
		TETRID_dead_x=1;
		TETRID_dead_y=TETRID_PLAYINGFIELD_SIZE_Y-1;
		TETRID_init_game();
	}
}

//=========================================================================================================================
void TETRID_check_lines()
{//=========================================================================================================================

int y=0;
	for(y=TETRID_PLAYINGFIELD_SIZE_Y-2; y>0; y--)
	{
		if(
			(TETRID_playing_field[1][y].filled)
			&&(TETRID_playing_field[2][y].filled)
			&&(TETRID_playing_field[3][y].filled)
			&&(TETRID_playing_field[4][y].filled)
			&&(TETRID_playing_field[5][y].filled)
			&&(TETRID_playing_field[6][y].filled)
			&&(TETRID_playing_field[7][y].filled)
			&&(TETRID_playing_field[8][y].filled)
			&&(TETRID_playing_field[9][y].filled)
			&&(TETRID_playing_field[10][y].filled)
		)
		{
			TETRID_amt_of_lines_to_flash++;
			TETRID_line_to_flash[TETRID_amt_of_lines_to_flash]=y;
			TETRID_can_make_new_piece=0;

			if(TETRID_amt_of_lines_to_flash==1)
			{
				HARDWARE_play_sound("gotline",127,44100,0);

				int z=0;
				z=rand()%5;
				if(z==0)CAPTION_make_caption(&friend_tetrid_caption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,3,"Nice! Keep going!",FONT_NORMAL_ID,WHITE,BLACK,1,1);
				if(z==1)CAPTION_make_caption(&friend_tetrid_caption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,3,"Not bad. Can Yuu keep it going?",FONT_NORMAL_ID,WHITE,BLACK,1,1);
				if(z==2)CAPTION_make_caption(&friend_tetrid_caption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,3,"So far Yuu is alright, I guess.",FONT_NORMAL_ID,WHITE,BLACK,1,1);
				if(z==3)CAPTION_make_caption(&friend_tetrid_caption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,3,"Yuu will never make it.",FONT_NORMAL_ID,WHITE,BLACK,1,1);
				if(z==4)CAPTION_make_caption(&friend_tetrid_caption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,3,"Yuu can do it, come on!",FONT_NORMAL_ID,WHITE,BLACK,1,1);
			}

		}
		//else no_more_flashing=1;
	}
}

//=========================================================================================================================
void TETRID_flash_line()
{//=========================================================================================================================
	//HARDWARE_set_bg_palette_color(0,7,RGB(rand()%255,rand()%255,rand()%255));
	int y=0;
	/*if(TETRID_times_flashed<20)
	{
		for(y=TETRID_amt_of_lines_to_flash; y>0; y--)
		{
			int x=0;
			for(x=1; x<11; x++)
			{
				HARDWARE_set_32x32_map_tile(0,TETRID_bg_layer,TETRID_playing_field_offset_x+x,TETRID_playing_field_offset_y+TETRID_line_to_flash[y],TETRID_map[TETRID_playing_field[x][TETRID_line_to_flash[y]].color+21*32]);
			}
		}
		TETRID_times_flashed++;
	}
	else*/
	if(TETRID_times_flashed<40)
	{
		if(TETRID_times_flashed%5==0)
		{
			if(TETRID_times_flashed%10==0)
			for(y=TETRID_amt_of_lines_to_flash; y>0; y--)
			{
				int x=0;
				for(x=1; x<11; x++)
				{
					TETRID_set_tile(0,TETRID_bg_layer,TETRID_playing_field_offset_x+x,TETRID_playing_field_offset_y+TETRID_line_to_flash[y],TETRID_playing_field[x][TETRID_line_to_flash[y]].color+21*32);
				}
			}
			else
			for(y=TETRID_amt_of_lines_to_flash; y>0; y--)
			{
				int x=0;
				for(x=1; x<11; x++)
				{
					TETRID_set_tile(0,TETRID_bg_layer,TETRID_playing_field_offset_x+x,TETRID_playing_field_offset_y+TETRID_line_to_flash[y],0);
				}
			}

			//TETRID_redraw_map();
		}

		TETRID_times_flashed++;
	}
	else
	{
		for(y=TETRID_amt_of_lines_to_flash; y>0; y--)
		{
			TETRID_move_down_blocks(TETRID_line_to_flash[y]);
		}
		TETRID_amt_of_lines_to_flash=0;
		TETRID_times_flashed=0;
		TETRID_can_make_new_piece=1;
	}
}
//=========================================================================================================================
void TETRID_move_down_blocks(int y)
{//=========================================================================================================================
	int y2=0;
	for(y2=y; y2>1; y2--)
	{
		int x=0;
		for (x=1; x<TETRID_PLAYINGFIELD_SIZE_X-1; x++)
		{
			TETRID_playing_field[x][y2].filled=TETRID_playing_field[x][y2-1].filled;
			TETRID_playing_field[x][y2].color=TETRID_playing_field[x][y2-1].color;
		}
	}
	TETRID_update_score(10);
}
//=========================================================================================================================
void TETRID_update_score(int amt)
{//=========================================================================================================================


	TETRID_current_score+=amt;
	char char_score[15];
	sprintf(char_score,"%d",TETRID_current_score);
	//stringstream char_score;
	//char_score<<TETRID_current_score;
	int score_length=strlen(char_score);
	//score_length--;

	int x=0;

	if(TETRID_current_score==0)
	for(x=0;x<3;x++)
	{
		TETRID_set_tile(0,TETRID_bg_layer,TETRID_playing_field_offset_x+TETRID_PLAYINGFIELD_SIZE_X+x,TETRID_playing_field_offset_y+(6),0);
	}

	for(x=0;x<score_length;x++)
	{
		TETRID_set_tile(0,TETRID_bg_layer,TETRID_playing_field_offset_x+TETRID_PLAYINGFIELD_SIZE_X+3+x-score_length,TETRID_playing_field_offset_y+(6),(char_score[x]-48)+(24*32));
	}

	//TETRID_redraw_map();


}
//=========================================================================================================================
void TETRID_update_next_piece()
{//=========================================================================================================================
	int TETRID_next_piece_color=0;
	switch (TETRID_next_piece)
	{
		case TBLOCK:		{TETRID_next_piece_color=bBLUE;break;}
		case JBLOCK:		{TETRID_next_piece_color=bYELLOW;break;}
		case LBLOCK:		{TETRID_next_piece_color=bRED;break;}
		case BACKZBLOCK:	{TETRID_next_piece_color=bGREEN;break;}
		case ZBLOCK:		{TETRID_next_piece_color=bORANGE;break;}
		case IBLOCK:		{TETRID_next_piece_color=bPURPLE;break;}
		case SQUAREBLOCK:	{TETRID_next_piece_color=bPINK;break;}
		default:break;
	}
	TETRID_set_block_locations(TETRID_next_piece,0);
	int y=0; int x=0;
	for(y=8;y<12;y++)
		for(x=0;x<4;x++)
			TETRID_set_tile(0,TETRID_bg_layer,TETRID_playing_field_offset_x+TETRID_PLAYINGFIELD_SIZE_X+x,TETRID_playing_field_offset_y+(y),8+(20*32));


	TETRID_set_tile(0,TETRID_bg_layer,TETRID_playing_field_offset_x+TETRID_PLAYINGFIELD_SIZE_X+2+TETRID_block[0].x,TETRID_playing_field_offset_y+(8+1)+TETRID_block[0].y,TETRID_next_piece_color+(20*32));
	TETRID_set_tile(0,TETRID_bg_layer,TETRID_playing_field_offset_x+TETRID_PLAYINGFIELD_SIZE_X+2+TETRID_block[1].x,TETRID_playing_field_offset_y+(8+1)+TETRID_block[1].y,TETRID_next_piece_color+(20*32));
	TETRID_set_tile(0,TETRID_bg_layer,TETRID_playing_field_offset_x+TETRID_PLAYINGFIELD_SIZE_X+2+TETRID_block[2].x,TETRID_playing_field_offset_y+(8+1)+TETRID_block[2].y,TETRID_next_piece_color+(20*32));
	//TETRID_set_tile(0,TETRID_bg_layer,TETRID_playing_field_offset_x+TETRID_PLAYINGFIELD_SIZE_X+2+TETRID_block[3].x,TETRID_playing_field_offset_y+(8+1)+TETRID_block[3].y,TETRID_next_piece_color+(20*32));

	//TETRID_redraw_map();

}
//=========================================================================================================================
void TETRID_update_level()
{//=========================================================================================================================




	if(TETRID_current_level!=TETRID_current_score/20)
	{
		TETRID_current_level=TETRID_current_score/20;
		if(TETRID_current_level<21)
		{
			if(TETRID_current_level==TETRID_master_stage_level)
			TETRID_set_tile(0,TETRID_bg_layer,TETRID_playing_field_offset_x+TETRID_PLAYINGFIELD_SIZE_X,TETRID_playing_field_offset_y+(4),20+24*32);
			else
			TETRID_set_tile(0,TETRID_bg_layer,TETRID_playing_field_offset_x+TETRID_PLAYINGFIELD_SIZE_X,TETRID_playing_field_offset_y+(4),TETRID_current_level+24*32);

			//TETRID_redraw_map();
		}

		TETRID_flash_screen_amt=25;
		if(TETRID_level_drop_speed>6)TETRID_level_drop_speed-=3;



		if(TETRID_current_level==TETRID_extra_stage_level)
		{
			TETRID_extra_stage_flash=1;
			CAPTION_make_caption(&friend_tetrid_caption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,3,"Holy crap, it's the extra stage!",FONT_NORMAL_ID,YELLOW,BLACK,1,1);

		}
		if(TETRID_current_level==TETRID_extra_extra_stage_level)
		{
			TETRID_extra_extra_stage_flash=1;
			CAPTION_make_caption(&friend_tetrid_caption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,3,"I've never gotten this far!",FONT_NORMAL_ID,ORANGE,BLACK,1,1);
		}

		if(TETRID_current_level==TETRID_master_stage_level)
		{
			TETRID_master_stage_flash=1;
			CAPTION_make_caption(&friend_tetrid_caption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,3,"Yuu is amazing!",FONT_NORMAL_ID,RED,BLACK,1,1);
		}
		if(TETRID_current_level>TETRID_credits_level)
		{
			TETRID_credits=1;
			CAPTION_make_caption(&friend_tetrid_caption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,5,"Yuu did it!!!",FONT_HUGE_ID,LIGHTGREEN,BLACK,1,1);
		}

		if(TETRID_current_level>0)
		{
			if(TETRID_current_level<TETRID_extra_stage_level)CAPTION_make_caption(&friend_tetrid_caption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,3,"Level up!",FONT_NORMAL_ID,WHITE,BLACK,1,1);
			int x=0;
			for(x=0;x<7;x++)
			{
				//HARDWARE_set_bg_palette_color(0,TETRID_bg_layer,(int)TETRID_tileset[(8*8)*TETRID_map[1+x]],TETRID_get_gametoy_palette_color(rand()%10));
				TETRID_palette[(int)TETRID_tileset[(8*8)*TETRID_original_map[1+x]]] = TETRID_get_gametoy_palette_color(rand()%10);
			}
			//TETRID_redraw_map();
			HARDWARE_play_sound("gotline",127,22050,0);
		}

	}
}

//=========================================================================================================================
void TETRID_flash_screen()
{//=========================================================================================================================
	//ham_SetBgPalColRGB(6,rand()%255,rand()%255,rand()%255);
	//ham_SetBgPalColRGB(2,rand()%255,rand()%255,rand()%255);
	TETRID_flash_screen_amt--;
}

//=========================================================================================================================
void TETRID_set_block_locations(int type_of_piece, int rotation)
{//=========================================================================================================================
	switch(type_of_piece)
	{
		/*case TBLOCK:{
				if(rotation==0){TETRID_block[0].x=0; TETRID_block[0].y=0;
					TETRID_block[1].x=-1; TETRID_block[1].y=0;
					TETRID_block[2].x=0; TETRID_block[2].y=1;
					TETRID_block[3].x=1; TETRID_block[3].y=0;
				}
				if(rotation==1){TETRID_block[0].x=0; TETRID_block[0].y=0;
					TETRID_block[1].x=0; TETRID_block[1].y=-1;
					TETRID_block[2].x=-1; TETRID_block[2].y=0;
					TETRID_block[3].x=0; TETRID_block[3].y=1;
				}
				if(rotation==2){TETRID_block[0].x=0; TETRID_block[0].y=0;
					TETRID_block[1].x=1; TETRID_block[1].y=0;
					TETRID_block[2].x=0; TETRID_block[2].y=-1;
					TETRID_block[3].x=-1; TETRID_block[3].y=0;
				}
				if(rotation==3){TETRID_block[0].x=0; TETRID_block[0].y=0;
					TETRID_block[1].x=0; TETRID_block[1].y=1;
					TETRID_block[2].x=1; TETRID_block[2].y=0;
					TETRID_block[3].x=0; TETRID_block[3].y=-1;
				}
				break;
			}
		case JBLOCK:{
				if(rotation==0){TETRID_block[0].x=0; TETRID_block[0].y=0;
					TETRID_block[1].x=-1; TETRID_block[1].y=0;
					TETRID_block[2].x=1; TETRID_block[2].y=0;
					TETRID_block[3].x=1; TETRID_block[3].y=1;
				}
				if(rotation==1){TETRID_block[0].x=0; TETRID_block[0].y=0;
					TETRID_block[1].x=0; TETRID_block[1].y=-1;
					TETRID_block[2].x=0; TETRID_block[2].y=1;
					TETRID_block[3].x=-1; TETRID_block[3].y=1;
				}
				if(rotation==2){TETRID_block[0].x=0; TETRID_block[0].y=0;
					TETRID_block[1].x=1; TETRID_block[1].y=0;
					TETRID_block[2].x=-1; TETRID_block[2].y=0;
					TETRID_block[3].x=-1; TETRID_block[3].y=-1;
				}
				if(rotation==3){TETRID_block[0].x=0; TETRID_block[0].y=0;
					TETRID_block[1].x=0; TETRID_block[1].y=1;
					TETRID_block[2].x=0; TETRID_block[2].y=-1;
					TETRID_block[3].x=1; TETRID_block[3].y=-1;
				}
				break;
			}
		case LBLOCK:{
				if(rotation==0){TETRID_block[0].x=0; TETRID_block[0].y=0;
					TETRID_block[1].x=-1; TETRID_block[1].y=0;
					TETRID_block[2].x=-1; TETRID_block[2].y=1;
					TETRID_block[3].x=1; TETRID_block[3].y=0;
				}
				if(rotation==1){TETRID_block[0].x=0; TETRID_block[0].y=0;
					TETRID_block[1].x=0; TETRID_block[1].y=-1;
					TETRID_block[2].x=-1; TETRID_block[2].y=-1;
					TETRID_block[3].x=0; TETRID_block[3].y=1;
				}
				if(rotation==2){TETRID_block[0].x=0; TETRID_block[0].y=0;
					TETRID_block[1].x=1; TETRID_block[1].y=0;
					TETRID_block[2].x=1; TETRID_block[2].y=-1;
					TETRID_block[3].x=-1; TETRID_block[3].y=0;
				}
				if(rotation==3){TETRID_block[0].x=0; TETRID_block[0].y=0;
					TETRID_block[1].x=0; TETRID_block[1].y=1;
					TETRID_block[2].x=1; TETRID_block[2].y=1;
					TETRID_block[3].x=0; TETRID_block[3].y=-1;
				}
				break;
			}
		case BACKZBLOCK:{
				if(rotation==0){TETRID_block[0].x=0; TETRID_block[0].y=0;
					TETRID_block[1].x=-1; TETRID_block[1].y=1;
					TETRID_block[2].x=1; TETRID_block[2].y=0;
					TETRID_block[3].x=0; TETRID_block[3].y=1;
				}
				if(rotation==1){TETRID_block[0].x=0; TETRID_block[0].y=0;
					TETRID_block[1].x=-1; TETRID_block[1].y=-1;
					TETRID_block[2].x=0; TETRID_block[2].y=1;
					TETRID_block[3].x=-1; TETRID_block[3].y=0;
				}
				break;
			}
		case ZBLOCK:{
				if(rotation==0){TETRID_block[0].x=0; TETRID_block[0].y=0;
					TETRID_block[1].x=-1; TETRID_block[1].y=0;
					TETRID_block[2].x=1; TETRID_block[2].y=1;
					TETRID_block[3].x=0; TETRID_block[3].y=1;
				}
				if(rotation==1){TETRID_block[0].x=0; TETRID_block[0].y=0;
					TETRID_block[1].x=0; TETRID_block[1].y=1;
					TETRID_block[2].x=1; TETRID_block[2].y=-1;
					TETRID_block[3].x=1; TETRID_block[3].y=0;
				}
				break;
			}
		case IBLOCK:{
				if(rotation==0){TETRID_block[0].x=0; TETRID_block[0].y=0;
					TETRID_block[1].x=-2; TETRID_block[1].y=0;
					TETRID_block[2].x=-1; TETRID_block[2].y=0;
					TETRID_block[3].x=1; TETRID_block[3].y=0;
				}
				if(rotation==1){TETRID_block[0].x=0; TETRID_block[0].y=0;
					TETRID_block[1].x=0; TETRID_block[1].y=-2;
					TETRID_block[2].x=0; TETRID_block[2].y=-1;
					TETRID_block[3].x=0; TETRID_block[3].y=1;
				}
				break;
			}
		case SQUAREBLOCK:{
				if(rotation==0){TETRID_block[0].x=0; TETRID_block[0].y=0;
					TETRID_block[1].x=0; TETRID_block[1].y=1;
					TETRID_block[2].x=-1; TETRID_block[2].y=1;
					TETRID_block[3].x=-1; TETRID_block[3].y=0;
				}
				break;
			}*/





		case TBLOCK:{
				if(rotation==0){TETRID_block[0].x=0; TETRID_block[0].y=0;
					TETRID_block[1].x=0; TETRID_block[1].y=1;
					TETRID_block[2].x=-1; TETRID_block[2].y=0;
					//TETRID_block[3].x=1; TETRID_block[3].y=0;
				}
				if(rotation==1){TETRID_block[0].x=0; TETRID_block[0].y=0;
					TETRID_block[1].x=-1; TETRID_block[1].y=0;
					TETRID_block[2].x=0; TETRID_block[2].y=-1;
					//TETRID_block[3].x=0; TETRID_block[3].y=1;
				}
				if(rotation==2){TETRID_block[0].x=0; TETRID_block[0].y=0;
					TETRID_block[1].x=0; TETRID_block[1].y=-1;
					TETRID_block[2].x=1; TETRID_block[2].y=0;
					//TETRID_block[3].x=-1; TETRID_block[3].y=0;
				}
				if(rotation==3){TETRID_block[0].x=0; TETRID_block[0].y=0;
					TETRID_block[1].x=1; TETRID_block[1].y=0;
					TETRID_block[2].x=0; TETRID_block[2].y=1;
					//TETRID_block[3].x=0; TETRID_block[3].y=-1;
				}
				break;
			}
		case JBLOCK:{
				if(rotation==0){TETRID_block[0].x=0; TETRID_block[0].y=0;
					TETRID_block[1].x=-1; TETRID_block[1].y=1;
					TETRID_block[2].x=1; TETRID_block[2].y=1;
					//TETRID_block[3].x=1; TETRID_block[3].y=1;
				}
				if(rotation==1){TETRID_block[0].x=0; TETRID_block[0].y=0;
					TETRID_block[1].x=-1; TETRID_block[1].y=-1;
					TETRID_block[2].x=-1; TETRID_block[2].y=1;
					//TETRID_block[3].x=-1; TETRID_block[3].y=1;
				}
				if(rotation==2){TETRID_block[0].x=0; TETRID_block[0].y=0;
					TETRID_block[1].x=1; TETRID_block[1].y=-1;
					TETRID_block[2].x=-1; TETRID_block[2].y=-1;
					//TETRID_block[3].x=-1; TETRID_block[3].y=-1;
				}
				if(rotation==3){TETRID_block[0].x=0; TETRID_block[0].y=0;
					TETRID_block[1].x=1; TETRID_block[1].y=1;
					TETRID_block[2].x=1; TETRID_block[2].y=-1;
					//TETRID_block[3].x=1; TETRID_block[3].y=-1;
				}
				break;
			}
		case LBLOCK:{
				if(rotation==0){TETRID_block[0].x=0; TETRID_block[0].y=0;
					TETRID_block[1].x=-1; TETRID_block[1].y=-1;
					TETRID_block[2].x=0; TETRID_block[2].y=1;
					//TETRID_block[3].x=1; TETRID_block[3].y=0;
				}
				if(rotation==1){TETRID_block[0].x=0; TETRID_block[0].y=0;
					TETRID_block[1].x=1; TETRID_block[1].y=-1;
					TETRID_block[2].x=-1; TETRID_block[2].y=0;
					//TETRID_block[3].x=0; TETRID_block[3].y=1;
				}
				if(rotation==2){TETRID_block[0].x=0; TETRID_block[0].y=0;
					TETRID_block[1].x=1; TETRID_block[1].y=1;
					TETRID_block[2].x=0; TETRID_block[2].y=-1;
					//TETRID_block[3].x=-1; TETRID_block[3].y=0;
				}
				if(rotation==3){TETRID_block[0].x=0; TETRID_block[0].y=0;
					TETRID_block[1].x=-1; TETRID_block[1].y=1;
					TETRID_block[2].x=1; TETRID_block[2].y=0;
					//TETRID_block[3].x=0; TETRID_block[3].y=-1;
				}
				break;
			}
		case BACKZBLOCK:{
				if(rotation==0){TETRID_block[0].x=0; TETRID_block[0].y=0;
					TETRID_block[1].x=1; TETRID_block[1].y=-1;
					TETRID_block[2].x=0; TETRID_block[2].y=1;
					//TETRID_block[3].x=0; TETRID_block[3].y=1;
				}
				if(rotation==1){TETRID_block[0].x=0; TETRID_block[0].y=0;
					TETRID_block[1].x=1; TETRID_block[1].y=1;
					TETRID_block[2].x=-1; TETRID_block[2].y=0;
					//TETRID_block[3].x=-1; TETRID_block[3].y=0;
				}
				if(rotation==2){TETRID_block[0].x=0; TETRID_block[0].y=0;
					TETRID_block[1].x=-1; TETRID_block[1].y=1;
					TETRID_block[2].x=0; TETRID_block[2].y=-1;
					//TETRID_block[3].x=-1; TETRID_block[3].y=0;
				}
				if(rotation==3){TETRID_block[0].x=0; TETRID_block[0].y=0;
					TETRID_block[1].x=-1; TETRID_block[1].y=-1;
					TETRID_block[2].x=1; TETRID_block[2].y=0;
					//TETRID_block[3].x=0; TETRID_block[3].y=-1;
				}
				break;
			}
		case ZBLOCK:{
				if(rotation==0){TETRID_block[0].x=0; TETRID_block[0].y=0;
					TETRID_block[1].x=0; TETRID_block[1].y=-1;
					TETRID_block[2].x=0; TETRID_block[2].y=1;
					//TETRID_block[3].x=0; TETRID_block[3].y=1;
				}
				if(rotation==1){TETRID_block[0].x=0; TETRID_block[0].y=0;
					TETRID_block[1].x=1; TETRID_block[1].y=0;
					TETRID_block[2].x=-1; TETRID_block[2].y=0;
					//TETRID_block[3].x=1; TETRID_block[3].y=0;
				}
				break;
			}
		case IBLOCK:{
				if(rotation==0){TETRID_block[0].x=0; TETRID_block[0].y=0;
					TETRID_block[1].x=-1; TETRID_block[1].y=-1;
					TETRID_block[2].x=1; TETRID_block[2].y=1;
					//TETRID_block[3].x=1; TETRID_block[3].y=0;
				}
				if(rotation==1){TETRID_block[0].x=0; TETRID_block[0].y=0;
					TETRID_block[1].x=1; TETRID_block[1].y=-1;
					TETRID_block[2].x=-1; TETRID_block[2].y=1;
					//TETRID_block[3].x=0; TETRID_block[3].y=1;
				}
				break;
			}



		default: break;
	};
}//**********************************************************END SET BLOCK LOCATIONS


//=========================================================================================================================
bool TETRID_new_piece(int type_of_piece)
{//=========================================================================================================================
	TETRID_current_location_x=TETRID_PLAYINGFIELD_SIZE_X/2;
	TETRID_current_location_y=1;
	TETRID_set_block_locations(type_of_piece, 0); //******************************SET BLOCK LOCATIONS
	if(
			(TETRID_playing_field[TETRID_current_location_x+TETRID_block[0].x][TETRID_current_location_y+TETRID_block[0].y].filled==1)
			||(TETRID_playing_field[TETRID_current_location_x+TETRID_block[1].x][TETRID_current_location_y+TETRID_block[1].y].filled==1)
			||(TETRID_playing_field[TETRID_current_location_x+TETRID_block[2].x][TETRID_current_location_y+TETRID_block[2].y].filled==1)
			//||(TETRID_playing_field[TETRID_current_location_x+TETRID_block[3].x][TETRID_current_location_y+TETRID_block[3].y].filled==1)

		)
	{
		TETRID_set_block_locations(TETRID_current_piece, TETRID_current_rotation);
		return 1;
	} //******************************SET BLOCK LOCATIONS
	else
	{
		TETRID_current_piece=type_of_piece;
		TETRID_playing_field[TETRID_current_location_x+TETRID_block[0].x][TETRID_current_location_y+TETRID_block[0].y].filled=1;
		TETRID_playing_field[TETRID_current_location_x+TETRID_block[1].x][TETRID_current_location_y+TETRID_block[1].y].filled=1;
		TETRID_playing_field[TETRID_current_location_x+TETRID_block[2].x][TETRID_current_location_y+TETRID_block[2].y].filled=1;
		//TETRID_playing_field[TETRID_current_location_x+TETRID_block[3].x][TETRID_current_location_y+TETRID_block[3].y].filled=1;

		TETRID_current_rotation=0;
		TETRID_set_block_colors(type_of_piece);
		TETRID_set_playing_field_colors();
		return 0;
	}
}


//=========================================================================================================================
void TETRID_new_random_piece()
{//=========================================================================================================================
	//***********************CHECK LINES

	TETRID_check_for_fast_music();

	if(TETRID_can_make_new_piece&&TETRID_amt_of_lines_to_flash==0)
	{
		TETRID_dying=TETRID_new_piece(TETRID_next_piece);
		TETRID_can_make_new_piece=0;
		switch(rand()%TETRID_AMT_OF_PIECES)
		{
			case 0:{TETRID_next_piece=TBLOCK;break;}
			case 1:{TETRID_next_piece=JBLOCK;break;}
			case 2:{TETRID_next_piece=LBLOCK;break;}
			case 3:{TETRID_next_piece=BACKZBLOCK;break;}
			case 4:{TETRID_next_piece=ZBLOCK;break;}
			case 5:{TETRID_next_piece=IBLOCK;break;}
			case 6:{TETRID_next_piece=SQUAREBLOCK;break;}
			default:break;
		}
	}
}

//=========================================================================================================================
void TETRID_init_playingfield_array()
{//=========================================================================================================================
	int x,y;
	for (x=1; x<TETRID_PLAYINGFIELD_SIZE_X-1; x++){
		for(y=0; y<TETRID_PLAYINGFIELD_SIZE_Y-1; y++){TETRID_playing_field[x][y].filled=0;TETRID_playing_field[x][y].color=bEMPTY;}
	}
	x=0;
	for(y=0;y<TETRID_PLAYINGFIELD_SIZE_Y;y++){TETRID_playing_field[x][y].filled=1;TETRID_playing_field[x][y].color=bRED;}
	x=TETRID_PLAYINGFIELD_SIZE_X-1;
	for(y=0;y<TETRID_PLAYINGFIELD_SIZE_Y;y++){TETRID_playing_field[x][y].filled=1;TETRID_playing_field[x][y].color=bRED;}
	y=TETRID_PLAYINGFIELD_SIZE_Y-1;
	for(x=0;x<TETRID_PLAYINGFIELD_SIZE_X-1;x++){TETRID_playing_field[x][y].filled=1;TETRID_playing_field[x][y].color=bRED;}
	TETRID_current_piece=7;
	TETRID_can_make_new_piece=1;
}

//=========================================================================================================================
	void TETRID_init_game()
{//=========================================================================================================================
	if(TETRID_background_is_init==0)
	{
		//ham_SetBgMode(0);
		//ham_LoadBGPal((void *)&master_Palette,sizeof(master_Palette));
		//ham_SetBgPalCol 	(0, COLOR_NAVY);
		//ham_SetBgPalCol 	(1, COLOR_BLACK);

		//INIT THE SCROLLING BACKGROUND : bg 1
		//ham_bg[3].ti = ham_InitTileSet((void *)&scrollingbackground_Tiles,SIZEOF_16BIT(scrollingbackground_Tiles),1,1);
		//ham_bg[3].mi = ham_InitMapSet((void *)&scrollingbackground_Map,SIZEOF_16BIT(scrollingbackground_Map),0,0);
		//ham_InitBg(3,1,3,0);
		//initialize the playing field background (the scrolly one) on bg 3
		//ham_bg[2].ti = ham_InitTileSet((void *)&playingbackground_Tiles,SIZEOF_16BIT(playingbackground_Tiles),1,1);
		//ham_bg[2].mi = ham_InitMapSet((void *)&playingbackground_Map,SIZEOF_16BIT(playingbackground_Map),0,0);
		//ham_InitBg(2,1,2,0);


		{
		   TETRID_palette =         (short unsigned int*)HARDWARE_load_file("/minigame/tetrid/TETRID_playingfield_Pal.bin");
		   TETRID_tileset =         (unsigned char*)HARDWARE_load_file("/minigame/tetrid/TETRID_playingfield_Tiles.bin");
		   TETRID_map     =         (short unsigned int*)HARDWARE_load_file("/minigame/tetrid/TETRID_playingfield_Map.bin");
		   TETRID_original_map     =         (short unsigned int*)HARDWARE_load_file("/minigame/tetrid/TETRID_playingfield_Map.bin");
		   TETRID_tileset_size =     HARDWARE_get_file_size("/minigame/tetrid/TETRID_playingfield_Tiles.bin");

		}


		//init the playing field,(walls and tile sprites) bg 2

		//HARDWARE_load_bg_palette(0,TETRID_bg_layer,TETRID_palette);
		//HARDWARE_load_bg_tiles(0,TETRID_bg_layer,TETRID_tileset,TETRID_tileset_size/2);
		//HARDWARE_load_map(0,TETRID_bg_layer,TETRID_map,BG_256X256,256,256);

		//HARDWARE_init_bg(0,TETRID_bg_layer,BG_256X256,0,1);
		//HARDWARE_scroll_bg_xy(0,TETRID_bg_layer,0,0);


		HARDWARE_load_AUX_map_to_xy_xy(2,TETRID_map,TETRID_tileset,TETRID_palette,256,192,TETRID_fromx+TETRID_playing_field_map_scroll_x,TETRID_fromy,TETRID_aspectratio,0);

		TETRID_background_is_init=1;

		int x=0;
		int y=0;
		for(x=0;x<32;x++)
		for(y=0;y<24;y++)
		{
			TETRID_set_tile(0,TETRID_bg_layer,x,y,8+(23*32));

		}
		x=0;
		for(y=0;y<24;y++)TETRID_set_tile(0,TETRID_bg_layer,x,y,(31*32));
		x=31;
		for(y=0;y<24;y++)TETRID_set_tile(0,TETRID_bg_layer,x,y,(31*32));

		TETRID_redraw_map();


	}



	if(easymode==1)
	{
		TETRID_extra_stage_level = 6;
		TETRID_extra_extra_stage_level =  7;
		TETRID_master_stage_level =  8;
		TETRID_credits_level = 9;
	}
	else
	{
		TETRID_extra_stage_level = 9;
		TETRID_extra_extra_stage_level =  14;
		TETRID_master_stage_level =  19;
		TETRID_credits_level = 24;
	}



	TETRID_credits=0;
	TETRID_credit_screen_init=0;
	TETRID_playing_fast_music=0;
	TETRID_init_playingfield_array(); //fill array with 0's
	TETRID_frames=0;
	TETRID_extra_stage_flash=0;
	TETRID_extra_extra_stage_flash=0;
	TETRID_master_stage_flash=0;
	TETRID_teh_matrixxx=0;
	TETRID_background_color=0;
	TETRID_block_tile_row=0;
	TETRID_current_score=0;
	TETRID_current_level=1;
	TETRID_tried_to_drop=0;
	TETRID_sliding=0;
	TETRID_already_updating=0;
	TETRID_frames_since_last_pressed_A=0;
	TETRID_frames_since_last_pressed_B=0;
	TETRID_frames_since_last_pressed_RIGHT=0;
	TETRID_frames_since_last_pressed_LEFT=0;
	TETRID_frames_since_last_pressed_DOWN=0;
	TETRID_frames_since_last_pressed_R=0;
	TETRID_can_press_A=1;
	TETRID_can_press_B=1;
	TETRID_can_press_RIGHT=1;
	TETRID_can_press_LEFT=1;
	TETRID_can_press_DOWN=1;
	TETRID_can_press_R=1;
	TETRID_level_drop_speed=30;
	TETRID_playing_field_map_scroll_x=0;

	TETRID_dead_x=1;
	TETRID_dead_y=TETRID_PLAYINGFIELD_SIZE_Y-1;
	TETRID_dying=0;
	TETRID_flash_screen_amt=0;
	TETRID_amt_of_lines_to_flash=0;
	TETRID_times_flashed=0;
	TETRID_next_piece=rand()%TETRID_AMT_OF_PIECES;
	TETRID_new_random_piece();

	int x=0;
	for(x=0;x<9;x++)
	{
		//HARDWARE_set_bg_palette_color(0,TETRID_bg_layer,(int)TETRID_tileset[(8*8)*TETRID_map[x]],TETRID_get_gametoy_palette_color(x));

		TETRID_palette[(int)TETRID_tileset[(8*8)*TETRID_original_map[x]]]=TETRID_get_gametoy_palette_color(x);
	}



	HARDWARE_play_music("tetrid",32);


}



//=========================================================================================================================
void TETRID_main()
{//=========================================================================================================================


	if(TETRID_credits==0)
	{

			if(TETRID_background_is_init==0)TETRID_init_game();

			if(TETRID_newframe==1)
			{
				TETRID_newframe=0;


				//bg.scrollbackground();
				//TEHMATRIXXXTEXT

				//TETRID_block_tile_row=4;
				//ham_SetBgPalColRGB(1,0,teh_matrixxx,0);
				if(TETRID_teh_matrixxx+20>255)TETRID_teh_matrixxx=0;
				else TETRID_teh_matrixxx+=20;

				//FLASHINGB&WTEXT

				//TETRID_block_tile_row=4;
				//ham_SetBgPalColRGB(1,teh_matrixxx,teh_matrixxx,teh_matrixxx);
				//if(teh_matrixxx+20>255)teh_matrixxx=0;
				//else teh_matrixxx+=20;


				if(TETRID_master_stage_flash)
				{
					if(TETRID_vbl_count%3==0)
					{
						//HARDWARE_set_bg_palette_color(0,TETRID_bg_layer,(int)TETRID_tileset[(8*8)*TETRID_map[rand()%9]],TETRID_get_gametoy_palette_color(rand()%11));
						TETRID_palette[(int)TETRID_tileset[(8*8)*TETRID_original_map[rand()%9]]] = TETRID_get_gametoy_palette_color(rand()%11);
					}
					TETRID_shakeplayingfield();

				}
				else
				{

					//INSANECOLORS
					if(TETRID_extra_stage_flash)
					{
						if(TETRID_vbl_count%5==0)
						{
							//HARDWARE_set_bg_palette_color(0,TETRID_bg_layer,(int)TETRID_tileset[(8*8)*TETRID_map[rand()%9]],TETRID_get_gametoy_palette_color(rand()%11));
							TETRID_palette[(int)TETRID_tileset[(8*8)*TETRID_original_map[rand()%9]]] = TETRID_get_gametoy_palette_color(rand()%11);
						}
						TETRID_scrollplayingbackground();

					}

					//HURTSMYEYES
					if(TETRID_extra_extra_stage_flash)
					{
						//ham_SetBgPalColRGB(6,rand()%255,rand()%255,rand()%255);
						//int x=0;
						//for(x=0; x<TETRID_PLAYINGFIELD_SIZE_X;x++)
						//ham_SetBgPalColRGB(rand()%14,rand()%255,rand()%255,rand()%255);
						//TETRID_block_tile_row=4;
						if(TETRID_vbl_count%2==0)TETRID_shakeplayingfield();
					}
				}




				if(TETRID_vbl_count%5==0)
				{

					static int fade_in_out=0;

					if(fade_in_out==0)
					{
						TETRID_score_color_fade++;
						if(TETRID_score_color_fade>10)
						{
							TETRID_score_color_fade=10;
							fade_in_out=1;
						}
					}
					else
					{
						TETRID_score_color_fade--;
						if(TETRID_score_color_fade<1)
						{
							TETRID_score_color_fade=1;
							fade_in_out=0;
						}
					}

					//HARDWARE_set_bg_palette_color(0,TETRID_bg_layer,(int)TETRID_tileset[(8*8)*TETRID_map[1]],TETRID_get_gametoy_palette_color(TETRID_score_color_fade));
					TETRID_palette[(int)TETRID_tileset[(8*8)*TETRID_original_map[1]]] = TETRID_get_gametoy_palette_color(TETRID_score_color_fade);

				}


				if(TETRID_dying){TETRID_dead();}
					else if(TETRID_amt_of_lines_to_flash!=0){TETRID_flash_line();}
						else if(TETRID_flash_screen_amt>0){TETRID_flash_screen();}
							else
							{

								TETRID_redraw_playing_field();
								TETRID_update_score(0);
								TETRID_update_level();
								TETRID_update_next_piece();

								if(TETRID_frames>TETRID_level_drop_speed&&TETRID_can_make_new_piece==0)
								{

									TETRID_move_piece(TETRID_DOWN);
									TETRID_frames=0;

								}

								if(TETRID_can_make_new_piece)
								{

									TETRID_check_lines();
									TETRID_new_random_piece();

								}
								else
								TETRID_query_keys();

								TETRID_frames++;

							}


				TETRID_redraw_map();
			}
		}
		else
		{
			if(TETRID_credit_screen_init==0)
			{
				HARDWARE_delete_AUX_bg(2);
				//HARDWARE_delete_bg(0,1);

				HARDWARE_stop_music();

				HARDWARE_unload_file((void**)&TETRID_palette);
				HARDWARE_unload_file((void**)&TETRID_tileset);
				HARDWARE_unload_file((void**)&TETRID_map);
				HARDWARE_unload_file((void**)&TETRID_original_map);

				{
				   TETRID_palette =         (short unsigned int*)HARDWARE_load_file("/minigame/tetrid/TETRID_credits_Pal.bin");
				   TETRID_tileset =         (unsigned char*)HARDWARE_load_file("/minigame/tetrid/TETRID_credits_Tiles.bin");
				   TETRID_map     =         (short unsigned int*)HARDWARE_load_file("/minigame/tetrid/TETRID_credits_Map.bin");
				   TETRID_tileset_size =     HARDWARE_get_file_size("/minigame/tetrid/TETRID_credits_Tiles.bin");

				}

				//init the playing field,(walls and tile sprites) bg 2
				//HARDWARE_load_bg_palette(0,TETRID_bg_layer,TETRID_palette);
				//HARDWARE_load_bg_tiles(0,TETRID_bg_layer,TETRID_tileset,TETRID_tileset_size/2);
				//HARDWARE_load_map(0,TETRID_bg_layer,TETRID_map,BG_256X256,256,256);
				//HARDWARE_init_bg(0,TETRID_bg_layer,BG_256X256,0,1);
				//HARDWARE_scroll_bg_xy(0,TETRID_bg_layer,0,0);


				HARDWARE_load_AUX_map_to_xy_xy(2,TETRID_map,TETRID_tileset,TETRID_palette,256,192,TETRID_fromx+TETRID_playing_field_map_scroll_x,TETRID_fromy,TETRID_aspectratio,0);

				TETRID_background_is_init=0;
				TETRID_credit_screen_init=1;

			}

			if(TETRID_vbl_count%30==0)
			{
				static int everyother=0;
				everyother++;

				if(everyother%4==0)
				{
					int r=rand()%3;
					if(r==0)CAPTION_make_caption(&friend_tetrid_caption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,5,"Yuu going to press Start?",FONT_NORMAL_ID,WHITE,BLACK,1,1);
					if(r==1)CAPTION_make_caption(&friend_tetrid_caption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,5,"Yuu should press Start",FONT_NORMAL_ID,WHITE,BLACK,1,1);
					if(r==2)CAPTION_make_caption(&friend_tetrid_caption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,5,"Yuu needs to press Start!",FONT_NORMAL_ID,WHITE,BLACK,1,1);
				}
			}

			if(BUTTON_START_PRESSED)
			{

				HARDWARE_delete_AUX_bg(2);
				//HARDWARE_delete_bg(0,1);

				HARDWARE_unload_file((void**)&TETRID_palette);
				HARDWARE_unload_file((void**)&TETRID_tileset);
				HARDWARE_unload_file((void**)&TETRID_map);



				GAME_playing_tetrid=0;

			}


		}

	//TETRID_end_game();
}


//=========================================================================================================================
void TETRID_vbl()
{//=========================================================================================================================
	TETRID_newframe=1;
	TETRID_vbl_count++;
	if(TETRID_vbl_count>59)TETRID_vbl_count=0;
}



