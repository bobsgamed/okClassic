//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================



#include "../../main.h"
//#include "titlescreen.h"


unsigned short intro_palette_1[256]= {0};
unsigned short intro_palette_0[256]= {0};

int TITLESCREEN_vbl_counter = 0;
int intro_vbl_counter2 = 0;

int TITLESCREEN_running = 0;

unsigned short* intro_top_palette =  NULL;
unsigned char* intro_top_tileset =  NULL;
unsigned short* intro_top_map     =  NULL;
int intro_top_tileset_size = 0;

unsigned short* intro_bottom_palette =  NULL;
unsigned char* intro_bottom_tileset =  NULL;
unsigned short* intro_bottom_map     =  NULL;
int intro_bottom_tileset_size = 0;

unsigned short* blackscreen_palette =  NULL;
unsigned char* blackscreen_tileset =  NULL;
unsigned short* blackscreen_map     =  NULL;

CAPTION* taglinecaption = NULL;




//=========================================================================================================================
void TITLESCREEN_vbl()
{//=========================================================================================================================
	CAPTION_vbl();

}


//=========================================================================================================================
void load_title_screen()
{//=========================================================================================================================


			//intro_bottom_palette =         HARDWARE_load_file("/intro/title/title_screen_bottom_Pal.bin");
			//intro_bottom_tileset =         HARDWARE_load_file("/intro/title/title_screen_bottom_Tiles.bin");
			//intro_bottom_map     =         HARDWARE_load_file("/intro/title/title_screen_bottom_Map.bin");

			intro_top_tileset =         (unsigned char*)HARDWARE_load_file("/intro/title/title_screen_top_Tiles.bin");
			intro_top_map     =         (short unsigned int*)HARDWARE_load_file("/intro/title/title_screen_top_Map.bin");
			intro_top_palette =         (short unsigned int*)HARDWARE_load_file("/intro/title/title_screen_top_Pal.bin");



				float aspectratio = 1;//((float)((float)(GAME_VIEWPORT_HEIGHT_PIXELS)/2.0f)/192.0f);
				int fromx = ((GAME_VIEWPORT_WIDTH_PIXELS-(aspectratio*256.0f))/2);
				int fromy = 22;

				intro_top_palette[(int)intro_top_tileset[(8*8)*intro_top_map[5+(31*32)]]]=HARDWARE_RGB(0,0,0);

				HARDWARE_load_AUX_map_to_xy_xy(1,intro_top_map,intro_top_tileset,intro_top_palette,256,192,fromx,fromy,aspectratio,0);



				//HARDWARE_load_AUX_map_to_xy_xy(1,intro_top_map,intro_top_tileset,clear_palette,256,192,fromx,fromy,aspectratio,0);
				//HARDWARE_load_AUX_map_to_xy_xy(0,intro_bottom_map,intro_bottom_tileset,clear_palette,256,192,fromx,fromy+(GAME_VIEWPORT_HEIGHT_PIXELS/2),aspectratio,0);


			static int end_start_screen=0;

			//int p=-31;
			int a=255;
			while(a>0&&MAIN_QUIT==false)//p<=0&&MAIN_QUIT==false)
			{

#ifdef ND
				if(TITLESCREEN_vbl_counter%8==0)
				{


					a-=2;
					if(a<0)a=0;
#else
				if(TITLESCREEN_vbl_counter%2==0)
				{

					a-=1;
					if(a<0)a=0;
#endif



					//make black texture fullscreen
					//draw texture in render
					//gradually

					fade_alpha=a;
					fade_layer=6;

					/*HARDWARE_create_brightened_palette((void*)intro_top_palette,(void*)intro_palette_1,p);
					//HARDWARE_create_brightened_palette((void*)intro_bottom_palette,(void*)intro_palette_0,p);

					int x=0;
					for(x=0;x<4;x++)
					intro_palette_1[intro_top_tileset[(8*8)*intro_top_map[x+(31*32)]]]=intro_palette_1[intro_top_tileset[(8*8)*intro_top_map[4+(31*32)]]];


					//intro_palette_0[2]=intro_palette_1[intro_top_tileset[(8*8)*intro_top_map[5+(31*32)]]];

					whilefix();

					float aspectratio = 1;//((float)((float)(GAME_VIEWPORT_HEIGHT_PIXELS)/2.0f)/192.0f);
					int fromx = ((GAME_VIEWPORT_WIDTH_PIXELS-(aspectratio*256.0f))/2);
					int fromy = 32;

					HARDWARE_load_AUX_map_to_xy_xy(1,intro_top_map,intro_top_tileset,intro_palette_1,256,192,fromx,fromy,aspectratio,0);
					//HARDWARE_load_AUX_map_to_xy_xy(0,intro_bottom_map,intro_bottom_tileset,intro_palette_0,256,192,fromx,fromy+(GAME_VIEWPORT_HEIGHT_PIXELS/2),aspectratio,0);


					p++;*/

					if(a<32)
					{
						a=0;
						fade_alpha=a;
						TITLESCREEN_vbl_counter=119;
						if(taglinecaption==NULL)CAPTION_make_caption(&taglinecaption, 1, CAPTION_CENTERED_X, GAME_VIEWPORT_HEIGHT_PIXELS/2+27, -1, "a game by one person", FONT_NORMAL_ID, WHITE, CLEAR,6,1);
					}


				}

				/*static int s=0;

				static int g[5]={31,31,31,31,31};


				if(TITLESCREEN_vbl_counter%120==0&&a<138){s=1;}

				if(s!=0&&TITLESCREEN_vbl_counter%3==0)
				{



					//set all to 31
					int x=0;
					for(x=0;x<5;x++)g[x]=0;

					//set one to 16
					if(s<6)g[s-1]=31;
					s++;
					if(s>6)
					{
						s=0;
					}

					intro_palette_1[(int)intro_top_tileset[(8*8)*intro_top_map[0+(31*32)]]]=HARDWARE_RGB(g[0],31,g[0]);
					intro_palette_1[(int)intro_top_tileset[(8*8)*intro_top_map[1+(31*32)]]]=HARDWARE_RGB(g[1],31,g[1]);
					intro_palette_1[(int)intro_top_tileset[(8*8)*intro_top_map[2+(31*32)]]]=HARDWARE_RGB(g[2],31,g[2]);
					intro_palette_1[(int)intro_top_tileset[(8*8)*intro_top_map[3+(31*32)]]]=HARDWARE_RGB(g[3],31,g[3]);
					intro_palette_1[(int)intro_top_tileset[(8*8)*intro_top_map[4+(31*32)]]]=HARDWARE_RGB(g[4],31,g[4]);
					HARDWARE_load_AUX_map_to_xy_xy(1,intro_top_map,intro_top_tileset,intro_palette_1,256,192,fromx,fromy,aspectratio,0);
				}*/

				whilefix();
			}





			/*intro_palette_1[(int)intro_top_tileset[(8*8)*intro_top_map[0+(31*32)]]]=HARDWARE_RGB(0,31,0);
			intro_palette_1[(int)intro_top_tileset[(8*8)*intro_top_map[1+(31*32)]]]=HARDWARE_RGB(0,31,0);
			intro_palette_1[(int)intro_top_tileset[(8*8)*intro_top_map[2+(31*32)]]]=HARDWARE_RGB(0,31,0);
			intro_palette_1[(int)intro_top_tileset[(8*8)*intro_top_map[3+(31*32)]]]=HARDWARE_RGB(0,31,0);
			intro_palette_1[(int)intro_top_tileset[(8*8)*intro_top_map[4+(31*32)]]]=HARDWARE_RGB(0,31,0);
			HARDWARE_load_AUX_map_to_xy_xy(1,intro_top_map,intro_top_tileset,intro_palette_1,256,192,fromx,fromy,aspectratio,0);*/





			while(end_start_screen==0&&MAIN_QUIT==false)
			{



				//fade "demo 1 + 2"
				/*if(TITLESCREEN_vbl_counter%4==0)
				{
					static int c=0;
					static int fade=0;
					if(fade==0)
					{
						c++;
						if(c>31)
						{
							c=31;
							fade=1;
						}
					}
					else
					{
						c--;
						if(c<0)
						{
							c=0;
							fade=0;
						}
					}

					intro_palette_1[(int)intro_top_tileset[(8*8)*intro_top_map[5+(31*32)]]]=HARDWARE_RGB(c,c,c);
					//intro_palette_0[2]=HARDWARE_RGB(c,c,c);

					float aspectratio = 1;//((float)((float)(GAME_VIEWPORT_HEIGHT_PIXELS)/2.0f)/192.0f);
					int fromx = ((GAME_VIEWPORT_WIDTH_PIXELS-(aspectratio*256.0f))/2);
					int fromy = 0;

					HARDWARE_load_AUX_map_to_xy_xy(1,intro_top_map,intro_top_tileset,intro_palette_1,256,192,fromx,fromy,aspectratio,0);
					//HARDWARE_load_AUX_map_to_xy_xy(0,intro_bottom_map,intro_bottom_tileset,intro_palette_0,256,192,fromx,fromy+(GAME_VIEWPORT_HEIGHT_PIXELS/2),aspectratio,0);
				}*/



				static int s=0;

				static int g[5]={31,31,31,31,31};

#ifdef ND
				if(TITLESCREEN_vbl_counter%60==0){s=1;TITLESCREEN_vbl_counter=0;}
				if(s!=0&&TITLESCREEN_vbl_counter%1==0)
#else
				if(TITLESCREEN_vbl_counter%120==0){s=1;TITLESCREEN_vbl_counter=0;}
				if(s!=0&&TITLESCREEN_vbl_counter%3==0)
#endif

				{
					//set all to 31
					int x=0;
					for(x=0;x<5;x++)g[x]=0;

					//set one to 16
					if(s<6)g[s-1]=31;
					s++;
					if(s>6)
					{
						s=0;
					}

					intro_top_palette[(int)intro_top_tileset[(8*8)*intro_top_map[0+(31*32)]]]=HARDWARE_RGB(g[0],31,g[0]);
					intro_top_palette[(int)intro_top_tileset[(8*8)*intro_top_map[1+(31*32)]]]=HARDWARE_RGB(g[1],31,g[1]);
					intro_top_palette[(int)intro_top_tileset[(8*8)*intro_top_map[2+(31*32)]]]=HARDWARE_RGB(g[2],31,g[2]);
					intro_top_palette[(int)intro_top_tileset[(8*8)*intro_top_map[3+(31*32)]]]=HARDWARE_RGB(g[3],31,g[3]);
					intro_top_palette[(int)intro_top_tileset[(8*8)*intro_top_map[4+(31*32)]]]=HARDWARE_RGB(g[4],31,g[4]);
					HARDWARE_load_AUX_map_to_xy_xy(1,intro_top_map,intro_top_tileset,intro_top_palette,256,192,fromx,fromy,aspectratio,0);
				}

				whilefix();


				static int start_stage=0;

				static CAPTION* introcaption=NULL;
				static CAPTION* easymodecaption=NULL;


				if(start_stage==0)
				{


					//if(easymode)if(easymodecaption==NULL)CAPTION_make_caption(&easymodecaption, 1, CAPTION_CENTERED_X,200, -1, "easy mode", FONT_NORMAL_ID, BLUE, CLEAR,5,1);

					//if(introcaption==NULL)CAPTION_make_caption(&introcaption, 1, CAPTION_CENTERED_X, GAME_VIEWPORT_HEIGHT_PIXELS-10, -1, "press the action button", FONT_NORMAL_ID, WHITE, CLEAR,6,1);

					if(BUTTON_A_PRESSED)
					{
						HARDWARE_play_sound("blip",127,44100,0);
						if(introcaption!=NULL)CAPTION_delete_caption(introcaption);
						if(taglinecaption!=NULL)taglinecaption->time_left=3;
						start_stage=2;


						int x=0;
						for(x=0;x<5;x++)g[x]=0;

						intro_top_palette[(int)intro_top_tileset[(8*8)*intro_top_map[0+(31*32)]]]=HARDWARE_RGB(g[0],31,g[0]);
						intro_top_palette[(int)intro_top_tileset[(8*8)*intro_top_map[1+(31*32)]]]=HARDWARE_RGB(g[1],31,g[1]);
						intro_top_palette[(int)intro_top_tileset[(8*8)*intro_top_map[2+(31*32)]]]=HARDWARE_RGB(g[2],31,g[2]);
						intro_top_palette[(int)intro_top_tileset[(8*8)*intro_top_map[3+(31*32)]]]=HARDWARE_RGB(g[3],31,g[3]);
						intro_top_palette[(int)intro_top_tileset[(8*8)*intro_top_map[4+(31*32)]]]=HARDWARE_RGB(g[4],31,g[4]);
						HARDWARE_load_AUX_map_to_xy_xy(1,intro_top_map,intro_top_tileset,intro_top_palette,256,192,fromx,fromy,aspectratio,0);


					}
				}


				if(start_stage==1)
				{
					if(introcaption==NULL)CAPTION_make_caption(&introcaption, 1, CAPTION_CENTERED_X, (GAME_VIEWPORT_HEIGHT_PIXELS/2)+(GAME_VIEWPORT_HEIGHT_PIXELS/3), -1, "now press the shift key", FONT_NORMAL_ID, WHITE, CLEAR,5,1);

					if(BUTTON_B_PRESSED)
					{
						HARDWARE_play_sound("blip",127,44100,0);
						if(introcaption!=NULL)CAPTION_delete_caption(introcaption);
						start_stage=2;
						intro_vbl_counter2=0;
					}
				}


				if(start_stage==2)
				{
					//if(introcaption==NULL)CAPTION_make_caption(&introcaption, 1, CAPTION_CENTERED_X, (GAME_VIEWPORT_HEIGHT_PIXELS/2)+(GAME_VIEWPORT_HEIGHT_PIXELS/3), -1, "thank Yuu for playing", FONT_NORMAL_ID, WHITE, CLEAR,5,1);

					if(intro_vbl_counter2>200)
					{
						//HARDWARE_play_preloaded_sound((void*)blip, (int*)blip_size,127,44100,0);
						if(introcaption!=NULL)CAPTION_delete_caption(introcaption);
						if(easymodecaption!=NULL)CAPTION_delete_caption(easymodecaption);
						start_stage=3;
						intro_vbl_counter2=0;
						end_start_screen=1;
					}
				}

				/*if(start_stage==3)
				{
					if(introcaption==NULL)CAPTION_make_caption(&introcaption, 1, CAPTION_CENTERED_X, (GAME_VIEWPORT_HEIGHT_PIXELS/2)+(GAME_VIEWPORT_HEIGHT_PIXELS/4), -1, "just kidding ;}", FONT_NORMAL_ID, WHITE, CLEAR,4,1);

					if(intro_vbl_counter2>300)
					{
						//HARDWARE_play_preloaded_sound((void*)blip, (int*)blip_size,127,44100,0);
						if(introcaption!=NULL)CAPTION_delete_caption(introcaption);
						end_start_screen=1;
					}
				}*/




				CAPTION_main();



			}

}




//=========================================================================================================================
void unload_title_screen()
{//=========================================================================================================================

		//int p=0;
		int a=0;
		while(a<255&&MAIN_QUIT==false)//p>=-31&&MAIN_QUIT==false)
		{

#ifdef ND
			if(TITLESCREEN_vbl_counter%3==0)
#else
			if(TITLESCREEN_vbl_counter%6==0)
#endif
			{
				/*HARDWARE_create_brightened_palette((void*)intro_top_palette,(void*)intro_palette_1,p);
				HARDWARE_create_brightened_palette((void*)intro_bottom_palette,(void*)intro_palette_0,p);

					int x=0;
					for(x=0;x<4;x++)
					intro_palette_1[intro_top_tileset[(8*8)*intro_top_map[x+(31*32)]]]=intro_palette_1[intro_top_tileset[(8*8)*intro_top_map[4+(31*32)]]];




				whilefix();

				//HARDWARE_load_bg_palette(1,3,(int*)&intro_palette_1);
				//HARDWARE_load_bg_palette(0,3,(int*)&intro_palette_0);
					float aspectratio = ((float)((float)(GAME_VIEWPORT_HEIGHT_PIXELS)/2.0f)/192.0f);
					int fromx = ((GAME_VIEWPORT_WIDTH_PIXELS-(aspectratio*256.0f))/2);
					int fromy = 0;

					HARDWARE_load_AUX_map_to_xy_xy(1,intro_top_map,intro_top_tileset,intro_palette_1,256,192,fromx,fromy,aspectratio,0);
					HARDWARE_load_AUX_map_to_xy_xy(0,intro_bottom_map,intro_bottom_tileset,intro_palette_0,256,192,fromx,fromy+(GAME_VIEWPORT_HEIGHT_PIXELS/2),aspectratio,0);

				p--;*/

				fade_alpha=a;


				a+=10;
				if(a>255)a=255;

			}

			whilefix();
		}

		HARDWARE_delete_AUX_bg(1);
		//HARDWARE_delete_AUX_bg(0);


		HARDWARE_unload_file((void**)&intro_top_palette);
		//HARDWARE_unload_file((void*)&intro_bottom_palette);
		HARDWARE_unload_file((void**)&intro_top_tileset);
		//HARDWARE_unload_file((void*)&intro_bottom_tileset);
		HARDWARE_unload_file((void**)&intro_top_map);
		//HARDWARE_unload_file((void*)&intro_bottom_map);

}



//========================================================
//title screen
//========================================================
void title_screen()
{

/*
	//========================================================
	//warning screen
	//========================================================
	load_warning_screen();
	while(!BUTTON_A_PRESSED&&MAIN_QUIT==false){whilefix();}
	HARDWARE_play_sound("blip",127,44100,0);
	unload_warning_screen();
*/

	HARDWARE_play_music("k",64);


/*
	//========================================================
	//license screen
	//========================================================
	TITLESCREEN_vbl_counter=0;
	load_license_screen();
	TITLESCREEN_vbl_counter=0;
	while(TITLESCREEN_vbl_counter<240){whilefix();}
	//while(!BUTTON_A_PRESSED){whilefix();}
	//HARDWARE_play_preloaded_sound((void*)blip, (int*)blip_size,127,44100,0);
	unload_license_screen();*/

	//========================================================
	//start screen
	//========================================================
	//HARDWARE_load_sprite_palette((int*)GAME_original_SPRITE_PALETTE);///FIX THIS
	//HARDWARE_load_sprite_palette(0,(int*)GAME_original_SPRITE_PALETTE);

	TITLESCREEN_vbl_counter=0;
	load_title_screen();

	//press a
	//now press b
	//now press c
	//just kidding

	unload_title_screen();




	//intro hospital

	//intro moving in




	static CAPTION* fiveyearsagocaption=NULL;
	if(fiveyearsagocaption==NULL)CAPTION_make_caption(&fiveyearsagocaption, 1, CAPTION_CENTERED_SCREEN, 192/2, 5, "one year from now...", FONT_NORMAL_ID, WHITE, CLEAR,7,1);
	while(fiveyearsagocaption!=NULL&&MAIN_QUIT==false)
	{
		whilefix();
		CAPTION_main();

		static int volume=64;
		if(TITLESCREEN_vbl_counter%5==0)
		{
			volume-=2;
			if(volume<0)volume=0;
			HARDWARE_set_music_volume(volume);
		}

	}





}






//=========================================================================================================================
void load_black_screen()
{//=========================================================================================================================





blackscreen_palette =         (short unsigned int*)HARDWARE_load_file("/intro/blackscreen/blackscreen_Pal.bin");
blackscreen_tileset =         (unsigned char*)HARDWARE_load_file("/intro/blackscreen/blackscreen_Tiles.bin");
blackscreen_map     =         (short unsigned int*)HARDWARE_load_file("/intro/blackscreen/blackscreen_Map.bin");


	float aspectratio = ((float)((float)(GAME_VIEWPORT_WIDTH_PIXELS)/1.0f)/256.0f);
	int fromx = ((GAME_VIEWPORT_WIDTH_PIXELS-(aspectratio*256.0f)));
	int fromy = 0;


	HARDWARE_load_AUX_map_to_xy_xy(0,blackscreen_map,blackscreen_tileset,blackscreen_palette,256,256,fromx,fromy,aspectratio,0);



}

//=========================================================================================================================
void unload_black_screen()
{//=========================================================================================================================




		HARDWARE_delete_AUX_bg(0);


		HARDWARE_unload_file((void**)&blackscreen_map);
		HARDWARE_unload_file((void**)&blackscreen_palette);
		HARDWARE_unload_file((void**)&blackscreen_tileset);

}




//=========================================================================================================================
void load_bob_scene_2()
{//=========================================================================================================================



			GLOBAL_main_sprite_input_off=1;


			//HARDWARE_fade_palette
			{///fix this

					int from = 0;
					int to = -31;

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

			}

			load_black_screen();


			static CAPTION* transitioncaption=NULL;
			if(transitioncaption==NULL)CAPTION_make_caption(&transitioncaption, 1, CAPTION_CENTERED_SCREEN, 192/2, 5, "three years ago...", FONT_NORMAL_ID, WHITE, CLEAR,5,1);
			while(transitioncaption!=NULL&&MAIN_QUIT==false)
			{
				whilefix();
				CAPTION_main();

				static int volume=64;
				if(TITLESCREEN_vbl_counter%5==0)
				{
					volume-=2;
					if(volume<0)volume=0;
					HARDWARE_set_music_volume(volume);
				}

			}
			HARDWARE_stop_music();



			MAP_change_map(MAP_bobsgame_CITYBobsAptInside,32,9);

			MAP_set_map_cam_to_cameraman();

			ZOOMlock=0;
			ZOOMto=2.0f;

			GLOBAL_main_sprite_input_off=0;
			GLOBAL_main_sprite_standing=1;


			unload_black_screen();


}




//=========================================================================================================================
void load_bob_scene_3()
{//=========================================================================================================================



			GLOBAL_main_sprite_input_off=1;

			//HARDWARE_unload_file((void*)&HARDWARE_map_palette);
			//HARDWARE_map_palette=HARDWARE_load_file(HARDWARE_map_palette_filename);

			//HARDWARE_fade_palette
			{///fix this

					int from = 0;
					int to = -31;

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

			}

			load_black_screen();


			static CAPTION* transitioncaption=NULL;
			if(transitioncaption==NULL)CAPTION_make_caption(&transitioncaption, 1, CAPTION_CENTERED_SCREEN, 192/2, 6, "two years ago...", FONT_NORMAL_ID, WHITE, CLEAR,5,1);
			while(transitioncaption!=NULL&&MAIN_QUIT==false)
			{
				whilefix();
				CAPTION_main();

				static int volume=64;
				if(TITLESCREEN_vbl_counter%5==0)
				{
					volume-=2;
					if(volume<1)volume=1;
					HARDWARE_set_music_volume(volume);
				}

			}
			HARDWARE_stop_music();



			MAP_change_map(MAP_bobsgame_CITYBobsAptInsideTrashed,32,9);

			MAP_set_map_cam_to_cameraman();

			ZOOMlock=0;
			ZOOMto=2.0f;

			GLOBAL_main_sprite_input_off=0;
			GLOBAL_main_sprite_standing=1;


			unload_black_screen();


}
