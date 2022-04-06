//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================

#include "../../main.h"


#define RANGE_CITYCasinoEntranceToOUTSIDECity1 34*8,49*8,40*8,50*8
#define RANGE_CITYCasinoEntranceToOUTSIDECity2 42*8,49*8,48*8,50*8
#define RANGE_CITYCasinoEntranceToOUTSIDECity3 50*8,49*8,56*8,50*8
#define RANGE_CITYCasinoEntranceToOUTSIDECity4 58*8,49*8,64*8,50*8
#define RANGE_CITYCasinoEntranceToMain 46*8,9*8,52*8,10*8
#define RANGE_CITYCasinoMainToEntrance 46*8,81*8,52*8,82*8
#define RANGE_CITYCasinoMainToBackRoom 5*8,9*8,9*8,10*8
#define RANGE_CITYCasinoBackRoomToMain 5*8,22*8,9*8,23*8


//========================================================
//CITYCasinoEntrance
//========================================================
void bobsgame_CITYCasinoEntrance_Map_Load_Function()
{
//RANGE_CITYCasinoEntranceToOUTSIDECity1 34*8,49*8,40*8,50*8
//RANGE_CITYCasinoEntranceToOUTSIDECity2 42*8,49*8,48*8,50*8
//RANGE_CITYCasinoEntranceToOUTSIDECity3 50*8,49*8,56*8,50*8
//RANGE_CITYCasinoEntranceToOUTSIDECity4 58*8,49*8,64*8,50*8
//RANGE_CITYCasinoEntranceToMain 46*8,9*8,52*8,10*8
}
void bobsgame_CITYCasinoEntrance_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//TODO: need bunny girls

	static NPC* clerk1 = NULL;
	if(clerk1==NULL)
	{
		NPC_create_random_ADULT_xy_feet(&clerk1,41*8,31*8);
		//NPC_create_npc_xy_feet(&casinoclerk1_npc,casinoclerk1,16,40,18*8,15*8);
		clerk1->non_walkable=1;
		clerk1->layer=3;
		NPC_animate_stand_dir(&clerk1,DOWN);
		clerk1->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		clerk1->walk_dir=clerk1->anim_dir;
		//NPC_animate_increment_direction_frame_now(&casinoclerk1_npc, casinoclerk1_npc->anim_direction);

	}
	if(clerk1!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&clerk1,45))NPC_stare_at_npc_not_opposite_walking_direction(&clerk1,&PLAYER_npc);
		else
		{
			if(clerk1->AI==0){if(clerk1->vbls>200){if(r(4)==0){clerk1->AI=1+r(3);}else{clerk1->vbls=0;NPC_animate_stand_dir(&clerk1, clerk1->walk_dir);}}}
			if(clerk1->AI==1){if(clerk1->walk_dir==UP||clerk1->walk_dir==DOWN)NPC_animate_stand_dir(&clerk1,LEFT);else NPC_animate_stand_dir(&clerk1,UP);clerk1->vbls=r(120);clerk1->AI=0;}
			if(clerk1->AI==2){if(clerk1->walk_dir==UP||clerk1->walk_dir==DOWN)NPC_animate_stand_dir(&clerk1,RIGHT);else NPC_animate_stand_dir(&clerk1,DOWN);clerk1->vbls=r(120);clerk1->AI=0;}
			if(clerk1->AI==3){NPC_animate(&clerk1);clerk1->vbls=r(120);clerk1->AI=0;}
		}

		if(ACTION_range_xy_xy(41*8,33*8,43*8,34*8,"Talk To Casino Clerk"))
		{
			TEXT_set_sprite_window(0,clerk1,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("" //?
			);
		}
	}

	static NPC* clerk2 = NULL;
	if(clerk2==NULL)
	{
		NPC_create_random_ADULT_xy_feet(&clerk2,46*8,31*8);
		//NPC_create_npc_xy_feet(&casinoclerk2_npc,casinoclerk2,16,40,18*8,15*8);

		clerk2->non_walkable=1;
		clerk2->layer=3;
		NPC_animate_stand_dir(&clerk2,DOWN);

		clerk2->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		clerk2->walk_dir=clerk2->anim_dir;

		//NPC_animate_increment_direction_frame_now(&casinoclerk2_npc, casinoclerk2_npc->anim_direction);

	}
	if(clerk2!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&clerk2,45))NPC_stare_at_npc_not_opposite_walking_direction(&clerk2,&PLAYER_npc);
		else
		{
			if(clerk2->AI==0){if(clerk2->vbls>200){if(r(4)==0){clerk2->AI=1+r(3);}else{clerk2->vbls=0;NPC_animate_stand_dir(&clerk2, clerk2->walk_dir);}}}
			if(clerk2->AI==1){if(clerk2->walk_dir==UP||clerk2->walk_dir==DOWN)NPC_animate_stand_dir(&clerk2,LEFT);else NPC_animate_stand_dir(&clerk2,UP);clerk2->vbls=r(120);clerk2->AI=0;}
			if(clerk2->AI==2){if(clerk2->walk_dir==UP||clerk2->walk_dir==DOWN)NPC_animate_stand_dir(&clerk2,RIGHT);else NPC_animate_stand_dir(&clerk2,DOWN);clerk2->vbls=r(120);clerk2->AI=0;}
			if(clerk2->AI==3){NPC_animate(&clerk2);clerk2->vbls=r(120);clerk2->AI=0;}
		}

		if(ACTION_range_xy_xy(46*8,33*8,48*8,34*8,"Talk To Casino Clerk"))
		{
			TEXT_set_sprite_window(0,clerk2,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("" //?
			);
		}
	}

	static NPC* clerk3 = NULL;
	if(clerk3==NULL)
	{
		NPC_create_random_ADULT_xy_feet(&clerk3,52*8,31*8);
		//NPC_create_npc_xy_feet(&casinoclerk3_npc,casinoclerk3,16,40,18*8,15*8);

		clerk3->non_walkable=1;
		clerk3->layer=3;
		NPC_animate_stand_dir(&clerk3,DOWN);

		clerk3->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		clerk3->walk_dir=clerk3->anim_dir;

		//NPC_animate_increment_direction_frame_now(&casinoclerk3_npc, casinoclerk3_npc->anim_direction);

	}
	if(clerk3!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&clerk3,45))NPC_stare_at_npc_not_opposite_walking_direction(&clerk3,&PLAYER_npc);
		else
		{
			if(clerk3->AI==0){if(clerk3->vbls>200){if(r(4)==0){clerk3->AI=1+r(3);}else{clerk3->vbls=0;NPC_animate_stand_dir(&clerk3, clerk3->walk_dir);}}}
			if(clerk3->AI==1){if(clerk3->walk_dir==UP||clerk3->walk_dir==DOWN)NPC_animate_stand_dir(&clerk3,LEFT);else NPC_animate_stand_dir(&clerk3,UP);clerk3->vbls=r(120);clerk3->AI=0;}
			if(clerk3->AI==2){if(clerk3->walk_dir==UP||clerk3->walk_dir==DOWN)NPC_animate_stand_dir(&clerk3,RIGHT);else NPC_animate_stand_dir(&clerk3,DOWN);clerk3->vbls=r(120);clerk3->AI=0;}
			if(clerk3->AI==3){NPC_animate(&clerk3);clerk3->vbls=r(120);clerk3->AI=0;}
		}

		if(ACTION_range_xy_xy(52*8,33*8,54*8,34*8,"Talk To Casino Clerk"))
		{
			TEXT_set_sprite_window(0,clerk3,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("" //?
			);
		}
	}

	static NPC* clerk4 = NULL;
	if(clerk4==NULL)
	{
		NPC_create_random_ADULT_xy_feet(&clerk4,57*8,31*8);
		//NPC_create_npc_xy_feet(&casinoclerk4_npc,casinoclerk4,16,40,18*8,15*8);

		clerk4->non_walkable=1;
		clerk4->layer=3;
		NPC_animate_stand_dir(&clerk4,DOWN);

		clerk4->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		clerk4->walk_dir=clerk4->anim_dir;

		//NPC_animate_increment_direction_frame_now(&casinoclerk4_npc, casinoclerk4_npc->anim_direction);

	}
	if(clerk4!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&clerk4,35))NPC_stare_at_npc_not_opposite_walking_direction(&clerk4,&PLAYER_npc);
		else
		{
			if(clerk4->AI==0){if(clerk4->vbls>200){if(r(4)==0){clerk4->AI=1+r(3);}else{clerk4->vbls=0;NPC_animate_stand_dir(&clerk4, clerk4->walk_dir);}}}
			if(clerk4->AI==1){if(clerk4->walk_dir==UP||clerk4->walk_dir==DOWN)NPC_animate_stand_dir(&clerk4,LEFT);else NPC_animate_stand_dir(&clerk4,UP);clerk4->vbls=r(120);clerk4->AI=0;}
			if(clerk4->AI==2){if(clerk4->walk_dir==UP||clerk4->walk_dir==DOWN)NPC_animate_stand_dir(&clerk4,RIGHT);else NPC_animate_stand_dir(&clerk4,DOWN);clerk4->vbls=r(120);clerk4->AI=0;}
			if(clerk4->AI==3){NPC_animate(&clerk4);clerk4->vbls=r(120);clerk4->AI=0;}
		}

		if(ACTION_range_xy_xy(57*8,33*8,59*8,34*8,"Talk To Casino Clerk"))
		{
			TEXT_set_sprite_window(0,clerk4,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("" //?
			);
		}
	}

//85.18 down couch
//93,26 left
//93,40 left
//5,40 right
//5,26 right
//12,18 down

	static NPC* gamblers[6] = {NULL,NULL,NULL,NULL,NULL,NULL};
	int c=0;
	for(c=0;c<6;c++)
	{
		if(gamblers[c]==NULL)
		{
			int x=0;
			int y=0;
			int dir=UP;
			int bgp=2;
			GFX* gfx=NULL;

			if(c== 0){x=86*8-4; y=18*8;dir=DOWN;	bgp=2;  }
			if(c== 1){x=13*8-4; y=18*8;dir=DOWN;	bgp=2;	}
			if(c== 2){x=93*8+2;	y=26*8-4;dir=LEFT;	bgp=2;  }
			if(c== 3){x=93*8+2;	y=40*8-4;dir=LEFT;	bgp=2;  }
			if(c== 4){x= 5*8-2;	y=40*8-4;dir=RIGHT;	bgp=2;  }
			if(c== 5){x= 5*8-2;	y=26*8-4;dir=RIGHT;	bgp=2;	}

			if(gfx==NULL)NPC_create_random_ADULT_xy_feet(&gamblers[c],x,y);
			else NPC_create_npc_xy_feet(&gamblers[c],gfx,16,40,x,y);

			NPC_animate_stand_dir(&gamblers[c], dir);
			gamblers[c]->non_walkable=1;
			gamblers[c]->walk_dir=dir;
			gamblers[c]->layer=bgp;
			//NPC_animate_increment_direction_frame_now(&casinopeople_npcs[c], dir);
		}

		if(gamblers[c]!=NULL)
		{
			if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&gamblers[c],15))NPC_stare_at_npc_not_opposite_walking_direction(&gamblers[c],&PLAYER_npc);
			else if(gamblers[c]->AI==0){if(gamblers[c]->vbls>200){if(r(4)==0){gamblers[c]->AI=1+r(3);}else{gamblers[c]->vbls=0;NPC_animate_stand_dir(&gamblers[c], gamblers[c]->walk_dir);}}}
			else if(gamblers[c]->AI==1){if(gamblers[c]->walk_dir==UP||gamblers[c]->walk_dir==DOWN)NPC_animate_stand_dir(&gamblers[c],LEFT);else NPC_animate_stand_dir(&gamblers[c],UP);gamblers[c]->vbls=r(120);gamblers[c]->AI=0;}
			else if(gamblers[c]->AI==2){if(gamblers[c]->walk_dir==UP||gamblers[c]->walk_dir==DOWN)NPC_animate_stand_dir(&gamblers[c],RIGHT);else NPC_animate_stand_dir(&gamblers[c],DOWN);gamblers[c]->vbls=r(120);gamblers[c]->AI=0;}
			else if(gamblers[c]->AI==3){NPC_animate(&gamblers[c]);gamblers[c]->vbls=r(120);gamblers[c]->AI=0;}

		}
	}

//TODO: classy music

//people milling about everywhere

//doors
//37,49
//45
//53
//61
//up to 41
//27,71
//up to 19
//49,2

	c=0;
	static NPC* entergamblers[6] = {NULL,NULL,NULL,NULL,NULL,NULL};
	static int last_clock=0;
	for(c=0;c<6;c++)
	{
		if(entergamblers[c]==NULL&&CLOCK_second!=last_clock&&CLOCK_second%30==0)
		{
			last_clock=CLOCK_second;

			int randnum=r(4);
			if(randnum==0)NPC_create_random_ADULT_xy_feet(&entergamblers[c],38*8,49*8);
			if(randnum==1)NPC_create_random_ADULT_xy_feet(&entergamblers[c],46*8,49*8);
			if(randnum==2)NPC_create_random_ADULT_xy_feet(&entergamblers[c],54*8,49*8);
			if(randnum==3)NPC_create_random_ADULT_xy_feet(&entergamblers[c],62*8,49*8);

			entergamblers[c]->non_walkable = 1;
			entergamblers[c]->AI = 0;
			entergamblers[c]->walking_speed = SPEED_NORMAL+r(SPEED_SLOW-SPEED_FASTEST);
			entergamblers[c]->ignore_fx_layer = 1;
			NPC_animate_stand_dir(&entergamblers[c], UP);
		}

		if(entergamblers[c]!=NULL)
		{
			if(entergamblers[c]->AI== 0)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&entergamblers[c],entergamblers[c]->walking_speed, -1,42*8)==(1))entergamblers[c]->AI+=1+r(2);
			if(entergamblers[c]->AI== 1)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&entergamblers[c],entergamblers[c]->walking_speed, 26*8,-1)==1)entergamblers[c]->AI=3;
			if(entergamblers[c]->AI== 2)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&entergamblers[c],entergamblers[c]->walking_speed, 72*8,-1)==1)entergamblers[c]->AI=3;
			if(entergamblers[c]->AI== 3)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&entergamblers[c],entergamblers[c]->walking_speed, -1,20*8)==1)entergamblers[c]->AI++;
			if(entergamblers[c]->AI== 4)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&entergamblers[c],entergamblers[c]->walking_speed, 49*8,-1)==1)entergamblers[c]->AI++;
			if(entergamblers[c]->AI== 5)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&entergamblers[c],entergamblers[c]->walking_speed, -1,2*8)==1){NPC_delete_npc(&entergamblers[c]);}
		}
	}

	c=0;
	static NPC* exitgamblers[6] = {NULL,NULL,NULL,NULL,NULL,NULL};
	static int last_clock2=0;
	for(c=0;c<6;c++)
	{
		if(exitgamblers[c]==NULL&&CLOCK_second!=last_clock2&&CLOCK_second%30==15)
		{
			last_clock2=CLOCK_second;

			NPC_create_random_ADULT_xy_feet(&exitgamblers[c],49*8,2*8);

			exitgamblers[c]->non_walkable = 1;
			exitgamblers[c]->AI = 0;
			exitgamblers[c]->walking_speed = SPEED_NORMAL+r(SPEED_SLOW-SPEED_FASTEST);
			exitgamblers[c]->ignore_fx_layer = 1;
			NPC_animate_stand_dir(&exitgamblers[c], DOWN);
		}

		if(exitgamblers[c]!=NULL)
		{
			if(exitgamblers[c]->AI== 0)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&exitgamblers[c],exitgamblers[c]->walking_speed, -1,18*8)==(1))exitgamblers[c]->AI+=1+r(2);
			if(exitgamblers[c]->AI== 1)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&exitgamblers[c],exitgamblers[c]->walking_speed, 28*8,-1)==1)exitgamblers[c]->AI=3;
			if(exitgamblers[c]->AI== 2)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&exitgamblers[c],exitgamblers[c]->walking_speed, 70*8,-1)==1)exitgamblers[c]->AI=3;
			if(exitgamblers[c]->AI== 3)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&exitgamblers[c],exitgamblers[c]->walking_speed, -1,40*8)==1)exitgamblers[c]->AI++;
			if(exitgamblers[c]->AI== 4)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&exitgamblers[c],exitgamblers[c]->walking_speed, 49*8,-1)==1)exitgamblers[c]->AI+=1+r(4);
			if(exitgamblers[c]->AI== 5)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&exitgamblers[c],exitgamblers[c]->walking_speed, 36*8,-1)==1)exitgamblers[c]->AI=9;
			if(exitgamblers[c]->AI== 6)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&exitgamblers[c],exitgamblers[c]->walking_speed, 44*8,-1)==1)exitgamblers[c]->AI=9;
			if(exitgamblers[c]->AI== 7)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&exitgamblers[c],exitgamblers[c]->walking_speed, 52*8,-1)==1)exitgamblers[c]->AI=9;
			if(exitgamblers[c]->AI== 8)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&exitgamblers[c],exitgamblers[c]->walking_speed, 60*8,-1)==1)exitgamblers[c]->AI=9;
			if(exitgamblers[c]->AI== 9)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&exitgamblers[c],exitgamblers[c]->walking_speed, -1,49*8)==1){NPC_delete_npc(&exitgamblers[c]);}
		}
	}

	if(walking_into_door(RANGE_CITYCasinoEntranceToOUTSIDECity1))
	{
		MAP_change_map(MAP_bobsgame_CITYCity,189,39);return;
	}
	if(walking_into_door(RANGE_CITYCasinoEntranceToOUTSIDECity2))
	{
		MAP_change_map(MAP_bobsgame_CITYCity,197,39);return;
	}
	if(walking_into_door(RANGE_CITYCasinoEntranceToOUTSIDECity3))
	{
		MAP_change_map(MAP_bobsgame_CITYCity,205,39);return;
	}
	if(walking_into_door(RANGE_CITYCasinoEntranceToOUTSIDECity4))
	{
		MAP_change_map(MAP_bobsgame_CITYCity,213,39);return;
	}
	if(walking_into_door(RANGE_CITYCasinoEntranceToMain))
	{
		MAP_change_map(MAP_bobsgame_CITYCasinoMain,48,80);return;
	}
}
void bobsgame_CITYCasinoEntrance_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYCasinoEntrance_Map_VBL_Function()
{

}
void bobsgame_CITYCasinoEntrance_Map_HBL_Function()
{

}

//========================================================
//CITYCasinoMain
//========================================================
void bobsgame_CITYCasinoMain_Map_Load_Function()
{
//RANGE_CITYCasinoMainToEntrance 46*8,81*8,52*8,82*8
//RANGE_CITYCasinoMainToBackRoom 5*8,9*8,9*8,10*8
			current_mod = mods[6];
			HARDWARE_stop_music();
			HARDWARE_play_music("casino",64);

		//murmur
		{HARDWARE_play_sound("murmur",64,40000,1);}

}
void bobsgame_CITYCasinoMain_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}



//TODO: need better gambler people

	static NPC* gamblers2[22] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	int c=0;
	for(c=0;c<22;c++)
	{
		if(gamblers2[c]==NULL)
		{
			int x=0;
			int y=0;
			int dir=UP;
			int bgp=2;
			GFX* gfx=NULL;

			if(c== 0){x= 6*8+2;y=75*8-2;dir=LEFT;bgp=2;}
			if(c== 1){x= 6*8+2;y=70*8-2;dir=LEFT;bgp=2;}
			//if(c== 2){x= 6*8+2;y=65*8-2;dir=LEFT;bgp=2;}
			if(c== 2){x= 6*8+2;y=60*8-2;dir=LEFT;bgp=2;}
			//if(c== 4){x= 6*8+2;y=55*8-2;dir=LEFT;bgp=2;}

			if(c== 3){x=14*8-2;y=25*8-2;dir=RIGHT;bgp=2;}
			//if(c==13){x=14*8-2;y=29*8-2;dir=RIGHT;bgp=2;}
			if(c== 4){x=14*8-2;y=33*8-2;dir=RIGHT;bgp=2;}
			if(c== 5){x=14*8-2;y=37*8-2;dir=RIGHT;bgp=2;}
			if(c== 6){x=14*8-2;y=41*8-2;dir=RIGHT;bgp=2;}

			if(c== 7){x=23*8+2;y=25*8-2;dir=LEFT;bgp=2;}
			if(c== 8){x=23*8+2;y=29*8-2;dir=LEFT;bgp=2;}
			//if(c==19){x=23*8+2;y=33*8-2;dir=LEFT;bgp=2;}
			if(c== 9){x=23*8+2;y=37*8-2;dir=LEFT;bgp=2;}
			//if(c==21){x=23*8+2;y=41*8-2;dir=LEFT;bgp=2;}

			if(c==10){x=31*8-2;y=25*8-2;dir=RIGHT;bgp=2;}
			//if(c==23){x=31*8-2;y=29*8-2;dir=RIGHT;bgp=2;}
			if(c==11){x=31*8-2;y=33*8-2;dir=RIGHT;bgp=2;}
			if(c==12){x=31*8-2;y=37*8-2;dir=RIGHT;bgp=2;}
			if(c==13){x=31*8-2;y=41*8-2;dir=RIGHT;bgp=2;}

			if(c==14){x=40*8+2;y=25*8-2;dir=LEFT;bgp=2;}
			//if(c==28){x=40*8+2;y=29*8-2;dir=LEFT;bgp=2;}
			if(c==15){x=40*8+2;y=33*8-2;dir=LEFT;bgp=2;}
			if(c==16){x=40*8+2;y=37*8-2;dir=LEFT;bgp=2;}
			//if(c==31){x=40*8+2;y=41*8-2;dir=LEFT;bgp=2;}

			if(c==17){x=13*8;y=59*8-6;dir=UP;bgp=2;}
			//if(c==33){x=18*8;y=59*8-6;dir=UP;bgp=2;}
			if(c==18){x=23*8;y=59*8-6;dir=UP;bgp=2;}
			//if(c==35){x=28*8;y=59*8-6;dir=UP;bgp=2;}
			//if(c==36){x=33*8;y=59*8-6;dir=UP;bgp=2;}
			if(c==19){x=38*8;y=59*8-6;dir=UP;bgp=2;}

			if(c==20){x=13*8;y=72*8-6;dir=UP;bgp=2;}
			//if(c==40){x=18*8;y=72*8-6;dir=UP;bgp=2;}
			//if(c==41){x=23*8;y=72*8-6;dir=UP;bgp=2;}
			if(c==21){x=28*8;y=72*8-6;dir=UP;bgp=2;}
			if(c==22){x=33*8;y=72*8-6;dir=UP;bgp=2;}
			//if(c==44){x=38*8;y=72*8-6;dir=UP;bgp=2;}

			if(gfx==NULL)NPC_create_random_ADULT_xy_feet(&gamblers2[c],x,y);
			else NPC_create_npc_xy_feet(&gamblers2[c],gfx,16,40,x,y);

			NPC_animate_stand_dir(&gamblers2[c], dir);
			gamblers2[c]->non_walkable=1;
			gamblers2[c]->walk_dir=dir;
			gamblers2[c]->layer=bgp;
			//NPC_animate_increment_direction_frame_now(&gamblers_npcs[c], dir);
		}

		if(gamblers2[c]!=NULL)
		{
			if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&gamblers2[c],15))NPC_stare_at_npc_not_opposite_walking_direction(&gamblers2[c],&PLAYER_npc);
			else if(gamblers2[c]->AI==0){if(gamblers2[c]->vbls>200){if(r(4)==0){gamblers2[c]->AI=1+r(3);}else{gamblers2[c]->vbls=0;NPC_animate_stand_dir(&gamblers2[c], gamblers2[c]->walk_dir);}}}
			else if(gamblers2[c]->AI==1){if(gamblers2[c]->walk_dir==UP||gamblers2[c]->walk_dir==DOWN)NPC_animate_stand_dir(&gamblers2[c],LEFT);else NPC_animate_stand_dir(&gamblers2[c],UP);gamblers2[c]->vbls=r(120);gamblers2[c]->AI=0;}
			else if(gamblers2[c]->AI==2){if(gamblers2[c]->walk_dir==UP||gamblers2[c]->walk_dir==DOWN)NPC_animate_stand_dir(&gamblers2[c],RIGHT);else NPC_animate_stand_dir(&gamblers2[c],DOWN);gamblers2[c]->vbls=r(120);gamblers2[c]->AI=0;}
			else if(gamblers2[c]->AI==3){NPC_animate(&gamblers2[c]);gamblers2[c]->vbls=r(120);gamblers2[c]->AI=0;}
		}
	}

	//TODO: need dealers, tuxedos?

	//blackjack dealers

	//57,41
	//57,53
	//57,65


	static NPC* bjdealers[3] = {NULL,NULL,NULL};
	c=0;
	for(c=0;c<3;c++)
	{
		if(bjdealers[c]==NULL)
		{
			int x=0;
			int y=0;
			int dir=UP;
			int bgp=2;
			GFX* gfx=NULL;

			if(c== 0){x=58*8-2;y=41*8-2;dir=RIGHT;bgp=2;}
			if(c== 1){x=58*8-2;y=53*8-2;dir=RIGHT;bgp=2;}
			if(c== 2){x=58*8-2;y=65*8-2;dir=RIGHT;bgp=2;}

			if(gfx==NULL)NPC_create_random_ADULT_xy_feet(&bjdealers[c],x,y);
			else NPC_create_npc_xy_feet(&bjdealers[c],gfx,16,40,x,y);

			NPC_animate_stand_dir(&bjdealers[c], dir);
			bjdealers[c]->non_walkable=1;
			bjdealers[c]->walk_dir=dir;
			bjdealers[c]->layer=bgp;
			//NPC_animate_increment_direction_frame_now(&bjdealers_npcs[c], dir);
		}

		if(bjdealers[c]!=NULL)
		{
			if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&bjdealers[c],15))NPC_stare_at_npc_not_opposite_walking_direction(&bjdealers[c],&PLAYER_npc);
			else if(bjdealers[c]->AI==0){if(bjdealers[c]->vbls>200){if(r(4)==0){bjdealers[c]->AI=1+r(3);}else{bjdealers[c]->vbls=0;NPC_animate_stand_dir(&bjdealers[c], bjdealers[c]->walk_dir);}}}
			else if(bjdealers[c]->AI==1){if(bjdealers[c]->walk_dir==UP||bjdealers[c]->walk_dir==DOWN)NPC_animate_stand_dir(&bjdealers[c],LEFT);else NPC_animate_stand_dir(&bjdealers[c],UP);bjdealers[c]->vbls=r(120);bjdealers[c]->AI=0;}
			else if(bjdealers[c]->AI==2){if(bjdealers[c]->walk_dir==UP||bjdealers[c]->walk_dir==DOWN)NPC_animate_stand_dir(&bjdealers[c],RIGHT);else NPC_animate_stand_dir(&bjdealers[c],DOWN);bjdealers[c]->vbls=r(120);bjdealers[c]->AI=0;}
			else if(bjdealers[c]->AI==3){NPC_animate(&bjdealers[c]);bjdealers[c]->vbls=r(120);bjdealers[c]->AI=0;}
		}
	}



	//blackjack players

	static NPC* bjplayers[6] = {NULL,NULL,NULL,NULL,NULL,NULL};
	c=0;
	for(c=0;c<6;c++)
	{
		if(bjplayers[c]==NULL)
		{
			int x=0;
			int y=0;
			int dir=UP;
			int bgp=2;
			GFX* gfx=NULL;

			if(c== 0){x=64*8+2;y=38*8-2;dir=LEFT;bgp=2;}
			if(c== 1){x=64*8+2;y=41*8-2;dir=LEFT;bgp=2;}
			//if(c== 2){x=64*8+2;y=44*8-2;dir=LEFT;bgp=2;}

			//if(c== 3){x=64*8+2;y=50*8-2;dir=LEFT;bgp=2;}
			if(c== 2){x=64*8+2;y=53*8-2;dir=LEFT;bgp=2;}
			if(c== 3){x=64*8+2;y=56*8-2;dir=LEFT;bgp=2;}

			if(c== 4){x=64*8+2;y=62*8-2;dir=LEFT;bgp=2;}
			//if(c== 7){x=64*8+2;y=65*8-2;dir=LEFT;bgp=2;}
			if(c== 5){x=64*8+2;y=68*8-2;dir=LEFT;bgp=2;}


			if(gfx==NULL)NPC_create_random_ADULT_xy_feet(&bjplayers[c],x,y);
			else NPC_create_npc_xy_feet(&bjplayers[c],gfx,16,40,x,y);

			NPC_animate_stand_dir(&bjplayers[c], dir);
			bjplayers[c]->non_walkable=1;
			bjplayers[c]->walk_dir=dir;
			bjplayers[c]->layer=bgp;
			//NPC_animate_increment_direction_frame_now(&bjplayers[c], dir);
		}

		if(bjplayers[c]!=NULL)
		{
			if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&bjplayers[c],15))NPC_stare_at_npc_not_opposite_walking_direction(&bjplayers[c],&PLAYER_npc);
			else if(bjplayers[c]->AI==0){if(bjplayers[c]->vbls>200){if(r(4)==0){bjplayers[c]->AI=1+r(3);}else{bjplayers[c]->vbls=0;NPC_animate_stand_dir(&bjplayers[c], bjplayers[c]->walk_dir);}}}
			else if(bjplayers[c]->AI==1){if(bjplayers[c]->walk_dir==UP||bjplayers[c]->walk_dir==DOWN)NPC_animate_stand_dir(&bjplayers[c],LEFT);else NPC_animate_stand_dir(&bjplayers[c],UP);bjplayers[c]->vbls=r(120);bjplayers[c]->AI=0;}
			else if(bjplayers[c]->AI==2){if(bjplayers[c]->walk_dir==UP||bjplayers[c]->walk_dir==DOWN)NPC_animate_stand_dir(&bjplayers[c],RIGHT);else NPC_animate_stand_dir(&bjplayers[c],DOWN);bjplayers[c]->vbls=r(120);bjplayers[c]->AI=0;}
			else if(bjplayers[c]->AI==3){NPC_animate(&bjplayers[c]);bjplayers[c]->vbls=r(120);bjplayers[c]->AI=0;}
		}
	}



	//roulette dealers

	static NPC* roulettedealers[3] = {NULL,NULL,NULL};
	c=0;
	for(c=0;c<3;c++)
	{
		if(roulettedealers[c]==NULL)
		{
			int x=0;
			int y=0;
			int dir=UP;
			int bgp=2;
			GFX* gfx=NULL;

			if(c== 0){x=70*8;y=41*8;dir=RIGHT;bgp=2;}
			if(c== 1){x=87*8;y=52*8;dir=LEFT;bgp=2;}
			if(c== 2){x=70*8;y=63*8;dir=RIGHT;bgp=2;}

			if(gfx==NULL)NPC_create_random_ADULT_xy_feet(&roulettedealers[c],x,y);
			else NPC_create_npc_xy_feet(&roulettedealers[c],gfx,16,40,x,y);

			NPC_animate_stand_dir(&roulettedealers[c], dir);
			roulettedealers[c]->non_walkable=1;
			roulettedealers[c]->walk_dir=dir;
			roulettedealers[c]->layer=bgp;
			//NPC_animate_increment_direction_frame_now(&roulettedealers_npcs[c], dir);
		}

		if(roulettedealers[c]!=NULL)
		{
			if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&roulettedealers[c],15))NPC_stare_at_npc_not_opposite_walking_direction(&roulettedealers[c],&PLAYER_npc);
			else if(roulettedealers[c]->AI==0){if(roulettedealers[c]->vbls>200){if(r(4)==0){roulettedealers[c]->AI=1+r(3);}else{roulettedealers[c]->vbls=0;NPC_animate_stand_dir(&roulettedealers[c], roulettedealers[c]->walk_dir);}}}
			else if(roulettedealers[c]->AI==1){if(roulettedealers[c]->walk_dir==UP||roulettedealers[c]->walk_dir==DOWN)NPC_animate_stand_dir(&roulettedealers[c],LEFT);else NPC_animate_stand_dir(&roulettedealers[c],UP);roulettedealers[c]->vbls=r(120);roulettedealers[c]->AI=0;}
			else if(roulettedealers[c]->AI==2){if(roulettedealers[c]->walk_dir==UP||roulettedealers[c]->walk_dir==DOWN)NPC_animate_stand_dir(&roulettedealers[c],RIGHT);else NPC_animate_stand_dir(&roulettedealers[c],DOWN);roulettedealers[c]->vbls=r(120);roulettedealers[c]->AI=0;}
			else if(roulettedealers[c]->AI==3){NPC_animate(&roulettedealers[c]);roulettedealers[c]->vbls=r(120);roulettedealers[c]->AI=0;}
		}
	}

	//roulette players

	static NPC* rouletteplayers_npcs[8] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	c=0;
	for(c=0;c<8;c++)
	{
		if(rouletteplayers_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			int dir=UP;
			int bgp=2;
			GFX* gfx=NULL;

			if(c== 0){x=76*8;y=43*8;dir=UP;bgp=2;}
			if(c== 1){x=80*8;y=43*8;dir=UP;bgp=2;}
			if(c== 2){x=83*8;y=43*8;dir=UP;bgp=2;}
			if(c== 3){x=79*8;y=54*8;dir=UP;bgp=2;}
			if(c== 4){x=74*8;y=54*8;dir=UP;bgp=2;}
			if(c== 5){x=77*8;y=65*8;dir=UP;bgp=2;}
			if(c== 6){x=81*8;y=65*8;dir=UP;bgp=2;}
			if(c== 7){x=84*8;y=65*8;dir=UP;bgp=2;}
			//if(c== 8){x=73*8;y=60*8;dir=DOWN;bgp=2;}
			//if(c== 9){x=73*8;y=60*8;dir=DOWN;bgp=2;}

			if(gfx==NULL)NPC_create_random_ADULT_xy_feet(&rouletteplayers_npcs[c],x,y);
			else NPC_create_npc_xy_feet(&rouletteplayers_npcs[c],gfx,16,40,x,y);

			NPC_animate_stand_dir(&rouletteplayers_npcs[c], dir);
			rouletteplayers_npcs[c]->non_walkable=1;
			rouletteplayers_npcs[c]->walk_dir=dir;
			rouletteplayers_npcs[c]->layer=bgp;
			//NPC_animate_increment_direction_frame_now(&rouletteplayers_npcs[c], dir);
		}

		if(rouletteplayers_npcs[c]!=NULL)
		{
			if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&rouletteplayers_npcs[c],15))NPC_stare_at_npc_not_opposite_walking_direction(&rouletteplayers_npcs[c],&PLAYER_npc);
			else if(rouletteplayers_npcs[c]->AI==0){if(rouletteplayers_npcs[c]->vbls>200){if(r(4)==0){rouletteplayers_npcs[c]->AI=1+r(3);}else{rouletteplayers_npcs[c]->vbls=0;NPC_animate_stand_dir(&rouletteplayers_npcs[c], rouletteplayers_npcs[c]->walk_dir);if(rouletteplayers_npcs[c]->anim_frame_count!=0){rouletteplayers_npcs[c]->anim_frame_count=3;NPC_animate(&rouletteplayers_npcs[c]);}}}}
			else if(rouletteplayers_npcs[c]->AI==1){if(rouletteplayers_npcs[c]->walk_dir==UP||rouletteplayers_npcs[c]->walk_dir==DOWN)NPC_animate_stand_dir(&rouletteplayers_npcs[c],LEFT);else NPC_animate_stand_dir(&rouletteplayers_npcs[c],UP);rouletteplayers_npcs[c]->vbls=r(120);rouletteplayers_npcs[c]->AI=0;}
			else if(rouletteplayers_npcs[c]->AI==2){if(rouletteplayers_npcs[c]->walk_dir==UP||rouletteplayers_npcs[c]->walk_dir==DOWN)NPC_animate_stand_dir(&rouletteplayers_npcs[c],RIGHT);else NPC_animate_stand_dir(&rouletteplayers_npcs[c],DOWN);rouletteplayers_npcs[c]->vbls=r(120);rouletteplayers_npcs[c]->AI=0;}
			else if(rouletteplayers_npcs[c]->AI==3){NPC_animate(&rouletteplayers_npcs[c]);rouletteplayers_npcs[c]->vbls=r(120);rouletteplayers_npcs[c]->AI=0;}
		}
	}

	//cashiers

	static NPC* cashier_npc = NULL;
	if(cashier_npc==NULL)
	{
		//NPC_create_npc_xy_feet(&cashier_npc,SPRITE,16,40,61*8,17*8);
		NPC_create_random_ADULT_xy_feet(&cashier_npc,61*8,17*8);

		cashier_npc->layer=2;
		cashier_npc->non_walkable=1;
		NPC_animate_stand_dir(&cashier_npc,LEFT);

		cashier_npc->walking_speed = SPEED_NORMAL;
		cashier_npc->AI=0;
	}
	if(cashier_npc!=NULL)
	{
		if(NPC_in_range_of_area_xyxy_in_direction_by_amount(&PLAYER_npc,57*8,12*8,59*8,22*8,PLAYER_npc->anim_dir,0))
		{
			if(NPC_walk_to_xy_nohit(&cashier_npc,cashier_npc->walking_speed, 61*8-2,15*8)==1)NPC_animate_stand_dir(&cashier_npc,LEFT);
		}
		else
		if(NPC_in_range_of_area_xyxy_in_direction_by_amount(&PLAYER_npc,60*8,22*8,75*8,24*8,PLAYER_npc->anim_dir,0))
		{
			if(NPC_walk_to_xy_nohit(&cashier_npc,cashier_npc->walking_speed, 68*8,19*8)==1)NPC_animate_stand_dir(&cashier_npc,DOWN);
		}
		else if(cashier_npc->AI== 0){if(NPC_walk_to_xy_nohit(&cashier_npc,cashier_npc->walking_speed,75*8,12*8)==1){cashier_npc->AI=3;cashier_npc->vbls=r(60);NPC_animate_stand_dir(&cashier_npc,UP);}}
		else if(cashier_npc->AI== 1){if(NPC_walk_to_xy_nohit(&cashier_npc,cashier_npc->walking_speed,81*8,19*8)==1){cashier_npc->AI=3;cashier_npc->vbls=r(60);NPC_animate_stand_dir(&cashier_npc,DOWN);}}
		else if(cashier_npc->AI== 2){if(NPC_walk_to_xy_nohit(&cashier_npc,cashier_npc->walking_speed,93*8+4,16*8)==1){cashier_npc->AI=3;cashier_npc->vbls=r(60);NPC_animate_stand_dir(&cashier_npc,RIGHT);}}
		else if(cashier_npc->AI== 3){if(cashier_npc->vbls>120){cashier_npc->vbls=0;cashier_npc->AI=r(3);}}

		if(cashier_npc->MAP_y>14*8)cashier_npc->layer=3;else cashier_npc->layer=2;

		if(ACTION_range_xy_xy(58*8,12*8,75*8,23*8,"Talk To Cashier"))
		{
			TEXT_set_sprite_window(0,cashier_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}

	//TODO: need bunny girl sprite
	//bunny girls walking around

	static NPC* bunnygirl1_npc = NULL;
	if(bunnygirl1_npc==NULL)
	{
		//NPC_create_npc_xy_feet(&bunnygirl1_npc,SPRITE,16,40,7*8,16*8);
		NPC_create_random_WOMAN_xy_feet(&bunnygirl1_npc,7*8,16*8);

		bunnygirl1_npc->layer=2;
		bunnygirl1_npc->non_walkable=1;
		NPC_animate_stand_dir(&bunnygirl1_npc,DOWN);

		bunnygirl1_npc->walking_speed = SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		bunnygirl1_npc->AI=0;
	}
	if(bunnygirl1_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&bunnygirl1_npc,15))NPC_stare_at_npc(&bunnygirl1_npc,&PLAYER_npc);
		//else NPC_animate_set_direction_now(&bunnygirl1_npc, LEFT);

		else if(bunnygirl1_npc->AI== 0){if(NPC_walk_to_xy_nohit_pushmain(&bunnygirl1_npc,bunnygirl1_npc->walking_speed, 7*8,16*8)==1){NPC_animate_stand_dir(&bunnygirl1_npc,r(4));bunnygirl1_npc->vbls=r(40);bunnygirl1_npc->AI++;}}
		else if(bunnygirl1_npc->AI== 1){if(bunnygirl1_npc->vbls>60)bunnygirl1_npc->AI++;}
		else if(bunnygirl1_npc->AI== 2){if(NPC_walk_to_xy_nohit_pushmain(&bunnygirl1_npc,bunnygirl1_npc->walking_speed, 9*8,47*8)==1){NPC_animate_stand_dir(&bunnygirl1_npc,r(4));bunnygirl1_npc->vbls=r(40);bunnygirl1_npc->AI++;}}
		else if(bunnygirl1_npc->AI== 3){if(bunnygirl1_npc->vbls>60)bunnygirl1_npc->AI++;}
		else if(bunnygirl1_npc->AI== 4){if(NPC_walk_to_xy_nohit_pushmain(&bunnygirl1_npc,bunnygirl1_npc->walking_speed, 9*8,76*8)==1){NPC_animate_stand_dir(&bunnygirl1_npc,r(4));bunnygirl1_npc->vbls=r(40);bunnygirl1_npc->AI++;}}
		else if(bunnygirl1_npc->AI== 5){if(bunnygirl1_npc->vbls>60)bunnygirl1_npc->AI++;}
		else if(bunnygirl1_npc->AI== 6){if(NPC_walk_to_xy_nohit_pushmain(&bunnygirl1_npc,bunnygirl1_npc->walking_speed,47*8,76*8)==1){NPC_animate_stand_dir(&bunnygirl1_npc,r(4));bunnygirl1_npc->vbls=r(40);bunnygirl1_npc->AI++;}}
		else if(bunnygirl1_npc->AI== 7){if(bunnygirl1_npc->vbls>60)bunnygirl1_npc->AI++;}
		else if(bunnygirl1_npc->AI== 8){if(NPC_walk_to_xy_nohit_pushmain(&bunnygirl1_npc,bunnygirl1_npc->walking_speed,47*8,47*8)==1){NPC_animate_stand_dir(&bunnygirl1_npc,r(4));bunnygirl1_npc->vbls=r(40);bunnygirl1_npc->AI++;}}
		else if(bunnygirl1_npc->AI== 9){if(bunnygirl1_npc->vbls>60)bunnygirl1_npc->AI++;}
		else if(bunnygirl1_npc->AI==10){if(NPC_walk_to_xy_nohit_pushmain(&bunnygirl1_npc,bunnygirl1_npc->walking_speed,26*8,47*8)==1){NPC_animate_stand_dir(&bunnygirl1_npc,r(4));bunnygirl1_npc->vbls=r(40);bunnygirl1_npc->AI++;}}
		else if(bunnygirl1_npc->AI==11){if(bunnygirl1_npc->vbls>60)bunnygirl1_npc->AI++;}
		else if(bunnygirl1_npc->AI==12){if(NPC_walk_to_xy_nohit_pushmain(&bunnygirl1_npc,bunnygirl1_npc->walking_speed,26*8,16*8)==1){NPC_animate_stand_dir(&bunnygirl1_npc,r(4));bunnygirl1_npc->vbls=r(40);bunnygirl1_npc->AI++;}}
		else if(bunnygirl1_npc->AI==13){if(bunnygirl1_npc->vbls>60)bunnygirl1_npc->AI=0;}

//start at 7 16, 9 47, 9 76, 47 46, 47 47, 26 47, 26 16


		if(ACTION_npc(&bunnygirl1_npc,"Talk To Bunny Girl"))
		{
			TEXT_set_sprite_window(0,bunnygirl1_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}


	static NPC* bunnygirl2_npc = NULL;
	if(bunnygirl2_npc==NULL)
	{
		//NPC_create_npc_xy_feet(&bunnygirl2_npc,SPRITE,16,40,90*8,73*8);
		NPC_create_random_WOMAN_xy_feet(&bunnygirl2_npc,90*8,73*8);

		bunnygirl2_npc->layer=2;
		bunnygirl2_npc->non_walkable=1;
		NPC_animate_stand_dir(&bunnygirl2_npc,DOWN);

		bunnygirl2_npc->walking_speed = SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		bunnygirl2_npc->AI=0;
	}
	if(bunnygirl2_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&bunnygirl2_npc,15))NPC_stare_at_npc(&bunnygirl2_npc,&PLAYER_npc);
		//else NPC_animate_set_direction_now(&bunnygirl2_npc, LEFT);

// start at 90 73, 50 73, 50 33, 89 33, 89 48 , 68 48, 68 58, 90 58
		else if(bunnygirl2_npc->AI== 0){if(NPC_walk_to_xy_nohit_pushmain(&bunnygirl2_npc,bunnygirl2_npc->walking_speed,90*8,73*8)==1){NPC_animate_stand_dir(&bunnygirl2_npc,r(4));bunnygirl2_npc->vbls=r(40);bunnygirl2_npc->AI++;}}
		else if(bunnygirl2_npc->AI== 1){if(bunnygirl2_npc->vbls>60)bunnygirl2_npc->AI++;}
		else if(bunnygirl2_npc->AI== 2){if(NPC_walk_to_xy_nohit_pushmain(&bunnygirl2_npc,bunnygirl2_npc->walking_speed,50*8,73*8)==1){NPC_animate_stand_dir(&bunnygirl2_npc,r(4));bunnygirl2_npc->vbls=r(40);bunnygirl2_npc->AI++;}}
		else if(bunnygirl2_npc->AI== 3){if(bunnygirl2_npc->vbls>60)bunnygirl2_npc->AI++;}
		else if(bunnygirl2_npc->AI== 4){if(NPC_walk_to_xy_nohit_pushmain(&bunnygirl2_npc,bunnygirl2_npc->walking_speed,50*8,33*8)==1){NPC_animate_stand_dir(&bunnygirl2_npc,r(4));bunnygirl2_npc->vbls=r(40);bunnygirl2_npc->AI++;}}
		else if(bunnygirl2_npc->AI== 5){if(bunnygirl2_npc->vbls>60)bunnygirl2_npc->AI++;}
		else if(bunnygirl2_npc->AI== 6){if(NPC_walk_to_xy_nohit_pushmain(&bunnygirl2_npc,bunnygirl2_npc->walking_speed,89*8,33*8)==1){NPC_animate_stand_dir(&bunnygirl2_npc,r(4));bunnygirl2_npc->vbls=r(40);bunnygirl2_npc->AI++;}}
		else if(bunnygirl2_npc->AI== 7){if(bunnygirl2_npc->vbls>60)bunnygirl2_npc->AI++;}
		else if(bunnygirl2_npc->AI== 8){if(NPC_walk_to_xy_nohit_pushmain(&bunnygirl2_npc,bunnygirl2_npc->walking_speed,89*8,48*8)==1){NPC_animate_stand_dir(&bunnygirl2_npc,r(4));bunnygirl2_npc->vbls=r(40);bunnygirl2_npc->AI++;}}
		else if(bunnygirl2_npc->AI== 9){if(bunnygirl2_npc->vbls>60)bunnygirl2_npc->AI++;}
		else if(bunnygirl2_npc->AI==10){if(NPC_walk_to_xy_nohit_pushmain(&bunnygirl2_npc,bunnygirl2_npc->walking_speed,68*8,48*8)==1){NPC_animate_stand_dir(&bunnygirl2_npc,r(4));bunnygirl2_npc->vbls=r(40);bunnygirl2_npc->AI++;}}
		else if(bunnygirl2_npc->AI==11){if(bunnygirl2_npc->vbls>60)bunnygirl2_npc->AI++;}
		else if(bunnygirl2_npc->AI==12){if(NPC_walk_to_xy_nohit_pushmain(&bunnygirl2_npc,bunnygirl2_npc->walking_speed,68*8,58*8)==1){NPC_animate_stand_dir(&bunnygirl2_npc,r(4));bunnygirl2_npc->vbls=r(40);bunnygirl2_npc->AI++;}}
		else if(bunnygirl2_npc->AI==13){if(bunnygirl2_npc->vbls>60)bunnygirl2_npc->AI++;}
		else if(bunnygirl2_npc->AI==14){if(NPC_walk_to_xy_nohit_pushmain(&bunnygirl2_npc,bunnygirl2_npc->walking_speed,90*8,58*8)==1){NPC_animate_stand_dir(&bunnygirl2_npc,r(4));bunnygirl2_npc->vbls=r(40);bunnygirl2_npc->AI++;}}
		else if(bunnygirl2_npc->AI==15){if(bunnygirl2_npc->vbls>60)bunnygirl2_npc->AI=0;}

		if(ACTION_npc(&bunnygirl2_npc,"Talk To Bunny Girl"))
		{
			TEXT_set_sprite_window(0,bunnygirl2_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}




	static int last_clock=0;

	if(last_clock!=CLOCK_second)
	{
		last_clock=CLOCK_second;
		//ringing

		if(CLOCK_second%20==0&&CLOCK_minute%2==0)
			HARDWARE_play_sound("casinoding",63,35000+r(20000),0);

		//laughter
		//if(CLOCK_second==10&&CLOCK_minute%3==0)
			//HARDWARE_play_sound(MAX_AUDIO_CHANNELS-4,"laugh",63,30000+r(20000),0);

		//digital beeping

		if(CLOCK_second%20==0&&CLOCK_minute%2==1)
			HARDWARE_play_sound("casinobeep",63,35000+r(30000),0);

		//coin clatter


	}


	if(walking_into_door(RANGE_CITYCasinoMainToEntrance))
	{
		MAP_change_map(MAP_bobsgame_CITYCasinoEntrance,48,10);return;
	}

	if(walking_into_door(RANGE_CITYCasinoMainToBackRoom))
	{
		MAP_change_map(MAP_bobsgame_CITYCasinoBackroom,7,21);return;
	}

}
void bobsgame_CITYCasinoMain_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYCasinoMain_Map_VBL_Function()
{

}
void bobsgame_CITYCasinoMain_Map_HBL_Function()
{

}
//========================================================
//CITYCasinoBackroom
//========================================================
void bobsgame_CITYCasinoBackroom_Map_Load_Function()
{
//RANGE_CITYCasinoBackRoomToMain 5*8,22*8,9*8,23*8
}
void bobsgame_CITYCasinoBackroom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}



	static NPC* crimeboss_npc = NULL;
	if(crimeboss_npc==NULL)
	{
		//NPC_create_random_ADULT_xy_feet(&crimeboss_npc,10*8-4,27*8);
		NPC_create_npc_xy_feet(&crimeboss_npc,GFX_ADULT_crimeboss,16,40,11*8,16*8);

		crimeboss_npc->non_walkable=1;
		crimeboss_npc->layer=2;
		NPC_animate_stand_dir(&crimeboss_npc,DOWN);

		crimeboss_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		crimeboss_npc->walk_dir=crimeboss_npc->anim_dir;
	}
	if(crimeboss_npc!=NULL)
	{

		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&crimeboss_npc,15))NPC_stare_at_npc_not_opposite_walking_direction(&crimeboss_npc,&PLAYER_npc);
		else
		{
			if(crimeboss_npc->AI==0){if(crimeboss_npc->vbls>200){if(r(4)==0){crimeboss_npc->AI=1+r(3);}else{crimeboss_npc->vbls=0;NPC_animate_stand_dir(&crimeboss_npc, crimeboss_npc->walk_dir);if(crimeboss_npc->anim_frame_count!=0){crimeboss_npc->anim_frame_count=3;NPC_animate(&crimeboss_npc);}}}}
			if(crimeboss_npc->AI==1){if(crimeboss_npc->walk_dir==UP||crimeboss_npc->walk_dir==DOWN)NPC_animate_stand_dir(&crimeboss_npc,LEFT);else NPC_animate_stand_dir(&crimeboss_npc,UP);crimeboss_npc->vbls=r(120);crimeboss_npc->AI=0;}
			if(crimeboss_npc->AI==2){if(crimeboss_npc->walk_dir==UP||crimeboss_npc->walk_dir==DOWN)NPC_animate_stand_dir(&crimeboss_npc,RIGHT);else NPC_animate_stand_dir(&crimeboss_npc,DOWN);crimeboss_npc->vbls=r(120);crimeboss_npc->AI=0;}
			if(crimeboss_npc->AI==3){NPC_animate(&crimeboss_npc);crimeboss_npc->vbls=r(120);crimeboss_npc->AI=0;}
		}

		if(ACTION_npc(&crimeboss_npc,"Talk To Crime Organization Team Leader"))
		{
			TEXT_set_sprite_window(0,crimeboss_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("" //?
			);
		}
	}

//mafia guy
//9,14
//15,14

	static NPC* mafiaguy1_npc = NULL;
	if(mafiaguy1_npc==NULL)
	{
		//NPC_create_random_ADULT_xy_feet(&mafiaguy1_npc,10*8-4,27*8);
		NPC_create_npc_xy_feet(&mafiaguy1_npc,GFX_ADULT_mafiaguy,16,40,8*8,12*8);

		mafiaguy1_npc->non_walkable=1;
		mafiaguy1_npc->layer=2;
		NPC_animate_stand_dir(&mafiaguy1_npc,RIGHT);

		mafiaguy1_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		mafiaguy1_npc->walk_dir=mafiaguy1_npc->anim_dir;
	}
	if(mafiaguy1_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&mafiaguy1_npc,15))NPC_stare_at_npc_not_opposite_walking_direction(&mafiaguy1_npc,&PLAYER_npc);
		else
		{
			if(mafiaguy1_npc->AI==0){if(mafiaguy1_npc->vbls>200){if(r(4)==0){mafiaguy1_npc->AI=1+r(3);}else{mafiaguy1_npc->vbls=0;NPC_animate_stand_dir(&mafiaguy1_npc, mafiaguy1_npc->walk_dir);if(mafiaguy1_npc->anim_frame_count!=0){mafiaguy1_npc->anim_frame_count=3;NPC_animate(&mafiaguy1_npc);}}}}
			if(mafiaguy1_npc->AI==1){if(mafiaguy1_npc->walk_dir==UP||mafiaguy1_npc->walk_dir==DOWN)NPC_animate_stand_dir(&mafiaguy1_npc,LEFT);else NPC_animate_stand_dir(&mafiaguy1_npc,UP);mafiaguy1_npc->vbls=r(120);mafiaguy1_npc->AI=0;}
			if(mafiaguy1_npc->AI==2){if(mafiaguy1_npc->walk_dir==UP||mafiaguy1_npc->walk_dir==DOWN)NPC_animate_stand_dir(&mafiaguy1_npc,RIGHT);else NPC_animate_stand_dir(&mafiaguy1_npc,DOWN);mafiaguy1_npc->vbls=r(120);mafiaguy1_npc->AI=0;}
			if(mafiaguy1_npc->AI==3){NPC_animate(&mafiaguy1_npc);mafiaguy1_npc->vbls=r(120);mafiaguy1_npc->AI=0;}
		}

		if(ACTION_npc(&mafiaguy1_npc,"Talk To Crime Organization Associate"))
		{
			TEXT_set_sprite_window(0,mafiaguy1_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("" //?
			);
		}
	}

	static NPC* mafiaguy2_npc = NULL;
	if(mafiaguy2_npc==NULL)
	{
		//NPC_create_random_ADULT_xy_feet(&mafiaguy2_npc,10*8-4,27*8);
		NPC_create_npc_xy_feet(&mafiaguy2_npc,GFX_ADULT_shadywatchdealer,16,40,14*8,12*8);

		mafiaguy2_npc->non_walkable=1;
		mafiaguy2_npc->layer=2;
		NPC_animate_stand_dir(&mafiaguy2_npc,LEFT);

		mafiaguy2_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		mafiaguy2_npc->walk_dir=mafiaguy2_npc->anim_dir;
	}
	if(mafiaguy2_npc!=NULL)
	{

		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&mafiaguy2_npc,15))NPC_stare_at_npc_not_opposite_walking_direction(&mafiaguy2_npc,&PLAYER_npc);
		else
		{
			if(mafiaguy2_npc->AI==0){if(mafiaguy2_npc->vbls>200){if(r(4)==0){mafiaguy2_npc->AI=1+r(3);}else{mafiaguy2_npc->vbls=0;NPC_animate_stand_dir(&mafiaguy2_npc, mafiaguy2_npc->walk_dir);if(mafiaguy2_npc->anim_frame_count!=0){mafiaguy2_npc->anim_frame_count=3;NPC_animate(&mafiaguy2_npc);}}}}
			if(mafiaguy2_npc->AI==1){if(mafiaguy2_npc->walk_dir==UP||mafiaguy2_npc->walk_dir==DOWN)NPC_animate_stand_dir(&mafiaguy2_npc,LEFT);else NPC_animate_stand_dir(&mafiaguy2_npc,UP);mafiaguy2_npc->vbls=r(120);mafiaguy2_npc->AI=0;}
			if(mafiaguy2_npc->AI==2){if(mafiaguy2_npc->walk_dir==UP||mafiaguy2_npc->walk_dir==DOWN)NPC_animate_stand_dir(&mafiaguy2_npc,RIGHT);else NPC_animate_stand_dir(&mafiaguy2_npc,DOWN);mafiaguy2_npc->vbls=r(120);mafiaguy2_npc->AI=0;}
			if(mafiaguy2_npc->AI==3){NPC_animate(&mafiaguy2_npc);mafiaguy2_npc->vbls=r(120);mafiaguy2_npc->AI=0;}
		}

		if(ACTION_npc(&mafiaguy2_npc,"Talk To Crime Organization Associate"))
		{
			TEXT_set_sprite_window(0,mafiaguy2_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("" //?
			);
		}
	}

//chair at 11,11




	if(walking_into_door(RANGE_CITYCasinoBackRoomToMain))
	{
		MAP_change_map(MAP_bobsgame_CITYCasinoMain,7,10);return;
	}

}
void bobsgame_CITYCasinoBackroom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYCasinoBackroom_Map_VBL_Function()
{

}
void bobsgame_CITYCasinoBackroom_Map_HBL_Function()
{

}

