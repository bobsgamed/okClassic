//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================


#include "../../main.h"



#define RANGE_CITYGroovyClubEntranceToOUTSIDECity 10*8,25*8,16*8,26*8
#define RANGE_CITYGroovyClubEntranceToGroovyClub 47*8,9*8,51*8,10*8
#define RANGE_CITYGroovyClubToGroovyClubEntrance 47*8,75*8,51*8,76*8

//========================================================
//CITYGroovyClubEntrance
//========================================================
void bobsgame_CITYGroovyClubEntrance_Map_Load_Function()
{
//RANGE_CITYGroovyClubEntranceToOUTSIDECity 10*8,25*8,16*8,26*8
//RANGE_CITYGroovyClubEntranceToGroovyClub 47*8,9*8,51*8,10*8
}
void bobsgame_CITYGroovyClubEntrance_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}
	static NPC* groovyticketguy_npc = NULL;
	if(groovyticketguy_npc==NULL)
	{
		NPC_create_npc_xy_feet(&groovyticketguy_npc,GFX_ADULT_GENERICmanlongsleeves,16,40,9*8,12*8);
		groovyticketguy_npc->non_walkable=1;
		groovyticketguy_npc->pushable=1;
		groovyticketguy_npc->layer=2;
	}
	else if(groovyticketguy_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&groovyticketguy_npc,60))NPC_stare_at_npc(&groovyticketguy_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&groovyticketguy_npc, DOWN);
		if(ACTION_range_xy_xy(7*8,13*8,11*8,14*8,"Purchase Ticket"))
		{
			TEXT_set_sprite_window(0,groovyticketguy_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);//TODO: buy a ticket in
		}
		//TODO: need club ticket girl
	}

	static NPC* groovybouncer_npc = NULL;
	if(groovybouncer_npc==NULL)
	{
		NPC_create_npc_xy_feet(&groovybouncer_npc,GFX_ADULT_GENERICmanbeardbaldingtshirt2,16,40,48*8,11*8);
		groovybouncer_npc->non_walkable=1;
		//groovybouncer_npc->pushable=1;
		groovybouncer_npc->layer=2;
	}
	else if(groovybouncer_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&groovybouncer_npc,30))NPC_stare_at_npc(&groovybouncer_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&groovybouncer_npc, DOWN);
		if(ACTION_npc(&groovybouncer_npc,"Talk To Bouncer"))
		{
			TEXT_set_sprite_window(0,groovybouncer_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);//TODO: need bouncer sprite
			//TODO: checks your clothes, hair, ticket, lets you in. otherwise get ejected, kicked outside "get outta here, square."
			//TODO: not allowed past rope.
		}
	}
//4,20 left ads
//23,10 up posters
//22,22 down ads

//door 13 25  to 15,19
//line 28,18 28,15 32,15 32,20 37,20 37,14 42,14 42,20 49,20 49,12 look left, pause, 49,9 delete
	int c=0;
	static NPC* line_npcs[20] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	for(c=0;c<20;c++)
	{
		if(line_npcs[c]==NULL&&CLOCK_second%10==0)
		{
			CLOCK_second++;
			NPC_create_random_ADULT_OR_CHILD_xy_feet(&line_npcs[c],13*8,25*8);
			line_npcs[c]->non_walkable=1;
			line_npcs[c]->AI=1;
			line_npcs[c]->walking_speed=SPEED_NORMAL+r(SPEED_SLOW-SPEED_FASTEST);
			line_npcs[c]->ignore_fx_layer=1;
			NPC_animate_stand_dir(&line_npcs[c], UP);
		}
		if(line_npcs[c]!=NULL)
		{
			if(line_npcs[c]->AI== 1)if(NPC_walk_to_xy_intelligenthit_stopforothers_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 15*8,19*8)==(1))line_npcs[c]->AI++;
			if(line_npcs[c]->AI== 2)if(NPC_walk_to_xy_intelligenthit_stopforothers_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 28*8,18*8)==(1))line_npcs[c]->AI++;
			if(line_npcs[c]->AI== 3)if(NPC_walk_to_xy_intelligenthit_stopforothers_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 28*8,15*8)==(1))line_npcs[c]->AI++;
			if(line_npcs[c]->AI== 4)if(NPC_walk_to_xy_intelligenthit_stopforothers_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 32*8,15*8)==(1))line_npcs[c]->AI++;
			if(line_npcs[c]->AI== 5)if(NPC_walk_to_xy_intelligenthit_stopforothers_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 32*8,20*8)==(1))line_npcs[c]->AI++;
			if(line_npcs[c]->AI== 6)if(NPC_walk_to_xy_intelligenthit_stopforothers_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 37*8,20*8)==(1))line_npcs[c]->AI++;
			if(line_npcs[c]->AI== 7)if(NPC_walk_to_xy_intelligenthit_stopforothers_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 37*8,14*8)==(1))line_npcs[c]->AI++;
			if(line_npcs[c]->AI== 8)if(NPC_walk_to_xy_intelligenthit_stopforothers_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 42*8,14*8)==(1))line_npcs[c]->AI++;
			if(line_npcs[c]->AI== 9)if(NPC_walk_to_xy_intelligenthit_stopforothers_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 42*8,20*8)==(1))line_npcs[c]->AI++;
			if(line_npcs[c]->AI==10)if(NPC_walk_to_xy_intelligenthit_stopforothers_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 50*8,20*8)==(1))line_npcs[c]->AI++;
			if(line_npcs[c]->AI==11)if(NPC_walk_to_xy_intelligenthit_stopforothers_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 50*8,14*8)==(1)){line_npcs[c]->AI++;line_npcs[c]->vbls=0;}
			if(line_npcs[c]->AI==12)if(line_npcs[c]->vbls>60){line_npcs[c]->AI++;}
			if(line_npcs[c]->AI==13)if(NPC_walk_to_xy_nohit_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 50*8,11*8)==(1)){line_npcs[c]->AI++;line_npcs[c]->vbls=0;NPC_animate_stand_dir(&line_npcs[c], LEFT);}
			if(line_npcs[c]->AI==14)if(line_npcs[c]->vbls>60){line_npcs[c]->AI++;}
			if(line_npcs[c]->AI==15)if(NPC_walk_to_xy_nohit_pushmain(&line_npcs[c],line_npcs[c]->walking_speed,50*8,9*8)==(1)){NPC_delete_npc(&line_npcs[c]);}
		}
	}

	if(walking_into_door(RANGE_CITYGroovyClubEntranceToOUTSIDECity))
	{
		MAP_change_map(MAP_bobsgame_CITYCity,324,37);return;
	}
	if(walking_into_door(RANGE_CITYGroovyClubEntranceToGroovyClub))
	{
		MAP_change_map(MAP_bobsgame_CITYGroovyClub,48,74);return;
	}

}
void bobsgame_CITYGroovyClubEntrance_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYGroovyClubEntrance_Map_VBL_Function()
{

}
void bobsgame_CITYGroovyClubEntrance_Map_HBL_Function()
{

}

//========================================================
//CITYGroovyClub
//========================================================
void bobsgame_CITYGroovyClub_Map_Load_Function()
{
//RANGE_CITYGroovyClubToGroovyClubEntrance 47*8,75*8,51*8,76*8
			current_mod = mods[5];
			HARDWARE_stop_music();
			HARDWARE_play_music("disko",64);
}
void bobsgame_CITYGroovyClub_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}
	static NPC* groovydj_npc = NULL;
	if(groovydj_npc==NULL)
	{
		NPC_create_npc_xy_feet(&groovydj_npc,GFX_ADULT_GENERICmanlongsleeves,16,40,39*8,12*8);
		groovydj_npc->non_walkable=1;
		//groovydj_npc->pushable=1;
		groovydj_npc->layer=3;
		NPC_animate_stand_dir(&groovydj_npc, DOWN);
	}
	else if(groovydj_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&groovydj_npc,30))NPC_stare_at_npc(&groovydj_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&groovydj_npc, DOWN);
		if(ACTION_range_xy_xy(37*8,15*8,41*8,16*8,"Talk To DJ"))
		{
			TEXT_set_sprite_window(0,groovydj_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);//TODO: need dj sprite
			//request music
		}
	}
	//dance floor lights
	if(groovydj_npc->vbls>30)
	{
		groovydj_npc->vbls=0;
		static int cycle=0;
		if(cycle==0)
		{
			///TODO: MUST FIX!!!
			///HARDWARE_set_tile_gfx_to_tile(1,3,HARDWARE_map_3[0],HARDWARE_map_3[3]);
			///HARDWARE_set_tile_gfx_to_tile(1,3,HARDWARE_map_3[1],HARDWARE_map_3[4]);
			///HARDWARE_set_tile_gfx_to_tile(1,3,HARDWARE_map_3[2],HARDWARE_map_3[5]);
			cycle=1;
		}
			else if(cycle==1)
			{
				///HARDWARE_set_tile_gfx_to_tile(1,3,HARDWARE_map_3[0],HARDWARE_map_3[6]);
				///HARDWARE_set_tile_gfx_to_tile(1,3,HARDWARE_map_3[1],HARDWARE_map_3[4]);
				///HARDWARE_set_tile_gfx_to_tile(1,3,HARDWARE_map_3[2],HARDWARE_map_3[5]);
				cycle=2;
			}
				else if(cycle==2)
				{
					///HARDWARE_set_tile_gfx_to_tile(1,3,HARDWARE_map_3[0],HARDWARE_map_3[3]);
					///HARDWARE_set_tile_gfx_to_tile(1,3,HARDWARE_map_3[1],HARDWARE_map_3[7]);
					///HARDWARE_set_tile_gfx_to_tile(1,3,HARDWARE_map_3[2],HARDWARE_map_3[5]);
					cycle=3;
				}
					else if(cycle==3)
					{
						///HARDWARE_set_tile_gfx_to_tile(1,3,HARDWARE_map_3[0],HARDWARE_map_3[3]);
						///HARDWARE_set_tile_gfx_to_tile(1,3,HARDWARE_map_3[1],HARDWARE_map_3[4]);
						///HARDWARE_set_tile_gfx_to_tile(1,3,HARDWARE_map_3[2],HARDWARE_map_3[8]);
						cycle=1;
					}
	}
	//do shadow
	static int lastdjtimer = 0;
	if(lastdjtimer!=groovydj_npc->vbls)
	{
		lastdjtimer=groovydj_npc->vbls;
		///int tile = lastdjtimer%8;
		///HARDWARE_set_tile_gfx_to_tile(1,0,HARDWARE_map_0[0],HARDWARE_map_0[1+tile]);
		///HARDWARE_set_tile_gfx_to_tile(1,0,HARDWARE_map_0[9],HARDWARE_map_0[10+tile]);
	}
	//dancers
	//randomly move to the beat
	int c=0;
	static NPC* dance_npcs[30] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	for(c=0;c<1;c++)
	{
		if(dance_npcs[c]==NULL)
		{

			if(c==0)NPC_create_npc_xy_feet(&dance_npcs[c],GFX_ADULT_momo,16,40,(r(48-22)+22)*8,(r(51-25)+25)*8);
			else NPC_create_random_ADULT_OR_CHILD_xy_feet(&dance_npcs[c],(r(48-22)+22)*8,(r(51-25)+25)*8); //22,25  48,51
			dance_npcs[c]->non_walkable=1;
			dance_npcs[c]->pushable=1;
			dance_npcs[c]->AI=r(2);
			dance_npcs[c]->walking_speed=SPEED_SLOWEST-r(SPEED_FAST-SPEED_FASTEST);
			dance_npcs[c]->walk_dir=r(4);
			dance_npcs[c]->pixels_to_walk=r(30);
			//dance_npcs[c]->ignore_fx_layer=1;
			NPC_animate_stand_dir(&dance_npcs[c], UP);
		}
		if(dance_npcs[c]!=NULL)
		{


			if(dance_npcs[c]->AI==0)
			{
				//random walk
				if(dance_npcs[c]->vbls>30)
				{
					if(NPC_walk_randomly_within_xy_xy(&dance_npcs[c],22*8,25*8,48*8,51*8)==(1)){dance_npcs[c]->vbls=1;dance_npcs[c]->pixels_to_walk=r(30);dance_npcs[c]->walk_dir=r(4);}
				}
				else if(dance_npcs[c]->vbls%10==0)NPC_animate(&dance_npcs[c]);
			}
			else
			if(dance_npcs[c]->AI==1)
			{
				//just walk in place in circles
				//if(dance_npcs[c]->vbl_timer>30)
				{
					if(dance_npcs[c]->vbls%10==0){NPC_animate(&dance_npcs[c]);dance_npcs[c]->pixels_to_walk--;dance_npcs[c]->vbls=1;}

					if(dance_npcs[c]->pixels_to_walk<=0){dance_npcs[c]->pixels_to_walk=r(30);dance_npcs[c]->walk_dir=r(4);}
					//dance_npcs[c]->vbl_timer=0;
				}

			}

		//NPC_randomly_twitch_around_room(&dance_npcs[c]);
			//if(dance_npcs[c]->cycle==0)
		}
	}

	static int last_second=0;
	if(last_second!=CLOCK_second&&CLOCK_second%30==0)for(c=0;c<1;c++){last_second=CLOCK_second;if(dance_npcs[c]->AI==1)dance_npcs[c]->AI=0;else if(dance_npcs[c]->AI==0)dance_npcs[c]->AI=1;}
	//people sitting at tables, bar
	//waitress
	//4,56 up
	//4,72 up
	//16.66 right
	//21,66 left
	//29,66 right
	//34,66 left
	//10,38 left bar
	//10,32 left
	//10,26 left
	//10,20 left

	static NPC* table_npcs[8] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	for(c=0;c<8;c++)
	{
		if(table_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			int dir=0;
			if(c==0){x= 4;y=56;dir=UP;}
			if(c==1){x= 4;y=72;dir=UP;}
			if(c==2){x=16;y=66;dir=RIGHT;}
			if(c==3){x=21;y=66;dir=LEFT;}
			if(c==4){x=29;y=66;dir=RIGHT;}
			if(c==5){x=10;y=38;dir=LEFT;}
			if(c==6){x=10;y=32;dir=LEFT;}
			if(c==7){x=10;y=20;dir=LEFT;}
			NPC_create_random_ADULT_OR_CHILD_xy_feet(&table_npcs[c],x*8,(y*8)+3);
			table_npcs[c]->non_walkable=1;
			NPC_animate_stand_dir(&table_npcs[c], dir);
			table_npcs[c]->walk_dir=dir;
		}
		if(table_npcs[c]!=NULL)
		{
			if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&table_npcs[c],30))NPC_stare_at_npc(&table_npcs[c],&PLAYER_npc);
			else NPC_animate_stand_dir(&table_npcs[c], table_npcs[c]->walk_dir);
		}
	}

//6, 18-41 waitress
//up, stop, face right, up, stop, face right 4,38 left bottles 4,18 left fridge
	static NPC* barmaid_npc = NULL;
	if(barmaid_npc==NULL)
	{
		NPC_create_npc_xy_feet(&barmaid_npc,GFX_ADULT_GENERICwomanlonghair,16,40,5*8,18*8);
		barmaid_npc->non_walkable=1;
		//barmaid_npc->pushable=1;
		barmaid_npc->layer=3;
		NPC_animate_stand_dir(&barmaid_npc, RIGHT);
		barmaid_npc->vbls=0;
	}
	else if(barmaid_npc!=NULL)
	{
		if(barmaid_npc->AI== 0)if(NPC_walk_to_xy_nohit(&barmaid_npc,SPEED_NORMAL, 6*8,19*8)==(1)){NPC_animate_stand_dir(&barmaid_npc, RIGHT);if(barmaid_npc->vbls>120){barmaid_npc->AI=r(6);barmaid_npc->vbls=0;}}
		if(barmaid_npc->AI== 1)if(NPC_walk_to_xy_nohit(&barmaid_npc,SPEED_NORMAL, 6*8,24*8)==(1)){NPC_animate_stand_dir(&barmaid_npc, RIGHT);if(barmaid_npc->vbls>120){barmaid_npc->AI=r(6);barmaid_npc->vbls=0;}}
		if(barmaid_npc->AI== 2)if(NPC_walk_to_xy_nohit(&barmaid_npc,SPEED_NORMAL, 6*8,35*8)==(1)){NPC_animate_stand_dir(&barmaid_npc, RIGHT);if(barmaid_npc->vbls>120){barmaid_npc->AI=r(6);barmaid_npc->vbls=0;}}
		if(barmaid_npc->AI== 3)if(NPC_walk_to_xy_nohit(&barmaid_npc,SPEED_NORMAL, 6*8,30*8)==(1)){NPC_animate_stand_dir(&barmaid_npc, RIGHT);if(barmaid_npc->vbls>120){barmaid_npc->AI=r(6);barmaid_npc->vbls=0;}}
		if(barmaid_npc->AI== 4)if(NPC_walk_to_xy_nohit(&barmaid_npc,SPEED_NORMAL, 5*8,36*8)==(1)){NPC_animate_stand_dir(&barmaid_npc, LEFT);if(barmaid_npc->vbls>120){barmaid_npc->AI=r(6);barmaid_npc->vbls=0;}}
		if(barmaid_npc->AI== 5)if(NPC_walk_to_xy_nohit(&barmaid_npc,SPEED_NORMAL, 5*8,18*8)==(1)){NPC_animate_stand_dir(&barmaid_npc, LEFT);if(barmaid_npc->vbls>120){barmaid_npc->AI=r(6);barmaid_npc->vbls=0;}}
	}

	if(walking_into_door(RANGE_CITYGroovyClubToGroovyClubEntrance))
	{
		MAP_change_map(MAP_bobsgame_CITYGroovyClubEntrance,48,10);return;
	}

}
void bobsgame_CITYGroovyClub_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYGroovyClub_Map_VBL_Function()
{

}
void bobsgame_CITYGroovyClub_Map_HBL_Function()
{

}



