//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================



#include "../../main.h"



#define RANGE_CITYHospitalEntranceToOUTSIDECityLeft 15*8,42*8,23*8,43*8
#define RANGE_CITYHospitalEntranceToOUTSIDECityMiddle 25*8,42*8,33*8,43*8
#define RANGE_CITYHospitalEntranceToOUTSIDECityRight 35*8,42*8,43*8,43*8
#define RANGE_CITYHospitalEntranceToBathroom 43*8,18*8,47*8,19*8
#define RANGE_CITYHospitalEntranceToElevator1 56*8,19*8,62*8,20*8
#define RANGE_CITYHospitalEntranceToElevator2 71*8,19*8,77*8,20*8
#define RANGE_CITYHospitalEntranceBathroomToEntrance 13*8,21*8,17*8,22*8
#define RANGE_CITYHospitalElevatorToSelectedFloor 5*8,19*8,11*8,20*8
#define RANGE_CITYHospitalWaitingOutPatientToElevator1 56*8,33*8,62*8,34*8
#define RANGE_CITYHospitalWaitingOutPatientToElevator2 71*8,33*8,77*8,34*8
#define RANGE_CITYHospitalWaitingOutPatientToWomensBathroom 44*8,34*8,48*8,35*8
#define RANGE_CITYHospitalWaitingOutPatientToMensBathroom 28*8,34*8,32*8,35*8
#define RANGE_CITYHospitalWaitingOutPatientToPatientRoom 6*8,9*8,10*8,10*8
#define RANGE_CITYHospitalWaitingOutPatientToOperatingRoom 69*8,9*8,77*8,10*8
#define RANGE_CITYHospitalWaitingOutPatientToPatientRoom2 27*8,9*8,31*8,10*8
#define RANGE_CITYHospitalWaitingOutPatientToPatientRoom3 48*8,9*8,52*8,10*8
#define RANGE_CITYHospitalMensBathroomToWaitingOutPatient 3*8,21*8,7*8,22*8
#define RANGE_CITYHospitalWomensBathroomToWaitingOutPatient 7*8,21*8,11*8,22*8
#define RANGE_CITYHospitalPatientRoomToWaitingOutPatient 6*8,30*8,10*8,31*8
#define RANGE_CITYHospitalOperatingRoomToWaitingOutPatient 12*8,38*8,20*8,39*8
#define RANGE_CITYHospitalPsychiatricWardToElevator 56*8,19*8,62*8,20*8
#define RANGE_CITYHospitalPsychiatricWardToElevator2 71*8,19*8,77*8,20*8
#define RANGE_CITYHospitalPsychiatricWardToSoftRoom 6*8,9*8,10*8,10*8
#define RANGE_CITYHospitalPsychiatricWardToSoftRoom2 20*8,9*8,24*8,10*8
#define RANGE_CITYHospitalPsychiatricWardToSoftRoom3 34*8,9*8,38*8,10*8
#define RANGE_CITYHospitalSoftRoomToPsychiatricWard 6*8,22*8,10*8,23*8
#define RANGE_CITYHospitalMaternityWardToElevator 56*8,19*8,62*8,20*8
#define RANGE_CITYHospitalMaternityWardToElevator2 71*8,19*8,77*8,20*8
#define RANGE_CITYHospitalMaternityWardToInfirmary 4*8,36*8,8*8,37*8
#define RANGE_CITYHospitalMaternityWardInfimaryToMaternityWard 4*8,26*8,8*8,27*8
#define RANGE_CITYHospitalMorgueToElevator 56*8,19*8,62*8,20*8
#define RANGE_CITYHospitalMorgueToElevator2 71*8,19*8,77*8,20*8
#define RANGE_CITYHospitalElevator2ToSelectedFloor 5*8,19*8,11*8,20*8
#define RANGE_CITYHospitalPatientRoom2ToWaitingOutPatient 6*8,30*8,10*8,31*8
#define RANGE_CITYHospitalPatientRoom3ToWaitingOutPatient 6*8,30*8,10*8,31*8
#define RANGE_CITYHospitalSoftRoom2ToPsychiatricWard 6*8,22*8,10*8,23*8
#define RANGE_CITYHospitalSoftRoom3ToPsychiatricWard 6*8,22*8,10*8,23*8



//========================================================
//CITYHospitalEntrance
//========================================================
void bobsgame_CITYHospitalEntrance_Map_Load_Function()
{
//RANGE_CITYHospitalEntranceToOUTSIDECityLeft 15*8,42*8,23*8,43*8
//RANGE_CITYHospitalEntranceToOUTSIDECityMiddle 25*8,42*8,33*8,43*8
//RANGE_CITYHospitalEntranceToOUTSIDECityRight 35*8,42*8,43*8,43*8
//RANGE_CITYHospitalEntranceToBathroom 43*8,18*8,47*8,19*8
//RANGE_CITYHospitalEntranceToElevator1 56*8,19*8,62*8,20*8
//RANGE_CITYHospitalEntranceToElevator2 71*8,19*8,77*8,20*8
}
void bobsgame_CITYHospitalEntrance_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//15,22
//24,22
//nurses
	static NPC* nurse1_npc = NULL;
	if(nurse1_npc==NULL)
	{
		NPC_create_npc_xy_feet(&nurse1_npc,GFX_ADULT_nurse,16,40,15*8,22*8);
		nurse1_npc->layer=3;
		nurse1_npc->non_walkable=1;
		NPC_animate_stand_dir(&nurse1_npc,DOWN);
	}
	if(nurse1_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&nurse1_npc,50))NPC_stare_at_npc(&nurse1_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&nurse1_npc, DOWN);
		//TODO: ANIMATE
		if(ACTION_range_xy_xy(12*8,24*8,16*8,25*8,"Talk To Nurse"))
		{
			TEXT_set_sprite_window(0,nurse1_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
	static NPC* nurse2_npc = NULL;
	if(nurse2_npc==NULL)
	{
		NPC_create_npc_xy_feet(&nurse2_npc,GFX_ADULT_paramedic,16,40,24*8,22*8);
		nurse2_npc->layer=3;
		nurse2_npc->non_walkable=1;
		NPC_animate_stand_dir(&nurse2_npc,DOWN);
	}
	if(nurse2_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&nurse2_npc,50))NPC_stare_at_npc(&nurse2_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&nurse2_npc, DOWN);
		//TODO: ANIMATE
		if(ACTION_range_xy_xy(22*8,24*8,26*8,25*8,"Talk To Nurse"))
		{
			TEXT_set_sprite_window(0,nurse2_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
//51,34 left
//55,37 right
//60,40 up
//65,34 left
//69,33 right over 1
//72,40 up
//76,40 up
//79,37 left
//79,33 left over 1
	static NPC* entrancepatients_npcs[9] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	int c=0;
	for(c=0;c<9;c++)
	{
		if(entrancepatients_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			int dir=UP;
			int bgp=2;
			//int* gfx=NULL;
			if(c== 0){x=51*8+2;y=32*8;dir=LEFT;bgp=1;}
			if(c== 1){x=55*8-2;y=34*8-4;dir=RIGHT;bgp=1;}
			if(c== 2){x=60*8;y=40*8;dir=UP;}
			if(c== 3){x=65*8+2;y=34*8-4;dir=LEFT;bgp=1;}
			if(c== 4){x=69*8-2;y=33*8;dir=RIGHT;bgp=1;}
			if(c== 5){x=72*8;y=40*8;dir=UP;}
			if(c== 6){x=76*8;y=40*8;dir=UP;}
			if(c== 7){x=79*8+2;y=34*8-4;dir=LEFT;bgp=1;}
			if(c== 8){x=79*8+2;y=31*8;dir=LEFT;bgp=1;}
			NPC_create_random_ADULT_xy_feet(&entrancepatients_npcs[c],x,y);

			//NPC_create_npc_xy_feet(&entrancepatients_npcs[c],gfx,16,40,x,(y));
			NPC_animate_stand_dir(&entrancepatients_npcs[c], dir);
			entrancepatients_npcs[c]->non_walkable=1;
			entrancepatients_npcs[c]->walk_dir=dir;
			entrancepatients_npcs[c]->layer=bgp;
			NPC_animate_dir(&entrancepatients_npcs[c], dir);
		}
		if(entrancepatients_npcs[c]!=NULL)
		{
			//if(NPC_in_range_of_npc_amt(&PLAYER_npc,entrancepatients_npcs[c],15))NPC_stare_at_npc(&entrancepatients_npcs[c],PLAYER_npc);
			//else NPC_animate_set_direction_now(&entrancepatients_npcs[c], entrancepatients_npcs[c]->walking_direction);
			//TODO: ANIMATE
		}
	}

	if(walking_into_door(RANGE_CITYHospitalEntranceToOUTSIDECityLeft))
	{
		MAP_change_map(MAP_bobsgame_CITYCity,1255,39);return;
	}
	if(walking_into_door(RANGE_CITYHospitalEntranceToOUTSIDECityMiddle))
	{
		MAP_change_map(MAP_bobsgame_CITYCity,1265,39);return;
	}
	if(walking_into_door(RANGE_CITYHospitalEntranceToOUTSIDECityRight))
	{
		MAP_change_map(MAP_bobsgame_CITYCity,1275,39);return;
	}
	if(walking_into_door(RANGE_CITYHospitalEntranceToBathroom))
	{
		MAP_change_map(MAP_bobsgame_CITYHospitalEntranceBathroom,15,20);return;
	}
	if(walking_into_door(RANGE_CITYHospitalEntranceToElevator1))
	{
		MAP_change_map(MAP_bobsgame_CITYHospitalElevator,7,18);return;
	}
	if(walking_into_door(RANGE_CITYHospitalEntranceToElevator2))
	{
		MAP_change_map(MAP_bobsgame_CITYHospitalElevator2,7,18);return;
	}
}
void bobsgame_CITYHospitalEntrance_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYHospitalEntrance_Map_VBL_Function()
{

}
void bobsgame_CITYHospitalEntrance_Map_HBL_Function()
{

}
//========================================================
//CITYHospitalEntranceBathroom
//========================================================
void bobsgame_CITYHospitalEntranceBathroom_Map_Load_Function()
{
//RANGE_CITYHospitalEntranceBathroomToEntrance 13*8,21*8,17*8,22*8
}
void bobsgame_CITYHospitalEntranceBathroom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}
//4,10 down
//TODO: use toilet
//maybe someone in stall?

	static NPC* stallman_npc = NULL;
	if(stallman_npc==NULL)
	{
		NPC_create_random_MAN_xy_feet(&stallman_npc,3*8,11*8);
		//NPC_create_npc_xy_feet(&stallman_npc,SPRITE,16,40,7*8,27*8);
		stallman_npc->non_walkable=1;
		stallman_npc->layer=2;
		NPC_animate_stand_dir(&stallman_npc,DOWN);
		stallman_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		stallman_npc->walk_dir=stallman_npc->anim_dir;
		//NPC_animate_increment_direction_frame_now(&stallman_npc, stallman_npc->anim_direction);
	}
	if(stallman_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&stallman_npc,45))NPC_stare_at_npc_not_opposite_walking_direction(&stallman_npc,&PLAYER_npc);
		else if(stallman_npc->AI==0){if(stallman_npc->vbls>200){if(r(4)==0){stallman_npc->AI=1+r(3);}else{stallman_npc->vbls=0;NPC_animate_stand_dir(&stallman_npc, stallman_npc->walk_dir);if(stallman_npc->anim_frame_count!=0){stallman_npc->anim_frame_count=3;NPC_animate(&stallman_npc);}}}}
		else if(stallman_npc->AI==1){if(stallman_npc->walk_dir==UP||stallman_npc->walk_dir==DOWN)NPC_animate_stand_dir(&stallman_npc,LEFT);else NPC_animate_stand_dir(&stallman_npc,UP);stallman_npc->vbls=r(120);stallman_npc->AI=0;}
		else if(stallman_npc->AI==2){if(stallman_npc->walk_dir==UP||stallman_npc->walk_dir==DOWN)NPC_animate_stand_dir(&stallman_npc,RIGHT);else NPC_animate_stand_dir(&stallman_npc,DOWN);stallman_npc->vbls=r(120);stallman_npc->AI=0;}
		else if(stallman_npc->AI==3){NPC_animate(&stallman_npc);stallman_npc->vbls=r(120);stallman_npc->AI=0;}

		if(ACTION_range_xy_xy(3*8,13*8,5*8,14*8,"Talk To Pooping Man"))
		{
			TEXT_set_sprite_window(0,stallman_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}

	if(walking_into_door(RANGE_CITYHospitalEntranceBathroomToEntrance))
	{
		MAP_change_map(MAP_bobsgame_CITYHospitalEntrance,45,19);return;
	}
}
void bobsgame_CITYHospitalEntranceBathroom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYHospitalEntranceBathroom_Map_VBL_Function()
{

}
void bobsgame_CITYHospitalEntranceBathroom_Map_HBL_Function()
{

}
//========================================================
//CITYHospitalElevator
//========================================================
void bobsgame_CITYHospitalElevator_Map_Load_Function()
{
//RANGE_CITYHospitalElevatorToSelectedFloor 5*8,19*8,11*8,20*8
}
void bobsgame_CITYHospitalElevator_Map_Run_Function(int MAP_just_loaded)
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
		TEXT_window("Which floor?<Q:Entrance 1F:OutPatient 2F:Psychiatric 3F:Maternity 4F:Morgue BF>"
		);
	}
	//if select same floor no ding
	//if no floor selected leave to same floor
	//if selected floor cant leave while animating
	if(strcmp(TEXTANSWER_selected_answer_string,"Entrance 1F")==0&&floor!=0){floor=0;door_locked=1;animate=1;}
	if(strcmp(TEXTANSWER_selected_answer_string,"OutPatient 2F")==0&&floor!=1){floor=1;door_locked=1;animate=1;}
	if(strcmp(TEXTANSWER_selected_answer_string,"Psychiatric 3F")==0&&floor!=2){floor=2;door_locked=1;animate=1;}
	if(strcmp(TEXTANSWER_selected_answer_string,"Maternity 4F")==0&&floor!=3){floor=3;door_locked=1;animate=1;}
	if(strcmp(TEXTANSWER_selected_answer_string,"Morgue BF")==0&&floor!=4){floor=4;door_locked=1;animate=1;}
	//if animation done, ding sound
	if(animate==1)
	{
		//TODO: screen shake
		//ding
		HARDWARE_play_sound("elevatording",127,44100,0);
		door_locked=0;
		animate=0;
	}

	if(walking_into_door(RANGE_CITYHospitalElevatorToSelectedFloor)
	&&door_locked==0)
	{
		//change to selected floor
		if(floor==0){MAP_change_map(MAP_bobsgame_CITYHospitalEntrance,58,20);return;}
		if(floor==1){MAP_change_map(MAP_bobsgame_CITYHospitalWaitingOutPatient,58,34);return;}
		if(floor==2){MAP_change_map(MAP_bobsgame_CITYHospitalPsychiatricWard,58,20);return;}
		if(floor==3){MAP_change_map(MAP_bobsgame_CITYHospitalMaternityWard,58,20);return;}
		if(floor==4){MAP_change_map(MAP_bobsgame_CITYHospitalMorgue,58,20);return;}
	}
}
void bobsgame_CITYHospitalElevator_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYHospitalElevator_Map_VBL_Function()
{

}
void bobsgame_CITYHospitalElevator_Map_HBL_Function()
{

}
//========================================================
//CITYHospitalElevator2
//========================================================
void bobsgame_CITYHospitalElevator2_Map_Load_Function()
{
//RANGE_CITYHospitalElevator2ToSelectedFloor 5*8,19*8,11*8,20*8
}
void bobsgame_CITYHospitalElevator2_Map_Run_Function(int MAP_just_loaded)
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
		TEXT_window("Which floor?<Q:Entrance 1F:OutPatient 2F:Psychiatric 3F:Maternity 4F:Morgue BF>"
		);
	}
	//if select same floor no ding
	//if no floor selected leave to same floor
	//if selected floor cant leave while animating
	if(strcmp(TEXTANSWER_selected_answer_string,"Entrance 1F")==0&&floor!=0){floor=0;door_locked=1;animate=1;}
	if(strcmp(TEXTANSWER_selected_answer_string,"OutPatient 2F")==0&&floor!=1){floor=1;door_locked=1;animate=1;}
	if(strcmp(TEXTANSWER_selected_answer_string,"Psychiatric 3F")==0&&floor!=2){floor=2;door_locked=1;animate=1;}
	if(strcmp(TEXTANSWER_selected_answer_string,"Maternity 4F")==0&&floor!=3){floor=3;door_locked=1;animate=1;}
	if(strcmp(TEXTANSWER_selected_answer_string,"Morgue BF")==0&&floor!=4){floor=4;door_locked=1;animate=1;}
	//if animation done, ding sound
	if(animate==1)
	{
		//TODO: screen shake
		//ding
		HARDWARE_play_sound("elevatording",127,44100,0);
		door_locked=0;
		animate=0;
	}

	if(walking_into_door(RANGE_CITYHospitalElevator2ToSelectedFloor)
	&&door_locked==0)
	{
		//change to selected floor
		if(floor==0){MAP_change_map(MAP_bobsgame_CITYHospitalEntrance,73,20);return;}
		if(floor==1){MAP_change_map(MAP_bobsgame_CITYHospitalWaitingOutPatient,73,34);return;}
		if(floor==2){MAP_change_map(MAP_bobsgame_CITYHospitalPsychiatricWard,73,20);return;}
		if(floor==3){MAP_change_map(MAP_bobsgame_CITYHospitalMaternityWard,73,20);return;}
		if(floor==4){MAP_change_map(MAP_bobsgame_CITYHospitalMorgue,73,20);return;}
	}
}
void bobsgame_CITYHospitalElevator2_Map_Stop_Function()
{

	NPC_delete_all_npcs();
}
void bobsgame_CITYHospitalElevator2_Map_VBL_Function()
{

}
void bobsgame_CITYHospitalElevator2_Map_HBL_Function()
{

}
//========================================================
//CITYHospitalWaitingOutPatient
//========================================================
void bobsgame_CITYHospitalWaitingOutPatient_Map_Load_Function()
{
//RANGE_CITYHospitalWaitingOutPatientToElevator1 56*8,33*8,62*8,34*8
//RANGE_CITYHospitalWaitingOutPatientToElevator2 71*8,33*8,77*8,34*8
//RANGE_CITYHospitalWaitingOutPatientToWomensBathroom 44*8,34*8,48*8,35*8
//RANGE_CITYHospitalWaitingOutPatientToMensBathroom 28*8,34*8,32*8,35*8
//RANGE_CITYHospitalWaitingOutPatientToPatientRoom 6*8,9*8,10*8,10*8
//RANGE_CITYHospitalWaitingOutPatientToOperatingRoom 69*8,9*8,77*8,10*8
//RANGE_CITYHospitalWaitingOutPatientToPatientRoom2 27*8,9*8,31*8,10*8
//RANGE_CITYHospitalWaitingOutPatientToPatientRoom3 48*8,9*8,52*8,10*8
}
void bobsgame_CITYHospitalWaitingOutPatient_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//9,42 up
//11,42 up
//15,44 right
//15,49 right

	static NPC* outpatientnurse_npc = NULL;
	if(outpatientnurse_npc==NULL)
	{
		NPC_create_npc_xy_feet(&outpatientnurse_npc,GFX_ADULT_nurse,16,40,11*8,44*8);
		//NPC_create_random_ADULT_xy_feet(&outpatientnurse_npc,11*8,34*8);
		outpatientnurse_npc->layer=2;
		outpatientnurse_npc->non_walkable=1;
		NPC_animate_stand_dir(&outpatientnurse_npc,RIGHT);
		outpatientnurse_npc->walking_speed = SPEED_NORMAL;
		outpatientnurse_npc->AI=0;
	}
	if(outpatientnurse_npc!=NULL)
	{
		if(NPC_in_range_of_area_xyxy_in_direction_by_amount(&PLAYER_npc,18*8,42*8,21*8,50*8,PLAYER_npc->anim_dir,0))
		{
			if(NPC_walk_to_xy_nohit(&outpatientnurse_npc,outpatientnurse_npc->walking_speed, 16*8,46*8)==1)NPC_animate_stand_dir(&outpatientnurse_npc,RIGHT);
		}
		else
		if(NPC_in_range_of_area_xyxy_in_direction_by_amount(&PLAYER_npc,4*8,36*8,16*8,39*8,PLAYER_npc->anim_dir,0))
		{
			if(NPC_walk_to_xy_nohit(&outpatientnurse_npc,outpatientnurse_npc->walking_speed, 14*8,41*8)==1)NPC_animate_stand_dir(&outpatientnurse_npc,UP);
		}
		else if(outpatientnurse_npc->AI== 0){if(NPC_walk_to_xy_nohit(&outpatientnurse_npc,outpatientnurse_npc->walking_speed, 9*8,41*8)==1){outpatientnurse_npc->AI=4;outpatientnurse_npc->vbls=r(60);NPC_animate_stand_dir(&outpatientnurse_npc,UP);}}
		else if(outpatientnurse_npc->AI== 1){if(NPC_walk_to_xy_nohit(&outpatientnurse_npc,outpatientnurse_npc->walking_speed,11*8,41*8)==1){outpatientnurse_npc->AI=4;outpatientnurse_npc->vbls=r(60);NPC_animate_stand_dir(&outpatientnurse_npc,UP);}}
		else if(outpatientnurse_npc->AI== 2){if(NPC_walk_to_xy_nohit(&outpatientnurse_npc,outpatientnurse_npc->walking_speed,16*8,44*8)==1){outpatientnurse_npc->AI=4;outpatientnurse_npc->vbls=r(60);NPC_animate_stand_dir(&outpatientnurse_npc,RIGHT);}}
		else if(outpatientnurse_npc->AI== 3){if(NPC_walk_to_xy_nohit(&outpatientnurse_npc,outpatientnurse_npc->walking_speed,16*8,48*8)==1){outpatientnurse_npc->AI=4;outpatientnurse_npc->vbls=r(60);NPC_animate_stand_dir(&outpatientnurse_npc,RIGHT);}}
		else if(outpatientnurse_npc->AI== 4){if(outpatientnurse_npc->vbls>120){outpatientnurse_npc->vbls=0;outpatientnurse_npc->AI=r(4);}}
		if(ACTION_range_xy_xy(4*8,38*8,19*8,50*8,"Talk To Outpatient Nurse"))
		{
			TEXT_set_sprite_window(0,outpatientnurse_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}

//39,47 face right
//46,52 face up
//54,48 face left
//60,46 right over 1
//76,48 left
//4,14 down, cart, talk to at 2-6,12-17
//23,30 down cart, talk to at 21-25,26-33
//43,12-4 wheelchair
//10,32-4 wheelchair
	static NPC* waitingpatients_npcs[9] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	int c=0;
	for(c=0;c<9;c++)
	{
		if(waitingpatients_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			int dir=UP;
			int bgp=2;
			//int* gfx=NULL;
			if(c== 0){x=40*8+2;y=48*8-4;dir=RIGHT;}
			if(c== 1){x=46*8;y=52*8+4;dir=UP;}
			if(c== 2){x=54*8-2;y=48*8-4;dir=LEFT;}
			if(c== 3){x=61*8+2;y=48*8-4;dir=RIGHT;}
			if(c== 4){x=76*8-2;y=48*8-4;dir=LEFT;}
			if(c== 5){x= 4*8;y=14*8;dir=DOWN;bgp=1;}
			if(c== 6){x=23*8;y=30*8;dir=DOWN;bgp=1;}
			if(c== 7){x=43*8;y=12*8;dir=DOWN;}
			if(c== 8){x=10*8;y=31*8;dir=DOWN;}
			NPC_create_random_ADULT_xy_feet(&waitingpatients_npcs[c],x,y);

			//NPC_create_npc_xy_feet(&waitingpatients_npcs[c],gfx,16,40,x,(y));
			NPC_animate_stand_dir(&waitingpatients_npcs[c], dir);
			waitingpatients_npcs[c]->non_walkable=1;
			waitingpatients_npcs[c]->walk_dir=dir;
			waitingpatients_npcs[c]->layer=bgp;
			//NPC_animate_increment_direction_frame_now(&waitingpatients_npcs[c], dir);
		}
		if(waitingpatients_npcs[c]!=NULL)
		{
			//if(NPC_in_range_of_npc_amt(&PLAYER_npc,waitingpatients_npcs[c],15))NPC_stare_at_npc(&waitingpatients_npcs[c],PLAYER_npc);
			//else NPC_animate_set_direction_now(&waitingpatients_npcs[c], waitingpatients_npcs[c]->walking_direction);
			//TODO: ANIMATE
		}
	}
//TODO: fish tank at 49,33-53,34
//nurse walking around?
//doctor running around?
	if(walking_into_door(RANGE_CITYHospitalWaitingOutPatientToElevator1))
	{
		MAP_change_map(MAP_bobsgame_CITYHospitalElevator,7,18);return;
	}
	if(walking_into_door(RANGE_CITYHospitalWaitingOutPatientToElevator2))
	{
		MAP_change_map(MAP_bobsgame_CITYHospitalElevator2,7,18);return;
	}
	if(walking_into_door(RANGE_CITYHospitalWaitingOutPatientToWomensBathroom))
	{
		MAP_change_map(MAP_bobsgame_CITYHospitalOutPatientWomensBathroom,9,20);return;
		//TODO: cant do that.
	}
	if(walking_into_door(RANGE_CITYHospitalWaitingOutPatientToMensBathroom))
	{
		MAP_change_map(MAP_bobsgame_CITYHospitalOutPatientMensBathroom,5,20);return;
	}
	if(walking_into_door(RANGE_CITYHospitalWaitingOutPatientToPatientRoom))
	{
		MAP_change_map(MAP_bobsgame_CITYHospitalPatientRoom,8,29);return;
	}
	if(walking_into_door(RANGE_CITYHospitalWaitingOutPatientToOperatingRoom))
	{
		MAP_change_map(MAP_bobsgame_CITYHospitalOperatingRoom,15,37);return;
	}
	if(walking_into_door(RANGE_CITYHospitalWaitingOutPatientToPatientRoom2))
	{
		MAP_change_map(MAP_bobsgame_CITYHospitalPatientRoom2,8,29);return;
	}
	if(walking_into_door(RANGE_CITYHospitalWaitingOutPatientToPatientRoom3))
	{
		MAP_change_map(MAP_bobsgame_CITYHospitalPatientRoom3,8,29);return;
	}
}
void bobsgame_CITYHospitalWaitingOutPatient_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYHospitalWaitingOutPatient_Map_VBL_Function()
{

}
void bobsgame_CITYHospitalWaitingOutPatient_Map_HBL_Function()
{

}
//========================================================
//CITYHospitalOutPatientMensBathroom
//========================================================
void bobsgame_CITYHospitalOutPatientMensBathroom_Map_Load_Function()
{
//RANGE_CITYHospitalMensBathroomToWaitingOutPatient 3*8,21*8,7*8,22*8
}
void bobsgame_CITYHospitalOutPatientMensBathroom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}
//TODO: use toilet
//TODO: something scary in here

	static NPC* stallman_npc = NULL;
	if(stallman_npc==NULL)
	{
		NPC_create_random_MAN_xy_feet(&stallman_npc,3*8,11*8);
		//NPC_create_npc_xy_feet(&stallman_npc,SPRITE,16,40,7*8,27*8);
		stallman_npc->non_walkable=1;
		stallman_npc->layer=2;
		NPC_animate_stand_dir(&stallman_npc,DOWN);
		stallman_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		stallman_npc->walk_dir=stallman_npc->anim_dir;
		//NPC_animate_increment_direction_frame_now(&stallman_npc, stallman_npc->anim_direction);
	}
	if(stallman_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&stallman_npc,45))NPC_stare_at_npc_not_opposite_walking_direction(&stallman_npc,&PLAYER_npc);
		else if(stallman_npc->AI==0){if(stallman_npc->vbls>200){if(r(4)==0){stallman_npc->AI=1+r(3);}else{stallman_npc->vbls=0;NPC_animate_stand_dir(&stallman_npc, stallman_npc->walk_dir);if(stallman_npc->anim_frame_count!=0){stallman_npc->anim_frame_count=3;NPC_animate(&stallman_npc);}}}}
		else if(stallman_npc->AI==1){if(stallman_npc->walk_dir==UP||stallman_npc->walk_dir==DOWN)NPC_animate_stand_dir(&stallman_npc,LEFT);else NPC_animate_stand_dir(&stallman_npc,UP);stallman_npc->vbls=r(120);stallman_npc->AI=0;}
		else if(stallman_npc->AI==2){if(stallman_npc->walk_dir==UP||stallman_npc->walk_dir==DOWN)NPC_animate_stand_dir(&stallman_npc,RIGHT);else NPC_animate_stand_dir(&stallman_npc,DOWN);stallman_npc->vbls=r(120);stallman_npc->AI=0;}
		else if(stallman_npc->AI==3){NPC_animate(&stallman_npc);stallman_npc->vbls=r(120);stallman_npc->AI=0;}

		if(ACTION_range_xy_xy(3*8,13*8,5*8,14*8,"Talk To Pooping Man"))
		{
			TEXT_set_sprite_window(0,stallman_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}

	if(walking_into_door(RANGE_CITYHospitalMensBathroomToWaitingOutPatient))
	{
		MAP_change_map(MAP_bobsgame_CITYHospitalWaitingOutPatient,30,35);return;
	}
}
void bobsgame_CITYHospitalOutPatientMensBathroom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYHospitalOutPatientMensBathroom_Map_VBL_Function()
{

}
void bobsgame_CITYHospitalOutPatientMensBathroom_Map_HBL_Function()
{

}
//========================================================
//CITYHospitalOutPatientWomensBathroom
//========================================================
void bobsgame_CITYHospitalOutPatientWomensBathroom_Map_Load_Function()
{
//RANGE_CITYHospitalWomensBathroomToWaitingOutPatient 7*8,21*8,11*8,22*8
}
void bobsgame_CITYHospitalOutPatientWomensBathroom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//TODO: use toilet

	static NPC* stallwoman_npc = NULL;
	if(stallwoman_npc==NULL)
	{
		NPC_create_random_WOMAN_xy_feet(&stallwoman_npc,3*8,11*8);
		//NPC_create_npc_xy_feet(&stallwoman_npc,SPRITE,16,40,7*8,27*8);
		stallwoman_npc->non_walkable=1;
		stallwoman_npc->layer=2;
		NPC_animate_stand_dir(&stallwoman_npc,DOWN);
		stallwoman_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		stallwoman_npc->walk_dir=stallwoman_npc->anim_dir;
		//NPC_animate_increment_direction_frame_now(&stallwoman_npc, stallwoman_npc->anim_direction);
	}
	if(stallwoman_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&stallwoman_npc,45))NPC_stare_at_npc_not_opposite_walking_direction(&stallwoman_npc,&PLAYER_npc);
		else if(stallwoman_npc->AI==0){if(stallwoman_npc->vbls>200){if(r(4)==0){stallwoman_npc->AI=1+r(3);}else{stallwoman_npc->vbls=0;NPC_animate_stand_dir(&stallwoman_npc, stallwoman_npc->walk_dir);if(stallwoman_npc->anim_frame_count!=0){stallwoman_npc->anim_frame_count=3;NPC_animate(&stallwoman_npc);}}}}
		else if(stallwoman_npc->AI==1){if(stallwoman_npc->walk_dir==UP||stallwoman_npc->walk_dir==DOWN)NPC_animate_stand_dir(&stallwoman_npc,LEFT);else NPC_animate_stand_dir(&stallwoman_npc,UP);stallwoman_npc->vbls=r(120);stallwoman_npc->AI=0;}
		else if(stallwoman_npc->AI==2){if(stallwoman_npc->walk_dir==UP||stallwoman_npc->walk_dir==DOWN)NPC_animate_stand_dir(&stallwoman_npc,RIGHT);else NPC_animate_stand_dir(&stallwoman_npc,DOWN);stallwoman_npc->vbls=r(120);stallwoman_npc->AI=0;}
		else if(stallwoman_npc->AI==3){NPC_animate(&stallwoman_npc);stallwoman_npc->vbls=r(120);stallwoman_npc->AI=0;}

		if(ACTION_range_xy_xy(3*8,13*8,5*8,14*8,"Talk To Sexy Lady"))
		{
			TEXT_set_sprite_window(0,stallwoman_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}

	if(walking_into_door(RANGE_CITYHospitalWomensBathroomToWaitingOutPatient))
	{
		MAP_change_map(MAP_bobsgame_CITYHospitalWaitingOutPatient,46,35);return;
	}
}
void bobsgame_CITYHospitalOutPatientWomensBathroom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYHospitalOutPatientWomensBathroom_Map_VBL_Function()
{

}
void bobsgame_CITYHospitalOutPatientWomensBathroom_Map_HBL_Function()
{

}
//========================================================
//CITYHospitalPatientRoom
//========================================================
void bobsgame_CITYHospitalPatientRoom_Map_Load_Function()
{
//RANGE_CITYHospitalPatientRoomToWaitingOutPatient 6*8,30*8,10*8,31*8
}
void bobsgame_CITYHospitalPatientRoom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//diseased
//director
//cripped
//familydoctordentist
//surgeon

//10,14 down visitor.
	static NPC* visitor_npc = NULL;
	if(visitor_npc==NULL)
	{
		//NPC_create_npc_xy_feet(&visitor_npc,GENERICbaldsuitguy,16,40,24*8,22*8);
		NPC_create_random_ADULT_xy_feet(&visitor_npc,10*8,12*8);
		visitor_npc->layer=2;
		visitor_npc->non_walkable=1;
		NPC_animate_stand_dir(&visitor_npc,DOWN);
	}
	if(visitor_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&visitor_npc,30))NPC_stare_at_npc(&visitor_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&visitor_npc, DOWN);
		if(ACTION_npc(&visitor_npc,"Talk To Visitor"))
		{
			TEXT_set_sprite_window(0,visitor_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
//TODO: have flowers, food?
//TODO: need sick lying down sprite
//17,25 face left, over 1
//15-18, 24
	static NPC* patient1_npc = NULL;
	if(patient1_npc==NULL)
	{
		//NPC_create_npc_xy_feet(&patient1_npc,diseased,16,40,17*8,24*8);
		NPC_create_random_ADULT_xy_feet(&patient1_npc,17*8,24*8);
		patient1_npc->layer=1;
		patient1_npc->non_walkable=1;
		NPC_animate_stand_dir(&patient1_npc,LEFT);
	}
	if(patient1_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&patient1_npc,30))NPC_stare_at_npc(&patient1_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&patient1_npc, LEFT);
		if(ACTION_range_xy_xy(15*8,24*8,18*8,25*8,"Talk To Patient"))
		{
			TEXT_set_sprite_window(0,patient1_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
//17,12 over 1
//15-18 13
	static NPC* patient2_npc = NULL;
	if(patient2_npc==NULL)
	{
		//NPC_create_npc_xy_feet(&patient2_npc,diseased,16,40,17*8,15*8);
		NPC_create_random_ADULT_xy_feet(&patient2_npc,17*8,15*8);
		patient2_npc->layer=1;
		patient2_npc->non_walkable=1;
		NPC_animate_stand_dir(&patient2_npc,LEFT);
	}
	if(patient2_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&patient2_npc,30))NPC_stare_at_npc(&patient2_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&patient2_npc, LEFT);
		if(ACTION_range_xy_xy(15*8,15*8,18*8,16*8,"Talk To Patient"))
		{
			TEXT_set_sprite_window(0,patient2_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}

	if(walking_into_door(RANGE_CITYHospitalPatientRoomToWaitingOutPatient))
	{
		MAP_change_map(MAP_bobsgame_CITYHospitalWaitingOutPatient,8,10);return;
	}
}
void bobsgame_CITYHospitalPatientRoom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYHospitalPatientRoom_Map_VBL_Function()
{

}
void bobsgame_CITYHospitalPatientRoom_Map_HBL_Function()
{

}
//========================================================
//CITYHospitalPatientRoom2
//========================================================
void bobsgame_CITYHospitalPatientRoom2_Map_Load_Function()
{
//RANGE_CITYHospitalPatientRoom2ToWaitingOutPatient 6*8,30*8,10*8,31*8
}
void bobsgame_CITYHospitalPatientRoom2_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

	if(walking_into_door(RANGE_CITYHospitalPatientRoom2ToWaitingOutPatient))
	{
		MAP_change_map(MAP_bobsgame_CITYHospitalWaitingOutPatient,29,10);return;
	}
}
void bobsgame_CITYHospitalPatientRoom2_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYHospitalPatientRoom2_Map_VBL_Function()
{

}
void bobsgame_CITYHospitalPatientRoom2_Map_HBL_Function()
{

}
//========================================================
//CITYHospitalPatientRoom3
//========================================================
void bobsgame_CITYHospitalPatientRoom3_Map_Load_Function()
{
//RANGE_CITYHospitalPatientRoom3ToWaitingOutPatient 6*8,30*8,10*8,31*8
}
void bobsgame_CITYHospitalPatientRoom3_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

	if(walking_into_door(RANGE_CITYHospitalPatientRoom3ToWaitingOutPatient))
	{
		MAP_change_map(MAP_bobsgame_CITYHospitalWaitingOutPatient,50,10);return;
	}
}
void bobsgame_CITYHospitalPatientRoom3_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYHospitalPatientRoom3_Map_VBL_Function()
{

}
void bobsgame_CITYHospitalPatientRoom3_Map_HBL_Function()
{

}

//========================================================
//CITYHospitalOperatingRoom
//========================================================
void bobsgame_CITYHospitalOperatingRoom_Map_Load_Function()
{
//RANGE_CITYHospitalOperatingRoomToWaitingOutPatient 12*8,38*8,20*8,39*8
}
void bobsgame_CITYHospitalOperatingRoom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//surgeon
//12,21 up
//13,24 right
	static NPC* surgeon_npc = NULL;
	if(surgeon_npc==NULL)
	{
		NPC_create_npc_xy_feet(&surgeon_npc,GFX_ADULT_surgeon,16,40,13*8,22*8);
		//NPC_create_random_ADULT_xy_feet(&surgeon_npc,17*8,15*8);
		surgeon_npc->layer=2;
		surgeon_npc->non_walkable=1;
		NPC_animate_stand_dir(&surgeon_npc,DOWN);
	}
	if(surgeon_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&surgeon_npc,20))NPC_stare_at_npc(&surgeon_npc,&PLAYER_npc);
		//else NPC_animate_set_direction_now(&surgeon_npc, LEFT);
		else if(surgeon_npc->AI==0){if(NPC_walk_to_xy_nohit_pushmain(&surgeon_npc,SPEED_NORMAL,11*8,23*8)==1){NPC_animate_stand_dir(&surgeon_npc,LEFT);surgeon_npc->vbls=r(40);surgeon_npc->AI++;}}
		else if(surgeon_npc->AI==1){if(surgeon_npc->vbls>120)surgeon_npc->AI++;}
		else if(surgeon_npc->AI==2){if(NPC_walk_to_xy_nohit_pushmain(&surgeon_npc,SPEED_NORMAL,14*8,25*8)==1){NPC_animate_stand_dir(&surgeon_npc,RIGHT);surgeon_npc->vbls=r(40);surgeon_npc->AI++;}}
		else if(surgeon_npc->AI==3){if(surgeon_npc->vbls>120)surgeon_npc->AI=0;}
		if(ACTION_npc(&surgeon_npc,"Talk To Surgeon"))
		{
			TEXT_set_sprite_window(0,surgeon_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""//alright lets start sawing. you ever play that surgery game? with the magic hands? yeah, i got that. here feel em. "my hands arent sterile" oh thats a myth. here you wanna try this? its fun! go for it, brain, spleen, whatever you feel like. he signed the waiver.
			);
		}
	}
//diseased
//17,23 over 1
	static NPC* diseased_npc = NULL;
	if(diseased_npc==NULL)
	{
		NPC_create_npc_xy_feet(&diseased_npc,GFX_ADULT_diseased,16,40,16*8,24*8);
		//NPC_create_random_ADULT_xy_feet(&diseased_npc,17*8,15*8);
		diseased_npc->layer=1;
		diseased_npc->non_walkable=1;
		NPC_animate_stand_dir(&diseased_npc,DOWN);
	}
	if(diseased_npc!=NULL)
	{
		if(ACTION_range_xy_xy(17*8,22*8,19*8,27*8,"Talk To Patient"))
		{
			TEXT_set_sprite_window(0,diseased_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""//<TINY><GRAY>the anaethestic didnt work i can feel i can talk but i cant move help help help
			);
		}
	}
	//assistants
	static NPC* surgerynurse1_npc = NULL;
	if(surgerynurse1_npc==NULL)
	{
		NPC_create_npc_xy_feet(&surgerynurse1_npc,GFX_ADULT_nurse,16,40,6*8,22*8);
		//NPC_create_random_ADULT_xy_feet(&surgerynurse1_npc,17*8,15*8);
		surgerynurse1_npc->layer=2;
		surgerynurse1_npc->non_walkable=1;
		NPC_animate_stand_dir(&surgerynurse1_npc,RIGHT);
	}
	if(surgerynurse1_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&surgerynurse1_npc,20))NPC_stare_at_npc(&surgerynurse1_npc,&PLAYER_npc);
		//else NPC_animate_set_direction_now(&surgerynurse1_npc, LEFT);
		else if(surgerynurse1_npc->AI==0){if(NPC_walk_to_xy_nohit_pushmain(&surgerynurse1_npc,SPEED_NORMAL,5*8,12*8)==1){NPC_animate_stand_dir(&surgerynurse1_npc,UP);surgerynurse1_npc->vbls=r(40);surgerynurse1_npc->AI++;}}
		else if(surgerynurse1_npc->AI==1){if(surgerynurse1_npc->vbls>120)surgerynurse1_npc->AI++;}
		else if(surgerynurse1_npc->AI==2){if(NPC_walk_to_xy_nohit_pushmain(&surgerynurse1_npc,SPEED_NORMAL,6*8,22*8)==1){NPC_animate_stand_dir(&surgerynurse1_npc,RIGHT);surgerynurse1_npc->vbls=r(40);surgerynurse1_npc->AI++;}}
		else if(surgerynurse1_npc->AI==3){if(surgerynurse1_npc->vbls>120)surgerynurse1_npc->AI=0;}
		if(ACTION_npc(&surgerynurse1_npc,"Talk To Assistant"))
		{
			TEXT_set_sprite_window(0,surgerynurse1_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
	//TODO: need nurse in scrubs.
	static NPC* surgerynurse2_npc = NULL;
	if(surgerynurse2_npc==NULL)
	{
		NPC_create_npc_xy_feet(&surgerynurse2_npc,GFX_ADULT_nurse,16,40,22*8,12*8);
		//NPC_create_random_ADULT_xy_feet(&surgerynurse2_npc,17*8,15*8);
		surgerynurse2_npc->layer=2;
		surgerynurse2_npc->non_walkable=1;
		NPC_animate_stand_dir(&surgerynurse2_npc,UP);
	}
	if(surgerynurse2_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&surgerynurse2_npc,20))NPC_stare_at_npc(&surgerynurse2_npc,&PLAYER_npc);
		//else NPC_animate_set_direction_now(&surgerynurse2_npc, LEFT);
		else if(surgerynurse2_npc->AI==0){if(NPC_walk_to_xy_nohit_pushmain(&surgerynurse2_npc,SPEED_NORMAL,22*8,26*8)==1){NPC_animate_stand_dir(&surgerynurse2_npc,LEFT);surgerynurse2_npc->vbls=r(40);surgerynurse2_npc->AI++;}}
		else if(surgerynurse2_npc->AI==1){if(surgerynurse2_npc->vbls>120)surgerynurse2_npc->AI++;}
		else if(surgerynurse2_npc->AI==2){if(NPC_walk_to_xy_nohit_pushmain(&surgerynurse2_npc,SPEED_NORMAL,22*8,12*8)==1){NPC_animate_stand_dir(&surgerynurse2_npc,UP);surgerynurse2_npc->vbls=r(40);surgerynurse2_npc->AI++;}}
		else if(surgerynurse2_npc->AI==3){if(surgerynurse2_npc->vbls>120)surgerynurse2_npc->AI=0;}
		if(ACTION_npc(&surgerynurse2_npc,"Talk To Assistant"))
		{
			TEXT_set_sprite_window(0,surgerynurse2_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
	//TODO: beeping
	if(walking_into_door(RANGE_CITYHospitalOperatingRoomToWaitingOutPatient))
	{
		MAP_change_map(MAP_bobsgame_CITYHospitalWaitingOutPatient,72,10);return;
	}
}
void bobsgame_CITYHospitalOperatingRoom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYHospitalOperatingRoom_Map_VBL_Function()
{

}
void bobsgame_CITYHospitalOperatingRoom_Map_HBL_Function()
{

}
//========================================================
//CITYHospitalPsychiatricWard
//========================================================
void bobsgame_CITYHospitalPsychiatricWard_Map_Load_Function()
{
//RANGE_CITYHospitalPsychiatricWardToElevator 56*8,19*8,62*8,20*8
//RANGE_CITYHospitalPsychiatricWardToElevator2 71*8,19*8,77*8,20*8
//RANGE_CITYHospitalPsychiatricWardToSoftRoom 6*8,9*8,10*8,10*8
//RANGE_CITYHospitalPsychiatricWardToSoftRoom2 20*8,9*8,24*8,10*8
//RANGE_CITYHospitalPsychiatricWardToSoftRoom3 34*8,9*8,38*8,10*8
}
void bobsgame_CITYHospitalPsychiatricWard_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//15,12 down wheelchair
//10,17 down
//14,17 down--
//21,17 down
//25,17 down--
//10,22 up--
//14,22 up
//21,22 up--
//25,22 up
//10,41 down wheelchair
//19,39 right
//19,36 right
//24,32 down
	static NPC* crazypeople_npcs[11] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	int c=0;
	for(c=0;c<11;c++)
	{
		if(crazypeople_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			int dir=UP;
			int bgp=2;
			//int* gfx=NULL;
			if(c== 0){x=15*8;y=12*8;dir=DOWN;}
			if(c== 1){x=11*8;y=41*8;dir=DOWN;}
			if(c== 2){x=11*8;y=18*8;dir=DOWN;}
			if(c== 3){x=15*8;y=18*8;dir=DOWN;}
			if(c== 4){x=22*8;y=18*8;dir=DOWN;}
			if(c== 5){x=15*8;y=23*8;dir=UP;bgp=3;}
			if(c== 6){x=22*8;y=23*8;dir=UP;bgp=3;}
			if(c== 7){x=26*8;y=23*8;dir=UP;bgp=3;}
			if(c== 8){x=21*8+2;y=36*8+4;dir=RIGHT;bgp=1;}
			if(c== 9){x=21*8+2;y=34*8;dir=RIGHT;bgp=1;}
			if(c==10){x=25*8;y=32*8;dir=DOWN;bgp=1;}
			NPC_create_random_ADULT_xy_feet(&crazypeople_npcs[c],x,y);

			//NPC_create_npc_xy_feet(&crazypeople_npcs[c],gfx,16,40,x,(y));
			NPC_animate_stand_dir(&crazypeople_npcs[c], dir);
			crazypeople_npcs[c]->non_walkable=1;
			crazypeople_npcs[c]->walk_dir=dir;
			crazypeople_npcs[c]->layer=bgp;
			//NPC_animate_increment_direction_frame_now(&crazypeople_npcs[c], dir);
		}
		if(crazypeople_npcs[c]!=NULL)
		{
			if(crazypeople_npcs[c]->AI==0){if(crazypeople_npcs[c]->vbls>200){if(r(3)==0){crazypeople_npcs[c]->AI=1+r(3);}else{crazypeople_npcs[c]->vbls=0;NPC_animate_stand_dir(&crazypeople_npcs[c], crazypeople_npcs[c]->walk_dir);if(crazypeople_npcs[c]->anim_frame_count!=0){crazypeople_npcs[c]->anim_frame_count=3;NPC_animate(&crazypeople_npcs[c]);}}}}
			if(crazypeople_npcs[c]->AI==1){if(crazypeople_npcs[c]->walk_dir==UP||crazypeople_npcs[c]->walk_dir==DOWN)NPC_animate_stand_dir(&crazypeople_npcs[c],LEFT);else NPC_animate_stand_dir(&crazypeople_npcs[c],UP);crazypeople_npcs[c]->vbls=r(120);crazypeople_npcs[c]->AI=0;}
			if(crazypeople_npcs[c]->AI==2){if(crazypeople_npcs[c]->walk_dir==UP||crazypeople_npcs[c]->walk_dir==DOWN)NPC_animate_stand_dir(&crazypeople_npcs[c],RIGHT);else NPC_animate_stand_dir(&crazypeople_npcs[c],DOWN);crazypeople_npcs[c]->vbls=r(120);crazypeople_npcs[c]->AI=0;}
			if(crazypeople_npcs[c]->AI==3){NPC_animate(&crazypeople_npcs[c]);crazypeople_npcs[c]->vbls=r(120);crazypeople_npcs[c]->AI=0;}
			//if(NPC_in_range_of_npc_amt(&PLAYER_npc,crazypeople_npcs[c],15))NPC_stare_at_npc(&crazypeople_npcs[c],PLAYER_npc);
			//else NPC_animate_set_direction_now(&crazypeople_npcs[c], crazypeople_npcs[c]->walking_direction);
		}
	}
//42, 12 up looking at tank
	static NPC* crazylookingatfish_npc = NULL;
	if(crazylookingatfish_npc==NULL)
	{
		//NPC_create_npc_xy_feet(&crazylookingatfish_npc,crazylookingatfish,16,40,13*8,22*8);
		NPC_create_random_ADULT_xy_feet(&crazylookingatfish_npc,42*8,12*8);
		crazylookingatfish_npc->layer=2;
		crazylookingatfish_npc->non_walkable=1;
		NPC_animate_stand_dir(&crazylookingatfish_npc,UP);
	}
	if(crazylookingatfish_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&crazylookingatfish_npc,15))NPC_stare_at_npc(&crazylookingatfish_npc,&PLAYER_npc);
		//else NPC_animate_set_direction_now(&crazylookingatfish_npc, LEFT);
		else if(crazylookingatfish_npc->AI==0){if(NPC_walk_to_xy_nohit_pushmain(&crazylookingatfish_npc,SPEED_NORMAL,41*8,12*8)==1){NPC_animate_stand_dir(&crazylookingatfish_npc,UP);crazylookingatfish_npc->vbls=r(40);crazylookingatfish_npc->AI=3;}}
		else if(crazylookingatfish_npc->AI==1){if(NPC_walk_to_xy_nohit_pushmain(&crazylookingatfish_npc,SPEED_NORMAL,42*8,12*8)==1){NPC_animate_stand_dir(&crazylookingatfish_npc,UP);crazylookingatfish_npc->vbls=r(40);crazylookingatfish_npc->AI=3;}}
		else if(crazylookingatfish_npc->AI==2){if(NPC_walk_to_xy_nohit_pushmain(&crazylookingatfish_npc,SPEED_NORMAL,44*8,12*8)==1){NPC_animate_stand_dir(&crazylookingatfish_npc,UP);crazylookingatfish_npc->vbls=r(40);crazylookingatfish_npc->AI=3;}}
		else if(crazylookingatfish_npc->AI==3){if(crazylookingatfish_npc->vbls>120)crazylookingatfish_npc->AI=r(3);}
		if(ACTION_npc(&crazylookingatfish_npc,"Talk To Fish Watcher"))
		{
			TEXT_set_sprite_window(0,crazylookingatfish_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
	static NPC* psychiatrist_npc = NULL;
	if(psychiatrist_npc==NULL)
	{
		NPC_create_npc_xy_feet(&psychiatrist_npc,GFX_ADULT_psychiatrist,16,40,38*8,18*8);
		//NPC_create_random_ADULT_xy_feet(&psychiatrist_npc,11*8,34*8);
		psychiatrist_npc->layer=2;
		psychiatrist_npc->non_walkable=1;
		NPC_animate_stand_dir(&psychiatrist_npc,DOWN);
		psychiatrist_npc->walking_speed = SPEED_NORMAL;
		psychiatrist_npc->AI=0;
	}
	if(psychiatrist_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&psychiatrist_npc,60))NPC_stare_at_npc(&psychiatrist_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&psychiatrist_npc, DOWN);
		if(ACTION_npc(&psychiatrist_npc,"Talk To Psychiatrist"))
		{
			TEXT_set_sprite_window(0,psychiatrist_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}

	static NPC* quack_npc = NULL;
	if(quack_npc==NULL)
	{
		NPC_create_npc_xy_feet(&quack_npc,GFX_ADULT_quack,16,40,14*8,41*8);
		//NPC_create_random_ADULT_xy_feet(&quack_npc,17*8,15*8);
		quack_npc->layer=2;
		quack_npc->non_walkable=1;
		NPC_animate_stand_dir(&quack_npc,LEFT);
	}
	if(quack_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&quack_npc,15))NPC_dont_look_at_npc(&quack_npc,&PLAYER_npc);
		//else NPC_animate_set_direction_now(&quack_npc, LEFT);
		else if(quack_npc->AI== 0){if(NPC_walk_to_xy_nohit_pushmain(&quack_npc,SPEED_NORMAL,14*8,41*8)==1){NPC_animate_stand_dir(&quack_npc,LEFT);quack_npc->vbls=r(40);quack_npc->AI++;}}
		else if(quack_npc->AI== 1){if(quack_npc->vbls>120)quack_npc->AI++;}
		else if(quack_npc->AI== 2){if(NPC_walk_to_xy_nohit_pushmain(&quack_npc,SPEED_FAST,  13*8,25*8)==1){NPC_animate_stand_dir(&quack_npc,RIGHT);quack_npc->vbls=r(40);quack_npc->AI++;}}
		else if(quack_npc->AI== 3){if(quack_npc->vbls>120)quack_npc->AI++;}
		else if(quack_npc->AI== 4){if(NPC_walk_to_xy_nohit_pushmain(&quack_npc,SPEED_NORMAL, 6*8,29*8)==1){NPC_animate_stand_dir(&quack_npc,LEFT);quack_npc->vbls=r(40);quack_npc->AI++;}}
		else if(quack_npc->AI== 5){if(quack_npc->vbls>120)quack_npc->AI++;}
		else if(quack_npc->AI== 6){if(NPC_walk_to_xy_nohit_pushmain(&quack_npc,SPEED_SLOW,   3*8,12*8)==1){NPC_animate_stand_dir(&quack_npc,UP);quack_npc->vbls=r(40);quack_npc->AI++;}}
		else if(quack_npc->AI== 7){if(quack_npc->vbls>120)quack_npc->AI++;}
		else if(quack_npc->AI== 8){if(NPC_walk_to_xy_nohit_pushmain(&quack_npc,SPEED_NORMAL,14*8,14*8)==1){NPC_animate_stand_dir(&quack_npc,UP);quack_npc->vbls=r(40);quack_npc->AI++;}}
		else if(quack_npc->AI== 9){if(quack_npc->vbls>120)quack_npc->AI++;}
		else if(quack_npc->AI==10){if(NPC_walk_to_xy_nohit_pushmain(&quack_npc,SPEED_FAST,  34*8,17*8)==1){NPC_animate_stand_dir(&quack_npc,RIGHT);quack_npc->vbls=r(40);quack_npc->AI++;}}
		else if(quack_npc->AI==11){if(quack_npc->vbls>120)quack_npc->AI++;}
		else if(quack_npc->AI==12){if(NPC_walk_to_xy_nohit_pushmain(&quack_npc,SPEED_NORMAL,33*8,39*8)==1){NPC_animate_stand_dir(&quack_npc,RIGHT);quack_npc->vbls=r(40);quack_npc->AI++;}}
		else if(quack_npc->AI==13){if(quack_npc->vbls>120)quack_npc->AI++;}
		else if(quack_npc->AI==14){if(NPC_walk_to_xy_nohit_pushmain(&quack_npc,SPEED_NORMAL,19*8,43*8)==1){NPC_animate_stand_dir(&quack_npc,UP);quack_npc->vbls=r(40);quack_npc->AI++;}}
		else if(quack_npc->AI==15){if(quack_npc->vbls>120)quack_npc->AI=0;}
		if(ACTION_npc(&quack_npc,"Talk To Doctor"))
		{
			TEXT_set_sprite_window(0,quack_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("The apple man is the demon king.<.>"
			"I have the secret dance of the flies.<.>"
			"Nobody understand, nobody understand my body.<.>"
			"Too much brain they cannot see. Quotient 300 of smart.<.>"
			"Planet spin on rubber sheet.<.>"
			"Push the ice to melt. Same as time.<.>"
			"Think hard make quantum teleport.<.>"
			"Nobody understand, nobody understand.<.>"
			"Death illusion, reality simulation, think think think hard change data.<.>"
			"Mind over matter, matter is mind, no matter, don't mind, no mind does not matter.<.>"
			"Psychosomatic reality we see me not psychotic Yuu is stupid and evil go away my love love.<.>"
			);
		}
	}
//TODO: 3-4,26-31 fishtank
//TODO: 7-9,40-44 fishtank
//clerk
//64,37 up
//76,37 up
	static NPC* psychnurse_npc = NULL;
	if(psychnurse_npc==NULL)
	{
		NPC_create_npc_xy_feet(&psychnurse_npc,GFX_ADULT_paramedic,16,40,64*8,37*8);
		//NPC_create_random_ADULT_xy_feet(&psychnurse_npc,11*8,34*8);
		psychnurse_npc->layer=2;
		psychnurse_npc->non_walkable=1;
		NPC_animate_stand_dir(&psychnurse_npc,RIGHT);
		psychnurse_npc->walking_speed = SPEED_NORMAL;
		psychnurse_npc->AI=0;
	}
	if(psychnurse_npc!=NULL)
	{
		if(NPC_in_range_of_area_xyxy_in_direction_by_amount(&PLAYER_npc,63*8,33*8,76*8,34*8,PLAYER_npc->anim_dir,0))
		{
			if(NPC_walk_to_xy_nohit(&psychnurse_npc,psychnurse_npc->walking_speed, 76*8,36*8)==1)NPC_animate_stand_dir(&psychnurse_npc,UP);
		}
		else
		if(NPC_in_range_of_area_xyxy_in_direction_by_amount(&PLAYER_npc,60*8,35*8,61*8,40*8,PLAYER_npc->anim_dir,0))
		{
			if(NPC_walk_to_xy_nohit(&psychnurse_npc,psychnurse_npc->walking_speed, 64*8,36*8)==1)NPC_animate_stand_dir(&psychnurse_npc,LEFT);
		}
		else if(psychnurse_npc->AI== 0){if(NPC_walk_to_xy_nohit(&psychnurse_npc,psychnurse_npc->walking_speed,76*8,36*8)==1){psychnurse_npc->AI=3;psychnurse_npc->vbls=r(60);NPC_animate_stand_dir(&psychnurse_npc,UP);}}
		else if(psychnurse_npc->AI== 1){if(NPC_walk_to_xy_nohit(&psychnurse_npc,psychnurse_npc->walking_speed,71*8,36*8)==1){psychnurse_npc->AI=3;psychnurse_npc->vbls=r(60);NPC_animate_stand_dir(&psychnurse_npc,UP);}}
		else if(psychnurse_npc->AI== 2){if(NPC_walk_to_xy_nohit(&psychnurse_npc,psychnurse_npc->walking_speed,64*8,36*8)==1){psychnurse_npc->AI=3;psychnurse_npc->vbls=r(60);NPC_animate_stand_dir(&psychnurse_npc,UP);}}
		else if(psychnurse_npc->AI== 3){if(psychnurse_npc->vbls>120){psychnurse_npc->vbls=0;psychnurse_npc->AI=r(3);}}
		if(ACTION_range_xy_xy(60*8,33*8,77*8,40*8,"Talk To Psychiatric Assistant"))
		{
			TEXT_set_sprite_window(0,psychnurse_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
//wheelchair 52,23 down
//TODO: limit going in/out of door
//TODO: maybe split these maps
//TODO: need psychiatrist office?

	if(walking_into_door(RANGE_CITYHospitalPsychiatricWardToElevator))
	{
		MAP_change_map(MAP_bobsgame_CITYHospitalElevator,7,18);return;
	}
	if(walking_into_door(RANGE_CITYHospitalPsychiatricWardToElevator2))
	{
		MAP_change_map(MAP_bobsgame_CITYHospitalElevator2,7,18);return;
	}
	if(walking_into_door(RANGE_CITYHospitalPsychiatricWardToSoftRoom))
	{
		MAP_change_map(MAP_bobsgame_CITYHospitalSoftRoom,8,21);return;
	}
	if(walking_into_door(RANGE_CITYHospitalPsychiatricWardToSoftRoom2))
	{
		MAP_change_map(MAP_bobsgame_CITYHospitalSoftRoom2,8,21);return;
	}
	if(walking_into_door(RANGE_CITYHospitalPsychiatricWardToSoftRoom3))
	{
		MAP_change_map(MAP_bobsgame_CITYHospitalSoftRoom3,8,21);return;
	}
}
void bobsgame_CITYHospitalPsychiatricWard_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYHospitalPsychiatricWard_Map_VBL_Function()
{

}
void bobsgame_CITYHospitalPsychiatricWard_Map_HBL_Function()
{

}
//========================================================
//CITYHospitalSoftRoom
//========================================================
void bobsgame_CITYHospitalSoftRoom_Map_Load_Function()
{
//RANGE_CITYHospitalSoftRoomToPsychiatricWard 6*8,22*8,10*8,23*8
}
void bobsgame_CITYHospitalSoftRoom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//8,15 face left
	static NPC* softroom_npc = NULL;
	if(softroom_npc==NULL)
	{
		NPC_create_npc_xy_feet(&softroom_npc,GFX_ADULT_tinfoilhatman,16,40,5*8,15*8);
		//NPC_create_random_ADULT_xy_feet(&softroom_npc,8*8,15*8);
		softroom_npc->layer=2;
		softroom_npc->non_walkable=1;
		NPC_animate_stand_dir(&softroom_npc,LEFT);
	}
	if(softroom_npc!=NULL)
	{
		//if(NPC_in_range_of_npc_amt(&PLAYER_npc,softroom_npc,30))NPC_stare_at_npc(&softroom_npc,PLAYER_npc);
		//else NPC_animate_set_direction_now(&softroom_npc, LEFT);
		NPC_stare_at_npc(&softroom_npc,&PLAYER_npc);
		if(ACTION_npc(&softroom_npc,"Talk To Tin Foil Hat Man"))
		{
			TEXT_set_sprite_window(0,softroom_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}

	if(walking_into_door(RANGE_CITYHospitalSoftRoomToPsychiatricWard))
	{
		MAP_change_map(MAP_bobsgame_CITYHospitalPsychiatricWard,8,10);return;
	}
}
void bobsgame_CITYHospitalSoftRoom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYHospitalSoftRoom_Map_VBL_Function()
{

}
void bobsgame_CITYHospitalSoftRoom_Map_HBL_Function()
{

}
//========================================================
//CITYHospitalSoftRoom2
//========================================================
void bobsgame_CITYHospitalSoftRoom2_Map_Load_Function()
{
//RANGE_CITYHospitalSoftRoom2ToPsychiatricWard 6*8,22*8,10*8,23*8
}
void bobsgame_CITYHospitalSoftRoom2_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

	static NPC* softroom_npc = NULL;
	if(softroom_npc==NULL)
	{
		NPC_create_npc_xy_feet(&softroom_npc,GFX_ADULT_timetraveler,16,40,5*8,15*8);
		//NPC_create_random_ADULT_xy_feet(&softroom_npc,8*8,15*8);
		softroom_npc->layer=2;
		softroom_npc->non_walkable=1;
		NPC_animate_stand_dir(&softroom_npc,LEFT);
	}
	if(softroom_npc!=NULL)
	{
		//if(NPC_in_range_of_npc_amt(&PLAYER_npc,softroom_npc,30))NPC_stare_at_npc(&softroom_npc,PLAYER_npc);
		//else NPC_animate_set_direction_now(&softroom_npc, LEFT);
		NPC_stare_at_npc(&softroom_npc,&PLAYER_npc);
		if(ACTION_npc(&softroom_npc,"Talk To Time Traveler"))
		{
			TEXT_set_sprite_window(0,softroom_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}

	if(walking_into_door(RANGE_CITYHospitalSoftRoom2ToPsychiatricWard))
	{
		MAP_change_map(MAP_bobsgame_CITYHospitalPsychiatricWard,22,10);return;
	}
}
void bobsgame_CITYHospitalSoftRoom2_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYHospitalSoftRoom2_Map_VBL_Function()
{

}
void bobsgame_CITYHospitalSoftRoom2_Map_HBL_Function()
{

}
//========================================================
//CITYHospitalSoftRoom3
//========================================================
void bobsgame_CITYHospitalSoftRoom3_Map_Load_Function()
{
//RANGE_CITYHospitalSoftRoom3ToPsychiatricWard 6*8,22*8,10*8,23*8
}
void bobsgame_CITYHospitalSoftRoom3_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

	static NPC* softroom_npc = NULL;
	if(softroom_npc==NULL)
	{
		NPC_create_npc_xy_feet(&softroom_npc,GFX_ADULT_hospitaldirector,16,40,5*8,15*8);
		//NPC_create_random_ADULT_xy_feet(&softroom_npc,8*8,15*8);
		softroom_npc->layer=2;
		softroom_npc->non_walkable=1;
		NPC_animate_stand_dir(&softroom_npc,LEFT);
	}
	if(softroom_npc!=NULL)
	{
		//if(NPC_in_range_of_npc_amt(&PLAYER_npc,softroom_npc,30))NPC_stare_at_npc(&softroom_npc,PLAYER_npc);
		//else NPC_animate_set_direction_now(&softroom_npc, LEFT);
		NPC_dont_look_at_npc(&softroom_npc,&PLAYER_npc);
		if(ACTION_npc(&softroom_npc,"Talk To Hospital Director"))
		{
			TEXT_set_sprite_window(0,softroom_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}

	if(walking_into_door(RANGE_CITYHospitalSoftRoom3ToPsychiatricWard))
	{
		MAP_change_map(MAP_bobsgame_CITYHospitalPsychiatricWard,36,10);return;
	}
}
void bobsgame_CITYHospitalSoftRoom3_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYHospitalSoftRoom3_Map_VBL_Function()
{

}
void bobsgame_CITYHospitalSoftRoom3_Map_HBL_Function()
{

}
//========================================================
//CITYHospitalMaternityWard
//========================================================
void bobsgame_CITYHospitalMaternityWard_Map_Load_Function()
{
//RANGE_CITYHospitalMaternityWardToElevator 56*8,19*8,62*8,20*8
//RANGE_CITYHospitalMaternityWardToElevator2 71*8,19*8,77*8,20*8
//RANGE_CITYHospitalMaternityWardToInfirmary 4*8,36*8,8*8,37*8
}
void bobsgame_CITYHospitalMaternityWard_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

	static NPC* maternitynurse_npc = NULL;
	if(maternitynurse_npc==NULL)
	{
		NPC_create_npc_xy_feet(&maternitynurse_npc,GFX_ADULT_nurse,16,40,64*8,36*8);
		//NPC_create_random_ADULT_xy_feet(&maternitynurse_npc,11*8,34*8);
		maternitynurse_npc->layer=2;
		maternitynurse_npc->non_walkable=1;
		NPC_animate_stand_dir(&maternitynurse_npc,RIGHT);
		maternitynurse_npc->walking_speed = SPEED_NORMAL;
		maternitynurse_npc->AI=0;
	}
	if(maternitynurse_npc!=NULL)
	{
		if(NPC_in_range_of_area_xyxy_in_direction_by_amount(&PLAYER_npc,60*8,31*8,76*8,34*8,PLAYER_npc->anim_dir,0))
		{
			if(NPC_walk_to_xy_nohit(&maternitynurse_npc,maternitynurse_npc->walking_speed, 66*8,36*8)==1)NPC_animate_stand_dir(&maternitynurse_npc,UP);
		}
		else
		if(NPC_in_range_of_area_xyxy_in_direction_by_amount(&PLAYER_npc,55*8,35*8,61*8,40*8,PLAYER_npc->anim_dir,0))
		{
			if(NPC_walk_to_xy_nohit(&maternitynurse_npc,maternitynurse_npc->walking_speed, 61*8,36*8)==1)NPC_animate_stand_dir(&maternitynurse_npc,LEFT);
		}
		else if(maternitynurse_npc->AI== 0){if(NPC_walk_to_xy_nohit(&maternitynurse_npc,maternitynurse_npc->walking_speed,75*8,36*8)==1){maternitynurse_npc->AI=3;maternitynurse_npc->vbls=r(60);NPC_animate_stand_dir(&maternitynurse_npc,UP);}}
		else if(maternitynurse_npc->AI== 1){if(NPC_walk_to_xy_nohit(&maternitynurse_npc,maternitynurse_npc->walking_speed,67*8,36*8)==1){maternitynurse_npc->AI=3;maternitynurse_npc->vbls=r(60);NPC_animate_stand_dir(&maternitynurse_npc,UP);}}
		else if(maternitynurse_npc->AI== 2){if(NPC_walk_to_xy_nohit(&maternitynurse_npc,maternitynurse_npc->walking_speed,61*8,36*8)==1){maternitynurse_npc->AI=3;maternitynurse_npc->vbls=r(60);NPC_animate_stand_dir(&maternitynurse_npc,UP);}}
		else if(maternitynurse_npc->AI== 3){if(maternitynurse_npc->vbls>120){maternitynurse_npc->vbls=0;maternitynurse_npc->AI=r(3);}}
		if(ACTION_range_xy_xy(58*8,33*8,77*8,40*8,"Talk To Maternity Nurse"))
		{
			TEXT_set_sprite_window(0,maternitynurse_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
//18,42 up
//20,42 up
//24,42 up
//30
//32
//36
	static NPC* waitingdads_npcs[6] = {NULL,NULL,NULL,NULL,NULL,NULL};
	int c=0;
	for(c=0;c<6;c++)
	{
		if(waitingdads_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			int dir=UP;
			int bgp=2;
			//int* gfx=NULL;
			if(c== 0){x=18*8;y=42*8;dir=UP;}
			if(c== 1){x=20*8;y=42*8;dir=UP;}
			if(c== 2){x=24*8;y=42*8;dir=UP;}
			if(c== 3){x=30*8;y=42*8;dir=UP;}
			if(c== 4){x=32*8;y=42*8;dir=UP;}
			if(c== 5){x=36*8;y=42*8;dir=UP;}
			NPC_create_random_ADULT_xy_feet(&waitingdads_npcs[c],x,y);

			//NPC_create_npc_xy_feet(&waitingdads_npcs[c],gfx,16,40,x,(y));
			NPC_animate_stand_dir(&waitingdads_npcs[c], dir);
			waitingdads_npcs[c]->non_walkable=1;
			waitingdads_npcs[c]->walk_dir=dir;
			waitingdads_npcs[c]->layer=bgp;
			//NPC_animate_increment_direction_frame_now(&waitingdads_npcs[c], dir);
		}
		if(waitingdads_npcs[c]!=NULL)
		{
			if(waitingdads_npcs[c]->AI==0){if(waitingdads_npcs[c]->vbls>200){if(r(3)==0){waitingdads_npcs[c]->AI=1+r(3);}else{waitingdads_npcs[c]->vbls=0;NPC_animate_stand_dir(&waitingdads_npcs[c], waitingdads_npcs[c]->walk_dir);if(waitingdads_npcs[c]->anim_frame_count!=0){waitingdads_npcs[c]->anim_frame_count=3;NPC_animate(&waitingdads_npcs[c]);}}}}
			if(waitingdads_npcs[c]->AI==1){if(waitingdads_npcs[c]->walk_dir==UP||waitingdads_npcs[c]->walk_dir==DOWN)NPC_animate_stand_dir(&waitingdads_npcs[c],LEFT);else NPC_animate_stand_dir(&waitingdads_npcs[c],UP);waitingdads_npcs[c]->vbls=r(120);waitingdads_npcs[c]->AI=0;}
			if(waitingdads_npcs[c]->AI==2){if(waitingdads_npcs[c]->walk_dir==UP||waitingdads_npcs[c]->walk_dir==DOWN)NPC_animate_stand_dir(&waitingdads_npcs[c],RIGHT);else NPC_animate_stand_dir(&waitingdads_npcs[c],DOWN);waitingdads_npcs[c]->vbls=r(120);waitingdads_npcs[c]->AI=0;}
			if(waitingdads_npcs[c]->AI==3){NPC_animate(&waitingdads_npcs[c]);waitingdads_npcs[c]->vbls=r(120);waitingdads_npcs[c]->AI=0;}
			//if(NPC_in_range_of_npc_amt(&PLAYER_npc,waitingdads_npcs[c],15))NPC_stare_at_npc(&waitingdads_npcs[c],PLAYER_npc);
			//else NPC_animate_set_direction_now(&waitingdads_npcs[c], waitingdads_npcs[c]->walking_direction);
		}
	}

	if(walking_into_door(RANGE_CITYHospitalMaternityWardToElevator))
	{
		MAP_change_map(MAP_bobsgame_CITYHospitalElevator,7,18);return;
	}
	if(walking_into_door(RANGE_CITYHospitalMaternityWardToElevator2))
	{
		MAP_change_map(MAP_bobsgame_CITYHospitalElevator2,7,18);return;
	}
	if(walking_into_door(RANGE_CITYHospitalMaternityWardToInfirmary))
	{
		MAP_change_map(MAP_bobsgame_CITYHospitalMaternityWardInfirmary,6,25);return;
	}
}
void bobsgame_CITYHospitalMaternityWard_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYHospitalMaternityWard_Map_VBL_Function()
{

}
void bobsgame_CITYHospitalMaternityWard_Map_HBL_Function()
{

}
//========================================================
//CITYHospitalMaternityWardInfirmary
//========================================================
void bobsgame_CITYHospitalMaternityWardInfirmary_Map_Load_Function()
{
//RANGE_CITYHospitalMaternityWardInfimaryToMaternityWard 4*8,26*8,8*8,27*8
}
void bobsgame_CITYHospitalMaternityWardInfirmary_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}
	static NPC* babynurse_npc = NULL;
	if(babynurse_npc==NULL)
	{
		NPC_create_npc_xy_feet(&babynurse_npc,GFX_ADULT_nurse,16,40,12*8,20*8);
		//NPC_create_random_ADULT_xy_feet(&babynurse_npc,17*8,15*8);
		babynurse_npc->layer=2;
		babynurse_npc->non_walkable=1;
		NPC_animate_stand_dir(&babynurse_npc,LEFT);
	}
	if(babynurse_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&babynurse_npc,20))NPC_stare_at_npc(&babynurse_npc,&PLAYER_npc);
		//else NPC_animate_set_direction_now(&babynurse_npc, LEFT);
		else if(babynurse_npc->AI== 0){if(NPC_walk_to_xy_nohit_pushmain(&babynurse_npc,SPEED_NORMAL,	16*8,13*8)==1){NPC_animate_stand_dir(&babynurse_npc,UP);babynurse_npc->vbls=r(40);babynurse_npc->AI++;}}
		else if(babynurse_npc->AI== 1){if(babynurse_npc->vbls>120)babynurse_npc->AI++;}
		else if(babynurse_npc->AI== 2){if(NPC_walk_to_xy_nohit_pushmain(&babynurse_npc,SPEED_NORMAL,  20*8,17*8)==1){NPC_animate_stand_dir(&babynurse_npc,DOWN);babynurse_npc->vbls=r(40);babynurse_npc->AI++;}}
		else if(babynurse_npc->AI== 3){if(babynurse_npc->vbls>120)babynurse_npc->AI++;}
		else if(babynurse_npc->AI== 4){if(NPC_walk_to_xy_nohit_pushmain(&babynurse_npc,SPEED_NORMAL,	27*8,13*8)==1){NPC_animate_stand_dir(&babynurse_npc,UP);babynurse_npc->vbls=r(40);babynurse_npc->AI++;}}
		else if(babynurse_npc->AI== 5){if(babynurse_npc->vbls>120)babynurse_npc->AI++;}
		else if(babynurse_npc->AI== 6){if(NPC_walk_to_xy_nohit_pushmain(&babynurse_npc,SPEED_NORMAL,  31*8,17*8)==1){NPC_animate_stand_dir(&babynurse_npc,DOWN);babynurse_npc->vbls=r(40);babynurse_npc->AI++;}}
		else if(babynurse_npc->AI== 7){if(babynurse_npc->vbls>120)babynurse_npc->AI++;}
		else if(babynurse_npc->AI== 8){if(NPC_walk_to_xy_nohit_pushmain(&babynurse_npc,SPEED_NORMAL,	34*8,17*8)==1){NPC_animate_stand_dir(&babynurse_npc,DOWN);babynurse_npc->vbls=r(40);babynurse_npc->AI++;}}
		else if(babynurse_npc->AI== 9){if(babynurse_npc->vbls>120)babynurse_npc->AI++;}
		else if(babynurse_npc->AI==10){if(NPC_walk_to_xy_nohit_pushmain(&babynurse_npc,SPEED_SLOWEST*2, 41*8,15*8)==1){NPC_animate_stand_dir(&babynurse_npc,UP);babynurse_npc->vbls=r(40);babynurse_npc->AI++;}}
		else if(babynurse_npc->AI==11){if(babynurse_npc->vbls>120)babynurse_npc->AI++;}
		else if(babynurse_npc->AI==12){if(NPC_walk_to_xy_nohit_pushmain(&babynurse_npc,SPEED_FASTER,	 5*8,14*8)==1){NPC_animate_stand_dir(&babynurse_npc,LEFT);babynurse_npc->vbls=r(40);babynurse_npc->AI++;}}
		else if(babynurse_npc->AI==13){if(babynurse_npc->vbls>120)babynurse_npc->AI++;}
		else if(babynurse_npc->AI==14){if(NPC_walk_to_xy_nohit_pushmain(&babynurse_npc,SPEED_NORMAL,	12*8,14*8)==1){NPC_animate_stand_dir(&babynurse_npc,UP);babynurse_npc->vbls=r(40);babynurse_npc->AI++;}}
		else if(babynurse_npc->AI==15){if(NPC_walk_to_xy_nohit_pushmain(&babynurse_npc,SPEED_NORMAL,	12*8,18*8)==1){NPC_animate_stand_dir(&babynurse_npc,LEFT);babynurse_npc->vbls=r(40);babynurse_npc->AI++;}}
		else if(babynurse_npc->AI==16){if(babynurse_npc->vbls>120)babynurse_npc->AI=0;}

		if(ACTION_npc(&babynurse_npc,"Talk To Baby Nurse"))
		{
			TEXT_set_sprite_window(0,babynurse_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
	//TODO: demon child 40-43,12
	//need to change gfx
	if(walking_into_door(RANGE_CITYHospitalMaternityWardInfimaryToMaternityWard))
	{
		MAP_change_map(MAP_bobsgame_CITYHospitalMaternityWard,6,37);return;
	}
}
void bobsgame_CITYHospitalMaternityWardInfirmary_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYHospitalMaternityWardInfirmary_Map_VBL_Function()
{

}
void bobsgame_CITYHospitalMaternityWardInfirmary_Map_HBL_Function()
{

}
//========================================================
//CITYHospitalEmergencyEntrance
//========================================================
void bobsgame_CITYHospitalEmergencyEntrance_Map_Load_Function()
{

}
void bobsgame_CITYHospitalEmergencyEntrance_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//TODO: used for opening scene
//maybe i should combine this with the entrance :| i'd have to change uh... elevator tile, coming in from city tile, the clerk tiles and the visitor tiles. all one amount though.

}
void bobsgame_CITYHospitalEmergencyEntrance_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYHospitalEmergencyEntrance_Map_VBL_Function()
{

}
void bobsgame_CITYHospitalEmergencyEntrance_Map_HBL_Function()
{

}
//========================================================
//CITYHospitalMorgue
//========================================================
void bobsgame_CITYHospitalMorgue_Map_Load_Function()
{
//RANGE_CITYHospitalMorgueToElevator 56*8,19*8,62*8,20*8
//RANGE_CITYHospitalMorgueToElevator2 71*8,19*8,77*8,20*8
}
void bobsgame_CITYHospitalMorgue_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}
//TODO: need corpse sprite
//need more sick, hospital gown people. people with iv's

//alien
//22,30 face down
//37,30
	static NPC* deadalien_npc = NULL;
	if(deadalien_npc==NULL)
	{
		NPC_create_npc_xy_feet(&deadalien_npc,GFX_ADULT_alien,16,40,21*8+4,33*8);
		//NPC_create_random_ADULT_xy_feet(&deadalien_npc,11*8,34*8);
		deadalien_npc->layer=1;
		deadalien_npc->non_walkable=1;
		NPC_animate_stand_dir(&deadalien_npc,DOWN);
		deadalien_npc->walking_speed = SPEED_NORMAL;
		deadalien_npc->AI=0;
	}
	if(deadalien_npc!=NULL)
	{
		if(ACTION_range_xy_xy(20*8,30*8,23*8,36*8,"Communicate Telepathically"))
		{
			TEXT_set_sprite_window(0,deadalien_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
	static NPC* corpse_npc = NULL;
	if(corpse_npc==NULL)
	{
		NPC_create_npc_xy_feet(&corpse_npc,GFX_ADULT_diseased,16,40,36*8+4,33*8);
		//NPC_create_random_ADULT_xy_feet(&corpse_npc,11*8,34*8);
		corpse_npc->layer=1;
		corpse_npc->non_walkable=1;
		NPC_animate_stand_dir(&corpse_npc,DOWN);
		corpse_npc->walking_speed = SPEED_NORMAL;
		corpse_npc->AI=0;
	}
	if(corpse_npc!=NULL)
	{
		if(ACTION_range_xy_xy(35*8,30*8,38*8,36*8,"Call Forth The Spirits"))
		{
			TEXT_set_sprite_window(0,corpse_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}

//7,34
//18 35 face right
//18,40
//32 40
//33 35 right
//33 38
//36 37 up
//36 40
	static NPC* morguedoc_npc = NULL;
	if(morguedoc_npc==NULL)
	{
		NPC_create_npc_xy_feet(&morguedoc_npc,GFX_ADULT_madscientist,16,40,7*8,35*8);
		//NPC_create_random_ADULT_xy_feet(&morguedoc_npc,17*8,15*8);
		morguedoc_npc->layer=2;
		morguedoc_npc->non_walkable=1;
		NPC_animate_stand_dir(&morguedoc_npc,LEFT);
	}
	if(morguedoc_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&morguedoc_npc,15))NPC_stare_at_npc(&morguedoc_npc,&PLAYER_npc);
		//else NPC_animate_set_direction_now(&morguedoc_npc, LEFT);
		else if(morguedoc_npc->AI== 0){if(NPC_walk_to_xy_nohit_pushmain(&morguedoc_npc,SPEED_NORMAL,	18*8,35*8)==1){NPC_animate_stand_dir(&morguedoc_npc,RIGHT);morguedoc_npc->vbls=r(40);morguedoc_npc->AI++;}}
		else if(morguedoc_npc->AI== 1){if(morguedoc_npc->vbls>120)morguedoc_npc->AI++;}
		else if(morguedoc_npc->AI== 2){if(NPC_walk_to_xy_nohit_pushmain(&morguedoc_npc,SPEED_NORMAL,  18*8,40*8)==1){morguedoc_npc->vbls=r(40);morguedoc_npc->AI++;}}
		else if(morguedoc_npc->AI== 3){if(NPC_walk_to_xy_nohit_pushmain(&morguedoc_npc,SPEED_NORMAL,	32*8,40*8)==1){morguedoc_npc->vbls=r(40);morguedoc_npc->AI++;}}
		else if(morguedoc_npc->AI== 4){if(NPC_walk_to_xy_nohit_pushmain(&morguedoc_npc,SPEED_NORMAL,  33*8,35*8)==1){NPC_animate_stand_dir(&morguedoc_npc,RIGHT);morguedoc_npc->vbls=r(40);morguedoc_npc->AI++;}}
		else if(morguedoc_npc->AI== 5){if(morguedoc_npc->vbls>120)morguedoc_npc->AI++;}
		else if(morguedoc_npc->AI== 6){if(NPC_walk_to_xy_nohit_pushmain(&morguedoc_npc,SPEED_NORMAL,	33*8,38*8)==1){morguedoc_npc->vbls=r(40);morguedoc_npc->AI++;}}
		else if(morguedoc_npc->AI== 7){if(NPC_walk_to_xy_nohit_pushmain(&morguedoc_npc,SPEED_NORMAL,  36*8,37*8)==1){NPC_animate_stand_dir(&morguedoc_npc,UP);morguedoc_npc->vbls=r(40);morguedoc_npc->AI++;}}
		else if(morguedoc_npc->AI== 8){if(morguedoc_npc->vbls>120)morguedoc_npc->AI++;}
		else if(morguedoc_npc->AI== 9){if(NPC_walk_to_xy_nohit_pushmain(&morguedoc_npc,SPEED_NORMAL,	36*8,40*8)==1){morguedoc_npc->vbls=r(40);morguedoc_npc->AI++;}}
		else if(morguedoc_npc->AI==10){if(NPC_walk_to_xy_nohit_pushmain(&morguedoc_npc,SPEED_NORMAL,	18*8,40*8)==1){morguedoc_npc->vbls=r(40);morguedoc_npc->AI++;}}
		else if(morguedoc_npc->AI==11){if(NPC_walk_to_xy_nohit_pushmain(&morguedoc_npc,SPEED_NORMAL,	14*8,30*8)==1){NPC_animate_stand_dir(&morguedoc_npc,UP);morguedoc_npc->vbls=r(40);morguedoc_npc->AI++;}}
		else if(morguedoc_npc->AI==12){if(morguedoc_npc->vbls>120)morguedoc_npc->AI=0;}

		if(ACTION_npc(&morguedoc_npc,"Talk To Mad Scientist"))
		{
			TEXT_set_sprite_window(0,morguedoc_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
	//TODO: need death ray

	if(walking_into_door(RANGE_CITYHospitalMorgueToElevator))
	{
		MAP_change_map(MAP_bobsgame_CITYHospitalElevator,7,18);return;
	}
	if(walking_into_door(RANGE_CITYHospitalMorgueToElevator2))
	{
		MAP_change_map(MAP_bobsgame_CITYHospitalElevator2,7,18);return;
	}
}
void bobsgame_CITYHospitalMorgue_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYHospitalMorgue_Map_VBL_Function()
{

}
void bobsgame_CITYHospitalMorgue_Map_HBL_Function()
{

}



