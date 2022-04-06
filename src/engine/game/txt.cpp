


#include "../../main.h"
//#include "txt.h"


int GLOBAL_text_engine_state=0;


int* FONT_NORMAL_indexed_gfx_data=NULL;
int* FONT_HUGE_indexed_gfx_data=NULL;
int* FONT_SMALL_indexed_gfx_data=NULL;
int* FONT_TINY_indexed_gfx_data=NULL;
int* FONT_OUTLINED_indexed_gfx_data=NULL;
int* FONT_BOB_indexed_gfx_data=NULL;
int* FONT_JAPANESE_indexed_gfx_data=NULL;

char* TEXT_text = NULL;

TEXTBOX TEXT_textbox[2];

float TEXT_scale=1.0f;

bool TEXT_box_done_scrolling_up=0;
int TEXT_shake_is_on=0;


NPC* TEXT_npc_1=NULL;
NPC* TEXT_npc_2=NULL;
NPC* TEXT_npc_3=NULL;
NPC* TEXT_npc_4=NULL;
NPC* TEXT_npc_5=NULL;
NPC* TEXT_npc_6=NULL;


int* TEXT_font_pointer=0;
int TEXT_font_id=0;

int TEXT_color[3] = {BLACK,WHITE,GRAY};

int TEXT_font_height=0;

int TEXT_selected_textbox=0;

int TEXT_string_position=0;
int TEXT_length=0;

bool TEXT_waiting_for_button_input=0;
bool TEXT_waiting_for_input_to_close=0;
bool TEXT_a_unpressed=0;
bool TEXT_wait_for_unpress=0;
int TEXT_vbl_counter=0;


bool TEXT_deinit=0;
int TEXT_vbl_count=0;
bool TEXT_drawing_paused=0;
bool selected_sprite_window=0;

bool TEXT_delay_is_on=0;
int TEXT_delay_counter=0;
bool TEXT_button_icon_is_on=0;
int TEXT_button_timer=0;
bool TEXT_button_icon_down=0;
bool TEXT_keep_text_box_open_for_more_text=0;
bool TEXT_wait_for_cancel_button_unpress=0;
bool TEXT_paused=0;
bool TEXT_cant_cancel=0;

bool TEXT_led_flicker_is_on=0;



//=========================================================================================================================
int font_index(char c)
{//=========================================================================================================================
	int i=-1;
	switch(c)
	{
		case 'A': {i=CHAR_A; break;}
		case 'B': {i=CHAR_B; break;}
		case 'C': {i=CHAR_C; break;}
		case 'D': {i=CHAR_D; break;}
		case 'E': {i=CHAR_E; break;}
		case 'F': {i=CHAR_F; break;}
		case 'G': {i=CHAR_G; break;}
		case 'H': {i=CHAR_H; break;}
		case 'I': {i=CHAR_I; break;}
		case 'J': {i=CHAR_J; break;}
		case 'K': {i=CHAR_K; break;}
		case 'L': {i=CHAR_L; break;}
		case 'M': {i=CHAR_M; break;}
		case 'N': {i=CHAR_N; break;}
		case 'O': {i=CHAR_O; break;}
		case 'P': {i=CHAR_P; break;}
		case 'Q': {i=CHAR_Q; break;}
		case 'R': {i=CHAR_R; break;}
		case 'S': {i=CHAR_S; break;}
		case 'T': {i=CHAR_T; break;}
		case 'U': {i=CHAR_U; break;}
		case 'V': {i=CHAR_V; break;}
		case 'W': {i=CHAR_W; break;}
		case 'X': {i=CHAR_X; break;}
		case 'Y': {i=CHAR_Y; break;}
		case 'Z': {i=CHAR_Z; break;}
		case 'a': {i=CHAR_a; break;}
		case 'b': {i=CHAR_b; break;}
		case 'c': {i=CHAR_c; break;}
		case 'd': {i=CHAR_d; break;}
		case 'e': {i=CHAR_e; break;}
		case 'f': {i=CHAR_f; break;}
		case 'g': {i=CHAR_g; break;}
		case 'h': {i=CHAR_h; break;}
		case 'i': {i=CHAR_i; break;}
		case 'j': {i=CHAR_j; break;}
		case 'k': {i=CHAR_k; break;}
		case 'l': {i=CHAR_l; break;}
		case 'm': {i=CHAR_m; break;}
		case 'n': {i=CHAR_n; break;}
		case 'o': {i=CHAR_o; break;}
		case 'p': {i=CHAR_p; break;}
		case 'q': {i=CHAR_q; break;}
		case 'r': {i=CHAR_r; break;}
		case 's': {i=CHAR_s; break;}
		case 't': {i=CHAR_t; break;}
		case 'u': {i=CHAR_u; break;}
		case 'v': {i=CHAR_v; break;}
		case 'w': {i=CHAR_w; break;}
		case 'x': {i=CHAR_x; break;}
		case 'y': {i=CHAR_y; break;}
		case 'z': {i=CHAR_z; break;}
		case '.': {i=CHAR_PERIOD; break;}
		case ',': {i=CHAR_COMMA; break;}
		case '\'':{i=CHAR_QUOTE; break;}// /'
		case '’': {i=CHAR_QUOTE; break;}// /'
		case '!': {i=CHAR_EXCLAMATION; break;}
		case '?': {i=CHAR_QUESTIONMARK; break;}
		case '=': {i=CHAR_EQUALS; break;}
		case '\\':{i=CHAR_BACKSLASH; break;}
		case '/': {i=CHAR_FRONTSLASH; break;}
		case '^': {i=CHAR_CARET; break;}
		case '_': {i=CHAR_UNDERSCORE; break;}
		case '&': {i=CHAR_AMPERSAND; break;}
		case '+': {i=CHAR_PLUS; break;}
		case '#': {i=CHAR_POUND; break;}
		case '$': {i=CHAR_DOLLAR; break;}
		case '%': {i=CHAR_PERCENT; break;}
		case '(': {i=CHAR_OPENPARENTHESIS; break;}
		case ')': {i=CHAR_CLOSEPARENTHESIS; break;}
		case '"': {i=CHAR_DOUBLEQUOTE; break;}
		case '*': {i=CHAR_ASTERISK; break;}
		case '-': {i=CHAR_MINUS; break;}
		case ':': {i=CHAR_COLON; break;}
		case ';': {i=CHAR_SEMICOLON; break;}
		case '|': {i=CHAR_PIPE; break;}
		case '`': {i=CHAR_BACKQUOTE; break;}
		case '~': {i=CHAR_TILDE; break;}
		case '@': {i=CHAR_AT; break;}
		case '{': {i=CHAR_OPENCURLYBRACKET; break;}
		case '}': {i=CHAR_CLOSECURLYBRACKET; break;}
		case '[': {i=CHAR_OPENSQUAREBRACKET; break;}
		case ']': {i=CHAR_CLOSESQUAREBRACKET; break;}
		case '0': {i=CHAR_0; break;}
		case '1': {i=CHAR_1; break;}
		case '2': {i=CHAR_2; break;}
		case '3': {i=CHAR_3; break;}
		case '4': {i=CHAR_4; break;}
		case '5': {i=CHAR_5; break;}
		case '6': {i=CHAR_6; break;}
		case '7': {i=CHAR_7; break;}
		case '8': {i=CHAR_8; break;}
		case '9': {i=CHAR_9; break;}

		case 'Ñ': {i=CHAR_dN; break;}
		case 'á': {i=CHAR_aa; break;}
		case 'é': {i=CHAR_ae; break;}
		case 'í': {i=CHAR_ai; break;}
		case 'ó': {i=CHAR_ao; break;}
		case 'ú': {i=CHAR_au; break;}
		case 'ñ': {i=CHAR_dn; break;}
		case '¡': {i=CHAR_iE; break;}
		case '¿': {i=CHAR_iQ; break;}
		case 'É': {i=CHAR_aE; break;}
		case 'Í': {i=CHAR_aI; break;}
		case 'Á': {i=CHAR_aA; break;}

		case '»': {i=CHAR_RR; break;}
		case '«': {i=CHAR_LL; break;}
		case 'â': {i=CHAR_ca; break;}
		case 'ê': {i=CHAR_ce; break;}
		case 'î': {i=CHAR_ci; break;}
		case 'ô': {i=CHAR_co; break;}
		case 'û': {i=CHAR_cu; break;}
		case 'à': {i=CHAR_ga; break;}
		case 'è': {i=CHAR_ge; break;}
		case 'ë': {i=CHAR_de; break;}
		case 'ç': {i=CHAR_cc; break;}
		case 'œ': {i=CHAR_lo; break;}

		case 'Ó': {i=CHAR_aO; break;}
		case 'ù': {i=CHAR_gu; break;}

		case 'Ï': {i=CHAR_dI; break;}
		case 'Ä': {i=CHAR_dA; break;}
		case 'Ö': {i=CHAR_dO; break;}
		case 'Ü': {i=CHAR_dU; break;}
		case 'ä': {i=CHAR_da; break;}
		case 'ö': {i=CHAR_do; break;}
		case 'ü': {i=CHAR_du; break;}
		case 'ß': {i=CHAR_dB; break;}


		case ' ': {i=CHAR_SPACE; break;}

		case '\n':{i=-1;break;}

		default: {i=CHAR_BLOCK;break;}
	}

	return i;
}


//=========================================================================================================================
bool is_a_vowel(char c)
{//=========================================================================================================================
	switch(c)
	{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'y':
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
		case 'Y': return 1;
		default: return 0;
	}
	return 0;
}

//=========================================================================================================================
void TEXT_reset_vars()
{//=========================================================================================================================

	TEXT_font_height	= FONT_NORMAL_HEIGHT;
	TEXT_font_pointer	= FONT_NORMAL_indexed_gfx_data;
	TEXT_font_id= FONT_NORMAL_ID;

	TEXT_color[0] = BLACK;
	TEXT_color[1] = WHITE;
	TEXT_color[2] = DARKGRAY;

	TEXT_clear_text_box_gfx_data(1);
	TEXT_clear_text_box_gfx_data(0);
	TEXT_selected_textbox=0;


	TEXT_textbox[1].activated=0;

	TEXT_textbox[0].screen_x=((GAME_VIEWPORT_WIDTH_PIXELS-(64*3+32))/2)+32;//GAME_VIEWPORT_WIDTH_PIXELS-64*3-16;//80-8-1-32;//original x,-8 right border,- 1 to center the final //iphone hack
	TEXT_textbox[0].screen_y=GAME_VIEWPORT_HEIGHT_PIXELS;

	TEXT_textbox[1].screen_y=-64;

	TEXT_wait_for_cancel_button_unpress=0;

	ACTION_caption_delete();

}

//=========================================================================================================================
void TEXT_update_sprite_window_gfx_data(int box)
{//=========================================================================================================================

	int* gfx_data = (int*)HARDWARE_load_file(TEXT_textbox[box].sprite_window_gfx->FileName);
	int* top_pixel = &TEXT_textbox[box].sprite_window_top_pixel;
	int size_x = TEXT_textbox[box].sprite_window_gfx->data_size_x;
	int size_y = TEXT_textbox[box].sprite_window_gfx->data_size_y;

	//-----------------------------
	//use black from the right palette. i really need to fix this and make them both use 0 clear 1 black, etc
	//-----------------------------
	int black_color = 255;
	if(GLOBAL_hq2x_is_on==0)black_color=1;//uses the normal sprite palette.

	int clear_color = gfx_data[0];

	//-----------------------------
	//clear it
	//-----------------------------
	int q=0;
	for(q=0;q<32*64;q++)TEXT_textbox[box].sprite_window_indexed_gfx_data[q]=black_color;

	//-----------------------------
	//fill in with sprite data, cutting off feet, and replacing transparent with black
	//-----------------------------
		//-----------------------------
		//first find the top pixel of the sprite
		//-----------------------------
		int x=0;
		int y=0;
		*top_pixel=32;

		for(y=0;y<size_y;y++)
			for(x=0;x<size_x;x++)
			{

				int i =  ((64*(x/8))+//skip 64 for each tile x
						(x%8))+//remaining x
						(64*(size_x/8)*(y/8))+//skip 2 x 64 for each tile y
						(8*(y%8));//8 for each row in tile y

				int p = gfx_data[i];

				if(p!=0&&y<*top_pixel)
				{
					*top_pixel=y;
					y=32;
					break;
				}
			}

		//this is so it goes through twice for each pixel if its using an original sprite
		if(GLOBAL_hq2x_is_on==0)size_y*=2;


		int sy=0;
		//-----------------------------
		//starting from the top pixel, fill in the sprite window up to 32 y
		//-----------------------------
		for(y=*top_pixel;y<size_y&&sy<64;y++)
		{
			sy++;
			for(x=0;x<32;x++)
			{
				//-----------------------------
				//get the pixel from the original sprite
				//-----------------------------
					int xx=0;
					int yy=0;

					if(GLOBAL_hq2x_is_on) //we are using a hq2x sprite
					{
						xx=x;
						yy=y;
					}
					else //we are using original sprites at half the size
					{
						//doubled size y above, and half the x and y values each time so it will get the same pixel twice
						xx=floor(x/2);
						yy=floor(y/2);
					}

					int i =  ((64*(xx/8))+//skip 64 for each tile x
							(xx%8))+//remaining x
							(64*(size_x/8)*(yy/8))+//skip 2 x 64 for each tile y
							(8*(yy%8));//8 for each row in tile y

					int p = gfx_data[i];


				//-----------------------------
				//copy the values into the sprite window
				//-----------------------------
				int y2=y-*top_pixel;
				int newi = ((64*(x/8))+//skip 64 for each tile x
						(x%8))+//remaining x
						(64*(32/8)*(y2/8))+//skip 2 x 64 for each tile y
						(8*(y2%8));//8 for each row in tile y

				if(p==0&&y2<63)p = black_color;	//make black
				if(y2==63)p = black_color;	//make bottom row black
				if(y2>63)p = clear_color;	//cut off overhang feet

				TEXT_textbox[box].sprite_window_indexed_gfx_data[newi]=p;

			}
		}

		HARDWARE_unload_file((void**)&gfx_data);

		HARDWARE_update_sprite_texture(TEXT_textbox[box].sprite_window_sprite,0);


}

//=========================================================================================================================
void TEXT_set_sprite_window(int box,NPC* npc,GFX* gfx)
{//=========================================================================================================================

	if(npc!=NULL||gfx!=NULL)
	{
		//if no gfx is input, just take it from the npc
		if(gfx==NULL&&npc!=NULL)gfx=npc->gfx;
		//if there isn't an npc, stay on main sprite. this way just putting in a gfx works, but the camera won't try to move
		if(npc==NULL)npc=PLAYER_npc;

		if(gfx==GFX_KID_yuu)TEXT_textbox[box].voice_pitch=40000;
		if(gfx==GFX_KID_youngyuu)TEXT_textbox[box].voice_pitch=55000;
		if(gfx==GFX_ADULT_mom||gfx==GFX_ADULT_youngmom)TEXT_textbox[box].voice_pitch=70000;
		if(gfx==GFX_ADULT_dad||gfx==GFX_ADULT_youngdad)TEXT_textbox[box].voice_pitch=20000;
		if(gfx==GFX_KID_brother||gfx==GFX_KID_youngbrother)TEXT_textbox[box].voice_pitch=30000;
		if(gfx==GFX_KID_littlebrother)TEXT_textbox[box].voice_pitch=55000;

		if(gfx==GFX_ADULT_bob)TEXT_textbox[box].voice_pitch=37000;
		if(gfx==GFX_ADULT_bobscary)TEXT_textbox[box].voice_pitch=32000;

		if(gfx==GFX_ADULT_bigwig)TEXT_textbox[box].voice_pitch=25000;

		TEXT_textbox[box].sprite_window_npc=npc;
		TEXT_textbox[box].sprite_window_gfx=gfx;

		//if(GLOBAL_text_engine_state!=0)
		{
			TEXT_update_sprite_window_gfx_data(box);

			TEXT_move_sprites();
		}
	}

}

//=========================================================================================================================
void TEXT_init()
{//=========================================================================================================================


	//-----------------------------
	//load fonts
	//-----------------------------
	FONT_NORMAL_indexed_gfx_data=(int*)HARDWARE_load_file("/font/font_normal.bin");
	FONT_HUGE_indexed_gfx_data=(int*)HARDWARE_load_file("/font/font_huge.bin");
	FONT_SMALL_indexed_gfx_data=(int*)HARDWARE_load_file("/font/font_small.bin");
	FONT_TINY_indexed_gfx_data=(int*)HARDWARE_load_file("/font/font_tiny.bin");
	FONT_OUTLINED_indexed_gfx_data=(int*)HARDWARE_load_file("/font/font_outlined.bin");
	FONT_BOB_indexed_gfx_data=(int*)HARDWARE_load_file("/font/font_bob.bin");
	//FONT_JAPANESE_indexed_gfx_data=HARDWARE_load_file("/font/font_japanese.bin");


	//init variables
	int i=0;
	for(i=0;i<2;i++)
	{

		TEXT_textbox[i].screen_x=0;
		TEXT_textbox[i].screen_y=0;
		TEXT_textbox[i].activated=0;
		TEXT_textbox[i].line=0;
		TEXT_textbox[i].tile=0;
		TEXT_textbox[i].chunk=0;
		TEXT_textbox[i].x_in_tile=0;

		TEXT_textbox[i].sprite_window_npc=&main_npc;

		TEXT_textbox[i].sprite_window_gfx=GFX_KID_yuu;

		TEXT_textbox[i].indexed_gfx_data=(int*)malloc(3*64*64*sizeof(int));
		TEXT_textbox[i].sprite_window_indexed_gfx_data=(int*)malloc(32*64*sizeof(int));

		int x=0;
		for(x=0;x<3*64*64;x++)TEXT_textbox[i].indexed_gfx_data[x]=TEXT_color[0];
		for(x=0;x<32*64;x++)TEXT_textbox[i].sprite_window_indexed_gfx_data[x]=TEXT_color[0];

		TEXT_textbox[i].sprite_window_sprite = HARDWARE_create_sprite(TEXTSPRITEWINDOW_GFX[i],0,5,TEXT_scale,TEXT_textbox[i].screen_x-32,GAME_VIEWPORT_HEIGHT_PIXELS,255);

		TEXT_textbox[i].chunk_sprite[0] = HARDWARE_create_sprite(TEXT_GFX[i],0,5,TEXT_scale,(TEXT_textbox[i].screen_x+(64*0)),GAME_VIEWPORT_HEIGHT_PIXELS,255);
		TEXT_textbox[i].chunk_sprite[1] = HARDWARE_create_sprite(TEXT_GFX[i],0,5,TEXT_scale,(TEXT_textbox[i].screen_x+(64*1)),GAME_VIEWPORT_HEIGHT_PIXELS,255);
		TEXT_textbox[i].chunk_sprite[2] = HARDWARE_create_sprite(TEXT_GFX[i],0,5,TEXT_scale,(TEXT_textbox[i].screen_x+(64*2)),GAME_VIEWPORT_HEIGHT_PIXELS,255);
		//TEXT_textbox[i].chunk_sprite[3] = HARDWARE_create_sprite(TEXT_GFX[i],0,1,TEXT_scale,(TEXT_textbox[i].screen_x+(64*3)),GAME_VIEWPORT_HEIGHT_PIXELS);
		///can use this to increase the text window width, also have to increase gfx_data size

		TEXT_textbox[i].button_sprite = NULL;

		TEXT_textbox[i].voice_pitch=40000;

		TEXT_textbox[i].sprite_window_top_pixel=32;

		TEXT_textbox[0].redraw=0;

	}


	//-----------------------------
	//update sprite window gfx
	//-----------------------------
	//dont need to do this here?
	//TEXT_update_sprite_window_gfx_data(0,TEXT_textbox[0].sprite_window_indexed_gfx_array, TEXT_textbox[0].sprite_window_npc->gfx, &TEXT_box_1_sprite_window_top_pixel, TEXT_textbox[0].sprite_window_indexed_gfx_array_size_x, TEXT_textbox[0].sprite_window_indexed_gfx_array_size_y);
	//TEXT_update_sprite_window_gfx_data(1,TEXT_box_2_sprite_window_indexed_gfx_array, TEXT_textbox[1].sprite_window_npc->gfx, &TEXT_box_2_sprite_window_top_pixel, TEXT_box_2_sprite_window_indexed_gfx_array_size_x, TEXT_box_2_sprite_window_indexed_gfx_array_size_y);


}

//=========================================================================================================================
void TEXT_close_textbox()
{//=========================================================================================================================

	GLOBAL_camera_fx_bounds_off=0;
	cameraman_target=PLAYER_npc;
	TEXT_textbox[0].sprite_window_npc=PLAYER_npc;
	TEXT_textbox[1].sprite_window_npc=PLAYER_npc;
	cameraman->walking_speed=SPEED_FASTER;


	TEXT_clear_text_box_gfx_data(1);
	TEXT_clear_text_box_gfx_data(0);

	TEXT_selected_textbox=0;

	TEXT_drawing_paused=0;

	TEXT_textbox[0].redraw=1;
	TEXT_textbox[1].redraw=1;

	//TEXT_update_textbox_sprite_textures();

	/*HARDWARE_delete_sprite(1,TEXT_box_1_sprite_window_id);
	HARDWARE_delete_sprite(1,TEXT_box_1_chunk_1_id);
	HARDWARE_delete_sprite(1,TEXT_box_1_chunk_2_id);
	HARDWARE_delete_sprite(1,TEXT_box_1_chunk_3_id);

	HARDWARE_delete_sprite(1,TEXT_box_2_sprite_window_id);
	HARDWARE_delete_sprite(1,TEXT_box_2_chunk_1_id);
	HARDWARE_delete_sprite(1,TEXT_box_2_chunk_2_id);
	HARDWARE_delete_sprite(1,TEXT_box_2_chunk_3_id);

	HARDWARE_delete_sprite_gfxslot(1,TEXT_textbox[0].sprite_window_indexed_gfx_array);
	HARDWARE_delete_sprite_gfxslot(1,TEXT_box_1_chunk_1_gfx);
	HARDWARE_delete_sprite_gfxslot(1,TEXT_box_1_chunk_2_gfx);
	HARDWARE_delete_sprite_gfxslot(1,TEXT_box_1_chunk_3_gfx);

	HARDWARE_delete_sprite_gfxslot(1,TEXT_box_2_sprite_window_indexed_gfx_array);
	HARDWARE_delete_sprite_gfxslot(1,TEXT_box_2_chunk_1_gfx);
	HARDWARE_delete_sprite_gfxslot(1,TEXT_box_2_chunk_2_gfx);
	HARDWARE_delete_sprite_gfxslot(1,TEXT_box_2_chunk_3_gfx);*/

	TEXT_textbox[1].activated=0;
	GLOBAL_text_engine_state=0;
}

//=========================================================================================================================
void TEXT_move_sprites()
{//=========================================================================================================================
	HARDWARE_set_sprite_xy(TEXT_textbox[0].chunk_sprite[0],TEXT_textbox[0].screen_x+(64*0),TEXT_textbox[0].screen_y);
	HARDWARE_set_sprite_xy(TEXT_textbox[0].chunk_sprite[1],TEXT_textbox[0].screen_x+(64*1),TEXT_textbox[0].screen_y);
	HARDWARE_set_sprite_xy(TEXT_textbox[0].chunk_sprite[2],TEXT_textbox[0].screen_x+(64*2),TEXT_textbox[0].screen_y);

	HARDWARE_set_sprite_xy(TEXT_textbox[0].sprite_window_sprite,TEXT_textbox[0].screen_x-32,TEXT_textbox[0].screen_y);//-(TEXT_box_1_sprite_window_top_pixel*2)); //iphone hack

	HARDWARE_set_sprite_xy(TEXT_textbox[1].chunk_sprite[0],TEXT_textbox[0].screen_x+(64*0),TEXT_textbox[1].screen_y);
	HARDWARE_set_sprite_xy(TEXT_textbox[1].chunk_sprite[1],TEXT_textbox[0].screen_x+(64*1),TEXT_textbox[1].screen_y);
	HARDWARE_set_sprite_xy(TEXT_textbox[1].chunk_sprite[2],TEXT_textbox[0].screen_x+(64*2),TEXT_textbox[1].screen_y);

	HARDWARE_set_sprite_xy(TEXT_textbox[1].sprite_window_sprite,TEXT_textbox[0].screen_x-32,TEXT_textbox[1].screen_y);//-(TEXT_box_2_sprite_window_top_pixel*2)); //iphone hack

}

//=========================================================================================================================
void TEXT_update_textbox_sprite_textures()
{//=========================================================================================================================

	if(TEXT_textbox[0].redraw==1)
	{
		HARDWARE_update_sprite_texture(TEXT_textbox[0].chunk_sprite[0],(64*64*0));
		HARDWARE_update_sprite_texture(TEXT_textbox[0].chunk_sprite[1],(64*64*1));
		HARDWARE_update_sprite_texture(TEXT_textbox[0].chunk_sprite[2],(64*64*2));
		TEXT_textbox[0].redraw=0;
	}

	if(TEXT_textbox[1].redraw==1)
	{
		HARDWARE_update_sprite_texture(TEXT_textbox[1].chunk_sprite[0],(64*64*0));
		HARDWARE_update_sprite_texture(TEXT_textbox[1].chunk_sprite[1],(64*64*1));
		HARDWARE_update_sprite_texture(TEXT_textbox[1].chunk_sprite[2],(64*64*2));
		TEXT_textbox[1].redraw=0;
	}
}



//=========================================================================================================================
void TEXT_clear_text_box_gfx_data(int box)
{//=========================================================================================================================
	int x;
	for(x=0; x<64*64*3; x++)
	{
		TEXT_textbox[box].indexed_gfx_data[x]=TEXT_color[0];
	}
}



//=========================================================================================================================
int TEXT_get_letter_pixel_color(int letter_index, int y, int x_in_letter, int blank)
{//=========================================================================================================================

	if(blank==1)return TEXT_color[0];

	return TEXT_color[TEXT_font_pointer[(letter_index*16*16)+(y*16)+x_in_letter]];


}

//=========================================================================================================================
void TEXT_draw_column(int letter_index,int x_in_letter,int blank)
{//=========================================================================================================================

	int b = TEXT_selected_textbox;
	int* gfx = TEXT_textbox[b].indexed_gfx_data;

	int line=TEXT_textbox[b].line;
	int tile=TEXT_textbox[b].tile;
	int chunk=TEXT_textbox[b].chunk;
	int x_in_tile=TEXT_textbox[b].x_in_tile;

	int y=0;
	int h = TEXT_font_height;

	if(line==0)//SPLIT FOR LINE 1
	{
		for(y=0; y<6	&&	y<h; y++)	gfx[( ((8*2) + (8*(y-0 )) + x_in_tile) + (tile*64) + (chunk*64*64) + (64*8*0) )] = TEXT_get_letter_pixel_color(letter_index,y,x_in_letter,blank);
		for(y=6; y<12	&&	y<h; y++)	gfx[( ((8*0) + (8*(y-6 )) + x_in_tile) + (tile*64) + (chunk*64*64) + (64*8*1) )] = TEXT_get_letter_pixel_color(letter_index,y,x_in_letter,blank);
	}

	if(line==1)//SPLIT FOR LINE
	{
		for(y=0; y<2	&&	y<h; y++)	gfx[( ((8*6) + (8*(y-0 )) + x_in_tile) + (tile*64) + (chunk*64*64) + (64*8*1) )] = TEXT_get_letter_pixel_color(letter_index,y,x_in_letter,blank);
		for(y=2; y<10	&&	y<h; y++)	gfx[( ((8*0) + (8*(y-2 )) + x_in_tile) + (tile*64) + (chunk*64*64) + (64*8*2) )] = TEXT_get_letter_pixel_color(letter_index,y,x_in_letter,blank);
		for(y=10; y<12	&&	y<h; y++)	gfx[( ((8*0) + (8*(y-10)) + x_in_tile) + (tile*64) + (chunk*64*64) + (64*8*3) )] = TEXT_get_letter_pixel_color(letter_index,y,x_in_letter,blank);
	}

	if(line==2)//SPLIT FOR LINE
	{
		for(y=0; y<6	&&	y<h; y++)	gfx[( ((8*2) + (8*(y-0 )) + x_in_tile) + (tile*64) + (chunk*64*64) + (64*8*3) )] = TEXT_get_letter_pixel_color(letter_index,y,x_in_letter,blank);
		for(y=6; y<12	&&	y<h; y++)	gfx[( ((8*0) + (8*(y-6 )) + x_in_tile) + (tile*64) + (chunk*64*64) + (64*8*4) )] = TEXT_get_letter_pixel_color(letter_index,y,x_in_letter,blank);
	}

	if(line==3)//SPLIT FOR LINE
	{
		for(y=0; y<2	&&	y<h; y++)	gfx[( ((8*6) + (8*(y-0 )) + x_in_tile) + (tile*64) + (chunk*64*64) + (64*8*4) )] = TEXT_get_letter_pixel_color(letter_index,y,x_in_letter,blank);
		for(y=2; y<10	&&	y<h; y++)	gfx[( ((8*0) + (8*(y-2 )) + x_in_tile) + (tile*64) + (chunk*64*64) + (64*8*5) )] = TEXT_get_letter_pixel_color(letter_index,y,x_in_letter,blank);
		for(y=10; y<12	&&	y<h; y++)	gfx[( ((8*0) + (8*(y-10)) + x_in_tile) + (tile*64) + (chunk*64*64) + (64*8*6) )] = TEXT_get_letter_pixel_color(letter_index,y,x_in_letter,blank);
	}

	if(line==4)//SPLIT FOR LINE
	{
		for(y=0; y<6	&&	y<h; y++)	gfx[( ((8*2) + (8*(y-0 )) + x_in_tile) + (tile*64) + (chunk*64*64) + (64*8*6) )] = TEXT_get_letter_pixel_color(letter_index,y,x_in_letter,blank);
		for(y=6; y<12	&&	y<h; y++)	gfx[( ((8*0) + (8*(y-6 )) + x_in_tile) + (tile*64) + (chunk*64*64) + (64*8*7) )] = TEXT_get_letter_pixel_color(letter_index,y,x_in_letter,blank);
	}

}



//=========================================================================================================================
int TEXT_get_char_width(int letter_index)
{//=========================================================================================================================

	if(letter_index==-1)return 0;

	int x=0;
	int y=0;
	int w=0;
	for(x=15;x>=0;x--)
		for(y=0;y<TEXT_font_height;y++)
			if(TEXT_font_pointer[(letter_index*16*16)+(y*16)+x]!=0){w=x+1;x=-1;y=TEXT_font_height;break;}

	if(letter_index==font_index(' '))w=3;//WIDTH OF SPACE IS DETERMINED HERE

	return w;
}



//=========================================================================================================================
void TEXT_draw_letter()
{//=========================================================================================================================


	int letter_index = font_index(TEXT_text[TEXT_string_position]);
	if(letter_index==-1)return;

	char* text = TEXT_text;

	int letter_width = TEXT_get_char_width(letter_index);

	int b = TEXT_selected_textbox;


	//play sound sometimes, for vowels
	if(
		(
			TEXT_textbox[b].chunk==0&&
			TEXT_textbox[b].x_in_tile==0&&
			TEXT_textbox[b].tile==0&&
			TEXT_textbox[b].line==0
		)
		||
		(
			TEXT_string_position%2==0
			&&
			TEXT_string_position<TEXT_length-1
			&&
			(
				is_a_vowel(text[TEXT_string_position-1])!=is_a_vowel(text[TEXT_string_position])
				||
				is_a_vowel(text[TEXT_string_position])!=is_a_vowel(text[TEXT_string_position+1])
			)
		)
	)
	{
		if(TEXT_font_id==FONT_BOB_ID||TEXT_font_id==FONT_HUGE_ID)
		{
			HARDWARE_play_sound("blah",127,TEXT_textbox[b].voice_pitch+(rand()%20000)+10000,0);
		}
		else
		{
			HARDWARE_play_sound("blah",127,TEXT_textbox[b].voice_pitch+(rand()%20000),0);
		}

		TEXT_delay_is_on=1;///why do i do this? slight delay on vowels so the sound has time to play?
		TEXT_delay_counter=3;
	}


	int put_in_space_already=0;

	int x_in_letter=0;
	for (x_in_letter=0; x_in_letter<letter_width; x_in_letter++)
	{

		if(TEXT_textbox[b].x_in_tile>7)
		{
			TEXT_textbox[b].x_in_tile=0;
			TEXT_textbox[b].tile++;
		}

		if(TEXT_textbox[b].tile>7)
		{
			TEXT_textbox[b].tile=0;
			TEXT_textbox[b].x_in_tile=0;
			TEXT_textbox[b].chunk++;
		}

		if(TEXT_textbox[b].chunk>2)
		{
			TEXT_textbox[b].chunk=0;
			TEXT_textbox[b].x_in_tile=0;
			TEXT_textbox[b].tile=0;
			TEXT_textbox[b].line++;
		}

		if(TEXT_textbox[b].line>4)
		{
			//PAUSE,CLEAR,START OVER
			TEXT_waiting_for_button_input=1;
		}


		//it it's a space on the last tile/chunk/pixel, skip it
		if(text[TEXT_string_position]==' '&&TEXT_textbox[b].tile>7&&TEXT_textbox[b].chunk==2&&TEXT_textbox[b].x_in_tile>7)
		{
			TEXT_textbox[b].chunk=0;
			TEXT_textbox[b].x_in_tile=0;
			TEXT_textbox[b].tile=0;
			TEXT_textbox[b].line++;

			x_in_letter=letter_width;

			put_in_space_already=1;

			if(TEXT_textbox[b].line>4)
			{
				TEXT_waiting_for_button_input=1;
			}
		}

		if(TEXT_waiting_for_button_input==0&&put_in_space_already==0)
		{
			TEXT_draw_column(letter_index,x_in_letter,0);
			TEXT_textbox[b].x_in_tile++;
		}
	}



	//===================================INSERT SPACE
	//if(text[TEXT_string_position]==' ')put_in_space_already=1;	breaks the pixel length count.. i'd have to make it width-1 in get_text_length



	if(TEXT_textbox[b].line<5 && TEXT_textbox[b].chunk<3 && TEXT_textbox[b].tile<8 && TEXT_textbox[b].x_in_tile<8 && !put_in_space_already)
	{
		TEXT_draw_column(0,0,1);
		TEXT_textbox[b].x_in_tile++;
		put_in_space_already=1;
	}

	if(TEXT_textbox[b].x_in_tile>7)
	{
		if(put_in_space_already)
		{
			TEXT_textbox[b].x_in_tile=0;
			TEXT_textbox[b].tile++;
		}
		else
		{
			TEXT_textbox[b].x_in_tile=0;
			TEXT_textbox[b].tile++;
			if(TEXT_textbox[b].tile<8)TEXT_draw_column(0,0,1);
			TEXT_textbox[b].x_in_tile=1;
		}

	}


	if(TEXT_textbox[b].tile>7)
	{
		TEXT_textbox[b].tile=0;

		if(put_in_space_already)
		{
			TEXT_textbox[b].chunk++;
			TEXT_textbox[b].x_in_tile=0;
		}
		else
		{
			TEXT_textbox[b].chunk++;
			TEXT_textbox[b].x_in_tile=0;
			if(TEXT_textbox[b].chunk<3)TEXT_draw_column(0,0,1);
			TEXT_textbox[b].x_in_tile=1;
		}
	}


	if(TEXT_textbox[b].chunk>2)
	{
		TEXT_textbox[b].chunk=0;
		TEXT_textbox[b].x_in_tile=0;
		TEXT_textbox[b].tile=0;
		TEXT_textbox[b].line++;
	}

	if(TEXT_textbox[b].line>4)
	{
		//PAUSE,CLEAR,START OVER
		TEXT_waiting_for_button_input=1;
	}


	//END INSERT SPACE===================================================================
	///TEXT_update_textbox_sprite_textures();
	TEXT_textbox[b].redraw=1;

}

//=========================================================================================================================
int TEXT_get_next_word_length()
{//=========================================================================================================================

	char* text = TEXT_text;
	int temp_position=TEXT_string_position;
	int next_word_length=0;

	while(
			//we should be starting on a space or the beginning of the test. include the starting space, up to the next space
			(text[temp_position]!=' '||temp_position==TEXT_string_position)//if it's the start of the string or it's not a space
			&&
			!(text[temp_position]=='<'&&text[temp_position+1]=='.')//newline
			&&
			!(text[temp_position]=='<'&&text[temp_position+1]=='N'&&text[temp_position+2]=='E')//newline?
			&&
			temp_position<TEXT_length
	)

	{
		//skip over tags
		if(text[temp_position]=='<'){int x=0; while(temp_position+x<TEXT_length&&text[temp_position+x]!='>'){x++;} temp_position+=x; next_word_length--;}

		next_word_length+=TEXT_get_char_width(font_index(text[temp_position]));

		//add a space between letters
		next_word_length++;

		temp_position++;
	}

	//THIS SKIPS WORDS LONGER THEN THE MAXIMUM LENGTH
	if(next_word_length>(64*3))
	{
		TEXT_string_position=temp_position;
		ERROR_set_error("a word was too long for the text engine.");
		return TEXT_get_next_word_length();
	}

	return next_word_length;
}

//=========================================================================================================================
void TEXT_main()//meant to be called from GAME_update so it doesnt lock up the main loop
{//=========================================================================================================================
	TEXT_window(NULL);//meant to be called from GAME_update so it doesnt lock up the main loop
}


//=========================================================================================================================
void TEXT_window(const char* temptext)//meant to be called from GAME_update so it doesnt lock up the main loop
{//=========================================================================================================================
	if(TEXT_deinit==1){TEXT_close_textbox();TEXT_deinit=0;}

	//-----------------------------
	//if the text pointer is empty, fill it with a new string
	//-----------------------------
	if(TEXT_text==NULL)
	{
		//make sure we are sending in a string
		if(temptext!=NULL)
		{
			TEXT_length=strlen(temptext);
			//make a string buffer to hold the temporary text coming in
			TEXT_text = (char*) malloc((TEXT_length+1)*sizeof(char));
			strcpy(TEXT_text,temptext);

		}
	}

	//-----------------------------
	//if there's new text, the text window is off, and it's not paused, start the text engine
	//-----------------------------
	if(TEXT_text!=NULL&&TEXT_string_position==0&&GLOBAL_text_engine_state==0&&TEXT_drawing_paused==0)
	{
		TEXT_reset_vars();

		//zoom the camera to the talking NPC
		cameraman_target=TEXT_textbox[0].sprite_window_npc;
		cameraman->walking_speed=SPEED_FASTER;
		GLOBAL_camera_fx_bounds_off=1;//avoid camera boundaries

		TEXT_drawing_paused=1;//wait for the text box to scroll up before drawing text in it.
		GLOBAL_text_engine_state=1;//text box is open

		HARDWARE_play_sound("blah",127,TEXT_textbox[TEXT_selected_textbox].voice_pitch+(rand()%20000),0);
	}

	//-----------------------------
	//if there's new text, the box is open, and it's set to stay open, draw the text into it
	//this is for sending another text string into an already-open text box.
	//-----------------------------
	if(TEXT_text!=NULL&&TEXT_string_position==0&&GLOBAL_text_engine_state==1&&TEXT_keep_text_box_open_for_more_text==1)
	{
		TEXT_keep_text_box_open_for_more_text=0;

		//start a new line of text.
		TEXT_textbox[TEXT_selected_textbox].chunk=0;
		TEXT_textbox[TEXT_selected_textbox].x_in_tile=0;
		TEXT_textbox[TEXT_selected_textbox].tile=0;
		TEXT_textbox[TEXT_selected_textbox].line++;
		if(TEXT_textbox[TEXT_selected_textbox].line>4)
		{
			TEXT_waiting_for_button_input=1;
		}

	}

	//-----------------------------
	//parse options (even if the text box is paused)
	//-----------------------------
	if(TEXT_text!=NULL)
	{
		if(
			TEXT_text[TEXT_string_position]=='<'
			&&
			GLOBAL_text_engine_state==1
			&&
			TEXT_waiting_for_button_input==0
			&&
			TEXT_paused==0
		)
		{
			TEXT_parse_options();
			TEXT_string_position++;
		}
	}

	//-----------------------------
	//draw text
	//-----------------------------
	if(TEXT_text!=NULL&&GLOBAL_text_engine_state==1&&TEXT_drawing_paused==0)
	{

		//-----------------------------
		//draw text
		//-----------------------------
		if(TEXT_string_position<TEXT_length&&TEXT_waiting_for_button_input==0&&TEXT_paused==0)
		{

			//automatically colorize "Yuu"
			if(TEXT_string_position<TEXT_length-2)
			if(TEXT_text[TEXT_string_position]=='Y'&&TEXT_text[TEXT_string_position+1]=='u'&&TEXT_text[TEXT_string_position+2]=='u')
			{
				TEXT_color[1] = PURPLE;
				if(TEXT_color[0]==BLACK)TEXT_color[2]=TEXT_color[1]+1;else TEXT_color[2]=TEXT_color[1]-1;
			}


			//parse option tags
			//this should never happen, it should be parsed above.
			if(TEXT_text[TEXT_string_position]=='<')
			{
				TEXT_parse_options();
				ERROR_set_error("tag parsed inside draw text.");
			}

			else

			//-----------------------------
			//handle space
			//-----------------------------
			if(TEXT_text[TEXT_string_position]==' ')
			{

				//get next word length including the space
				int next_word_length = TEXT_get_next_word_length();

				//see if it fits on the current line
				int pixels_left_in_line = (3*64)-((8*TEXT_textbox[TEXT_selected_textbox].tile)+(64*TEXT_textbox[TEXT_selected_textbox].chunk)+(TEXT_textbox[TEXT_selected_textbox].x_in_tile));
				if(TEXT_textbox[TEXT_selected_textbox].line==4)pixels_left_in_line-=8; //for the text button icon

				//if it doesnt fit, go to the next line
				if(pixels_left_in_line<next_word_length)
				{
					TEXT_textbox[TEXT_selected_textbox].chunk=0;
					TEXT_textbox[TEXT_selected_textbox].x_in_tile=0;
					TEXT_textbox[TEXT_selected_textbox].tile=0;
					TEXT_textbox[TEXT_selected_textbox].line++;

					//if we're on the last line, wait for input
					if(TEXT_textbox[TEXT_selected_textbox].line>4)
					{
						TEXT_waiting_for_button_input=1;
					}
				}

				//play a sound for each word. if the last word was a question, raise voice.
				//if(text[temp_position-1]=='?')HARDWARE_play_sound(MAX_AUDIO_CHANNELS-1,"blah",127,TEXT_textbox[TEXT_selected_textbox].voice_pitch+(30000),0);
				//else HARDWARE_play_sound(MAX_AUDIO_CHANNELS-1,"blah",127,TEXT_textbox[TEXT_selected_textbox].voice_pitch+(rand()%20000),0);


				//only draw the space if we're not at the beginning of the text box
				if(TEXT_textbox[TEXT_selected_textbox].x_in_tile!=0||TEXT_textbox[TEXT_selected_textbox].tile!=0||TEXT_textbox[TEXT_selected_textbox].chunk!=0)
				TEXT_draw_letter();

			}
			else
			{
				//if TEXT_font_pointer<FONT_JAPANESE
				TEXT_draw_letter();
			}


			//automatically colorize "Yuu" back to white
			if(TEXT_string_position>=2)
			if(TEXT_text[TEXT_string_position-2]=='Y'&&TEXT_text[TEXT_string_position-1]=='u'&&TEXT_text[TEXT_string_position]=='u')
			{
				TEXT_color[0] = BLACK;
				TEXT_color[1] = WHITE;
				TEXT_color[2] = GRAY;
			}


			TEXT_string_position++;


		}

		if(TEXT_waiting_for_button_input==1)
		{

				if(BUTTON_B_HELD&&TEXT_wait_for_cancel_button_unpress!=1)
				{
					TEXT_wait_for_cancel_button_unpress=1;
					HARDWARE_play_sound("blip",63,22050,0);
				}



				if(TEXT_wait_for_cancel_button_unpress==1)
				{
					if(!BUTTON_B_HELD)
					{
						TEXT_wait_for_cancel_button_unpress=0;
						if(TEXT_cant_cancel==0)
							{
								TEXT_waiting_for_input_to_close=1;
								TEXT_wait_for_unpress=1;
								TEXT_paused=0;
							}
					}
				}



				if(TEXT_button_icon_is_on==0)
				{

					//text_button_icon_1_gfx = HARDWARE_create_sprite_gfxslot(1,TEXT_button_icon_GFX,0,8,8,1,0);
					//{
						if(TEXT_selected_textbox==0)
						{

							TEXT_textbox[0].button_sprite = HARDWARE_create_sprite(TEXT_button_icon_GFX,0,1,1.0f,TEXT_textbox[0].screen_x+(64*3)-8,TEXT_textbox[0].screen_y+64-8-2,255);
							//HARDWARE_create_sprite(TEXT_button_icon_1_id,TEXT_button_icon_1_gfx,8,8,1,0,0,0,0,0,1,0,TEXT_textbox[0].screen_x+(64*3)-8,TEXT_textbox[0].screen_y+64-8-2);

						}


						if(TEXT_selected_textbox==1)
						{

							TEXT_textbox[0].button_sprite = HARDWARE_create_sprite(TEXT_button_icon_GFX,0,1,1.0f,TEXT_textbox[0].screen_x+(64*3)-8,TEXT_textbox[1].screen_y+64-8-2,255);
							//HARDWARE_create_sprite(TEXT_button_icon_1_id,TEXT_button_icon_1_gfx,8,8,1,0,0,0,0,0,1,0,TEXT_textbox[0].screen_x+(64*3)-8,TEXT_textbox[1].screen_y+64-8-2);
						}
					//}
					TEXT_button_icon_is_on=1;

				}




				if(
				(BUTTON_ACTION_HELD||TouchScreen.Held||skiptext)&&
				TEXT_wait_for_unpress!=1)
				{
					TEXT_wait_for_unpress=1;

					HARDWARE_play_sound("blip",63,70000,0);

				}



				if(TEXT_wait_for_unpress==1)
				{
					if((!BUTTON_ACTION_HELD&&!TouchScreen.Held)||skiptext)
					{
						TEXT_wait_for_unpress=0;
						TEXT_a_unpressed=1;
					}
				}



				if(TEXT_a_unpressed==1)
				{

						if(TEXT_button_icon_is_on)
						{
							TEXT_button_icon_is_on=0;
							HARDWARE_delete_sprite(TEXT_textbox[0].button_sprite);
							//HARDWARE_delete_sprite_gfxslot(1,TEXT_button_icon_1_gfx);
						}


						TEXT_a_unpressed=0;
						TEXT_clear_text_box_gfx_data(TEXT_selected_textbox);

						if(TEXT_waiting_for_input_to_close!=1&&GLOBAL_text_engine_state!=2)
						{
							///TEXT_update_textbox_sprite_textures();
							TEXT_textbox[TEXT_selected_textbox].redraw=1;
						}

						TEXT_textbox[TEXT_selected_textbox].line=0;
						TEXT_textbox[TEXT_selected_textbox].tile=0;
						TEXT_textbox[TEXT_selected_textbox].chunk=0;
						TEXT_textbox[TEXT_selected_textbox].x_in_tile=0;

						TEXT_waiting_for_button_input=0;
					}
		}



		if(TEXT_paused==1)
		{
			if(BUTTON_B_HELD&&TEXT_wait_for_cancel_button_unpress!=1)
			{
				TEXT_wait_for_cancel_button_unpress=1;


				HARDWARE_play_sound("blip",63,22050,0);


			}
			if(TEXT_wait_for_cancel_button_unpress==1)
			{
				if(!BUTTON_B_HELD)
				{
					TEXT_wait_for_cancel_button_unpress=0;
					if(TEXT_cant_cancel==0)
						{
							TEXT_waiting_for_input_to_close=1;
						TEXT_wait_for_unpress=1;
						}
				}
			}
			if(TEXT_button_icon_is_on==0)
			{

				//text_button_icon_1_gfx = HARDWARE_create_sprite_gfxslot(1,TEXT_button_icon_GFX,0,8,8,1,0);

						if(TEXT_selected_textbox==0)
						{

							TEXT_textbox[0].button_sprite = HARDWARE_create_sprite(TEXT_button_icon_GFX,0,1,1.0f,TEXT_textbox[0].screen_x+(64*3)-8,TEXT_textbox[0].screen_y+64-8-2,255);
							//HARDWARE_create_sprite(TEXT_button_icon_1_id,TEXT_button_icon_1_gfx,8,8,1,0,0,0,0,0,1,0,TEXT_textbox[0].screen_x+(64*3)-8,TEXT_textbox[0].screen_y+64-8-2);

						}


						if(TEXT_selected_textbox==1)
						{

							TEXT_textbox[0].button_sprite = HARDWARE_create_sprite(TEXT_button_icon_GFX,0,1,1.0f,TEXT_textbox[0].screen_x+(64*3)-8,TEXT_textbox[1].screen_y+64-8-2,255);
							//HARDWARE_create_sprite(TEXT_button_icon_1_id,TEXT_button_icon_1_gfx,8,8,1,0,0,0,0,0,1,0,TEXT_textbox[0].screen_x+(64*3)-8,TEXT_textbox[1].screen_y+64-8-2);
						}

				//if(TEXT_selected_textbox==0)HARDWARE_create_sprite(1,TEXT_button_icon_1_id,TEXT_button_icon_1_gfx,8,8,1,0,0,0,0,0,1,0,TEXT_textbox[0].screen_x+(64*3)-8,TEXT_textbox[0].screen_y+64-8-2);
				//if(TEXT_selected_textbox==1)HARDWARE_create_sprite(1,TEXT_button_icon_1_id,TEXT_button_icon_1_gfx,8,8,1,0,0,0,0,0,1,0,TEXT_textbox[0].screen_x+(64*3)-8,TEXT_textbox[1].screen_y+64-8-2-12);

				TEXT_button_icon_is_on=1;

			}
			if(
			(BUTTON_ACTION_HELD||TouchScreen.Held||skiptext)&&
			TEXT_wait_for_unpress!=1)
			{
				TEXT_wait_for_unpress=1;

				HARDWARE_play_sound("blip",63,70000,0);

			}
			if(TEXT_wait_for_unpress==1)
			{
				if((!BUTTON_ACTION_HELD&&!TouchScreen.Held)||skiptext)
				{
					TEXT_wait_for_unpress=0;
					TEXT_a_unpressed=1;
				}
			}
			if(TEXT_a_unpressed==1)
			{
				TEXT_paused=0;
				if(TEXT_button_icon_is_on)
				{

					TEXT_button_icon_is_on=0;

					HARDWARE_delete_sprite(TEXT_textbox[0].button_sprite);
					//HARDWARE_delete_sprite_gfxslot(1,TEXT_button_icon_1_gfx);
				}

				TEXT_a_unpressed=0;
				}
		}



		if(TEXT_string_position>=TEXT_length&&TEXT_waiting_for_input_to_close==0)
		{
			if(TEXT_keep_text_box_open_for_more_text==0)
			{
				TEXT_waiting_for_button_input=1;
				TEXT_waiting_for_input_to_close=1;
			}
			else
			{
				if(TEXT_text!=NULL)free(TEXT_text);///set text string to log
				TEXT_text = NULL;

				///log conversations, parse NPC names
				///log entered room name
				///log items, interactions

				TEXT_string_position=0;
			}
		}




		if(TEXT_waiting_for_input_to_close==1&&TEXT_waiting_for_button_input==0)
		{
			TEXT_waiting_for_input_to_close=0;

			if(TEXT_text!=NULL)free(TEXT_text);///set text string to log
			TEXT_text = NULL;

			TEXT_string_position=0;

			TEXT_cant_cancel=0;
			TEXT_paused=0;

			GLOBAL_text_engine_state=2;
			TEXT_textbox[1].activated=0;

		}
	}


}





//=========================================================================================================================
void TEXT_vbl()
{//=========================================================================================================================
	TEXT_vbl_count++;

	bool TEXT_scrolling_up=0;
//	bool TEXT_scrolling_right=0;
//	bool TEXT_scrolling_left=0;

/*
	TEXT_scale = 1.0f;
	HARDWARE_sprite_set_scale(1,TEXT_box_1_sprite_window_id,TEXT_scale*2);
	HARDWARE_sprite_set_scale(1,TEXT_box_2_sprite_window_id,TEXT_scale*2);
	HARDWARE_sprite_set_scale(1,TEXT_box_1_chunk_1_id,TEXT_scale);
	HARDWARE_sprite_set_scale(1,TEXT_box_1_chunk_2_id,TEXT_scale);
	HARDWARE_sprite_set_scale(1,TEXT_box_1_chunk_3_id,TEXT_scale);
	HARDWARE_sprite_set_scale(1,TEXT_box_2_chunk_1_id,TEXT_scale);
	HARDWARE_sprite_set_scale(1,TEXT_box_2_chunk_2_id,TEXT_scale);
	HARDWARE_sprite_set_scale(1,TEXT_box_2_chunk_3_id,TEXT_scale);
*/

	if(TEXT_textbox[1].activated&&TEXT_textbox[1].screen_y!=10)
	{
		TEXT_textbox[1].screen_y+=4;
		if(TEXT_textbox[1].screen_y>GAME_VIEWPORT_HEIGHT_PIXELS)TEXT_textbox[1].screen_y=0;
		if(TEXT_textbox[1].screen_y>10&&TEXT_textbox[1].screen_y<16)TEXT_textbox[1].screen_y=10;
		TEXT_move_sprites();
	}


	if(TEXT_textbox[1].activated==0&&TEXT_textbox[1].screen_y!=-64)//GAME_VIEWPORT_HEIGHT_PIXELS) iphone hack, remove -32
	{
		TEXT_textbox[1].screen_y-=4;
		//if(TEXT_textbox[1].screen_y<0)TEXT_textbox[1].screen_y=GAME_VIEWPORT_HEIGHT_PIXELS+TEXT_textbox[1].screen_y; iphone hack, uncomment
		//if(TEXT_textbox[1].screen_y<GAME_VIEWPORT_HEIGHT_PIXELS+4&&TEXT_textbox[1].screen_y>16)TEXT_textbox[1].screen_y=GAME_VIEWPORT_HEIGHT_PIXELS; iphone hack
		if(TEXT_textbox[1].screen_y<-64)TEXT_textbox[1].screen_y=-64;//iphone hack, delete this line
		TEXT_move_sprites();
	}

	if(GLOBAL_text_engine_state==3) //ANSWER BOX TURNED ON,SCROLL TEXT BOX UP,ANSWER BOX UP
	{


		if(TEXT_textbox[0].screen_y>GAME_VIEWPORT_HEIGHT_PIXELS-64-8-(11*TEXTANSWER_number_of_answers)-2)
		{
			TEXT_textbox[0].screen_y-=3;
			if(TEXT_textbox[0].screen_y<GAME_VIEWPORT_HEIGHT_PIXELS-64-8-(11*TEXTANSWER_number_of_answers)-2)TEXT_textbox[0].screen_y=GAME_VIEWPORT_HEIGHT_PIXELS-64-8-(11*TEXTANSWER_number_of_answers)-2;
			TEXT_move_sprites();
		}

		if(TEXT_textbox[0].screen_y==GAME_VIEWPORT_HEIGHT_PIXELS-64-8-(11*TEXTANSWER_number_of_answers)-2)
		{
			if(TEXTANSWER_answerbox_y>TEXT_textbox[0].screen_y+64+8-2)
			{
				TEXTANSWER_answerbox_y-=4;
				if(TEXTANSWER_answerbox_y<TEXT_textbox[0].screen_y+64+8-2)TEXTANSWER_answerbox_y=TEXT_textbox[0].screen_y+64+8-2;
				TEXTANSWER_move_answerbox();
			}
		}

		if(TEXTANSWER_selected_answer!=0)if(TEXTANSWER_cursor_sprite!=NULL)TEXTANSWER_cursor_sprite->screen_y=TEXTANSWER_answerbox_y+1+((TEXTANSWER_selected_answer-1)*11);


		static bool pixel=1;
		if(TEXT_vbl_count%20==0)
		{
			if(pixel)
			{
				//HARDWARE_set_sprite_x(TEXTANSWER_cursor_sprite,TEXT_textbox[0].screen_x+(64*3)-(64*TEXTANSWER_amt_of_chunks)-8-1);
				if(TEXTANSWER_cursor_sprite!=NULL)TEXTANSWER_cursor_sprite->screen_x=TEXT_textbox[0].screen_x+(64*3)-(64*TEXTANSWER_amt_of_chunks)-8-1;
			}
			else
			{
				//HARDWARE_set_sprite_x(TEXTANSWER_cursor_sprite,TEXT_textbox[0].screen_x+(64*3)-(64*TEXTANSWER_amt_of_chunks)-8);
				if(TEXTANSWER_cursor_sprite!=NULL)TEXTANSWER_cursor_sprite->screen_x=TEXT_textbox[0].screen_x+(64*3)-(64*TEXTANSWER_amt_of_chunks)-8;
			}
			pixel=!pixel;
		}

	}
	else
	if(GLOBAL_text_engine_state==4) //ANSWER BOX TURNED OFF,SCROLL TEXT BOX DOWN,SCROLL ANSWER BOX DOWN,DELETE ANSWER BOX
	{
		if(TEXTANSWER_answerbox_y<GAME_VIEWPORT_HEIGHT_PIXELS)
		{
			TEXTANSWER_answerbox_y+=4;
			TEXTANSWER_move_answerbox();
		}
		if(TEXT_textbox[0].screen_y<GAME_VIEWPORT_HEIGHT_PIXELS-64-8)
		{
			TEXT_textbox[0].screen_y+=3;
			if(TEXT_textbox[0].screen_y>GAME_VIEWPORT_HEIGHT_PIXELS-64-8)TEXT_textbox[0].screen_y=GAME_VIEWPORT_HEIGHT_PIXELS-64-8;
			TEXT_move_sprites();
		}
		else
		{
			GLOBAL_text_engine_state=1;
		}
	}
	else
	if(GLOBAL_text_engine_state==6) //KEYBOARD TURNED ON,SCROLL TEXT BOX UP,KEYBOARD BOX UP
	{
		if(TEXT_textbox[0].screen_y>GAME_VIEWPORT_HEIGHT_PIXELS-64-8-64-2)
		{
			TEXT_textbox[0].screen_y-=3;
			if(TEXT_textbox[0].screen_y<GAME_VIEWPORT_HEIGHT_PIXELS-64-8-64-2)TEXT_textbox[0].screen_y=GAME_VIEWPORT_HEIGHT_PIXELS-64-8-64-2;
			TEXT_move_sprites();
		}
		if(TEXT_textbox[0].screen_y==GAME_VIEWPORT_HEIGHT_PIXELS-64-8-64-2)
		{
			if(TEXT_keyboard_y>TEXT_textbox[0].screen_y+64+8-2)
			{
				TEXT_keyboard_y-=4;
				if(TEXT_keyboard_y<TEXT_textbox[0].screen_y+64+8-2)TEXT_keyboard_y=TEXT_textbox[0].screen_y+64+8-2;


				//HARDWARE_set_sprite_y(TEXT_keyboard_sprite[0],TEXT_keyboard_y);
				//HARDWARE_set_sprite_y(TEXT_keyboard_sprite[1],TEXT_keyboard_y);
				//HARDWARE_set_sprite_y(TEXT_keyboard_sprite[2],TEXT_keyboard_y);

				if(TEXT_keyboard_sprite[0]!=NULL)TEXT_keyboard_sprite[0]->screen_y=TEXT_keyboard_y;
				if(TEXT_keyboard_sprite[1]!=NULL)TEXT_keyboard_sprite[1]->screen_y=TEXT_keyboard_y;
				if(TEXT_keyboard_sprite[2]!=NULL)TEXT_keyboard_sprite[2]->screen_y=TEXT_keyboard_y;

			}
		}

	}
	else
	if(GLOBAL_text_engine_state==5) //KEYBOARD TURNED OFF,SCROLL TEXT BOX DOWN,SCROLL KEYBOARD DOWN,DELETE KEYBOARD
	{
		if(TEXT_keyboard_y<GAME_VIEWPORT_HEIGHT_PIXELS)
		{
			TEXT_keyboard_y+=4;

			//HARDWARE_set_sprite_y(TEXT_keyboard_sprite[0],TEXT_keyboard_y);
			//HARDWARE_set_sprite_y(TEXT_keyboard_sprite[1],TEXT_keyboard_y);
			//HARDWARE_set_sprite_y(TEXT_keyboard_sprite[2],TEXT_keyboard_y);

			if(TEXT_keyboard_sprite[0]!=NULL)TEXT_keyboard_sprite[0]->screen_y=TEXT_keyboard_y;
			if(TEXT_keyboard_sprite[1]!=NULL)TEXT_keyboard_sprite[1]->screen_y=TEXT_keyboard_y;
			if(TEXT_keyboard_sprite[2]!=NULL)TEXT_keyboard_sprite[2]->screen_y=TEXT_keyboard_y;

		}
		if(TEXT_textbox[0].screen_y<GAME_VIEWPORT_HEIGHT_PIXELS-64-8)
		{
			TEXT_textbox[0].screen_y+=4;
			if(TEXT_textbox[0].screen_y>GAME_VIEWPORT_HEIGHT_PIXELS-64-8)TEXT_textbox[0].screen_y=GAME_VIEWPORT_HEIGHT_PIXELS-64-8;
			TEXT_move_sprites();
		}
		else
		{
			GLOBAL_text_engine_state=1;
		}
	}
	else
	if(GLOBAL_text_engine_state==2) //===========================TEXT BOX IS IN SCROLLING DOWN STATE. WHEN FINISHED,DELETE TEXT BOX===================
	{
		TEXT_textbox[0].screen_x=((GAME_VIEWPORT_WIDTH_PIXELS-(64*3+32))/2)+32;

		if(TEXT_textbox[0].screen_y<GAME_VIEWPORT_HEIGHT_PIXELS)
		{
			TEXT_textbox[0].screen_y+=4;
				if(TEXT_textbox[0].screen_y>GAME_VIEWPORT_HEIGHT_PIXELS)TEXT_textbox[0].screen_y=GAME_VIEWPORT_HEIGHT_PIXELS;
			TEXT_move_sprites();
		}
		else
		{
			TEXT_deinit=1;
		}
	}



	else

	if(GLOBAL_text_engine_state==1)	//==================================TEXT BOX IS IN RUNNING STATE==============================
	{
		TEXT_textbox[0].screen_x=((GAME_VIEWPORT_WIDTH_PIXELS-(64*3+32))/2)+32;

		if(TEXT_shake_is_on==0)
		{
			if(TEXT_textbox[0].screen_y==GAME_VIEWPORT_HEIGHT_PIXELS-64-8-8+8+8&&TEXT_box_done_scrolling_up==0)
			{
				TEXT_box_done_scrolling_up=1;
			}
			else
			if(TEXT_textbox[0].screen_y>GAME_VIEWPORT_HEIGHT_PIXELS-64-8-8+8+8&&TEXT_box_done_scrolling_up==0)//was +8
			{
				TEXT_textbox[0].screen_y-=4;
				TEXT_move_sprites();
				TEXT_scrolling_up=1;
			}
			else
			{

				TEXT_textbox[0].screen_y=GAME_VIEWPORT_HEIGHT_PIXELS-64-8-8+8+8;
				TEXT_move_sprites();

				TEXT_scrolling_up=0;
			}
		}


		if(TEXT_scrolling_up==1||TEXT_delay_is_on==1)TEXT_drawing_paused=1;
		else TEXT_drawing_paused=0;

		if(TEXT_delay_is_on)
		{

		//	if(TEXT_led_flicker_is_on){HARDWARE_set_led_blink(1,1);TEXT_led_flicker_is_on=0;}

			if(TEXT_delay_counter>0)TEXT_delay_counter--;
			else
			{
				TEXT_delay_is_on=0;
				TEXT_shake_is_on=0;
				TEXT_led_flicker_is_on=0;
				//HARDWARE_set_led_blink(0,0);
				TEXT_move_sprites();
			}

			if(TEXT_shake_is_on==1&&TEXT_delay_counter%3==0)
			{
				static int x=0;
				static int y=0;
				static int y2=0;

				if(x<=TEXT_textbox[0].screen_x)
				{
					x=TEXT_textbox[0].screen_x+1;
					y=TEXT_textbox[0].screen_y+2;
					y2=TEXT_textbox[1].screen_y+2;
				}
				else
					if(x>=TEXT_textbox[0].screen_x+1)
					{
						x=TEXT_textbox[0].screen_x-1;
						y=TEXT_textbox[0].screen_y-2;
						y2=TEXT_textbox[1].screen_y-2;
					}

				if(TEXT_selected_textbox==1)
				{
					HARDWARE_set_sprite_xy(TEXT_textbox[1].sprite_window_sprite,x-32,TEXT_textbox[1].screen_y);//-(TEXT_box_2_sprite_window_top_pixel*2));
					HARDWARE_set_sprite_xy(TEXT_textbox[1].chunk_sprite[0],x+(64*0),TEXT_textbox[1].screen_y);
					HARDWARE_set_sprite_xy(TEXT_textbox[1].chunk_sprite[1],x+(64*1),TEXT_textbox[1].screen_y);
					HARDWARE_set_sprite_xy(TEXT_textbox[1].chunk_sprite[2],x+(64*2),TEXT_textbox[1].screen_y);
				}
				else
				{
					HARDWARE_set_sprite_xy(TEXT_textbox[0].sprite_window_sprite,x-32,TEXT_textbox[0].screen_y);//-(TEXT_box_1_sprite_window_top_pixel*2));
					HARDWARE_set_sprite_xy(TEXT_textbox[0].chunk_sprite[0],x+(64*0),TEXT_textbox[0].screen_y);
					HARDWARE_set_sprite_xy(TEXT_textbox[0].chunk_sprite[1],x+(64*1),TEXT_textbox[0].screen_y);
					HARDWARE_set_sprite_xy(TEXT_textbox[0].chunk_sprite[2],x+(64*2),TEXT_textbox[0].screen_y);
				}

			}

		}

	}	//END IF TEXT BOX ON
	else
	if(GLOBAL_text_engine_state==0)
	{
		TEXT_textbox[1].screen_y=-64;
		TEXT_textbox[0].screen_x=((GAME_VIEWPORT_WIDTH_PIXELS-(64*3+32))/2)+32;
		TEXT_textbox[0].screen_y=GAME_VIEWPORT_HEIGHT_PIXELS;
		TEXT_move_sprites();
		TEXT_box_done_scrolling_up=0;

	}


	if(TEXT_button_icon_is_on==1)
	{

		if(TEXT_selected_textbox==0)HARDWARE_set_sprite_xy(TEXT_textbox[0].button_sprite,TEXT_textbox[0].screen_x+(64*3)-8,TEXT_textbox[0].screen_y+64-8-(TEXT_button_icon_down*2));
		if(TEXT_selected_textbox==1)HARDWARE_set_sprite_xy(TEXT_textbox[0].button_sprite,TEXT_textbox[0].screen_x+(64*3)-8,TEXT_textbox[1].screen_y+64-8-(TEXT_button_icon_down*2));

		if(TEXT_button_timer>30)
		{
			TEXT_button_timer=0;

			if(TEXT_button_icon_down==0)
			{
				TEXT_button_icon_down=1;
			}
			else
			{
				TEXT_button_icon_down=0;
			}
		}
		TEXT_button_timer++;
	}

	TEXT_update_textbox_sprite_textures();

}

//=========================================================================================================================
void TEXT_parse_options()
{//=========================================================================================================================
	int TEXT_option_length=0;
	char TEXT_option_buffer[MAX_ANSWER_LENGTH*6+5+2];

	TEXT_string_position++;
	while(TEXT_text[TEXT_string_position+TEXT_option_length]!='>'&&TEXT_string_position+TEXT_option_length<TEXT_length)
	{
			if(TEXT_option_length<MAX_ANSWER_LENGTH*6+5+1)TEXT_option_buffer[TEXT_option_length] = TEXT_text[TEXT_string_position+TEXT_option_length]; //fix fox longer than 6 longest answers
//		else {
//				TEXT_option_buffer[TEXT_option_length]=NULL;
//				int amt=0;
//				while(text[TEXT_string_position+amt]!='>')amt++;
//				TEXT_string_position+=amt-TEXT_option_length;
//				break;

//			}

		if(TEXT_text[TEXT_string_position+TEXT_option_length]==':')
		{
			int TEXT_temp_answer_length=0;
			while(TEXT_text[TEXT_string_position+TEXT_option_length+1+TEXT_temp_answer_length]!=':'&&TEXT_text[TEXT_string_position+TEXT_option_length+1+TEXT_temp_answer_length]!='>')
			{
				TEXT_temp_answer_length++;
			}
			if(TEXT_temp_answer_length>MAX_ANSWER_LENGTH-1)
			{
				int i=0;
				for(i=0;i<MAX_ANSWER_LENGTH-1;i++)TEXT_option_buffer[TEXT_option_length+1+i]=TEXT_text[TEXT_string_position+TEXT_option_length+1+i];
				TEXT_option_length+=MAX_ANSWER_LENGTH-1; //increments below
				TEXT_string_position+=(TEXT_temp_answer_length-1)-(MAX_ANSWER_LENGTH-1-1); //cuts off answers longer than 50. increments the length by 50,only takes 50 from the answer,increments position by the whole thing
			}
		}
		TEXT_option_length++;
	}
	TEXT_option_buffer[TEXT_option_length]= '\0';
	TEXT_string_position+=TEXT_option_length;

	/*
#define CLEAR 			0
#define BLACK 			1
#define WHITE 			2
#define GRAY 			3
#define RED 			4
#define ORANGE			5
#define YELLOW			6
#define GREEN			7
#define BLUE			8
#define PURPLE			9
#define PINK			10

*/
	if(strcmp(TEXT_option_buffer,".")==0) //if i change this from "." remember to change get_next_word_length above.
	{
		TEXT_waiting_for_button_input=1;
	}
	else
	if(strcmp(TEXT_option_buffer,"0")==0)
	{
		TEXT_selected_textbox=0;
		cameraman_target=TEXT_textbox[0].sprite_window_npc;	//if is not NULL!! else yuu
		cameraman->walking_speed=SPEED_FASTER;
	}
	else
	if(strcmp(TEXT_option_buffer,"1")==0)
	{
		TEXT_selected_textbox=1;
		TEXT_textbox[1].activated=1;
		cameraman_target=TEXT_textbox[1].sprite_window_npc;
		cameraman->walking_speed=SPEED_FASTER;
	}
	else
	if(strcmp(TEXT_option_buffer,"PAUSE")==0)
	{
		TEXT_paused=1;
	}
	else
	if(strcmp(TEXT_option_buffer,"BOB")==0)
	{
		TEXT_font_height	= FONT_BOB_HEIGHT;
		TEXT_font_pointer	= FONT_BOB_indexed_gfx_data;
		TEXT_font_id = FONT_BOB_ID;
	}
	else
	if(strcmp(TEXT_option_buffer,"NORMAL")==0)
	{
		TEXT_font_height	= FONT_NORMAL_HEIGHT;
		TEXT_font_pointer	= FONT_NORMAL_indexed_gfx_data;
		TEXT_font_id = FONT_NORMAL_ID;
	}
	else
	if(strcmp(TEXT_option_buffer,"SMALL")==0)
	{
		TEXT_font_height	= FONT_SMALL_HEIGHT;
		TEXT_font_pointer	= FONT_SMALL_indexed_gfx_data;
		TEXT_font_id = FONT_SMALL_ID;
	}
	else
	if(strcmp(TEXT_option_buffer,"TINY")==0)
	{
		TEXT_font_height	= FONT_TINY_HEIGHT;
		TEXT_font_pointer	= FONT_TINY_indexed_gfx_data;
		TEXT_font_id = FONT_TINY_ID;
	}
	else
	if(strcmp(TEXT_option_buffer,"HUGE")==0)
	{
		TEXT_font_height	= FONT_HUGE_HEIGHT;
		TEXT_font_pointer	= FONT_HUGE_indexed_gfx_data;
		TEXT_font_id = FONT_HUGE_ID;
	}
	else
	if(strcmp(TEXT_option_buffer,"BLACK")==0)
	{
		TEXT_color[0] = WHITE;
		TEXT_color[1] = BLACK;
		TEXT_color[2] = LIGHTGRAY;
	}
	else
	if(strcmp(TEXT_option_buffer,"WHITE")==0)
	{
		TEXT_color[0] = BLACK;
		TEXT_color[1] = WHITE;
		TEXT_color[2] = GRAY;
	}
	else
	if(strcmp(TEXT_option_buffer,"GRAY")==0)
	{
		TEXT_color[0] = BLACK;
		TEXT_color[1] = GRAY;
		TEXT_color[2] = DARKGRAY;
	}
	else
	if(strcmp(TEXT_option_buffer,"LIGHTGRAY")==0)
	{
		TEXT_color[0] = BLACK;
		TEXT_color[1] = LIGHTGRAY;
		TEXT_color[2] = GRAY;
	}
	else
	if(strcmp(TEXT_option_buffer,"RED")==0)
	{
		TEXT_color[1] = RED;
		if(TEXT_color[0]==BLACK)TEXT_color[2]=TEXT_color[1]+1;else TEXT_color[2]=TEXT_color[1]-1;
	}
	else
	if(strcmp(TEXT_option_buffer,"ORANGE")==0)
	{
		TEXT_color[1] = ORANGE;
		if(TEXT_color[0]==BLACK)TEXT_color[2]=TEXT_color[1]+1;else TEXT_color[2]=TEXT_color[1]-1;
	}
	else
	if(strcmp(TEXT_option_buffer,"YELLOW")==0)
	{
		TEXT_color[1] = YELLOW;
		if(TEXT_color[0]==BLACK)TEXT_color[2]=TEXT_color[1]+1;else TEXT_color[2]=TEXT_color[1]-1;
	}
	else
	if(strcmp(TEXT_option_buffer,"GREEN")==0)
	{
		TEXT_color[1] = GREEN;
		if(TEXT_color[0]==BLACK)TEXT_color[2]=TEXT_color[1]+1;else TEXT_color[2]=TEXT_color[1]-1;
	}
	else
	if(strcmp(TEXT_option_buffer,"BLUE")==0)
	{
		TEXT_color[1] = BLUE;
		if(TEXT_color[0]==BLACK)TEXT_color[2]=TEXT_color[1]+1;else TEXT_color[2]=TEXT_color[1]-1;
	}
	else
	if(strcmp(TEXT_option_buffer,"PURPLE")==0)
	{
		TEXT_color[1] = PURPLE;
		if(TEXT_color[0]==BLACK)TEXT_color[2]=TEXT_color[1]+1;else TEXT_color[2]=TEXT_color[1]-1;
	}
	else
	if(strcmp(TEXT_option_buffer,"PINK")==0)
	{
		TEXT_color[1] = PINK;
		if(TEXT_color[0]==BLACK)TEXT_color[2]=TEXT_color[1]+1;else TEXT_color[2]=TEXT_color[1]-1;
	}
	else
	if(strcmp(TEXT_option_buffer,"BGBLACK")==0)
	{
		TEXT_color[0] = BLACK;
		TEXT_color[2] = TEXT_color[1]+1;
	}
	else
	if(strcmp(TEXT_option_buffer,"BGWHITE")==0)
	{
		TEXT_color[0] = WHITE;
		TEXT_color[2] = TEXT_color[1]-1;
	}

	//////////////////////////////////////////////////////////////////////////////////////////////////
	//if(strcmp(TEXT_option_buffer,"SW1")==0)
	//{
//		selected_sprite_window = 0;
	//}
	//if(strcmp(TEXT_option_buffer,"SW2")==0)
	//{
//		selected_sprite_window = 1;
	//}
//	if(strcmp(TEXT_option_buffer,"TEXTLEFT")==0)
//	{
// 		TEXT_on_left=1;
// 		TEXT_drawing_paused=1;
//	}
//	if(strcmp(TEXT_option_buffer,"TEXTRIGHT")==0)
//	{
//		TEXT_on_left=0;
//		TEXT_drawing_paused=1;
//	}
	else

	if(strcmp(TEXT_option_buffer,"CAM0")==0)
	{
		cameraman_target=TEXT_textbox[0].sprite_window_npc;
		cameraman->walking_speed=SPEED_FASTER;
	}
	else
	if(strcmp(TEXT_option_buffer,"CAM1")==0)
	{
		cameraman_target=TEXT_textbox[1].sprite_window_npc;
		cameraman->walking_speed=SPEED_FASTER;
	}
	else
	if(strcmp(TEXT_option_buffer,"CLOSE1")==0)
	{
		TEXT_selected_textbox=0;
		TEXT_textbox[1].activated=0;
	}
	else
	if(strcmp(TEXT_option_buffer,"SHAKE1SEC")==0)
	{
		TEXT_delay_is_on=1;
		TEXT_drawing_paused=1;
		TEXT_delay_counter=60;
		TEXT_shake_is_on=1;
	}
	else
	if(strcmp(TEXT_option_buffer,"SHAKE2SEC")==0)
	{
		TEXT_delay_is_on=1;
		TEXT_drawing_paused=1;
		TEXT_delay_counter=120;
		TEXT_shake_is_on=1;
	}
	else

	if(strcmp(TEXT_option_buffer,"CLEAR")==0)
	{
		TEXT_textbox[TEXT_selected_textbox].line=0;
		TEXT_textbox[TEXT_selected_textbox].tile=0;
		TEXT_textbox[TEXT_selected_textbox].chunk=0;
		TEXT_textbox[TEXT_selected_textbox].x_in_tile=0;
		TEXT_clear_text_box_gfx_data(TEXT_selected_textbox);
		///TEXT_update_textbox_sprite_textures();
		TEXT_textbox[TEXT_selected_textbox].redraw=1;
	}
	else
	if(strcmp(TEXT_option_buffer,"NEXTLINE")==0)
	{
		TEXT_textbox[TEXT_selected_textbox].chunk=0;
		TEXT_textbox[TEXT_selected_textbox].x_in_tile=0;
		TEXT_textbox[TEXT_selected_textbox].tile=0;
		TEXT_textbox[TEXT_selected_textbox].line++;
		if(TEXT_textbox[TEXT_selected_textbox].line>4)
		{
			TEXT_waiting_for_button_input=1;
		}
	}
	else
	if(strcmp(TEXT_option_buffer,"DELAY")==0)
	{
		TEXT_delay_is_on=1;
		TEXT_drawing_paused=1;
		TEXT_delay_counter=20;
	}
	else
	if(strcmp(TEXT_option_buffer,"DELAY30")==0)
	{
		TEXT_delay_is_on=1;
		TEXT_drawing_paused=1;
		TEXT_delay_counter=30;
	}
	else
	if(strcmp(TEXT_option_buffer,"DELAY60")==0)
	{
		TEXT_delay_is_on=1;
		TEXT_drawing_paused=1;
		TEXT_delay_counter=60;
	}
	else
	if(strcmp(TEXT_option_buffer,"DELAY1SEC")==0)
	{
		TEXT_delay_is_on=1;
		TEXT_drawing_paused=1;
		TEXT_delay_counter=60;
	}
	else
	if(strcmp(TEXT_option_buffer,"DELAY2SEC")==0)
	{
		TEXT_delay_is_on=1;
		TEXT_drawing_paused=1;
		TEXT_delay_counter=60*2;
	}
	else
	if(strcmp(TEXT_option_buffer,"DELAY2SECFLICKER")==0)
	{
		TEXT_delay_is_on=1;
		TEXT_drawing_paused=1;
		TEXT_delay_counter=60*2;
		TEXT_led_flicker_is_on=1;
	}
	else
	if(strcmp(TEXT_option_buffer,"KEEPOPENAFTER")==0)
	{
		TEXT_keep_text_box_open_for_more_text=1;
	}
	else
	if(strcmp(TEXT_option_buffer,"NOCANCEL")==0)
	{
		TEXT_cant_cancel=1;
	}
	else
	if(strcmp(TEXT_option_buffer,"YUU")==0)
	{
		if(PLAYER_npc!=NULL)
		{
			TEXT_set_sprite_window(TEXT_selected_textbox,PLAYER_npc,NULL);

			if(TEXT_selected_textbox==0)cameraman_target=TEXT_textbox[0].sprite_window_npc;
			if(TEXT_selected_textbox==1)cameraman_target=TEXT_textbox[1].sprite_window_npc;

			TEXT_textbox[TEXT_selected_textbox].voice_pitch=40000;
			if(PLAYER_npc->gfx==GFX_KID_youngyuu)TEXT_textbox[TEXT_selected_textbox].voice_pitch=55000;
		}
		else
		{
			//text_update_sprite_window_gfx_data();
		}



	}
	else
	if(strcmp(TEXT_option_buffer,"MOM")==0)
	{
		TEXT_set_sprite_window(TEXT_selected_textbox,mom_npc,NULL);
	//HARDWARE_sprite_enable_double_gfx_size(1,TEXT_box_1_sprite_window_id,1);
	//HARDWARE_sprite_enable_double_gfx_size(1,TEXT_box_2_sprite_window_id,1);
	//HARDWARE_set_sprite_rotation(1,TEXT_box_1_sprite_window_id,3);
	//HARDWARE_set_sprite_rotation(1,TEXT_box_2_sprite_window_id,3);
		//if(TEXT_selected_textbox==0)cameraman_target=TEXT_textbox[0].sprite_window_npc;
		//if(TEXT_selected_textbox==1)cameraman_target=TEXT_textbox[1].sprite_window_npc;
		//text_voice_pitch[TEXT_selected_textbox]=70000;



	}
	else
	if(strcmp(TEXT_option_buffer,"DAD")==0)
	{
			TEXT_set_sprite_window(TEXT_selected_textbox,dad_npc,NULL);
			if(TEXT_selected_textbox==0)cameraman_target=TEXT_textbox[0].sprite_window_npc;
			if(TEXT_selected_textbox==1)cameraman_target=TEXT_textbox[1].sprite_window_npc;
			TEXT_textbox[TEXT_selected_textbox].voice_pitch=20000;
	}
	else
	if(strcmp(TEXT_option_buffer,"BROTHER")==0)
	{

			TEXT_set_sprite_window(TEXT_selected_textbox,brother_npc,NULL);
			if(TEXT_selected_textbox==0)cameraman_target=TEXT_textbox[0].sprite_window_npc;
			if(TEXT_selected_textbox==1)cameraman_target=TEXT_textbox[1].sprite_window_npc;
			TEXT_textbox[TEXT_selected_textbox].voice_pitch=30000;
	}
	else
	if(strcmp(TEXT_option_buffer,"NPC1")==0)
	{

			TEXT_set_sprite_window(TEXT_selected_textbox,TEXT_npc_1,NULL);
			if(TEXT_selected_textbox==0)cameraman_target=TEXT_textbox[0].sprite_window_npc;
			if(TEXT_selected_textbox==1)cameraman_target=TEXT_textbox[1].sprite_window_npc;

	}
	else
	if(strcmp(TEXT_option_buffer,"NPC2")==0)
	{

			TEXT_set_sprite_window(TEXT_selected_textbox,TEXT_npc_2,NULL);
			if(TEXT_selected_textbox==0)cameraman_target=TEXT_textbox[0].sprite_window_npc;
			if(TEXT_selected_textbox==1)cameraman_target=TEXT_textbox[1].sprite_window_npc;
	}
	else
	if(strcmp(TEXT_option_buffer,"NPC3")==0)
	{

			TEXT_set_sprite_window(TEXT_selected_textbox,TEXT_npc_3,NULL);
			if(TEXT_selected_textbox==0)cameraman_target=TEXT_textbox[0].sprite_window_npc;
			if(TEXT_selected_textbox==1)cameraman_target=TEXT_textbox[1].sprite_window_npc;
	}
	else
	if(strcmp(TEXT_option_buffer,"NPC4")==0)
	{

			TEXT_set_sprite_window(TEXT_selected_textbox,TEXT_npc_4,NULL);
			if(TEXT_selected_textbox==0)cameraman_target=TEXT_textbox[0].sprite_window_npc;
			if(TEXT_selected_textbox==1)cameraman_target=TEXT_textbox[1].sprite_window_npc;
	}
	else
	if(strcmp(TEXT_option_buffer,"NPC5")==0)
	{

			TEXT_set_sprite_window(TEXT_selected_textbox,TEXT_npc_5,NULL);
			if(TEXT_selected_textbox==0)cameraman_target=TEXT_textbox[0].sprite_window_npc;
			if(TEXT_selected_textbox==1)cameraman_target=TEXT_textbox[1].sprite_window_npc;
	}
	else
	if(strcmp(TEXT_option_buffer,"NPC6")==0)
	{

			TEXT_set_sprite_window(TEXT_selected_textbox,TEXT_npc_6,NULL);
			if(TEXT_selected_textbox==0)cameraman_target=TEXT_textbox[0].sprite_window_npc;
			if(TEXT_selected_textbox==1)cameraman_target=TEXT_textbox[1].sprite_window_npc;
	}
	else
	if(TEXT_option_buffer[0]=='P'&&TEXT_option_buffer[1]=='I'&&TEXT_option_buffer[2]=='T'&&TEXT_option_buffer[3]=='C'&&TEXT_option_buffer[4]=='H')
	{

		int pitch = 0;
		pitch+=atoi((const char*)&TEXT_option_buffer[5]);//*10000;
		//pitch+=atoi(TEXT_option_buffer[6])*1000;
		//pitch+=atoi(TEXT_option_buffer[7])*100;
		//pitch+=atoi(TEXT_option_buffer[8])*10;
		//pitch+=atoi(TEXT_option_buffer[9])*1;

		TEXT_textbox[TEXT_selected_textbox].voice_pitch=pitch;
	}
	else
	if(TEXT_option_buffer[0]=='Q'&&TEXT_option_buffer[1]==':')
	{
		TEXTANSWER_answerbox(TEXT_option_buffer,TEXT_option_length);
	}
	else
	if(strcmp(TEXT_option_buffer,"KEYBOARD")==0)
	{
		TEXT_keyboard();
	}
	else
	if(strcmp(TEXT_option_buffer,"NUMPAD")==0)
	{
		TEXT_numpad();
	}
	else
	{
		//error, unknown
		//print to stderr
		//caption "error"
		//CAPTION_make_caption(NULL,1,200,0,5,TEXT_option_buffer,FONT_TINY_ID,RED,BLACK,1,1);
		//fprintf(stderr, TEXT_option_buffer);

	}

}
