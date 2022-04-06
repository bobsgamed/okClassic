//==============================================================================
//Copyright 2003-2012 by Robert Pelloni.
//All Rights Reserved.
//==============================================================================


#include "../main.h"
//#include "ping.h"



int GAME_playing_ping=0;

int PING_got_high_score=0;


int PING_paddle_gfx[PING_PADDLE_SIZE_X*PING_PADDLE_SIZE_Y] = {2};
int PING_ball_gfx[PING_PADDLE_SIZE_X*PING_PADDLE_SIZE_X] = {2};


//int PING_lpaddle_gfx_slot = -1;

SPRITE* PING_lpaddle_sprite;
//int PING_lpaddle_sprite_id = 127-10;


int PING_lpaddle_x = 0;
int PING_lpaddle_y = 0;

//int PING_rpaddle_gfx_slot = -1;

SPRITE* PING_rpaddle_sprite;
//int PING_rpaddle_sprite_id = 127-11;


int PING_rpaddle_x = 0;
int PING_rpaddle_y = 0;

//int PING_ball_gfx_slot = -1;

SPRITE* PING_ball_sprite;
//int PING_ball_sprite_id = 127-12;


int PING_ball_x = 0;
int PING_ball_y = 0;

int PING_paddle=LEFT;
int PING_paddle_speed=2;


int PING_screen_x = 0;
int PING_screen_y = 0;


int PING_high_score=0;
int PING_max_ball_speed = 0;

int PING_score =0;

int PING_tv_rolling=0;

int PING_frames_since_last_pressed_A=0;
int PING_frames_since_last_pressed_B=0;
int PING_frames_since_last_pressed_RIGHT=0;
int PING_frames_since_last_pressed_LEFT=0;
int PING_frames_since_last_pressed_DOWN=0;
int PING_frames_since_last_pressed_UP=0;
int PING_frames_since_last_pressed_R=0;
bool PING_can_press_A=0;
bool PING_can_press_B=0;
bool PING_can_press_RIGHT=0;
bool PING_can_press_LEFT=0;
bool PING_can_press_DOWN=0;
bool PING_can_press_UP=0;
bool PING_can_press_R=0;

int PING_dead_x=0;
int PING_dead_y=0;
bool PING_dying=0;

bool PING_credits=0;
bool PING_credit_screen_init=0;
bool PING_background_is_init=0;

bool PING_already_updating=0;

int PING_frames=0; //frame counter
int PING_vbl_count=0;

int PING_scrollingplayingfield_map_x=0;
int PING_scrollingplayingfield_map_y=0;
int PING_playing_field_map_scroll_x=0;


bool PING_newframe=1;


unsigned short* PING_palette =  NULL;
unsigned char* PING_tileset =   NULL;
unsigned short* PING_map     =   NULL;

int PING_tileset_size = 0;

int PING_quit=0;



//=========================================================================================================================
void PING_reset_ball_paddle_xy()
{//=========================================================================================================================



PING_lpaddle_x = 10 - (PING_PADDLE_SIZE_X/2);
PING_lpaddle_y = (PING_HEIGHT_PIXELS/2) - (PING_PADDLE_SIZE_Y/2);


PING_rpaddle_x = PING_WIDTH_PIXELS - 10 - (PING_PADDLE_SIZE_X/2);
PING_rpaddle_y = (PING_HEIGHT_PIXELS/2) - (PING_PADDLE_SIZE_Y/2);


PING_ball_x = (PING_WIDTH_PIXELS/2) - (PING_PADDLE_SIZE_X/2);
PING_ball_y = (PING_HEIGHT_PIXELS/2) - (PING_PADDLE_SIZE_X/2);

}




//=========================================================================================================================
void PING_redraw_map()
{//=========================================================================================================================



	HARDWARE_delete_AUX_bg(1);
	HARDWARE_load_AUX_map_to_xy_xy(1,PING_map,PING_tileset,PING_palette,256,192,TV_fromx+PING_playing_field_map_scroll_x,TV_fromy,TV_aspectratio,0);


}


//=========================================================================================================================
void PING_set_tile(int screen,int layer, int x, int y, int index)
{//=========================================================================================================================

	//HARDWARE_set_32x32_map_tile(screen,layer,x,y,PING_map[index]);

	PING_map[(y*32)+x]=PING_map[index];


}





//=========================================================================================================================
void PING_shakeplayingfield()
{//=========================================================================================================================
	//called every VBL to make the background pretty
	//M_BG1SCRLX_SET(playing_field_map_x);

	static int dir=0;
	if(dir==0)
	{
		PING_playing_field_map_scroll_x++;
		if(PING_playing_field_map_scroll_x>3)
		{
			dir=1;
			PING_playing_field_map_scroll_x--;
		}
	}
	else
	{
		PING_playing_field_map_scroll_x--;
		if(PING_playing_field_map_scroll_x<-3)
		{
			dir=0;
			PING_playing_field_map_scroll_x++;
		}
	}


	HARDWARE_set_AUX_map_xy(1,TV_fromx+PING_playing_field_map_scroll_x,TV_fromy);
}






//=========================================================================================================================
void PING_query_keys()
{//=========================================================================================================================


	if((!BUTTON_UP_HELD)||(PING_frames_since_last_pressed_UP>=0))
	{
		PING_can_press_UP=1;
	}
	else PING_frames_since_last_pressed_UP++;


	if((!BUTTON_DOWN_HELD)||(PING_frames_since_last_pressed_DOWN>=0))
	{
		PING_can_press_DOWN=1;
	}
	else PING_frames_since_last_pressed_DOWN++;



	if((BUTTON_UP_HELD)&&(PING_can_press_UP))
	{
		//HARDWARE_play_sound("tick",127,40000+rand()%20000,0);

		if(PING_paddle==LEFT)
		{
			PING_lpaddle_y-=PING_paddle_speed;
			if(PING_lpaddle_y<8)PING_lpaddle_y=8;
		}
		if(PING_paddle==RIGHT)
		{
			PING_rpaddle_y-=PING_paddle_speed;
			if(PING_rpaddle_y<8)PING_rpaddle_y=8;
		}

		//PING_lpaddle_y-=2;
		//PING_ball_y--;

		PING_can_press_UP=0;
		PING_frames_since_last_pressed_UP=0;
	}


	if((BUTTON_DOWN_HELD)&&(PING_can_press_DOWN))
	{
		//HARDWARE_play_sound("tick",127,40000+rand()%20000,0);

		if(PING_paddle==LEFT)
		{
			PING_lpaddle_y+=PING_paddle_speed;
			if(PING_lpaddle_y+PING_PADDLE_SIZE_Y>=PING_HEIGHT_PIXELS)PING_lpaddle_y=PING_HEIGHT_PIXELS-(PING_PADDLE_SIZE_Y+1);
		}
		if(PING_paddle==RIGHT)
		{
			PING_rpaddle_y+=PING_paddle_speed;
			if(PING_rpaddle_y+PING_PADDLE_SIZE_Y>=PING_HEIGHT_PIXELS)PING_rpaddle_y=PING_HEIGHT_PIXELS-(PING_PADDLE_SIZE_Y+1);
		}

		//PING_lpaddle_y+=2;
		//PING_ball_y++;

		PING_can_press_DOWN=0;
		PING_frames_since_last_pressed_DOWN=0;
	}


}


//=========================================================================================================================
void PING_dead()
{//=========================================================================================================================


	static int first_death=0;

	if(first_death==0)
	{
		first_death=1;
		HARDWARE_play_music("tetrid_death",32);

		CAPTION_make_caption(&yuu_ping_caption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,3,"Aww.. Yuu sucks. Come on, let's see this.",FONT_NORMAL_ID,WHITE,BLACK,1,1);
	}
	else
	if(first_death==1)
	{
		first_death=0;
		HARDWARE_play_music("tetrid_death",32);

		CAPTION_make_caption(&yuu_ping_caption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,3,"Yuu thinks there's some kind of trick?",FONT_NORMAL_ID,WHITE,BLACK,1,1);
	}

}




//=========================================================================================================================
void PING_update_score()
{//=========================================================================================================================


	//PING_score+=amt;
	char char_score[15];
	sprintf(char_score,"%d",PING_score);
	int score_length=strlen(char_score);


	int x=0;

	//if(PING_score==0)
	for(x=0;x<3;x++)
	{
		PING_set_tile(1,2,8+x-3,2,29*32);
		PING_set_tile(1,2,8+x-3,3,29*32);
	}

	for(x=0;x<score_length;x++)
	{
		PING_set_tile(1,2,8+x-score_length,2,(char_score[x]-48)+(30*32));
		PING_set_tile(1,2,8+x-score_length,3,(char_score[x]-48)+(31*32));
	}

	char char_hiscore[15];
	sprintf(char_hiscore,"%d",PING_high_score);
	int hiscore_length=strlen(char_hiscore);

	//if(PING_high_score==0)
	for(x=0;x<3;x++)
	{
		PING_set_tile(1,2,29+x-3,2,29*32);
		PING_set_tile(1,2,29+x-3,3,29*32);
	}

	for(x=0;x<hiscore_length;x++)
	{
		PING_set_tile(1,2,29+x-hiscore_length,2,(char_hiscore[x]-48)+(30*32));
		PING_set_tile(1,2,29+x-hiscore_length,3,(char_hiscore[x]-48)+(31*32));
	}

}





//=========================================================================================================================
	void PING_init_game()
{//=========================================================================================================================

if(easymode==1)
{
	PING_high_score=66;
	PING_max_ball_speed = 9;

}
else
{
	PING_high_score=333;//142
	PING_max_ball_speed = 9;
}




PING_screen_x = TV_fromx + 15+3;
PING_screen_y = TV_fromy + 15+3+10;

	if(PING_background_is_init==0)
	{


	   PING_palette =         (short unsigned int*)HARDWARE_load_file("/minigame/ping/ping_v00_Pal.bin");
	   PING_tileset =         (unsigned char*)HARDWARE_load_file("/minigame/ping/ping_v00_Tiles.bin");
	   PING_map     =         (short unsigned int*)HARDWARE_load_file("/minigame/ping/ping_v00_Map.bin");
	   //PING_original_map =    HARDWARE_load_file("/minigame/ping/ping_v00_Map.bin");
	   PING_tileset_size =    HARDWARE_get_file_size("/minigame/ping/ping_v00_Tiles.bin");

		HARDWARE_load_AUX_map_to_xy_xy(1,PING_map,PING_tileset,PING_palette,256,192,TV_fromx+PING_playing_field_map_scroll_x,TV_fromy,TV_aspectratio,0);

		PING_background_is_init=1;


		PING_reset_ball_paddle_xy();

		int f=0;
		for(f=0;f<PING_PADDLE_SIZE_X*PING_PADDLE_SIZE_Y;f++)PING_paddle_gfx[f]=2;
		for(f=0;f<PING_BALL_SIZE*PING_BALL_SIZE;f++)PING_ball_gfx[f]=2;

		//create paddle sprites, ball sprite

		//PING_lpaddle_gfx_slot = HARDWARE_create_sprite_gfxslot(1,PINGPADDLE_GFX,0,16,32,1,0);
		//HARDWARE_create_sprite(1,PING_lpaddle_sprite_id,PING_lpaddle_gfx_slot,16,32,1,0,0,0,0,0,5,0,PING_screen_x+PING_lpaddle_x,PING_screen_y+PING_lpaddle_y);
		PING_lpaddle_sprite = HARDWARE_create_sprite(PINGPADDLE_GFX,0,5,1.0f,PING_screen_x+PING_lpaddle_x,PING_screen_y+PING_lpaddle_y,255);

		//PING_rpaddle_gfx_slot = HARDWARE_create_sprite_gfxslot(1,PINGPADDLE_GFX,0,16,32,1,0);
		//HARDWARE_create_sprite(1,PING_rpaddle_sprite_id,PING_rpaddle_gfx_slot,16,32,1,0,0,0,0,0,5,0,PING_screen_x+PING_rpaddle_x,PING_screen_y+PING_rpaddle_y);
		PING_rpaddle_sprite = HARDWARE_create_sprite(PINGPADDLE_GFX,0,5,1.0f,PING_screen_x+PING_rpaddle_x,PING_screen_y+PING_rpaddle_y,255);

		//PING_ball_gfx_slot = HARDWARE_create_sprite_gfxslot(1,PINGBALL_GFX,0,8,8,1,0);
		//HARDWARE_create_sprite(1,PING_ball_sprite_id,PING_ball_gfx_slot,8,8,1,0,0,0,0,0,5,0,PING_screen_x+PING_ball_x,PING_screen_y+PING_ball_y);
		PING_ball_sprite = HARDWARE_create_sprite(PINGBALL_GFX,0,5,1.0f,PING_screen_x+PING_ball_x,PING_screen_y+PING_ball_y,255);


		CAPTION_make_caption(&yuu_ping_caption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,3,"Wow. This is horrible.",FONT_NORMAL_ID,WHITE,BLACK,1,1);

	}


	PING_frames=0;


	PING_frames_since_last_pressed_A=0;
	PING_frames_since_last_pressed_B=0;
	PING_frames_since_last_pressed_RIGHT=0;
	PING_frames_since_last_pressed_LEFT=0;
	PING_frames_since_last_pressed_DOWN=0;
	PING_frames_since_last_pressed_R=0;
	PING_can_press_A=1;
	PING_can_press_B=1;
	PING_can_press_RIGHT=1;
	PING_can_press_LEFT=1;
	PING_can_press_DOWN=1;
	PING_can_press_R=1;




}



//=========================================================================================================================
void PING_main()
{//=========================================================================================================================


	if(PING_quit==0)
	{

			if(PING_background_is_init==0)PING_init_game();

			if(PING_newframe==1)
			{
				PING_newframe=0;


				if(PING_tv_rolling)
				{
					//TODO: make the tv roll
					PING_shakeplayingfield();

				}

				if(PING_vbl_count%3==0)
				{
					//make the tv scanlines pulse
					static int fade_in_out=0;

					int spritecolor=3;
					int bgcolor=28;

					if(fade_in_out==0)
					{
						//set white to gray
						spritecolor=3;
						bgcolor=28;
						fade_in_out=1;
					}
					else
					{
						//set gray to white
						spritecolor=2;
						bgcolor=31;
						fade_in_out=0;
					}

					int f=0;
					for(f=0;f<PING_PADDLE_SIZE_X*PING_PADDLE_SIZE_Y;f++)PING_paddle_gfx[f]=spritecolor;
					for(f=0;f<PING_BALL_SIZE*PING_BALL_SIZE;f++)PING_ball_gfx[f]=spritecolor;
					//redraw sprites
					HARDWARE_update_sprite_texture(PING_lpaddle_sprite,0);
					HARDWARE_update_sprite_texture(PING_rpaddle_sprite,0);
					HARDWARE_update_sprite_texture(PING_ball_sprite,0);
					//set tilemap palette
					PING_palette[PING_tileset[8*8*PING_map[(29*32)+1]]] = HARDWARE_RGB(bgcolor,bgcolor,bgcolor);
				}


				if(PING_dying)
				{
					PING_dead();
				}
				else
				{
					//check keys
					PING_query_keys();


					static int PING_ball_direction_x=LEFT;

					static int PING_ball_direction_y=0;
					static int PING_angle=5;

					static int PING_ball_speed=1;


					//move ball==============================================================================
					//move up or down based on angle
					if(PING_vbl_count%PING_angle==0)PING_ball_y+=PING_ball_direction_y;

					//if hit ceiling, bounce
					if(PING_ball_y<=8)PING_ball_direction_y=1;
					if(PING_ball_y+PING_BALL_SIZE>PING_HEIGHT_PIXELS)PING_ball_direction_y=-1;

					int hitleft=0;
					int hitright=0;
					int hitwall=0;

					if(PING_ball_direction_x==LEFT)
					{
						PING_paddle=LEFT;
						PING_ball_x-=PING_ball_speed;

						if(PING_ball_x<=PING_lpaddle_x+PING_PADDLE_SIZE_X)
						{
							//if it's touching the paddle
							if(
								(PING_ball_y>=PING_lpaddle_y&&PING_ball_y<PING_lpaddle_y+PING_PADDLE_SIZE_Y)
								||
								(PING_ball_y+PING_BALL_SIZE>PING_lpaddle_y&&PING_ball_y+PING_BALL_SIZE<=PING_lpaddle_y+PING_PADDLE_SIZE_Y)
								)
							{
								hitleft=1;

							}
							else hitwall=1;
						}
					}
					else
					if(PING_ball_direction_x==RIGHT)
					{
						PING_paddle=RIGHT;
						PING_ball_x+=PING_ball_speed;

						if(PING_ball_x+PING_BALL_SIZE>PING_rpaddle_x)
						{
							//if it's touching the paddle
							if(
							(PING_ball_y>=PING_rpaddle_y&&PING_ball_y<PING_rpaddle_y+PING_PADDLE_SIZE_Y)
							||
							(PING_ball_y+PING_BALL_SIZE>PING_rpaddle_y&&PING_ball_y+PING_BALL_SIZE<=PING_rpaddle_y+PING_PADDLE_SIZE_Y)
							)
							{
								hitright=1;

							}
							else hitwall=1;
						}
					}

					//handle hits======================================================
					if(hitleft||hitright)
					{
						//play sound
						HARDWARE_play_sound("pingbeep",64,44100,0);

						//score
						PING_score++;

						if(PING_score==3)CAPTION_make_caption(&yuu_ping_caption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,3,"This is so easy.",FONT_NORMAL_ID,WHITE,BLACK,1,1);
						if(PING_score==15)CAPTION_make_caption(&yuu_ping_caption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,3,"Ok, maybe not.",FONT_NORMAL_ID,WHITE,BLACK,1,1);
						if(PING_score==30)CAPTION_make_caption(&yuu_ping_caption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,3,"There's a rhythm to it.",FONT_NORMAL_ID,WHITE,BLACK,1,1);
						if(PING_score==40)CAPTION_make_caption(&yuu_ping_caption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,3,"I'm starting to get it.",FONT_NORMAL_ID,WHITE,BLACK,1,1);
						if(PING_score==50)CAPTION_make_caption(&yuu_ping_caption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,3,"Yeah, I can do this.",FONT_NORMAL_ID,WHITE,BLACK,1,1);

						//increase speed
						//if(PING_vbl_count%2==0)
						PING_ball_speed++;
						if(PING_ball_speed>PING_max_ball_speed)PING_ball_speed=PING_max_ball_speed;

						int pixels_from_middle=0;

						if(hitleft)
						{
							//change direction
							PING_ball_direction_x=RIGHT;
							//if ball touching paddle, bounce depending on angle
							//set angle depending on where touched the paddle.
							//so we should calc based on the middle of the ball vs the middle of the paddle divided into chunks.
							if(PING_ball_y+(PING_BALL_SIZE/2)>PING_lpaddle_y+(PING_PADDLE_SIZE_Y/2))
							{
								if(PING_ball_direction_y==0)PING_ball_direction_y=1;//down
								pixels_from_middle = (PING_ball_y+(PING_BALL_SIZE/2))-(PING_lpaddle_y+(PING_PADDLE_SIZE_Y/2));
							}

							if(PING_ball_y+(PING_BALL_SIZE/2)<=PING_lpaddle_y+(PING_PADDLE_SIZE_Y/2))
							{
								if(PING_ball_direction_y==0)PING_ball_direction_y=-1;//up
								pixels_from_middle = (PING_lpaddle_y+(PING_PADDLE_SIZE_Y/2))-(PING_ball_y+(PING_BALL_SIZE/2));
							}
						}

						if(hitright)
						{
							//change direction
							PING_ball_direction_x=LEFT;

							//if ball touching paddle, bounce depending on angle
							if(PING_ball_y+(PING_BALL_SIZE/2)>PING_rpaddle_y+(PING_PADDLE_SIZE_Y/2))
							{
								if(PING_ball_direction_y==0)PING_ball_direction_y=1;//down
								pixels_from_middle = (PING_ball_y+(PING_BALL_SIZE/2))-(PING_rpaddle_y+(PING_PADDLE_SIZE_Y/2));
							}

							if(PING_ball_y+(PING_BALL_SIZE/2)<=PING_rpaddle_y+(PING_PADDLE_SIZE_Y/2))
							{
								if(PING_ball_direction_y==0)PING_ball_direction_y=-1;//up
								pixels_from_middle = (PING_rpaddle_y+(PING_PADDLE_SIZE_Y/2))-(PING_ball_y+(PING_BALL_SIZE/2));
							}
						}


							 if(pixels_from_middle<((PING_PADDLE_SIZE_Y/2)/6)*1)PING_angle=6;//+(rand()%1); //in the middle
						else if(pixels_from_middle<((PING_PADDLE_SIZE_Y/2)/6)*2)PING_angle=5;//+(rand()%1); //near the middle
						else if(pixels_from_middle<((PING_PADDLE_SIZE_Y/2)/6)*3)PING_angle=4;//+(rand()%1); //near edge
						else if(pixels_from_middle<((PING_PADDLE_SIZE_Y/2)/6)*4)PING_angle=3;//+(rand()%1); //very edge
						else if(pixels_from_middle<((PING_PADDLE_SIZE_Y/2)/6)*5)PING_angle=2;//+(rand()%1); //very edge
						else if(pixels_from_middle<((PING_PADDLE_SIZE_Y/2)/6)*6)PING_angle=1;//+(rand()%1); //very edge

					}

					if(hitwall) //reset
					{
						HARDWARE_play_sound("pingbad",64,44100,0);

						//reset ball speed, direction, x, y
						PING_ball_direction_x = LEFT;
						PING_ball_direction_y = 0;
						PING_angle=5;
						PING_ball_speed = 1;

						if(PING_score>PING_high_score)
						{
							PING_high_score=PING_score;
							PING_got_high_score=1;
							HARDWARE_play_sound("pinghighscore",64,44100,0);
						}
						PING_score = 0;

						if(PING_got_high_score==0)
						{

							int r=0;
							r=rand()%5;
							if(r==0)CAPTION_make_caption(&yuu_ping_caption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,3,"Is this even possible?",FONT_NORMAL_ID,WHITE,BLACK,1,1);
							if(r==1)CAPTION_make_caption(&yuu_ping_caption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,3,"I hate this game.",FONT_NORMAL_ID,WHITE,BLACK,1,1);
							if(r==2)CAPTION_make_caption(&yuu_ping_caption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,3,"What a dumb game.",FONT_NORMAL_ID,WHITE,BLACK,1,1);
							if(r==3)CAPTION_make_caption(&yuu_ping_caption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,3,"People liked this?",FONT_NORMAL_ID,WHITE,BLACK,1,1);
							if(r==4)CAPTION_make_caption(&yuu_ping_caption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,3,"What's the point of this?",FONT_NORMAL_ID,WHITE,BLACK,1,1);

							PING_reset_ball_paddle_xy();
						}
						else
						{
							PING_quit=1;
						}
					}


					//move paddles
					HARDWARE_set_sprite_xy(PING_lpaddle_sprite,PING_screen_x+PING_lpaddle_x,PING_screen_y+PING_lpaddle_y);
					HARDWARE_set_sprite_xy(PING_rpaddle_sprite,PING_screen_x+PING_rpaddle_x,PING_screen_y+PING_rpaddle_y);


						//if ball past paddle, update score, replace ball in middle.

					//set ball sprite
					HARDWARE_set_sprite_xy(PING_ball_sprite,PING_screen_x+PING_ball_x,PING_screen_y+PING_ball_y);


					PING_update_score();

					PING_frames++;

				}


				PING_redraw_map();
			}
		}
		else
		{


				HARDWARE_delete_AUX_bg(1);

				HARDWARE_delete_sprite(PING_lpaddle_sprite);
				HARDWARE_delete_sprite(PING_rpaddle_sprite);
				HARDWARE_delete_sprite(PING_ball_sprite);

				//HARDWARE_delete_sprite_gfxslot(1,PING_lpaddle_gfx_slot);
				//HARDWARE_delete_sprite_gfxslot(1,PING_rpaddle_gfx_slot);
				//HARDWARE_delete_sprite_gfxslot(1,PING_ball_gfx_slot);



				HARDWARE_unload_file((void**)&PING_palette);
				HARDWARE_unload_file((void**)&PING_tileset);
				HARDWARE_unload_file((void**)&PING_map);


				PING_background_is_init=0;

				GAME_playing_ping=0;

				unload_tv_fullscreen();


		}

}


//=========================================================================================================================
void PING_vbl()
{//=========================================================================================================================
	PING_newframe=1;
	PING_vbl_count++;
	if(PING_vbl_count>59)PING_vbl_count=0;
}



