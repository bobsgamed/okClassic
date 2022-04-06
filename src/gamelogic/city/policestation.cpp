//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================


#include "../../main.h"



#define RANGE_CITYPoliceStationLobbyToOUTSIDECity 17*8,22*8,25*8,23*8
#define RANGE_CITYPoliceStationLobbyToOffice 3*8,10*8,7*8,11*8
#define RANGE_CITYPoliceStationLobbyToPrisonStairs 25*8,10*8,29*8,11*8
#define RANGE_CITYPoliceStationOfficeToLobby 3*8,47*8,7*8,48*8
#define RANGE_CITYPoliceStationOfficeTo2WayRoom 3*8,9*8,7*8,10*8
#define RANGE_CITYPoliceStationInterrogationRoomToPrisonStairsHall 11*8,22*8,15*8,23*8
#define RANGE_CITYPoliceStation2WayMirrorToOffice 3*8,27*8,7*8,28*8
#define RANGE_CITYPoliceStation2WayMirrorToEvidenceRoom 3*8,14*8,7*8,15*8
#define RANGE_CITYPoliceStationEvidenceRoomTo2WayMirror 3*8,24*8,7*8,25*8
#define RANGE_CITYPoliceStationPrisonStairsToLobby 8*8,47*8,12*8,48*8
#define RANGE_CITYPoliceStationPrisonStairsToHoldingCell 2*8,22*8,6*8,23*8
#define RANGE_CITYPoliceStationPrisonStairsToInterrogationRoom 8*8,9*8,12*8,10*8
#define RANGE_CITYPoliceStationHoldingCellsToPrisonStairs 19*8,26*8,23*8,27*8
#define RANGE_CITYPoliceStationHoldingCellsToVisitingRoom 25*8,9*8,29*8,10*8
#define RANGE_CITYPoliceStationPrisonVisitingRoomToHoldingCell 25*8,31*8,29*8,32*8
#define RANGE_CITYPoliceStationPrisonVisitingRoomToPrisonHallway 25*8,9*8,29*8,10*8
#define RANGE_CITYPoliceStationPrisonHallwayToVisitingRoom 25*8,87*8,29*8,88*8
#define RANGE_CITYPoliceStationPrisonHallwayToPrisonCell 16*8,28*8,20*8,29*8
#define RANGE_CITYPoliceStationPrisonCellToPrisonHallway 5*8,9*8,9*8,10*8




//========================================================
//CITYPoliceStationLobby
//========================================================
void bobsgame_CITYPoliceStationLobby_Map_Load_Function()
{
//RANGE_CITYPoliceStationLobbyToOUTSIDECity 17*8,22*8,25*8,23*8
//RANGE_CITYPoliceStationLobbyToOffice 3*8,10*8,7*8,11*8
//RANGE_CITYPoliceStationLobbyToPrisonStairs 25*8,10*8,29*8,11*8
}
void bobsgame_CITYPoliceStationLobby_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}
//8,20 up
//10,20up
//14,20up
//4,19,right over 1
//4,16 right over 1

	static NPC* policelobby_npcs[5] = {NULL,NULL,NULL,NULL,NULL};
	int c=0;
	for(c=0;c<5;c++)
	{
		if(policelobby_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			int dir=UP;
			int bgp=2;
			//int* gfx=NULL;
			if(c== 0){x= 8*8;y=20*8;dir=UP;}
			if(c== 1){x=10*8;y=20*8;dir=UP;}
			if(c== 2){x=14*8;y=20*8;dir=UP;}
			if(c== 3){x= 4*8-4;y=19*8;dir=RIGHT;bgp=1;}
			if(c== 4){x= 4*8-4;y=16*8;dir=RIGHT;bgp=1;}
			NPC_create_random_ADULT_xy_feet(&policelobby_npcs[c],x,y);

			//NPC_create_npc_xy_feet(&policelobby_npcs[c],gfx,16,40,x,(y));
			NPC_animate_stand_dir(&policelobby_npcs[c], dir);
			policelobby_npcs[c]->non_walkable=1;
			policelobby_npcs[c]->walk_dir=dir;
			policelobby_npcs[c]->layer=bgp;
			//NPC_animate_increment_direction_frame_now(&policelobby_npcs[c], dir);
		}
		if(policelobby_npcs[c]!=NULL)
		{
			if(policelobby_npcs[c]->AI==0){if(policelobby_npcs[c]->vbls>200){if(r(3)==0){policelobby_npcs[c]->AI=1+r(3);}else{policelobby_npcs[c]->vbls=0;NPC_animate_stand_dir(&policelobby_npcs[c], policelobby_npcs[c]->walk_dir);if(policelobby_npcs[c]->anim_frame_count!=0){policelobby_npcs[c]->anim_frame_count=3;NPC_animate(&policelobby_npcs[c]);}}}}
			if(policelobby_npcs[c]->AI==1){if(policelobby_npcs[c]->walk_dir==UP||policelobby_npcs[c]->walk_dir==DOWN)NPC_animate_stand_dir(&policelobby_npcs[c],LEFT);else NPC_animate_stand_dir(&policelobby_npcs[c],UP);policelobby_npcs[c]->vbls=r(120);policelobby_npcs[c]->AI=0;}
			if(policelobby_npcs[c]->AI==2){if(policelobby_npcs[c]->walk_dir==UP||policelobby_npcs[c]->walk_dir==DOWN)NPC_animate_stand_dir(&policelobby_npcs[c],RIGHT);else NPC_animate_stand_dir(&policelobby_npcs[c],DOWN);policelobby_npcs[c]->vbls=r(120);policelobby_npcs[c]->AI=0;}
			if(policelobby_npcs[c]->AI==3){NPC_animate(&policelobby_npcs[c]);policelobby_npcs[c]->vbls=r(120);policelobby_npcs[c]->AI=0;}
			//if(NPC_in_range_of_npc_amt(&PLAYER_npc,policelobby_npcs[c],15))NPC_stare_at_npc(&policelobby_npcs[c],PLAYER_npc);
			//else NPC_animate_set_direction_now(&policelobby_npcs[c], policelobby_npcs[c]->walking_direction);
		}
	}
	//11,8, down under 3
	static NPC* lobbycop_npc = NULL;
	if(lobbycop_npc==NULL)
	{
		NPC_create_npc_xy_feet(&lobbycop_npc,GFX_ADULT_policeofficerfemale,16,40,11*8,8*8-3);
		//NPC_create_random_ADULT_xy_feet(&lobbycop_npc,11*8,34*8);
		lobbycop_npc->layer=3;
		lobbycop_npc->non_walkable=1;
		NPC_animate_stand_dir(&lobbycop_npc,DOWN);
		lobbycop_npc->walking_speed = SPEED_NORMAL;
		lobbycop_npc->AI=0;
	}
	if(lobbycop_npc!=NULL)
	{
		if(ACTION_range_xy_xy(9*8,9*8,14*8,10*8,"Submit To Authority"))//Surrender, Admit Guilt, Turn Self In, Sign Confession
		{
			TEXT_set_sprite_window(0,lobbycop_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}

	if(walking_into_door(RANGE_CITYPoliceStationLobbyToOUTSIDECity))
	{
		MAP_change_map(MAP_bobsgame_CITYCity,1342,39);return;
	}
	if(walking_into_door(RANGE_CITYPoliceStationLobbyToOffice))
	{
		MAP_change_map(MAP_bobsgame_CITYPoliceStationOffice,5,46);return;
	}
	if(walking_into_door(RANGE_CITYPoliceStationLobbyToPrisonStairs))
	{
		MAP_change_map(MAP_bobsgame_CITYPoliceStationStairWellToHoldCell,10,46);return;
		//TODO: this should be locked unless you're caught by the cops
	}
}
void bobsgame_CITYPoliceStationLobby_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYPoliceStationLobby_Map_VBL_Function()
{

}
void bobsgame_CITYPoliceStationLobby_Map_HBL_Function()
{

}
//========================================================
//CITYPoliceStationOffice
//========================================================
void bobsgame_CITYPoliceStationOffice_Map_Load_Function()
{
//RANGE_CITYPoliceStationOfficeToLobby 3*8,47*8,7*8,48*8
//RANGE_CITYPoliceStationOfficeTo2WayRoom 3*8,9*8,7*8,10*8
}
void bobsgame_CITYPoliceStationOffice_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}
//detectives
//13,41 up under 2
//13,33 up
//officers
//19.18 down
//15,18 down
//11,18 down
//7,22 right
//11 24 up under 2
//15 24 up under 2
//19 24 up under 2
	static NPC* policelobby_npcs[9] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	int c=0;
	for(c=0;c<9;c++)
	{
		if(policelobby_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			int dir=UP;
			int bgp=2;
			GFX* gfx=NULL;
			if(c== 0){x=19*8;y=17*8;dir=DOWN;		gfx=GFX_ADULT_policeofficermale;}
			if(c== 1){x=15*8;y=17*8;dir=DOWN;		gfx=GFX_ADULT_securityguard;}
			if(c== 2){x=11*8;y=17*8;dir=DOWN;		gfx=GFX_ADULT_policeofficerfemale;}
			if(c== 3){x= 7*8+3;y=22*8;dir=RIGHT;	gfx=GFX_ADULT_privateeye;}
			if(c== 4){x=11*8;y=24*8-4;dir=UP;bgp=2;	gfx=GFX_ADULT_policeofficermale;}
			if(c== 5){x=15*8;y=24*8-4;dir=UP;bgp=2;	gfx=GFX_ADULT_securityguard;}
			if(c== 6){x=19*8;y=24*8-4;dir=UP;bgp=2;	gfx=GFX_ADULT_swat;}
			if(c== 7){x=13*8;y=42*8-1;dir=UP;bgp=2;	gfx=GFX_ADULT_policeofficerfemale;}
			if(c== 8){x=13*8;y=33*8-1;dir=UP;bgp=2;	gfx=GFX_ADULT_policeofficermale;}
			//NPC_create_random_ADULT_xy_feet(&policelobby_npcs[c],x,y);
			NPC_create_npc_xy_feet(&policelobby_npcs[c],gfx,16,40,x,(y));
			NPC_animate_stand_dir(&policelobby_npcs[c], dir);
			policelobby_npcs[c]->non_walkable=1;
			policelobby_npcs[c]->walk_dir=dir;
			policelobby_npcs[c]->layer=bgp;
			//NPC_animate_increment_direction_frame_now(&policelobby_npcs[c], dir);
		}
		if(policelobby_npcs[c]!=NULL)
		{
			if(policelobby_npcs[c]->AI==0){if(policelobby_npcs[c]->vbls>200){if(r(3)==0){policelobby_npcs[c]->AI=1+r(3);}else{policelobby_npcs[c]->vbls=0;NPC_animate_stand_dir(&policelobby_npcs[c], policelobby_npcs[c]->walk_dir);if(policelobby_npcs[c]->anim_frame_count!=0){policelobby_npcs[c]->anim_frame_count=3;NPC_animate(&policelobby_npcs[c]);}}}}
			if(policelobby_npcs[c]->AI==1){if(policelobby_npcs[c]->walk_dir==UP||policelobby_npcs[c]->walk_dir==DOWN)NPC_animate_stand_dir(&policelobby_npcs[c],LEFT);else NPC_animate_stand_dir(&policelobby_npcs[c],UP);policelobby_npcs[c]->vbls=r(120);policelobby_npcs[c]->AI=0;}
			if(policelobby_npcs[c]->AI==2){if(policelobby_npcs[c]->walk_dir==UP||policelobby_npcs[c]->walk_dir==DOWN)NPC_animate_stand_dir(&policelobby_npcs[c],RIGHT);else NPC_animate_stand_dir(&policelobby_npcs[c],DOWN);policelobby_npcs[c]->vbls=r(120);policelobby_npcs[c]->AI=0;}
			if(policelobby_npcs[c]->AI==3){NPC_animate(&policelobby_npcs[c]);policelobby_npcs[c]->vbls=r(120);policelobby_npcs[c]->AI=0;}
			//if(NPC_in_range_of_npc_amt(&PLAYER_npc,policelobby_npcs[c],15))NPC_stare_at_npc(&policelobby_npcs[c],PLAYER_npc);
			//else NPC_animate_set_direction_now(&policelobby_npcs[c], policelobby_npcs[c]->walking_direction);
		}
	}

//chief
//15,13 down

	static NPC* chief_npc = NULL;
	if(chief_npc==NULL)
	{
		NPC_create_npc_xy_feet(&chief_npc,GFX_ADULT_townsheriff,16,40,15*8,12*8);
		//NPC_create_random_ADULT_xy_feet(&chief_npc,11*8,34*8);
		chief_npc->layer=2;
		chief_npc->non_walkable=1;
		NPC_animate_stand_dir(&chief_npc,DOWN);
		chief_npc->walking_speed = SPEED_NORMAL;
		chief_npc->AI=0;
	}
	if(chief_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&chief_npc,15))NPC_stare_at_npc(&chief_npc,&PLAYER_npc);
		//else NPC_animate_set_direction_now(&chief_npc, LEFT);
		else if(chief_npc->AI== 0){if(NPC_walk_to_xy_nohit_pushmain(&chief_npc,SPEED_NORMAL,	20*8,12*8)==1){NPC_animate_stand_dir(&chief_npc,DOWN);chief_npc->vbls=r(40);chief_npc->AI++;}}
		else if(chief_npc->AI== 1){if(chief_npc->vbls>120)chief_npc->AI++;}
		else if(chief_npc->AI== 2){if(NPC_walk_to_xy_nohit_pushmain(&chief_npc,SPEED_NORMAL,  17*8,12*8)==1){NPC_animate_stand_dir(&chief_npc,UP);chief_npc->vbls=r(40);chief_npc->AI++;}}
		else if(chief_npc->AI== 3){if(chief_npc->vbls>120)chief_npc->AI++;}
		else if(chief_npc->AI== 4){if(NPC_walk_to_xy_nohit_pushmain(&chief_npc,SPEED_NORMAL,  14*8,12*8)==1){NPC_animate_stand_dir(&chief_npc,DOWN);chief_npc->vbls=r(40);chief_npc->AI++;}}
		else if(chief_npc->AI== 5){if(chief_npc->vbls>120)chief_npc->AI=0;}
		if(ACTION_npc(&chief_npc,"Talk To Sheriff"))
		{
			TEXT_set_sprite_window(0,chief_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
	if(walking_into_door(RANGE_CITYPoliceStationOfficeToLobby))
	{
		MAP_change_map(MAP_bobsgame_CITYPoliceStationLobby,5,11);return;
	}
	if(walking_into_door(RANGE_CITYPoliceStationOfficeTo2WayRoom))
	{
		MAP_change_map(MAP_bobsgame_CITYPoliceStationOffice2WayMirror,5,26);return;
	}
}
void bobsgame_CITYPoliceStationOffice_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYPoliceStationOffice_Map_VBL_Function()
{

}
void bobsgame_CITYPoliceStationOffice_Map_HBL_Function()
{

}
//========================================================
//CITYPoliceStationInterrogationRoom
//========================================================
void bobsgame_CITYPoliceStationInterrogationRoom_Map_Load_Function()
{
//RANGE_CITYPoliceStationInterrogationRoomToPrisonStairsHall 11*8,22*8,15*8,23*8
}
void bobsgame_CITYPoliceStationInterrogationRoom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//TODO: need good cop bad cop. need fat donut cop sprite.
//should have swat guy
//
//fat donut cop will be the mean one :)
//kick a chair or something

//11,13 left
	static NPC* interrogator_npc = NULL;
	if(interrogator_npc==NULL)
	{
		NPC_create_npc_xy_feet(&interrogator_npc,GFX_ADULT_swat,16,40,12*8,13*8);
		//NPC_create_random_ADULT_xy_feet(&interrogator_npc,11*8,34*8);
		interrogator_npc->layer=2;
		interrogator_npc->non_walkable=1;
		NPC_animate_stand_dir(&interrogator_npc,LEFT);
		interrogator_npc->walking_speed = SPEED_NORMAL;
		interrogator_npc->AI=0;
	}
	if(interrogator_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&interrogator_npc,15))NPC_stare_at_npc(&interrogator_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&interrogator_npc, LEFT);

		if(ACTION_npc(&interrogator_npc,"Talk To Sheriff"))
		{
			TEXT_set_sprite_window(0,interrogator_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
	static NPC* mime_npc = NULL;
	if(mime_npc==NULL)
	{
		NPC_create_npc_xy_feet(&mime_npc,GFX_ADULT_mime,16,40,6*8-2,13*8);
		//NPC_create_random_ADULT_xy_feet(&mime_npc,11*8,34*8);
		mime_npc->layer=1;
		mime_npc->non_walkable=1;
		NPC_animate_stand_dir(&mime_npc,RIGHT);
		mime_npc->walking_speed = SPEED_SLOWEST*4;
		mime_npc->AI=0;
	}
	if(mime_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&mime_npc,15))NPC_stare_at_npc(&mime_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&mime_npc, RIGHT);
		if(NPC_should_animate(&mime_npc))NPC_animate_dir(&mime_npc,mime_npc->anim_dir);
	}
	//4-6 12-13 sit in chair
	if(ACTION_range_xy_xy(4*8,12*8,6*8,13*8,"Confess! Admit It, Punk!"))
	{
		//you sit at 5,13 face right over 1
		TEXT_set_sprite_window(0,PLAYER_npc,NULL);
		TEXT_set_sprite_window(1,PLAYER_npc,NULL);
		TEXT_window(""
		);
	}

	if(walking_into_door(RANGE_CITYPoliceStationInterrogationRoomToPrisonStairsHall))
	{
		MAP_change_map(MAP_bobsgame_CITYPoliceStationStairWellToHoldCell,10,10);return;
	}
}
void bobsgame_CITYPoliceStationInterrogationRoom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYPoliceStationInterrogationRoom_Map_VBL_Function()
{

}
void bobsgame_CITYPoliceStationInterrogationRoom_Map_HBL_Function()
{

}
//========================================================
//CITYPoliceStationOffice2WayMirror
//========================================================
void bobsgame_CITYPoliceStationOffice2WayMirror_Map_Load_Function()
{
//RANGE_CITYPoliceStation2WayMirrorToOffice 3*8,27*8,7*8,28*8
//RANGE_CITYPoliceStation2WayMirrorToEvidenceRoom 3*8,14*8,7*8,15*8
}
void bobsgame_CITYPoliceStationOffice2WayMirror_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//yuu's controls are off, automatically place him in chair, have guy screaming at him
//cia guy standing there if event sequence.
//19,13 down cia
	static NPC* cia_npc = NULL;
	if(cia_npc==NULL)
	{
		NPC_create_npc_xy_feet(&cia_npc,GFX_ADULT_cia,16,40,19*8,12*8);
		//NPC_create_random_ADULT_xy_feet(&cia_npc,11*8,34*8);
		cia_npc->layer=2;
		cia_npc->non_walkable=1;
		NPC_animate_stand_dir(&cia_npc,DOWN);
		cia_npc->walking_speed = SPEED_NORMAL;
		cia_npc->AI=0;
	}
	if(cia_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&cia_npc,15))NPC_stare_at_npc(&cia_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&cia_npc, DOWN);

		if(ACTION_npc(&cia_npc,"Talk To Spook"))
		{
			TEXT_set_sprite_window(0,cia_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
	static NPC* mime_npc = NULL;
	if(mime_npc==NULL)
	{
		NPC_create_npc_xy_feet(&mime_npc,GFX_ADULT_mime,16,40,20*8-2,18*8);
		//NPC_create_random_ADULT_xy_feet(&mime_npc,11*8,34*8);
		mime_npc->layer=1;
		mime_npc->non_walkable=1;
		NPC_animate_stand_dir(&mime_npc,RIGHT);
		mime_npc->walking_speed = SPEED_SLOWEST*4;
		mime_npc->AI=0;
	}
	if(mime_npc!=NULL)
	{
		if(NPC_should_animate(&mime_npc))NPC_animate_dir(&mime_npc,mime_npc->anim_dir);
	}
	static NPC* interrogator_npc = NULL;
	if(interrogator_npc==NULL)
	{
		NPC_create_npc_xy_feet(&interrogator_npc,GFX_ADULT_swat,16,40,26*8,18*8);
		//NPC_create_random_ADULT_xy_feet(&interrogator_npc,11*8,34*8);
		interrogator_npc->layer=2;
		interrogator_npc->non_walkable=1;
		NPC_animate_stand_dir(&interrogator_npc,LEFT);
		interrogator_npc->walking_speed = SPEED_NORMAL;
		interrogator_npc->AI=0;
	}
	if(interrogator_npc!=NULL)
	{

	}

	if(walking_into_door(RANGE_CITYPoliceStation2WayMirrorToOffice))
	{
		MAP_change_map(MAP_bobsgame_CITYPoliceStationOffice,5,10);return;
	}
	if(walking_into_door(RANGE_CITYPoliceStation2WayMirrorToEvidenceRoom))
	{
		MAP_change_map(MAP_bobsgame_CITYPoliceStationEvidenceRoom,5,23);return;
	}
}
void bobsgame_CITYPoliceStationOffice2WayMirror_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYPoliceStationOffice2WayMirror_Map_VBL_Function()
{

}
void bobsgame_CITYPoliceStationOffice2WayMirror_Map_HBL_Function()
{

}
//========================================================
//CITYPoliceStationEvidenceRoom
//========================================================
void bobsgame_CITYPoliceStationEvidenceRoom_Map_Load_Function()
{
//RANGE_CITYPoliceStationEvidenceRoomTo2WayMirror 3*8,24*8,7*8,25*8
}
void bobsgame_CITYPoliceStationEvidenceRoom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//filing cabinets 21-26 ,11

	if(walking_into_door(RANGE_CITYPoliceStationEvidenceRoomTo2WayMirror))
	{
		MAP_change_map(MAP_bobsgame_CITYPoliceStationOffice2WayMirror,5,15);return;
	}
}
void bobsgame_CITYPoliceStationEvidenceRoom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYPoliceStationEvidenceRoom_Map_VBL_Function()
{

}
void bobsgame_CITYPoliceStationEvidenceRoom_Map_HBL_Function()
{

}
//========================================================
//CITYPoliceStationStairWellToHoldCell
//========================================================
void bobsgame_CITYPoliceStationStairWellToHoldCell_Map_Load_Function()
{
//RANGE_CITYPoliceStationPrisonStairsToLobby 8*8,47*8,12*8,48*8
//RANGE_CITYPoliceStationPrisonStairsToHoldingCell 2*8,22*8,6*8,23*8
//RANGE_CITYPoliceStationPrisonStairsToInterrogationRoom 8*8,9*8,12*8,10*8
}
void bobsgame_CITYPoliceStationStairWellToHoldCell_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}
	if(walking_into_door(RANGE_CITYPoliceStationPrisonStairsToLobby))
	{
		MAP_change_map(MAP_bobsgame_CITYPoliceStationLobby,28,10);return;
	}
	if(walking_into_door(RANGE_CITYPoliceStationPrisonStairsToHoldingCell))
	{
		MAP_change_map(MAP_bobsgame_CITYPoliceStationHoldingCells,21,25);return;
	}
	if(walking_into_door(RANGE_CITYPoliceStationPrisonStairsToInterrogationRoom))
	{
		MAP_change_map(MAP_bobsgame_CITYPoliceStationInterrogationRoom,13,21);return;
	}
}
void bobsgame_CITYPoliceStationStairWellToHoldCell_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYPoliceStationStairWellToHoldCell_Map_VBL_Function()
{

}
void bobsgame_CITYPoliceStationStairWellToHoldCell_Map_HBL_Function()
{

}
//========================================================
//CITYPoliceStationHoldingCells
//========================================================
void bobsgame_CITYPoliceStationHoldingCells_Map_Load_Function()
{
//RANGE_CITYPoliceStationHoldingCellsToPrisonStairs 19*8,26*8,23*8,27*8
//RANGE_CITYPoliceStationHoldingCellsToVisitingRoom 25*8,9*8,29*8,10*8
}
void bobsgame_CITYPoliceStationHoldingCells_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}
//a few people in holding cell.
//12,12 right under 2
//10,10,left under 2
//15,15 down under 2
	static NPC* holding_npcs[3] = {NULL,NULL,NULL};
	int c=0;
	for(c=0;c<3;c++)
	{
		if(holding_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			int dir=UP;
			int bgp=2;
			GFX* gfx=NULL;
			if(c== 0){x=11*8;y=11*8;dir=RIGHT;		bgp=2;	gfx=GFX_ADULT_thug;}
			if(c== 1){x= 9*8;y=10*8;dir=LEFT;		bgp=2;	gfx=GFX_ADULT_prostitute;}
			if(c== 2){x=15*8+4;y=15*8+5;dir=DOWN;	bgp=3;	gfx=GFX_ADULT_hobo;}
			//NPC_create_random_ADULT_xy_feet(&holding_npcs[c],x,y);
			NPC_create_npc_xy_feet(&holding_npcs[c],gfx,16,40,x,y);
			NPC_animate_stand_dir(&holding_npcs[c], dir);
			holding_npcs[c]->non_walkable=1;
			holding_npcs[c]->walk_dir=dir;
			holding_npcs[c]->layer=bgp;
			//NPC_animate_increment_direction_frame_now(&holding_npcs[c], dir);
		}
		if(holding_npcs[c]!=NULL)
		{
			if(holding_npcs[c]->AI==0){if(holding_npcs[c]->vbls>200){if(r(4)==0){holding_npcs[c]->AI=1+r(3);}else{holding_npcs[c]->vbls=0;NPC_animate_stand_dir(&holding_npcs[c], holding_npcs[c]->walk_dir);if(holding_npcs[c]->anim_frame_count!=0){holding_npcs[c]->anim_frame_count=3;NPC_animate(&holding_npcs[c]);}}}}
			if(holding_npcs[c]->AI==1){if(holding_npcs[c]->walk_dir==UP||holding_npcs[c]->walk_dir==DOWN)NPC_animate_stand_dir(&holding_npcs[c],LEFT);else NPC_animate_stand_dir(&holding_npcs[c],UP);holding_npcs[c]->vbls=r(120);holding_npcs[c]->AI=0;}
			if(holding_npcs[c]->AI==2){if(holding_npcs[c]->walk_dir==UP||holding_npcs[c]->walk_dir==DOWN)NPC_animate_stand_dir(&holding_npcs[c],RIGHT);else NPC_animate_stand_dir(&holding_npcs[c],DOWN);holding_npcs[c]->vbls=r(120);holding_npcs[c]->AI=0;}
			if(holding_npcs[c]->AI==3){NPC_animate(&holding_npcs[c]);holding_npcs[c]->vbls=r(120);holding_npcs[c]->AI=0;}
			//if(NPC_in_range_of_npc_amt(&PLAYER_npc,holding_npcs[c],15))NPC_stare_at_npc(&holding_npcs[c],PLAYER_npc);
			//else NPC_animate_set_direction_now(&holding_npcs[c], holding_npcs[c]->walking_direction);
		}
	}
//officer waiting.
//28,21 left over 1
//24,18-23 talk to
	static NPC* holdingcop_npc = NULL;
	if(holdingcop_npc==NULL)
	{
		NPC_create_npc_xy_feet(&holdingcop_npc,GFX_ADULT_policeofficermale,16,40,28*8,20*8);
		//NPC_create_random_ADULT_xy_feet(&holdingcop_npc,11*8,34*8);
		holdingcop_npc->layer=1;
		holdingcop_npc->non_walkable=1;
		NPC_animate_stand_dir(&holdingcop_npc,LEFT);
		holdingcop_npc->walking_speed = SPEED_NORMAL;
		holdingcop_npc->AI=0;
	}
	if(holdingcop_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&holdingcop_npc,15))NPC_stare_at_npc(&holdingcop_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&holdingcop_npc, LEFT);

		if(ACTION_range_xy_xy(24*8,18*8,25*8,23*8,"Talk To Officer"))
		{
			TEXT_set_sprite_window(0,holdingcop_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
//TODO: payphone 19-20,9

	if(walking_into_door(RANGE_CITYPoliceStationHoldingCellsToPrisonStairs))
	{
		MAP_change_map(MAP_bobsgame_CITYPoliceStationStairWellToHoldCell,4,23);return;
	}
	if(walking_into_door(RANGE_CITYPoliceStationHoldingCellsToVisitingRoom))
	{
		MAP_change_map(MAP_bobsgame_CITYPoliceStationPrisonVisitingRoom,27,30);return;
	}
}
void bobsgame_CITYPoliceStationHoldingCells_Map_Stop_Function()
{

	NPC_delete_all_npcs();
}
void bobsgame_CITYPoliceStationHoldingCells_Map_VBL_Function()
{

}
void bobsgame_CITYPoliceStationHoldingCells_Map_HBL_Function()
{

}
//========================================================
//CITYPoliceStationPrisonVisitingRoom
//========================================================
void bobsgame_CITYPoliceStationPrisonVisitingRoom_Map_Load_Function()
{
//RANGE_CITYPoliceStationPrisonVisitingRoomToHoldingCell 25*8,31*8,29*8,32*8
//RANGE_CITYPoliceStationPrisonVisitingRoomToPrisonHallway 25*8,9*8,29*8,10*8
}
void bobsgame_CITYPoliceStationPrisonVisitingRoom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}
//TODO: need more orange shirt people
// 9,23 up
//15,23 up
//21,23 up
//27,23 up
// 9,19 down
//15,19 down
//21,19 down
//27,19 down
	static NPC* holding_npcs[8] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	int c=0;
	for(c=0;c<8;c++)
	{
		if(holding_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			int dir=UP;
			int bgp=2;
			GFX* gfx=NULL;
			if(c== 0){x= 5*8;y=23*8-4;dir=UP;	bgp=2;}
			if(c== 1){x=11*8;y=23*8-4;dir=UP;	bgp=2;}
			if(c== 2){x=17*8;y=23*8-4;dir=UP;	bgp=2;}
			if(c== 3){x=23*8;y=23*8-4;dir=UP;	bgp=2;}

			if(c== 4){x= 5*8;y=19*8;dir=DOWN;	bgp=3;	gfx=GFX_ADULT_convict;}
			if(c== 5){x=11*8;y=19*8;dir=DOWN;	bgp=3;	gfx=GFX_ADULT_convict;}
			if(c== 6){x=17*8;y=19*8;dir=DOWN;	bgp=3;	gfx=GFX_ADULT_convict;}
			if(c== 7){x=23*8;y=19*8;dir=DOWN;	bgp=3;	gfx=GFX_ADULT_convict;}

			if(gfx==NULL)NPC_create_random_ADULT_xy_feet(&holding_npcs[c],x,y);
			else NPC_create_npc_xy_feet(&holding_npcs[c],gfx,16,40,x,y);
			NPC_animate_stand_dir(&holding_npcs[c], dir);
			holding_npcs[c]->non_walkable=1;
			holding_npcs[c]->walk_dir=dir;
			holding_npcs[c]->layer=bgp;
			//NPC_animate_increment_direction_frame_now(&holding_npcs[c], dir);
		}
		if(holding_npcs[c]!=NULL)
		{
			if(holding_npcs[c]->AI==0){if(holding_npcs[c]->vbls>200){if(r(4)==0){holding_npcs[c]->AI=1+r(3);}else{holding_npcs[c]->vbls=0;NPC_animate_stand_dir(&holding_npcs[c], holding_npcs[c]->walk_dir);if(holding_npcs[c]->anim_frame_count!=0){holding_npcs[c]->anim_frame_count=3;NPC_animate(&holding_npcs[c]);}}}}
			if(holding_npcs[c]->AI==1){if(holding_npcs[c]->walk_dir==UP||holding_npcs[c]->walk_dir==DOWN)NPC_animate_stand_dir(&holding_npcs[c],LEFT);else NPC_animate_stand_dir(&holding_npcs[c],UP);holding_npcs[c]->vbls=r(120);holding_npcs[c]->AI=0;}
			if(holding_npcs[c]->AI==2){if(holding_npcs[c]->walk_dir==UP||holding_npcs[c]->walk_dir==DOWN)NPC_animate_stand_dir(&holding_npcs[c],RIGHT);else NPC_animate_stand_dir(&holding_npcs[c],DOWN);holding_npcs[c]->vbls=r(120);holding_npcs[c]->AI=0;}
			if(holding_npcs[c]->AI==3){NPC_animate(&holding_npcs[c]);holding_npcs[c]->vbls=r(120);holding_npcs[c]->AI=0;}
			//if(NPC_in_range_of_npc_amt(&PLAYER_npc,holding_npcs[c],15))NPC_stare_at_npc(&holding_npcs[c],PLAYER_npc);
			//else NPC_animate_set_direction_now(&holding_npcs[c], holding_npcs[c]->walking_direction);
		}
	}

	static NPC* visitingguard_npc = NULL;
	if(visitingguard_npc==NULL)
	{
		NPC_create_npc_xy_feet(&visitingguard_npc,GFX_ADULT_policeofficermale,16,40,23*8,10*8+4);
		//NPC_create_random_ADULT_xy_feet(&visitingguard_npc,11*8,34*8);
		visitingguard_npc->layer=1;
		visitingguard_npc->non_walkable=1;
		NPC_animate_stand_dir(&visitingguard_npc,DOWN);
		visitingguard_npc->walking_speed = SPEED_NORMAL;
		visitingguard_npc->AI=0;
	}
	if(visitingguard_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&visitingguard_npc,15))NPC_stare_at_npc(&visitingguard_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&visitingguard_npc, DOWN);
		if(ACTION_range_xy_xy(26*8,21*8,30*8,22*8,"Call Officer"))
		{
			//TODO: have him walk to door, talk to you, then go back to wall, then door is open?
			TEXT_set_sprite_window(0,visitingguard_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
	//TODO: can't walk through door at 26-30,22

	if(walking_into_door(RANGE_CITYPoliceStationPrisonVisitingRoomToHoldingCell))
	{
		MAP_change_map(MAP_bobsgame_CITYPoliceStationHoldingCells,27,10);return;
	}
	if(walking_into_door(RANGE_CITYPoliceStationPrisonVisitingRoomToPrisonHallway))
	{
		MAP_change_map(MAP_bobsgame_CITYPoliceStationPrisonHallway,27,86);return;
	}
}
void bobsgame_CITYPoliceStationPrisonVisitingRoom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYPoliceStationPrisonVisitingRoom_Map_VBL_Function()
{

}
void bobsgame_CITYPoliceStationPrisonVisitingRoom_Map_HBL_Function()
{

}
//========================================================
//CITYPoliceStationPrisonHallway
//========================================================
void bobsgame_CITYPoliceStationPrisonHallway_Map_Load_Function()
{
//RANGE_CITYPoliceStationPrisonHallwayToVisitingRoom 25*8,87*8,29*8,88*8
//RANGE_CITYPoliceStationPrisonHallwayToPrisonCell 16*8,28*8,20*8,29*8
}
void bobsgame_CITYPoliceStationPrisonHallway_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}
//TODO: need sleazy uncle in orange

//7,70 down
//18,73 down
//5,60 over 1 up
//21,60 over 1 up
//6,47 down
//15,47 down
//15,42 right
//5,30 up over 1
//3,17 down
//2-10
//13-21
	static NPC* prisoners_npcs[10] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	int c=0;
	for(c=0;c<10;c++)
	{
		if(prisoners_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			int dir=UP;
			int bgp=2;
			GFX* gfx=NULL;
			if(c== 0){x= 7*8+2;y=70*8-4;dir=DOWN;	bgp=2;gfx=GFX_ADULT_convict;}
			if(c== 1){x=18*8+3;y=73*8;dir=DOWN;	bgp=2;gfx=GFX_ADULT_convict;}
			if(c== 2){x= 5*8;y=60*8;dir=UP;		bgp=1;gfx=GFX_ADULT_convict;}
			if(c== 3){x=21*8;y=60*8;dir=UP;		bgp=1;gfx=GFX_ADULT_convict;}
			if(c== 4){x= 6*8;y=47*8;dir=DOWN;	bgp=3;gfx=GFX_ADULT_convict;}
			if(c== 5){x=15*8;y=47*8;dir=DOWN;	bgp=3;gfx=GFX_ADULT_convict;}
			if(c== 6){x=16*8-2;y=41*8-2;dir=RIGHT;	bgp=2;gfx=GFX_ADULT_convict;}
			if(c== 7){x= 5*8;y=30*8;dir=UP;		bgp=1;gfx=GFX_ADULT_convict;}
			if(c== 8){x= 3*8;y=17*8;dir=DOWN;	bgp=3;gfx=GFX_ADULT_convict;}
			if(c== 9){x=17*8;y=17*8;dir=DOWN;	bgp=3;gfx=GFX_ADULT_convict;}
			if(gfx==NULL)NPC_create_random_ADULT_xy_feet(&prisoners_npcs[c],x,y);
			else NPC_create_npc_xy_feet(&prisoners_npcs[c],gfx,16,40,x,y);
			NPC_animate_stand_dir(&prisoners_npcs[c], dir);
			prisoners_npcs[c]->non_walkable=1;
			prisoners_npcs[c]->walk_dir=dir;
			prisoners_npcs[c]->layer=bgp;
			//NPC_animate_increment_direction_frame_now(&prisoners_npcs[c], dir);
			prisoners_npcs[c]->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		}
		if(prisoners_npcs[c]!=NULL)
		{
			if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&prisoners_npcs[c],35))NPC_stare_at_npc(&prisoners_npcs[c],&PLAYER_npc);
			else
			if(c==2||c==4||c==7||c==8)
			{
				if(prisoners_npcs[c]->AI== 0){if(NPC_walk_to_xy_nohit_pushmain(&prisoners_npcs[c],prisoners_npcs[c]->walking_speed,3*8,prisoners_npcs[c]->MAP_y+prisoners_npcs[c]->size_y-prisoners_npcs[c]->hitsize_y)==1){NPC_animate_stand_dir(&prisoners_npcs[c],prisoners_npcs[c]->walk_dir);prisoners_npcs[c]->vbls=r(40);prisoners_npcs[c]->AI++;}}
				if(prisoners_npcs[c]->AI== 1){if(prisoners_npcs[c]->vbls>120)prisoners_npcs[c]->AI++;}
				if(prisoners_npcs[c]->AI== 2){if(NPC_walk_to_xy_nohit_pushmain(&prisoners_npcs[c],prisoners_npcs[c]->walking_speed,5*8,prisoners_npcs[c]->MAP_y+prisoners_npcs[c]->size_y-prisoners_npcs[c]->hitsize_y)==1){NPC_animate_stand_dir(&prisoners_npcs[c],prisoners_npcs[c]->walk_dir);prisoners_npcs[c]->vbls=r(40);prisoners_npcs[c]->AI++;}}
				if(prisoners_npcs[c]->AI== 3){if(prisoners_npcs[c]->vbls>120)prisoners_npcs[c]->AI++;}
				if(prisoners_npcs[c]->AI== 4){if(NPC_walk_to_xy_nohit_pushmain(&prisoners_npcs[c],prisoners_npcs[c]->walking_speed,10*8,prisoners_npcs[c]->MAP_y+prisoners_npcs[c]->size_y-prisoners_npcs[c]->hitsize_y)==1){NPC_animate_stand_dir(&prisoners_npcs[c],prisoners_npcs[c]->walk_dir);prisoners_npcs[c]->vbls=r(40);prisoners_npcs[c]->AI++;}}
				if(prisoners_npcs[c]->AI== 5){if(prisoners_npcs[c]->vbls>120)prisoners_npcs[c]->AI=0;}
			}
			else
			if(c==3||c==5||c==9)
			{
				if(prisoners_npcs[c]->AI== 0){if(NPC_walk_to_xy_nohit_pushmain(&prisoners_npcs[c],prisoners_npcs[c]->walking_speed,14*8,prisoners_npcs[c]->MAP_y+prisoners_npcs[c]->size_y-prisoners_npcs[c]->hitsize_y)==1){NPC_animate_stand_dir(&prisoners_npcs[c],prisoners_npcs[c]->walk_dir);prisoners_npcs[c]->vbls=r(40);prisoners_npcs[c]->AI++;}}
				if(prisoners_npcs[c]->AI== 1){if(prisoners_npcs[c]->vbls>120)prisoners_npcs[c]->AI++;}
				if(prisoners_npcs[c]->AI== 2){if(NPC_walk_to_xy_nohit_pushmain(&prisoners_npcs[c],prisoners_npcs[c]->walking_speed,17*8,prisoners_npcs[c]->MAP_y+prisoners_npcs[c]->size_y-prisoners_npcs[c]->hitsize_y)==1){NPC_animate_stand_dir(&prisoners_npcs[c],prisoners_npcs[c]->walk_dir);prisoners_npcs[c]->vbls=r(40);prisoners_npcs[c]->AI++;}}
				if(prisoners_npcs[c]->AI== 3){if(prisoners_npcs[c]->vbls>120)prisoners_npcs[c]->AI++;}
				if(prisoners_npcs[c]->AI== 4){if(NPC_walk_to_xy_nohit_pushmain(&prisoners_npcs[c],prisoners_npcs[c]->walking_speed,21*8,prisoners_npcs[c]->MAP_y+prisoners_npcs[c]->size_y-prisoners_npcs[c]->hitsize_y)==1){NPC_animate_stand_dir(&prisoners_npcs[c],prisoners_npcs[c]->walk_dir);prisoners_npcs[c]->vbls=r(40);prisoners_npcs[c]->AI++;}}
				if(prisoners_npcs[c]->AI== 5){if(prisoners_npcs[c]->vbls>120)prisoners_npcs[c]->AI=0;}
			}
			else
			{
				if(prisoners_npcs[c]->AI==0){if(prisoners_npcs[c]->vbls>200){if(r(4)==0){prisoners_npcs[c]->AI=1+r(3);}else{prisoners_npcs[c]->vbls=0;NPC_animate_stand_dir(&prisoners_npcs[c], prisoners_npcs[c]->walk_dir);if(prisoners_npcs[c]->anim_frame_count!=0){prisoners_npcs[c]->anim_frame_count=3;NPC_animate(&prisoners_npcs[c]);}}}}
				if(prisoners_npcs[c]->AI==1){if(prisoners_npcs[c]->walk_dir==UP||prisoners_npcs[c]->walk_dir==DOWN)NPC_animate_stand_dir(&prisoners_npcs[c],LEFT);else NPC_animate_stand_dir(&prisoners_npcs[c],UP);prisoners_npcs[c]->vbls=r(120);prisoners_npcs[c]->AI=0;}
				if(prisoners_npcs[c]->AI==2){if(prisoners_npcs[c]->walk_dir==UP||prisoners_npcs[c]->walk_dir==DOWN)NPC_animate_stand_dir(&prisoners_npcs[c],RIGHT);else NPC_animate_stand_dir(&prisoners_npcs[c],DOWN);prisoners_npcs[c]->vbls=r(120);prisoners_npcs[c]->AI=0;}
				if(prisoners_npcs[c]->AI==3){NPC_animate(&prisoners_npcs[c]);prisoners_npcs[c]->vbls=r(120);prisoners_npcs[c]->AI=0;}
			}
			//if(NPC_in_range_of_npc_amt(&PLAYER_npc,prisoners_npcs[c],15))NPC_stare_at_npc(&prisoners_npcs[c],PLAYER_npc);
			//else NPC_animate_set_direction_now(&prisoners_npcs[c], prisoners_npcs[c]->walking_direction);

		}
	}
//guard 6,83 look up down
//26,83
//26,53
//6,53 look up down
//26,53
//26,23
//6,23 look up down
//26,23
//26,83

	static NPC* guard_npc = NULL;
	if(guard_npc==NULL)
	{
		NPC_create_npc_xy_feet(&guard_npc,GFX_ADULT_securityguard,16,40,6*8,83*8);
		//NPC_create_random_ADULT_xy_feet(&guard_npc,11*8,34*8);
		guard_npc->layer=2;
		guard_npc->non_walkable=1;
		NPC_animate_stand_dir(&guard_npc,DOWN);
		guard_npc->walking_speed = SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		guard_npc->AI=0;
	}
	if(guard_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&guard_npc,15))NPC_stare_at_npc(&guard_npc,&PLAYER_npc);
		//else NPC_animate_set_direction_now(&guard_npc, LEFT);
		else if(guard_npc->AI== 0){if(NPC_walk_to_xy_nohit_pushmain(&guard_npc,guard_npc->walking_speed, 6*8,83*8)==1){NPC_animate_stand_dir(&guard_npc,DOWN);guard_npc->vbls=r(40);guard_npc->AI++;}}
		else if(guard_npc->AI== 1){if(guard_npc->vbls>60)guard_npc->AI++;}
		else if(guard_npc->AI== 2){NPC_animate_stand_dir(&guard_npc,UP);guard_npc->vbls=r(40);guard_npc->AI++;}
		else if(guard_npc->AI== 3){if(guard_npc->vbls>60)guard_npc->AI++;}
		else if(guard_npc->AI== 4){if(NPC_walk_to_xy_nohit_pushmain(&guard_npc,guard_npc->walking_speed,26*8,83*8)==1){guard_npc->vbls=r(40);guard_npc->AI++;}}
		else if(guard_npc->AI== 5){if(NPC_walk_to_xy_nohit_pushmain(&guard_npc,guard_npc->walking_speed,26*8,53*8)==1){guard_npc->vbls=r(40);guard_npc->AI++;}}
		else if(guard_npc->AI== 6){if(NPC_walk_to_xy_nohit_pushmain(&guard_npc,guard_npc->walking_speed, 6*8,53*8)==1){NPC_animate_stand_dir(&guard_npc,DOWN);guard_npc->vbls=r(40);guard_npc->AI++;}}
		else if(guard_npc->AI== 7){if(guard_npc->vbls>60)guard_npc->AI++;}
		else if(guard_npc->AI== 8){NPC_animate_stand_dir(&guard_npc,UP);guard_npc->vbls=r(40);guard_npc->AI++;}
		else if(guard_npc->AI== 9){if(guard_npc->vbls>60)guard_npc->AI++;}
		else if(guard_npc->AI==10){if(NPC_walk_to_xy_nohit_pushmain(&guard_npc,guard_npc->walking_speed,26*8,53*8)==1){guard_npc->vbls=r(40);guard_npc->AI++;}}
		else if(guard_npc->AI==11){if(NPC_walk_to_xy_nohit_pushmain(&guard_npc,guard_npc->walking_speed,26*8,23*8)==1){guard_npc->vbls=r(40);guard_npc->AI++;}}
		else if(guard_npc->AI==12){if(NPC_walk_to_xy_nohit_pushmain(&guard_npc,guard_npc->walking_speed, 6*8,23*8)==1){NPC_animate_stand_dir(&guard_npc,DOWN);guard_npc->vbls=r(40);guard_npc->AI++;}}
		else if(guard_npc->AI==13){if(guard_npc->vbls>60)guard_npc->AI++;}
		else if(guard_npc->AI==14){NPC_animate_stand_dir(&guard_npc,UP);guard_npc->vbls=r(40);guard_npc->AI++;}
		else if(guard_npc->AI==15){if(guard_npc->vbls>60)guard_npc->AI++;}
		else if(guard_npc->AI==16){if(NPC_walk_to_xy_nohit_pushmain(&guard_npc,guard_npc->walking_speed,26*8,23*8)==1){guard_npc->vbls=r(40);guard_npc->AI++;}}
		else if(guard_npc->AI==17){if(NPC_walk_to_xy_nohit_pushmain(&guard_npc,guard_npc->walking_speed,26*8,83*8)==1){NPC_animate_stand_dir(&guard_npc,DOWN);guard_npc->vbls=r(40);guard_npc->AI++;}}
		else if(guard_npc->AI==18){if(guard_npc->vbls>120)guard_npc->AI=0;}

		if(ACTION_npc(&guard_npc,"Talk To Guard"))
		{
			TEXT_set_sprite_window(0,guard_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
	static NPC* guard2_npc = NULL;
	if(guard2_npc==NULL)
	{
		NPC_create_npc_xy_feet(&guard2_npc,GFX_ADULT_policeofficerfemale,16,40,6*8,21*8);
		//NPC_create_random_ADULT_xy_feet(&guard2_npc,11*8,34*8);
		guard2_npc->layer=2;
		guard2_npc->non_walkable=1;
		NPC_animate_stand_dir(&guard2_npc,DOWN);
		guard2_npc->walking_speed = SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		guard2_npc->AI=0;
	}
	if(guard2_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&guard2_npc,15))NPC_stare_at_npc(&guard2_npc,&PLAYER_npc);
		//else NPC_animate_set_direction_now(&guard2_npc, LEFT);
		else if(guard2_npc->AI== 0){if(NPC_walk_to_xy_nohit_pushmain(&guard2_npc,guard2_npc->walking_speed, 6*8,21*8)==1){NPC_animate_stand_dir(&guard2_npc,DOWN);guard2_npc->vbls=r(40);guard2_npc->AI++;}}
		else if(guard2_npc->AI== 1){if(guard2_npc->vbls>60)guard2_npc->AI++;}
		else if(guard2_npc->AI== 2){NPC_animate_stand_dir(&guard2_npc,UP);guard2_npc->vbls=r(40);guard2_npc->AI++;}
		else if(guard2_npc->AI== 3){if(guard2_npc->vbls>60)guard2_npc->AI++;}
		else if(guard2_npc->AI== 4){if(NPC_walk_to_xy_nohit_pushmain(&guard2_npc,guard2_npc->walking_speed,28*8,21*8)==1){guard2_npc->vbls=r(40);guard2_npc->AI++;}}
		else if(guard2_npc->AI== 5){if(NPC_walk_to_xy_nohit_pushmain(&guard2_npc,guard2_npc->walking_speed,28*8,51*8)==1){guard2_npc->vbls=r(40);guard2_npc->AI++;}}
		else if(guard2_npc->AI== 6){if(NPC_walk_to_xy_nohit_pushmain(&guard2_npc,guard2_npc->walking_speed, 6*8,51*8)==1){NPC_animate_stand_dir(&guard2_npc,DOWN);guard2_npc->vbls=r(40);guard2_npc->AI++;}}
		else if(guard2_npc->AI== 7){if(guard2_npc->vbls>60)guard2_npc->AI++;}
		else if(guard2_npc->AI== 8){NPC_animate_stand_dir(&guard2_npc,UP);guard2_npc->vbls=r(40);guard2_npc->AI++;}
		else if(guard2_npc->AI== 9){if(guard2_npc->vbls>60)guard2_npc->AI++;}
		else if(guard2_npc->AI==10){if(NPC_walk_to_xy_nohit_pushmain(&guard2_npc,guard2_npc->walking_speed,28*8,51*8)==1){guard2_npc->vbls=r(40);guard2_npc->AI++;}}
		else if(guard2_npc->AI==11){if(NPC_walk_to_xy_nohit_pushmain(&guard2_npc,guard2_npc->walking_speed,28*8,81*8)==1){guard2_npc->vbls=r(40);guard2_npc->AI++;}}
		else if(guard2_npc->AI==12){if(NPC_walk_to_xy_nohit_pushmain(&guard2_npc,guard2_npc->walking_speed, 6*8,81*8)==1){NPC_animate_stand_dir(&guard2_npc,DOWN);guard2_npc->vbls=r(40);guard2_npc->AI++;}}
		else if(guard2_npc->AI==13){if(guard2_npc->vbls>60)guard2_npc->AI++;}
		else if(guard2_npc->AI==14){NPC_animate_stand_dir(&guard2_npc,UP);guard2_npc->vbls=r(40);guard2_npc->AI++;}
		else if(guard2_npc->AI==15){if(guard2_npc->vbls>60)guard2_npc->AI++;}
		else if(guard2_npc->AI==16){if(NPC_walk_to_xy_nohit_pushmain(&guard2_npc,guard2_npc->walking_speed,28*8,81*8)==1){guard2_npc->vbls=r(40);guard2_npc->AI++;}}
		else if(guard2_npc->AI==17){if(NPC_walk_to_xy_nohit_pushmain(&guard2_npc,guard2_npc->walking_speed,28*8,21*8)==1){NPC_animate_stand_dir(&guard2_npc,DOWN);guard2_npc->vbls=r(40);guard2_npc->AI++;}}
		else if(guard2_npc->AI==18){if(guard2_npc->vbls>120)guard2_npc->AI=0;}

		if(ACTION_npc(&guard2_npc,"Talk To Guard"))
		{
			TEXT_set_sprite_window(0,guard2_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
	if(walking_into_door(RANGE_CITYPoliceStationPrisonHallwayToVisitingRoom))
	{
		MAP_change_map(MAP_bobsgame_CITYPoliceStationPrisonVisitingRoom,27,10);return;
	}
	if(walking_into_door(RANGE_CITYPoliceStationPrisonHallwayToPrisonCell))
	{
		MAP_change_map(MAP_bobsgame_CITYPoliceStationPrisonCell,7,10);return;
	}

}
void bobsgame_CITYPoliceStationPrisonHallway_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYPoliceStationPrisonHallway_Map_VBL_Function()
{

}
void bobsgame_CITYPoliceStationPrisonHallway_Map_HBL_Function()
{

}
//========================================================
//CITYPoliceStationPrisonCell
//========================================================
void bobsgame_CITYPoliceStationPrisonCell_Map_Load_Function()
{
//RANGE_CITYPoliceStationPrisonCellToPrisonHallway 5*8,9*8,9*8,10*8
}
void bobsgame_CITYPoliceStationPrisonCell_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

	if(walking_into_door(RANGE_CITYPoliceStationPrisonCellToPrisonHallway))
	{
		MAP_change_map(MAP_bobsgame_CITYPoliceStationPrisonHallway,18,27);return;
	}
}
void bobsgame_CITYPoliceStationPrisonCell_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYPoliceStationPrisonCell_Map_VBL_Function()
{

}
void bobsgame_CITYPoliceStationPrisonCell_Map_HBL_Function()
{

}


