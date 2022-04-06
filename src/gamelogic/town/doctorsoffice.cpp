//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================



#include "../../main.h"


#define RANGE_TOWNDoctorsOfficeEntranceToOutside 4*8,29*8,8*8,30*8
#define RANGE_TOWNDoctorsOfficeEntranceToDoctorsOfficeBackHall 4*8,10*8,8*8,11*8
#define RANGE_TOWNDoctorsOfficeBackHallToDoctorsOfficeEntrance 4*8,29*8,8*8,30*8
#define RANGE_TOWNDoctorsOfficeBackHallToDoctorsOfficeBackRoom 5*8,10*8,9*8,11*8
#define RANGE_TOWNDoctorsOfficeBackRoomToDoctorsOfficeBackHall 5*8,24*8,9*8,25*8


//========================================================
//TOWNDoctorsOfficeEntrance
//========================================================
void bobsgame_TOWNDoctorsOfficeEntrance_Map_Load_Function()
{
//RANGE_TOWNDoctorsOfficeEntranceToOutside 4*8,29*8,8*8,30*8
//RANGE_TOWNDoctorsOfficeEntranceToDoctorsOfficeBackHall 4*8,10*8,8*8,11*8
}

void bobsgame_TOWNDoctorsOfficeEntrance_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//TODO: fish in fish tank
//receptionist 16,7, under 3, down
	static NPC* receptionist_npc = NULL;
	if(receptionist_npc==NULL)
	{
		NPC_create_npc_xy_feet(&receptionist_npc,GFX_ADULT_nurse,16,40,17*8,8*8-3);
		receptionist_npc->non_walkable=1;
		receptionist_npc->layer=3;
		NPC_animate_stand_dir(&receptionist_npc, DOWN);
	}
	else if(receptionist_npc!=NULL)
	{
		if(ACTION_range_xy_xy(15*8,9*8,19*8,11*8,"Make Appointment"))
		{
			TEXT_set_sprite_window(0,receptionist_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}


	//patients
//14,26 up
//18,26 up
//22,26 up
//26,26 up
//17,22 left
//17,18 left
//20,20 right
//20,22 right
//30,18 left
//30,22 left
	static NPC* patients_npcs[10] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	int c=0;
	for(c=0;c<10;c++)
	{
		if(patients_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			int dir=UP;
			int bgp=2;
			if(c== 0){x=14*8;y=27*8-4;dir=UP;}
			if(c== 1){x=18*8;y=27*8-4;dir=UP;}
			if(c== 2){x=22*8;y=27*8-4;dir=UP;}
			if(c== 3){x=26*8;y=27*8-4;dir=UP;}
			if(c== 4){x=17*8;y=18*8;dir=LEFT;}
			if(c== 5){x=17*8;y=22*8-4;dir=LEFT;}
			if(c== 6){x=21*8;y=20*8;dir=RIGHT;}
			if(c== 7){x=21*8;y=22*8-4;dir=RIGHT;}
			if(c== 8){x=30*8;y=18*8;dir=LEFT;}
			if(c== 9){x=30*8;y=22*8-4;dir=LEFT;}
			NPC_create_random_ADULT_xy_feet(&patients_npcs[c],x,(y)+3);
			NPC_animate_stand_dir(&patients_npcs[c], dir);
			patients_npcs[c]->non_walkable=1;
			patients_npcs[c]->layer=bgp;
		}
		else if(patients_npcs[c]!=NULL)
		{
			//if(NPC_in_range_of_npc_amt(&PLAYER_npc,patients_npcs[c],16))NPC_stare_at_npc(&patients_npcs[c],PLAYER_npc);
			//else NPC_animate_set_direction_now(&patients_npcs[c], UP);
			//if(ACTION_npc(&patients_npcs[c],"Talk To Patient"))
			//{
			//	TEXT_set_sprite_window(0,patients_npcs[c],NULL);
			//	TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			//	if(c==0)TEXT_window("");
			//}
		}
	}
	if(walking_into_door(RANGE_TOWNDoctorsOfficeEntranceToOutside))
	{
		MAP_change_map(MAP_bobsgame_TOWNTown,402,300);return;
	}
	if(walking_into_door(RANGE_TOWNDoctorsOfficeEntranceToDoctorsOfficeBackHall))
	{
		MAP_change_map(MAP_bobsgame_TOWNDoctorsOfficeBackHall,6,28);return;
	}
}
void bobsgame_TOWNDoctorsOfficeEntrance_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_TOWNDoctorsOfficeEntrance_Map_VBL_Function()
{

}

void bobsgame_TOWNDoctorsOfficeEntrance_Map_HBL_Function()
{

}

//========================================================
//TOWNDoctorsOfficeBackHall
//========================================================
void bobsgame_TOWNDoctorsOfficeBackHall_Map_Load_Function()
{
//RANGE_TOWNDoctorsOfficeBackHallToDoctorsOfficeEntrance 4*8,29*8,8*8,30*8
//RANGE_TOWNDoctorsOfficeBackHallToDoctorsOfficeBackRoom 5*8,10*8,9*8,11*8
}

void bobsgame_TOWNDoctorsOfficeBackHall_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//16,24 down
//23,18 down
//10,20-10,25 talk to
	static NPC* receptionist_npc = NULL;
	if(receptionist_npc==NULL)
	{
		NPC_create_npc_xy_feet(&receptionist_npc,GFX_ADULT_nurse,16,40,15*8,23*8);
		receptionist_npc->non_walkable=1;
		receptionist_npc->layer=1;
		NPC_animate_stand_dir(&receptionist_npc, DOWN);
	}
	else if(receptionist_npc!=NULL)
	{
		if(ACTION_range_xy_xy(10*8,20*8,11*8,25*8,"Talk To Nurse"))
		{
			TEXT_set_sprite_window(0,receptionist_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
	static NPC* receptionist2_npc = NULL;
	if(receptionist2_npc==NULL)
	{
		NPC_create_npc_xy_feet(&receptionist2_npc,GFX_ADULT_nurse,16,40,22*8,17*8);
		receptionist2_npc->non_walkable=1;
		receptionist2_npc->layer=2;
		NPC_animate_stand_dir(&receptionist2_npc, DOWN);
	}
	else if(receptionist2_npc!=NULL)
	{

	}
	if(walking_into_door(RANGE_TOWNDoctorsOfficeBackHallToDoctorsOfficeEntrance))
	{
		MAP_change_map(MAP_bobsgame_TOWNDoctorsOfficeEntrance,6,11);return;
	}
	if(walking_into_door(RANGE_TOWNDoctorsOfficeBackHallToDoctorsOfficeBackRoom))
	{
		MAP_change_map(MAP_bobsgame_TOWNDoctorsOfficeBackRoom,7,23);return;
	}
}
void bobsgame_TOWNDoctorsOfficeBackHall_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_TOWNDoctorsOfficeBackHall_Map_VBL_Function()
{

}

void bobsgame_TOWNDoctorsOfficeBackHall_Map_HBL_Function()
{

}

//========================================================
//TOWNDoctorsOfficeBackRoom
//========================================================
void bobsgame_TOWNDoctorsOfficeBackRoom_Map_Load_Function()
{
//RANGE_TOWNDoctorsOfficeBackRoomToDoctorsOfficeBackHall 5*8,24*8,9*8,25*8
}

void bobsgame_TOWNDoctorsOfficeBackRoom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//20,15-24,24 sit in bed
//doctor at 18,20 face down
//22,22 lay down
	static NPC* doctor_npc = NULL;
	if(doctor_npc==NULL)
	{
		NPC_create_npc_xy_feet(&doctor_npc,GFX_ADULT_familydoctordentist,16,40,18*8,19*8);
		doctor_npc->non_walkable=1;
		//doctor_npc->layer=1;
		NPC_animate_stand_dir(&doctor_npc, DOWN);
	}
	else if(doctor_npc!=NULL)
	{
		if(ACTION_npc(&doctor_npc,"What's Up, Doc?"))
		{
			TEXT_set_sprite_window(0,doctor_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("Very funny. Could I have Yuu lay down and take his shirt off?<.>"
			"<1>Why do I need to take off my shirt?<.>"
			"<0>Don't ask foolish questions."
			);
		}
	}
	if(ACTION_range_xy_xy(20*8,16*8,24*8,24*8,"Lay Down"))
	{
		//TODO: move sprite to 22,22 down
		//use shirtless animation
		//doctor gets up, moves next to table
			TEXT_set_sprite_window(0,doctor_npc,NULL);
		TEXT_set_sprite_window(1,PLAYER_npc,NULL);
		TEXT_window("Ah, hmm. I see. I see.<.>"
		"<1>What is it, doc? Is it bad? I can take it!<.>"
		"<0>I suppose I should just tell Yuu. Are you prepared for a great shock?<.>"
		"<1>I'm scared. Don't tell me.<.>"
		"<0>Yuu is going to die.<.>"
		"<1>*sob*<.>"
		"I knew it. How much time do I have left? Can I spend one last day with my family?<.>"
		"<0>Let's see, Yuu is 12? Probably about 60 years left, on average.<.>"
		"*chuckle*<.>"
		"<1>That's horrible.<.>"
		"<0>Don't worry. Just a little doctor humor.<.>"
		"To be honest, Yuu appears to have an untreatable form of mental illness, though I'm not a specialist in that field.<.>"
		"Yuu might already be seeing symptoms of it.<.>"
		"For instance, does Yuu ever feel like people are speaking about Yuu in third person, or talking in a strange context?<.>"
		"Or perhaps Yuu feels that his actions are controlled by some unknown outside force?<.>"
		"Yuu might be speaking out uncontrollably, or talking to himself, or hearing voices.<.>"
		"These are the usual signs of psychosis. Nothing to worry about.<.>"
		"Yuu can live out the rest of his life quite comfortably in a nice soft bed.<.>"
		"See? That doesn't sound so bad now, does it?<.>"
		"<1>That's worse than before! Tell me you're joking!<.>"
		"<0>*chuckle*<.>"
		"Maybe, maybe not.<.>"
		"Now if Yuu could excuse me, this is a proctology examination center, not a pediatric clinic.<.>"
		"Unless...<.>"
		"<1>I'm leaving.<.>"
		"<0>That will be $10,000. Please see the receptionist on the way out.<.>"
		"I hope Yuu has insurance.<.>"
		"*chuckle*"
		);
	}
	if(walking_into_door(RANGE_TOWNDoctorsOfficeBackRoomToDoctorsOfficeBackHall))
	{
		MAP_change_map(MAP_bobsgame_TOWNDoctorsOfficeBackHall,7,11);return;
	}
}
void bobsgame_TOWNDoctorsOfficeBackRoom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_TOWNDoctorsOfficeBackRoom_Map_VBL_Function()
{

}

void bobsgame_TOWNDoctorsOfficeBackRoom_Map_HBL_Function()
{

}


