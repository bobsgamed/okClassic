


#include "../../main.h"
//#include "demoend.h"

//=========================================================================================================================
void load_demo_screen()
{//=========================================================================================================================

	//NPC_pause();


	CLOCK_paused=1;
	//GAME_is_running=0;

	//HARDWARE_delete_sprite(0,shadow->PLAYER_id_touchmap);
	//HARDWARE_delete_sprite(1,shadow->PLAYER_id);



			{

			intro_top_palette =         (short unsigned int*)HARDWARE_load_file("/intro/demo_end/demo_end_top_Pal.bin");
			intro_top_tileset =         (unsigned char*)HARDWARE_load_file("/intro/demo_end/demo_end_top_Tiles.bin");
			intro_top_map     =         (short unsigned int*)HARDWARE_load_file("/intro/demo_end/demo_end_top_Map.bin");
			intro_top_tileset_size =     HARDWARE_get_file_size("/intro/demo_end/demo_end_top_Tiles.bin");

			intro_bottom_palette =         (short unsigned int*)HARDWARE_load_file("/intro/demo_end/demo_end_bottom_Pal.bin");
			intro_bottom_tileset =         (unsigned char*)HARDWARE_load_file("/intro/demo_end/demo_end_bottom_Tiles.bin");
			intro_bottom_map     =         (short unsigned int*)HARDWARE_load_file("/intro/demo_end/demo_end_bottom_Map.bin");
			intro_bottom_tileset_size =     HARDWARE_get_file_size("/intro/demo_end/demo_end_bottom_Tiles.bin");

			}

			//HARDWARE_load_bg_palette(1,0,warning_screen_top_palette);
			//HARDWARE_load_bg_palette(0,0,intro_bottom_palette);


			float aspectratio = ((float)((float)(GAME_VIEWPORT_HEIGHT_PIXELS)/1.0f)/192.0f);
			int fromx = ((GAME_VIEWPORT_WIDTH_PIXELS-(aspectratio*256.0f))/2);
			int fromy = 0;

			//HARDWARE_load_AUX_map_to_xy_xy(1,intro_top_map,intro_top_tileset,intro_top_palette,256,192,fromx,fromy,aspectratio);
			HARDWARE_load_AUX_map_to_xy_xy(0,intro_bottom_map,intro_bottom_tileset,(unsigned short*)&clear_palette,256,192,fromx,fromy,aspectratio,0);



			//HARDWARE_load_bg_tiles(1,3,intro_top_tileset,intro_top_tileset_size/2);
			//HARDWARE_load_bg_tiles(0,3,intro_bottom_tileset,intro_bottom_tileset_size/2);

			//HARDWARE_load_map(1,3,intro_top_map,BG_256X256,256,192);
			//HARDWARE_load_map(0,3,intro_bottom_map,BG_256X256,256,192);

			//HARDWARE_init_bg(1,3,BG_256X256,0,1);
			//HARDWARE_init_bg(0,3,BG_256X256,0,1);

			//HARDWARE_scroll_bg_xy(1,3,0,0);
			//HARDWARE_scroll_bg_xy(0,3,0,0);


					int p=-31;
					while(p<=0&&MAIN_QUIT==false)
					{
						if(TITLESCREEN_vbl_counter%5==0)
						{
							HARDWARE_create_brightened_palette((int*)intro_top_palette,(int*)&intro_palette_1,p);
							HARDWARE_create_brightened_palette((int*)intro_bottom_palette,(int*)&intro_palette_0,p);

							int x=0;
							for(x=0;x<4;x++)
							intro_palette_0[intro_bottom_tileset[(8*8)*intro_bottom_map[x+(31*32)]]]=intro_palette_0[intro_bottom_tileset[(8*8)*intro_bottom_map[4+(31*32)]]];


							//intro_palette_0[2]=intro_palette_1[intro_top_tileset[(8*8)*intro_top_map[5+(31*32)]]];


							float aspectratio = ((float)((float)(GAME_VIEWPORT_HEIGHT_PIXELS)/1.0f)/192.0f);
							int fromx = ((GAME_VIEWPORT_WIDTH_PIXELS-(aspectratio*256.0f))/2);
							int fromy = 0;

							//HARDWARE_load_AUX_map_to_xy_xy(1,intro_top_map,intro_top_tileset,intro_palette_1,256,192,fromx,fromy,aspectratio);
							HARDWARE_load_AUX_map_to_xy_xy(0,intro_bottom_map,intro_bottom_tileset,(unsigned short*)&intro_palette_0,256,192,fromx,fromy,aspectratio,0);


							whilefix();

							//HARDWARE_load_bg_palette(1,3,(int*)&intro_palette_1);
							//HARDWARE_load_bg_palette(0,3,(int*)&intro_palette_0);

							p++;
						}

						whilefix();
					}


			static CAPTION* cheatcaption = NULL;

			if(easymode==1)if(cheatcaption==NULL)CAPTION_make_caption(&cheatcaption, 1, CAPTION_CENTERED_X,200, -1, "Thanks for playing! Try it on normal!", FONT_NORMAL_ID, GREEN, CLEAR,5,1);
			if(easymode==0&&cheater==1)if(cheatcaption==NULL)CAPTION_make_caption(&cheatcaption, 1, CAPTION_CENTERED_X,200, -1, "Nice job! Well...", FONT_NORMAL_ID, GREEN, CLEAR,5,1);
			if(easymode==0&&cheater==0)if(cheatcaption==NULL)CAPTION_make_caption(&cheatcaption, 1, CAPTION_CENTERED_X,200, -1, "Whoa. Seriously, I'm impressed.", FONT_NORMAL_ID, GREEN, CLEAR,5,1);



			while(1&&MAIN_QUIT==false)
			{

					if(TITLESCREEN_vbl_counter%4==0)
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

						//HARDWARE_set_bg_palette_color(0,3,(int)intro_bottom_tileset[(8*8)*intro_bottom_map[5+(31*32)]],HARDWARE_RGB(c,c,c));
						//HARDWARE_set_bg_palette_color(1,3,2,HARDWARE_RGB(c,c,c));
						intro_palette_0[(int)intro_bottom_tileset[(8*8)*intro_bottom_map[5+(31*32)]]] = HARDWARE_RGB(c,c,c);

						float aspectratio = ((float)((float)(GAME_VIEWPORT_HEIGHT_PIXELS)/1.0f)/192.0f);
						int fromx = ((GAME_VIEWPORT_WIDTH_PIXELS-(aspectratio*256.0f))/2);
						int fromy = 0;

						//HARDWARE_load_AUX_map_to_xy_xy(1,intro_top_map,intro_top_tileset,intro_palette_1,256,192,fromx,fromy,aspectratio);
						HARDWARE_load_AUX_map_to_xy_xy(0,intro_bottom_map,intro_bottom_tileset,(unsigned short*)&intro_palette_0,256,192,fromx,fromy,aspectratio,0);

					}


					static int s=0;

					static int g[5]={31,31,31,31,31};


					if(TITLESCREEN_vbl_counter%(60+(rand()%420))==0){s=1;TITLESCREEN_vbl_counter=0;}

					if(s!=0&&TITLESCREEN_vbl_counter%2==0)
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

						//HARDWARE_set_bg_palette_color(0,3,(int)intro_bottom_tileset[(8*8)*intro_bottom_map[0+(31*32)]],HARDWARE_RGB(g[0],31,g[0]));
						//HARDWARE_set_bg_palette_color(0,3,(int)intro_bottom_tileset[(8*8)*intro_bottom_map[1+(31*32)]],HARDWARE_RGB(g[1],31,g[1]));
						//HARDWARE_set_bg_palette_color(0,3,(int)intro_bottom_tileset[(8*8)*intro_bottom_map[2+(31*32)]],HARDWARE_RGB(g[2],31,g[2]));
						//HARDWARE_set_bg_palette_color(0,3,(int)intro_bottom_tileset[(8*8)*intro_bottom_map[3+(31*32)]],HARDWARE_RGB(g[3],31,g[3]));
						//HARDWARE_set_bg_palette_color(0,3,(int)intro_bottom_tileset[(8*8)*intro_bottom_map[4+(31*32)]],HARDWARE_RGB(g[4],31,g[4]));

						intro_palette_0[(int)intro_bottom_tileset[(8*8)*intro_bottom_map[0+(31*32)]]] = HARDWARE_RGB(g[0],31,g[0]);
						intro_palette_0[(int)intro_bottom_tileset[(8*8)*intro_bottom_map[1+(31*32)]]] = HARDWARE_RGB(g[1],31,g[1]);
						intro_palette_0[(int)intro_bottom_tileset[(8*8)*intro_bottom_map[2+(31*32)]]] = HARDWARE_RGB(g[2],31,g[2]);
						intro_palette_0[(int)intro_bottom_tileset[(8*8)*intro_bottom_map[3+(31*32)]]] = HARDWARE_RGB(g[3],31,g[3]);
						intro_palette_0[(int)intro_bottom_tileset[(8*8)*intro_bottom_map[4+(31*32)]]] = HARDWARE_RGB(g[4],31,g[4]);

						float aspectratio = ((float)((float)(GAME_VIEWPORT_HEIGHT_PIXELS)/1.0f)/192.0f);
						int fromx = ((GAME_VIEWPORT_WIDTH_PIXELS-(aspectratio*256.0f))/2);
						int fromy = 0;

						//HARDWARE_load_AUX_map_to_xy_xy(1,intro_top_map,intro_top_tileset,intro_palette_1,256,192,fromx,fromy,aspectratio);
						HARDWARE_load_AUX_map_to_xy_xy(0,intro_bottom_map,intro_bottom_tileset,(unsigned short*)&intro_palette_0,256,192,fromx,fromy,aspectratio,0);



					}



					whilefix();

					CAPTION_main();

			}


}

//=========================================================================================================================
void unload_demo_screen()
{//=========================================================================================================================

			int p=0;
			while(p>=-31&&MAIN_QUIT==false)
			{
				if(TITLESCREEN_vbl_counter%3==0)
				{
					HARDWARE_create_brightened_palette((int*)intro_top_palette,(int*)&intro_palette_1,p);
					HARDWARE_create_brightened_palette((int*)intro_bottom_palette,(int*)&intro_palette_0,p);

					whilefix();

					//HARDWARE_load_bg_palette(1,3,(int*)&intro_palette_1);
					//HARDWARE_load_bg_palette(0,3,(int*)&intro_palette_0);


					float aspectratio = ((float)((float)(GAME_VIEWPORT_HEIGHT_PIXELS)/1.0f)/192.0f);
					int fromx = ((GAME_VIEWPORT_WIDTH_PIXELS-(aspectratio*256.0f))/2);
					int fromy = 0;

					//HARDWARE_load_AUX_map_to_xy_xy(1,intro_top_map,intro_top_tileset,intro_palette_1,256,192,fromx,fromy,aspectratio);
					HARDWARE_load_AUX_map_to_xy_xy(0,intro_bottom_map,intro_bottom_tileset,(unsigned short*)&intro_palette_0,256,192,fromx,fromy,aspectratio,0);


					p--;
				}

				whilefix();

			}

			//HARDWARE_delete_bg(0,3);
			//HARDWARE_delete_bg(1,3);
		//HARDWARE_delete_AUX_bg(1);
		HARDWARE_delete_AUX_bg(0);


			HARDWARE_unload_file((void**)&intro_top_palette);
			HARDWARE_unload_file((void**)&intro_bottom_palette);
			HARDWARE_unload_file((void**)&intro_top_tileset);
			HARDWARE_unload_file((void**)&intro_bottom_tileset);
			HARDWARE_unload_file((void**)&intro_top_map);
			HARDWARE_unload_file((void**)&intro_bottom_map);
}










