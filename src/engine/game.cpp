


#include "../main.h"
//#include "game.h"


int GAMESTATE= 1;

int GLOBAL_debug_level_select=78;

bool GAME_paused=0;
bool music_playing=0;

int timer_var=0;
int vbl_var=0;
int vbl_10_var=0;
int vbl_20_var=0;
int vbl_30_var=0;
int vbl_60_var=0;
int vbl_5_var=0;



int DOWN=0;
int UP=1;
int LEFT=2;
int RIGHT=3;

int UPLEFT=4;
int UPRIGHT=5;

int DOWNRIGHT=6;
int DOWNLEFT=7;


//=========================================================================================================================
void GAME_init()
{//=========================================================================================================================

	ZOOMlock=1;

	HARDWARE_init_arrays();

//update loading bar during this and swap buffer
	HARDWARE_init_gfx_data();

	ITEM_init_item_list();
	DEBUG_init();
	PLAYER_init();
	TEXT_init();
	NPC_init();


	if(GAMESTATE==INTRO)
	{



		TITLESCREEN_running=1;
		TITLESCREEN_vbl_counter=0;


		PLAYER_npc->layer=5;
		PLAYER_npc->scale=2;

		PLAYER_npc->screen_x=GAME_VIEWPORT_WIDTH_PIXELS/2-16;
		PLAYER_npc->screen_y=GAME_VIEWPORT_HEIGHT_PIXELS/2+50;

		PLAYER_npc->sprite = HARDWARE_create_sprite(GFX_KID_youngyuu,PLAYER_npc->gfx_index,PLAYER_npc->layer,PLAYER_npc->scale,PLAYER_npc->screen_x,PLAYER_npc->screen_y,255);


		title_screen();///this traps the engine, fix that so it can keep running through properly...

		TITLESCREEN_running=0;

		PLAYER_npc->gfx=GFX_KID_youngyuu;
		//PLAYER_npc->gfx=GFX_ADULT_bob;
		PLAYER_npc->layer=2;
		PLAYER_npc->scale=1;

		PLAYER_npc->anim_frame_count=1;
		NPC_animate_stand_dir(&PLAYER_npc,DOWN);

		//PLAYER_npc->gfx=GFX_KID_youngyuu;


		MAP_set_map_cam_to_cameraman();

		HARDWARE_stop_music();
		HARDWARE_set_music_volume(64);



		//MAP_change_map(MAP_bobsgame_CITYStadiumMain,93,30);



		int a=255;
		while(a>0)
		{
			fade_alpha=a;
			a-=20;
			if(a<0)a=0;

			whilefix();

		}

		//MAP_change_map(MAP_bobsgame_CITYBobsAptInside,32,9);


		MAP_change_map(MAP_bobsgame_INTROUpstairsYuusRoom,16,14);

		//battery_quest=9;
		//battery_quest=7;
		//MAP_change_map(MAP_bobsgame_INTRODownstairs,5,27);
		//MAP_change_map(MAP_bobsgame_INTROTown,32,76);
		//MAP_change_map(MAP_bobsgame_INTROTown,4,35);
		//MAP_change_map(MAP_bobsgame_INTROTown,200,35);
		//MAP_change_map(MAP_bobsgame_CITYBobsAptInside,17,22);





		//PLAYER_npc->visible=0;
		//MAP_change_map(MAP_bobsgame_MISCCastRoom,64/2,64/2);



		//MAP_change_map(MAP_bobsgame_MISCMeetingRoom,14,20);
		//MAP_change_map(MAP_bobsgame_INTROBasement,16,30);
		//MAP_change_map(MAP_bobsgame_INTROTown,244,80);


			//HARDWARE_fade_palette
			/*{///fix this

					int from = -31;
					int to = 0;
					int amt=0;

					if(from<=to)amt=1;
					else if(from>=to)amt=-1;

					int p=from;

					while(p!=to&&MAIN_QUIT==false)
					{
						if(fade_vbl_counter%2==0)
						{
							fade_vbl_counter++;

							HARDWARE_create_brightened_palette(HARDWARE_map_palette,(int*)&GAME_temp_TILESET_PALETTE,p);

							HARDWARE_load_bg_palette((int*)&GAME_temp_TILESET_PALETTE);
							HARDWARE_reload_bg_textures();

							p+=amt;

						}

						whilefix();
					}

			}*/


		/*CLOCK_unknown=1;
		CLOCK_init();

		CLOCK_hour=12+5;
		CLOCK_minute=0;
		CLOCK_day=MONDAY;

		CLOCK_moving=true;
		CLOCK_update_clock();*/

		CLOCK_paused=1;

		//ITEM_get_no_caption(&GameToy);
		//ITEM_get_no_caption(&CannedAir);
		//ITEM_get_no_caption(&LunchBag);
		//ITEM_get_no_caption(&CoatHanger);
		//ITEM_get_no_caption(&GameToyColors);
		//ITEM_get_no_caption(&ElectricToothbrush);
		//ITEM_get_no_caption(&SuperGlue);

	}


	if(GAMESTATE==TOWN)
	{

		PLAYER_npc->gfx=GFX_KID_yuu;

		MAP_set_map_cam_to_cameraman();


		//ITEM_get(&CannedAir);

		//MAP_change_map(MAP_bobsgame_CITYBobsAptInsideTrashed,32,9);

		//MAP_change_map(MAP_bobsgame_TOWNTown,1474,235);//movie theatre
		//MAP_change_map(MAP_bobsgame_TOWNTown,1368,270);//music store
		//MAP_change_map(MAP_bobsgame_TOWNTown,1280,270);//arcade
		//MAP_change_map(MAP_bobsgame_TOWNTown,1240,270);//game store
		//MAP_change_map(MAP_bobsgame_TOWNTown,1195,270);//video rent
		//MAP_change_map(MAP_bobsgame_TOWNTown,1160,270);//electronics
		//MAP_change_map(MAP_bobsgame_TOWNTown,1095,240);//grocery
		//MAP_change_map(MAP_bobsgame_TOWNTown,985,240);//department
		//MAP_change_map(MAP_bobsgame_TOWNTown,915,270);//pet store
		//MAP_change_map(MAP_bobsgame_TOWNTown,880,270);//beauty
		//MAP_change_map(MAP_bobsgame_TOWNTown,840,270);//pizza
		//MAP_change_map(MAP_bobsgame_TOWNTown,800,270);//bookstore
		//MAP_change_map(MAP_bobsgame_TOWNTown,775,270);//coffee
		//MAP_change_map(MAP_bobsgame_TOWNTown,711,240);//gas station
		//MAP_change_map(MAP_bobsgame_TOWNTown,575,300);//tacoburger
		//MAP_change_map(MAP_bobsgame_TOWNTown,500,300);//church
		//MAP_change_map(MAP_bobsgame_TOWNTown,400,300);//clinic

		//MAP_change_map(MAP_bobsgame_TOWNTown,240,280);//school

		//MAP_change_map(MAP_bobsgame_TOWNTown,506,510);//yuu house
		//MAP_change_map(MAP_bobsgame_TOWNTown,525,460);//yuu house backyard
		//MAP_change_map(MAP_bobsgame_TOWNTown,800,270);
		//MAP_change_map(MAP_bobsgame_TOWNTown,800,270);


		//MAP_change_map(MAP_bobsgame_TOWNTown,492,531);//dog walker/jogger 7 am/6 am
		//MAP_change_map(MAP_bobsgame_TOWNTown,1500,531);//ice cream man 5 pm
		//MAP_change_map(MAP_bobsgame_TOWNTown,492,540);//mailman 10 am

		//MAP_change_map(MAP_bobsgame_TOWNYUUUpstairsYuusRoom,16,14);
		//MAP_change_map(MAP_bobsgame_TOWNYUUDownstairs,16,14);
		//MAP_change_map(MAP_bobsgame_TOWNYUUDownstairs,48,35);
		//MAP_change_map(MAP_bobsgame_TOWNYUUDownstairs,34,21);



		//MAP_change_map(MAP_bobsgame_TOWNFRIENDDownstairs,20,16);
		//MAP_change_map(MAP_bobsgame_JAPANUpstairsMainBedroom,10,16);
		//MAP_change_map(MAP_bobsgame_TOWNCRAZYDownstairs,7,15);
		//MAP_change_map(MAP_bobsgame_SCHOOLPlayground,35,182);



		//MAP_change_map(MAP_bobsgame_TOWNTown,800,270);
		MAP_change_map(MAP_bobsgame_SCHOOLEntranceHallway,153,40);
		//MAP_change_map(MAP_bobsgame_SCHOOLGymHallway,103,46);
		//MAP_change_map(MAP_bobsgame_SCHOOLBackHallway,103,46);
		//MAP_change_map(MAP_bobsgame_SCHOOLClassroom6,21,30);
		//MAP_change_map(MAP_bobsgame_SCHOOLGymGym,21,30);
		//MAP_change_map(MAP_bobsgame_TOWNCoffeeShop,15,30);
		//MAP_change_map(MAP_bobsgame_TOWNPizzaPlace,25,25);
		//MAP_change_map(MAP_bobsgame_TOWNBookstore,20,27);
		//MAP_change_map(MAP_bobsgame_TOWNVideoRent,20,24);
		//MAP_change_map(MAP_bobsgame_TOWNRecordStore,24,24);
		//MAP_change_map(MAP_bobsgame_TOWNPets4Less,20,24);
		//MAP_change_map(MAP_bobsgame_TOWNElectronicsStore,20,25);
		//MAP_change_map(MAP_bobsgame_TOWNBeautySalon,22,32);
		//MAP_change_map(MAP_bobsgame_TOWNArcade,22,16);
		//MAP_change_map(MAP_bobsgame_TOWNGroceryStore,22,16);
		//MAP_change_map(MAP_bobsgame_TOWNGasStation,22,16);
		//MAP_change_map(MAP_bobsgame_TOWNDepartmentStore,57,72);
		//MAP_change_map(MAP_bobsgame_TOWNTacoBurger,22,16);
		//MAP_change_map(MAP_bobsgame_TOWNChurch,21,40);
		//MAP_change_map(MAP_bobsgame_TOWNDoctorsOfficeEntrance,6,21);
		//MAP_change_map(MAP_bobsgame_TOWNGameStore,6,21);
		//MAP_change_map(MAP_bobsgame_TOWNMovieTheatreLobby,10,20);
		//MAP_change_map(MAP_bobsgame_TOWNMovieTheatreMainHall,70,42);
		//MAP_change_map(MAP_bobsgame_TOWNMovieTheatreMensBathroom,15,16);
		//MAP_change_map(MAP_bobsgame_TOWNMovieTheaterBuffer,5,16);


		CLOCK_unknown=0;
		CLOCK_init();


		CLOCK_hour=7;//12+4;
		CLOCK_minute=0;
		CLOCK_day=MONDAY;


		CLOCK_moving=true;
		CLOCK_update_clock();

		CLOCK_paused=0;
	}




	if(GAMESTATE==CITY)
	{

		PLAYER_npc->gfx=GFX_KID_yuu;

		MAP_set_map_cam_to_cameraman();

		MAP_change_map(MAP_bobsgame_CITYCity,1000,45);
		//MAP_change_map(MAP_bobsgame_CITYPartyStore,16,16);
		//MAP_change_map(MAP_bobsgame_CITYGroovyClubEntrance,16,16);
		//MAP_change_map(MAP_bobsgame_CITYGroovyClub,48,73);
		//MAP_change_map(MAP_bobsgame_CITYOfficeEntrance,32,32);
		//MAP_change_map(MAP_bobsgame_CITYOfficeWorkroom,32,26);
		//MAP_change_map(MAP_bobsgame_CITYOfficeBreakRoom,32,15);
		//MAP_change_map(MAP_bobsgame_CITYOfficeBossFloor,25,25);
		//MAP_change_map(MAP_bobsgame_CITYNeighborAptInside,15,20);
		//MAP_change_map(MAP_bobsgame_CITYAptMainOffice,40,15);
		//MAP_change_map(MAP_bobsgame_CITYBankEntrance,20,21);
		//MAP_change_map(MAP_bobsgame_CITYBankOwnerOffice,20,21);
		//MAP_change_map(MAP_bobsgame_CITYFancyRestaurantEntrance,15,15);
		//MAP_change_map(MAP_bobsgame_CITYFancyRestaurantKitchen,15,15);
		//MAP_change_map(MAP_bobsgame_CITYFashionStore,15,15);
		//MAP_change_map(MAP_bobsgame_CITYElevatedLifeplace,15,15);
		//MAP_change_map(MAP_bobsgame_CITYElevatedLifeplaceElevator,5,13);
		//MAP_change_map(MAP_bobsgame_CITYDeli,15,15);
		//MAP_change_map(MAP_bobsgame_CITYTheCafe,15,15);
		//MAP_change_map(MAP_bobsgame_CITYPoolHall,15,15);
		//MAP_change_map(MAP_bobsgame_CITYLaundromat,15,15);
		//MAP_change_map(MAP_bobsgame_CITYHospitalEntrance,25,40);
		//MAP_change_map(MAP_bobsgame_CITYHospitalWaitingOutPatient,25,40);
		//MAP_change_map(MAP_bobsgame_CITYHospitalOperatingRoom,15,15);
		//MAP_change_map(MAP_bobsgame_CITYHospitalPsychiatricWard,25,40);
		//MAP_change_map(MAP_bobsgame_CITYHospitalMaternityWard,60,25);
		//MAP_change_map(MAP_bobsgame_CITYHospitalMorgue,60,25);
		//MAP_change_map(MAP_bobsgame_CITYPoliceStationLobby,25,20);
		//MAP_change_map(MAP_bobsgame_CITYPoliceStationPrisonVisitingRoom,15,24);
		//MAP_change_map(MAP_bobsgame_CITYFireDepartmentGarage,45,50);
		//MAP_change_map(MAP_bobsgame_CITYFireDepartmentQuarters,24,14);
		//MAP_change_map(MAP_bobsgame_CITYCityHallEntrance,24,45);
		//MAP_change_map(MAP_bobsgame_CITYCityHallOffices,24,45);
		//MAP_change_map(MAP_bobsgame_CITYCityHallMeetingRoom,24,45);
		//MAP_change_map(MAP_bobsgame_CITYCityHallMayorOffice,24,40);
		//MAP_change_map(MAP_bobsgame_CITYMuseumLobby,24,20);
		//MAP_change_map(MAP_bobsgame_CITYHotelEntrance,24,20);
		//MAP_change_map(MAP_bobsgame_CITYHotelPool,13,52);
		//MAP_change_map(MAP_bobsgame_CITYHotelSauna,6,21);
		//MAP_change_map(MAP_bobsgame_CITYHotelHallway,24,40);
		//MAP_change_map(MAP_bobsgame_CITYStadiumLobby,24,25);
		//MAP_change_map(MAP_bobsgame_CITYStadiumBathroomLeftMens,24,19);
		//MAP_change_map(MAP_bobsgame_CITYStadiumBackstage,24,15);
		//MAP_change_map(MAP_bobsgame_CITYStadiumMain,20,25);
		//MAP_change_map(MAP_bobsgame_CITYStadiumMain,100,204);
		//MAP_change_map(MAP_bobsgame_CITYPawnShop,15,25);
		//MAP_change_map(MAP_bobsgame_CITYCasinoEntrance,25,25);
		//MAP_change_map(MAP_bobsgame_CITYCasinoMain,20,20);
		//MAP_change_map(MAP_bobsgame_CITYCasinoBackroom,6,18);
		//MAP_change_map(MAP_bobsgame_CITYHourlyMotel,22,64);

	}


	load_bg_pals_based_on_time();
	HARDWARE_reload_bg_textures();

	ZOOMlock=0;
	ZOOMto=1.0f;

}



//=========================================================================================================================
void GAME_vbl()
{//=========================================================================================================================

	vbl_var++;

	if(vbl_var%5==0)vbl_5_var++;
	if(vbl_var%10==0)vbl_10_var++;
	if(vbl_var%20==0)vbl_20_var++;
	if(vbl_var%30==0)vbl_30_var++;
	if(vbl_var%60==0)vbl_60_var++;
	if(vbl_10_var==60)vbl_10_var=0;
	if(vbl_20_var==60)vbl_20_var=0;
	if(vbl_30_var==60)vbl_30_var=0;
	if(vbl_60_var==60)vbl_60_var=0;

	if(vbl_var==60)
	{
		vbl_var=0;
		timer_var=0;



		//{
		//	static CAPTION* mainspritespeed= NULL;
		//	static int lastx=0;
		//	int pxpersec = PLAYER_npc->MAP_x-lastx;
		//	if(pxpersec<0)pxpersec*=-1;
		//	lastx=PLAYER_npc->MAP_x;
		//	char speed[5] = {0,0,0,0,'\0'};
		//	speed[0]=(pxpersec/1000)+48;
		//	speed[1]=(pxpersec%1000/100)+48;
		//	speed[2]=(pxpersec%1000%100/10)+48;
		//	speed[3]=(pxpersec%1000%100%10)+48;
		//	if(mainspritespeed!=NULL){CAPTION_delete_caption(mainspritespeed);}
		//	if(mainspritespeed==NULL)CAPTION_make_caption(&mainspritespeed,0,128,10,-1,(char*)speed,FONT_TINY_ID,WHITE,BLACK);
		//}

	}

	if(GAME_paused==1)
	{
		start_screen_vbl();
	}

	CLOCK_vbl();
	TEXT_vbl();
	CAPTION_vbl();
	LETTERBOX_vbl();
	PLAYER_vbl();
	DEBUG_vbl();



	//if(GLOBAL_map_initialized==1)
	{
		MAP_set_map_cam_to_cameraman();

		MAP_current_map_vbl_function();



		delete_unneeded_metatiles();

		static int f=0;
		if(framesrendered%2==0)
		{
			f++;
			if(f>3)f=0;
			create_needed_metatiles(f);//nice and smooth! a little bit of ghosting but thats ok :-)
		}


	}

	if(GAME_playing_tetrid==1)TETRID_vbl();
	if(GAME_playing_ping==1)PING_vbl();
	if(GAME_playing_ramio==1)RAMIO_vbl();

	NPC_vbl();	//keep this here otherwise sprites "lag" back and forth




}

//=========================================================================================================================
void GAME_timer()
{//=========================================================================================================================


	//======================timers
	//sprite timer
	cameraman->ms++;

	//npc timer
	if(first_NPC!=NULL)
	{
		NPC* current_npc = first_NPC;
		bool stop=0;
		while(stop==0)
		{
			current_npc->ms++;
			if(current_npc->next!=NULL)current_npc = (NPC* )current_npc->next; else stop=1;
		}
	}


	timer_var++;

	//start screen timer
	if(GAME_paused==1)start_screen_timer();



}


//=========================================================================================================================
void GAME_main(int gamespeed) //kodenermaschiniene
{//=========================================================================================================================



	reset_controls();//this really only needs to happen once per frame
	check_controls();

		//if(c==0)
		{
			//check for pause
			if(BUTTON_START_PRESSED)
			{
				if(GAME_paused==0)
				{
					if(GLOBAL_text_engine_state==0&&GLOBAL_main_sprite_input_off==0)//GLOBAL_map_initialized==1&&
					start_screen_init();
				}
				else
				start_screen_deinit();
			}

			if(GAME_paused==1)start_screen_main();

			//=====================text===================
			int t=0;
			for(t=0;t<4;t++)
			TEXT_main();

			CLOCK_main();
			CAPTION_main();
		}

	int c=0;
	for(c=0;c<gamespeed;c++)
	{

		GAME_timer();//this should run about 1200 times a second, or 20 times a frame

		NPC_main();
		PLAYER_main();

		if(GAME_playing_tetrid==1)TETRID_main();
		if(GAME_playing_ping==1)PING_main();
		if(GAME_playing_ramio==1)RAMIO_main();

		MAP_main();

	}

	HARDWARE_unload_wavs_done_playing();

}



