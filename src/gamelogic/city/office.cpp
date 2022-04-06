//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================



#include "../../main.h"


#define RANGE_CITYOfficeEntranceToOUTSIDECity 29*8,43*8,37*8,44*8
#define RANGE_CITYOfficeEntranceToOfficeElevator 7*8,19*8,13*8,20*8
#define RANGE_CITYOfficeElevatorToSelectedFloor 5*8,19*8,11*8,20*8
#define RANGE_CITYOfficeWorkroomToOfficeElevator 7*8,19*8,13*8,20*8
#define RANGE_CITYOfficeBreakRoomToOfficeElevator 7*8,19*8,13*8,20*8
#define RANGE_CITYOfficeBossFloorToOfficeElevator 7*8,19*8,13*8,20*8

//========================================================
//CITYOfficeEntrance
//========================================================
void bobsgame_CITYOfficeEntrance_Map_Load_Function()
{
//RANGE_CITYOfficeEntranceToOUTSIDECity 29*8,43*8,37*8,44*8
//RANGE_CITYOfficeEntranceToOfficeElevator 7*8,19*8,13*8,20*8
}
void bobsgame_CITYOfficeEntrance_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//18,36 right secretary
//22,32-38 talk to secretary
	static NPC* officelady_npc = NULL;
	if(officelady_npc==NULL)
	{
		NPC_create_npc_xy_feet(&officelady_npc,GFX_ADULT_secretary,16,40,19*8-4,35*8);
		officelady_npc->non_walkable=1;
		//officelady_npc->pushable=1;
		officelady_npc->layer=1;
		NPC_animate_stand_dir(&officelady_npc, RIGHT);
	}
	else if(officelady_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&officelady_npc,30))NPC_stare_at_npc(&officelady_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&officelady_npc, RIGHT);
		if(ACTION_range_xy_xy(21*8,32*8,22*8,38*8,"Talk To Office Lady"))
		{
			TEXT_set_sprite_window(0,officelady_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);//TODO: make appointment for upstairs
			//get elevator pass
		}
	}
//52 22 down couch
//28 12 down
//46 33 right couch
	static NPC* officeentrance_npcs[5] = {NULL,NULL,NULL,NULL,NULL};
	int c=0;
	for(c=0;c<5;c++)
	{
		if(officeentrance_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			int dir=UP;
			int bgp=2;
			if(c== 0){x=54*8;y=22*8;dir=DOWN;}
			if(c== 1){x=30*8;y=12*8;dir=DOWN;}
			if(c== 2){x=47*8+3;y=33*8;dir=RIGHT;}
			if(c== 3){x=50*8;y=22*8;dir=DOWN;}
			if(c== 4){x=27*8;y=12*8;dir=DOWN;}
			NPC_create_random_ADULT_OR_CHILD_xy_feet(&officeentrance_npcs[c],x,(y)+3);
			NPC_animate_stand_dir(&officeentrance_npcs[c], dir);
			officeentrance_npcs[c]->non_walkable=1;
			officeentrance_npcs[c]->walk_dir=dir;
			officeentrance_npcs[c]->layer=bgp;
		}
		if(officeentrance_npcs[c]!=NULL)
		{
			//if(NPC_in_range_of_npc_amt(&PLAYER_npc,officeentrance_npcs[c],12))NPC_stare_at_npc(&officeentrance_npcs[c],PLAYER_npc);
			//else NPC_animate_set_direction_now(&officeentrance_npcs[c], officeentrance_npcs[c]->walking_direction);
		}
	}
	//15-17 20 plaque on the wall
	if(ACTION_range_xy_xy(15*8,19*8,17*8,20*8,"Read Plaque"))
	{
		TEXT_set_sprite_window(0,PLAYER_npc,NULL);
		TEXT_set_sprite_window(1,PLAYER_npc,NULL);
		TEXT_window(""
		);
	}
	//TODO: guy talking to people at couch
	//walks to the water cooler? paces back and forth?

	if(walking_into_door(RANGE_CITYOfficeEntranceToOUTSIDECity))
	{
		MAP_change_map(MAP_bobsgame_CITYCity,709,39);return;
	}
	if(walking_into_door(RANGE_CITYOfficeEntranceToOfficeElevator))
	{
		MAP_change_map(MAP_bobsgame_CITYOfficeElevator,7,18);return;
		//TODO: need elevator pass
	}
}
void bobsgame_CITYOfficeEntrance_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYOfficeEntrance_Map_VBL_Function()
{

}
void bobsgame_CITYOfficeEntrance_Map_HBL_Function()
{

}
//========================================================
//CITYOfficeElevator
//========================================================
void bobsgame_CITYOfficeElevator_Map_Load_Function()
{
//RANGE_CITYOfficeElevatorToSelectedFloor 5*8,19*8,11*8,20*8
}
void bobsgame_CITYOfficeElevator_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

	static int floor=0;
	static int door_locked=0;
	int animate=0;
	if(ACTION_range_xy_xy(2*8,18*8,5*8,19*8,"Select Floor"))
	{
		TEXT_set_sprite_window(0,PLAYER_npc,NULL);
		TEXT_set_sprite_window(1,PLAYER_npc,NULL);
		TEXT_window("Which floor?<Q:Entrance 1F:Workroom 2F:Breakroom 3F:Management 4F>"
		);
	}
	//if select same floor no ding
	//if no floor selected leave to same floor
	//if selected floor cant leave while animating
	if(strcmp(TEXTANSWER_selected_answer_string,"Entrance 1F")==0&&floor!=0){floor=0;door_locked=1;animate=1;}
	if(strcmp(TEXTANSWER_selected_answer_string,"Workroom 2F")==0&&floor!=1){floor=1;door_locked=1;animate=1;}
	if(strcmp(TEXTANSWER_selected_answer_string,"Breakroom 3F")==0&&floor!=2){floor=2;door_locked=1;animate=1;}
	if(strcmp(TEXTANSWER_selected_answer_string,"Management 4F")==0&&floor!=3){floor=3;door_locked=1;animate=1;}
	//if animation done, ding sound
	if(animate==1)
	{
		//TODO: screen shake
		//ding
		HARDWARE_play_sound("elevatording",127,44100,0);
		door_locked=0;
		animate=0;
	}

	if(walking_into_door(RANGE_CITYOfficeElevatorToSelectedFloor)
		&&door_locked==0)
	{
		//change to selected floor
		if(floor==0){MAP_change_map(MAP_bobsgame_CITYOfficeEntrance,9,20);return;}
		if(floor==1){MAP_change_map(MAP_bobsgame_CITYOfficeWorkroom,9,20);return;}
		if(floor==2){MAP_change_map(MAP_bobsgame_CITYOfficeBreakRoom,9,20);return;}
		if(floor==3){MAP_change_map(MAP_bobsgame_CITYOfficeBossFloor,9,20);return;}
	}
}
void bobsgame_CITYOfficeElevator_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYOfficeElevator_Map_VBL_Function()
{

}
void bobsgame_CITYOfficeElevator_Map_HBL_Function()
{

}
//========================================================
//CITYOfficeWorkroom
//========================================================
void bobsgame_CITYOfficeWorkroom_Map_Load_Function()
{
//RANGE_CITYOfficeWorkroomToOfficeElevator 7*8,19*8,13*8,20*8
}
void bobsgame_CITYOfficeWorkroom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}
//watercooler 19,24 left
//16 24 right
//25,14 up
//41 14 up
//54 37 down
//39 37
//57 14 up
	static NPC* officeentrance_npcs[7] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	int c=0;
	for(c=0;c<7;c++)
	{
		if(officeentrance_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			int dir=UP;
			int bgp=2;
			GFX* gfx=NULL;
			if(c== 0){x=26*8;y=13*8;dir=UP;gfx=GFX_ADULT_businessguy;}
			if(c== 1){x=42*8;y=13*8;dir=UP;gfx=GFX_ADULT_officeworkermale;}
			if(c== 2){x=55*8;y=37*8;dir=DOWN;gfx=GFX_ADULT_officeworkerfemale;bgp=3;}
			if(c== 3){x=40*8;y=37*8;dir=DOWN;gfx=GFX_ADULT_officeworkermale;bgp=3;}
			if(c== 4){x=57*8;y=13*8;dir=UP;gfx=GFX_ADULT_fatmeekcoder;}
			if(c== 5){x=19*8;y=23*8;dir=LEFT;gfx=GFX_ADULT_skinnymeekcoder;}
			if(c== 6){x=16*8;y=23*8;dir=RIGHT;gfx=GFX_ADULT_officeworkerfemale;}
			NPC_create_npc_xy_feet(&officeentrance_npcs[c],gfx,16,40,x,(y));
			NPC_animate_stand_dir(&officeentrance_npcs[c], dir);
			officeentrance_npcs[c]->non_walkable=1;
			officeentrance_npcs[c]->walk_dir=dir;
			officeentrance_npcs[c]->layer=bgp;
		}
		if(officeentrance_npcs[c]!=NULL)
		{
			if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&officeentrance_npcs[c],15))NPC_stare_at_npc(&officeentrance_npcs[c],&PLAYER_npc);
			else NPC_animate_stand_dir(&officeentrance_npcs[c], officeentrance_npcs[c]->walk_dir);
		}
	}

	if(walking_into_door(RANGE_CITYOfficeWorkroomToOfficeElevator))
	{
		MAP_change_map(MAP_bobsgame_CITYOfficeElevator,7,18);return;
	}
}
void bobsgame_CITYOfficeWorkroom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYOfficeWorkroom_Map_VBL_Function()
{

}
void bobsgame_CITYOfficeWorkroom_Map_HBL_Function()
{

}
//========================================================
//CITYOfficeBreakRoom
//========================================================
void bobsgame_CITYOfficeBreakRoom_Map_Load_Function()
{
//RANGE_CITYOfficeBreakRoomToOfficeElevator 7*8,19*8,13*8,20*8
}
void bobsgame_CITYOfficeBreakRoom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//21,37 up
//19,29 down
//36 25 down
//29,30 down
//51,37 up over 1
//44,23 right
//44,33 right
	static NPC* officebreakroom_npcs[7] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	int c=0;
	for(c=0;c<7;c++)
	{
		if(officebreakroom_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			int dir=UP;
			int bgp=2;
			GFX* gfx=NULL;
			if(c== 0){x=16*8;y=37*8;dir=UP;			gfx=GFX_ADULT_businessguy;}
			if(c== 1){x=19*8;y=29*8;dir=DOWN;		gfx=GFX_ADULT_officeworkermale;}
			if(c== 2){x=36*8;y=25*8;dir=DOWN;		gfx=GFX_ADULT_officeworkerfemale;}
			if(c== 3){x=29*8;y=30*8;dir=DOWN;		gfx=GFX_ADULT_officeworkermale;}
			if(c== 4){x=51*8;y=37*8;dir=UP;			gfx=GFX_ADULT_skinnymeekcoder;}
			if(c== 5){x=44*8+3;y=23*8;dir=RIGHT;	gfx=GFX_ADULT_skinnymeekcoder;}
			if(c== 6){x=44*8+3;y=32*8;dir=RIGHT;	gfx=GFX_ADULT_officeworkerfemale;}
			NPC_create_npc_xy_feet(&officebreakroom_npcs[c],gfx,16,40,x,(y));
			NPC_animate_stand_dir(&officebreakroom_npcs[c], dir);
			officebreakroom_npcs[c]->non_walkable=1;
			officebreakroom_npcs[c]->walk_dir=dir;
			officebreakroom_npcs[c]->layer=bgp;
		}
		if(officebreakroom_npcs[c]!=NULL)
		{
			if(c<4&&NPC_in_range_of_npc_by_amount(&PLAYER_npc,&officebreakroom_npcs[c],15))NPC_stare_at_npc(&officebreakroom_npcs[c],&PLAYER_npc);
			else NPC_animate_stand_dir(&officebreakroom_npcs[c], officebreakroom_npcs[c]->walk_dir);
		}
	}
	if(walking_into_door(RANGE_CITYOfficeBreakRoomToOfficeElevator))
	{
		MAP_change_map(MAP_bobsgame_CITYOfficeElevator,7,18);return;
	}
}
void bobsgame_CITYOfficeBreakRoom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYOfficeBreakRoom_Map_VBL_Function()
{

}
void bobsgame_CITYOfficeBreakRoom_Map_HBL_Function()
{

}
//========================================================
//CITYOfficeBossFloor
//========================================================
void bobsgame_CITYOfficeBossFloor_Map_Load_Function()
{
	//RANGE_CITYOfficeBossFloorToOfficeElevator 7*8,19*8,13*8,20*8
}
void bobsgame_CITYOfficeBossFloor_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

	//26,36 over 3 up
	static NPC* officelady_npc = NULL;
	if(officelady_npc==NULL)
	{
		NPC_create_npc_xy_feet(&officelady_npc,GFX_ADULT_secretary,16,40,26*8,36*8-4);
		officelady_npc->non_walkable=1;
		//officelady_npc->pushable=1;
		officelady_npc->layer=3;
		NPC_animate_stand_dir(&officelady_npc, UP);
	}
	else if(officelady_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&officelady_npc,30))NPC_stare_at_npc(&officelady_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&officelady_npc, UP);
		if(ACTION_range_xy_xy(23*8,32*8,27*8,33*8,"Talk To Office Lady"))
		{
			TEXT_set_sprite_window(0,officelady_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
	//TODO: need boss in chair sprite, wheeling back and forth
	//49,23 face down
	//53 19 right
	//49, 17 up
	static NPC* officeboss_npc = NULL;
	if(officeboss_npc==NULL)
	{
		NPC_create_npc_xy_feet(&officeboss_npc,GFX_ADULT_secretary,16,40,49*8,22*8);
		officeboss_npc->non_walkable=1;
		//officeboss_npc->pushable=1;
		officeboss_npc->layer=2;
		NPC_animate_stand_dir(&officeboss_npc, DOWN);
	}
	else if(officeboss_npc!=NULL)
	{
		if(officeboss_npc->AI==0)if(NPC_walk_to_xy_nohit(&officeboss_npc,SPEED_FAST,53*8,17*8)==(1)){NPC_animate_stand_dir(&officeboss_npc,RIGHT);if(officeboss_npc->vbls>120){officeboss_npc->vbls=0;officeboss_npc->AI=r(3);}}
		if(officeboss_npc->AI==1)if(NPC_walk_to_xy_nohit(&officeboss_npc,SPEED_FAST,50*8,17*8)==(1)){NPC_animate_stand_dir(&officeboss_npc,UP);if(officeboss_npc->vbls>120){officeboss_npc->vbls=0;officeboss_npc->AI=r(3);}}
		if(officeboss_npc->AI==2)if(NPC_walk_to_xy_nohit(&officeboss_npc,SPEED_FAST,51*8,22*8)==(1)){NPC_animate_stand_dir(&officeboss_npc,DOWN);if(officeboss_npc->vbls>120){officeboss_npc->vbls=0;officeboss_npc->AI=r(3);}}
		if(officeboss_npc->AI==3)if(NPC_walk_to_xy_nohit(&officeboss_npc,SPEED_FAST,49*8,22*8)==(1)){NPC_animate_stand_dir(&officeboss_npc,DOWN);}
	}
	if(walking_into_door(RANGE_CITYOfficeBossFloorToOfficeElevator))
	{
		MAP_change_map(MAP_bobsgame_CITYOfficeElevator,7,18);return;
	}
}
void bobsgame_CITYOfficeBossFloor_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYOfficeBossFloor_Map_VBL_Function()
{

}
void bobsgame_CITYOfficeBossFloor_Map_HBL_Function()
{

}


