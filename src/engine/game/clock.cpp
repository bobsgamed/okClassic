

#include "../../main.h"
//#include "clock.h"

	CAPTION* timecaption=NULL;
	CAPTION* daycaption=NULL;
	CAPTION* moneycaption=NULL;

	bool CLOCK_paused=0;

	bool CLOCK_unknown=0;

	bool CLOCK_moving=0;

	int CLOCK_vbl_count=0;
	int CLOCK_second=0;
	int CLOCK_minute=0;
	int CLOCK_hour=0;
	int CLOCK_day=0;

	char CLOCK_day_text[128];
	char CLOCK_time_text[128];


//=========================================================================================================================
void CLOCK_init()
{//=========================================================================================================================

	sprintf(CLOCK_day_text," Sunday ");
	sprintf(CLOCK_time_text," 00:00 PM ");

	CLOCK_vbl_count=0;
	CLOCK_second=0;
	CLOCK_minute=0;
	CLOCK_hour=1;
	CLOCK_day=1;

	CLOCK_update_clock();

	CLOCK_paused=0;

}

//=========================================================================================================================
void CLOCK_update_clock()
{//=========================================================================================================================


	int timecolor = RED;
	int timecolor2 = BLACK;

	if(CLOCK_unknown==0)
	{

		if(kitchen_tv_on)
		{
			timecolor = BLUE;
			timecolor2 = BLACK;
		}


		if(CLOCK_paused==1)
		{
			timecolor = DARKGRAY;
			timecolor2 = LIGHTGRAY;
		}

		switch(CLOCK_day)
		{
			case 1:{sprintf(CLOCK_day_text," Sunday "); break;}
			case 2:{sprintf(CLOCK_day_text," Monday "); break;}
			case 3:{sprintf(CLOCK_day_text," Tuesday "); break;}
			case 4:{sprintf(CLOCK_day_text," Wednesday "); break;}
			case 5:{sprintf(CLOCK_day_text," Thursday "); break;}
			case 6:{sprintf(CLOCK_day_text," Friday "); break;}
			case 7:{sprintf(CLOCK_day_text," Saturday "); break;}
			case 0:
			default:{CLOCK_day=0;break;}
		}

		switch(CLOCK_hour)
		{
			case 1:{CLOCK_time_text[1]='0';CLOCK_time_text[2]='1';CLOCK_time_text[7]='A'; break;}
			case 2:{CLOCK_time_text[1]='0';CLOCK_time_text[2]='2';CLOCK_time_text[7]='A'; break;}
			case 3:{CLOCK_time_text[1]='0';CLOCK_time_text[2]='3';CLOCK_time_text[7]='A'; break;}
			case 4:{CLOCK_time_text[1]='0';CLOCK_time_text[2]='4';CLOCK_time_text[7]='A'; break;}
			case 5:{CLOCK_time_text[1]='0';CLOCK_time_text[2]='5';CLOCK_time_text[7]='A'; break;}
			case 6:{CLOCK_time_text[1]='0';CLOCK_time_text[2]='6';CLOCK_time_text[7]='A'; break;}
			case 7:{CLOCK_time_text[1]='0';CLOCK_time_text[2]='7';CLOCK_time_text[7]='A'; break;}
			case 8:{CLOCK_time_text[1]='0';CLOCK_time_text[2]='8';CLOCK_time_text[7]='A'; break;}
			case 9:{CLOCK_time_text[1]='0';CLOCK_time_text[2]='9';CLOCK_time_text[7]='A'; break;}
			case 10:{CLOCK_time_text[1]='1';CLOCK_time_text[2]='0';CLOCK_time_text[7]='A'; break;}
			case 11:{CLOCK_time_text[1]='1';CLOCK_time_text[2]='1';CLOCK_time_text[7]='A'; break;}
			case 12:{CLOCK_time_text[1]='1';CLOCK_time_text[2]='2';CLOCK_time_text[7]='P'; break;}
			case 13:{CLOCK_time_text[1]='0';CLOCK_time_text[2]='1';CLOCK_time_text[7]='P'; break;}
			case 14:{CLOCK_time_text[1]='0';CLOCK_time_text[2]='2';CLOCK_time_text[7]='P'; break;}
			case 15:{CLOCK_time_text[1]='0';CLOCK_time_text[2]='3';CLOCK_time_text[7]='P'; break;}
			case 16:{CLOCK_time_text[1]='0';CLOCK_time_text[2]='4';CLOCK_time_text[7]='P'; break;}
			case 17:{CLOCK_time_text[1]='0';CLOCK_time_text[2]='5';CLOCK_time_text[7]='P'; break;}
			case 18:{CLOCK_time_text[1]='0';CLOCK_time_text[2]='6';CLOCK_time_text[7]='P'; break;}
			case 19:{CLOCK_time_text[1]='0';CLOCK_time_text[2]='7';CLOCK_time_text[7]='P'; break;}
			case 20:{CLOCK_time_text[1]='0';CLOCK_time_text[2]='8';CLOCK_time_text[7]='P'; break;}
			case 21:{CLOCK_time_text[1]='0';CLOCK_time_text[2]='9';CLOCK_time_text[7]='P'; break;}
			case 22:{CLOCK_time_text[1]='1';CLOCK_time_text[2]='0';CLOCK_time_text[7]='P'; break;}
			case 23:{CLOCK_time_text[1]='1';CLOCK_time_text[2]='1';CLOCK_time_text[7]='P'; break;}
			case 24:{CLOCK_time_text[1]='1';CLOCK_time_text[2]='2';CLOCK_time_text[7]='A'; break;}
			case 0:
			default:{break;}
		}

		CLOCK_time_text[4] = 48+(CLOCK_minute/10);//48+int = ascii numbers
		CLOCK_time_text[5] = 48+(CLOCK_minute%10);

		//CAPTION_delete_caption(timecaption);
		//CAPTION_delete_caption(daycaption);
		//CAPTION_delete_caption(moneycaption);
		if(timecaption==NULL)CAPTION_make_caption(&timecaption,1,0,0,-1,(char*)CLOCK_time_text,FONT_SMALL_ID,timecolor,timecolor2,1,1);
		if(daycaption==NULL)CAPTION_make_caption(&daycaption,1,timecaption->width,0,-1,(char*)CLOCK_day_text,FONT_SMALL_ID,BLACK,WHITE,1,1);
		if(moneycaption==NULL)CAPTION_make_caption(&moneycaption,1,timecaption->width+daycaption->width,0,-1," $0 ",FONT_SMALL_ID,GREEN,BLACK,1,1);

		timecaption->color_txt=timecolor;
		timecaption->color_bg=timecolor2;

		if(strcmp(CLOCK_time_text,timecaption->text)!=0||strcmp(CLOCK_day_text,daycaption->text)!=0)
		{

			CAPTION_replace_text(timecaption,(const char*)CLOCK_time_text);
			CAPTION_replace_text(daycaption,(const char*)CLOCK_day_text);
			CAPTION_replace_text(moneycaption," $0 ");

			if(CLOCK_minute%15==0)
			{
				load_bg_pals_based_on_time();
				HARDWARE_reload_bg_textures();
			}
		}


	}
	else
	{
		//CAPTION_delete_caption(timecaption);
		//CAPTION_delete_caption(daycaption);
		//CAPTION_delete_caption(moneycaption);
		if(timecaption==NULL)CAPTION_make_caption(&timecaption,1,0,0,-1," ??:?? ",FONT_SMALL_ID,timecolor,timecolor2,1,1);
		if(daycaption==NULL)CAPTION_make_caption(&daycaption,1,timecaption->width,0,-1," ?????? ",FONT_SMALL_ID,BLACK,WHITE,1,1);
		if(moneycaption==NULL)CAPTION_make_caption(&moneycaption,1,timecaption->width+daycaption->width,0,-1," $? ",FONT_SMALL_ID,GREEN,BLACK,1,1);

		//CAPTION_replace_text(timecaption," ??:?? ");
		//CAPTION_replace_text(daycaption," ?????? ");
		//CAPTION_replace_text(moneycaption," $? ");

	}

}

//=========================================================================================================================
void CLOCK_vbl()
{//=========================================================================================================================

	//if(timecaption!=NULL)timecaption->scale=2.0f/ZOOM;
	//if(daycaption!=NULL)daycaption->scale=2.0f/ZOOM;
	//if(moneycaption!=NULL)moneycaption->scale=2.0f/ZOOM;

	if(CLOCK_paused==0&&GLOBAL_text_engine_state==0)
	{
		//CLOCK_moving=0;
		daycaption->screen_x=timecaption->width;
		moneycaption->screen_x=timecaption->width+daycaption->width;

		CLOCK_vbl_count++;

		if((CLOCK_vbl_count>=6)||(CLOCK_vbl_count>=1&&kitchen_tv_on==1))
		{
			CLOCK_vbl_count=0;
			CLOCK_second++;//10 seconds per second (60 vbls)
		}

		if(CLOCK_second>=60)
		{
			CLOCK_second=0;
			CLOCK_minute+=1; //ten minutes per minute
			CLOCK_moving=1;
			HARDWARE_play_sound("tick",64,44100,0);
		}

		if(CLOCK_minute>=60) //six minutes per hour,one day is 6*24 = 120 = 2 hours.
		{
			CLOCK_minute=0;
			CLOCK_hour++;
			CLOCK_moving=1;
			HARDWARE_play_sound("clockbeep",64,44100,0);
		}

		if(CLOCK_hour>24)
		{
			CLOCK_hour=1;
			CLOCK_day++;
			CLOCK_moving=1;

			mailman_came_today=0;
			icecreamman_came_today=0;
			jogger_came_today=0;
			dogwalker_came_today=0;

		}

		if(CLOCK_day>7)
		{
			CLOCK_day=1;
			CLOCK_moving=1;
		}
	}

	static bool last_clock_paused=false;

	if(last_clock_paused!=CLOCK_paused)
	{
		last_clock_paused=CLOCK_paused;
		CLOCK_moving=1;
	}



}
//=========================================================================================================================
void CLOCK_main()
{//=========================================================================================================================
	if(CLOCK_moving){CLOCK_update_clock();CLOCK_moving=0;}

}



