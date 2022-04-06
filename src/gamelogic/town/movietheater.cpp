//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================



#include "../../main.h"



#define RANGE_TOWNMovieTheatreLobbyToOUTSIDETown1 15*8,34*8,21*8,35*8
#define RANGE_TOWNMovieTheatreLobbyToOUTSIDETown2 23*8,34*8,29*8,35*8
#define RANGE_TOWNMovieTheatreLobbyToOUTSIDETown3 31*8,34*8,37*8,35*8
#define RANGE_TOWNMovieTheatreLobbyToMovieTheatreMainHallLeft 4*8,9*8,12*8,10*8
#define RANGE_TOWNMovieTheatreLobbyToMovieTheatreMainHallRight 40*8,9*8,48*8,10*8
#define RANGE_TOWNMovieTheatreMainHallToMovieTheatreLobbyLeft 49*8,50*8,57*8,51*8
#define RANGE_TOWNMovieTheatreMainHallToMovieTheatreLobbyRight 85*8,50*8,93*8,51*8
#define RANGE_TOWNMovieTheatreMainHallToMensBathroom 46*8,14*8,50*8,15*8
#define RANGE_TOWNMovieTheatreMainHallToWomensBathroom 92*8,14*8,96*8,15*8
#define RANGE_TOWNMovieTheatreMainHallToMovieTheatreBuffer 4*8,15*8,10*8,16*8
#define RANGE_TOWNMovieTheatreMainHallToMovieTheatrePhotoBooth 102*8,17*8,106*8,18*8
#define RANGE_TOWNMovieTheatrePhotoBoothToMovieTheatreMainHall 3*8,10*8,5*8,11*8
#define RANGE_TOWNMovieTheatreMensBathroomToMovieTheatreMainHall 36*8,20*8,40*8,21*8
#define RANGE_TOWNMovieTheatreWomensBathroomToMovieTheatreMainHall 5*8,20*8,9*8,21*8
#define RANGE_TOWNMovieTheatreBufferToMovieTheatreMainHall 3*8,40*8,9*8,41*8
#define RANGE_TOWNMovieTheatreBufferToMovieTheaterInsideLeft 10*8,13*8,11*8,19*8
#define RANGE_TOWNMovieTheatreBufferToMovieTheaterInsideRight 57*8,13*8,58*8,19*8
#define RANGE_TOWNMovieTheatreInsideToMovieTheatreBufferLeft 1*8,62*8,2*8,67*8
#define RANGE_TOWNMovieTheatreInsideToMovieTheatreBufferRight 48*8,62*8,49*8,67*8



//========================================================
//TOWNMovieTheatreLobby
//========================================================
void bobsgame_TOWNMovieTheatreLobby_Map_Load_Function()
{
//NPC_create_sprite(&alienposter,64,64,40,184);
//NPC_create_sprite(&pingthemovie,64,64,328,184);
//RANGE_TOWNMovieTheatreLobbyToOUTSIDETown1 15*8,34*8,21*8,35*8
//RANGE_TOWNMovieTheatreLobbyToOUTSIDETown2 23*8,34*8,29*8,35*8
//RANGE_TOWNMovieTheatreLobbyToOUTSIDETown3 31*8,34*8,37*8,35*8
//RANGE_TOWNMovieTheatreLobbyToMovieTheatreMainHallLeft 4*8,9*8,12*8,10*8
//RANGE_TOWNMovieTheatreLobbyToMovieTheatreMainHallRight 40*8,9*8,48*8,10*8
}

void bobsgame_TOWNMovieTheatreLobby_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//door 33,33
//25,33
//17,33
//line 19-21,16
//line 26-28,16
//line 33-35,16
//door up 8,11
//door up 43,11
//TODO: buy tickets
//TODO: line behavior.
//TODO: line exists on entering
//TODO: other people in cliques
//TODO: posters
//TODO: animate lights
	//TODO:need crowd murmur
	static NPC* line_npcs[30] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	int c=0;
	for(c=0;c<30;c++)
	{
		if(line_npcs[c]==NULL&&CLOCK_second/10==c%6)
		{
			int randnum=0;
			randnum=r(3);
			if(randnum==0)NPC_create_random_ADULT_OR_CHILD_xy_feet(&line_npcs[c],20*8,33*8);
			if(randnum==1)NPC_create_random_ADULT_OR_CHILD_xy_feet(&line_npcs[c],34*8,33*8);
			if(randnum==2)NPC_create_random_ADULT_OR_CHILD_xy_feet(&line_npcs[c],27*8,33*8);
			line_npcs[c]->non_walkable=1;
			line_npcs[c]->AI=randnum+1;
			line_npcs[c]->walking_speed=SPEED_NORMAL+r(SPEED_SLOW-SPEED_FASTEST);
			line_npcs[c]->ignore_fx_layer=1;
			NPC_animate_stand_dir(&line_npcs[c], UP);
		}
		if(line_npcs[c]!=NULL)
		{
			if(line_npcs[c]->AI== 1){if(NPC_walk_to_xy_intelligenthit_stopforothers_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 20*8,16*8)==(1)){line_npcs[c]->AI+=3;line_npcs[c]->vbls=0;NPC_animate_stand_dir(&line_npcs[c], UP);}}
			else if(line_npcs[c]->AI== 2){if(NPC_walk_to_xy_intelligenthit_stopforothers_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 34*8,16*8)==(1)){line_npcs[c]->AI+=3;line_npcs[c]->vbls=0;NPC_animate_stand_dir(&line_npcs[c], UP);}}
			else if(line_npcs[c]->AI== 3){if(NPC_walk_to_xy_intelligenthit_stopforothers_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 27*8,16*8)==(1)){line_npcs[c]->AI+=3;line_npcs[c]->vbls=0;NPC_animate_stand_dir(&line_npcs[c], UP);}}
			else if(line_npcs[c]->AI== 4){if(line_npcs[c]->vbls>120){line_npcs[c]->AI+=3;}}
			else if(line_npcs[c]->AI== 5){if(line_npcs[c]->vbls>120){line_npcs[c]->AI+=3;}}
			else if(line_npcs[c]->AI== 6){if(line_npcs[c]->vbls>120){line_npcs[c]->AI+=(r(2))+1;}}
			//walk to open spot
			else if(line_npcs[c]->AI== 7){if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 8*8,16*8)==1){line_npcs[c]->AI+=2;}}
			else if(line_npcs[c]->AI== 8){if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 43*8,16*8)==1){line_npcs[c]->AI+=2;}}
			else if(line_npcs[c]->AI== 9){if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 8*8,11*8)==1){NPC_delete_npc(&line_npcs[c]);}}
			else if(line_npcs[c]->AI==10){if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 43*8,11*8)==1){NPC_delete_npc(&line_npcs[c]);}}
		}
	}
		static NPC* ticketclerk_npc = NULL;
	if(ticketclerk_npc==NULL)
	{
		NPC_create_npc_xy_feet(&ticketclerk_npc,GFX_ADULT_GENERICwomanlonghair,16,40,19*8,12*8);
		ticketclerk_npc->non_walkable=1;
		ticketclerk_npc->layer=3;
		NPC_animate_stand_dir(&ticketclerk_npc, DOWN);
		//TODO: need ticket clerk sprite
	}
	else if(ticketclerk_npc!=NULL)
	{
		if(ACTION_range_xy_xy(17*8,14*8,21*8,15*8,"Buy Movie Ticket"))
		{
			TEXT_set_sprite_window(0,ticketclerk_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("I'm sorry, sir, but Yuu will have to wait in line like everyone else."
			);
		}
	}
		static NPC* ticketclerk2_npc = NULL;
	if(ticketclerk2_npc==NULL)
	{
		NPC_create_npc_xy_feet(&ticketclerk2_npc,GFX_ADULT_GENERICwomanlonghair,16,40,26*8,12*8);
		ticketclerk2_npc->non_walkable=1;
		ticketclerk2_npc->layer=3;
		NPC_animate_stand_dir(&ticketclerk2_npc, DOWN);
		//TODO: need ticket clerk sprite
	}
	else if(ticketclerk2_npc!=NULL)
	{
		if(ACTION_range_xy_xy(24*8,14*8,28*8,15*8,"Buy A Ticket"))
		{
			TEXT_set_sprite_window(0,ticketclerk2_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("I'm sorry, sir, but Yuu must get in line."
			);
		}
	}
		static NPC* ticketclerk3_npc = NULL;
	if(ticketclerk3_npc==NULL)
	{
		NPC_create_npc_xy_feet(&ticketclerk3_npc,GFX_ADULT_GENERICwomanlonghair,16,40,33*8,12*8);
		ticketclerk3_npc->non_walkable=1;
		ticketclerk3_npc->layer=3;
		NPC_animate_stand_dir(&ticketclerk3_npc, DOWN);
		//TODO: need ticket clerk sprite
	}
	else if(ticketclerk3_npc!=NULL)
	{
		if(ACTION_range_xy_xy(31*8,14*8,35*8,15*8,"Buy Movie Pass"))
		{
			TEXT_set_sprite_window(0,ticketclerk3_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("I'm sorry, sir, but Yuu is going to have to start at the end of the line."
			);
		}
	}

	if(walking_into_door(RANGE_TOWNMovieTheatreLobbyToOUTSIDETown1))
	{
		MAP_change_map(MAP_bobsgame_TOWNTown,1463,229);return;
	}
	if(walking_into_door(RANGE_TOWNMovieTheatreLobbyToOUTSIDETown2))
	{
		MAP_change_map(MAP_bobsgame_TOWNTown,1471,229);return;
	}
	if(walking_into_door(RANGE_TOWNMovieTheatreLobbyToOUTSIDETown3))
	{
		MAP_change_map(MAP_bobsgame_TOWNTown,1479,229);return;
	}
	if(walking_into_door(RANGE_TOWNMovieTheatreLobbyToMovieTheatreMainHallLeft))
	{
		MAP_change_map(MAP_bobsgame_TOWNMovieTheatreMainHall,52,49);return;
	}
	if(walking_into_door(RANGE_TOWNMovieTheatreLobbyToMovieTheatreMainHallRight))
	{
		MAP_change_map(MAP_bobsgame_TOWNMovieTheatreMainHall,88,49);return;
	}
}
void bobsgame_TOWNMovieTheatreLobby_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_TOWNMovieTheatreLobby_Map_VBL_Function()
{

}

void bobsgame_TOWNMovieTheatreLobby_Map_HBL_Function()
{

}

//========================================================
//TOWNMovieTheatreMainHall
//========================================================
void bobsgame_TOWNMovieTheatreMainHall_Map_Load_Function()
{
//NPC_create_sprite(&vampireromance,64,64,160,56);
//NPC_create_sprite(&warposter,64,64,256,56);
//NPC_create_sprite(&angryrobotsposter,64,64,392,216);
//NPC_create_sprite(&actionmanposter,64,64,696,216);
//NPC_create_sprite(&alienposter,64,64,912,56);
//NPC_create_sprite(&photoboothsign,32,16,792,112);
//RANGE_TOWNMovieTheatreMainHallToMovieTheatreLobbyLeft 49*8,50*8,57*8,51*8
//RANGE_TOWNMovieTheatreMainHallToMovieTheatreLobbyRight 85*8,50*8,93*8,51*8
//RANGE_TOWNMovieTheatreMainHallToMensBathroom 46*8,14*8,50*8,15*8
//RANGE_TOWNMovieTheatreMainHallToWomensBathroom 92*8,14*8,96*8,15*8
//RANGE_TOWNMovieTheatreMainHallToMovieTheatreBuffer 4*8,15*8,10*8,16*8
//RANGE_TOWNMovieTheatreMainHallToMovieTheatrePhotoBooth 102*8,17*8,106*8,18*8
}

void bobsgame_TOWNMovieTheatreMainHall_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//door 53,50
//89,50
//usher 69,29
//candy 1 61.18
//69.18
//77.18
//85.18
//TODO: vending machines
//TODO: photo booth
//TODO: movie posters
//TODO: payphone
//TODO: buy candy
//TODO: movie usher
//TODO: need ticket for theatre and hallway
//TODO: random people back and forth
//TODO: bench people "that was terrible"
	//TODO:need crowd murmur
	static NPC* usher_npc = NULL;
	if(usher_npc==NULL)
	{
		NPC_create_npc_xy_feet(&usher_npc,GFX_ADULT_GENERICwomanlonghair,16,40,69*8+4,29*8);
		usher_npc->non_walkable=1;
		usher_npc->layer=2;
		NPC_animate_stand_dir(&usher_npc, RIGHT);
		//TODO: need usher sprite
	}
	else if(usher_npc!=NULL)
	{
		if(ACTION_range_xy_xy(69*8,28*8,73*8,29*8,"Show Ticket"))
		{
			TEXT_set_sprite_window(0,usher_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("I'm sorry, sir, Yuu needs a ticket."
			);
		}
		//TODO: if try to get past here, get stopped by usher guy
		//TODO: have to wait in line
	}
		static NPC* line_npcs[10] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	int c=0;
	for(c=0;c<10;c++)
	{
		if(line_npcs[c]==NULL&&CLOCK_second/10==c%6)
		{
			int randnum=0;
			randnum=r(2);
			if(randnum==0)NPC_create_random_ADULT_OR_CHILD_xy_feet(&line_npcs[c],53*8,50*8);
			if(randnum==1)NPC_create_random_ADULT_OR_CHILD_xy_feet(&line_npcs[c],89*8,50*8);
			line_npcs[c]->non_walkable=1;
			line_npcs[c]->AI=randnum+1;
			line_npcs[c]->walking_speed=SPEED_NORMAL+r(SPEED_SLOW-SPEED_FASTEST);
			line_npcs[c]->ignore_fx_layer=1;
			NPC_animate_stand_dir(&line_npcs[c], UP);
		}
		if(line_npcs[c]!=NULL)
		{
			if(line_npcs[c]->AI== 1){if(NPC_walk_to_xy_intelligenthit_stopforothers_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 53*8,40*8)==(1)){line_npcs[c]->AI+=2;}}
			else if(line_npcs[c]->AI== 2){if(NPC_walk_to_xy_intelligenthit_stopforothers_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 89*8,42*8)==(1)){line_npcs[c]->AI+=2;}}
			else if(line_npcs[c]->AI== 3){if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 71*8+6,-1)==1){line_npcs[c]->AI+=2;}}
			else if(line_npcs[c]->AI== 4){if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 71*8+6,-1)==1){line_npcs[c]->AI+=1;}}
			else if(line_npcs[c]->AI== 5){if(NPC_walk_to_xy_intelligenthit_stopforothers_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 71*8+6,29*8)==(1)){line_npcs[c]->AI+=1;line_npcs[c]->vbls=0;NPC_animate_stand_dir(&line_npcs[c], LEFT);}}
			else if(line_npcs[c]->AI== 6){if(line_npcs[c]->vbls>30){line_npcs[c]->AI++;}}
			else if(line_npcs[c]->AI== 7){if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 71*8+6,25*8)==1){line_npcs[c]->AI+=(r(4))+1;}}
			//walk to open spot
			else if(line_npcs[c]->AI== 8){if(NPC_walk_to_xy_intelligenthit_stopforothers_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 61*8,18*8)==(1)){line_npcs[c]->AI+=4;line_npcs[c]->vbls=0;NPC_animate_stand_dir(&line_npcs[c], UP);}}
			else if(line_npcs[c]->AI== 9){if(NPC_walk_to_xy_intelligenthit_stopforothers_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 69*8,18*8)==(1)){line_npcs[c]->AI+=4;line_npcs[c]->vbls=0;NPC_animate_stand_dir(&line_npcs[c], UP);}}
			else if(line_npcs[c]->AI==10){if(NPC_walk_to_xy_intelligenthit_stopforothers_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 77*8,18*8)==(1)){line_npcs[c]->AI+=4;line_npcs[c]->vbls=0;NPC_animate_stand_dir(&line_npcs[c], UP);}}
			else if(line_npcs[c]->AI==11){if(NPC_walk_to_xy_intelligenthit_stopforothers_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 85*8,18*8)==(1)){line_npcs[c]->AI+=4;line_npcs[c]->vbls=0;NPC_animate_stand_dir(&line_npcs[c], UP);}}
			else if(line_npcs[c]->AI==12){if(line_npcs[c]->vbls>120){line_npcs[c]->AI+=4;}}
			else if(line_npcs[c]->AI==13){if(line_npcs[c]->vbls>120){line_npcs[c]->AI+=3;}}
			else if(line_npcs[c]->AI==14){if(line_npcs[c]->vbls>120){line_npcs[c]->AI+=3;}}
			else if(line_npcs[c]->AI==15){if(line_npcs[c]->vbls>120){line_npcs[c]->AI+=2;}}
			else if(line_npcs[c]->AI==16){if((NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&line_npcs[c],line_npcs[c]->walking_speed,   7*8,-1)==1)){NPC_delete_npc(&line_npcs[c]);}}
			else if(line_npcs[c]->AI==17){if((NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 136*8,-1)==1)){NPC_delete_npc(&line_npcs[c]);}}
		}
	}
	static NPC* candycounter_npc = NULL;
	if(candycounter_npc==NULL)
	{
		NPC_create_npc_xy_feet(&candycounter_npc,GFX_ADULT_GENERICwomanlonghair,16,40,61*8,14*8);
		candycounter_npc->non_walkable=1;
		candycounter_npc->layer=3;
		NPC_animate_stand_dir(&candycounter_npc,DOWN);
		//TODO: need candycounter sprite
	}
	else if(candycounter_npc!=NULL)
	{
		if(ACTION_range_xy_xy(60*8,16*8,63*8,17*8,"Waste Money"))
		{
			TEXT_set_sprite_window(0,candycounter_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
		static NPC* candycounter2_npc = NULL;
	if(candycounter2_npc==NULL)
	{
		NPC_create_npc_xy_feet(&candycounter2_npc,GFX_ADULT_GENERICwomanlonghair,16,40,69*8,14*8);
		candycounter2_npc->non_walkable=1;
		candycounter2_npc->layer=3;
		NPC_animate_stand_dir(&candycounter2_npc,DOWN);
		//TODO: need candycounter sprite
	}
	else if(candycounter2_npc!=NULL)
	{
		if(ACTION_range_xy_xy(67*8,16*8,72*8,17*8,"Buy Candy"))
		{
			TEXT_set_sprite_window(0,candycounter2_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
		static NPC* candycounter3_npc = NULL;
	if(candycounter3_npc==NULL)
	{
		NPC_create_npc_xy_feet(&candycounter3_npc,GFX_ADULT_GENERICwomanlonghair,16,40,77*8,14*8);
		candycounter3_npc->non_walkable=1;
		candycounter3_npc->layer=3;
		NPC_animate_stand_dir(&candycounter3_npc,DOWN);
		//TODO: need candycounter sprite
	}
	else if(candycounter3_npc!=NULL)
	{
		if(ACTION_range_xy_xy(75*8,16*8,80*8,17*8,"Buy Popcorn"))
		{
			TEXT_set_sprite_window(0,candycounter3_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
	static NPC* candycounter4_npc = NULL;
	if(candycounter4_npc==NULL)
	{
		NPC_create_npc_xy_feet(&candycounter4_npc,GFX_ADULT_GENERICwomanlonghair,16,40,85*8,14*8);
		candycounter4_npc->non_walkable=1;
		candycounter4_npc->layer=3;
		NPC_animate_stand_dir(&candycounter4_npc,DOWN);
		//TODO: need candycounter sprite
	}
	else if(candycounter4_npc!=NULL)
	{
		if(ACTION_range_xy_xy(83*8,16*8,87*8,17*8,"Buy Concessions"))
		{
			TEXT_set_sprite_window(0,candycounter4_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
	static NPC* theatreusher_npc = NULL;
	if(theatreusher_npc==NULL)
	{
		NPC_create_npc_xy_feet(&theatreusher_npc,GFX_ADULT_GENERICwomanlonghair,16,40,10*8,17*8);
		theatreusher_npc->non_walkable=1;
		theatreusher_npc->layer=2;
		NPC_animate_stand_dir(&theatreusher_npc,DOWN);
		//TODO: need theatreusher sprite
	}
	else if(theatreusher_npc!=NULL)
	{
		if(ACTION_range_xy_xy(3*8,15*8,10*8,16*8,"Show Ticket Stub"))
		{
			TEXT_set_sprite_window(0,theatreusher_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("I'm sorry, sir, Yuu needs a ticket."
			);
		}
		//TODO: if try to get past here, get stopped by theatreusher guy
	}
	if(walking_into_door(RANGE_TOWNMovieTheatreMainHallToMovieTheatreLobbyLeft))
	{
		MAP_change_map(MAP_bobsgame_TOWNMovieTheatreLobby,7,10);return;
	}
	if(walking_into_door(RANGE_TOWNMovieTheatreMainHallToMovieTheatreLobbyRight))
	{
		MAP_change_map(MAP_bobsgame_TOWNMovieTheatreLobby,43,10);return;
	}
	if(walking_into_door(RANGE_TOWNMovieTheatreMainHallToMensBathroom))
	{
		MAP_change_map(MAP_bobsgame_TOWNMovieTheatreMensBathroom,38,19);return;
	}
	if(walking_into_door(RANGE_TOWNMovieTheatreMainHallToWomensBathroom))
	{
		MAP_change_map(MAP_bobsgame_TOWNMovieTheatreWomensBathroom,5,19);return;
		//TODO: can't do that.
	}
	if(walking_into_door(RANGE_TOWNMovieTheatreMainHallToMovieTheatreBuffer))
	{
		MAP_change_map(MAP_bobsgame_TOWNMovieTheaterBuffer,5,39);return;
	}
	if(walking_into_door(RANGE_TOWNMovieTheatreMainHallToMovieTheatrePhotoBooth))
	{
		MAP_change_map(MAP_bobsgame_TOWNMovieTheatrePhotoBooth,3,9);return;
	}
}
void bobsgame_TOWNMovieTheatreMainHall_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_TOWNMovieTheatreMainHall_Map_VBL_Function()
{

}

void bobsgame_TOWNMovieTheatreMainHall_Map_HBL_Function()
{

}

//========================================================
//TOWNMovieTheatrePhotoBooth
//========================================================
void bobsgame_TOWNMovieTheatrePhotoBooth_Map_Load_Function()
{
//RANGE_TOWNMovieTheatrePhotoBoothToMovieTheatreMainHall 3*8,10*8,5*8,11*8
}

void bobsgame_TOWNMovieTheatrePhotoBooth_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//TODO: the screen says "smile" flash palette camera noise
	if(walking_into_door(RANGE_TOWNMovieTheatrePhotoBoothToMovieTheatreMainHall))
	{
		MAP_change_map(MAP_bobsgame_TOWNMovieTheatreMainHall,103,18);return;
	}
}
void bobsgame_TOWNMovieTheatrePhotoBooth_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_TOWNMovieTheatrePhotoBooth_Map_VBL_Function()
{

}

void bobsgame_TOWNMovieTheatrePhotoBooth_Map_HBL_Function()
{

}

//========================================================
//TOWNMovieTheatreMensBathroom
//========================================================
void bobsgame_TOWNMovieTheatreMensBathroom_Map_Load_Function()
{
//RANGE_TOWNMovieTheatreMensBathroomToMovieTheatreMainHall 36*8,20*8,40*8,21*8
}

void bobsgame_TOWNMovieTheatreMensBathroom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

	static NPC* stallguy1_npc = NULL;
	if(stallguy1_npc==NULL)
	{
		NPC_create_random_MAN_xy_feet(&stallguy1_npc,3*8,11*8);
		//NPC_create_npc_xy_feet(&stallguy1_npc,SPRITE,16,40,7*8,27*8);
		stallguy1_npc->non_walkable=1;
		stallguy1_npc->layer=2;
		NPC_animate_stand_dir(&stallguy1_npc,DOWN);
		stallguy1_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		stallguy1_npc->walk_dir=stallguy1_npc->anim_dir;
		//NPC_animate_increment_direction_frame_now(&stallguy1_npc, stallguy1_npc->anim_direction);
	}
	if(stallguy1_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&stallguy1_npc,45))NPC_stare_at_npc_not_opposite_walking_direction(&stallguy1_npc,&PLAYER_npc);
		else if(stallguy1_npc->AI==0){if(stallguy1_npc->vbls>200){if(r(4)==0){stallguy1_npc->AI=1+r(3);}else{stallguy1_npc->vbls=0;NPC_animate_stand_dir(&stallguy1_npc, stallguy1_npc->walk_dir);if(stallguy1_npc->anim_frame_count!=0){stallguy1_npc->anim_frame_count=3;NPC_animate(&stallguy1_npc);}}}}
		else if(stallguy1_npc->AI==1){if(stallguy1_npc->walk_dir==UP||stallguy1_npc->walk_dir==DOWN)NPC_animate_stand_dir(&stallguy1_npc,LEFT);else NPC_animate_stand_dir(&stallguy1_npc,UP);stallguy1_npc->vbls=r(120);stallguy1_npc->AI=0;}
		else if(stallguy1_npc->AI==2){if(stallguy1_npc->walk_dir==UP||stallguy1_npc->walk_dir==DOWN)NPC_animate_stand_dir(&stallguy1_npc,RIGHT);else NPC_animate_stand_dir(&stallguy1_npc,DOWN);stallguy1_npc->vbls=r(120);stallguy1_npc->AI=0;}
		else if(stallguy1_npc->AI==3){NPC_animate(&stallguy1_npc);stallguy1_npc->vbls=r(120);stallguy1_npc->AI=0;}

		if(ACTION_range_xy_xy(3*8,13*8,5*8,14*8,"Talk To Pooping Man"))
		{
			TEXT_set_sprite_window(0,stallguy1_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}

	static NPC* stallguy2_npc = NULL;
	if(stallguy2_npc==NULL)
	{
		NPC_create_random_MAN_xy_feet(&stallguy2_npc,13*8,11*8);
		//NPC_create_npc_xy_feet(&stallguy2_npc,SPRITE,16,40,7*8,27*8);
		stallguy2_npc->non_walkable=1;
		stallguy2_npc->layer=2;
		NPC_animate_stand_dir(&stallguy2_npc,DOWN);
		stallguy2_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		stallguy2_npc->walk_dir=stallguy2_npc->anim_dir;
		//NPC_animate_increment_direction_frame_now(&stallguy2_npc, stallguy2_npc->anim_direction);
	}
	if(stallguy2_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&stallguy2_npc,45))NPC_stare_at_npc_not_opposite_walking_direction(&stallguy2_npc,&PLAYER_npc);
		else if(stallguy2_npc->AI==0){if(stallguy2_npc->vbls>200){if(r(4)==0){stallguy2_npc->AI=1+r(3);}else{stallguy2_npc->vbls=0;NPC_animate_stand_dir(&stallguy2_npc, stallguy2_npc->walk_dir);if(stallguy2_npc->anim_frame_count!=0){stallguy2_npc->anim_frame_count=3;NPC_animate(&stallguy2_npc);}}}}
		else if(stallguy2_npc->AI==1){if(stallguy2_npc->walk_dir==UP||stallguy2_npc->walk_dir==DOWN)NPC_animate_stand_dir(&stallguy2_npc,LEFT);else NPC_animate_stand_dir(&stallguy2_npc,UP);stallguy2_npc->vbls=r(120);stallguy2_npc->AI=0;}
		else if(stallguy2_npc->AI==2){if(stallguy2_npc->walk_dir==UP||stallguy2_npc->walk_dir==DOWN)NPC_animate_stand_dir(&stallguy2_npc,RIGHT);else NPC_animate_stand_dir(&stallguy2_npc,DOWN);stallguy2_npc->vbls=r(120);stallguy2_npc->AI=0;}
		else if(stallguy2_npc->AI==3){NPC_animate(&stallguy2_npc);stallguy2_npc->vbls=r(120);stallguy2_npc->AI=0;}

		if(ACTION_range_xy_xy(13*8,13*8,15*8,14*8,"Talk To Pooping Man"))
		{
			TEXT_set_sprite_window(0,stallguy2_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}

	//21,11 up urinal
	static NPC* peeingguy_npc = NULL;
	if(peeingguy_npc==NULL)
	{
		NPC_create_npc_xy_feet(&peeingguy_npc,GFX_ADULT_GENERICmanlongsleeves,16,40,21*8,11*8);
		peeingguy_npc->non_walkable=1;
		peeingguy_npc->layer=2;
		NPC_animate_stand_dir(&peeingguy_npc,UP);
		//TODO: need peeingguy sprite
	}
	else if(peeingguy_npc!=NULL)
	{

		if(ACTION_npc(&peeingguy_npc,"Talk To Peeing Man"))
		{
			TEXT_set_sprite_window(0,stallguy2_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}

	if(walking_into_door(RANGE_TOWNMovieTheatreMensBathroomToMovieTheatreMainHall))
	{
		MAP_change_map(MAP_bobsgame_TOWNMovieTheatreMainHall,48,15);return;
	}
}
void bobsgame_TOWNMovieTheatreMensBathroom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_TOWNMovieTheatreMensBathroom_Map_VBL_Function()
{

}

void bobsgame_TOWNMovieTheatreMensBathroom_Map_HBL_Function()
{

}

//========================================================
//TOWNMovieTheatreWomensBathroom
//========================================================
void bobsgame_TOWNMovieTheatreWomensBathroom_Map_Load_Function()
{
//RANGE_TOWNMovieTheatreWomensBathroomToMovieTheatreMainHall 5*8,20*8,9*8,21*8
}

void bobsgame_TOWNMovieTheatreWomensBathroom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

	static NPC* stallgirl1_npc = NULL;
	if(stallgirl1_npc==NULL)
	{
		NPC_create_random_WOMAN_xy_feet(&stallgirl1_npc,20*8,11*8);
		//NPC_create_npc_xy_feet(&stallgirl1_npc,SPRITE,16,40,7*8,27*8);
		stallgirl1_npc->non_walkable=1;
		stallgirl1_npc->layer=2;
		NPC_animate_stand_dir(&stallgirl1_npc,DOWN);
		stallgirl1_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		stallgirl1_npc->walk_dir=stallgirl1_npc->anim_dir;
		//NPC_animate_increment_direction_frame_now(&stallgirl1_npc, stallgirl1_npc->anim_direction);
	}
	if(stallgirl1_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&stallgirl1_npc,45))NPC_stare_at_npc_not_opposite_walking_direction(&stallgirl1_npc,&PLAYER_npc);
		else if(stallgirl1_npc->AI==0){if(stallgirl1_npc->vbls>200){if(r(4)==0){stallgirl1_npc->AI=1+r(3);}else{stallgirl1_npc->vbls=0;NPC_animate_stand_dir(&stallgirl1_npc, stallgirl1_npc->walk_dir);if(stallgirl1_npc->anim_frame_count!=0){stallgirl1_npc->anim_frame_count=3;NPC_animate(&stallgirl1_npc);}}}}
		else if(stallgirl1_npc->AI==1){if(stallgirl1_npc->walk_dir==UP||stallgirl1_npc->walk_dir==DOWN)NPC_animate_stand_dir(&stallgirl1_npc,LEFT);else NPC_animate_stand_dir(&stallgirl1_npc,UP);stallgirl1_npc->vbls=r(120);stallgirl1_npc->AI=0;}
		else if(stallgirl1_npc->AI==2){if(stallgirl1_npc->walk_dir==UP||stallgirl1_npc->walk_dir==DOWN)NPC_animate_stand_dir(&stallgirl1_npc,RIGHT);else NPC_animate_stand_dir(&stallgirl1_npc,DOWN);stallgirl1_npc->vbls=r(120);stallgirl1_npc->AI=0;}
		else if(stallgirl1_npc->AI==3){NPC_animate(&stallgirl1_npc);stallgirl1_npc->vbls=r(120);stallgirl1_npc->AI=0;}

		if(ACTION_range_xy_xy(20*8,13*8,22*8,14*8,"Talk To Freshening Up Woman"))
		{
			TEXT_set_sprite_window(0,stallgirl1_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}

	static NPC* stallgirl2_npc = NULL;
	if(stallgirl2_npc==NULL)
	{
		NPC_create_random_WOMAN_xy_feet(&stallgirl2_npc,30*8,11*8);
		//NPC_create_npc_xy_feet(&stallgirl2_npc,SPRITE,16,40,7*8,27*8);
		stallgirl2_npc->non_walkable=1;
		stallgirl2_npc->layer=2;
		NPC_animate_stand_dir(&stallgirl2_npc,DOWN);
		stallgirl2_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		stallgirl2_npc->walk_dir=stallgirl2_npc->anim_dir;
		//NPC_animate_increment_direction_frame_now(&stallgirl2_npc, stallgirl2_npc->anim_direction);
	}
	if(stallgirl2_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&stallgirl2_npc,45))NPC_stare_at_npc_not_opposite_walking_direction(&stallgirl2_npc,&PLAYER_npc);
		else if(stallgirl2_npc->AI==0){if(stallgirl2_npc->vbls>200){if(r(4)==0){stallgirl2_npc->AI=1+r(3);}else{stallgirl2_npc->vbls=0;NPC_animate_stand_dir(&stallgirl2_npc, stallgirl2_npc->walk_dir);if(stallgirl2_npc->anim_frame_count!=0){stallgirl2_npc->anim_frame_count=3;NPC_animate(&stallgirl2_npc);}}}}
		else if(stallgirl2_npc->AI==1){if(stallgirl2_npc->walk_dir==UP||stallgirl2_npc->walk_dir==DOWN)NPC_animate_stand_dir(&stallgirl2_npc,LEFT);else NPC_animate_stand_dir(&stallgirl2_npc,UP);stallgirl2_npc->vbls=r(120);stallgirl2_npc->AI=0;}
		else if(stallgirl2_npc->AI==2){if(stallgirl2_npc->walk_dir==UP||stallgirl2_npc->walk_dir==DOWN)NPC_animate_stand_dir(&stallgirl2_npc,RIGHT);else NPC_animate_stand_dir(&stallgirl2_npc,DOWN);stallgirl2_npc->vbls=r(120);stallgirl2_npc->AI=0;}
		else if(stallgirl2_npc->AI==3){NPC_animate(&stallgirl2_npc);stallgirl2_npc->vbls=r(120);stallgirl2_npc->AI=0;}

		if(ACTION_range_xy_xy(30*8,13*8,32*8,14*8,"Talk To Checking Make-Up Woman"))
		{
			TEXT_set_sprite_window(0,stallgirl2_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}

	static NPC* stallgirl3_npc = NULL;
	if(stallgirl3_npc==NULL)
	{
		NPC_create_random_WOMAN_xy_feet(&stallgirl3_npc,40*8,11*8);
		//NPC_create_npc_xy_feet(&stallgirl3_npc,SPRITE,16,40,7*8,27*8);
		stallgirl3_npc->non_walkable=1;
		stallgirl3_npc->layer=2;
		NPC_animate_stand_dir(&stallgirl3_npc,DOWN);
		stallgirl3_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		stallgirl3_npc->walk_dir=stallgirl3_npc->anim_dir;
		//NPC_animate_increment_direction_frame_now(&stallgirl3_npc, stallgirl3_npc->anim_direction);
	}
	if(stallgirl3_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&stallgirl3_npc,45))NPC_stare_at_npc_not_opposite_walking_direction(&stallgirl3_npc,&PLAYER_npc);
		else if(stallgirl3_npc->AI==0){if(stallgirl3_npc->vbls>200){if(r(4)==0){stallgirl3_npc->AI=1+r(3);}else{stallgirl3_npc->vbls=0;NPC_animate_stand_dir(&stallgirl3_npc, stallgirl3_npc->walk_dir);if(stallgirl3_npc->anim_frame_count!=0){stallgirl3_npc->anim_frame_count=3;NPC_animate(&stallgirl3_npc);}}}}
		else if(stallgirl3_npc->AI==1){if(stallgirl3_npc->walk_dir==UP||stallgirl3_npc->walk_dir==DOWN)NPC_animate_stand_dir(&stallgirl3_npc,LEFT);else NPC_animate_stand_dir(&stallgirl3_npc,UP);stallgirl3_npc->vbls=r(120);stallgirl3_npc->AI=0;}
		else if(stallgirl3_npc->AI==2){if(stallgirl3_npc->walk_dir==UP||stallgirl3_npc->walk_dir==DOWN)NPC_animate_stand_dir(&stallgirl3_npc,RIGHT);else NPC_animate_stand_dir(&stallgirl3_npc,DOWN);stallgirl3_npc->vbls=r(120);stallgirl3_npc->AI=0;}
		else if(stallgirl3_npc->AI==3){NPC_animate(&stallgirl3_npc);stallgirl3_npc->vbls=r(120);stallgirl3_npc->AI=0;}

		if(ACTION_range_xy_xy(40*8,13*8,42*8,14*8,"Talk To Powdering Nose Woman"))
		{
			TEXT_set_sprite_window(0,stallgirl3_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}

	if(walking_into_door(RANGE_TOWNMovieTheatreWomensBathroomToMovieTheatreMainHall))
	{
		MAP_change_map(MAP_bobsgame_TOWNMovieTheatreMainHall,92,15);return;
	}
}
void bobsgame_TOWNMovieTheatreWomensBathroom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_TOWNMovieTheatreWomensBathroom_Map_VBL_Function()
{

}

void bobsgame_TOWNMovieTheatreWomensBathroom_Map_HBL_Function()
{

}

//========================================================
//TOWNMovieTheaterBuffer
//========================================================
void bobsgame_TOWNMovieTheaterBuffer_Map_Load_Function()
{
//NPC_create_sprite(&angryrobotsposter,64,64,120,120);
//NPC_create_sprite(&alienposter,64,64,184,120);
//NPC_create_sprite(&pingthemovie,64,64,312,120);
//NPC_create_sprite(&vampireromance,64,64,376,120);
//RANGE_TOWNMovieTheatreBufferToMovieTheatreMainHall 3*8,40*8,9*8,41*8
//RANGE_TOWNMovieTheatreBufferToMovieTheaterInsideLeft 10*8,13*8,11*8,19*8
//RANGE_TOWNMovieTheatreBufferToMovieTheaterInsideRight 57*8,13*8,58*8,19*8
}

void bobsgame_TOWNMovieTheaterBuffer_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//going into a movie people come from door, to both entrances
//6,40 door to 6,27 split
//6,17->9,17
//61,27 61,17->59,17
int exit_or_enter_switch=0;
	if(exit_or_enter_switch==1)
	{
		static NPC* entering_npcs[30] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
		int c=0;
		for(c=0;c<30;c++)
		{
			if(entering_npcs[c]==NULL&&CLOCK_second/10==c%6)
			{
				NPC_create_random_ADULT_OR_CHILD_xy_feet(&entering_npcs[c],6*8,40*8);
				entering_npcs[c]->non_walkable=1;
				entering_npcs[c]->AI=1;
				entering_npcs[c]->walking_speed=SPEED_NORMAL+r(SPEED_SLOW-SPEED_FASTEST);
				entering_npcs[c]->ignore_fx_layer=1;
				NPC_animate_stand_dir(&entering_npcs[c], UP);
			}
			if(entering_npcs[c]!=NULL)
			{
				if(entering_npcs[c]!=NULL)if(entering_npcs[c]->AI== 1)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&entering_npcs[c],entering_npcs[c]->walking_speed, entering_npcs[c]->MAP_x+8,27*8)==1){entering_npcs[c]->AI+=(r(2))+1;}
				if(entering_npcs[c]!=NULL)if(entering_npcs[c]->AI== 2)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&entering_npcs[c],entering_npcs[c]->walking_speed, entering_npcs[c]->MAP_x+8,17*8)==1){entering_npcs[c]->AI+=2;}
				if(entering_npcs[c]!=NULL)if(entering_npcs[c]->AI== 3)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&entering_npcs[c],entering_npcs[c]->walking_speed, 61*8,-1)==1){entering_npcs[c]->AI+=2;}
				if(entering_npcs[c]!=NULL)if(entering_npcs[c]->AI== 4)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&entering_npcs[c],entering_npcs[c]->walking_speed, 9*8,-1)==1){NPC_delete_npc(&entering_npcs[c]);}
				if(entering_npcs[c]!=NULL)if(entering_npcs[c]->AI== 5)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&entering_npcs[c],entering_npcs[c]->walking_speed, entering_npcs[c]->MAP_x+8,17*8)==1){entering_npcs[c]->AI++;}
				if(entering_npcs[c]!=NULL)if(entering_npcs[c]->AI== 6)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&entering_npcs[c],entering_npcs[c]->walking_speed, 59*8,-1)==1){NPC_delete_npc(&entering_npcs[c]);}
			}
		}
	}
	if(exit_or_enter_switch==0)
	{
		//leaving movie people come from theatre exits leave to hallway
		static NPC* exiting_npcs[10] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
		int c=0;
		for(c=0;c<10;c++)
		{
			if(exiting_npcs[c]==NULL&&CLOCK_second/10==c%6)
			{
				int randnum=r(2);
				if(randnum==0)NPC_create_random_ADULT_OR_CHILD_xy_feet(&exiting_npcs[c],9*8,17*8);
				if(randnum==1)NPC_create_random_ADULT_OR_CHILD_xy_feet(&exiting_npcs[c],59*8,17*8);
				exiting_npcs[c]->non_walkable=1;
				exiting_npcs[c]->AI=randnum+1;
				exiting_npcs[c]->walking_speed=SPEED_NORMAL+r(SPEED_SLOW-SPEED_FASTEST);
				exiting_npcs[c]->ignore_fx_layer=1;
				NPC_animate_stand_dir(&exiting_npcs[c], DOWN);
			}
			if(exiting_npcs[c]!=NULL)
			{
				if(exiting_npcs[c]!=NULL)if(exiting_npcs[c]->AI== 1)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&exiting_npcs[c],exiting_npcs[c]->walking_speed, 6*8,-1)==1){exiting_npcs[c]->AI+=2;}
				if(exiting_npcs[c]!=NULL)if(exiting_npcs[c]->AI== 2)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&exiting_npcs[c],exiting_npcs[c]->walking_speed, exiting_npcs[c]->MAP_x+8,27*8)==1){exiting_npcs[c]->AI+=2;}
				if(exiting_npcs[c]!=NULL)if(exiting_npcs[c]->AI== 3)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&exiting_npcs[c],exiting_npcs[c]->walking_speed, exiting_npcs[c]->MAP_x+8,39*8)==1){NPC_delete_npc(&exiting_npcs[c]);}
				if(exiting_npcs[c]!=NULL)if(exiting_npcs[c]->AI== 4)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&exiting_npcs[c],exiting_npcs[c]->walking_speed, 6*8,-1)==1){exiting_npcs[c]->AI++;}
				if(exiting_npcs[c]!=NULL)if(exiting_npcs[c]->AI== 5)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&exiting_npcs[c],exiting_npcs[c]->walking_speed, exiting_npcs[c]->MAP_x+8,39*8)==1){NPC_delete_npc(&exiting_npcs[c]);}
			}
		}
	}
	//TODO:need crowd murmur
	if(walking_into_door(RANGE_TOWNMovieTheatreBufferToMovieTheatreMainHall))
	{
		MAP_change_map(MAP_bobsgame_TOWNMovieTheatreMainHall,8,16);return;
	}
	if(walking_into_door(RANGE_TOWNMovieTheatreBufferToMovieTheaterInsideLeft))
	{
		MAP_change_map(MAP_bobsgame_TOWNMovieTheatreInside,2,63);return;
	}
	if(walking_into_door(RANGE_TOWNMovieTheatreBufferToMovieTheaterInsideRight))
	{
		MAP_change_map(MAP_bobsgame_TOWNMovieTheatreInside,46,63);return;
	}
}
void bobsgame_TOWNMovieTheaterBuffer_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_TOWNMovieTheaterBuffer_Map_VBL_Function()
{

}

void bobsgame_TOWNMovieTheaterBuffer_Map_HBL_Function()
{

}

//========================================================
//TOWNMovieTheatreInside
//========================================================
void bobsgame_TOWNMovieTheatreInside_Map_Load_Function()
{
//RANGE_TOWNMovieTheatreInsideToMovieTheatreBufferLeft 1*8,62*8,2*8,67*8
//RANGE_TOWNMovieTheatreInsideToMovieTheatreBufferRight 48*8,62*8,49*8,67*8
}

void bobsgame_TOWNMovieTheatreInside_Map_Run_Function(int MAP_just_loaded)
{

static int frame[11]={0,0,0,0,0,0,0,0,0,0,0};
static int timer[11]={0,0,0,0,0,0,0,0,0,0,0};
static int lastvbltimer = 0;
static int lastvbltimer2 = 0;

	if(MAP_just_loaded==1)
	{
		int n=0;for(n=0;n<11;n++){frame[n]=0;timer[n]=0;}
		lastvbltimer = 0;
		lastvbltimer2= 0;

	}

	//animate all the people,

//2-9, 16-17
//24
//32
//40
//48
//56
//64
//72
//80
//2-7,88
//2-5,96

	if(lastvbltimer!=vbl_5_var)
	{
		lastvbltimer=vbl_5_var;

		int c=0;
		for(c=0;c<11;c++)
		{

			if(frame[c]!=2&&timer[c]==0)
			{
				int x=0;
				int y=0;

				frame[c]=2;

				int xmax=80;
				int xstart=72;

				if(c== 0){y=  0;}
				if(c== 1){y=  8;}
				if(c== 2){y= 16;}
				if(c== 3){y= 24;}
				if(c== 4){y= 32;}
				if(c== 5){y= 40;}
				if(c== 6){y= 48;}
				if(c== 7){y= 56;}
				if(c== 8){y= 64;}
				if(c== 9){y= 72;xmax=78;}
				if(c==10){y= 80;xmax=76;}

				for(x=xstart;x<xmax;x++)
				{
					///TODO: MUST FIX THIS!!!
					///HARDWARE_set_tile_gfx_to_tile(1,1,HARDWARE_map_1[HARDWARE_map_width_tiles*y+x],HARDWARE_map_1[HARDWARE_map_width_tiles*(y+frame[c])+x]);
					///HARDWARE_set_tile_gfx_to_tile(1,1,HARDWARE_map_1[HARDWARE_map_width_tiles*(y+1)+x],HARDWARE_map_1[HARDWARE_map_width_tiles*(y+frame[c]+1)+x]);
				}
			}
			if(timer[c]>0)timer[c]--;
		}
	}

	if(lastvbltimer2!=vbl_5_var)
	{
		lastvbltimer2=vbl_5_var;

		int x=0;
		int y=0;

		int t=0;
		int m=r(2);

		for(t=0;t<m;t++)
		{
			int c=r(11);

			if(frame[c]==2)frame[c]=2+((1+r(2))*2);
			timer[c]=1+r(5);

			int xmax=80;
			int xstart=72;

			if(c== 0){y=  0;}
			if(c== 1){y=  8;}
			if(c== 2){y= 16;}
			if(c== 3){y= 24;}
			if(c== 4){y= 32;}
			if(c== 5){y= 40;}
			if(c== 6){y= 48;}
			if(c== 7){y= 56;}
			if(c== 8){y= 64;}
			if(c== 9){y= 72;xmax=78;}
			if(c==10){y= 80;xmax=76;}

			xstart=72+(r(5))*2;
			if(xmax>xstart+2)xmax=xstart+2;

			for(x=xstart;x<xmax;x++)
			{
				///TODO: MUST FIX THIS!!!
				///HARDWARE_set_tile_gfx_to_tile(1,1,HARDWARE_map_1[HARDWARE_map_width_tiles*y+x],HARDWARE_map_1[HARDWARE_map_width_tiles*(y+frame[c])+x]);
				///HARDWARE_set_tile_gfx_to_tile(1,1,HARDWARE_map_1[HARDWARE_map_width_tiles*(y+1)+x],HARDWARE_map_1[HARDWARE_map_width_tiles*(y+frame[c]+1)+x]);
			}
		}
	}

//TODO: need usher with flashlight
//TODO: need movie scene
//TODO: sit down in front row "my neck hurts"
	if(walking_into_door(RANGE_TOWNMovieTheatreInsideToMovieTheatreBufferLeft))
	{
		MAP_change_map(MAP_bobsgame_TOWNMovieTheaterBuffer,8,16);return;
	}
	if(walking_into_door(RANGE_TOWNMovieTheatreInsideToMovieTheatreBufferRight))
	{
		MAP_change_map(MAP_bobsgame_TOWNMovieTheaterBuffer,58,16);return;
	}
}
void bobsgame_TOWNMovieTheatreInside_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_TOWNMovieTheatreInside_Map_VBL_Function()
{

}

void bobsgame_TOWNMovieTheatreInside_Map_HBL_Function()
{

}



