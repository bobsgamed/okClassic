
//==============================================================================
#ifndef PING_H
#define PING_H
//==============================================================================


//================
//defines
//================

	#define PING_PADDLE_SIZE_X 8
	#define PING_PADDLE_SIZE_Y 32
	#define PING_BALL_SIZE 8

	#define PING_HEIGHT_PIXELS ((192)-(15*2)-(3*2))
	#define PING_WIDTH_PIXELS (256-(15*2)-(3*2))

#define PADDLE_SIZE_X 8
#define PADDLE_SIZE_Y 32
#define BALL_SIZE 8

//================
//variables
//================

extern int GAME_playing_ping;

extern int PING_got_high_score;

extern int PING_paddle_gfx[PING_PADDLE_SIZE_X*PING_PADDLE_SIZE_Y];
extern int PING_ball_gfx[PING_PADDLE_SIZE_X*PING_PADDLE_SIZE_X];

//================
//prototypes
//================

//#include <cstdio>

void PING_update_score();
void PING_vbl();
void PING_init_game();
void PING_main();








//==============================================================================
#endif
//==============================================================================
