//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================



#include "../../main.h"



#define RANGE_FRIENDDownstairsToOUTSIDEFrontyard 31*8,42*8,35*8,43*8
#define RANGE_FRIENDDownstairsToDownstairsBathroom 45*8,35*8,49*8,36*8
#define RANGE_FRIENDDownstairsToUpstairs 54*8,26*8,60*8,27*8
#define RANGE_FRIENDDownstairsToBasement 55*8,15*8,59*8,16*8
#define RANGE_FRIENDDownstairsToGarage 60*8,9*8,61*8,13*8
#define RANGE_FRIENDDownstairsToOUTSIDEBackyard 47*8,8*8,51*8,9*8
#define RANGE_FRIENDUpstairsToDownstairs 54*8,26*8,60*8,27*8
#define RANGE_FRIENDUpstairsToFriendsRoom 6*8,8*8,10*8,9*8
#define RANGE_FRIENDUpstairsToSistersRoom 37*8,8*8,41*8,9*8
#define RANGE_FRIENDUpstairsToParentsRoom 30*8,16*8,34*8,17*8
#define RANGE_FRIENDUpstairsToUpstairsBathroom 7*8,16*8,11*8,17*8
#define RANGE_FRIENDFriendsRoomToUpstairs 6*8,22*8,10*8,23*8
#define RANGE_FRIENDSistersRoomToUpstairs 7*8,22*8,11*8,23*8
#define RANGE_FRIENDUpstairsBathroomToUpstairs 9*8,8*8,13*8,9*8
#define RANGE_FRIENDParentsRoomToUpstairs 15*8,8*8,19*8,9*8
#define RANGE_FRIENDBasementToDownstairs 55*8,8*8,59*8,9*8
#define RANGE_FRIENDGarageToDownstairs 1*8,10*8,2*8,14*8
#define RANGE_FRIENDDownstairsBathroomToDownstairs 4*8,17*8,8*8,18*8
#define RANGE_FRIENDMirrorEffect 2*8,11*8,9*8,13*8


//========================================================
//FRIENDDownstairs
//========================================================
void bobsgame_TOWNFRIENDDownstairs_Map_Load_Function()
{
//RANGE_FRIENDDownstairsToOUTSIDEFrontyard 31*8,42*8,35*8,43*8
//RANGE_FRIENDDownstairsToDownstairsBathroom 45*8,35*8,49*8,36*8
//RANGE_FRIENDDownstairsToUpstairs 54*8,26*8,60*8,27*8
//RANGE_FRIENDDownstairsToBasement 55*8,15*8,59*8,16*8
//RANGE_FRIENDDownstairsToGarage 60*8,9*8,61*8,13*8
//RANGE_FRIENDDownstairsToOUTSIDEBackyard 47*8,8*8,51*8,9*8
}

void bobsgame_TOWNFRIENDDownstairs_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//TODO: unless its between 11:00pm and 6:00am
//13,22 face up watching tv friendsdad
	static NPC* friendsdad_npc = NULL;
	if(friendsdad_npc==NULL)
	{
		NPC_create_npc_xy_feet(&friendsdad_npc,GFX_ADULT_friendsdad,16,40,13*8,22*8+2);
		friendsdad_npc->non_walkable=1;
		//friendsdad_npc->pushable=1;
		friendsdad_npc->layer=2;
	}
	if(friendsdad_npc!=NULL)
	{
		if(NPC_in_range_of_npc(&PLAYER_npc,&friendsdad_npc))NPC_stare_at_npc(&friendsdad_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&friendsdad_npc, UP);
		if(ACTION_npc(&friendsdad_npc,"Talk To Friend's Dad"))
		{
			TEXT_set_sprite_window(0,friendsdad_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
	//TODO: tv sound and tv animation for friendsdad
//44,18 face right friends mom in the kitchen
	static NPC* friendsmom_npc = NULL;
	if(friendsmom_npc==NULL)
	{
		NPC_create_npc_xy_feet(&friendsmom_npc,GFX_ADULT_friendsmom,16,40,44*8,17*8);
		friendsmom_npc->non_walkable=1;
		//friendsmom_npc->pushable=1;
		friendsmom_npc->layer=2;
	}
	if(friendsmom_npc!=NULL)
	{
		if(NPC_in_range_of_npc(&PLAYER_npc,&friendsmom_npc))NPC_stare_at_npc(&friendsmom_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&friendsmom_npc,RIGHT);
		if(ACTION_npc(&friendsmom_npc,"Talk To Friend's Mom"))
		{
			TEXT_set_sprite_window(0,friendsmom_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
//44,16 45,16 44,15 45,15 layer 1 to 2
///TODO: MUST FIX THIS!!
		///HARDWARE_set_map_tile(1,2,43,14,HARDWARE_map_1[HARDWARE_map_width_tiles*14+43]);
		///HARDWARE_set_map_tile(1,2,44,14,HARDWARE_map_1[HARDWARE_map_width_tiles*14+44]);
		///HARDWARE_set_map_tile(1,2,43,15,HARDWARE_map_1[HARDWARE_map_width_tiles*15+43]);
		///HARDWARE_set_map_tile(1,2,44,15,HARDWARE_map_1[HARDWARE_map_width_tiles*15+44]);
		///HARDWARE_set_map_tile(1,1,43,14,0);
		///HARDWARE_set_map_tile(1,1,44,14,0);
		///HARDWARE_set_map_tile(1,1,43,15,0);
		///HARDWARE_set_map_tile(1,1,44,15,0);
//TODO: tv sound for friendsmom, maybe tv glow
	if(walking_into_door(RANGE_FRIENDDownstairsToOUTSIDEFrontyard))
	{
		MAP_change_map(MAP_bobsgame_TOWNTown,321,504);return;
	}
	if(walking_into_door(RANGE_FRIENDDownstairsToDownstairsBathroom))
	{
		MAP_change_map(MAP_bobsgame_TOWNFRIENDDownstairsBathroom,6,16);return;
	}
	if(walking_into_door(RANGE_FRIENDDownstairsToUpstairs))
	{
		MAP_change_map(MAP_bobsgame_TOWNFRIENDUpstairs,57,25);return;
	}
	if(walking_into_door(RANGE_FRIENDDownstairsToBasement))
	{
		MAP_change_map(MAP_bobsgame_TOWNFRIENDBasement,57,9);return;
	}
	if(walking_into_door(RANGE_FRIENDDownstairsToGarage))
	{
		MAP_change_map(MAP_bobsgame_TOWNFRIENDGarage,2,11);return;
	}
	if(walking_into_door(RANGE_FRIENDDownstairsToOUTSIDEBackyard))
	{
		MAP_change_map(MAP_bobsgame_TOWNTown,337,463);return;
	}
}
void bobsgame_TOWNFRIENDDownstairs_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_TOWNFRIENDDownstairs_Map_VBL_Function()
{

}

void bobsgame_TOWNFRIENDDownstairs_Map_HBL_Function()
{

}

//========================================================
//FRIENDUpstairs
//========================================================
void bobsgame_TOWNFRIENDUpstairs_Map_Load_Function()
{
//RANGE_FRIENDUpstairsToDownstairs 54*8,26*8,60*8,27*8
//RANGE_FRIENDUpstairsToFriendsRoom 6*8,8*8,10*8,9*8
//RANGE_FRIENDUpstairsToSistersRoom 37*8,8*8,41*8,9*8
//RANGE_FRIENDUpstairsToParentsRoom 30*8,16*8,34*8,17*8
//RANGE_FRIENDUpstairsToUpstairsBathroom 7*8,16*8,11*8,17*8
}

void bobsgame_TOWNFRIENDUpstairs_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//TODO:friends sisters room is locked when shes out
	if(walking_into_door(RANGE_FRIENDUpstairsToDownstairs))
	{
		MAP_change_map(MAP_bobsgame_TOWNFRIENDDownstairs,57,27);return;
	}
	if(walking_into_door(RANGE_FRIENDUpstairsToFriendsRoom))
	{
		MAP_change_map(MAP_bobsgame_TOWNFRIENDUpstairsFriendsRoom,8,21);return;
	}
	if(walking_into_door(RANGE_FRIENDUpstairsToSistersRoom))
	{
		MAP_change_map(MAP_bobsgame_TOWNFRIENDUpstairsSistersRoom,9,21);return;
	}
	if(walking_into_door(RANGE_FRIENDUpstairsToParentsRoom))
	{
		MAP_change_map(MAP_bobsgame_TOWNFRIENDUpstairsParentsRoom,17,9);return;
	}
	if(walking_into_door(RANGE_FRIENDUpstairsToUpstairsBathroom))
	{
		MAP_change_map(MAP_bobsgame_TOWNFRIENDUpstairsBathroom,11,9);return;
	}
}
void bobsgame_TOWNFRIENDUpstairs_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_TOWNFRIENDUpstairs_Map_VBL_Function()
{

}

void bobsgame_TOWNFRIENDUpstairs_Map_HBL_Function()
{

}

//========================================================
//FRIENDUpstairsFriendsRoom
//========================================================
void bobsgame_TOWNFRIENDUpstairsFriendsRoom_Map_Load_Function()
{
//RANGE_FRIENDFriendsRoomToUpstairs 6*8,22*8,10*8,23*8
}

void bobsgame_TOWNFRIENDUpstairsFriendsRoom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

	if(walking_into_door(RANGE_FRIENDFriendsRoomToUpstairs))
	{
		MAP_change_map(MAP_bobsgame_TOWNFRIENDUpstairs,8,9);return;
	}
}
void bobsgame_TOWNFRIENDUpstairsFriendsRoom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_TOWNFRIENDUpstairsFriendsRoom_Map_VBL_Function()
{

}

void bobsgame_TOWNFRIENDUpstairsFriendsRoom_Map_HBL_Function()
{

}

//========================================================
//FRIENDUpstairsSistersRoom
//========================================================
void bobsgame_TOWNFRIENDUpstairsSistersRoom_Map_Load_Function()
{
//RANGE_FRIENDSistersRoomToUpstairs 7*8,22*8,11*8,23*8
}

void bobsgame_TOWNFRIENDUpstairsSistersRoom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//TODO: unless friends sister is on a date with yuus brother
	static NPC* friendssister_npc = NULL;
	if(friendssister_npc==NULL)
	{
		NPC_create_npc_xy_feet(&friendssister_npc,GFX_KID_sister,16,32,9*8,14*8);
		//friendssister_npc->non_walkable=1;
		//friendssister_npc->pushable=1;
		friendssister_npc->layer=2;
	}
	if(friendssister_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&friendssister_npc,32))NPC_stare_at_npc(&friendssister_npc,&PLAYER_npc);
		else
		{
			NPC_animate_stand_dir(&friendssister_npc,UP);
		}
		NPC_avoid_nearest_npc(&friendssister_npc,8);
		if(ACTION_npc(&friendssister_npc,"Talk To Friend's Sister"))
		{
			TEXT_set_sprite_window(0,friendssister_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
	if(walking_into_door(RANGE_FRIENDSistersRoomToUpstairs))
	{
		MAP_change_map(MAP_bobsgame_TOWNFRIENDUpstairs,39,9);return;
	}
}
void bobsgame_TOWNFRIENDUpstairsSistersRoom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_TOWNFRIENDUpstairsSistersRoom_Map_VBL_Function()
{

}

void bobsgame_TOWNFRIENDUpstairsSistersRoom_Map_HBL_Function()
{

}

//========================================================
//FRIENDUpstairsBathroom
//========================================================
void bobsgame_TOWNFRIENDUpstairsBathroom_Map_Load_Function()
{
//RANGE_FRIENDUpstairsBathroomToUpstairs 9*8,8*8,13*8,9*8
}

void bobsgame_TOWNFRIENDUpstairsBathroom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

	if(walking_into_door(RANGE_FRIENDUpstairsBathroomToUpstairs))
	{
		MAP_change_map(MAP_bobsgame_TOWNFRIENDUpstairs,9,15);return;
	}
}
void bobsgame_TOWNFRIENDUpstairsBathroom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_TOWNFRIENDUpstairsBathroom_Map_VBL_Function()
{

}

void bobsgame_TOWNFRIENDUpstairsBathroom_Map_HBL_Function()
{

}

//========================================================
//FRIENDUpstairsParentsRoom
//========================================================
void bobsgame_TOWNFRIENDUpstairsParentsRoom_Map_Load_Function()
{
//RANGE_FRIENDParentsRoomToUpstairs 15*8,8*8,19*8,9*8
}

void bobsgame_TOWNFRIENDUpstairsParentsRoom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

	if(CLOCK_hour<6||CLOCK_hour>12+10)
	{
		static NPC* friendsdad_npc = NULL;
		if(friendsdad_npc==NULL)
		{
			NPC_create_npc_xy_feet(&friendsdad_npc,GFX_ADULT_friendsdad,16,40,22*8,19*8);
			friendsdad_npc->non_walkable=1;
			//friendsdad_npc->pushable=1;
			friendsdad_npc->layer=2;
		}
		if(friendsdad_npc!=NULL)
		{
			//TODO: talk to friendsdad
		}
		//TODO: tv sound and tv animation, big screen same as downstairs
		//TODO: need upside down friends parents sprites
		static NPC* friendsmom_npc = NULL;
		if(friendsmom_npc==NULL)
		{
			NPC_create_npc_xy_feet(&friendsmom_npc,GFX_ADULT_friendsmom,16,40,25*8,19*8);
			friendsmom_npc->non_walkable=1;
			//friendsmom_npc->pushable=1;
			friendsmom_npc->layer=2;
		}
		if(friendsmom_npc!=NULL)
		{
			//TODO: talk to friendsmom
		}
	}
	if(walking_into_door(RANGE_FRIENDParentsRoomToUpstairs))
	{
		MAP_change_map(MAP_bobsgame_TOWNFRIENDUpstairs,32,15);return;
	}
}
void bobsgame_TOWNFRIENDUpstairsParentsRoom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_TOWNFRIENDUpstairsParentsRoom_Map_VBL_Function()
{

}

void bobsgame_TOWNFRIENDUpstairsParentsRoom_Map_HBL_Function()
{

}

//========================================================
//FRIENDBasement
//========================================================
void bobsgame_TOWNFRIENDBasement_Map_Load_Function()
{
//RANGE_FRIENDBasementToDownstairs 55*8,8*8,59*8,9*8
}

void bobsgame_TOWNFRIENDBasement_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//sleazy uncle bob is here
//12,21 face up, look at yuu
	static NPC* sleazyunclebob_npc = NULL;
	if(sleazyunclebob_npc==NULL)
	{
		NPC_create_npc_xy_feet(&sleazyunclebob_npc,GFX_ADULT_sleazyunclebob,16,40,12*8,21*8);
		sleazyunclebob_npc->non_walkable=1;
		//sleazyunclebob_npc->pushable=1;
		sleazyunclebob_npc->layer=2;
	}
	if(sleazyunclebob_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&sleazyunclebob_npc,32))NPC_stare_at_npc(&sleazyunclebob_npc,&PLAYER_npc);
		else
		{
			NPC_animate_stand_dir(&sleazyunclebob_npc,UP);
		}
		if(ACTION_npc(&sleazyunclebob_npc,"Talk To Friend's Lazy Uncle"))
		{
			TEXT_set_sprite_window(0,sleazyunclebob_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
	if(walking_into_door(RANGE_FRIENDBasementToDownstairs))
	{
		MAP_change_map(MAP_bobsgame_TOWNFRIENDDownstairs,57,14);return;
	}
}
void bobsgame_TOWNFRIENDBasement_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_TOWNFRIENDBasement_Map_VBL_Function()
{

}

void bobsgame_TOWNFRIENDBasement_Map_HBL_Function()
{

}

//========================================================
//FRIENDGarage
//========================================================
void bobsgame_TOWNFRIENDGarage_Map_Load_Function()
{
//RANGE_FRIENDGarageToDownstairs 1*8,10*8,2*8,14*8
}

void bobsgame_TOWNFRIENDGarage_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//sleazy uncle bobs conversion van,
//TODO: needs new part
	static NPC* bobsvan_npc=NULL;
	if(bobsvan_npc==NULL)
	{
		NPC_create_npc(&bobsvan_npc,GFX_CAR_van,64,64,8*8,14*8);
		NPC_set_car_anim_frame_now(&bobsvan_npc,UP);
		bobsvan_npc->non_walkable=1;
		bobsvan_npc->animation_off=1;
		bobsvan_npc->scale=1.5f;
	}
	if(bobsvan_npc!=NULL)
	{
		if(ACTION_npc(&bobsvan_npc,"Check Out Conversion Van"))
		{
			TEXT_set_sprite_window(0,PLAYER_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
	if(walking_into_door(RANGE_FRIENDGarageToDownstairs))
	{
		MAP_change_map(MAP_bobsgame_TOWNFRIENDDownstairs,59,11);return;
	}
}
void bobsgame_TOWNFRIENDGarage_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_TOWNFRIENDGarage_Map_VBL_Function()
{

}

void bobsgame_TOWNFRIENDGarage_Map_HBL_Function()
{

}

//========================================================
//FRIENDDownstairsBathroom
//========================================================
void bobsgame_TOWNFRIENDDownstairsBathroom_Map_Load_Function()
{
//RANGE_FRIENDDownstairsBathroomToDownstairs 4*8,17*8,8*8,18*8
//RANGE_FRIENDMirrorEffect 2*8,11*8,9*8,13*8
}

void bobsgame_TOWNFRIENDDownstairsBathroom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//TODO: the toilet paper is fake
//everything is sparking clean
//it smells like cinnamon
	if(walking_into_door(RANGE_FRIENDDownstairsBathroomToDownstairs))
	{
		MAP_change_map(MAP_bobsgame_TOWNFRIENDDownstairs,47,36);return;
	}
	if(walking_into_door(RANGE_FRIENDMirrorEffect))
	{
	//
	}
}
void bobsgame_TOWNFRIENDDownstairsBathroom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_TOWNFRIENDDownstairsBathroom_Map_VBL_Function()
{

}

void bobsgame_TOWNFRIENDDownstairsBathroom_Map_HBL_Function()
{

}


