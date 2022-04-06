//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================
#ifndef CONTROLS_H
#define CONTROLS_H
//==============================================================================


typedef struct {
   int Held, Released, Pressed, Pressed0;
   int X, Y, altX, altY, Pressure, Vx, Vy, oldVx, oldVy, Downtime, Uptime, DoubleTap;
} HARDWARE_TouchScreen;

//================
//defines
//================



//================
//variables
//================


extern int DEADZONE;

extern bool KEY_UP_HELD;
extern bool KEY_DOWN_HELD;
extern bool KEY_LEFT_HELD;
extern bool KEY_RIGHT_HELD;

extern bool KEY_START_HELD;
extern bool KEY_SELECT_HELD;

extern bool KEY_A_HELD;
extern bool KEY_B_HELD;
extern bool KEY_Y_HELD;
extern bool KEY_X_HELD;
extern bool KEY_L_HELD;
extern bool KEY_R_HELD;

extern SDL_Event event;
extern SDL_Joystick *stick;


extern bool BUTTON_ACTION_PRESSED;
extern bool BUTTON_UP_PRESSED;
extern bool BUTTON_DOWN_PRESSED;
extern bool BUTTON_LEFT_PRESSED;
extern bool BUTTON_RIGHT_PRESSED;
extern bool BUTTON_L_PRESSED;
extern bool BUTTON_R_PRESSED;
extern bool BUTTON_A_PRESSED;
extern bool BUTTON_B_PRESSED;
extern bool BUTTON_X_PRESSED;
extern bool BUTTON_Y_PRESSED;
extern bool BUTTON_START_PRESSED;
extern bool BUTTON_SELECT_PRESSED;

extern bool BUTTON_ACTION_HELD;
extern bool BUTTON_UP_HELD;
extern bool BUTTON_DOWN_HELD;
extern bool BUTTON_LEFT_HELD;
extern bool BUTTON_RIGHT_HELD;
extern bool BUTTON_L_HELD;
extern bool BUTTON_R_HELD;
extern bool BUTTON_A_HELD;
extern bool BUTTON_B_HELD;
extern bool BUTTON_X_HELD;
extern bool BUTTON_Y_HELD;
extern bool BUTTON_START_HELD;
extern bool BUTTON_SELECT_HELD;


extern float MAXZOOM;
extern float MINZOOM;
extern float ZOOMINCREMENT;


extern HARDWARE_TouchScreen TouchScreen;


//================
//prototypes
//================

void check_controls();
void whilefix();
void main_vbl_timed();


//==============================================================================
#endif
//==============================================================================
