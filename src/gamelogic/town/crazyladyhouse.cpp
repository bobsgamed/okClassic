//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================



#include "../../main.h"



#define RANGE_CRAZYDownstairsToUpstairs 17*8,24*8,23*8,25*8
#define RANGE_CRAZYDownstairsToDownstairsBathroom 10*8,32*8,14*8,33*8
#define RANGE_CRAZYDownstairsToOUTSIDEFrontyard 35*8,37*8,39*8,38*8
#define RANGE_CRAZYDownstairsToOUTSIDEBackyard 22*8,8*8,26*8,9*8
#define RANGE_CRAZYDownstairsToGarage 1*8,25*8,2*8,29*8
#define RANGE_CRAZYDownstairsToBasement 18*8,14*8,22*8,15*8
#define RANGE_CRAZYUpstairsToDownstairs 17*8,20*8,23*8,21*8
#define RANGE_CRAZYUpstairsToUpstairsBathroom 7*8,16*8,11*8,17*8
#define RANGE_CRAZYUpstairsToBedroom 11*8,8*8,15*8,9*8
#define RANGE_CRAZYUpstairsToHiddenRoom 23*8,8*8,24*8,13*8
#define RANGE_CRAZYBedroomToUpstairs 8*8,22*8,12*8,23*8
#define RANGE_CRAZYUpstairsBathroomToUpstairs 7*8,8*8,11*8,9*8
#define RANGE_CRAZYDownstairsBathroomToDownstairs 3*8,15*8,7*8,16*8
#define RANGE_CRAZYMirrorEffect 2*8,11*8,7*8,12*8
#define RANGE_CRAZYBasementToDownstairs 19*8,9*8,23*8,10*8
#define RANGE_CRAZYGarageToDownstairs 25*8,10*8,26*8,14*8
#define RANGE_CRAZYHiddenRoomToUpstairs 1*8,25*8,2*8,29*8




//========================================================
//CRAZYDownstairs
//========================================================
void bobsgame_TOWNCRAZYDownstairs_Map_Load_Function()
{
//RANGE_CRAZYDownstairsToUpstairs 17*8,24*8,23*8,25*8
//RANGE_CRAZYDownstairsToDownstairsBathroom 10*8,32*8,14*8,33*8
//RANGE_CRAZYDownstairsToOUTSIDEFrontyard 35*8,37*8,39*8,38*8
//RANGE_CRAZYDownstairsToOUTSIDEBackyard 22*8,8*8,26*8,9*8
//RANGE_CRAZYDownstairsToGarage 1*8,25*8,2*8,29*8
//RANGE_CRAZYDownstairsToBasement 18*8,14*8,22*8,15*8
}

void bobsgame_TOWNCRAZYDownstairs_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//crazy lady at 28,19 face right
	static NPC* crazylady_npc = NULL;
	if(crazylady_npc==NULL)
	{
		NPC_create_npc_xy_feet(&crazylady_npc,GFX_ADULT_crazylady,16,40,29*8+2,19*8+6);
		crazylady_npc->non_walkable=1;
		//crazylady_npc->pushable=1;
		crazylady_npc->layer=2;
		NPC_animate_stand_dir(&crazylady_npc,RIGHT);
	}
	if(crazylady_npc!=NULL)
	{
		//if(NPC_in_range_of_npc_amt(&PLAYER_npc,crazylady_npc,32))NPC_stare_at_npc(&crazylady_npc,PLAYER_npc);
		//else NPC_animate_set_direction_now(&crazylady_npc,RIGHT);
		if(ACTION_npc(&crazylady_npc,"Talk To Crazy Lady"))
		{
			TEXT_set_sprite_window(0,crazylady_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
	//TODO: need lots of cats
	if(walking_into_door(RANGE_CRAZYDownstairsToUpstairs))
	{
		MAP_change_map(MAP_bobsgame_TOWNCRAZYUpstairs,20,19);return;
	}
	if(walking_into_door(RANGE_CRAZYDownstairsToDownstairsBathroom))
	{
		MAP_change_map(MAP_bobsgame_TOWNCRAZYDownstairsBathroom,5,14);return;
	}
	if(walking_into_door(RANGE_CRAZYDownstairsToOUTSIDEFrontyard))
	{
		MAP_change_map(MAP_bobsgame_TOWNTown,447,504);return;
	}
	if(walking_into_door(RANGE_CRAZYDownstairsToOUTSIDEBackyard))
	{
		MAP_change_map(MAP_bobsgame_TOWNTown,439,463);return;
	}
	if(walking_into_door(RANGE_CRAZYDownstairsToGarage))
	{
		MAP_change_map(MAP_bobsgame_TOWNCRAZYGarage,24,11);return;
	}
	if(walking_into_door(RANGE_CRAZYDownstairsToBasement))
	{
		MAP_change_map(MAP_bobsgame_TOWNCRAZYBasement,21,10);return;
	}
}
void bobsgame_TOWNCRAZYDownstairs_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_TOWNCRAZYDownstairs_Map_VBL_Function()
{

}

void bobsgame_TOWNCRAZYDownstairs_Map_HBL_Function()
{

}

//========================================================
//CRAZYUpstairs
//========================================================
void bobsgame_TOWNCRAZYUpstairs_Map_Load_Function()
{
//RANGE_CRAZYUpstairsToDownstairs 17*8,20*8,23*8,21*8
//RANGE_CRAZYUpstairsToUpstairsBathroom 7*8,16*8,11*8,17*8
//RANGE_CRAZYUpstairsToBedroom 11*8,8*8,15*8,9*8
//RANGE_CRAZYUpstairsToHiddenRoom 23*8,8*8,24*8,13*8
}

void bobsgame_TOWNCRAZYUpstairs_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//the photos on the wall are the store sample photos
	if(walking_into_door(RANGE_CRAZYUpstairsToDownstairs))
	{
		MAP_change_map(MAP_bobsgame_TOWNCRAZYDownstairs,20,25);return;
	}
	if(walking_into_door(RANGE_CRAZYUpstairsToUpstairsBathroom))
	{
		MAP_change_map(MAP_bobsgame_TOWNCRAZYUpstairsBathroom,9,9);return;
	}
	if(walking_into_door(RANGE_CRAZYUpstairsToBedroom))
	{
		MAP_change_map(MAP_bobsgame_TOWNCRAZYUpstairsBedroom,10,21);return;
	}
	if(walking_into_door(RANGE_CRAZYUpstairsToHiddenRoom))
	{
		MAP_change_map(MAP_bobsgame_TOWNCRAZYUpstairsHidden,2,28);return;
	}
}
void bobsgame_TOWNCRAZYUpstairs_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_TOWNCRAZYUpstairs_Map_VBL_Function()
{

}

void bobsgame_TOWNCRAZYUpstairs_Map_HBL_Function()
{

}

//========================================================
//CRAZYUpstairsBedroom
//========================================================
void bobsgame_TOWNCRAZYUpstairsBedroom_Map_Load_Function()
{
//RANGE_CRAZYBedroomToUpstairs 8*8,22*8,12*8,23*8
}

void bobsgame_TOWNCRAZYUpstairsBedroom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}
	if(walking_into_door(RANGE_CRAZYBedroomToUpstairs))
	{
		MAP_change_map(MAP_bobsgame_TOWNCRAZYUpstairs,13,9);return;
	}
}
void bobsgame_TOWNCRAZYUpstairsBedroom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_TOWNCRAZYUpstairsBedroom_Map_VBL_Function()
{

}

void bobsgame_TOWNCRAZYUpstairsBedroom_Map_HBL_Function()
{

}

//========================================================
//CRAZYUpstairsBathroom
//========================================================
void bobsgame_TOWNCRAZYUpstairsBathroom_Map_Load_Function()
{
//RANGE_CRAZYUpstairsBathroomToUpstairs 7*8,8*8,11*8,9*8
}

void bobsgame_TOWNCRAZYUpstairsBathroom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//TODO: denture adhesive?? something like that. hair rollers?
	if(walking_into_door(RANGE_CRAZYUpstairsBathroomToUpstairs))
	{
		MAP_change_map(MAP_bobsgame_TOWNCRAZYUpstairs,9,15);return;
	}
}
void bobsgame_TOWNCRAZYUpstairsBathroom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_TOWNCRAZYUpstairsBathroom_Map_VBL_Function()
{

}

void bobsgame_TOWNCRAZYUpstairsBathroom_Map_HBL_Function()
{

}

//========================================================
//CRAZYDownstairsBathroom
//========================================================
void bobsgame_TOWNCRAZYDownstairsBathroom_Map_Load_Function()
{
//RANGE_CRAZYDownstairsBathroomToDownstairs 3*8,15*8,7*8,16*8
//RANGE_CRAZYMirrorEffect 2*8,11*8,7*8,12*8
}

void bobsgame_TOWNCRAZYDownstairsBathroom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//TODO: the toilet is filled with jelly.
	if(walking_into_door(RANGE_CRAZYDownstairsBathroomToDownstairs))
	{
		MAP_change_map(MAP_bobsgame_TOWNCRAZYDownstairs,12,33);return;
	}
	if(walking_into_door(RANGE_CRAZYMirrorEffect))
	{
	//
	}
}
void bobsgame_TOWNCRAZYDownstairsBathroom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_TOWNCRAZYDownstairsBathroom_Map_VBL_Function()
{

}

void bobsgame_TOWNCRAZYDownstairsBathroom_Map_HBL_Function()
{

}

//========================================================
//CRAZYBasement
//========================================================
void bobsgame_TOWNCRAZYBasement_Map_Load_Function()
{
//RANGE_CRAZYBasementToDownstairs 19*8,9*8,23*8,10*8
}

void bobsgame_TOWNCRAZYBasement_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//TODO: find something down here
	if(walking_into_door(RANGE_CRAZYBasementToDownstairs))
	{
		MAP_change_map(MAP_bobsgame_TOWNCRAZYDownstairs,20,13);return;
	}
}
void bobsgame_TOWNCRAZYBasement_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_TOWNCRAZYBasement_Map_VBL_Function()
{

}

void bobsgame_TOWNCRAZYBasement_Map_HBL_Function()
{

}

//========================================================
//CRAZYGarage
//========================================================
void bobsgame_TOWNCRAZYGarage_Map_Load_Function()
{
//RANGE_CRAZYGarageToDownstairs 25*8,10*8,26*8,14*8
}

void bobsgame_TOWNCRAZYGarage_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//TODO: lots of boxes. find something in here.
	if(walking_into_door(RANGE_CRAZYGarageToDownstairs))
	{
		MAP_change_map(MAP_bobsgame_TOWNCRAZYDownstairs,2,26);return;
	}
}
void bobsgame_TOWNCRAZYGarage_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_TOWNCRAZYGarage_Map_VBL_Function()
{

}

void bobsgame_TOWNCRAZYGarage_Map_HBL_Function()
{

}

//========================================================
//CRAZYUpstairsHidden
//========================================================
void bobsgame_TOWNCRAZYUpstairsHidden_Map_Load_Function()
{
//RANGE_CRAZYHiddenRoomToUpstairs 1*8,25*8,2*8,29*8
}

void bobsgame_TOWNCRAZYUpstairsHidden_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//scrawny kid locked away 16,15 face down
	static NPC* scrawnykid_npc = NULL;
	if(scrawnykid_npc==NULL)
	{
		NPC_create_npc_xy_feet(&scrawnykid_npc,GFX_KID_scrawnyboy,16,32,16*8,15*8);
		scrawnykid_npc->non_walkable=1;
		//scrawnykid_npc->pushable=1;
		scrawnykid_npc->layer=3;
		NPC_animate_stand_dir(&scrawnykid_npc,DOWN);
	}
	if(scrawnykid_npc!=NULL)
	{
		//if(NPC_in_range_of_npc_amt(&PLAYER_npc,scrawnykid_npc,32))NPC_stare_at_npc(&scrawnykid_npc,PLAYER_npc);
		//else NPC_animate_set_direction_now(&scrawnykid_npc,RIGHT);
		if(ACTION_npc(&scrawnykid_npc,"Talk To Kid"))
		{
			TEXT_set_sprite_window(0,scrawnykid_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
	//TODO: kid runs to bars, pleads for help
	if(walking_into_door(RANGE_CRAZYHiddenRoomToUpstairs))
	{
		MAP_change_map(MAP_bobsgame_TOWNCRAZYUpstairs,22,10);return;
	}
}
void bobsgame_TOWNCRAZYUpstairsHidden_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_TOWNCRAZYUpstairsHidden_Map_VBL_Function()
{

}

void bobsgame_TOWNCRAZYUpstairsHidden_Map_HBL_Function()
{

}


