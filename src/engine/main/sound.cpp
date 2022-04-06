




#include "../../main.h"
//#include "sound.h"

#include "SDL_mixer.h"

int G_mute=0;//GLOBAL MUTE

int current_bgm_volume=0;

Mix_Music* song_playing = NULL;


int* current_mod_data_pointer=NULL;


char playingname[128];


Mix_Chunk *mixchunks[32] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
char* mixchunkfilename[32] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};


char blah_FileName[128];
char blah50_FileName[128];
char blah60_FileName[128];
char blah70_FileName[128];
char blah80_FileName[128];
char blah90_FileName[128];
//char blah_FileName[128];
char blah110_FileName[128];
char blah120_FileName[128];
char blah130_FileName[128];
char blah140_FileName[128];
char blah150_FileName[128];
char blah160_FileName[128];
char blah170_FileName[128];
char blah180_FileName[128];


char blip_FileName[128];
char blip50_FileName[128];
char blip170_FileName[128];



char footstep_FileName[128];
char gtbling_FileName[128];
char tick_FileName[128];
char blocksmash_FileName[128];
char whup_FileName[128];
char gotline_FileName[128];
char zap_FileName[128];

char carhorn_FileName[128];
char howdareyouwhyioutta_FileName[128];
char keyjingle_FileName[128];
char whatdoyouthinkyouredoing_FileName[128];
char birdchirp_FileName[128];
char crickets_FileName[128];
char doorknock_FileName[128];
char ping_FileName[128];
char carhit_FileName[128];
char carpass_FileName[128];
char carstart_FileName[128];
char doorsound_FileName[128];
char whatdoyouwant_FileName[128];
char elevatording_FileName[128];
char fastfooddrivethru_FileName[128];
char heavyapplause_FileName[128];
char icecreambell_FileName[128];
char murmur_FileName[128];
char oooh_FileName[128];
char booo_FileName[128];
char casinobeep_FileName[128];
char casinoding_FileName[128];
char laugh_FileName[128];
char schoolbell_FileName[128];
char applause_FileName[128];

char tv_FileName[128];

char cabinet_FileName[128];
char drawer_FileName[128];
char fridgedoor_FileName[128];
char microwavebeep_FileName[128];
char microwavedoor_FileName[128];
char pan_FileName[128];
char sink_FileName[128];
char step_FileName[128];

char pingbeep_FileName[128];
char pingbad_FileName[128];
char pinghighscore_FileName[128];

char ramiojump_FileName[128];
char ramiosplat_FileName[128];
char ramiobrickthud_FileName[128];
char ramiomoneybrick_FileName[128];

char ramiodeath_FileName[128];
char ramiowon_FileName[128];


char alarmclock_FileName[128];
char clocktick_FileName[128];
char clockbeep_FileName[128];

char knockknock_FileName[128];
char buzz_FileName[128];
char cannedair_FileName[128];

char gotitem_FileName[128];

char bird1_FileName[128];
char bird2_FileName[128];
char bird3_FileName[128];
char bird4_FileName[128];
char bird5_FileName[128];
char bird6_FileName[128];
char bird7_FileName[128];
char bird8_FileName[128];
char bird9_FileName[128];
char bird10_FileName[128];
char bird11_FileName[128];
char bird12_FileName[128];

char birds1_FileName[128];
char birds2_FileName[128];
char birds3_FileName[128];

char carhorn1_FileName[128];
char carhorn2_FileName[128];
char carhorn3_FileName[128];
char carhorn4_FileName[128];
char carhorn5_FileName[128];
char carhorn6_FileName[128];
char carhorn7_FileName[128];
char carhorn8_FileName[128];




//==========================================================================================================================
void HARDWARE_sound_init()//InitSound
{//==========================================================================================================================

	strcpy(blah_FileName,"data/sfx/blah.wav");
	strcpy(blah50_FileName,"data/sfx/blah50.wav");
	strcpy(blah60_FileName,"data/sfx/blah60.wav");
	strcpy(blah70_FileName,"data/sfx/blah70.wav");
	strcpy(blah80_FileName,"data/sfx/blah80.wav");
	strcpy(blah90_FileName,"data/sfx/blah90.wav");
	strcpy(blah110_FileName,"data/sfx/blah110.wav");
	strcpy(blah120_FileName,"data/sfx/blah120.wav");
	strcpy(blah130_FileName,"data/sfx/blah130.wav");
	strcpy(blah140_FileName,"data/sfx/blah140.wav");
	strcpy(blah150_FileName,"data/sfx/blah150.wav");
	strcpy(blah160_FileName,"data/sfx/blah160.wav");
	strcpy(blah170_FileName,"data/sfx/blah170.wav");
	strcpy(blah180_FileName,"data/sfx/blah180.wav");


	strcpy(blip_FileName,"data/sfx/blip.wav");
	strcpy(blip50_FileName,"data/sfx/blip50.wav");
	strcpy(blip170_FileName,"data/sfx/blip170.wav");


	strcpy(footstep_FileName,"data/sfx/footstepnormal.wav");
	strcpy(gtbling_FileName,"data/sfx/gtbling.wav");
	strcpy(tick_FileName,"data/sfx/tick.wav");
	strcpy(blocksmash_FileName,"data/sfx/blocksmash.wav");
	strcpy(whup_FileName,"data/sfx/whup.wav");
	strcpy(gotline_FileName,"data/sfx/gotline.wav");
	strcpy(zap_FileName,"data/sfx/zap.wav");

	//howdareyouwhyioutta_FileName,"data/sfx/howdareyouwhyioutta.wav");
	//whatdoyouthinkyouredoing_FileName,"data/sfx/whatdoyouthinkyouredoing.wav");
	//whatdoyouwant_FileName,"data/sfx/whatdoyouwant.wav");

	strcpy(carhorn_FileName,"data/sfx/carhorn.wav");
	strcpy(carhit_FileName,"data/sfx/carhit.wav");
	strcpy(carpass_FileName,"data/sfx/carpass.wav");
	strcpy(carstart_FileName,"data/sfx/carstart.wav");

	strcpy(keyjingle_FileName,"data/sfx/keyjingle.wav");

	strcpy(birdchirp_FileName,"data/sfx/birdchirp.wav");
	strcpy(crickets_FileName,"data/sfx/crickets.wav");

	strcpy(doorsound_FileName,"data/sfx/doorsound.wav");
	strcpy(doorknock_FileName,"data/sfx/doorknock.wav");

	strcpy(ping_FileName,"data/sfx/ping.wav");

	strcpy(elevatording_FileName,"data/sfx/elevatording.wav");
	strcpy(fastfooddrivethru_FileName,"data/sfx/fastfooddrivethru.wav");
	strcpy(heavyapplause_FileName,"data/sfx/heavyapplause.wav");
	strcpy(icecreambell_FileName,"data/sfx/icecreambell.wav");
	strcpy(murmur_FileName,"data/sfx/murmur.wav");
	strcpy(oooh_FileName,"data/sfx/oooh.wav");
	strcpy(booo_FileName,"data/sfx/booo.wav");
	strcpy(casinobeep_FileName,"data/sfx/casinobeep.wav");
	strcpy(casinoding_FileName,"data/sfx/casinoding.wav");
	strcpy(laugh_FileName,"data/sfx/laugh.wav");
	strcpy(schoolbell_FileName,"data/sfx/schoolbell.wav");
	strcpy(applause_FileName,"data/sfx/applause.wav");

	strcpy(tv_FileName,"data/sfx/tv.wav");

	strcpy(cabinet_FileName,"data/sfx/cabinet.wav");
	strcpy(drawer_FileName,"data/sfx/drawer.wav");
	strcpy(fridgedoor_FileName,"data/sfx/fridgedoor.wav");
	strcpy(microwavebeep_FileName,"data/sfx/microwavebeep.wav");
	strcpy(microwavedoor_FileName,"data/sfx/microwavedoor.wav");
	strcpy(pan_FileName,"data/sfx/pan.wav");
	strcpy(sink_FileName,"data/sfx/sink.wav");
	strcpy(step_FileName,"data/sfx/step.wav");

	strcpy(pingbeep_FileName,"data/sfx/pingbeep.wav");
	strcpy(pingbad_FileName,"data/sfx/pingbad.wav");
	strcpy(pinghighscore_FileName,"data/sfx/pinghighscore.wav");

	strcpy(ramiojump_FileName,"data/sfx/ramiojump.wav");
	strcpy(ramiosplat_FileName,"data/sfx/ramiosplat.wav");
	strcpy(ramiobrickthud_FileName,"data/sfx/ramiobrickthud.wav");
	strcpy(ramiomoneybrick_FileName,"data/sfx/ramiomoneybrick.wav");
	strcpy(ramiodeath_FileName,"data/sfx/ramiodeath.wav");
	strcpy(ramiowon_FileName,"data/sfx/ramiowon.wav");

	strcpy(alarmclock_FileName,"data/sfx/alarmclock.wav");
	strcpy(clocktick_FileName,"data/sfx/clocktick.wav");
	strcpy(clockbeep_FileName,"data/sfx/clockbeep.wav");
	strcpy(knockknock_FileName,"data/sfx/knockknock.wav");
	strcpy(buzz_FileName,"data/sfx/buzz.wav");
	strcpy(cannedair_FileName,"data/sfx/cannedair.wav");
	strcpy(gotitem_FileName,"data/sfx/gotitem.wav");

	strcpy(bird1_FileName,"data/sfx/bird1.wav");
	strcpy(bird2_FileName,"data/sfx/bird2.wav");
	strcpy(bird3_FileName,"data/sfx/bird3.wav");
	strcpy(bird4_FileName,"data/sfx/bird4.wav");
	strcpy(bird5_FileName,"data/sfx/bird5.wav");
	strcpy(bird6_FileName,"data/sfx/bird6.wav");
	strcpy(bird7_FileName,"data/sfx/bird7.wav");
	strcpy(bird8_FileName,"data/sfx/bird8.wav");
	strcpy(bird9_FileName,"data/sfx/bird9.wav");
	strcpy(bird10_FileName,"data/sfx/bird10.wav");
	strcpy(bird11_FileName,"data/sfx/bird11.wav");
	strcpy(bird12_FileName,"data/sfx/bird12.wav");

	strcpy(birds1_FileName,"data/sfx/birds1.wav");
	strcpy(birds2_FileName,"data/sfx/birds2.wav");
	strcpy(birds3_FileName,"data/sfx/birds3.wav");

	strcpy(carhorn1_FileName,"data/sfx/carhorn1.wav");
	strcpy(carhorn2_FileName,"data/sfx/carhorn2.wav");
	strcpy(carhorn3_FileName,"data/sfx/carhorn3.wav");
	strcpy(carhorn4_FileName,"data/sfx/carhorn4.wav");
	strcpy(carhorn5_FileName,"data/sfx/carhorn5.wav");
	strcpy(carhorn6_FileName,"data/sfx/carhorn6.wav");
	strcpy(carhorn7_FileName,"data/sfx/carhorn7.wav");
	strcpy(carhorn8_FileName,"data/sfx/carhorn8.wav");

}


//==========================================================================================================================
char* HARDWARE_get_sound_filename_from_name(const char* name, int freq)
{//==========================================================================================================================

	char* filename = NULL;

	if(strcmp(name,"blah")==0)
	{
		if(freq>=83000)filename=blah180_FileName;
		else if(freq>=78000&&freq<=83000)filename=blah170_FileName;
		else if(freq>=73000&&freq<=78000)filename=blah160_FileName;
		else if(freq>=68000&&freq<=73000)filename=blah150_FileName;
		else if(freq>=63000&&freq<=68000)filename=blah140_FileName;
		else if(freq>=58000&&freq<=63000)filename=blah130_FileName;
		else if(freq>=53000&&freq<=58000)filename=blah120_FileName;
		else if(freq>=48000&&freq<=53000)filename=blah110_FileName;
		else if(freq>=43000&&freq<=48000)filename=blah_FileName;
		else if(freq>=38000&&freq<=43000)filename=blah90_FileName;
		else if(freq>=33000&&freq<=38000)filename=blah80_FileName;
		else if(freq>=28000&&freq<=33000)filename=blah70_FileName;
		else if(freq>=23000&&freq<=28000)filename=blah60_FileName;
		else if(freq<=23000)filename=blah50_FileName;
	}


	if(strcmp(name,"blip")==0)
	{
		if(freq>48000)filename=blip170_FileName;
		else if(freq>=43000&&freq<=48000)filename=blip_FileName;
		else if(freq<43000)filename=blip50_FileName;
	}



	if(strcmp(name,"footstep")==0)filename=footstep_FileName;
	if(strcmp(name,"gtbling")==0)filename=gtbling_FileName;
	if(strcmp(name,"tick")==0)filename=tick_FileName;
	if(strcmp(name,"blocksmash")==0)filename=blocksmash_FileName;
	if(strcmp(name,"whup")==0)filename=whup_FileName;
	if(strcmp(name,"gotline")==0)filename=gotline_FileName;
	if(strcmp(name,"zap")==0)filename=zap_FileName;


	if(strcmp(name,"carhorn")==0)filename=carhorn_FileName;
	if(strcmp(name,"howdareyouwhyioutta")==0)filename=howdareyouwhyioutta_FileName;
	if(strcmp(name,"keyjingle")==0)filename=keyjingle_FileName;
	if(strcmp(name,"whatdoyouthinkyouredoing")==0)filename=whatdoyouthinkyouredoing_FileName;
	if(strcmp(name,"birdchirp")==0)filename=birdchirp_FileName;
	if(strcmp(name,"crickets")==0)filename=crickets_FileName;
	if(strcmp(name,"doorknock")==0)filename=doorknock_FileName;
	if(strcmp(name,"ping")==0)filename=ping_FileName;
	if(strcmp(name,"carhit")==0)filename=carhit_FileName;
	if(strcmp(name,"carpass")==0)filename=carpass_FileName;
	if(strcmp(name,"carstart")==0)filename=carstart_FileName;
	if(strcmp(name,"doorsound")==0)filename=doorsound_FileName;
	if(strcmp(name,"whatdoyouwant")==0)filename=whatdoyouwant_FileName;
	if(strcmp(name,"elevatording")==0)filename=elevatording_FileName;
	if(strcmp(name,"fastfooddrivethru")==0)filename=fastfooddrivethru_FileName;
	if(strcmp(name,"heavyapplause")==0)filename=heavyapplause_FileName;
	if(strcmp(name,"icecreambell")==0)filename=icecreambell_FileName;
	if(strcmp(name,"murmur")==0)filename=murmur_FileName;
	if(strcmp(name,"oooh")==0)filename=oooh_FileName;
	if(strcmp(name,"booo")==0)filename=booo_FileName;
	if(strcmp(name,"casinobeep")==0)filename=casinobeep_FileName;
	if(strcmp(name,"casinoding")==0)filename=casinoding_FileName;
	if(strcmp(name,"laugh")==0)filename=laugh_FileName;
	if(strcmp(name,"schoolbell")==0)filename=schoolbell_FileName;
	if(strcmp(name,"applause")==0)filename=applause_FileName;

	if(strcmp(name,"tv")==0)filename=tv_FileName;



	if(strcmp(name,"cabinet")==0)filename=cabinet_FileName;
	if(strcmp(name,"drawer")==0)filename=drawer_FileName;
	if(strcmp(name,"fridgedoor")==0)filename=fridgedoor_FileName;
	if(strcmp(name,"microwavebeep")==0)filename=microwavebeep_FileName;
	if(strcmp(name,"microwavedoor")==0)filename=microwavedoor_FileName;
	if(strcmp(name,"pan")==0)filename=pan_FileName;
	if(strcmp(name,"sink")==0)filename=sink_FileName;
	if(strcmp(name,"step")==0)filename=step_FileName;

	if(strcmp(name,"pingbeep")==0)filename=pingbeep_FileName;
	if(strcmp(name,"pingbad")==0)filename=pingbad_FileName;
	if(strcmp(name,"pinghighscore")==0)filename=pinghighscore_FileName;


	if(strcmp(name,"ramiojump")==0)filename=ramiojump_FileName;
	if(strcmp(name,"ramiosplat")==0)filename=ramiosplat_FileName;
	if(strcmp(name,"ramiobrickthud")==0)filename=ramiobrickthud_FileName;
	if(strcmp(name,"ramiomoneybrick")==0)filename=ramiomoneybrick_FileName;
	if(strcmp(name,"ramiodeath")==0)filename=ramiodeath_FileName;
	if(strcmp(name,"ramiowon")==0)filename=ramiowon_FileName;

	if(strcmp(name,"alarmclock")==0)filename=alarmclock_FileName;
	if(strcmp(name,"clocktick")==0)filename=clocktick_FileName;
	if(strcmp(name,"clockbeep")==0)filename=clockbeep_FileName;
	if(strcmp(name,"knockknock")==0)filename=knockknock_FileName;
	if(strcmp(name,"buzz")==0)filename=buzz_FileName;
	if(strcmp(name,"cannedair")==0)filename=cannedair_FileName;
	if(strcmp(name,"gotitem")==0)filename=gotitem_FileName;



	if(strcmp(name,"bird1")==0)filename=bird1_FileName;
	if(strcmp(name,"bird2")==0)filename=bird2_FileName;
	if(strcmp(name,"bird3")==0)filename=bird3_FileName;
	if(strcmp(name,"bird4")==0)filename=bird4_FileName;
	if(strcmp(name,"bird5")==0)filename=bird5_FileName;
	if(strcmp(name,"bird6")==0)filename=bird6_FileName;
	if(strcmp(name,"bird7")==0)filename=bird7_FileName;
	if(strcmp(name,"bird8")==0)filename=bird8_FileName;
	if(strcmp(name,"bird9")==0)filename=bird9_FileName;
	if(strcmp(name,"bird10")==0)filename=bird10_FileName;
	if(strcmp(name,"bird11")==0)filename=bird11_FileName;
	if(strcmp(name,"bird12")==0)filename=bird12_FileName;

	if(strcmp(name,"birds1")==0)filename=birds1_FileName;
	if(strcmp(name,"birds2")==0)filename=birds2_FileName;
	if(strcmp(name,"birds3")==0)filename=birds3_FileName;


	if(strcmp(name,"carhorn1")==0)filename=carhorn1_FileName;
	if(strcmp(name,"carhorn2")==0)filename=carhorn2_FileName;
	if(strcmp(name,"carhorn3")==0)filename=carhorn3_FileName;
	if(strcmp(name,"carhorn4")==0)filename=carhorn4_FileName;
	if(strcmp(name,"carhorn5")==0)filename=carhorn5_FileName;
	if(strcmp(name,"carhorn6")==0)filename=carhorn6_FileName;
	if(strcmp(name,"carhorn7")==0)filename=carhorn7_FileName;
	if(strcmp(name,"carhorn8")==0)filename=carhorn8_FileName;

	return filename;
}



//==========================================================================================================================
Mix_Chunk* HARDWARE_get_sound_data_pointer_from_name(const char* name, int freq)
{//==========================================================================================================================

	char* filename = NULL;


	filename = HARDWARE_get_sound_filename_from_name(name,freq);
	if(filename==NULL)return NULL;

	//search mixchunkfilenames 0-31 for matches with filename
	int d=-1;
	int x=0;
	for(x=0;x<MAX_SOUNDS_PLAYING;x++)
	{
		if(mixchunkfilename[x]==filename)
		{
			d=x;
			x=MAX_SOUNDS_PLAYING;
			break;
		}
	}

	if(d==-1)
	{
		//find open filename slot
		for(x=0;x<MAX_SOUNDS_PLAYING;x++)
		{
			if(mixchunkfilename[x]==NULL)
			{
				d=x;
				mixchunkfilename[d]=filename;//set slot to filename
				mixchunks[d] = Mix_LoadWAV(mixchunkfilename[d]);//load wav
				x=MAX_SOUNDS_PLAYING;
				break;
			}
		}
	}

	return mixchunks[d];
}


//==========================================================================================================================
bool HARDWARE_play_sound(const char* name,int vol,int freq, int loop)//if(!HARDWARE_is_sound_channel_busy(chan))//HARDWARE_PlayFSSoundEx2(chan,HARDWARE_FSGetFile(0,name,""),vol,freq,0,loop,0);
{//==========================================================================================================================

	if(G_mute)vol=0;


	Mix_Chunk* data = NULL;
	data = HARDWARE_get_sound_data_pointer_from_name(name,freq);

	if(data!=NULL)
	{
		if(loop==1)loop=-1;//infinite loops
		Mix_VolumeChunk(data,MIX_MAX_VOLUME*((float)((float)vol/256.0f)));
		Mix_PlayChannel(-1, data, loop);
	}
	else
	{
		ERROR_set_error(name);
		ERROR_set_error(" could not be played.\n");
	}


	return true;
}

//==========================================================================================================================
bool HARDWARE_play_sound_if_not_playing(const char* name,int vol,int freq, int loop)
{//==========================================================================================================================


	if(G_mute)vol=0;


	char* filename = NULL;
	filename = HARDWARE_get_sound_filename_from_name(name,freq);
	if(filename==NULL)return 0;

	int x=0;
	for(x=0;x<MAX_SOUNDS_PLAYING;x++)
	{
		if(mixchunkfilename[x]!=NULL)
		if(strcmp(mixchunkfilename[x],filename)==0)
		{

				return 0;

		}
	}

	HARDWARE_play_sound(name,vol,freq,loop);


	return 1;
}

//==========================================================================================================================
void HARDWARE_stop_sound(const char* name)//if(HARDWARE_is_sound_channel_busy(chan))HARDWARE_StopSound(chan);
{//==========================================================================================================================

	Mix_Chunk* data = NULL;
	data = HARDWARE_get_sound_data_pointer_from_name(name,44100);

	//go through all playing channels, if channel is playing data, stop channel
	if(data!=NULL)
	{
		int channel=0;
		int maxchannels= Mix_AllocateChannels(-1);

		for(channel=0;channel<maxchannels;channel++)
		{
			if(data==Mix_GetChunk(channel))Mix_HaltChannel(channel);
		}
	}
}

//==========================================================================================================================
void HARDWARE_unload_wavs_done_playing()
{//==========================================================================================================================

	//go through each mixchunk[d]
	//see if still playing
	//if not playing, unload mixchunk[d] and set mixchunkfilename[d] to NULL

	int x=0;
	for(x=0;x<MAX_SOUNDS_PLAYING;x++)
	{

		if(mixchunks[x]!=NULL&&mixchunkfilename[x]!=NULL)
		{
			int channel=0;
			int playing=0;
			int maxchannels= Mix_AllocateChannels(-1);
			for(channel=0;channel<maxchannels;channel++)
			{

				if(mixchunks[x]==Mix_GetChunk(channel))playing=1;
			}

			if(playing==0)
			{

				if(
					strcmp(mixchunkfilename[x],"data/sfx/footstepnormal.wav")!=0//dont unload footstep, its used a lot
					)
				{
					Mix_FreeChunk(mixchunks[x]);
					mixchunks[x]=NULL;
					mixchunkfilename[x]=NULL;
				}
			}
		}
	}


}

//==========================================================================================================================
void HARDWARE_set_channel_volume(int chan, int vol)//if(HARDWARE_is_sound_channel_busy(chan))HARDWARE_StopSound(chan);
{//==========================================================================================================================

	if(G_mute)vol=0;
	else
	Mix_Volume(chan,MIX_MAX_VOLUME*((float)((float)vol/256.0f)));
}




//==========================================================================================================================
void HARDWARE_set_music_volume(int vol)//if(HARDWARE_is_sound_channel_busy(chan))HARDWARE_StopSound(chan);
{//==========================================================================================================================

	if(G_mute)vol=0;

	if(current_bgm_volume!=vol)
	{
		current_bgm_volume=vol;
		if(song_playing!=NULL)Mix_VolumeMusic(MIX_MAX_VOLUME*((float)((float)vol/64.0f)));
	}
}







//==========================================================================================================================
void HARDWARE_play_music(const char* name,int vol)//HARDWARE_PlayFSMod(mod);
{//==========================================================================================================================

	if(G_mute)vol=0;


	if(strcmp(name,playingname)!=0||song_playing==NULL)
	{

		//copy string into playing string
		strcpy(playingname,name);


		//free the previous song
		if(song_playing!=NULL)
		{
			Mix_HookMusicFinished(NULL);
			Mix_HaltMusic();
			while(Mix_PlayingMusic()){};
			Mix_FreeMusic(song_playing);
			while(Mix_PlayingMusic()){};
			song_playing=NULL;
		}

		//load the new one
		if(strcmp(name,"nice")==0)						song_playing=Mix_LoadMUS("data/bgm/snappy_nice_v01.s3m");
		//if(strcmp(name,"simple")==0)					song_playing=Mix_LoadMUS("data/bgm/simple_v00.mod");
		if(strcmp(name,"g65_theme")==0)				song_playing=Mix_LoadMUS("data/bgm/g65_theme_v00.mod");
		if(strcmp(name,"birds_horns")==0)				song_playing=Mix_LoadMUS("data/bgm/birds_horns_v00.mod");
		if(strcmp(name,"snappy")==0)					song_playing=Mix_LoadMUS("data/bgm/snappy_v08.mod");
		if(strcmp(name,"tetrid")==0)				song_playing=Mix_LoadMUS("data/bgm/tetrid_v00.mod");
		if(strcmp(name,"tetrid_doublespeed")==0)	song_playing=Mix_LoadMUS("data/bgm/tetrid_doublespeed_v00.mod");
		if(strcmp(name,"tetrid_death")==0)			song_playing=Mix_LoadMUS("data/bgm/tetrid_death_v00.mod");
		if(strcmp(name,"s31")==0)						song_playing=Mix_LoadMUS("data/bgm/s31_v07.mod");
		if(strcmp(name,"k")==0)						song_playing=Mix_LoadMUS("data/bgm/k_v01.mod");
		//if(strcmp(name,"casino")==0)					song_playing=Mix_LoadMUS("data/bgm/casino_v00.mod");
		//if(strcmp(name,"disko")==0)					song_playing=Mix_LoadMUS("data/bgm/disko_v04.mod");
		if(strcmp(name,"dinnertime")==0)				song_playing=Mix_LoadMUS("data/bgm/dinnertime_v00.s3m");
		if(strcmp(name,"ramio")==0)				song_playing=Mix_LoadMUS("data/bgm/ramio_v00.s3m");
		if(strcmp(name,"scary")==0)				song_playing=Mix_LoadMUS("data/bgm/scary_v01.mod");
		if(strcmp(name,"chase")==0)				song_playing=Mix_LoadMUS("data/bgm/chase_v00.s3m");
		if(strcmp(name,"bobend")==0)				song_playing=Mix_LoadMUS("data/bgm/bobend_v00.s3m");

		if(song_playing==NULL)
		{
			ERROR_set_error(name);
			ERROR_set_error(" could not be loaded.\n");
		}
		else
		Mix_PlayMusic(song_playing, -1);
	}




	if(vol!=current_bgm_volume)
	{
		current_bgm_volume=vol;
		if(song_playing!=NULL)Mix_VolumeMusic(MIX_MAX_VOLUME*((float)((float)vol/64.0f)));
	}


}


//==========================================================================================================================
void HARDWARE_stop_music()//HARDWARE_StopMod();
{//==========================================================================================================================

	if(song_playing!=NULL)
	{

			Mix_HookMusicFinished(NULL);
			Mix_HaltMusic();
			while(Mix_PlayingMusic()){};
			Mix_FreeMusic(song_playing);
			while(Mix_PlayingMusic()){};
			song_playing=NULL;
	}

}
