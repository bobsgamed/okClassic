


#include "../../main.h"
//#include "txtkeyboard.h"

int TEXT_keyboard_y=0;
SPRITE* TEXT_keyboard_sprite[3] = {NULL, NULL, NULL};//={FIRST_SPRITE_ID+17,FIRST_SPRITE_ID+16,FIRST_SPRITE_ID+15};
SPRITE* TEXT_keypressed_sprite = NULL;// = FIRST_SPRITE_ID+14;

//int TEXT_keyboard_gfx[3]={0,0,0};
//int TEXT_keypressed_gfx=0;


char numpadchars[25]="";
char keyboardchars[25]="";

CAPTION* typecaption=NULL;


//=========================================================================================================================
void TEXT_keyboard()
{//=========================================================================================================================
	//take answer box sprite ids
	//create keyboard sprites
	//move up textbox
	//move up keyboard
	//put up caption
	//check for stylus clicks or pad input,translate to letter
	//update caption on each click
	//if ok pressed,keyboard answer = caption text
	//move down keyboard and textbox
	//delete sprites

		TEXT_keyboard_y=192;

		int s=0;
		for(s=0;s<3;s++)
		{
			//text_keyboard_gfx[s] = HARDWARE_create_sprite_gfxslot(0,TEXT_keyboard_GFX,64*64*s,64,64,1,0);

			TEXT_keyboard_sprite[s] = HARDWARE_create_sprite(TEXT_keyboard_GFX,0,1,1.0f,32+(64*s),TEXT_keyboard_y,255);

			//HARDWARE_create_sprite(0,TEXT_keyboard_sprite_id[s],TEXT_keyboard_gfx[s],64,64,1,0,0,0,0,0,1,0,32+(64*s),TEXT_keyboard_y);//text_box_y+32+8+2);
	 }

		GLOBAL_text_engine_state=6;
	// GLOBAL_main_sprite_input_off=1;

		while(TEXT_textbox[0].screen_y!=GAME_VIEWPORT_HEIGHT_PIXELS-64-8-64-2||TEXT_keyboard_y!=TEXT_textbox[0].screen_y+64+8-2){whilefix();}

	char numrow[] = "1234567890";
	char toprow[] = "qwertyuiop";
	char middlerow[]="asdfghjkl";
	char bottomrow[]="zxcvbnm";
	char selectedchar='\0';
	int l=0;
	for(l=0;l<24;l++)keyboardchars[l]='\0';
	int charstyped=0;

	CAPTION_make_caption(&typecaption,0,32,192-64-8-8,-1,keyboardchars,FONT_HUGE_ID,GREEN,BLACK,1,1);

	bool enter_pressed=0;
	bool shift_pressed=0;

	bool	shift_selected=0;
	bool	enter_selected=0;
	bool	backspace_selected=0;

	//text_keypressed_gfx= HARDWARE_create_sprite_gfxslot(0,TEXT_keypressed_icon_GFX,0,16,16,1,0);


	TEXT_keypressed_sprite = HARDWARE_create_sprite(TEXT_keypressed_icon_GFX,0,1,1.0f,-16,-16,255);

	if(TEXT_keypressed_sprite!=NULL)TEXT_keypressed_sprite->alpha=159;


	int clickx=0;
	int clicky=0;
		while(!enter_pressed)
		{

			if(BUTTON_RIGHT_HELD||BUTTON_LEFT_HELD||BUTTON_DOWN_HELD||BUTTON_UP_HELD)
			{
					if(BUTTON_RIGHT_HELD)
					{
						if(selectedchar==' ')clickx=32+14;
						else if(backspace_selected)clickx=32+14;
						else if(enter_selected)clickx=32+14;
					//	else if(shift_selected)
						else clickx+=16;
					}
					if(BUTTON_LEFT_HELD)
					{
						if(selectedchar==' ')clickx=32+133;
						else if(backspace_selected)clickx=32+156;
						else if(enter_selected)clickx=32+156;
						else if(shift_selected)	clickx=32+170;
						else clickx-=16;
					}
					if(BUTTON_DOWN_HELD)
					{
						//if(selectedchar=='1')clicky=TEXT_keyboard_y+11;
						//else if(backspace_selected)clicky=TEXT_keyboard_y+11;
						//else
						if(enter_selected)clicky=TEXT_keyboard_y+55;
						else if(shift_selected)clicky=TEXT_keyboard_y+11;
						else clicky+=16;
					}
					if(BUTTON_UP_HELD)
					{
						//if(selectedchar==' ')clickx=32+14;
						//else if(backspace_selected)clickx=32+14;
						//else
						if(enter_selected)clicky=TEXT_keyboard_y+8;
						else if(shift_selected)	clicky=TEXT_keyboard_y+24;
						else clicky-=16;
					}

						shift_selected=0;
						enter_selected=0;
						backspace_selected=0;
					while(BUTTON_RIGHT_HELD||BUTTON_LEFT_HELD||BUTTON_DOWN_HELD||BUTTON_UP_HELD)whilefix();

					if(clickx>32+190)clickx=32+14;
					if(clickx<32)clickx=32+170;
					if(clicky<TEXT_keyboard_y+1)clicky=TEXT_keyboard_y+64-4;
					if(clicky>TEXT_keyboard_y+64-1)clicky=TEXT_keyboard_y+4;

					if(clicky>=TEXT_keyboard_y+1+16*0&&clicky<TEXT_keyboard_y+1+16*1&&clickx>32&&clickx<32+192) //num row
					{
						if(clickx>=32+1&&clickx<32+159)
						{
							selectedchar=numrow[(clickx-32-1)/16];
							//HARDWARE_set_sprite_xy(TEXT_keypressed_sprite,((clickx-32-1)/16)*16+32+1,TEXT_keyboard_y+1);
							if(TEXT_keypressed_sprite!=NULL)TEXT_keypressed_sprite->screen_x=((clickx-32-1)/16)*16+32+1;
							if(TEXT_keypressed_sprite!=NULL)TEXT_keypressed_sprite->screen_y=TEXT_keyboard_y+1;
						}

						if(clickx>=32+161&&clickx<32+190)//backspace
						{
							backspace_selected=1;
							//HARDWARE_set_sprite_xy(TEXT_keypressed_sprite,32+170,TEXT_keyboard_y+1);
							if(TEXT_keypressed_sprite!=NULL)TEXT_keypressed_sprite->screen_x=32+170;
							if(TEXT_keypressed_sprite!=NULL)TEXT_keypressed_sprite->screen_y=TEXT_keyboard_y+1;
						}
					}
					else
					if(clicky>=TEXT_keyboard_y+1+16*1&&clicky<=TEXT_keyboard_y+1+16*2&&clickx>32&&clickx<32+192) //top row
					{
						if(clickx>=32+9&&clickx<32+167)
						{
							selectedchar=(shift_pressed*('A'-'a'))+toprow[(clickx-32-9)/16];
							//HARDWARE_set_sprite_xy(TEXT_keypressed_sprite,((clickx-32-9)/16)*16+32+9,TEXT_keyboard_y+1+16*1);

							if(TEXT_keypressed_sprite!=NULL)TEXT_keypressed_sprite->screen_x=((clickx-32-9)/16)*16+32+9;
							if(TEXT_keypressed_sprite!=NULL)TEXT_keypressed_sprite->screen_y=TEXT_keyboard_y+1+16*1;

						}
						if(clickx>=32+169&&clickx<=32+190)//enter
						{
							enter_selected=1;
							//HARDWARE_set_sprite_xy(TEXT_keypressed_sprite,32+174,TEXT_keyboard_y+27);
							if(TEXT_keypressed_sprite!=NULL)TEXT_keypressed_sprite->screen_x=32+174;
							if(TEXT_keypressed_sprite!=NULL)TEXT_keypressed_sprite->screen_y=TEXT_keyboard_y+27;
						}
					}
					else
					if(clicky>=TEXT_keyboard_y+1+16*2&&clicky<=TEXT_keyboard_y+1+16*3&&clickx>32&&clickx<32+192) //middle row
					{
						if(clickx>=32+17&&clickx<32+159)
						{
							selectedchar=(shift_pressed*('A'-'a'))+middlerow[(clickx-32-17)/16];
							//HARDWARE_set_sprite_xy(TEXT_keypressed_sprite,((clickx-32-17)/16)*16+32+17,TEXT_keyboard_y+1+16*2);

							if(TEXT_keypressed_sprite!=NULL)TEXT_keypressed_sprite->screen_x=((clickx-32-17)/16)*16+32+17;
							if(TEXT_keypressed_sprite!=NULL)TEXT_keypressed_sprite->screen_y=TEXT_keyboard_y+1+16*2;

						}

						if(clickx>=32+1&&clickx<32+15)//shift
						{
							selectedchar='\0';
							shift_selected=1;
							//HARDWARE_set_sprite_xy(TEXT_keypressed_sprite,32+4,TEXT_keyboard_y+50-2);

							if(TEXT_keypressed_sprite!=NULL)TEXT_keypressed_sprite->screen_x=32+4;
							if(TEXT_keypressed_sprite!=NULL)TEXT_keypressed_sprite->screen_y=TEXT_keyboard_y+50-2;


						}
						if(clickx>=32+161&&clickx<=32+190)//enter
						{
							enter_selected=1;
							//HARDWARE_set_sprite_xy(TEXT_keypressed_sprite,32+174,TEXT_keyboard_y+27);
							if(TEXT_keypressed_sprite!=NULL)TEXT_keypressed_sprite->screen_x=32+174;
							if(TEXT_keypressed_sprite!=NULL)TEXT_keypressed_sprite->screen_y=TEXT_keyboard_y+27;
						}
					}
					else
					if(clicky>=TEXT_keyboard_y+1+16*3&&clicky<TEXT_keyboard_y+1+16*4-1&&clickx>32&&clickx<32+192) //bottom row
					{
						if(clickx>=32+25&&clickx<32+135)
						{
							selectedchar=(shift_pressed*('A'-'a'))+bottomrow[(clickx-32-25)/16];
							//HARDWARE_set_sprite_xy(TEXT_keypressed_sprite,((clickx-32-25)/16)*16+32+25,TEXT_keyboard_y+1+16*3);

							if(TEXT_keypressed_sprite!=NULL)TEXT_keypressed_sprite->screen_x=((clickx-32-25)/16)*16+32+25;
							if(TEXT_keypressed_sprite!=NULL)TEXT_keypressed_sprite->screen_y=TEXT_keyboard_y+1+16*3;
						}

						if(clickx>=32+1&&clickx<32+23)//shift
						{
							selectedchar='\0';
							shift_selected=1;
							//HARDWARE_set_sprite_xy(TEXT_keypressed_sprite,32+4,TEXT_keyboard_y+50-2);
							if(TEXT_keypressed_sprite!=NULL)TEXT_keypressed_sprite->screen_x=32+4;
							if(TEXT_keypressed_sprite!=NULL)TEXT_keypressed_sprite->screen_y=TEXT_keyboard_y+50-2;
						}
						if(clickx>=32+137&&clickx<32+190)
						{
							selectedchar = ' ';
							//HARDWARE_set_sprite_xy(TEXT_keypressed_sprite,32+158,TEXT_keyboard_y+1+16*3);

							if(TEXT_keypressed_sprite!=NULL)TEXT_keypressed_sprite->screen_x=32+158;
							if(TEXT_keypressed_sprite!=NULL)TEXT_keypressed_sprite->screen_y=TEXT_keyboard_y+1+16*3;


						}	//space

					}
					else
					{
						//HARDWARE_set_sprite_xy(0,TEXT_keypressed_sprite_id,-16,-16);
						selectedchar='\0';
					}
			}
		if(BUTTON_ACTION_HELD)
		{
			HARDWARE_update_sprite_texture(TEXT_keypressed_sprite,16*16*1);
			if(backspace_selected)//clicky>TEXT_keyboard_y+1+16*0&&clicky<TEXT_keyboard_y+1+16*1&&clickx>32+161&&clickx<32+190)//backspace
				{//backspace
					if(charstyped>0)charstyped--;
					keyboardchars[charstyped]='\0';
					selectedchar='\0';
					CAPTION_delete_caption(typecaption);
					CAPTION_make_caption(&typecaption,0,32,192-64-8-8,-1,keyboardchars,FONT_HUGE_ID,GREEN,BLACK,1,1);
				}
				if(enter_selected)//(clicky>TEXT_keyboard_y+1+16*1&&clicky<TEXT_keyboard_y+1+16*2&&clickx>32+169&&clickx<32+190)||(clicky>TEXT_keyboard_y+1+16*2&&clicky<TEXT_keyboard_y+1+16*3&&clickx>32+161&&clickx<32+190))
				{//enter
					selectedchar='\0';
					enter_pressed=1;
				}

				if(shift_selected||shift_pressed==1)//(clicky>TEXT_keyboard_y+1+16*2&&clicky<TEXT_keyboard_y+1+16*3&&clickx>32+1&&clickx<32+15)||(clicky>TEXT_keyboard_y+1+16*3&&clicky<TEXT_keyboard_y+1+16*4-1&&clickx>32+1&&clickx<32+23))
				{//shift
					if(!shift_pressed)selectedchar='\0';
					shift_pressed=!shift_pressed;
					int s=0;

					if(shift_pressed)for(s=0;s<3;s++)HARDWARE_update_sprite_texture(TEXT_keyboard_sprite[s],64*64*s);
					else
				 for(s=0;s<3;s++)HARDWARE_update_sprite_texture(TEXT_keyboard_sprite[s],64*64*s);
				}

				if(selectedchar!='\0')
				{
					if(charstyped<23)charstyped++;
					keyboardchars[charstyped-1]=selectedchar;
					keyboardchars[charstyped]='\0';

					//selectedchar='\0';
					CAPTION_delete_caption(typecaption);
	 				CAPTION_make_caption(&typecaption,0,32,192-64-8-8,-1,keyboardchars,FONT_HUGE_ID,GREEN,BLACK,1,1);
	 			}
	 			while(BUTTON_ACTION_HELD)whilefix();
	 			HARDWARE_update_sprite_texture(TEXT_keypressed_sprite,16*16*0);
	 		}

			if(TouchScreen.Held)
			{
				selectedchar='\0';
				bool stylus_released=0;
				while(stylus_released!=1)
				{
					if(TouchScreen.Held)//&&clicky!=TouchScreen.Y&&clickx!=TouchScreen.X)
					{
						clickx=TouchScreen.X;
						clicky=TouchScreen.Y;
						shift_selected=0;
						enter_selected=0;
						backspace_selected=0;
						//UpdateTouchScreen();
					}
					else stylus_released=1;

					HARDWARE_update_sprite_texture(TEXT_keypressed_sprite,16*16*1);

					if(clicky>=TEXT_keyboard_y+1+16*0&&clicky<TEXT_keyboard_y+1+16*1&&clickx>32&&clickx<32+192) //num row
					{
						if(clickx>=32+1&&clickx<32+159){selectedchar=numrow[(clickx-32-1)/16];HARDWARE_set_sprite_xy(TEXT_keypressed_sprite,((clickx-32-1)/16)*16+32+1,TEXT_keyboard_y+1);}
						if(clickx>=32+161&&clickx<32+190)//backspace
						{
							HARDWARE_set_sprite_xy(TEXT_keypressed_sprite,32+170,TEXT_keyboard_y+1);
							backspace_selected=1;
						}
					}
					else
					if(clicky>=TEXT_keyboard_y+1+16*1&&clicky<=TEXT_keyboard_y+1+16*2&&clickx>32&&clickx<32+192) //top row
					{
						if(clickx>=32+9&&clickx<32+167){selectedchar=(shift_pressed*('A'-'a'))+toprow[(clickx-32-9)/16];HARDWARE_set_sprite_xy(TEXT_keypressed_sprite,((clickx-32-9)/16)*16+32+9,TEXT_keyboard_y+1+16*1);}
						if(clickx>=32+169&&clickx<=32+190)//enter
						{
							HARDWARE_set_sprite_xy(TEXT_keypressed_sprite,32+174,TEXT_keyboard_y+27);
							enter_selected=1;
						}
					}
					else
					if(clicky>=TEXT_keyboard_y+1+16*2&&clicky<=TEXT_keyboard_y+1+16*3&&clickx>32&&clickx<32+192) //middle row
					{
						if(clickx>=32+17&&clickx<32+159){selectedchar=(shift_pressed*('A'-'a'))+middlerow[(clickx-32-17)/16];HARDWARE_set_sprite_xy(TEXT_keypressed_sprite,((clickx-32-17)/16)*16+32+17,TEXT_keyboard_y+1+16*2);}
						if(clickx>=32+1&&clickx<32+15)//shift
						{
							HARDWARE_set_sprite_xy(TEXT_keypressed_sprite,32+4,TEXT_keyboard_y+50-2);
							shift_selected=1;
						}
						if(clickx>=32+161&&clickx<=32+190)//enter
						{
							HARDWARE_set_sprite_xy(TEXT_keypressed_sprite,32+174,TEXT_keyboard_y+27);
							enter_selected=1;
						}
					}
					else
					if(clicky>=TEXT_keyboard_y+1+16*3&&clicky<TEXT_keyboard_y+1+16*4-1&&clickx>32&&clickx<32+192) //bottom row
					{
						if(clickx>=32+25&&clickx<32+135){selectedchar=(shift_pressed*('A'-'a'))+bottomrow[(clickx-32-25)/16];HARDWARE_set_sprite_xy(TEXT_keypressed_sprite,((clickx-32-25)/16)*16+32+25,TEXT_keyboard_y+1+16*3);}
						if(clickx>=32+1&&clickx<32+23)//shift
						{
							HARDWARE_set_sprite_xy(TEXT_keypressed_sprite,32+4,TEXT_keyboard_y+50-2);
							shift_selected=1;
						}
						if(clickx>=32+137&&clickx<32+190){selectedchar = ' '; HARDWARE_set_sprite_xy(TEXT_keypressed_sprite,32+158,TEXT_keyboard_y+1+16*3);}	//space
					}
					else
					{
					//	HARDWARE_update_sprite_texture_by_sprite_id(0,TEXT_keypressed_sprite_id,(unsigned char*)&TEXT_keypressed_icon_Bitmap[16*16*0]);
						HARDWARE_set_sprite_xy(TEXT_keypressed_sprite,-16,-16);
						selectedchar='\0';
					}

					{reset_controls();check_controls();}
				}//end while stylus isnt released

				HARDWARE_update_sprite_texture(TEXT_keypressed_sprite,16*16*0);

				if(backspace_selected)//clicky>TEXT_keyboard_y+1+16*0&&clicky<TEXT_keyboard_y+1+16*1&&clickx>32+161&&clickx<32+190)//backspace
				{//backspace
					if(charstyped>0)charstyped--;
					keyboardchars[charstyped]='\0';
					selectedchar='\0';
					CAPTION_delete_caption(typecaption);
	 				CAPTION_make_caption(&typecaption,0,32,192-64-8-8,-1,keyboardchars,FONT_HUGE_ID,GREEN,BLACK,1,1);
				}
				if(enter_selected)//(clicky>TEXT_keyboard_y+1+16*1&&clicky<TEXT_keyboard_y+1+16*2&&clickx>32+169&&clickx<32+190)||(clicky>TEXT_keyboard_y+1+16*2&&clicky<TEXT_keyboard_y+1+16*3&&clickx>32+161&&clickx<32+190))
				{//enter
					selectedchar='\0';
					enter_pressed=1;
				}

				if(shift_selected||shift_pressed==1)//(clicky>TEXT_keyboard_y+1+16*2&&clicky<TEXT_keyboard_y+1+16*3&&clickx>32+1&&clickx<32+15)||(clicky>TEXT_keyboard_y+1+16*3&&clicky<TEXT_keyboard_y+1+16*4-1&&clickx>32+1&&clickx<32+23))
				{//shift
					//selectedchar='\0';
					shift_pressed=!shift_pressed;
					int s=0;

					if(shift_pressed)for(s=0;s<3;s++)HARDWARE_update_sprite_texture(TEXT_keyboard_sprite[s],64*64*s);
					else
				 for(s=0;s<3;s++)HARDWARE_update_sprite_texture(TEXT_keyboard_sprite[s],64*64*s);
				}

				if(selectedchar!='\0')
				{
					if(charstyped<23)charstyped++;
					keyboardchars[charstyped-1]=selectedchar;
					keyboardchars[charstyped]='\0';

					selectedchar='\0';
					CAPTION_delete_caption(typecaption);
	 				CAPTION_make_caption(&typecaption,0,32,192-64-8-8,-1,keyboardchars,FONT_HUGE_ID,GREEN,BLACK,1,1);
	 			}
			}//end if stylus held

		}//end while enter_pressed==0
		HARDWARE_delete_sprite(TEXT_keypressed_sprite);
		//HARDWARE_delete_sprite_gfxslot(0,TEXT_keypressed_gfx);

		GLOBAL_text_engine_state=5;

		CAPTION_delete_caption(typecaption);

		while(TEXT_textbox[0].screen_y<GAME_VIEWPORT_HEIGHT_PIXELS-64-8)whilefix();

		s=0;
		for(s=0;s<3;s++)
		{
			HARDWARE_delete_sprite(TEXT_keyboard_sprite[s]);
			//HARDWARE_delete_sprite_gfxslot(0,TEXT_keyboard_gfx[s]);
		}

GLOBAL_main_sprite_input_off=0;
}

//=========================================================================================================================
void TEXT_numpad()
{//=========================================================================================================================
	TEXT_keyboard_y=192;

 	//text_keyboard_gfx[0]	= HARDWARE_create_sprite_gfxslot(0,TEXT_numpad_GFX,0,64,64,1,0);


	//HARDWARE_create_sprite(0,TEXT_keyboard_sprite_id[0],TEXT_keyboard_gfx[0],64,64,1,0,0,0,0,0,1,0,64+32,TEXT_keyboard_y);//text_box_y+32+8+2);
	TEXT_keyboard_sprite[0] = HARDWARE_create_sprite(TEXT_numpad_GFX,0,1,1.0f,64+32,TEXT_keyboard_y,255);


	GLOBAL_text_engine_state=6;
GLOBAL_main_sprite_input_off=1;

	while(TEXT_textbox[0].screen_y!=GAME_VIEWPORT_HEIGHT_PIXELS-64-8-64-2||TEXT_keyboard_y!=TEXT_textbox[0].screen_y+64+8-2){whilefix();}

	char numrow[] = "789";
	char toprow[] = "456";
	char middlerow[]="123";
	char bottomrow[]="0";
	char selectedchar='\0';
	int l=0;
	for(l=0;l<24;l++)numpadchars[l]='\0';
	int charstyped=0;

	CAPTION_make_caption(&typecaption,0,64+32,192-64-8-8,-1,numpadchars,FONT_HUGE_ID,RED,BLACK,1,1);

	bool enter_pressed=0;

	bool	enter_selected=0;
	bool	backspace_selected=0;

	//text_keypressed_gfx= HARDWARE_create_sprite_gfxslot(0,TEXT_keypressed_icon_GFX,0,16,16,1,0);

	TEXT_keypressed_sprite = HARDWARE_create_sprite(TEXT_keypressed_icon_GFX,0,1,1.0f,-16,-16,255);

	if(TEXT_keypressed_sprite!=NULL)TEXT_keypressed_sprite->alpha=159;



	int clickx=0;
	int clicky=0;
		while(!enter_pressed)
		{

			if(BUTTON_RIGHT_HELD||BUTTON_LEFT_HELD||BUTTON_DOWN_HELD||BUTTON_UP_HELD)
			{
					if(BUTTON_RIGHT_HELD)
					{
						if(selectedchar=='9')clickx=64+32+7;
						else if(selectedchar=='6')clickx=64+32+7;
						else if(selectedchar=='0')clickx=64+32+39;
					//	else if(backspace_selected)clickx=32+14;
					//	else if(enter_selected)clickx=32+14;
						else clickx+=16;
					}
					if(BUTTON_LEFT_HELD)
					{
						if(selectedchar=='7')clickx=64+32+39;
						else if(selectedchar=='4')clickx=64+32+39;
						else if(selectedchar=='0')clickx=64+32+56;
						//else if(backspace_selected)clickx=64+32+156;
						//else if(enter_selected)clickx=64+32+156;
						else clickx-=16;
					}
					if(BUTTON_DOWN_HELD)
					{
						//if(enter_selected)clicky=TEXT_keyboard_y+55;
						//else
						clicky+=16;
					}
					if(BUTTON_UP_HELD)
					{
						//if(enter_selected)clicky=TEXT_keyboard_y+8;
						//else
						clicky-=16;
					}

						enter_selected=0;
						backspace_selected=0;
					while(BUTTON_RIGHT_HELD||BUTTON_LEFT_HELD||BUTTON_DOWN_HELD||BUTTON_UP_HELD)whilefix();

					if(clickx>64+32+64)clickx=64+32+7;
					if(clickx<64+32)clickx=64+32+56;
					if(clicky<TEXT_keyboard_y+1)clicky=TEXT_keyboard_y+64-4;
					if(clicky>TEXT_keyboard_y+64-1)clicky=TEXT_keyboard_y+4;

					if(clicky>=TEXT_keyboard_y+1+16*0&&clicky<TEXT_keyboard_y+1+16*1&&clickx>64+32&&clickx<64+32+64-16) //top row
					{
						if(clickx>=64+32+1&&clickx<64+32+47){selectedchar=numrow[(clickx-64-32-1)/16];HARDWARE_set_sprite_xy(TEXT_keypressed_sprite,((clickx-64-32-1)/16)*16+64+32+1,TEXT_keyboard_y+1);}

					}
					else
					if(clicky>=TEXT_keyboard_y+1+16*1&&clicky<TEXT_keyboard_y+1+16*2&&clickx>64+32&&clickx<64+32+64-16) //mid row
					{
						if(clickx>=64+32+1&&clickx<64+32+47){selectedchar=toprow[(clickx-64-32-1)/16];HARDWARE_set_sprite_xy(TEXT_keypressed_sprite,((clickx-64-32-1)/16)*16+64+32+1,TEXT_keyboard_y+1+16*1);}

					}
					else
					if(clicky>=TEXT_keyboard_y+1+16*2&&clicky<=TEXT_keyboard_y+1+16*3&&clickx>64+32&&clickx<=64+32+64) //bottom row
					{
						if(clickx>=64+32+1&&clickx<64+32+47){selectedchar=middlerow[(clickx-64-32-1)/16];HARDWARE_set_sprite_xy(TEXT_keypressed_sprite,((clickx-64-32-1)/16)*16+64+32+1,TEXT_keyboard_y+1+16*2);}
						if(clickx>=64+32+49&&clickx<=64+32+62)//enter
						{
							HARDWARE_set_sprite_xy(TEXT_keypressed_sprite,64+32+49,TEXT_keyboard_y+43);
							selectedchar='\0';
							enter_selected=1;
						}
					}
					else
					if(clicky>=TEXT_keyboard_y+1+16*3&&clicky<=TEXT_keyboard_y+1+16*4-1&&clickx>64+32&&clickx<=64+32+64) //zero row
					{
						if(clickx>=64+32+1&&clickx<64+32+31){selectedchar=bottomrow[0/*(clickx-64-32-1)/16*/];HARDWARE_set_sprite_xy(TEXT_keypressed_sprite,/*((clickx-64-32-1)/16)*16+*/64+32+11,TEXT_keyboard_y+1+16*3);}
						if(clickx>=64+32+33&&clickx<64+32+47)//backspace
						{
							HARDWARE_set_sprite_xy(TEXT_keypressed_sprite,64+32+33,TEXT_keyboard_y+49);
							selectedchar='\0';
							backspace_selected=1;
						}
						if(clickx>=64+32+49&&clickx<=64+32+62)//enter
						{
							HARDWARE_set_sprite_xy(TEXT_keypressed_sprite,64+32+49,TEXT_keyboard_y+43);
							selectedchar='\0';
							enter_selected=1;
						}
					}
					else
					{
					//	HARDWARE_update_sprite_texture_by_sprite_id(0,TEXT_keypressed_sprite_id,(unsigned char*)&TEXT_keypressed_icon_Bitmap[16*16*0]);
					//	HARDWARE_set_sprite_xy(0,TEXT_keypressed_sprite_id,-16,-16);
						selectedchar='\0';
					}

			}
		if(BUTTON_ACTION_HELD)
		{
			HARDWARE_update_sprite_texture(TEXT_keypressed_sprite,16*16*1);
			if(backspace_selected)//clicky>TEXT_keyboard_y+1+16*0&&clicky<TEXT_keyboard_y+1+16*1&&clickx>32+161&&clickx<32+190)//backspace
				{//backspace
					if(charstyped>0)charstyped--;
					numpadchars[charstyped]='\0';
					selectedchar='\0';
					CAPTION_delete_caption(typecaption);
	 				CAPTION_make_caption(&typecaption,0,64+32,192-64-8-8,-1,numpadchars,FONT_HUGE_ID,RED,BLACK,1,1);
				}
				if(enter_selected)//(clicky>TEXT_keyboard_y+1+16*1&&clicky<TEXT_keyboard_y+1+16*2&&clickx>32+169&&clickx<32+190)||(clicky>TEXT_keyboard_y+1+16*2&&clicky<TEXT_keyboard_y+1+16*3&&clickx>32+161&&clickx<32+190))
				{//enter
					selectedchar='\0';
					enter_pressed=1;
				}

				if(selectedchar!='\0')
				{
					if(charstyped<23)charstyped++;
					numpadchars[charstyped-1]=selectedchar;
					numpadchars[charstyped]='\0';
					//selectedchar='\0';
					CAPTION_delete_caption(typecaption);
	 				CAPTION_make_caption(&typecaption,0,64+32,192-64-8-8,-1,numpadchars,FONT_HUGE_ID,RED,BLACK,1,1);
	 			}
	 			while(BUTTON_ACTION_HELD)whilefix();
	 			HARDWARE_update_sprite_texture(TEXT_keypressed_sprite,16*16*0);
	 		}

			if(TouchScreen.Held)
			{
				selectedchar='\0';
				bool stylus_released=0;
				while(stylus_released!=1)
				{
					if(TouchScreen.Held)//&&clicky!=TouchScreen.Y&&clickx!=TouchScreen.X)
					{
						clickx=TouchScreen.X;
						clicky=TouchScreen.Y;
						enter_selected=0;
						backspace_selected=0;
						//UpdateTouchScreen();
					}
					else stylus_released=1;

					HARDWARE_update_sprite_texture(TEXT_keypressed_sprite,16*16*1);

					if(clicky>=TEXT_keyboard_y+1+16*0&&clicky<TEXT_keyboard_y+1+16*1&&clickx>64+32&&clickx<64+32+64-16) //top row
					{
						if(clickx>=64+32+1&&clickx<64+32+47){selectedchar=numrow[(clickx-64-32-1)/16];HARDWARE_set_sprite_xy(TEXT_keypressed_sprite,((clickx-64-32-1)/16)*16+64+32+1,TEXT_keyboard_y+1);}

					}
					else
					if(clicky>=TEXT_keyboard_y+1+16*1&&clicky<TEXT_keyboard_y+1+16*2&&clickx>64+32&&clickx<64+32+64-16) //mid row
					{
						if(clickx>=64+32+1&&clickx<64+32+47){selectedchar=toprow[(clickx-64-32-1)/16];HARDWARE_set_sprite_xy(TEXT_keypressed_sprite,((clickx-64-32-1)/16)*16+64+32+1,TEXT_keyboard_y+1+16*1);}

					}
					else
					if(clicky>=TEXT_keyboard_y+1+16*2&&clicky<=TEXT_keyboard_y+1+16*3&&clickx>64+32&&clickx<=64+32+64) //bottom row
					{
						if(clickx>=64+32+1&&clickx<64+32+47){selectedchar=middlerow[(clickx-64-32-1)/16];HARDWARE_set_sprite_xy(TEXT_keypressed_sprite,((clickx-64-32-1)/16)*16+64+32+1,TEXT_keyboard_y+1+16*2);}
						if(clickx>=64+32+49&&clickx<=64+32+62)//enter
						{
							HARDWARE_set_sprite_xy(TEXT_keypressed_sprite,64+32+49,TEXT_keyboard_y+43);
							enter_selected=1;
						}
					}
					else
					if(clicky>=TEXT_keyboard_y+1+16*3&&clicky<=TEXT_keyboard_y+1+16*4-1&&clickx>64+32&&clickx<=64+32+64) //zero row
					{
						if(clickx>=64+32+1&&clickx<64+32+31){selectedchar=bottomrow[0/*(clickx-64-32-1)/16*/];HARDWARE_set_sprite_xy(TEXT_keypressed_sprite,/*((clickx-64-32-1)/16)*16+*/64+32+11,TEXT_keyboard_y+1+16*3);}
						if(clickx>=64+32+33&&clickx<64+32+47)//backspace
						{
							HARDWARE_set_sprite_xy(TEXT_keypressed_sprite,64+32+33,TEXT_keyboard_y+49);
							backspace_selected=1;
						}
						if(clickx>=64+32+49&&clickx<=64+32+62)//enter
						{
							HARDWARE_set_sprite_xy(TEXT_keypressed_sprite,64+32+49,TEXT_keyboard_y+43);
							enter_selected=1;
						}
					}
					else
					{
					//	HARDWARE_update_sprite_texture_by_sprite_id(0,TEXT_keypressed_sprite_id,(unsigned char*)&TEXT_keypressed_icon_Bitmap[16*16*0]);
						HARDWARE_set_sprite_xy(TEXT_keypressed_sprite,-16,-16);
						selectedchar='\0';
					}
					{reset_controls();check_controls();}
				}//end while stylus isnt released

				HARDWARE_update_sprite_texture(TEXT_keypressed_sprite,16*16*0);

				if(backspace_selected)//clicky>TEXT_keyboard_y+1+16*0&&clicky<TEXT_keyboard_y+1+16*1&&clickx>32+161&&clickx<32+190)//backspace
				{//backspace
					if(charstyped>0)charstyped--;
					numpadchars[charstyped]='\0';
					selectedchar='\0';
					CAPTION_delete_caption(typecaption);
	 				CAPTION_make_caption(&typecaption,0,64+32,192-64-8-8,-1,numpadchars,FONT_HUGE_ID,RED,BLACK,1,1);

				}
				if(enter_selected)//(clicky>TEXT_keyboard_y+1+16*1&&clicky<TEXT_keyboard_y+1+16*2&&clickx>32+169&&clickx<32+190)||(clicky>TEXT_keyboard_y+1+16*2&&clicky<TEXT_keyboard_y+1+16*3&&clickx>32+161&&clickx<32+190))
				{//enter
					selectedchar='\0';
					enter_pressed=1;
				}
				if(selectedchar!='\0')
				{
					if(charstyped<23)charstyped++;
					numpadchars[charstyped-1]=selectedchar;
					numpadchars[charstyped]='\0';
					selectedchar='\0';

					CAPTION_delete_caption(typecaption);
	 				CAPTION_make_caption(&typecaption,0,64+32,192-64-8-8,-1,numpadchars,FONT_HUGE_ID,RED,BLACK,1,1);
	 			}
			}//end if stylus held

		}//end while enter_pressed==0
		HARDWARE_delete_sprite(TEXT_keypressed_sprite);
		//HARDWARE_delete_sprite_gfxslot(0,TEXT_keypressed_gfx);

		GLOBAL_text_engine_state=5;
		CAPTION_delete_caption(typecaption);

		while(TEXT_textbox[0].screen_y<GAME_VIEWPORT_HEIGHT_PIXELS-64-8)whilefix();

			HARDWARE_delete_sprite(TEXT_keyboard_sprite[0]);
			//HARDWARE_delete_sprite_gfxslot(0,TEXT_keyboard_gfx[0]);

GLOBAL_main_sprite_input_off=0;

}





