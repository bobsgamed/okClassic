//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================

#include "../../main.h"



#define RANGE_CITYBankEntranceToOUTSIDECity 34*8,42*8,42*8,43*8
#define RANGE_CITYBankEntranceToBankElevator 62*8,19*8,68*8,20*8
#define RANGE_CITYBankElevatorToSelectedFloor 5*8,19*8,11*8,20*8
#define RANGE_CITYBankOwnerOfficeToBankElevator 62*8,19*8,68*8,20*8


//========================================================
//CITYBankEntrance
//========================================================
void bobsgame_CITYBankEntrance_Map_Load_Function()
{
//RANGE_CITYBankEntranceToOUTSIDECity 34*8,42*8,42*8,43*8
//RANGE_CITYBankEntranceToBankElevator 62*8,19*8,68*8,20*8
}
void bobsgame_CITYBankEntrance_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}
//63,35 face left cust service
//46 14 down teller
//38 14 down
//30 14 down
//22 19
//14
//5
//38 42 door to 35,32 5,32 5,26 33,26 33,23
//tellers
//6,19 14,19 22,19 30,19 38,19
	static NPC* teller1_npc = NULL;
	if(teller1_npc==NULL)
	{
		NPC_create_npc_xy_feet(&teller1_npc,GFX_ADULT_businesswoman,16,40,5*8,15*8);
		teller1_npc->layer=3;
		NPC_animate_stand_dir(&teller1_npc, DOWN);
	}
	else if(teller1_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&teller1_npc,30))NPC_stare_at_npc(&teller1_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&teller1_npc, DOWN);
		if(ACTION_range_xy_xy(3*8,18*8,7*8,19*8,"Talk To Suzanne"))
		{
			TEXT_set_sprite_window(0,teller1_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
	static NPC* teller2_npc = NULL;
	if(teller2_npc==NULL)
	{
		NPC_create_npc_xy_feet(&teller2_npc,GFX_ADULT_businesswoman,16,40,38*8,15*8);
		teller2_npc->layer=3;
		NPC_animate_stand_dir(&teller2_npc, DOWN);
	}
	else if(teller2_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&teller2_npc,30))NPC_stare_at_npc(&teller2_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&teller2_npc, DOWN);
		if(ACTION_range_xy_xy(36*8,18*8,40*8,19*8,"Talk To Diane"))
		{
			TEXT_set_sprite_window(0,teller2_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
	static NPC* teller3_npc = NULL;
	if(teller3_npc==NULL)
	{
		NPC_create_npc_xy_feet(&teller3_npc,GFX_ADULT_businesswoman,16,40,30*8,15*8);
		teller3_npc->layer=3;
		NPC_animate_stand_dir(&teller3_npc, DOWN);
	}
	else if(teller3_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&teller3_npc,30))NPC_stare_at_npc(&teller3_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&teller3_npc, DOWN);
		if(ACTION_range_xy_xy(28*8,18*8,32*8,19*8,"Talk To Tina"))
		{
			TEXT_set_sprite_window(0,teller3_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
	static NPC* teller4_npc = NULL;
	if(teller4_npc==NULL)
	{
		NPC_create_npc_xy_feet(&teller4_npc,GFX_ADULT_businesswoman,16,40,22*8,15*8);
		teller4_npc->layer=3;
		NPC_animate_stand_dir(&teller4_npc, DOWN);
	}
	else if(teller4_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&teller4_npc,30))NPC_stare_at_npc(&teller4_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&teller4_npc, DOWN);
		if(ACTION_range_xy_xy(20*8,18*8,24*8,19*8,"Talk To Barbara"))
		{
			TEXT_set_sprite_window(0,teller4_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
	static NPC* teller5_npc = NULL;
	if(teller5_npc==NULL)
	{
		NPC_create_npc_xy_feet(&teller5_npc,GFX_ADULT_businesswoman,16,40,14*8,15*8);
		teller5_npc->layer=3;
		NPC_animate_stand_dir(&teller5_npc, DOWN);
	}
	else if(teller5_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&teller5_npc,30))NPC_stare_at_npc(&teller5_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&teller5_npc, DOWN);
		if(ACTION_range_xy_xy(12*8,18*8,16*8,19*8,"Talk To Cheryl"))
		{
			TEXT_set_sprite_window(0,teller5_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}

	static NPC* loanrep_npc = NULL;
	if(loanrep_npc==NULL)
	{
		NPC_create_npc_xy_feet(&loanrep_npc,GFX_ADULT_businessguy,16,40,63*8+5,35*8);
		loanrep_npc->layer=1;
		NPC_animate_stand_dir(&loanrep_npc,LEFT);
		NPC_animate_dir(&loanrep_npc,LEFT);
	}
	else if(loanrep_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&loanrep_npc,30))NPC_stare_at_npc(&loanrep_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&loanrep_npc, LEFT);
		if(ACTION_range_xy_xy(58*8,35*8,56*8,38*8,"Talk To Loan Specialist"))
		{
			TEXT_set_sprite_window(0,loanrep_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
			//TODO: sit down in chair
			//TRY TO GET A LOAN. get thrown out?
		}
	}
	static NPC* security_npc = NULL;
	if(security_npc==NULL)
	{
		NPC_create_npc_xy_feet(&security_npc,GFX_ADULT_securityguard,16,40,34*8,31*8);
		security_npc->layer=1;
		NPC_animate_stand_dir(&security_npc,DOWN);
	}
	else if(security_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&security_npc,30))NPC_stare_at_npc(&security_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&security_npc, DOWN);
		if(ACTION_npc(&security_npc,"Talk To Security Guard"))
		{
			TEXT_set_sprite_window(0,security_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}
	static int spotused[5]={0,0,0,0,0};
	static int randnum=0;
	static NPC* line_npcs[20] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	int c=0;
	for(c=0;c<10;c++)
	{
		if(line_npcs[c]==NULL&&CLOCK_second/10==c%6)
		{
			NPC_create_random_ADULT_xy_feet(&line_npcs[c],38*8,41*8);
			line_npcs[c]->non_walkable=1;
			line_npcs[c]->AI=1;
			line_npcs[c]->walking_speed=SPEED_NORMAL+r(SPEED_SLOW-SPEED_FASTEST);
			line_npcs[c]->ignore_fx_layer=1;
			NPC_animate_stand_dir(&line_npcs[c], UP);
		}
		if(line_npcs[c]!=NULL)
		{
			if(line_npcs[c]->AI== 1)if(NPC_walk_to_xy_nohit_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 29*8,36*8)==(1))line_npcs[c]->AI++;
			if(line_npcs[c]->AI== 2)if(NPC_walk_to_xy_intelligenthit_stopforothers_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 29*8,31*8)==(1))line_npcs[c]->AI++;
			if(line_npcs[c]->AI== 3)if(NPC_walk_to_xy_intelligenthit_stopforothers_pushmain(&line_npcs[c],line_npcs[c]->walking_speed,  7*8,31*8)==(1))line_npcs[c]->AI++;
			if(line_npcs[c]->AI== 4)if(NPC_walk_to_xy_intelligenthit_stopforothers_pushmain(&line_npcs[c],line_npcs[c]->walking_speed,  7*8,26*8)==(1))line_npcs[c]->AI++;
			if(line_npcs[c]->AI== 5)if(NPC_walk_to_xy_intelligenthit_stopforothers_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 30*8,26*8)==(1))line_npcs[c]->AI++;
			if(line_npcs[c]->AI== 6)if(NPC_walk_to_xy_intelligenthit_stopforothers_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 31*8,21*8)==(1))line_npcs[c]->AI++;
			if(line_npcs[c]->AI== 7){randnum=(r(6));line_npcs[c]->vbls=0;if(spotused[randnum]==0){line_npcs[c]->AI+=randnum+1;spotused[randnum]=1;}}
			if(line_npcs[c]->AI== 8)if(line_npcs[c]->vbls>60){line_npcs[c]->AI+=5;}
			if(line_npcs[c]->AI== 9)if(line_npcs[c]->vbls>60){line_npcs[c]->AI+=5;}
			if(line_npcs[c]->AI==10)if(line_npcs[c]->vbls>60){line_npcs[c]->AI+=5;}
			if(line_npcs[c]->AI==11)if(line_npcs[c]->vbls>60){line_npcs[c]->AI+=5;}
			if(line_npcs[c]->AI==12)if(line_npcs[c]->vbls>60){line_npcs[c]->AI+=5;}
			//walk to open spot
			if(line_npcs[c]->AI==13)if(NPC_walk_to_xy_nohit_pushmain(&line_npcs[c],line_npcs[c]->walking_speed,  6*8,19*8)==(1)){line_npcs[c]->AI+=5;line_npcs[c]->vbls=0;NPC_animate_stand_dir(&line_npcs[c], UP);}
			if(line_npcs[c]->AI==14)if(NPC_walk_to_xy_nohit_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 14*8,19*8)==(1)){line_npcs[c]->AI+=5;line_npcs[c]->vbls=0;NPC_animate_stand_dir(&line_npcs[c], UP);}
			if(line_npcs[c]->AI==15)if(NPC_walk_to_xy_nohit_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 22*8,19*8)==(1)){line_npcs[c]->AI+=5;line_npcs[c]->vbls=0;NPC_animate_stand_dir(&line_npcs[c], UP);}
			if(line_npcs[c]->AI==16)if(NPC_walk_to_xy_nohit_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 30*8,19*8)==(1)){line_npcs[c]->AI+=5;line_npcs[c]->vbls=0;NPC_animate_stand_dir(&line_npcs[c], UP);}
			if(line_npcs[c]->AI==17)if(NPC_walk_to_xy_nohit_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 38*8,19*8)==(1)){line_npcs[c]->AI+=5;line_npcs[c]->vbls=0;NPC_animate_stand_dir(&line_npcs[c], UP);}
			//stand for awhile, then open up spot
			if(line_npcs[c]->AI==18)if(line_npcs[c]->vbls>200){line_npcs[c]->AI+=5;spotused[0]=0;}
			if(line_npcs[c]->AI==19)if(line_npcs[c]->vbls>200){line_npcs[c]->AI+=5;spotused[1]=0;}
			if(line_npcs[c]->AI==20)if(line_npcs[c]->vbls>200){line_npcs[c]->AI+=5;spotused[2]=0;}
			if(line_npcs[c]->AI==21)if(line_npcs[c]->vbls>200){line_npcs[c]->AI+=5;spotused[3]=0;}
			if(line_npcs[c]->AI==22)if(line_npcs[c]->vbls>200){line_npcs[c]->AI+=5;spotused[4]=0;}
			//walk to tray
			if(line_npcs[c]->AI==23)if(NPC_walk_to_xy_nohit_pushmain(&line_npcs[c],line_npcs[c]->walking_speed,  6*8,21*8)==(1)){line_npcs[c]->AI+=5;line_npcs[c]->vbls=0;}
			if(line_npcs[c]->AI==24)if(NPC_walk_to_xy_nohit_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 14*8,21*8)==(1)){line_npcs[c]->AI+=4;line_npcs[c]->vbls=0;}
			if(line_npcs[c]->AI==25)if(NPC_walk_to_xy_nohit_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 22*8,21*8)==(1)){line_npcs[c]->AI+=3;line_npcs[c]->vbls=0;}
			if(line_npcs[c]->AI==26)if(NPC_walk_to_xy_nohit_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 30*8,21*8)==(1)){line_npcs[c]->AI+=2;line_npcs[c]->vbls=0;}
			if(line_npcs[c]->AI==27)if(NPC_walk_to_xy_nohit_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 38*8,21*8)==(1)){line_npcs[c]->AI+=1;line_npcs[c]->vbls=0;}
			if(line_npcs[c]->AI==28)if(NPC_walk_to_xy_nohit_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 3*8,21*8)==(1)){line_npcs[c]->AI++;line_npcs[c]->vbls=0;}
			if(line_npcs[c]->AI==29)if(NPC_walk_to_xy_nohit_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 3*8,39*8)==(1)){line_npcs[c]->AI++;line_npcs[c]->vbls=0;}
			if(line_npcs[c]->AI==30)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&line_npcs[c],line_npcs[c]->walking_speed, 36*8,41*8)==(1)){NPC_delete_npc(&line_npcs[c]);}
		}
	}
	if(walking_into_door(RANGE_CITYBankEntranceToOUTSIDECity))
	{
		MAP_change_map(MAP_bobsgame_CITYCity,1445,33);return;
	}
	if(walking_into_door(RANGE_CITYBankEntranceToBankElevator))
	{
		MAP_change_map(MAP_bobsgame_CITYBankElevator,7,18);return;
	}
}
void bobsgame_CITYBankEntrance_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYBankEntrance_Map_VBL_Function()
{

}
void bobsgame_CITYBankEntrance_Map_HBL_Function()
{

}
//========================================================
//CITYBankElevator
//========================================================
void bobsgame_CITYBankElevator_Map_Load_Function()
{
//RANGE_CITYBankElevatorToSelectedFloor 5*8,19*8,11*8,20*8
}
void bobsgame_CITYBankElevator_Map_Run_Function(int MAP_just_loaded)
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
		TEXT_window("Which floor?<Q:Entrance 1F:Bank President 2F>"
		);
	}
	//if selected floor cant leave while animating
	if(strcmp(TEXTANSWER_selected_answer_string,"Entrance 1F")==0&&floor!=0){floor=0;door_locked=1;animate=1;}
	if(strcmp(TEXTANSWER_selected_answer_string,"Bank President 2F")==0&&floor!=1){floor=1;door_locked=1;animate=1;}
	//if animation done, ding sound
	if(animate==1)
	{
		//TODO: screen shake
		//ding
		HARDWARE_play_sound("elevatording",127,44100,0);
		door_locked=0;
		animate=0;
	}
	if(walking_into_door(RANGE_CITYBankElevatorToSelectedFloor)&&door_locked==0)
	{
		//change to selected floor
		if(floor==0){MAP_change_map(MAP_bobsgame_CITYBankEntrance,64,20);return;}
		if(floor==1){MAP_change_map(MAP_bobsgame_CITYBankOwnerOffice,64,20);return;}
	}
}
void bobsgame_CITYBankElevator_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYBankElevator_Map_VBL_Function()
{

}
void bobsgame_CITYBankElevator_Map_HBL_Function()
{

}
//========================================================
//CITYBankOwnerOffice
//========================================================
void bobsgame_CITYBankOwnerOffice_Map_Load_Function()
{
//RANGE_CITYBankOwnerOfficeToBankElevator 62*8,19*8,68*8,20*8
}
void bobsgame_CITYBankOwnerOffice_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}
//secretary 49.36 face up
//talk to  48-52, 33-34
	static NPC* banksecretary_npc = NULL;
	if(banksecretary_npc==NULL)
	{
		NPC_create_npc_xy_feet(&banksecretary_npc,GFX_ADULT_secretary,16,40,50*8,36*8);
		banksecretary_npc->layer=3;
		NPC_animate_stand_dir(&banksecretary_npc,UP);
	}
	else if(banksecretary_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&banksecretary_npc,30))NPC_stare_at_npc(&banksecretary_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&banksecretary_npc, UP);
		if(ACTION_range_xy_xy(48*8,33*8,52*8,34*8,"Talk To Secretary"))
		{
			TEXT_set_sprite_window(0,banksecretary_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
			//TODO: need phone ringing a lot if you get close
		}
	}

//bigwig face right 16, 32
//talk to 21, 30-36

	static NPC* bigwig_npc = NULL;
	if(bigwig_npc==NULL)
	{
		NPC_create_npc_xy_feet(&bigwig_npc,GFX_ADULT_bigwig,16,40,16*8,32*8);
		bigwig_npc->layer=3;
		NPC_animate_stand_dir(&bigwig_npc,RIGHT);
	}
	else if(bigwig_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&bigwig_npc,30))NPC_stare_at_npc(&bigwig_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&bigwig_npc, RIGHT);
		if(ACTION_range_xy_xy(20*8,30*8,21*8,36*8,"Talk To Bank President"))
		{
			TEXT_set_sprite_window(0,bigwig_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}//TODO: sit in chair
	}

	//TODO: big tv showing news.

	if(walking_into_door(RANGE_CITYBankOwnerOfficeToBankElevator))
	{
		MAP_change_map(MAP_bobsgame_CITYBankElevator,7,18);return;
	}
}
void bobsgame_CITYBankOwnerOffice_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_CITYBankOwnerOffice_Map_VBL_Function()
{

}
void bobsgame_CITYBankOwnerOffice_Map_HBL_Function()
{

}

