



#include "../../main.h"
//#include "debug.h"




//==========================================================================================================================
void calculate_fps()
{//==========================================================================================================================


        //-----------------------------
        //FPS
        //-----------------------------

			static int secondstotal=0;
			secondspassed = (float)(SDL_GetTicks())/1000;

			static DEBUG_overlay_STRUCT* fps_overlay = NULL;


			if(secondspassed>lastsecondspassed)
			{
				lastsecondspassed=secondspassed;
				fps = framesrendered;
				framesrendered=0;

				secondstotal++;

				if(fpsmeter)
				{
					char fpschar[128];
					sprintf(fpschar,"fps:%c%c%c",48+((fps/100)%10),48+((fps/10)%10),48+(fps%10));

					if(fps_overlay==NULL)fps_overlay = DEBUG_make_overlay((char*)fpschar,(HARDWARE_SCREEN_WIDTH_PIXELS/2)-20,HARDWARE_SCREEN_HEIGHT_PIXELS-10);
					else DEBUG_update_overlay(fps_overlay,(char*)fpschar,(HARDWARE_SCREEN_WIDTH_PIXELS/2)-(fps_overlay->width/2),HARDWARE_SCREEN_HEIGHT_PIXELS-10);

					//if(fpscaption==NULL)CAPTION_make_caption(&fpscaption,1,CAPTION_CENTERED_X,0,-1,(char*)fpschar,FONT_SMALL_ID,WHITE,CLEAR,1,1);
					//else if(fpscaption!=NULL)CAPTION_replace_text(fpscaption,(char*)fpschar);
				}
				else
				{
					//if(fpscaption!=NULL)CAPTION_delete_caption(fpscaption);
					if(fps_overlay!=NULL)DEBUG_delete_overlay(fps_overlay);fps_overlay=NULL;

				}

				if(secondstotal>1&&fps>70&&vsync==1)
				{
					vsync=0;
					CAPTION_make_caption(NULL,1,CAPTION_CENTERED_X,10,10,"Please Turn VSync On - See Readme",FONT_HUGE_ID,RED,CLEAR,5,1);
					//fprintf(stderr,"Vsync Hard-Limiter Activated. Please check your Video Settings Control Panel for a \"vertical sync\" option and turn it on for smoother gameplay.\n");
				}
			}


			static int tilexyswitch=1;
			//static CAPTION* tilecaption=NULL;
			static char tilexy[10];
			static int curx=0;
			static int cury=0;

			static DEBUG_overlay_STRUCT* tilexy_overlay = NULL;

			if(tilexyswitch==1)
			{
				if(curx!= (PLAYER_npc->MAP_x+PLAYER_npc->size_x/2)/8||cury!=((PLAYER_npc->MAP_y+(PLAYER_npc->size_y-6))/8)+1)
				{
					curx=(PLAYER_npc->MAP_x+PLAYER_npc->size_x/2)/8;
					cury=((PLAYER_npc->MAP_y+(PLAYER_npc->size_y-PLAYER_npc->hitsize_y))/8)+1;
					tilexy[0]=(curx/1000)+48;
					tilexy[1]=(curx%1000/100)+48;
					tilexy[2]=(curx%1000%100/10)+48;
					tilexy[3]=(curx%1000%100%10)+48;
					tilexy[4]=',';
					tilexy[5]=(cury/1000)+48;
					tilexy[6]=(cury%1000/100)+48;
					tilexy[7]=(cury%1000%100/10)+48;
					tilexy[8]=(cury%1000%100%10)+48;
					tilexy[9]='\0';

					if(tilexy_overlay==NULL)tilexy_overlay = DEBUG_make_overlay((char*)tilexy,HARDWARE_SCREEN_WIDTH_PIXELS-50,HARDWARE_SCREEN_HEIGHT_PIXELS-10);
					else DEBUG_update_overlay(tilexy_overlay,(char*)tilexy,HARDWARE_SCREEN_WIDTH_PIXELS-tilexy_overlay->width,HARDWARE_SCREEN_HEIGHT_PIXELS-10);

					//if(tilecaption==NULL)CAPTION_make_caption(&tilecaption,1,GAME_VIEWPORT_WIDTH_PIXELS-(50*ZOOM),0,-1,(char*)tilexy,FONT_SMALL_ID,WHITE,BLACK,5,1);
					//if(tilecaption!=NULL){CAPTION_replace_text(tilecaption,(char*)tilexy);}//CAPTION_delete_caption(tilecaption);}
				}
			}


			static int zoomcaptionswitch=1;
			static CAPTION* zoomcaption=NULL;
			static char zoomchar[4];
			static float curzoom=1.00f;

			if(zoomcaptionswitch==1)
			{
				if(curzoom!=ZOOMto)
				{
					curzoom=ZOOMto;
					zoomchar[0]=((int)((int)(curzoom)))+48;
					zoomchar[1]=((int)((int)(curzoom*10.0f))%10)+48;
					zoomchar[2]=((int)((int)(curzoom*100.0f))%10)+48;
					zoomchar[3]='\0';

					if(zoomcaption==NULL)CAPTION_make_caption(&zoomcaption,1,200,0,-1,(char*)zoomchar,FONT_SMALL_ID,WHITE,BLACK,5,1);
					if(zoomcaption!=NULL){CAPTION_replace_text(zoomcaption,(char*)zoomchar);}//CAPTION_delete_caption(tilecaption);}
				}
			}

/*
            char mapxchar[5];
            mapxchar[0] = 48+((abs(MAP_cam_x)/1000)%10);
            mapxchar[1] = 48+((abs(MAP_cam_x)/100)%10);
            mapxchar[2] = 48+((abs(MAP_cam_x)/10)%10);
            mapxchar[3] = 48+(abs(MAP_cam_x)%10);
            mapxchar[4] = '\0';

            static CAPTION* mapxcaption = NULL;
            if(mapxcaption==NULL)CAPTION_make_caption(&mapxcaption,1,GAME_VIEWPORT_WIDTH_PIXELS/2+100,0,-1,(char*)mapxchar,FONT_SMALL_ID,WHITE,BLACK);
            //void CAPTION_make_caption(CAPTION**caption_pp,int screen,int x,int y,int seconds,char *caption_text,int caption_font_id,int caption_text_color,int caption_bg_color) //-1 seconds for stay open until manual delete :)
            CAPTION_replace_text(mapxcaption,(char*)mapxchar);
*/

}






//=========================================================================================================================
void DEBUG_init()
{//=========================================================================================================================


}



//=========================================================================================================================
void DEBUG_main()
{//=========================================================================================================================


		/* if(BUTTON_START_HELD)
		{
			while(BUTTON_START_HELD&&MAIN_QUIT==false)whilefix();

			if(GLOBAL_text_engine_state==0&&GLOBAL_main_sprite_input_off==0)
			{
				//if(music_playing==1){HARDWARE_stop_music();music_playing=0;}
				//else{HARDWARE_play_music_file(current_mod);music_playing=1;}

				GLOBAL_debug_level_select++;
				if(GLOBAL_debug_level_select>81)GLOBAL_debug_level_select=0;

				switch(GLOBAL_debug_level_select)
				{

				case  0: {MAP_change_map(MAP_bobsgame_TOWNYUUUpstairsYuusRoom,16,14);PLAYER_npc->gfx_filename=yuu;break;}
				//case  0: {MAP_change_map(MAP_bobsgame_MISCCastRoom,14,14);break;}


				case  1: {MAP_change_map(MAP_bobsgame_SCHOOLEntranceHallway,153,47);break;}
				case  2: {MAP_change_map(MAP_bobsgame_SCHOOLGymHallway,103,46);break;}
				case  3: {MAP_change_map(MAP_bobsgame_SCHOOLBackHallway,103,46);break;}
				case  4: {MAP_change_map(MAP_bobsgame_SCHOOLClassroom6,21,30);break;}
				case  5: {MAP_change_map(MAP_bobsgame_SCHOOLGymGym,21,30);break;}



				case  6: {MAP_change_map(MAP_bobsgame_TOWNCoffeeShop,15,30);break;}
				case  7: {MAP_change_map(MAP_bobsgame_TOWNPizzaPlace,25,25);break;}
				case  8: {MAP_change_map(MAP_bobsgame_TOWNBookstore,20,27);break;}
				case  9: {MAP_change_map(MAP_bobsgame_TOWNVideoRent,20,24);break;}
				case 10: {MAP_change_map(MAP_bobsgame_TOWNRecordStore,24,24);break;}
				case 11: {MAP_change_map(MAP_bobsgame_TOWNPets4Less,20,24);break;}
				case 12: {MAP_change_map(MAP_bobsgame_TOWNElectronicsStore,20,25);break;}
				case 13: {MAP_change_map(MAP_bobsgame_TOWNBeautySalon,22,32);break;}
				case 14: {MAP_change_map(MAP_bobsgame_TOWNArcade,22,16);break;}
				case 15: {MAP_change_map(MAP_bobsgame_TOWNGroceryStore,22,16);break;}
				case 16: {MAP_change_map(MAP_bobsgame_TOWNDepartmentStore,22,16);break;}
				case 17: {MAP_change_map(MAP_bobsgame_TOWNGasStation,22,16);break;}
				case 18: {MAP_change_map(MAP_bobsgame_TOWNDepartmentStore,57,72);break;}
				case 19: {MAP_change_map(MAP_bobsgame_TOWNTacoBurger,22,16);break;}
				case 20: {MAP_change_map(MAP_bobsgame_TOWNChurch,21,40);break;}
				case 21: {MAP_change_map(MAP_bobsgame_TOWNDoctorsOfficeEntrance,6,21);break;}
				case 22: {MAP_change_map(MAP_bobsgame_TOWNGameStore,6,21);break;}


				case 23: {MAP_change_map(MAP_bobsgame_TOWNMovieTheatreLobby,10,20);break;}
				case 24: {MAP_change_map(MAP_bobsgame_TOWNMovieTheatreMainHall,70,42);break;}
				case 25: {MAP_change_map(MAP_bobsgame_TOWNMovieTheatreMensBathroom,15,16);break;}
				case 26: {MAP_change_map(MAP_bobsgame_TOWNMovieTheaterBuffer,5,16);break;}


				case 27: {MAP_change_map(MAP_bobsgame_TOWNFRIENDDownstairs,20,16);break;}
				case 28: {MAP_change_map(MAP_bobsgame_TOWNCRAZYDownstairs,20,16);break;}
				case 29: {MAP_change_map(MAP_bobsgame_TOWNMANSIONDownstairs,20,16);break;}
				case 30: {MAP_change_map(MAP_bobsgame_JAPANUpstairsMainBedroom,10,16);break;}


				case 31: {MAP_change_map(MAP_bobsgame_CITYPartyStore,16,16);break;}
				case 32: {MAP_change_map(MAP_bobsgame_CITYGroovyClubEntrance,16,16);break;}
				case 33: {MAP_change_map(MAP_bobsgame_CITYGroovyClub,48,73);break;}
				case 34: {MAP_change_map(MAP_bobsgame_CITYOfficeEntrance,32,32);break;}
				case 35: {MAP_change_map(MAP_bobsgame_CITYOfficeWorkroom,32,26);break;}
				case 36: {MAP_change_map(MAP_bobsgame_CITYOfficeBreakRoom,32,15);break;}
				case 37: {MAP_change_map(MAP_bobsgame_CITYOfficeBossFloor,25,25);break;}
				//case 38: {MAP_change_map(MAP_bobsgame_CITYNeighborAptInside,15,20);break;}
				case 39: {MAP_change_map(MAP_bobsgame_CITYAptMainOffice,40,15);break;}
				case 40: {MAP_change_map(MAP_bobsgame_CITYBankEntrance,20,21);break;}
				case 41: {MAP_change_map(MAP_bobsgame_CITYBankOwnerOffice,20,21);break;}
				case 42: {MAP_change_map(MAP_bobsgame_CITYFancyRestaurantEntrance,15,15);break;}
				case 43: {MAP_change_map(MAP_bobsgame_CITYFancyRestaurantKitchen,15,15);break;}
				case 44: {MAP_change_map(MAP_bobsgame_CITYFashionStore,15,15);break;}
				case 45: {MAP_change_map(MAP_bobsgame_CITYElevatedLifeplace,15,15);break;}
				case 46: {MAP_change_map(MAP_bobsgame_CITYElevatedLifeplaceElevator,5,13);break;}
				case 47: {MAP_change_map(MAP_bobsgame_CITYDeli,15,15);break;}
				case 48: {MAP_change_map(MAP_bobsgame_CITYTheCafe,15,15);break;}
				case 49: {MAP_change_map(MAP_bobsgame_CITYPoolHall,15,15);break;}
				case 50: {MAP_change_map(MAP_bobsgame_CITYLaundromat,15,15);break;}
				case 51: {MAP_change_map(MAP_bobsgame_CITYHospitalEntrance,25,40);break;}
				case 52: {MAP_change_map(MAP_bobsgame_CITYHospitalWaitingOutPatient,25,40);break;}
				case 53: {MAP_change_map(MAP_bobsgame_CITYHospitalOperatingRoom,15,15);break;}
				case 54: {MAP_change_map(MAP_bobsgame_CITYHospitalPsychiatricWard,25,40);break;}
				case 55: {MAP_change_map(MAP_bobsgame_CITYHospitalMaternityWard,60,25);break;}
				case 56: {MAP_change_map(MAP_bobsgame_CITYHospitalMorgue,60,25);break;}
				case 57: {MAP_change_map(MAP_bobsgame_CITYPoliceStationLobby,25,20);break;}
				case 58: {MAP_change_map(MAP_bobsgame_CITYPoliceStationPrisonVisitingRoom,15,24);break;}
				case 59: {MAP_change_map(MAP_bobsgame_CITYFireDepartmentGarage,45,50);break;}
				case 60: {MAP_change_map(MAP_bobsgame_CITYFireDepartmentQuarters,24,14);break;}
				case 61: {MAP_change_map(MAP_bobsgame_CITYCityHallEntrance,24,45);break;}
				case 62: {MAP_change_map(MAP_bobsgame_CITYCityHallOffices,24,45);break;}
				case 63: {MAP_change_map(MAP_bobsgame_CITYCityHallMeetingRoom,24,45);break;}
				case 64: {MAP_change_map(MAP_bobsgame_CITYCityHallMayorOffice,24,40);break;}
				case 65: {MAP_change_map(MAP_bobsgame_CITYMuseumLobby,24,20);break;}
				case 66: {MAP_change_map(MAP_bobsgame_CITYHotelEntrance,24,20);break;}
				case 67: {MAP_change_map(MAP_bobsgame_CITYHotelPool,13,52);break;}
				case 68: {MAP_change_map(MAP_bobsgame_CITYHotelSauna,6,21);break;}
				case 69: {MAP_change_map(MAP_bobsgame_CITYHotelHallway,24,40);break;}
				case 70: {MAP_change_map(MAP_bobsgame_CITYStadiumLobby,24,25);break;}
				case 71: {MAP_change_map(MAP_bobsgame_CITYStadiumBathroomLeftMens,24,19);break;}
				case 72: {MAP_change_map(MAP_bobsgame_CITYStadiumBackstage,24,15);break;}
				case 73: {MAP_change_map(MAP_bobsgame_CITYStadiumMain,20,25);break;}
				case 74: {MAP_change_map(MAP_bobsgame_CITYPawnShop,15,25);break;}
				case 75: {MAP_change_map(MAP_bobsgame_CITYCasinoEntrance,25,25);break;}
				case 76: {MAP_change_map(MAP_bobsgame_CITYCasinoMain,20,20);break;}
				case 77: {MAP_change_map(MAP_bobsgame_CITYCasinoBackroom,6,18);break;}
				case 78: {MAP_change_map(MAP_bobsgame_CITYHourlyMotel,22,64);break;}
				case 79: {MAP_change_map(MAP_bobsgame_SCHOOLPlayground,22,64);break;}
				case 80: {MAP_change_map(MAP_bobsgame_CITYCity,1000,45);break;}
				case 81: {MAP_change_map(MAP_bobsgame_INTROUpstairsYuusRoom,16,14);PLAYER_npc->gfx_filename=youngyuu;break;}


				//case  79: {MAP_change_map(MAP_bobsgame_TOWNTown,800,270);break;}

				default: break;
				}



*/



	//==========DEBUG===============================================================================================================
		//if(BUTTON_L_HELD)CLOCK_second++;
		//if(BUTTON_L_HELD)
		{
		 //while(BUTTON_L_HELD&&MAIN_QUIT==false)whilefix();

		 //if(LETTERBOX_on==0)LETTERBOX_init(32,1);else if(LETTERBOX_sprites_exist)LETTERBOX_deinit();

		}

		//if(BUTTON_Y_HELD)//test making a clone of main sprite as an npc
		//{
			//while(BUTTON_Y_HELD&&MAIN_QUIT==false)whilefix();
			//NPC_create_npc_xy_feet(NULL,yuu,16,32,PLAYER_npc->MAP_x+PLAYER_npc->size_x,PLAYER_npc->MAP_y+PLAYER_npc->size_y);
		//}

		/*
		if(BUTTON_SELECT_HELD) //delete all npcs
		{
			while(BUTTON_SELECT_HELD&&MAIN_QUIT==false)whilefix();
		 NPC_delete_all_npcs();
		}
		if(BUTTON_X_HELD) //delete last npc
		{
			while(BUTTON_X_HELD&&MAIN_QUIT==false){whilefix();}
			NPC *last_npc = PLAYER_npc;
			while(last_npc->next!=NULL)
			{
			 last_npc = (NPC *)last_npc->next;
			}
			if(last_npc==clicktarget)
			if(last_npc!=PLAYER_npc)NPC_delete_npc(last_npc);
		}	*/

		/*	static int tilexyswitch=0;
			static CAPTION* tilecaption=NULL;
			static char tilexy[10];
			static int curx=0;
			static int cury=0;

			if(BUTTON_SELECT_HELD)
			{
				while(BUTTON_SELECT_HELD&&MAIN_QUIT==false)whilefix();
				if(tilexyswitch==0)
				{
					tilexyswitch=1;
					if(tilecaption==NULL)CAPTION_make_caption(&tilecaption,0,128,0,-1,(char*)tilexy,FONT_TINY_ID,WHITE,BLACK);
				}
				else
				{
					tilexyswitch=0;
					if(tilecaption!=NULL){CAPTION_delete_caption(tilecaption);}
				}
			}

			if(tilexyswitch==1)
			{
				if(curx!= (PLAYER_npc->MAP_x+PLAYER_npc->size_x/2)/8||cury!=((PLAYER_npc->MAP_y+(PLAYER_npc->size_y-6))/8)+1)
				{
					curx=(PLAYER_npc->MAP_x+PLAYER_npc->size_x/2)/8;
					cury=((PLAYER_npc->MAP_y+(PLAYER_npc->size_y-PLAYER_npc->hitsize_y))/8)+1;
					tilexy[0]=(curx/1000)+48;
					tilexy[1]=(curx%1000/100)+48;
					tilexy[2]=(curx%1000%100/10)+48;
					tilexy[3]=(curx%1000%100%10)+48;
					tilexy[4]=',';
					tilexy[5]=(cury/1000)+48;
					tilexy[6]=(cury%1000/100)+48;
					tilexy[7]=(cury%1000%100/10)+48;
					tilexy[8]=(cury%1000%100%10)+48;
					tilexy[9]='\0';

					if(tilecaption!=NULL){CAPTION_replace_text(tilecaption,(char*)tilexy);}//CAPTION_delete_caption(tilecaption);}
				}
			}

	*/




	/*if(BUTTON_SELECT_HELD&&BUTTON_L_HELD&&BUTTON_R_HELD)
	{
		PLAYER_npc->gfx_filename=yuu;
		MAP_change_map(MAP_bobsgame_TOWNYUUUpstairsYuusRoom,16,14);
	}*/

/*
		if(bottom_screen_on==0)
		{
			if(last_npcs_created!=npcs_created||update_debug_counters==1)
			{
				if(last_npcs_created!=npcs_created)last_npcs_created=npcs_created;
				PA_SetTextTileCol(0,0);
				PA_OutputText(0,0,1,"                                ");
				PA_OutputText(0,0,1,"npcs created %d",last_npcs_created);
			}
			if(last_npcs_setdeleted!=npcs_setdeleted||update_debug_counters==1)
			{
				if(last_npcs_setdeleted!=npcs_setdeleted)last_npcs_setdeleted=npcs_setdeleted;
				PA_SetTextTileCol(0,0);
				PA_OutputText(0,0,2,"                                ");
				PA_OutputText(0,0,2,"npcs setdeleted %d",last_npcs_setdeleted);
			}
			if(last_npcs_vbldeleted!=npcs_vbldeleted||update_debug_counters==1)
			{
				if(last_npcs_vbldeleted!=npcs_vbldeleted)last_npcs_vbldeleted=npcs_vbldeleted;
				PA_SetTextTileCol(0,0);
				PA_OutputText(0,0,3,"                                ");
				PA_OutputText(0,0,3,"npcs vbldeleted %d",last_npcs_vbldeleted);
			}
			if(last_npcs_existing!=npcs_existing||update_debug_counters==1)
			{
				if(last_npcs_existing!=npcs_existing)last_npcs_existing=npcs_existing;
				PA_SetTextTileCol(0,0);
				PA_OutputText(0,0,4,"                                ");
				PA_OutputText(0,0,4,"npcs existing %d",last_npcs_existing);
			}
			if(npcs_existing>npcs_maxexisting||update_debug_counters==1)
			{
				if(npcs_existing>npcs_maxexisting)npcs_maxexisting=npcs_existing;
				PA_SetTextTileCol(0,0);
				PA_OutputText(0,0,5,"                                ");
				PA_OutputText(0,0,5,"npcs max exist %d",npcs_maxexisting);
			}
			if(last_caps_created!=caps_created||update_debug_counters==1)
			{
				if(last_caps_created!=caps_created)last_caps_created=caps_created;
				PA_SetTextTileCol(0,0);
				PA_OutputText(0,0,7,"                                ");
				PA_OutputText(0,0,7,"caps created %d",last_caps_created);
			}
			if(last_caps_setdeleted!=caps_setdeleted||update_debug_counters==1)
			{
				if(last_caps_setdeleted!=caps_setdeleted)last_caps_setdeleted=caps_setdeleted;
				PA_SetTextTileCol(0,0);
				PA_OutputText(0,0,8,"                                ");
				PA_OutputText(0,0,8,"caps setdeleted %d",last_caps_setdeleted);
			}
			if(last_caps_vbldeleted!=caps_vbldeleted||update_debug_counters==1)
			{
				if(last_caps_vbldeleted!=caps_vbldeleted)last_caps_vbldeleted=caps_vbldeleted;
				PA_SetTextTileCol(0,0);
				PA_OutputText(0,0,9,"                                ");
				PA_OutputText(0,0,9,"caps vbldeleted %d",last_caps_vbldeleted);
			}
			if(last_caps_existing!=caps_existing||update_debug_counters==1)
			{
				if(last_caps_existing!=caps_existing)last_caps_existing=caps_existing;
				PA_SetTextTileCol(0,0);
				PA_OutputText(0,0,10,"                                ");
				PA_OutputText(0,0,10,"caps existing %d",last_caps_existing);
			}
			if(caps_existing>caps_maxexisting||update_debug_counters==1)
			{
				if(caps_existing>caps_maxexisting)caps_maxexisting=caps_existing;
				PA_SetTextTileCol(0,0);
				PA_OutputText(0,0,11,"                                ");
				PA_OutputText(0,0,11,"caps max exist %d",caps_maxexisting);
				update_debug_counters=0;
			}
		}
*/
//===========END DEBUG==============================================================================================================


}



//=========================================================================================================================
void DEBUG_vbl()
{//=========================================================================================================================



}


