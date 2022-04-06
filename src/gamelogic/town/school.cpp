//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================





#include "../../main.h"


#define RANGE_SCHOOLMainOfficeToEntranceHallway 14*8,27*8,22*8,28*8
#define RANGE_SCHOOLMainOfficeToPrincipalsOffice 1*8,13*8,2*8,17*8
#define RANGE_SCHOOLPrincipalsOfficeToMainOffice 26*8,12*8,27*8,16*8
#define RANGE_SCHOOLDetentionToEntranceHallway 9*8,27*8,13*8,28*8
#define RANGE_SCHOOLClinicToEntranceHallway 29*8,27*8,33*8,28*8
#define RANGE_SCHOOLClinicToClinicBathroom 4*8,18*8,8*8,19*8
#define RANGE_SCHOOLClinicBathroomToClinic 4*8,17*8,8*8,18*8
#define RANGE_SCHOOLTeachersLoungeToEntranceHallway 13*8,27*8,21*8,28*8
#define RANGE_SCHOOLMusicRoomToGymHallway 19*8,39*8,23*8,40*8
#define RANGE_SCHOOLArtRoomToGymHallway 19*8,39*8,23*8,40*8
#define RANGE_SCHOOLComputerLabToGymHallway 19*8,39*8,23*8,40*8
#define RANGE_SCHOOLKitchenToGymHallway 7*8,39*8,11*8,40*8
#define RANGE_SCHOOLLibraryToClassHallway 18*8,39*8,26*8,40*8
#define RANGE_SCHOOLCustodianToBackHallway 4*8,44*8,8*8,45*8
#define RANGE_SCHOOLCustodianToOUTSIDERoof 12*8,6*8,16*8,7*8
#define RANGE_SCHOOLGirlsBathroomToBackHallway 9*8,39*8,13*8,40*8
#define RANGE_SCHOOLBoysBathroomToBackHallway 9*8,39*8,13*8,40*8
#define RANGE_SCHOOLEntranceHallwayToOUTSIDEPlayground1 7*8,41*8,15*8,42*8
#define RANGE_SCHOOLEntranceHallwayToOUTSIDEPlayground2 106*8,41*8,114*8,42*8
#define RANGE_SCHOOLEntranceHallwayToOUTSIDE1 143*8,49*8,149*8,50*8
#define RANGE_SCHOOLEntranceHallwayToOUTSIDE2 152*8,49*8,158*8,50*8
#define RANGE_SCHOOLEntranceHallwayToOUTSIDE3 161*8,49*8,167*8,50*8
#define RANGE_SCHOOLEntranceHallwayToGymHallwayLeft 7*8,10*8,15*8,11*8
#define RANGE_SCHOOLEntranceHallwayToTeachersLounge 30*8,26*8,38*8,27*8
#define RANGE_SCHOOLEntranceHallwayToClinic 85*8,26*8,89*8,27*8
#define RANGE_SCHOOLEntranceHallwayToMainOffice 151*8,26*8,159*8,27*8
#define RANGE_SCHOOLEntranceHallwayToDetention 174*8,26*8,178*8,27*8
#define RANGE_SCHOOLEntranceHallwayToGymCafeteria 193*8,10*8,201*8,11*8
#define RANGE_SCHOOLEntranceHallwayToGymHallwayMiddle 100*8,10*8,108*8,11*8
#define RANGE_SCHOOLGymHallwayToEntranceHallwayLeft 7*8,53*8,15*8,54*8
#define RANGE_SCHOOLGymHallwayToEntranceHallwayMiddle 100*8,53*8,108*8,54*8
#define RANGE_SCHOOLGymHallwayToClassHallwayLeft 7*8,10*8,15*8,11*8
#define RANGE_SCHOOLGymHallwayToMusicRoom 38*8,38*8,42*8,39*8
#define RANGE_SCHOOLGymHallwayToArtRoom 78*8,38*8,82*8,39*8
#define RANGE_SCHOOLGymHallwayToComputerLab 118*8,38*8,122*8,39*8
#define RANGE_SCHOOLGymHallwayToKitchen 146*8,38*8,150*8,39*8
#define RANGE_SCHOOLGymHallwayToGymCafeteria 156*8,44*8,157*8,49*8
#define RANGE_SCHOOLClassHallwayToGymHallwayLeft 7*8,53*8,15*8,54*8
#define RANGE_SCHOOLClassHallwayToBackHallwayLeft 7*8,10*8,15*8,11*8
#define RANGE_SCHOOLClassHallwayToLibrary 37*8,38*8,45*8,39*8
#define RANGE_SCHOOLClassHallwayToClassroom4 86*8,38*8,90*8,39*8
#define RANGE_SCHOOLClassHallwayToClassroom5 126*8,38*8,130*8,39*8
#define RANGE_SCHOOLClassHallwayToClassroom6 166*8,38*8,170*8,39*8
#define RANGE_SCHOOLClassHallwayToGymCafeteria 193*8,53*8,201*8,54*8
#define RANGE_SCHOOLClassHallwayToBackHallwayRight 193*8,10*8,201*8,11*8
#define RANGE_SCHOOLBackHallwayToClassHallwayLeft 7*8,53*8,15*8,54*8
#define RANGE_SCHOOLBackHallwayToClassHallwayRight 193*8,53*8,201*8,54*8
#define RANGE_SCHOOLBackHallwayToCustodian 4*8,38*8,8*8,39*8
#define RANGE_SCHOOLBackHallwayToClassroom3 36*8,38*8,40*8,39*8
#define RANGE_SCHOOLBackHallwayToClassroom2 76*8,38*8,80*8,39*8
#define RANGE_SCHOOLBackHallwayToClassroom1 147*8,38*8,151*8,39*8
#define RANGE_SCHOOLBackHallwayToGirlsBathroom 176*8,38*8,180*8,39*8
#define RANGE_SCHOOLBackHallwayToBoysBathroom 195*8,38*8,199*8,39*8
#define RANGE_SCHOOLBackHallwayToOUTSIDEPlayground1 103*8,11*8,111*8,12*8
#define RANGE_SCHOOLBackHallwayToOUTSIDEPlayground2 115*8,11*8,123*8,12*8
#define RANGE_SCHOOLClassroom1ToBackHallway 20*8,39*8,24*8,40*8
#define RANGE_SCHOOLClassroom2ToBackHallway 20*8,39*8,24*8,40*8
#define RANGE_SCHOOLClassroom3ToBackHallway 20*8,39*8,24*8,40*8
#define RANGE_SCHOOLClassroom4ToClassHallway 20*8,39*8,24*8,40*8
#define RANGE_SCHOOLClassroom5ToClassHallway 20*8,39*8,24*8,40*8
#define RANGE_SCHOOLClassroom6ToClassHallway 20*8,39*8,24*8,40*8
#define RANGE_SCHOOLGymCafeteriaToClassHallway 38*8,10*8,46*8,11*8
#define RANGE_SCHOOLGymCafeteriaToEntranceHallway 38*8,53*8,46*8,54*8
#define RANGE_SCHOOLGymCafeteriaToGymHallway 1*8,39*8,2*8,44*8
#define RANGE_SCHOOLGymGymToClassHallway 38*8,10*8,46*8,11*8
#define RANGE_SCHOOLGymGymToEntranceHallway 38*8,53*8,46*8,54*8
#define RANGE_SCHOOLGymGymToGymHallway 1*8,39*8,2*8,46*8


//========================================================
//SCHOOLMainOffice
//========================================================
void bobsgame_SCHOOLMainOffice_Map_Load_Function()
{
//RANGE_SCHOOLMainOfficeToEntranceHallway 14*8,27*8,22*8,28*8
//RANGE_SCHOOLMainOfficeToPrincipalsOffice 1*8,13*8,2*8,17*8
}

void bobsgame_SCHOOLMainOffice_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//secretary here. feet at 17.16
//tiles 17,13-18,15 from layer 1 to 2
//talk to desk at 17-18,20
	static NPC* secretary_npc = NULL;
		static int office_cycle=0; //save. also save whether had principal meeting.
	//TODO: handle generic office action. secretary asks if yuu needs help. not allowed in principals office.
	if(secretary_npc==NULL)
	{
		NPC_create_npc_xy_feet(&secretary_npc,GFX_ADULT_secretary,16,40,18*8,16*8);
		secretary_npc->non_walkable=1;
		///TODO: MUST FIX THIS!!!
		///HARDWARE_set_map_tile(1,2,17,13,HARDWARE_map_1[HARDWARE_map_width_tiles*13+17]);	//sitting in front of left chair
		///HARDWARE_set_map_tile(1,2,18,13,HARDWARE_map_1[HARDWARE_map_width_tiles*13+18]);
		///HARDWARE_set_map_tile(1,2,17,14,HARDWARE_map_1[HARDWARE_map_width_tiles*14+17]);
		///HARDWARE_set_map_tile(1,2,18,14,HARDWARE_map_1[HARDWARE_map_width_tiles*14+18]);
		///HARDWARE_set_map_tile(1,2,17,15,HARDWARE_map_1[HARDWARE_map_width_tiles*15+17]);
		///HARDWARE_set_map_tile(1,2,18,15,HARDWARE_map_1[HARDWARE_map_width_tiles*15+18]);
		///HARDWARE_set_map_tile(1,1,17,13,0);
		///HARDWARE_set_map_tile(1,1,18,13,0);
		///HARDWARE_set_map_tile(1,1,17,14,0);
		///HARDWARE_set_map_tile(1,1,18,14,0);
		///HARDWARE_set_map_tile(1,1,17,15,0);
		///HARDWARE_set_map_tile(1,1,18,15,0);
	}
	if(secretary_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&secretary_npc,30))NPC_stare_at_npc(&secretary_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&secretary_npc, DOWN);
		if(office_cycle==0)
			if(ACTION_range_xy_xy(16*8,19*8,19*8,20*8,"Talk To Secretary"))
			{
				TEXT_set_sprite_window(0,secretary_npc,NULL);
				TEXT_set_sprite_window(1,PLAYER_npc,NULL);
				TEXT_window("<NOCANCEL>Can I help Yuu?<.>"
				"<1>They just said my name over the P.A.<.>"
				"<0>Ah, yes. Can I have Yuu's name, please?<.>"
				"<1>...<.>"
				"<0>Oh, right. I remember now. Yuu is *THAT* one.<.>"
				"*smirk*<.>"
				"Go right ahead and have a seat, and we'll be right with Yuu.<.>"
				"<1>Oh, is there already a meeting?<.>"
				"<0>That's none of Yuu's business, young man.<.>"
				"And for Yuu's information, no, I just feel like giving orders.<.>"
				"*smile*<.>"
				"<1>..."
				);
				office_cycle=1;
			}
		if(office_cycle==1)
			if(ACTION_range_xy_xy(8*8,19*8,10*8,21*8,"Sit Down"))
			{
				TEXT_set_sprite_window(0,secretary_npc,NULL);
				TEXT_set_sprite_window(1,PLAYER_npc,NULL);
				TEXT_window("<NOCANCEL>Excuse me, sir?<.>"
				"<1>Yes?<.>"
				"<0>The principal can see Yuu now, go ahead.<.>"
				"<1>...<.>"
				"<0>If I could just have Yuu's name...<.>"
				"<1>It's \"Yuu\".<.>"
				"<0>*snort*<.>"
				"<SMALL><GRAY>Stupid kid.<.>"
				"<NORMAL><WHITE><1>What?<.>"
				"<0>Nothing, thanks. Go on in. *chuckle*"
				);
				office_cycle=2;
			}
	}
		if(walking_into_door(RANGE_SCHOOLMainOfficeToEntranceHallway)&&(office_cycle==3||office_cycle==0))
	{
		MAP_change_map(MAP_bobsgame_SCHOOLEntranceHallway,154,27);return;
	}
		if(office_cycle!=3&&office_cycle!=0)
		if(ACTION_range_xy_xy(RANGE_SCHOOLMainOfficeToEntranceHallway,"Leave Office"))
		{
			TEXT_set_sprite_window(0,secretary_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("Just a minute, sir.");
		}
		if(office_cycle==0)
		if(ACTION_range_xy_xy(RANGE_SCHOOLMainOfficeToPrincipalsOffice,"Go In Principal's Office"))
		{
			TEXT_set_sprite_window(0,secretary_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("Can I help Yuu, sir?");
		}
	if(office_cycle==1)
		if(ACTION_range_xy_xy(RANGE_SCHOOLMainOfficeToPrincipalsOffice,"Go In Principal's Office"))
		{
			TEXT_set_sprite_window(0,secretary_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("Have a seat, sir.");
		}
		if(walking_into_door(RANGE_SCHOOLMainOfficeToPrincipalsOffice)&&office_cycle==2)
	{
		office_cycle=3;
		MAP_change_map(MAP_bobsgame_SCHOOLPrincipalsOffice,24,15);return;
	}
}
void bobsgame_SCHOOLMainOffice_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_SCHOOLMainOffice_Map_VBL_Function()
{

}

void bobsgame_SCHOOLMainOffice_Map_HBL_Function()
{

}

//========================================================
//SCHOOLPrincipalsOffice
//========================================================
void bobsgame_SCHOOLPrincipalsOffice_Map_Load_Function()
{
//RANGE_SCHOOLPrincipalsOfficeToMainOffice 26*8,12*8,27*8,16*8
}

void bobsgame_SCHOOLPrincipalsOffice_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//principal at 9,19 xy feet over layer 1 facing right
//talk to desk at 14,18-20
//chair at 17-18,19
	static NPC* principal_npc = NULL;
	if(principal_npc==NULL)
	{
		NPC_create_npc_xy_feet(&principal_npc,GFX_ADULT_principal,16,40,(9*8)+2,19*8);
		principal_npc->non_walkable=1;
		principal_npc->layer=1;
		NPC_animate_stand_dir(&principal_npc, RIGHT);
		NPC_animate_dir(&principal_npc,RIGHT);
	}
	if(principal_npc!=NULL)
	{
			static int principal_cycle=0;
			if(principal_cycle==0)
			if(ACTION_npc(&principal_npc,"Talk To Principal"))
			{
				TEXT_set_sprite_window(0,principal_npc,NULL);
				TEXT_set_sprite_window(1,PLAYER_npc,NULL);
				TEXT_window("Could Yuu please take a seat? We're going to have a nice discussion.<.>A \"pleasant chat\" if Yuu will.");
			}
			if(principal_cycle==0)
			if(ACTION_range_xy_xy(17*8,19*8,19*8,20*8,"Sit In Chair"))
			{
				//sit in chair, face left.
				principal_cycle=1;
				GLOBAL_main_sprite_input_off=1;
				GLOBAL_main_sprite_standing=1;
				PLAYER_npc->MAP_x=(17*8)-4;
				PLAYER_npc->MAP_y=(16*8)-4;
				NPC_animate_stand_dir(&PLAYER_npc, LEFT);
				LETTERBOX_init(64,1);
				CAPTION_make_caption(NULL, 1, 128, 40, 8, "The PrinciPal", FONT_BOB_ID, RED, CLEAR,1,1);
				TEXT_set_sprite_window(0,principal_npc,NULL);
				TEXT_set_sprite_window(1,PLAYER_npc,NULL);
				TEXT_window("<NOCANCEL>So, young man, I've heard quite a few stories about Yuu.<.>"
				"Does Yuu have any explanation for his recent behavior?<.>"
				"<1>I'm not sure what you're talking about. Have I done something wrong?<.>"
				"<0>*cough*<.>"
				"I guess we have to take this one step at a time.<.>"
				"I've got all day, Yuu knows. We'll get to the bottom of this.<.>"
				"<1>The bottom of what? I'm really not sure what you're talking about.<.>"
				"<0>Oh, I see. Yuu seems to have suffered a convenient bout of amnesia.<.>"
				"We'll just go right ahead and play Yuu's little game, if that's what he wants.<.>"
				"<1>No, seriously. Is it about my homework?<.>"
				"<0>Ah, playing innocent. Not going to work. Try again, my deviant friend.<.>"
				"<1>Hmm..<.>Oh, is it my hair? It's naturally like this, I really can't help it.<.>"
				"<0>What? Look, I don't have time for this.<.>"
				"<1>I thought you said you had all day. Do you have to use the bathroom? I'll wait.<.>"
				"<0>...<.>"
				"Look, Yuu little brat, we've all heard the stories about your so-called \"adventures.\" Always poking your nose into places Yuu doesn't belong.<.>"
				"Getting into everyone else's business, always there to lend a \"helping hand.\"<.>"
				"All of a sudden, showing up with just the right tool for job.<.>"
				"Then every time Yuu gets involved, disaster strikes.. \"Accidentally,\" of course.<.>"
				"Yuu expects us to believe it's just some kind of coincidence?<.>"
				"Yuu thinks we're stupid or something?<.>"
				);
				//TODO: puzzle fight
				//TODO: get janitor key
				//TODO: access p.a.
			}
		if(principal_cycle==1&&GLOBAL_text_engine_state==0)
		{
			if(LETTERBOX_sprites_exist)LETTERBOX_deinit();
			GLOBAL_main_sprite_input_off=0;
			principal_cycle=2;
		}
	}
	if(walking_into_door(RANGE_SCHOOLPrincipalsOfficeToMainOffice))
	{
		MAP_change_map(MAP_bobsgame_SCHOOLMainOffice,2,15);return;
	}
}
void bobsgame_SCHOOLPrincipalsOffice_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_SCHOOLPrincipalsOffice_Map_VBL_Function()
{

}

void bobsgame_SCHOOLPrincipalsOffice_Map_HBL_Function()
{

}

//========================================================
//SCHOOLDetention
//========================================================
void bobsgame_SCHOOLDetention_Map_Load_Function()
{
//RANGE_SCHOOLDetentionToEntranceHallway 9*8,27*8,13*8,28*8
}

void bobsgame_SCHOOLDetention_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//hall monitor at 7,15 feet
//tiles at 7,14 8,14 7,13 8,13
	static NPC* hallmonitor_npc = NULL;
	if(hallmonitor_npc==NULL)
	{
		NPC_create_npc_xy_feet(&hallmonitor_npc,GFX_ADULT_hallmonitor,16,40,7*8,14*8);
		hallmonitor_npc->non_walkable=1;

		///TODO: MUST FIX THIS!!!
		///HARDWARE_set_map_tile(1,2,6,11,HARDWARE_map_1[HARDWARE_map_width_tiles*11+6]);	//sitting in front of left chair
		///HARDWARE_set_map_tile(1,2,7,11,HARDWARE_map_1[HARDWARE_map_width_tiles*11+7]);
		///HARDWARE_set_map_tile(1,2,6,12,HARDWARE_map_1[HARDWARE_map_width_tiles*12+6]);
		///HARDWARE_set_map_tile(1,2,7,12,HARDWARE_map_1[HARDWARE_map_width_tiles*12+7]);
		///HARDWARE_set_map_tile(1,2,6,13,HARDWARE_map_1[HARDWARE_map_width_tiles*13+6]);
		///HARDWARE_set_map_tile(1,2,7,13,HARDWARE_map_1[HARDWARE_map_width_tiles*13+7]);
		///HARDWARE_set_map_tile(1,1,6,11,0);
		///HARDWARE_set_map_tile(1,1,7,11,0);
		///HARDWARE_set_map_tile(1,1,6,12,0);
		///HARDWARE_set_map_tile(1,1,7,12,0);
		///HARDWARE_set_map_tile(1,1,6,13,0);
		///HARDWARE_set_map_tile(1,1,7,13,0);
	}
	if(hallmonitor_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&hallmonitor_npc,30))NPC_stare_at_npc(&hallmonitor_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&hallmonitor_npc, DOWN);
		if(ACTION_npc(&hallmonitor_npc,"Talk To Hall Monitor"))
		{
			TEXT_set_sprite_window(0,hallmonitor_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("Well, well, well.<.>"
			"What a surprise. Never thought I'd see Yuu here.<.>"
			"*snicker*<.>"
			"Have a seat. I'm going to enjoy every second of this.<.>"
			);
		}
		//TODO: take a seat, clock ticks for 30 minutes. 3 minutes realtime, thats not bad.
		//TODO: maybe show instructional video
	}
	if(walking_into_door(RANGE_SCHOOLDetentionToEntranceHallway))
	{
		MAP_change_map(MAP_bobsgame_SCHOOLEntranceHallway,176,27);return;
		//TODO: cant leave unless past 30 minutes.
	}
}
void bobsgame_SCHOOLDetention_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_SCHOOLDetention_Map_VBL_Function()
{

}

void bobsgame_SCHOOLDetention_Map_HBL_Function()
{

}

//========================================================
//SCHOOLClinic
//========================================================
void bobsgame_SCHOOLClinic_Map_Load_Function()
{
//RANGE_SCHOOLClinicToEntranceHallway 29*8,27*8,33*8,28*8
//RANGE_SCHOOLClinicToClinicBathroom 4*8,18*8,8*8,19*8
}

void bobsgame_SCHOOLClinic_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//nurse at desk at 29,17
//tiles at 29,16, 30,16  29,17, 30,17 from 1 to 2
//talk to nurse at 29-30,21, in front of desk
	static int allowed_in=0;
	static NPC* nurse_npc = NULL;
	if(nurse_npc==NULL)
	{
		NPC_create_npc_xy_feet(&nurse_npc,GFX_ADULT_nurse,16,40,29*8,(17*8)-4);
		nurse_npc->non_walkable=1;
		///TODO: MUST FIX THIS!!!
		///HARDWARE_set_map_tile(1,2,28,14,HARDWARE_map_1[HARDWARE_map_width_tiles*14+28]);	//sitting in front of left chair
		///HARDWARE_set_map_tile(1,2,29,14,HARDWARE_map_1[HARDWARE_map_width_tiles*14+29]);
		///HARDWARE_set_map_tile(1,2,28,15,HARDWARE_map_1[HARDWARE_map_width_tiles*15+28]);
		///HARDWARE_set_map_tile(1,2,29,15,HARDWARE_map_1[HARDWARE_map_width_tiles*15+29]);
		///HARDWARE_set_map_tile(1,1,28,14,0);
		///HARDWARE_set_map_tile(1,1,29,14,0);
		///HARDWARE_set_map_tile(1,1,28,15,0);
		///HARDWARE_set_map_tile(1,1,29,15,0);
	}
	if(nurse_npc!=NULL)
	{
		//look at you?
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&nurse_npc,30))NPC_stare_at_npc(&nurse_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&nurse_npc, DOWN);
		if(ACTION_range_xy_xy(28*8,20*8,31*8,21*8,"Talk To Nurse"))
		{
			TEXT_set_sprite_window(0,nurse_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("Well, hello sweetie! Is Yuu sick?<.>"
			"Yuu looks alright to me, is Yuu sure?<.>"
			"*chuckle* It's alright. Yuu don't fool me, but I don't mind.<.>"
			"If Yuu wants to skip a class or two, I'll play along.<.>"
			"Just go grab a hot washcloth and hold it to Yuu's forehead for a minute.<.>"
			"Or put the thermometer on a light bulb for a second when I'm not looking.<.>"
			"<1>I really do feel a bit ill. Can I lie down for a few minutes?<.>"
			"<0>Ohohoho. Sure, whatever Yuu wants. *wink*<.>"
			"<1>Alright then, can I get through?<.>"
			"<0>Tsk tsk tsk. Can't Yuu tell when someone is joking?<.>"
			"Yuu should know I can't let any fakers in here, what if I lose my job?<.>"
			"I'm already banned from the hospital for that silly lobotomy mixup.<.>"
			"Those Doctors just take everything, like, way too seriously, Yuu knows?<.>"
			"<1>I think I'm going to vomit.<.>"
			"<0>Ah, the finger down the throat trick won't work here. Find somewhere else to play hooky, cutie.<.>"
			);
			allowed_in=1;
			///HARDWARE_set_map_tile(1,2,21,18,0);//rope
			///HARDWARE_set_map_tile(1,2,22,18,0);
			///HARDWARE_set_map_tile(1,2,23,18,0);
			///HARDWARE_set_map_tile(1,2,24,18,0);
			///HARDWARE_set_map_tile(1,0,21,19,0);//shadow
			///HARDWARE_set_map_tile(1,0,22,19,0);
			///HARDWARE_set_map_tile(1,0,23,19,0);
			///HARDWARE_set_map_tile(1,0,24,19,0);
		}
	}
		if(allowed_in==0)
	{
		if(NPC_in_range_of_area_xyxy_in_direction_by_amount(&PLAYER_npc,21*8,19*8,25*8,20*8,UP,2))PLAYER_npc->MAP_y+=2;
	}
	//sick kids
	static NPC* sickkid1_npc = NULL;
	if(sickkid1_npc==NULL)
	{
		NPC_create_random_CHILD_xy_feet(&sickkid1_npc,17*8,(26*8)-4);
		sickkid1_npc->non_walkable=1;
	}
	if(sickkid1_npc!=NULL)
	{
		if(ACTION_range_xy_xy(14*8,23*8,18*8,24*8,"Talk To Unconscious Kid"))
		{
			TEXT_set_sprite_window(0,sickkid1_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("Shh. I'm supposed to be unconscious. I had to fake the bubonic plague to get in here, and let me tell Yuu, that wasn't easy.");
		}
	}
	//4,25 head, rotate 270
	static NPC* sickkid2_npc = NULL;
	if(sickkid2_npc==NULL)
	{
		NPC_create_random_CHILD_xy_feet(&sickkid2_npc,6*8,(25*8));
		sickkid2_npc->non_walkable=1;
		sickkid2_npc->layer=1;
	}
	if(sickkid2_npc!=NULL)
	{
		if(ACTION_npc(&sickkid2_npc,"Talk To Dead Kid"))
		{
			TEXT_set_sprite_window(0,sickkid2_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("Don't worry. I'm just playing dead. I nabbed some flour from the kitchen and put it on my face. The mexican pizzas were so delicious.");
		}
	}

	if(walking_into_door(RANGE_SCHOOLClinicToEntranceHallway))
	{
		MAP_change_map(MAP_bobsgame_SCHOOLEntranceHallway,87,27);return;
	}
	if(walking_into_door(RANGE_SCHOOLClinicToClinicBathroom))
	{
		MAP_change_map(MAP_bobsgame_SCHOOLClinicBathroom,6,16);return;
	}
}
void bobsgame_SCHOOLClinic_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_SCHOOLClinic_Map_VBL_Function()
{

}

void bobsgame_SCHOOLClinic_Map_HBL_Function()
{

}

//========================================================
//SCHOOLClinicBathroom
//========================================================
void bobsgame_SCHOOLClinicBathroom_Map_Load_Function()
{
//RANGE_SCHOOLClinicBathroomToClinic 4*8,17*8,8*8,18*8
}

void bobsgame_SCHOOLClinicBathroom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}
	if(walking_into_door(RANGE_SCHOOLClinicBathroomToClinic))
	{
		MAP_change_map(MAP_bobsgame_SCHOOLClinic,6,19);return;
	}
	//TODO: something in the trash can
}
void bobsgame_SCHOOLClinicBathroom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_SCHOOLClinicBathroom_Map_VBL_Function()
{

}

void bobsgame_SCHOOLClinicBathroom_Map_HBL_Function()
{

}

//========================================================
//SCHOOLTeachersLounge
//========================================================
void bobsgame_SCHOOLTeachersLounge_Map_Load_Function()
{
//RANGE_SCHOOLTeachersLoungeToEntranceHallway 13*8,27*8,21*8,28*8
}

void bobsgame_SCHOOLTeachersLounge_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

	//couch 31,16
	//couch 34,16 face down
	//couch 27-4,18 face right
	//couch 27-4,22 face right
	//table 17,16 face down, tiles 17-18,14 on layer 2
	//table 13,16 face down, tiles 13-14,14 on layer 2
	//table 9,16 face down, tiles 9-10,14 on layer 2
	//table 17,20 face up
	//table 13,20 face up
	//table 9,20 face up
	static NPC* givenupteacher_npc = NULL;
	static NPC* maleangryteacher_npc = NULL;
	static NPC* malesadteacher_npc = NULL;
	static NPC* femaleangryteacher_npc = NULL;
	static NPC* femalesadteacher_npc = NULL;
	static NPC* grannycluelessteacher_npc = NULL;
	static NPC* pcteacher_npc = NULL;
	static NPC* hallmonitor_npc = NULL;
	static NPC* nurse_npc 		= NULL;
	static NPC* secretary_npc = NULL;
	static NPC* librarian_npc = NULL;
	//couch down
	if(givenupteacher_npc==NULL){NPC_create_npc_xy_feet(&givenupteacher_npc,GFX_ADULT_givenupteacher,16,40,31*8,(16*8)-3);NPC_animate_stand_dir(&givenupteacher_npc, DOWN);}
	if(maleangryteacher_npc==NULL){NPC_create_npc_xy_feet(&maleangryteacher_npc,GFX_ADULT_maleangryteacher,16,40,(34*8)-1,(16*8)-3);NPC_animate_stand_dir(&maleangryteacher_npc, DOWN);}
	//couch right
	if(malesadteacher_npc==NULL){NPC_create_npc_xy_feet(&malesadteacher_npc,GFX_ADULT_malesadteacher,16,40,(27*8)+2,(18*8)-6);NPC_animate_stand_dir(&malesadteacher_npc, RIGHT);malesadteacher_npc->layer=1;}
	if(femaleangryteacher_npc==NULL){NPC_create_npc_xy_feet(&femaleangryteacher_npc,GFX_ADULT_femaleangryteacher,16,40,(27*8)+2,(22*8)-3);NPC_animate_stand_dir(&femaleangryteacher_npc, RIGHT);}
	//table top
	if(femalesadteacher_npc==NULL){NPC_create_npc_xy_feet(&femalesadteacher_npc,GFX_ADULT_femalesadteacher,16,40,18*8,(16*8)-5);NPC_animate_stand_dir(&femalesadteacher_npc, DOWN);}
	if(grannycluelessteacher_npc==NULL){NPC_create_npc_xy_feet(&grannycluelessteacher_npc,GFX_ADULT_grannycluelessteacher,16,40,14*8,(16*8)-5);NPC_animate_stand_dir(&grannycluelessteacher_npc, DOWN);}
	if(librarian_npc==NULL)
	{
		NPC_create_npc_xy_feet(&librarian_npc,GFX_ADULT_librarian,16,40,10*8,(16*8)-5);NPC_animate_stand_dir(&librarian_npc, DOWN);

		///TODO: MUST FIX THIS!
		///HARDWARE_set_map_tile(1,2,17,14,HARDWARE_map_1[HARDWARE_map_width_tiles*14+17]);	//top table chair tiles
		///HARDWARE_set_map_tile(1,2,18,14,HARDWARE_map_1[HARDWARE_map_width_tiles*14+18]);
		///HARDWARE_set_map_tile(1,2,13,14,HARDWARE_map_1[HARDWARE_map_width_tiles*14+13]);
		///HARDWARE_set_map_tile(1,2,14,14,HARDWARE_map_1[HARDWARE_map_width_tiles*14+14]);
		///HARDWARE_set_map_tile(1,2, 9,14,HARDWARE_map_1[HARDWARE_map_width_tiles*14+ 9]);
		///HARDWARE_set_map_tile(1,2,10,14,HARDWARE_map_1[HARDWARE_map_width_tiles*14+10]);
		///HARDWARE_set_map_tile(1,1,17,14,0);
		///HARDWARE_set_map_tile(1,1,18,14,0);
		///HARDWARE_set_map_tile(1,1,13,14,0);
		///HARDWARE_set_map_tile(1,1,14,14,0);
		///HARDWARE_set_map_tile(1,1, 9,14,0);
		///HARDWARE_set_map_tile(1,1,10,14,0);
	}
	//by back wall
	if(pcteacher_npc==NULL){NPC_create_npc_xy_feet(&pcteacher_npc,GFX_ADULT_pcteacher,16,40,7*8,(13*8));NPC_animate_stand_dir(&pcteacher_npc, DOWN);}
	//table bottom
	if(hallmonitor_npc==NULL)	{NPC_create_npc_xy_feet(&hallmonitor_npc,GFX_ADULT_hallmonitor,16,40,18*8,(20*8));NPC_animate_stand_dir(&hallmonitor_npc, UP);hallmonitor_npc->layer=3;}
	if(nurse_npc==NULL)			{NPC_create_npc_xy_feet(&nurse_npc,GFX_ADULT_nurse,16,40,14*8,(20*8));			NPC_animate_stand_dir(&nurse_npc, UP);		nurse_npc->layer=3;}
	if(secretary_npc==NULL)		{NPC_create_npc_xy_feet(&secretary_npc,GFX_ADULT_secretary,16,40,10*8,(20*8));		NPC_animate_stand_dir(&secretary_npc, UP);	secretary_npc->layer=3;}
	//TODO: hide in closet or something, conversation between all of the teachers about you
	if(walking_into_door(RANGE_SCHOOLTeachersLoungeToEntranceHallway))
	{
		MAP_change_map(MAP_bobsgame_SCHOOLEntranceHallway,34,27);return;
	}
}
void bobsgame_SCHOOLTeachersLounge_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_SCHOOLTeachersLounge_Map_VBL_Function()
{

}

void bobsgame_SCHOOLTeachersLounge_Map_HBL_Function()
{

}

//========================================================
//SCHOOLMusicRoom
//========================================================
void bobsgame_SCHOOLMusicRoom_Map_Load_Function()
{
//RANGE_SCHOOLMusicRoomToGymHallway 19*8,39*8,23*8,40*8
}

void bobsgame_SCHOOLMusicRoom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

	static NPC* musicteacher_npc = NULL;
	if(musicteacher_npc==NULL)
	{
		NPC_create_npc_xy_feet(&musicteacher_npc,GFX_ADULT_femaleangryteacher,16,40,23*8,20*8);
		musicteacher_npc->non_walkable=1;
		musicteacher_npc->pushable=1;
	}
	if(musicteacher_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&musicteacher_npc,30))NPC_stare_at_npc(&musicteacher_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&musicteacher_npc, DOWN);
		if(ACTION_npc(&musicteacher_npc,"Talk To Music Teacher"))
		{
			TEXT_set_sprite_window(0,musicteacher_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("Okay now, listen up. Music is a strict discipline.<.>"
			"It might seem at first like it's meant to be fun, but that's a grave mistake that many beginners make.<.>"
			"Music is a painful struggle of constant effort to the road of perfection.<.>"
			"The notion that a person can just pick up an instrument and enjoy figuring out how to make pleasant noises is a foolish blunder.<.>"
			"Years of studying technical notation and careful finger placement exercises must be diligently followed before even a single grubby finger can touch so much as a tamborine.<.>"
			"Now, are Yuu serious about this, or aren't Yuu?<.>"
			"<1>I guess not.. I just wanted to try..<.>"
			"<0>That's what I thought. Here's your triangle.<.>"
			"<1>Don't I get the thing to make it ring?<.>"
			"<0>*chuckle* Don't make me laugh. Yuu can have that after Yuu've mastered the difference between an allegro and presto sixteenth.");
		}
	}
//kids in chairs
	//9,29
	//13,29
	//17,29
	//21,29
	//25,29
	//29,29
	//33,29
	//11,23
	//15,23
	//19,23
	//23,23
	//27,23
	//31,23
		static NPC* classkids_npcs[15] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	int c=0;
	for(c=0;c<15;c++)
	{
		if(classkids_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			GFX* gfx=NULL;
			if(c== 0){x=12;y=28;gfx=GFX_KID_pudgyboy;}
			if(c== 1){x=15;y=28;gfx=GFX_KID_nerdboy;}
			if(c== 2){x=18;y=28;gfx=GFX_KID_uglyboy;}
			if(c== 3){x=22;y=28;gfx=GFX_KID_nerdgirl;}
			if(c== 4){x=26;y=28;gfx=GFX_KID_punkboy;}
			if(c== 5){x=28;y=28;gfx=GFX_KID_emoboy;}
			if(c== 6){x=33;y=28;gfx=GFX_KID_emogirl;}
			if(c== 7){x=11;y=22;gfx=GFX_KID_uglygirl;}
			if(c== 8){x=14;y=22;gfx=GFX_KID_pudgygirl;}
			if(c== 9){x=17;y=22;gfx=GFX_KID_conceitedgirl;}
			if(c==10){x=20;y=22;gfx=GFX_KID_notfriend;}
			if(c==12){x=27;y=22;gfx=GFX_KID_bully;}
			if(c==13){x=30;y=22;gfx=GFX_KID_jockboy;}
			if(c==14){x=33;y=22;gfx=GFX_KID_greaserboy;}

			if(gfx!=NULL)
			{
				NPC_create_npc_xy_feet(&classkids_npcs[c],gfx,16,32,x*8,(y*8)+3);
				NPC_animate_stand_dir(&classkids_npcs[c], UP);
				classkids_npcs[c]->layer=3;
			}
		}
		if(classkids_npcs[c]!=NULL)
		{
			if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&classkids_npcs[c],30))NPC_stare_at_npc(&classkids_npcs[c],&PLAYER_npc);
			else NPC_animate_stand_dir(&classkids_npcs[c], UP);
		}
	}
	if(ACTION_range_xy_xy(23*8,22*8,24*8,24*8,"Sit In Chair"))
	{
		//TODO: sit at 24,23 face up
		//TODO: music class.
		//stop clock, music game?
	}
	if(walking_into_door(RANGE_SCHOOLMusicRoomToGymHallway))
	{
		MAP_change_map(MAP_bobsgame_SCHOOLGymHallway,40,39);return;
	}
}
void bobsgame_SCHOOLMusicRoom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_SCHOOLMusicRoom_Map_VBL_Function()
{

}

void bobsgame_SCHOOLMusicRoom_Map_HBL_Function()
{

}

//========================================================
//SCHOOLArtRoom
//========================================================
void bobsgame_SCHOOLArtRoom_Map_Load_Function()
{
//RANGE_SCHOOLArtRoomToGymHallway 19*8,39*8,23*8,40*8
}

void bobsgame_SCHOOLArtRoom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

	static NPC* artteacher_npc = NULL;
	if(artteacher_npc==NULL)
	{
		NPC_create_npc_xy_feet(&artteacher_npc,GFX_ADULT_grannycluelessteacher,16,40,22*8,19*8);
		artteacher_npc->non_walkable=1;
		artteacher_npc->pushable=1;
	}
	if(artteacher_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&artteacher_npc,30))NPC_stare_at_npc(&artteacher_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&artteacher_npc, DOWN);
		if(ACTION_npc(&artteacher_npc,"Talk To Art Teacher"))
		{
			TEXT_set_sprite_window(0,artteacher_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("Just close your eyes and use your imagination. Or paint with your eyes closed. That, children, is the beauty of the modern abstract art movement.");
			//TODO: painting minigame?
			//thats terrible, child.
		}
	}
		static NPC* classkids_npcs[15] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	int c=0;
	for(c=0;c<15;c++)
	{
		if(classkids_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			GFX* gfx=NULL;
			if(c== 0){x= 8;y=25;gfx=GFX_KID_pudgyboy;}
			if(c== 1){x=11;y=25;gfx=GFX_KID_nerdboy;}
			if(c== 2){x=14;y=25;gfx=GFX_KID_uglyboy;}
			if(c== 3){x=17;y=25;gfx=GFX_KID_nerdgirl;}
			if(c== 4){x=25;y=25;gfx=GFX_KID_punkboy;}
			if(c== 5){x=28;y=25;gfx=GFX_KID_emoboy;}
			if(c== 6){x=31;y=25;gfx=GFX_KID_emogirl;}
			if(c== 7){x=34;y=25;gfx=GFX_KID_uglygirl;}
			if(c== 8){x= 8;y=34;gfx=GFX_KID_pudgygirl;}
			if(c== 9){x=11;y=34;gfx=GFX_KID_conceitedgirl;}
			if(c==10){x=14;y=34;gfx=GFX_KID_notfriend;}
			if(c==12){x=17;y=34;gfx=GFX_KID_bully;}
			if(c==13){x=30;y=34;gfx=GFX_KID_jockboy;}
			if(c==14){x=34;y=34;gfx=GFX_KID_greaserboy;}
			//TODO: sit down at 26,35
			if(gfx!=NULL)
			{
				NPC_create_npc_xy_feet(&classkids_npcs[c],gfx,16,32,x*8,(y*8)+3);
				NPC_animate_stand_dir(&classkids_npcs[c], UP);
				classkids_npcs[c]->layer=3;
			}
		}
		if(classkids_npcs[c]!=NULL)
		{
			if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&classkids_npcs[c],30))NPC_stare_at_npc(&classkids_npcs[c],&PLAYER_npc);
			else NPC_animate_stand_dir(&classkids_npcs[c], UP);
		}
	}
		if(walking_into_door(RANGE_SCHOOLArtRoomToGymHallway))
	{
		MAP_change_map(MAP_bobsgame_SCHOOLGymHallway,80,39);return;
	}
}
void bobsgame_SCHOOLArtRoom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_SCHOOLArtRoom_Map_VBL_Function()
{

}

void bobsgame_SCHOOLArtRoom_Map_HBL_Function()
{

}

//========================================================
//SCHOOLComputerLab
//========================================================
void bobsgame_SCHOOLComputerLab_Map_Load_Function()
{
//RANGE_SCHOOLComputerLabToGymHallway 19*8,39*8,23*8,40*8
}

void bobsgame_SCHOOLComputerLab_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}
//pcteacher. assistant?
	static NPC* pcteacher_npc = NULL;
	if(pcteacher_npc==NULL)
	{
		NPC_create_npc_xy_feet(&pcteacher_npc,GFX_ADULT_pcteacher,16,40,22*8,14*8);
		pcteacher_npc->non_walkable=1;
		pcteacher_npc->pushable=1;
	}
	if(pcteacher_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&pcteacher_npc,30))NPC_stare_at_npc(&pcteacher_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&pcteacher_npc, DOWN);
		if(ACTION_npc(&pcteacher_npc,"Talk To PC Teacher"))
		{
			TEXT_set_sprite_window(0,pcteacher_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("Don't be changing around the grades when I'm not looking.<.>"
			"Unless you want to buy me a double float. *chuckle*<.>"
			"Just a little joke.<.>"
			"Move it, kid, you're blocking the view, so to speak.<.>"
			"How's it going, ladies?"
			);
		}
	}
		static NPC* classkids_npcs[15] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	int c=0;
	for(c=0;c<15;c++)
	{
		if(classkids_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			GFX* gfx=NULL;
			int dir=RIGHT;
			if(c== 0){x=(27*8)+2;y=(19*8);gfx=GFX_KID_pudgyboy;dir=RIGHT;}
			if(c== 1){x=(27*8)+2;y=(23*8);gfx=GFX_KID_nerdboy;dir=RIGHT;}
			if(c== 2){x=(27*8)+2;y=(28*8);gfx=GFX_KID_uglyboy;dir=RIGHT;}
			if(c== 3){x=(27*8)+2;y=(32*8);gfx=GFX_KID_nerdgirl;dir=RIGHT;}
			if(c== 4){x=(38*8)-2;y=(19*8);gfx=GFX_KID_punkboy;dir=LEFT;}
			if(c== 5){x=(38*8)-2;y=(23*8);gfx=GFX_KID_emoboy;dir=LEFT;}
			if(c== 6){x=(38*8)-2;y=(28*8);gfx=GFX_KID_emogirl;dir=LEFT;}
			if(c== 7){x=(38*8)-2;y=(32*8);gfx=GFX_KID_uglygirl;dir=LEFT;}
			if(c== 8){x=( 7*8);y=(31*8);gfx=GFX_KID_pudgygirl;dir=DOWN;}
			if(c== 9){x=(11*8);y=(31*8);gfx=GFX_KID_conceitedgirl;dir=DOWN;}
			if(c==10){x=( 7*8);y=(18*8);gfx=GFX_KID_notfriend;dir=UP;}
			if(c==12){x=( 6*8)-2;y=(21*8);gfx=GFX_KID_bully;dir=LEFT;}
			if(c==13){x=( 6*8)-2;y=(24*8);gfx=GFX_KID_jockboy;dir=LEFT;}
			if(c==14){x=( 6*8)-2;y=(28*8);gfx=GFX_KID_greaserboy;dir=LEFT;}
			if(gfx!=NULL)
			{
				NPC_create_npc_xy_feet(&classkids_npcs[c],gfx,16,32,x,(y)+3);
				NPC_animate_stand_dir(&classkids_npcs[c], dir);
			}
		}
	}
		//TODO: sit down at 10,18 UP
	//TODO: use the internet. everything is blocked but keyword ????.
	if(walking_into_door(RANGE_SCHOOLComputerLabToGymHallway))
	{
		MAP_change_map(MAP_bobsgame_SCHOOLGymHallway,120,39);return;
	}
}
void bobsgame_SCHOOLComputerLab_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_SCHOOLComputerLab_Map_VBL_Function()
{

}

void bobsgame_SCHOOLComputerLab_Map_HBL_Function()
{

}

//========================================================
//SCHOOLKitchen
//========================================================
void bobsgame_SCHOOLKitchen_Map_Load_Function()
{
//RANGE_SCHOOLKitchenToGymHallway 7*8,39*8,11*8,40*8
}

void bobsgame_SCHOOLKitchen_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//TODO: need lunchlady
	if(walking_into_door(RANGE_SCHOOLKitchenToGymHallway))
	{
		MAP_change_map(MAP_bobsgame_SCHOOLGymHallway,148,39);return;
	}
}
void bobsgame_SCHOOLKitchen_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_SCHOOLKitchen_Map_VBL_Function()
{

}

void bobsgame_SCHOOLKitchen_Map_HBL_Function()
{

}

//========================================================
//SCHOOLLibrary
//========================================================
void bobsgame_SCHOOLLibrary_Map_Load_Function()
{
//RANGE_SCHOOLLibraryToClassHallway 18*8,39*8,26*8,40*8
}

void bobsgame_SCHOOLLibrary_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//librarian. assistant?
	static NPC* librarian_npc = NULL;
	if(librarian_npc==NULL)
	{
		NPC_create_npc_xy_feet(&librarian_npc,GFX_ADULT_librarian,16,40,33*8,30*8);
		librarian_npc->non_walkable=1;
		librarian_npc->pushable=1;
	}
	if(librarian_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&librarian_npc,30))NPC_stare_at_npc(&librarian_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&librarian_npc, DOWN);
		if(ACTION_range_xy_xy(30*8,33*8,36*8,35*8,"Talk To Librarian"))
		{
			TEXT_set_sprite_window(0,librarian_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("Well hello, child. Would Yuu like me to recommend some books?<.><1>No, that's alright.<.><0>Now, don't be shy.<.>We've got a wonderful selection. Let's see... <.>\"Little Walrus Meets The Evil Drug Pusher And Falls Into An Endless Cycle Of Addiction-fueled Despair,\" <.>\"Cheeky Penguin Gets Abducted By Child Molestors,\" <.>\"Brave Chipmunk Gets Mauled By Terrorist Bear...\" <.>Any of those sound interesting?<.><1>Do you have anything with more substance? Those are all blatant attempts at pushing morals onto children. Aren't the authors just writing material they know will sell to schools?<.><0>Hmph. Don't Yuu just know everything? <.><1>No, I just..<.><0>Well little boy, maybe this is more suitable for your distinguished tastes. Now get out.");
			//get item "mein kampf" or maybe MIT encyclopedia of psychological knowledge. give it to little brother?
		}
	}
		static NPC* classkids_npcs[15] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	int c=0;
	for(c=0;c<15;c++)
	{
		if(classkids_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			GFX* gfx=NULL;
			int dir=UP;
			if(c== 0){x=31;y=21;gfx=GFX_KID_pudgyboy;}
			if(c== 1){x=39;y=21;gfx=GFX_KID_nerdboy;}
			if(c== 2){x=43;y=21;gfx=GFX_KID_uglyboy;}
			if(c== 3){x=17;y=21;gfx=GFX_KID_nerdgirl;}
			if(c== 4){x= 8;y=21;gfx=GFX_KID_punkboy;}
			if(c== 5){x= 7;y=12;gfx=GFX_KID_emoboy;}
			if(c== 6){x=14;y=12;gfx=GFX_KID_emogirl;}
			if(c== 7){x=23;y=13;gfx=GFX_KID_uglygirl;}
			if(c== 8){x=33;y=12;gfx=GFX_KID_pudgygirl;}
			if(c== 9){x=40;y=12;gfx=GFX_KID_conceitedgirl;}
			if(c==10){x=17;y=30;gfx=GFX_KID_notfriend;}
			if(c==12){x=10;y=30;gfx=GFX_KID_bully;}
			if(c==13){x= 5;y=30;gfx=GFX_KID_jockboy;}
			if(c==14){x=11;y=35;gfx=GFX_KID_greaserboy;dir=DOWN;}
			if(gfx!=NULL)
			{
				NPC_create_npc_xy_feet(&classkids_npcs[c],gfx,16,32,x*8,(y*8)+3);
				NPC_animate_stand_dir(&classkids_npcs[c], dir);
				classkids_npcs[c]->non_walkable=1;
				classkids_npcs[c]->pushable=1;
			}
		}
		if(classkids_npcs[c]!=NULL)
		{
			if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&classkids_npcs[c],20))NPC_stare_at_npc(&classkids_npcs[c],&PLAYER_npc);
			else NPC_animate_stand_dir(&classkids_npcs[c], UP);
		}
	}
		//TODO: tv support
	//TODO: talk to each kid about books.
	if(walking_into_door(RANGE_SCHOOLLibraryToClassHallway))
	{
		MAP_change_map(MAP_bobsgame_SCHOOLClassHallway,40,39);return;
	}
}
void bobsgame_SCHOOLLibrary_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_SCHOOLLibrary_Map_VBL_Function()
{

}

void bobsgame_SCHOOLLibrary_Map_HBL_Function()
{

}

//========================================================
//SCHOOLCustodian
//========================================================
void bobsgame_SCHOOLCustodian_Map_Load_Function()
{
//RANGE_SCHOOLCustodianToBackHallway 4*8,44*8,8*8,45*8
//RANGE_SCHOOLCustodianToOUTSIDERoof 12*8,6*8,16*8,7*8
}

void bobsgame_SCHOOLCustodian_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//custodian at desk
	static NPC* custodian_npc = NULL;
	if(custodian_npc==NULL)
	{
		NPC_create_npc_xy_feet(&custodian_npc,GFX_ADULT_janitor,16,40,6*8,31*8);
		custodian_npc->non_walkable=1;
		//TODO: set custodian tiles to layer 2 while hes at desk
		//5,30  6,30  6,31
		///TODO: MUST FIX!!
		///HARDWARE_set_map_tile(1,2,5,29,HARDWARE_map_1[HARDWARE_map_width_tiles*29+5]);	//top table chair tiles
		///HARDWARE_set_map_tile(1,2,6,29,HARDWARE_map_1[HARDWARE_map_width_tiles*29+6]);
		///HARDWARE_set_map_tile(1,2,6,30,HARDWARE_map_1[HARDWARE_map_width_tiles*30+6]);
		///HARDWARE_set_map_tile(1,1,5,29,0);
		///HARDWARE_set_map_tile(1,1,6,29,0);
		///HARDWARE_set_map_tile(1,1,6,30,0);
	}
	if(custodian_npc!=NULL)
	{
		//look at you?
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&custodian_npc,30))NPC_stare_at_npc(&custodian_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&custodian_npc, DOWN);
		if(ACTION_npc(&custodian_npc,"Talk To Custodian"))
		{
			TEXT_set_sprite_window(0,custodian_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("Hey, kid.<.>I used to be called a janitor, Yuu know.<.>A female janitor was called a janitrix, but nobody could remember that. <.>Then they changed it for some reason, so now I'm a custodian. <.>Custodial Technician.<.>I like the sound of that.<.>I still just clean stuff, though.<.>This is a pretty good job, for an old man like me.<.>I really like seeing Yuu kids and your smiling faces.<.>Never had a kid myself, Yuu know.<.>Oh, there was one lovely lady in my life, when I was younger. I wonder what she's doing now?");
			//TODO: crazy lady story
		}
	}
	if(walking_into_door(RANGE_SCHOOLCustodianToBackHallway))
	{
		MAP_change_map(MAP_bobsgame_SCHOOLBackHallway,6,39);return;
	}
	if(walking_into_door(RANGE_SCHOOLCustodianToOUTSIDERoof))
	{
		}
}
void bobsgame_SCHOOLCustodian_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_SCHOOLCustodian_Map_VBL_Function()
{

}

void bobsgame_SCHOOLCustodian_Map_HBL_Function()
{

}

//========================================================
//SCHOOLGirlsBathroom
//========================================================
void bobsgame_SCHOOLGirlsBathroom_Map_Load_Function()
{
//RANGE_SCHOOLGirlsBathroomToBackHallway 9*8,39*8,13*8,40*8
}

void bobsgame_SCHOOLGirlsBathroom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//17,22
//17,18
//17,10

	static NPC* stallgirl1_npc = NULL;
	if(stallgirl1_npc==NULL)
	{
		//NPC_create_random_MAN_xy_feet(&stallgirl1_npc,88*8,38*8);
		NPC_create_npc_xy_feet(&stallgirl1_npc,GFX_KID_GENERICgirl1,16,32,17*8,22*8);
		stallgirl1_npc->non_walkable=1;
		stallgirl1_npc->layer=2;
		NPC_animate_stand_dir(&stallgirl1_npc,LEFT);
		stallgirl1_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		stallgirl1_npc->walk_dir=stallgirl1_npc->anim_dir;
		//NPC_animate_increment_direction_frame_now(&stallgirl1_npc, stallgirl1_npc->anim_direction);
	}
	if(stallgirl1_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&stallgirl1_npc,45))NPC_stare_at_npc_not_opposite_walking_direction(&stallgirl1_npc,&PLAYER_npc);
		else if(stallgirl1_npc->AI==0){if(stallgirl1_npc->vbls>200){if(r(4)==0){stallgirl1_npc->AI=1+r(3);}else{stallgirl1_npc->vbls=0;NPC_animate_stand_dir(&stallgirl1_npc, stallgirl1_npc->walk_dir);if(stallgirl1_npc->anim_frame_count!=0){stallgirl1_npc->anim_frame_count=3;NPC_animate(&stallgirl1_npc);}}}}
		else if(stallgirl1_npc->AI==1){if(stallgirl1_npc->walk_dir==UP||stallgirl1_npc->walk_dir==DOWN)NPC_animate_stand_dir(&stallgirl1_npc,LEFT);else NPC_animate_stand_dir(&stallgirl1_npc,UP);stallgirl1_npc->vbls=r(120);stallgirl1_npc->AI=0;}
		else if(stallgirl1_npc->AI==2){if(stallgirl1_npc->walk_dir==UP||stallgirl1_npc->walk_dir==DOWN)NPC_animate_stand_dir(&stallgirl1_npc,RIGHT);else NPC_animate_stand_dir(&stallgirl1_npc,DOWN);stallgirl1_npc->vbls=r(120);stallgirl1_npc->AI=0;}
		else if(stallgirl1_npc->AI==3){NPC_animate(&stallgirl1_npc);stallgirl1_npc->vbls=r(120);stallgirl1_npc->AI=0;}

		if(ACTION_range_xy_xy(12*8,21*8,13*8,24*8,"Talk To Freshening Up Girl"))
		{
			TEXT_set_sprite_window(0,stallgirl1_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}

	static NPC* stallgirl2_npc = NULL;
	if(stallgirl2_npc==NULL)
	{
		//NPC_create_random_MAN_xy_feet(&stallgirl2_npc,88*8,38*8);
		NPC_create_npc_xy_feet(&stallgirl2_npc,GFX_KID_GENERICgirl1,16,32,17*8,18*8);
		stallgirl2_npc->non_walkable=1;
		stallgirl2_npc->layer=2;
		NPC_animate_stand_dir(&stallgirl2_npc,LEFT);
		stallgirl2_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		stallgirl2_npc->walk_dir=stallgirl2_npc->anim_dir;
		//NPC_animate_increment_direction_frame_now(&stallgirl2_npc, stallgirl2_npc->anim_direction);
	}
	if(stallgirl2_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&stallgirl2_npc,45))NPC_stare_at_npc_not_opposite_walking_direction(&stallgirl2_npc,&PLAYER_npc);
		else if(stallgirl2_npc->AI==0){if(stallgirl2_npc->vbls>200){if(r(4)==0){stallgirl2_npc->AI=1+r(3);}else{stallgirl2_npc->vbls=0;NPC_animate_stand_dir(&stallgirl2_npc, stallgirl2_npc->walk_dir);if(stallgirl2_npc->anim_frame_count!=0){stallgirl2_npc->anim_frame_count=3;NPC_animate(&stallgirl2_npc);}}}}
		else if(stallgirl2_npc->AI==1){if(stallgirl2_npc->walk_dir==UP||stallgirl2_npc->walk_dir==DOWN)NPC_animate_stand_dir(&stallgirl2_npc,LEFT);else NPC_animate_stand_dir(&stallgirl2_npc,UP);stallgirl2_npc->vbls=r(120);stallgirl2_npc->AI=0;}
		else if(stallgirl2_npc->AI==2){if(stallgirl2_npc->walk_dir==UP||stallgirl2_npc->walk_dir==DOWN)NPC_animate_stand_dir(&stallgirl2_npc,RIGHT);else NPC_animate_stand_dir(&stallgirl2_npc,DOWN);stallgirl2_npc->vbls=r(120);stallgirl2_npc->AI=0;}
		else if(stallgirl2_npc->AI==3){NPC_animate(&stallgirl2_npc);stallgirl2_npc->vbls=r(120);stallgirl2_npc->AI=0;}

		if(ACTION_range_xy_xy(12*8,17*8,13*8,20*8,"Talk To Powdering Nose Girl"))
		{
			TEXT_set_sprite_window(0,stallgirl2_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}

	static NPC* stallgirl3_npc = NULL;
	if(stallgirl3_npc==NULL)
	{
		//NPC_create_random_MAN_xy_feet(&stallgirl3_npc,88*8,38*8);
		NPC_create_npc_xy_feet(&stallgirl3_npc,GFX_KID_GENERICgirl1,16,32,17*8,10*8);
		stallgirl3_npc->non_walkable=1;
		stallgirl3_npc->layer=2;
		NPC_animate_stand_dir(&stallgirl3_npc,LEFT);
		stallgirl3_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		stallgirl3_npc->walk_dir=stallgirl3_npc->anim_dir;
		//NPC_animate_increment_direction_frame_now(&stallgirl3_npc, stallgirl3_npc->anim_direction);
	}
	if(stallgirl3_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&stallgirl3_npc,45))NPC_stare_at_npc_not_opposite_walking_direction(&stallgirl3_npc,&PLAYER_npc);
		else if(stallgirl3_npc->AI==0){if(stallgirl3_npc->vbls>200){if(r(4)==0){stallgirl3_npc->AI=1+r(3);}else{stallgirl3_npc->vbls=0;NPC_animate_stand_dir(&stallgirl3_npc, stallgirl3_npc->walk_dir);if(stallgirl3_npc->anim_frame_count!=0){stallgirl3_npc->anim_frame_count=3;NPC_animate(&stallgirl3_npc);}}}}
		else if(stallgirl3_npc->AI==1){if(stallgirl3_npc->walk_dir==UP||stallgirl3_npc->walk_dir==DOWN)NPC_animate_stand_dir(&stallgirl3_npc,LEFT);else NPC_animate_stand_dir(&stallgirl3_npc,UP);stallgirl3_npc->vbls=r(120);stallgirl3_npc->AI=0;}
		else if(stallgirl3_npc->AI==2){if(stallgirl3_npc->walk_dir==UP||stallgirl3_npc->walk_dir==DOWN)NPC_animate_stand_dir(&stallgirl3_npc,RIGHT);else NPC_animate_stand_dir(&stallgirl3_npc,DOWN);stallgirl3_npc->vbls=r(120);stallgirl3_npc->AI=0;}
		else if(stallgirl3_npc->AI==3){NPC_animate(&stallgirl3_npc);stallgirl3_npc->vbls=r(120);stallgirl3_npc->AI=0;}

		if(ACTION_range_xy_xy(12*8,9*8,13*8,12*8,"Talk To Checking Makeup Girl"))
		{
			TEXT_set_sprite_window(0,stallgirl3_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}

//elevator to paradise. was that an elevator?!?! girl comes out. girl group attacks you later?
	if(walking_into_door(RANGE_SCHOOLGirlsBathroomToBackHallway))
	{
		MAP_change_map(MAP_bobsgame_SCHOOLBackHallway,178,39);return;
	}
}
void bobsgame_SCHOOLGirlsBathroom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_SCHOOLGirlsBathroom_Map_VBL_Function()
{

}

void bobsgame_SCHOOLGirlsBathroom_Map_HBL_Function()
{

}

//========================================================
//SCHOOLBoysBathroom
//========================================================
void bobsgame_SCHOOLBoysBathroom_Map_Load_Function()
{
//RANGE_SCHOOLBoysBathroomToBackHallway 9*8,39*8,13*8,40*8
}

void bobsgame_SCHOOLBoysBathroom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

	//kids in stalls looking left
	//17,22
	//17,18
	//17,10

	static NPC* stallboy1_npc = NULL;
	if(stallboy1_npc==NULL)
	{
		//NPC_create_random_MAN_xy_feet(&stallboy1_npc,88*8,38*8);
		NPC_create_npc_xy_feet(&stallboy1_npc,GFX_KID_GENERICboy1,16,32,17*8,22*8);
		stallboy1_npc->non_walkable=1;
		stallboy1_npc->layer=2;
		NPC_animate_stand_dir(&stallboy1_npc,LEFT);
		stallboy1_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		stallboy1_npc->walk_dir=stallboy1_npc->anim_dir;
		//NPC_animate_increment_direction_frame_now(&stallboy1_npc, stallboy1_npc->anim_direction);
	}
	if(stallboy1_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&stallboy1_npc,45))NPC_stare_at_npc_not_opposite_walking_direction(&stallboy1_npc,&PLAYER_npc);
		else if(stallboy1_npc->AI==0){if(stallboy1_npc->vbls>200){if(r(4)==0){stallboy1_npc->AI=1+r(3);}else{stallboy1_npc->vbls=0;NPC_animate_stand_dir(&stallboy1_npc, stallboy1_npc->walk_dir);if(stallboy1_npc->anim_frame_count!=0){stallboy1_npc->anim_frame_count=3;NPC_animate(&stallboy1_npc);}}}}
		else if(stallboy1_npc->AI==1){if(stallboy1_npc->walk_dir==UP||stallboy1_npc->walk_dir==DOWN)NPC_animate_stand_dir(&stallboy1_npc,LEFT);else NPC_animate_stand_dir(&stallboy1_npc,UP);stallboy1_npc->vbls=r(120);stallboy1_npc->AI=0;}
		else if(stallboy1_npc->AI==2){if(stallboy1_npc->walk_dir==UP||stallboy1_npc->walk_dir==DOWN)NPC_animate_stand_dir(&stallboy1_npc,RIGHT);else NPC_animate_stand_dir(&stallboy1_npc,DOWN);stallboy1_npc->vbls=r(120);stallboy1_npc->AI=0;}
		else if(stallboy1_npc->AI==3){NPC_animate(&stallboy1_npc);stallboy1_npc->vbls=r(120);stallboy1_npc->AI=0;}

		if(ACTION_range_xy_xy(12*8,21*8,13*8,24*8,"Talk To Pooping Boy"))
		{
			TEXT_set_sprite_window(0,stallboy1_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}

	static NPC* stallboy2_npc = NULL;
	if(stallboy2_npc==NULL)
	{
		//NPC_create_random_MAN_xy_feet(&stallboy2_npc,88*8,38*8);
		NPC_create_npc_xy_feet(&stallboy2_npc,GFX_KID_GENERICboy1,16,32,17*8,18*8);
		stallboy2_npc->non_walkable=1;
		stallboy2_npc->layer=2;
		NPC_animate_stand_dir(&stallboy2_npc,LEFT);
		stallboy2_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		stallboy2_npc->walk_dir=stallboy2_npc->anim_dir;
		//NPC_animate_increment_direction_frame_now(&stallboy2_npc, stallboy2_npc->anim_direction);
	}
	if(stallboy2_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&stallboy2_npc,45))NPC_stare_at_npc_not_opposite_walking_direction(&stallboy2_npc,&PLAYER_npc);
		else if(stallboy2_npc->AI==0){if(stallboy2_npc->vbls>200){if(r(4)==0){stallboy2_npc->AI=1+r(3);}else{stallboy2_npc->vbls=0;NPC_animate_stand_dir(&stallboy2_npc, stallboy2_npc->walk_dir);if(stallboy2_npc->anim_frame_count!=0){stallboy2_npc->anim_frame_count=3;NPC_animate(&stallboy2_npc);}}}}
		else if(stallboy2_npc->AI==1){if(stallboy2_npc->walk_dir==UP||stallboy2_npc->walk_dir==DOWN)NPC_animate_stand_dir(&stallboy2_npc,LEFT);else NPC_animate_stand_dir(&stallboy2_npc,UP);stallboy2_npc->vbls=r(120);stallboy2_npc->AI=0;}
		else if(stallboy2_npc->AI==2){if(stallboy2_npc->walk_dir==UP||stallboy2_npc->walk_dir==DOWN)NPC_animate_stand_dir(&stallboy2_npc,RIGHT);else NPC_animate_stand_dir(&stallboy2_npc,DOWN);stallboy2_npc->vbls=r(120);stallboy2_npc->AI=0;}
		else if(stallboy2_npc->AI==3){NPC_animate(&stallboy2_npc);stallboy2_npc->vbls=r(120);stallboy2_npc->AI=0;}

		if(ACTION_range_xy_xy(12*8,17*8,13*8,20*8,"Talk To Pooping Boy"))
		{
			TEXT_set_sprite_window(0,stallboy2_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}

	static NPC* stallboy3_npc = NULL;
	if(stallboy3_npc==NULL)
	{
		//NPC_create_random_MAN_xy_feet(&stallboy3_npc,88*8,38*8);
		NPC_create_npc_xy_feet(&stallboy3_npc,GFX_KID_GENERICboy1,16,32,17*8,10*8);
		stallboy3_npc->non_walkable=1;
		stallboy3_npc->layer=2;
		NPC_animate_stand_dir(&stallboy3_npc,LEFT);
		stallboy3_npc->walking_speed=SPEED_NORMAL+(r(SPEED_SLOWEST-SPEED_FAST));
		stallboy3_npc->walk_dir=stallboy3_npc->anim_dir;
		//NPC_animate_increment_direction_frame_now(&stallboy3_npc, stallboy3_npc->anim_direction);
	}
	if(stallboy3_npc!=NULL)
	{
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&stallboy3_npc,45))NPC_stare_at_npc_not_opposite_walking_direction(&stallboy3_npc,&PLAYER_npc);
		else if(stallboy3_npc->AI==0){if(stallboy3_npc->vbls>200){if(r(4)==0){stallboy3_npc->AI=1+r(3);}else{stallboy3_npc->vbls=0;NPC_animate_stand_dir(&stallboy3_npc, stallboy3_npc->walk_dir);if(stallboy3_npc->anim_frame_count!=0){stallboy3_npc->anim_frame_count=3;NPC_animate(&stallboy3_npc);}}}}
		else if(stallboy3_npc->AI==1){if(stallboy3_npc->walk_dir==UP||stallboy3_npc->walk_dir==DOWN)NPC_animate_stand_dir(&stallboy3_npc,LEFT);else NPC_animate_stand_dir(&stallboy3_npc,UP);stallboy3_npc->vbls=r(120);stallboy3_npc->AI=0;}
		else if(stallboy3_npc->AI==2){if(stallboy3_npc->walk_dir==UP||stallboy3_npc->walk_dir==DOWN)NPC_animate_stand_dir(&stallboy3_npc,RIGHT);else NPC_animate_stand_dir(&stallboy3_npc,DOWN);stallboy3_npc->vbls=r(120);stallboy3_npc->AI=0;}
		else if(stallboy3_npc->AI==3){NPC_animate(&stallboy3_npc);stallboy3_npc->vbls=r(120);stallboy3_npc->AI=0;}

		if(ACTION_range_xy_xy(12*8,9*8,13*8,12*8,"Talk To Pooping Boy"))
		{
			TEXT_set_sprite_window(0,stallboy3_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(""
			);
		}
	}

	if(walking_into_door(RANGE_SCHOOLBoysBathroomToBackHallway))
	{
		MAP_change_map(MAP_bobsgame_SCHOOLBackHallway,197,39);return;
	}
}
void bobsgame_SCHOOLBoysBathroom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_SCHOOLBoysBathroom_Map_VBL_Function()
{

}

void bobsgame_SCHOOLBoysBathroom_Map_HBL_Function()
{

}

//========================================================
//SCHOOLEntranceHallway
//========================================================
void bobsgame_SCHOOLEntranceHallway_Map_Load_Function()
{
//RANGE_SCHOOLEntranceHallwayToOUTSIDEPlayground1 7*8,41*8,15*8,42*8
//RANGE_SCHOOLEntranceHallwayToOUTSIDEPlayground2 106*8,41*8,114*8,42*8
//RANGE_SCHOOLEntranceHallwayToOUTSIDE1 143*8,49*8,149*8,50*8
//RANGE_SCHOOLEntranceHallwayToOUTSIDE2 152*8,49*8,158*8,50*8
//RANGE_SCHOOLEntranceHallwayToOUTSIDE3 161*8,49*8,167*8,50*8
//RANGE_SCHOOLEntranceHallwayToGymHallwayLeft 7*8,10*8,15*8,11*8
//RANGE_SCHOOLEntranceHallwayToTeachersLounge 30*8,26*8,38*8,27*8
//RANGE_SCHOOLEntranceHallwayToClinic 85*8,26*8,89*8,27*8
//RANGE_SCHOOLEntranceHallwayToMainOffice 151*8,26*8,159*8,27*8
//RANGE_SCHOOLEntranceHallwayToDetention 174*8,26*8,178*8,27*8
//RANGE_SCHOOLEntranceHallwayToGymCafeteria 193*8,10*8,201*8,11*8
//RANGE_SCHOOLEntranceHallwayToGymHallwayMiddle 100*8,10*8,108*8,11*8


}
///============================================================================================================
///============================================================================================================
///============================================================================================================
///============================================================================================================
///============================================================================================================
///============================================================================================================
void bobsgame_SCHOOLEntranceHallway_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{
			//load_tv_fullscreen();
			//HARDWARE_play_music("ramio",64);
			//GAME_playing_ramio=1;
	}
//=================================================================================================================
//MORNING 7:00-7:30
//=================================================================================================================
//=================================================================================================================
//KIDS COME IN FROM ENTRANCE, WALK TO 3 HALLWAYS
//=================================================================================================================
//doors 145,48.  154,48    163.48 walk to x,35ish 32-39
//walk to 10.11  103.11  196.11
	static NPC* enterkids[100]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};

	if(CLOCK_hour==7)
	{
			if(CLOCK_minute<30)
			{
				HARDWARE_play_sound_if_not_playing("murmur",127,50000,1);
				int c=0;

				static int last_vbl10_var=0;

				for(c=0;c<1;c++)//40 temp
				if(enterkids[c]==NULL&&last_vbl10_var!=vbl_10_var)
				{
					last_vbl10_var=vbl_10_var;

					int cycle=r(3);
					if(cycle==0)
					{
						int x=(143+r(3))*8;
						int y=48*8;
						if(MAP_is_xy_within_screen_by_64px(x,y))NPC_create_random_CHILD_xy_feet(&enterkids[c],x,y);
						else
						{
							int randnum=r(2);
							int x=MAP_cam_x-16;
							if(randnum==1)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
							int y=34*8;
							if(!NPC_cant_create_at_xy(x,y))NPC_create_random_CHILD_xy_feet(&enterkids[c],x,y);
						}
					}
					if(cycle==1)
					{
						int x=(152+r(3))*8;
						int y=48*8;
						if(MAP_is_xy_within_screen_by_64px(x,y))NPC_create_random_CHILD_xy_feet(&enterkids[c],x,y);
						else
						{
							int randnum=r(2);
							int x=MAP_cam_x-16;
							if(randnum==1)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
							int y=34*8;
							if(!NPC_cant_create_at_xy(x,y))NPC_create_random_CHILD_xy_feet(&enterkids[c],x,y);
						}
					}
					if(cycle==2)
					{
						int x=(161+r(3))*8;
						int y=48*8;
						if(MAP_is_xy_within_screen_by_64px(x,y))NPC_create_random_CHILD_xy_feet(&enterkids[c],x,y);
						else
						{
							int randnum=r(2);
							int x=MAP_cam_x-16;
							if(randnum==1)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
							int y=34*8;
							if(!NPC_cant_create_at_xy(x,y))NPC_create_random_CHILD_xy_feet(&enterkids[c],x,y);
						}
					}
					if(enterkids[c]!=NULL)enterkids[c]->walking_speed = SPEED_FAST+r(SPEED_SLOWEST-SPEED_FASTEST);
					if(enterkids[c]!=NULL)enterkids[c]->AI=cycle;
					if(enterkids[c]!=NULL)enterkids[c]->non_walkable=1;
				}
			}


			int c=0;
			for(c=0;c<1;c++)
			if(enterkids[c]!=NULL)
			{
				if(enterkids[c]!=NULL)if(enterkids[c]->AI==0)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&enterkids[c], enterkids[c]->walking_speed, -1, 34*8)){enterkids[c]->AI=(r(2))+3;}
				if(enterkids[c]!=NULL)if(enterkids[c]->AI==1)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&enterkids[c], enterkids[c]->walking_speed, -1, 36*8)){enterkids[c]->AI=(r(2))+3;}
				if(enterkids[c]!=NULL)if(enterkids[c]->AI==2)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&enterkids[c], enterkids[c]->walking_speed, -1, 38*8)){enterkids[c]->AI=(r(2))+3;}

				if(enterkids[c]!=NULL)if(enterkids[c]->AI==3)if(enterkids[c]->MAP_x<=15*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&enterkids[c], enterkids[c]->walking_speed, (10+(c%3))*8, -1))enterkids[c]->AI+=2;
				if(enterkids[c]!=NULL)if(enterkids[c]->AI==4)if((enterkids[c]->MAP_x<=109*8&&enterkids[c]->MAP_x>=98*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&enterkids[c], enterkids[c]->walking_speed, (103+(c%3))*8, -1))enterkids[c]->AI+=2;

				if(enterkids[c]!=NULL)if(enterkids[c]->AI==5)if(enterkids[c]->MAP_y<=8*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&enterkids[c], enterkids[c]->walking_speed, (9+(c%5))*8, 11*8)){NPC_delete_npc(&enterkids[c]);}
				if(enterkids[c]!=NULL)if(enterkids[c]->AI==6)if(enterkids[c]->MAP_y<=8*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&enterkids[c], enterkids[c]->walking_speed, (102+(c%5))*8, 11*8)){NPC_delete_npc(&enterkids[c]);}

				if(enterkids[c]!=NULL)if(MAP_is_xy_within_screen_by_64px(enterkids[c]->MAP_x,enterkids[c]->MAP_y)==0){NPC_delete_npc(&enterkids[c]);}
			}
































		if((walking_into_door(RANGE_SCHOOLEntranceHallwayToOUTSIDEPlayground1)||//)//{MAP_change_map(MAP_bobsgame_SCHOOLPlayground,88,227);return;}
		    walking_into_door(RANGE_SCHOOLEntranceHallwayToOUTSIDEPlayground2)))//{MAP_change_map(MAP_bobsgame_SCHOOLPlayground,187,227);return;}
		{
			if(ACTION_check("Check Playground Door"))
			{
				TEXT_set_sprite_window(0,PLAYER_npc,NULL);
				TEXT_window("There's an alarm system on the playground doors. Maybe I should wait until recess.");
			}
		}

		if(walking_into_door(RANGE_SCHOOLEntranceHallwayToOUTSIDE1)){MAP_change_map(MAP_bobsgame_TOWNTown,233,275);return;}
		if(walking_into_door(RANGE_SCHOOLEntranceHallwayToOUTSIDE2)){MAP_change_map(MAP_bobsgame_TOWNTown,242,275);return;}
		if(walking_into_door(RANGE_SCHOOLEntranceHallwayToOUTSIDE3)){MAP_change_map(MAP_bobsgame_TOWNTown,251,275);return;}
		if(walking_into_door(RANGE_SCHOOLEntranceHallwayToGymHallwayLeft)){MAP_change_map(MAP_bobsgame_SCHOOLGymHallway,10,52);return;}
		if(walking_into_door(RANGE_SCHOOLEntranceHallwayToTeachersLounge))
		{
			if(demobutton){MAP_change_map(MAP_bobsgame_SCHOOLTeachersLounge,16,26);return;}
			if(ACTION_check("Check Teacher's Lounge Door"))
			{
				TEXT_set_sprite_window(0,PLAYER_npc,NULL);
				TEXT_window("Doesn't open. I don't see a lock though...");
			}
		}
		if(walking_into_door(RANGE_SCHOOLEntranceHallwayToClinic)){MAP_change_map(MAP_bobsgame_SCHOOLClinic,31,26);return;}
		if(walking_into_door(RANGE_SCHOOLEntranceHallwayToMainOffice)){MAP_change_map(MAP_bobsgame_SCHOOLMainOffice,17,26);return;}
		if(walking_into_door(RANGE_SCHOOLEntranceHallwayToDetention))
		{
			if(demobutton){MAP_change_map(MAP_bobsgame_SCHOOLDetention,11,26);return;}
			if(ACTION_check("Check Detention Room Door"))
			{
				TEXT_set_sprite_window(0,PLAYER_npc,NULL);
				TEXT_window("I shouldn't be getting too ahead of myself.");
			}
		}
		if(walking_into_door(RANGE_SCHOOLEntranceHallwayToGymCafeteria))
		{
			if(demobutton){MAP_change_map(MAP_bobsgame_SCHOOLGymCafeteria,41,52);return;}
			if(ACTION_check("Check Gymnasium Door"))
			{
				TEXT_set_sprite_window(0,PLAYER_npc,NULL);
				TEXT_window("The gym is closed. It'll be open at lunchtime.");
			}
		}
		if(walking_into_door(RANGE_SCHOOLEntranceHallwayToGymHallwayMiddle)){MAP_change_map(MAP_bobsgame_SCHOOLGymHallway,103,52);return;	}
		//TODO:hall monitor standing around
		//TODO: detention door blacked out.
		//TODO: teachers door blacked out.
		//TODO: 3x2 tv at 184,22   145,22   120,22    46,22   23,22
		//TODO: white flickering flourescent lights?
		//TODO: crowd murmur, footsteps
	}


















//=================================================================================================================
//SCHOOL IN SESSION 7:30-4:30
//=================================================================================================================
	if((CLOCK_hour>7&&CLOCK_hour<12+4)||(CLOCK_hour==4&&CLOCK_minute<30))
	{
		if((walking_into_door(RANGE_SCHOOLEntranceHallwayToOUTSIDEPlayground1)||//)//{MAP_change_map(MAP_bobsgame_SCHOOLPlayground,88,227);return;}
		    walking_into_door(RANGE_SCHOOLEntranceHallwayToOUTSIDEPlayground2)))//{MAP_change_map(MAP_bobsgame_SCHOOLPlayground,187,227);return;}
		{
			if(ACTION_check("Check Playground Door"))
			{
				TEXT_set_sprite_window(0,PLAYER_npc,NULL);
				TEXT_window("There's an alarm system on the playground doors. Maybe I should wait until recess.");
			}
		}
		if((walking_into_door(RANGE_SCHOOLEntranceHallwayToOUTSIDE2)||//)//{MAP_change_map(MAP_bobsgame_TOWNTown,242,275);return;}
		    walking_into_door(RANGE_SCHOOLEntranceHallwayToOUTSIDE3)||//)//{MAP_change_map(MAP_bobsgame_TOWNTown,251,275);return;}
		    walking_into_door(RANGE_SCHOOLEntranceHallwayToOUTSIDE1)))
		{
			if(demobutton){MAP_change_map(MAP_bobsgame_TOWNTown,233,275);return;}
			if(ACTION_check("Check Exit Door"))
			{
				TEXT_set_sprite_window(0,PLAYER_npc,NULL);
				TEXT_window("There's a padlocked chain on it.. Not very comforting. Can they even do that?");
			}
		}
		if(walking_into_door(RANGE_SCHOOLEntranceHallwayToGymHallwayLeft)){MAP_change_map(MAP_bobsgame_SCHOOLGymHallway,10,52);return;}
		if(walking_into_door(RANGE_SCHOOLEntranceHallwayToTeachersLounge))
		{
			if(demobutton){MAP_change_map(MAP_bobsgame_SCHOOLTeachersLounge,16,26);return;}
			if(ACTION_check("Check Teacher's Lounge Door"))
			{
				TEXT_set_sprite_window(0,PLAYER_npc,NULL);
				TEXT_window("Doesn't open. I don't see a lock though...");
			}
		}
		if(walking_into_door(RANGE_SCHOOLEntranceHallwayToClinic)){MAP_change_map(MAP_bobsgame_SCHOOLClinic,31,26);return;}
		if(walking_into_door(RANGE_SCHOOLEntranceHallwayToMainOffice)){MAP_change_map(MAP_bobsgame_SCHOOLMainOffice,17,26);return;}
		if(walking_into_door(RANGE_SCHOOLEntranceHallwayToDetention))
		{
			if(demobutton){MAP_change_map(MAP_bobsgame_SCHOOLDetention,11,26);return;}
			if(ACTION_check("Check Detention Room Door"))
			{
				TEXT_set_sprite_window(0,PLAYER_npc,NULL);
				TEXT_window("I shouldn't be getting too ahead of myself.");
			}
		} //hall monitor in here? watching movies?
		if(walking_into_door(RANGE_SCHOOLEntranceHallwayToGymCafeteria))
		{
			if(CLOCK_hour==12){MAP_change_map(MAP_bobsgame_SCHOOLGymCafeteria,41,52);return;}
			else
			if(CLOCK_day==TUESDAY&&((CLOCK_hour==12+3&&CLOCK_minute>=30)||(CLOCK_hour==12+4&&CLOCK_minute<=30))){MAP_change_map(MAP_bobsgame_SCHOOLGymGym,41,52);return;}
			else
			if(ACTION_check("Check Gymnasium Door"))
			{
					TEXT_set_sprite_window(0,PLAYER_npc,NULL);
					if(CLOCK_hour<12)TEXT_window("The gym is closed. Maybe it's being set up for lunchtime.");
					if(CLOCK_hour>12)TEXT_window("The gym is closed. I guess they're cleaning up the mess from lunch.");
			}
		}
		if(walking_into_door(RANGE_SCHOOLEntranceHallwayToGymHallwayMiddle)){MAP_change_map(MAP_bobsgame_SCHOOLGymHallway,103,52);return;}

	}
		//teachers lounge needs key?
		//janitor makes rounds?
//=================================================================================================================
//SCHOOL CLOSED SESSION 4:30-5:30
//=================================================================================================================
	if(CLOCK_hour>=12+4)
	{
		static NPC* schoolentrancehallwayexitingkids_npcs[40]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
		if(CLOCK_hour==12+4&&CLOCK_minute>=30)
		{
			//exiting kids flooding out
			if(CLOCK_minute>=30)
			{
				HARDWARE_play_sound_if_not_playing("murmur",127,50000,1);
				int c=0;
				for(c=0;c<40;c++)
				if(schoolentrancehallwayexitingkids_npcs[c]==NULL&&vbl_10_var%10==c%10)
				{
					int cycle=r(2);
					if(cycle==0)
					{
						int x=(9+r(3))*8;
						int y=11*8;
						if(MAP_is_xy_within_screen_by_64px(x,y))NPC_create_random_CHILD_xy_feet(&schoolentrancehallwayexitingkids_npcs[c],x,y);
						else
						{
							int randnum=r(2);
							int x=MAP_cam_x-16;
							if(randnum==1)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
							int y=34*8;
							if(!NPC_cant_create_at_xy(x,y))NPC_create_random_CHILD_xy_feet(&schoolentrancehallwayexitingkids_npcs[c],x,y);
						}
					}
					if(cycle==1)
					{
						int x=(102+r(3))*8;
						int y=11*8;
						if(MAP_is_xy_within_screen_by_64px(x,y))NPC_create_random_CHILD_xy_feet(&schoolentrancehallwayexitingkids_npcs[c],x,y);
						else
						{
							int randnum=r(2);
							int x=MAP_cam_x-16;
							if(randnum==1)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
							int y=34*8;//touchmap_cam_y*2+r(384);
							if(!NPC_cant_create_at_xy(x,y))NPC_create_random_CHILD_xy_feet(&schoolentrancehallwayexitingkids_npcs[c],x,y);
						}
					}
					if(schoolentrancehallwayexitingkids_npcs[c]!=NULL)schoolentrancehallwayexitingkids_npcs[c]->walking_speed = SPEED_FASTER+r(SPEED_SLOWEST-SPEED_FASTEST);
					if(schoolentrancehallwayexitingkids_npcs[c]!=NULL)schoolentrancehallwayexitingkids_npcs[c]->AI=cycle;
					if(schoolentrancehallwayexitingkids_npcs[c]!=NULL)schoolentrancehallwayexitingkids_npcs[c]->non_walkable=1;
				}
			}
		}
			int c=0;
		for(c=0;c<40;c++)
		if(schoolentrancehallwayexitingkids_npcs[c]!=NULL)
		{
			if(schoolentrancehallwayexitingkids_npcs[c]->AI==0)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&schoolentrancehallwayexitingkids_npcs[c], schoolentrancehallwayexitingkids_npcs[c]->walking_speed, schoolentrancehallwayexitingkids_npcs[c]->MAP_x+8, 34*8)==1)schoolentrancehallwayexitingkids_npcs[c]->AI=(r(2))+2;
			if(schoolentrancehallwayexitingkids_npcs[c]->AI==1)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&schoolentrancehallwayexitingkids_npcs[c], schoolentrancehallwayexitingkids_npcs[c]->walking_speed, schoolentrancehallwayexitingkids_npcs[c]->MAP_x+8, 36*8)==1)schoolentrancehallwayexitingkids_npcs[c]->AI=(r(2))+2;
			if(schoolentrancehallwayexitingkids_npcs[c]->AI==2)if((schoolentrancehallwayexitingkids_npcs[c]->MAP_x>=144*8&&schoolentrancehallwayexitingkids_npcs[c]->MAP_x<=163*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&schoolentrancehallwayexitingkids_npcs[c], schoolentrancehallwayexitingkids_npcs[c]->walking_speed, (145+(c%20))*8, 36*8)){schoolentrancehallwayexitingkids_npcs[c]->AI=(r(3))+4;}
			if(schoolentrancehallwayexitingkids_npcs[c]->AI==3)if((schoolentrancehallwayexitingkids_npcs[c]->MAP_x>=144*8&&schoolentrancehallwayexitingkids_npcs[c]->MAP_x<=163*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&schoolentrancehallwayexitingkids_npcs[c], schoolentrancehallwayexitingkids_npcs[c]->walking_speed, (145+(c%20))*8, 35*8)){schoolentrancehallwayexitingkids_npcs[c]->AI=(r(3))+4;}

			if(schoolentrancehallwayexitingkids_npcs[c]->AI==4)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&schoolentrancehallwayexitingkids_npcs[c], schoolentrancehallwayexitingkids_npcs[c]->walking_speed, (142+(c%5))*8, 48*8)==1){NPC_delete_npc(&schoolentrancehallwayexitingkids_npcs[c]);}
			if(schoolentrancehallwayexitingkids_npcs[c]->AI==5)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&schoolentrancehallwayexitingkids_npcs[c], schoolentrancehallwayexitingkids_npcs[c]->walking_speed, (151+(c%5))*8, 48*8)==1){NPC_delete_npc(&schoolentrancehallwayexitingkids_npcs[c]);}
			if(schoolentrancehallwayexitingkids_npcs[c]->AI==6)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&schoolentrancehallwayexitingkids_npcs[c], schoolentrancehallwayexitingkids_npcs[c]->walking_speed, (160+(c%5))*8, 48*8)==1){NPC_delete_npc(&schoolentrancehallwayexitingkids_npcs[c]);}
			if(MAP_is_xy_within_screen_by_64px(schoolentrancehallwayexitingkids_npcs[c]->MAP_x,schoolentrancehallwayexitingkids_npcs[c]->MAP_y)==0){NPC_delete_npc(&schoolentrancehallwayexitingkids_npcs[c]);}
		}
		//TODO: hall monitor watching
		//if have detention cant leave
		//somehow have hall monitor lady come get you if you have detention
		//otherwise she tells you to get out
		//janitor makes rounds.
		//teachers lounge light on, cant get in, can hear sounds of party going on inside??
		if(walking_into_door(RANGE_SCHOOLEntranceHallwayToTeachersLounge))
		{
			if(demobutton){MAP_change_map(MAP_bobsgame_SCHOOLTeachersLounge,16,26);return;}
			if(ACTION_check("Check Teacher's Lounge Door"))
			{
				TEXT_set_sprite_window(0,PLAYER_npc,NULL);
				TEXT_window("Is there a party or something going on in there?<.>How do they get in there?!");
			}
		}
		if((walking_into_door(RANGE_SCHOOLEntranceHallwayToGymCafeteria)||//){MAP_change_map(MAP_bobsgame_SCHOOLGymCafeteria,41,52);return;}
		    walking_into_door(RANGE_SCHOOLEntranceHallwayToGymHallwayMiddle)||//){MAP_change_map(MAP_bobsgame_SCHOOLGymHallway,103,52);return;}
		    walking_into_door(RANGE_SCHOOLEntranceHallwayToGymHallwayLeft)||//){MAP_change_map(MAP_bobsgame_SCHOOLGymHallway,10,52);return;}
		    walking_into_door(RANGE_SCHOOLEntranceHallwayToClinic)||//){MAP_change_map(MAP_bobsgame_SCHOOLClinic,31,26);return;}
		    walking_into_door(RANGE_SCHOOLEntranceHallwayToMainOffice)||//){MAP_change_map(MAP_bobsgame_SCHOOLMainOffice,17,26);return;}
		    walking_into_door(RANGE_SCHOOLEntranceHallwayToOUTSIDEPlayground1)||//)//{MAP_change_map(MAP_bobsgame_SCHOOLPlayground,88,227);return;}
		    walking_into_door(RANGE_SCHOOLEntranceHallwayToOUTSIDEPlayground2)))//{MAP_change_map(MAP_bobsgame_SCHOOLPlayground,187,227);return;}
		{
			if(ACTION_check("Check Door"))
			{
				TEXT_set_sprite_window(0,PLAYER_npc,NULL);
				TEXT_window("School is over.. I can *leave* now! What am I doing?!");
			}
		}
		if(walking_into_door(RANGE_SCHOOLEntranceHallwayToOUTSIDE1)){MAP_change_map(MAP_bobsgame_TOWNTown,233,275);return;}
		if(walking_into_door(RANGE_SCHOOLEntranceHallwayToOUTSIDE2)){MAP_change_map(MAP_bobsgame_TOWNTown,242,275);return;}
		if(walking_into_door(RANGE_SCHOOLEntranceHallwayToOUTSIDE3)){MAP_change_map(MAP_bobsgame_TOWNTown,251,275);return;}
		if(walking_into_door(RANGE_SCHOOLEntranceHallwayToDetention))
		{
			if(demobutton){MAP_change_map(MAP_bobsgame_SCHOOLDetention,11,26);return;}
			if(ACTION_check("Check Detention Room Door"))
			{
				TEXT_set_sprite_window(0,PLAYER_npc,NULL);
				TEXT_window("I shouldn't be getting too ahead of myself.");
			}
		}
	}
//=================================================================================================================
//ACTIONS
//=================================================================================================================
	//if(walking_into_door(RANGE_SCHOOLEntranceHallwayToOUTSIDEPlayground1)){MAP_change_map(MAP_bobsgame_SCHOOLPlayground,88,227);return;}
	//if(walking_into_door(RANGE_SCHOOLEntranceHallwayToOUTSIDEPlayground2)){MAP_change_map(MAP_bobsgame_SCHOOLPlayground,187,227);return;}
	//if(walking_into_door(RANGE_SCHOOLEntranceHallwayToOUTSIDE1)){MAP_change_map(MAP_bobsgame_TOWNTown,233,275);return;}
	//if(walking_into_door(RANGE_SCHOOLEntranceHallwayToOUTSIDE2)){MAP_change_map(MAP_bobsgame_TOWNTown,242,275);return;}
	//if(walking_into_door(RANGE_SCHOOLEntranceHallwayToOUTSIDE3)){MAP_change_map(MAP_bobsgame_TOWNTown,251,275);return;}
	//if(walking_into_door(RANGE_SCHOOLEntranceHallwayToGymHallwayLeft)){MAP_change_map(MAP_bobsgame_SCHOOLGymHallway,10,52);return;}
	//if(walking_into_door(RANGE_SCHOOLEntranceHallwayToTeachersLounge)){MAP_change_map(MAP_bobsgame_SCHOOLTeachersLounge,16,26);return;}
	//if(walking_into_door(RANGE_SCHOOLEntranceHallwayToClinic)){MAP_change_map(MAP_bobsgame_SCHOOLClinic,31,26);return;}
	//if(walking_into_door(RANGE_SCHOOLEntranceHallwayToMainOffice)){MAP_change_map(MAP_bobsgame_SCHOOLMainOffice,17,26);return;}
	//if(walking_into_door(RANGE_SCHOOLEntranceHallwayToDetention)){MAP_change_map(MAP_bobsgame_SCHOOLDetention,11,26);return;}
	//if(walking_into_door(RANGE_SCHOOLEntranceHallwayToGymCafeteria)){MAP_change_map(MAP_bobsgame_SCHOOLGymCafeteria,41,52);return;}
	//if(walking_into_door(RANGE_SCHOOLEntranceHallwayToGymHallwayMiddle)){MAP_change_map(MAP_bobsgame_SCHOOLGymHallway,103,52);return;}
		//SCHOOL SCHEDULE
	//7:00-7:30 school opens, hall monitor in entrance. classes open no teacher. everything else closed.
	//7:35 class starts. 2 hrs
	//9:30 recess 1/2 hr
	//10:00 recess end
	//10:05 class starts 2 hrs
		//12:00 lunchtime 1 hr
	//1:00 lunchtime end
	//1:05 class starts 2 hrs
	//3:00 recess 1/2 hr
	//3:30 recess ends
	//3:35 special class starts 1 hr
	//4:30 special class ends school out
	//MONDAY music class
	//TUESDAY gym class
	//WEDNESDAY library
	//THURSDAY art class
	//FRIDAY computer class
	//bell rings at 7:30, 7:35, 9:30, 10:00, 10:05, 12:00, 1:00, 1:05, 3:00, 3:30, 3:35, 4:30
	if(CLOCK_hour==7&&CLOCK_second==0&&CLOCK_minute==30){CAPTION_make_caption(NULL,1,60,80,5,"School is starting! Get to class!",FONT_SMALL_ID,WHITE,BLACK,1,1);HARDWARE_play_sound("schoolbell",127,44100,0);}
	if(CLOCK_hour==7&&CLOCK_second==0&&CLOCK_minute==35){CAPTION_make_caption(NULL,1,80,80,5,"Late for class!",FONT_SMALL_ID,WHITE,BLACK,1,1);HARDWARE_play_sound("schoolbell",127,44100,0);HARDWARE_stop_sound("murmur");}
	if(CLOCK_hour==9&&CLOCK_second==0&&CLOCK_minute==30){CAPTION_make_caption(NULL,1,80,80,5,"Alright! Recess!",FONT_SMALL_ID,WHITE,BLACK,1,1);HARDWARE_play_sound("schoolbell",127,44100,0);}
	if(CLOCK_hour==10&&CLOCK_second==0&&CLOCK_minute==0){CAPTION_make_caption(NULL,1,60,80,5,"Recess over - get to class!",FONT_SMALL_ID,WHITE,BLACK,1,1);HARDWARE_play_sound("schoolbell",127,44100,0);}
	if(CLOCK_hour==10&&CLOCK_second==0&&CLOCK_minute==5){CAPTION_make_caption(NULL,1,80,80,5,"Late for class!",FONT_SMALL_ID,WHITE,BLACK,1,1);HARDWARE_play_sound("schoolbell",127,44100,0);HARDWARE_stop_sound("murmur");}
	if(CLOCK_hour==12&&CLOCK_second==0&&CLOCK_minute==0){CAPTION_make_caption(NULL,1,80,80,5,"Alright! Lunchtime!",FONT_SMALL_ID,WHITE,BLACK,1,1);HARDWARE_play_sound("schoolbell",127,44100,0);}
	if(CLOCK_hour==12+1&&CLOCK_second==0&&CLOCK_minute==0){CAPTION_make_caption(NULL,1,60,80,5,"Lunch is over- get to class!!",FONT_SMALL_ID,WHITE,BLACK,1,1);HARDWARE_play_sound("schoolbell",127,44100,0);}
	if(CLOCK_hour==12+1&&CLOCK_second==0&&CLOCK_minute==5){CAPTION_make_caption(NULL,1,80,80,5,"Late for class!",FONT_SMALL_ID,WHITE,BLACK,1,1);HARDWARE_play_sound("schoolbell",127,44100,0);HARDWARE_stop_sound("murmur");}
	if(CLOCK_hour==12+3&&CLOCK_second==0&&CLOCK_minute==0){CAPTION_make_caption(NULL,1,80,80,5,"Alright! Recess!",FONT_SMALL_ID,WHITE,BLACK,1,1);HARDWARE_play_sound("schoolbell",127,44100,0);}
	if(CLOCK_hour==12+3&&CLOCK_second==0&&CLOCK_minute==30){CAPTION_make_caption(NULL,1,60,80,5,"Recess over - get to special class!",FONT_SMALL_ID,WHITE,BLACK,1,1);HARDWARE_play_sound("schoolbell",127,44100,0);}
	if(CLOCK_hour==12+3&&CLOCK_second==0&&CLOCK_minute==35){CAPTION_make_caption(NULL,1,70,80,5,"Late for special class!",FONT_SMALL_ID,WHITE,BLACK,1,1);HARDWARE_play_sound("schoolbell",127,44100,0);HARDWARE_stop_sound("murmur");}
	if(CLOCK_hour==12+4&&CLOCK_second==0&&CLOCK_minute==30){CAPTION_make_caption(NULL,1,80,80,5,"School's OUT!",FONT_SMALL_ID,WHITE,BLACK,1,1);HARDWARE_play_sound("schoolbell",127,44100,0);}
		if(CLOCK_hour==12+5)HARDWARE_stop_sound("murmur");
}

void bobsgame_SCHOOLEntranceHallway_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_SCHOOLEntranceHallway_Map_VBL_Function()
{

}

void bobsgame_SCHOOLEntranceHallway_Map_HBL_Function()
{

}

//========================================================
//SCHOOLGymHallway
//========================================================
void bobsgame_SCHOOLGymHallway_Map_Load_Function()
{
//RANGE_SCHOOLGymHallwayToEntranceHallwayLeft 7*8,53*8,15*8,54*8
//RANGE_SCHOOLGymHallwayToEntranceHallwayMiddle 100*8,53*8,108*8,54*8
//RANGE_SCHOOLGymHallwayToClassHallwayLeft 7*8,10*8,15*8,11*8
//RANGE_SCHOOLGymHallwayToMusicRoom 38*8,38*8,42*8,39*8
//RANGE_SCHOOLGymHallwayToArtRoom 78*8,38*8,82*8,39*8
//RANGE_SCHOOLGymHallwayToComputerLab 118*8,38*8,122*8,39*8
//RANGE_SCHOOLGymHallwayToKitchen 146*8,38*8,150*8,39*8
//RANGE_SCHOOLGymHallwayToGymCafeteria 156*8,44*8,157*8,49*8
}

void bobsgame_SCHOOLGymHallway_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//7:00-7:35 kids flooding from left and middle bottom hallway, to upper left hallway
//lunchroom 155 47
//comp lab 119 40
//middle hallway 104 52
//art room 81 40
//music room  41 39
//left hallway 10 52
//top left hallway 10 12
	static NPC* randomkids_npcs[40]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	int randamount=40;
		int c=0;
	int hi=0;
	for(c=0;c<randamount;c++)
	{
		if(randomkids_npcs[c]!=NULL)hi++;
	}
	if(hi==0) {HARDWARE_stop_sound("murmur");}
	else {HARDWARE_play_sound_if_not_playing("murmur",127,50000,1);}
	if(CLOCK_hour==7)
	{
		if(CLOCK_minute<=35)
		{
			//entering kids flooding out
			int c=0;
			for(c=0;c<randamount;c++)
			if(randomkids_npcs[c]==NULL&&vbl_10_var%10==c%10)
			{
				int cycle=r(2);
				if(cycle==0)
				{
					int x=(10+r(3))*8;
					int y=52*8;
					if(MAP_is_xy_within_screen_by_64px(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					else
					{
						int randnum=r(2);
						int x=MAP_cam_x-16;
						if(randnum==1)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
						int y=48*8;//touchmap_cam_y*2+r(384);
						if(!NPC_cant_create_at_xy(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					}
				}
				if(cycle==1)
				{
					int x=(103+r(3))*8;
					int y=52*8;
					if(MAP_is_xy_within_screen_by_64px(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					else
					{
						int randnum=r(2);
						int x=MAP_cam_x-16;
						if(randnum==1)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
						int y=48*8;//touchmap_cam_y*2+r(384);
						if(!NPC_cant_create_at_xy(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					}
				}
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->walking_speed = SPEED_FASTER+r(SPEED_SLOWEST-SPEED_FASTEST);
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->AI=cycle;
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->non_walkable=1;
			}
		}
			int c=0;
		for(c=0;c<randamount;c++)
		if(randomkids_npcs[c]!=NULL)
		{
			if(randomkids_npcs[c]!=NULL)if(randomkids_npcs[c]->AI==0)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, randomkids_npcs[c]->MAP_x+8, 48*8)==1)randomkids_npcs[c]->AI=2;
			if(randomkids_npcs[c]!=NULL)if(randomkids_npcs[c]->AI==1)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, randomkids_npcs[c]->MAP_x+8, 47*8)==1)randomkids_npcs[c]->AI=2;
			if(randomkids_npcs[c]!=NULL)if(randomkids_npcs[c]->AI==2)if((randomkids_npcs[c]->MAP_x<=9*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, ( 8+(c%3))*8, 48*8)==1){randomkids_npcs[c]->AI++;}

			if(randomkids_npcs[c]!=NULL)if(randomkids_npcs[c]->AI==3)if(randomkids_npcs[c]->MAP_y<=9*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, ( 8+(c%3))*8, 12*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(randomkids_npcs[c]!=NULL)if(MAP_is_xy_within_screen_by_64px(randomkids_npcs[c]->MAP_x,randomkids_npcs[c]->MAP_y)==0){NPC_delete_npc(&randomkids_npcs[c]);}
		}
	}
//12:00-12:10 kids flooding from upper left hallway into gym right hallway
//lunchroom 155 47
//comp lab 119 40
//middle hallway 104 52
//art room 81 40
//music room  41 39
//left hallway 10 52
//top left hallway 10 12
	if(CLOCK_hour==12)
	{
		if(CLOCK_minute<10)
		{
			//entering kids flooding out
			int c=0;
			for(c=0;c<randamount;c++)
			if(randomkids_npcs[c]==NULL&&vbl_10_var%10==c%10)
			{
				int cycle=0;
				if(cycle==0)
				{
					int x=(10+r(3))*8;
					int y=12*8;
					if(MAP_is_xy_within_screen_by_64px(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					else
					{
						int randnum=r(2);
						int x=MAP_cam_x-16;
						if(randnum==1)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
						int y=48*8;//touchmap_cam_y*2+r(384);
						if(!NPC_cant_create_at_xy(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					}
				}
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->walking_speed = SPEED_FASTER+r(SPEED_SLOWEST-SPEED_FASTEST);
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->AI=cycle;
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->non_walkable=1;
			}
		}
			int c=0;
		for(c=0;c<randamount;c++)
		if(randomkids_npcs[c]!=NULL)
		{
			if(randomkids_npcs[c]->AI==0)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, randomkids_npcs[c]->MAP_x+8, 48*8)==1)randomkids_npcs[c]->AI=1;
			if(randomkids_npcs[c]->AI==1)if(randomkids_npcs[c]->MAP_x>=153*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, 155*8, (46+(c%3))*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(MAP_is_xy_within_screen_by_64px(randomkids_npcs[c]->MAP_x,randomkids_npcs[c]->MAP_y)==0){NPC_delete_npc(&randomkids_npcs[c]);}
		}
	}
//1:00-1:05 kids flooding out of gym to upper left hallway
//lunchroom 155 47
//comp lab 119 40
//middle hallway 104 52
//art room 81 40
//music room  41 39
//left hallway 10 52
//top left hallway 10 12
	if(CLOCK_hour==12+1)
	{
		if(CLOCK_minute<5)
		{
			//entering kids flooding out
			int c=0;
			for(c=0;c<randamount;c++)
			if(randomkids_npcs[c]==NULL&&vbl_10_var%10==c%10)
			{
				int cycle=0;
				if(cycle==0)
				{
					int x=155*8;
					int y=47*8;
					if(MAP_is_xy_within_screen_by_64px(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					else
					{
						int randnum=r(2);
						int x=MAP_cam_x-16;
						if(randnum==1)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
						int y=48*8;//touchmap_cam_y*2+r(384);
						if(!NPC_cant_create_at_xy(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					}
				}
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->walking_speed = SPEED_FASTER+r(SPEED_SLOWEST-SPEED_FASTEST);
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->AI=cycle;
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->non_walkable=1;
			}
		}
			int c=0;
		for(c=0;c<randamount;c++)
		if(randomkids_npcs[c]!=NULL)
		{
			if(randomkids_npcs[c]->AI==0)if(randomkids_npcs[c]->MAP_x<=9*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, 10*8, randomkids_npcs[c]->MAP_y+randomkids_npcs[c]->size_y-randomkids_npcs[c]->hitsize_y)==1)randomkids_npcs[c]->AI=1;
			if(randomkids_npcs[c]->AI==1)if(randomkids_npcs[c]->MAP_y<=9*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, 10*8, 12*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(MAP_is_xy_within_screen_by_64px(randomkids_npcs[c]->MAP_x,randomkids_npcs[c]->MAP_y)==0){NPC_delete_npc(&randomkids_npcs[c]);}
		}
	}
//3:30-3:35 kids flooding from upper left hallway to all classrooms and gym
//lunchroom 155 47
//comp lab 119 40
//middle hallway 104 52
//art room 81 40
//music room  41 39
//left hallway 10 52
//top left hallway 10 12
	if(CLOCK_hour==12+3)
	{
		if(CLOCK_minute>=30&&CLOCK_minute<35)
		{
			//entering kids flooding out
			int c=0;
			for(c=0;c<randamount;c++)
			if(randomkids_npcs[c]==NULL&&vbl_10_var%10==c%10)
			{
				int cycle=0;
				if(cycle==0)
				{
					int x=(10+r(3))*8;
					int y=12*8;
					if(MAP_is_xy_within_screen_by_64px(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					else
					{
						int randnum=r(2);
						int x=MAP_cam_x-16;
						if(randnum==1)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
						int y=48*8;//touchmap_cam_y*2+r(384);
						if(!NPC_cant_create_at_xy(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					}
				}
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->walking_speed = SPEED_FASTER+r(SPEED_SLOWEST-SPEED_FASTEST);
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->AI=0;
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->non_walkable=1;
			}
		}
			int c=0;
		for(c=0;c<randamount;c++)
		if(randomkids_npcs[c]!=NULL)
		{
			if(randomkids_npcs[c]->AI==0)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, randomkids_npcs[c]->MAP_x+8, 48*8)==1)randomkids_npcs[c]->AI=(r(4))+1;
			if(randomkids_npcs[c]->AI==1)if((randomkids_npcs[c]->MAP_x>=153*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, 155*8, randomkids_npcs[c]->MAP_y+randomkids_npcs[c]->size_y-randomkids_npcs[c]->hitsize_y)==1)randomkids_npcs[c]->AI+=4;
			if(randomkids_npcs[c]->AI==2)if((randomkids_npcs[c]->MAP_x>=116*8&&randomkids_npcs[c]->MAP_x<=122*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, 119*8, randomkids_npcs[c]->MAP_y+randomkids_npcs[c]->size_y-randomkids_npcs[c]->hitsize_y)==1)randomkids_npcs[c]->AI+=4;
			if(randomkids_npcs[c]->AI==3)if((randomkids_npcs[c]->MAP_x>=78*8&&randomkids_npcs[c]->MAP_x<=84*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, 81*8, randomkids_npcs[c]->MAP_y+randomkids_npcs[c]->size_y-randomkids_npcs[c]->hitsize_y)==1)randomkids_npcs[c]->AI+=4;
			if(randomkids_npcs[c]->AI==4)if((randomkids_npcs[c]->MAP_x>=38*8&&randomkids_npcs[c]->MAP_x<=44*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, 41*8, randomkids_npcs[c]->MAP_y+randomkids_npcs[c]->size_y-randomkids_npcs[c]->hitsize_y)==1)randomkids_npcs[c]->AI+=4;
			if(randomkids_npcs[c]->AI==5)if((randomkids_npcs[c]->MAP_x>=153*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, 155*8, 47*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(randomkids_npcs[c]->AI==6)if((randomkids_npcs[c]->MAP_y<=37*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, 119*8, 40*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(randomkids_npcs[c]->AI==7)if((randomkids_npcs[c]->MAP_y<=37*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, 81*8, 40*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(randomkids_npcs[c]->AI==8)if((randomkids_npcs[c]->MAP_y<=37*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, 41*8, 40*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(MAP_is_xy_within_screen_by_64px(randomkids_npcs[c]->MAP_x,randomkids_npcs[c]->MAP_y)==0){NPC_delete_npc(&randomkids_npcs[c]);}
		}
	}
//4:30-5:00 kids flooding out of upper left hallway and gym and all classrooms to lower left and middle hallways
//lunchroom 155 47
//comp lab 119 40
//middle hallway 104 52
//art room 81 40
//music room  41 39
//left hallway 10 52
//top left hallway 10 12
	if(CLOCK_hour==12+4)
	{
		if(CLOCK_minute>=30&&CLOCK_minute<55)
		{
			//entering kids flooding out
			int c=0;
			for(c=0;c<randamount;c++)
			if(randomkids_npcs[c]==NULL&&vbl_10_var%10==c%10)
			{
				int cycle=r(5);
				if(cycle==0)
				{
					int x=(10+r(3))*8;
					int y=12*8;
					if(MAP_is_xy_within_screen_by_64px(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					else
					{
						int randnum=r(2);
						int x=MAP_cam_x-16;
						if(randnum==1)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
						int y=48*8;//touchmap_cam_y*2+r(384);
						if(!NPC_cant_create_at_xy(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					}
				}
				if(cycle==1)
				{
					int x=154*8;
					int y=(45+(r(3)))*8;
					if(MAP_is_xy_within_screen_by_64px(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					else
					{
						int randnum=r(2);
						int x=MAP_cam_x-16;
						if(randnum==1)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
						int y=48*8;//touchmap_cam_y*2+r(384);
						if(!NPC_cant_create_at_xy(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					}
				}
				if(cycle==2)
				{
					int x=(118+r(3))*8;
					int y=40*8;
					if(MAP_is_xy_within_screen_by_64px(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					else
					{
						int randnum=r(2);
						int x=MAP_cam_x-16;
						if(randnum==1)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
						int y=48*8;//touchmap_cam_y*2+r(384);
						if(!NPC_cant_create_at_xy(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					}
				}
				if(cycle==3)
				{
					int x=(80+r(3))*8;
					int y=40*8;
					if(MAP_is_xy_within_screen_by_64px(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					else
					{
						int randnum=r(2);
						int x=MAP_cam_x-16;
						if(randnum==1)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
						int y=48*8;//touchmap_cam_y*2+r(384);
						if(!NPC_cant_create_at_xy(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					}
				}
				if(cycle==4)
				{
					int x=(40+r(3))*8;
					int y=40*8;
					if(MAP_is_xy_within_screen_by_64px(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					else
					{
						int randnum=r(2);
						int x=MAP_cam_x-16;
						if(randnum==1)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
						int y=48*8;//touchmap_cam_y*2+r(384);
						if(!NPC_cant_create_at_xy(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					}
				}
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->walking_speed = SPEED_FASTER+r(SPEED_SLOWEST-SPEED_FASTEST);
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->AI=0;
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->non_walkable=1;
			}
		}
			int c=0;
		for(c=0;c<randamount;c++)
		if(randomkids_npcs[c]!=NULL)
		{
			if(randomkids_npcs[c]->AI==0)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, randomkids_npcs[c]->MAP_x+8, 48*8)==1)randomkids_npcs[c]->AI=(r(2))+1;
			if(randomkids_npcs[c]->AI==1)if((randomkids_npcs[c]->MAP_x<=9*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, 10*8, 48*8)==1)randomkids_npcs[c]->AI+=2;
			if(randomkids_npcs[c]->AI==2)if((randomkids_npcs[c]->MAP_x<=107*8&&randomkids_npcs[c]->MAP_x>=100*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, 104*8, 48*8)==1)randomkids_npcs[c]->AI+=2;
			if(randomkids_npcs[c]->AI==3)if((randomkids_npcs[c]->MAP_y>=47*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, 10*8, 52*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(randomkids_npcs[c]->AI==4)if((randomkids_npcs[c]->MAP_y>=47*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, 104*8, 52*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(MAP_is_xy_within_screen_by_64px(randomkids_npcs[c]->MAP_x,randomkids_npcs[c]->MAP_y)==0){NPC_delete_npc(&randomkids_npcs[c]);}
		}
	}
//=================================================================================================================
//ACTIONS
//=================================================================================================================
	if(walking_into_door(RANGE_SCHOOLGymHallwayToEntranceHallwayLeft)){MAP_change_map(MAP_bobsgame_SCHOOLEntranceHallway,11,11);return;}
	if(walking_into_door(RANGE_SCHOOLGymHallwayToEntranceHallwayMiddle)){MAP_change_map(MAP_bobsgame_SCHOOLEntranceHallway,103,11);return;}
	if(walking_into_door(RANGE_SCHOOLGymHallwayToClassHallwayLeft)){MAP_change_map(MAP_bobsgame_SCHOOLClassHallway,10,52);return;}
		if(walking_into_door(RANGE_SCHOOLGymHallwayToMusicRoom))
	{
		if(demobutton||(CLOCK_day==MONDAY&&((CLOCK_hour==12+3&&CLOCK_minute>=30)||(CLOCK_hour==12+4&&CLOCK_minute<=30)))){MAP_change_map(MAP_bobsgame_SCHOOLMusicRoom,21,38);return;}
		else
		if(ACTION_check("Check Music Room Door"))
		{
			TEXT_set_sprite_window(0,PLAYER_npc,NULL);
			TEXT_window("Music classes are on Mondays. The music teacher is clearly emotionally unstable. I always get stuck with the triangle. I hate Mondays.");
		}
	}
	if(walking_into_door(RANGE_SCHOOLGymHallwayToArtRoom))
	{
		if(demobutton||(CLOCK_day==THURSDAY&&((CLOCK_hour==12+3&&CLOCK_minute>=30)||(CLOCK_hour==12+4&&CLOCK_minute<=30)))){MAP_change_map(MAP_bobsgame_SCHOOLArtRoom,21,38);return;}
		else
		if(ACTION_check("Check Art Room Door"))
		{
			TEXT_set_sprite_window(0,PLAYER_npc,NULL);
			TEXT_window("Art classes are on Thursdays. I heard the principal volunteered to be a nude model. That's creepy.");
		}
	}
	if(walking_into_door(RANGE_SCHOOLGymHallwayToComputerLab))
	{
		if(demobutton||(CLOCK_day==THURSDAY&&((CLOCK_hour==12+3&&CLOCK_minute>=30)||(CLOCK_hour==12+4&&CLOCK_minute<=30)))){MAP_change_map(MAP_bobsgame_SCHOOLComputerLab,21,38);return;}
		else
		if(ACTION_check("Check Computer Lab Door"))
		{
			TEXT_set_sprite_window(0,PLAYER_npc,NULL);
			TEXT_window("Computer classes are on Fridays. The PC teacher could use a tan.");
		}
	}
	if(walking_into_door(RANGE_SCHOOLGymHallwayToKitchen))
	{
		if(demobutton||((CLOCK_hour==11&&CLOCK_minute>=30)||(CLOCK_hour==12))){MAP_change_map(MAP_bobsgame_SCHOOLKitchen,9,38);return;}
		else
		if(ACTION_check("Check Kitchen Door"))
		{
			TEXT_set_sprite_window(0,PLAYER_npc,NULL);
			TEXT_window("The kitchen is locked to keep kids from devouring all the delicious mexican pizzas.");
		}
	}
	if(walking_into_door(RANGE_SCHOOLGymHallwayToGymCafeteria))
	{
		if(demobutton||(CLOCK_hour==12)){MAP_change_map(MAP_bobsgame_SCHOOLGymCafeteria,2,42);return;}
		else
		if(CLOCK_day==TUESDAY&&((CLOCK_hour==12+3&&CLOCK_minute>=30)||(CLOCK_hour==12+4&&CLOCK_minute<=30))){MAP_change_map(MAP_bobsgame_SCHOOLGymGym,2,42);return;}
		else
		if(ACTION_check("Check Gymnasium Door"))
		{
			TEXT_set_sprite_window(0,PLAYER_npc,NULL);
			if(CLOCK_hour<12)TEXT_window("The gym is closed. Maybe it's being set up for lunchtime.");
			if(CLOCK_hour>12)TEXT_window("The gym is closed. I guess they're cleaning up the mess from lunch.");
		}
	}
	//bell rings at 7:30, 7:35, 9:30, 10:00, 10:05, 12:00, 1:00, 1:05, 3:00, 3:30, 3:35, 4:30
	if(CLOCK_hour==7&&CLOCK_second==0&&CLOCK_minute==30){CAPTION_make_caption(NULL,1,60,80,5,"School is starting! Get to class!",FONT_SMALL_ID,WHITE,BLACK,1,1);HARDWARE_play_sound("schoolbell",127,44100,0);}
	if(CLOCK_hour==7&&CLOCK_second==0&&CLOCK_minute==35){CAPTION_make_caption(NULL,1,80,80,5,"Late for class!",FONT_SMALL_ID,WHITE,BLACK,1,1);HARDWARE_play_sound("schoolbell",127,44100,0);HARDWARE_stop_sound("murmur");}
	if(CLOCK_hour==9&&CLOCK_second==0&&CLOCK_minute==30){CAPTION_make_caption(NULL,1,80,80,5,"Alright! Recess!",FONT_SMALL_ID,WHITE,BLACK,1,1);HARDWARE_play_sound("schoolbell",127,44100,0);}
	if(CLOCK_hour==10&&CLOCK_second==0&&CLOCK_minute==0){CAPTION_make_caption(NULL,1,60,80,5,"Recess over - get to class!",FONT_SMALL_ID,WHITE,BLACK,1,1);HARDWARE_play_sound("schoolbell",127,44100,0);}
	if(CLOCK_hour==10&&CLOCK_second==0&&CLOCK_minute==5){CAPTION_make_caption(NULL,1,80,80,5,"Late for class!",FONT_SMALL_ID,WHITE,BLACK,1,1);HARDWARE_play_sound("schoolbell",127,44100,0);HARDWARE_stop_sound("murmur");}
	if(CLOCK_hour==12&&CLOCK_second==0&&CLOCK_minute==0){CAPTION_make_caption(NULL,1,80,80,5,"Alright! Lunchtime!",FONT_SMALL_ID,WHITE,BLACK,1,1);HARDWARE_play_sound("schoolbell",127,44100,0);}
	if(CLOCK_hour==12+1&&CLOCK_second==0&&CLOCK_minute==0){CAPTION_make_caption(NULL,1,60,80,5,"Lunch is over- get to class!!",FONT_SMALL_ID,WHITE,BLACK,1,1);HARDWARE_play_sound("schoolbell",127,44100,0);}
	if(CLOCK_hour==12+1&&CLOCK_second==0&&CLOCK_minute==5){CAPTION_make_caption(NULL,1,80,80,5,"Late for class!",FONT_SMALL_ID,WHITE,BLACK,1,1);HARDWARE_play_sound("schoolbell",127,44100,0);HARDWARE_stop_sound("murmur");}
	if(CLOCK_hour==12+3&&CLOCK_second==0&&CLOCK_minute==0){CAPTION_make_caption(NULL,1,80,80,5,"Alright! Recess!",FONT_SMALL_ID,WHITE,BLACK,1,1);HARDWARE_play_sound("schoolbell",127,44100,0);}
	if(CLOCK_hour==12+3&&CLOCK_second==0&&CLOCK_minute==30){CAPTION_make_caption(NULL,1,60,80,5,"Recess over - get to special class!",FONT_SMALL_ID,WHITE,BLACK,1,1);HARDWARE_play_sound("schoolbell",127,44100,0);}
	if(CLOCK_hour==12+3&&CLOCK_second==0&&CLOCK_minute==35){CAPTION_make_caption(NULL,1,70,80,5,"Late for special class!",FONT_SMALL_ID,WHITE,BLACK,1,1);HARDWARE_play_sound("schoolbell",127,44100,0);HARDWARE_stop_sound("murmur");}
	if(CLOCK_hour==12+4&&CLOCK_second==0&&CLOCK_minute==30){CAPTION_make_caption(NULL,1,80,80,5,"School's OUT!",FONT_SMALL_ID,WHITE,BLACK,1,1);HARDWARE_play_sound("schoolbell",127,44100,0);}
}

void bobsgame_SCHOOLGymHallway_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_SCHOOLGymHallway_Map_VBL_Function()
{

}

void bobsgame_SCHOOLGymHallway_Map_HBL_Function()
{

}

//========================================================
//SCHOOLClassHallway
//========================================================
void bobsgame_SCHOOLClassHallway_Map_Load_Function()
{
//RANGE_SCHOOLClassHallwayToGymHallwayLeft 7*8,53*8,15*8,54*8
//RANGE_SCHOOLClassHallwayToBackHallwayLeft 7*8,10*8,15*8,11*8
//RANGE_SCHOOLClassHallwayToLibrary 37*8,38*8,45*8,39*8
//RANGE_SCHOOLClassHallwayToClassroom4 86*8,38*8,90*8,39*8
//RANGE_SCHOOLClassHallwayToClassroom5 126*8,38*8,130*8,39*8
//RANGE_SCHOOLClassHallwayToClassroom6 166*8,38*8,170*8,39*8
//RANGE_SCHOOLClassHallwayToGymCafeteria 193*8,53*8,201*8,54*8
//RANGE_SCHOOLClassHallwayToBackHallwayRight 193*8,10*8,201*8,11*8
}

void bobsgame_SCHOOLClassHallway_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//kids flooding out of class based on time
//kids standing at lockers
//kids coming out of classrooms.
//random crowds left/right?
//6th classroom  169,40
//5th 128,40
//4th 88 40
//lunchroom 197,53
//hallway left up 11,12  down 11,52
//hallway right up 197, 12  down 197,12
//=================================================================================================================
//7:00-7:35 kids coming from hallways into class
//=================================================================================================================
//hallway left up 11,12  down 11,52
//hallway right up 197, 12  down 197,12
//if in range of hallway, kids get made at bottom hall.
//half walk towards classes, half walk to upper hallway
//else kids get made at touchmapcamx-16 and walk into classes
//6th classroom 169,40
//5th classroom 128,40
//4th classroom 88 40
	static NPC* randomkids_npcs[40]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	int randamount=40;
		int c=0;
	int hi=0;
	for(c=0;c<randamount;c++)
	{
		if(randomkids_npcs[c]!=NULL)hi++;
	}
	if(hi==0) {HARDWARE_stop_sound("murmur");}
	else {HARDWARE_play_sound_if_not_playing("murmur",127,50000,1);}
	if(CLOCK_hour==7)
	{
		if(CLOCK_minute<35)
		{
			//entering kids flooding out
			int c=0;
			for(c=0;c<randamount;c++)
			if(randomkids_npcs[c]==NULL&&vbl_10_var%10==c%10)
			{
				int cycle=r(2);
				if(cycle==0)
				{
					int x=(10+r(3))*8;
					int y=52*8;
					if(MAP_is_xy_within_screen_by_64px(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					else
					{
						int randnum=r(2);
						int x=MAP_cam_x-16;
						if(randnum==1)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
						int y=48*8;//touchmap_cam_y*2+r(384);
						if(!NPC_cant_create_at_xy(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					}
				}
				if(cycle==1)
				{
					int x=(196+r(3))*8;
					int y=52*8;
					if(MAP_is_xy_within_screen_by_64px(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					else
					{
						int randnum=r(2);
						int x=MAP_cam_x-16;
						if(randnum==1)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
						int y=48*8;//touchmap_cam_y*2+r(384);
						if(!NPC_cant_create_at_xy(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					}
				}
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->walking_speed = SPEED_FASTER+r(SPEED_SLOWEST-SPEED_FASTEST);
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->AI=cycle;
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->non_walkable=1;
			}
		}
			int c=0;
		for(c=0;c<randamount;c++)
		if(randomkids_npcs[c]!=NULL)
		{
			if(randomkids_npcs[c]->AI==0)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, randomkids_npcs[c]->MAP_x+8, 48*8)==1)randomkids_npcs[c]->AI=(r(5))+2;
			if(randomkids_npcs[c]->AI==1)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, randomkids_npcs[c]->MAP_x+8, 47*8)==1)randomkids_npcs[c]->AI=(r(5))+2;
			if(randomkids_npcs[c]->AI==2)if((randomkids_npcs[c]->MAP_x>=85*8&&randomkids_npcs[c]->MAP_x<=93*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, ( 88+(c%3))*8, 48*8)==1){randomkids_npcs[c]->AI+=5;}
			if(randomkids_npcs[c]->AI==3)if((randomkids_npcs[c]->MAP_x>=125*8&&randomkids_npcs[c]->MAP_x<=134*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (128+(c%3))*8, 48*8)==1){randomkids_npcs[c]->AI+=5;}
			if(randomkids_npcs[c]->AI==4)if((randomkids_npcs[c]->MAP_x>=166*8&&randomkids_npcs[c]->MAP_x<=174*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (169+(c%3))*8, 47*8)==1){randomkids_npcs[c]->AI+=5;}
			if(randomkids_npcs[c]->AI==5)if((randomkids_npcs[c]->MAP_x<=9*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, ( 8+(c%3))*8, 48*8)==1){randomkids_npcs[c]->AI+=5;}
			if(randomkids_npcs[c]->AI==6)if((randomkids_npcs[c]->MAP_x>=194*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (196+(c%3))*8, 47*8)==1){randomkids_npcs[c]->AI+=5;}

			if(randomkids_npcs[c]->AI==7)if(randomkids_npcs[c]->MAP_y<=37*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, ( 88+(c%3))*8, 40*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(randomkids_npcs[c]->AI==8)if(randomkids_npcs[c]->MAP_y<=37*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (128+(c%3))*8, 40*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(randomkids_npcs[c]->AI==9)if(randomkids_npcs[c]->MAP_y<=37*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (169+(c%3))*8, 40*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(randomkids_npcs[c]->AI==10)if(randomkids_npcs[c]->MAP_y<=9*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, ( 10+(c%3))*8, 12*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(randomkids_npcs[c]->AI==11)if(randomkids_npcs[c]->MAP_y<=9*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (196+(c%3))*8, 12*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(MAP_is_xy_within_screen_by_64px(randomkids_npcs[c]->MAP_x,randomkids_npcs[c]->MAP_y)==0){NPC_delete_npc(&randomkids_npcs[c]);}
		}
	}
//=================================================================================================================
//9:30-9:35 kids flooding out of classrooms to recess up hallway
//=================================================================================================================
//flooding out of hallways too, down hallway to up hallway
//kids flood to the playground for recess
//6th classroom  169,40
//5th 128,40
//4th 88 40
//hallway left up 11,12  down 11,52
//hallway right up 197, 12  down 197,12
	if(CLOCK_hour==9)
	{
		//exiting kids flooding out
		if(CLOCK_minute>=30&&CLOCK_minute<35)
		{
			int c=0;
			for(c=0;c<randamount;c++)
			if(randomkids_npcs[c]==NULL&&vbl_10_var%10==c%10)
			{
				int cycle=r(3);
				if(cycle==0)
				{
					int x=(168+r(3))*8;
					int y=40*8;
					if(MAP_is_xy_within_screen_by_64px(x,y)){NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);randomkids_npcs[c]->AI=r(2);}
					else
					if(MAP_is_xy_within_screen_by_64px(11*8,52*8)==(1)){NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],11*8,52*8);randomkids_npcs[c]->AI=0;}
					else
					{
						int randnum=r(2);
						int x=MAP_cam_x-16;
						if(randnum==0)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
						int y=48*8;//touchmap_cam_y*2+r(384);
						if(!NPC_cant_create_at_xy(x,y)){NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);randomkids_npcs[c]->AI=randnum;}
					}
				}
				if(cycle==1)
				{
					int x=(127+r(3))*8;
					int y=40*8;
					if(MAP_is_xy_within_screen_by_64px(x,y)){NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);randomkids_npcs[c]->AI=r(2);}
					else
					{
						int randnum=r(2);
						int x=MAP_cam_x-16;
						if(randnum==0)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
						int y=48*8;//touchmap_cam_y*2+r(384);
						if(!NPC_cant_create_at_xy(x,y)){NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);randomkids_npcs[c]->AI=randnum;}
					}
				}
				if(cycle==2)
				{
					int x=(87+r(3))*8;
					int y=40*8;
					if(MAP_is_xy_within_screen_by_64px(x,y)){NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);randomkids_npcs[c]->AI=r(2);}
					else
					if(MAP_is_xy_within_screen_by_64px(197*8,52*8)==(1)){NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],197*8,52*8);randomkids_npcs[c]->AI=1;}
					else
					{
						int randnum=r(2);
						int x=MAP_cam_x-16;
						if(randnum==0)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
						int y=48*8;//touchmap_cam_y*2+r(384);
						if(!NPC_cant_create_at_xy(x,y)){NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);randomkids_npcs[c]->AI=randnum;}
					}
				}
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->walking_speed = SPEED_FASTER+r(SPEED_SLOWEST-SPEED_FASTEST);
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->non_walkable=1;
			}
		}
		int c=0;
		for(c=0;c<randamount;c++)
		if(randomkids_npcs[c]!=NULL)
		{
			if(randomkids_npcs[c]->AI==0)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, randomkids_npcs[c]->MAP_x+8, 47*8)==1)randomkids_npcs[c]->AI+=2;
			if(randomkids_npcs[c]->AI==1)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, randomkids_npcs[c]->MAP_x+8, 48*8)==1)randomkids_npcs[c]->AI+=2;
			if(randomkids_npcs[c]->AI==2)if((randomkids_npcs[c]->MAP_x<=9*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, ( 8+(c%3))*8, 47*8)==1){randomkids_npcs[c]->AI+=2;}
			if(randomkids_npcs[c]->AI==3)if((randomkids_npcs[c]->MAP_x>=194*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (196+(c%3))*8, 48*8)==1){randomkids_npcs[c]->AI+=2;}

			if(randomkids_npcs[c]->AI==4)if(randomkids_npcs[c]->MAP_y<=9*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, ( 10+(c%3))*8, 12*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(randomkids_npcs[c]->AI==5)if(randomkids_npcs[c]->MAP_y<=9*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (196+(c%3))*8, 12*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(MAP_is_xy_within_screen_by_64px(randomkids_npcs[c]->MAP_x,randomkids_npcs[c]->MAP_y)==0){NPC_delete_npc(&randomkids_npcs[c]);}
		}
	}
//=================================================================================================================
//10:00-10:05 kids flooding into class from recess up hallway
//=================================================================================================================
//from up hallway to bottom hallway
//6th classroom  169,40
//5th 128,40
//4th 88 40
//hallway left up 11,12  down 11,52
//hallway right up 197, 12  down 197,12
	if(CLOCK_hour==10)
	{
		if(CLOCK_minute<5)
		{
			//entering kids flooding out
			int c=0;
			for(c=0;c<randamount;c++)
			if(randomkids_npcs[c]==NULL&&vbl_10_var%10==c%10)
			{
				int cycle=r(2);
				if(cycle==0)
				{
					int x=(10+r(3))*8;
					int y=12*8;
					if(MAP_is_xy_within_screen_by_64px(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					else
					{
						int randnum=r(2);
						int x=MAP_cam_x-16;
						if(randnum==1)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
						int y=48*8;//touchmap_cam_y*2+r(384);
						if(!NPC_cant_create_at_xy(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					}
				}
				if(cycle==1)
				{
					int x=(196+r(3))*8;
					int y=12*8;
					if(MAP_is_xy_within_screen_by_64px(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					else
					{
						int randnum=r(2);
						int x=MAP_cam_x-16;
						if(randnum==1)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
						int y=48*8;//touchmap_cam_y*2+r(384);
						if(!NPC_cant_create_at_xy(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					}
				}
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->walking_speed = SPEED_FASTER+r(SPEED_SLOWEST-SPEED_FASTEST);
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->AI=cycle;
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->non_walkable=1;
			}
		}
			int c=0;
		for(c=0;c<randamount;c++)
		if(randomkids_npcs[c]!=NULL)
		{
			if(randomkids_npcs[c]->AI==0)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, randomkids_npcs[c]->MAP_x+8, 48*8)==1)randomkids_npcs[c]->AI=(r(5))+2;
			if(randomkids_npcs[c]->AI==1)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, randomkids_npcs[c]->MAP_x+8, 47*8)==1)randomkids_npcs[c]->AI=(r(5))+2;
			if(randomkids_npcs[c]->AI==2)if((randomkids_npcs[c]->MAP_x>=85*8&&randomkids_npcs[c]->MAP_x<=93*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, ( 88+(c%3))*8, 48*8)==1){randomkids_npcs[c]->AI+=5;}
			if(randomkids_npcs[c]->AI==3)if((randomkids_npcs[c]->MAP_x>=125*8&&randomkids_npcs[c]->MAP_x<=134*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (128+(c%3))*8, 48*8)==1){randomkids_npcs[c]->AI+=5;}
			if(randomkids_npcs[c]->AI==4)if((randomkids_npcs[c]->MAP_x>=166*8&&randomkids_npcs[c]->MAP_x<=174*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (169+(c%3))*8, 47*8)==1){randomkids_npcs[c]->AI+=5;}
			if(randomkids_npcs[c]->AI==5)if((randomkids_npcs[c]->MAP_x<=9*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, ( 8+(c%3))*8, 47*8)==1){randomkids_npcs[c]->AI+=5;}
			if(randomkids_npcs[c]->AI==6)if((randomkids_npcs[c]->MAP_x>=194*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (196+(c%3))*8, 48*8)==1){randomkids_npcs[c]->AI+=5;}

			if(randomkids_npcs[c]->AI==7)if(randomkids_npcs[c]->MAP_y<=37*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, ( 88+(c%3))*8, 40*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(randomkids_npcs[c]->AI==8)if(randomkids_npcs[c]->MAP_y<=37*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (128+(c%3))*8, 40*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(randomkids_npcs[c]->AI==9)if(randomkids_npcs[c]->MAP_y<=37*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (169+(c%3))*8, 40*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(randomkids_npcs[c]->AI==10)if(randomkids_npcs[c]->MAP_y>=47*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, ( 10+(c%3))*8, 52*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(randomkids_npcs[c]->AI==11)if(randomkids_npcs[c]->MAP_y>=47*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (196+(c%3))*8, 52*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(MAP_is_xy_within_screen_by_64px(randomkids_npcs[c]->MAP_x,randomkids_npcs[c]->MAP_y)==0){NPC_delete_npc(&randomkids_npcs[c]);}
		}
	}
//=================================================================================================================
//12:00-12:05//kids flood to gymnasium for lunch
//=================================================================================================================
//top hallway to right down hallway
//6th classroom  169,40
//5th 128,40
//4th 88 40
//hallway left up 11,12  down 11,52
//hallway right up 197, 12  down 197,12
	if(CLOCK_hour==12)
	{
		if(CLOCK_minute<=10)
		{
			//exiting kids flooding out
			int c=0;
			for(c=0;c<randamount;c++)
			if(randomkids_npcs[c]==NULL&&vbl_10_var%10==c%10)
			{
				int cycle=r(3);
				if(cycle==0)
				{
					int x=(168+r(3))*8;
					int y=40*8;
					if(MAP_is_xy_within_screen_by_64px(x,y)){NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);randomkids_npcs[c]->AI=r(2);}
					else
					if(MAP_is_xy_within_screen_by_64px(11*8,12*8)==(1)){NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],11*8,12*8);randomkids_npcs[c]->AI=0;}
					else
					{
						int randnum=r(2);
						int x=MAP_cam_x-16;
						if(randnum==0)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
						int y=48*8;//touchmap_cam_y*2+r(384);
						if(!NPC_cant_create_at_xy(x,y)){NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);randomkids_npcs[c]->AI=randnum;}
					}
				}
				if(cycle==1)
				{
					int x=(127+r(3))*8;
					int y=40*8;
					if(MAP_is_xy_within_screen_by_64px(x,y)){NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);randomkids_npcs[c]->AI=r(2);}
					else
					{
						int randnum=r(2);
						int x=MAP_cam_x-16;
						if(randnum==0)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
						int y=48*8;//touchmap_cam_y*2+r(384);
						if(!NPC_cant_create_at_xy(x,y)){NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);randomkids_npcs[c]->AI=randnum;}
					}
				}
				if(cycle==2)
				{
					int x=(87+r(3))*8;
					int y=40*8;
					if(MAP_is_xy_within_screen_by_64px(x,y)){NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);randomkids_npcs[c]->AI=r(2);}
					else
					if(MAP_is_xy_within_screen_by_64px(197*8,12*8)==(1)){NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],197*8,12*8);randomkids_npcs[c]->AI=1;}
					else
					{
						int randnum=r(2);
						int x=MAP_cam_x-16;
						if(randnum==0)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
						int y=48*8;//touchmap_cam_y*2+r(384);
						if(!NPC_cant_create_at_xy(x,y)){NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);randomkids_npcs[c]->AI=randnum;}
					}
				}
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->walking_speed = SPEED_FASTER+r(SPEED_SLOWEST-SPEED_FASTEST);
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->non_walkable=1;
			}
		}
		int c=0;
		for(c=0;c<randamount;c++)
		if(randomkids_npcs[c]!=NULL)
		{
			if(randomkids_npcs[c]->AI==0)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, randomkids_npcs[c]->MAP_x+8, 47*8)==1)randomkids_npcs[c]->AI+=2;
			if(randomkids_npcs[c]->AI==1)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, randomkids_npcs[c]->MAP_x+8, 48*8)==1)randomkids_npcs[c]->AI+=2;
			if(randomkids_npcs[c]->AI==2)if((randomkids_npcs[c]->MAP_x<=9*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, ( 8+(c%3))*8, 47*8)==1){randomkids_npcs[c]->AI+=2;}
			if(randomkids_npcs[c]->AI==3)if((randomkids_npcs[c]->MAP_x>=194*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (196+(c%3))*8, 48*8)==1){randomkids_npcs[c]->AI+=2;}

			if(randomkids_npcs[c]->AI==4)if(randomkids_npcs[c]->MAP_y>=47*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, ( 10+(c%3))*8, 52*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(randomkids_npcs[c]->AI==5)if(randomkids_npcs[c]->MAP_y>=47*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (196+(c%3))*8, 52*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(MAP_is_xy_within_screen_by_64px(randomkids_npcs[c]->MAP_x,randomkids_npcs[c]->MAP_y)==0){NPC_delete_npc(&randomkids_npcs[c]);}
		}
	}
//=================================================================================================================
//1:00-1:05 back from lunch from bottom right door
//=================================================================================================================
//from bottom hallway to top hallway
//from bottom hallway to classrooms
//6th classroom  169,40
//5th 128,40
//4th 88 40
//hallway left up 11,12  down 11,52
//hallway right up 197, 12  down 197,12
	if(CLOCK_hour==12+1)
	{
		if(CLOCK_minute<5)
		{
			int c=0;
			for(c=0;c<randamount;c++)
			if(randomkids_npcs[c]==NULL&&vbl_10_var%10==c%10)
			{
				int cycle=r(2);
				if(cycle==0)
				{
					int x=(10+r(3))*8;
					int y=52*8;
					if(MAP_is_xy_within_screen_by_64px(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					else
					{
						int randnum=r(2);
						int x=MAP_cam_x-16;
						if(randnum==1)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
						int y=48*8;//touchmap_cam_y*2+r(384);
						if(!NPC_cant_create_at_xy(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					}
				}
				if(cycle==1)
				{
					int x=(196+r(3))*8;
					int y=52*8;
					if(MAP_is_xy_within_screen_by_64px(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					else
					{
						int randnum=r(2);
						int x=MAP_cam_x-16;
						if(randnum==1)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
						int y=48*8;//touchmap_cam_y*2+r(384);
						if(!NPC_cant_create_at_xy(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					}
				}
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->walking_speed = SPEED_FASTER+r(SPEED_SLOWEST-SPEED_FASTEST);
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->AI=cycle;
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->non_walkable=1;
			}
		}
		int c=0;
		for(c=0;c<randamount;c++)
		if(randomkids_npcs[c]!=NULL)
		{
			if(randomkids_npcs[c]->AI==0)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, randomkids_npcs[c]->MAP_x+8, 48*8)==1)randomkids_npcs[c]->AI=(r(5))+2;
			if(randomkids_npcs[c]->AI==1)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, randomkids_npcs[c]->MAP_x+8, 47*8)==1)randomkids_npcs[c]->AI=(r(5))+2;
			if(randomkids_npcs[c]->AI==2)if((randomkids_npcs[c]->MAP_x>=85*8&&randomkids_npcs[c]->MAP_x<=93*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, ( 88+(c%3))*8, 48*8)==1){randomkids_npcs[c]->AI+=5;}
			if(randomkids_npcs[c]->AI==3)if((randomkids_npcs[c]->MAP_x>=125*8&&randomkids_npcs[c]->MAP_x<=134*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (128+(c%3))*8, 48*8)==1){randomkids_npcs[c]->AI+=5;}
			if(randomkids_npcs[c]->AI==4)if((randomkids_npcs[c]->MAP_x>=166*8&&randomkids_npcs[c]->MAP_x<=174*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (169+(c%3))*8, 47*8)==1){randomkids_npcs[c]->AI+=5;}
			if(randomkids_npcs[c]->AI==5)if((randomkids_npcs[c]->MAP_x<=9*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, ( 8+(c%3))*8, 48*8)==1){randomkids_npcs[c]->AI+=5;}
			if(randomkids_npcs[c]->AI==6)if((randomkids_npcs[c]->MAP_x>=194*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (196+(c%3))*8, 47*8)==1){randomkids_npcs[c]->AI+=5;}

			if(randomkids_npcs[c]->AI==7)if(randomkids_npcs[c]->MAP_y<=37*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, ( 88+(c%3))*8, 40*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(randomkids_npcs[c]->AI==8)if(randomkids_npcs[c]->MAP_y<=37*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (128+(c%3))*8, 40*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(randomkids_npcs[c]->AI==9)if(randomkids_npcs[c]->MAP_y<=37*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (169+(c%3))*8, 40*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(randomkids_npcs[c]->AI==10)if(randomkids_npcs[c]->MAP_y<=9*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, ( 10+(c%3))*8, 12*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(randomkids_npcs[c]->AI==11)if(randomkids_npcs[c]->MAP_y<=9*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (196+(c%3))*8, 12*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(MAP_is_xy_within_screen_by_64px(randomkids_npcs[c]->MAP_x,randomkids_npcs[c]->MAP_y)==0){NPC_delete_npc(&randomkids_npcs[c]);}
		}
	}
//=================================================================================================================
//3:00-3:05 out to recess
//=================================================================================================================
//flooding out of hallways too, down hallway to up hallway
//kids flood to the playground for recess
//6th classroom  169,40
//5th 128,40
//4th 88 40
//hallway left up 11,12  down 11,52
//hallway right up 197, 12  down 197,12
	if(CLOCK_hour==12+3&&CLOCK_minute<30)
	{
		if(CLOCK_minute<=10)
		{
			if(CLOCK_minute<=5)
			{
				int c=0;
				for(c=0;c<randamount;c++)
				if(randomkids_npcs[c]==NULL&&vbl_10_var%10==c%10)
				{
					int cycle=r(3);
					if(cycle==0)
					{
						int x=(168+r(3))*8;
						int y=40*8;
						if(MAP_is_xy_within_screen_by_64px(x,y)){NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);randomkids_npcs[c]->AI=r(2);}
						else
						if(MAP_is_xy_within_screen_by_64px(11*8,52*8)==(1)){NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],11*8,52*8);randomkids_npcs[c]->AI=0;}
						else
						{
							int randnum=r(2);
							int x=MAP_cam_x-16;
							if(randnum==0)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
							int y=48*8;//touchmap_cam_y*2+r(384);
							if(!NPC_cant_create_at_xy(x,y)){NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);randomkids_npcs[c]->AI=randnum;}
						}
					}
					if(cycle==1)
					{
						int x=(127+r(3))*8;
						int y=40*8;
						if(MAP_is_xy_within_screen_by_64px(x,y)){NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);randomkids_npcs[c]->AI=r(2);}
						else
						{
							int randnum=r(2);
							int x=MAP_cam_x-16;
							if(randnum==0)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
							int y=48*8;//touchmap_cam_y*2+r(384);
							if(!NPC_cant_create_at_xy(x,y)){NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);randomkids_npcs[c]->AI=randnum;}
						}
					}
					if(cycle==2)
					{
						int x=(87+r(3))*8;
						int y=40*8;
						if(MAP_is_xy_within_screen_by_64px(x,y)){NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);randomkids_npcs[c]->AI=r(2);}
						else
						if(MAP_is_xy_within_screen_by_64px(197*8,52*8)==(1)){NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],197*8,52*8);randomkids_npcs[c]->AI=1;}
						else
						{
							int randnum=r(2);
							int x=MAP_cam_x-16;
							if(randnum==0)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
							int y=48*8;//touchmap_cam_y*2+r(384);
							if(!NPC_cant_create_at_xy(x,y)){NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);randomkids_npcs[c]->AI=randnum;}
						}
					}
					if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->walking_speed = SPEED_FASTER+r(SPEED_SLOWEST-SPEED_FASTEST);
					if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->non_walkable=1;
				}
			}
		}
		int c=0;
		for(c=0;c<randamount;c++)
		if(randomkids_npcs[c]!=NULL)
		{
			if(randomkids_npcs[c]->AI==0)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, randomkids_npcs[c]->MAP_x+8, 47*8)==1)randomkids_npcs[c]->AI+=2;
			if(randomkids_npcs[c]->AI==1)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, randomkids_npcs[c]->MAP_x+8, 48*8)==1)randomkids_npcs[c]->AI+=2;
			if(randomkids_npcs[c]->AI==2)if((randomkids_npcs[c]->MAP_x<=9*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, ( 8+(c%3))*8, 47*8)==1){randomkids_npcs[c]->AI+=2;}
			if(randomkids_npcs[c]->AI==3)if((randomkids_npcs[c]->MAP_x>=194*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (196+(c%3))*8, 48*8)==1){randomkids_npcs[c]->AI+=2;}

			if(randomkids_npcs[c]->AI==4)if(randomkids_npcs[c]->MAP_y<=9*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, ( 10+(c%3))*8, 12*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(randomkids_npcs[c]->AI==5)if(randomkids_npcs[c]->MAP_y<=9*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (196+(c%3))*8, 12*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(MAP_is_xy_within_screen_by_64px(randomkids_npcs[c]->MAP_x,randomkids_npcs[c]->MAP_y)==0){NPC_delete_npc(&randomkids_npcs[c]);}
		}
	}
//=================================================================================================================
//3:30-3:35 from recess to special classes
//=================================================================================================================
	if(CLOCK_hour==12+3)
	{
		if(CLOCK_minute>=30&&CLOCK_minute<35)
		{
			//entering kids flooding out
			int c=0;
			for(c=0;c<randamount;c++)
			if(randomkids_npcs[c]==NULL&&vbl_10_var%10==c%10)
			{
				int cycle=r(2);
				if(cycle==0)
				{
					int x=(10+r(3))*8;
					int y=12*8;
					if(MAP_is_xy_within_screen_by_64px(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					else
					{
						int randnum=r(2);
						int x=MAP_cam_x-16;
						if(randnum==1)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
						int y=48*8;//touchmap_cam_y*2+r(384);
						if(!NPC_cant_create_at_xy(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					}
				}
				if(cycle==1)
				{
					int x=(196+r(3))*8;
					int y=12*8;
					if(MAP_is_xy_within_screen_by_64px(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					else
					{
						int randnum=r(2);
						int x=MAP_cam_x-16;
						if(randnum==1)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
						int y=48*8;//touchmap_cam_y*2+r(384);
						if(!NPC_cant_create_at_xy(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					}
				}
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->walking_speed = SPEED_FASTER+r(SPEED_SLOWEST-SPEED_FASTEST);
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->AI=cycle;
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->non_walkable=1;
			}
		}
			if(CLOCK_minute>=30)
		{
			int c=0;
			for(c=0;c<randamount;c++)
			if(randomkids_npcs[c]!=NULL)
			{
				if(randomkids_npcs[c]->AI==0)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, randomkids_npcs[c]->MAP_x+8, 48*8)==1)randomkids_npcs[c]->AI=(r(3))+2;
				if(randomkids_npcs[c]->AI==1)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, randomkids_npcs[c]->MAP_x+8, 47*8)==1)randomkids_npcs[c]->AI=(r(3))+2;
				if(randomkids_npcs[c]->AI==2)if((randomkids_npcs[c]->MAP_x>=36*8&&randomkids_npcs[c]->MAP_x<=42*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, ( 39+(c%3))*8, 40*8)==1){randomkids_npcs[c]->AI+=3;}
				if(randomkids_npcs[c]->AI==3)if((randomkids_npcs[c]->MAP_x<=9*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, ( 8+(c%3))*8, 47*8)==1){randomkids_npcs[c]->AI+=3;}
				if(randomkids_npcs[c]->AI==4)if((randomkids_npcs[c]->MAP_x>=194*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (196+(c%3))*8, 48*8)==1){randomkids_npcs[c]->AI+=3;}

				if(randomkids_npcs[c]->AI==5) if(randomkids_npcs[c]->MAP_y<=37*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, ( 39+(c%3))*8, 40*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
				if(randomkids_npcs[c]->AI==6)if(randomkids_npcs[c]->MAP_y>=47*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, ( 10+(c%3))*8, 52*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
				if(randomkids_npcs[c]->AI==7)if(randomkids_npcs[c]->MAP_y>=47*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (196+(c%3))*8, 52*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
				if(MAP_is_xy_within_screen_by_64px(randomkids_npcs[c]->MAP_x,randomkids_npcs[c]->MAP_y)==0){NPC_delete_npc(&randomkids_npcs[c]);}
			}
		}
	}
//=================================================================================================================
//4:30 schools out
//=================================================================================================================
	if(CLOCK_hour==12+4)
	{
		if(CLOCK_minute>=30&&CLOCK_minute<=55)
		{
			//entering kids flooding out
			int c=0;
			for(c=0;c<randamount;c++)
			if(randomkids_npcs[c]==NULL&&vbl_10_var%10==c%10)
			{
				int cycle=r(2);
				if(cycle==0)
				{
					int x=(10+r(3))*8;
					int y=12*8;
					if(MAP_is_xy_within_screen_by_64px(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					else
					{
						int randnum=r(2);
						int x=MAP_cam_x-16;
						if(randnum==1)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
						int y=48*8;//touchmap_cam_y*2+r(384);
						if(!NPC_cant_create_at_xy(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					}
				}
				if(cycle==1)
				{
					int x=(196+r(3))*8;
					int y=12*8;
					if(MAP_is_xy_within_screen_by_64px(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					else
					{
						int randnum=r(2);
						int x=MAP_cam_x-16;
						if(randnum==1)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
						int y=48*8;//touchmap_cam_y*2+r(384);
						if(!NPC_cant_create_at_xy(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					}
				}
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->walking_speed = SPEED_FASTEST+r(SPEED_FAST-SPEED_FASTEST);
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->AI=cycle;
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->non_walkable=1;
			}
		}
		//kids come out of classrooms and library??
			int c=0;
		for(c=0;c<randamount;c++)
		if(randomkids_npcs[c]!=NULL)
		{
			if(randomkids_npcs[c]->AI==0)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, randomkids_npcs[c]->MAP_x+8, 48*8)==1)randomkids_npcs[c]->AI=(r(2))+2;
			if(randomkids_npcs[c]->AI==1)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, randomkids_npcs[c]->MAP_x+8, 47*8)==1)randomkids_npcs[c]->AI=(r(2))+2;
			if(randomkids_npcs[c]->AI==2)if((randomkids_npcs[c]->MAP_x<=9*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, ( 8+(c%3))*8, 47*8)==1){randomkids_npcs[c]->AI+=2;}
			if(randomkids_npcs[c]->AI==3)if((randomkids_npcs[c]->MAP_x>=194*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (196+(c%3))*8, 48*8)==1){randomkids_npcs[c]->AI+=2;}

			if(randomkids_npcs[c]->AI==4)if(randomkids_npcs[c]->MAP_y>=47*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, ( 10+(c%3))*8, 52*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(randomkids_npcs[c]->AI==5)if(randomkids_npcs[c]->MAP_y>=47*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (196+(c%3))*8, 52*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(MAP_is_xy_within_screen_by_64px(randomkids_npcs[c]->MAP_x,randomkids_npcs[c]->MAP_y)==0){NPC_delete_npc(&randomkids_npcs[c]);}
		}
	}
//TODO: screaming, loud, really fast children
//=================================================================================================================
//ACTIONS
//=================================================================================================================
	if(walking_into_door(RANGE_SCHOOLClassHallwayToGymHallwayLeft)){MAP_change_map(MAP_bobsgame_SCHOOLGymHallway,10,11);return;}
	if(walking_into_door(RANGE_SCHOOLClassHallwayToBackHallwayLeft)){MAP_change_map(MAP_bobsgame_SCHOOLBackHallway,10,52);return;}
	if(walking_into_door(RANGE_SCHOOLClassHallwayToLibrary))
	{
		//only on WEDNESDAY at 3:30-4:30
		if(demobutton||(CLOCK_day==WEDNESDAY&&((CLOCK_hour==12+3&&CLOCK_minute>=30)||(CLOCK_hour==12+4&&CLOCK_minute<=30)))){MAP_change_map(MAP_bobsgame_SCHOOLLibrary,21,38);return;}
		else
		if(ACTION_check("Check Library Door"))
		{
			TEXT_set_sprite_window(0,PLAYER_npc,NULL);
			TEXT_window("There's a sign on the door. It says \"The Library is currently being used by another class. Please come back later.\"<.>I guess all the books are in use.<.>Our class gets in on Wednesdays.");
		}
	}
		if(walking_into_door(RANGE_SCHOOLClassHallwayToClassroom4))
	{
		//closed during recess, lunch, special class, after school. sooo..
		//between 7:00-9:30||10:00-12:00||1:00-3:00
		//hmm. not my class, only delivering something? talking to the teacher?
		//maybe class should be open at recess, and its a necessary thing to talk to the teachers
		if(demobutton||((CLOCK_hour>=7&&(CLOCK_hour<9||(CLOCK_hour==9&&CLOCK_minute<30)))||(CLOCK_hour>=10&&CLOCK_hour<12)||(CLOCK_hour>12+1&&CLOCK_hour<3))){MAP_change_map(MAP_bobsgame_SCHOOLClassroom4,22,38);return;}
		else
		if(ACTION_check("Check Classroom Door"))
		{
			TEXT_set_sprite_window(0,PLAYER_npc,NULL);
			if(((CLOCK_hour==9&&CLOCK_minute>=30)||(CLOCK_hour==12+3&&CLOCK_minute<30)))TEXT_window("Locked. I'm supposed to be at recess. What am I doing?");
			if(((CLOCK_hour==12&&CLOCK_minute>=0)))TEXT_window("Locked. I'm supposed to be at Lunch. What am I doing?");
			if(((CLOCK_hour==12+3&&CLOCK_minute>=30)))TEXT_window("Locked. I'm supposed to be at special class. What am I doing?");
			if(((CLOCK_hour==12+4&&CLOCK_minute>=30)))TEXT_window("Locked. School is over! I can get out of this place! What am I doing?");
		}
	}
		if(walking_into_door(RANGE_SCHOOLClassHallwayToClassroom5))
	{
		//closed during recess, lunch, special class, after school. sooo..
		//between 7:00-9:30||10:00-12:00||1:00-3:00
		//hmm. not my class, only delivering something? talking to the teacher?
		//maybe class should be open at recess, and its a necessary thing to talk to the teachers
		if(demobutton||((CLOCK_hour>=7&&(CLOCK_hour<9||(CLOCK_hour==9&&CLOCK_minute<30)))||(CLOCK_hour>=10&&CLOCK_hour<12)||(CLOCK_hour>12+1&&CLOCK_hour<3))){MAP_change_map(MAP_bobsgame_SCHOOLClassroom5,22,38);return;}
		else
		if(ACTION_check("Check Classroom Door"))
		{
			TEXT_set_sprite_window(0,PLAYER_npc,NULL);
			if(((CLOCK_hour==9&&CLOCK_minute>=30)||(CLOCK_hour==12+3&&CLOCK_minute<30)))TEXT_window("Locked. I'm supposed to be at recess. What am I doing?");
			if(((CLOCK_hour==12&&CLOCK_minute>=0)))TEXT_window("Locked. I'm supposed to be at Lunch. What am I doing?");
			if(((CLOCK_hour==12+3&&CLOCK_minute>=30)))TEXT_window("Locked. I'm supposed to be at special class. What am I doing?");
			if(((CLOCK_hour==12+4&&CLOCK_minute>=30)))TEXT_window("Locked. School is over! I can get out of this place! What am I doing?");
		}
	}
		if(walking_into_door(RANGE_SCHOOLClassHallwayToClassroom6))
	{
		//closed during recess, lunch, special class, after school. sooo..
		//between 7:00-9:30||10:00-12:00||1:00-3:00
		//hmm. not my class, only delivering something? talking to the teacher?
		//maybe class should be open at recess, and its a necessary thing to talk to the teachers
		if(demobutton||((CLOCK_hour>=7&&(CLOCK_hour<9||(CLOCK_hour==9&&CLOCK_minute<30)))||(CLOCK_hour>=10&&CLOCK_hour<12)||(CLOCK_hour>12+1&&CLOCK_hour<3))){MAP_change_map(MAP_bobsgame_SCHOOLClassroom6,22,38);return;}
		else
		if(ACTION_check("Check Classroom Door"))
		{
			TEXT_set_sprite_window(0,PLAYER_npc,NULL);
			if(((CLOCK_hour==9&&CLOCK_minute>=30)||(CLOCK_hour==12+3&&CLOCK_minute<30)))TEXT_window("Locked. I'm supposed to be at recess. What am I doing?");
			if(((CLOCK_hour==12&&CLOCK_minute>=0)))TEXT_window("Locked. I'm supposed to be at Lunch. What am I doing?");
			if(((CLOCK_hour==12+3&&CLOCK_minute>=30)))TEXT_window("Locked. I'm supposed to be at special class. What am I doing?");
			if(((CLOCK_hour==12+4&&CLOCK_minute>=30)))TEXT_window("Locked. School is over! I can get out of this place! What am I doing?");
		}
	}
		if(walking_into_door(RANGE_SCHOOLClassHallwayToGymCafeteria))
	{
		//only during lunch 12:00-1:00 or on tuesday after 3:30
		//{MAP_change_map(MAP_bobsgame_SCHOOLGymCafeteria,41,11);return;}
		if(demobutton||(CLOCK_hour==12)){MAP_change_map(MAP_bobsgame_SCHOOLGymCafeteria,41,11);return;}
		else
		if(CLOCK_day==TUESDAY&&((CLOCK_hour==12+3&&CLOCK_minute>=30)||(CLOCK_hour==12+4&&CLOCK_minute<=30))){MAP_change_map(MAP_bobsgame_SCHOOLGymGym,41,11);return;}
		else
		if(ACTION_check("Check Gymnasium Door"))
		{
				TEXT_set_sprite_window(0,PLAYER_npc,NULL);
				if(CLOCK_hour<12)TEXT_window("The gym is closed. Maybe it's being set up for lunchtime.");
				if(CLOCK_hour>12)TEXT_window("The gym is closed. I guess they're cleaning up the mess from lunch.");
		}
	}
		if(walking_into_door(RANGE_SCHOOLClassHallwayToBackHallwayRight)){MAP_change_map(MAP_bobsgame_SCHOOLBackHallway,196,52);return;}
	//bell rings at 7:30, 7:35, 9:30, 10:00, 10:05, 12:00, 1:00, 1:05, 3:00, 3:30, 3:35, 4:30
	if(CLOCK_hour==7&&CLOCK_second==0&&CLOCK_minute==30){CAPTION_make_caption(NULL,1,60,80,5,"School is starting! Get to class!",FONT_SMALL_ID,WHITE,BLACK,1,1);HARDWARE_play_sound("schoolbell",127,44100,0);}
	if(CLOCK_hour==7&&CLOCK_second==0&&CLOCK_minute==35){CAPTION_make_caption(NULL,1,80,80,5,"Late for class!",FONT_SMALL_ID,WHITE,BLACK,1,1);HARDWARE_play_sound("schoolbell",127,44100,0);HARDWARE_stop_sound("murmur");}
	if(CLOCK_hour==9&&CLOCK_second==0&&CLOCK_minute==30){CAPTION_make_caption(NULL,1,80,80,5,"Alright! Recess!",FONT_SMALL_ID,WHITE,BLACK,1,1);HARDWARE_play_sound("schoolbell",127,44100,0);}
	if(CLOCK_hour==10&&CLOCK_second==0&&CLOCK_minute==0){CAPTION_make_caption(NULL,1,60,80,5,"Recess over - get to class!",FONT_SMALL_ID,WHITE,BLACK,1,1);HARDWARE_play_sound("schoolbell",127,44100,0);}
	if(CLOCK_hour==10&&CLOCK_second==0&&CLOCK_minute==5){CAPTION_make_caption(NULL,1,80,80,5,"Late for class!",FONT_SMALL_ID,WHITE,BLACK,1,1);HARDWARE_play_sound("schoolbell",127,44100,0);HARDWARE_stop_sound("murmur");}
	if(CLOCK_hour==12&&CLOCK_second==0&&CLOCK_minute==0){CAPTION_make_caption(NULL,1,80,80,5,"Alright! Lunchtime!",FONT_SMALL_ID,WHITE,BLACK,1,1);HARDWARE_play_sound("schoolbell",127,44100,0);}
	if(CLOCK_hour==12+1&&CLOCK_second==0&&CLOCK_minute==0){CAPTION_make_caption(NULL,1,60,80,5,"Lunch is over- get to class!!",FONT_SMALL_ID,WHITE,BLACK,1,1);HARDWARE_play_sound("schoolbell",127,44100,0);}
	if(CLOCK_hour==12+1&&CLOCK_second==0&&CLOCK_minute==5){CAPTION_make_caption(NULL,1,80,80,5,"Late for class!",FONT_SMALL_ID,WHITE,BLACK,1,1);HARDWARE_play_sound("schoolbell",127,44100,0);HARDWARE_stop_sound("murmur");}
	if(CLOCK_hour==12+3&&CLOCK_second==0&&CLOCK_minute==0){CAPTION_make_caption(NULL,1,80,80,5,"Alright! Recess!",FONT_SMALL_ID,WHITE,BLACK,1,1);HARDWARE_play_sound("schoolbell",127,44100,0);}
	if(CLOCK_hour==12+3&&CLOCK_second==0&&CLOCK_minute==30){CAPTION_make_caption(NULL,1,60,80,5,"Recess over - get to special class!",FONT_SMALL_ID,WHITE,BLACK,1,1);HARDWARE_play_sound("schoolbell",127,44100,0);}
	if(CLOCK_hour==12+3&&CLOCK_second==0&&CLOCK_minute==35){CAPTION_make_caption(NULL,1,70,80,5,"Late for special class!",FONT_SMALL_ID,WHITE,BLACK,1,1);HARDWARE_play_sound("schoolbell",127,44100,0);HARDWARE_stop_sound("murmur");}
	if(CLOCK_hour==12+4&&CLOCK_second==0&&CLOCK_minute==30){CAPTION_make_caption(NULL,1,80,80,5,"School's OUT!",FONT_SMALL_ID,WHITE,BLACK,1,1);HARDWARE_play_sound("schoolbell",127,44100,0);}
}

void bobsgame_SCHOOLClassHallway_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_SCHOOLClassHallway_Map_VBL_Function()
{

}

void bobsgame_SCHOOLClassHallway_Map_HBL_Function()
{

}

//========================================================
//SCHOOLBackHallway
//========================================================
void bobsgame_SCHOOLBackHallway_Map_Load_Function()
{
//RANGE_SCHOOLBackHallwayToClassHallwayLeft 7*8,53*8,15*8,54*8
//RANGE_SCHOOLBackHallwayToClassHallwayRight 193*8,53*8,201*8,54*8
//RANGE_SCHOOLBackHallwayToCustodian 4*8,38*8,8*8,39*8
//RANGE_SCHOOLBackHallwayToClassroom3 36*8,38*8,40*8,39*8
//RANGE_SCHOOLBackHallwayToClassroom2 76*8,38*8,80*8,39*8
//RANGE_SCHOOLBackHallwayToClassroom1 147*8,38*8,151*8,39*8
//RANGE_SCHOOLBackHallwayToGirlsBathroom 176*8,38*8,180*8,39*8
//RANGE_SCHOOLBackHallwayToBoysBathroom 195*8,38*8,199*8,39*8
//RANGE_SCHOOLBackHallwayToOUTSIDEPlayground1 103*8,11*8,111*8,12*8
//RANGE_SCHOOLBackHallwayToOUTSIDEPlayground2 115*8,11*8,123*8,12*8
}

void bobsgame_SCHOOLBackHallway_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//class 3  39 40
//class 2  79 40
//playground left 106.13
//playground right 118.13
//class 1 150.40
//left hallway 10.52
//right hallway 196.52
//7:00-7:35 from hallway left and right to classrooms 1 2 3
	static NPC* randomkids_npcs[100]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	int randamount=100;
		int c=0;
	int hi=0;
	for(c=0;c<randamount;c++)
	{
		if(randomkids_npcs[c]!=NULL)hi++;
	}
	if(hi==0) {HARDWARE_stop_sound("murmur");}
	else {HARDWARE_play_sound_if_not_playing("murmur",127,50000,1);}
	if(CLOCK_hour==7)
	{
		if(CLOCK_minute<35)
		{
			//entering kids flooding out
			int c=0;
			for(c=0;c<randamount;c++)
			if(randomkids_npcs[c]==NULL&&vbl_10_var%10==c%10)
			{
				int cycle=r(2);
				if(cycle==0)
				{
					int x=(10+r(3))*8;
					int y=52*8;
					if(MAP_is_xy_within_screen_by_64px(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					else
					{
						int randnum=r(2);
						int x=MAP_cam_x-16;
						if(randnum==1)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
						int y=49*8;//touchmap_cam_y*2+r(384);
						if(!NPC_cant_create_at_xy(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					}
				}
				if(cycle==1)
				{
					int x=(196+r(3))*8;
					int y=52*8;
					if(MAP_is_xy_within_screen_by_64px(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					else
					{
						int randnum=r(2);
						int x=MAP_cam_x-16;
						if(randnum==1)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
						int y=49*8;//touchmap_cam_y*2+r(384);
						if(!NPC_cant_create_at_xy(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					}
				}
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->walking_speed = SPEED_FASTER+r(SPEED_SLOWEST-SPEED_FASTEST);
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->AI=cycle;
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->non_walkable=1;
			}
		}
			int c=0;
		for(c=0;c<randamount;c++)
		if(randomkids_npcs[c]!=NULL)
		{
			if(randomkids_npcs[c]->AI==0)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, randomkids_npcs[c]->MAP_x+8, 49*8)==1)randomkids_npcs[c]->AI=(r(3))+2;
			if(randomkids_npcs[c]->AI==1)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, randomkids_npcs[c]->MAP_x+8, 49*8)==1)randomkids_npcs[c]->AI=(r(3))+2;
			if(randomkids_npcs[c]->AI==2)if((randomkids_npcs[c]->MAP_x>=36*8&&randomkids_npcs[c]->MAP_x<=42*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, ( 38+(c%3))*8, 49*8)==1){randomkids_npcs[c]->AI+=3;}
			if(randomkids_npcs[c]->AI==3)if((randomkids_npcs[c]->MAP_x>=76*8&&randomkids_npcs[c]->MAP_x<=82*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (78+(c%3))*8, 49*8)==1){randomkids_npcs[c]->AI+=3;}
			if(randomkids_npcs[c]->AI==4)if((randomkids_npcs[c]->MAP_x>=148*8&&randomkids_npcs[c]->MAP_x<=153*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (149+(c%3))*8, 49*8)==1){randomkids_npcs[c]->AI+=3;}

			if(randomkids_npcs[c]->AI==5)if(randomkids_npcs[c]->MAP_y<=37*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, ( 38+(c%3))*8, 40*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(randomkids_npcs[c]->AI==6)if(randomkids_npcs[c]->MAP_y<=37*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (78+(c%3))*8, 40*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(randomkids_npcs[c]->AI==7)if(randomkids_npcs[c]->MAP_y<=37*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (149+(c%3))*8, 40*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(MAP_is_xy_within_screen_by_64px(randomkids_npcs[c]->MAP_x,randomkids_npcs[c]->MAP_y)==0){NPC_delete_npc(&randomkids_npcs[c]);}
		}
	}
//9:30-9:35 from hallways left and right and classrooms 1 2 3 to playground 1 2
	if(CLOCK_hour==9)
	{
		if(CLOCK_minute>=30&&CLOCK_minute<35)
		{
			//entering kids flooding out
			int c=0;
			for(c=0;c<randamount;c++)
			if(randomkids_npcs[c]==NULL&&vbl_10_var%10==c%10)
			{
				int cycle=r(3);
				if(cycle==0)
				{
					int x=(10+r(3))*8;
					int y=52*8;
					if(MAP_is_xy_within_screen_by_64px(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					else
					if(MAP_is_xy_within_screen_by_64px(150*8,40*8)==(1))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],150*8,40*8);
					else
					{
						int randnum=r(2);
						int x=MAP_cam_x-16;
						if(randnum==1)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
						int y=48*8;//touchmap_cam_y*2+r(384);
						if(!NPC_cant_create_at_xy(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					}
				}
				if(cycle==1)
				{
					int x=(196+r(3))*8;
					int y=52*8;
					if(MAP_is_xy_within_screen_by_64px(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					else
					if(MAP_is_xy_within_screen_by_64px(39*8,40*8)==(1))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],39*8,40*8);
					else
					{
						int randnum=r(2);
						int x=MAP_cam_x-16;
						if(randnum==1)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
						int y=48*8;//touchmap_cam_y*2+r(384);
						if(!NPC_cant_create_at_xy(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					}
				}
				if(cycle==2)
				{
					if(MAP_is_xy_within_screen_by_64px(79*8,40*8)==(1))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],79*8,40*8);
					else
					{
						int randnum=r(2);
						int x=MAP_cam_x-16;
						if(randnum==1)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
						int y=48*8;//touchmap_cam_y*2+r(384);
						if(!NPC_cant_create_at_xy(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					}
				}
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->walking_speed = SPEED_FASTER+r(SPEED_SLOWEST-SPEED_FASTEST);
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->AI=r(2);
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->non_walkable=1;
			}
		}
			int c=0;
		for(c=0;c<randamount;c++)
		if(randomkids_npcs[c]!=NULL)
		{
			if(randomkids_npcs[c]->AI==0)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, randomkids_npcs[c]->MAP_x+8, 48*8)==1)randomkids_npcs[c]->AI=(r(2))+2;
			if(randomkids_npcs[c]->AI==1)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, randomkids_npcs[c]->MAP_x+8, 48*8)==1)randomkids_npcs[c]->AI=(r(2))+2;
			if(randomkids_npcs[c]->AI==2)if((randomkids_npcs[c]->MAP_x>=100*8&&randomkids_npcs[c]->MAP_x<=104*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, ( 103+(c%3))*8, 48*8)==1){randomkids_npcs[c]->AI+=2;}
			if(randomkids_npcs[c]->AI==3)if((randomkids_npcs[c]->MAP_x>=118*8&&randomkids_npcs[c]->MAP_x<=122*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (120+(c%3))*8, 48*8)==1){randomkids_npcs[c]->AI+=2;}

			if(randomkids_npcs[c]->AI==4)if(randomkids_npcs[c]->MAP_y<=10*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (105+(c%3))*8, 13*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(randomkids_npcs[c]->AI==5)if(randomkids_npcs[c]->MAP_y<=10*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (117+(c%3))*8, 13*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(MAP_is_xy_within_screen_by_64px(randomkids_npcs[c]->MAP_x,randomkids_npcs[c]->MAP_y)==0){NPC_delete_npc(&randomkids_npcs[c]);}
		}
	}
//10:00-10:05 from playground 1 2 to classrooms 1 2 3 and hallways left and right
	if(CLOCK_hour==10)
	{
		if(CLOCK_minute<5)
		{
			//entering kids flooding out
			int c=0;
			for(c=0;c<randamount;c++)
			if(randomkids_npcs[c]==NULL&&vbl_10_var%10==c%10)
			{
				int cycle=r(2);
				if(cycle==0)
				{
					int x=(105+r(3))*8;
					int y=13*8;
					if(MAP_is_xy_within_screen_by_64px(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					else
					{
						int randnum=r(2);
						int x=MAP_cam_x-16;
						if(randnum==1)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
						int y=49*8;//touchmap_cam_y*2+r(384);
						if(!NPC_cant_create_at_xy(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					}
				}
				if(cycle==1)
				{
					int x=(117+r(3))*8;
					int y=13*8;
					if(MAP_is_xy_within_screen_by_64px(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					else
					{
						int randnum=r(2);
						int x=MAP_cam_x-16;
						if(randnum==1)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
						int y=49*8;//touchmap_cam_y*2+r(384);
						if(!NPC_cant_create_at_xy(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					}
				}
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->walking_speed = SPEED_FASTER+r(SPEED_SLOWEST-SPEED_FASTEST);
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->AI=cycle;
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->non_walkable=1;
			}
		}
			int c=0;
		for(c=0;c<randamount;c++)
		if(randomkids_npcs[c]!=NULL)
		{
			if(randomkids_npcs[c]->AI==0)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, randomkids_npcs[c]->MAP_x+8, 49*8)==1)randomkids_npcs[c]->AI=(r(5))+2;
			if(randomkids_npcs[c]->AI==1)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, randomkids_npcs[c]->MAP_x+8, 49*8)==1)randomkids_npcs[c]->AI=(r(5))+2;
			if(randomkids_npcs[c]->AI==2)if((randomkids_npcs[c]->MAP_x>=36*8&&randomkids_npcs[c]->MAP_x<=42*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, ( 38+(c%3))*8, 49*8)==1){randomkids_npcs[c]->AI+=5;}
			if(randomkids_npcs[c]->AI==3)if((randomkids_npcs[c]->MAP_x>=76*8&&randomkids_npcs[c]->MAP_x<=82*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (78+(c%3))*8, 49*8)==1){randomkids_npcs[c]->AI+=5;}
			if(randomkids_npcs[c]->AI==4)if((randomkids_npcs[c]->MAP_x>=148*8&&randomkids_npcs[c]->MAP_x<=153*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (149+(c%3))*8, 49*8)==1){randomkids_npcs[c]->AI+=5;}
			if(randomkids_npcs[c]->AI==5)if((randomkids_npcs[c]->MAP_x<=9*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, ( 8+(c%3))*8, 47*8)==1){randomkids_npcs[c]->AI+=5;}
			if(randomkids_npcs[c]->AI==6)if((randomkids_npcs[c]->MAP_x>=194*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (196+(c%3))*8, 48*8)==1){randomkids_npcs[c]->AI+=5;}

			if(randomkids_npcs[c]->AI==7)if(randomkids_npcs[c]->MAP_y<=37*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, ( 38+(c%3))*8, 40*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(randomkids_npcs[c]->AI==8)if(randomkids_npcs[c]->MAP_y<=37*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (78+(c%3))*8, 40*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(randomkids_npcs[c]->AI==9)if(randomkids_npcs[c]->MAP_y<=37*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (149+(c%3))*8, 40*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(randomkids_npcs[c]->AI==10)if(randomkids_npcs[c]->MAP_y>=47*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, ( 10+(c%3))*8, 52*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(randomkids_npcs[c]->AI==11)if(randomkids_npcs[c]->MAP_y>=47*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (196+(c%3))*8, 52*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(MAP_is_xy_within_screen_by_64px(randomkids_npcs[c]->MAP_x,randomkids_npcs[c]->MAP_y)==0){NPC_delete_npc(&randomkids_npcs[c]);}
		}
	}
//12:00-12:10 from classrooms 1 2 3 to hallways left and right
	if(CLOCK_hour==12)
	{
		if(CLOCK_minute<10)
		{
			//entering kids flooding out
			int c=0;
			for(c=0;c<randamount;c++)
			if(randomkids_npcs[c]==NULL&&vbl_10_var%10==c%10)
			{
				int cycle=r(3);
				if(cycle==0)
				{
					int x=(38+r(3))*8;
					int y=40*8;
					if(MAP_is_xy_within_screen_by_64px(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					else
					{
						int randnum=r(2);
						int x=MAP_cam_x-16;
						if(randnum==1)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
						int y=49*8;//touchmap_cam_y*2+r(384);
						if(!NPC_cant_create_at_xy(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					}
				}
				if(cycle==1)
				{
					int x=(78+r(3))*8;
					int y=40*8;
					if(MAP_is_xy_within_screen_by_64px(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					else
					{
						int randnum=r(2);
						int x=MAP_cam_x-16;
						if(randnum==1)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
						int y=49*8;//touchmap_cam_y*2+r(384);
						if(!NPC_cant_create_at_xy(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					}
				}
				if(cycle==2)
				{
					int x=(149+r(3))*8;
					int y=40*8;
					if(MAP_is_xy_within_screen_by_64px(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					else
					{
						int randnum=r(2);
						int x=MAP_cam_x-16;
						if(randnum==1)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
						int y=49*8;//touchmap_cam_y*2+r(384);
						if(!NPC_cant_create_at_xy(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					}
				}
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->walking_speed = SPEED_FASTER+r(SPEED_SLOWEST-SPEED_FASTEST);
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->AI=r(2);
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->non_walkable=1;
			}
		}
			int c=0;
		for(c=0;c<randamount;c++)
		if(randomkids_npcs[c]!=NULL)
		{
			if(randomkids_npcs[c]->AI==0)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, randomkids_npcs[c]->MAP_x+8, 49*8)==1)randomkids_npcs[c]->AI=(r(2))+2;
			if(randomkids_npcs[c]->AI==1)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, randomkids_npcs[c]->MAP_x+8, 49*8)==1)randomkids_npcs[c]->AI=(r(2))+2;
			if(randomkids_npcs[c]->AI==2)if((randomkids_npcs[c]->MAP_x<=9*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, ( 8+(c%3))*8, 47*8)==1){randomkids_npcs[c]->AI+=2;}
			if(randomkids_npcs[c]->AI==3)if((randomkids_npcs[c]->MAP_x>=194*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (196+(c%3))*8, 48*8)==1){randomkids_npcs[c]->AI+=2;}

			if(randomkids_npcs[c]->AI==4)if(randomkids_npcs[c]->MAP_y>=47*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, ( 10+(c%3))*8, 52*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(randomkids_npcs[c]->AI==5)if(randomkids_npcs[c]->MAP_y>=47*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (196+(c%3))*8, 52*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(MAP_is_xy_within_screen_by_64px(randomkids_npcs[c]->MAP_x,randomkids_npcs[c]->MAP_y)==0){NPC_delete_npc(&randomkids_npcs[c]);}
		}
	}
//1:00-1:05 from hallways left and right to classrooms 1 2 3
	if(CLOCK_hour==12+1)
	{
		if(CLOCK_minute<5)
		{
			//entering kids flooding out
			int c=0;
			for(c=0;c<randamount;c++)
			if(randomkids_npcs[c]==NULL&&vbl_10_var%10==c%10)
			{
				int cycle=r(2);
				if(cycle==0)
				{
					int x=(10+r(3))*8;
					int y=52*8;
					if(MAP_is_xy_within_screen_by_64px(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					else
					{
						int randnum=r(2);
						int x=MAP_cam_x-16;
						if(randnum==1)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
						int y=49*8;//touchmap_cam_y*2+r(384);
						if(!NPC_cant_create_at_xy(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					}
				}
				if(cycle==1)
				{
					int x=(196+r(3))*8;
					int y=52*8;
					if(MAP_is_xy_within_screen_by_64px(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					else
					{
						int randnum=r(2);
						int x=MAP_cam_x-16;
						if(randnum==1)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
						int y=49*8;//touchmap_cam_y*2+r(384);
						if(!NPC_cant_create_at_xy(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					}
				}
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->walking_speed = SPEED_FASTER+r(SPEED_SLOWEST-SPEED_FASTEST);
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->AI=cycle;
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->non_walkable=1;
			}
		}
			int c=0;
		for(c=0;c<randamount;c++)
		if(randomkids_npcs[c]!=NULL)
		{
			if(randomkids_npcs[c]->AI==0)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, randomkids_npcs[c]->MAP_x+8, 49*8)==1)randomkids_npcs[c]->AI=(r(3))+2;
			if(randomkids_npcs[c]->AI==1)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, randomkids_npcs[c]->MAP_x+8, 49*8)==1)randomkids_npcs[c]->AI=(r(3))+2;
			if(randomkids_npcs[c]->AI==2)if((randomkids_npcs[c]->MAP_x>=36*8&&randomkids_npcs[c]->MAP_x<=42*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, ( 38+(c%3))*8, 49*8)==1){randomkids_npcs[c]->AI+=3;}
			if(randomkids_npcs[c]->AI==3)if((randomkids_npcs[c]->MAP_x>=76*8&&randomkids_npcs[c]->MAP_x<=82*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (78+(c%3))*8, 49*8)==1){randomkids_npcs[c]->AI+=3;}
			if(randomkids_npcs[c]->AI==4)if((randomkids_npcs[c]->MAP_x>=148*8&&randomkids_npcs[c]->MAP_x<=153*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (149+(c%3))*8, 49*8)==1){randomkids_npcs[c]->AI+=3;}

			if(randomkids_npcs[c]->AI==5)if(randomkids_npcs[c]->MAP_y<=37*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, ( 38+(c%3))*8, 40*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(randomkids_npcs[c]->AI==6)if(randomkids_npcs[c]->MAP_y<=37*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (78+(c%3))*8, 40*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(randomkids_npcs[c]->AI==7)if(randomkids_npcs[c]->MAP_y<=37*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (149+(c%3))*8, 40*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(MAP_is_xy_within_screen_by_64px(randomkids_npcs[c]->MAP_x,randomkids_npcs[c]->MAP_y)==0){NPC_delete_npc(&randomkids_npcs[c]);}
		}
	}
//3:00-3:05 from hallways left and right and classrooms 1 2 3 to playground 1 2
	if(CLOCK_hour==12+3&&CLOCK_minute<30)
	{
		if(CLOCK_minute<5)
		{
			//entering kids flooding out
			int c=0;
			for(c=0;c<randamount;c++)
			if(randomkids_npcs[c]==NULL&&vbl_10_var%10==c%10)
			{
				int cycle=r(3);
				if(cycle==0)
				{
					int x=(10+r(3))*8;
					int y=52*8;
					if(MAP_is_xy_within_screen_by_64px(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					else
					if(MAP_is_xy_within_screen_by_64px(150*8,40*8)==(1))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],150*8,40*8);
					else
					{
						int randnum=r(2);
						int x=MAP_cam_x-16;
						if(randnum==1)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
						int y=48*8;//touchmap_cam_y*2+r(384);
						if(!NPC_cant_create_at_xy(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					}
				}
				if(cycle==1)
				{
					int x=(196+r(3))*8;
					int y=52*8;
					if(MAP_is_xy_within_screen_by_64px(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					else
					if(MAP_is_xy_within_screen_by_64px(39*8,40*8)==(1))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],39*8,40*8);
					else
					{
						int randnum=r(2);
						int x=MAP_cam_x-16;
						if(randnum==1)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
						int y=48*8;//touchmap_cam_y*2+r(384);
						if(!NPC_cant_create_at_xy(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					}
				}
				if(cycle==2)
				{
					if(MAP_is_xy_within_screen_by_64px(79*8,40*8)==(1))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],79*8,40*8);
					else
					{
						int randnum=r(2);
						int x=MAP_cam_x-16;
						if(randnum==1)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
						int y=48*8;//touchmap_cam_y*2+r(384);
						if(!NPC_cant_create_at_xy(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					}
				}
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->walking_speed = SPEED_FASTER+r(SPEED_SLOWEST-SPEED_FASTEST);
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->AI=r(2);
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->non_walkable=1;
			}
		}
			int c=0;
		for(c=0;c<randamount;c++)
		if(randomkids_npcs[c]!=NULL)
		{
			if(randomkids_npcs[c]->AI==0)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, randomkids_npcs[c]->MAP_x+8, 48*8)==1)randomkids_npcs[c]->AI=(r(2))+2;
			if(randomkids_npcs[c]->AI==1)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, randomkids_npcs[c]->MAP_x+8, 48*8)==1)randomkids_npcs[c]->AI=(r(2))+2;
			if(randomkids_npcs[c]->AI==2)if((randomkids_npcs[c]->MAP_x>=100*8&&randomkids_npcs[c]->MAP_x<=104*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, ( 103+(c%3))*8, 48*8)==1){randomkids_npcs[c]->AI+=2;}
			if(randomkids_npcs[c]->AI==3)if((randomkids_npcs[c]->MAP_x>=118*8&&randomkids_npcs[c]->MAP_x<=122*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (120+(c%3))*8, 48*8)==1){randomkids_npcs[c]->AI+=2;}

			if(randomkids_npcs[c]->AI==4)if(randomkids_npcs[c]->MAP_y<=10*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (105+(c%3))*8, 13*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(randomkids_npcs[c]->AI==5)if(randomkids_npcs[c]->MAP_y<=10*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (117+(c%3))*8, 13*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(MAP_is_xy_within_screen_by_64px(randomkids_npcs[c]->MAP_x,randomkids_npcs[c]->MAP_y)==0){NPC_delete_npc(&randomkids_npcs[c]);}
		}
	}
//3:30-3:35 from playground 1 2 to hallways left and right
	if(CLOCK_hour==12+3&&CLOCK_minute>=30)
	{
		if(CLOCK_minute>=30&&CLOCK_minute<35)
		{
			//entering kids flooding out
			int c=0;
			for(c=0;c<randamount;c++)
			if(randomkids_npcs[c]==NULL&&vbl_10_var%10==c%10)
			{
				int cycle=r(2);
				if(cycle==0)
				{
					int x=(105+r(3))*8;
					int y=13*8;
					if(MAP_is_xy_within_screen_by_64px(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					else
					{
						int randnum=r(2);
						int x=MAP_cam_x-16;
						if(randnum==1)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
						int y=49*8;//touchmap_cam_y*2+r(384);
						if(!NPC_cant_create_at_xy(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					}
				}
				if(cycle==1)
				{
					int x=(117+r(3))*8;
					int y=13*8;
					if(MAP_is_xy_within_screen_by_64px(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					else
					{
						int randnum=r(2);
						int x=MAP_cam_x-16;
						if(randnum==1)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
						int y=49*8;//touchmap_cam_y*2+r(384);
						if(!NPC_cant_create_at_xy(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					}
				}
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->walking_speed = SPEED_FASTER+r(SPEED_SLOWEST-SPEED_FASTEST);
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->AI=cycle;
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->non_walkable=1;
			}
		}
			int c=0;
		for(c=0;c<randamount;c++)
		if(randomkids_npcs[c]!=NULL)
		{
			if(randomkids_npcs[c]->AI==0)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, randomkids_npcs[c]->MAP_x+8, 49*8)==1)randomkids_npcs[c]->AI=(r(2))+2;
			if(randomkids_npcs[c]->AI==1)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, randomkids_npcs[c]->MAP_x+8, 49*8)==1)randomkids_npcs[c]->AI=(r(2))+2;
			if(randomkids_npcs[c]->AI==2)if((randomkids_npcs[c]->MAP_x<=9*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, ( 8+(c%3))*8, 47*8)==1){randomkids_npcs[c]->AI+=2;}
			if(randomkids_npcs[c]->AI==3)if((randomkids_npcs[c]->MAP_x>=194*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (196+(c%3))*8, 48*8)==1){randomkids_npcs[c]->AI+=2;}

			if(randomkids_npcs[c]->AI==4)if(randomkids_npcs[c]->MAP_y>=47*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, ( 10+(c%3))*8, 52*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(randomkids_npcs[c]->AI==5)if(randomkids_npcs[c]->MAP_y>=47*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (196+(c%3))*8, 52*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(MAP_is_xy_within_screen_by_64px(randomkids_npcs[c]->MAP_x,randomkids_npcs[c]->MAP_y)==0){NPC_delete_npc(&randomkids_npcs[c]);}
		}
	}
//4:30-5:00 from classrooms 1 2 3 to hallways left and right
	if(CLOCK_hour==12+4)
	{
		if(CLOCK_minute>=30&&CLOCK_minute<55)
		{
			//entering kids flooding out
			int c=0;
			for(c=0;c<randamount;c++)
			if(randomkids_npcs[c]==NULL&&vbl_10_var%10==c%10)
			{
				int cycle=r(3);
				if(cycle==0)
				{
					int x=(38+r(3))*8;
					int y=40*8;
					if(MAP_is_xy_within_screen_by_64px(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					else
					{
						int randnum=r(2);
						int x=MAP_cam_x-16;
						if(randnum==1)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
						int y=49*8;//touchmap_cam_y*2+r(384);
						if(!NPC_cant_create_at_xy(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					}
				}
				if(cycle==1)
				{
					int x=(78+r(3))*8;
					int y=40*8;
					if(MAP_is_xy_within_screen_by_64px(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					else
					{
						int randnum=r(2);
						int x=MAP_cam_x-16;
						if(randnum==1)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
						int y=49*8;//touchmap_cam_y*2+r(384);
						if(!NPC_cant_create_at_xy(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					}
				}
				if(cycle==2)
				{
					int x=(149+r(3))*8;
					int y=40*8;
					if(MAP_is_xy_within_screen_by_64px(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					else
					{
						int randnum=r(2);
						int x=MAP_cam_x-16;
						if(randnum==1)x=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16;
						int y=49*8;//touchmap_cam_y*2+r(384);
						if(!NPC_cant_create_at_xy(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
					}
				}
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->walking_speed = SPEED_FASTER+r(SPEED_SLOWEST-SPEED_FASTEST);
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->AI=r(2);
				if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->non_walkable=1;
			}
		}
			int c=0;
		for(c=0;c<randamount;c++)
		if(randomkids_npcs[c]!=NULL)
		{
			if(randomkids_npcs[c]->AI==0)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, randomkids_npcs[c]->MAP_x+8, 49*8)==1)randomkids_npcs[c]->AI=(r(2))+2;
			if(randomkids_npcs[c]->AI==1)if(NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, randomkids_npcs[c]->MAP_x+8, 49*8)==1)randomkids_npcs[c]->AI=(r(2))+2;
			if(randomkids_npcs[c]->AI==2)if((randomkids_npcs[c]->MAP_x<=9*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, ( 8+(c%3))*8, 47*8)==1){randomkids_npcs[c]->AI+=2;}
			if(randomkids_npcs[c]->AI==3)if((randomkids_npcs[c]->MAP_x>=194*8)||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (196+(c%3))*8, 48*8)==1){randomkids_npcs[c]->AI+=2;}

			if(randomkids_npcs[c]->AI==4)if(randomkids_npcs[c]->MAP_y>=47*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, ( 10+(c%3))*8, 52*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(randomkids_npcs[c]->AI==5)if(randomkids_npcs[c]->MAP_y>=47*8||NPC_walk_to_xy_intelligenthit_avoidothers_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, (196+(c%3))*8, 52*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
			if(MAP_is_xy_within_screen_by_64px(randomkids_npcs[c]->MAP_x,randomkids_npcs[c]->MAP_y)==0){NPC_delete_npc(&randomkids_npcs[c]);}
		}
	}
//=================================================================================================================
//ACTIONS
//=================================================================================================================
	if(walking_into_door(RANGE_SCHOOLBackHallwayToClassHallwayLeft)){MAP_change_map(MAP_bobsgame_SCHOOLClassHallway,10,11);return;}
	if(walking_into_door(RANGE_SCHOOLBackHallwayToClassHallwayRight)){MAP_change_map(MAP_bobsgame_SCHOOLClassHallway,196,11);return;}
	if(walking_into_door(RANGE_SCHOOLBackHallwayToCustodian))
	{
		//TODO: only if ????
		if(demobutton){MAP_change_map(MAP_bobsgame_SCHOOLCustodian,6,43);return;}
		//else
		if(ACTION_check("Check Custodian Room"))
		{
			TEXT_set_sprite_window(0,PLAYER_npc,NULL);
			TEXT_window("Locked. There's a keyhole.");
		}
	}
		if(walking_into_door(RANGE_SCHOOLBackHallwayToClassroom3))
	{
		//closed during recess, lunch, special class, after school. sooo..
		//between 7:00-9:30||10:00-12:00||1:00-3:00
		//hmm. not my class, only delivering something? talking to the teacher?
		//maybe class should be open at recess, and its a necessary thing to talk to the teachers
		if(demobutton||((CLOCK_hour>=7&&(CLOCK_hour<9||(CLOCK_hour==9&&CLOCK_minute<30)))||(CLOCK_hour>=10&&CLOCK_hour<12)||(CLOCK_hour>12+1&&CLOCK_hour<3))){MAP_change_map(MAP_bobsgame_SCHOOLClassroom3,22,38);return;}
		else
		if(ACTION_check("Check Classroom Door"))
		{
			TEXT_set_sprite_window(0,PLAYER_npc,NULL);
			if(((CLOCK_hour==9&&CLOCK_minute>=30)||(CLOCK_hour==12+3&&CLOCK_minute<30)))TEXT_window("Locked. I'm supposed to be at recess. What am I doing?");
			if(((CLOCK_hour==12&&CLOCK_minute>=0)))TEXT_window("Locked. I'm supposed to be at Lunch. What am I doing?");
			if(((CLOCK_hour==12+3&&CLOCK_minute>=30)))TEXT_window("Locked. I'm supposed to be at special class. What am I doing?");
			if(((CLOCK_hour==12+4&&CLOCK_minute>=30)))TEXT_window("Locked. School is over! I can get out of this place! What am I doing?");
		}
	}
	if(walking_into_door(RANGE_SCHOOLBackHallwayToClassroom2))
	{
		//closed during recess, lunch, special class, after school. sooo..
		//between 7:00-9:30||10:00-12:00||1:00-3:00
		if(demobutton||((CLOCK_hour>=7&&(CLOCK_hour<9||(CLOCK_hour==9&&CLOCK_minute<30)))||(CLOCK_hour>=10&&CLOCK_hour<12)||(CLOCK_hour>12+1&&CLOCK_hour<3))){MAP_change_map(MAP_bobsgame_SCHOOLClassroom2,22,38);return;}
		else
		if(ACTION_check("Check Classroom Door"))
		{
			TEXT_set_sprite_window(0,PLAYER_npc,NULL);
			if(((CLOCK_hour==9&&CLOCK_minute>=30)||(CLOCK_hour==12+3&&CLOCK_minute<30)))TEXT_window("Locked. I'm supposed to be at recess. What am I doing?");
			if(((CLOCK_hour==12&&CLOCK_minute>=0)))TEXT_window("Locked. I'm supposed to be at Lunch. What am I doing?");
			if(((CLOCK_hour==12+3&&CLOCK_minute>=30)))TEXT_window("Locked. I'm supposed to be at special class. What am I doing?");
			if(((CLOCK_hour==12+4&&CLOCK_minute>=30)))TEXT_window("Locked. School is over! I can get out of this place! What am I doing?");
		}
	}
	if(walking_into_door(RANGE_SCHOOLBackHallwayToClassroom1))
	{
		//closed during recess, lunch, special class, after school. sooo..
		//between 7:00-9:30||10:00-12:00||1:00-3:00
		if(demobutton||((CLOCK_hour>=7&&(CLOCK_hour<9||(CLOCK_hour==9&&CLOCK_minute<30)))||(CLOCK_hour>=10&&CLOCK_hour<12)||(CLOCK_hour>12+1&&CLOCK_hour<3))){MAP_change_map(MAP_bobsgame_SCHOOLClassroom1,22,38);return;}
		else
		if(ACTION_check("Check Classroom Door"))
		{
			TEXT_set_sprite_window(0,PLAYER_npc,NULL);
			if(((CLOCK_hour==9&&CLOCK_minute>=30)||(CLOCK_hour==12+3&&CLOCK_minute<30)))TEXT_window("Locked. I'm supposed to be at recess. What am I doing?");
			if(((CLOCK_hour==12&&CLOCK_minute>=0)))TEXT_window("Locked. I'm supposed to be at Lunch. What am I doing?");
			if(((CLOCK_hour==12+3&&CLOCK_minute>=30)))TEXT_window("Locked. I'm supposed to be at special class. What am I doing?");
			if(((CLOCK_hour==12+4&&CLOCK_minute>=30)))TEXT_window("Locked. School is over! I can get out of this place! What am I doing?");
		}
	}
	if(walking_into_door(RANGE_SCHOOLBackHallwayToGirlsBathroom))
	{
		//TODO: only if ????
		if(demobutton){MAP_change_map(MAP_bobsgame_SCHOOLGirlsBathroom,11,38);return;}
		//else
		if(ACTION_check("Go In Girl's Bathroom"))
		{
			TEXT_set_sprite_window(0,PLAYER_npc,NULL);
			TEXT_window("The Nintendo DS Wireless Connection will now automatically upload your personal information to federal law enforcement sex offender databases, sicko creep.<.>Confirm? <Q:Alright!:Sure:Yes.:I agree.:Please!:I can't wait!><CLEAR>Please wait.<DELAY2SECFLICKER>.<DELAY2SECFLICKER>.<DELAY2SECFLICKER>.<DELAY2SECFLICKER>Complete.<.>A heavily armed team of special officers will swarm down by helicopter in a moment to arrest you. Have a nice day!<.>Seriously though, Yuu should at least crossdress if he wants in here. Have some decency!");
		}
	}
	if(walking_into_door(RANGE_SCHOOLBackHallwayToBoysBathroom)){MAP_change_map(MAP_bobsgame_SCHOOLBoysBathroom,11,38);return;}
	if(walking_into_door(RANGE_SCHOOLBackHallwayToOUTSIDEPlayground1))
	{
		//only between 9:30-10:00, and 3:00-3:30
		if(demobutton||((CLOCK_hour==9&&CLOCK_minute>=30)||(CLOCK_hour==3&&CLOCK_minute<30))){MAP_change_map(MAP_bobsgame_SCHOOLPlayground,184,71);return;}
		else
		if(ACTION_check("Check Playground Door"))
		{
			TEXT_set_sprite_window(0,PLAYER_npc,NULL);
			TEXT_window("Locked. I guess I have to wait until recess.");
		}
	}
	if(walking_into_door(RANGE_SCHOOLBackHallwayToOUTSIDEPlayground2))
	{
		//only between 9:30-10:00, and 3:00-3:30
		if(demobutton||((CLOCK_hour==9&&CLOCK_minute>=30)||(CLOCK_hour==3&&CLOCK_minute<30))){MAP_change_map(MAP_bobsgame_SCHOOLPlayground,196,71);return;}
		else
		if(ACTION_check("Check Playground Door"))
		{
			TEXT_set_sprite_window(0,PLAYER_npc,NULL);
			TEXT_window("Locked. I guess I have to wait until recess.");
		}
	}
	//SCHOOL SCHEDULE
	//7:00-7:30 school opens, hall monitor in entrance. classes open no teacher. everything else closed.
	//7:35 class starts. 2 hrs
	//===
	//9:30 recess 1/2 hr
	//10:00 recess end
	//===
	//10:05 class starts 2 hrs
	//===
	//12:00 lunchtime 1 hr
	//1:00 lunchtime end
	//===
	//1:05 class starts 2 hrs
	//====
	//3:00 recess 1/2 hr
	//3:30 recess ends
	//===
	//3:35 special class starts 1 hr
	//4:30 special class ends school out
	//
	//MONDAY music class
	//TUESDAY gym class
	//WEDNESDAY library
	//THURSDAY art class
	//FRIDAY computer class
	//bell rings at 7:30, 7:35, 9:30, 10:00, 10:05, 12:00, 1:00, 1:05, 3:00, 3:30, 3:35, 4:30
	if(CLOCK_hour==7&&CLOCK_second==0&&CLOCK_minute==30){CAPTION_make_caption(NULL,1,60,80,5,"School is starting! Get to class!",FONT_SMALL_ID,WHITE,BLACK,1,1);HARDWARE_play_sound("schoolbell",127,44100,0);}
	if(CLOCK_hour==7&&CLOCK_second==0&&CLOCK_minute==35){CAPTION_make_caption(NULL,1,80,80,5,"Late for class!",FONT_SMALL_ID,WHITE,BLACK,1,1);HARDWARE_play_sound("schoolbell",127,44100,0);HARDWARE_stop_sound("murmur");}
	if(CLOCK_hour==9&&CLOCK_second==0&&CLOCK_minute==30){CAPTION_make_caption(NULL,1,80,80,5,"Alright! Recess!",FONT_SMALL_ID,WHITE,BLACK,1,1);HARDWARE_play_sound("schoolbell",127,44100,0);}
	if(CLOCK_hour==10&&CLOCK_second==0&&CLOCK_minute==0){CAPTION_make_caption(NULL,1,60,80,5,"Recess over - get to class!",FONT_SMALL_ID,WHITE,BLACK,1,1);HARDWARE_play_sound("schoolbell",127,44100,0);}
	if(CLOCK_hour==10&&CLOCK_second==0&&CLOCK_minute==5){CAPTION_make_caption(NULL,1,80,80,5,"Late for class!",FONT_SMALL_ID,WHITE,BLACK,1,1);HARDWARE_play_sound("schoolbell",127,44100,0);HARDWARE_stop_sound("murmur");}
	if(CLOCK_hour==12&&CLOCK_second==0&&CLOCK_minute==0){CAPTION_make_caption(NULL,1,80,80,5,"Alright! Lunchtime!",FONT_SMALL_ID,WHITE,BLACK,1,1);HARDWARE_play_sound("schoolbell",127,44100,0);}
	if(CLOCK_hour==12+1&&CLOCK_second==0&&CLOCK_minute==0){CAPTION_make_caption(NULL,1,60,80,5,"Lunch is over- get to class!!",FONT_SMALL_ID,WHITE,BLACK,1,1);HARDWARE_play_sound("schoolbell",127,44100,0);}
	if(CLOCK_hour==12+1&&CLOCK_second==0&&CLOCK_minute==5){CAPTION_make_caption(NULL,1,80,80,5,"Late for class!",FONT_SMALL_ID,WHITE,BLACK,1,1);HARDWARE_play_sound("schoolbell",127,44100,0);HARDWARE_stop_sound("murmur");}
	if(CLOCK_hour==12+3&&CLOCK_second==0&&CLOCK_minute==0){CAPTION_make_caption(NULL,1,80,80,5,"Alright! Recess!",FONT_SMALL_ID,WHITE,BLACK,1,1);HARDWARE_play_sound("schoolbell",127,44100,0);}
	if(CLOCK_hour==12+3&&CLOCK_second==0&&CLOCK_minute==30){CAPTION_make_caption(NULL,1,60,80,5,"Recess over - get to special class!",FONT_SMALL_ID,WHITE,BLACK,1,1);HARDWARE_play_sound("schoolbell",127,44100,0);}
	if(CLOCK_hour==12+3&&CLOCK_second==0&&CLOCK_minute==35){CAPTION_make_caption(NULL,1,70,80,5,"Late for special class!",FONT_SMALL_ID,WHITE,BLACK,1,1);HARDWARE_play_sound("schoolbell",127,44100,0);HARDWARE_stop_sound("murmur");}
	if(CLOCK_hour==12+4&&CLOCK_second==0&&CLOCK_minute==30){CAPTION_make_caption(NULL,1,80,80,5,"School's OUT!",FONT_SMALL_ID,WHITE,BLACK,1,1);HARDWARE_play_sound("schoolbell",127,44100,0);}
}

void bobsgame_SCHOOLBackHallway_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_SCHOOLBackHallway_Map_VBL_Function()
{

}

void bobsgame_SCHOOLBackHallway_Map_HBL_Function()
{

}

//========================================================
//SCHOOLClassroom1
//========================================================
void bobsgame_SCHOOLClassroom1_Map_Load_Function()
{
//RANGE_SCHOOLClassroom1ToBackHallway 20*8,39*8,24*8,40*8
}

void bobsgame_SCHOOLClassroom1_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

	//little kids sitting at desks
	//everyone turns to look at you
	//teacher up front
	//"excuse me young man, can i help yuu? yuu isn't one of my students, is yuu lost?
		//teacher 21.13
	//blackboard 13-27,11
	//desk 11,13 tiles layer 1 10,11,12 11y 10y on layer2
	//3x2 tv at ???
	static NPC* classkids_npcs[15] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	static NPC* teacher_npc = NULL;
	int c=0;
	for(c=0;c<15;c++)
	{
		int x=0;
		int y=0;
			if(c== 0){x= 8;y=23;}
			if(c== 1){x=14;y=22;}
			if(c== 2){x=20;y=22;}
			if(c== 3){x=27;y=22;}
			if(c== 4){x=33;y=23;}
			if(c== 5){x= 8;y=29;}
			if(c== 6){x=14;y=28;}
			if(c== 7){x=20;y=28;}
			if(c== 8){x=27;y=28;}
			if(c== 9){x=33;y=29;}
			if(c== 10){x= 8;y=35;}
			if(c== 11){x=14;y=34;}
			if(c== 12){x=20;y=34;}
			if(c== 13){x=27;y=34;}
			if(c== 14){x=33;y=35;}
		if(classkids_npcs[c]==NULL)
		{
			NPC_create_random_CHILD_xy_feet(&classkids_npcs[c],(x*8),(y*8)+3);
			classkids_npcs[c]->anim_dir=UP;
			NPC_animate_stand_dir(&classkids_npcs[c], UP);
			classkids_npcs[c]->layer=3;
		}
		if(classkids_npcs[c]!=NULL)
		{
			NPC_stare_at_npc(&classkids_npcs[c],&PLAYER_npc);
		}
	}
	if(teacher_npc==NULL)
	{
		NPC_create_npc_xy_feet(&teacher_npc,GFX_ADULT_grannycluelessteacher,16,40,21*8,12*8);
		teacher_npc->non_walkable=1;
		teacher_npc->pushable=1;
	}
	if(teacher_npc!=NULL)
	{
		NPC_stare_at_npc(&teacher_npc,&PLAYER_npc);
		if(ACTION_npc(&teacher_npc,"Talk To Teacher"))
		{
			TEXT_set_sprite_window(0,teacher_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("Have a seat, little boy.<.>"
			"Wait a second, dearie, Yuu isn't one of my students, is Yuu?<.>"
			"<1>No, I'm in 6th grade.<.><0>Oh dear, is Yuu lost? Let me just call Yuu's mommy and we'll find out where Yuu belongs.<.>"
			"<1>No, that's ok, I think I can find it. Thanks."
			);
		}
	}
//=================================================================================================================
//ACTIONS
//=================================================================================================================
	if(walking_into_door(RANGE_SCHOOLClassroom1ToBackHallway))
	{
		MAP_change_map(MAP_bobsgame_SCHOOLBackHallway,149,39);return;
	}
}
void bobsgame_SCHOOLClassroom1_Map_Stop_Function()
{

	NPC_delete_all_npcs();
}
void bobsgame_SCHOOLClassroom1_Map_VBL_Function()
{

}

void bobsgame_SCHOOLClassroom1_Map_HBL_Function()
{

}

//========================================================
//SCHOOLClassroom2
//========================================================
void bobsgame_SCHOOLClassroom2_Map_Load_Function()
{
//RANGE_SCHOOLClassroom2ToBackHallway 20*8,39*8,24*8,40*8
}

void bobsgame_SCHOOLClassroom2_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

	static NPC* classkids_npcs[15] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	static NPC* teacher_npc = NULL;
	int c=0;
	for(c=0;c<15;c++)
	{
		int x=0;
		int y=0;
			if(c== 0){x= 8;y=23;}
			if(c== 1){x=14;y=22;}
			if(c== 2){x=20;y=22;}
			if(c== 3){x=27;y=22;}
			if(c== 4){x=33;y=23;}
			if(c== 5){x= 8;y=29;}
			if(c== 6){x=14;y=28;}
			if(c== 7){x=20;y=28;}
			if(c== 8){x=27;y=28;}
			if(c== 9){x=33;y=29;}
			if(c== 10){x= 8;y=35;}
			if(c== 11){x=14;y=34;}
			if(c== 12){x=20;y=34;}
			if(c== 13){x=27;y=34;}
			if(c== 14){x=33;y=35;}
		if(classkids_npcs[c]==NULL)
		{
			NPC_create_random_CHILD_xy_feet(&classkids_npcs[c],(x*8),(y*8)+3);
			classkids_npcs[c]->anim_dir=UP;
			NPC_animate_stand_dir(&classkids_npcs[c], UP);
			classkids_npcs[c]->layer=3;
		}
		if(classkids_npcs[c]!=NULL)
		{
			NPC_stare_at_npc(&classkids_npcs[c],&PLAYER_npc);
		}
	}
	if(teacher_npc==NULL)
	{
		NPC_create_npc_xy_feet(&teacher_npc,GFX_ADULT_femaleangryteacher,16,40,21*8,12*8);
		teacher_npc->non_walkable=1;
		teacher_npc->pushable=1;
	}
	if(teacher_npc!=NULL)
	{
		NPC_stare_at_npc(&teacher_npc,&PLAYER_npc);
		if(ACTION_npc(&teacher_npc,"Talk To Teacher"))
		{
			TEXT_set_sprite_window(0,teacher_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("Yuu don't belong in here!<.>"
			"WHAT DOES YUU THINK HE'S DOING?!<SHAKE1SEC><.>"
			"GET OUT OF MY CLASSROOM!<SHAKE1SEC><.>"
			"I will be SURE to inform the principal of this disruption, Yuu little hooligan!"
			);
		}
	}
//=================================================================================================================
//ACTIONS
//=================================================================================================================
	if(walking_into_door(RANGE_SCHOOLClassroom2ToBackHallway))
	{
		MAP_change_map(MAP_bobsgame_SCHOOLBackHallway,78,39);return;
	}
}
void bobsgame_SCHOOLClassroom2_Map_Stop_Function()
{

	NPC_delete_all_npcs();
}
void bobsgame_SCHOOLClassroom2_Map_VBL_Function()
{

}

void bobsgame_SCHOOLClassroom2_Map_HBL_Function()
{

}

//========================================================
//SCHOOLClassroom3
//========================================================
void bobsgame_SCHOOLClassroom3_Map_Load_Function()
{
//RANGE_SCHOOLClassroom3ToBackHallway 20*8,39*8,24*8,40*8
}

void bobsgame_SCHOOLClassroom3_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

	static NPC* classkids_npcs[15] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	static NPC* teacher_npc = NULL;
	int c=0;
	for(c=0;c<15;c++)
	{
		int x=0;
		int y=0;
			if(c== 0){x= 8;y=23;}
			if(c== 1){x=14;y=22;}
			if(c== 2){x=20;y=22;}
			if(c== 3){x=27;y=22;}
			if(c== 4){x=33;y=23;}
			if(c== 5){x= 8;y=29;}
			if(c== 6){x=14;y=28;}
			if(c== 7){x=20;y=28;}
			if(c== 8){x=27;y=28;}
			if(c== 9){x=33;y=29;}
			if(c== 10){x= 8;y=35;}
			if(c== 11){x=14;y=34;}
			if(c== 12){x=20;y=34;}
			if(c== 13){x=27;y=34;}
			if(c== 14){x=33;y=35;}
		if(classkids_npcs[c]==NULL)
		{
			NPC_create_random_CHILD_xy_feet(&classkids_npcs[c],(x*8),(y*8)+3);
			classkids_npcs[c]->anim_dir=UP;
			NPC_animate_stand_dir(&classkids_npcs[c], UP);
			classkids_npcs[c]->layer=3;
		}
		if(classkids_npcs[c]!=NULL)
		{
			NPC_stare_at_npc(&classkids_npcs[c],&PLAYER_npc);
		}
	}
	if(teacher_npc==NULL)
	{
		NPC_create_npc_xy_feet(&teacher_npc,GFX_ADULT_femalesadteacher,16,40,21*8,12*8);
		teacher_npc->non_walkable=1;
		teacher_npc->pushable=1;
	}
	else if(teacher_npc!=NULL)
	{
		NPC_stare_at_npc(&teacher_npc,&PLAYER_npc);
		if(ACTION_npc(&teacher_npc,"Talk To Teacher"))
		{
			TEXT_set_sprite_window(0,teacher_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("Sir, could Yuu please leave my classroom?<.>"
			"I..<DELAY1SEC>I..<DELAY1SEC>I really can't handle this right now.<.>"
			"<1>Oh no, I'm sorry. <.>"
			"Don't cry! I'm leaving, it's OK.<.>"
			"<0>Oh, okay then. I'm sorry, I just.. I can't.. They don't listen!<.>"
			"*sob*<SHAKE1SEC><.>"
			"I changed my mind! Don't leave! Don't leave me here!");
		}
	}
//=================================================================================================================
//ACTIONS
//=================================================================================================================
	if(walking_into_door(RANGE_SCHOOLClassroom3ToBackHallway))
	{
		MAP_change_map(MAP_bobsgame_SCHOOLBackHallway,38,39);return;
	}
}
void bobsgame_SCHOOLClassroom3_Map_Stop_Function()
{

	NPC_delete_all_npcs();
}
void bobsgame_SCHOOLClassroom3_Map_VBL_Function()
{

}

void bobsgame_SCHOOLClassroom3_Map_HBL_Function()
{

}

//========================================================
//SCHOOLClassroom4
//========================================================
void bobsgame_SCHOOLClassroom4_Map_Load_Function()
{
//RANGE_SCHOOLClassroom4ToClassHallway 20*8,39*8,24*8,40*8
}

void bobsgame_SCHOOLClassroom4_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

	static NPC* classkids_npcs[15] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	static NPC* teacher_npc = NULL;
	int c=0;
	for(c=0;c<15;c++)
	{
		int x=0;
		int y=0;
			if(c== 0){x= 8;y=23;}
			if(c== 1){x=14;y=22;}
			if(c== 2){x=20;y=22;}
			if(c== 3){x=27;y=22;}
			if(c== 4){x=33;y=23;}
			if(c== 5){x= 8;y=29;}
			if(c== 6){x=14;y=28;}
			if(c== 7){x=20;y=28;}
			if(c== 8){x=27;y=28;}
			if(c== 9){x=33;y=29;}
			if(c== 10){x= 8;y=35;}
			if(c== 11){x=14;y=34;}
			if(c== 12){x=20;y=34;}
			if(c== 13){x=27;y=34;}
			if(c== 14){x=33;y=35;}
		if(classkids_npcs[c]==NULL)
		{
			NPC_create_random_CHILD_xy_feet(&classkids_npcs[c],(x*8),(y*8)+3);
			classkids_npcs[c]->anim_dir=UP;
			NPC_animate_stand_dir(&classkids_npcs[c], UP);
			classkids_npcs[c]->layer=3;
		}
		else if(classkids_npcs[c]!=NULL)
		{
			NPC_stare_at_npc(&classkids_npcs[c],&PLAYER_npc);
		}
	}
	if(teacher_npc==NULL)
	{
		NPC_create_npc_xy_feet(&teacher_npc,GFX_ADULT_maleangryteacher,16,40,21*8,12*8);
		teacher_npc->non_walkable=1;
		teacher_npc->pushable=1;
	}
	else if(teacher_npc!=NULL)
	{
		NPC_stare_at_npc(&teacher_npc,&PLAYER_npc);
		if(ACTION_npc(&teacher_npc,"Talk To Teacher"))
		{
			TEXT_set_sprite_window(0,teacher_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("What can I help you with, soldier? Need some direction?<.><1>No, I think I'm fine. Sorry.<.><0>Don't be sorry. Have some courage, champ. Don't be afraid to ask a superior commander for guidance.<.><1>Oh, alright then. Which class am I supposed to be in again?<.><0>FIGURE IT OUT YOURSELF!<SHAKE1SEC><.>DO YUU WANT TO BE A MAN OR NOT?!<SHAKE1SEC><.>YUU THINK LIFE COMES WITH DIRECTIONS?!<SHAKE1SEC><.>NOW GIVE ME 20.. err.. GET OUT!!<SHAKE1SEC>");
		}
	}
//=================================================================================================================
//ACTIONS
//=================================================================================================================
	if(walking_into_door(RANGE_SCHOOLClassroom4ToClassHallway))
	{
		MAP_change_map(MAP_bobsgame_SCHOOLClassHallway,88,39);return;
	}
}
void bobsgame_SCHOOLClassroom4_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_SCHOOLClassroom4_Map_VBL_Function()
{

}

void bobsgame_SCHOOLClassroom4_Map_HBL_Function()
{

}

//========================================================
//SCHOOLClassroom5
//========================================================
void bobsgame_SCHOOLClassroom5_Map_Load_Function()
{
//RANGE_SCHOOLClassroom5ToClassHallway 20*8,39*8,24*8,40*8
}

void bobsgame_SCHOOLClassroom5_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

	static NPC* classkids_npcs[15] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	static NPC* teacher_npc = NULL;
	int c=0;
	for(c=0;c<15;c++)
	{
		int x=0;
		int y=0;
			if(c== 0){x= 8;y=23;}
			if(c== 1){x=14;y=22;}
			if(c== 2){x=20;y=22;}
			if(c== 3){x=27;y=22;}
			if(c== 4){x=33;y=23;}
			if(c== 5){x= 8;y=29;}
			if(c== 6){x=14;y=28;}
			if(c== 7){x=20;y=28;}
			if(c== 8){x=27;y=28;}
			if(c== 9){x=33;y=29;}
			if(c== 10){x= 8;y=35;}
			if(c== 11){x=14;y=34;}
			if(c== 12){x=20;y=34;}
			if(c== 13){x=27;y=34;}
			if(c== 14){x=33;y=35;}
		if(classkids_npcs[c]==NULL)
		{
			NPC_create_random_CHILD_xy_feet(&classkids_npcs[c],(x*8),(y*8)+3);
			classkids_npcs[c]->anim_dir=UP;
			NPC_animate_stand_dir(&classkids_npcs[c], UP);
			classkids_npcs[c]->layer=3;
		}
		if(classkids_npcs[c]!=NULL)
		{
			NPC_stare_at_npc(&classkids_npcs[c],&PLAYER_npc);
		}
	}
	if(teacher_npc==NULL)
	{
		NPC_create_npc_xy_feet(&teacher_npc,GFX_ADULT_malesadteacher,16,40,21*8,12*8);
		teacher_npc->non_walkable=1;
		teacher_npc->pushable=1;
	}
	else if(teacher_npc!=NULL)
	{
		NPC_stare_at_npc(&teacher_npc,&PLAYER_npc);
		if(ACTION_npc(&teacher_npc,"Talk To Teacher"))
		{
			TEXT_set_sprite_window(0,teacher_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("Umm.. could Yuu please, I mean, if it's not too much trouble.. <.>Or, Yuu could, Yuu knows, stay if Yuu wanted. But it really would be better if Yuu went to his own class. <.>It's totally up to Yuu though.<.>Oh, nevermind.");
		}
	}
//=================================================================================================================
//ACTIONS
//=================================================================================================================
	if(walking_into_door(RANGE_SCHOOLClassroom5ToClassHallway))
	{
		MAP_change_map(MAP_bobsgame_SCHOOLClassHallway,128,39);return;
	}
}
void bobsgame_SCHOOLClassroom5_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_SCHOOLClassroom5_Map_VBL_Function()
{

}

void bobsgame_SCHOOLClassroom5_Map_HBL_Function()
{

}

//========================================================
//SCHOOLClassroom6
//========================================================
void bobsgame_SCHOOLClassroom6_Map_Load_Function()
{
//RANGE_SCHOOLClassroom6ToClassHallway 20*8,39*8,24*8,40*8
}

void bobsgame_SCHOOLClassroom6_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

	static NPC* classkids_npcs[15] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	static NPC* teacher_npc = NULL;
//int* gothgirl = NULL;
//int* punkgirl = NULL;
//int* skatergirl = NULL;
//int* jockgirl = NULL;
//int* paperboy = NULL;
//int* foreignboy = NULL;
//int* japaneseboy = NULL;
	int c=0;
	for(c=0;c<15;c++)
	{
		if(classkids_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			GFX* gfx=NULL;
			if(c== 0){x= 8;y=23;gfx=GFX_KID_pudgyboy;}
			if(c== 1){x=14;y=22;gfx=GFX_KID_nerdboy;}
			if(c== 2){x=20;y=22;gfx=GFX_KID_uglyboy;}
			if(c== 3){x=27;y=22;gfx=GFX_KID_nerdgirl;}
			if(c== 4){x=33;y=23;gfx=GFX_KID_punkboy;}
			if(c== 5){x= 8;y=29;gfx=GFX_KID_emoboy;}
			if(c== 6){x=14;y=28;gfx=GFX_KID_emogirl;}
			if(c== 7){x=20;y=28;gfx=GFX_KID_uglygirl;}
			if(c== 8){x=27;y=28;gfx=GFX_KID_pudgygirl;}
			if(c== 9){x=33;y=29;gfx=GFX_KID_conceitedgirl;}
			if(c== 10){x= 8;y=35;gfx=GFX_KID_notfriend;}
			//if(c== 11){x=14;y=34;}
			if(c== 12){x=20;y=34;gfx=GFX_KID_bully;}
			if(c== 13){x=27;y=34;gfx=GFX_KID_jockboy;}
			if(c== 14){x=33;y=35;gfx=GFX_KID_greaserboy;}
			if(gfx!=NULL)
			{
				NPC_create_npc_xy_feet(&classkids_npcs[c],gfx,16,32,x*8,(y*8)+3);
				NPC_animate_stand_dir(&classkids_npcs[c], UP);
				classkids_npcs[c]->layer=3;
			}
		}
		else if(classkids_npcs[c]!=NULL)
		{
			if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&classkids_npcs[c],30))NPC_stare_at_npc(&classkids_npcs[c],&PLAYER_npc);
			else NPC_animate_stand_dir(&classkids_npcs[c], UP);
		}
	}
	if(teacher_npc==NULL)
	{
		NPC_create_npc_xy_feet(&teacher_npc,GFX_ADULT_givenupteacher,16,40,21*8,12*8);
		teacher_npc->non_walkable=1;
		teacher_npc->pushable=1;
	}
	else if(teacher_npc!=NULL)
	{
		NPC_stare_at_npc(&teacher_npc,&PLAYER_npc);
		if(ACTION_npc(&teacher_npc,"Talk To Teacher"))
		{
			TEXT_set_sprite_window(0,teacher_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("Sit down or something.<.>Or do whatever Yuu want, it doesn't matter.<.>"
			"I think I might make today self-study.<.>Or maybe I'll show a video.<.>"
			"Maybe I'll go home.<.>"
			"I'll give Yuu an A if you sit down, OK?<.>"
			"Or Yuu don't really have to do that. Whatever."
			);
		}
	}
//TODO:cant leave if class started
//TODO:sit down in seat
//TODO:discussions between kids and teacher.
	static int classroom_cycle=0;
	if(ACTION_range_xy_xy(13*8,34*8,15*8,36*8,"Sit At Desk"))
	{
		PLAYER_npc->MAP_x=(14-1)*8;
		PLAYER_npc->MAP_y=(34-3)*8;
		PLAYER_npc->layer=3;
		NPC_animate_stand_dir(&PLAYER_npc,UP);
		GLOBAL_main_sprite_input_off=1;
		GLOBAL_main_sprite_standing=1;
		classroom_cycle=1;
	}
		if(classroom_cycle==1)
	{
		TEXT_set_sprite_window(0,teacher_npc,NULL);
		TEXT_set_sprite_window(1,classkids_npcs[1],NULL);
		TEXT_npc_1 = classkids_npcs[6];
		TEXT_npc_2 = classkids_npcs[0];
		TEXT_npc_3 = classkids_npcs[9];
		TEXT_npc_4 = classkids_npcs[8];
		TEXT_npc_5 = classkids_npcs[1];
		TEXT_npc_6 = classkids_npcs[12];
		TEXT_window("<NOCANCEL>Everybody quiet down!<.>"
		"How was everyone's weekend?<.>"
		"Just kidding. You all know I don't care about that.<.>"
		"We'll start today's lesson plan with Columbus.<.>"
		"Does anyone know who Columbus was?<.>"
		"<1>I do.<.>"
		"<0>Yes, we know. Does anybody else?<CLOSE1><.>"
		"Didn't think so.<.>"
		"Let's see here... I'm supposed to tell you about how Columbus is a hero for discovering America.<.>"
		"Now that my legal requirement is fulfilled, I'll tell you the real story.<.>"
		"Columbus was a crank, plain and simple. Just some deadbeat who couldn't handle his wife or whatever, so he scammed a ship from the Queen and left for nowhere. The guy was a lunatic.<.>"
		"I mean, he set sail for \"Lands unseen,\" which basically means it was a death march. A suicide mission. Think about it, just setting off for nowhere.<.>"
		"So by chance the nut hits land, and *bam* famous just like that. I mean, he doesn't even know. He thinks he's somewhere else. Where was that again.. <.>"
		"Ah. India. That's why we called Native Americans \"Indians\" for a couple of centuries before politicians started fighting over words.<.>"
		"If *I* was in charge, I'd work on some of the caveman speak we've still got hanging around. \"Fire Place,\" \"Up Stairs.\" Ooga ungh. Where's the outraged cavemen?<.>"
		"<1>Sir, It doesn't say that in the book.<.><CLOSE1>"
		"<0>Of course it doesn't, idiot.<.>"
		"They can't possibly get away with telling you guys the truth. The government modifies the past to meet the needs of the present.<.>"
		"The funny part is that it actually works. People are inclined to believe what they read in anything that seems reputable, and be skeptical of any information receieved from a fringe source.<.>"
		"It's a cognitive bias, a stupid human trick. We're all vulnerable to it, because it's common sense- most of the time that independent information is just some psuedoscientific extremist theory.<.>"
		"<1><NPC1>What's soodosyantic mean?<.><CLOSE1>"
		"<0>Totally crap.<.>"
		"So the public really has no choice BUT to believe the official news and books. There really is no good solution besides figuring it out yourself, which is, again, usually bunk.<.>"
		"<1><NPC2>I'm scared.<.><CLOSE1>"
		"<0>As you should be. This world is totally evil. You're basically all just living in a fantasy dreamland, a childhood paradise paid for by your parents, who will soon die and leave you alone by yourself.<.>"
		"Some of you will starve to death, some of you will die in a gutter, shivering from withdrawal from some addiction, eventually choking on your own vomit.<.>"
		"<1><NPC3>Excuse me, I'll have you know that I'm to inherit the vast fortune of the O\'nceit Family.<.><CLOSE1>"
		"<0>That's where the addiction comes from.<.>"
		"<1><NPC4>*sob*<.><CLOSE1>"
		"Quit whining. It only gets worse from here, so you had better appreciate it.<.>"
		"<1><NPC5>My lunch money always gets stolen and I get kicked in the groin every day. That's a good thing?<.>"
		"<NPC6>*snicker*<.><CLOSE1>"
		"<0>Like I said, paradise. Enjoy it now, deal with it later.<.>"
		"But what do I care? I mean, here I am, stuck in a room with little kids all day. Do you know what kind of salary teachers make these days?<.>"
		"I should just leave you with the book and stop trying to care about my job.<.>"
		"This world is a miserable heap of talking corpses. That wraps it up for today.<.>"
		"Go home, or whatever. I don't care."
		);
		classroom_cycle++;
	}
	if(classroom_cycle==2&&GLOBAL_text_engine_state==0)
	{
			PLAYER_npc->MAP_x=(16)*8;
		PLAYER_npc->MAP_y=(34-4)*8;
		PLAYER_npc->layer=2;
		GLOBAL_main_sprite_input_off=0;
		classroom_cycle=0;
		NPC_animate_stand_dir(&teacher_npc,UP);
	}

//=================================================================================================================
//ACTIONS
//=================================================================================================================
	if(walking_into_door(RANGE_SCHOOLClassroom6ToClassHallway))
	{
		MAP_change_map(MAP_bobsgame_SCHOOLClassHallway,168,39);return;
	}
}
void bobsgame_SCHOOLClassroom6_Map_Stop_Function()
{

	NPC_delete_all_npcs();
}
void bobsgame_SCHOOLClassroom6_Map_VBL_Function()
{

}

void bobsgame_SCHOOLClassroom6_Map_HBL_Function()
{

}

//========================================================
//SCHOOLGymCafeteria
//========================================================
void bobsgame_SCHOOLGymCafeteria_Map_Load_Function()
{
//RANGE_SCHOOLGymCafeteriaToClassHallway 38*8,10*8,46*8,11*8
//RANGE_SCHOOLGymCafeteriaToEntranceHallway 38*8,53*8,46*8,54*8
//RANGE_SCHOOLGymCafeteriaToGymHallway 1*8,39*8,2*8,44*8
}

void bobsgame_SCHOOLGymCafeteria_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//11.27//down
//14.30//up
//17.35//down
//21.38//up
//32.43//down
//35.46//up
//37//down
//40//up
	static NPC* lunchkids_npcs[48] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	static NPC* hallmonitor_npc = NULL;
	if(hallmonitor_npc==NULL)
	{
		NPC_create_npc_xy_feet(&hallmonitor_npc,GFX_ADULT_hallmonitor,16,40,23*8,20*8);
		hallmonitor_npc->non_walkable=1;
		hallmonitor_npc->pushable=1;
	}
	else if(hallmonitor_npc!=NULL)
	{
		//look at you?
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&hallmonitor_npc,30))NPC_stare_at_npc(&hallmonitor_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&hallmonitor_npc, DOWN);
		//walk back and forth?
		if(ACTION_npc(&hallmonitor_npc,"Talk To Hall Monitor"))
		{
			TEXT_set_sprite_window(0,hallmonitor_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("*Grunt*<.>What does Yuu want, kid?<.>"
			"Want me to give Yuu detention for obstructing an official school procedure? Either get in line or get out!<.>"
			"<TINY><GRAY>I hope Yuu choke, Yuu delinquent.<.>"
			"<1><NORMAL><WHITE>What?!<.>"
			"<0>I didn't say anything. MOVE IT!"
			);
		}
	}
		int c=0;
	for(c=0;c<38;c++)
	{
		if(lunchkids_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			GFX* gfx=NULL;
			int type=0;
			//TODO: lunch lady behind counter
			//TODO: really loud, food thrown?
			//TODO: talk to certain kids. one seat open at each table. conversation with clique?
			//TODO: lunch menu
			//TODO: kids in seats should randomly change frames (up/down a pixel) and look left or right for a second.
			//TODO: bell rings at 1:00
			//TODO: all kids leave when bell rings
			//get kicked out?
		//TABLE 1
			if(c== 0){x=12;y=26;gfx=GFX_KID_pudgyboy;type=1;}
			if(c== 1){x=15;y=26;gfx=GFX_KID_uglyboy;type=1;}
			if(c== 2){x=18;y=26;type=2;}
			if(c== 3){x=21;y=26;type=2;}

			if(c== 4){x=12;y=30;gfx=GFX_KID_nerdboy;type=1;}
			if(c== 5){x=15;y=30;type=2;}
			if(c== 6){x=18;y=30;type=2;}
			if(c== 7){x=21;y=30;gfx=GFX_KID_notfriend;type=1;}
		//TABLE 2
			if(c== 8){x=32;y=26;gfx=GFX_KID_pudgygirl;type=1;}
			if(c== 9){x=35;y=26;gfx=GFX_KID_nerdgirl;type=1;}
			if(c==10){x=38;y=26;gfx=GFX_KID_gothboy;type=1;}
			if(c==11){x=41;y=26;gfx=GFX_KID_uglygirl;type=1;}
			//if(c==){x=32;y=30;}
			if(c==12){x=35;y=30;gfx=GFX_KID_jockgirl;type=1;}
			if(c==13){x=38;y=30;type=2;}
			if(c==14){x=41;y=30;type=2;}
		//TABLE 3
			if(c==15){x=12;y=34;gfx=GFX_KID_conceitedgirl;type=1;}
			//if(c==){x=15;y=34;}
			if(c==16){x=18;y=34;type=2;}
			if(c==17){x=21;y=34;type=2;}
			if(c==18){x=12;y=38;gfx=GFX_KID_conceitedboy;type=1;}
			//if(c==){x=15;y=38;}
			if(c==19){x=18;y=38;type=2;}
			if(c==20){x=21;y=38;type=2;}
		//TABLE 4
			if(c==21){x=32;y=34;gfx=GFX_KID_skatergirl;type=1;}
			if(c==22){x=35;y=34;gfx=GFX_KID_emoboy;type=1;}
			if(c==23){x=38;y=34;gfx=GFX_KID_punkgirl;type=1;}
			if(c==24){x=41;y=34;gfx=GFX_KID_emogirl;type=1;}
			if(c==25){x=32;y=38;gfx=GFX_KID_punkboy;type=1;}
			if(c==26){x=35;y=38;gfx=GFX_KID_gothgirl;type=1;}
			if(c==27){x=38;y=38;type=2;}
			if(c==28){x=41;y=38;type=2;}
        //TABLE 5
			if(c==29){x=12;y=42;type=2;}
			//if(c==){x=15;y=42;}
			if(c==30){x=18;y=42;type=2;}
			if(c==31){x=21;y=42;type=2;}
			if(c==32){x=12;y=46;gfx=GFX_KID_foreignboy;type=1;}
			//if(c==){x=15;y=46;}
			if(c==33){x=18;y=46;type=2;}
			//if(c==){x=21;y=46;}
		//TABLE 6
			if(c==34){x=32;y=42;gfx=GFX_KID_bully;type=1;}
			//if(c==){x=35;y=42;}
			if(c==35){x=38;y=42;gfx=GFX_KID_jockboy;type=1;}
			//if(c==){x=41;y=42;}
			//if(c==){x=32;y=46;}
			if(c==36){x=35;y=46;gfx=GFX_KID_thugboy;type=1;}
			//if(c==){x=38;y=46;}
			if(c==37){x=41;y=46;gfx=GFX_KID_greaserboy;type=1;}
			if(type==0);
			else
			if(type==1)NPC_create_npc_xy_feet(&lunchkids_npcs[c],gfx,16,32,x*8,(y*8)+3);
			else
			if(type==2)NPC_create_random_CHILD_xy_feet(&lunchkids_npcs[c],(x*8),(y*8)+3);
			if(lunchkids_npcs[c]!=NULL)lunchkids_npcs[c]->layer=2;
			if(lunchkids_npcs[c]!=NULL)lunchkids_npcs[c]->non_walkable=1;
			if(lunchkids_npcs[c]!=NULL)lunchkids_npcs[c]->ignore_fx_layer=1;
		}
		else if(lunchkids_npcs[c]!=NULL)
		{
			if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&lunchkids_npcs[c],12))NPC_stare_at_npc(&lunchkids_npcs[c],&PLAYER_npc);
			else
			{
				if(c%16<8)NPC_animate_stand_dir(&lunchkids_npcs[c],DOWN);
					else NPC_animate_stand_dir(&lunchkids_npcs[c],UP);
			}
		}
	}
	static NPC* randomkids_npcs[12]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	int randamount=12;
	//kids come in from door, 42.12    3.44
	//get in line, 3.33  3.21  20.21
	//goto trash, go in other door?  25.32  46.39   49.15
	for(c=0;c<randamount;c++)
	if(randomkids_npcs[c]==NULL&&vbl_10_var%10==c%10)
	{
		int cycle=r(2);
		if(cycle==0)
		{
			int x=(42+r(3))*8;
			int y=12*8;
			if(MAP_is_xy_within_screen_by_64px(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
		}
		if(cycle==1)
		{
			int x=3*8;
			int y=44*8;
			if(MAP_is_xy_within_screen_by_64px(x,y))NPC_create_random_CHILD_xy_feet(&randomkids_npcs[c],x,y);
		}
		if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->walking_speed = SPEED_FASTER+r(SPEED_SLOWEST-SPEED_FASTEST);
		if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->AI=cycle;
		if(randomkids_npcs[c]!=NULL)randomkids_npcs[c]->non_walkable=1;
	}
	for(c=0;c<randamount;c++)
	if(randomkids_npcs[c]!=NULL)
	{
		if(randomkids_npcs[c]->AI==0) if(randomkids_npcs[c]->MAP_y>=17*8||NPC_walk_to_xy_nohit_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, 41*8, 20*8)==1)randomkids_npcs[c]->AI+=2;//from door to line
		if(randomkids_npcs[c]->AI==1) if(randomkids_npcs[c]->MAP_y<=21*8||NPC_walk_to_xy_nohit_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed,  3*8, 24*8)==1)randomkids_npcs[c]->AI+=2;
		if(randomkids_npcs[c]->AI==2) if(randomkids_npcs[c]->MAP_x<= 4*8||NPC_walk_to_xy_nohit_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed,    3*8, 20*8)==1){randomkids_npcs[c]->AI+=2;}
		if(randomkids_npcs[c]->AI==3) if(randomkids_npcs[c]->MAP_x>=29*8||NPC_walk_to_xy_nohit_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed,   30*8, 20*8)==1){randomkids_npcs[c]->AI+=2;}

		if(randomkids_npcs[c]->AI==4) if((randomkids_npcs[c]->MAP_y>=37*8&&randomkids_npcs[c]->MAP_x>=8*8)||NPC_walk_to_xy_nohit_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed,    10*8, 40*8)==1){randomkids_npcs[c]->AI+=2;}
		if(randomkids_npcs[c]->AI==5) if(randomkids_npcs[c]->MAP_x<= 4*8||NPC_walk_to_xy_nohit_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed,    3*8, 20*8)==1){randomkids_npcs[c]->AI+=2;}
		if(randomkids_npcs[c]->AI==6) if(randomkids_npcs[c]->MAP_x>=23*8||NPC_walk_to_xy_nohit_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed,   24*8, 40*8)==1){randomkids_npcs[c]->AI+=2;}
		if(randomkids_npcs[c]->AI==7) if((randomkids_npcs[c]->MAP_y>=37*8&&randomkids_npcs[c]->MAP_x>=8*8)||NPC_walk_to_xy_nohit_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed,    10*8, 40*8)==1){randomkids_npcs[c]->AI+=2;}

		if(randomkids_npcs[c]->AI==8) if(randomkids_npcs[c]->MAP_y>=46*8||NPC_walk_to_xy_nohit_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed,   26*8, 49*8)==1){randomkids_npcs[c]->AI+=2;}
		if(randomkids_npcs[c]->AI==9) if(randomkids_npcs[c]->MAP_x>=23*8||NPC_walk_to_xy_nohit_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed,   24*8, 40*8)==1){randomkids_npcs[c]->AI+=2;}

		if(randomkids_npcs[c]->AI==10)if(randomkids_npcs[c]->MAP_x<=8*8||NPC_walk_to_xy_nohit_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed,   7*8, 50*8)==1){randomkids_npcs[c]->AI+=2;}
		if(randomkids_npcs[c]->AI==11)if(randomkids_npcs[c]->MAP_x>=48*8||NPC_walk_to_xy_nohit_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed,   49*8, 40*8)==1){randomkids_npcs[c]->AI+=2;}
		if(randomkids_npcs[c]->AI==12)if(randomkids_npcs[c]->MAP_x<= 3*8||NPC_walk_to_xy_nohit_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, 	3*8,42*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
		if(randomkids_npcs[c]->AI==13)if(randomkids_npcs[c]->MAP_y<= 9*8||NPC_walk_to_xy_nohit_pushmain(&randomkids_npcs[c], randomkids_npcs[c]->walking_speed, 	42*8,12*8)==1){NPC_delete_npc(&randomkids_npcs[c]);}
		if(MAP_is_xy_within_screen_by_64px(randomkids_npcs[c]->MAP_x,randomkids_npcs[c]->MAP_y)==0){NPC_delete_npc(&randomkids_npcs[c]);}
	}

//=================================================================================================================
//ACTIONS
//=================================================================================================================
	if(walking_into_door(RANGE_SCHOOLGymCafeteriaToClassHallway)){MAP_change_map(MAP_bobsgame_SCHOOLClassHallway,196,52);return;}
	if(walking_into_door(RANGE_SCHOOLGymCafeteriaToEntranceHallway)){MAP_change_map(MAP_bobsgame_SCHOOLEntranceHallway,196,11);return;}
	if(walking_into_door(RANGE_SCHOOLGymCafeteriaToGymHallway)){MAP_change_map(MAP_bobsgame_SCHOOLGymHallway,154,46);return;}
	}

void bobsgame_SCHOOLGymCafeteria_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_SCHOOLGymCafeteria_Map_VBL_Function()
{

}

void bobsgame_SCHOOLGymCafeteria_Map_HBL_Function()
{

}

//========================================================
//SCHOOLGymGym
//========================================================
void bobsgame_SCHOOLGymGym_Map_Load_Function()
{
//RANGE_SCHOOLGymGymToClassHallway 38*8,10*8,46*8,11*8
//RANGE_SCHOOLGymGymToEntranceHallway 38*8,53*8,46*8,54*8
//RANGE_SCHOOLGymGymToGymHallway 1*8,39*8,2*8,46*8
}

void bobsgame_SCHOOLGymGym_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//male angry teacher
	static NPC* gymteacher_npc = NULL;
	if(gymteacher_npc==NULL)
	{
		NPC_create_npc_xy_feet(&gymteacher_npc,GFX_ADULT_maleangryteacher,16,40,23*8,20*8);
		gymteacher_npc->non_walkable=1;
		gymteacher_npc->pushable=1;
	}
	else if(gymteacher_npc!=NULL)
	{
		//look at you?
		if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&gymteacher_npc,30))NPC_stare_at_npc(&gymteacher_npc,&PLAYER_npc);
		else NPC_animate_stand_dir(&gymteacher_npc, DOWN);
		//walk back and forth?
		if(ACTION_npc(&gymteacher_npc,"Talk To Gym Teacher"))
		{
			TEXT_set_sprite_window(0,gymteacher_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("How's it going, little trooper?<.>"
			"Looks to me like Yuu want to give the rope a try.<.>"
			"<1>No, not really. I'm fine.<.>"
			"<0>What's that, soldier? Don't Yuu know better than to talk back to a commanding officer?!<.>"
			"Yuu is going to climb that rope, whether he likes it or not.<.>"
			"But before that, we're going to give Yuu a little extra punishment. It's for Yuu's own good, Yuu knows.<.>"
			"*whistle* Everybody line up! We're playing dodgeball, everyone against Yuu!<.>"
			"(Class cheers)<.>"
			"<1>Oh no..<.>"
			"<0>That's right. Now get over by the wall, and we'll do this. Miss every shot and I'll give Yuu a chance at climbing the rope, just like Yuu wanted.<.>"
			"Any objections?<.>"
			"<1>Well, I..<.>"
			"<0>I didn't think so. Yuu wouldn't want to fail gym class, would he now?<.>"
			"<1>No, sir. But..<.>"
			"<0>Now that's the spirit! Get over there!"
			);
			//TODO: rope minigame
			//TODO: whistle sound
			//TODO: dodgeball minigame
		}
	}
	static NPC* classkids_npcs[15] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	int c=0;
	for(c=0;c<15;c++)
	{
		if(classkids_npcs[c]==NULL)
		{
			int x=0;
			int y=0;
			GFX* gfx=NULL;
			int dir=UP;
			if(c== 0){x=24;y=38;gfx=GFX_KID_pudgyboy;}
			if(c== 1){x=22;y=36;gfx=GFX_KID_nerdboy;}
			if(c== 2){x=20;y=37;gfx=GFX_KID_uglyboy;}
			if(c== 3){x=18;y=30;gfx=GFX_KID_nerdgirl;}
			if(c== 4){x=15;y=31;gfx=GFX_KID_uglygirl;}
			if(c== 5){x=20;y=34;gfx=GFX_KID_pudgygirl;}
			if(c== 6){x=28;y=30;gfx=GFX_KID_punkboy;}
			if(c== 7){x=30;y=27;gfx=GFX_KID_emoboy;}
			if(c== 8){x=32;y=29;gfx=GFX_KID_emogirl;}
			if(c== 9){x=29;y=32;gfx=GFX_KID_conceitedgirl;}
			if(c==10){x=24;y=45;gfx=GFX_KID_notfriend;}
			if(c==11){x=10;y=45;gfx=GFX_KID_bully;}
			if(c==12){x= 5;y=45;gfx=GFX_KID_jockboy;}
			if(c==13){x= 7;y=45;gfx=GFX_KID_greaserboy;}
			if(gfx!=NULL)
			{
				NPC_create_npc_xy_feet(&classkids_npcs[c],gfx,16,32,x*8,(y*8)+3);
				NPC_animate_stand_dir(&classkids_npcs[c], dir);
				classkids_npcs[c]->non_walkable=1;
				classkids_npcs[c]->pushable=1;
			}
		}
		if(classkids_npcs[c]!=NULL)
		{
			if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&classkids_npcs[c],20))NPC_stare_at_npc(&classkids_npcs[c],&PLAYER_npc);
			else NPC_animate_stand_dir(&classkids_npcs[c], UP);
		}
	}
//=================================================================================================================
//ACTIONS
//=================================================================================================================
	if(walking_into_door(RANGE_SCHOOLGymGymToClassHallway)){MAP_change_map(MAP_bobsgame_SCHOOLClassHallway,196,52);return;}
	if(walking_into_door(RANGE_SCHOOLGymGymToEntranceHallway)){MAP_change_map(MAP_bobsgame_SCHOOLEntranceHallway,196,11);return;}
	if(walking_into_door(RANGE_SCHOOLGymGymToGymHallway)){MAP_change_map(MAP_bobsgame_SCHOOLGymHallway,154,46);return;}
}
void bobsgame_SCHOOLGymGym_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_SCHOOLGymGym_Map_VBL_Function()
{

}

void bobsgame_SCHOOLGymGym_Map_HBL_Function()
{

}


