

#include "../../main.h"
//#include "map.h"


bool MAP_just_loaded=0;

int MAP_cam_x=0;
int MAP_cam_y=0;

int MAP_fx_border_width=0;
int MAP_fx_border_height=0;

int HARDWARE_map_id=0;

int* HARDWARE_map_0=NULL;
int* HARDWARE_map_1=NULL;
int* HARDWARE_map_2=NULL;
int* HARDWARE_map_3=NULL;

int* HARDWARE_map_hit_layer=NULL; //was bool before condensed separate bins into 1 single bin
int* HARDWARE_map_fx_layer=NULL;


char HARDWARE_map_0_filename[256];
char HARDWARE_map_1_filename[256];
char HARDWARE_map_2_filename[256];
char HARDWARE_map_3_filename[256];


char HARDWARE_map_hit_layer_filename[256];
char HARDWARE_map_fx_layer_filename[256];
char HARDWARE_map_palette_filename[256];
char HARDWARE_map_tileset_filename[256];

void (*MAP_current_map_load_function)()=DO_NOTHING_Function;
void (*MAP_current_map_run_function)(BOOL)=DO_NOTHING_Function;
void (*MAP_current_map_stop_function)()=DO_NOTHING_Function;
void (*MAP_current_map_vbl_function)()=DO_NOTHING_Function;
void (*MAP_current_map_hbl_function)()=DO_NOTHING_Function;

int HARDWARE_map_tileset_size=0;

int dont_load_palette=0;

int HARDWARE_map_width_tiles=0;
int HARDWARE_map_height_tiles=0;

int HARDWARE_map_width=0;
int HARDWARE_map_height=0;

int* HARDWARE_map_palette=NULL;
int* HARDWARE_map_tileset=NULL;

//=========================================================================================================================
void MAP_set_map_cam_to_cameraman()
{//=========================================================================================================================

	int x=cameraman->MAP_x;
	int y=cameraman->MAP_y;

	MAP_cam_x=x-(GAME_VIEWPORT_WIDTH_PIXELS/2);
	MAP_cam_y=y-(GAME_VIEWPORT_HEIGHT_PIXELS/2);
}



//=========================================================================================================================
bool MAP_is_xy_within_screen_by_amt(int x,int y, int amt)
{//=========================================================================================================================

	if(x==-1)x=(MAP_cam_x)+GAME_VIEWPORT_WIDTH_PIXELS/2;
	if(y==-1)y=(MAP_cam_y)+GAME_VIEWPORT_HEIGHT_PIXELS/2;

	if((x+amt>=MAP_cam_x||x>=MAP_cam_x)&&(x-amt<=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS||x<=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS)&&(y+amt>=MAP_cam_y||y>=MAP_cam_y)&&(y-amt<=MAP_cam_y+GAME_VIEWPORT_HEIGHT_PIXELS||y<=MAP_cam_y+GAME_VIEWPORT_HEIGHT_PIXELS))return 1;

	return 0;

}

//=========================================================================================================================
bool MAP_is_xy_within_screen_by_64px(int x,int y)
{//=========================================================================================================================

	int amt=64;

	if(x==-1)x=(MAP_cam_x)+GAME_VIEWPORT_WIDTH_PIXELS/2;
	if(y==-1)y=(MAP_cam_y)+GAME_VIEWPORT_HEIGHT_PIXELS/2;

	if((x+amt>=MAP_cam_x||x>=MAP_cam_x)&&(x-amt<=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS||x<=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS)&&(y+amt>=MAP_cam_y||y>=MAP_cam_y)&&(y-amt<=MAP_cam_y+GAME_VIEWPORT_HEIGHT_PIXELS||y<=MAP_cam_y+GAME_VIEWPORT_HEIGHT_PIXELS))return 1;

	return 0;

}

//=========================================================================================================================
bool MAP_is_xyxy_within_screen_by_amt(int x,int y, int x2, int y2, int amt)
{//=========================================================================================================================

	if(x==-1)x=(MAP_cam_x)+GAME_VIEWPORT_WIDTH_PIXELS/2;
	if(y==-1)y=(MAP_cam_y)+GAME_VIEWPORT_HEIGHT_PIXELS/2;
	if(x2==-1)x2=(MAP_cam_x)+GAME_VIEWPORT_WIDTH_PIXELS/2;
	if(y2==-1)y2=(MAP_cam_y)+GAME_VIEWPORT_HEIGHT_PIXELS/2;

	if(
		(
			(MAP_cam_x>=x-amt&&MAP_cam_x<=x2+amt)||// left side of screen is in range
			(MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS>=x-amt&&MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS<=x2+amt)|| //right side of screen is in range
			(x+amt>=MAP_cam_x&&x-amt<=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS)||//left boundary of range is within screen
			(x2+amt>=MAP_cam_x&&x2-amt<=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS)//right boundary of range is within screen
		)
		&&
		(
			(MAP_cam_y>=y-amt&&MAP_cam_y<=y2+amt)||// top of screen is in range
			(MAP_cam_y+GAME_VIEWPORT_HEIGHT_PIXELS>=y-amt&&MAP_cam_y+GAME_VIEWPORT_HEIGHT_PIXELS<=y2+amt)|| //bottom of screen is within range
			(y+amt>=MAP_cam_y&&y-amt<=MAP_cam_y+GAME_VIEWPORT_HEIGHT_PIXELS)||//top boundary of range is within screen
			(y2+amt>=MAP_cam_y&&y2-amt<=MAP_cam_y+GAME_VIEWPORT_HEIGHT_PIXELS)//bottom boundary of range is within screen

		)
	)return 1;

	return 0;
}

//=========================================================================================================================
bool MAP_is_xy_within_screen(int x,int y)
{//=========================================================================================================================

	if(x==-1)x=(MAP_cam_x)+GAME_VIEWPORT_WIDTH_PIXELS/2;
	if(y==-1)y=(MAP_cam_y)+GAME_VIEWPORT_HEIGHT_PIXELS/2;

	if((x>=MAP_cam_x)&&(x<=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS)&&(y>=MAP_cam_y)&&(y<=MAP_cam_y+GAME_VIEWPORT_HEIGHT_PIXELS))return 1;

	return 0;
}



#define GLOBAL_BRIGHTNESS 2

#define SKY 30
#define TREE1 31
#define TREE2 32

//sky original 21 27 31
//tree1 original 20 31 16
//tree2 12 29 12

#define TIME_DAWN 0
#define TIME_EARLY 1
#define TIME_DAY 2
#define TIME_DUSK 3
#define TIME_DARK 4


//=========================================================================================================================
void set_window_colors(int time)
{//=========================================================================================================================

	if(time==TIME_DAWN)
	{
	//dawn
	GAME_temp_TILESET_PALETTE[SKY]=HARDWARE_RGB(0,7,15);
	GAME_temp_TILESET_PALETTE[TREE1]=HARDWARE_RGB(0,11,1);
	GAME_temp_TILESET_PALETTE[TREE2]=HARDWARE_RGB(0,9,0);
	}
	if(time==TIME_EARLY)
	{
	//early
	GAME_temp_TILESET_PALETTE[SKY]=HARDWARE_RGB(9,11,18);
	GAME_temp_TILESET_PALETTE[TREE1]=HARDWARE_RGB(0,11,1);
	GAME_temp_TILESET_PALETTE[TREE2]=HARDWARE_RGB(0,9,0);
	}
	if(time==TIME_DAY)
	{
	//day
	GAME_temp_TILESET_PALETTE[SKY]=HARDWARE_RGB(21,27,31);
	GAME_temp_TILESET_PALETTE[TREE1]=HARDWARE_RGB(20,31,16);
	GAME_temp_TILESET_PALETTE[TREE2]=HARDWARE_RGB(12,29,12);
	}
	if(time==TIME_DUSK)
	{
	//dusk
	GAME_temp_TILESET_PALETTE[SKY]=HARDWARE_RGB(0,7,15);
	GAME_temp_TILESET_PALETTE[TREE1]=HARDWARE_RGB(0,11,1);
	GAME_temp_TILESET_PALETTE[TREE2]=HARDWARE_RGB(0,9,0);
	}
	if(time==TIME_DARK)
	{
	//dark
	GAME_temp_TILESET_PALETTE[SKY]=HARDWARE_RGB(1,0,9);
	GAME_temp_TILESET_PALETTE[TREE1]=HARDWARE_RGB(0,5,1);
	GAME_temp_TILESET_PALETTE[TREE2]=HARDWARE_RGB(0,6,0);
	}
}



//=========================================================================================================================
void load_bg_pals_based_on_time()
{//=========================================================================================================================

int brightness = 0;

if(CLOCK_hour<3)brightness=-10;
if(CLOCK_hour==3)brightness=-10+(CLOCK_minute/15);
if(CLOCK_hour==4)brightness=-6+(CLOCK_minute/20);
if(CLOCK_hour==5)brightness=-3;
if(CLOCK_hour==6)brightness=-2;
if(CLOCK_hour==7)brightness=-1;
if(CLOCK_hour>7&&CLOCK_hour<12+7)brightness=0;
if(CLOCK_hour==12+7)brightness=-1;
if(CLOCK_hour==12+8)brightness=-2;
if(CLOCK_hour==12+9)brightness=-3;
if(CLOCK_hour==12+10)brightness=-(4+(CLOCK_minute/30));
if(CLOCK_hour==12+11)brightness=-(6+(CLOCK_minute/15));
if(CLOCK_hour>12+11)brightness=-10;




	if((CLOCK_hour>=5&&CLOCK_hour<6))//yellowish
	{

		HARDWARE_create_brightened_palette(HARDWARE_map_palette,(int*)&GAME_temp_TILESET_PALETTE,brightness+GLOBAL_BRIGHTNESS);

		GAME_temp_TILESET_PALETTE[1]=HARDWARE_RGB(0,0,0);

		set_window_colors(TIME_DAWN);

		HARDWARE_load_bg_palette((int*)&GAME_temp_TILESET_PALETTE);

	}


	if((CLOCK_hour>=6&&CLOCK_hour<=7))//yellowish
	{

		HARDWARE_create_brightened_palette(HARDWARE_map_palette,(int*)&GAME_temp_TILESET_PALETTE,brightness+GLOBAL_BRIGHTNESS);

		GAME_temp_TILESET_PALETTE[1]=HARDWARE_RGB(0,0,0);

		set_window_colors(TIME_EARLY);

		HARDWARE_load_bg_palette((int*)&GAME_temp_TILESET_PALETTE);
	}
	if(CLOCK_hour>=8&&CLOCK_hour<=12+7)//normal	160 248 248
	{
		HARDWARE_create_brightened_palette(HARDWARE_map_palette,(int*)&GAME_temp_TILESET_PALETTE,brightness+GLOBAL_BRIGHTNESS);

		GAME_temp_TILESET_PALETTE[1]=HARDWARE_RGB(0,0,0);

		set_window_colors(TIME_DAY);

		HARDWARE_load_bg_palette((int*)&GAME_temp_TILESET_PALETTE);


	}
	if(CLOCK_hour>=12+8&&CLOCK_hour<=12+10)//dark blue
	{

		HARDWARE_create_brightened_palette(HARDWARE_map_palette,(int*)&GAME_temp_TILESET_PALETTE,brightness+GLOBAL_BRIGHTNESS);

		GAME_temp_TILESET_PALETTE[1]=HARDWARE_RGB(0,0,0);

		set_window_colors(TIME_DUSK);

		HARDWARE_load_bg_palette((int*)&GAME_temp_TILESET_PALETTE);

	}
	if((CLOCK_hour>=12+11||CLOCK_hour<=4))//black
	{

		HARDWARE_create_brightened_palette(HARDWARE_map_palette,(int*)&GAME_temp_TILESET_PALETTE,brightness+GLOBAL_BRIGHTNESS);

		GAME_temp_TILESET_PALETTE[1]=HARDWARE_RGB(0,0,0);

		set_window_colors(TIME_DARK);

		HARDWARE_load_bg_palette((int*)&GAME_temp_TILESET_PALETTE);

	}

}
//=========================================================================================================================
void MAP_change_map(int cm,int sx,int sy)
{//=========================================================================================================================


	if(PLAYER_npc==NULL){ERROR_set_error("MAP_change_map()");return;}

	//update_debug_counters=1;

	GLOBAL_main_sprite_input_off=1;

	///TODO: need to have cameraman target presets
	///should have this be a function where you update the target NPC values instead of pointing to an NPC
	cameraman_target=PLAYER_npc;

//trying to come up with a solution where npcs appear to delete simultaneously with bg, not after or before. hideobj or something?
	MAP_current_map_stop_function();//delete npcs
	//NPC_vbl();//npcs actually get deleted. ** calling this before vbl is init is bad. breaks shadow??



	/*if(clicktarget!=NULL)
	{
		NPC_stop_chasing(PLAYER_npc);
		//delete clicktarget gfx/sprite
		if(clicktarget_sprite_on)HARDWARE_delete_sprite(1,clicktarget->PLAYER_id);
		if(clicktarget_sprite_on)HARDWARE_delete_sprite(0,clicktarget->PLAYER_id_touchmap);

		clicktarget=NULL;
		GLOBAL_main_sprite_actions_off=0;
	}*/

	ACTION_caption_delete();

	//UnInitializePathfinder();


	HARDWARE_delete_all_bg_data();


	load_map_data(cm);  //this is in gamelogic.h at the bottom.
	HARDWARE_map_id=cm;


	//load new map files into memory
	HARDWARE_map_0=(int*)HARDWARE_load_file(HARDWARE_map_0_filename);
	HARDWARE_map_1=(int*)HARDWARE_load_file(HARDWARE_map_1_filename);
	HARDWARE_map_2=(int*)HARDWARE_load_file(HARDWARE_map_2_filename);
	HARDWARE_map_3=(int*)HARDWARE_load_file(HARDWARE_map_3_filename);

	HARDWARE_map_hit_layer=(int*)HARDWARE_load_file(HARDWARE_map_hit_layer_filename);
	HARDWARE_map_fx_layer=(int*)HARDWARE_load_file(HARDWARE_map_fx_layer_filename);

	HARDWARE_map_palette=(int*)HARDWARE_load_file(HARDWARE_map_palette_filename);
	HARDWARE_map_tileset=(int*)HARDWARE_load_file(HARDWARE_map_tileset_filename);

	//set width and height
	HARDWARE_map_width=HARDWARE_map_width_tiles*8;
	HARDWARE_map_height=HARDWARE_map_height_tiles*8;





	//if(HARDWARE_map_id!=MAP_bobsgame_INTROTown&&HARDWARE_map_id!=MAP_bobsgame_TOWNTown)InitializePathfinder();


	//-----------------------------
	//get the camera border width and height
	//-----------------------------


	int topbounds=0;
	int leftbounds=0;
	int rightbounds=-1;
	int bottombounds=-1;
	int camstop_tile=4;

	if(HARDWARE_map_width_tiles>SCREEN_WIDTH_TILES){rightbounds=(HARDWARE_map_width_tiles)*8;}
	if(HARDWARE_map_height_tiles>SCREEN_HEIGHT_TILES){bottombounds=(HARDWARE_map_height_tiles)*8;}

	if(HARDWARE_map_height_tiles<=SCREEN_HEIGHT_TILES)
		{
			int x=0; int y=0;
			for(y=HARDWARE_map_height_tiles-1;y>=0;y--)for(x=0;x<HARDWARE_map_width_tiles;x++)if(HARDWARE_map_fx_layer!=NULL)if(HARDWARE_map_fx_layer[(x+(y*HARDWARE_map_width_tiles))]==camstop_tile){ bottombounds=(y)*8; y=-1; x=HARDWARE_map_width_tiles;}
		}

	if(HARDWARE_map_width_tiles<=SCREEN_WIDTH_TILES)
	{
		int x=0; int y=0;
		for(x=HARDWARE_map_width_tiles-1;x>=0;x--)for(y=0;y<HARDWARE_map_height_tiles;y++)if(HARDWARE_map_fx_layer!=NULL)if(HARDWARE_map_fx_layer[(x+(y*HARDWARE_map_width_tiles))]==camstop_tile){ rightbounds=(x)*8; x=-1; y=HARDWARE_map_height_tiles;}
	}

	MAP_fx_border_width=rightbounds-leftbounds;
	MAP_fx_border_height=bottombounds-topbounds;



	load_bg_pals_based_on_time();


	HARDWARE_reload_bg_textures();



	//this should leave the sprite in the same place after entering a new map,then after everything is loaded the camera will center the sprite on the screen. seamless transition!
	if((PLAYER_npc->screen_x+(PLAYER_npc->size_x/2))<=GAME_VIEWPORT_WIDTH_PIXELS/2)cameraman->MAP_x=((sx*8)+(PLAYER_npc->size_x/2))+((GAME_VIEWPORT_WIDTH_PIXELS/2)-(PLAYER_npc->screen_x+(PLAYER_npc->size_x/2)));
	if((PLAYER_npc->screen_x+(PLAYER_npc->size_x/2))>GAME_VIEWPORT_WIDTH_PIXELS/2) cameraman->MAP_x=((sx*8)+(PLAYER_npc->size_x/2))-((PLAYER_npc->screen_x+(PLAYER_npc->size_x/2))-(GAME_VIEWPORT_WIDTH_PIXELS/2));
	if((PLAYER_npc->screen_y+(PLAYER_npc->size_y/2))<=GAME_VIEWPORT_HEIGHT_PIXELS/2)cameraman->MAP_y=(((sy*8)-PLAYER_npc->size_y+6)+(PLAYER_npc->size_y/2))+((GAME_VIEWPORT_HEIGHT_PIXELS/2)-(PLAYER_npc->screen_y+(PLAYER_npc->size_y/2)));
	if((PLAYER_npc->screen_y+(PLAYER_npc->size_y/2))>GAME_VIEWPORT_HEIGHT_PIXELS/2) cameraman->MAP_y=(((sy*8)-PLAYER_npc->size_y+6)+(PLAYER_npc->size_y/2))-((PLAYER_npc->screen_y+(PLAYER_npc->size_y/2))-(GAME_VIEWPORT_HEIGHT_PIXELS/2));

	MAP_set_map_cam_to_cameraman();

	//leave obj xy alone and draw the map before,then center the camera.. nice transitions


	MAP_current_map_load_function();
	//MAP_current_map_run_function(1);


	MAP_just_loaded=1;


	//now we can update mainsprite variables,though obj xy should stay the same unless something happened
	PLAYER_npc->MAP_x=(sx*8);
	PLAYER_npc->MAP_y=((sy*8)-PLAYER_npc->size_y+6);

	NPC_set_screen_xy(&PLAYER_npc);

	//if(PLAYER_npc->sprite!=NULL)HARDWARE_set_sprite_xy(PLAYER_npc->sprite,PLAYER_npc->screen_x,PLAYER_npc->screen_y);


	//cameraman->walking_speed=SPEED_NORMAL;
	//cameraman->vbl_timer=0;

	GLOBAL_main_sprite_input_off=0;
	//GLOBAL_map_initialized=1;



}
//=========================================================================================================================
void MAP_reinit_current_map()
{//=========================================================================================================================

	if(PLAYER_npc==NULL){ERROR_set_error("MAP_reinit_current_map()");return;}

	cameraman_target=PLAYER_npc;

	load_bg_pals_based_on_time();
	HARDWARE_reload_bg_textures();

}

//=========================================================================================================================
void MAP_main()
{//=========================================================================================================================

	ACTION_in_action_range=0; //this is set to 1 if ACTION_check() is called in maprun

	if(MAP_just_loaded==1){MAP_just_loaded=0;MAP_current_map_run_function(1);}//MAP_just_loaded is set to 1 in changemap, for init stuff in run functions
	else MAP_current_map_run_function(0);

	if(ACTION_in_action_range==0)ACTION_caption_delete_if_no_action();

}



