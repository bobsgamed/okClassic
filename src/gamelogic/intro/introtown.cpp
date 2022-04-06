//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================




#include "../../main.h"


#define RANGE_INTROOutsideToINTRODownstairs 242*8,85*8,246*8,86*8
#define RANGE_INTROOutsideToINTROToolshed 265*8,57*8,271*8,58*8
#define RANGE_INTROOutsideToINTROFriendsHouse 54*8,85*8,58*8,86*8

#define RANGE_LeftBarrier 1*8,31*8,2*8,47*8
#define RANGE_RightBarrier 451*8,32*8,452*8,47*8

CAPTION* friend_tetrid_caption = NULL;



//========================================================
//INTROTown
//========================================================
void bobsgame_INTROTown_Map_Load_Function()
{
//RANGE_INTROOutsideToINTRODownstairs 242*8,85*8,246*8,86*8
//RANGE_INTROOutsideToINTROToolshed 265*8,57*8,271*8,58*8
//RANGE_INTROOutsideToINTROFriendsHouse 54*8,85*8,58*8,86*8
//RANGE_LeftBarrier 1*8,31*8,2*8,47*8
//RANGE_RightBarrier 451*8,32*8,452*8,47*8


		HARDWARE_play_music("snappy",64);


}

void bobsgame_INTROTown_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}


//birds chirping
//car horns?
//friend outside, on lawn chairs?
//talk to friend hey, kid.


sfx_birds(16);
sfx_carhorns(16);




//animals









//32,72 kid on lawn chair, face down


static NPC* friend_NPC=NULL;
static int tetridchallenge=0;

	if(friend_NPC==NULL){NPC_create_npc_xy_feet(&friend_NPC,GFX_KID_youngfriend, 16, 32, 32*8,71*8+4);friend_NPC->non_walkable=1;NPC_animate_stand_dir(&friend_NPC, DOWN);}


	if(tetridchallenge==0)
	if(ACTION_npc(&friend_NPC,"Talk To Kid")&&GLOBAL_text_engine_state==0)
	{

		TEXT_set_sprite_window(0,PLAYER_npc,NULL);
		TEXT_set_sprite_window(1,friend_NPC,NULL);
		if(battery_quest==11)
		{
			TEXT_window("<NOCANCEL><1>Uh, who are you? Why are you in my backyard?<.>"
						"<0>Hey... Uh... I just moved in a couple houses down. I'm <PURPLE>Yuu!<WHITE><.>"
						"<1>What?<.><HUGE>MOOOOOOOOM!!! There's a crazy guy in our backyard!<NORMAL><.>"
						"<0>I mean.. my name.. it's <PURPLE>Yuu<WHITE>.<.>"
						"<1>Oh. Uh.. Nice to meet.. <PURPLE>Yuu<WHITE>?<.>Wow, that's weird.<.>"
						"<0>Yeah, I know.<.>Hey, um.. Did you want to play some <BLUE>GameToy<WHITE> with me?<.>"
						"<1>Some what?<.><BLUE>GameToy<WHITE>? Yuu means the old one?<.>"
						"<1>Man, that thing is ancient.<.>"
						"<0>I... Uh... Well.. My mom said...<.>"
						"<0>Umm..<.>"
						"<1>Really, though. <BLUE>GameToy?<WHITE><.> Doesn't <PURPLE>Yuu<WHITE> have anything better?<.>"
						"<0>No.. My brother has some newer games, but he's always playing them.<.>"
						"<1>Sounds like my sister. Actually.. Come to think of it, I might have one of those somewhere.<.>"
						"<1>No, wait. I have the <BLUE>GameToy Colors<WHITE>. It's been a long time since I've played it.<.>"
						"<1>What games does <PURPLE>Yuu<WHITE> have?<.>"
						"<0>Is there more than one?<.>"
						"<1>Good point. <BLUE>Tetrid<WHITE>, right?<.>"
						"<1>Hey, did <PURPLE>Yuu<WHITE> ever beat it?<.>"
						"<1>I heard it's got a cool ending.. Man, I always did want to see that.<.>"
						"<0>Yeah, it's easy!<.>"
						"<1>Yeah, right. That game is impossible! I tried for years.<.>"
						"<0>I bet I can do it.<.>"
						"<1><PURPLE>Yuu<WHITE> wants to bet? Alright. How about this.<.><PURPLE>Yuu<WHITE> beats <BLUE>Tetrid<WHITE>, and I'll give <PURPLE>Yuu<WHITE> my old <BLUE>GameToy Colors.<WHITE><.>"
						"<0>Deal.<.>"
						"<1>Alright, let's see this."
				);
			}
			else
		{
			TEXT_window("<NOCANCEL><1>Uh, who are you? Why are you in my backyard?<.>"
						"<0>Hey... Uh... I just moved in a couple houses down. I'm <PURPLE>Yuu!<WHITE><.>"
						"<1>What?<.><HUGE>MOOOOOOOOM!!! There's a crazy guy in our backyard!<NORMAL><.>"
						"<0>I mean.. my name.. it's <PURPLE>Yuu<WHITE>.<.>"
						"<1>Oh. Uh.. Nice to meet.. <PURPLE>Yuu<WHITE>?<.>Wow, that's weird.<.>"
						"<0>Yeah, I know.<.>Hey, um.. Did you want to play some <BLUE>GameToy<WHITE> with me?<.>"
						"<1>Some what?<.><BLUE>GameToy<WHITE>? Yuu means the old one?<.>"
						"<1>Man, that thing is ancient.<.>"
						"<0>I... Uh... Well.. My mom said...<.>"
						"<0>Umm..<.>"
						"<0><SMALL><GRAY>My uncle owns an amusement park?<WHITE><NORMAL><.>"
						"<1>Wow, really?! That's awesome! Hey, I think we're going to be friends!<.>"
						"<1>Really, though. <BLUE>GameToy?<WHITE><.> Doesn't <PURPLE>Yuu<WHITE> have anything better?<.>"
						"<0>No.. My brother has some newer games, but he's always playing them.<.>"
						"<1>Sounds like my sister. Actually.. Come to think of it, I might have one of those somewhere.<.>"
						"<1>No, wait. I have the <BLUE>GameToy Colors<WHITE>. It's been a long time since I've played it.<.>"
						"<1>What games does <PURPLE>Yuu<WHITE> have?<.>"
						"<0>Is there more than one?<.>"
						"<1>Good point. <BLUE>Tetrid<WHITE>, right?<.>"
						"<1>Hey, did <PURPLE>Yuu<WHITE> ever beat it?<.>"
						"<1>I heard it's got a cool ending.. Man, I always did want to see that.<.>"
						"<0>Yeah, it's easy!<.>"
						"<1>Yeah, right. That game is impossible! I tried for years.<.>"
						"<0>I bet I can do it.<.>"
						"<1><PURPLE>Yuu<WHITE> wants to bet? Alright. How about this.<.><PURPLE>Yuu<WHITE> beats <BLUE>Tetrid<WHITE>, and I'll give <PURPLE>Yuu<WHITE> my old <BLUE>GameToy Colors.<WHITE><.>"
						"<0>Deal.<.>"
						"<1>Alright, let's see this."
				);
			}

			tetridchallenge=1;


	}

	if(tetridchallenge==1&&GLOBAL_text_engine_state==0)
	{
		HARDWARE_play_sound("gtbling",127,44100,0);
		tetridchallenge=2;
		GLOBAL_main_sprite_input_off=1;
		GLOBAL_main_sprite_actions_off=1;
		load_gametoy_fullscreen();
		GAME_playing_tetrid=1;
	}


	if(tetridchallenge==2&&GAME_playing_tetrid==1&&GLOBAL_text_engine_state==0)
	{
		//text_update_sprite_window_gfx(0,PLAYER_npc,NULL);
		//text_update_sprite_window_gfx(1,friend_NPC,NULL);
		//text_window("<1><PURPLE>Yuu<WHITE> totally sucks.");

	}


	if(tetridchallenge==2&&GAME_playing_tetrid==0&&GLOBAL_text_engine_state==0)
	{

		tetridchallenge=3;



		GLOBAL_main_sprite_input_off=0;
		GLOBAL_main_sprite_actions_off=0;

		unload_gametoy_fullscreen();


		TEXT_set_sprite_window(0,PLAYER_npc,NULL);
		TEXT_set_sprite_window(1,friend_NPC,NULL);
		TEXT_window("<NOCANCEL><1><PURPLE>Yuu..<WHITE> actually.. did it.<.>"
					"That's... incredible...<.>"
					"<0>Oh come on, it wasn't that hard.<.>"
					"<1>No, really.<.>"
					"I heard this rumor...<.>"
					"The programmer couldn't even beat it.<.>"
					"<PURPLE>Yuu<WHITE> seriously just beat the person who made it.<.>"
					"<0>What? Why would they do that?!<.>"
					"<1>Don't ask me! Maybe they thought it was funny.<.>"
					"<0>...<.>"
					"<1>Seriously, <PURPLE>Yuu<WHITE> wasn't kidding. <PURPLE>Yuu<WHITE> is awesome at games.<.>"
					"<0>I'm alright.<.>"
					"<1>No, there's something strange about <PURPLE>Yuu.<WHITE><.>"
					"The way <PURPLE>Yuu<WHITE> plays like that...<.>"
					"It's like <PURPLE>Yuu<WHITE> was born with a <GREEN>special power<WHITE> or something.<.>"
					"<0>No, just this <BLUE>GameToy.<WHITE><.>"
					"<1>...<.>"
					".............<.>"
					"Uhhh.....<.>"
					"<BOB>What?!<SHAKE1SEC><NORMAL><.>"
					);

	}


	if(tetridchallenge==3&&GLOBAL_text_engine_state==0)
	{

		//fade out

		//change map

		//bob cutscene

		int p=0;
		while(p>=-31&&MAIN_QUIT==false)
		{

			{


				HARDWARE_create_brightened_palette(HARDWARE_map_palette,(int*)&GAME_temp_TILESET_PALETTE,p);
				//HARDWARE_create_brightened_palette(current_touchmap_302_palette,(int*)&tileset_palette_touchmap_302,p);
				//HARDWARE_create_brightened_palette(current_touchmap_1_palette,(int*)&tileset_palette_touchmap_1,p);
				//HARDWARE_create_brightened_palette(GAME_original_SPRITE_PALETTE,(int*)&GAME_temp_SPRITE_PALETTE,p);

				//HARDWARE_load_sprite_palette(1,0,(int*)&GAME_temp_SPRITE_PALETTE);
				//HARDWARE_load_sprite_palette(0,0,(int*)&GAME_temp_SPRITE_PALETTE);
				HARDWARE_load_bg_palette((int*)&GAME_temp_TILESET_PALETTE);
				HARDWARE_reload_bg_textures();
				//HARDWARE_load_bg_palette(1,2,(int*)&GAME_temp_TILESET_PALETTE);
				//HARDWARE_load_bg_palette(1,1,(int*)&GAME_temp_TILESET_PALETTE);
				//HARDWARE_load_bg_palette(1,0,(int*)&GAME_temp_TILESET_PALETTE);
				//HARDWARE_load_bg_palette(0,3,(int*)&tileset_palette_touchmap_302);
				//HARDWARE_load_bg_palette(0,1,(int*)&tileset_palette_touchmap_1);

				p--;
			}

			whilefix();
		}


		GLOBAL_main_sprite_input_off=1;
		//PLAYER_npc->gfx_filename=bob;
		MAP_change_map(MAP_bobsgame_CITYBobsAptInside,32,9);

		return;



	}




	//if(walking_into_door(RANGE_INTROOutsideToINTRODownstairs))
	//{
		//MAP_change_map(MAP_bobsgame_INTRODownstairs,32,9);return;




	//}

	if(ACTION_range_xy_xy(RANGE_INTROOutsideToINTRODownstairs,"Go back inside."))
	{

		if(GLOBAL_text_engine_state==0)
		{
			TEXT_set_sprite_window(0,PLAYER_npc,NULL);
			TEXT_window("No way! I finally got out here! I'm not getting stuck with unpacking more boxes.");
		}
	}

	//if(walking_into_door(RANGE_INTROOutsideToINTROToolshed))
	//{
	//locked



	if(ACTION_range_xy_xy(RANGE_INTROOutsideToINTROToolshed,"Check out the shed."))
	{

		if(GLOBAL_text_engine_state==0)
		{
			TEXT_set_sprite_window(0,PLAYER_npc,NULL);
			TEXT_window("This hasn't been opened in awhile. It's rusted shut... <.>I think I need something for that.");
		}
	}



	if(ACTION_range_xy_xy(RANGE_INTROOutsideToINTROFriendsHouse,"Enter stranger's home without permission."))
	{

		if(GLOBAL_text_engine_state==0)
		{
			TEXT_set_sprite_window(0,PLAYER_npc,NULL);
			TEXT_window("I totally would, but he's right there.<.>I should at least wait until he's not around before I steal whatever he keeps in jars.");
		}
	}

	static int zap_left=0;
	static int zap_right=0;

	static NPC* electricshock_NPC=NULL;

	if(walking_into_door(RANGE_LeftBarrier))
	{
	//knock back to 10,38 very fast play bzzzap

		zap_left=1;

	}


	if(zap_left==1)
	{
		static int count=0;
		if(count==0)
		{
			HARDWARE_play_sound("zap",127,44100,0);
			HARDWARE_play_sound("zap",127,35000,0);
			if(electricshock_NPC==NULL)NPC_create_npc(&electricshock_NPC,GFX_MISC_electricshock,64,64,PLAYER_npc->MAP_x-16,PLAYER_npc->MAP_y-14);
			if(electricshock_NPC!=NULL)electricshock_NPC->layer=1;
            if(electricshock_NPC!=NULL)electricshock_NPC->alpha=127;
		}
		if(count<500&&timer_var%2==0)
		{
			count++;
			count++;
			if(NPC_check_hit_move_pixel(&PLAYER_npc,RIGHT)==true){cameraman->MAP_x++;}
			if(NPC_check_hit_move_pixel(&PLAYER_npc,RIGHT)==true){cameraman->MAP_x++;}

			if(electricshock_NPC!=NULL)NPC_animate_cycle_through_frames_now(&electricshock_NPC,5);
			if(electricshock_NPC!=NULL)electricshock_NPC->MAP_x=PLAYER_npc->MAP_x-16;
			if(electricshock_NPC!=NULL)electricshock_NPC->MAP_y=PLAYER_npc->MAP_y-14;
			//if(NPC_check_hit_move_pixel(&PLAYER_npc,hit_direction_y)==true){if(hit_direction_y==UP)cameraman->MAP_y--;else cameraman->MAP_y++;}
		}
		if(count>=500)
		{
			if(electricshock_NPC!=NULL)NPC_delete_npc(&electricshock_NPC);
			TEXT_set_sprite_window(0,PLAYER_npc,NULL);
			TEXT_window("<NOCANCEL><HUGE>OWWWWWWWW!<SHAKE1SEC><.><NORMAL>Holy crap... I can't believe they sell this thing.<.>I totally have to get my brother one.");
			count=0;
			zap_left=0;
		}
	}

	if(walking_into_door(RANGE_RightBarrier))
	{
		//knock back to 441, 38
		zap_right=1;
	}


	if(zap_right==1)
	{
		static int count=0;
		if(count==0)
		{
			HARDWARE_play_sound("zap",127,44100,0);
			HARDWARE_play_sound("zap",127,35000,0);
			if(electricshock_NPC==NULL)NPC_create_npc(&electricshock_NPC,GFX_MISC_electricshock,64,64,PLAYER_npc->MAP_x-16,PLAYER_npc->MAP_y-14);
			if(electricshock_NPC!=NULL)electricshock_NPC->layer=1;
            if(electricshock_NPC!=NULL)electricshock_NPC->alpha=127;

		}
		if(count<500&&timer_var%2==0)
		{
			count++;
			count++;
			if(NPC_check_hit_move_pixel(&PLAYER_npc,LEFT)==true){cameraman->MAP_x--;}
			if(NPC_check_hit_move_pixel(&PLAYER_npc,LEFT)==true){cameraman->MAP_x--;}

			if(electricshock_NPC!=NULL)NPC_animate_cycle_through_frames_now(&electricshock_NPC,5);
			if(electricshock_NPC!=NULL)electricshock_NPC->MAP_x=PLAYER_npc->MAP_x-16;
			if(electricshock_NPC!=NULL)electricshock_NPC->MAP_y=PLAYER_npc->MAP_y-14;
			//if(NPC_check_hit_move_pixel(&PLAYER_npc,hit_direction_y)==true){if(hit_direction_y==UP)cameraman->MAP_y--;else cameraman->MAP_y++;}
		}
		if(count>=500)
		{
			if(electricshock_NPC!=NULL)NPC_delete_npc(&electricshock_NPC);
			TEXT_set_sprite_window(0,PLAYER_npc,NULL);
			TEXT_window("<NOCANCEL><HUGE>OWWWWWWWW!<SHAKE1SEC><.><NORMAL>Holy crap... I can't believe they sell this thing.<.>I totally have to get my brother one.");
			count=0;
			zap_right=0;
		}
	}











}
void bobsgame_INTROTown_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_INTROTown_Map_VBL_Function()
{

}

void bobsgame_INTROTown_Map_HBL_Function()
{

}



