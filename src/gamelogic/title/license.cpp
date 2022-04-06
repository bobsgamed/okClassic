



#include "../../main.h"
//#include "license.h"


//=========================================================================================================================
void load_license_screen()
{//=========================================================================================================================
			{
			intro_top_palette =         (short unsigned int*)HARDWARE_load_file("/intro/license/license_screen_top_Pal.bin");
			intro_top_tileset =         (unsigned char*)HARDWARE_load_file("/intro/license/license_screen_top_Tiles.bin");
			intro_top_map     =         (short unsigned int*)HARDWARE_load_file("/intro/license/license_screen_top_Map.bin");
			intro_top_tileset_size =     HARDWARE_get_file_size("/intro/license/license_screen_top_Tiles.bin");

			intro_bottom_palette =         (short unsigned int*)HARDWARE_load_file("/intro/license/license_screen_bottom_Pal.bin");
			intro_bottom_tileset =         (unsigned char*)HARDWARE_load_file("/intro/license/license_screen_bottom_Tiles.bin");
			intro_bottom_map     =         (short unsigned int*)HARDWARE_load_file("/intro/license/license_screen_bottom_Map.bin");
			intro_bottom_tileset_size =     HARDWARE_get_file_size("/intro/license/license_screen_bottom_Tiles.bin");
			}

			//HARDWARE_load_bg_palette(1,0,warning_screen_top_palette);
			//HARDWARE_load_bg_palette(0,0,intro_bottom_palette);





			//sdl hack

				//HARDWARE_load_bg_tiles(1,3,intro_top_tileset,intro_top_tileset_size/2);
				//HARDWARE_load_bg_tiles(0,3,intro_bottom_tileset,intro_bottom_tileset_size/2);

				//HARDWARE_load_map(1,3,intro_top_map,BG_256X256,256,192);
				//HARDWARE_load_map(0,3,intro_bottom_map,BG_256X256,256,192);


				//HARDWARE_init_bg(1,3,BG_256X256,0,1);
				//HARDWARE_init_bg(0,3,BG_256X256,0,1);

				//HARDWARE_scroll_bg_xy(1,3,0,0);
				//HARDWARE_scroll_bg_xy(0,3,0,0);


				float aspectratio = 1.0f;//((float)((float)(GAME_VIEWPORT_HEIGHT_PIXELS)/2.0f)/192.0f);
				int fromx = ((GAME_VIEWPORT_WIDTH_PIXELS-(aspectratio*256.0f))/2);
				int fromy = 0;


				HARDWARE_load_AUX_map_to_xy_xy(1,intro_top_map,intro_top_tileset,clear_palette,256,192,fromx,fromy,aspectratio,0);
				HARDWARE_load_AUX_map_to_xy_xy(0,intro_bottom_map,intro_bottom_tileset,clear_palette,256,192,fromx,fromy+(GAME_VIEWPORT_HEIGHT_PIXELS/2),aspectratio,0);


			//end sdl hack


			int p=-31;
			while(p<=0&&MAIN_QUIT==false)
			{
				if(TITLESCREEN_vbl_counter%3==0)
				{
					//HARDWARE_create_brightened_palette((void*)intro_top_palette,(void*)intro_palette_1,p);
					HARDWARE_create_brightened_palette((int*)intro_bottom_palette,(int*)&intro_palette_0,p);

					//HARDWARE_load_bg_palette(1,3,intro_palette_1);


					//HARDWARE_load_bg_palette(0,3,(int*)&intro_palette_0);//sdl hack
					HARDWARE_load_AUX_map_to_xy_xy(0,intro_bottom_map,intro_bottom_tileset,(unsigned short*)&intro_palette_0,256,192,fromx,fromy+(GAME_VIEWPORT_HEIGHT_PIXELS/2),aspectratio,0);


					p++;
				}

				whilefix();
			}


			p=-31;
			while(p<=0&&MAIN_QUIT==false)
			{
				if(TITLESCREEN_vbl_counter%3==0)
				{
					HARDWARE_create_brightened_palette((int*)intro_top_palette,(int*)&intro_palette_1,p);
					//HARDWARE_create_brightened_palette((void*)intro_bottom_palette,(void*)intro_palette_0,p);

					//HARDWARE_load_bg_palette(1,3,(int*)&intro_palette_1);//sdl hack
					HARDWARE_load_AUX_map_to_xy_xy(1,intro_top_map,intro_top_tileset,(unsigned short*)&intro_palette_1,256,192,fromx,fromy,aspectratio,0);
					//HARDWARE_load_bg_palette(0,3,intro_palette_0);

					p++;
				}

				whilefix();
			}




}

//=========================================================================================================================
void unload_license_screen()
{//=========================================================================================================================

			int p=0;
			while(p>=-31&&MAIN_QUIT==false)
			{
				if(TITLESCREEN_vbl_counter%3==0)
				{
					HARDWARE_create_brightened_palette((int*)intro_top_palette,(int*)&intro_palette_1,p);
					HARDWARE_create_brightened_palette((int*)intro_bottom_palette,(int*)&intro_palette_0,p);

					//HARDWARE_load_bg_palette(1,3,(int*)&intro_palette_1);
					//HARDWARE_load_bg_palette(0,3,(int*)&intro_palette_0);

					float aspectratio = 1.0f;//((float)((float)(GAME_VIEWPORT_HEIGHT_PIXELS)/2.0f)/192.0f);
					int fromx = ((GAME_VIEWPORT_WIDTH_PIXELS-(aspectratio*256.0f))/2);
					int fromy = 0;

					HARDWARE_load_AUX_map_to_xy_xy(1,intro_top_map,intro_top_tileset,(unsigned short*)&intro_palette_1,256,192,fromx,fromy,aspectratio,0);
					HARDWARE_load_AUX_map_to_xy_xy(0,intro_bottom_map,intro_bottom_tileset,(unsigned short*)&intro_palette_0,256,192,fromx,fromy+(GAME_VIEWPORT_HEIGHT_PIXELS/2),aspectratio,0);

					p--;
				}

				whilefix();
			}

			HARDWARE_delete_AUX_bg(1);
			HARDWARE_delete_AUX_bg(0);


			HARDWARE_unload_file((void**)&intro_top_palette);
			HARDWARE_unload_file((void**)&intro_bottom_palette);
			HARDWARE_unload_file((void**)&intro_top_tileset);
			HARDWARE_unload_file((void**)&intro_bottom_tileset);
			HARDWARE_unload_file((void**)&intro_top_map);
			HARDWARE_unload_file((void**)&intro_bottom_map);
}

