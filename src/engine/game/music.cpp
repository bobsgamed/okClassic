


#include "../../main.h"
//#include "music.h"




int sfxmod=1;



//=========================================================================================================================
void sfx_crickets(int vol)
{//=========================================================================================================================

if(kitchen_tv_on)sfxmod=6;else sfxmod=1;



	static int cricket_timer=0;
	if(cricket_timer!=CLOCK_second/(4*sfxmod))//about twice a second, its possible
	{
		cricket_timer=CLOCK_second/(4*sfxmod);
		if(r(5)==0)HARDWARE_play_sound("crickets",vol,(44100/2)+((r(3))*(44100/4)),0); //one out of every 5 chances
	}
}


//=========================================================================================================================
void sfx_clocktick(int vol)
{//=========================================================================================================================

if(kitchen_tv_on)sfxmod=6;else sfxmod=1;

	static int clocktick_timer=0;

	if(clocktick_timer!=CLOCK_second/(6*sfxmod))//about twice a second, its possible
	{
		clocktick_timer=CLOCK_second/(6*sfxmod);
		HARDWARE_play_sound("tick",vol,(44100),0); //one out of every 5 chances
	}
}

//=========================================================================================================================
void sfx_birds(int vol)
{//=========================================================================================================================

if(kitchen_tv_on)sfxmod=6;else sfxmod=1;

	static int birds_timer=0;
	if(birds_timer!=CLOCK_second/(10*sfxmod))//second is 10 seconds per second, so this is once every 1 seconds
	{
		birds_timer=CLOCK_second/(10*sfxmod);

		if(r(2)==0)//once every 2 times, average is 2*2 once every 2 seconds.
		{
			int s = r(15);

			if(s==0)HARDWARE_play_sound("bird1",vol,(44100/2)+((r(3))*(44100/4)),0);
			if(s==1)HARDWARE_play_sound("bird2",vol,(44100/2)+((r(3))*(44100/4)),0);
			if(s==2)HARDWARE_play_sound("bird3",vol,(44100/2)+((r(3))*(44100/4)),0);
			if(s==3)HARDWARE_play_sound("bird4",vol,(44100/2)+((r(3))*(44100/4)),0);
			if(s==4)HARDWARE_play_sound("bird5",vol,(44100/2)+((r(3))*(44100/4)),0);
			if(s==5)HARDWARE_play_sound("bird6",vol,(44100/2)+((r(3))*(44100/4)),0);
			if(s==6)HARDWARE_play_sound("bird7",vol,(44100/2)+((r(3))*(44100/4)),0);
			if(s==7)HARDWARE_play_sound("bird8",vol,(44100/2)+((r(3))*(44100/4)),0);
			if(s==8)HARDWARE_play_sound("bird9",vol,(44100/2)+((r(3))*(44100/4)),0);
			if(s==9)HARDWARE_play_sound("bird10",vol,(44100/2)+((r(3))*(44100/4)),0);
			if(s==10)HARDWARE_play_sound("bird11",vol,(44100/2)+((r(3))*(44100/4)),0);
			if(s==11)HARDWARE_play_sound("bird12",vol,(44100/2)+((r(3))*(44100/4)),0);

			if(s==12)HARDWARE_play_sound("birds1",vol,(44100/2)+((r(3))*(44100/4)),0);
			if(s==13)HARDWARE_play_sound("birds2",vol,(44100/2)+((r(3))*(44100/4)),0);
			if(s==14)HARDWARE_play_sound("birds3",vol,(44100/2)+((r(3))*(44100/4)),0);
		}
	}
}

//=========================================================================================================================
void sfx_carhorns(int vol)
{//=========================================================================================================================

	static int carhorns_timer=0;
	if(carhorns_timer!=CLOCK_second/(40*sfxmod))//once every 4 seconds
	{
		carhorns_timer=CLOCK_second/(40*sfxmod);

		if(r(3)==0)//once out of 3, so once every 12 seconds.
		{
			int s = r(8);
			if(s==0)HARDWARE_play_sound("carhorn1",vol,(44100/2)+((r(3))*(44100/4)),0);
			if(s==1)HARDWARE_play_sound("carhorn2",vol,(44100/2)+((r(3))*(44100/4)),0);
			if(s==2)HARDWARE_play_sound("carhorn3",vol,(44100/2)+((r(3))*(44100/4)),0);
			if(s==3)HARDWARE_play_sound("carhorn4",vol,(44100/2)+((r(3))*(44100/4)),0);
			if(s==4)HARDWARE_play_sound("carhorn5",vol,(44100/2)+((r(3))*(44100/4)),0);
			if(s==5)HARDWARE_play_sound("carhorn6",vol,(44100/2)+((r(3))*(44100/4)),0);
			if(s==6)HARDWARE_play_sound("carhorn7",vol,(44100/2)+((r(3))*(44100/4)),0);
			if(s==7)HARDWARE_play_sound("carhorn8",vol,(44100/2)+((r(3))*(44100/4)),0);
		}
	}
}



//=========================================================================================================================
void music_init()
{//=========================================================================================================================

	//mods[0]=HARDWARE_get_file_index("simple_v00");
	//mods[1]=HARDWARE_get_file_index("underwater_v03");
	//mods[2]=HARDWARE_get_file_index("overwater_v03");
	//mods[3]=HARDWARE_get_file_index("calmbeat_v05");
	//mods[4]=HARDWARE_get_file_index("rain_v06");
	//mods[5]=HARDWARE_get_file_index("disko_v04");
	//mods[6]=HARDWARE_get_file_index("casino_v00");
	//mods[7]=HARDWARE_get_file_index("snappy_v01");
	//mods[8]=HARDWARE_get_file_index("tiny_v01");

	//current_mod = mods[0];



	//music_playing=1;

	//HARDWARE_play_music_file("/bgm/simple_v00.mod");



	//SndPlayMOD(simple_v00);
	//SndPlayMOD(g65_theme_v00);

}



//=========================================================================================================================
void music_main()
{//=========================================================================================================================




}



//=========================================================================================================================
void music_vbl()
{//=========================================================================================================================




}




