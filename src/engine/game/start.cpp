

#include "../../main.h"
//#include "start.h"



float STARTSCREEN_aspectratio = 0;//((float)((float)(GAME_VIEWPORT_HEIGHT_PIXELS)/1.0f)/192.0f);
int STARTSCREEN_fromx = 0;//((GAME_VIEWPORT_WIDTH_PIXELS-(STARTSCREEN_aspectratio*256.0f))/2);
int STARTSCREEN_fromy = 0;


unsigned short* start_status_1_palette =   NULL ;
unsigned char* start_status_1_tileset =   NULL ;
unsigned short* start_status_1_map     =   NULL ;
int start_status_1_tileset_size = 0;

unsigned short* start_status_3_palette =   NULL ;
unsigned char* start_status_3_tileset=   NULL ;
unsigned short* start_status_3_map   =   NULL ;
int start_status_3_tileset_size = 0;

unsigned short* startscreen_palette	= NULL;
unsigned char* startscreen_tileset	= NULL;
unsigned short* startscreen_map   	= NULL;

int start_screen_x3=0;
int start_screen_y3=0;
int start_screen_x2=0;
int start_screen_y2=0;
int start_screen_x1=0;
int start_screen_y1=0;

int current_start_screen=0;

CAPTION* mentalstatecaption=NULL;
CAPTION* stylecaption=NULL;
CAPTION* staminacaption=NULL;
CAPTION* hygienecaption=NULL;
CAPTION* foodcaption=NULL;
CAPTION* poopcaption=NULL;

CAPTION* itemcaption[20]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};

int selected_item=0;
CAPTION* descriptioncaption=NULL;
CAPTION* descriptioncaption2=NULL;

int mr_cart_switch=0;

unsigned short start_temp_map_width = 0;
unsigned short start_temp_map_height = 0;
unsigned short* start_temp_hit_layer = 0;
unsigned short* start_temp_fx_layer = 0;
unsigned short* start_temp_action_layer=0;

unsigned short start_hit_action_layer[32*24]={0};
unsigned short start_fx_layer[32*24]={0};

bool start_screen_ready=0;

int current_mod = 0;
int amt_of_mods=8;
int mod_selection=0;
int mods[128];

CAPTION* musicchoicecaption1=NULL;
CAPTION* musicchoicecaption2=NULL;
CAPTION* musicchoicecaption3=NULL;
CAPTION* musicchoicecaption4=NULL;
CAPTION* musicchoicecaption5=NULL;
CAPTION* musicchoicecaption6=NULL;
CAPTION* musicchoicecaption7=NULL;
CAPTION* musicchoicecaption8=NULL;

int start_scroll=0;
int start_scroll_dir = RIGHT;

int start_screen_timer_var=0;
int start_screen_vbl_count=0;




//=========================================================================================================================
void make_status_captions()
{//=========================================================================================================================
	HARDWARE_set_sprite_y(TEXTANSWER_cursor_sprite,-8);

	CAPTION_make_caption(&mentalstatecaption,1,165,20,-1,		"bored"		,FONT_NORMAL_ID,YELLOW,BLACK,4,STARTSCREEN_aspectratio);//"bored"
	CAPTION_make_caption(&stylecaption,1,165,20+16*1,-1,		"average"	,FONT_NORMAL_ID,YELLOW,BLACK,4,STARTSCREEN_aspectratio);//"average"
	CAPTION_make_caption(&staminacaption,1,165,20+16*2,-1,	"awake"		,FONT_NORMAL_ID,GREEN,BLACK,4,STARTSCREEN_aspectratio); //"awake"
	CAPTION_make_caption(&hygienecaption,1,165,21+16*3,-1,	"fresh"		,FONT_NORMAL_ID,BLUE,BLACK,4,STARTSCREEN_aspectratio);  //"fresh"
	CAPTION_make_caption(&foodcaption,1,165,21+16*4,-1,		"full"		,FONT_NORMAL_ID,BLUE,BLACK,4,STARTSCREEN_aspectratio);  //"full"
	CAPTION_make_caption(&poopcaption,1,165,20+16*5,-1,		"just went"	,FONT_NORMAL_ID,BLUE,BLACK,4,STARTSCREEN_aspectratio);  //"just went"

}





//=========================================================================================================================
void make_stuff_captions()
{//=========================================================================================================================

		if(ITEM_items_in_pocket>0)HARDWARE_set_sprite_y(TEXTANSWER_cursor_sprite,50+16*selected_item);

/*
	static char d1[50];
	static char d2[50];

if(ITEM_items_in_pocket>0)
{
	int l=strlen(pocket[selected_item]->description);

	int a=0;
	for(a=0;a<l/2;a++)
	d1[a]=pocket[selected_item]->description[a];
	d1[a]='\0';
	for(a=a+0;a<l;a++)
	d2[a]=pocket[selected_item]->description[a];
	d2[a]='\0';
}
*/

		if(ITEM_items_in_pocket>0)CAPTION_make_caption(&descriptioncaption,1,32,0,-1,pocket[selected_item]->description,FONT_SMALL_ID,WHITE,BLACK,4,1);
		//if(ITEM_items_in_pocket>0)CAPTION_make_caption(&descriptioncaption2,1,0,16,-1,(char*)d2,FONT_SMALL_ID,WHITE,BLACK,4,STARTSCREEN_aspectratio);

		int i=0;
		for(i=0;i<ITEM_items_in_pocket;i++)
		{
			CAPTION_make_caption(&itemcaption[i],1,32,48+16*i,-1,pocket[i]->name,FONT_SMALL_ID,WHITE,BLACK,4,1);
		}

}
//=========================================================================================================================
void delete_status_captions()
{//=========================================================================================================================
			CAPTION_delete_caption(mentalstatecaption);
			CAPTION_delete_caption(stylecaption);
			CAPTION_delete_caption(staminacaption);
			CAPTION_delete_caption(hygienecaption);
			CAPTION_delete_caption(foodcaption);
			CAPTION_delete_caption(poopcaption);

			CAPTION_main();
			CAPTION_vbl();
			CAPTION_main();
}
//=========================================================================================================================
void delete_stuff_captions()
{//=========================================================================================================================


	if(ITEM_items_in_pocket>0)CAPTION_delete_caption(descriptioncaption);
	//if(ITEM_items_in_pocket>0)CAPTION_delete_caption(descriptioncaption2);
	int i;
	for(i=0;i<ITEM_items_in_pocket;i++)
	{
		CAPTION_delete_caption(itemcaption[i]);
	}

			CAPTION_main();
			CAPTION_vbl();
			CAPTION_main();
}











//=========================================================================================================================
void start_screen_timer()
{//=========================================================================================================================

	/*	start_screen_timer_var++;

		if(start_screen_timer_var%10==0)
		{
			start_screen_y1++;if(start_screen_y1>=32*8)start_screen_y1=0;
		}

		if(start_screen_timer_var%20==0)
		{
			start_screen_x3++;if(start_screen_x3>=32*8)start_screen_x3=0;
			start_screen_x2--;if(start_screen_x2<0)start_screen_x2=32*8-1;
		}

		if(start_screen_timer_var%120==0)
		{
			start_screen_y3+=rand()%32;if(start_screen_y3>=32*8)start_screen_y3=0;
			start_screen_y2-=rand()%32;if(start_screen_y2<0)start_screen_y2=32*8-1;
		}*/

}


//=========================================================================================================================
//void start_screen_set_captions()
//{//=========================================================================================================================



	//CAPTION_delete_all_captions();



	/*if(current_start_screen==2)//SFX
	{
		CAPTION_delete_all_captions();

		HARDWARE_set_sprite_y(0,TEXTANSWER_cursor_sprite_id,mod_selection*16+2);
		int color=WHITE;
		if(current_mod==mods[0])color=RED;else color=WHITE;	CAPTION_make_caption(&musicchoicecaption1,0,32,16*0,-1,"cute",FONT_BOB_ID,color,BLACK);
		if(current_mod==mods[1])color=RED;else color=WHITE;	CAPTION_make_caption(&musicchoicecaption2,0,32,16*1,-1,"underwater",FONT_BOB_ID,color,BLACK);
		if(current_mod==mods[2])color=RED;else color=WHITE;	CAPTION_make_caption(&musicchoicecaption3,0,32,16*2,-1,"overwater",FONT_BOB_ID,color,BLACK);
		if(current_mod==mods[3])color=RED;else color=WHITE;	CAPTION_make_caption(&musicchoicecaption4,0,32,16*3,-1,"calmbeat",FONT_BOB_ID,color,BLACK);
		if(current_mod==mods[4])color=RED;else color=WHITE;	CAPTION_make_caption(&musicchoicecaption5,0,32,16*4,-1,"rain",FONT_BOB_ID,color,BLACK);
		if(current_mod==mods[5])color=RED;else color=WHITE;	CAPTION_make_caption(&musicchoicecaption6,0,32,16*5,-1,"disko",FONT_BOB_ID,color,BLACK);
		if(current_mod==mods[6])color=RED;else color=WHITE;	CAPTION_make_caption(&musicchoicecaption7,0,32,16*6,-1,"snappy",FONT_BOB_ID,color,BLACK);
	}*/


//}

int TEMP_clock_paused=0;
int TEMP_main_sprite_input_off=0;
int TEMP_main_sprite_standing=0;
int TEMP_main_sprite_actions_off=0;

//=========================================================================================================================
void start_screen_init()
{//=========================================================================================================================


	HARDWARE_play_sound("gotline",127,44100,0);
	//cameraman_target=&main_npc;
	//GLOBAL_main_sprite_input_off=1;

	//NPC_pause();
	//CAPTION_pause();
	//HARDWARE_delete_bg(1,3);
	//HARDWARE_delete_bg(1,2);
	//HARDWARE_delete_bg(1,1);
	//HARDWARE_delete_bg(1,0);
	//bottom_screen_on=0;
	//HARDWARE_delete_sprite(0,main_sprite_shadow->PLAYER_id_touchmap);
	//HARDWARE_delete_bg(0,3);
	//HARDWARE_delete_bg(0,1);
	//HARDWARE_stop_music();


	GAME_paused=1;



	TEMP_clock_paused=CLOCK_paused;
	TEMP_main_sprite_input_off=GLOBAL_main_sprite_input_off;
	TEMP_main_sprite_actions_off=GLOBAL_main_sprite_actions_off;

	CLOCK_paused=1;
	GLOBAL_main_sprite_input_off=1;
	GLOBAL_main_sprite_actions_off=1;




	//black screens on top and bottom
	//mrcart on top
	//status screen on bottom
	//NEED CUSTOM TEXT ANSWER FULLSCREEN OBJ FINE
	//SELECTION WHEEL MAYBE?
	//L AND R SELECTION DEAL ON TOP

	//STATUS
	//RADIO/MP3 PLAYER/MEMORY RADIO/HEAD CHIP (THIS SHOULD BE SELECT)
	//OBJECTIVES/FRIENDS/STARS/PERCENT/CONVERSATIONS [mr cart previous hints of the day]
	//ITEMS
	//CHEAT/SECRET/DEBUG/OPTIONS [greyed out cheat/secret]

		//status screen
		/*
			time
			day
			weather

			BODY STATUS
			health/injury/speed
			sleepiness/energy/stamina
			hunger/thirst
			bathroom/pee/poo

			cleanliness/hygiene/stinkiness
			comfort/wet/cold

			mood/morale
			paranoia/frightened/anxiety
			depression
			confidence/optimism/enthusiasm

			coolness/hip points/esteem/image
			popularity/amount of friends/respect
			reputation/karma/honesty/trust
			ability/work ethic/concentration/skill/life experience

			school grade
			math/physics/computers/science
			english/history
			art ability
			music ability

			detention status
			grounding status
		*/
		//HARDWARE_zero_bg_system();

		/*
		//top screen palette
		HARDWARE_load_bg_palette(1,3,HARDWARE_get_file_address("start_Map_Layer_3_Pal"));
		HARDWARE_load_bg_palette(1,2,HARDWARE_get_file_address("start_Map_Layer_2_Pal"));
		HARDWARE_load_bg_palette(1,1,HARDWARE_get_file_address("start_Map_Layer_1_Pal"));
		//top screen tiles
 		HARDWARE_load_bg_tiles(1,3,HARDWARE_get_file_address("start_Map_Layer_3_Tiles"),6*32);
 		HARDWARE_load_bg_tiles(1,2,HARDWARE_get_file_address("start_Map_Layer_2_Tiles"),6*32);
 		HARDWARE_load_bg_tiles(1,1,HARDWARE_get_file_address("start_Map_Layer_1_Tiles"),(1024-12)*32);
		//top screen map
		HARDWARE_load_map(1,3,HARDWARE_get_file_address("start_Map_Layer_3_Map"),BG_512X256);
		HARDWARE_load_map(1,2,HARDWARE_get_file_address("start_Map_Layer_2_Map"),BG_512X256);
		HARDWARE_load_map(1,1,HARDWARE_get_file_address("start_Map_Layer_1_Map"),BG_512X256);
		//initialize top screen
		HARDWARE_init_bg(1,3,BG_512X256,0,1);
		HARDWARE_init_bg(1,2,BG_512X256,0,1);
		HARDWARE_init_bg(1,1,BG_512X256,0,1);
		//hide layers
		HARDWARE_hide_bg(1,3);
		HARDWARE_hide_bg(1,2);
		HARDWARE_hide_bg(1,1);

		HARDWARE_scroll_bg_xy(1,3,0,0);
		HARDWARE_scroll_bg_xy(1,2,0,0);
		HARDWARE_scroll_bg_xy(1,1,0,0);

		HARDWARE_init_large_bg(1,3,32,32,HARDWARE_get_file_address("start_Map_Layer_3_Map"));
		HARDWARE_init_large_bg(1,2,32,32,HARDWARE_get_file_address("start_Map_Layer_2_Map"));
		HARDWARE_init_large_bg(1,1,32,32,HARDWARE_get_file_address("start_Map_Layer_1_Map"));

		HARDWARE_infinite_large_scroll_bg_xy(1,3,start_screen_x3,start_screen_y3);
		HARDWARE_infinite_large_scroll_bg_xy(1,2,start_screen_x2,start_screen_y2);
		HARDWARE_infinite_large_scroll_bg_xy(1,1,start_screen_x1,start_screen_y1);

		HARDWARE_show_bg(1,3);
		HARDWARE_show_bg(1,2);
		HARDWARE_show_bg(1,1);
		*/




		//HARDWARE_delete_bg(0,0);

		{
		   //start_status_1_palette =         HARDWARE_load_file("/startscreen/status_layer_1_Pal.bin");
		   //start_status_1_tileset =         HARDWARE_load_file("/startscreen/status_layer_1_Tiles.bin");
		   //start_status_1_map     =         HARDWARE_load_file("/startscreen/status_layer_1_Map.bin");
		   //start_status_1_tileset_size =     HARDWARE_get_file_size("/startscreen/status_layer_1_Tiles.bin");

		   //start_status_3_palette =         HARDWARE_load_file("/startscreen/status_layer_3_Pal.bin");
		   //start_status_3_tileset =         HARDWARE_load_file("/startscreen/status_layer_3_Tiles.bin");
		   //start_status_3_map     =         HARDWARE_load_file("/startscreen/status_layer_3_Map.bin");
		   //start_status_3_tileset_size =     HARDWARE_get_file_size("/startscreen/status_layer_3_Tiles.bin");


		   startscreen_palette =         (short unsigned int*)HARDWARE_load_file("/startscreen/startscreen_status_Pal.bin");
		   startscreen_tileset =         (unsigned char*)HARDWARE_load_file("/startscreen/startscreen_status_Tiles.bin");
		   startscreen_map     =         (short unsigned int*)HARDWARE_load_file("/startscreen/startscreen_status_Map.bin");

		   //startscreen_tileset_size= HARDWARE_get_file_size("/startscreen/startscreen_status_Tiles.bin");

		   /*startscreen_palette =         HARDWARE_load_file("/startscreen/startscreen_stuff_Pal.bin");
		   startscreen_tileset =         HARDWARE_load_file("/startscreen/startscreen_stuff_Tiles.bin");
		   startscreen_map     =         HARDWARE_load_file("/startscreen/startscreen_stuff_Map.bin");
		   startscreen_tileset_size= HARDWARE_get_file_size("/startscreen/startscreen_stuff_Tiles.bin");

		   startscreen_palette =         HARDWARE_load_file("/startscreen/startscreen_sound_Pal.bin");
		   startscreen_tileset =         HARDWARE_load_file("/startscreen/startscreen_sound_Tiles.bin");
		   startscreen_map     =         HARDWARE_load_file("/startscreen/startscreen_sound_Map.bin");
		   startscreen_tileset_size= HARDWARE_get_file_size("/startscreen/startscreen_sound_Tiles.bin");*/

		}


		STARTSCREEN_aspectratio = ((float)((float)(GAME_VIEWPORT_HEIGHT_PIXELS)/1.0f)/192.0f);
		STARTSCREEN_fromx = ((GAME_VIEWPORT_WIDTH_PIXELS-(STARTSCREEN_aspectratio*256.0f))/2);
		STARTSCREEN_fromy = 0;

		HARDWARE_load_AUX_map_to_xy_xy(0,startscreen_map,startscreen_tileset,startscreen_palette,256,192,STARTSCREEN_fromx,STARTSCREEN_fromy,STARTSCREEN_aspectratio,0);




		//////////

		/*HARDWARE_load_bg_palette(0,2,start_status_3_palette);
		HARDWARE_load_bg_palette(0,0,start_status_1_palette);

		HARDWARE_load_bg_tiles(0,2,start_status_3_tileset,512*32);
		HARDWARE_load_bg_tiles(0,0,start_status_1_tileset,512*32);

		HARDWARE_load_map(0,2,start_status_3_map,BG_512X256,256,256);
		HARDWARE_load_map(0,0,start_status_1_map,BG_512X256,256,256);

		HARDWARE_init_bg(0,2,BG_512X256,0,1);
		HARDWARE_init_bg(0,0,BG_512X256,0,1);

		HARDWARE_hide_bg(0,2);
		HARDWARE_hide_bg(0,0);

		HARDWARE_scroll_bg_xy(0,2,0,0);
		HARDWARE_scroll_bg_xy(0,0,0,0);

		HARDWARE_init_large_bg(0,2,32*3,32,start_status_3_map);
		HARDWARE_init_large_bg(0,0,32,32,start_status_1_map);

		HARDWARE_infinite_large_scroll_bg_xy(0,2,0,0);
		HARDWARE_infinite_large_scroll_bg_xy(0,0,0,0);

		HARDWARE_show_bg(0,2);
		HARDWARE_show_bg(0,0);*/

	//answer_cursor_gfx = HARDWARE_create_sprite_gfxslot(1,answer_cursor_GFX,0,8,8,1,0);

	TEXTANSWER_cursor_sprite = HARDWARE_create_sprite(TEXTANSWER_cursor_GFX,0,5,1.0f,25,-8,255);

	//HARDWARE_create_sprite(1,TEXTANSWER_cursor_sprite_id,answer_cursor_gfx,8,8,0,0,0,0,0,0,5,0,25,-8);

	//NPC_create_npc(&mr_cart,mrcart,64,64,(256/2+64/2)/8,(192/2+64/2)/8);
	//mr_cart->layer=1;

 	//start_temp_map_width = HARDWARE_map_width;
	//start_temp_map_height = HARDWARE_map_height;

	//GLOBAL_main_sprite_actions_off=1;
	//GLOBAL_main_sprite_fx_off=1;

	//HARDWARE_map_width=32;
	//HARDWARE_map_height=24;

	//cameraman->MAP_x=256/2;
	//cameraman->MAP_y=192/2;
	//MAP_cam_x=0;
	//MAP_cam_y=0;
	//touchmap_cam_x=0;
	//touchmap_cam_y=0;

	//mr_cart->animation_off=1;
	//mr_cart->ignore_hit_layer=1;
	//mr_cart->not_on_touchmap=1;

	selected_item=0;
	current_start_screen=0;
	//start_screen_set_captions();



	make_status_captions();

	start_screen_ready=1;

}
//=========================================================================================================================
void start_screen_deinit()
{//=========================================================================================================================


	if(current_start_screen==0)delete_status_captions();
	if(current_start_screen==1)delete_stuff_captions();



	HARDWARE_delete_AUX_bg(0);

	HARDWARE_delete_sprite(TEXTANSWER_cursor_sprite);
	//HARDWARE_delete_sprite_gfxslot(1,answer_cursor_gfx);


	//HARDWARE_wait_for_vbl();
	//HARDWARE_wait_for_vbl();


	//HARDWARE_delete_bg(0,2);
	//HARDWARE_delete_bg(0,0);

	//HARDWARE_unload_file((void*)&start_status_1_palette);
	//HARDWARE_unload_file((void*)&start_status_1_tileset);
	//HARDWARE_unload_file((void*)&start_status_1_map);

	HARDWARE_unload_file((void**)&startscreen_palette);
	HARDWARE_unload_file((void**)&startscreen_tileset);
	HARDWARE_unload_file((void**)&startscreen_map);



	//start_screen_y1=0;
	//start_screen_y2=0;
	//start_screen_y3=0;

	//start_screen_x1=0;
	//start_screen_x2=0;
	//start_screen_x3=0;

	//start_scroll=0;
	//current_start_screen=1;

	//CAPTION_delete_all_captions();


	//mr_cart_switch=-1;

	//NPC_delete_npc(mr_cart);

	//PLAYER_npc=&main_npc;

	//cameraman->MAP_x=PLAYER_npc->MAP_x;
	//cameraman->MAP_y=PLAYER_npc->MAP_y;

	//MAP_set_map_cam_to_cameraman();
	//MAP_set_touchmap_cam();

 	//HARDWARE_map_width=start_temp_map_width;
	//HARDWARE_map_height=start_temp_map_height;

	//GLOBAL_main_sprite_actions_off=0;
	//GLOBAL_main_sprite_fx_off=0;

	start_screen_ready=0;



	HARDWARE_play_sound("gotline",127,44100,0);
	//HARDWARE_hide_bg(1,0);
	//HARDWARE_hide_bg(1,1);
	//HARDWARE_hide_bg(1,2);
	//HARDWARE_hide_bg(1,3);
	//HARDWARE_delete_all_bg_data();
	//MAP_reinit_current_map();

	CLOCK_paused=TEMP_clock_paused;
	GLOBAL_main_sprite_input_off=TEMP_main_sprite_input_off;
	GLOBAL_main_sprite_actions_off=TEMP_main_sprite_actions_off;

	GAME_paused=0;
	//HARDWARE_wait_for_vbl();
	//HARDWARE_wait_for_vbl();
	//NPC_unpause();
	//MAP_reload_bottom_screen();
	//HARDWARE_create_sprite(0,main_sprite_shadow->PLAYER_id_touchmap,main_sprite_shadow->gfx_slot_touchmap,PLAYER_npc->data_size_x,PLAYER_npc->data_size_y,1,0,0,0,0,0,2,0,PLAYER_npc->screen_x_touchmap,PLAYER_npc->screen_y_touchmap);
	//HARDWARE_set_sprite_rotation(0,main_sprite_shadow->PLAYER_id_touchmap,0);
	//HARDWARE_set_sprite_alpha(0,main_sprite_shadow->PLAYER_id_touchmap,1);

	//GLOBAL_main_sprite_input_off=0;
	//HARDWARE_play_music_file(current_mod);
	//CAPTION_unpause();
	//CLOCK_paused=0;

}



//=========================================================================================================================
void start_screen_vbl()
{//=========================================================================================================================


/*
	if(start_screen_ready==1)
	{
		start_screen_vbl_count++;

		if(start_screen_vbl_count>60*((rand()%5)+1))
		{
			start_screen_vbl_count=0;
			//NPC_set_anim_frame_now(mr_cart,(rand()%40));
		}

		if(start_scroll!=current_start_screen*32*8)
		{
			if(start_scroll_dir==RIGHT)
			{start_scroll+=32;if(start_scroll>current_start_screen*32*8)start_scroll=current_start_screen*32*8;}
			if(start_scroll_dir==LEFT)
			{start_scroll-=32;if(start_scroll<current_start_screen*32*8)start_scroll=current_start_screen*32*8;}
		}

		//HARDWARE_infinite_large_scroll_bg_xy(1,3,start_screen_x3,start_screen_y3);
		//HARDWARE_infinite_large_scroll_bg_xy(1,2,start_screen_x2,start_screen_y2);
		//HARDWARE_infinite_large_scroll_bg_xy(1,1,start_screen_x1,start_screen_y1);

		//HARDWARE_infinite_large_scroll_bg_xy(0,2,start_scroll,0);
	}*/
}
//=========================================================================================================================
void start_screen_main()
{//=========================================================================================================================

	//NPC_walk_randomly_around_room_and_stop_no_animation(mr_cart);






/*
	int clickx=0;
	int clicky=0;
	if(TouchScreen.Held)
	{
		clickx=TouchScreen.X;
		clicky=TouchScreen.Y;
		while(TouchScreen.Held&&MAIN_QUIT==false)whilefix();

		if(clickx<55&&clicky>140){current_start_screen--;if(current_start_screen<0){current_start_screen=1;start_scroll=32*8*3;}start_scroll_dir=LEFT;HARDWARE_play_sound("blip",127,44100,0);}
		if(clickx>200&&clicky>140){current_start_screen++;if(current_start_screen>1){current_start_screen=0;start_scroll=-32*8;}start_scroll_dir=RIGHT;HARDWARE_play_sound("blip",127,44100,0);}
		start_screen_set_captions();

	}*/









int changed=0;

	if(BUTTON_RIGHT_PRESSED||BUTTON_R_PRESSED)
	{

		//while((BUTTON_RIGHT_HELD||BUTTON_R_HELD)&&MAIN_QUIT==false)whilefix();

		current_start_screen++;
		changed=1;

		if(current_start_screen>1)
		{
			current_start_screen=0;
			//start_scroll=-32*8;

		}
		//start_scroll_dir=RIGHT;
	}
	else
	if(BUTTON_LEFT_PRESSED||BUTTON_L_PRESSED)
	{

		//while((BUTTON_LEFT_HELD||BUTTON_L_HELD)&&MAIN_QUIT==false)whilefix();

			current_start_screen--;
			changed=1;
			if(current_start_screen<0)
			{
				current_start_screen=1;
				//start_scroll=32*8*3;
			}
			//start_scroll_dir=LEFT;

	}

	if(changed==1)
	{
			selected_item=0;

			HARDWARE_delete_AUX_bg(0);

			HARDWARE_unload_file((void**)&startscreen_palette);
			HARDWARE_unload_file((void**)&startscreen_tileset);
			HARDWARE_unload_file((void**)&startscreen_map);

			if(current_start_screen==0)//status
			{


				delete_stuff_captions();
				make_status_captions();


				startscreen_palette =(short unsigned int*)         HARDWARE_load_file("/startscreen/startscreen_status_Pal.bin");
				startscreen_tileset =(unsigned char*)         HARDWARE_load_file("/startscreen/startscreen_status_Tiles.bin");
				startscreen_map     =(short unsigned int*)         HARDWARE_load_file("/startscreen/startscreen_status_Map.bin");
			}
			else
			if(current_start_screen==1)//stuff
			{


				delete_status_captions();
				make_stuff_captions();




				startscreen_palette =(short unsigned int*)         HARDWARE_load_file("/startscreen/startscreen_stuff_Pal.bin");
				startscreen_tileset =(unsigned char*)         HARDWARE_load_file("/startscreen/startscreen_stuff_Tiles.bin");
				startscreen_map     =(short unsigned int*)        HARDWARE_load_file("/startscreen/startscreen_stuff_Map.bin");
			}


			STARTSCREEN_aspectratio = ((float)((float)(GAME_VIEWPORT_HEIGHT_PIXELS)/1.0f)/192.0f);
			STARTSCREEN_fromx = ((GAME_VIEWPORT_WIDTH_PIXELS-(STARTSCREEN_aspectratio*256.0f))/2);
			STARTSCREEN_fromy = 0;

			HARDWARE_load_AUX_map_to_xy_xy(0,startscreen_map,startscreen_tileset,startscreen_palette,256,192,STARTSCREEN_fromx,STARTSCREEN_fromy,STARTSCREEN_aspectratio,0);




			HARDWARE_play_sound("blip",127,44100,0);

	}




	if(current_start_screen==1)//STUFF
	{
		if(BUTTON_UP_HELD)
		{
			while(BUTTON_UP_HELD)whilefix();

			selected_item--;if(selected_item<0)selected_item=ITEM_items_in_pocket-1;

			delete_stuff_captions();
			make_stuff_captions();


			HARDWARE_play_sound("blip",127,44100,0);
		}
		if(BUTTON_DOWN_HELD)
		{
			while(BUTTON_DOWN_HELD)whilefix();

			selected_item++;if(selected_item>=ITEM_items_in_pocket)selected_item=0;

			delete_stuff_captions();
			make_stuff_captions();

			HARDWARE_play_sound("blip",127,44100,0);
		}
	}

	/*if(current_start_screen==2)//SOUND
	{

		if(BUTTON_UP_PRESSED)
		{
			while(BUTTON_UP_PRESSED&&MAIN_QUIT==false)whilefix();
			mod_selection--;if(mod_selection<0)mod_selection=amt_of_mods;
			HARDWARE_set_sprite_y(0,TEXTANSWER_cursor_sprite_id,2+16*mod_selection);
			//start_screen_set_captions();
		}
		if(BUTTON_DOWN_PRESSED)
		{
			while(BUTTON_DOWN_PRESSED&&MAIN_QUIT==false)whilefix();
			mod_selection++;if(mod_selection>amt_of_mods)mod_selection=0;
			HARDWARE_set_sprite_y(0,TEXTANSWER_cursor_sprite_id,2+16*mod_selection);
			//start_screen_set_captions();
		}
		if(BUTTON_ACTION_HELD)
		{
			while(BUTTON_ACTION_HELD&&MAIN_QUIT==false)whilefix();
			current_mod = mods[mod_selection];
			HARDWARE_stop_music();
			//HARDWARE_play_music_file(current_mod);
			start_screen_set_captions();
		}
	}*/

}
