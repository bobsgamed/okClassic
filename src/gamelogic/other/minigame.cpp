

#include "../../main.h"
//#include "minigame.h"



unsigned short* minigame_palette =  NULL;
unsigned char* minigame_tileset =   NULL;
unsigned short* minigame_map     =   NULL;
int minigame_tileset_size = 0;

unsigned short* tv_palette =  NULL;
unsigned char* 	tv_tileset =   NULL;
unsigned short* tv_map     =   NULL;

unsigned short* scanlines_palette =  NULL;
unsigned char* 	scanlines_tileset =   NULL;
unsigned short* scanlines_map     =   NULL;

float 	TV_aspectratio = 1.0f;//((float)(((float)(GAME_VIEWPORT_HEIGHT_PIXELS)/1.6f))/192.0f);
int 	TV_fromx = 0; //((GAME_VIEWPORT_WIDTH_PIXELS-(TETRID_aspectratio*256.0f))/2);
int 	TV_fromy = 0;//(GAME_VIEWPORT_HEIGHT_PIXELS/3.5f)+7-4;


//=========================================================================================================================
void load_gametoy()
{//=========================================================================================================================




    //HARDWARE_delete_bg(0,0);

    {

       minigame_palette         =         (short unsigned int*)HARDWARE_load_file("/minigame/gametoy/gametoy_v01_Pal.bin");
       minigame_tileset         =         (unsigned char*)HARDWARE_load_file("/minigame/gametoy/gametoy_v01_Tiles.bin");
       minigame_map             =         (short unsigned int*)HARDWARE_load_file("/minigame/gametoy/gametoy_v01_Map.bin");
       minigame_tileset_size    =     HARDWARE_get_file_size("/minigame/gametoy/gametoy_v01_Tiles.bin");

    }


   float aspectratio = ((float)((float)(GAME_VIEWPORT_HEIGHT_PIXELS-((64*2+8))))/192.0f);
   int fromx = ((GAME_VIEWPORT_WIDTH_PIXELS-(aspectratio*256.0f))/2);
   int fromy = ((GAME_VIEWPORT_HEIGHT_PIXELS-(aspectratio*192.0f))/2);

    HARDWARE_load_AUX_map_to_xy_xy(1,minigame_map,minigame_tileset,minigame_palette,256,192,fromx,fromy,aspectratio,0);


    //CAPTION_make_caption(NULL, 0,100,60,2,"Gantendo",FONT_SMALL_ID,DARKGREEN,CLEAR);









}


//=========================================================================================================================
void unload_gametoy()
{//=========================================================================================================================


        HARDWARE_delete_AUX_bg(1);

        HARDWARE_unload_file((void**)&minigame_palette);
        HARDWARE_unload_file((void**)&minigame_tileset);
        HARDWARE_unload_file((void**)&minigame_map);



}

//=========================================================================================================================
void load_gametoy_broken()
{//=========================================================================================================================




        //HARDWARE_delete_bg(0,0);

        {
           minigame_palette         =         (short unsigned int*)HARDWARE_load_file("/minigame/gametoy/gametoy_broken_v01_Pal.bin");
           minigame_tileset         =         (unsigned char*)HARDWARE_load_file("/minigame/gametoy/gametoy_broken_v01_Tiles.bin");
           minigame_map             =         (short unsigned int*)HARDWARE_load_file("/minigame/gametoy/gametoy_broken_v01_Map.bin");
           minigame_tileset_size    =     HARDWARE_get_file_size("/minigame/gametoy/gametoy_broken_v01_Tiles.bin");

        }

        //HARDWARE_load_map(0,0,minigame_map,BG_256X256,256,256);

		float aspectratio = ((float)((float)(GAME_VIEWPORT_HEIGHT_PIXELS-((64*2+8))))/192.0f); //should fit in between the text boxes no matter the zoom
		int fromx = ((GAME_VIEWPORT_WIDTH_PIXELS-(aspectratio*256.0f))/2);
		int fromy = ((GAME_VIEWPORT_HEIGHT_PIXELS-(aspectratio*192.0f))/2);

		HARDWARE_load_AUX_map_to_xy_xy(1,minigame_map,minigame_tileset,minigame_palette,256,192,fromx,fromy,aspectratio,0);




        //CAPTION_make_caption(NULL, 0,100,60,2,"Gantendo",FONT_SMALL_ID,DARKGREEN,CLEAR);


}


//=========================================================================================================================
void unload_gametoy_broken()
{//=========================================================================================================================



        HARDWARE_delete_AUX_bg(1);

        HARDWARE_unload_file((void**)&minigame_palette);
        HARDWARE_unload_file((void**)&minigame_tileset);
        HARDWARE_unload_file((void**)&minigame_map);


}




//=========================================================================================================================
void load_gametoy_fullscreen()
{//=========================================================================================================================


        //bottom_screen_on=0;

        //HARDWARE_delete_bg(0,1);
        //HARDWARE_delete_bg(0,3);
        //HARDWARE_reset_screen_bg_system(0);






//set cameraman_target to bottom half of the screen, so you can see yuu and friend talking above it.

//zoom should be 1.5
ZOOMto=2.0f;
ZOOM=2.0f;

set_zoom();

ZOOMlock=1;

dummy_camera_target->MAP_x=PLAYER_npc->MAP_x;
dummy_camera_target->MAP_y=PLAYER_npc->MAP_y+GAME_VIEWPORT_HEIGHT_PIXELS/2.5f;
GLOBAL_camera_fx_bounds_off=1;
cameraman_target=dummy_camera_target;

TETRID_aspectratio = 1.0f;//((float)(((float)(GAME_VIEWPORT_HEIGHT_PIXELS)/1.6f))/192.0f);
TETRID_fromx = ((GAME_VIEWPORT_WIDTH_PIXELS-(TETRID_aspectratio*256.0f))/2);
TETRID_fromy = (GAME_VIEWPORT_HEIGHT_PIXELS/3.5f)+7-4;



        {
           minigame_palette =         (short unsigned int*)HARDWARE_load_file("/minigame/gametoy/gametoy_fullscreen_v02_Pal.bin");
           minigame_tileset =         (unsigned char*)HARDWARE_load_file("/minigame/gametoy/gametoy_fullscreen_v02_Tiles.bin");
           minigame_map     =         (short unsigned int*)HARDWARE_load_file("/minigame/gametoy/gametoy_fullscreen_v02_Map.bin");
           minigame_tileset_size =     HARDWARE_get_file_size("/minigame/gametoy/gametoy_fullscreen_v02_Tiles.bin");

        }



		HARDWARE_load_AUX_map_to_xy_xy(3,minigame_map,minigame_tileset,minigame_palette,256,192,TETRID_fromx,TETRID_fromy-7,TETRID_aspectratio,0);






        //HARDWARE_load_bg_palette(0,0,minigame_palette);
        //HARDWARE_load_bg_tiles(0,0,minigame_tileset,minigame_tileset_size/2);
        //HARDWARE_load_map(0,0,minigame_map,BG_256X256,256,256);
        //HARDWARE_init_bg(0,0,BG_256X256,0,1);
        //HARDWARE_hide_bg(0,0);
        //HARDWARE_scroll_bg_xy(0,0,0,0);


        //CAPTION_make_caption(NULL, 0,100,60,2,"Gantendo",FONT_SMALL_ID,DARKGREEN,CLEAR);

        //HARDWARE_hide_bg(0,3);
        //HARDWARE_show_bg(0,0);



}


//=========================================================================================================================
void unload_gametoy_fullscreen()
{//=========================================================================================================================


	HARDWARE_delete_AUX_bg(3);

    HARDWARE_unload_file((void**)&minigame_palette);
    HARDWARE_unload_file((void**)&minigame_tileset);
    HARDWARE_unload_file((void**)&minigame_map);

ZOOMlock=0;

}



//=========================================================================================================================
void load_tv_fullscreen()
{//=========================================================================================================================


//set cameraman_target to bottom half of the screen, so you can see yuu and friend talking above it.

//zoom should be 1.5
ZOOMto=2.0f;
ZOOM=2.0f;

set_zoom();

ZOOMlock=1;

dummy_camera_target->MAP_x=PLAYER_npc->MAP_x;
dummy_camera_target->MAP_y=PLAYER_npc->MAP_y+((GAME_VIEWPORT_HEIGHT_PIXELS)/2.5f)+16;
GLOBAL_camera_fx_bounds_off=1;
cameraman_target=dummy_camera_target;



TV_aspectratio = 1.0f;//((float)(((float)(GAME_VIEWPORT_HEIGHT_PIXELS)/1.6f))/192.0f);
TV_fromx = ((GAME_VIEWPORT_WIDTH_PIXELS-(TV_aspectratio*256.0f))/2);
TV_fromy = (GAME_VIEWPORT_HEIGHT_PIXELS/3.5f)-20;


tv_palette =         (short unsigned int*)HARDWARE_load_file("/minigame/tv/tv_fullscreen_v01_Pal.bin");
tv_tileset =         (unsigned char*)HARDWARE_load_file("/minigame/tv/tv_fullscreen_v01_Tiles.bin");
tv_map     =         (short unsigned int*)HARDWARE_load_file("/minigame/tv/tv_fullscreen_v01_Map.bin");
//tv_tileset_size =     HARDWARE_get_file_size("/minigame/tv/tv_fullscreen_v01_Tiles.bin");

scanlines_palette =         (short unsigned int*)HARDWARE_load_file("/minigame/tv/scanlines_v00_Pal.bin");
scanlines_tileset =         (unsigned char*)HARDWARE_load_file("/minigame/tv/scanlines_v00_Tiles.bin");
scanlines_map     =         (short unsigned int*)HARDWARE_load_file("/minigame/tv/scanlines_v00_Map.bin");

scanlines_palette[1]=HARDWARE_RGB(31,31,31);

HARDWARE_load_AUX_map_to_xy_xy(3,tv_map,tv_tileset,tv_palette,256,192,TV_fromx,TV_fromy,TV_aspectratio,0);
HARDWARE_load_AUX_map_to_xy_xy(2,scanlines_map,scanlines_tileset,scanlines_palette,256,192,TV_fromx,TV_fromy,TV_aspectratio,1);

CLOCK_paused=1;

}

//=========================================================================================================================
void load_ping_tv_fullscreen()
{//=========================================================================================================================


//set cameraman_target to bottom half of the screen, so you can see yuu and friend talking above it.

//zoom should be 1.5
ZOOMto=2.0f;
ZOOM=2.0f;

set_zoom();

ZOOMlock=1;

dummy_camera_target->MAP_x=PLAYER_npc->MAP_x;
dummy_camera_target->MAP_y=PLAYER_npc->MAP_y+(GAME_VIEWPORT_HEIGHT_PIXELS/2.5f)+16;
GLOBAL_camera_fx_bounds_off=1;
cameraman_target=dummy_camera_target;



TV_aspectratio = 1.0f;//((float)(((float)(GAME_VIEWPORT_HEIGHT_PIXELS)/1.6f))/192.0f);
TV_fromx = ((GAME_VIEWPORT_WIDTH_PIXELS*2-(TV_aspectratio*256.0f))/2);
TV_fromy = (GAME_VIEWPORT_HEIGHT_PIXELS*2/3.5f)-20;


tv_palette =         (short unsigned int*)HARDWARE_load_file("/minigame/tv/tv_fullscreen_v01_Pal.bin");
tv_tileset =         (unsigned char*)HARDWARE_load_file("/minigame/tv/tv_fullscreen_v01_Tiles.bin");
tv_map     =         (short unsigned int*)HARDWARE_load_file("/minigame/tv/tv_fullscreen_v01_Map.bin");
//tv_tileset_size =     HARDWARE_get_file_size("/minigame/tv/tv_fullscreen_v01_Tiles.bin");

scanlines_palette =         (short unsigned int*)HARDWARE_load_file("/minigame/tv/scanlines_v00_Pal.bin");
scanlines_tileset =         (unsigned char*)HARDWARE_load_file("/minigame/tv/scanlines_v00_Tiles.bin");
scanlines_map     =         (short unsigned int*)HARDWARE_load_file("/minigame/tv/scanlines_v00_Map.bin");

scanlines_palette[1]=HARDWARE_RGB(10,10,10);

HARDWARE_load_AUX_map_to_xy_xy(3,tv_map,tv_tileset,tv_palette,256,192,TV_fromx,TV_fromy,TV_aspectratio,0);
HARDWARE_load_AUX_map_to_xy_xy(2,scanlines_map,scanlines_tileset,scanlines_palette,256,192,TV_fromx,TV_fromy,TV_aspectratio,1);

CLOCK_paused=1;

}


//=========================================================================================================================
void unload_tv_fullscreen()
{//=========================================================================================================================


HARDWARE_delete_AUX_bg(3);
HARDWARE_delete_AUX_bg(2);

HARDWARE_unload_file((void**)&tv_palette);
HARDWARE_unload_file((void**)&tv_tileset);
HARDWARE_unload_file((void**)&tv_map);

HARDWARE_unload_file((void**)&scanlines_palette);
HARDWARE_unload_file((void**)&scanlines_tileset);
HARDWARE_unload_file((void**)&scanlines_map);

GLOBAL_camera_fx_bounds_off=0;
cameraman_target=PLAYER_npc;

ZOOMlock=0;

GLOBAL_main_sprite_input_off=0;
GLOBAL_main_sprite_standing=0;
GLOBAL_main_sprite_actions_off=0;

CLOCK_paused=0;



}




