//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================



#include "../../main.h"

#define RANGE_CITYTheCafeEntranceToOUTSIDECity 6*8,18*8,14*8,19*8
#define RANGE_CITYTheCafeEntranceToTheCafe 6*8,8*8,14*8,9*8
#define RANGE_CITYTheCafeToTheCafeEntrance 6*8,38*8,14*8,39*8
#define RANGE_CITYTheCafeToBathroom 4*8,9*8,8*8,10*8
#define RANGE_CITYTheCafeToDressingRoom 11*8,14*8,15*8,15*8
#define RANGE_CITYTheCafeBathroomToTheCafe 4*8,20*8,8*8,21*8
#define RANGE_CITYTheCafeDressingRoomToTheCafe 3*8,25*8,7*8,26*8
#define RANGE_CITYTheCafeDressingRoomToStage 16*8,20*8,20*8,21*8
#define RANGE_CITYTheCafeToDressingRoomFromStage 24*8,7*8,28*8,8*8
//========================================================
//CITYTheCafeEntrance
//========================================================
void bobsgame_CITYTheCafeEntrance_Map_Load_Function()
{
//RANGE_CITYTheCafeEntranceToOUTSIDECity 6*8,18*8,14*8,19*8
//RANGE_CITYTheCafeEntranceToTheCafe 6*8,8*8,14*8,9*8
}
void bobsgame_CITYTheCafeEntrance_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}
//nothing here. payphone disgusting?
//2-4,8-9

//newspapers
//2-4,14-15

	if(walking_into_door(RANGE_CITYTheCafeEntranceToOUTSIDECity))
	{
		MAP_change_map(MAP_bobsgame_CITYCity,263,39);return;
	}
	if(walking_into_door(RANGE_CITYTheCafeEntranceToTheCafe))
	{
		MAP_change_map(MAP_bobsgame_CITYTheCafe,9,37);return;
	}
}
void bobsgame_CITYTheCafeEntrance_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYTheCafeEntrance_Map_VBL_Function()
{

}
void bobsgame_CITYTheCafeEntrance_Map_HBL_Function()
{

}
//========================================================
//CITYTheCafe
//========================================================
void bobsgame_CITYTheCafe_Map_Load_Function()
{
//RANGE_CITYTheCafeToTheCafeEntrance 6*8,38*8,14*8,39*8
//RANGE_CITYTheCafeToBathroom 4*8,9*8,8*8,10*8
//RANGE_CITYTheCafeToDressingRoom 11*8,14*8,15*8,15*8
//RANGE_CITYTheCafeToDressingRoomFromStage 24*8,7*8,28*8,8*8
}
void bobsgame_CITYTheCafe_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//21,y face right
//27,y face left over layer1
//32,y
//38,y
//x,28
//x,36
//x,45

//45,23 face right
//45,29 face right
//45,35 face right
//45,41 right over 1
//21,19 up
//25
//29
//33
//37
	static NPC* perv_npcs[20] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	int c=0;
	for(c=0;c<21;c++)
	{
		if(perv_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			int dir=UP;
			int bgp=2;
			//int* gfx=NULL;
			if(c== 0){x=21*8+2;y=30*8;dir=RIGHT;}
			if(c== 1){x=28*8-2;y=30*8;dir=LEFT;}
			if(c== 2){x=32*8+2;y=30*8;dir=RIGHT;}
			if(c== 3){x=39*8-2;y=30*8;dir=LEFT;}
			if(c== 4){x=21*8+2;y=37*8;dir=RIGHT;}
			if(c== 5){x=28*8-2;y=37*8;dir=LEFT;}
			if(c== 6){x=32*8+2;y=37*8;dir=RIGHT;}
			if(c== 7){x=39*8-2;y=37*8;dir=LEFT;}

			if(c== 8){x=21*8+2;y=44*8;dir=RIGHT;}
			if(c== 9){x=28*8-2;y=44*8;dir=LEFT;}
			if(c==10){x=32*8+2;y=44*8;dir=RIGHT;}
			if(c==11){x=39*8-2;y=44*8;dir=LEFT;}

			if(c==12){x=46*8-2;y=23*8;dir=RIGHT;}
			if(c==13){x=46*8-2;y=29*8;dir=RIGHT;}
			if(c==14){x=46*8-2;y=35*8;dir=RIGHT;}
			if(c==15){x=46*8-2;y=41*8;dir=RIGHT;}
			if(c==16){x=21*8;y=19*8+5;dir=UP;}
			if(c==17){x=25*8;y=19*8+5;dir=UP;}
			//29. yuu sits here.
			//crossdress? get on stage?
			if(c==18){x=33*8;y=19*8+5;dir=UP;}
			if(c==19){x=37*8;y=19*8+5;dir=UP;}
			NPC_create_random_MAN_xy_feet(&perv_npcs[c],x,y);

			//NPC_create_npc_xy_feet(&perv_npcs[c],gfx,16,40,x,(y));
			NPC_animate_stand_dir(&perv_npcs[c], dir);
			perv_npcs[c]->non_walkable=1;
			perv_npcs[c]->walk_dir=dir;
			perv_npcs[c]->layer=bgp;
		}
		if(perv_npcs[c]!=NULL)
		{
			if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&perv_npcs[c],15))NPC_stare_at_npc(&perv_npcs[c],&PLAYER_npc);
			else NPC_animate_stand_dir(&perv_npcs[c], perv_npcs[c]->walk_dir);
			//TODO: ANIMATE
		}
	}
//bartender
//50,21-43
//51 right

	static NPC* cafebartender_npc = NULL;
	if(cafebartender_npc==NULL)
	{
		NPC_create_npc_xy_feet(&cafebartender_npc,GFX_ADULT_GENERICmanlongsleeves,16,40,33*8,39*8);
		//NPC_create_random_ADULT_xy_feet(&cafebartender_npc,51*8,26*8);
		cafebartender_npc->layer=2;
		cafebartender_npc->non_walkable=1;
		NPC_animate_stand_dir(&cafebartender_npc,LEFT);
		cafebartender_npc->walking_speed = SPEED_SLOWEST+r(SPEED_SLOWEST-SPEED_FASTEST);
		cafebartender_npc->AI=0;
	}
	if(cafebartender_npc!=NULL)
	{
		//TODO: ANIMATE
		// new function, if x>amount bartender runs to your xy, can talk to
		if(cafebartender_npc->AI== 0)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&cafebartender_npc,cafebartender_npc->walking_speed, 51*8,22*8)==1){cafebartender_npc->AI=4;cafebartender_npc->vbls=r(60);NPC_animate_stand_dir(&cafebartender_npc,LEFT);}
		if(cafebartender_npc->AI== 1)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&cafebartender_npc,cafebartender_npc->walking_speed, 51*8,40*8)==1){cafebartender_npc->AI=4;cafebartender_npc->vbls=r(60);NPC_animate_stand_dir(&cafebartender_npc,LEFT);}
		if(cafebartender_npc->AI== 2)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&cafebartender_npc,cafebartender_npc->walking_speed, 51*8,30*8)==1){cafebartender_npc->AI=4;cafebartender_npc->vbls=r(60);NPC_animate_stand_dir(&cafebartender_npc,LEFT);}
		if(cafebartender_npc->AI== 3)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&cafebartender_npc,cafebartender_npc->walking_speed, 52*8,35*8)==1){cafebartender_npc->AI=4;cafebartender_npc->vbls=r(60);NPC_animate_stand_dir(&cafebartender_npc,RIGHT);}
		if(cafebartender_npc->AI== 4)if(cafebartender_npc->vbls>120){cafebartender_npc->vbls=0;cafebartender_npc->AI=r(4);}
	}
//TODO: need bartender sprite
//girl show?
//17,9-39,15 curtain
static int dancing_started=0;
static int curtain_down=0;
	if(ACTION_range_xy_xy(28*8,18*8,30*8,20*8,"Enjoy Wholesome Dancing"))
	{
		dancing_started=1;
	}
	if(dancing_started)
	{
		//TODO: sit in chair face up, sprite input off
		//curtain disappears.
		if(curtain_down==0)
		{
			static int x=17;
			int y=0;
			static int last_vbl_var=0;
			if(last_vbl_var!=vbl_var&&vbl_var%2==0)
			{
				for(y=9;y<16;y++)
				{
					///TODO: MUST FIX!!!
					///HARDWARE_set_map_tile(1,1,x,y,0);
					//TODO: something for bottom screen?
				}
				last_vbl_var=vbl_var;
				x++;
			}
			if(x>39)curtain_down=1;
		}
		else
		{
			//TODO: do show
			//music plays, lights dim
			//girls come out at 26,8.

			//twirl around
			//hey, whats this kid doing in here?!
			//get out!!
			//you got silver thong.
		}
	}
	if(walking_into_door(RANGE_CITYTheCafeToTheCafeEntrance))
	{
		MAP_change_map(MAP_bobsgame_CITYTheCafeEntrance,9,9);return;
	}
	if(walking_into_door(RANGE_CITYTheCafeToBathroom))
	{
		MAP_change_map(MAP_bobsgame_CITYTheCafeBathroom,6,19);return;
	}
	if(walking_into_door(RANGE_CITYTheCafeToDressingRoom))
	{
		MAP_change_map(MAP_bobsgame_CITYTheCafeDressingRoom,5,24);return;
	}
	if(walking_into_door(RANGE_CITYTheCafeToDressingRoomFromStage))
	{
		MAP_change_map(MAP_bobsgame_CITYTheCafeDressingRoom,18,19);return;
	}
}
void bobsgame_CITYTheCafe_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYTheCafe_Map_VBL_Function()
{

}
void bobsgame_CITYTheCafe_Map_HBL_Function()
{

}
//========================================================
//CITYTheCafeBathroom
//========================================================
void bobsgame_CITYTheCafeBathroom_Map_Load_Function()
{
//RANGE_CITYTheCafeBathroomToTheCafe 4*8,20*8,8*8,21*8
}
void bobsgame_CITYTheCafeBathroom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//something in the urinal

	if(walking_into_door(RANGE_CITYTheCafeBathroomToTheCafe))
	{
		MAP_change_map(MAP_bobsgame_CITYTheCafe,6,10);return;
	}
}
void bobsgame_CITYTheCafeBathroom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYTheCafeBathroom_Map_VBL_Function()
{

}
void bobsgame_CITYTheCafeBathroom_Map_HBL_Function()
{

}
//========================================================
//CITYTheCafeDressingRoom
//========================================================
void bobsgame_CITYTheCafeDressingRoom_Map_Load_Function()
{
//RANGE_CITYTheCafeDressingRoomToTheCafe 3*8,25*8,7*8,26*8
//RANGE_CITYTheCafeDressingRoomToStage 16*8,20*8,20*8,21*8
}
void bobsgame_CITYTheCafeDressingRoom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//girls in here.
//5,13,20  ,13
//under 2
	static NPC* stripper1_npc = NULL;
	if(stripper1_npc==NULL)
	{
		NPC_create_npc_xy_feet(&stripper1_npc,GFX_ADULT_dancer,16,40,5*8,12*8+4);
		stripper1_npc->layer=3;
		stripper1_npc->non_walkable=1;
		NPC_animate_stand_dir(&stripper1_npc,UP);
	}
	if(stripper1_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&stripper1_npc,30))NPC_stare_at_npc(&stripper1_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&stripper1_npc, UP);
		//TODO: ANIMATE
		if(ACTION_npc(&stripper1_npc,"Talk To Dancer"))
		{
			TEXT_set_sprite_window(0,stripper1_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
	static NPC* stripper2_npc = NULL;
	if(stripper2_npc==NULL)
	{
		NPC_create_npc_xy_feet(&stripper2_npc,GFX_ADULT_dancer,16,40,13*8,12*8+4);
		stripper2_npc->layer=3;
		stripper2_npc->non_walkable=1;
		NPC_animate_stand_dir(&stripper2_npc,UP);
	}
	if(stripper2_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&stripper2_npc,30))NPC_stare_at_npc(&stripper2_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&stripper2_npc, UP);
		//TODO: ANIMATE
		if(ACTION_npc(&stripper2_npc,"Talk To Dancer"))
		{
			TEXT_set_sprite_window(0,stripper2_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
	static NPC* stripper3_npc = NULL;
	if(stripper3_npc==NULL)
	{
		NPC_create_npc_xy_feet(&stripper3_npc,GFX_ADULT_dancer,16,40,23*8,13*8);
		stripper3_npc->layer=2;
		stripper3_npc->non_walkable=1;
		NPC_animate_stand_dir(&stripper3_npc,DOWN);
	}
	if(stripper3_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&stripper3_npc,30))NPC_stare_at_npc(&stripper3_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&stripper3_npc, DOWN);
		//TODO: ANIMATE
		if(ACTION_npc(&stripper3_npc,"Talk To Dancer"))
		{
			TEXT_set_sprite_window(0,stripper3_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}

	if(walking_into_door(RANGE_CITYTheCafeDressingRoomToTheCafe))
	{
		MAP_change_map(MAP_bobsgame_CITYTheCafe,13,15);return;
	}
	if(walking_into_door(RANGE_CITYTheCafeDressingRoomToStage))
	{
		MAP_change_map(MAP_bobsgame_CITYTheCafe,26,8);return;
	}
}
void bobsgame_CITYTheCafeDressingRoom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYTheCafeDressingRoom_Map_VBL_Function()
{

}
void bobsgame_CITYTheCafeDressingRoom_Map_HBL_Function()
{

}



