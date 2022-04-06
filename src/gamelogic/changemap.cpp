

#include "../main.h"
#include "changemap.h"



//CHANGE MAP
void load_map_data(int map)
{
    switch (map)
    {

		case MAP_bobsgame_TOWNYUUDownstairs:
		{
			   HARDWARE_map_width_tiles=62;
			   HARDWARE_map_height_tiles=43;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNYUUDownstairs_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNYUUDownstairs_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNYUUDownstairs_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNYUUDownstairs_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNYUUDownstairs_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNYUUDownstairs_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNYUUDownstairs_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNYUUDownstairs_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNYUUDownstairs_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNYUUDownstairs_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNYUUDownstairs_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNYUUDownstairs_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNYUUDownstairs_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNYUUDownstairs_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNYUUDownstairs_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNYUUDownstairs_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNYUUDownstairs_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNYUUDownstairs_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNYUUDownstairs_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNYUUDownstairs_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNYUUUpstairs:
		  {
			   HARDWARE_map_width_tiles=62;
			   HARDWARE_map_height_tiles=32;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNYUUUpstairs_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNYUUUpstairs_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNYUUUpstairs_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNYUUUpstairs_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNYUUUpstairs_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNYUUUpstairs_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNYUUUpstairs_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNYUUUpstairs_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNYUUUpstairs_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNYUUUpstairs_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNYUUUpstairs_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNYUUUpstairs_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNYUUUpstairs_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNYUUUpstairs_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNYUUUpstairs_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNYUUUpstairs_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNYUUUpstairs_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNYUUUpstairs_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNYUUUpstairs_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNYUUUpstairs_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNYUUUpstairsYuusRoom:
		  {
			   HARDWARE_map_width_tiles=33;
			   HARDWARE_map_height_tiles=32;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNYUUUpstairsYuusRoom_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNYUUUpstairsYuusRoom_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNYUUUpstairsYuusRoom_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNYUUUpstairsYuusRoom_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNYUUUpstairsYuusRoom_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNYUUUpstairsYuusRoom_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNYUUUpstairsYuusRoom_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNYUUUpstairsYuusRoom_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNYUUUpstairsYuusRoom_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNYUUUpstairsYuusRoom_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNYUUUpstairsYuusRoom_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNYUUUpstairsYuusRoom_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNYUUUpstairsYuusRoom_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNYUUUpstairsYuusRoom_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNYUUUpstairsYuusRoom_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNYUUUpstairsYuusRoom_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNYUUUpstairsYuusRoom_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNYUUUpstairsYuusRoom_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNYUUUpstairsYuusRoom_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNYUUUpstairsYuusRoom_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNYUUUpstairsBabyRoom:
		  {
			   HARDWARE_map_width_tiles=32;
			   HARDWARE_map_height_tiles=32;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNYUUUpstairsBabyRoom_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNYUUUpstairsBabyRoom_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNYUUUpstairsBabyRoom_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNYUUUpstairsBabyRoom_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNYUUUpstairsBabyRoom_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNYUUUpstairsBabyRoom_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNYUUUpstairsBabyRoom_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNYUUUpstairsBabyRoom_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNYUUUpstairsBabyRoom_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNYUUUpstairsBabyRoom_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNYUUUpstairsBabyRoom_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNYUUUpstairsBabyRoom_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNYUUUpstairsBabyRoom_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNYUUUpstairsBabyRoom_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNYUUUpstairsBabyRoom_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNYUUUpstairsBabyRoom_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNYUUUpstairsBabyRoom_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNYUUUpstairsBabyRoom_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNYUUUpstairsBabyRoom_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNYUUUpstairsBabyRoom_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNYUUUpstairsBrothersRoom:
		  {
			   HARDWARE_map_width_tiles=32;
			   HARDWARE_map_height_tiles=32;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNYUUUpstairsBrothersRoom_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNYUUUpstairsBrothersRoom_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNYUUUpstairsBrothersRoom_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNYUUUpstairsBrothersRoom_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNYUUUpstairsBrothersRoom_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNYUUUpstairsBrothersRoom_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNYUUUpstairsBrothersRoom_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNYUUUpstairsBrothersRoom_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNYUUUpstairsBrothersRoom_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNYUUUpstairsBrothersRoom_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNYUUUpstairsBrothersRoom_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNYUUUpstairsBrothersRoom_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNYUUUpstairsBrothersRoom_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNYUUUpstairsBrothersRoom_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNYUUUpstairsBrothersRoom_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNYUUUpstairsBrothersRoom_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNYUUUpstairsBrothersRoom_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNYUUUpstairsBrothersRoom_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNYUUUpstairsBrothersRoom_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNYUUUpstairsBrothersRoom_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNYUUUpstairsBathroom:
		  {
			   HARDWARE_map_width_tiles=32;
			   HARDWARE_map_height_tiles=32;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNYUUUpstairsBathroom_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNYUUUpstairsBathroom_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNYUUUpstairsBathroom_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNYUUUpstairsBathroom_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNYUUUpstairsBathroom_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNYUUUpstairsBathroom_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNYUUUpstairsBathroom_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNYUUUpstairsBathroom_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNYUUUpstairsBathroom_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNYUUUpstairsBathroom_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNYUUUpstairsBathroom_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNYUUUpstairsBathroom_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNYUUUpstairsBathroom_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNYUUUpstairsBathroom_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNYUUUpstairsBathroom_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNYUUUpstairsBathroom_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNYUUUpstairsBathroom_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNYUUUpstairsBathroom_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNYUUUpstairsBathroom_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNYUUUpstairsBathroom_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNYUUUpstairsParentsRoom:
		  {
			   HARDWARE_map_width_tiles=32;
			   HARDWARE_map_height_tiles=32;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNYUUUpstairsParentsRoom_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNYUUUpstairsParentsRoom_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNYUUUpstairsParentsRoom_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNYUUUpstairsParentsRoom_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNYUUUpstairsParentsRoom_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNYUUUpstairsParentsRoom_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNYUUUpstairsParentsRoom_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNYUUUpstairsParentsRoom_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNYUUUpstairsParentsRoom_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNYUUUpstairsParentsRoom_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNYUUUpstairsParentsRoom_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNYUUUpstairsParentsRoom_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNYUUUpstairsParentsRoom_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNYUUUpstairsParentsRoom_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNYUUUpstairsParentsRoom_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNYUUUpstairsParentsRoom_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNYUUUpstairsParentsRoom_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNYUUUpstairsParentsRoom_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNYUUUpstairsParentsRoom_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNYUUUpstairsParentsRoom_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNYUUBasement:
		  {
			   HARDWARE_map_width_tiles=62;
			   HARDWARE_map_height_tiles=37;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNYUUBasement_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNYUUBasement_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNYUUBasement_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNYUUBasement_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNYUUBasement_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNYUUBasement_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNYUUBasement_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNYUUBasement_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNYUUBasement_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNYUUBasement_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNYUUBasement_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNYUUBasement_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNYUUBasement_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNYUUBasement_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNYUUBasement_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNYUUBasement_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNYUUBasement_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNYUUBasement_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNYUUBasement_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNYUUBasement_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNYUUGarage:
		  {
			   HARDWARE_map_width_tiles=32;
			   HARDWARE_map_height_tiles=32;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNYUUGarage_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNYUUGarage_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNYUUGarage_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNYUUGarage_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNYUUGarage_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNYUUGarage_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNYUUGarage_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNYUUGarage_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNYUUGarage_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNYUUGarage_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNYUUGarage_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNYUUGarage_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNYUUGarage_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNYUUGarage_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNYUUGarage_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNYUUGarage_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNYUUGarage_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNYUUGarage_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNYUUGarage_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNYUUGarage_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNYUUAttic:
		  {
			   HARDWARE_map_width_tiles=32;
			   HARDWARE_map_height_tiles=32;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNYUUAttic_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNYUUAttic_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNYUUAttic_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNYUUAttic_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNYUUAttic_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNYUUAttic_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNYUUAttic_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNYUUAttic_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNYUUAttic_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNYUUAttic_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNYUUAttic_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNYUUAttic_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNYUUAttic_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNYUUAttic_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNYUUAttic_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNYUUAttic_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNYUUAttic_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNYUUAttic_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNYUUAttic_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNYUUAttic_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNYUUDownstairsBathroom:
		  {
			   HARDWARE_map_width_tiles=32;
			   HARDWARE_map_height_tiles=32;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNYUUDownstairsBathroom_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNYUUDownstairsBathroom_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNYUUDownstairsBathroom_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNYUUDownstairsBathroom_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNYUUDownstairsBathroom_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNYUUDownstairsBathroom_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNYUUDownstairsBathroom_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNYUUDownstairsBathroom_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNYUUDownstairsBathroom_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNYUUDownstairsBathroom_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNYUUDownstairsBathroom_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNYUUDownstairsBathroom_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNYUUDownstairsBathroom_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNYUUDownstairsBathroom_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNYUUDownstairsBathroom_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNYUUDownstairsBathroom_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNYUUDownstairsBathroom_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNYUUDownstairsBathroom_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNYUUDownstairsBathroom_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNYUUDownstairsBathroom_TouchMap_1_Tiles.bin");
			   break;
		  }







    case MAP_bobsgame_TOWNYUUBackyardToolShed:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNYUUBackyardToolShed_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNYUUBackyardToolShed_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNYUUBackyardToolShed_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNYUUBackyardToolShed_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNYUUBackyardToolShed_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNYUUBackyardToolShed_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNYUUBackyardToolShed_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNYUUBackyardToolShed_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNYUUBackyardToolShed_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNYUUBackyardToolShed_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNYUUBackyardToolShed_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNYUUBackyardToolShed_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNYUUBackyardToolShed_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNYUUBackyardToolShed_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNYUUBackyardToolShed_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNYUUBackyardToolShed_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNYUUBackyardToolShed_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNYUUBackyardToolShed_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNYUUBackyardToolShed_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNYUUBackyardToolShed_TouchMap_1_Tiles.bin");
         break;
    }



    case MAP_bobsgame_INTROTown:
    {
        HARDWARE_map_width_tiles=453;
        HARDWARE_map_height_tiles=87;
        strcpy(HARDWARE_map_0_filename,"/tilemap/intro/INTROTown_Map_0.bin");
        strcpy(HARDWARE_map_1_filename,"/tilemap/intro/INTROTown_Map_1.bin");
        strcpy(HARDWARE_map_2_filename,"/tilemap/intro/INTROTown_Map_2.bin");
        strcpy(HARDWARE_map_3_filename,"/tilemap/intro/INTROTown_Map_3.bin");
        strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/intro/INTROTown_Map_Hit.bin");
        strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/intro/INTROTown_Map_FX.bin");
        MAP_current_map_load_function=(void (*) ())&bobsgame_INTROTown_Map_Load_Function;
        MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_INTROTown_Map_Run_Function;
        MAP_current_map_stop_function=(void (*) ())&bobsgame_INTROTown_Map_Stop_Function;
        MAP_current_map_vbl_function=(void (*) ())&bobsgame_INTROTown_Map_VBL_Function;
        MAP_current_map_hbl_function=(void (*) ())&bobsgame_INTROTown_Map_HBL_Function;
        strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
        strcpy(HARDWARE_map_tileset_filename,"/tilemap/intro/INTROTown_Tiles.bin");
        HARDWARE_map_tileset_size=HARDWARE_get_file_size("/tilemap/intro/INTROTown_Tiles.bin");
        //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_INTROTown_TouchMap_302_Pal.bin");
        //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_INTROTown_TouchMap_1_Pal.bin");
        //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_INTROTown_TouchMap_302_Tiles.bin");
        //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_INTROTown_TouchMap_1_Tiles.bin");
        //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_INTROTown_TouchMap_302_Map.bin");
        ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_INTROTown_TouchMap_1_Map.bin");
        //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_INTROTown_TouchMap_302_Tiles.bin");
        //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_INTROTown_TouchMap_1_Tiles.bin");





        break;
    }




    case MAP_bobsgame_INTRODownstairs:
    {
        HARDWARE_map_width_tiles=62;
        HARDWARE_map_height_tiles=43;
        strcpy(HARDWARE_map_0_filename,"/tilemap/intro/INTRODownstairs_Map_0.bin");
        strcpy(HARDWARE_map_1_filename,"/tilemap/intro/INTRODownstairs_Map_1.bin");
        strcpy(HARDWARE_map_2_filename,"/tilemap/intro/INTRODownstairs_Map_2.bin");
        strcpy(HARDWARE_map_3_filename,"/tilemap/intro/INTRODownstairs_Map_3.bin");
        strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/intro/INTRODownstairs_Map_Hit.bin");
        strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/intro/INTRODownstairs_Map_FX.bin");
        MAP_current_map_load_function=(void (*) ())&bobsgame_INTRODownstairs_Map_Load_Function;
        MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_INTRODownstairs_Map_Run_Function;
        MAP_current_map_stop_function=(void (*) ())&bobsgame_INTRODownstairs_Map_Stop_Function;
        MAP_current_map_vbl_function=(void (*) ())&bobsgame_INTRODownstairs_Map_VBL_Function;
        MAP_current_map_hbl_function=(void (*) ())&bobsgame_INTRODownstairs_Map_HBL_Function;
        strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
        strcpy(HARDWARE_map_tileset_filename,"/tilemap/intro/INTRODownstairs_Tiles.bin");
        HARDWARE_map_tileset_size=HARDWARE_get_file_size("/tilemap/intro/INTRODownstairs_Tiles.bin");
        //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_INTRODownstairs_TouchMap_302_Pal.bin");
        //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_INTRODownstairs_TouchMap_1_Pal.bin");
        //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_INTRODownstairs_TouchMap_302_Tiles.bin");
        //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_INTRODownstairs_TouchMap_1_Tiles.bin");
        //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_INTRODownstairs_TouchMap_302_Map.bin");
        ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_INTRODownstairs_TouchMap_1_Map.bin");
        //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_INTRODownstairs_TouchMap_302_Tiles.bin");
        //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_INTRODownstairs_TouchMap_1_Tiles.bin");





        break;
    }
    case MAP_bobsgame_INTROUpstairs:
    {
        HARDWARE_map_width_tiles=62;
        HARDWARE_map_height_tiles=32;
        strcpy(HARDWARE_map_0_filename,"/tilemap/intro/INTROUpstairs_Map_0.bin");
        strcpy(HARDWARE_map_1_filename,"/tilemap/intro/INTROUpstairs_Map_1.bin");
        strcpy(HARDWARE_map_2_filename,"/tilemap/intro/INTROUpstairs_Map_2.bin");
        strcpy(HARDWARE_map_3_filename,"/tilemap/intro/INTROUpstairs_Map_3.bin");
        strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/intro/INTROUpstairs_Map_Hit.bin");
        strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/intro/INTROUpstairs_Map_FX.bin");
        MAP_current_map_load_function=(void (*) ())&bobsgame_INTROUpstairs_Map_Load_Function;
        MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_INTROUpstairs_Map_Run_Function;
        MAP_current_map_stop_function=(void (*) ())&bobsgame_INTROUpstairs_Map_Stop_Function;
        MAP_current_map_vbl_function=(void (*) ())&bobsgame_INTROUpstairs_Map_VBL_Function;
        MAP_current_map_hbl_function=(void (*) ())&bobsgame_INTROUpstairs_Map_HBL_Function;
        strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
        strcpy(HARDWARE_map_tileset_filename,"/tilemap/intro/INTROUpstairs_Tiles.bin");
        HARDWARE_map_tileset_size=HARDWARE_get_file_size("/tilemap/intro/INTROUpstairs_Tiles.bin");
        //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_INTROUpstairs_TouchMap_302_Pal.bin");
        //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_INTROUpstairs_TouchMap_1_Pal.bin");
        //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_INTROUpstairs_TouchMap_302_Tiles.bin");
        //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_INTROUpstairs_TouchMap_1_Tiles.bin");
        //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_INTROUpstairs_TouchMap_302_Map.bin");
        ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_INTROUpstairs_TouchMap_1_Map.bin");
        //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_INTROUpstairs_TouchMap_302_Tiles.bin");
        //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_INTROUpstairs_TouchMap_1_Tiles.bin");





        break;
    }
    case MAP_bobsgame_INTROUpstairsYuusRoom:
    {
        HARDWARE_map_width_tiles=33;
        HARDWARE_map_height_tiles=32;
        strcpy(HARDWARE_map_0_filename,"/tilemap/intro/INTROUpstairsYuusRoom_Map_0.bin");
        strcpy(HARDWARE_map_1_filename,"/tilemap/intro/INTROUpstairsYuusRoom_Map_1.bin");
        strcpy(HARDWARE_map_2_filename,"/tilemap/intro/INTROUpstairsYuusRoom_Map_2.bin");
        strcpy(HARDWARE_map_3_filename,"/tilemap/intro/INTROUpstairsYuusRoom_Map_3.bin");
        strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/intro/INTROUpstairsYuusRoom_Map_Hit.bin");
        strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/intro/INTROUpstairsYuusRoom_Map_FX.bin");
        MAP_current_map_load_function=(void (*) ())&bobsgame_INTROUpstairsYuusRoom_Map_Load_Function;
        MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_INTROUpstairsYuusRoom_Map_Run_Function;
        MAP_current_map_stop_function=(void (*) ())&bobsgame_INTROUpstairsYuusRoom_Map_Stop_Function;
        MAP_current_map_vbl_function=(void (*) ())&bobsgame_INTROUpstairsYuusRoom_Map_VBL_Function;
        MAP_current_map_hbl_function=(void (*) ())&bobsgame_INTROUpstairsYuusRoom_Map_HBL_Function;
        strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
        strcpy(HARDWARE_map_tileset_filename,"/tilemap/intro/INTROUpstairsYuusRoom_Tiles.bin");


        HARDWARE_map_tileset_size=HARDWARE_get_file_size("/tilemap/intro/INTROUpstairsYuusRoom_Tiles.bin");

        //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_INTROUpstairsYuusRoom_TouchMap_302_Pal.bin");
        //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_INTROUpstairsYuusRoom_TouchMap_1_Pal.bin");
        //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_INTROUpstairsYuusRoom_TouchMap_302_Tiles.bin");
        //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_INTROUpstairsYuusRoom_TouchMap_1_Tiles.bin");
        //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_INTROUpstairsYuusRoom_TouchMap_302_Map.bin");
        ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_INTROUpstairsYuusRoom_TouchMap_1_Map.bin");
        //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_INTROUpstairsYuusRoom_TouchMap_302_Tiles.bin");
        //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_INTROUpstairsYuusRoom_TouchMap_1_Tiles.bin");


        /* NSString*	MAP_filename3=(NSString*) [[NSBundle mainBundle] pathForResource:@"bobsgame_INTROUpstairsYuusRoom_Map_Layer_3.png" ofType:nil];
         [bg[3] setTexture:[[Texture2D alloc] initWithImage:(UIImage *)[[UIImage alloc]imageWithContentsOfFile:MAP_filename3]]];
         NSString*	MAP_filename0=(NSString*) [[NSBundle mainBundle] pathForResource:@"bobsgame_INTROUpstairsYuusRoom_Map_Layer_0.png" ofType:nil];
         [bg[0] setTexture:[[Texture2D alloc] initWithImage:(UIImage *)[[UIImage alloc]imageWithContentsOfFile:MAP_filename0]]];
         NSString*	MAP_filename2=(NSString*) [[NSBundle mainBundle] pathForResource:@"bobsgame_INTROUpstairsYuusRoom_Map_Layer_2.png" ofType:nil];
         [bg[2] setTexture:[[Texture2D alloc] initWithImage:(UIImage *)[[UIImage alloc]imageWithContentsOfFile:MAP_filename2]]];
         NSString*	MAP_filename1=(NSString*) [[NSBundle mainBundle] pathForResource:@"bobsgame_INTROUpstairsYuusRoom_Map_Layer_1.png" ofType:nil];
         [bg[1] setTexture:[[Texture2D alloc] initWithImage:(UIImage *)[[UIImage alloc]imageWithContentsOfFile:MAP_filename1]]];
         */

        break;
    }
    case MAP_bobsgame_INTROUpstairsBabyRoom:
    {
        HARDWARE_map_width_tiles=32;
        HARDWARE_map_height_tiles=32;
        strcpy(HARDWARE_map_0_filename,"/tilemap/intro/INTROUpstairsBabyRoom_Map_0.bin");
        strcpy(HARDWARE_map_1_filename,"/tilemap/intro/INTROUpstairsBabyRoom_Map_1.bin");
        strcpy(HARDWARE_map_2_filename,"/tilemap/intro/INTROUpstairsBabyRoom_Map_2.bin");
        strcpy(HARDWARE_map_3_filename,"/tilemap/intro/INTROUpstairsBabyRoom_Map_3.bin");
        strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/intro/INTROUpstairsBabyRoom_Map_Hit.bin");
        strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/intro/INTROUpstairsBabyRoom_Map_FX.bin");
        MAP_current_map_load_function=(void (*) ())&bobsgame_INTROUpstairsBabyRoom_Map_Load_Function;
        MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_INTROUpstairsBabyRoom_Map_Run_Function;
        MAP_current_map_stop_function=(void (*) ())&bobsgame_INTROUpstairsBabyRoom_Map_Stop_Function;
        MAP_current_map_vbl_function=(void (*) ())&bobsgame_INTROUpstairsBabyRoom_Map_VBL_Function;
        MAP_current_map_hbl_function=(void (*) ())&bobsgame_INTROUpstairsBabyRoom_Map_HBL_Function;
        strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
        strcpy(HARDWARE_map_tileset_filename,"/tilemap/intro/INTROUpstairsBabyRoom_Tiles.bin");
        HARDWARE_map_tileset_size=HARDWARE_get_file_size("/tilemap/intro/INTROUpstairsBabyRoom_Tiles.bin");
        //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_INTROUpstairsBabyRoom_TouchMap_302_Pal.bin");
        //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_INTROUpstairsBabyRoom_TouchMap_1_Pal.bin");
        //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_INTROUpstairsBabyRoom_TouchMap_302_Tiles.bin");
        //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_INTROUpstairsBabyRoom_TouchMap_1_Tiles.bin");
        //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_INTROUpstairsBabyRoom_TouchMap_302_Map.bin");
        ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_INTROUpstairsBabyRoom_TouchMap_1_Map.bin");
        //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_INTROUpstairsBabyRoom_TouchMap_302_Tiles.bin");
        //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_INTROUpstairsBabyRoom_TouchMap_1_Tiles.bin");





        break;
    }
    case MAP_bobsgame_INTROUpstairsBrothersRoom:
    {
        HARDWARE_map_width_tiles=32;
        HARDWARE_map_height_tiles=32;
        strcpy(HARDWARE_map_0_filename,"/tilemap/intro/INTROUpstairsBrothersRoom_Map_0.bin");
        strcpy(HARDWARE_map_1_filename,"/tilemap/intro/INTROUpstairsBrothersRoom_Map_1.bin");
        strcpy(HARDWARE_map_2_filename,"/tilemap/intro/INTROUpstairsBrothersRoom_Map_2.bin");
        strcpy(HARDWARE_map_3_filename,"/tilemap/intro/INTROUpstairsBrothersRoom_Map_3.bin");
        strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/intro/INTROUpstairsBrothersRoom_Map_Hit.bin");
        strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/intro/INTROUpstairsBrothersRoom_Map_FX.bin");
        MAP_current_map_load_function=(void (*) ())&bobsgame_INTROUpstairsBrothersRoom_Map_Load_Function;
        MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_INTROUpstairsBrothersRoom_Map_Run_Function;
        MAP_current_map_stop_function=(void (*) ())&bobsgame_INTROUpstairsBrothersRoom_Map_Stop_Function;
        MAP_current_map_vbl_function=(void (*) ())&bobsgame_INTROUpstairsBrothersRoom_Map_VBL_Function;
        MAP_current_map_hbl_function=(void (*) ())&bobsgame_INTROUpstairsBrothersRoom_Map_HBL_Function;
        strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
        strcpy(HARDWARE_map_tileset_filename,"/tilemap/intro/INTROUpstairsBrothersRoom_Tiles.bin");
        HARDWARE_map_tileset_size=HARDWARE_get_file_size("/tilemap/intro/INTROUpstairsBrothersRoom_Tiles.bin");
        //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_INTROUpstairsBrothersRoom_TouchMap_302_Pal.bin");
        //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_INTROUpstairsBrothersRoom_TouchMap_1_Pal.bin");
        //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_INTROUpstairsBrothersRoom_TouchMap_302_Tiles.bin");
        //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_INTROUpstairsBrothersRoom_TouchMap_1_Tiles.bin");
        //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_INTROUpstairsBrothersRoom_TouchMap_302_Map.bin");
        ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_INTROUpstairsBrothersRoom_TouchMap_1_Map.bin");
        //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_INTROUpstairsBrothersRoom_TouchMap_302_Tiles.bin");
        //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_INTROUpstairsBrothersRoom_TouchMap_1_Tiles.bin");





        break;
    }
    case MAP_bobsgame_INTROUpstairsBathroom:
    {
        HARDWARE_map_width_tiles=32;
        HARDWARE_map_height_tiles=32;
        strcpy(HARDWARE_map_0_filename,"/tilemap/intro/INTROUpstairsBathroom_Map_0.bin");
        strcpy(HARDWARE_map_1_filename,"/tilemap/intro/INTROUpstairsBathroom_Map_1.bin");
        strcpy(HARDWARE_map_2_filename,"/tilemap/intro/INTROUpstairsBathroom_Map_2.bin");
        strcpy(HARDWARE_map_3_filename,"/tilemap/intro/INTROUpstairsBathroom_Map_3.bin");
        strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/intro/INTROUpstairsBathroom_Map_Hit.bin");
        strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/intro/INTROUpstairsBathroom_Map_FX.bin");
        MAP_current_map_load_function=(void (*) ())&bobsgame_INTROUpstairsBathroom_Map_Load_Function;
        MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_INTROUpstairsBathroom_Map_Run_Function;
        MAP_current_map_stop_function=(void (*) ())&bobsgame_INTROUpstairsBathroom_Map_Stop_Function;
        MAP_current_map_vbl_function=(void (*) ())&bobsgame_INTROUpstairsBathroom_Map_VBL_Function;
        MAP_current_map_hbl_function=(void (*) ())&bobsgame_INTROUpstairsBathroom_Map_HBL_Function;
        strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
        strcpy(HARDWARE_map_tileset_filename,"/tilemap/intro/INTROUpstairsBathroom_Tiles.bin");
        HARDWARE_map_tileset_size=HARDWARE_get_file_size("/tilemap/intro/INTROUpstairsBathroom_Tiles.bin");
        //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_INTROUpstairsBathroom_TouchMap_302_Pal.bin");
        //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_INTROUpstairsBathroom_TouchMap_1_Pal.bin");
        //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_INTROUpstairsBathroom_TouchMap_302_Tiles.bin");
        //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_INTROUpstairsBathroom_TouchMap_1_Tiles.bin");
        //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_INTROUpstairsBathroom_TouchMap_302_Map.bin");
        ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_INTROUpstairsBathroom_TouchMap_1_Map.bin");
        //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_INTROUpstairsBathroom_TouchMap_302_Tiles.bin");
        //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_INTROUpstairsBathroom_TouchMap_1_Tiles.bin");





        break;
    }
    case MAP_bobsgame_INTROUpstairsParentsRoom:
    {
        HARDWARE_map_width_tiles=32;
        HARDWARE_map_height_tiles=32;
        strcpy(HARDWARE_map_0_filename,"/tilemap/intro/INTROUpstairsParentsRoom_Map_0.bin");
        strcpy(HARDWARE_map_1_filename,"/tilemap/intro/INTROUpstairsParentsRoom_Map_1.bin");
        strcpy(HARDWARE_map_2_filename,"/tilemap/intro/INTROUpstairsParentsRoom_Map_2.bin");
        strcpy(HARDWARE_map_3_filename,"/tilemap/intro/INTROUpstairsParentsRoom_Map_3.bin");
        strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/intro/INTROUpstairsParentsRoom_Map_Hit.bin");
        strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/intro/INTROUpstairsParentsRoom_Map_FX.bin");
        MAP_current_map_load_function=(void (*) ())&bobsgame_INTROUpstairsParentsRoom_Map_Load_Function;
        MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_INTROUpstairsParentsRoom_Map_Run_Function;
        MAP_current_map_stop_function=(void (*) ())&bobsgame_INTROUpstairsParentsRoom_Map_Stop_Function;
        MAP_current_map_vbl_function=(void (*) ())&bobsgame_INTROUpstairsParentsRoom_Map_VBL_Function;
        MAP_current_map_hbl_function=(void (*) ())&bobsgame_INTROUpstairsParentsRoom_Map_HBL_Function;
        strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
        strcpy(HARDWARE_map_tileset_filename,"/tilemap/intro/INTROUpstairsParentsRoom_Tiles.bin");
        HARDWARE_map_tileset_size=HARDWARE_get_file_size("/tilemap/intro/INTROUpstairsParentsRoom_Tiles.bin");
        //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_INTROUpstairsParentsRoom_TouchMap_302_Pal.bin");
        //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_INTROUpstairsParentsRoom_TouchMap_1_Pal.bin");
        //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_INTROUpstairsParentsRoom_TouchMap_302_Tiles.bin");
        //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_INTROUpstairsParentsRoom_TouchMap_1_Tiles.bin");
        //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_INTROUpstairsParentsRoom_TouchMap_302_Map.bin");
        ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_INTROUpstairsParentsRoom_TouchMap_1_Map.bin");
        //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_INTROUpstairsParentsRoom_TouchMap_302_Tiles.bin");
        //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_INTROUpstairsParentsRoom_TouchMap_1_Tiles.bin");





        break;
    }
    case MAP_bobsgame_INTROBasement:
    {
        HARDWARE_map_width_tiles=62;
        HARDWARE_map_height_tiles=37;
        strcpy(HARDWARE_map_0_filename,"/tilemap/intro/INTROBasement_Map_0.bin");
        strcpy(HARDWARE_map_1_filename,"/tilemap/intro/INTROBasement_Map_1.bin");
        strcpy(HARDWARE_map_2_filename,"/tilemap/intro/INTROBasement_Map_2.bin");
        strcpy(HARDWARE_map_3_filename,"/tilemap/intro/INTROBasement_Map_3.bin");
        strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/intro/INTROBasement_Map_Hit.bin");
        strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/intro/INTROBasement_Map_FX.bin");
        MAP_current_map_load_function=(void (*) ())&bobsgame_INTROBasement_Map_Load_Function;
        MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_INTROBasement_Map_Run_Function;
        MAP_current_map_stop_function=(void (*) ())&bobsgame_INTROBasement_Map_Stop_Function;
        MAP_current_map_vbl_function=(void (*) ())&bobsgame_INTROBasement_Map_VBL_Function;
        MAP_current_map_hbl_function=(void (*) ())&bobsgame_INTROBasement_Map_HBL_Function;
        strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
        strcpy(HARDWARE_map_tileset_filename,"/tilemap/intro/INTROBasement_Tiles.bin");
        HARDWARE_map_tileset_size=HARDWARE_get_file_size("/tilemap/intro/INTROBasement_Tiles.bin");
        //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_INTROBasement_TouchMap_302_Pal.bin");
        //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_INTROBasement_TouchMap_1_Pal.bin");
        //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_INTROBasement_TouchMap_302_Tiles.bin");
        //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_INTROBasement_TouchMap_1_Tiles.bin");
        //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_INTROBasement_TouchMap_302_Map.bin");
        ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_INTROBasement_TouchMap_1_Map.bin");
        //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_INTROBasement_TouchMap_302_Tiles.bin");
        //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_INTROBasement_TouchMap_1_Tiles.bin");





        break;
    }
    case MAP_bobsgame_INTROGarage:
    {
        HARDWARE_map_width_tiles=32;
        HARDWARE_map_height_tiles=32;
        strcpy(HARDWARE_map_0_filename,"/tilemap/intro/INTROGarage_Map_0.bin");
        strcpy(HARDWARE_map_1_filename,"/tilemap/intro/INTROGarage_Map_1.bin");
        strcpy(HARDWARE_map_2_filename,"/tilemap/intro/INTROGarage_Map_2.bin");
        strcpy(HARDWARE_map_3_filename,"/tilemap/intro/INTROGarage_Map_3.bin");
        strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/intro/INTROGarage_Map_Hit.bin");
        strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/intro/INTROGarage_Map_FX.bin");
        MAP_current_map_load_function=(void (*) ())&bobsgame_INTROGarage_Map_Load_Function;
        MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_INTROGarage_Map_Run_Function;
        MAP_current_map_stop_function=(void (*) ())&bobsgame_INTROGarage_Map_Stop_Function;
        MAP_current_map_vbl_function=(void (*) ())&bobsgame_INTROGarage_Map_VBL_Function;
        MAP_current_map_hbl_function=(void (*) ())&bobsgame_INTROGarage_Map_HBL_Function;
        strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
        strcpy(HARDWARE_map_tileset_filename,"/tilemap/intro/INTROGarage_Tiles.bin");
        HARDWARE_map_tileset_size=HARDWARE_get_file_size("/tilemap/intro/INTROGarage_Tiles.bin");
        //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_INTROGarage_TouchMap_302_Pal.bin");
        //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_INTROGarage_TouchMap_1_Pal.bin");
        //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_INTROGarage_TouchMap_302_Tiles.bin");
        //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_INTROGarage_TouchMap_1_Tiles.bin");
        //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_INTROGarage_TouchMap_302_Map.bin");
        ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_INTROGarage_TouchMap_1_Map.bin");
        //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_INTROGarage_TouchMap_302_Tiles.bin");
        //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_INTROGarage_TouchMap_1_Tiles.bin");





        break;
    }
    case MAP_bobsgame_INTRODownstairsBathroom:
    {
        HARDWARE_map_width_tiles=32;
        HARDWARE_map_height_tiles=32;
        strcpy(HARDWARE_map_0_filename,"/tilemap/intro/INTRODownstairsBathroom_Map_0.bin");
        strcpy(HARDWARE_map_1_filename,"/tilemap/intro/INTRODownstairsBathroom_Map_1.bin");
        strcpy(HARDWARE_map_2_filename,"/tilemap/intro/INTRODownstairsBathroom_Map_2.bin");
        strcpy(HARDWARE_map_3_filename,"/tilemap/intro/INTRODownstairsBathroom_Map_3.bin");
        strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/intro/INTRODownstairsBathroom_Map_Hit.bin");
        strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/intro/INTRODownstairsBathroom_Map_FX.bin");
        MAP_current_map_load_function=(void (*) ())&bobsgame_INTRODownstairsBathroom_Map_Load_Function;
        MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_INTRODownstairsBathroom_Map_Run_Function;
        MAP_current_map_stop_function=(void (*) ())&bobsgame_INTRODownstairsBathroom_Map_Stop_Function;
        MAP_current_map_vbl_function=(void (*) ())&bobsgame_INTRODownstairsBathroom_Map_VBL_Function;
        MAP_current_map_hbl_function=(void (*) ())&bobsgame_INTRODownstairsBathroom_Map_HBL_Function;
        strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
        strcpy(HARDWARE_map_tileset_filename,"/tilemap/intro/INTRODownstairsBathroom_Tiles.bin");
        HARDWARE_map_tileset_size=HARDWARE_get_file_size("/tilemap/intro/INTRODownstairsBathroom_Tiles.bin");
        //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_INTRODownstairsBathroom_TouchMap_302_Pal.bin");
        //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_INTRODownstairsBathroom_TouchMap_1_Pal.bin");
        //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_INTRODownstairsBathroom_TouchMap_302_Tiles.bin");
        //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_INTRODownstairsBathroom_TouchMap_1_Tiles.bin");
        //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_INTRODownstairsBathroom_TouchMap_302_Map.bin");
        ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_INTRODownstairsBathroom_TouchMap_1_Map.bin");
        //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_INTRODownstairsBathroom_TouchMap_302_Tiles.bin");
        //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_INTRODownstairsBathroom_TouchMap_1_Tiles.bin");





        break;
    }
    case MAP_bobsgame_INTROAttic:
    {
        HARDWARE_map_width_tiles=32;
        HARDWARE_map_height_tiles=32;
        strcpy(HARDWARE_map_0_filename,"/tilemap/intro/INTROAttic_Map_0.bin");
        strcpy(HARDWARE_map_1_filename,"/tilemap/intro/INTROAttic_Map_1.bin");
        strcpy(HARDWARE_map_2_filename,"/tilemap/intro/INTROAttic_Map_2.bin");
        strcpy(HARDWARE_map_3_filename,"/tilemap/intro/INTROAttic_Map_3.bin");
        strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/intro/INTROAttic_Map_Hit.bin");
        strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/intro/INTROAttic_Map_FX.bin");
        MAP_current_map_load_function=(void (*) ())&bobsgame_INTROAttic_Map_Load_Function;
        MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_INTROAttic_Map_Run_Function;
        MAP_current_map_stop_function=(void (*) ())&bobsgame_INTROAttic_Map_Stop_Function;
        MAP_current_map_vbl_function=(void (*) ())&bobsgame_INTROAttic_Map_VBL_Function;
        MAP_current_map_hbl_function=(void (*) ())&bobsgame_INTROAttic_Map_HBL_Function;

        strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
        strcpy(HARDWARE_map_tileset_filename,"/tilemap/intro/INTROAttic_Tiles.bin");

        HARDWARE_map_tileset_size=HARDWARE_get_file_size("/tilemap/intro/INTROAttic_Tiles.bin");

        //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_INTROAttic_TouchMap_302_Pal.bin");
        //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_INTROAttic_TouchMap_1_Pal.bin");
        //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_INTROAttic_TouchMap_302_Tiles.bin");
        //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_INTROAttic_TouchMap_1_Tiles.bin");
        //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_INTROAttic_TouchMap_302_Map.bin");
        ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_INTROAttic_TouchMap_1_Map.bin");

        //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_INTROAttic_TouchMap_302_Tiles.bin");
        //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_INTROAttic_TouchMap_1_Tiles.bin");





        break;
    }


    case MAP_bobsgame_MISCnothing:
    {
        HARDWARE_map_width_tiles=32;
        HARDWARE_map_height_tiles=32;

        strcpy(HARDWARE_map_0_filename,"/tilemap/misc/MISCnothing_Map_0.bin");
        strcpy(HARDWARE_map_1_filename,"/tilemap/misc/MISCnothing_Map_1.bin");
        strcpy(HARDWARE_map_2_filename,"/tilemap/misc/MISCnothing_Map_2.bin");
        strcpy(HARDWARE_map_3_filename,"/tilemap/misc/MISCnothing_Map_3.bin");

        strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/misc/MISCnothing_Map_Hit.bin");
        strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/misc/MISCnothing_Map_FX.bin");
        MAP_current_map_load_function=(void (*) ())&bobsgame_MISCnothing_Map_Load_Function;
        MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_MISCnothing_Map_Run_Function;
        MAP_current_map_stop_function=(void (*) ())&bobsgame_MISCnothing_Map_Stop_Function;
        MAP_current_map_vbl_function=(void (*) ())&bobsgame_MISCnothing_Map_VBL_Function;
        MAP_current_map_hbl_function=(void (*) ())&bobsgame_MISCnothing_Map_HBL_Function;
        strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
        strcpy(HARDWARE_map_tileset_filename,"/tilemap/misc/MISCnothing_Tiles.bin");
        HARDWARE_map_tileset_size=HARDWARE_get_file_size("/tilemap/misc/MISCnothing_Tiles.bin");
        //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_MISCnothing_TouchMap_302_Pal.bin");
        //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_MISCnothing_TouchMap_1_Pal.bin");
        //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_MISCnothing_TouchMap_302_Tiles.bin");
        //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_MISCnothing_TouchMap_1_Tiles.bin");
        //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_MISCnothing_TouchMap_302_Map.bin");
        ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_MISCnothing_TouchMap_1_Map.bin");
        //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_MISCnothing_TouchMap_302_Tiles.bin");
        //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_MISCnothing_TouchMap_1_Tiles.bin");



        break;
    }










































    case MAP_bobsgame_CITYBobsAptInside:
    {
        HARDWARE_map_width_tiles=32;
        HARDWARE_map_height_tiles=35;
        strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYBobsAptInside_Map_0.bin");
        strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYBobsAptInside_Map_1.bin");
        strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYBobsAptInside_Map_2.bin");
        strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYBobsAptInside_Map_3.bin");
        strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYBobsAptInside_Map_Hit.bin");
        strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYBobsAptInside_Map_FX.bin");
        MAP_current_map_load_function=(void (*) ())&bobsgame_CITYBobsAptInside_Map_Load_Function;
        MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYBobsAptInside_Map_Run_Function;
        MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYBobsAptInside_Map_Stop_Function;
        MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYBobsAptInside_Map_VBL_Function;
        MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYBobsAptInside_Map_HBL_Function;
        strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
        strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYBobsAptInside_Tiles.bin");
        HARDWARE_map_tileset_size=HARDWARE_get_file_size("/tilemap/city/CITYBobsAptInside_Tiles.bin");
        //strcpy(current_touchmap_302_palette_filename,"/touchmap/city/bobsgame_CITYBobsAptInside_TouchMap_302_Pal.bin");
        //strcpy(current_touchmap_1_palette_filename,"/touchmap/city/bobsgame_CITYBobsAptInside_TouchMap_1_Pal.bin");
        //strcpy(current_touchmap_302_tileset_filename,"/touchmap/city/bobsgame_CITYBobsAptInside_TouchMap_302_Tiles.bin");
        //strcpy(current_touchmap_1_tileset_filename,"/touchmap/city/bobsgame_CITYBobsAptInside_TouchMap_1_Tiles.bin");
        //strcpy(current_touchmap_302_map_filename,"/touchmap/city/bobsgame_CITYBobsAptInside_TouchMap_302_Map.bin");
        ////strcpy(current_touchmap_1_map_filename,"/touchmap/city/bobsgame_CITYBobsAptInside_TouchMap_1_Map.bin");
        //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/city/bobsgame_CITYBobsAptInside_TouchMap_302_Tiles.bin");
        //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/city/bobsgame_CITYBobsAptInside_TouchMap_1_Tiles.bin");
        break;
    }

    case MAP_bobsgame_CITYBobsAptInsideTrashed:
    {
        HARDWARE_map_width_tiles=32;
        HARDWARE_map_height_tiles=35;
        strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYBobsAptInsideTrashed_Map_0.bin");
        strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYBobsAptInsideTrashed_Map_1.bin");
        strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYBobsAptInsideTrashed_Map_2.bin");
        strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYBobsAptInsideTrashed_Map_3.bin");
        strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYBobsAptInsideTrashed_Map_Hit.bin");
        strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYBobsAptInsideTrashed_Map_FX.bin");
        MAP_current_map_load_function=(void (*) ())&bobsgame_CITYBobsAptInside_Map_Load_Function;
        MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYBobsAptInside_Map_Run_Function;
        MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYBobsAptInside_Map_Stop_Function;
        MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYBobsAptInside_Map_VBL_Function;
        MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYBobsAptInside_Map_HBL_Function;
        strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
        strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYBobsAptInsideTrashed_Tiles.bin");
        HARDWARE_map_tileset_size=HARDWARE_get_file_size("/tilemap/city/CITYBobsAptInsideTrashed_Tiles.bin");
        //strcpy(current_touchmap_302_palette_filename,"/touchmap/city/bobsgame_CITYBobsAptInsideTrashed_TouchMap_302_Pal.bin");
        //strcpy(current_touchmap_1_palette_filename,"/touchmap/city/bobsgame_CITYBobsAptInsideTrashed_TouchMap_1_Pal.bin");
        //strcpy(current_touchmap_302_tileset_filename,"/touchmap/city/bobsgame_CITYBobsAptInsideTrashed_TouchMap_302_Tiles.bin");
        //strcpy(current_touchmap_1_tileset_filename,"/touchmap/city/bobsgame_CITYBobsAptInsideTrashed_TouchMap_1_Tiles.bin");
        //strcpy(current_touchmap_302_map_filename,"/touchmap/city/bobsgame_CITYBobsAptInsideTrashed_TouchMap_302_Map.bin");
        ////strcpy(current_touchmap_1_map_filename,"/touchmap/city/bobsgame_CITYBobsAptInsideTrashed_TouchMap_1_Map.bin");
        //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/city/bobsgame_CITYBobsAptInsideTrashed_TouchMap_302_Tiles.bin");
        //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/city/bobsgame_CITYBobsAptInsideTrashed_TouchMap_1_Tiles.bin");
        break;
    }

















































    case MAP_bobsgame_CITYBobsBathroom:
    {
        HARDWARE_map_width_tiles=32;
        HARDWARE_map_height_tiles=32;
        strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYBobsBathroom_Map_0.bin");
        strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYBobsBathroom_Map_1.bin");
        strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYBobsBathroom_Map_2.bin");
        strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYBobsBathroom_Map_3.bin");
        strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYBobsBathroom_Map_Hit.bin");
        strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYBobsBathroom_Map_FX.bin");
        MAP_current_map_load_function=(void (*) ())&bobsgame_CITYBobsBathroom_Map_Load_Function;
        MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYBobsBathroom_Map_Run_Function;
        MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYBobsBathroom_Map_Stop_Function;
        MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYBobsBathroom_Map_VBL_Function;
        MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYBobsBathroom_Map_HBL_Function;
        strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
        strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYBobsBathroom_Tiles.bin");
        HARDWARE_map_tileset_size=HARDWARE_get_file_size("/tilemap/city/CITYBobsBathroom_Tiles.bin");
        //strcpy(current_touchmap_302_palette_filename,"/touchmap/city/bobsgame_CITYBobsBathroom_TouchMap_302_Pal.bin");
        //strcpy(current_touchmap_1_palette_filename,"/touchmap/city/bobsgame_CITYBobsBathroom_TouchMap_1_Pal.bin");
        //strcpy(current_touchmap_302_tileset_filename,"/touchmap/city/bobsgame_CITYBobsBathroom_TouchMap_302_Tiles.bin");
        //strcpy(current_touchmap_1_tileset_filename,"/touchmap/city/bobsgame_CITYBobsBathroom_TouchMap_1_Tiles.bin");
        //strcpy(current_touchmap_302_map_filename,"/touchmap/city/bobsgame_CITYBobsBathroom_TouchMap_302_Map.bin");
        ////strcpy(current_touchmap_1_map_filename,"/touchmap/city/bobsgame_CITYBobsBathroom_TouchMap_1_Map.bin");
        //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/city/bobsgame_CITYBobsBathroom_TouchMap_302_Tiles.bin");
        //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/city/bobsgame_CITYBobsBathroom_TouchMap_1_Tiles.bin");
        break;
    }






















































		  case MAP_bobsgame_TOWNGENERIC1Downstairs:
		  {
			   HARDWARE_map_width_tiles=62;
			   HARDWARE_map_height_tiles=43;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNGENERIC1Downstairs_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNGENERIC1Downstairs_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNGENERIC1Downstairs_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNGENERIC1Downstairs_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNGENERIC1Downstairs_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNGENERIC1Downstairs_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNGENERIC1Downstairs_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNGENERIC1Downstairs_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNGENERIC1Downstairs_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNGENERIC1Downstairs_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNGENERIC1Downstairs_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNGENERIC1Downstairs_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNGENERIC1Downstairs_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNGENERIC1Downstairs_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNGENERIC1Downstairs_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNGENERIC1Downstairs_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNGENERIC1Downstairs_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNGENERIC1Downstairs_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNGENERIC1Downstairs_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNGENERIC1Downstairs_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNGENERIC2Downstairs:
		  {
			   HARDWARE_map_width_tiles=62;
			   HARDWARE_map_height_tiles=43;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNGENERIC2Downstairs_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNGENERIC2Downstairs_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNGENERIC2Downstairs_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNGENERIC2Downstairs_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNGENERIC2Downstairs_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNGENERIC2Downstairs_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNGENERIC2Downstairs_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNGENERIC2Downstairs_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNGENERIC2Downstairs_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNGENERIC2Downstairs_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNGENERIC2Downstairs_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNGENERIC2Downstairs_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNGENERIC2Downstairs_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNGENERIC2Downstairs_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNGENERIC2Downstairs_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNGENERIC2Downstairs_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNGENERIC2Downstairs_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNGENERIC2Downstairs_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNGENERIC2Downstairs_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNGENERIC2Downstairs_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNGENERIC3Downstairs:
		  {
			   HARDWARE_map_width_tiles=62;
			   HARDWARE_map_height_tiles=43;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNGENERIC3Downstairs_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNGENERIC3Downstairs_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNGENERIC3Downstairs_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNGENERIC3Downstairs_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNGENERIC3Downstairs_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNGENERIC3Downstairs_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNGENERIC3Downstairs_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNGENERIC3Downstairs_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNGENERIC3Downstairs_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNGENERIC3Downstairs_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNGENERIC3Downstairs_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNGENERIC3Downstairs_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNGENERIC3Downstairs_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNGENERIC3Downstairs_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNGENERIC3Downstairs_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNGENERIC3Downstairs_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNGENERIC3Downstairs_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNGENERIC3Downstairs_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNGENERIC3Downstairs_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNGENERIC3Downstairs_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNFRIENDDownstairs:
		  {
			   HARDWARE_map_width_tiles=62;
			   HARDWARE_map_height_tiles=43;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNFRIENDDownstairs_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNFRIENDDownstairs_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNFRIENDDownstairs_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNFRIENDDownstairs_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNFRIENDDownstairs_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNFRIENDDownstairs_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNFRIENDDownstairs_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNFRIENDDownstairs_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNFRIENDDownstairs_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNFRIENDDownstairs_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNFRIENDDownstairs_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNFRIENDDownstairs_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNFRIENDDownstairs_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNFRIENDDownstairs_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNFRIENDDownstairs_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNFRIENDDownstairs_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNFRIENDDownstairs_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNFRIENDDownstairs_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNFRIENDDownstairs_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNFRIENDDownstairs_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNFRIENDUpstairs:
		  {
			   HARDWARE_map_width_tiles=62;
			   HARDWARE_map_height_tiles=33;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNFRIENDUpstairs_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNFRIENDUpstairs_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNFRIENDUpstairs_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNFRIENDUpstairs_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNFRIENDUpstairs_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNFRIENDUpstairs_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNFRIENDUpstairs_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNFRIENDUpstairs_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNFRIENDUpstairs_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNFRIENDUpstairs_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNFRIENDUpstairs_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNFRIENDUpstairs_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNFRIENDUpstairs_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNFRIENDUpstairs_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNFRIENDUpstairs_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNFRIENDUpstairs_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNFRIENDUpstairs_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNFRIENDUpstairs_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNFRIENDUpstairs_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNFRIENDUpstairs_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNFRIENDUpstairsFriendsRoom:
		  {
			   HARDWARE_map_width_tiles=33;
			   HARDWARE_map_height_tiles=32;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNFRIENDUpstairsFriendsRoom_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNFRIENDUpstairsFriendsRoom_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNFRIENDUpstairsFriendsRoom_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNFRIENDUpstairsFriendsRoom_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNFRIENDUpstairsFriendsRoom_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNFRIENDUpstairsFriendsRoom_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNFRIENDUpstairsFriendsRoom_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNFRIENDUpstairsFriendsRoom_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNFRIENDUpstairsFriendsRoom_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNFRIENDUpstairsFriendsRoom_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNFRIENDUpstairsFriendsRoom_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNFRIENDUpstairsFriendsRoom_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNFRIENDUpstairsFriendsRoom_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNFRIENDUpstairsFriendsRoom_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNFRIENDUpstairsFriendsRoom_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNFRIENDUpstairsFriendsRoom_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNFRIENDUpstairsFriendsRoom_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNFRIENDUpstairsFriendsRoom_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNFRIENDUpstairsFriendsRoom_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNFRIENDUpstairsFriendsRoom_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNFRIENDUpstairsSistersRoom:
		  {
			   HARDWARE_map_width_tiles=32;
			   HARDWARE_map_height_tiles=32;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNFRIENDUpstairsSistersRoom_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNFRIENDUpstairsSistersRoom_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNFRIENDUpstairsSistersRoom_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNFRIENDUpstairsSistersRoom_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNFRIENDUpstairsSistersRoom_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNFRIENDUpstairsSistersRoom_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNFRIENDUpstairsSistersRoom_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNFRIENDUpstairsSistersRoom_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNFRIENDUpstairsSistersRoom_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNFRIENDUpstairsSistersRoom_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNFRIENDUpstairsSistersRoom_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNFRIENDUpstairsSistersRoom_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNFRIENDUpstairsSistersRoom_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNFRIENDUpstairsSistersRoom_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNFRIENDUpstairsSistersRoom_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNFRIENDUpstairsSistersRoom_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNFRIENDUpstairsSistersRoom_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNFRIENDUpstairsSistersRoom_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNFRIENDUpstairsSistersRoom_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNFRIENDUpstairsSistersRoom_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNFRIENDUpstairsBathroom:
		  {
			   HARDWARE_map_width_tiles=32;
			   HARDWARE_map_height_tiles=32;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNFRIENDUpstairsBathroom_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNFRIENDUpstairsBathroom_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNFRIENDUpstairsBathroom_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNFRIENDUpstairsBathroom_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNFRIENDUpstairsBathroom_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNFRIENDUpstairsBathroom_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNFRIENDUpstairsBathroom_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNFRIENDUpstairsBathroom_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNFRIENDUpstairsBathroom_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNFRIENDUpstairsBathroom_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNFRIENDUpstairsBathroom_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNFRIENDUpstairsBathroom_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNFRIENDUpstairsBathroom_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNFRIENDUpstairsBathroom_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNFRIENDUpstairsBathroom_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNFRIENDUpstairsBathroom_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNFRIENDUpstairsBathroom_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNFRIENDUpstairsBathroom_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNFRIENDUpstairsBathroom_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNFRIENDUpstairsBathroom_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNFRIENDUpstairsParentsRoom:
		  {
			   HARDWARE_map_width_tiles=43;
			   HARDWARE_map_height_tiles=32;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNFRIENDUpstairsParentsRoom_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNFRIENDUpstairsParentsRoom_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNFRIENDUpstairsParentsRoom_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNFRIENDUpstairsParentsRoom_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNFRIENDUpstairsParentsRoom_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNFRIENDUpstairsParentsRoom_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNFRIENDUpstairsParentsRoom_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNFRIENDUpstairsParentsRoom_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNFRIENDUpstairsParentsRoom_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNFRIENDUpstairsParentsRoom_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNFRIENDUpstairsParentsRoom_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNFRIENDUpstairsParentsRoom_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNFRIENDUpstairsParentsRoom_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNFRIENDUpstairsParentsRoom_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNFRIENDUpstairsParentsRoom_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNFRIENDUpstairsParentsRoom_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNFRIENDUpstairsParentsRoom_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNFRIENDUpstairsParentsRoom_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNFRIENDUpstairsParentsRoom_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNFRIENDUpstairsParentsRoom_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNFRIENDBasement:
		  {
			   HARDWARE_map_width_tiles=62;
			   HARDWARE_map_height_tiles=37;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNFRIENDBasement_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNFRIENDBasement_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNFRIENDBasement_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNFRIENDBasement_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNFRIENDBasement_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNFRIENDBasement_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNFRIENDBasement_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNFRIENDBasement_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNFRIENDBasement_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNFRIENDBasement_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNFRIENDBasement_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNFRIENDBasement_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNFRIENDBasement_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNFRIENDBasement_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNFRIENDBasement_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNFRIENDBasement_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNFRIENDBasement_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNFRIENDBasement_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNFRIENDBasement_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNFRIENDBasement_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNFRIENDGarage:
		  {
			   HARDWARE_map_width_tiles=32;
			   HARDWARE_map_height_tiles=32;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNFRIENDGarage_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNFRIENDGarage_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNFRIENDGarage_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNFRIENDGarage_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNFRIENDGarage_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNFRIENDGarage_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNFRIENDGarage_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNFRIENDGarage_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNFRIENDGarage_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNFRIENDGarage_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNFRIENDGarage_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNFRIENDGarage_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNFRIENDGarage_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNFRIENDGarage_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNFRIENDGarage_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNFRIENDGarage_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNFRIENDGarage_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNFRIENDGarage_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNFRIENDGarage_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNFRIENDGarage_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNFRIENDDownstairsBathroom:
		  {
			   HARDWARE_map_width_tiles=32;
			   HARDWARE_map_height_tiles=32;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNFRIENDDownstairsBathroom_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNFRIENDDownstairsBathroom_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNFRIENDDownstairsBathroom_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNFRIENDDownstairsBathroom_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNFRIENDDownstairsBathroom_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNFRIENDDownstairsBathroom_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNFRIENDDownstairsBathroom_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNFRIENDDownstairsBathroom_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNFRIENDDownstairsBathroom_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNFRIENDDownstairsBathroom_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNFRIENDDownstairsBathroom_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNFRIENDDownstairsBathroom_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNFRIENDDownstairsBathroom_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNFRIENDDownstairsBathroom_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNFRIENDDownstairsBathroom_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNFRIENDDownstairsBathroom_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNFRIENDDownstairsBathroom_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNFRIENDDownstairsBathroom_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNFRIENDDownstairsBathroom_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNFRIENDDownstairsBathroom_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_JAPANUpstairsMainBedroom:
		  {
			   HARDWARE_map_width_tiles=32;
			   HARDWARE_map_height_tiles=32;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/JAPANUpstairsMainBedroom_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/JAPANUpstairsMainBedroom_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/JAPANUpstairsMainBedroom_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/JAPANUpstairsMainBedroom_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/JAPANUpstairsMainBedroom_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/JAPANUpstairsMainBedroom_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_JAPANUpstairsMainBedroom_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_JAPANUpstairsMainBedroom_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_JAPANUpstairsMainBedroom_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_JAPANUpstairsMainBedroom_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_JAPANUpstairsMainBedroom_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/JAPANUpstairsMainBedroom_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_JAPANUpstairsMainBedroom_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_JAPANUpstairsMainBedroom_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_JAPANUpstairsMainBedroom_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_JAPANUpstairsMainBedroom_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_JAPANUpstairsMainBedroom_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_JAPANUpstairsMainBedroom_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_JAPANUpstairsMainBedroom_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_JAPANUpstairsMainBedroom_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNCRAZYDownstairs:
		  {
			   HARDWARE_map_width_tiles=46;
			   HARDWARE_map_height_tiles=38;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNCRAZYDownstairs_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNCRAZYDownstairs_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNCRAZYDownstairs_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNCRAZYDownstairs_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNCRAZYDownstairs_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNCRAZYDownstairs_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNCRAZYDownstairs_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNCRAZYDownstairs_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNCRAZYDownstairs_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNCRAZYDownstairs_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNCRAZYDownstairs_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNCRAZYDownstairs_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNCRAZYDownstairs_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNCRAZYDownstairs_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNCRAZYDownstairs_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNCRAZYDownstairs_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNCRAZYDownstairs_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNCRAZYDownstairs_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNCRAZYDownstairs_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNCRAZYDownstairs_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNCRAZYUpstairs:
		  {
			   HARDWARE_map_width_tiles=32;
			   HARDWARE_map_height_tiles=32;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNCRAZYUpstairs_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNCRAZYUpstairs_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNCRAZYUpstairs_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNCRAZYUpstairs_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNCRAZYUpstairs_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNCRAZYUpstairs_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNCRAZYUpstairs_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNCRAZYUpstairs_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNCRAZYUpstairs_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNCRAZYUpstairs_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNCRAZYUpstairs_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNCRAZYUpstairs_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNCRAZYUpstairs_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNCRAZYUpstairs_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNCRAZYUpstairs_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNCRAZYUpstairs_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNCRAZYUpstairs_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNCRAZYUpstairs_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNCRAZYUpstairs_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNCRAZYUpstairs_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNCRAZYUpstairsBedroom:
		  {
			   HARDWARE_map_width_tiles=32;
			   HARDWARE_map_height_tiles=32;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNCRAZYUpstairsBedroom_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNCRAZYUpstairsBedroom_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNCRAZYUpstairsBedroom_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNCRAZYUpstairsBedroom_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNCRAZYUpstairsBedroom_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNCRAZYUpstairsBedroom_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNCRAZYUpstairsBedroom_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNCRAZYUpstairsBedroom_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNCRAZYUpstairsBedroom_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNCRAZYUpstairsBedroom_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNCRAZYUpstairsBedroom_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNCRAZYUpstairsBedroom_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNCRAZYUpstairsBedroom_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNCRAZYUpstairsBedroom_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNCRAZYUpstairsBedroom_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNCRAZYUpstairsBedroom_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNCRAZYUpstairsBedroom_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNCRAZYUpstairsBedroom_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNCRAZYUpstairsBedroom_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNCRAZYUpstairsBedroom_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNCRAZYUpstairsBathroom:
		  {
			   HARDWARE_map_width_tiles=32;
			   HARDWARE_map_height_tiles=32;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNCRAZYUpstairsBathroom_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNCRAZYUpstairsBathroom_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNCRAZYUpstairsBathroom_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNCRAZYUpstairsBathroom_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNCRAZYUpstairsBathroom_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNCRAZYUpstairsBathroom_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNCRAZYUpstairsBathroom_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNCRAZYUpstairsBathroom_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNCRAZYUpstairsBathroom_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNCRAZYUpstairsBathroom_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNCRAZYUpstairsBathroom_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNCRAZYUpstairsBathroom_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNCRAZYUpstairsBathroom_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNCRAZYUpstairsBathroom_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNCRAZYUpstairsBathroom_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNCRAZYUpstairsBathroom_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNCRAZYUpstairsBathroom_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNCRAZYUpstairsBathroom_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNCRAZYUpstairsBathroom_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNCRAZYUpstairsBathroom_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNCRAZYDownstairsBathroom:
		  {
			   HARDWARE_map_width_tiles=32;
			   HARDWARE_map_height_tiles=32;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNCRAZYDownstairsBathroom_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNCRAZYDownstairsBathroom_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNCRAZYDownstairsBathroom_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNCRAZYDownstairsBathroom_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNCRAZYDownstairsBathroom_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNCRAZYDownstairsBathroom_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNCRAZYDownstairsBathroom_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNCRAZYDownstairsBathroom_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNCRAZYDownstairsBathroom_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNCRAZYDownstairsBathroom_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNCRAZYDownstairsBathroom_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNCRAZYDownstairsBathroom_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNCRAZYDownstairsBathroom_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNCRAZYDownstairsBathroom_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNCRAZYDownstairsBathroom_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNCRAZYDownstairsBathroom_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNCRAZYDownstairsBathroom_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNCRAZYDownstairsBathroom_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNCRAZYDownstairsBathroom_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNCRAZYDownstairsBathroom_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNCRAZYBasement:
		  {
			   HARDWARE_map_width_tiles=48;
			   HARDWARE_map_height_tiles=37;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNCRAZYBasement_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNCRAZYBasement_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNCRAZYBasement_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNCRAZYBasement_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNCRAZYBasement_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNCRAZYBasement_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNCRAZYBasement_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNCRAZYBasement_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNCRAZYBasement_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNCRAZYBasement_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNCRAZYBasement_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNCRAZYBasement_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNCRAZYBasement_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNCRAZYBasement_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNCRAZYBasement_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNCRAZYBasement_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNCRAZYBasement_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNCRAZYBasement_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNCRAZYBasement_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNCRAZYBasement_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNCRAZYGarage:
		  {
			   HARDWARE_map_width_tiles=32;
			   HARDWARE_map_height_tiles=32;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNCRAZYGarage_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNCRAZYGarage_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNCRAZYGarage_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNCRAZYGarage_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNCRAZYGarage_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNCRAZYGarage_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNCRAZYGarage_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNCRAZYGarage_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNCRAZYGarage_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNCRAZYGarage_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNCRAZYGarage_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNCRAZYGarage_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNCRAZYGarage_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNCRAZYGarage_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNCRAZYGarage_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNCRAZYGarage_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNCRAZYGarage_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNCRAZYGarage_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNCRAZYGarage_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNCRAZYGarage_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNCRAZYUpstairsHidden:
		  {
			   HARDWARE_map_width_tiles=32;
			   HARDWARE_map_height_tiles=42;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNCRAZYUpstairsHidden_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNCRAZYUpstairsHidden_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNCRAZYUpstairsHidden_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNCRAZYUpstairsHidden_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNCRAZYUpstairsHidden_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNCRAZYUpstairsHidden_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNCRAZYUpstairsHidden_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNCRAZYUpstairsHidden_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNCRAZYUpstairsHidden_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNCRAZYUpstairsHidden_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNCRAZYUpstairsHidden_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNCRAZYUpstairsHidden_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNCRAZYUpstairsHidden_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNCRAZYUpstairsHidden_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNCRAZYUpstairsHidden_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNCRAZYUpstairsHidden_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNCRAZYUpstairsHidden_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNCRAZYUpstairsHidden_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNCRAZYUpstairsHidden_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNCRAZYUpstairsHidden_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_SCHOOLMainOffice:
		  {
			   HARDWARE_map_width_tiles=32;
			   HARDWARE_map_height_tiles=32;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/school/SCHOOLMainOffice_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/school/SCHOOLMainOffice_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/school/SCHOOLMainOffice_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/school/SCHOOLMainOffice_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/school/SCHOOLMainOffice_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/school/SCHOOLMainOffice_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_SCHOOLMainOffice_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_SCHOOLMainOffice_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_SCHOOLMainOffice_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_SCHOOLMainOffice_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_SCHOOLMainOffice_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/school/SCHOOLMainOffice_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_SCHOOLMainOffice_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_SCHOOLMainOffice_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_SCHOOLMainOffice_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_SCHOOLMainOffice_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_SCHOOLMainOffice_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_SCHOOLMainOffice_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLMainOffice_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLMainOffice_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_SCHOOLPrincipalsOffice:
		  {
			   HARDWARE_map_width_tiles=32;
			   HARDWARE_map_height_tiles=32;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/school/SCHOOLPrincipalsOffice_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/school/SCHOOLPrincipalsOffice_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/school/SCHOOLPrincipalsOffice_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/school/SCHOOLPrincipalsOffice_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/school/SCHOOLPrincipalsOffice_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/school/SCHOOLPrincipalsOffice_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_SCHOOLPrincipalsOffice_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_SCHOOLPrincipalsOffice_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_SCHOOLPrincipalsOffice_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_SCHOOLPrincipalsOffice_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_SCHOOLPrincipalsOffice_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/school/SCHOOLPrincipalsOffice_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_SCHOOLPrincipalsOffice_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_SCHOOLPrincipalsOffice_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_SCHOOLPrincipalsOffice_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_SCHOOLPrincipalsOffice_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_SCHOOLPrincipalsOffice_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_SCHOOLPrincipalsOffice_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLPrincipalsOffice_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLPrincipalsOffice_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_SCHOOLDetention:
		  {
			   HARDWARE_map_width_tiles=32;
			   HARDWARE_map_height_tiles=32;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/school/SCHOOLDetention_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/school/SCHOOLDetention_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/school/SCHOOLDetention_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/school/SCHOOLDetention_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/school/SCHOOLDetention_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/school/SCHOOLDetention_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_SCHOOLDetention_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_SCHOOLDetention_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_SCHOOLDetention_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_SCHOOLDetention_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_SCHOOLDetention_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/school/SCHOOLDetention_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_SCHOOLDetention_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_SCHOOLDetention_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_SCHOOLDetention_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_SCHOOLDetention_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_SCHOOLDetention_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_SCHOOLDetention_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLDetention_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLDetention_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_SCHOOLClinic:
		  {
			   HARDWARE_map_width_tiles=40;
			   HARDWARE_map_height_tiles=32;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/school/SCHOOLClinic_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/school/SCHOOLClinic_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/school/SCHOOLClinic_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/school/SCHOOLClinic_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/school/SCHOOLClinic_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/school/SCHOOLClinic_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_SCHOOLClinic_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_SCHOOLClinic_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_SCHOOLClinic_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_SCHOOLClinic_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_SCHOOLClinic_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/school/SCHOOLClinic_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_SCHOOLClinic_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_SCHOOLClinic_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_SCHOOLClinic_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_SCHOOLClinic_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_SCHOOLClinic_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_SCHOOLClinic_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLClinic_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLClinic_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_SCHOOLClinicBathroom:
		  {
			   HARDWARE_map_width_tiles=32;
			   HARDWARE_map_height_tiles=32;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/school/SCHOOLClinicBathroom_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/school/SCHOOLClinicBathroom_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/school/SCHOOLClinicBathroom_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/school/SCHOOLClinicBathroom_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/school/SCHOOLClinicBathroom_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/school/SCHOOLClinicBathroom_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_SCHOOLClinicBathroom_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_SCHOOLClinicBathroom_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_SCHOOLClinicBathroom_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_SCHOOLClinicBathroom_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_SCHOOLClinicBathroom_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/school/SCHOOLClinicBathroom_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_SCHOOLClinicBathroom_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_SCHOOLClinicBathroom_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_SCHOOLClinicBathroom_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_SCHOOLClinicBathroom_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_SCHOOLClinicBathroom_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_SCHOOLClinicBathroom_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLClinicBathroom_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLClinicBathroom_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_SCHOOLTeachersLounge:
		  {
			   HARDWARE_map_width_tiles=40;
			   HARDWARE_map_height_tiles=32;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/school/SCHOOLTeachersLounge_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/school/SCHOOLTeachersLounge_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/school/SCHOOLTeachersLounge_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/school/SCHOOLTeachersLounge_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/school/SCHOOLTeachersLounge_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/school/SCHOOLTeachersLounge_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_SCHOOLTeachersLounge_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_SCHOOLTeachersLounge_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_SCHOOLTeachersLounge_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_SCHOOLTeachersLounge_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_SCHOOLTeachersLounge_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/school/SCHOOLTeachersLounge_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_SCHOOLTeachersLounge_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_SCHOOLTeachersLounge_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_SCHOOLTeachersLounge_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_SCHOOLTeachersLounge_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_SCHOOLTeachersLounge_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_SCHOOLTeachersLounge_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLTeachersLounge_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLTeachersLounge_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_SCHOOLMusicRoom:
		  {
			   HARDWARE_map_width_tiles=43;
			   HARDWARE_map_height_tiles=42;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/school/SCHOOLMusicRoom_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/school/SCHOOLMusicRoom_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/school/SCHOOLMusicRoom_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/school/SCHOOLMusicRoom_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/school/SCHOOLMusicRoom_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/school/SCHOOLMusicRoom_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_SCHOOLMusicRoom_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_SCHOOLMusicRoom_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_SCHOOLMusicRoom_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_SCHOOLMusicRoom_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_SCHOOLMusicRoom_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/school/SCHOOLMusicRoom_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_SCHOOLMusicRoom_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_SCHOOLMusicRoom_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_SCHOOLMusicRoom_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_SCHOOLMusicRoom_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_SCHOOLMusicRoom_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_SCHOOLMusicRoom_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLMusicRoom_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLMusicRoom_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_SCHOOLArtRoom:
		  {
			   HARDWARE_map_width_tiles=43;
			   HARDWARE_map_height_tiles=42;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/school/SCHOOLArtRoom_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/school/SCHOOLArtRoom_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/school/SCHOOLArtRoom_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/school/SCHOOLArtRoom_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/school/SCHOOLArtRoom_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/school/SCHOOLArtRoom_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_SCHOOLArtRoom_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_SCHOOLArtRoom_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_SCHOOLArtRoom_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_SCHOOLArtRoom_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_SCHOOLArtRoom_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/school/SCHOOLArtRoom_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_SCHOOLArtRoom_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_SCHOOLArtRoom_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_SCHOOLArtRoom_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_SCHOOLArtRoom_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_SCHOOLArtRoom_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_SCHOOLArtRoom_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLArtRoom_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLArtRoom_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_SCHOOLComputerLab:
		  {
			   HARDWARE_map_width_tiles=43;
			   HARDWARE_map_height_tiles=42;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/school/SCHOOLComputerLab_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/school/SCHOOLComputerLab_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/school/SCHOOLComputerLab_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/school/SCHOOLComputerLab_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/school/SCHOOLComputerLab_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/school/SCHOOLComputerLab_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_SCHOOLComputerLab_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_SCHOOLComputerLab_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_SCHOOLComputerLab_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_SCHOOLComputerLab_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_SCHOOLComputerLab_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/school/SCHOOLComputerLab_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_SCHOOLComputerLab_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_SCHOOLComputerLab_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_SCHOOLComputerLab_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_SCHOOLComputerLab_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_SCHOOLComputerLab_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_SCHOOLComputerLab_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLComputerLab_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLComputerLab_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_SCHOOLKitchen:
		  {
			   HARDWARE_map_width_tiles=40;
			   HARDWARE_map_height_tiles=42;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/school/SCHOOLKitchen_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/school/SCHOOLKitchen_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/school/SCHOOLKitchen_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/school/SCHOOLKitchen_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/school/SCHOOLKitchen_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/school/SCHOOLKitchen_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_SCHOOLKitchen_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_SCHOOLKitchen_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_SCHOOLKitchen_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_SCHOOLKitchen_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_SCHOOLKitchen_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/school/SCHOOLKitchen_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_SCHOOLKitchen_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_SCHOOLKitchen_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_SCHOOLKitchen_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_SCHOOLKitchen_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_SCHOOLKitchen_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_SCHOOLKitchen_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLKitchen_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLKitchen_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_SCHOOLLibrary:
		  {
			   HARDWARE_map_width_tiles=50;
			   HARDWARE_map_height_tiles=42;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/school/SCHOOLLibrary_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/school/SCHOOLLibrary_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/school/SCHOOLLibrary_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/school/SCHOOLLibrary_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/school/SCHOOLLibrary_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/school/SCHOOLLibrary_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_SCHOOLLibrary_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_SCHOOLLibrary_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_SCHOOLLibrary_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_SCHOOLLibrary_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_SCHOOLLibrary_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/school/SCHOOLLibrary_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_SCHOOLLibrary_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_SCHOOLLibrary_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_SCHOOLLibrary_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_SCHOOLLibrary_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_SCHOOLLibrary_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_SCHOOLLibrary_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLLibrary_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLLibrary_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_SCHOOLCustodian:
		  {
			   HARDWARE_map_width_tiles=32;
			   HARDWARE_map_height_tiles=47;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/school/SCHOOLCustodian_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/school/SCHOOLCustodian_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/school/SCHOOLCustodian_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/school/SCHOOLCustodian_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/school/SCHOOLCustodian_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/school/SCHOOLCustodian_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_SCHOOLCustodian_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_SCHOOLCustodian_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_SCHOOLCustodian_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_SCHOOLCustodian_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_SCHOOLCustodian_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/school/SCHOOLCustodian_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_SCHOOLCustodian_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_SCHOOLCustodian_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_SCHOOLCustodian_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_SCHOOLCustodian_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_SCHOOLCustodian_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_SCHOOLCustodian_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLCustodian_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLCustodian_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_SCHOOLGirlsBathroom:
		  {
			   HARDWARE_map_width_tiles=32;
			   HARDWARE_map_height_tiles=42;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/school/SCHOOLGirlsBathroom_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/school/SCHOOLGirlsBathroom_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/school/SCHOOLGirlsBathroom_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/school/SCHOOLGirlsBathroom_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/school/SCHOOLGirlsBathroom_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/school/SCHOOLGirlsBathroom_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_SCHOOLGirlsBathroom_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_SCHOOLGirlsBathroom_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_SCHOOLGirlsBathroom_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_SCHOOLGirlsBathroom_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_SCHOOLGirlsBathroom_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/school/SCHOOLGirlsBathroom_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_SCHOOLGirlsBathroom_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_SCHOOLGirlsBathroom_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_SCHOOLGirlsBathroom_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_SCHOOLGirlsBathroom_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_SCHOOLGirlsBathroom_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_SCHOOLGirlsBathroom_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLGirlsBathroom_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLGirlsBathroom_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_SCHOOLBoysBathroom:
		  {
			   HARDWARE_map_width_tiles=32;
			   HARDWARE_map_height_tiles=42;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/school/SCHOOLBoysBathroom_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/school/SCHOOLBoysBathroom_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/school/SCHOOLBoysBathroom_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/school/SCHOOLBoysBathroom_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/school/SCHOOLBoysBathroom_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/school/SCHOOLBoysBathroom_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_SCHOOLBoysBathroom_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_SCHOOLBoysBathroom_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_SCHOOLBoysBathroom_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_SCHOOLBoysBathroom_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_SCHOOLBoysBathroom_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/school/SCHOOLBoysBathroom_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_SCHOOLBoysBathroom_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_SCHOOLBoysBathroom_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_SCHOOLBoysBathroom_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_SCHOOLBoysBathroom_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_SCHOOLBoysBathroom_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_SCHOOLBoysBathroom_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLBoysBathroom_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLBoysBathroom_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_SCHOOLEntranceHallway:
		  {
			   HARDWARE_map_width_tiles=208;
			   HARDWARE_map_height_tiles=50;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/school/SCHOOLEntranceHallway_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/school/SCHOOLEntranceHallway_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/school/SCHOOLEntranceHallway_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/school/SCHOOLEntranceHallway_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/school/SCHOOLEntranceHallway_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/school/SCHOOLEntranceHallway_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_SCHOOLEntranceHallway_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_SCHOOLEntranceHallway_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_SCHOOLEntranceHallway_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_SCHOOLEntranceHallway_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_SCHOOLEntranceHallway_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/school/SCHOOLEntranceHallway_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_SCHOOLEntranceHallway_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_SCHOOLEntranceHallway_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_SCHOOLEntranceHallway_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_SCHOOLEntranceHallway_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_SCHOOLEntranceHallway_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_SCHOOLEntranceHallway_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLEntranceHallway_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLEntranceHallway_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_SCHOOLGymHallway:
		  {
			   HARDWARE_map_width_tiles=208;
			   HARDWARE_map_height_tiles=57;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/school/SCHOOLGymHallway_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/school/SCHOOLGymHallway_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/school/SCHOOLGymHallway_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/school/SCHOOLGymHallway_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/school/SCHOOLGymHallway_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/school/SCHOOLGymHallway_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_SCHOOLGymHallway_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_SCHOOLGymHallway_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_SCHOOLGymHallway_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_SCHOOLGymHallway_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_SCHOOLGymHallway_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/school/SCHOOLGymHallway_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_SCHOOLGymHallway_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_SCHOOLGymHallway_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_SCHOOLGymHallway_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_SCHOOLGymHallway_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_SCHOOLGymHallway_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_SCHOOLGymHallway_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLGymHallway_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLGymHallway_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_SCHOOLClassHallway:
		  {
			   HARDWARE_map_width_tiles=208;
			   HARDWARE_map_height_tiles=57;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/school/SCHOOLClassHallway_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/school/SCHOOLClassHallway_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/school/SCHOOLClassHallway_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/school/SCHOOLClassHallway_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/school/SCHOOLClassHallway_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/school/SCHOOLClassHallway_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_SCHOOLClassHallway_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_SCHOOLClassHallway_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_SCHOOLClassHallway_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_SCHOOLClassHallway_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_SCHOOLClassHallway_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/school/SCHOOLClassHallway_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_SCHOOLClassHallway_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_SCHOOLClassHallway_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_SCHOOLClassHallway_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_SCHOOLClassHallway_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_SCHOOLClassHallway_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_SCHOOLClassHallway_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLClassHallway_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLClassHallway_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_SCHOOLBackHallway:
		  {
			   HARDWARE_map_width_tiles=208;
			   HARDWARE_map_height_tiles=57;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/school/SCHOOLBackHallway_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/school/SCHOOLBackHallway_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/school/SCHOOLBackHallway_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/school/SCHOOLBackHallway_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/school/SCHOOLBackHallway_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/school/SCHOOLBackHallway_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_SCHOOLBackHallway_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_SCHOOLBackHallway_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_SCHOOLBackHallway_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_SCHOOLBackHallway_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_SCHOOLBackHallway_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/school/SCHOOLBackHallway_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_SCHOOLBackHallway_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_SCHOOLBackHallway_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_SCHOOLBackHallway_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_SCHOOLBackHallway_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_SCHOOLBackHallway_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_SCHOOLBackHallway_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLBackHallway_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLBackHallway_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_SCHOOLClassroom1:
		  {
			   HARDWARE_map_width_tiles=43;
			   HARDWARE_map_height_tiles=42;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/school/SCHOOLClassroom1_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/school/SCHOOLClassroom1_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/school/SCHOOLClassroom1_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/school/SCHOOLClassroom1_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/school/SCHOOLClassroom1_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/school/SCHOOLClassroom1_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_SCHOOLClassroom1_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_SCHOOLClassroom1_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_SCHOOLClassroom1_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_SCHOOLClassroom1_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_SCHOOLClassroom1_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/school/SCHOOLClassroom1_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_SCHOOLClassroom1_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_SCHOOLClassroom1_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_SCHOOLClassroom1_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_SCHOOLClassroom1_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_SCHOOLClassroom1_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_SCHOOLClassroom1_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLClassroom1_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLClassroom1_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_SCHOOLClassroom2:
		  {
			   HARDWARE_map_width_tiles=43;
			   HARDWARE_map_height_tiles=42;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/school/SCHOOLClassroom2_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/school/SCHOOLClassroom2_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/school/SCHOOLClassroom2_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/school/SCHOOLClassroom2_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/school/SCHOOLClassroom2_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/school/SCHOOLClassroom2_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_SCHOOLClassroom2_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_SCHOOLClassroom2_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_SCHOOLClassroom2_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_SCHOOLClassroom2_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_SCHOOLClassroom2_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/school/SCHOOLClassroom2_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_SCHOOLClassroom2_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_SCHOOLClassroom2_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_SCHOOLClassroom2_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_SCHOOLClassroom2_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_SCHOOLClassroom2_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_SCHOOLClassroom2_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLClassroom2_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLClassroom2_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_SCHOOLClassroom3:
		  {
			   HARDWARE_map_width_tiles=43;
			   HARDWARE_map_height_tiles=42;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/school/SCHOOLClassroom3_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/school/SCHOOLClassroom3_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/school/SCHOOLClassroom3_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/school/SCHOOLClassroom3_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/school/SCHOOLClassroom3_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/school/SCHOOLClassroom3_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_SCHOOLClassroom3_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_SCHOOLClassroom3_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_SCHOOLClassroom3_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_SCHOOLClassroom3_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_SCHOOLClassroom3_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/school/SCHOOLClassroom3_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_SCHOOLClassroom3_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_SCHOOLClassroom3_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_SCHOOLClassroom3_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_SCHOOLClassroom3_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_SCHOOLClassroom3_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_SCHOOLClassroom3_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLClassroom3_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLClassroom3_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_SCHOOLClassroom4:
		  {
			   HARDWARE_map_width_tiles=43;
			   HARDWARE_map_height_tiles=42;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/school/SCHOOLClassroom4_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/school/SCHOOLClassroom4_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/school/SCHOOLClassroom4_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/school/SCHOOLClassroom4_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/school/SCHOOLClassroom4_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/school/SCHOOLClassroom4_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_SCHOOLClassroom4_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_SCHOOLClassroom4_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_SCHOOLClassroom4_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_SCHOOLClassroom4_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_SCHOOLClassroom4_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/school/SCHOOLClassroom4_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_SCHOOLClassroom4_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_SCHOOLClassroom4_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_SCHOOLClassroom4_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_SCHOOLClassroom4_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_SCHOOLClassroom4_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_SCHOOLClassroom4_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLClassroom4_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLClassroom4_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_SCHOOLClassroom5:
		  {
			   HARDWARE_map_width_tiles=43;
			   HARDWARE_map_height_tiles=42;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/school/SCHOOLClassroom5_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/school/SCHOOLClassroom5_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/school/SCHOOLClassroom5_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/school/SCHOOLClassroom5_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/school/SCHOOLClassroom5_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/school/SCHOOLClassroom5_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_SCHOOLClassroom5_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_SCHOOLClassroom5_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_SCHOOLClassroom5_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_SCHOOLClassroom5_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_SCHOOLClassroom5_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/school/SCHOOLClassroom5_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_SCHOOLClassroom5_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_SCHOOLClassroom5_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_SCHOOLClassroom5_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_SCHOOLClassroom5_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_SCHOOLClassroom5_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_SCHOOLClassroom5_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLClassroom5_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLClassroom5_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_SCHOOLClassroom6:
		  {
			   HARDWARE_map_width_tiles=43;
			   HARDWARE_map_height_tiles=42;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/school/SCHOOLClassroom6_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/school/SCHOOLClassroom6_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/school/SCHOOLClassroom6_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/school/SCHOOLClassroom6_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/school/SCHOOLClassroom6_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/school/SCHOOLClassroom6_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_SCHOOLClassroom6_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_SCHOOLClassroom6_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_SCHOOLClassroom6_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_SCHOOLClassroom6_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_SCHOOLClassroom6_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/school/SCHOOLClassroom6_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_SCHOOLClassroom6_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_SCHOOLClassroom6_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_SCHOOLClassroom6_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_SCHOOLClassroom6_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_SCHOOLClassroom6_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_SCHOOLClassroom6_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLClassroom6_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLClassroom6_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_SCHOOLGymCafeteria:
		  {
			   HARDWARE_map_width_tiles=53;
			   HARDWARE_map_height_tiles=57;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/school/SCHOOLGymCafeteria_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/school/SCHOOLGymCafeteria_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/school/SCHOOLGymCafeteria_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/school/SCHOOLGymCafeteria_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/school/SCHOOLGymCafeteria_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/school/SCHOOLGymCafeteria_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_SCHOOLGymCafeteria_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_SCHOOLGymCafeteria_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_SCHOOLGymCafeteria_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_SCHOOLGymCafeteria_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_SCHOOLGymCafeteria_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/school/SCHOOLGymCafeteria_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_SCHOOLGymCafeteria_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_SCHOOLGymCafeteria_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_SCHOOLGymCafeteria_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_SCHOOLGymCafeteria_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_SCHOOLGymCafeteria_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_SCHOOLGymCafeteria_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLGymCafeteria_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLGymCafeteria_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_SCHOOLGymGym:
		  {
			   HARDWARE_map_width_tiles=53;
			   HARDWARE_map_height_tiles=57;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/school/SCHOOLGymGym_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/school/SCHOOLGymGym_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/school/SCHOOLGymGym_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/school/SCHOOLGymGym_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/school/SCHOOLGymGym_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/school/SCHOOLGymGym_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_SCHOOLGymGym_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_SCHOOLGymGym_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_SCHOOLGymGym_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_SCHOOLGymGym_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_SCHOOLGymGym_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/school/SCHOOLGymGym_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_SCHOOLGymGym_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_SCHOOLGymGym_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_SCHOOLGymGym_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_SCHOOLGymGym_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_SCHOOLGymGym_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_SCHOOLGymGym_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLGymGym_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLGymGym_TouchMap_1_Tiles.bin");
			   break;
		  }





















		  case MAP_bobsgame_TOWNCoffeeShop:
		  {
			   HARDWARE_map_width_tiles=34;
			   HARDWARE_map_height_tiles=68;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNCoffeeShop_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNCoffeeShop_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNCoffeeShop_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNCoffeeShop_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNCoffeeShop_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNCoffeeShop_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNCoffeeShop_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNCoffeeShop_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNCoffeeShop_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNCoffeeShop_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNCoffeeShop_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNCoffeeShop_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNCoffeeShop_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNCoffeeShop_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNCoffeeShop_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNCoffeeShop_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNCoffeeShop_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNCoffeeShop_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNCoffeeShop_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNCoffeeShop_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNPizzaPlace:
		  {
			   HARDWARE_map_width_tiles=38;
			   HARDWARE_map_height_tiles=33;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNPizzaPlace_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNPizzaPlace_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNPizzaPlace_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNPizzaPlace_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNPizzaPlace_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNPizzaPlace_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNPizzaPlace_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNPizzaPlace_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNPizzaPlace_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNPizzaPlace_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNPizzaPlace_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNPizzaPlace_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNPizzaPlace_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNPizzaPlace_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNPizzaPlace_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNPizzaPlace_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNPizzaPlace_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNPizzaPlace_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNPizzaPlace_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNPizzaPlace_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNBookstore:
		  {
			   HARDWARE_map_width_tiles=32;
			   HARDWARE_map_height_tiles=52;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNBookstore_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNBookstore_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNBookstore_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNBookstore_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNBookstore_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNBookstore_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNBookstore_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNBookstore_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNBookstore_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNBookstore_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNBookstore_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNBookstore_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNBookstore_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNBookstore_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNBookstore_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNBookstore_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNBookstore_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNBookstore_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNBookstore_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNBookstore_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNBookstoreBathroom:
		  {
			   HARDWARE_map_width_tiles=32;
			   HARDWARE_map_height_tiles=32;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNBookstoreBathroom_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNBookstoreBathroom_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNBookstoreBathroom_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNBookstoreBathroom_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNBookstoreBathroom_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNBookstoreBathroom_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNBookstoreBathroom_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNBookstoreBathroom_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNBookstoreBathroom_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNBookstoreBathroom_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNBookstoreBathroom_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNBookstoreBathroom_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNBookstoreBathroom_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNBookstoreBathroom_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNBookstoreBathroom_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNBookstoreBathroom_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNBookstoreBathroom_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNBookstoreBathroom_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNBookstoreBathroom_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNBookstoreBathroom_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNVideoRent:
		  {
			   HARDWARE_map_width_tiles=41;
			   HARDWARE_map_height_tiles=38;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNVideoRent_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNVideoRent_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNVideoRent_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNVideoRent_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNVideoRent_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNVideoRent_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNVideoRent_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNVideoRent_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNVideoRent_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNVideoRent_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNVideoRent_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNVideoRent_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNVideoRent_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNVideoRent_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNVideoRent_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNVideoRent_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNVideoRent_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNVideoRent_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNVideoRent_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNVideoRent_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNVideoRentAdultRoom:
		  {
			   HARDWARE_map_width_tiles=32;
			   HARDWARE_map_height_tiles=32;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNVideoRentAdultRoom_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNVideoRentAdultRoom_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNVideoRentAdultRoom_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNVideoRentAdultRoom_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNVideoRentAdultRoom_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNVideoRentAdultRoom_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNVideoRentAdultRoom_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNVideoRentAdultRoom_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNVideoRentAdultRoom_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNVideoRentAdultRoom_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNVideoRentAdultRoom_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNVideoRentAdultRoom_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNVideoRentAdultRoom_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNVideoRentAdultRoom_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNVideoRentAdultRoom_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNVideoRentAdultRoom_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNVideoRentAdultRoom_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNVideoRentAdultRoom_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNVideoRentAdultRoom_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNVideoRentAdultRoom_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNRecordStore:
		  {
			   HARDWARE_map_width_tiles=41;
			   HARDWARE_map_height_tiles=48;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNRecordStore_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNRecordStore_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNRecordStore_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNRecordStore_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNRecordStore_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNRecordStore_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNRecordStore_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNRecordStore_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNRecordStore_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNRecordStore_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNRecordStore_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNRecordStore_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNRecordStore_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNRecordStore_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNRecordStore_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNRecordStore_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNRecordStore_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNRecordStore_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNRecordStore_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNRecordStore_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNPets4Less:
		  {
			   HARDWARE_map_width_tiles=32;
			   HARDWARE_map_height_tiles=53;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNPets4Less_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNPets4Less_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNPets4Less_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNPets4Less_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNPets4Less_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNPets4Less_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNPets4Less_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNPets4Less_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNPets4Less_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNPets4Less_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNPets4Less_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNPets4Less_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNPets4Less_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNPets4Less_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNPets4Less_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNPets4Less_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNPets4Less_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNPets4Less_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNPets4Less_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNPets4Less_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNElectronicsStore:
		  {
			   HARDWARE_map_width_tiles=40;
			   HARDWARE_map_height_tiles=53;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNElectronicsStore_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNElectronicsStore_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNElectronicsStore_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNElectronicsStore_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNElectronicsStore_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNElectronicsStore_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNElectronicsStore_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNElectronicsStore_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNElectronicsStore_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNElectronicsStore_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNElectronicsStore_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNElectronicsStore_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNElectronicsStore_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNElectronicsStore_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNElectronicsStore_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNElectronicsStore_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNElectronicsStore_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNElectronicsStore_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNElectronicsStore_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNElectronicsStore_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNElectronicsStoreBackRoom:
		  {
			   HARDWARE_map_width_tiles=32;
			   HARDWARE_map_height_tiles=32;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNElectronicsStoreBackRoom_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNElectronicsStoreBackRoom_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNElectronicsStoreBackRoom_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNElectronicsStoreBackRoom_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNElectronicsStoreBackRoom_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNElectronicsStoreBackRoom_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNElectronicsStoreBackRoom_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNElectronicsStoreBackRoom_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNElectronicsStoreBackRoom_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNElectronicsStoreBackRoom_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNElectronicsStoreBackRoom_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNElectronicsStoreBackRoom_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNElectronicsStoreBackRoom_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNElectronicsStoreBackRoom_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNElectronicsStoreBackRoom_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNElectronicsStoreBackRoom_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNElectronicsStoreBackRoom_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNElectronicsStoreBackRoom_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNElectronicsStoreBackRoom_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNElectronicsStoreBackRoom_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNBeautySalon:
		  {
			   HARDWARE_map_width_tiles=42;
			   HARDWARE_map_height_tiles=42;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNBeautySalon_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNBeautySalon_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNBeautySalon_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNBeautySalon_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNBeautySalon_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNBeautySalon_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNBeautySalon_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNBeautySalon_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNBeautySalon_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNBeautySalon_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNBeautySalon_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNBeautySalon_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNBeautySalon_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNBeautySalon_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNBeautySalon_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNBeautySalon_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNBeautySalon_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNBeautySalon_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNBeautySalon_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNBeautySalon_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNBeautySalonTanningRoom:
		  {
			   HARDWARE_map_width_tiles=32;
			   HARDWARE_map_height_tiles=32;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNBeautySalonTanningRoom_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNBeautySalonTanningRoom_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNBeautySalonTanningRoom_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNBeautySalonTanningRoom_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNBeautySalonTanningRoom_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNBeautySalonTanningRoom_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNBeautySalonTanningRoom_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNBeautySalonTanningRoom_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNBeautySalonTanningRoom_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNBeautySalonTanningRoom_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNBeautySalonTanningRoom_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNBeautySalonTanningRoom_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNBeautySalonTanningRoom_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNBeautySalonTanningRoom_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNBeautySalonTanningRoom_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNBeautySalonTanningRoom_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNBeautySalonTanningRoom_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNBeautySalonTanningRoom_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNBeautySalonTanningRoom_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNBeautySalonTanningRoom_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNArcade:
		  {
			   HARDWARE_map_width_tiles=90;
			   HARDWARE_map_height_tiles=33;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNArcade_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNArcade_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNArcade_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNArcade_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNArcade_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNArcade_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNArcade_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNArcade_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNArcade_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNArcade_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNArcade_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNArcade_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNArcade_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNArcade_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNArcade_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNArcade_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNArcade_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNArcade_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNArcade_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNArcade_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNGroceryStore:
		  {
			   HARDWARE_map_width_tiles=112;
			   HARDWARE_map_height_tiles=90;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNGroceryStore_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNGroceryStore_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNGroceryStore_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNGroceryStore_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNGroceryStore_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNGroceryStore_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNGroceryStore_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNGroceryStore_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNGroceryStore_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNGroceryStore_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNGroceryStore_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNGroceryStore_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNGroceryStore_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNGroceryStore_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNGroceryStore_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNGroceryStore_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNGroceryStore_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNGroceryStore_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNGroceryStore_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNGroceryStore_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNGasStation:
		  {
			   HARDWARE_map_width_tiles=57;
			   HARDWARE_map_height_tiles=43;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNGasStation_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNGasStation_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNGasStation_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNGasStation_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNGasStation_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNGasStation_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNGasStation_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNGasStation_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNGasStation_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNGasStation_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNGasStation_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNGasStation_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNGasStation_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNGasStation_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNGasStation_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNGasStation_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNGasStation_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNGasStation_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNGasStation_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNGasStation_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNDepartmentStore:
		  {
			   HARDWARE_map_width_tiles=112;
			   HARDWARE_map_height_tiles=80;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNDepartmentStore_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNDepartmentStore_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNDepartmentStore_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNDepartmentStore_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNDepartmentStore_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNDepartmentStore_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNDepartmentStore_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNDepartmentStore_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNDepartmentStore_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNDepartmentStore_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNDepartmentStore_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNDepartmentStore_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNDepartmentStore_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNDepartmentStore_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNDepartmentStore_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNDepartmentStore_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNDepartmentStore_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNDepartmentStore_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNDepartmentStore_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNDepartmentStore_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNTacoBurger:
		  {
			   HARDWARE_map_width_tiles=38;
			   HARDWARE_map_height_tiles=55;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNTacoBurger_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNTacoBurger_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNTacoBurger_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNTacoBurger_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNTacoBurger_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNTacoBurger_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNTacoBurger_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNTacoBurger_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNTacoBurger_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNTacoBurger_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNTacoBurger_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNTacoBurger_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNTacoBurger_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNTacoBurger_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNTacoBurger_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNTacoBurger_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNTacoBurger_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNTacoBurger_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNTacoBurger_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNTacoBurger_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNChurch:
		  {
			   HARDWARE_map_width_tiles=44;
			   HARDWARE_map_height_tiles=64;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNChurch_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNChurch_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNChurch_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNChurch_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNChurch_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNChurch_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNChurch_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNChurch_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNChurch_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNChurch_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNChurch_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNChurch_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNChurch_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNChurch_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNChurch_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNChurch_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNChurch_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNChurch_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNChurch_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNChurch_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNDoctorsOfficeEntrance:
		  {
			   HARDWARE_map_width_tiles=34;
			   HARDWARE_map_height_tiles=32;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNDoctorsOfficeEntrance_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNDoctorsOfficeEntrance_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNDoctorsOfficeEntrance_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNDoctorsOfficeEntrance_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNDoctorsOfficeEntrance_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNDoctorsOfficeEntrance_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNDoctorsOfficeEntrance_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNDoctorsOfficeEntrance_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNDoctorsOfficeEntrance_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNDoctorsOfficeEntrance_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNDoctorsOfficeEntrance_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNDoctorsOfficeEntrance_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNDoctorsOfficeEntrance_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNDoctorsOfficeEntrance_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNDoctorsOfficeEntrance_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNDoctorsOfficeEntrance_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNDoctorsOfficeEntrance_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNDoctorsOfficeEntrance_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNDoctorsOfficeEntrance_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNDoctorsOfficeEntrance_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNDoctorsOfficeBackHall:
		  {
			   HARDWARE_map_width_tiles=34;
			   HARDWARE_map_height_tiles=32;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNDoctorsOfficeBackHall_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNDoctorsOfficeBackHall_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNDoctorsOfficeBackHall_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNDoctorsOfficeBackHall_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNDoctorsOfficeBackHall_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNDoctorsOfficeBackHall_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNDoctorsOfficeBackHall_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNDoctorsOfficeBackHall_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNDoctorsOfficeBackHall_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNDoctorsOfficeBackHall_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNDoctorsOfficeBackHall_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNDoctorsOfficeBackHall_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNDoctorsOfficeBackHall_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNDoctorsOfficeBackHall_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNDoctorsOfficeBackHall_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNDoctorsOfficeBackHall_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNDoctorsOfficeBackHall_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNDoctorsOfficeBackHall_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNDoctorsOfficeBackHall_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNDoctorsOfficeBackHall_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNDoctorsOfficeBackRoom:
		  {
			   HARDWARE_map_width_tiles=32;
			   HARDWARE_map_height_tiles=32;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNDoctorsOfficeBackRoom_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNDoctorsOfficeBackRoom_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNDoctorsOfficeBackRoom_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNDoctorsOfficeBackRoom_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNDoctorsOfficeBackRoom_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNDoctorsOfficeBackRoom_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNDoctorsOfficeBackRoom_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNDoctorsOfficeBackRoom_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNDoctorsOfficeBackRoom_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNDoctorsOfficeBackRoom_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNDoctorsOfficeBackRoom_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNDoctorsOfficeBackRoom_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNDoctorsOfficeBackRoom_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNDoctorsOfficeBackRoom_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNDoctorsOfficeBackRoom_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNDoctorsOfficeBackRoom_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNDoctorsOfficeBackRoom_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNDoctorsOfficeBackRoom_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNDoctorsOfficeBackRoom_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNDoctorsOfficeBackRoom_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNGameStore:
		  {
			   HARDWARE_map_width_tiles=46;
			   HARDWARE_map_height_tiles=44;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNGameStore_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNGameStore_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNGameStore_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNGameStore_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNGameStore_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNGameStore_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNGameStore_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNGameStore_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNGameStore_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNGameStore_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNGameStore_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNGameStore_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNGameStore_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNGameStore_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNGameStore_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNGameStore_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNGameStore_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNGameStore_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNGameStore_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNGameStore_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNMovieTheatreLobby:
		  {
			   HARDWARE_map_width_tiles=52;
			   HARDWARE_map_height_tiles=35;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNMovieTheatreLobby_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNMovieTheatreLobby_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNMovieTheatreLobby_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNMovieTheatreLobby_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNMovieTheatreLobby_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNMovieTheatreLobby_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNMovieTheatreLobby_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNMovieTheatreLobby_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNMovieTheatreLobby_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNMovieTheatreLobby_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNMovieTheatreLobby_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNMovieTheatreLobby_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNMovieTheatreLobby_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNMovieTheatreLobby_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNMovieTheatreLobby_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNMovieTheatreLobby_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNMovieTheatreLobby_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNMovieTheatreLobby_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNMovieTheatreLobby_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNMovieTheatreLobby_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNMovieTheatreMainHall:
		  {
			   HARDWARE_map_width_tiles=143;
			   HARDWARE_map_height_tiles=51;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNMovieTheatreMainHall_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNMovieTheatreMainHall_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNMovieTheatreMainHall_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNMovieTheatreMainHall_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNMovieTheatreMainHall_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNMovieTheatreMainHall_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNMovieTheatreMainHall_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNMovieTheatreMainHall_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNMovieTheatreMainHall_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNMovieTheatreMainHall_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNMovieTheatreMainHall_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNMovieTheatreMainHall_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNMovieTheatreMainHall_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNMovieTheatreMainHall_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNMovieTheatreMainHall_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNMovieTheatreMainHall_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNMovieTheatreMainHall_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNMovieTheatreMainHall_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNMovieTheatreMainHall_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNMovieTheatreMainHall_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNMovieTheatrePhotoBooth:
		  {
			   HARDWARE_map_width_tiles=32;
			   HARDWARE_map_height_tiles=32;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNMovieTheatrePhotoBooth_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNMovieTheatrePhotoBooth_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNMovieTheatrePhotoBooth_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNMovieTheatrePhotoBooth_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNMovieTheatrePhotoBooth_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNMovieTheatrePhotoBooth_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNMovieTheatrePhotoBooth_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNMovieTheatrePhotoBooth_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNMovieTheatrePhotoBooth_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNMovieTheatrePhotoBooth_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNMovieTheatrePhotoBooth_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNMovieTheatrePhotoBooth_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNMovieTheatrePhotoBooth_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNMovieTheatrePhotoBooth_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNMovieTheatrePhotoBooth_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNMovieTheatrePhotoBooth_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNMovieTheatrePhotoBooth_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNMovieTheatrePhotoBooth_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNMovieTheatrePhotoBooth_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNMovieTheatrePhotoBooth_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNMovieTheatreMensBathroom:
		  {
			   HARDWARE_map_width_tiles=45;
			   HARDWARE_map_height_tiles=32;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNMovieTheatreMensBathroom_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNMovieTheatreMensBathroom_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNMovieTheatreMensBathroom_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNMovieTheatreMensBathroom_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNMovieTheatreMensBathroom_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNMovieTheatreMensBathroom_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNMovieTheatreMensBathroom_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNMovieTheatreMensBathroom_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNMovieTheatreMensBathroom_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNMovieTheatreMensBathroom_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNMovieTheatreMensBathroom_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNMovieTheatreMensBathroom_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNMovieTheatreMensBathroom_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNMovieTheatreMensBathroom_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNMovieTheatreMensBathroom_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNMovieTheatreMensBathroom_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNMovieTheatreMensBathroom_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNMovieTheatreMensBathroom_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNMovieTheatreMensBathroom_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNMovieTheatreMensBathroom_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNMovieTheatreWomensBathroom:
		  {
			   HARDWARE_map_width_tiles=45;
			   HARDWARE_map_height_tiles=32;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNMovieTheatreWomensBathroom_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNMovieTheatreWomensBathroom_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNMovieTheatreWomensBathroom_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNMovieTheatreWomensBathroom_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNMovieTheatreWomensBathroom_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNMovieTheatreWomensBathroom_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNMovieTheatreWomensBathroom_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNMovieTheatreWomensBathroom_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNMovieTheatreWomensBathroom_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNMovieTheatreWomensBathroom_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNMovieTheatreWomensBathroom_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNMovieTheatreWomensBathroom_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNMovieTheatreWomensBathroom_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNMovieTheatreWomensBathroom_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNMovieTheatreWomensBathroom_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNMovieTheatreWomensBathroom_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNMovieTheatreWomensBathroom_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNMovieTheatreWomensBathroom_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNMovieTheatreWomensBathroom_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNMovieTheatreWomensBathroom_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNMovieTheaterBuffer:
		  {
			   HARDWARE_map_width_tiles=68;
			   HARDWARE_map_height_tiles=44;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNMovieTheaterBuffer_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNMovieTheaterBuffer_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNMovieTheaterBuffer_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNMovieTheaterBuffer_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNMovieTheaterBuffer_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNMovieTheaterBuffer_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNMovieTheaterBuffer_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNMovieTheaterBuffer_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNMovieTheaterBuffer_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNMovieTheaterBuffer_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNMovieTheaterBuffer_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNMovieTheaterBuffer_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNMovieTheaterBuffer_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNMovieTheaterBuffer_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNMovieTheaterBuffer_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNMovieTheaterBuffer_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNMovieTheaterBuffer_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNMovieTheaterBuffer_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNMovieTheaterBuffer_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNMovieTheaterBuffer_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_TOWNMovieTheatreInside:
		  {
			   HARDWARE_map_width_tiles=80;
			   HARDWARE_map_height_tiles=88;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNMovieTheatreInside_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNMovieTheatreInside_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNMovieTheatreInside_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNMovieTheatreInside_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNMovieTheatreInside_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNMovieTheatreInside_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNMovieTheatreInside_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNMovieTheatreInside_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNMovieTheatreInside_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNMovieTheatreInside_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNMovieTheatreInside_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNMovieTheatreInside_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNMovieTheatreInside_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNMovieTheatreInside_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNMovieTheatreInside_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNMovieTheatreInside_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNMovieTheatreInside_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNMovieTheatreInside_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNMovieTheatreInside_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNMovieTheatreInside_TouchMap_1_Tiles.bin");
			   break;
		  }






		  case MAP_bobsgame_CITYPartyStore:
		  {
			   HARDWARE_map_width_tiles=57;
			   HARDWARE_map_height_tiles=43;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYPartyStore_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYPartyStore_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYPartyStore_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYPartyStore_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYPartyStore_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYPartyStore_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_CITYPartyStore_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYPartyStore_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYPartyStore_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYPartyStore_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYPartyStore_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYPartyStore_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYPartyStore_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYPartyStore_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYPartyStore_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYPartyStore_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYPartyStore_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYPartyStore_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYPartyStore_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYPartyStore_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_CITYPartyStoreBathroom:
		  {
			   HARDWARE_map_width_tiles=32;
			   HARDWARE_map_height_tiles=32;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYPartyStoreBathroom_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYPartyStoreBathroom_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYPartyStoreBathroom_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYPartyStoreBathroom_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYPartyStoreBathroom_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYPartyStoreBathroom_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_CITYPartyStoreBathroom_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYPartyStoreBathroom_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYPartyStoreBathroom_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYPartyStoreBathroom_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYPartyStoreBathroom_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYPartyStoreBathroom_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYPartyStoreBathroom_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYPartyStoreBathroom_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYPartyStoreBathroom_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYPartyStoreBathroom_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYPartyStoreBathroom_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYPartyStoreBathroom_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYPartyStoreBathroom_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYPartyStoreBathroom_TouchMap_1_Tiles.bin");
			   break;
		  }

		  case MAP_bobsgame_CITYGroovyClubEntrance:
		  {
			   HARDWARE_map_width_tiles=56;
			   HARDWARE_map_height_tiles=32;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYGroovyClubEntrance_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYGroovyClubEntrance_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYGroovyClubEntrance_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYGroovyClubEntrance_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYGroovyClubEntrance_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYGroovyClubEntrance_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_CITYGroovyClubEntrance_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYGroovyClubEntrance_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYGroovyClubEntrance_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYGroovyClubEntrance_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYGroovyClubEntrance_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYGroovyClubEntrance_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYGroovyClubEntrance_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYGroovyClubEntrance_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYGroovyClubEntrance_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYGroovyClubEntrance_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYGroovyClubEntrance_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYGroovyClubEntrance_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYGroovyClubEntrance_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYGroovyClubEntrance_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_CITYGroovyClub:
		  {
			   HARDWARE_map_width_tiles=56;
			   HARDWARE_map_height_tiles=76;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYGroovyClub_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYGroovyClub_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYGroovyClub_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYGroovyClub_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYGroovyClub_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYGroovyClub_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_CITYGroovyClub_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYGroovyClub_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYGroovyClub_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYGroovyClub_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYGroovyClub_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYGroovyClub_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYGroovyClub_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYGroovyClub_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYGroovyClub_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYGroovyClub_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYGroovyClub_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYGroovyClub_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYGroovyClub_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYGroovyClub_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_CITYOfficeEntrance:
		  {
			   HARDWARE_map_width_tiles=66;
			   HARDWARE_map_height_tiles=44;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYOfficeEntrance_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYOfficeEntrance_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYOfficeEntrance_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYOfficeEntrance_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYOfficeEntrance_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYOfficeEntrance_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_CITYOfficeEntrance_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYOfficeEntrance_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYOfficeEntrance_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYOfficeEntrance_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYOfficeEntrance_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYOfficeEntrance_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYOfficeEntrance_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYOfficeEntrance_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYOfficeEntrance_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYOfficeEntrance_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYOfficeEntrance_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYOfficeEntrance_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYOfficeEntrance_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYOfficeEntrance_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_CITYOfficeElevator:
		  {
			   HARDWARE_map_width_tiles=32;
			   HARDWARE_map_height_tiles=32;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYOfficeElevator_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYOfficeElevator_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYOfficeElevator_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYOfficeElevator_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYOfficeElevator_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYOfficeElevator_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_CITYOfficeElevator_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYOfficeElevator_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYOfficeElevator_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYOfficeElevator_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYOfficeElevator_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYOfficeElevator_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYOfficeElevator_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYOfficeElevator_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYOfficeElevator_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYOfficeElevator_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYOfficeElevator_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYOfficeElevator_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYOfficeElevator_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYOfficeElevator_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_CITYOfficeWorkroom:
		  {
			   HARDWARE_map_width_tiles=66;
			   HARDWARE_map_height_tiles=44;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYOfficeWorkroom_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYOfficeWorkroom_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYOfficeWorkroom_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYOfficeWorkroom_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYOfficeWorkroom_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYOfficeWorkroom_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_CITYOfficeWorkroom_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYOfficeWorkroom_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYOfficeWorkroom_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYOfficeWorkroom_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYOfficeWorkroom_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYOfficeWorkroom_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYOfficeWorkroom_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYOfficeWorkroom_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYOfficeWorkroom_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYOfficeWorkroom_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYOfficeWorkroom_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYOfficeWorkroom_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYOfficeWorkroom_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYOfficeWorkroom_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_CITYOfficeBreakRoom:
		  {
			   HARDWARE_map_width_tiles=66;
			   HARDWARE_map_height_tiles=44;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYOfficeBreakRoom_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYOfficeBreakRoom_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYOfficeBreakRoom_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYOfficeBreakRoom_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYOfficeBreakRoom_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYOfficeBreakRoom_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_CITYOfficeBreakRoom_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYOfficeBreakRoom_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYOfficeBreakRoom_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYOfficeBreakRoom_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYOfficeBreakRoom_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYOfficeBreakRoom_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYOfficeBreakRoom_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYOfficeBreakRoom_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYOfficeBreakRoom_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYOfficeBreakRoom_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYOfficeBreakRoom_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYOfficeBreakRoom_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYOfficeBreakRoom_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYOfficeBreakRoom_TouchMap_1_Tiles.bin");
			   break;
		  }
		  case MAP_bobsgame_CITYOfficeBossFloor:
		  {
			   HARDWARE_map_width_tiles=66;
			   HARDWARE_map_height_tiles=44;
			   strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYOfficeBossFloor_Map_0.bin");
			   strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYOfficeBossFloor_Map_1.bin");
			   strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYOfficeBossFloor_Map_2.bin");
			   strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYOfficeBossFloor_Map_3.bin");
			   strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYOfficeBossFloor_Map_Hit.bin");
			   strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYOfficeBossFloor_Map_FX.bin");
			   MAP_current_map_load_function=(void (*) ())&bobsgame_CITYOfficeBossFloor_Map_Load_Function;
			   MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYOfficeBossFloor_Map_Run_Function;
			   MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYOfficeBossFloor_Map_Stop_Function;
			   MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYOfficeBossFloor_Map_VBL_Function;
			   MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYOfficeBossFloor_Map_HBL_Function;
			   strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
			   strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYOfficeBossFloor_Tiles.bin");
			   //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYOfficeBossFloor_TouchMap_302_Pal.bin");
			   //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYOfficeBossFloor_TouchMap_1_Pal.bin");
			   //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYOfficeBossFloor_TouchMap_302_Tiles.bin");
			   //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYOfficeBossFloor_TouchMap_1_Tiles.bin");
			   //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYOfficeBossFloor_TouchMap_302_Map.bin");
			   ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYOfficeBossFloor_TouchMap_1_Map.bin");
			   //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYOfficeBossFloor_TouchMap_302_Tiles.bin");
			   //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYOfficeBossFloor_TouchMap_1_Tiles.bin");
			   break;
		  }




    case MAP_bobsgame_CITYNeighborAptInside:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=35;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYNeighborAptbobsgame_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYNeighborAptbobsgame_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYNeighborAptbobsgame_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYNeighborAptbobsgame_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYNeighborAptbobsgame_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYNeighborAptbobsgame_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYNeighborAptbobsgame_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYNeighborAptbobsgame_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYNeighborAptbobsgame_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYNeighborAptbobsgame_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYNeighborAptbobsgame_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYNeighborAptbobsgame_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYNeighborAptbobsgame_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYNeighborAptbobsgame_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYNeighborAptbobsgame_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYNeighborAptbobsgame_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYNeighborAptbobsgame_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYNeighborAptbobsgame_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYNeighborAptbobsgame_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYNeighborAptbobsgame_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYNeighborsAptBathroom:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYNeighborsAptBathroom_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYNeighborsAptBathroom_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYNeighborsAptBathroom_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYNeighborsAptBathroom_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYNeighborsAptBathroom_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYNeighborsAptBathroom_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYNeighborsAptBathroom_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYNeighborsAptBathroom_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYNeighborsAptBathroom_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYNeighborsAptBathroom_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYNeighborsAptBathroom_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYNeighborsAptBathroom_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYNeighborsAptBathroom_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYNeighborsAptBathroom_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYNeighborsAptBathroom_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYNeighborsAptBathroom_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYNeighborsAptBathroom_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYNeighborsAptBathroom_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYNeighborsAptBathroom_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYNeighborsAptBathroom_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYAptMainOffice:
    {
         HARDWARE_map_width_tiles=72;
         HARDWARE_map_height_tiles=35;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYAptMainOffice_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYAptMainOffice_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYAptMainOffice_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYAptMainOffice_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYAptMainOffice_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYAptMainOffice_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYAptMainOffice_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYAptMainOffice_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYAptMainOffice_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYAptMainOffice_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYAptMainOffice_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYAptMainOffice_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYAptMainOffice_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYAptMainOffice_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYAptMainOffice_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYAptMainOffice_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYAptMainOffice_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYAptMainOffice_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYAptMainOffice_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYAptMainOffice_TouchMap_1_Tiles.bin");
         break;
    }

    case MAP_bobsgame_CITYBankEntrance:
    {
         HARDWARE_map_width_tiles=75;
         HARDWARE_map_height_tiles=43;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYBankEntrance_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYBankEntrance_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYBankEntrance_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYBankEntrance_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYBankEntrance_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYBankEntrance_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYBankEntrance_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYBankEntrance_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYBankEntrance_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYBankEntrance_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYBankEntrance_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYBankEntrance_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYBankEntrance_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYBankEntrance_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYBankEntrance_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYBankEntrance_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYBankEntrance_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYBankEntrance_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYBankEntrance_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYBankEntrance_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYBankElevator:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYBankElevator_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYBankElevator_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYBankElevator_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYBankElevator_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYBankElevator_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYBankElevator_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYBankElevator_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYBankElevator_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYBankElevator_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYBankElevator_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYBankElevator_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYBankElevator_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYBankElevator_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYBankElevator_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYBankElevator_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYBankElevator_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYBankElevator_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYBankElevator_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYBankElevator_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYBankElevator_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYBankOwnerOffice:
    {
         HARDWARE_map_width_tiles=75;
         HARDWARE_map_height_tiles=43;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYBankOwnerOffice_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYBankOwnerOffice_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYBankOwnerOffice_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYBankOwnerOffice_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYBankOwnerOffice_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYBankOwnerOffice_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYBankOwnerOffice_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYBankOwnerOffice_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYBankOwnerOffice_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYBankOwnerOffice_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYBankOwnerOffice_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYBankOwnerOffice_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYBankOwnerOffice_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYBankOwnerOffice_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYBankOwnerOffice_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYBankOwnerOffice_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYBankOwnerOffice_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYBankOwnerOffice_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYBankOwnerOffice_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYBankOwnerOffice_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYFancyRestaurantEntrance:
    {
         HARDWARE_map_width_tiles=43;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYFancyRestaurantEntrance_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYFancyRestaurantEntrance_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYFancyRestaurantEntrance_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYFancyRestaurantEntrance_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYFancyRestaurantEntrance_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYFancyRestaurantEntrance_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYFancyRestaurantEntrance_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYFancyRestaurantEntrance_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYFancyRestaurantEntrance_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYFancyRestaurantEntrance_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYFancyRestaurantEntrance_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYFancyRestaurantEntrance_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYFancyRestaurantEntrance_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYFancyRestaurantEntrance_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYFancyRestaurantEntrance_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYFancyRestaurantEntrance_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYFancyRestaurantEntrance_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYFancyRestaurantEntrance_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYFancyRestaurantEntrance_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYFancyRestaurantEntrance_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYFancyRestaurant:
    {
         HARDWARE_map_width_tiles=58;
         HARDWARE_map_height_tiles=68;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYFancyRestaurant_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYFancyRestaurant_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYFancyRestaurant_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYFancyRestaurant_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYFancyRestaurant_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYFancyRestaurant_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYFancyRestaurant_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYFancyRestaurant_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYFancyRestaurant_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYFancyRestaurant_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYFancyRestaurant_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYFancyRestaurant_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYFancyRestaurant_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYFancyRestaurant_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYFancyRestaurant_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYFancyRestaurant_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYFancyRestaurant_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYFancyRestaurant_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYFancyRestaurant_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYFancyRestaurant_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYFancyRestaurantKitchen:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=33;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYFancyRestaurantKitchen_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYFancyRestaurantKitchen_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYFancyRestaurantKitchen_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYFancyRestaurantKitchen_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYFancyRestaurantKitchen_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYFancyRestaurantKitchen_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYFancyRestaurantKitchen_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYFancyRestaurantKitchen_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYFancyRestaurantKitchen_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYFancyRestaurantKitchen_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYFancyRestaurantKitchen_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYFancyRestaurantKitchen_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYFancyRestaurantKitchen_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYFancyRestaurantKitchen_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYFancyRestaurantKitchen_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYFancyRestaurantKitchen_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYFancyRestaurantKitchen_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYFancyRestaurantKitchen_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYFancyRestaurantKitchen_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYFancyRestaurantKitchen_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYFancyRestaurantKitchenFreezer:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYFancyRestaurantKitchenFreezer_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYFancyRestaurantKitchenFreezer_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYFancyRestaurantKitchenFreezer_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYFancyRestaurantKitchenFreezer_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYFancyRestaurantKitchenFreezer_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYFancyRestaurantKitchenFreezer_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYFancyRestaurantKitchenFreezer_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYFancyRestaurantKitchenFreezer_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYFancyRestaurantKitchenFreezer_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYFancyRestaurantKitchenFreezer_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYFancyRestaurantKitchenFreezer_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYFancyRestaurantKitchenFreezer_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYFancyRestaurantKitchenFreezer_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYFancyRestaurantKitchenFreezer_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYFancyRestaurantKitchenFreezer_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYFancyRestaurantKitchenFreezer_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYFancyRestaurantKitchenFreezer_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYFancyRestaurantKitchenFreezer_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYFancyRestaurantKitchenFreezer_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYFancyRestaurantKitchenFreezer_TouchMap_1_Tiles.bin");
         break;
    }

    case MAP_bobsgame_CITYFashionStore:
    {
         HARDWARE_map_width_tiles=39;
         HARDWARE_map_height_tiles=55;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYFashionStore_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYFashionStore_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYFashionStore_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYFashionStore_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYFashionStore_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYFashionStore_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYFashionStore_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYFashionStore_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYFashionStore_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYFashionStore_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYFashionStore_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYFashionStore_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYFashionStore_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYFashionStore_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYFashionStore_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYFashionStore_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYFashionStore_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYFashionStore_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYFashionStore_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYFashionStore_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYFashionStoreDressingRoom:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYFashionStoreDressingRoom_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYFashionStoreDressingRoom_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYFashionStoreDressingRoom_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYFashionStoreDressingRoom_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYFashionStoreDressingRoom_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYFashionStoreDressingRoom_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYFashionStoreDressingRoom_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYFashionStoreDressingRoom_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYFashionStoreDressingRoom_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYFashionStoreDressingRoom_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYFashionStoreDressingRoom_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYFashionStoreDressingRoom_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYFashionStoreDressingRoom_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYFashionStoreDressingRoom_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYFashionStoreDressingRoom_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYFashionStoreDressingRoom_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYFashionStoreDressingRoom_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYFashionStoreDressingRoom_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYFashionStoreDressingRoom_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYFashionStoreDressingRoom_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYFashionStoreDressingRoom2:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYFashionStoreDressingRoom2_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYFashionStoreDressingRoom2_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYFashionStoreDressingRoom2_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYFashionStoreDressingRoom2_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYFashionStoreDressingRoom2_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYFashionStoreDressingRoom2_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYFashionStoreDressingRoom2_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYFashionStoreDressingRoom2_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYFashionStoreDressingRoom2_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYFashionStoreDressingRoom2_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYFashionStoreDressingRoom2_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYFashionStoreDressingRoom2_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYFashionStoreDressingRoom2_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYFashionStoreDressingRoom2_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYFashionStoreDressingRoom2_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYFashionStoreDressingRoom2_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYFashionStoreDressingRoom2_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYFashionStoreDressingRoom2_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYFashionStoreDressingRoom2_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYFashionStoreDressingRoom2_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYElevatedLifeplace:
    {
         HARDWARE_map_width_tiles=52;
         HARDWARE_map_height_tiles=44;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYElevatedLifeplace_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYElevatedLifeplace_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYElevatedLifeplace_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYElevatedLifeplace_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYElevatedLifeplace_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYElevatedLifeplace_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYElevatedLifeplace_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYElevatedLifeplace_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYElevatedLifeplace_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYElevatedLifeplace_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYElevatedLifeplace_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYElevatedLifeplace_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYElevatedLifeplace_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYElevatedLifeplace_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYElevatedLifeplace_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYElevatedLifeplace_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYElevatedLifeplace_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYElevatedLifeplace_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYElevatedLifeplace_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYElevatedLifeplace_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYElevatedLifeplaceElevator:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYElevatedLifeplaceElevator_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYElevatedLifeplaceElevator_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYElevatedLifeplaceElevator_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYElevatedLifeplaceElevator_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYElevatedLifeplaceElevator_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYElevatedLifeplaceElevator_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYElevatedLifeplaceElevator_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYElevatedLifeplaceElevator_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYElevatedLifeplaceElevator_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYElevatedLifeplaceElevator_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYElevatedLifeplaceElevator_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYElevatedLifeplaceElevator_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYElevatedLifeplaceElevator_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYElevatedLifeplaceElevator_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYElevatedLifeplaceElevator_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYElevatedLifeplaceElevator_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYElevatedLifeplaceElevator_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYElevatedLifeplaceElevator_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYElevatedLifeplaceElevator_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYElevatedLifeplaceElevator_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYElevatedLifeplaceHallway:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYElevatedLifeplaceHallway_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYElevatedLifeplaceHallway_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYElevatedLifeplaceHallway_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYElevatedLifeplaceHallway_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYElevatedLifeplaceHallway_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYElevatedLifeplaceHallway_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYElevatedLifeplaceHallway_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYElevatedLifeplaceHallway_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYElevatedLifeplaceHallway_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYElevatedLifeplaceHallway_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYElevatedLifeplaceHallway_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYElevatedLifeplaceHallway_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYElevatedLifeplaceHallway_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYElevatedLifeplaceHallway_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYElevatedLifeplaceHallway_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYElevatedLifeplaceHallway_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYElevatedLifeplaceHallway_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYElevatedLifeplaceHallway_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYElevatedLifeplaceHallway_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYElevatedLifeplaceHallway_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYElevatedLifeplaceApartment:
    {
         HARDWARE_map_width_tiles=42;
         HARDWARE_map_height_tiles=43;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYElevatedLifeplaceApartment_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYElevatedLifeplaceApartment_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYElevatedLifeplaceApartment_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYElevatedLifeplaceApartment_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYElevatedLifeplaceApartment_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYElevatedLifeplaceApartment_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYElevatedLifeplaceApartment_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYElevatedLifeplaceApartment_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYElevatedLifeplaceApartment_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYElevatedLifeplaceApartment_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYElevatedLifeplaceApartment_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYElevatedLifeplaceApartment_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYElevatedLifeplaceApartment_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYElevatedLifeplaceApartment_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYElevatedLifeplaceApartment_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYElevatedLifeplaceApartment_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYElevatedLifeplaceApartment_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYElevatedLifeplaceApartment_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYElevatedLifeplaceApartment_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYElevatedLifeplaceApartment_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYElevatedLifeplaceBathroom:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYElevatedLifeplaceBathroom_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYElevatedLifeplaceBathroom_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYElevatedLifeplaceBathroom_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYElevatedLifeplaceBathroom_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYElevatedLifeplaceBathroom_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYElevatedLifeplaceBathroom_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYElevatedLifeplaceBathroom_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYElevatedLifeplaceBathroom_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYElevatedLifeplaceBathroom_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYElevatedLifeplaceBathroom_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYElevatedLifeplaceBathroom_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYElevatedLifeplaceBathroom_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYElevatedLifeplaceBathroom_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYElevatedLifeplaceBathroom_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYElevatedLifeplaceBathroom_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYElevatedLifeplaceBathroom_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYElevatedLifeplaceBathroom_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYElevatedLifeplaceBathroom_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYElevatedLifeplaceBathroom_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYElevatedLifeplaceBathroom_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYElevatedLifeplaceBedroom:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYElevatedLifeplaceBedroom_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYElevatedLifeplaceBedroom_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYElevatedLifeplaceBedroom_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYElevatedLifeplaceBedroom_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYElevatedLifeplaceBedroom_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYElevatedLifeplaceBedroom_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYElevatedLifeplaceBedroom_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYElevatedLifeplaceBedroom_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYElevatedLifeplaceBedroom_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYElevatedLifeplaceBedroom_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYElevatedLifeplaceBedroom_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYElevatedLifeplaceBedroom_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYElevatedLifeplaceBedroom_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYElevatedLifeplaceBedroom_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYElevatedLifeplaceBedroom_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYElevatedLifeplaceBedroom_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYElevatedLifeplaceBedroom_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYElevatedLifeplaceBedroom_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYElevatedLifeplaceBedroom_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYElevatedLifeplaceBedroom_TouchMap_1_Tiles.bin");
         break;
    }

    case MAP_bobsgame_CITYDeli:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=43;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYDeli_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYDeli_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYDeli_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYDeli_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYDeli_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYDeli_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYDeli_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYDeli_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYDeli_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYDeli_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYDeli_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYDeli_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYDeli_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYDeli_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYDeli_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYDeli_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYDeli_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYDeli_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYDeli_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYDeli_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYTheCafeEntrance:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYTheCafeEntrance_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYTheCafeEntrance_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYTheCafeEntrance_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYTheCafeEntrance_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYTheCafeEntrance_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYTheCafeEntrance_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYTheCafeEntrance_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYTheCafeEntrance_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYTheCafeEntrance_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYTheCafeEntrance_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYTheCafeEntrance_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYTheCafeEntrance_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYTheCafeEntrance_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYTheCafeEntrance_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYTheCafeEntrance_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYTheCafeEntrance_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYTheCafeEntrance_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYTheCafeEntrance_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYTheCafeEntrance_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYTheCafeEntrance_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYTheCafe:
    {
         HARDWARE_map_width_tiles=57;
         HARDWARE_map_height_tiles=48;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYTheCafe_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYTheCafe_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYTheCafe_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYTheCafe_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYTheCafe_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYTheCafe_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYTheCafe_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYTheCafe_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYTheCafe_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYTheCafe_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYTheCafe_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYTheCafe_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYTheCafe_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYTheCafe_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYTheCafe_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYTheCafe_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYTheCafe_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYTheCafe_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYTheCafe_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYTheCafe_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYTheCafeBathroom:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYTheCafeBathroom_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYTheCafeBathroom_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYTheCafeBathroom_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYTheCafeBathroom_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYTheCafeBathroom_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYTheCafeBathroom_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYTheCafeBathroom_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYTheCafeBathroom_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYTheCafeBathroom_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYTheCafeBathroom_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYTheCafeBathroom_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYTheCafeBathroom_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYTheCafeBathroom_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYTheCafeBathroom_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYTheCafeBathroom_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYTheCafeBathroom_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYTheCafeBathroom_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYTheCafeBathroom_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYTheCafeBathroom_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYTheCafeBathroom_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYTheCafeDressingRoom:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYTheCafeDressingRoom_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYTheCafeDressingRoom_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYTheCafeDressingRoom_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYTheCafeDressingRoom_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYTheCafeDressingRoom_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYTheCafeDressingRoom_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYTheCafeDressingRoom_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYTheCafeDressingRoom_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYTheCafeDressingRoom_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYTheCafeDressingRoom_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYTheCafeDressingRoom_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYTheCafeDressingRoom_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYTheCafeDressingRoom_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYTheCafeDressingRoom_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYTheCafeDressingRoom_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYTheCafeDressingRoom_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYTheCafeDressingRoom_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYTheCafeDressingRoom_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYTheCafeDressingRoom_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYTheCafeDressingRoom_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYPoolHall:
    {
         HARDWARE_map_width_tiles=42;
         HARDWARE_map_height_tiles=63;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYPoolHall_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYPoolHall_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYPoolHall_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYPoolHall_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYPoolHall_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYPoolHall_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYPoolHall_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYPoolHall_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYPoolHall_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYPoolHall_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYPoolHall_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYPoolHall_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYPoolHall_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYPoolHall_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYPoolHall_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYPoolHall_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYPoolHall_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYPoolHall_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYPoolHall_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYPoolHall_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYLaundromat:
    {
         HARDWARE_map_width_tiles=46;
         HARDWARE_map_height_tiles=48;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYLaundromat_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYLaundromat_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYLaundromat_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYLaundromat_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYLaundromat_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYLaundromat_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYLaundromat_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYLaundromat_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYLaundromat_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYLaundromat_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYLaundromat_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYLaundromat_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYLaundromat_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYLaundromat_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYLaundromat_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYLaundromat_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYLaundromat_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYLaundromat_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYLaundromat_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYLaundromat_TouchMap_1_Tiles.bin");
         break;
    }

    case MAP_bobsgame_CITYHospitalEntrance:
    {
         HARDWARE_map_width_tiles=83;
         HARDWARE_map_height_tiles=43;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYHospitalEntrance_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYHospitalEntrance_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYHospitalEntrance_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYHospitalEntrance_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYHospitalEntrance_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYHospitalEntrance_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYHospitalEntrance_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYHospitalEntrance_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYHospitalEntrance_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYHospitalEntrance_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYHospitalEntrance_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYHospitalEntrance_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYHospitalEntrance_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYHospitalEntrance_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYHospitalEntrance_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYHospitalEntrance_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYHospitalEntrance_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYHospitalEntrance_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHospitalEntrance_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHospitalEntrance_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYHospitalEntranceBathroom:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYHospitalEntranceBathroom_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYHospitalEntranceBathroom_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYHospitalEntranceBathroom_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYHospitalEntranceBathroom_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYHospitalEntranceBathroom_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYHospitalEntranceBathroom_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYHospitalEntranceBathroom_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYHospitalEntranceBathroom_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYHospitalEntranceBathroom_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYHospitalEntranceBathroom_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYHospitalEntranceBathroom_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYHospitalEntranceBathroom_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYHospitalEntranceBathroom_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYHospitalEntranceBathroom_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYHospitalEntranceBathroom_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYHospitalEntranceBathroom_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYHospitalEntranceBathroom_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYHospitalEntranceBathroom_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHospitalEntranceBathroom_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHospitalEntranceBathroom_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYHospitalElevator:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYHospitalElevator_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYHospitalElevator_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYHospitalElevator_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYHospitalElevator_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYHospitalElevator_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYHospitalElevator_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYHospitalElevator_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYHospitalElevator_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYHospitalElevator_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYHospitalElevator_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYHospitalElevator_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYHospitalElevator_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYHospitalElevator_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYHospitalElevator_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYHospitalElevator_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYHospitalElevator_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYHospitalElevator_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYHospitalElevator_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHospitalElevator_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHospitalElevator_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYHospitalElevator2:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYHospitalElevator2_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYHospitalElevator2_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYHospitalElevator2_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYHospitalElevator2_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYHospitalElevator2_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYHospitalElevator2_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYHospitalElevator2_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYHospitalElevator2_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYHospitalElevator2_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYHospitalElevator2_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYHospitalElevator2_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYHospitalElevator2_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYHospitalElevator2_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYHospitalElevator2_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYHospitalElevator2_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYHospitalElevator2_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYHospitalElevator2_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYHospitalElevator2_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHospitalElevator2_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHospitalElevator2_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYHospitalWaitingOutPatient:
    {
         HARDWARE_map_width_tiles=83;
         HARDWARE_map_height_tiles=57;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYHospitalWaitingOutPatient_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYHospitalWaitingOutPatient_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYHospitalWaitingOutPatient_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYHospitalWaitingOutPatient_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYHospitalWaitingOutPatient_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYHospitalWaitingOutPatient_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYHospitalWaitingOutPatient_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYHospitalWaitingOutPatient_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYHospitalWaitingOutPatient_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYHospitalWaitingOutPatient_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYHospitalWaitingOutPatient_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYHospitalWaitingOutPatient_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYHospitalWaitingOutPatient_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYHospitalWaitingOutPatient_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYHospitalWaitingOutPatient_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYHospitalWaitingOutPatient_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYHospitalWaitingOutPatient_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYHospitalWaitingOutPatient_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHospitalWaitingOutPatient_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHospitalWaitingOutPatient_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYHospitalOutPatientMensBathroom:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYHospitalOutPatientMensBathroom_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYHospitalOutPatientMensBathroom_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYHospitalOutPatientMensBathroom_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYHospitalOutPatientMensBathroom_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYHospitalOutPatientMensBathroom_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYHospitalOutPatientMensBathroom_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYHospitalOutPatientMensBathroom_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYHospitalOutPatientMensBathroom_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYHospitalOutPatientMensBathroom_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYHospitalOutPatientMensBathroom_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYHospitalOutPatientMensBathroom_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYHospitalOutPatientMensBathroom_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYHospitalOutPatientMensBathroom_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYHospitalOutPatientMensBathroom_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYHospitalOutPatientMensBathroom_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYHospitalOutPatientMensBathroom_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYHospitalOutPatientMensBathroom_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYHospitalOutPatientMensBathroom_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHospitalOutPatientMensBathroom_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHospitalOutPatientMensBathroom_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYHospitalOutPatientWomensBathroom:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYHospitalOutPatientWomensBathroom_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYHospitalOutPatientWomensBathroom_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYHospitalOutPatientWomensBathroom_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYHospitalOutPatientWomensBathroom_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYHospitalOutPatientWomensBathroom_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYHospitalOutPatientWomensBathroom_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYHospitalOutPatientWomensBathroom_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYHospitalOutPatientWomensBathroom_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYHospitalOutPatientWomensBathroom_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYHospitalOutPatientWomensBathroom_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYHospitalOutPatientWomensBathroom_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYHospitalOutPatientWomensBathroom_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYHospitalOutPatientWomensBathroom_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYHospitalOutPatientWomensBathroom_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYHospitalOutPatientWomensBathroom_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYHospitalOutPatientWomensBathroom_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYHospitalOutPatientWomensBathroom_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYHospitalOutPatientWomensBathroom_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHospitalOutPatientWomensBathroom_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHospitalOutPatientWomensBathroom_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYHospitalPatientRoom:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYHospitalPatientRoom_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYHospitalPatientRoom_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYHospitalPatientRoom_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYHospitalPatientRoom_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYHospitalPatientRoom_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYHospitalPatientRoom_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYHospitalPatientRoom_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYHospitalPatientRoom_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYHospitalPatientRoom_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYHospitalPatientRoom_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYHospitalPatientRoom_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYHospitalPatientRoom_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYHospitalPatientRoom_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYHospitalPatientRoom_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYHospitalPatientRoom_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYHospitalPatientRoom_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYHospitalPatientRoom_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYHospitalPatientRoom_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHospitalPatientRoom_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHospitalPatientRoom_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYHospitalPatientRoom2:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYHospitalPatientRoom2_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYHospitalPatientRoom2_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYHospitalPatientRoom2_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYHospitalPatientRoom2_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYHospitalPatientRoom2_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYHospitalPatientRoom2_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYHospitalPatientRoom2_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYHospitalPatientRoom2_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYHospitalPatientRoom2_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYHospitalPatientRoom2_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYHospitalPatientRoom2_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYHospitalPatientRoom2_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYHospitalPatientRoom2_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYHospitalPatientRoom2_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYHospitalPatientRoom2_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYHospitalPatientRoom2_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYHospitalPatientRoom2_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYHospitalPatientRoom2_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHospitalPatientRoom2_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHospitalPatientRoom2_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYHospitalPatientRoom3:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYHospitalPatientRoom3_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYHospitalPatientRoom3_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYHospitalPatientRoom3_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYHospitalPatientRoom3_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYHospitalPatientRoom3_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYHospitalPatientRoom3_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYHospitalPatientRoom3_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYHospitalPatientRoom3_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYHospitalPatientRoom3_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYHospitalPatientRoom3_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYHospitalPatientRoom3_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYHospitalPatientRoom3_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYHospitalPatientRoom3_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYHospitalPatientRoom3_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYHospitalPatientRoom3_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYHospitalPatientRoom3_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYHospitalPatientRoom3_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYHospitalPatientRoom3_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHospitalPatientRoom3_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHospitalPatientRoom3_TouchMap_1_Tiles.bin");
         break;
    }

    case MAP_bobsgame_CITYHospitalOperatingRoom:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=39;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYHospitalOperatingRoom_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYHospitalOperatingRoom_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYHospitalOperatingRoom_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYHospitalOperatingRoom_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYHospitalOperatingRoom_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYHospitalOperatingRoom_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYHospitalOperatingRoom_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYHospitalOperatingRoom_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYHospitalOperatingRoom_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYHospitalOperatingRoom_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYHospitalOperatingRoom_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYHospitalOperatingRoom_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYHospitalOperatingRoom_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYHospitalOperatingRoom_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYHospitalOperatingRoom_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYHospitalOperatingRoom_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYHospitalOperatingRoom_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYHospitalOperatingRoom_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHospitalOperatingRoom_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHospitalOperatingRoom_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYHospitalPsychiatricWard:
    {
         HARDWARE_map_width_tiles=83;
         HARDWARE_map_height_tiles=45;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYHospitalPsychiatricWard_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYHospitalPsychiatricWard_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYHospitalPsychiatricWard_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYHospitalPsychiatricWard_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYHospitalPsychiatricWard_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYHospitalPsychiatricWard_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYHospitalPsychiatricWard_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYHospitalPsychiatricWard_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYHospitalPsychiatricWard_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYHospitalPsychiatricWard_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYHospitalPsychiatricWard_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYHospitalPsychiatricWard_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYHospitalPsychiatricWard_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYHospitalPsychiatricWard_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYHospitalPsychiatricWard_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYHospitalPsychiatricWard_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYHospitalPsychiatricWard_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYHospitalPsychiatricWard_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHospitalPsychiatricWard_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHospitalPsychiatricWard_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYHospitalSoftRoom:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYHospitalSoftRoom_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYHospitalSoftRoom_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYHospitalSoftRoom_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYHospitalSoftRoom_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYHospitalSoftRoom_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYHospitalSoftRoom_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYHospitalSoftRoom_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYHospitalSoftRoom_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYHospitalSoftRoom_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYHospitalSoftRoom_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYHospitalSoftRoom_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYHospitalSoftRoom_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYHospitalSoftRoom_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYHospitalSoftRoom_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYHospitalSoftRoom_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYHospitalSoftRoom_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYHospitalSoftRoom_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYHospitalSoftRoom_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHospitalSoftRoom_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHospitalSoftRoom_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYHospitalSoftRoom2:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYHospitalSoftRoom2_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYHospitalSoftRoom2_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYHospitalSoftRoom2_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYHospitalSoftRoom2_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYHospitalSoftRoom2_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYHospitalSoftRoom2_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYHospitalSoftRoom2_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYHospitalSoftRoom2_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYHospitalSoftRoom2_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYHospitalSoftRoom2_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYHospitalSoftRoom2_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYHospitalSoftRoom2_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYHospitalSoftRoom2_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYHospitalSoftRoom2_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYHospitalSoftRoom2_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYHospitalSoftRoom2_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYHospitalSoftRoom2_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYHospitalSoftRoom2_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHospitalSoftRoom2_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHospitalSoftRoom2_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYHospitalSoftRoom3:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYHospitalSoftRoom3_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYHospitalSoftRoom3_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYHospitalSoftRoom3_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYHospitalSoftRoom3_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYHospitalSoftRoom3_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYHospitalSoftRoom3_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYHospitalSoftRoom3_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYHospitalSoftRoom3_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYHospitalSoftRoom3_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYHospitalSoftRoom3_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYHospitalSoftRoom3_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYHospitalSoftRoom3_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYHospitalSoftRoom3_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYHospitalSoftRoom3_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYHospitalSoftRoom3_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYHospitalSoftRoom3_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYHospitalSoftRoom3_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYHospitalSoftRoom3_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHospitalSoftRoom3_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHospitalSoftRoom3_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYHospitalMaternityWard:
    {
         HARDWARE_map_width_tiles=83;
         HARDWARE_map_height_tiles=45;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYHospitalMaternityWard_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYHospitalMaternityWard_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYHospitalMaternityWard_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYHospitalMaternityWard_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYHospitalMaternityWard_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYHospitalMaternityWard_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYHospitalMaternityWard_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYHospitalMaternityWard_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYHospitalMaternityWard_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYHospitalMaternityWard_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYHospitalMaternityWard_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYHospitalMaternityWard_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYHospitalMaternityWard_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYHospitalMaternityWard_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYHospitalMaternityWard_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYHospitalMaternityWard_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYHospitalMaternityWard_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYHospitalMaternityWard_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHospitalMaternityWard_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHospitalMaternityWard_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYHospitalMaternityWardInfirmary:
    {
         HARDWARE_map_width_tiles=45;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYHospitalMaternityWardInfirmary_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYHospitalMaternityWardInfirmary_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYHospitalMaternityWardInfirmary_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYHospitalMaternityWardInfirmary_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYHospitalMaternityWardInfirmary_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYHospitalMaternityWardInfirmary_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYHospitalMaternityWardInfirmary_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYHospitalMaternityWardInfirmary_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYHospitalMaternityWardInfirmary_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYHospitalMaternityWardInfirmary_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYHospitalMaternityWardInfirmary_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYHospitalMaternityWardInfirmary_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYHospitalMaternityWardInfirmary_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYHospitalMaternityWardInfirmary_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYHospitalMaternityWardInfirmary_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYHospitalMaternityWardInfirmary_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYHospitalMaternityWardInfirmary_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYHospitalMaternityWardInfirmary_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHospitalMaternityWardInfirmary_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHospitalMaternityWardInfirmary_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYHospitalEmergencyEntrance:
    {
         HARDWARE_map_width_tiles=83;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYHospitalEmergencyEntrance_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYHospitalEmergencyEntrance_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYHospitalEmergencyEntrance_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYHospitalEmergencyEntrance_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYHospitalEmergencyEntrance_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYHospitalEmergencyEntrance_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYHospitalEmergencyEntrance_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYHospitalEmergencyEntrance_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYHospitalEmergencyEntrance_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYHospitalEmergencyEntrance_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYHospitalEmergencyEntrance_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYHospitalEmergencyEntrance_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYHospitalEmergencyEntrance_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYHospitalEmergencyEntrance_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYHospitalEmergencyEntrance_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYHospitalEmergencyEntrance_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYHospitalEmergencyEntrance_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYHospitalEmergencyEntrance_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHospitalEmergencyEntrance_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHospitalEmergencyEntrance_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYHospitalMorgue:
    {
         HARDWARE_map_width_tiles=83;
         HARDWARE_map_height_tiles=43;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYHospitalMorgue_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYHospitalMorgue_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYHospitalMorgue_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYHospitalMorgue_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYHospitalMorgue_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYHospitalMorgue_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYHospitalMorgue_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYHospitalMorgue_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYHospitalMorgue_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYHospitalMorgue_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYHospitalMorgue_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYHospitalMorgue_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYHospitalMorgue_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYHospitalMorgue_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYHospitalMorgue_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYHospitalMorgue_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYHospitalMorgue_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYHospitalMorgue_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHospitalMorgue_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHospitalMorgue_TouchMap_1_Tiles.bin");
         break;
    }

    case MAP_bobsgame_CITYPoliceStationLobby:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYPoliceStationLobby_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYPoliceStationLobby_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYPoliceStationLobby_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYPoliceStationLobby_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYPoliceStationLobby_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYPoliceStationLobby_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYPoliceStationLobby_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYPoliceStationLobby_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYPoliceStationLobby_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYPoliceStationLobby_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYPoliceStationLobby_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYPoliceStationLobby_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYPoliceStationLobby_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYPoliceStationLobby_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYPoliceStationLobby_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYPoliceStationLobby_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYPoliceStationLobby_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYPoliceStationLobby_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYPoliceStationLobby_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYPoliceStationLobby_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYPoliceStationOffice:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=48;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYPoliceStationOffice_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYPoliceStationOffice_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYPoliceStationOffice_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYPoliceStationOffice_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYPoliceStationOffice_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYPoliceStationOffice_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYPoliceStationOffice_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYPoliceStationOffice_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYPoliceStationOffice_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYPoliceStationOffice_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYPoliceStationOffice_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYPoliceStationOffice_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYPoliceStationOffice_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYPoliceStationOffice_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYPoliceStationOffice_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYPoliceStationOffice_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYPoliceStationOffice_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYPoliceStationOffice_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYPoliceStationOffice_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYPoliceStationOffice_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYPoliceStationInterrogationRoom:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYPoliceStationInterrogationRoom_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYPoliceStationInterrogationRoom_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYPoliceStationInterrogationRoom_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYPoliceStationInterrogationRoom_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYPoliceStationInterrogationRoom_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYPoliceStationInterrogationRoom_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYPoliceStationInterrogationRoom_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYPoliceStationInterrogationRoom_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYPoliceStationInterrogationRoom_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYPoliceStationInterrogationRoom_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYPoliceStationInterrogationRoom_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYPoliceStationInterrogationRoom_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYPoliceStationInterrogationRoom_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYPoliceStationInterrogationRoom_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYPoliceStationInterrogationRoom_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYPoliceStationInterrogationRoom_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYPoliceStationInterrogationRoom_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYPoliceStationInterrogationRoom_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYPoliceStationInterrogationRoom_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYPoliceStationInterrogationRoom_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYPoliceStationOffice2WayMirror:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYPoliceStationOffice2WayMirror_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYPoliceStationOffice2WayMirror_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYPoliceStationOffice2WayMirror_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYPoliceStationOffice2WayMirror_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYPoliceStationOffice2WayMirror_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYPoliceStationOffice2WayMirror_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYPoliceStationOffice2WayMirror_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYPoliceStationOffice2WayMirror_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYPoliceStationOffice2WayMirror_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYPoliceStationOffice2WayMirror_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYPoliceStationOffice2WayMirror_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYPoliceStationOffice2WayMirror_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYPoliceStationOffice2WayMirror_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYPoliceStationOffice2WayMirror_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYPoliceStationOffice2WayMirror_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYPoliceStationOffice2WayMirror_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYPoliceStationOffice2WayMirror_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYPoliceStationOffice2WayMirror_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYPoliceStationOffice2WayMirror_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYPoliceStationOffice2WayMirror_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYPoliceStationEvidenceRoom:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYPoliceStationEvidenceRoom_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYPoliceStationEvidenceRoom_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYPoliceStationEvidenceRoom_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYPoliceStationEvidenceRoom_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYPoliceStationEvidenceRoom_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYPoliceStationEvidenceRoom_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYPoliceStationEvidenceRoom_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYPoliceStationEvidenceRoom_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYPoliceStationEvidenceRoom_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYPoliceStationEvidenceRoom_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYPoliceStationEvidenceRoom_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYPoliceStationEvidenceRoom_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYPoliceStationEvidenceRoom_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYPoliceStationEvidenceRoom_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYPoliceStationEvidenceRoom_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYPoliceStationEvidenceRoom_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYPoliceStationEvidenceRoom_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYPoliceStationEvidenceRoom_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYPoliceStationEvidenceRoom_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYPoliceStationEvidenceRoom_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYPoliceStationStairWellToHoldCell:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=48;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYPoliceStationStairWellToHoldCell_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYPoliceStationStairWellToHoldCell_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYPoliceStationStairWellToHoldCell_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYPoliceStationStairWellToHoldCell_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYPoliceStationStairWellToHoldCell_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYPoliceStationStairWellToHoldCell_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYPoliceStationStairWellToHoldCell_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYPoliceStationStairWellToHoldCell_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYPoliceStationStairWellToHoldCell_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYPoliceStationStairWellToHoldCell_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYPoliceStationStairWellToHoldCell_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYPoliceStationStairWellToHoldCell_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYPoliceStationStairWellToHoldCell_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYPoliceStationStairWellToHoldCell_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYPoliceStationStairWellToHoldCell_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYPoliceStationStairWellToHoldCell_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYPoliceStationStairWellToHoldCell_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYPoliceStationStairWellToHoldCell_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYPoliceStationStairWellToHoldCell_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYPoliceStationStairWellToHoldCell_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYPoliceStationHoldingCells:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYPoliceStationCells_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYPoliceStationHoldingCells_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYPoliceStationHoldingCells_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYPoliceStationHoldingCells_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYPoliceStationHoldingCells_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYPoliceStationHoldingCells_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYPoliceStationHoldingCells_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYPoliceStationHoldingCells_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYPoliceStationHoldingCells_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYPoliceStationHoldingCells_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYPoliceStationHoldingCells_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYPoliceStationHoldingCells_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYPoliceStationHoldingCells_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYPoliceStationHoldingCells_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYPoliceStationHoldingCells_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYPoliceStationHoldingCells_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYPoliceStationHoldingCells_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYPoliceStationHoldingCells_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYPoliceStationHoldingCells_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYPoliceStationHoldingCells_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYPoliceStationPrisonVisitingRoom:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYPoliceStationPrisonVisitingRoom_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYPoliceStationPrisonVisitingRoom_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYPoliceStationPrisonVisitingRoom_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYPoliceStationPrisonVisitingRoom_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYPoliceStationPrisonVisitingRoom_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYPoliceStationPrisonVisitingRoom_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYPoliceStationPrisonVisitingRoom_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYPoliceStationPrisonVisitingRoom_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYPoliceStationPrisonVisitingRoom_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYPoliceStationPrisonVisitingRoom_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYPoliceStationPrisonVisitingRoom_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYPoliceStationPrisonVisitingRoom_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYPoliceStationPrisonVisitingRoom_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYPoliceStationPrisonVisitingRoom_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYPoliceStationPrisonVisitingRoom_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYPoliceStationPrisonVisitingRoom_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYPoliceStationPrisonVisitingRoom_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYPoliceStationPrisonVisitingRoom_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYPoliceStationPrisonVisitingRoom_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYPoliceStationPrisonVisitingRoom_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYPoliceStationPrisonHallway:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=88;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYPoliceStationPrisonHallway_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYPoliceStationPrisonHallway_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYPoliceStationPrisonHallway_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYPoliceStationPrisonHallway_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYPoliceStationPrisonHallway_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYPoliceStationPrisonHallway_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYPoliceStationPrisonHallway_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYPoliceStationPrisonHallway_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYPoliceStationPrisonHallway_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYPoliceStationPrisonHallway_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYPoliceStationPrisonHallway_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYPoliceStationPrisonHallway_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYPoliceStationPrisonHallway_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYPoliceStationPrisonHallway_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYPoliceStationPrisonHallway_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYPoliceStationPrisonHallway_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYPoliceStationPrisonHallway_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYPoliceStationPrisonHallway_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYPoliceStationPrisonHallway_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYPoliceStationPrisonHallway_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYPoliceStationPrisonCell:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYPoliceStationPrisonCell_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYPoliceStationPrisonCell_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYPoliceStationPrisonCell_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYPoliceStationPrisonCell_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYPoliceStationPrisonCell_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYPoliceStationPrisonCell_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYPoliceStationPrisonCell_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYPoliceStationPrisonCell_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYPoliceStationPrisonCell_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYPoliceStationPrisonCell_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYPoliceStationPrisonCell_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYPoliceStationPrisonCell_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYPoliceStationPrisonCell_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYPoliceStationPrisonCell_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYPoliceStationPrisonCell_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYPoliceStationPrisonCell_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYPoliceStationPrisonCell_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYPoliceStationPrisonCell_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYPoliceStationPrisonCell_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYPoliceStationPrisonCell_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYFireDepartmentGarage:
    {
         HARDWARE_map_width_tiles=49;
         HARDWARE_map_height_tiles=55;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYFireDepartmentGarage_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYFireDepartmentGarage_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYFireDepartmentGarage_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYFireDepartmentGarage_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYFireDepartmentGarage_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYFireDepartmentGarage_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYFireDepartmentGarage_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYFireDepartmentGarage_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYFireDepartmentGarage_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYFireDepartmentGarage_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYFireDepartmentGarage_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYFireDepartmentGarage_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYFireDepartmentGarage_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYFireDepartmentGarage_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYFireDepartmentGarage_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYFireDepartmentGarage_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYFireDepartmentGarage_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYFireDepartmentGarage_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYFireDepartmentGarage_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYFireDepartmentGarage_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYFireDepartmentUpstairs:
    {
         HARDWARE_map_width_tiles=49;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYFireDepartmentUpstairs_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYFireDepartmentUpstairs_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYFireDepartmentUpstairs_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYFireDepartmentUpstairs_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYFireDepartmentUpstairs_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYFireDepartmentUpstairs_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYFireDepartmentUpstairs_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYFireDepartmentUpstairs_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYFireDepartmentUpstairs_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYFireDepartmentUpstairs_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYFireDepartmentUpstairs_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYFireDepartmentUpstairs_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYFireDepartmentUpstairs_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYFireDepartmentUpstairs_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYFireDepartmentUpstairs_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYFireDepartmentUpstairs_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYFireDepartmentUpstairs_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYFireDepartmentUpstairs_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYFireDepartmentUpstairs_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYFireDepartmentUpstairs_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYFireDepartmentQuarters:
    {
         HARDWARE_map_width_tiles=49;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYFireDepartmentQuarters_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYFireDepartmentQuarters_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYFireDepartmentQuarters_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYFireDepartmentQuarters_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYFireDepartmentQuarters_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYFireDepartmentQuarters_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYFireDepartmentQuarters_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYFireDepartmentQuarters_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYFireDepartmentQuarters_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYFireDepartmentQuarters_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYFireDepartmentQuarters_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYFireDepartmentQuarters_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYFireDepartmentQuarters_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYFireDepartmentQuarters_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYFireDepartmentQuarters_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYFireDepartmentQuarters_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYFireDepartmentQuarters_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYFireDepartmentQuarters_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYFireDepartmentQuarters_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYFireDepartmentQuarters_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYFireDepartmentBedroom:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=34;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYFireDepartmentBedroom_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYFireDepartmentBedroom_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYFireDepartmentBedroom_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYFireDepartmentBedroom_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYFireDepartmentBedroom_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYFireDepartmentBedroom_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYFireDepartmentBedroom_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYFireDepartmentBedroom_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYFireDepartmentBedroom_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYFireDepartmentBedroom_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYFireDepartmentBedroom_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYFireDepartmentBedroom_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYFireDepartmentBedroom_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYFireDepartmentBedroom_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYFireDepartmentBedroom_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYFireDepartmentBedroom_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYFireDepartmentBedroom_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYFireDepartmentBedroom_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYFireDepartmentBedroom_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYFireDepartmentBedroom_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYFireDepartmentBathroom:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=34;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYFireDepartmentBathroom_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYFireDepartmentBathroom_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYFireDepartmentBathroom_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYFireDepartmentBathroom_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYFireDepartmentBathroom_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYFireDepartmentBathroom_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYFireDepartmentBathroom_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYFireDepartmentBathroom_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYFireDepartmentBathroom_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYFireDepartmentBathroom_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYFireDepartmentBathroom_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYFireDepartmentBathroom_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYFireDepartmentBathroom_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYFireDepartmentBathroom_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYFireDepartmentBathroom_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYFireDepartmentBathroom_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYFireDepartmentBathroom_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYFireDepartmentBathroom_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYFireDepartmentBathroom_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYFireDepartmentBathroom_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYCityHallEntrance:
    {
         HARDWARE_map_width_tiles=95;
         HARDWARE_map_height_tiles=47;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYCityHallEntrance_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYCityHallEntrance_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYCityHallEntrance_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYCityHallEntrance_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYCityHallEntrance_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYCityHallEntrance_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYCityHallEntrance_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYCityHallEntrance_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYCityHallEntrance_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYCityHallEntrance_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYCityHallEntrance_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYCityHallEntrance_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYCityHallEntrance_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYCityHallEntrance_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYCityHallEntrance_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYCityHallEntrance_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYCityHallEntrance_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYCityHallEntrance_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYCityHallEntrance_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYCityHallEntrance_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYCityHallElevator:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYCityHallElevator_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYCityHallElevator_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYCityHallElevator_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYCityHallElevator_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYCityHallElevator_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYCityHallElevator_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYCityHallElevator_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYCityHallElevator_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYCityHallElevator_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYCityHallElevator_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYCityHallElevator_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYCityHallElevator_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYCityHallElevator_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYCityHallElevator_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYCityHallElevator_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYCityHallElevator_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYCityHallElevator_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYCityHallElevator_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYCityHallElevator_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYCityHallElevator_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYCityHallOffices:
    {
         HARDWARE_map_width_tiles=95;
         HARDWARE_map_height_tiles=47;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYCityHallOffices_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYCityHallOffices_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYCityHallOffices_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYCityHallOffices_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYCityHallOffices_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYCityHallOffices_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYCityHallOffices_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYCityHallOffices_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYCityHallOffices_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYCityHallOffices_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYCityHallOffices_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYCityHallOffices_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYCityHallOffices_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYCityHallOffices_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYCityHallOffices_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYCityHallOffices_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYCityHallOffices_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYCityHallOffices_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYCityHallOffices_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYCityHallOffices_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYCityHallMeetingRoom:
    {
         HARDWARE_map_width_tiles=95;
         HARDWARE_map_height_tiles=47;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYCityHallMeetingRoom_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYCityHallMeetingRoom_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYCityHallMeetingRoom_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYCityHallMeetingRoom_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYCityHallMeetingRoom_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYCityHallMeetingRoom_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYCityHallMeetingRoom_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYCityHallMeetingRoom_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYCityHallMeetingRoom_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYCityHallMeetingRoom_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYCityHallMeetingRoom_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYCityHallMeetingRoom_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYCityHallMeetingRoom_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYCityHallMeetingRoom_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYCityHallMeetingRoom_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYCityHallMeetingRoom_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYCityHallMeetingRoom_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYCityHallMeetingRoom_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYCityHallMeetingRoom_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYCityHallMeetingRoom_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYCityHallMayorOffice:
    {
         HARDWARE_map_width_tiles=95;
         HARDWARE_map_height_tiles=47;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYCityHallMayorOffice_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYCityHallMayorOffice_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYCityHallMayorOffice_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYCityHallMayorOffice_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYCityHallMayorOffice_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYCityHallMayorOffice_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYCityHallMayorOffice_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYCityHallMayorOffice_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYCityHallMayorOffice_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYCityHallMayorOffice_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYCityHallMayorOffice_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYCityHallMayorOffice_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYCityHallMayorOffice_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYCityHallMayorOffice_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYCityHallMayorOffice_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYCityHallMayorOffice_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYCityHallMayorOffice_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYCityHallMayorOffice_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYCityHallMayorOffice_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYCityHallMayorOffice_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYMuseumLobby:
    {
         HARDWARE_map_width_tiles=53;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYMuseumLobby_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYMuseumLobby_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYMuseumLobby_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYMuseumLobby_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYMuseumLobby_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYMuseumLobby_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYMuseumLobby_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYMuseumLobby_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYMuseumLobby_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYMuseumLobby_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYMuseumLobby_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYMuseumLobby_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYMuseumLobby_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYMuseumLobby_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYMuseumLobby_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYMuseumLobby_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYMuseumLobby_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYMuseumLobby_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYMuseumLobby_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYMuseumLobby_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYMuseumExhibit:
    {
         HARDWARE_map_width_tiles=79;
         HARDWARE_map_height_tiles=57;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYMuseumExhibit_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYMuseumExhibit_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYMuseumExhibit_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYMuseumExhibit_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYMuseumExhibit_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYMuseumExhibit_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYMuseumExhibit_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYMuseumExhibit_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYMuseumExhibit_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYMuseumExhibit_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYMuseumExhibit_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYMuseumExhibit_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYMuseumExhibit_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYMuseumExhibit_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYMuseumExhibit_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYMuseumExhibit_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYMuseumExhibit_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYMuseumExhibit_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYMuseumExhibit_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYMuseumExhibit_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYMuseumGiftShop:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYMuseumGiftShop_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYMuseumGiftShop_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYMuseumGiftShop_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYMuseumGiftShop_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYMuseumGiftShop_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYMuseumGiftShop_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYMuseumGiftShop_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYMuseumGiftShop_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYMuseumGiftShop_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYMuseumGiftShop_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYMuseumGiftShop_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYMuseumGiftShop_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYMuseumGiftShop_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYMuseumGiftShop_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYMuseumGiftShop_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYMuseumGiftShop_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYMuseumGiftShop_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYMuseumGiftShop_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYMuseumGiftShop_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYMuseumGiftShop_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYHotelEntrance:
    {
         HARDWARE_map_width_tiles=98;
         HARDWARE_map_height_tiles=61;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYHotelEntrance_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYHotelEntrance_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYHotelEntrance_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYHotelEntrance_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYHotelEntrance_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYHotelEntrance_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYHotelEntrance_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYHotelEntrance_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYHotelEntrance_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYHotelEntrance_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYHotelEntrance_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYHotelEntrance_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYHotelEntrance_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYHotelEntrance_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYHotelEntrance_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYHotelEntrance_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYHotelEntrance_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYHotelEntrance_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHotelEntrance_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHotelEntrance_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYHotelPool:
    {
         HARDWARE_map_width_tiles=66;
         HARDWARE_map_height_tiles=67;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYHotelPool_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYHotelPool_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYHotelPool_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYHotelPool_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYHotelPool_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYHotelPool_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYHotelPool_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYHotelPool_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYHotelPool_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYHotelPool_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYHotelPool_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYHotelPool_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYHotelPool_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYHotelPool_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYHotelPool_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYHotelPool_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYHotelPool_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYHotelPool_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHotelPool_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHotelPool_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYHotelSauna:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYHotelSauna_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYHotelSauna_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYHotelSauna_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYHotelSauna_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYHotelSauna_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYHotelSauna_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYHotelSauna_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYHotelSauna_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYHotelSauna_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYHotelSauna_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYHotelSauna_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYHotelSauna_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYHotelSauna_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYHotelSauna_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYHotelSauna_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYHotelSauna_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYHotelSauna_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYHotelSauna_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHotelSauna_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHotelSauna_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYHotelElevator:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYHotelElevator_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYHotelElevator_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYHotelElevator_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYHotelElevator_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYHotelElevator_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYHotelElevator_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYHotelElevator_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYHotelElevator_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYHotelElevator_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYHotelElevator_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYHotelElevator_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYHotelElevator_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYHotelElevator_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYHotelElevator_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYHotelElevator_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYHotelElevator_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYHotelElevator_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYHotelElevator_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHotelElevator_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHotelElevator_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYHotelHallway:
    {
         HARDWARE_map_width_tiles=98;
         HARDWARE_map_height_tiles=53;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYHotelHallway_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYHotelHallway_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYHotelHallway_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYHotelHallway_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYHotelHallway_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYHotelHallway_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYHotelHallway_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYHotelHallway_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYHotelHallway_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYHotelHallway_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYHotelHallway_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYHotelHallway_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYHotelHallway_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYHotelHallway_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYHotelHallway_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYHotelHallway_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYHotelHallway_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYHotelHallway_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHotelHallway_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHotelHallway_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYHotelRoom:
    {
         HARDWARE_map_width_tiles=34;
         HARDWARE_map_height_tiles=43;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYHotelRoom_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYHotelRoom_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYHotelRoom_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYHotelRoom_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYHotelRoom_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYHotelRoom_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYHotelRoom_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYHotelRoom_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYHotelRoom_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYHotelRoom_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYHotelRoom_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYHotelRoom_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYHotelRoom_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYHotelRoom_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYHotelRoom_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYHotelRoom_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYHotelRoom_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYHotelRoom_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHotelRoom_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHotelRoom_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYHotelRoomBathroom:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYHotelRoomBathroom_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYHotelRoomBathroom_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYHotelRoomBathroom_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYHotelRoomBathroom_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYHotelRoomBathroom_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYHotelRoomBathroom_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYHotelRoomBathroom_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYHotelRoomBathroom_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYHotelRoomBathroom_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYHotelRoomBathroom_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYHotelRoomBathroom_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYHotelRoomBathroom_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYHotelRoomBathroom_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYHotelRoomBathroom_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYHotelRoomBathroom_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYHotelRoomBathroom_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYHotelRoomBathroom_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYHotelRoomBathroom_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHotelRoomBathroom_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHotelRoomBathroom_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYHotelElevator2:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYHotelElevator2_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYHotelElevator2_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYHotelElevator2_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYHotelElevator2_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYHotelElevator2_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYHotelElevator2_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYHotelElevator2_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYHotelElevator2_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYHotelElevator2_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYHotelElevator2_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYHotelElevator2_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYHotelElevator2_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYHotelElevator2_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYHotelElevator2_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYHotelElevator2_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYHotelElevator2_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYHotelElevator2_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYHotelElevator2_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHotelElevator2_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHotelElevator2_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYHotelLinenCloset:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYHotelLinenCloset_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYHotelLinenCloset_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYHotelLinenCloset_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYHotelLinenCloset_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYHotelLinenCloset_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYHotelLinenCloset_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYHotelLinenCloset_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYHotelLinenCloset_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYHotelLinenCloset_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYHotelLinenCloset_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYHotelLinenCloset_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYHotelLinenCloset_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYHotelLinenCloset_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYHotelLinenCloset_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYHotelLinenCloset_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYHotelLinenCloset_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYHotelLinenCloset_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYHotelLinenCloset_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHotelLinenCloset_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHotelLinenCloset_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYStadiumLobby:
    {
         HARDWARE_map_width_tiles=203;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYStadiumLobby_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYStadiumLobby_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYStadiumLobby_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYStadiumLobby_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYStadiumLobby_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYStadiumLobby_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYStadiumLobby_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYStadiumLobby_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYStadiumLobby_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYStadiumLobby_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYStadiumLobby_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYStadiumLobby_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYStadiumLobby_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYStadiumLobby_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYStadiumLobby_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYStadiumLobby_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYStadiumLobby_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYStadiumLobby_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYStadiumLobby_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYStadiumLobby_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYStadiumBathroomLeftMens:
    {
         HARDWARE_map_width_tiles=82;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYStadiumBathroomLeftMens_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYStadiumBathroomLeftMens_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYStadiumBathroomLeftMens_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYStadiumBathroomLeftMens_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYStadiumBathroomLeftMens_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYStadiumBathroomLeftMens_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYStadiumBathroomLeftMens_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYStadiumBathroomLeftMens_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYStadiumBathroomLeftMens_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYStadiumBathroomLeftMens_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYStadiumBathroomLeftMens_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYStadiumBathroomLeftMens_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYStadiumBathroomLeftMens_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYStadiumBathroomLeftMens_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYStadiumBathroomLeftMens_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYStadiumBathroomLeftMens_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYStadiumBathroomLeftMens_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYStadiumBathroomLeftMens_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYStadiumBathroomLeftMens_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYStadiumBathroomLeftMens_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYStadiumBathroomRightWomens:
    {
         HARDWARE_map_width_tiles=82;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYStadiumBathroomRightWomens_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYStadiumBathroomRightWomens_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYStadiumBathroomRightWomens_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYStadiumBathroomRightWomens_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYStadiumBathroomRightWomens_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYStadiumBathroomRightWomens_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYStadiumBathroomRightWomens_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYStadiumBathroomRightWomens_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYStadiumBathroomRightWomens_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYStadiumBathroomRightWomens_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYStadiumBathroomRightWomens_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYStadiumBathroomRightWomens_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYStadiumBathroomRightWomens_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYStadiumBathroomRightWomens_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYStadiumBathroomRightWomens_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYStadiumBathroomRightWomens_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYStadiumBathroomRightWomens_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYStadiumBathroomRightWomens_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYStadiumBathroomRightWomens_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYStadiumBathroomRightWomens_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYStadiumLeftHallway:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=188;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYStadiumLeftHallway_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYStadiumLeftHallway_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYStadiumLeftHallway_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYStadiumLeftHallway_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYStadiumLeftHallway_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYStadiumLeftHallway_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYStadiumLeftHallway_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYStadiumLeftHallway_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYStadiumLeftHallway_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYStadiumLeftHallway_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYStadiumLeftHallway_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYStadiumLeftHallway_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYStadiumLeftHallway_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYStadiumLeftHallway_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYStadiumLeftHallway_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYStadiumLeftHallway_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYStadiumLeftHallway_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYStadiumLeftHallway_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYStadiumLeftHallway_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYStadiumLeftHallway_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYStadiumRightHallway:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=188;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYStadiumRightHallway_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYStadiumRightHallway_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYStadiumRightHallway_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYStadiumRightHallway_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYStadiumRightHallway_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYStadiumRightHallway_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYStadiumRightHallway_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYStadiumRightHallway_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYStadiumRightHallway_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYStadiumRightHallway_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYStadiumRightHallway_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYStadiumRightHallway_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYStadiumRightHallway_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYStadiumRightHallway_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYStadiumRightHallway_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYStadiumRightHallway_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYStadiumRightHallway_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYStadiumRightHallway_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYStadiumRightHallway_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYStadiumRightHallway_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYStadiumBackstage:
    {
         HARDWARE_map_width_tiles=203;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYStadiumBackstage_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYStadiumBackstage_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYStadiumBackstage_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYStadiumBackstage_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYStadiumBackstage_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYStadiumBackstage_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYStadiumBackstage_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYStadiumBackstage_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYStadiumBackstage_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYStadiumBackstage_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYStadiumBackstage_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYStadiumBackstage_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYStadiumBackstage_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYStadiumBackstage_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYStadiumBackstage_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYStadiumBackstage_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYStadiumBackstage_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYStadiumBackstage_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYStadiumBackstage_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYStadiumBackstage_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYStadiumDressingRoom:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYStadiumDressingRoom_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYStadiumDressingRoom_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYStadiumDressingRoom_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYStadiumDressingRoom_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYStadiumDressingRoom_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYStadiumDressingRoom_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYStadiumDressingRoom_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYStadiumDressingRoom_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYStadiumDressingRoom_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYStadiumDressingRoom_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYStadiumDressingRoom_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYStadiumDressingRoom_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYStadiumDressingRoom_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYStadiumDressingRoom_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYStadiumDressingRoom_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYStadiumDressingRoom_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYStadiumDressingRoom_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYStadiumDressingRoom_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYStadiumDressingRoom_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYStadiumDressingRoom_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYStadiumDressingRoomBathroom:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYStadiumDressingRoomBathroom_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYStadiumDressingRoomBathroom_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYStadiumDressingRoomBathroom_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYStadiumDressingRoomBathroom_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYStadiumDressingRoomBathroom_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYStadiumDressingRoomBathroom_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYStadiumDressingRoomBathroom_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYStadiumDressingRoomBathroom_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYStadiumDressingRoomBathroom_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYStadiumDressingRoomBathroom_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYStadiumDressingRoomBathroom_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYStadiumDressingRoomBathroom_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYStadiumDressingRoomBathroom_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYStadiumDressingRoomBathroom_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYStadiumDressingRoomBathroom_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYStadiumDressingRoomBathroom_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYStadiumDressingRoomBathroom_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYStadiumDressingRoomBathroom_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYStadiumDressingRoomBathroom_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYStadiumDressingRoomBathroom_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYStadiumMain:
    {
         HARDWARE_map_width_tiles=203;
         HARDWARE_map_height_tiles=224;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYStadiumMain_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYStadiumMain_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYStadiumMain_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYStadiumMain_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYStadiumMain_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYStadiumMain_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYStadiumMain_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYStadiumMain_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYStadiumMain_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYStadiumMain_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYStadiumMain_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYStadiumMain_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYStadiumMain_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYStadiumMain_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYStadiumMain_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYStadiumMain_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYStadiumMain_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYStadiumMain_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYStadiumMain_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYStadiumMain_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYStadiumProducerRoom:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYStadiumProducerRoom_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYStadiumProducerRoom_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYStadiumProducerRoom_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYStadiumProducerRoom_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYStadiumProducerRoom_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYStadiumProducerRoom_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYStadiumProducerRoom_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYStadiumProducerRoom_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYStadiumProducerRoom_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYStadiumProducerRoom_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYStadiumProducerRoom_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYStadiumProducerRoom_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYStadiumProducerRoom_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYStadiumProducerRoom_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYStadiumProducerRoom_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYStadiumProducerRoom_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYStadiumProducerRoom_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYStadiumProducerRoom_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYStadiumProducerRoom_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYStadiumProducerRoom_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYStadiumDressingRoom2:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYStadiumDressingRoom2_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYStadiumDressingRoom2_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYStadiumDressingRoom2_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYStadiumDressingRoom2_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYStadiumDressingRoom2_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYStadiumDressingRoom2_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYStadiumDressingRoom2_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYStadiumDressingRoom2_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYStadiumDressingRoom2_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYStadiumDressingRoom2_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYStadiumDressingRoom2_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYStadiumDressingRoom2_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYStadiumDressingRoom2_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYStadiumDressingRoom2_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYStadiumDressingRoom2_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYStadiumDressingRoom2_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYStadiumDressingRoom2_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYStadiumDressingRoom2_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYStadiumDressingRoom2_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYStadiumDressingRoom2_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYStadiumDressingRoom2Bathroom:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYStadiumDressingRoom2Bathroom_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYStadiumDressingRoom2Bathroom_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYStadiumDressingRoom2Bathroom_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYStadiumDressingRoom2Bathroom_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYStadiumDressingRoom2Bathroom_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYStadiumDressingRoom2Bathroom_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYStadiumDressingRoom2Bathroom_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYStadiumDressingRoom2Bathroom_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYStadiumDressingRoom2Bathroom_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYStadiumDressingRoom2Bathroom_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYStadiumDressingRoom2Bathroom_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYStadiumDressingRoom2Bathroom_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYStadiumDressingRoom2Bathroom_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYStadiumDressingRoom2Bathroom_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYStadiumDressingRoom2Bathroom_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYStadiumDressingRoom2Bathroom_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYStadiumDressingRoom2Bathroom_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYStadiumDressingRoom2Bathroom_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYStadiumDressingRoom2Bathroom_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYStadiumDressingRoom2Bathroom_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYStadiumDressingRoom3:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYStadiumDressingRoom3_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYStadiumDressingRoom3_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYStadiumDressingRoom3_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYStadiumDressingRoom3_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYStadiumDressingRoom3_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYStadiumDressingRoom3_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYStadiumDressingRoom3_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYStadiumDressingRoom3_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYStadiumDressingRoom3_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYStadiumDressingRoom3_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYStadiumDressingRoom3_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYStadiumDressingRoom3_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYStadiumDressingRoom3_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYStadiumDressingRoom3_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYStadiumDressingRoom3_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYStadiumDressingRoom3_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYStadiumDressingRoom3_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYStadiumDressingRoom3_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYStadiumDressingRoom3_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYStadiumDressingRoom3_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYStadiumDressingRoom3Bathroom:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYStadiumDressingRoom3Bathroom_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYStadiumDressingRoom3Bathroom_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYStadiumDressingRoom3Bathroom_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYStadiumDressingRoom3Bathroom_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYStadiumDressingRoom3Bathroom_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYStadiumDressingRoom3Bathroom_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYStadiumDressingRoom3Bathroom_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYStadiumDressingRoom3Bathroom_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYStadiumDressingRoom3Bathroom_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYStadiumDressingRoom3Bathroom_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYStadiumDressingRoom3Bathroom_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYStadiumDressingRoom3Bathroom_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYStadiumDressingRoom3Bathroom_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYStadiumDressingRoom3Bathroom_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYStadiumDressingRoom3Bathroom_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYStadiumDressingRoom3Bathroom_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYStadiumDressingRoom3Bathroom_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYStadiumDressingRoom3Bathroom_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYStadiumDressingRoom3Bathroom_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYStadiumDressingRoom3Bathroom_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYPawnShop:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=45;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYPawnShop_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYPawnShop_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYPawnShop_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYPawnShop_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYPawnShop_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYPawnShop_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYPawnShop_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYPawnShop_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYPawnShop_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYPawnShop_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYPawnShop_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYPawnShop_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYPawnShop_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYPawnShop_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYPawnShop_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYPawnShop_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYPawnShop_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYPawnShop_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYPawnShop_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYPawnShop_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYCasinoEntrance:
    {
         HARDWARE_map_width_tiles=98;
         HARDWARE_map_height_tiles=50;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYCasinoEntrance_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYCasinoEntrance_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYCasinoEntrance_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYCasinoEntrance_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYCasinoEntrance_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYCasinoEntrance_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYCasinoEntrance_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYCasinoEntrance_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYCasinoEntrance_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYCasinoEntrance_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYCasinoEntrance_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYCasinoEntrance_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYCasinoEntrance_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYCasinoEntrance_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYCasinoEntrance_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYCasinoEntrance_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYCasinoEntrance_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYCasinoEntrance_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYCasinoEntrance_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYCasinoEntrance_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYCasinoMain:
    {
         HARDWARE_map_width_tiles=98;
         HARDWARE_map_height_tiles=82;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYCasinoMain_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYCasinoMain_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYCasinoMain_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYCasinoMain_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYCasinoMain_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYCasinoMain_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYCasinoMain_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYCasinoMain_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYCasinoMain_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYCasinoMain_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYCasinoMain_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYCasinoMain_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYCasinoMain_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYCasinoMain_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYCasinoMain_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYCasinoMain_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYCasinoMain_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYCasinoMain_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYCasinoMain_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYCasinoMain_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYCasinoBackroom:
    {
         HARDWARE_map_width_tiles=37;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYCasinoBackroom_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYCasinoBackroom_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYCasinoBackroom_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYCasinoBackroom_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYCasinoBackroom_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYCasinoBackroom_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYCasinoBackroom_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYCasinoBackroom_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYCasinoBackroom_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYCasinoBackroom_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYCasinoBackroom_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYCasinoBackroom_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYCasinoBackroom_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYCasinoBackroom_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYCasinoBackroom_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYCasinoBackroom_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYCasinoBackroom_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYCasinoBackroom_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYCasinoBackroom_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYCasinoBackroom_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYHourlyMotel:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=67;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYHourlyMotel_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYHourlyMotel_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYHourlyMotel_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYHourlyMotel_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYHourlyMotel_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYHourlyMotel_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYHourlyMotel_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYHourlyMotel_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYHourlyMotel_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYHourlyMotel_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYHourlyMotel_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYHourlyMotel_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYHourlyMotel_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYHourlyMotel_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYHourlyMotel_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYHourlyMotel_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYHourlyMotel_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYHourlyMotel_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHourlyMotel_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHourlyMotel_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYHourlyMotelRoom:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=33;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYHourlyMotelRoom_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYHourlyMotelRoom_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYHourlyMotelRoom_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYHourlyMotelRoom_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYHourlyMotelRoom_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYHourlyMotelRoom_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYHourlyMotelRoom_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYHourlyMotelRoom_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYHourlyMotelRoom_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYHourlyMotelRoom_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYHourlyMotelRoom_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYHourlyMotelRoom_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYHourlyMotelRoom_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYHourlyMotelRoom_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYHourlyMotelRoom_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYHourlyMotelRoom_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYHourlyMotelRoom_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYHourlyMotelRoom_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHourlyMotelRoom_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHourlyMotelRoom_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYHourlyMotelRoomBathroom:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYHourlyMotelRoomBathroom_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYHourlyMotelRoomBathroom_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYHourlyMotelRoomBathroom_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYHourlyMotelRoomBathroom_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYHourlyMotelRoomBathroom_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYHourlyMotelRoomBathroom_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYHourlyMotelRoomBathroom_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYHourlyMotelRoomBathroom_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYHourlyMotelRoomBathroom_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYHourlyMotelRoomBathroom_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYHourlyMotelRoomBathroom_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYHourlyMotelRoomBathroom_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYHourlyMotelRoomBathroom_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYHourlyMotelRoomBathroom_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYHourlyMotelRoomBathroom_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYHourlyMotelRoomBathroom_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYHourlyMotelRoomBathroom_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYHourlyMotelRoomBathroom_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHourlyMotelRoomBathroom_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYHourlyMotelRoomBathroom_TouchMap_1_Tiles.bin");
         break;
    }





















































    case MAP_bobsgame_TOWNTown:
    {
         HARDWARE_map_width_tiles=1600;
         HARDWARE_map_height_tiles=900;
         strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNTown_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNTown_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNTown_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNTown_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNTown_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNTown_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNTown_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNTown_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNTown_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNTown_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNTown_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNTown_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNTown_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNTown_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNTown_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNTown_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNTown_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNTown_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNTown_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNTown_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_SCHOOLPlayground:
    {
         HARDWARE_map_width_tiles=301;
         HARDWARE_map_height_tiles=265;
         strcpy(HARDWARE_map_0_filename,"/tilemap/school/SCHOOLPlayground_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/school/SCHOOLPlayground_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/school/SCHOOLPlayground_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/school/SCHOOLPlayground_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/school/SCHOOLPlayground_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/school/SCHOOLPlayground_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_SCHOOLPlayground_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_SCHOOLPlayground_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_SCHOOLPlayground_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_SCHOOLPlayground_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_SCHOOLPlayground_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/school/SCHOOLPlayground_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_SCHOOLPlayground_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_SCHOOLPlayground_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_SCHOOLPlayground_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_SCHOOLPlayground_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_SCHOOLPlayground_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_SCHOOLPlayground_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLPlayground_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_SCHOOLPlayground_TouchMap_1_Tiles.bin");
         break;
    }

    case MAP_bobsgame_TOWNClubHouse:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNClubHouse_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNClubHouse_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNClubHouse_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNClubHouse_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNClubHouse_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNClubHouse_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNClubHouse_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNClubHouse_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNClubHouse_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNClubHouse_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNClubHouse_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNClubHouse_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNClubHouse_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNClubHouse_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNClubHouse_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNClubHouse_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNClubHouse_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNClubHouse_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNClubHouse_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNClubHouse_TouchMap_1_Tiles.bin");
         break;
    }

    case MAP_bobsgame_CITYAptRoof:
    {
         HARDWARE_map_width_tiles=66;
         HARDWARE_map_height_tiles=42;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYAptRoof_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYAptRoof_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYAptRoof_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYAptRoof_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYAptRoof_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYAptRoof_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYAptRoof_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYAptRoof_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYAptRoof_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYAptRoof_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYAptRoof_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYAptRoof_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYAptRoof_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYAptRoof_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYAptRoof_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYAptRoof_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYAptRoof_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYAptRoof_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYAptRoof_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYAptRoof_TouchMap_1_Tiles.bin");
         break;
    }
    case MAP_bobsgame_CITYCity:
    {
         HARDWARE_map_width_tiles=1681;
         HARDWARE_map_height_tiles=80;
         strcpy(HARDWARE_map_0_filename,"/tilemap/city/CITYCity_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/city/CITYCity_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/city/CITYCity_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/city/CITYCity_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/city/CITYCity_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/city/CITYCity_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_CITYCity_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_CITYCity_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_CITYCity_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_CITYCity_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_CITYCity_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/city/CITYCity_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_CITYCity_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_CITYCity_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_CITYCity_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_CITYCity_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_CITYCity_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_CITYCity_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYCity_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_CITYCity_TouchMap_1_Tiles.bin");
         break;
    }




    case MAP_bobsgame_MISCCastRoom:
    {
         HARDWARE_map_width_tiles=128;
         HARDWARE_map_height_tiles=128;
         strcpy(HARDWARE_map_0_filename,"/tilemap/misc/MISCCastRoom_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/misc/MISCCastRoom_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/misc/MISCCastRoom_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/misc/MISCCastRoom_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/misc/MISCCastRoom_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/misc/MISCCastRoom_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_MISCCastRoom_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_MISCCastRoom_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_MISCCastRoom_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_MISCCastRoom_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_MISCCastRoom_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/misc/MISCCastRoom_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_MISCnothing_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_MISCnothing_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_MISCnothing_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_MISCnothing_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_MISCnothing_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_MISCnothing_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_MISCnothing_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_MISCnothing_TouchMap_1_Tiles.bin");
         break;
    }


    case MAP_bobsgame_MISCMeetingRoom:
    {
         HARDWARE_map_width_tiles=32;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/misc/MISCMeetingRoom_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/misc/MISCMeetingRoom_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/misc/MISCMeetingRoom_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/misc/MISCMeetingRoom_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/misc/MISCMeetingRoom_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/misc/MISCMeetingRoom_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_MISCMeetingRoom_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_MISCMeetingRoom_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_MISCMeetingRoom_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_MISCMeetingRoom_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_MISCMeetingRoom_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/misc/MISCMeetingRoom_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_MISCnothing_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_MISCnothing_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_MISCnothing_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_MISCnothing_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_MISCnothing_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_MISCnothing_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_MISCnothing_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_MISCnothing_TouchMap_1_Tiles.bin");
         break;
    }


    case MAP_bobsgame_TOWNMANSIONDownstairs:
    {
         HARDWARE_map_width_tiles=100;
         HARDWARE_map_height_tiles=105;
         strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNMANSIONDownstairs_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNMANSIONDownstairs_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNMANSIONDownstairs_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNMANSIONDownstairs_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNMANSIONDownstairs_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNMANSIONDownstairs_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNMANSIONDownstairs_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNMANSIONDownstairs_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNMANSIONDownstairs_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNMANSIONDownstairs_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNMANSIONDownstairs_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNMANSIONDownstairs_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNMANSIONDownstairs_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNMANSIONDownstairs_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNMANSIONDownstairs_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNMANSIONDownstairs_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNMANSIONDownstairs_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNMANSIONDownstairs_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNMANSIONDownstairs_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNMANSIONDownstairs_TouchMap_1_Tiles.bin");
         break;
    }

    case MAP_bobsgame_TOWNMANSIONDownstairsKitchen:
    {
         HARDWARE_map_width_tiles=100;
         HARDWARE_map_height_tiles=32;
         strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNMANSIONDownstairsKitchen_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNMANSIONDownstairsKitchen_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNMANSIONDownstairsKitchen_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNMANSIONDownstairsKitchen_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNMANSIONDownstairsKitchen_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNMANSIONDownstairsKitchen_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNMANSIONDownstairsKitchen_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNMANSIONDownstairsKitchen_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNMANSIONDownstairsKitchen_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNMANSIONDownstairsKitchen_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNMANSIONDownstairsKitchen_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNMANSIONDownstairsKitchen_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNMANSIONDownstairsKitchen_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNMANSIONDownstairsKitchen_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNMANSIONDownstairsKitchen_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNMANSIONDownstairsKitchen_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNMANSIONDownstairsKitchen_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNMANSIONDownstairsKitchen_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNMANSIONDownstairsKitchen_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNMANSIONDownstairsKitchen_TouchMap_1_Tiles.bin");
         break;
    }

    case MAP_bobsgame_TOWNMANSIONUpstairsVideoGameRoom:
    {
         HARDWARE_map_width_tiles=100;
         HARDWARE_map_height_tiles=60;
         strcpy(HARDWARE_map_0_filename,"/tilemap/town/TOWNMANSIONUpstairsVideoGameRoom_Map_0.bin");
         strcpy(HARDWARE_map_1_filename,"/tilemap/town/TOWNMANSIONUpstairsVideoGameRoom_Map_1.bin");
         strcpy(HARDWARE_map_2_filename,"/tilemap/town/TOWNMANSIONUpstairsVideoGameRoom_Map_2.bin");
         strcpy(HARDWARE_map_3_filename,"/tilemap/town/TOWNMANSIONUpstairsVideoGameRoom_Map_3.bin");
         strcpy(HARDWARE_map_hit_layer_filename,"/tilemap/town/TOWNMANSIONUpstairsVideoGameRoom_Map_Hit.bin");
         strcpy(HARDWARE_map_fx_layer_filename,"/tilemap/town/TOWNMANSIONUpstairsVideoGameRoom_Map_FX.bin");
         MAP_current_map_load_function=(void (*) ())&bobsgame_TOWNMANSIONUpstairsVideoGameRoom_Map_Load_Function;
         MAP_current_map_run_function=(void (*) (BOOL))&bobsgame_TOWNMANSIONUpstairsVideoGameRoom_Map_Run_Function;
         MAP_current_map_stop_function=(void (*) ())&bobsgame_TOWNMANSIONUpstairsVideoGameRoom_Map_Stop_Function;
         MAP_current_map_vbl_function=(void (*) ())&bobsgame_TOWNMANSIONUpstairsVideoGameRoom_Map_VBL_Function;
         MAP_current_map_hbl_function=(void (*) ())&bobsgame_TOWNMANSIONUpstairsVideoGameRoom_Map_HBL_Function;
         strcpy(HARDWARE_map_palette_filename,"/tilemap/misc/bobsgame_pal_Pal.bin");
         strcpy(HARDWARE_map_tileset_filename,"/tilemap/town/TOWNMANSIONUpstairsVideoGameRoom_Tiles.bin");
         //strcpy(current_touchmap_302_palette_filename,"/touchmap/bobsgame_TOWNMANSIONUpstairsVideoGameRoom_TouchMap_302_Pal.bin");
         //strcpy(current_touchmap_1_palette_filename,"/touchmap/bobsgame_TOWNMANSIONUpstairsVideoGameRoom_TouchMap_1_Pal.bin");
         //strcpy(current_touchmap_302_tileset_filename,"/touchmap/bobsgame_TOWNMANSIONUpstairsVideoGameRoom_TouchMap_302_Tiles.bin");
         //strcpy(current_touchmap_1_tileset_filename,"/touchmap/bobsgame_TOWNMANSIONUpstairsVideoGameRoom_TouchMap_1_Tiles.bin");
         //strcpy(current_touchmap_302_map_filename,"/touchmap/bobsgame_TOWNMANSIONUpstairsVideoGameRoom_TouchMap_302_Map.bin");
         ////strcpy(current_touchmap_1_map_filename,"/touchmap/bobsgame_TOWNMANSIONUpstairsVideoGameRoom_TouchMap_1_Map.bin");
         //current_touchmap_302_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNMANSIONUpstairsVideoGameRoom_TouchMap_302_Tiles.bin");
         //current_touchmap_1_tileset_size=HARDWARE_get_file_size("/touchmap/bobsgame_TOWNMANSIONUpstairsVideoGameRoom_TouchMap_1_Tiles.bin");
         break;
    }




    default:
    {
        break;
    }

    }
}// end gfx.h





