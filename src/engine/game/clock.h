//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================
#ifndef CLOCK_H
#define CLOCK_H
//==============================================================================



//================
//defines
//================

#define SUNDAY 		1
#define MONDAY 		2
#define TUESDAY 	3
#define WEDNESDAY 	4
#define THURSDAY 	5
#define FRIDAY 		6
#define SATURDAY 	7

//================
//variables
//================

extern bool CLOCK_paused;

extern bool CLOCK_unknown;

extern bool CLOCK_moving;

extern int CLOCK_vbl_count;
extern int CLOCK_second;
extern int CLOCK_minute;
extern int CLOCK_hour;
extern int CLOCK_day;


//================
//prototypes
//================


void CLOCK_update_clock();
void CLOCK_init();
void CLOCK_vbl();
void CLOCK_main();




//==============================================================================
#endif
//==============================================================================


