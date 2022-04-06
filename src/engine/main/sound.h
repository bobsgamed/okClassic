//==============================================================================
#ifndef SOUND_H
#define SOUND_H
//==============================================================================

/*
#define SFX_BLAH 		(void*)blah, 		(int)blah_size
#define SFX_BLIP 		(void*)blip, 		(int)blip_size
#define SFX_FOOTSTEP 	(void*)footstep, 	(int)footstep_size
#define SFX_GTBLING 	(void*)gtbling, 	(int)gtbling_size
#define SFX_TICK 		(void*)tick, 		(int)tick_size
#define SFX_BLOCKSMASH 	(void*)blocksmash, 	(int)blocksmash_size
#define SFX_WHUP 		(void*)whup, 		(int)whup_size
#define SFX_GOTLINE 	(void*)gotline, 	(int)gotline_size
#define SFX_ZAP 		(void*)zap, 		(int)zap_size

*/



/*
int* simple_v00=0;
int* g65_theme_v00=0;
int* birds_horns_v00=0;
int* snappy_v03=0;
int* tetrid_v00=0;
int* tetrid_doublespeed_v00=0;
int* tetrid_death_v00=0;
int* s31_v07=0;
*/




/*
int* blah=NULL;
int blah_size=0;
int* blip=NULL;
int blip_size=0;
int* footstep=NULL;
int footstep_size=0;
int* gtbling=NULL;
int gtbling_size=0;
int* tick=NULL;
int tick_size=0;
int* blocksmash=NULL;
int blocksmash_size=0;
int* whup=NULL;
int whup_size=0;
int* gotline=NULL;
int gotline_size=0;
int* zap=NULL;
int zap_size=0;
*/

/*
int blah_size=0;
int blip_size=0;
int footstep_size=0;
int gtbling_size=0;
int tick_size=0;
int blocksmash_size=0;
int whup_size=0;
int gotline_size=0;
int zap_size=0;
*/

/*
#define MOD_SIMPLE_V00 0
//simple_v00
#define MOD_G65_THEME_V00 0
//g65_theme_v00
#define MOD_BIRDS_HORNS_V00 0
//birds_horns_v00
#define MOD_SNAPPY_V03 0
//snappy_v03
#define MOD_TETRID_V00 0
//tetrid_v00
#define MOD_TETRID_DOUBLESPEED_V00 0
//tetrid_doublespeed_v00
#define MOD_TETRID_DEATH_V00 0
//tetrid_death_v00
#define MOD_S31_V07 0
//s31_v07
*/


/*

Mix_Music *BGM_simple;
Mix_Music *BGM_g65_theme;
Mix_Music *BGM_birds_horns;
Mix_Music *BGM_snappy;
Mix_Music *BGM_tetrid;
Mix_Music *BGM_tetrid_doublespeed;
Mix_Music *BGM_tetrid_death;
Mix_Music *BGM_s31;
Mix_Music *BGM_casino;
Mix_Music *BGM_disko;
Mix_Music *BGM_nice;
Mix_Music *BGM_dinnertime;
*/




//================
//defines
//================


#define MAX_SOUNDS_PLAYING 32


//================
//variables
//================

extern int G_mute;//GLOBAL MUTE



//================
//prototypes
//================


bool HARDWARE_play_sound(const char* name,int vol,int freq, int loop);
void HARDWARE_stop_music();
void HARDWARE_play_music(const char* name,int vol);
void HARDWARE_stop_sound(const char* name);
void HARDWARE_set_music_volume(int vol);
bool HARDWARE_play_sound_if_not_playing(const char* name,int vol,int freq, int loop);

void HARDWARE_unload_wavs_done_playing();

void HARDWARE_sound_init();








//==============================================================================
#endif
//==============================================================================
