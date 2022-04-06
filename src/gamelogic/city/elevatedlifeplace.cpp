//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================


#include "../../main.h"



#define RANGE_CITYElevatedLifeplaceToOUTSIDECity 39*8,43*8,47*8,44*8
#define RANGE_CITYElevatedLifeplaceElevatorToOUTSIDECity 4*8,19*8,8*8,20*8
#define RANGE_CITYElevatedLifeplaceElevatorToElevatedLifeplaceHallway 4*8,8*8,8*8,9*8
#define RANGE_CITYElevatedLifeplaceHallwayToElevator 4*8,31*8,8*8,32*8
#define RANGE_CITYElevatedLifeplaceHallwayToApartment 10*8,12*8,11*8,17*8
#define RANGE_CITYElevatedLifeplaceApartmentToHallway 1*8,12*8,2*8,18*8
#define RANGE_CITYElevatedLifeplaceApartmentToBathroom 20*8,22*8,21*8,27*8
#define RANGE_CITYElevatedLifeplaceApartmentToBedroom 20*8,10*8,21*8,14*8
#define RANGE_CITYElevatedLifeplaceBathroomToApartment 1*8,10*8,2*8,14*8
#define RANGE_CITYElevatedLifeplaceBathroomToBedroom 3*8,9*8,7*8,10*8
#define RANGE_CITYElevatedLifeplaceBedroomToBathroom 3*8,24*8,7*8,25*8
#define RANGE_CITYElevatedLifeplaceBedroomToApartment 1*8,10*8,2*8,14*8



//========================================================
//CITYElevatedLifeplace
//========================================================
void bobsgame_CITYElevatedLifeplace_Map_Load_Function()
{
//RANGE_CITYElevatedLifeplaceToOUTSIDECity 39*8,43*8,47*8,44*8
}
void bobsgame_CITYElevatedLifeplace_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//10,21 face right
//15,18-22
	static NPC* manager_npc = NULL;
	if(manager_npc==NULL)
	{
		NPC_create_npc_xy_feet(&manager_npc,GFX_ADULT_GENERICmangrayhairbigheadsuit,16,40,10*8+4,20*8-4);
		manager_npc->layer=1;
		manager_npc->non_walkable=1;
		NPC_animate_stand_dir(&manager_npc,RIGHT);
		NPC_animate_dir(&manager_npc,RIGHT);
	}
	if(manager_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&manager_npc,30))NPC_stare_at_npc(&manager_npc,&PLAYER_npc);
			else NPC_animate_stand_dir(&manager_npc, RIGHT);
		if(ACTION_range_xy_xy(14*8,18*8,15*8,22*8,"Talk To Apartment Manager"))
		{
			TEXT_set_sprite_window(0,manager_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
	if(walking_into_door(RANGE_CITYElevatedLifeplaceToOUTSIDECity))
	{
		MAP_change_map(MAP_bobsgame_CITYCity,1628,39);return;
	}
}
void bobsgame_CITYElevatedLifeplace_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYElevatedLifeplace_Map_VBL_Function()
{

}
void bobsgame_CITYElevatedLifeplace_Map_HBL_Function()
{

}
//========================================================
//CITYElevatedLifeplaceElevator
//========================================================
void bobsgame_CITYElevatedLifeplaceElevator_Map_Load_Function()
{
//RANGE_CITYElevatedLifeplaceElevatorToOUTSIDECity 4*8,19*8,8*8,20*8
//RANGE_CITYElevatedLifeplaceElevatorToElevatedLifeplaceHallway 4*8,8*8,8*8,9*8
}
void bobsgame_CITYElevatedLifeplaceElevator_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

	static int floor=0;
	static int door_locked=0;
	int animate=0;
	if(floor!=0)
	{
		if(ACTION_range_xy_xy(2*8,18*8,4*8,19*8,"Press Down Button"))
		{
			floor=0;
			door_locked=1;
			animate=1;
		}
	}
	if(floor!=1)
	{
		if(ACTION_range_xy_xy(7*8,8*8,10*8,9*8,"Press Apartment Button"))
		{
			floor=1;
			door_locked=1;
			animate=1;
		}
	}
	//if selected floor cant leave while animating
	//if animation done, ding sound
	if(animate==1)
	{
		//TODO: screen shake
		//ding
		HARDWARE_play_sound("elevatording",127,44100,0);
		door_locked=0;
		animate=0;
	}

	if(walking_into_door(RANGE_CITYElevatedLifeplaceElevatorToOUTSIDECity)&&door_locked==0&&floor==0)
	{
		//if elevator is ground floor, OR selected floor is ground floor and animation is done
		//AND button for upper hallway hasnt been pressed yet
		MAP_change_map(MAP_bobsgame_CITYCity,1592,39);return;
	}
	if(walking_into_door(RANGE_CITYElevatedLifeplaceElevatorToElevatedLifeplaceHallway)&&door_locked==0&&floor==1)
	{
		//if press button
		//and elevator animation is done
		//OR is already on hallway and outside button hasnt been pressed
		MAP_change_map(MAP_bobsgame_CITYElevatedLifeplaceHallway,5,30);return;
	}
}
void bobsgame_CITYElevatedLifeplaceElevator_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYElevatedLifeplaceElevator_Map_VBL_Function()
{

}
void bobsgame_CITYElevatedLifeplaceElevator_Map_HBL_Function()
{

}
//========================================================
//CITYElevatedLifeplaceHallway
//========================================================
void bobsgame_CITYElevatedLifeplaceHallway_Map_Load_Function()
{
//RANGE_CITYElevatedLifeplaceHallwayToElevator 4*8,31*8,8*8,32*8
//RANGE_CITYElevatedLifeplaceHallwayToApartment 10*8,12*8,11*8,17*8
}
void bobsgame_CITYElevatedLifeplaceHallway_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}
	if(walking_into_door(RANGE_CITYElevatedLifeplaceHallwayToElevator))
	{
		//TODO: have to push button, wait for ding
		MAP_change_map(MAP_bobsgame_CITYElevatedLifeplaceElevator,5,9);return;
	}
	if(walking_into_door(RANGE_CITYElevatedLifeplaceHallwayToApartment))
	{
		MAP_change_map(MAP_bobsgame_CITYElevatedLifeplaceApartment,2,16);return;
	}
}
void bobsgame_CITYElevatedLifeplaceHallway_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYElevatedLifeplaceHallway_Map_VBL_Function()
{

}
void bobsgame_CITYElevatedLifeplaceHallway_Map_HBL_Function()
{

}
//========================================================
//CITYElevatedLifeplaceApartment
//========================================================
void bobsgame_CITYElevatedLifeplaceApartment_Map_Load_Function()
{
//RANGE_CITYElevatedLifeplaceApartmentToHallway 1*8,12*8,2*8,18*8
//RANGE_CITYElevatedLifeplaceApartmentToBathroom 20*8,22*8,21*8,27*8
//RANGE_CITYElevatedLifeplaceApartmentToBedroom 20*8,10*8,21*8,14*8
}
void bobsgame_CITYElevatedLifeplaceApartment_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}
//watch tv, eat.

	if(walking_into_door(RANGE_CITYElevatedLifeplaceApartmentToHallway))
	{
		MAP_change_map(MAP_bobsgame_CITYElevatedLifeplaceHallway,8,13);return;
	}
	if(walking_into_door(RANGE_CITYElevatedLifeplaceApartmentToBathroom))
	{
		MAP_change_map(MAP_bobsgame_CITYElevatedLifeplaceBathroom,2,12);return;
	}
	if(walking_into_door(RANGE_CITYElevatedLifeplaceApartmentToBedroom))
	{
		MAP_change_map(MAP_bobsgame_CITYElevatedLifeplaceBedroom,2,12);return;
	}
}
void bobsgame_CITYElevatedLifeplaceApartment_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYElevatedLifeplaceApartment_Map_VBL_Function()
{

}
void bobsgame_CITYElevatedLifeplaceApartment_Map_HBL_Function()
{

}
//========================================================
//CITYElevatedLifeplaceBathroom
//========================================================
void bobsgame_CITYElevatedLifeplaceBathroom_Map_Load_Function()
{
//RANGE_CITYElevatedLifeplaceBathroomToApartment 1*8,10*8,2*8,14*8
//RANGE_CITYElevatedLifeplaceBathroomToBedroom 3*8,9*8,7*8,10*8
}
void bobsgame_CITYElevatedLifeplaceBathroom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//TODO: use toilet, shower

	if(walking_into_door(RANGE_CITYElevatedLifeplaceBathroomToApartment))
	{
		MAP_change_map(MAP_bobsgame_CITYElevatedLifeplaceApartment,18,23);return;
	}
	if(walking_into_door(RANGE_CITYElevatedLifeplaceBathroomToBedroom))
	{
		MAP_change_map(MAP_bobsgame_CITYElevatedLifeplaceBedroom,5,23);return;
	}
}
void bobsgame_CITYElevatedLifeplaceBathroom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYElevatedLifeplaceBathroom_Map_VBL_Function()
{

}
void bobsgame_CITYElevatedLifeplaceBathroom_Map_HBL_Function()
{

}
//========================================================
//CITYElevatedLifeplaceBedroom
//========================================================
void bobsgame_CITYElevatedLifeplaceBedroom_Map_Load_Function()
{
//RANGE_CITYElevatedLifeplaceBedroomToBathroom 3*8,24*8,7*8,25*8
//RANGE_CITYElevatedLifeplaceBedroomToApartment 1*8,10*8,2*8,14*8
}
void bobsgame_CITYElevatedLifeplaceBedroom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//TODO: sleep

	if(walking_into_door(RANGE_CITYElevatedLifeplaceBedroomToBathroom))
	{
		MAP_change_map(MAP_bobsgame_CITYElevatedLifeplaceBathroom,5,10);return;
	}
	if(walking_into_door(RANGE_CITYElevatedLifeplaceBedroomToApartment))
	{
		MAP_change_map(MAP_bobsgame_CITYElevatedLifeplaceApartment,18,11);return;
	}
}
void bobsgame_CITYElevatedLifeplaceBedroom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYElevatedLifeplaceBedroom_Map_VBL_Function()
{

}
void bobsgame_CITYElevatedLifeplaceBedroom_Map_HBL_Function()
{

}


