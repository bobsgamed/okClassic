//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================



#include "../../main.h"


#define RANGE_CITYMuseumLobbyToOUTSIDECityLeft 8*8,24*8,14*8,25*8
#define RANGE_CITYMuseumLobbyToOUTSIDECityRight 16*8,24*8,22*8,25*8
#define RANGE_CITYMuseumLobbyToExhibit 41*8,10*8,49*8,11*8
#define RANGE_CITYMuseumLobbyToGiftShop 1*8,16*8,2*8,21*8
#define RANGE_CITYMuseumExhibitToLobby 67*8,56*8,75*8,57*8
#define RANGE_CITYMuseumExhibitToGiftShop 4*8,56*8,12*8,57*8
#define RANGE_CITYMuseumGiftShopToExhibit 4*8,9*8,12*8,10*8
#define RANGE_CITYMuseumGiftShopToLobby 27*8,16*8,28*8,21*8


//========================================================
//CITYMuseumLobby
//========================================================
void bobsgame_CITYMuseumLobby_Map_Load_Function()
{
//RANGE_CITYMuseumLobbyToOUTSIDECityLeft 8*8,24*8,14*8,25*8
//RANGE_CITYMuseumLobbyToOUTSIDECityRight 16*8,24*8,22*8,25*8
//RANGE_CITYMuseumLobbyToExhibit 41*8,10*8,49*8,11*8
//RANGE_CITYMuseumLobbyToGiftShop 1*8,16*8,2*8,21*8
}
void bobsgame_CITYMuseumLobby_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}
//28,13 down clerk
	static NPC* museumclerk_npc = NULL;
	if(museumclerk_npc==NULL)
	{
		NPC_create_random_ADULT_xy_feet(&museumclerk_npc,28*8+2,13*8-6);
		//NPC_create_npc_xy_feet(&museumclerk_npc,securityguard,16,40,28*8,13*8);
		museumclerk_npc->non_walkable=1;
		museumclerk_npc->layer=3;
		NPC_animate_stand_dir(&museumclerk_npc,DOWN);
		museumclerk_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		museumclerk_npc->walk_dir=museumclerk_npc->anim_dir;
		//NPC_animate_increment_direction_frame_now(&museumclerk_npc, museumclerk_npc->anim_direction);
	}
	if(museumclerk_npc!=NULL)
	{
		//if(NPC_in_range_of_npc_amt(&PLAYER_npc,museumclerk_npc,15))NPC_stare_at_npc(&museumclerk_npc,PLAYER_npc);
		//else NPC_animate_set_direction_now(&museumclerk_npc, museumclerk_npc->walking_direction);
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&museumclerk_npc,35))NPC_stare_at_npc(&museumclerk_npc,&PLAYER_npc);
		else
		{
			if(museumclerk_npc->AI==0){if(museumclerk_npc->vbls>200){if(r(4)==0){museumclerk_npc->AI=1+r(3);}else{museumclerk_npc->vbls=0;NPC_animate_stand_dir(&museumclerk_npc, museumclerk_npc->walk_dir);if(museumclerk_npc->anim_frame_count!=0){museumclerk_npc->anim_frame_count=3;NPC_animate(&museumclerk_npc);}}}}
			if(museumclerk_npc->AI==1){if(museumclerk_npc->walk_dir==UP||museumclerk_npc->walk_dir==DOWN)NPC_animate_stand_dir(&museumclerk_npc,LEFT);else NPC_animate_stand_dir(&museumclerk_npc,UP);museumclerk_npc->vbls=r(120);museumclerk_npc->AI=0;}
			if(museumclerk_npc->AI==2){if(museumclerk_npc->walk_dir==UP||museumclerk_npc->walk_dir==DOWN)NPC_animate_stand_dir(&museumclerk_npc,RIGHT);else NPC_animate_stand_dir(&museumclerk_npc,DOWN);museumclerk_npc->vbls=r(120);museumclerk_npc->AI=0;}
			if(museumclerk_npc->AI==3){NPC_animate(&museumclerk_npc);museumclerk_npc->vbls=r(120);museumclerk_npc->AI=0;}
		}
		if(ACTION_range_xy_xy(26*8,14*8,30*8,15*8,"Buy Art Exhibit Pass"))
		{
			TEXT_set_sprite_window(0,museumclerk_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("" //?
			);
		}
	}
	static NPC* museumclerk2_npc = NULL;
	if(museumclerk2_npc==NULL)
	{
		NPC_create_random_ADULT_xy_feet(&museumclerk2_npc,21*8,13*8-6);
		//NPC_create_npc_xy_feet(&museumclerk2_npc,securityguard,16,40,28*8,13*8);
		museumclerk2_npc->non_walkable=1;
		museumclerk2_npc->layer=3;
		NPC_animate_stand_dir(&museumclerk2_npc,DOWN);
		museumclerk2_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		museumclerk2_npc->walk_dir=museumclerk2_npc->anim_dir;
		//NPC_animate_increment_direction_frame_now(&museumclerk2_npc, museumclerk2_npc->anim_direction);
	}
	if(museumclerk2_npc!=NULL)
	{
		//if(NPC_in_range_of_npc_amt(&PLAYER_npc,museumclerk2_npc,15))NPC_stare_at_npc(&museumclerk2_npc,PLAYER_npc);
		//else NPC_animate_set_direction_now(&museumclerk2_npc, museumclerk2_npc->walking_direction);
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&museumclerk2_npc,35))NPC_stare_at_npc(&museumclerk2_npc,&PLAYER_npc);
		else
		{
			if(museumclerk2_npc->AI==0){if(museumclerk2_npc->vbls>200){if(r(4)==0){museumclerk2_npc->AI=1+r(3);}else{museumclerk2_npc->vbls=0;NPC_animate_stand_dir(&museumclerk2_npc, museumclerk2_npc->walk_dir);if(museumclerk2_npc->anim_frame_count!=0){museumclerk2_npc->anim_frame_count=3;NPC_animate(&museumclerk2_npc);}}}}
			if(museumclerk2_npc->AI==1){if(museumclerk2_npc->walk_dir==UP||museumclerk2_npc->walk_dir==DOWN)NPC_animate_stand_dir(&museumclerk2_npc,LEFT);else NPC_animate_stand_dir(&museumclerk2_npc,UP);museumclerk2_npc->vbls=r(120);museumclerk2_npc->AI=0;}
			if(museumclerk2_npc->AI==2){if(museumclerk2_npc->walk_dir==UP||museumclerk2_npc->walk_dir==DOWN)NPC_animate_stand_dir(&museumclerk2_npc,RIGHT);else NPC_animate_stand_dir(&museumclerk2_npc,DOWN);museumclerk2_npc->vbls=r(120);museumclerk2_npc->AI=0;}
			if(museumclerk2_npc->AI==3){NPC_animate(&museumclerk2_npc);museumclerk2_npc->vbls=r(120);museumclerk2_npc->AI=0;}
		}
		if(ACTION_range_xy_xy(19*8,14*8,23*8,15*8,"Talk To Museum Clerk"))
		{
			TEXT_set_sprite_window(0,museumclerk2_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("" //?
			);
		}
	}

//TODO: need museum curator guy

//TODO: need a crowd of people waiting for the event to open.
//TODO: museum curator guy removes the chain and shadow, everyone goes in.
//TODO: need a sign outdoors that says its going to be open on a certain day of the week at a certain time, get your tickets before it starts
//45,12 down museum guy
	static NPC* museumticketguy_npc = NULL;
	if(museumticketguy_npc==NULL)
	{
		NPC_create_random_ADULT_xy_feet(&museumticketguy_npc,45*8,12*8);
		//NPC_create_npc_xy_feet(&museumticketguy_npc,securityguard,16,40,7*8,27*8);
		museumticketguy_npc->non_walkable=1;
		museumticketguy_npc->layer=2;
		NPC_animate_stand_dir(&museumticketguy_npc,DOWN);
		museumticketguy_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		museumticketguy_npc->walk_dir=museumticketguy_npc->anim_dir;
		//NPC_animate_increment_direction_frame_now(&museumticketguy_npc, museumticketguy_npc->anim_direction);
	}
	if(museumticketguy_npc!=NULL)
	{
		//if(NPC_in_range_of_npc_amt(&PLAYER_npc,museumticketguy_npc,15))NPC_stare_at_npc(&museumticketguy_npc,PLAYER_npc);
		//else NPC_animate_set_direction_now(&museumticketguy_npc, museumticketguy_npc->walking_direction);
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&museumticketguy_npc,15))NPC_stare_at_npc(&museumticketguy_npc,&PLAYER_npc);
		else
		{
			if(museumticketguy_npc->AI==0){if(museumticketguy_npc->vbls>200){if(r(4)==0){museumticketguy_npc->AI=1+r(3);}else{museumticketguy_npc->vbls=0;NPC_animate_stand_dir(&museumticketguy_npc, museumticketguy_npc->walk_dir);if(museumticketguy_npc->anim_frame_count!=0){museumticketguy_npc->anim_frame_count=3;NPC_animate(&museumticketguy_npc);}}}}
			if(museumticketguy_npc->AI==1){if(museumticketguy_npc->walk_dir==UP||museumticketguy_npc->walk_dir==DOWN)NPC_animate_stand_dir(&museumticketguy_npc,LEFT);else NPC_animate_stand_dir(&museumticketguy_npc,UP);museumticketguy_npc->vbls=r(120);museumticketguy_npc->AI=0;}
			if(museumticketguy_npc->AI==2){if(museumticketguy_npc->walk_dir==UP||museumticketguy_npc->walk_dir==DOWN)NPC_animate_stand_dir(&museumticketguy_npc,RIGHT);else NPC_animate_stand_dir(&museumticketguy_npc,DOWN);museumticketguy_npc->vbls=r(120);museumticketguy_npc->AI=0;}
			if(museumticketguy_npc->AI==3){NPC_animate(&museumticketguy_npc);museumticketguy_npc->vbls=r(120);museumticketguy_npc->AI=0;}
		}
		if(ACTION_npc(&museumticketguy_npc,"Show Art Exhibit Pass"))
		{
			TEXT_set_sprite_window(0,museumticketguy_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("" //?
			);
		}
	}
//TODO: need snobby art people with berets? in all black hehe
//people coming out of gift shop and leaving
	int c=0;
	static NPC* museumexiting_npcs[6] = {NULL,NULL,NULL,NULL,NULL,NULL};
	static int last_clock=0;
	for(c=0;c<6;c++)
	{
		if(museumexiting_npcs[c]==NULL&&CLOCK_minute%4==0&&CLOCK_minute!=last_clock&&CLOCK_second%35==0)
		{
			last_clock=CLOCK_minute;
			NPC_create_random_ADULT_xy_feet(&museumexiting_npcs[c],2*8,20*8);
			museumexiting_npcs[c]->non_walkable=1;
			museumexiting_npcs[c]->AI=r(2);
			museumexiting_npcs[c]->walking_speed=SPEED_NORMAL+r(SPEED_SLOW-SPEED_FASTEST);
			museumexiting_npcs[c]->ignore_fx_layer=1;
			NPC_animate_stand_dir(&museumexiting_npcs[c], RIGHT);
		}
		if(museumexiting_npcs[c]!=NULL)
		{
			if(museumexiting_npcs[c]->AI== 0)if(NPC_walk_to_xy_LR_to_UD(&museumexiting_npcs[c],museumexiting_npcs[c]->walking_speed, 11*8,23*8)==1){NPC_delete_npc(&museumexiting_npcs[c]);}
			if(museumexiting_npcs[c]->AI== 1)if(NPC_walk_to_xy_LR_to_UD(&museumexiting_npcs[c],museumexiting_npcs[c]->walking_speed, 19*8,23*8)==1){NPC_delete_npc(&museumexiting_npcs[c]);}
		}
	}
	if(walking_into_door(RANGE_CITYMuseumLobbyToOUTSIDECityLeft))
	{
		MAP_change_map(MAP_bobsgame_CITYCity,1182,38);return;
	}
	if(walking_into_door(RANGE_CITYMuseumLobbyToOUTSIDECityRight))
	{
		MAP_change_map(MAP_bobsgame_CITYCity,1190,38);return;
	}
	if(walking_into_door(RANGE_CITYMuseumLobbyToExhibit))
	{
		MAP_change_map(MAP_bobsgame_CITYMuseumExhibit,70,55);return;
		//TODO: need ticket
		//maybe once completed museum tour, can go anywhere
	}
	if(walking_into_door(RANGE_CITYMuseumLobbyToGiftShop))
	{
		MAP_change_map(MAP_bobsgame_CITYMuseumGiftShop,25,19);return;
		//TODO: can probably go in here. cant get into exhibit from gift shop. one way. maybe make this one way.
	}
}
void bobsgame_CITYMuseumLobby_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYMuseumLobby_Map_VBL_Function()
{

}
void bobsgame_CITYMuseumLobby_Map_HBL_Function()
{

}
//========================================================
//CITYMuseumExhibit
//========================================================
void bobsgame_CITYMuseumExhibit_Map_Load_Function()
{
//RANGE_CITYMuseumExhibitToLobby 67*8,56*8,75*8,57*8
//RANGE_CITYMuseumExhibitToGiftShop 4*8,56*8,12*8,57*8
}
void bobsgame_CITYMuseumExhibit_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}
//TODO: need art people standing around
//TODO: need controlled event, crowd stands around
//TODO: security guard at 6,16 down, burglars after the jewel?
//TODO: need murmur
//71,42 right
//71,28 right
//70,18 up
//59,18 up
//48,18 up
//37,18 up
//36,27 left
//36,42 left
//47,49 up
//60,49 up

//36,53
//23,53
//23,42 right
//23,27 right
//15.21 up
//8,27 left
//8,42 left
//8,55 down door

	int c=0;
	static NPC* artpeople_npcs[20] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	static int last_clock=0;
	for(c=0;c<20;c++)
	{
		if(artpeople_npcs[c]==NULL&&CLOCK_second%20==0&&CLOCK_second!=last_clock)
		{
			last_clock=CLOCK_second;
			//if(r(2)==0)NPC_create_random_ADULT_xy_feet(&artpeople_npcs[c],26*8,46*8);
			//else
			NPC_create_random_ADULT_xy_feet(&artpeople_npcs[c],71*8,56*8);
			artpeople_npcs[c]->non_walkable=1;
			artpeople_npcs[c]->AI=1+r(11);
			artpeople_npcs[c]->walking_speed=SPEED_NORMAL+r(SPEED_SLOW-SPEED_FASTEST);
			//artpeople_npcs[c]->ignore_fx_layer=1;
			NPC_animate_stand_dir(&artpeople_npcs[c], UP);
		}
		if(artpeople_npcs[c]!=NULL)
		{
			if(artpeople_npcs[c]->AI== 0)if(artpeople_npcs[c]->vbls>200)artpeople_npcs[c]->AI=1+r(11);
			if(artpeople_npcs[c]->AI== 1)if(NPC_walk_to_xy_intelligenthit_pushothers(&artpeople_npcs[c],artpeople_npcs[c]->walking_speed, 71*8,42*8)==1){artpeople_npcs[c]->vbls=r(100);artpeople_npcs[c]->AI=0;NPC_animate_stand_dir(&artpeople_npcs[c], RIGHT);}
			if(artpeople_npcs[c]->AI== 2)if(NPC_walk_to_xy_intelligenthit_pushothers(&artpeople_npcs[c],artpeople_npcs[c]->walking_speed, 71*8,28*8)==1){artpeople_npcs[c]->vbls=r(100);artpeople_npcs[c]->AI=0;NPC_animate_stand_dir(&artpeople_npcs[c], RIGHT);}
			if(artpeople_npcs[c]->AI== 3)if(NPC_walk_to_xy_intelligenthit_pushothers(&artpeople_npcs[c],artpeople_npcs[c]->walking_speed, 70*8,18*8)==1){artpeople_npcs[c]->vbls=r(100);artpeople_npcs[c]->AI=0;NPC_animate_stand_dir(&artpeople_npcs[c], UP);}
			if(artpeople_npcs[c]->AI== 4)if(NPC_walk_to_xy_intelligenthit_pushothers(&artpeople_npcs[c],artpeople_npcs[c]->walking_speed, 59*8,18*8)==1){artpeople_npcs[c]->vbls=r(100);artpeople_npcs[c]->AI=0;NPC_animate_stand_dir(&artpeople_npcs[c], UP);}
			if(artpeople_npcs[c]->AI== 5)if(NPC_walk_to_xy_intelligenthit_pushothers(&artpeople_npcs[c],artpeople_npcs[c]->walking_speed, 48*8,18*8)==1){artpeople_npcs[c]->vbls=r(100);artpeople_npcs[c]->AI=0;NPC_animate_stand_dir(&artpeople_npcs[c], UP);}
			if(artpeople_npcs[c]->AI== 6)if(NPC_walk_to_xy_intelligenthit_pushothers(&artpeople_npcs[c],artpeople_npcs[c]->walking_speed, 37*8,18*8)==1){artpeople_npcs[c]->vbls=r(100);artpeople_npcs[c]->AI=0;NPC_animate_stand_dir(&artpeople_npcs[c], UP);}
			if(artpeople_npcs[c]->AI== 7)if(NPC_walk_to_xy_intelligenthit_pushothers(&artpeople_npcs[c],artpeople_npcs[c]->walking_speed, 36*8,27*8)==1){artpeople_npcs[c]->vbls=r(100);artpeople_npcs[c]->AI=0;NPC_animate_stand_dir(&artpeople_npcs[c], LEFT);}
			if(artpeople_npcs[c]->AI== 8)if(NPC_walk_to_xy_intelligenthit_pushothers(&artpeople_npcs[c],artpeople_npcs[c]->walking_speed, 36*8,42*8)==1){artpeople_npcs[c]->vbls=r(100);artpeople_npcs[c]->AI=0;NPC_animate_stand_dir(&artpeople_npcs[c], LEFT);}
			if(artpeople_npcs[c]->AI== 9)if(NPC_walk_to_xy_intelligenthit_pushothers(&artpeople_npcs[c],artpeople_npcs[c]->walking_speed, 47*8,49*8)==1){artpeople_npcs[c]->vbls=r(100);artpeople_npcs[c]->AI=0;NPC_animate_stand_dir(&artpeople_npcs[c], UP);}
			if(artpeople_npcs[c]->AI==10)if(NPC_walk_to_xy_intelligenthit_pushothers(&artpeople_npcs[c],artpeople_npcs[c]->walking_speed, 60*8,49*8)==1){artpeople_npcs[c]->vbls=r(100);artpeople_npcs[c]->AI=0;NPC_animate_stand_dir(&artpeople_npcs[c], UP);}
			if(artpeople_npcs[c]->AI==11)if(NPC_walk_to_xy_intelligenthit_pushothers(&artpeople_npcs[c],artpeople_npcs[c]->walking_speed, 26*8,53*8)==1){artpeople_npcs[c]->vbls=r(100);artpeople_npcs[c]->AI=13+r(6);}
			if(artpeople_npcs[c]->AI==12)if(artpeople_npcs[c]->vbls>200)artpeople_npcs[c]->AI=13+r(6);
			if(artpeople_npcs[c]->AI==13)if(NPC_walk_to_xy_intelligenthit_pushothers(&artpeople_npcs[c],artpeople_npcs[c]->walking_speed, 23*8,42*8)==1){artpeople_npcs[c]->vbls=r(100);artpeople_npcs[c]->AI=12;NPC_animate_stand_dir(&artpeople_npcs[c], RIGHT);}
			if(artpeople_npcs[c]->AI==14)if(NPC_walk_to_xy_intelligenthit_pushothers(&artpeople_npcs[c],artpeople_npcs[c]->walking_speed, 23*8,26*8)==1){artpeople_npcs[c]->vbls=r(100);artpeople_npcs[c]->AI=12;NPC_animate_stand_dir(&artpeople_npcs[c], RIGHT);}
			if(artpeople_npcs[c]->AI==15)if(NPC_walk_to_xy_intelligenthit_pushothers(&artpeople_npcs[c],artpeople_npcs[c]->walking_speed, 15*8,21*8)==1){artpeople_npcs[c]->vbls=r(100);artpeople_npcs[c]->AI=12;NPC_animate_stand_dir(&artpeople_npcs[c], UP);}
			if(artpeople_npcs[c]->AI==16)if(NPC_walk_to_xy_intelligenthit_pushothers(&artpeople_npcs[c],artpeople_npcs[c]->walking_speed, 8*8,26*8)==1){artpeople_npcs[c]->vbls=r(100);artpeople_npcs[c]->AI=12;NPC_animate_stand_dir(&artpeople_npcs[c], LEFT);}
			if(artpeople_npcs[c]->AI==17)if(NPC_walk_to_xy_intelligenthit_pushothers(&artpeople_npcs[c],artpeople_npcs[c]->walking_speed, 8*8,42*8)==1){artpeople_npcs[c]->vbls=r(100);artpeople_npcs[c]->AI=12;NPC_animate_stand_dir(&artpeople_npcs[c], LEFT);}
			if(artpeople_npcs[c]->AI==18)if(NPC_walk_to_xy_intelligenthit_pushothers(&artpeople_npcs[c],artpeople_npcs[c]->walking_speed, 8*8,55*8)==1){NPC_delete_npc(&artpeople_npcs[c]);}
		}
	}
//47,42 cloth
//60,42
//47,23
//60,23
static int unveiledsheet1=0;
	static NPC* statuesheet1_npc = NULL;
	if(statuesheet1_npc==NULL&&unveiledsheet1==0)
	{
		NPC_create_npc_xy_feet(&statuesheet1_npc,GFX_MISC_museumsheet,64,64,47*8-2,41*8);
		statuesheet1_npc->layer=1;
	}
	if(statuesheet1_npc!=NULL)
	{
		if(unveiledsheet1==1)
			if(statuesheet1_npc->vbls>10) //dave
			{
				if(statuesheet1_npc->anim_frame_count==3)
				{
					NPC_delete_npc(&statuesheet1_npc);
					HARDWARE_play_sound("oooh",127,44100,0);
				}
				else
				{
					NPC_animate_cycle_through_frames_now(&statuesheet1_npc,4);
					statuesheet1_npc->vbls=0;
				}
			}
	}
static int unveiledsheet2=0;
	static NPC* statuesheet2_npc = NULL;
	if(statuesheet2_npc==NULL&&unveiledsheet2==0)//hot
	{
		NPC_create_npc_xy_feet(&statuesheet2_npc,GFX_MISC_museumsheet,64,64,60*8-2,41*8);
		statuesheet2_npc->layer=1;
	}
	if(statuesheet2_npc!=NULL)
	{
		if(unveiledsheet2==1)
			if(statuesheet2_npc->vbls>10)
			{
				if(statuesheet2_npc->anim_frame_count==3)
				{
					NPC_delete_npc(&statuesheet2_npc);
					HARDWARE_play_sound("oooh",127,44100,0);
				}
				else
				{
					NPC_animate_cycle_through_frames_now(&statuesheet2_npc,4);
					statuesheet2_npc->vbls=0;
				}
			}
	}
	static int unveiledsheet3=0;
	static NPC* statuesheet3_npc = NULL;
	if(statuesheet3_npc==NULL&&unveiledsheet3==0)//brick
	{
		NPC_create_npc_xy_feet(&statuesheet3_npc,GFX_MISC_museumsheet,64,64,47*8-2,26*8);
		statuesheet3_npc->layer=1;
	}
	if(statuesheet3_npc!=NULL)
	{
		if(unveiledsheet3==1)
			if(statuesheet3_npc->vbls>10)
			{
				if(statuesheet3_npc->anim_frame_count==3)
				{
					NPC_delete_npc(&statuesheet3_npc);
					HARDWARE_play_sound("heavyapplause",127,44100,0);
				}
				else
				{
					NPC_animate_cycle_through_frames_now(&statuesheet3_npc,4);
					statuesheet3_npc->vbls=0;
				}
			}
	}
	static int unveiledsheet4=0;
	static NPC* statuesheet4_npc = NULL;
	if(statuesheet4_npc==NULL&&unveiledsheet4==0)//clicker
	{
		NPC_create_npc_xy_feet(&statuesheet4_npc,GFX_MISC_museumsheet,64,64,60*8-2,26*8);
		statuesheet4_npc->layer=1;
	}
	if(statuesheet4_npc!=NULL)
	{
		if(unveiledsheet4==1)
			if(statuesheet4_npc->vbls>10)
			{
				if(statuesheet4_npc->anim_frame_count==3)
				{
					NPC_delete_npc(&statuesheet4_npc);
					HARDWARE_play_sound("booo",127,44100,0);
				}
				else
				{
					NPC_animate_cycle_through_frames_now(&statuesheet4_npc,4);
					statuesheet4_npc->vbls=0;
				}
			}
	}

if(ACTION_range_xy_xy(45*8,32*8,49*8,33*8,"Unveil Greatness"))
{
//brick
	unveiledsheet3=1;
	TEXT_set_sprite_window(0,PLAYER_npc,NULL);
	TEXT_set_sprite_window(1,PLAYER_npc,NULL);
	TEXT_window("Enigmatically named \"Block,\" this magnificent sculptured masterpiece is renowned for being the greatest creative work of the century."
	);
}
if(ACTION_range_xy_xy(58*8,32*8,62*8,33*8,"Unveil Greatness"))
{
//the clicker
	unveiledsheet4=1;
	TEXT_set_sprite_window(0,PLAYER_npc,NULL);
	TEXT_set_sprite_window(1,PLAYER_npc,NULL);
	TEXT_window("It's called \"The Clicker.\" Some stupid statue of something or other. Who cares."
	);
}
if(ACTION_range_xy_xy(45*8,47*8,49*8,48*8,"Unveil Greatness"))
{
//dave
	unveiledsheet1=1;
	TEXT_set_sprite_window(0,PLAYER_npc,NULL);
	TEXT_set_sprite_window(1,PLAYER_npc,NULL);
	TEXT_window("\"Dave\" is always irritating Venus with late night phone calls. When will he give up already?"
	);
}
if(ACTION_range_xy_xy(58*8,47*8,62*8,48*8,"Unveil Greatness"))
{
//hawt chick
	unveiledsheet2=1;
	TEXT_set_sprite_window(0,PLAYER_npc,NULL);
	TEXT_set_sprite_window(1,PLAYER_npc,NULL);
	TEXT_window("\"Venus\" knows she's got it going on, besides the lack of arms. But some guys dig that kind of thing."
	);
}

if(ACTION_range_xy_xy(36*8,16*8,39*8,17*8,"Look At Painting"))
{
	//splatters
	TEXT_set_sprite_window(0,PLAYER_npc,NULL);
	TEXT_set_sprite_window(1,PLAYER_npc,NULL);
	TEXT_window("It's titled \"Protective Tarp Placed On Floor Underneath Easel.\"<.>"
				"It has a First Place ribbon on it."
	);
}
if(ACTION_range_xy_xy(47*8,16*8,50*8,17*8,"Look At Painting"))
{
	//alien
	TEXT_set_sprite_window(0,PLAYER_npc,NULL);
	TEXT_set_sprite_window(1,PLAYER_npc,NULL);
	TEXT_window("It's titled \"Paralyzed Alien Under The Bleeding Asteroid Next To Mr. Sun Being Hit By The Droopy Tree Stink Waves.\" Yawn."
	);
}
if(ACTION_range_xy_xy(58*8,16*8,61*8,17*8,"Look At Painting"))
{
	//mona
	TEXT_set_sprite_window(0,PLAYER_npc,NULL);
	TEXT_set_sprite_window(1,PLAYER_npc,NULL);
	TEXT_window("It's titled \"Ugly Painting Of Woman That Is Very Famous For Some Reason.\""
	);
}
if(ACTION_range_xy_xy(69*8,16*8,72*8,17*8,"Look At Painting"))
{
	//nature
	TEXT_set_sprite_window(0,PLAYER_npc,NULL);
	TEXT_set_sprite_window(1,PLAYER_npc,NULL);
	TEXT_window("It's titled \"Small Child Drowning Underwater In A Beautiful River Scene.\""
	);
}
if(ACTION_range_xy_xy(72*8,25*8,73*8,29*8,"Look At Painting"))
{
//painting right up
	TEXT_set_sprite_window(0,PLAYER_npc,NULL);
	TEXT_set_sprite_window(1,PLAYER_npc,NULL);
	TEXT_window("It's titled \"Pin Up Girl Of The Month.\""
	);
}
if(ACTION_range_xy_xy(72*8,40*8,73*8,44*8,"Look At Painting"))
{
//painting right down
	TEXT_set_sprite_window(0,PLAYER_npc,NULL);
	TEXT_set_sprite_window(1,PLAYER_npc,NULL);
	TEXT_window("It's titled \"Fancy Picture Frame- Art Not Included.\""
	);
}
if(ACTION_range_xy_xy(33*8,25*8,35*8,29*8,"Look At Painting"))
{
//left up
	TEXT_set_sprite_window(0,PLAYER_npc,NULL);
	TEXT_set_sprite_window(1,PLAYER_npc,NULL);
	TEXT_window("It's titled \"The President On The Toilet.\""
	);
}
if(ACTION_range_xy_xy(33*8,40*8,35*8,44*8,"Look At Painting"))
{
//left down
	TEXT_set_sprite_window(0,PLAYER_npc,NULL);
	TEXT_set_sprite_window(1,PLAYER_npc,NULL);
	TEXT_window("It's titled \"Untitled.\""
	);
}
if(ACTION_range_xy_xy(24*8,25*8,26*8,29*8,"Look At Painting"))
{
//room 2 right up
	TEXT_set_sprite_window(0,PLAYER_npc,NULL);
	TEXT_set_sprite_window(1,PLAYER_npc,NULL);
	TEXT_window("It's titled \"Actual Photo Of Bigfoot.\""
	);
}
if(ACTION_range_xy_xy(24*8,40*8,26*8,44*8,"Look At Painting"))
{
//right down
	TEXT_set_sprite_window(0,PLAYER_npc,NULL);
	TEXT_set_sprite_window(1,PLAYER_npc,NULL);
	TEXT_window("It's titled \"Man Eats Bowling Ball.\""
	);
}

if(ACTION_range_xy_xy(5*8,25*8,7*8,29*8,"Look At Painting"))
{
//left up
	TEXT_set_sprite_window(0,PLAYER_npc,NULL);
	TEXT_set_sprite_window(1,PLAYER_npc,NULL);
	TEXT_window("It's the most incredible thing Yuu has ever seen."
	);
}
if(ACTION_range_xy_xy(5*8,40*8,7*8,44*8,"Look At Painting"))
{
//left down
	TEXT_set_sprite_window(0,PLAYER_npc,NULL);
	TEXT_set_sprite_window(1,PLAYER_npc,NULL);
	TEXT_window("It's titled \"Something Clever.\""
	);
}

if(ACTION_range_xy_xy(12*8,19*8,18*8,20*8,"Look At Gigantic Jewel"))
{
//big jewel
	TEXT_set_sprite_window(0,PLAYER_npc,NULL);
	TEXT_set_sprite_window(1,PLAYER_npc,NULL);
	TEXT_window(""
	);
}

//sparkle at 14,9

	static NPC* jewelsparkle_npc = NULL;
	if(jewelsparkle_npc==NULL)
	{
		NPC_create_npc_xy_feet(&jewelsparkle_npc,GFX_MISC_jewelsparkle,16,16,15*8,10*8);
		jewelsparkle_npc->layer=1;
	}
	if(jewelsparkle_npc!=NULL)
	{
		if(jewelsparkle_npc->vbls>5){NPC_set_anim_frame_now(&jewelsparkle_npc,0);}
		if(jewelsparkle_npc->vbls>jewelsparkle_npc->AI){NPC_set_anim_frame_now(&jewelsparkle_npc,(r(4))+1);jewelsparkle_npc->vbls=0;jewelsparkle_npc->AI=50+r(120);}
	}
	if(walking_into_door(RANGE_CITYMuseumExhibitToLobby))
	{
		MAP_change_map(MAP_bobsgame_CITYMuseumLobby,44,11);return;
		//TODO: one way cant go back
	}
	if(walking_into_door(RANGE_CITYMuseumExhibitToGiftShop))
	{
		MAP_change_map(MAP_bobsgame_CITYMuseumGiftShop,7,10);return;
		//TODO: are you sure you're done? one way
	}
}
void bobsgame_CITYMuseumExhibit_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYMuseumExhibit_Map_VBL_Function()
{

}
void bobsgame_CITYMuseumExhibit_Map_HBL_Function()
{

}
//========================================================
//CITYMuseumGiftShop
//========================================================
void bobsgame_CITYMuseumGiftShop_Map_Load_Function()
{
//RANGE_CITYMuseumGiftShopToExhibit 4*8,9*8,12*8,10*8
//RANGE_CITYMuseumGiftShopToLobby 27*8,16*8,28*8,21*8
}
void bobsgame_CITYMuseumGiftShop_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

	//purchase a miniature block
//clerk 16,21 up
//13-19,19 talk to
	static NPC* giftshopclerk_npc = NULL;
	if(giftshopclerk_npc==NULL)
	{
		NPC_create_random_ADULT_xy_feet(&giftshopclerk_npc,16*8,21*8);
		//NPC_create_npc_xy_feet(&giftshopclerk_npc,SPRITE,16,40,7*8,27*8);
		giftshopclerk_npc->non_walkable=1;
		giftshopclerk_npc->layer=1;
		NPC_animate_stand_dir(&giftshopclerk_npc,UP);
		giftshopclerk_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		giftshopclerk_npc->walk_dir=giftshopclerk_npc->anim_dir;
		//NPC_animate_increment_direction_frame_now(&giftshopclerk_npc, giftshopclerk_npc->anim_direction);
	}
	if(giftshopclerk_npc!=NULL)
	{
		//if(NPC_in_range_of_npc_amt(&PLAYER_npc,giftshopclerk_npc,15))NPC_stare_at_npc(&giftshopclerk_npc,PLAYER_npc);
		//else NPC_animate_set_direction_now(&giftshopclerk_npc, giftshopclerk_npc->walking_direction);
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&giftshopclerk_npc,35))NPC_stare_at_npc(&giftshopclerk_npc,&PLAYER_npc);
		else
		{
			if(giftshopclerk_npc->AI==0){if(giftshopclerk_npc->vbls>200){if(r(4)==0){giftshopclerk_npc->AI=1+r(3);}else{giftshopclerk_npc->vbls=0;NPC_animate_stand_dir(&giftshopclerk_npc, giftshopclerk_npc->walk_dir);if(giftshopclerk_npc->anim_frame_count!=0){giftshopclerk_npc->anim_frame_count=3;NPC_animate(&giftshopclerk_npc);}}}}
			if(giftshopclerk_npc->AI==1){if(giftshopclerk_npc->walk_dir==UP||giftshopclerk_npc->walk_dir==DOWN)NPC_animate_stand_dir(&giftshopclerk_npc,LEFT);else NPC_animate_stand_dir(&giftshopclerk_npc,UP);giftshopclerk_npc->vbls=r(120);giftshopclerk_npc->AI=0;}
			if(giftshopclerk_npc->AI==2){if(giftshopclerk_npc->walk_dir==UP||giftshopclerk_npc->walk_dir==DOWN)NPC_animate_stand_dir(&giftshopclerk_npc,RIGHT);else NPC_animate_stand_dir(&giftshopclerk_npc,DOWN);giftshopclerk_npc->vbls=r(120);giftshopclerk_npc->AI=0;}
			if(giftshopclerk_npc->AI==3){NPC_animate(&giftshopclerk_npc);giftshopclerk_npc->vbls=r(120);giftshopclerk_npc->AI=0;}
		}
		if(ACTION_range_xy_xy(11*8,19*8,21*8,22*8,"Talk To Gift Shop Clerk"))
		{
			TEXT_set_sprite_window(0,giftshopclerk_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("" //?
			);
		}
	}
//7,22 down
//5,19 left
//5,14 left

	static NPC* giftshop1_npc = NULL;
	if(giftshop1_npc==NULL)
	{
		//NPC_create_npc_xy_feet(&giftshop1_npc,GENERICmanlongsleeves,16,40,33*8,39*8);
		NPC_create_random_ADULT_xy_feet(&giftshop1_npc,7*8,22*8);
		giftshop1_npc->layer=2;
		giftshop1_npc->non_walkable=1;
		NPC_animate_stand_dir(&giftshop1_npc,DOWN);
		giftshop1_npc->walking_speed = SPEED_SLOWEST+r(SPEED_SLOWEST-SPEED_FASTEST);
		giftshop1_npc->AI=0;
	}
	if(giftshop1_npc!=NULL)
	{
		if(giftshop1_npc->AI== 0)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&giftshop1_npc,giftshop1_npc->walking_speed,  5*8,19*8)==1){giftshop1_npc->AI=3;giftshop1_npc->vbls=r(60);NPC_animate_stand_dir(&giftshop1_npc,LEFT);}
		if(giftshop1_npc->AI== 1)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&giftshop1_npc,giftshop1_npc->walking_speed,  7*8,21*8)==1){giftshop1_npc->AI=3;giftshop1_npc->vbls=r(60);NPC_animate_stand_dir(&giftshop1_npc,DOWN);}
		if(giftshop1_npc->AI== 2)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&giftshop1_npc,giftshop1_npc->walking_speed,  5*8,14*8)==1){giftshop1_npc->AI=3;giftshop1_npc->vbls=r(60);NPC_animate_stand_dir(&giftshop1_npc,LEFT);}
		if(giftshop1_npc->AI== 3)if(giftshop1_npc->vbls>120){giftshop1_npc->vbls=0;giftshop1_npc->AI=r(3);}
	}
//16,12 up
//23,12 up
//20,12 up
	static NPC* giftshop2_npc = NULL;
	if(giftshop2_npc==NULL)
	{
		//NPC_create_npc_xy_feet(&giftshop2_npc,GENERICmanlongsleeves,16,40,33*8,39*8);
		NPC_create_random_ADULT_xy_feet(&giftshop2_npc,16*8,13*8);
		giftshop2_npc->layer=2;
		giftshop2_npc->non_walkable=1;
		NPC_animate_stand_dir(&giftshop2_npc,UP);
		giftshop2_npc->walking_speed = SPEED_SLOWEST+r(SPEED_SLOWEST-SPEED_FASTEST);
		giftshop2_npc->AI=0;
	}
	if(giftshop2_npc!=NULL)
	{
		if(giftshop2_npc->AI== 0)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&giftshop2_npc,giftshop2_npc->walking_speed, 20*8,13*8)==1){giftshop2_npc->AI=3;giftshop2_npc->vbls=r(60);NPC_animate_stand_dir(&giftshop2_npc,UP);}
		if(giftshop2_npc->AI== 1)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&giftshop2_npc,giftshop2_npc->walking_speed, 16*8,13*8)==1){giftshop2_npc->AI=3;giftshop2_npc->vbls=r(60);NPC_animate_stand_dir(&giftshop2_npc,UP);}
		if(giftshop2_npc->AI== 2)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&giftshop2_npc,giftshop2_npc->walking_speed, 23*8,13*8)==1){giftshop2_npc->AI=3;giftshop2_npc->vbls=r(60);NPC_animate_stand_dir(&giftshop2_npc,UP);}
		if(giftshop2_npc->AI== 3)if(giftshop2_npc->vbls>120){giftshop2_npc->vbls=0;giftshop2_npc->AI=r(3);}
	}
	if(walking_into_door(RANGE_CITYMuseumGiftShopToExhibit))
	{
		MAP_change_map(MAP_bobsgame_CITYMuseumExhibit,7,55);return;
		//TODO: probably one way only
	}
	if(walking_into_door(RANGE_CITYMuseumGiftShopToLobby))
	{
		MAP_change_map(MAP_bobsgame_CITYMuseumLobby,2,19);return;
		//TODO: are you sure youre done shopping? maybe make this one way.
	}
}
void bobsgame_CITYMuseumGiftShop_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYMuseumGiftShop_Map_VBL_Function()
{

}
void bobsgame_CITYMuseumGiftShop_Map_HBL_Function()
{

}



