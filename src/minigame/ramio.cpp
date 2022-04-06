//==============================================================================
//Copyright 2003-2012 by Robert Pelloni.
//All Rights Reserved.
//==============================================================================


#include "../main.h"
//#include "ramio.h"




typedef struct
{

	int x;
	int y;
	int frame;
	int dead;
	//int gfx_slot;
	SPRITE* sprite;
	int vbl;
	int dir;

}BOBA;

BOBA boba[16];


typedef struct
{

	int x;
	int y;
	int frame;
	int open;
	int contains;
	//int gfx_slot;
	SPRITE* sprite;
	int hit;
	int vbl;

}MONEYBLOCK;

MONEYBLOCK moneyblock[16];

//int RAMIO_money_gfxslot[16];

SPRITE* money_sprite[16];


typedef struct
{

	int x;
	int y;
	int frame;
	int open;
	int contains;
	//int gfx_slot;
	SPRITE* sprite;
	int hit;
	int vbl;

}BRICKBLOCK;

BRICKBLOCK brickblock[16];



int GAME_playing_ramio=0;



int RAMIO_won=0;

int RAMIO_timer=0;
int RAMIO_initial_timer=0;
int RAMIO_time_for_blocks=0;



CAPTION* RAMIO_timercaption = NULL;

//int RAMIO_guy_gfx_slot = -1;
SPRITE* RAMIO_guy_sprite;//_id = 127-12;

int RAMIO_guy_x = 5*8;
int RAMIO_guy_y = 14*8;



int RAMIO_screen_x = 0;
int RAMIO_screen_y = 0;


int RAMIO_high_score=142;
int RAMIO_score =0;
int RAMIO_got_high_score=0;


int RAMIO_tv_rolling=0;


int RAMIO_frames_since_last_pressed_A=0;
int RAMIO_frames_since_last_pressed_B=0;
int RAMIO_frames_since_last_pressed_RIGHT=0;
int RAMIO_frames_since_last_pressed_LEFT=0;
int RAMIO_frames_since_last_pressed_DOWN=0;
int RAMIO_frames_since_last_pressed_UP=0;
int RAMIO_frames_since_last_pressed_R=0;
bool RAMIO_can_press_A=0;
bool RAMIO_can_press_B=0;
bool RAMIO_can_press_RIGHT=0;
bool RAMIO_can_press_LEFT=0;
bool RAMIO_can_press_DOWN=0;
bool RAMIO_can_press_UP=0;
bool RAMIO_can_press_R=0;



int RAMIO_dead_x=0;
int RAMIO_dead_y=0;
bool RAMIO_dead=0;



bool RAMIO_credits=0;
bool RAMIO_credit_screen_init=0;
bool RAMIO_background_is_init=0;

bool RAMIO_already_updating=0;

int RAMIO_frames=0; //frame counter
int RAMIO_vbl_count=0;



int RAMIO_scrollingplayingfield_map_x=0;
int RAMIO_scrollingplayingfield_map_y=0;
int RAMIO_playing_field_map_scroll_x=0;


bool RAMIO_newframe=1;




unsigned short* RAMIO_palette =  NULL;
unsigned char* RAMIO_tileset =   NULL;

unsigned short* RAMIO_map3     =   NULL;
unsigned short* RAMIO_map2     =   NULL;
unsigned short* RAMIO_map1     =   NULL;
int* RAMIO_hitlayer     =   NULL;

unsigned short* RAMIO_metamap3     =   NULL;
unsigned short* RAMIO_metamap2     =   NULL;



int RAMIO_map_width=0;


int RAMIO_tileset_size = 0;


int RAMIO_map_x=0;
int RAMIO_offset_x=0;



//=========================================================================================================================
void RAMIO_redraw_map()
{//=========================================================================================================================



	HARDWARE_delete_AUX_bg(0);
	HARDWARE_delete_AUX_bg(1);
	HARDWARE_load_AUX_map_to_xy_xy(0,RAMIO_metamap3,RAMIO_tileset,RAMIO_palette,256,192,RAMIO_screen_x-RAMIO_offset_x,RAMIO_screen_y,TV_aspectratio,0);
	HARDWARE_load_AUX_map_to_xy_xy(1,RAMIO_metamap2,RAMIO_tileset,RAMIO_palette,256,192,RAMIO_screen_x-RAMIO_offset_x,RAMIO_screen_y,TV_aspectratio,0);


}


//=========================================================================================================================
void RAMIO_set_tile(int screen,int layer, int x, int y, int index)
{//=========================================================================================================================

	//HARDWARE_set_32x32_map_tile(screen,layer,x,y,RAMIO_map[index]);

	//RAMIO_map[(y*32)+x]=RAMIO_map[index];


}





//=========================================================================================================================
void RAMIO_shakeplayingfield()
{//=========================================================================================================================
	//called every VBL to make the background pretty
	//M_BG1SCRLX_SET(playing_field_map_x);

	static int dir=0;
	if(dir==0)
	{
		RAMIO_playing_field_map_scroll_x++;
		if(RAMIO_playing_field_map_scroll_x>3)
		{
			dir=1;
			RAMIO_playing_field_map_scroll_x--;
		}
	}
	else
	{
		RAMIO_playing_field_map_scroll_x--;
		if(RAMIO_playing_field_map_scroll_x<-3)
		{
			dir=0;
			RAMIO_playing_field_map_scroll_x++;
		}
	}


	HARDWARE_set_AUX_map_xy(2,TV_fromx+RAMIO_playing_field_map_scroll_x,TV_fromy);
}






//=========================================================================================================================
void RAMIO_query_keys()
{//=========================================================================================================================


	if((!BUTTON_RIGHT_HELD)||(RAMIO_frames_since_last_pressed_RIGHT>=0))
	{
		RAMIO_can_press_RIGHT=1;
	}
	else RAMIO_frames_since_last_pressed_RIGHT++;


	if((!BUTTON_LEFT_HELD)||(RAMIO_frames_since_last_pressed_LEFT>=0))
	{
		RAMIO_can_press_LEFT=1;
	}
	else RAMIO_frames_since_last_pressed_LEFT++;






}





//=========================================================================================================================
void RAMIO_update_score()
{//=========================================================================================================================


	//RAMIO_score+=amt;
	char char_score[15];
	sprintf(char_score,"%d",RAMIO_score);
	int score_length=strlen(char_score);


	int x=0;

	//if(RAMIO_score==0)
	for(x=0;x<3;x++)
	{
		//RAMIO_set_tile(1,2,8+x-3,2,29*32);
		//RAMIO_set_tile(1,2,8+x-3,3,29*32);
	}

	for(x=0;x<score_length;x++)
	{
		//RAMIO_set_tile(1,2,8+x-score_length,2,(char_score[x]-48)+(30*32));
		//RAMIO_set_tile(1,2,8+x-score_length,3,(char_score[x]-48)+(31*32));
	}

	char char_hiscore[15];
	sprintf(char_hiscore,"%d",RAMIO_high_score);
	int hiscore_length=strlen(char_hiscore);

	//if(RAMIO_high_score==0)
	for(x=0;x<3;x++)
	{
		//RAMIO_set_tile(1,2,29+x-3,2,29*32);
		//RAMIO_set_tile(1,2,29+x-3,3,29*32);
	}

	for(x=0;x<hiscore_length;x++)
	{
		//RAMIO_set_tile(1,2,29+x-hiscore_length,2,(char_hiscore[x]-48)+(30*32));
		//RAMIO_set_tile(1,2,29+x-hiscore_length,3,(char_hiscore[x]-48)+(31*32));
	}

}

//=========================================================================================================================
int check_hit_blocks(int x,int y, int frombelow)
{//=========================================================================================================================

	int hit=0;

	int q=0;
	for(q=0;q<16;q++)
	{
		if(moneyblock[q].sprite!=NULL)
		if(x>=moneyblock[q].x&&x<moneyblock[q].x+16)
		if(y>=moneyblock[q].y&&y<moneyblock[q].y+16)
		{
			hit=1;
			if(frombelow&&moneyblock[q].hit==0)moneyblock[q].hit=1;
		}
	}

	for(q=0;q<16;q++)
	{
		if(brickblock[q].sprite!=NULL)
		if(x>=brickblock[q].x&&x<brickblock[q].x+16)
		if(y>=brickblock[q].y&&y<brickblock[q].y+16)
		{
			hit=1;
			if(frombelow&&brickblock[q].hit==0)brickblock[q].hit=1;
		}
	}

	return hit;
}


//=========================================================================================================================
void init_brickblocks()
{//=========================================================================================================================




	int q=0;
	for(q=0;q<16;q++)
	{

		//brickblock[q].gfx_slot = -1;
		brickblock[q].sprite = NULL;

		brickblock[q].x=0;
		brickblock[q].y=0;
		brickblock[q].frame=0;
		brickblock[q].open=0;
		brickblock[q].contains=0;
		brickblock[q].vbl=0;
		brickblock[q].hit=0;

	}



}
//=========================================================================================================================
void make_brickblock(int x,int y)
{//=========================================================================================================================
	//find open brickblock
	int q=0;

	int b=0;
	for(b=0;b<16;b++)
	if(brickblock[b].sprite==NULL)
	{
		q=b;
		b=16;
		break;
	}


	//make brickblock

	//create sprite
	//brickblock[q].gfx_slot = HARDWARE_create_sprite_gfxslot(1,RAMIO_brickblock_gfx_GFX,0,16,16,1,0);
	//brickblock[q].PLAYER_id = 125-32-q;

	//HARDWARE_create_sprite(1,brickblock[q].PLAYER_id,brickblock[q].gfx_slot,16,16,1,0,0,0,0,0,5,0,RAMIO_screen_x+x,RAMIO_screen_y+y);

	brickblock[q].sprite = HARDWARE_create_sprite(RAMIO_brickblock_gfx_GFX,0,5,1.0f,RAMIO_screen_x+x,RAMIO_screen_y+y,255);

		brickblock[q].x=x;
		brickblock[q].y=y;
		brickblock[q].frame=0;
		brickblock[q].open=0;
		brickblock[q].contains=0;
		brickblock[q].vbl=0;
		brickblock[q].hit=0;

}

//=========================================================================================================================
void run_brickblocks()
{//=========================================================================================================================


	int q=0;
	for(q=0;q<16;q++)
	{

		if(brickblock[q].sprite!=NULL)
		{
			brickblock[q].vbl++;




			if(brickblock[q].hit!=0)
			{

				if(brickblock[q].hit==1)
				{
					//play sound
					HARDWARE_play_sound("ramiobrickthud",64,44100,0);

					//TODO:if small ramio, just bounce
					//else destroy

				}

				if(brickblock[q].hit<11)
				{

					if(brickblock[q].hit<=5)brickblock[q].y--; //1 2 3 4 5
					if(brickblock[q].hit>5)brickblock[q].y++; //6 7 8 9 10

					brickblock[q].hit++;
				}
				else
				{
					brickblock[q].hit=0;

				}

			}



			if(brickblock[q].x<1||brickblock[q].y>22*8||brickblock[q].x>32*8)
			{

				HARDWARE_delete_sprite(brickblock[q].sprite);
				//HARDWARE_delete_sprite_gfxslot(1,brickblock[q].gfx_slot);

				//brickblock[q].gfx_slot = -1;
				brickblock[q].sprite = NULL;

				brickblock[q].x=0;
				brickblock[q].y=0;
				brickblock[q].frame=0;
				brickblock[q].open=0;
				brickblock[q].contains=0;
				brickblock[q].vbl=0;
				brickblock[q].hit=0;
			}

		}
	}
}


//=========================================================================================================================
void set_brickblocks_xy()
{//=========================================================================================================================


	int q=0;
	for(q=0;q<16;q++)
	{
		if(brickblock[q].sprite!=NULL)
		{
			//set x y
			HARDWARE_set_sprite_xy(brickblock[q].sprite,RAMIO_screen_x+brickblock[q].x,RAMIO_screen_y+brickblock[q].y);
		}
	}

}

//=========================================================================================================================
void delete_brickblocks()
{//=========================================================================================================================

	int q=0;
	for(q=0;q<16;q++)
	{
		if(brickblock[q].sprite!=NULL)
		{
			HARDWARE_delete_sprite(brickblock[q].sprite);
			//HARDWARE_delete_sprite_gfxslot(1,brickblock[q].gfx_slot);


			//brickblock[q].gfx_slot = -1;
			brickblock[q].sprite = NULL;

			brickblock[q].x=0;
			brickblock[q].y=0;
			brickblock[q].frame=0;
			brickblock[q].open=0;
			brickblock[q].contains=0;
			brickblock[q].vbl=0;
			brickblock[q].hit=0;
		}
	}
}


//=========================================================================================================================
void init_moneyblocks()
{//=========================================================================================================================



	int q=0;
	for(q=0;q<16;q++)
	{

		money_sprite[q] = NULL;
		//RAMIO_money_gfxslot[q] = -1;

		//moneyblock[q].gfx_slot = -1;
		moneyblock[q].sprite = NULL;

		moneyblock[q].x=0;
		moneyblock[q].y=0;
		moneyblock[q].frame=0;
		moneyblock[q].open=0;
		moneyblock[q].contains=0;
		moneyblock[q].vbl=0;
		moneyblock[q].hit=0;

	}



}
//=========================================================================================================================
void make_moneyblock(int x, int y)
{//=========================================================================================================================
	//find open moneyblock
	int q=0;

	int b=0;
	for(b=0;b<16;b++)
	if(moneyblock[b].sprite==NULL)
	{
		q=b;
		b=16;
		break;
	}


	//make moneyblock

	//create sprite
	//moneyblock[q].gfx_slot = HARDWARE_create_sprite_gfxslot(1,RAMIO_moneyblock_gfx_GFX,0,16,16,1,0);
	//moneyblock[q].PLAYER_id = 125-16-q;

	//HARDWARE_create_sprite(1,moneyblock[q].PLAYER_id,moneyblock[q].gfx_slot,16,16,1,0,0,0,0,0,5,0,RAMIO_screen_x+x,RAMIO_screen_y+y);
	moneyblock[q].sprite = HARDWARE_create_sprite(RAMIO_moneyblock_gfx_GFX,0,5,1.0f,RAMIO_screen_x+x,RAMIO_screen_y+y,255);


		moneyblock[q].x=x;
		moneyblock[q].y=y;
		moneyblock[q].frame=0;
		moneyblock[q].open=0;
		moneyblock[q].contains=0;
		moneyblock[q].vbl=0;
		moneyblock[q].hit=0;

}

//=========================================================================================================================
void run_moneyblocks()
{//=========================================================================================================================


	int q=0;
	for(q=0;q<16;q++)
	{

		if(moneyblock[q].sprite!=NULL)
		{
			moneyblock[q].vbl++;

			if(moneyblock[q].open==0)
			{


				//animate
				if(moneyblock[q].vbl>5)
				{
					moneyblock[q].vbl=0;
					//set frame
					moneyblock[q].frame++;
					if(moneyblock[q].frame>6)
					moneyblock[q].frame=0;

					//update grx
					HARDWARE_update_sprite_texture(moneyblock[q].sprite,(16*16)*moneyblock[q].frame);
				}


			}

			if(moneyblock[q].hit!=0)
			{

				if(moneyblock[q].hit==1)
				{
					//play sound
					if(moneyblock[q].open==1)HARDWARE_play_sound("ramiobrickthud",64,44100,0);
					else HARDWARE_play_sound("ramiomoneybrick",64,44100,0);


					if(moneyblock[q].open==0)
					{

						int r=rand()%5;
						if(r==0)CAPTION_make_caption(&yuu_ramio_caption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,3,"Got more cash!",FONT_NORMAL_ID,WHITE,BLACK,1,1);
						if(r==1)CAPTION_make_caption(&yuu_ramio_caption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,3,"Alright!",FONT_NORMAL_ID,WHITE,BLACK,1,1);
						if(r==2)CAPTION_make_caption(&yuu_ramio_caption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,3,"Bling!",FONT_NORMAL_ID,WHITE,BLACK,1,1);


						RAMIO_timer+=RAMIO_time_for_blocks;
						//TODO:make coin or object
						//RAMIO_money_gfxslot[q] = HARDWARE_create_sprite_gfxslot(1,RAMIO_money_gfx_GFX,0,16,16,1,0);
						//money_sprite_id[q] = 125-16*3-q;

						//HARDWARE_create_sprite(1,money_sprite_id[q],RAMIO_money_gfxslot[q],16,16,1,0,0,0,0,0,5,0,RAMIO_screen_x+moneyblock[q].x,RAMIO_screen_y+moneyblock[q].y-16);
						money_sprite[q] = HARDWARE_create_sprite(RAMIO_money_gfx_GFX,0,5,1.0f,RAMIO_screen_x+moneyblock[q].x,RAMIO_screen_y+moneyblock[q].y-16,255);
					}


				}

				if(moneyblock[q].hit<11)
				{
					if(moneyblock[q].open==0)
					if(moneyblock[q].hit<9)
					HARDWARE_update_sprite_texture(money_sprite[q],(16*16)*moneyblock[q].hit);

					if(moneyblock[q].hit<=5)moneyblock[q].y--; //1 2 3 4 5
					if(moneyblock[q].hit>5)moneyblock[q].y++; //6 7 8 9 10

					moneyblock[q].hit++;
				}
				else
				{
					moneyblock[q].hit=0;


					if(moneyblock[q].open==0)
					{
						HARDWARE_delete_sprite(money_sprite[q]);
						//HARDWARE_delete_sprite_gfxslot(1,RAMIO_money_gfxslot[q]);
						money_sprite[q]=NULL;
						//RAMIO_money_gfxslot[q]=-1;
					}

					moneyblock[q].open=1;

				}

			}

			if(moneyblock[q].open==1)
			{
				if(moneyblock[q].frame!=7)
				{
					//update gfx to 7
					moneyblock[q].frame=7;
					HARDWARE_update_sprite_texture(moneyblock[q].sprite,(16*16)*moneyblock[q].frame);

				}
			}




			if(moneyblock[q].x<1||moneyblock[q].y>22*8||moneyblock[q].x>32*8)
			{

				if(money_sprite[q]!=NULL)
				{
					HARDWARE_delete_sprite(money_sprite[q]);
					//HARDWARE_delete_sprite_gfxslot(1,RAMIO_money_gfxslot[q]);
					money_sprite[q]=NULL;
					//RAMIO_money_gfxslot[q]=-1;
				}

				HARDWARE_delete_sprite(moneyblock[q].sprite);
				//HARDWARE_delete_sprite_gfxslot(1,moneyblock[q].gfx_slot);

				//moneyblock[q].gfx_slot = -1;
				moneyblock[q].sprite = NULL;

				moneyblock[q].x=0;
				moneyblock[q].y=0;
				moneyblock[q].frame=0;
				moneyblock[q].open=0;
				moneyblock[q].contains=0;
				moneyblock[q].vbl=0;
				moneyblock[q].hit=0;
			}

		}
	}
}


//=========================================================================================================================
void set_moneyblocks_xy()
{//=========================================================================================================================


	int q=0;
	for(q=0;q<16;q++)
	{
		if(moneyblock[q].sprite!=NULL)
		{
			//set x y
			HARDWARE_set_sprite_xy(moneyblock[q].sprite,RAMIO_screen_x+moneyblock[q].x,RAMIO_screen_y+moneyblock[q].y);
		}
		if(money_sprite[q]!=NULL)
		{
			//set x y
			HARDWARE_set_sprite_xy(money_sprite[q],RAMIO_screen_x+moneyblock[q].x,RAMIO_screen_y+moneyblock[q].y-16);
		}

	}

}

//=========================================================================================================================
void delete_moneyblocks()
{//=========================================================================================================================

	int q=0;
	for(q=0;q<16;q++)
	{
		if(moneyblock[q].sprite!=NULL)
		{
			HARDWARE_delete_sprite(moneyblock[q].sprite);
			//HARDWARE_delete_sprite_gfxslot(1,moneyblock[q].gfx_slot);


			//moneyblock[q].gfx_slot = -1;
			moneyblock[q].sprite = NULL;

			moneyblock[q].x=0;
			moneyblock[q].y=0;
			moneyblock[q].frame=0;
			moneyblock[q].open=0;
			moneyblock[q].contains=0;
			moneyblock[q].vbl=0;
			moneyblock[q].hit=0;
		}

		if(money_sprite[q]!=NULL)
		{
			HARDWARE_delete_sprite(money_sprite[q]);
			//HARDWARE_delete_sprite_gfxslot(1,RAMIO_money_gfxslot[q]);
			money_sprite[q]=NULL;
			//RAMIO_money_gfxslot[q]=-1;
		}


	}
}




//=========================================================================================================================
void init_bobas()
{//=========================================================================================================================


	int q=0;
	for(q=0;q<16;q++)
	{

		//boba[q].gfx_slot = -1;
		boba[q].sprite = NULL;

		boba[q].x=0;
		boba[q].y=0;
		boba[q].frame=0;
		boba[q].dead=0;
		boba[q].vbl=0;
		boba[q].dir=LEFT;

	}



}
//=========================================================================================================================
void make_boba(int x,int y)
{//=========================================================================================================================
	//find open boba
	int q=0;

	int b=0;
	for(b=0;b<16;b++)
	if(boba[b].sprite==NULL)
	{
		q=b;
		b=16;
		break;
	}


	//make boba

	//create sprite
	//boba[q].gfx_slot = HARDWARE_create_sprite_gfxslot(1,RAMIO_boba_gfx_GFX,0,16,16,1,0);
	//boba[q].PLAYER_id = 125-q;

	//HARDWARE_create_sprite(1,boba[q].PLAYER_id,boba[q].gfx_slot,16,16,1,0,0,0,0,0,5,0,RAMIO_screen_x+x,RAMIO_screen_y+y);
	boba[q].sprite = HARDWARE_create_sprite(RAMIO_boba_gfx_GFX,0,5,1.0f,RAMIO_screen_x+x,RAMIO_screen_y+y,255);


	boba[q].x=x;
	boba[q].y=y;
	boba[q].frame=0;
	boba[q].dead=0;
	boba[q].vbl=0;

}

//=========================================================================================================================
void set_bobas_xy()
{//=========================================================================================================================


	int q=0;
	for(q=0;q<16;q++)
	{
		if(boba[q].sprite!=NULL)
		{
			//set x y
			HARDWARE_set_sprite_xy(boba[q].sprite,RAMIO_screen_x+boba[q].x,RAMIO_screen_y+boba[q].y);
		}
	}

}



//=========================================================================================================================
void run_bobas()
{//=========================================================================================================================


	int q=0;
	for(q=0;q<16;q++)
	{

		if(boba[q].sprite!=NULL)
		{
			boba[q].vbl++;

			if(boba[q].dead==0)
			{


				int f=0;
				for(f=0;f<3;f++)
				{
					//check down
					if(
						(RAMIO_hitlayer[(((boba[q].y+16)/8)*RAMIO_map_width)+((boba[q].x+RAMIO_map_x+RAMIO_offset_x)/8)]==0)
						&&
						(RAMIO_hitlayer[(((boba[q].y+16)/8)*RAMIO_map_width)+(((boba[q].x+RAMIO_map_x+RAMIO_offset_x)+16-1)/8)]==0)
						&&
						(check_hit_blocks(boba[q].x,boba[q].y+16,0)+check_hit_blocks(boba[q].x+16-1,boba[q].y+16,0)==0)
					)
					boba[q].y++;
				}



				//animate
				if(boba[q].vbl>5)
				{
					boba[q].vbl=0;
					//set frame
					boba[q].frame++;
					if(boba[q].frame>4)
					boba[q].frame=0;

					//update grx
					HARDWARE_update_sprite_texture(boba[q].sprite,(16*16)*boba[q].frame);
				}


				if(boba[q].dir==LEFT&&boba[q].vbl%3==0)
				{
					//check hit
					if(
						(RAMIO_hitlayer[(((boba[q].y)/8)*RAMIO_map_width)+(((boba[q].x+RAMIO_map_x+RAMIO_offset_x)-1)/8)]==0)
						&&
						(RAMIO_hitlayer[(((boba[q].y+16-1)/8)*RAMIO_map_width)+(((boba[q].x+RAMIO_map_x+RAMIO_offset_x)-1)/8)]==0)
						&&
						(check_hit_blocks(boba[q].x-1,boba[q].y,0)+check_hit_blocks(boba[q].x-1,boba[q].y+16-1,0)==0)

					)
					{
						//move left
						boba[q].x--;
					}
					else
					boba[q].dir=RIGHT;
				}


				if(boba[q].dir==RIGHT&&boba[q].vbl%3==0)
				{
					//heck hit
					if(
						(RAMIO_hitlayer[(((boba[q].y)/8)*RAMIO_map_width)+(((boba[q].x+RAMIO_map_x+RAMIO_offset_x)+16)/8)]==0)
						&&
						(RAMIO_hitlayer[(((boba[q].y+16-1)/8)*RAMIO_map_width)+(((boba[q].x+RAMIO_map_x+RAMIO_offset_x)+16)/8)]==0)
						&&
						(check_hit_blocks(boba[q].x+16,boba[q].y,0)+check_hit_blocks(boba[q].x+16,boba[q].y+16-1,0)==0)
					)
					{
						//move right
						boba[q].x++;

					}
					else
					boba[q].dir=LEFT;
				}

			}

			if(boba[q].x<1||boba[q].y>=22*8||boba[q].x>32*8)
			{
				boba[q].dead=1;
				boba[q].frame=5;
				boba[q].vbl=61;
			}

			if(boba[q].dead==1)
			{

				if(boba[q].frame!=5)
				{
					//update gfx to 5
					boba[q].frame=5;
					HARDWARE_update_sprite_texture(boba[q].sprite,(16*16)*boba[q].frame);

				}

				if(boba[q].vbl>60)
				{

					HARDWARE_delete_sprite(boba[q].sprite);
					//HARDWARE_delete_sprite_gfxslot(1,boba[q].gfx_slot);


					//boba[q].gfx_slot = -1;
					boba[q].sprite = NULL;

					boba[q].x=0;
					boba[q].y=0;
					boba[q].frame=0;
					boba[q].dead=0;
					boba[q].vbl=0;
				}
			}



		}
	}

}


//=========================================================================================================================
void delete_bobas()
{//=========================================================================================================================

	int q=0;
	for(q=0;q<16;q++)
	{
		if(boba[q].sprite!=NULL)
		{
			HARDWARE_delete_sprite(boba[q].sprite);
			//HARDWARE_delete_sprite_gfxslot(1,boba[q].gfx_slot);


			//boba[q].gfx_slot = -1;
			boba[q].sprite = NULL;

			boba[q].x=0;
			boba[q].y=0;
			boba[q].frame=0;
			boba[q].dead=0;
			boba[q].vbl=0;
		}
	}
}







//=========================================================================================================================
	void RAMIO_init_game()
{//=========================================================================================================================



if(easymode==1)
{

	RAMIO_timer=0;
	RAMIO_initial_timer=1000;
	RAMIO_time_for_blocks=200;

}
else
{

	RAMIO_timer=0;
	RAMIO_initial_timer=800;
	RAMIO_time_for_blocks=140;

}


	CAPTION_make_caption(&yuu_ramio_caption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,3,"Alright! It works!",FONT_NORMAL_ID,WHITE,BLACK,1,1);

	init_bobas();
	init_moneyblocks();
	init_brickblocks();

	RAMIO_screen_x = TV_fromx+8;
	RAMIO_screen_y = TV_fromy+19;

	if(RAMIO_background_is_init==0)
	{




	RAMIO_palette =         (short unsigned int*)HARDWARE_load_file(HARDWARE_map_palette_filename);//HARDWARE_load_file("/minigame/ramio/ramiolevel1_Pal.bin");

	RAMIO_tileset =         (unsigned char*)HARDWARE_load_file("/minigame/ramio/ramiolevel1_Tiles.bin");
	RAMIO_map3     =         (short unsigned int*)HARDWARE_load_file("/minigame/ramio/ramiolevel1_Map_3.bin");
	RAMIO_map2     =         (short unsigned int*)HARDWARE_load_file("/minigame/ramio/ramiolevel1_Map_2.bin");
	RAMIO_map1     =        (short unsigned int*)HARDWARE_load_file("/minigame/ramio/ramiolevel1_Map_1.bin");
	RAMIO_hitlayer     =         (int*)HARDWARE_load_file("/minigame/ramio/ramiolevel1_Map_Hit.bin");
	//RAMIO_original_map =    HARDWARE_load_file("/minigame/ping/ping_v00_Map.bin");
	RAMIO_tileset_size =    HARDWARE_get_file_size("/minigame/ramio/ramiolevel1_Tiles.bin");

	//int RAMIO_map_size = HARDWARE_get_file_size("/minigame/ramio/ramiolevel1_Map_3.bin");

	//we know the map is 24 tall. so length is size/chunk/24.
	RAMIO_map_width = 500;//RAMIO_map_size/2/24;

		RAMIO_metamap3 = (short unsigned int*)calloc(32 * 24, sizeof(int));
		RAMIO_metamap2 = (short unsigned int*)calloc(32 * 24, sizeof(int));

		int y=0;
		int x=0;
		for(y=0;y<22;y++)
		for(x=0;x<30;x++)
		{
			RAMIO_metamap3[(32*y)+x] = RAMIO_map3[(RAMIO_map_width*y)+x];
			RAMIO_metamap2[(32*y)+x] = RAMIO_map2[(RAMIO_map_width*y)+x];
		}


		HARDWARE_load_AUX_map_to_xy_xy(0,RAMIO_metamap3,RAMIO_tileset,RAMIO_palette,256,192,RAMIO_screen_x+RAMIO_playing_field_map_scroll_x,RAMIO_screen_y,TV_aspectratio,0);
		HARDWARE_load_AUX_map_to_xy_xy(1,RAMIO_metamap2,RAMIO_tileset,RAMIO_palette,256,192,RAMIO_screen_x+RAMIO_playing_field_map_scroll_x,RAMIO_screen_y,TV_aspectratio,0);

		RAMIO_background_is_init=1;



		//we're going to use the metatile functions here.
		//load the full level map, grab just the needed tiles, make the onscreen map, and draw it. max maps onscreen should be 2 or 3.

		//probably i can fit the whole level data into memory at once no problem, so i dont need to load it from the file each time.




		//load sprite


		//create sprite
		//RAMIO_guy_gfx_slot = HARDWARE_create_sprite_gfxslot(1,RAMIO_guy_gfx_GFX,0,16,32,1,0);
		//HARDWARE_create_sprite(1,RAMIO_guy_sprite_id,RAMIO_guy_gfx_slot,16,32,1,0,0,0,0,0,5,0,RAMIO_screen_x+RAMIO_guy_x,RAMIO_screen_y+RAMIO_guy_y);

		RAMIO_guy_sprite = HARDWARE_create_sprite(RAMIO_guy_gfx_GFX,0,5,1.0f,RAMIO_screen_x+RAMIO_guy_x,RAMIO_screen_y+RAMIO_guy_y,255);


		//CAPTION_make_caption(&yuu_ping_caption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,3,"Wow. This is horrible.",FONT_NORMAL_ID,WHITE,BLACK,1,1);


	}


	RAMIO_frames=0;


	RAMIO_frames_since_last_pressed_A=0;
	RAMIO_frames_since_last_pressed_B=0;
	RAMIO_frames_since_last_pressed_RIGHT=0;
	RAMIO_frames_since_last_pressed_LEFT=0;
	RAMIO_frames_since_last_pressed_DOWN=0;
	RAMIO_frames_since_last_pressed_R=0;
	RAMIO_can_press_A=1;
	RAMIO_can_press_B=1;
	RAMIO_can_press_RIGHT=1;
	RAMIO_can_press_LEFT=1;
	RAMIO_can_press_DOWN=1;
	RAMIO_can_press_R=1;





RAMIO_timer=RAMIO_initial_timer;



	//make_boba(100,16*8);

}


//=========================================================================================================================
void RAMIO_winning()
{//=========================================================================================================================

	static int win=0;

	if(win==0)
	{

		CAPTION_make_caption(&yuu_ramio_caption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,3,"Yeah! I did it!",FONT_NORMAL_ID,WHITE,BLACK,1,1);

		HARDWARE_stop_music();

		HARDWARE_play_sound("ramiowon",64,44100,0);
		win=1;
		RAMIO_vbl_count=0;
	}
	else
	if(win==1)
	{


		if(RAMIO_vbl_count>150)
		{
			win=2;
		}


	}

	else
	if(win==2)
	{
		win=3;

		//delete sprites
		delete_bobas();
		delete_moneyblocks();
		delete_brickblocks();


		CAPTION_delete_caption(RAMIO_timercaption);


		//delete sprite

		HARDWARE_delete_sprite(RAMIO_guy_sprite);
		//HARDWARE_delete_sprite_gfxslot(1,RAMIO_guy_gfx_slot);



		//TODO:glitch, end game


		HARDWARE_delete_AUX_bg(0);
		HARDWARE_delete_AUX_bg(1);

		HARDWARE_stop_music();

		HARDWARE_unload_file((void**)&RAMIO_palette);
		HARDWARE_unload_file((void**)&RAMIO_tileset);

		HARDWARE_unload_file((void**)&RAMIO_map3);
		HARDWARE_unload_file((void**)&RAMIO_map2);
		HARDWARE_unload_file((void**)&RAMIO_map1);
		HARDWARE_unload_file((void**)&RAMIO_hitlayer);

		free(RAMIO_metamap3);
		free(RAMIO_metamap2);



		RAMIO_background_is_init=0;
		RAMIO_credit_screen_init=1;

		GAME_playing_ramio=0;

		unload_tv_fullscreen();
	}

}



//=========================================================================================================================
void RAMIO_dying()
{//=========================================================================================================================

	static int die=0;

	if(die==0)
	{

		int r=rand()%5;
		if(r==0)CAPTION_make_caption(&yuu_ramio_caption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,3,"Let's try this again.",FONT_NORMAL_ID,WHITE,BLACK,1,1);
		if(r==1)CAPTION_make_caption(&yuu_ramio_caption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,3,"I was so close!",FONT_NORMAL_ID,WHITE,BLACK,1,1);
		if(r==2)CAPTION_make_caption(&yuu_ramio_caption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,3,"Grrr. That was stupid.",FONT_NORMAL_ID,WHITE,BLACK,1,1);
		if(r==3)CAPTION_make_caption(&yuu_ramio_caption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,3,"One more try.",FONT_NORMAL_ID,WHITE,BLACK,1,1);
		if(r==4)CAPTION_make_caption(&yuu_ramio_caption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,3,"Nooooooooo!",FONT_NORMAL_ID,WHITE,BLACK,1,1);

		HARDWARE_stop_music();

		HARDWARE_play_sound("ramiodeath",64,44100,0);
		die=1;
		RAMIO_vbl_count=0;

		HARDWARE_update_sprite_texture(RAMIO_guy_sprite,(16*32)*11);
	}
	else
	if(die==1)
	{

		if(RAMIO_vbl_count>30)
		{
			HARDWARE_update_sprite_texture(RAMIO_guy_sprite,(16*32)*12);
			die=2;
			RAMIO_vbl_count=0;
		}
	}
	else
	if(die==2)
	{
		if(RAMIO_vbl_count>30)
		{
			HARDWARE_update_sprite_texture(RAMIO_guy_sprite,(16*32)*13);
			die=3;
			RAMIO_vbl_count=0;
		}
	}
	else
	if(die==3)
	{
		if(RAMIO_vbl_count>60)
		{
			die=4;
		}


	}
	else
	if(die==4)
	{

		HARDWARE_play_music("ramio",64);

		die=0;

		//do death animation


		//caption probably



		//delete sprites
		delete_bobas();
		delete_moneyblocks();
		delete_brickblocks();


		//init all variables


		RAMIO_guy_x = 5*8;
		RAMIO_guy_y = 14*8;


		//reset graphics

		RAMIO_offset_x=0;
		RAMIO_map_x=0;

			int y=0;
			int x=0;
			for(y=0;y<22;y++)
			for(x=0;x<30;x++)
			{


				RAMIO_metamap3[(32*y)+x] = RAMIO_map3[(RAMIO_map_width*y)+x+(RAMIO_map_x/8)];
				RAMIO_metamap2[(32*y)+x] = RAMIO_map2[(RAMIO_map_width*y)+x+(RAMIO_map_x/8)];

			}

			RAMIO_redraw_map();

			HARDWARE_set_AUX_map_xy(0,RAMIO_screen_x-RAMIO_offset_x,RAMIO_screen_y);
			HARDWARE_set_AUX_map_xy(1,RAMIO_screen_x-RAMIO_offset_x,RAMIO_screen_y);

		//start over


		RAMIO_dead=0;

		HARDWARE_play_music("ramio",64);

		RAMIO_timer=RAMIO_initial_timer;

	}

}


//=========================================================================================================================
void RAMIO_main()
{//=========================================================================================================================


	if(RAMIO_credits==0)
	{

			if(RAMIO_background_is_init==0)RAMIO_init_game();

			if(RAMIO_newframe==1)
			{
				RAMIO_newframe=0;




				if(RAMIO_vbl_count%3==0)
				{
					//make the tv scanlines pulse
					static int fade_in_out=0;

					if(fade_in_out==0)
					{
						fade_in_out=1;
					}
					else
					{
						fade_in_out=0;
					}

				}


				if(RAMIO_won==1)
				{




					RAMIO_winning();


				}
				else
				if(RAMIO_dead==1)
				{

					RAMIO_dying();




				}
				else
				{

					//RAMIO_query_keys();


					int jump_speed=6;
					int jump_decel=8;
					int fall_speed=3;
					int fall_accel=8;

					int max_walk_speed=2;
					int walk_accel=3;

					int walking_right=0;
					int walking_left=0;

					static int right_walk_speed=0;
					static int left_walk_speed=0;

					static int right_walk_cycles=0;
					static int left_walk_cycles=0;

					static int RAMIO_jumping=0;
					static int pixels_jumped=0;
					static int can_jump=0;
					static int jump_decel_count=0;


					int running=0;


					int PLAYER_height=32;
					int PLAYER_top=16;


					if(BUTTON_B_HELD)
					{
						running=1;
						max_walk_speed=3;
						jump_decel=12;
						fall_accel=4;
					}

					int c=0;

					//check keys
					if(BUTTON_RIGHT_HELD)
					{

						RAMIO_can_press_RIGHT=0;
						RAMIO_frames_since_last_pressed_RIGHT=0;

						right_walk_cycles++;
						if(right_walk_cycles>walk_accel+right_walk_speed)
						{
							right_walk_speed++;
							if(right_walk_speed>max_walk_speed)right_walk_speed=max_walk_speed;
							right_walk_cycles=0;

							//left_walk_speed--;
							//if(left_walk_speed<0)left_walk_speed=0;

						}

					}
					else
					{
						right_walk_cycles++;
						if(right_walk_cycles>walk_accel+right_walk_speed)
						{
							right_walk_speed--;
							if(right_walk_speed<0)right_walk_speed=0;
							right_walk_cycles=0;
						}

					}

					for(c=0;c<right_walk_speed;c++)
					{
						if(
							(RAMIO_hitlayer[(((RAMIO_guy_y+PLAYER_top)/8)*RAMIO_map_width)+(((RAMIO_guy_x+RAMIO_map_x+RAMIO_offset_x)+16-2)/8)]==0)
							&&
							(RAMIO_hitlayer[(((RAMIO_guy_y+PLAYER_height-1)/8)*RAMIO_map_width)+(((RAMIO_guy_x+RAMIO_map_x+RAMIO_offset_x)+16-2)/8)]==0)
							&&
							(check_hit_blocks(RAMIO_guy_x+16-2,RAMIO_guy_y+PLAYER_top,0)+check_hit_blocks(RAMIO_guy_x+16-2,RAMIO_guy_y+PLAYER_height-1,0)==0)

						)
						{
							RAMIO_guy_x++;
							walking_right=1;

						}
						else
						{

							right_walk_speed=1;
						}
					}




					if(BUTTON_LEFT_HELD)
					{

						RAMIO_can_press_LEFT=0;
						RAMIO_frames_since_last_pressed_LEFT=0;

						left_walk_cycles++;
						if(left_walk_cycles>walk_accel+left_walk_speed)
						{
							left_walk_speed++;
							if(left_walk_speed>max_walk_speed)left_walk_speed=max_walk_speed;
							left_walk_cycles=0;

							//right_walk_speed--;
							//if(right_walk_speed<0)right_walk_speed=0;

						}

					}
					else
					{

						left_walk_cycles++;
						if(left_walk_cycles>walk_accel+left_walk_speed)
						{
							left_walk_speed--;
							if(left_walk_speed<0)left_walk_speed=0;
							left_walk_cycles=0;
						}

					}

					for(c=0;c<left_walk_speed;c++)
					{
						if(
							RAMIO_guy_x>16
							&&
							(RAMIO_hitlayer[(((RAMIO_guy_y+PLAYER_top)/8)*RAMIO_map_width)+(((RAMIO_guy_x+RAMIO_map_x+RAMIO_offset_x)-1+2)/8)]==0)
							&&
							(RAMIO_hitlayer[(((RAMIO_guy_y+PLAYER_height-1)/8)*RAMIO_map_width)+(((RAMIO_guy_x+RAMIO_map_x+RAMIO_offset_x)-1+2)/8)]==0)
							&&
							(check_hit_blocks(RAMIO_guy_x-1+2,RAMIO_guy_y+PLAYER_top,0)+check_hit_blocks(RAMIO_guy_x-1+2,RAMIO_guy_y+PLAYER_height-1,0)==0)

							)
						{
							RAMIO_guy_x--;
							walking_left=1;
						}
						else
						{
							left_walk_speed=1;

						}
					}




					static int was_jumping=0;

					for(c=0;c<jump_speed;c++)
					{


						if(RAMIO_jumping==1)
						{
							jump_decel_count++;
						}
						else
						{
							jump_decel_count=0;
						}

						if(BUTTON_A_HELD)
						{

							if(can_jump==1)
							{
								RAMIO_jumping=1;
								can_jump=0;
								HARDWARE_play_sound("ramiojump",64,44100,0);
							}

							if(RAMIO_jumping==1)
							{

								int max_jump = 3;
								if(right_walk_speed==3||left_walk_speed==3)max_jump=4;

								if(pixels_jumped<16*max_jump+1)
								{

									if(
										(RAMIO_hitlayer[(((RAMIO_guy_y+PLAYER_top)/8)*RAMIO_map_width)+(((RAMIO_guy_x+RAMIO_map_x+RAMIO_offset_x)+2)/8)]==0)
										&&
										(RAMIO_hitlayer[(((RAMIO_guy_y+PLAYER_top)/8)*RAMIO_map_width)+(((RAMIO_guy_x+RAMIO_map_x+RAMIO_offset_x)+16-3)/8)]==0)
										&&
										(check_hit_blocks(RAMIO_guy_x+2,RAMIO_guy_y+PLAYER_top,1)+check_hit_blocks(RAMIO_guy_x+16-3,RAMIO_guy_y+PLAYER_top,1)==0)

										)
										{
											if(jump_decel_count>(pixels_jumped/jump_decel))
											{
												jump_decel_count=0;
												RAMIO_guy_y--;
												pixels_jumped++;
											}
										}
										else
										{

											RAMIO_jumping=0;
											pixels_jumped=0;
											can_jump=0;
											was_jumping=1;
										}
								}
								else
								{
									RAMIO_jumping=0;
									pixels_jumped=0;
									can_jump=0;
									was_jumping=1;
								}

							}
						}
						else
						{
							if(RAMIO_jumping==1)
							{
								if(pixels_jumped<(16*2)+1)
								{
									if(
										(RAMIO_hitlayer[(((RAMIO_guy_y+PLAYER_top)/8)*RAMIO_map_width)+(((RAMIO_guy_x+RAMIO_map_x+RAMIO_offset_x)+2)/8)]==0)
										&&
										(RAMIO_hitlayer[(((RAMIO_guy_y+PLAYER_top)/8)*RAMIO_map_width)+(((RAMIO_guy_x+RAMIO_map_x+RAMIO_offset_x)+16-3)/8)]==0)
										&&
										(check_hit_blocks(RAMIO_guy_x+2,RAMIO_guy_y+PLAYER_top,1)+check_hit_blocks(RAMIO_guy_x+16-3,RAMIO_guy_y+PLAYER_top,1)==0)

										)
										{

											if(jump_decel_count>(pixels_jumped/jump_decel))
											{
												jump_decel_count=0;
												RAMIO_guy_y--;
												pixels_jumped++;
											}

										}
										else
										{
											RAMIO_jumping=0;
											pixels_jumped=0;
											can_jump=0;
											was_jumping=1;
										}
								}
								else
								{
									RAMIO_jumping=0;
									pixels_jumped=0;
									can_jump=0;
									was_jumping=1;
								}
							}

						}

					}

					static int pixels_fell=0;
					static int fall_accel_count=0;

					for(c=0;c<fall_speed;c++)
					{

						//gravity
						if(RAMIO_jumping==0)
						{
							if(
								(RAMIO_hitlayer[(((RAMIO_guy_y+PLAYER_height)/8)*RAMIO_map_width)+(((RAMIO_guy_x+RAMIO_map_x+RAMIO_offset_x)+2)/8)]==0)
								&&
								(RAMIO_hitlayer[(((RAMIO_guy_y+PLAYER_height)/8)*RAMIO_map_width)+(((RAMIO_guy_x+RAMIO_map_x+RAMIO_offset_x)+16-3)/8)]==0)
								&&
								(check_hit_blocks(RAMIO_guy_x+2,RAMIO_guy_y+PLAYER_height,0)+check_hit_blocks(RAMIO_guy_x+16-3,RAMIO_guy_y+PLAYER_height,0)==0)

								)
								{

									fall_accel_count++;
									can_jump=0;


									if(fall_accel_count>(fall_accel/(pixels_fell+1)))
									{
										RAMIO_guy_y++;
										pixels_fell++;
										fall_accel_count=0;

										//check bobos
										int q=0;
										for(q=0;q<16;q++)
										{
											if(boba[q].sprite!=NULL)
											{
												if(boba[q].dead==0)
												if(RAMIO_guy_x+16-3>=boba[q].x&&RAMIO_guy_x+2<boba[q].x+16)
												if(RAMIO_guy_y+PLAYER_height>=boba[q].y&&RAMIO_guy_y+PLAYER_height<boba[q].y+16)
												{
													int r=rand()%5;

													if(r==0)CAPTION_make_caption(&yuu_ramio_caption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,3,"Squish!",FONT_NORMAL_ID,WHITE,BLACK,1,1);
													if(r==1)CAPTION_make_caption(&yuu_ramio_caption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,3,"Take that!",FONT_NORMAL_ID,WHITE,BLACK,1,1);
													if(r==2)CAPTION_make_caption(&yuu_ramio_caption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,3,"Poor guy.",FONT_NORMAL_ID,WHITE,BLACK,1,1);

													boba[q].dead=1;
													//play sound
													HARDWARE_play_sound("ramiosplat",64,44100,0);
													//bounce
													RAMIO_jumping=1;

												}

											}

										}


									}
								}
								else
								{
									if(!BUTTON_A_HELD)can_jump=1;
									pixels_fell=0;
									fall_accel_count=0;
									was_jumping=0;

								}
						}


					}


					HARDWARE_set_sprite_xy(RAMIO_guy_sprite,RAMIO_screen_x+RAMIO_guy_x,RAMIO_screen_y+RAMIO_guy_y);



					RAMIO_update_score();

					RAMIO_frames++;





					//get heart
					//turn into evil reggie
					//throw pizzas


					//sprite type broken brick


					//jump into ? blocks, get stuff

					//jump into bricks, break them


					//skidding is not right.
					//need to be able to run over spaces
					//slows down when hits a block on ceiling. no good

					//if bobas are above a block you hit, kill them

					//cant jump into a gap in between 2 blocks horizontally

					//DONE======================

					//make sprites
					//walk sprites, animate them
					//stomp on bobs head, delete them
					//run into sprites die

					//fall in pit die


					//sprite type brick 16x16
					//sprite type ? block
					//sprite type dead block


					//timer

					//need level end when enter door at end

					//timer
					//run out of time die






					//0 stand
					//1 right1
					//2 right2
					//3 right3
					//4 right2
					//5 rightjump
					//6 left1
					//7 left2
					//8 left3
					//9 left2
					//10 leftjump
					//11 dead

					int animspeed=5;
					if(running)animspeed=3;


					static int facing=RIGHT;

					if(right_walk_speed>left_walk_speed)
					{
						facing=RIGHT;
					}
					else
					if(right_walk_speed<left_walk_speed)
					{
						facing=LEFT;
					}

					if(facing==RIGHT)
					{
						if(RAMIO_jumping)
						{
							HARDWARE_update_sprite_texture(RAMIO_guy_sprite,(16*32)*5);
						}
						else
						if(walking_right)
						{

							static int frame = 0;
							if(RAMIO_vbl_count%animspeed==0)
							{
								frame++;
								if(frame>3)frame=0;
								HARDWARE_update_sprite_texture(RAMIO_guy_sprite,((16*32)*1)+((16*32)*frame));
							}
						}
						else
						HARDWARE_update_sprite_texture(RAMIO_guy_sprite,((16*32)*1)+(16*32)*0);
					}


					if(facing==LEFT)
					{
						if(RAMIO_jumping)
						{
							HARDWARE_update_sprite_texture(RAMIO_guy_sprite,(16*32)*10);
						}
						else
						if(walking_left)
						{

							static int frame = 0;
							if(RAMIO_vbl_count%animspeed==0)
							{
								frame++;
								if(frame>3)frame=0;
								HARDWARE_update_sprite_texture(RAMIO_guy_sprite,((16*32)*6)+((16*32)*frame));
							}
						}
						else
						HARDWARE_update_sprite_texture(RAMIO_guy_sprite,((16*32)*6));
					}

					run_bobas();
					run_moneyblocks();
					run_brickblocks();

					//check running into bobas
					int q=0;
					for(q=0;q<16;q++)
					{
						if(boba[q].sprite!=NULL)
						if(boba[q].dead==0)
						if(RAMIO_guy_x+16>=boba[q].x+4&&RAMIO_guy_x<boba[q].x+16-4)
						if(RAMIO_guy_y+PLAYER_height>=boba[q].y+4&&RAMIO_guy_y+PLAYER_height<=boba[q].y+16)
						RAMIO_dead=1;
					}

					//check fell in pit
					if(RAMIO_guy_y+PLAYER_height>=22*8)RAMIO_dead=1;



					//end of level
					if((RAMIO_guy_x+RAMIO_map_x)/8>=468)
					{
						RAMIO_won=1;

					}


					RAMIO_timer--;
					if(RAMIO_timer<=0)
					{
						RAMIO_dead=1;
					}


					//timer
					static char timerchar[6];
					timerchar[0] = '$';
					timerchar[1] = 48+((RAMIO_timer/1000)%10);
					timerchar[2] = 48+((RAMIO_timer/100)%10);
					timerchar[3] = 48+((RAMIO_timer/10)%10);
					timerchar[4] = 48+(RAMIO_timer%10);
					timerchar[5] = '\0';

					if(RAMIO_timercaption==NULL)CAPTION_make_caption(&RAMIO_timercaption,1,RAMIO_screen_x+20,RAMIO_screen_y+10,-1,(const char*)timerchar,FONT_NORMAL_ID,BLACK,CLEAR,5,1);
					CAPTION_replace_text(RAMIO_timercaption,(const char*)timerchar);





				}//end if not dead

			}//end newframe


			//if ramio is past x, scroll camera

			if(RAMIO_guy_x+16>=(32*8)/3)
			{
				RAMIO_offset_x++;
				RAMIO_guy_x--;

				int q=0;
				for(q=0;q<16;q++)
				{
					if(boba[q].sprite!=NULL)boba[q].x--;
					if(moneyblock[q].sprite!=NULL)moneyblock[q].x--;
					if(brickblock[q].sprite!=NULL)brickblock[q].x--;
				}

				if(RAMIO_offset_x>=8)
				{
					RAMIO_offset_x=0;
					RAMIO_map_x+=8;

					//crop new map

					int y=0;
					int x=0;
					for(y=0;y<22;y++)
					for(x=0;x<30;x++)
					{

						if(x==29)
						{
							int tile = RAMIO_map1[(RAMIO_map_width*y)+x+(RAMIO_map_x/8)];

							//check for bobas, blocks
							if(tile==RAMIO_map3[(RAMIO_map_width*23)+0])make_boba(x*8,y*8);
							if(tile==RAMIO_map3[(RAMIO_map_width*23)+1])make_brickblock(x*8,y*8);
							if(tile==RAMIO_map3[(RAMIO_map_width*23)+2])make_moneyblock(x*8,y*8);

						}


						RAMIO_metamap3[(32*y)+x] = RAMIO_map3[(RAMIO_map_width*y)+x+(RAMIO_map_x/8)];
						RAMIO_metamap2[(32*y)+x] = RAMIO_map2[(RAMIO_map_width*y)+x+(RAMIO_map_x/8)];

					}

					RAMIO_redraw_map();
				}

				HARDWARE_set_AUX_map_xy(0,RAMIO_screen_x-RAMIO_offset_x,RAMIO_screen_y);
				HARDWARE_set_AUX_map_xy(1,RAMIO_screen_x-RAMIO_offset_x,RAMIO_screen_y);
			}

			set_bobas_xy();
			set_moneyblocks_xy();
			set_brickblocks_xy();




		}
		else
		{
			if(RAMIO_credit_screen_init==0)
			{

				HARDWARE_delete_AUX_bg(2);

				HARDWARE_stop_music();

				HARDWARE_unload_file((void**)&RAMIO_palette);
				HARDWARE_unload_file((void**)&RAMIO_tileset);

				HARDWARE_unload_file((void**)&RAMIO_map3);
				HARDWARE_unload_file((void**)&RAMIO_map2);

				free(RAMIO_metamap3);
				free(RAMIO_metamap2);

				//HARDWARE_unload_file((void*)&RAMIO_original_map);


				RAMIO_palette =         (short unsigned int*)HARDWARE_load_file("/minigame/ramio/RAMIO_credits_Pal.bin");
				RAMIO_tileset =         (unsigned char*)HARDWARE_load_file("/minigame/ramio/RAMIO_credits_Tiles.bin");
				RAMIO_map3     =         (short unsigned int*)HARDWARE_load_file("/minigame/ramio/RAMIO_credits_Map.bin");
				RAMIO_tileset_size =     HARDWARE_get_file_size("/minigame/ramio/RAMIO_credits_Tiles.bin");

				HARDWARE_load_AUX_map_to_xy_xy(1,RAMIO_map3,RAMIO_tileset,RAMIO_palette,256,192,TV_fromx+RAMIO_playing_field_map_scroll_x,TV_fromy,TV_aspectratio,0);

				RAMIO_background_is_init=0;
				RAMIO_credit_screen_init=1;

			}

			if(BUTTON_START_PRESSED)
			{

				HARDWARE_delete_AUX_bg(2);

				HARDWARE_unload_file((void**)&RAMIO_palette);
				HARDWARE_unload_file((void**)&RAMIO_tileset);
				HARDWARE_unload_file((void**)&RAMIO_map3);

				GAME_playing_ramio=0;

			}


		}

}


//=========================================================================================================================
void RAMIO_vbl()
{//=========================================================================================================================
	RAMIO_newframe=1;
	RAMIO_vbl_count++;
	if(RAMIO_vbl_count>600)RAMIO_vbl_count=0;
}



