//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================



#include "../../main.h"



#define RANGE_CITYNeighborAptInsideToOUTSIDECity 17*8,34*8,21*8,35*8
#define RANGE_CITYNeighborAptInsideToNeighborAptBathroom 16*8,19*8,17*8,24*8
#define RANGE_CITYNeighborsAptBathroomToNeighborsAptInside 16*8,8*8,17*8,13*8


#define RANGE_CITYBobsAptInsideToOUTSIDECity 17*8,34*8,21*8,35*8
#define RANGE_CITYBobsAptInsideToBobsAptBathroom 16*8,19*8,17*8,24*8
#define RANGE_CITYBobsBathroomToBobsAptInside 16*8,8*8,17*8,12*8



#define RANGE_CITYAptMainOfficeToOUTSIDECity 33*8,34*8,41*8,35*8
#define RANGE_CITYAptMainOfficeToExerciseRoom 64*8,27*8,68*8,28*8



//========================================================
//CITYYuusAptInside
//========================================================
void bobsgame_CITYBobsAptInside_Map_Load_Function()
{
//RANGE_CITYYuusAptInsideToOUTSIDECity 17*8,34*8,21*8,35*8
//RANGE_CITYYuusAptInsideToYuusAptBathroom 16*8,19*8,17*8,24*8




HARDWARE_create_brightened_palette((int*)GAME_original_SPRITE_PALETTE,(int*)&GAME_temp_SPRITE_PALETTE,0);

HARDWARE_load_sprite_palette((int*)&GAME_temp_SPRITE_PALETTE);///FIX THIS
//HARDWARE_load_sprite_palette(0,(int*)GAME_temp_SPRITE_PALETTE);

}
void bobsgame_CITYBobsAptInside_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}


	PLAYER_npc->MAP_x=42*8;
	PLAYER_npc->MAP_y=42*8;
	//TODO: sleep. eat.

	static NPC* bob_npc=NULL;

	static int stage=0;//0;

		if(bob_npc==NULL)
		{

			if(stage<3)
			NPC_create_npc_xy_feet(&bob_npc,GFX_ADULT_bob,16,40,6*8,12*8-4);
			else
			if(stage<5)
			NPC_create_npc_xy_feet(&bob_npc,GFX_ADULT_bobscary,16,40,6*8,12*8-4);
			else
			NPC_create_npc_xy_feet(&bob_npc,GFX_ADULT_bobscary,16,40,14*8,12*8-4);
			//NPC_create_random_ADULT_xy_feet(&famousguy_npc,11*8,34*8);

			bob_npc->layer=2;
			bob_npc->non_walkable=1;
			NPC_animate_stand_dir(&bob_npc,UP);

			bob_npc->walking_speed = SPEED_FAST;
			bob_npc->AI=0;

			cameraman_target=bob_npc;
			//GLOBAL_main_sprite_input_off=1;
			//GLOBAL_main_sprite_standing=1;



		}
		if(bob_npc!=NULL)
		{

			//if(bob_npc->cycle== 0){if(NPC_walk_to_xy_nohit(&bob_npc,bob_npc->walking_speed,20*8,30*8)==1){bob_npc->cycle++;}}
			//if(bob_npc->cycle== 1){if(NPC_walk_to_xy_nohit(&bob_npc,bob_npc->walking_speed,93*8+4,30*8)==1){bob_npc->cycle++;bob_npc->vbl_timer=0;NPC_animate_set_direction_now(&bob_npc,DOWN);}}
			//if(bob_npc->cycle== 2){if(bob_npc->vbl_timer>120){bob_npc->vbl_timer=0;bob_npc->cycle++;tournament_cycle++;}}


			cameraman_target=bob_npc;



			if(stage==0)
			{
				HARDWARE_play_music("s31",64);
				stage=1;
				if(GLOBAL_text_engine_state==0)
				{
					TEXT_set_sprite_window(0,bob_npc,NULL);

					TEXT_window("<NOCANCEL>Man, I can't believe nobody has thought of this yet!<.>"
								"<BLUE>Tetrid<WHITE> has nothing on this. Nobody's ever seen anything like it!<.>"
								"A brand new puzzle game... It's practically its own genre! A million seller, for sure.<.>"
								"Once those <GRAY>Gantendo<WHITE> guys see it, I'm in.<.>"
								"I can't wait. This has got to be one of the <GREEN>best games ever made.<WHITE><.>"
								"I wonder what I should tell them?<.>"
								"Nah, I won't have to say a thing. The game is all that matters.<.>"
								"It doesn't matter what I say. They couldn't possibly pass up something this fun.<.>"
								"I can see it now... I'll just put it in their hands and that's it.<.>"
								//"Just like he said... If there's a great man there, he'll see it.<.>"
								"Okay, <GREEN>bob,<WHITE> calm down.<.> Don't get too ahead of yourself.<.>"
								"You've still got a long way to go. Work work work!<.>"
								//"I know it's lonely right now, but it'll be alright.<.>"
								//"I'm just hungry. Gotta fight through it. No time for that. This game has to be made.<.>"
								//"I don't care if I starve to death. Something like this, it's too important.<.>"
								"I'll make it. It won't take forever.<.>"
								"This game... it's <GREEN>unstoppable!<WHITE>"
								);


				}
			}

			if(stage==1&&GLOBAL_text_engine_state==0)
			{

				int p=0;
				while(p>=-31&&MAIN_QUIT==false)
				{
					if(TITLESCREEN_vbl_counter%3==0)
					{
						HARDWARE_create_brightened_palette(HARDWARE_map_palette,(int*)&GAME_temp_TILESET_PALETTE,p);
						//HARDWARE_create_brightened_palette(current_touchmap_302_palette,(int*)&tileset_palette_touchmap_302,p);
						//HARDWARE_create_brightened_palette(current_touchmap_1_palette,(int*)&tileset_palette_touchmap_1,p);
						//HARDWARE_create_brightened_palette(GAME_original_SPRITE_PALETTE,(int*)&GAME_temp_SPRITE_PALETTE,p);

						//HARDWARE_load_sprite_palette(1,0,(int*)&GAME_temp_SPRITE_PALETTE);
						//HARDWARE_load_sprite_palette(0,0,(int*)&GAME_temp_SPRITE_PALETTE);
						HARDWARE_load_bg_palette((int*)&GAME_temp_TILESET_PALETTE);
						HARDWARE_reload_bg_textures();



						p--;
					}

					whilefix();
				}
				cameraman_target=PLAYER_npc;
				stage=2;


			}




			if(stage==2)
			{



				//load_demo_screen();

				stage=3;


				load_black_screen();


				static CAPTION* transitioncaption=NULL;
				if(transitioncaption==NULL)CAPTION_make_caption(&transitioncaption, 1, CAPTION_CENTERED_SCREEN, 192/2, 5, "five years later...", FONT_NORMAL_ID, WHITE, CLEAR,5,1);
				while(transitioncaption!=NULL&&MAIN_QUIT==false)
				{
					whilefix();
					CAPTION_main();

					static int volume=64;
					if(TITLESCREEN_vbl_counter%5==0)
					{
						volume-=2;
						if(volume<0)volume=0;
						HARDWARE_set_music_volume(volume);
					}

				}
				HARDWARE_stop_music();








				//=====================================================
				//GAME_temp_SPRITE_PALETTE

					HARDWARE_create_brightened_palette(GAME_original_SPRITE_PALETTE,(int*)GAME_temp_SPRITE_PALETTE,2);

					GAME_temp_SPRITE_PALETTE[1]=HARDWARE_RGB(0,0,0);

					//SET GENERIC SPRITES GRAYSCALE
/*					GAME_temp_SPRITE_PALETTE[GENERIChaireyescolors[0]]		= HARDWARE_RGB(2,2,2);//hair
					GAME_temp_SPRITE_PALETTE[GENERIChaireyescolors[1]]		= HARDWARE_RGB(5,5,5);//hair
					GAME_temp_SPRITE_PALETTE[GENERIChaireyescolors[2]]		= HARDWARE_RGB(9,9,9);//hair
					GAME_temp_SPRITE_PALETTE[GENERIChaireyescolors[3]]		= HARDWARE_RGB(11,11,11);//hair

					GAME_temp_SPRITE_PALETTE[GENERIChaireyescolors[4]]		= HARDWARE_RGB(1,1,1);//eyes

					GAME_temp_SPRITE_PALETTE[GENERICshirtpantsshoescolors[0]] = HARDWARE_RGB(10,10,10);//shirt
					GAME_temp_SPRITE_PALETTE[GENERICshirtpantsshoescolors[1]] = HARDWARE_RGB(15,15,15);//shirt
					GAME_temp_SPRITE_PALETTE[GENERICshirtpantsshoescolors[2]] = HARDWARE_RGB(20,20,20);//shirt
					GAME_temp_SPRITE_PALETTE[GENERICshirtpantsshoescolors[3]] = HARDWARE_RGB(25,25,25);//shirt

					GAME_temp_SPRITE_PALETTE[GENERICshirtpantsshoescolors[4]] = HARDWARE_RGB(3,3,3);//pants
					GAME_temp_SPRITE_PALETTE[GENERICshirtpantsshoescolors[5]] = HARDWARE_RGB(7,7,7);//pants
					GAME_temp_SPRITE_PALETTE[GENERICshirtpantsshoescolors[6]] = HARDWARE_RGB(10,10,10);//pants

					GAME_temp_SPRITE_PALETTE[GENERICshirtpantsshoescolors[7]] = HARDWARE_RGB(1,1,1);//shoes
					GAME_temp_SPRITE_PALETTE[GENERICshirtpantsshoescolors[8]] = HARDWARE_RGB(3,3,3);//shoes
					GAME_temp_SPRITE_PALETTE[GENERICshirtpantsshoescolors[9]] = HARDWARE_RGB(5,5,5);//shoes*/

					HARDWARE_load_sprite_palette((int*)&GAME_temp_SPRITE_PALETTE);///FIX THIS
					//HARDWARE_load_sprite_palette(0,(int*)&GAME_temp_SPRITE_PALETTE);







					PLAYER_npc->gfx=GFX_KID_yuu;

					NPC_animate_stand_dir(&PLAYER_npc,DOWN);


					MAP_change_map(MAP_bobsgame_TOWNYUUUpstairsYuusRoom,16,14);

					MAP_set_map_cam_to_cameraman();


					CLOCK_unknown=0;
					CLOCK_init();


					CLOCK_hour=6;//12+4;
					CLOCK_minute=0;
					CLOCK_day=MONDAY;


					CLOCK_moving=true;
					CLOCK_update_clock();

					CLOCK_paused=0;


					load_bg_pals_based_on_time();
					HARDWARE_reload_bg_textures();


					ZOOMlock=0;
					ZOOMto=2.0f;

					GLOBAL_main_sprite_input_off=0;
					GLOBAL_main_sprite_standing=1;


				unload_black_screen();

				return;



			}


			if(stage==3)
			{


				ITEM_remove(&LunchBag);

				CLOCK_unknown=1;
				CLOCK_paused=1;
				CLOCK_update_clock();

				int x=0;
				for(x=0;x<256;x++)
				{
					int r, g, b;
					r = GAME_temp_TILESET_PALETTE[x]&31;
					g = (GAME_temp_TILESET_PALETTE[x]>>5)&31;
					b = (GAME_temp_TILESET_PALETTE[x]>>10)&31;
					//if(r>3||g>3||b>3)
					{
						r-= 5; if (r < 0) r = 0; if (r > 31) r = 31;
						g+= 10; if (g < 0) g = 0; if (g > 31) g = 31;
						b-= 5; if (b < 0) b = 0; if (b > 31) b = 31;
					}

					GAME_temp_TILESET_PALETTE[x] = HARDWARE_RGB(r, g, b);
				}


				HARDWARE_load_bg_palette((int*)&GAME_temp_TILESET_PALETTE);
				HARDWARE_reload_bg_textures();



				HARDWARE_play_music("scary",64);

				stage=4;

				if(GLOBAL_text_engine_state==0)
				{
					TEXT_set_sprite_window(0,bob_npc,NULL);

					TEXT_window("<NOCANCEL>Heh. heh heh heh.<.>"
								"Heh heh heh heh heh heh heh heh heh heh heh heh <CLEAR>heh heh heh heh heh heh heh heh heh heh heh<CLEAR>"
								"Just a little more, just a little more.<.>"
								"Every day, a little more. A little day for every more.<.>"
								"Almost there. I'm almost there. Right? Right.<.>"
								"Right. Left? Right. Wait. Hold on. What?<.>"
								"Ah. Lost it.<.>"
								"What was it, what was it, what was it?<.>"
								"Oh! Right.<.>"
								"Problem? No problem. Probably.<.>"
								"Ah. Well.<.>Maybe.<.>"
								"Just go. More going. Get going. Keep going. Going good. Good going.<.>"
								"Haha. Hah. hahahaha.<.>"
								"No problem.<.>Shut up! <.>Me?<.>"
								"Fine!<.>I'm fine. I'm fine. FINE. I'm fine. Go go go.<.>"
								"Go <GREEN>bob<WHITE>. Going going gone! Go go gogogogogogo."
								);


				}

			}

			if(stage==4&&GLOBAL_text_engine_state==0)
			{


					GLOBAL_main_sprite_input_off=1;

					int p=0;
					while(p>=-31&&MAIN_QUIT==false)
					{

						{


							HARDWARE_create_brightened_palette((int*)&GAME_temp_TILESET_PALETTE,(int*)&temp_palette,p);
							//HARDWARE_create_brightened_palette(current_touchmap_302_palette,(int*)&tileset_palette_touchmap_302,p);
							//HARDWARE_create_brightened_palette(current_touchmap_1_palette,(int*)&tileset_palette_touchmap_1,p);
							//HARDWARE_create_brightened_palette(GAME_original_SPRITE_PALETTE,(int*)&GAME_temp_SPRITE_PALETTE,p);

							//HARDWARE_load_sprite_palette(1,0,(int*)&GAME_temp_SPRITE_PALETTE);
							//HARDWARE_load_sprite_palette(0,0,(int*)&GAME_temp_SPRITE_PALETTE);
							HARDWARE_load_bg_palette((int*)&temp_palette);
							HARDWARE_reload_bg_textures();


							p--;
						}

						whilefix();
					}


					load_black_screen();


					static CAPTION* transitioncaption=NULL;
					if(transitioncaption==NULL)CAPTION_make_caption(&transitioncaption, 1, CAPTION_CENTERED_SCREEN, 192/2, 5, "after school (three years later)", FONT_NORMAL_ID, WHITE, CLEAR,5,1);
					while(transitioncaption!=NULL&&MAIN_QUIT==false)
					{
						whilefix();
						CAPTION_main();

						static int volume=64;
						if(TITLESCREEN_vbl_counter%5==0)
						{
							volume-=2;
							if(volume<0)volume=0;
							HARDWARE_set_music_volume(volume);
						}

					}
					HARDWARE_stop_music();

					CLOCK_unknown=0;
					CLOCK_paused=0;

					CLOCK_hour=12+3;
					CLOCK_minute=45;
					CLOCK_update_clock();


					MAP_change_map(MAP_bobsgame_TOWNYUUDownstairs,31,10);


					MAP_set_map_cam_to_cameraman();

					ZOOMlock=0;
					ZOOMto=2.0f;

					GLOBAL_main_sprite_input_off=0;
					GLOBAL_main_sprite_standing=1;

					PLAYER_npc->walk_dir=DOWN;
					NPC_animate_stand_dir(&PLAYER_npc, DOWN);

					unload_black_screen();

					stage=5;

					return;


			}

			if(stage==5)
			{

				CLOCK_unknown=0;
				CLOCK_paused=0;
				CLOCK_hour=3;
				CLOCK_minute=33;
				CLOCK_update_clock();
				CLOCK_unknown=1;
				CLOCK_paused=1;
				CLOCK_update_clock();


				HARDWARE_play_music("bobend",64);

				int x=0;
				for(x=0;x<256;x++)
				{
					int r, g, b;
					r = GAME_temp_TILESET_PALETTE[x]&31;
					g = (GAME_temp_TILESET_PALETTE[x]>>5)&31;
					b = (GAME_temp_TILESET_PALETTE[x]>>10)&31;
					//if(r>3||g>3||b>3)
					{
						r+= 10; if (r < 0) r = 0; if (r > 31) r = 31;
						g-= 5; if (g < 0) g = 0; if (g > 31) g = 31;
						b-= 5; if (b < 0) b = 0; if (b > 31) b = 31;
					}

					GAME_temp_TILESET_PALETTE[x] = HARDWARE_RGB(r, g, b);
				}


					int p=-31;
					while(p<-2&&MAIN_QUIT==false)
					{

						{

							HARDWARE_create_brightened_palette((int*)&GAME_temp_TILESET_PALETTE,(int*)&temp_palette,p);
							//if(bottom_screen_on==1)HARDWARE_create_brightened_palette(current_touchmap_302_palette,(int*)&tileset_palette_touchmap_302,p);
							//if(bottom_screen_on==1)HARDWARE_create_brightened_palette(current_touchmap_1_palette,(int*)&tileset_palette_touchmap_1,p);
							//HARDWARE_create_brightened_palette(GAME_original_SPRITE_PALETTE,(int*)&GAME_temp_SPRITE_PALETTE,p);

							//HARDWARE_load_sprite_palette(1,0,(int*)&GAME_temp_SPRITE_PALETTE);
							//HARDWARE_load_sprite_palette(0,0,(int*)&GAME_temp_SPRITE_PALETTE);

							HARDWARE_load_bg_palette((int*)&temp_palette);
							HARDWARE_reload_bg_textures();


							p++;

						}

						whilefix();
					}


				//HARDWARE_load_bg_palette(1,3,(int*)&GAME_temp_TILESET_PALETTE);
				//HARDWARE_load_bg_palette(1,2,(int*)&GAME_temp_TILESET_PALETTE);
				//HARDWARE_load_bg_palette(1,1,(int*)&GAME_temp_TILESET_PALETTE);
				//HARDWARE_load_bg_palette(1,0,(int*)&GAME_temp_TILESET_PALETTE);


				//HARDWARE_play_music("scary",64);

				stage=6;

				if(GLOBAL_text_engine_state==0)
				{
					TEXT_set_sprite_window(0,bob_npc,NULL);

					TEXT_window("<NOCANCEL>Heh heh heh heh<.>heh heh heh heh heh<.>"
								"Heh heh heh heh heh heh heh heh heh heh heh heh <.>heh heh heh heh heh heh heh heh heh heh heh<.>"
								"Heh heh heh heh heh heh heh heh heh heh heh heh heh heh heh heh heh heh heh heh heh heh heh<.>"
								"Heh heh ha ha ha ha ha ha ha ha ha ha ha ha ha ha ha ha ha <HUGE>ha ha ha ha ha ha ha ha ha"
								"ha ha ha ha ha ha ha ha ha ha ha<CLEAR>HA ha hA HA HA HA HA HA <BOB>ha ha ha ha ha ha<CLEAR>"
								"ha ha ha ha ha ha ha ha ha ha ha ha ha<CLEAR> ha ha ha ha ha ha ha ha ha ha ha ha ha ha ha"
								"<CLEAR>ha ha ha ha ha ha ha hahaha ha hahaha hahaha haha hahaha ha hahaha ha ha ha ha ha ha ha ha"
								"<CLEAR>hahaha hahaha ha hahaha hahaha ha hahaha ha haha ha ha haha ha ha ha ha ha ha hahaha"
								"<CLEAR>ha ha ha haha ha ha ha ha ha ha haha ha ha ha haha hah<CLEAR>aha ha ha haha ha ha ha ha ha"
								"<CLEAR>ha ha haha ha ha hahaha hahaha hahahaha haha haha hahaha ha ha ha ha ha ha ha ha ha ha"
								"<PITCH20000><CLEAR>ha ha ha ha ha ha ha hahaha ha hahaha hahaha haha hahaha ha hahaha ha ha ha ha ha ha ha ha"
								"<CLEAR>hahaha hahaha ha hahaha hahaha ha hahaha ha haha ha ha haha ha ha ha ha ha ha hahaha"
								"<CLEAR>ha ha ha haha ha ha ha ha ha ha haha ha ha ha haha hahaha ha ha haha ha ha ha ha ha"
								"<CLEAR>ha ha haha ha ha hahaha hahaha hahahaha haha haha hahaha ha ha ha ha ha ha ha ha ha ha"
								"<CLEAR>ha ha ha ha ha ha ha hahaha ha ha<CLEAR>haha hahaha haha hahaha ha hahaha ha ha ha ha ha ha ha ha"
								"<CLEAR>hahaha hahaha ha hahaha hahaha ha hahaha ha haha ha ha haha ha ha ha ha ha ha hahaha"
								"<PITCH17000><CLEAR>ha ha ha haha ha ha ha ha ha ha haha ha ha ha haha hahaha ha ha haha ha ha ha ha ha"
								"<CLEAR>ha ha ha ha ha ha ha ha<CLEAR>haha ha hahaha hahaha haha hahaha ha hahaha ha ha ha ha ha ha ha ha"
								"<CLEAR>hahaha hahaha ha hahaha hahaha ha hahaha ha haha ha ha haha ha ha ha ha ha ha hahaha"
								"<CLEAR>ha ha ha haha ha ha ha ha ha ha haha ha ha ha haha hahaha ha ha haha ha ha ha ha ha"
								"<CLEAR>ha ha haha ha ha hahaha hahaha hahahaha haha haha hahaha ha ha ha ha ha ha ha ha ha ha"
								"<PITCH15000><CLEAR>ha ha haha ha ha hahaha hahaha <CLEAR>hahahaha haha haha hahaha ha ha ha ha ha ha ha ha ha ha"
								"<CLEAR>ha ha ha ha ha ha ha hahaha ha hahaha hahaha haha hahaha ha hahaha ha ha ha ha ha ha ha ha"
								"<CLEAR>hahaha hahaha ha hahaha hahaha ha hahaha ha haha ha ha haha ha ha ha ha ha ha hahaha"
								"<CLEAR>ha ha ha <CLEAR>haha ha ha ha ha ha ha haha ha ha ha haha hahaha ha ha haha ha ha ha ha ha"
								"<PITCH10000><CLEAR>ha ha haha ha ha hahaha hahaha hahahaha haha haha hahaha ha ha ha ha ha ha ha ha ha ha"
								"<CLEAR>ha ha ha ha ha ha ha hahaha ha hahaha hahaha <CLEAR>haha hahaha ha hahaha ha ha ha ha ha ha ha ha"
								"<CLEAR>hahaha hahaha ha hahaha hahaha ha hahaha ha haha ha ha haha ha ha ha ha ha ha hahaha"
								"<CLEAR>ha ha ha haha ha ha <CLEAR>ha ha ha ha haha ha ha ha haha hahaha ha ha haha ha ha ha ha ha"
								"<CLEAR>ha ha haha ha ha hahaha hahaha hahahaha haha haha hahaha ha ha ha ha ha ha ha ha ha ha<.>"
								"<PITCH32000><NORMAL>Heh heh heh... <DELAY30> Hah.<DELAY30> Eh? <PAUSE>Where was I? <PAUSE>Ah.<.>"
								);
				}


			}

			if(stage==6&&GLOBAL_text_engine_state==0)
			{
				load_demo_screen();
			}



		}




	if(walking_into_door(RANGE_CITYBobsAptInsideToOUTSIDECity))
	{
		//MAP_change_map(MAP_bobsgame_CITYCity,527,15);return;
	}
	if(walking_into_door(RANGE_CITYBobsAptInsideToBobsAptBathroom))
	{
		MAP_change_map(MAP_bobsgame_CITYBobsBathroom,15,11);return;
	}
}
void bobsgame_CITYBobsAptInside_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYBobsAptInside_Map_VBL_Function()
{

}
void bobsgame_CITYBobsAptInside_Map_HBL_Function()
{

}





//========================================================
//CITYBobsBathroom
//========================================================
void bobsgame_CITYBobsBathroom_Map_Load_Function()
{
//RANGE_CITYBobsBathroomToBobsAptInside 16*8,8*8,17*8,12*8
}
void bobsgame_CITYBobsBathroom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

	//TODO: use toilet

	if(walking_into_door(RANGE_CITYBobsBathroomToBobsAptInside))
	{
		MAP_change_map(MAP_bobsgame_CITYBobsAptInside,17,22);return;
	}
}
void bobsgame_CITYBobsBathroom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYBobsBathroom_Map_VBL_Function()
{

}
void bobsgame_CITYBobsBathroom_Map_HBL_Function()
{

}
//========================================================
//CITYNeighborAptInside
//========================================================
void bobsgame_CITYNeighborAptbobsgame_Map_Load_Function()
{
//RANGE_CITYNeighborAptInsideToOUTSIDECity 17*8,34*8,21*8,35*8
//RANGE_CITYNeighborAptInsideToNeighborAptBathroom 16*8,19*8,17*8,24*8
}
void bobsgame_CITYNeighborAptbobsgame_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}
	//TODO: need fat guy neighbor sprite
	static NPC* neighbor_npc = NULL;
	if(neighbor_npc==NULL)
	{
		NPC_create_npc_xy_feet(&neighbor_npc,GFX_ADULT_GENERICbeardbaldingtshirt,16,40,9*8,13*8);
		neighbor_npc->non_walkable=1;
		//neighbor_npc->pushable=1;
		neighbor_npc->layer=3;
		NPC_animate_stand_dir(&neighbor_npc, LEFT);
	}
	else if(neighbor_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&neighbor_npc,30))NPC_stare_at_npc(&neighbor_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&neighbor_npc, LEFT);
		if(ACTION_range_xy_xy(11*8,12*8,15*8,15*8,"Talk To Neighbor"))
		{
			TEXT_set_sprite_window(0,neighbor_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
	if(walking_into_door(RANGE_CITYNeighborAptInsideToOUTSIDECity))
	{
		MAP_change_map(MAP_bobsgame_CITYCity,502,15);return;
	}
	if(walking_into_door(RANGE_CITYNeighborAptInsideToNeighborAptBathroom))
	{
		MAP_change_map(MAP_bobsgame_CITYNeighborsAptBathroom,15,11);return;
	}
}
void bobsgame_CITYNeighborAptbobsgame_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYNeighborAptbobsgame_Map_VBL_Function()
{

}
void bobsgame_CITYNeighborAptbobsgame_Map_HBL_Function()
{

}
//========================================================
//CITYNeighborsAptBathroom
//========================================================
void bobsgame_CITYNeighborsAptBathroom_Map_Load_Function()
{
//RANGE_CITYNeighborsAptBathroomToNeighborsAptInside 16*8,8*8,17*8,13*8
}
void bobsgame_CITYNeighborsAptBathroom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//TODO: use toilet
	if(walking_into_door(RANGE_CITYNeighborsAptBathroomToNeighborsAptInside))
	{
		MAP_change_map(MAP_bobsgame_CITYNeighborAptInside,17,22);return;
	}
}
void bobsgame_CITYNeighborsAptBathroom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYNeighborsAptBathroom_Map_VBL_Function()
{

}
void bobsgame_CITYNeighborsAptBathroom_Map_HBL_Function()
{

}
//========================================================
//CITYAptMainOffice
//========================================================
void bobsgame_CITYAptMainOffice_Map_Load_Function()
{
//RANGE_CITYAptMainOfficeToOUTSIDECity 33*8,34*8,41*8,35*8
//RANGE_CITYAptMainOfficeToExerciseRoom 64*8,27*8,68*8,28*8
}
void bobsgame_CITYAptMainOffice_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

	static NPC* apartmentmanager_npc = NULL;
	if(apartmentmanager_npc==NULL)
	{
		NPC_create_npc_xy_feet(&apartmentmanager_npc,GFX_ADULT_GENERICbeardbaldingtshirt,16,40,9*8,13*8);
		apartmentmanager_npc->non_walkable=1;
		//apartmentmanager_npc->pushable=1;
		apartmentmanager_npc->layer=3;
		NPC_animate_stand_dir(&apartmentmanager_npc, LEFT);
		//TODO: need apartment main office sprite smoking lady
	}
	else if(apartmentmanager_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&apartmentmanager_npc,30))NPC_stare_at_npc(&apartmentmanager_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&apartmentmanager_npc, LEFT);
		if(ACTION_range_xy_xy(11*8,12*8,15*8,15*8,"Talk To Apartment Manager"))
		{
			TEXT_set_sprite_window(0,apartmentmanager_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
		//TODO: rent apartment. get shown exercise room. get shown model.
	}
//need bathroom door locked.
	if(ACTION_range_xy_xy(15*8,21*8,16*8,26*8,"Check Bathroom Door"))
	{
		TEXT_set_sprite_window(0,PLAYER_npc,NULL);
		TEXT_set_sprite_window(1,PLAYER_npc,NULL);
		TEXT_window(""
		);
	}
	if(ACTION_range_xy_xy(64*8,26*8,67*8,27*8,"Check Exercise Room"))
	{
		TEXT_set_sprite_window(0,PLAYER_npc,NULL);
		TEXT_set_sprite_window(1,PLAYER_npc,NULL);
		TEXT_window(""
		);
	}

	if(walking_into_door(RANGE_CITYAptMainOfficeToOUTSIDECity))
	{
		MAP_change_map(MAP_bobsgame_CITYCity,498,39);return;
	}
	//if(walking_into_door(RANGE_CITYAptMainOfficeToExerciseRoom))
	//{
		//cant exercise, maybe
	//}
}
void bobsgame_CITYAptMainOffice_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYAptMainOffice_Map_VBL_Function()
{

}
void bobsgame_CITYAptMainOffice_Map_HBL_Function()
{

}



