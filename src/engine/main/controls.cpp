



#include "../../main.h"
//#include "controls.h"




int DEADZONE=8000;

bool KEY_UP_HELD=0;
bool KEY_DOWN_HELD=0;
bool KEY_LEFT_HELD=0;
bool KEY_RIGHT_HELD=0;

bool KEY_START_HELD=0;
bool KEY_SELECT_HELD=0;

bool KEY_A_HELD=0;
bool KEY_B_HELD=0;
bool KEY_Y_HELD=0;
bool KEY_X_HELD=0;
bool KEY_L_HELD=0;
bool KEY_R_HELD=0;

SDL_Event event;
SDL_Joystick *stick = NULL;

bool BUTTON_ACTION_PRESSED=0;
bool BUTTON_UP_PRESSED=0;
bool BUTTON_DOWN_PRESSED=0;
bool BUTTON_LEFT_PRESSED=0;
bool BUTTON_RIGHT_PRESSED=0;
bool BUTTON_L_PRESSED=0;
bool BUTTON_R_PRESSED=0;
bool BUTTON_A_PRESSED=0;
bool BUTTON_B_PRESSED=0;
bool BUTTON_X_PRESSED=0;
bool BUTTON_Y_PRESSED=0;
bool BUTTON_START_PRESSED=0;
bool BUTTON_SELECT_PRESSED=0;

bool BUTTON_ACTION_HELD=0;
bool BUTTON_UP_HELD=0;
bool BUTTON_DOWN_HELD=0;
bool BUTTON_LEFT_HELD=0;
bool BUTTON_RIGHT_HELD=0;
bool BUTTON_L_HELD=0;
bool BUTTON_R_HELD=0;
bool BUTTON_A_HELD=0;
bool BUTTON_B_HELD=0;
bool BUTTON_X_HELD=0;
bool BUTTON_Y_HELD=0;
bool BUTTON_START_HELD=0;
bool BUTTON_SELECT_HELD=0;


float MAXZOOM = 3.0f;
float MINZOOM = 1.0f;
float ZOOMINCREMENT = 0.25f;

HARDWARE_TouchScreen TouchScreen;




//===========================================================================================================================
void check_controls()
{//===========================================================================================================================



//see if button was held last frame
//if it wasnt, pressed = 1


int LAST_BUTTON_A_HELD=BUTTON_A_HELD;
int LAST_BUTTON_B_HELD=BUTTON_B_HELD;
int LAST_BUTTON_Y_HELD=BUTTON_Y_HELD;
int LAST_BUTTON_X_HELD=BUTTON_X_HELD;
int LAST_BUTTON_L_HELD=BUTTON_L_HELD;
int LAST_BUTTON_R_HELD=BUTTON_R_HELD;

int LAST_BUTTON_START_HELD=BUTTON_START_HELD;
int LAST_BUTTON_SELECT_HELD=BUTTON_SELECT_HELD;

int LAST_BUTTON_UP_HELD=BUTTON_UP_HELD;
int LAST_BUTTON_DOWN_HELD=BUTTON_DOWN_HELD;
int LAST_BUTTON_LEFT_HELD=BUTTON_LEFT_HELD;
int LAST_BUTTON_RIGHT_HELD=BUTTON_RIGHT_HELD;

BUTTON_ACTION_HELD=0;

BUTTON_A_HELD=0;
BUTTON_B_HELD=0;
BUTTON_Y_HELD=0;
BUTTON_X_HELD=0;
BUTTON_L_HELD=0;
BUTTON_R_HELD=0;

BUTTON_START_HELD=0;
BUTTON_SELECT_HELD=0;

BUTTON_UP_HELD=0;
BUTTON_DOWN_HELD=0;
BUTTON_LEFT_HELD=0;
BUTTON_RIGHT_HELD=0;



if(stick!=NULL)
{

    //joystick
    SDL_JoystickUpdate();


    //analog
    int xval=0;
    int yval=0;

    xval = SDL_JoystickGetAxis(stick,0);//x axis, returns -32767 to 32767
    yval = SDL_JoystickGetAxis(stick,1);//y axis

    if(xval<0-DEADZONE||xval>DEADZONE)
    {
        if(xval>0){BUTTON_RIGHT_HELD=1;YUU_WALKING_SPEED=YUU_WALKING_SPEED_JOYSTICK;}
        if(xval<0){BUTTON_LEFT_HELD=1;YUU_WALKING_SPEED=YUU_WALKING_SPEED_JOYSTICK;}
    }

    if(yval<0-DEADZONE||yval>DEADZONE)
    {
        if(yval>0){BUTTON_DOWN_HELD=1;YUU_WALKING_SPEED=YUU_WALKING_SPEED_JOYSTICK;}
        if(yval<0){BUTTON_UP_HELD=1;YUU_WALKING_SPEED=YUU_WALKING_SPEED_JOYSTICK;}
    }


    //dpad
    int dpad = SDL_JoystickGetHat(stick, 0);

    switch (dpad)
    {

        case SDL_HAT_RIGHTUP:{BUTTON_UP_HELD=1;BUTTON_RIGHT_HELD=1;YUU_WALKING_SPEED=YUU_WALKING_SPEED_JOYSTICK;}break;
        case SDL_HAT_RIGHTDOWN:{BUTTON_DOWN_HELD=1;BUTTON_RIGHT_HELD=1;YUU_WALKING_SPEED=YUU_WALKING_SPEED_JOYSTICK;}break;
        case SDL_HAT_LEFTUP:{BUTTON_UP_HELD=1;BUTTON_LEFT_HELD=1;YUU_WALKING_SPEED=YUU_WALKING_SPEED_JOYSTICK;}break;
        case SDL_HAT_LEFTDOWN:{BUTTON_DOWN_HELD=1;BUTTON_LEFT_HELD=1;YUU_WALKING_SPEED=YUU_WALKING_SPEED_JOYSTICK;}break;

        case SDL_HAT_UP:{BUTTON_UP_HELD=1;YUU_WALKING_SPEED=YUU_WALKING_SPEED_JOYSTICK;}break;
        case SDL_HAT_RIGHT:{BUTTON_RIGHT_HELD=1;YUU_WALKING_SPEED=YUU_WALKING_SPEED_JOYSTICK;}break;
        case SDL_HAT_DOWN:{BUTTON_DOWN_HELD=1;YUU_WALKING_SPEED=YUU_WALKING_SPEED_JOYSTICK;}break;
        case SDL_HAT_LEFT:{BUTTON_LEFT_HELD=1;YUU_WALKING_SPEED=YUU_WALKING_SPEED_JOYSTICK;}break;

        /*
        case SDL_HAT_CENTERED:
        {
            BUTTON_UP_HELD=0;
            BUTTON_DOWN_HELD=0;
            BUTTON_LEFT_HELD=0;
            BUTTON_RIGHT_HELD=0;
        }break;
        */

        default:break;

    }


    //buttons
     if(SDL_JoystickGetButton(stick, 1)==1)BUTTON_A_HELD=1;
     if(SDL_JoystickGetButton(stick, 0)==1)BUTTON_B_HELD=1;

     if(SDL_JoystickGetButton(stick, 2)==1)BUTTON_Y_HELD=1;
     if(SDL_JoystickGetButton(stick, 3)==1)BUTTON_X_HELD=1;

     if(SDL_JoystickGetButton(stick, 4)==1)BUTTON_L_HELD=1;
     if(SDL_JoystickGetButton(stick, 5)==1)BUTTON_R_HELD=1;

     if(SDL_JoystickGetButton(stick, 6)==1)BUTTON_SELECT_HELD=1;
     if(SDL_JoystickGetButton(stick, 7)==1)BUTTON_START_HELD=1;

}



/*

lt  rt
la  rb


    y

x       b

    a

1 a
2 b
3 x
4 y

5 la
6 lb

7 sel
8 start


hat dpad
9 leftanalogclick
10 rightanalogclick


z axis left trigger - right trigger

*/
        //-----------------------------
        //EVENTS
        //-----------------------------

        //While there's events to handle
        while( SDL_PollEvent( &event ) )
        {
            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                MAIN_QUIT = true;
            }

/*
            if( event.type == SDL_MOUSEBUTTONDOWN )
            { //If the left mouse button was pressed
                if( event.button.button == SDL_BUTTON_LEFT )
                { //Get the mouse offsets
                    TouchScreen.Held=true;
                    TouchScreen.X = event.button.x/ZOOM;
                    TouchScreen.Y = event.button.y/ZOOM;
                }
            }
*/
            //If a key was pressed
            if( event.type == SDL_KEYDOWN )
            {
                //Adjust the velocity
                switch( event.key.keysym.sym )
                {
                    case SDLK_w:
                    case SDLK_UP: {KEY_UP_HELD=1;YUU_WALKING_SPEED=YUU_WALKING_SPEED_KEYBOARD;} break;
                    case SDLK_s:
                    case SDLK_DOWN: {KEY_DOWN_HELD=1;YUU_WALKING_SPEED=YUU_WALKING_SPEED_KEYBOARD;} break;
                    case SDLK_a:
                    case SDLK_LEFT: {KEY_LEFT_HELD=1;YUU_WALKING_SPEED=YUU_WALKING_SPEED_KEYBOARD;} break;
                    case SDLK_d:
                    case SDLK_RIGHT: {KEY_RIGHT_HELD=1;YUU_WALKING_SPEED=YUU_WALKING_SPEED_KEYBOARD;} break;

					case SDLK_RETURN:
                    case SDLK_RIGHTBRACKET: {KEY_START_HELD=1;} break;
                    case SDLK_BACKSPACE:
                    case SDLK_LEFTBRACKET: {KEY_SELECT_HELD=1;} break;

                    case SDLK_SPACE: {KEY_A_HELD=1;} break;

                    case SDLK_LSHIFT: {KEY_B_HELD=1;} break;

                    case SDLK_q: {KEY_L_HELD=1;} break;
                    case SDLK_e: {KEY_R_HELD=1;} break;

                    case SDLK_z: {KEY_Y_HELD=1;} break;
                    case SDLK_x: {KEY_X_HELD=1;} break;

                    default:break;
                }
            }

            //If a key was released
            else if( event.type == SDL_KEYUP )
            {
                //Adjust the velocity
                switch( event.key.keysym.sym )
                {
                    case SDLK_w:
                    case SDLK_UP: {KEY_UP_HELD=0;} break;
                    case SDLK_s:
                    case SDLK_DOWN: {KEY_DOWN_HELD=0;} break;
                    case SDLK_a:
                    case SDLK_LEFT: {KEY_LEFT_HELD=0;} break;
                    case SDLK_d:
                    case SDLK_RIGHT: {KEY_RIGHT_HELD=0;} break;

					case SDLK_RETURN:
                    case SDLK_RIGHTBRACKET: {KEY_START_HELD=0;} break;

                    case SDLK_BACKSPACE:
                    case SDLK_LEFTBRACKET: {KEY_SELECT_HELD=0;} break;

                    case SDLK_SPACE: {KEY_A_HELD=0;} break;
                    case SDLK_LSHIFT: {KEY_B_HELD=0;} break;

                    case SDLK_q: {KEY_L_HELD=0;} break;
                    case SDLK_e: {KEY_R_HELD=0;} break;

                    case SDLK_z: {KEY_Y_HELD=0;} break;
                    case SDLK_x: {KEY_X_HELD=0;} break;

					//case SDLK_f: {if(fpsmeter==0)fpsmeter=1;else fpsmeter=0;}break;
                    //debug

					//map layer on/off
					case SDLK_1: {if(GLOBAL_bg_layer_enabled[1]==1)GLOBAL_bg_layer_enabled[1]=0;else GLOBAL_bg_layer_enabled[1]=1;} break;
					case SDLK_2: {if(GLOBAL_bg_layer_enabled[2]==1)GLOBAL_bg_layer_enabled[2]=0;else GLOBAL_bg_layer_enabled[2]=1;} break;
					case SDLK_3: {if(GLOBAL_bg_layer_enabled[3]==1)GLOBAL_bg_layer_enabled[3]=0;else GLOBAL_bg_layer_enabled[3]=1;} break;
					case SDLK_0: {if(GLOBAL_bg_layer_enabled[0]==1)GLOBAL_bg_layer_enabled[0]=0;else GLOBAL_bg_layer_enabled[0]=1;} break;
					case SDLK_4: {if(GLOBAL_sprite_layer_enabled==1)GLOBAL_sprite_layer_enabled=0;else GLOBAL_sprite_layer_enabled=1;} break;

					case SDLK_f: {if(GLOBAL_FRAMEBUFFER_FILTER_TYPE==GL_LINEAR)GLOBAL_FRAMEBUFFER_FILTER_TYPE=GL_NEAREST;else GLOBAL_FRAMEBUFFER_FILTER_TYPE=GL_LINEAR;}break;

					case SDLK_BACKQUOTE: {if(error_console_on==1)error_console_on=0;else error_console_on=1;}break;

					case SDLK_5: {CLOCK_hour--;CLOCK_moving=true;CLOCK_update_clock();}break;
					case SDLK_6: {CLOCK_hour++;CLOCK_moving=true;CLOCK_update_clock();}break;
					case SDLK_7: {CLOCK_minute--;CLOCK_moving=true;CLOCK_update_clock();}break;
					case SDLK_8: {CLOCK_minute++;CLOCK_moving=true;CLOCK_update_clock();}break;

                    //TODO: brightness controls
                    case SDLK_MINUS:
                    {
                        if(ZOOMlock==0)
						{
							if(ZOOMto>MINZOOM)ZOOMto-=ZOOMINCREMENT;
							if(ZOOMto<MINZOOM)ZOOMto=MINZOOM;
						}
                        //HARDWARE_brightness--;
                        //HARDWARE_create_brightened_palette((void*)GAME_original_SPRITE_PALETTE,(int*)GAME_temp_SPRITE_PALETTE,HARDWARE_brightness);
                        //HARDWARE_load_sprite_palette(1,0,(int*)GAME_temp_SPRITE_PALETTE);
                        //HARDWARE_refresh_sprite_textures();
                     break;
                    }
                    case SDLK_EQUALS:
                    {
                        if(ZOOMlock==0)
						{
							if(ZOOMto<MAXZOOM)ZOOMto+=ZOOMINCREMENT;
							if(ZOOMto>MAXZOOM)ZOOMto=MAXZOOM;
						}
                        //HARDWARE_brightness++;
                        //HARDWARE_create_brightened_palette((void*)GAME_original_SPRITE_PALETTE,(int*)GAME_temp_SPRITE_PALETTE,HARDWARE_brightness);
                        //HARDWARE_load_sprite_palette(1,0,(int*)GAME_temp_SPRITE_PALETTE);
                        //HARDWARE_refresh_sprite_textures();
                     break;
                    }
                    case SDLK_ESCAPE: {MAIN_QUIT = true; } break;
                    default:break;
                }
            }


#ifdef ND
				else
				if(event.type == SDL_JOYBUTTONDOWN)
				{
					if(event.jbutton.button==GP2X_BUTTON_DOWN){KEY_DOWN_HELD=1;}
					if(event.jbutton.button==GP2X_BUTTON_RIGHT){KEY_RIGHT_HELD=1;}
					if(event.jbutton.button==GP2X_BUTTON_UP){KEY_UP_HELD=1;}
					if(event.jbutton.button==GP2X_BUTTON_LEFT){KEY_LEFT_HELD=1;}

					if(event.jbutton.button==GP2X_BUTTON_Y)MAIN_QUIT = true;
					if(event.jbutton.button==GP2X_BUTTON_B)KEY_A_HELD=1;
				}

				else
				if(event.type == SDL_JOYBUTTONUP)
				{
					if(event.jbutton.button==GP2X_BUTTON_DOWN){KEY_DOWN_HELD=0;}
					if(event.jbutton.button==GP2X_BUTTON_RIGHT){KEY_RIGHT_HELD=0;}
					if(event.jbutton.button==GP2X_BUTTON_UP){KEY_UP_HELD=0;}
					if(event.jbutton.button==GP2X_BUTTON_LEFT){KEY_LEFT_HELD=0;}

					if(event.jbutton.button==GP2X_BUTTON_B)KEY_A_HELD=0;
				}
#endif

        }

        if(KEY_A_HELD==1)BUTTON_A_HELD=1;
        if(KEY_B_HELD==1)BUTTON_B_HELD=1;
        if(KEY_Y_HELD==1)BUTTON_Y_HELD=1;
        if(KEY_X_HELD==1)BUTTON_X_HELD=1;
        if(KEY_L_HELD==1)BUTTON_L_HELD=1;
        if(KEY_R_HELD==1)BUTTON_R_HELD=1;

        if(KEY_UP_HELD==1)BUTTON_UP_HELD=1;
        if(KEY_DOWN_HELD==1)BUTTON_DOWN_HELD=1;
        if(KEY_LEFT_HELD==1)BUTTON_LEFT_HELD=1;
        if(KEY_RIGHT_HELD==1)BUTTON_RIGHT_HELD=1;

        if(KEY_START_HELD==1)BUTTON_START_HELD=1;
        if(KEY_SELECT_HELD==1)BUTTON_SELECT_HELD=1;

        if(BUTTON_A_HELD==1&&LAST_BUTTON_A_HELD==0)BUTTON_A_PRESSED=1;
        if(BUTTON_B_HELD==1&&LAST_BUTTON_B_HELD==0)BUTTON_B_PRESSED=1;
        if(BUTTON_Y_HELD==1&&LAST_BUTTON_Y_HELD==0)BUTTON_Y_PRESSED=1;
        if(BUTTON_X_HELD==1&&LAST_BUTTON_X_HELD==0)BUTTON_X_PRESSED=1;
        if(BUTTON_L_HELD==1&&LAST_BUTTON_L_HELD==0)BUTTON_L_PRESSED=1;
        if(BUTTON_R_HELD==1&&LAST_BUTTON_R_HELD==0)BUTTON_R_PRESSED=1;

        if(BUTTON_START_HELD==1&&LAST_BUTTON_START_HELD==0)BUTTON_START_PRESSED=1;
        if(BUTTON_SELECT_HELD==1&&LAST_BUTTON_SELECT_HELD==0)BUTTON_SELECT_PRESSED=1;

        if(BUTTON_UP_HELD==1&&LAST_BUTTON_UP_HELD==0)BUTTON_UP_PRESSED=1;
        if(BUTTON_DOWN_HELD==1&&LAST_BUTTON_DOWN_HELD==0)BUTTON_DOWN_PRESSED=1;
        if(BUTTON_LEFT_HELD==1&&LAST_BUTTON_LEFT_HELD==0)BUTTON_LEFT_PRESSED=1;
        if(BUTTON_RIGHT_HELD==1&&LAST_BUTTON_RIGHT_HELD==0)BUTTON_RIGHT_PRESSED=1;


        if(BUTTON_A_HELD==1||BUTTON_L_HELD==1)BUTTON_ACTION_HELD=1;else BUTTON_ACTION_HELD=0;
        if(BUTTON_A_PRESSED==1||BUTTON_L_PRESSED==1)BUTTON_ACTION_PRESSED=1;

}

//==========================================================================================================================
void reset_controls()
{//==========================================================================================================================

        if(BUTTON_ACTION_PRESSED==1)BUTTON_ACTION_PRESSED=0;

        if(BUTTON_A_PRESSED==1)BUTTON_A_PRESSED=0;
        if(BUTTON_B_PRESSED==1)BUTTON_B_PRESSED=0;
        if(BUTTON_Y_PRESSED==1)BUTTON_Y_PRESSED=0;
        if(BUTTON_X_PRESSED==1)BUTTON_X_PRESSED=0;
        if(BUTTON_L_PRESSED==1)BUTTON_L_PRESSED=0;
        if(BUTTON_R_PRESSED==1)BUTTON_R_PRESSED=0;

        if(BUTTON_START_PRESSED==1)BUTTON_START_PRESSED=0;
        if(BUTTON_SELECT_PRESSED==1)BUTTON_SELECT_PRESSED=0;

        if(BUTTON_UP_PRESSED==1)BUTTON_UP_PRESSED=0;
        if(BUTTON_DOWN_PRESSED==1)BUTTON_DOWN_PRESSED=0;
        if(BUTTON_LEFT_PRESSED==1)BUTTON_LEFT_PRESSED=0;
        if(BUTTON_RIGHT_PRESSED==1)BUTTON_RIGHT_PRESSED=0;

        if(TouchScreen.Held==true)TouchScreen.Held=false;

}
