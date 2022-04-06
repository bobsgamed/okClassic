//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================



#include "../../main.h"
//#include "yuushouse.h"



#define RANGE_YUUDownstairsToGarage 1*8,9*8,2*8,13*8
#define RANGE_YUUDownstairsToUpstairs 2*8,26*8,8*8,27*8
#define RANGE_YUUDownstairsToDownstairsBathroom 26*8,35*8,30*8,36*8
#define RANGE_YUUDownstairsToOUTSIDEFrontyard 11*8,42*8,15*8,43*8
#define RANGE_YUUDownstairsToBasement 3*8,15*8,7*8,16*8
#define RANGE_YUUDownstairsToOUTSIDEBackyard 30*8,8*8,34*8,9*8
#define RANGE_YUUUpstairsToDownstairs 2*8,21*8,8*8,22*8
#define RANGE_YUUUpstairsToYuusRoom 47*8,8*8,51*8,9*8
#define RANGE_YUUUpstairsToBrothersRoom 24*8,8*8,28*8,9*8
#define RANGE_YUUUpstairsToParentsRoom 11*8,16*8,15*8,17*8
#define RANGE_YUUUpstairsToUpstairsBathroom 52*8,16*8,56*8,17*8
#define RANGE_YUUUpstairsToBabyRoom 34*8,16*8,38*8,17*8
#define RANGE_YUUYuusRoomToUpstairs 18*8,22*8,22*8,23*8
#define RANGE_TurnOnMES 14*8,11*8,18*8,12*8
#define RANGE_YUUBabyRoomToUpstairs 7*8,8*8,11*8,9*8
#define RANGE_YUUBrothersRoomToUpstairs 24*8,22*8,28*8,23*8
#define RANGE_YUUUpstairsBathroomToUpstairs 7*8,8*8,11*8,9*8
#define RANGE_YUUParentsRoomToUpstairs 4*8,8*8,8*8,9*8
#define RANGE_YUUBasementToDownstairs 3*8,8*8,7*8,9*8
#define RANGE_YUUGarageToDownstairs 25*8,10*8,26*8,14*8
#define RANGE_YUUGarageToAttic 4*8,10*8,8*8,11*8
#define RANGE_YUUAtticToGarage 4*8,14*8,7*8,15*8
#define RANGE_YUUDownstairsBathroomToDownstairs 4*8,17*8,8*8,18*8
#define RANGE_YUUMirrorEffect 6*8,11*8,11*8,13*8



NPC* dad_npc=NULL;
NPC* mom_npc=NULL;
NPC* brother_npc=NULL;
NPC* littlebro_npc=NULL;

int mom_flag=0;
int dad_flag=0;
int brother_flag=0;
NPC* coffee_npc = NULL;
int nes_turned_on=0;
int havelunch=0;

NPC* lunchnpc=NULL;
NPC* dinnernpc=NULL;

NPC* plate1=NULL;
NPC* plate2=NULL;
NPC* plate3=NULL;
NPC* plate4=NULL;
NPC* pingnpc=NULL;


CAPTION* yuu_ping_caption = NULL;
CAPTION* yuu_ramio_caption = NULL;

int kitchen_tv_on=0;



//int have_tissues_and_lotion=0;
//int have_coat_hanger=0;




///===============================================================================================================================================================================================
//YUUDownstairs
///===============================================================================================================================================================================================
void bobsgame_TOWNYUUDownstairs_Map_Load_Function()
{
//RANGE_YUUDownstairsToGarage 1*8,9*8,2*8,13*8
//RANGE_YUUDownstairsToUpstairs 2*8,26*8,8*8,27*8
//RANGE_YUUDownstairsToDownstairsBathroom 26*8,35*8,30*8,36*8
//RANGE_YUUDownstairsToOUTSIDEFrontyard 11*8,42*8,15*8,43*8
//RANGE_YUUDownstairsToBasement 3*8,15*8,7*8,16*8
//RANGE_YUUDownstairsToOUTSIDEBackyard 30*8,8*8,34*8,9*8


#define YUUDownstairs_StairsTop 4*8, 25*8
#define YUUDownstairs_StairsBottom 5*8, 38*8
#define YUUDownstairs_KitchenBottom 13*8, 38*8
#define YUUDownstairs_MiddleOfKitchen (18*8)-4, (21*8)+2
#define YUUDownstairs_KitchenSink (19*8), (12*8)-4
#define YUUDownstairs_CoffeeMaker (16*8), (12*8)-4
#define YUUDownstairs_Stove (13*8)+4, (18*8)
#define YUUDownstairs_Microwave (25*8), (12*8)-4
#define YUUDownstairs_Fridge (13*8)+4, (24*8)
#define YUUDownstairs_Cupboard (13*8), (12*8)-4
#define YUUDownstairs_TableLeft (20*8)-4, (21*8)+2
#define YUUDownstairs_TableRight (31*8)-3, (21*8)+2
#define YUUDownstairs_TableTopLeft 21*8, 18*8
//#define YUUDownstairs_TableTopRight
#define YUUDownstairs_GarageDoor 1*8, 12*8
#define YUUDownstairs_Couch 48*8, (33*8)
#define YUUDownstairs_Ping 48*8, (33*8)-3







//==============================================================================================================================
//YUUDOWNSTAIRS MAP LOAD
//==============================================================================================================================

	if(CLOCK_hour>0&&CLOCK_hour<6)	//midnight to 6 am
	{
		//nobody here
	}

	if(CLOCK_hour>=6&&CLOCK_hour<7)	//6 am to 7 am
	{



		//dad at kitchen table, mom at kitchen sink
		NPC_create_npc_xy_feet(&mom_npc,GFX_ADULT_mom, 16, 40, YUUDownstairs_KitchenSink);
		mom_npc->non_walkable=1;

		if(CLOCK_minute<29)
		{
			NPC_create_npc_xy_feet(&dad_npc,GFX_ADULT_dad, 16, 40, YUUDownstairs_TableLeft);
			dad_npc->non_walkable=1;
			NPC_animate_stand_dir(&dad_npc, RIGHT); //SETS FRAME COUNT TO 0 AND ANIMATES TO DIRECTION INPUT
		}
	}

	if(CLOCK_hour>=7&&CLOCK_hour<12+2)	//7 am to 2 pm
	{

		//mom on the couch, tv on, kicks you out
		//lunchbag on table. can't leave until you get it.
		NPC_create_npc_xy_feet(&mom_npc,GFX_ADULT_mom, 16, 40, YUUDownstairs_Couch);
		NPC_animate_stand_dir(&mom_npc, DOWN);
		mom_npc->non_walkable=1;
	}

	if(CLOCK_hour>=12+2&&CLOCK_hour<12+4)	//2 pm to 4 pm
	{
		//mom upstairs sleeping
		//brother in the kitchen
		if((CLOCK_hour==12+3&&CLOCK_minute<55))
		{
			NPC_create_npc_xy_feet(&brother_npc,GFX_KID_brother, 16, 32, YUUDownstairs_KitchenSink);
			brother_npc->non_walkable=1;
		}
	}

	if(CLOCK_hour>=12+4&&CLOCK_hour<12+6)	//4 pm to 7 pm
	{
		//mom cooking dinner in the kitchen
		NPC_create_npc_xy_feet(&mom_npc,GFX_ADULT_mom, 16, 40, YUUDownstairs_KitchenSink);
		mom_npc->non_walkable=1;
	}

	if(CLOCK_hour>=12+6&&CLOCK_hour<12+8)	//6 pm to 8 pm
	{
		//dad comes home
		//dinnertime
		//mom at the table right
		NPC_create_npc_xy_feet(&mom_npc,GFX_ADULT_mom, 16, 40, YUUDownstairs_TableRight);
		mom_npc->non_walkable=1;
		NPC_animate_stand_dir(&mom_npc, LEFT);
		NPC_create_npc_xy_feet(&dad_npc,GFX_ADULT_dad, 16, 40, YUUDownstairs_TableLeft);
		dad_npc->non_walkable=1;
		NPC_animate_stand_dir(&dad_npc, RIGHT); //SETS FRAME COUNT TO 0 AND ANIMATES TO DIRECTION INPUT
	}

	if(CLOCK_hour>=12+8&&CLOCK_hour<12+10)	//8 pm to 10 pm
	{
		//dad playing ping
		if(CLOCK_hour==12+8||CLOCK_minute<55)
			NPC_create_npc_xy_feet(&dad_npc,GFX_ADULT_dad, 16, 40, YUUDownstairs_Ping);

		dad_npc->non_walkable=1;

		//mom upstairs
	}

	if(CLOCK_hour>=12+10&&CLOCK_hour<24)	//10 pm to 12 am
	{
		//brother comes home
		//dad upstairs
		//mom upstairs
		if((CLOCK_hour==12+10&&CLOCK_minute>15)||(CLOCK_hour==12+11&&CLOCK_minute<55))
		{
			NPC_create_npc_xy_feet(&brother_npc,GFX_KID_brother, 16, 32, YUUDownstairs_TableLeft);
			NPC_animate_stand_dir(&brother_npc, RIGHT);
			brother_npc->non_walkable=1;
		}
	}
}





void bobsgame_TOWNYUUDownstairs_Map_Run_Function(int MAP_just_loaded)
{

	if(MAP_just_loaded==1)
	{

	}




//==============================================================================================================================
//YUUDOWNSTAIRS MAP RUN
//==============================================================================================================================


static int ping_switch=0;

			if(GLOBAL_text_engine_state==0&&ping_switch==1)
			{

				//clock paused


				//TODO: no music, no bird sounds

				GLOBAL_main_sprite_input_off=1;
				GLOBAL_main_sprite_standing=1;
				GLOBAL_main_sprite_actions_off=1;

				//yuu facing tv
				PLAYER_npc->MAP_x=48*8;
				PLAYER_npc->MAP_y=(33*8);
				PLAYER_npc->walk_dir=DOWN;
				NPC_animate_stand_dir(&PLAYER_npc, DOWN);


				//TODO: in brother room, play consoles "i'd better not touch these, he's gonna know

				//TODO: holding controller, flashing light in front of tv

				load_ping_tv_fullscreen();
				ping_switch=2;

				CLOCK_unknown=1;
				CLOCK_paused=1;

				GAME_playing_ping=1;
			}

			if(GLOBAL_text_engine_state==0&&ping_switch==2&&GAME_playing_ping==0)
			{
				ping_switch=3;

				TEXT_set_sprite_window(0,PLAYER_npc,NULL);
				TEXT_window("<NOCANCEL>Well that was easy. I got the high score, that's enough for me.<.>"
							"I don't get why my Dad likes this thing."
				);

				CLOCK_hour=6;
				CLOCK_minute=50;
				CLOCK_unknown=0;
				CLOCK_paused=0;
				CLOCK_update_clock();

			}


	//===============================================================================================
	if(CLOCK_hour>0&&CLOCK_hour<4)	//midnight to 4 am===============================================================================================
	{//===============================================================================================


		HARDWARE_stop_music();

		//crickets
		sfx_crickets(32);


	}
	//===============================================================================================
	if(CLOCK_hour>=4&&CLOCK_hour<6)	//4 to 6 am===============================================================================================
	{//===============================================================================================

		HARDWARE_stop_music();

		//crickets
		sfx_crickets(32);

		if(ACTION_range_xy_xy(27*8,14*8,28*8,16*8,"Turn On TV"))
		{
			if(GLOBAL_text_engine_state==0)
			{
				TEXT_set_sprite_window(0,PLAYER_npc,NULL);
				TEXT_window("I shouldn't make any noise, I'll wake people up.<.>"
							"It would help to <LIGHTGRAY>pass the time a bit more quickly<WHITE> though.");
			}
		}

		if(ACTION_range_xy_xy(51*8,35*8,54*8,37*8,"Play Ping"))
		{
			if(GLOBAL_text_engine_state==0)
			{
				TEXT_set_sprite_window(0,PLAYER_npc,NULL);
				TEXT_window("I don't want to make a lot of noise, it's still early.");
			}
		}

	}


	//===============================================================================================
	if(CLOCK_hour>=6&&CLOCK_hour<7)	//6 am to 7 am===============================================================================================
	{//===============================================================================================



		HARDWARE_play_music("nice",48);

		//birds chirping
		sfx_birds(16);
		//car horns
		sfx_carhorns(16);

		//tv sound
		if(kitchen_tv_on==0)
		{
			if(ACTION_range_xy_xy(27*8,14*8,28*8,16*8,"Turn On TV"))
			{
				kitchen_tv_on=1;
				HARDWARE_play_sound("tv",128,44100,1);
			}
		}
		else
		if(kitchen_tv_on==1)
		{
			if(ACTION_range_xy_xy(27*8,14*8,28*8,16*8,"Turn Off TV"))
			{
				kitchen_tv_on=0;
				HARDWARE_stop_sound("tv");
			}
		}

		//TODO: play ping when dad isn't using it.
		//try to beat his high score?
		//he moves to the mountains and takes it with him?

		//TODO: ping noises when dad is playing it. also in INTRO


		if(CLOCK_minute<30)
		{
			if(dad_npc!=NULL)
			{
				if(ACTION_range_xy_xy(51*8,35*8,54*8,37*8,"Play Ping"))
				{
						TEXT_set_sprite_window(0,PLAYER_npc,NULL);
						TEXT_set_sprite_window(1,dad_npc,NULL);
						TEXT_window("Maybe I'll try this thing.<.>"
									"<1>I see Yuu over there. Don't even think about it.<.>"
									"I've told Yuu before. Don't underestimate <YELLOW>PING<WHITE>, son.<.>"
									"<0>I just wanted to try it out.<.>"
									"<1>Don't make me laugh. \"Try it out.\"<.>"
									"It might look like a simple game to Yuu, but it's more than just a game.<.>"
									"To truly master the art takes decades of dedication. It's a lifelong commitment.<.>"
									"It may be intimidating, but we all have to start somewhere.<.>"
									"First, Yuu is going to need weeks of proper training and guidance, and just maybe Yuu will be ready to pick up the controller.<.>"
									"<0>Uh, I'll think about it.<.>"
									"<1>That's the right attitude. Prepare your mind first.<.>"
						);
				}
			}

		}
		else
		{


			if(ACTION_range_xy_xy(51*8,35*8,54*8,37*8,"Play Ping"))
			{


				if(GLOBAL_text_engine_state==0&&ping_switch==0)
				{
					TEXT_set_sprite_window(0,PLAYER_npc,NULL);
					TEXT_window("<NOCANCEL>How do I even turn this thing on?<.>"
								"Ah. Got it."
					);
					ping_switch=1;
				}
				else
				if(GLOBAL_text_engine_state==0&&PING_got_high_score==1)
				{
					TEXT_set_sprite_window(0,PLAYER_npc,NULL);
					TEXT_window("This game is boring, I don't want to play it anymore.<.>"
								"I already beat it anyway."
					);
				}


			}


		}



		if(CLOCK_minute<30)
		{

			if(dad_npc==NULL)
			{
				NPC_create_npc_xy_feet(&dad_npc,GFX_ADULT_dad, 16, 40, YUUDownstairs_TableLeft);
				dad_npc->non_walkable=1;
				NPC_animate_stand_dir(&dad_npc, RIGHT);


				//coffee and newspaper on table 23,20
			}



			if(mom_npc==NULL)
			{
				NPC_create_npc_xy_feet(&mom_npc,GFX_ADULT_mom, 16, 40, YUUDownstairs_Cupboard);
				mom_npc->non_walkable=1;
			}

			if(CLOCK_hour==6&&CLOCK_minute==0&&dad_flag==0&&mom_flag==0)////////////////////////coming downstairs
			{
				CLOCK_minute++;
				dad_flag=1;
				dad_npc->MAP_x=4*8;
				dad_npc->MAP_y=23*8;
				mom_flag=1;
				mom_npc->MAP_x=4*8;
				mom_npc->MAP_y=24*8;
			}





			if(dad_flag==0&&coffee_npc==NULL)
			{
				NPC_create_npc_xy_feet(&coffee_npc,GFX_MISC_coffeeandnewspaper, 16, 16,	(21*8), (20*8));
				coffee_npc->layer=1;
			}




			if(dad_flag==1)
				if(NPC_walk_to_xy_nohit(&dad_npc, SPEED_SLOWEST, YUUDownstairs_StairsBottom))
					dad_flag=2;//from stairs

			if(dad_flag==2)
				if(NPC_walk_to_xy_nohit(&dad_npc, SPEED_SLOWEST, YUUDownstairs_KitchenBottom))
				{
					dad_flag=3;

				}

			if(dad_flag==3)
				if(NPC_walk_to_xy_nohit(&dad_npc, SPEED_SLOWEST, YUUDownstairs_CoffeeMaker))
				{
					dad_npc->vbls=0;
					dad_flag=4;
				}
			if(dad_flag==4)
				{
					if(dad_npc->vbls>60)
					dad_flag=5;
				}

			if(dad_flag==5)
				if(NPC_walk_to_xy_nohit(&dad_npc, SPEED_SLOWEST, YUUDownstairs_TableLeft))
				{
					dad_flag=6;
					//coffee and newspaper on table 23,20
				}

			if(dad_flag==6)
			{
				NPC_animate_stand_dir(&dad_npc, RIGHT);    //sit at table facing right
				dad_flag=0;
			}





			if(mom_flag==1)
				if(NPC_walk_to_xy_nohit(&mom_npc, SPEED_SLOW, YUUDownstairs_StairsBottom))
					mom_flag=2;//from stairs

			if(mom_flag==2)
				if(NPC_walk_to_xy_nohit(&mom_npc, SPEED_SLOW, YUUDownstairs_KitchenBottom))
					mom_flag=3;

			if(mom_flag==3)
				if(NPC_walk_to_xy_nohit(&mom_npc, SPEED_SLOW, YUUDownstairs_Cupboard))
					mom_flag=0;//walk to kitchen

			if(dad_flag==0)
			if(ACTION_npc(&dad_npc,"Talk To Dad")&&GLOBAL_text_engine_state==0)
			{
				static int talkflag=0;
				if(talkflag==0)
				{
					TEXT_set_sprite_window(0,dad_npc,NULL);
					TEXT_set_sprite_window(1,mom_npc,NULL);
					TEXT_window(
								"Let's see here.. War, mmhmm.. <DELAY30>Collapsing economy, I see.. <.>"
								"*chuckle*<.>"
								"Oh, these politicians and their little squabbles.<.>"
								"Hold on, what's this? Gas<DELAY30> prices<DELAY30>.<DELAY30>.<DELAY30>.<.>*Ahem*<.>"
								"Son, <DELAY30>it has become clear to me <DELAY30>that an era of doom is upon us. <.>"
								"I must now entrust Yuu with a mission of destiny.<.>"
								"The fate of this fragile world rests on your shoulders.<.>"
								"<1>Don't pressure the boy, dear. <DELAY30>Don't worry, sweetie, the world will be fine without Yuu.<.>"
								"<0>Quit pampering the kid, woman! He'll never grow up to be planetary dictator at this rate.<.>"
								"Let me give Yuu some advice, son, <PAUSE>in all my years, I've learned one thing.<.>"
								"This world is nothing but <GRAY>misery<WHITE> and <GRAY>despair<WHITE>. <.>"
								"Life is <GRAY>endless suffering<WHITE>, and each day will always be worse than the last.<.>"
								"<1>....<DELAY30>Dear, just drink your coffee.<.>"
								"<0>*grumble* <DELAY30>*slurp*<.>"
								"Alright, it's not so bad."
								);
					talkflag++;
				}
				else
				if(talkflag==1)
				{
					TEXT_set_sprite_window(0,dad_npc,NULL);
					TEXT_set_sprite_window(1,mom_npc,NULL);
					TEXT_window(
								"<0>This coffee tastes different today.<.>"
								"<1>Well, since we're on such a tight budget I've just been putting the grounds back in the can.<.>"
								"<0>Oh, that makes sense.<.>*slurp*<DELAY30> I think it's better this way."
								);
				}
			}

			if(mom_flag==0)
			if(ACTION_npc(&mom_npc,"Talk To Mom")&&GLOBAL_text_engine_state==0)
			{
				TEXT_set_sprite_window(0,mom_npc,NULL);
				TEXT_set_sprite_window(1,PLAYER_npc,NULL);
				TEXT_window(
							"Goood MOOORNING, sweetie! Well, isn't Yuu just the early bird today?<.>"
							"I'm making some oatmeal, so just hold on a minute! <.>"
							"No respectable mother would allow Yuu to go to school irregular! <.>"
							"<SMALL>hmmmm-hmm-hmmmmmm hm hmmmm...<NORMAL><.>"
							"<1>Uhh...<DELAY30>No thanks, I'm not hungry.<.>"
							"<0><CLEAR><DAD>Listen to your mother. *grumble*"
							);
			}
		}
		//===============================================================================================
		if(CLOCK_minute>=30)
		{//===============================================================================================


		if(CLOCK_minute>30&&CLOCK_minute<45)
		{

			CLOCK_paused=1;

		}


			if(mom_npc==NULL)
			{
				NPC_create_npc_xy_feet(&mom_npc,GFX_ADULT_mom, 16, 40, YUUDownstairs_KitchenSink);
				mom_npc->non_walkable=1;
			}

			if(dad_npc!=NULL)
			{
				if(CLOCK_hour==6&&CLOCK_minute==30&&dad_flag==0)////////////////////////going to work
				{
					CLOCK_minute++;
					dad_flag=1;
					TEXT_set_sprite_window(0,dad_npc,NULL);
					TEXT_set_sprite_window(1,mom_npc,NULL);
					TEXT_window(
								"<NOCANCEL>Alright guys, today's the day. I can feel it! <.>"
								"I'll definitely find work, and we'll be out of our debt hole in no time! <.>"
								"<1>Sure, dear. Aren't you going to shave or shower?<.>"
								"<0>*snort* Any employer with their head on straight knows that appearances are deceiving. <.>"
								"They'll see that I don't waste time with trivial superficial matters. An unshaven worker is an efficient worker! <.>"
								"<1><CLEAR>And a stinky worker?<.>"
								"<0><CLEAR>They'll appreciate my idealistic conservation of water. Just trust me on this one. <.>"
								"Women, huh? <DELAY30>I'm telling Yuu, am I right, or am I right? <DELAY30>*snicker*<.>"
								"<1><YUU>We're in debt? Are they going to take our house?!<.>"
								"<0>Err..<DELAY60> Yuu just shouldn't worry about it, I'm sure it'll work out somehow. <.>"
								"Yuu just doesn't understand the finer nuances of financial management skills.<.>"
								"When Yuu gets to be older, it'll make sense.<.>"
								"<1>........."
								);

					//delete coffee and newspaper if exist
					if(coffee_npc!=NULL)
					{
						NPC_delete_npc(&coffee_npc);
						coffee_npc=NULL;
					}
				}

				if(dad_flag==1)
					if(NPC_walk_to_xy_nohit(&dad_npc, SPEED_SLOW, YUUDownstairs_MiddleOfKitchen))
					{
						if(GLOBAL_text_engine_state==0)
							dad_flag=2;
					}

				if(dad_flag==2)
					if(NPC_walk_to_xy_nohit(&dad_npc, SPEED_SLOWEST, YUUDownstairs_Cupboard))
						dad_flag=3;

				if(dad_flag==3)
					if(NPC_walk_to_xy_nohit(&dad_npc, SPEED_SLOWEST, YUUDownstairs_GarageDoor))
						dad_flag=4;

				if(dad_flag==4)
				{
					NPC_delete_npc(&dad_npc);
					dad_flag=5;
					dad_npc=NULL;
					HARDWARE_play_sound("doorsound",127,44100,0);
					mom_npc->vbls=0;
				}
			}

			if(dad_flag==5)
				if(mom_npc->vbls>120)
					dad_flag++;

			if(dad_flag==6)
			{
				HARDWARE_play_sound("carstart",63,44100,0);
				dad_flag=0;
			}


			static int busy_mom=0;
			if(ACTION_npc(&mom_npc,"Talk To Mom")&&GLOBAL_text_engine_state==0)
			{

				if(PING_got_high_score==1)busy_mom=2;

				if(busy_mom==0)
				{
					TEXT_set_sprite_window(0,mom_npc,NULL);
					TEXT_set_sprite_window(1,PLAYER_npc,NULL);
					TEXT_window(
								"<NOCANCEL><1>Is everything OK? Why do you look so worried?<.>"
								"<0>Everything is fine. Just perfect. I'm not worried at all!<.>"
								"<1>Oh. Alright then.<.>Is my oatmeal ready yet?<.>"
								"<0>Oatmeal? <DELAY30>What oatmeal?<.>No problems.<.>Nothing to worry about.<.>"
								"<SMALL><GRAY>hmmmm-hmm-hmmmmmm hm hmmmm...<NORMAL><WHITE><.>"
								"<1>Hmm...<.>"
								"<0>Perfectly happy. I'm very busy. Keeping busy.<.>"
								"Don't just stand around!<.>They say \"a watched pot never boils.\"<.>"
								"<LIGHTGRAY>Time isn't going to pass<WHITE> if Yuu doesn't stay busy.<.>"
								"There's still a half hour until Yuu can leave for school.<.>"
								"Yuu needs to <RED>find something to pass the time<WHITE>.<.>"
								"Now move it! I've got to stay busy! No problems!"
								);
						busy_mom=1;
				}
				else
				if(busy_mom==1)
				{
					TEXT_set_sprite_window(0,mom_npc,NULL);
					TEXT_set_sprite_window(1,PLAYER_npc,NULL);
					TEXT_window("Don't just stand around!<.>They say \"a watched pot never boils.\"<.>"
								"<LIGHTGRAY>Time isn't going to pass<WHITE> if Yuu doesn't stay busy.<.>"
								"There's still a half hour until Yuu can leave for school.<.>"
								"Yuu needs to <RED>find something to pass the time<WHITE>.<.>"
								"Now move it! I've got to stay busy! No problems!"
								);
				}
				else
				if(busy_mom==2)
				{
					TEXT_set_sprite_window(0,mom_npc,NULL);
					TEXT_set_sprite_window(1,PLAYER_npc,NULL);
					TEXT_window("Did Yuu get ready for school yet?<.>"
								"<1>Yep!<.>"
								"<0>Good. I'm almost done packing Yuu a lunch. Just a couple more minutes!<.>"
								);
				}

			}
		}

		if(mom_flag==0)//////////////////////////normal cooking cycle
		{
			static int mom_downstairs_cycle=0;

			if(mom_downstairs_cycle==0)
				if(NPC_walk_to_xy_nohit(&mom_npc, SPEED_SLOWER, YUUDownstairs_KitchenSink))//sink
				{
					NPC_animate_stand_dir(&mom_npc, UP);
					mom_downstairs_cycle=1;
					mom_npc->vbls=0;
					//sink sound
					HARDWARE_play_sound("sink",64,44100,0);
				}

			if(mom_downstairs_cycle==1)
				if(mom_npc->vbls>180)
					mom_downstairs_cycle=2;

			if(mom_downstairs_cycle==2)
				if(NPC_walk_to_xy_nohit(&mom_npc, SPEED_SLOWER, YUUDownstairs_Cupboard))//cupboard
				{
					NPC_animate_stand_dir(&mom_npc, UP);
					mom_downstairs_cycle=3;
					mom_npc->vbls=0;
					//cupboard sound
					HARDWARE_play_sound("drawer",64,44100,0);
				}

			if(mom_downstairs_cycle==3)
				if(mom_npc->vbls>120)
					mom_downstairs_cycle=4;

			if(mom_downstairs_cycle==4)
				if(NPC_walk_to_xy_nohit(&mom_npc, SPEED_SLOWER, YUUDownstairs_Microwave))//microwave
				{
					NPC_animate_stand_dir(&mom_npc, UP);
					mom_downstairs_cycle=5;
					mom_npc->vbls=0;
					//microwave beep
					HARDWARE_play_sound("microwavebeep",64,44100,0);
				}

			if(mom_downstairs_cycle==5)
				if(mom_npc->vbls>180)
					mom_downstairs_cycle=6;

			if(mom_downstairs_cycle==6)
				if(NPC_walk_to_xy_nohit(&mom_npc, SPEED_SLOWER, YUUDownstairs_Stove))//stove
				{
					mom_downstairs_cycle=7;
					mom_npc->vbls=0;
					//stove clank
					HARDWARE_play_sound("pan",64,44100,0);
				}

			if(mom_downstairs_cycle==7)
				if(mom_npc->vbls>60)
					mom_downstairs_cycle=8;

			if(mom_downstairs_cycle==8)
				if(NPC_walk_to_xy_nohit(&mom_npc, SPEED_SLOWER, YUUDownstairs_Fridge))//fridge
				{
					NPC_animate_stand_dir(&mom_npc, LEFT);
					mom_downstairs_cycle=9;
					mom_npc->vbls=0;
				}

			if(mom_downstairs_cycle==9)
				if(mom_npc->vbls>180)
				{
					//fridge clank
					HARDWARE_play_sound("cabinet",64,44100,0);
					mom_downstairs_cycle=0;
				}
		}



	}
	//===============================================================================================
	if(CLOCK_hour>=7&&CLOCK_hour<12+2)	//7 am to 2 pm/===============================================================================================
	{//===============================================================================================
		//TODO: 10 am brother comes downstairs, goes into garage


		if(kitchen_tv_on==0)
		{
			if(ACTION_range_xy_xy(27*8,14*8,28*8,16*8,"Turn On TV"))
			{
				kitchen_tv_on=1;
				HARDWARE_play_sound("tv",128,44100,1);
			}
		}
		else
		if(kitchen_tv_on==1)
		{
			if(ACTION_range_xy_xy(27*8,14*8,28*8,16*8,"Turn Off TV"))
			{
				kitchen_tv_on=0;
				HARDWARE_stop_sound("tv");
			}
		}

		//birds chirping
		sfx_birds(16);
		sfx_carhorns(16);

		if(mom_npc==NULL)
		{
			NPC_create_npc_xy_feet(&mom_npc,GFX_ADULT_mom, 16, 40, YUUDownstairs_KitchenSink);
			mom_npc->non_walkable=1;
		}

		if(CLOCK_hour==7&&CLOCK_minute==0&&mom_flag==0)////////////////////////mom walk to table
		{
			CLOCK_minute++;
			mom_flag=1;
		}

		if(mom_flag==1)
			if(NPC_walk_to_xy_nohit(&mom_npc, SPEED_SLOWEST, YUUDownstairs_TableTopLeft))
				mom_flag=2;

		if(mom_flag==2)
		{
			TEXT_set_sprite_window(0,mom_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(
						"<NOCANCEL>Okay honey, get going to school. I made Yuu a lunch, it's on the table.<.>"
						//"<1>What about the oatmeal?<.>"
						//"<0>What oatmeal?<.>"
						//"hmmm hmm hm hmmmm, hmm hm hmmmm...<DELAY30><.>"
						//"<1>......."
						);

			mom_flag=3;
		}

		if(mom_flag==3&&GLOBAL_text_engine_state==0)
			if(NPC_walk_to_xy_nohit(&mom_npc, SPEED_SLOWEST, 41*8, 16*8))//mom walk to couch
				mom_flag++;

		if(mom_flag==4)
			if(NPC_walk_to_xy_nohit(&mom_npc, SPEED_SLOWEST, 41*8, 28*8))
				mom_flag++;

		if(mom_flag==5)
			if(NPC_walk_to_xy_nohit(&mom_npc, SPEED_SLOWEST, 38*8, 34*8))
				mom_flag++;

		if(mom_flag==6)
			if(NPC_walk_to_xy_nohit(&mom_npc, SPEED_SLOWEST, 43*8, 34*8))
				mom_flag++;

		if(mom_flag==7)
			if(NPC_walk_to_xy_nohit(&mom_npc, SPEED_SLOWEST, YUUDownstairs_Couch))
			{
				NPC_animate_stand_dir(&mom_npc, DOWN);
				mom_flag=8;
			}


		if(lunchnpc==NULL&&mom_flag>2&&havelunch==0)
		{
			NPC_create_npc_xy_feet(&lunchnpc,GFX_MISC_lunchbag, 16, 16,	21*8, (19*8));
			lunchnpc->layer=1;
		}

		if(havelunch==0)
			if(ACTION_range_xy_xy(19*8,19*8,21*8,21*8,"Take Lunch"))
			{
				NPC_delete_npc(&lunchnpc);
				lunchnpc=NULL;
				havelunch=1;
				ITEM_get(&LunchBag);
			}

		//TODO: tv flickering light
		//TODO: overprotective mothers talkshow sound

		if(ACTION_npc(&mom_npc,"Talk To Mom")&&GLOBAL_text_engine_state==0)
		{
			TEXT_set_sprite_window(0,mom_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window("Shh!<DELAY30> The <PINK>Overprotective Mothers Daytime Talk Show<WHITE> is starting! <.>"
			"Get to school! Shoo! Off Yuu goes!");
		}


		if(((CLOCK_hour==7&&CLOCK_minute>=15)||CLOCK_hour>7))//========kicked out at 7:15
		{
			static int yelledat=0;

			if(yelledat==0)
			{
				TEXT_set_sprite_window(0,mom_npc,NULL);
				TEXT_set_sprite_window(1,PLAYER_npc,NULL);

				if(havelunch==0)
				TEXT_window("<NOCANCEL>What does Yuu think he's doing, young man?! Get to school! Yuu will be late!<.>"
							"<1>I don't have my lunch!<.>"
							"<0>Well, maybe Yuu should have listened to his mother!<.>"
							"GET TO SCHOOL! <DELAY30><HUGE> NOW!!!<NORMAL><SHAKE1SEC><.>"
							"<1>Alright, alright.<.>I'd better hurry."
							);
				else
				TEXT_window("<NOCANCEL>What does Yuu think he's doing, young man?! Get to school! Yuu will be late!<.>"
							"GET TO SCHOOL! <DELAY30><HUGE> NOW!!!<NORMAL><SHAKE1SEC><.>"
							"<1>Alright, alright.<.>I'd better hurry."
							);

				yelledat=1;
			}
			else
			if(yelledat==1)
			{

				//TODO: no lunch, no energy unless yuu can buy it at school.

				cameraman_target=PLAYER_npc;

				if(GLOBAL_text_engine_state==0)
				{
					yelledat=0;

					HARDWARE_play_sound("doorsound",127,44100,0);

					//MAP_change_map(MAP_bobsgame_TOWNTown,525,461);return;



						load_bob_scene_2();

						return;

				}
			}
		}
	}


static int talked_to_brother=0;

	//===============================================================================================
	if(CLOCK_hour>=12+2&&CLOCK_hour<12+4)	//2 pm to 4 pm===============================================================================================
	{//===============================================================================================

		//mom upstairs sleeping
		//brother is in the kitchen

		sfx_carhorns(16);
		HARDWARE_play_music("nice",48);

		if(kitchen_tv_on==0)
		{
			if(ACTION_range_xy_xy(27*8,14*8,28*8,16*8,"Turn On TV"))
			{
				kitchen_tv_on=1;
				HARDWARE_play_sound("tv",128,44100,1);
			}
		}
		else
		if(kitchen_tv_on==1)
		{
			if(ACTION_range_xy_xy(27*8,14*8,28*8,16*8,"Turn Off TV"))
			{
				kitchen_tv_on=0;
				HARDWARE_stop_sound("tv");
			}
		}


			if(ACTION_range_xy_xy(51*8,35*8,54*8,37*8,"Play Ping"))
			{


				if(GLOBAL_text_engine_state==0&&ping_switch==0)
				{
					TEXT_set_sprite_window(0,PLAYER_npc,NULL);
					TEXT_window("<NOCANCEL>How do I even turn this thing on?<.>"
								"Ah. Got it."
					);
					ping_switch=1;
				}
				else
				if(GLOBAL_text_engine_state==0&&PING_got_high_score==1)
				{
					TEXT_set_sprite_window(0,PLAYER_npc,NULL);
					TEXT_window("This game is boring, I don't want to play it anymore.<.>"
								"I already beat it anyway."
					);
				}


			}


		//===============================================================================================
		if(CLOCK_hour==12+3&&CLOCK_minute==0&&brother_flag==0)// if 3:00 brother comes in the garage
		{//===============================================================================================
			if(brother_npc==NULL)
			{
				NPC_create_npc_xy_feet(&brother_npc,GFX_KID_brother, 16, 32, YUUDownstairs_GarageDoor);
				brother_npc->non_walkable=1;
				HARDWARE_play_sound("doorsound",127,44100,0);
				brother_flag=1;
				CLOCK_minute++;
			}
		}
		//===============================================================================================
		if((CLOCK_hour==12+3&&CLOCK_minute<55))
		{//===============================================================================================
			if(brother_npc==NULL)
			{
				NPC_create_npc_xy_feet(&brother_npc,GFX_KID_brother, 16, 32, YUUDownstairs_KitchenSink);
				brother_npc->non_walkable=1;
			}

			if(brother_flag==1)
				if(GLOBAL_text_engine_state==0)
					brother_flag++;

			if(brother_flag==2)
				if(NPC_walk_to_xy_nohit(&brother_npc, SPEED_SLOWEST, YUUDownstairs_KitchenSink))
					brother_flag++;

			if(brother_flag==3)
			{
				NPC_animate_stand_dir(&brother_npc, DOWN);
				brother_flag=0;
			}

			if(ACTION_npc(&brother_npc,"Talk To Brother")&&GLOBAL_text_engine_state==0)
			{
				if(talked_to_brother==0)
				{
					TEXT_set_sprite_window(0,brother_npc,NULL);
					TEXT_set_sprite_window(1,PLAYER_npc,NULL);
					TEXT_window(
								"<NOCANCEL>What's up, twerp? How was kiddie school?<DELAY30> *snicker*<.>"
								"<1>Oh, pretty good. What's funny?<.>"
								"<0>What?<DELAY30>...<.>"
								"Oh yeah, did Yuu get a good night's rest? Wake up nice and early?<.>"
								"<1>Hey! Did you set my alarm?<.>"
								"<0>Heh heh heh.<.>"
								"Listen up, loser. I don't have time to play with dorks like Yuu.<.>"
								"I've got a hot date tonight, and I don't need to catch your geek virus.<.>"
								"<1>I have a virus?<PAUSE> Am I sick? Should I go to the doctor?<.>"
								"<0>Ugh. That's exactly what I mean.<.>"
								"Get out of my face, idiot.<.>"
								"<1>....."
								);
								talked_to_brother=1;
				}
				else
				{

					TEXT_set_sprite_window(0,brother_npc,NULL);
					TEXT_set_sprite_window(1,PLAYER_npc,NULL);
					TEXT_window(
								"Get OUT OF MY FACE!<SHAKE1SEC>"
								);

				}
			}
		}

		if(brother_npc!=NULL)
		{	//===============================================================================================
			if(CLOCK_hour==12+3&&CLOCK_minute==55&&brother_flag==0)////////////////////////going to date
			{//===============================================================================================
				CLOCK_minute++;
				brother_flag=1;
				TEXT_set_sprite_window(0,brother_npc,NULL);
				TEXT_set_sprite_window(1,PLAYER_npc,NULL);
				TEXT_window(
							"<NOCANCEL>Alright, I'm outta here. Yuu had better not rat me out, Yuu hears?"
							);
			}

			if(brother_flag==1)
				if(GLOBAL_text_engine_state==0)
					brother_flag=2;

			if(brother_flag==2)
				if(NPC_walk_to_xy_nohit(&brother_npc, SPEED_SLOWEST, YUUDownstairs_Cupboard))
					brother_flag=3;

			if(brother_flag==3)
				if(NPC_walk_to_xy_nohit(&brother_npc, SPEED_SLOWEST, YUUDownstairs_GarageDoor))
					brother_flag=4;

			if(brother_flag==4)
			{
				NPC_delete_npc(&brother_npc);
				brother_npc=NULL;
				HARDWARE_play_sound("doorsound",127,44100,0);
				brother_flag=5;
				PLAYER_npc->vbls=0;
			}
		}

		if(brother_flag==5)
		{
			if(PLAYER_npc->vbls>120)
			{
				HARDWARE_play_sound("carstart",63,44100,0);
				brother_flag=0;
			}
		}
	}


	//===============================================================================================
	if((CLOCK_hour>=12+4&&CLOCK_hour<12+6))	//4 pm to 6 pm===============================================================================================
	{//===============================================================================================

		if(CLOCK_hour!=12+5||CLOCK_minute<45)
		CLOCK_paused=1;


		sfx_carhorns(16);
		HARDWARE_play_music("nice",48);

		if(kitchen_tv_on==0)
		{
			if(ACTION_range_xy_xy(27*8,14*8,28*8,16*8,"Turn On TV"))
			{
				kitchen_tv_on=1;
				HARDWARE_play_sound("tv",128,44100,1);
			}
		}
		else
		if(kitchen_tv_on==1)
		{
			if(ACTION_range_xy_xy(27*8,14*8,28*8,16*8,"Turn Off TV"))
			{
				kitchen_tv_on=0;
				HARDWARE_stop_sound("tv");
			}
		}


			if(ACTION_range_xy_xy(51*8,35*8,54*8,37*8,"Play Ping"))
			{


				if(GLOBAL_text_engine_state==0&&ping_switch==0)
				{
					TEXT_set_sprite_window(0,PLAYER_npc,NULL);
					TEXT_window("<NOCANCEL>How do I even turn this thing on?<.>"
								"Ah. Got it."
					);
					ping_switch=1;
				}
				else
				if(GLOBAL_text_engine_state==0&&PING_got_high_score==1)
				{
					TEXT_set_sprite_window(0,PLAYER_npc,NULL);
					TEXT_window("This game is boring, I don't want to play it anymore.<.>"
								"I already beat it anyway."
					);
				}


			}



		//mom cooking dinner in the kitchen
		if(mom_npc==NULL)
		{
			NPC_create_npc_xy_feet(&mom_npc,GFX_ADULT_mom, 16, 40, YUUDownstairs_KitchenSink);
			mom_npc->non_walkable=1;
		}

		//===============================================================================================
		if(CLOCK_hour==12+4&&CLOCK_minute==0&&mom_flag==0)////////////////////////coming downstairs
		{//===============================================================================================
			CLOCK_minute++;
			mom_flag=1;
			mom_npc->MAP_x=4*8;
			mom_npc->MAP_y=24*8;
		}


		if(mom_flag==1)
			if(NPC_walk_to_xy_nohit(&mom_npc, SPEED_SLOW, YUUDownstairs_StairsBottom))
				mom_flag=2;//from stairs

		if(mom_flag==2)
			if(NPC_walk_to_xy_nohit(&mom_npc, SPEED_SLOW, YUUDownstairs_KitchenBottom))
				mom_flag=3;

		if(mom_flag==3)
			if(NPC_walk_to_xy_nohit(&mom_npc, SPEED_SLOW, YUUDownstairs_Cupboard))
				mom_flag=0;//walk to kitchen

		//dinner on stove
		if(dinnernpc==NULL)
		{
			NPC_create_npc_xy_feet(&dinnernpc,GFX_MISC_dinner, 16, 16,	(11*8), (16*8));
			dinnernpc->layer=1;
		}


		if(ACTION_npc(&mom_npc,"Talk To Mom")&&GLOBAL_text_engine_state==0)
		{
			if(CLOCK_hour!=12+5||CLOCK_minute<45)
			{
				static int c=0;

				if(c==0)
				{
					TEXT_set_sprite_window(0,mom_npc,NULL);
					TEXT_set_sprite_window(1,PLAYER_npc,NULL);
					TEXT_window(
								"<NOCANCEL>Excuse me! I'm busy making dinner.<.>"
								"We're having squid lasagna with banana sauce tonight, it's my very own recipe!<.>"
								"<1>Oh.. Sounds, uh, <DELAY30>different...<.>"
								"<0>Of course it does! Your mother certainly has a sense of gourmet taste, doesn't Yuu think?<.>"
								"<1><SMALL><GRAY>(Is she doing this on purpose?)<NORMAL><WHITE><.>"
								"<0>Listen, sweetie. Dinner won't be ready for another two hours.<.>"
								"Yuu needs to <RED>find something to do to pass the time<WHITE>.<.>"
								"If Yuu is going to just stand there, help me chop these sheep stomachs.<.>"
								"<1>Sheep..<DELAY30> Stomachs?<.>"
								"<0>Ohohohoho! Just a little joke. They're actually from pigs.<.>"
								"<1>Oh, ok then.<DELAY30> What?<.>"
								);
					c++;
				}
				else
				{
					TEXT_set_sprite_window(0,mom_npc,NULL);
					TEXT_set_sprite_window(1,PLAYER_npc,NULL);
					TEXT_window(
								"Hey, champ! Did Yuu find something to do yet?<.>"
								"<1>Not yet.<.>"
								"<0>Well, if Yuu is bored, Yuu can help scrape the suckers off of the squid.<.>"
								"<1>Um, I'm alright. I'll find something.<.>"
								"<0>Yuu is a growing young man! Yuu needs to explore. Go on an adventure!<.>"
								"<1>Can I go outside?<.>"
								"<0>Not until after dinner. A growing young man needs his energy!<.>"
								"I'm sure Yuu can find a new place to check out."
								);
				}
			}
			else
			{
				TEXT_set_sprite_window(0,mom_npc,NULL);
				TEXT_set_sprite_window(1,PLAYER_npc,NULL);
				TEXT_window(
							"Dinner's almost ready! I hope Yuu worked up an appetite!<.>"
							"<1>That really looks tasty, but..<DELAY30> uh..<DELAY30> I'm actually still full from lunch.<.>"
							"<0>Oh, don't Yuu be silly. I packed Yuu a light lunch just for the occasion!<.>"
							"<1>Ah. Thanks."
							);
			}

		}

		if(mom_flag==0)//////////////////////////normal cooking cycle
		{
			static int mom_downstairs_cycle=0;

			if(mom_downstairs_cycle==0)
				if(NPC_walk_to_xy_nohit(&mom_npc, SPEED_SLOWER, YUUDownstairs_KitchenSink))//sink
				{
					NPC_animate_stand_dir(&mom_npc, UP);
					mom_downstairs_cycle=1;
					mom_npc->vbls=0;
					//sink sound
					HARDWARE_play_sound("sink",64,44100,0);
				}

			if(mom_downstairs_cycle==1)
				if(mom_npc->vbls>180)
					mom_downstairs_cycle=2;

			if(mom_downstairs_cycle==2)
				if(NPC_walk_to_xy_nohit(&mom_npc, SPEED_SLOWER, YUUDownstairs_Cupboard))//cupboard
				{
					NPC_animate_stand_dir(&mom_npc, UP);
					mom_downstairs_cycle=3;
					mom_npc->vbls=0;
					//cupboard sound
					HARDWARE_play_sound("drawer",64,44100,0);
				}

			if(mom_downstairs_cycle==3)
				if(mom_npc->vbls>120)
					mom_downstairs_cycle=4;

			if(mom_downstairs_cycle==4)
				if(NPC_walk_to_xy_nohit(&mom_npc, SPEED_SLOWER, YUUDownstairs_Microwave))//microwave
				{
					NPC_animate_stand_dir(&mom_npc, UP);
					mom_downstairs_cycle=5;
					mom_npc->vbls=0;
					//microwave beep
					HARDWARE_play_sound("microwavebeep",64,44100,0);
				}

			if(mom_downstairs_cycle==5)
				if(mom_npc->vbls>180)
					mom_downstairs_cycle=6;

			if(mom_downstairs_cycle==6)
				if(NPC_walk_to_xy_nohit(&mom_npc, SPEED_SLOWER, YUUDownstairs_Stove))//stove
				{
					mom_downstairs_cycle=7;
					mom_npc->vbls=0;
					//stove clank
					HARDWARE_play_sound("pan",64,44100,0);
				}

			if(mom_downstairs_cycle==7)
				if(mom_npc->vbls>60)
					mom_downstairs_cycle=8;

			if(mom_downstairs_cycle==8)
				if(NPC_walk_to_xy_nohit(&mom_npc, SPEED_SLOWER, YUUDownstairs_Fridge))//fridge
				{
					NPC_animate_stand_dir(&mom_npc, LEFT);
					mom_downstairs_cycle=9;
					mom_npc->vbls=0;
				}

			if(mom_downstairs_cycle==9)
				if(mom_npc->vbls>180)
				{
					//fridge clank
					HARDWARE_play_sound("cabinet",64,44100,0);
					mom_downstairs_cycle=0;
				}
		}

	}


	//===============================================================================================
	if(CLOCK_hour>=12+6&&CLOCK_hour<12+8)	//6 pm to 8 pm===============================================================================================
	{//===============================================================================================


		if(kitchen_tv_on==0)
		{
			if(ACTION_range_xy_xy(27*8,14*8,28*8,16*8,"Turn On TV"))
			{
				kitchen_tv_on=1;
				HARDWARE_play_sound("tv",128,44100,1);
			}
		}
		else
		if(kitchen_tv_on==1)
		{
			if(ACTION_range_xy_xy(27*8,14*8,28*8,16*8,"Turn Off TV"))
			{
				kitchen_tv_on=0;
				HARDWARE_stop_sound("tv");
			}
		}


		//TODO: clock ticking

		//really faded car horns
		sfx_carhorns(8);


		//dad comes home
		//dinnertime
		if(mom_flag==5||(dad_flag==5&&CLOCK_hour>=12+6))
		{
			//dinner on table, plates
			if(dinnernpc==NULL)
			{
				NPC_create_npc(&dinnernpc,GFX_MISC_dinner, 16, 16,	24*8, (18*8));
				dinnernpc->layer=1;
			}

			if(dinnernpc!=NULL)
			{
				dinnernpc->MAP_x=24*8;
				dinnernpc->MAP_y=18*8;
			}

			if(plate1==NULL)
			{
				NPC_create_npc(&plate1,GFX_MISC_plate, 16, 16,	20*8, (19*8));
				plate1->layer=1;
			}

			if(plate2==NULL)
			{
				NPC_create_npc(&plate2,GFX_MISC_plate, 16, 16,	28*8, (18*8));
				plate2->layer=1;
			}

			if(plate3==NULL)
			{
				NPC_create_npc(&plate3,GFX_MISC_plate, 16, 16,	22*8, (18*8));
				plate3->layer=1;
			}

			if(plate4==NULL)
			{
				NPC_create_npc(&plate4,GFX_MISC_plate, 16, 16,	26*8, (18*8));
				plate4->layer=1;
			}
		}


		//===============================================================================================
		if(CLOCK_hour==12+6&&CLOCK_minute<30)
		{//===============================================================================================
			if(CLOCK_hour==12+6&&CLOCK_minute==0&&mom_flag==0&&dad_flag==0)////////////////////////dad comes home
			{
				if(dad_npc==NULL)
				{
					NPC_create_npc_xy_feet(&dad_npc,GFX_ADULT_dad, 16, 40, YUUDownstairs_GarageDoor);
					dad_npc->non_walkable=1;
					NPC_animate_stand_dir(&dad_npc, RIGHT);
					dad_flag=0;
				}

				CLOCK_minute++;

				mom_flag=1;
				dad_flag=1;
				TEXT_set_sprite_window(0,dad_npc,NULL);
				TEXT_set_sprite_window(1,mom_npc,NULL);
				TEXT_window(
							"<NOCANCEL>I'm home!<.>"
							"Boy that smells, uh,<DELAY30> interesting.<.>"
							"<1>Welcome home, dear. I'll go ahead and set the table. How did today go?<.>"
							"<0>Oh, good, good. Hey, I'm starving, let's eat first! We'll save the chitchat for later.<.>"
							"Have a seat, Yuu."
							);



				HARDWARE_play_sound("doorsound",127,44100,0);
			}

			//TODO: car comes in garage, can hear throughout whole house
			//TODO: mom screams upstairs? TIME TO EAT GET DOWN HERE
			if(dad_npc==NULL)
			{
				NPC_create_npc_xy_feet(&dad_npc,GFX_ADULT_dad, 16, 40, YUUDownstairs_TableLeft);
				dad_npc->non_walkable=1;
				NPC_animate_stand_dir(&dad_npc, RIGHT);
				dad_flag=0;
			}

			if(mom_npc==NULL)
			{
				NPC_create_npc_xy_feet(&mom_npc,GFX_ADULT_mom, 16, 40, YUUDownstairs_TableRight);
				mom_npc->non_walkable=1;
				NPC_animate_stand_dir(&mom_npc, LEFT);
				mom_flag=0;
			}

			if(dad_flag==1)
				if(NPC_walk_to_xy_nohit(&dad_npc, SPEED_SLOWEST, 4*8, 11*8))
					dad_flag++;//from garage

			if(dad_flag==2)
				if(NPC_walk_to_xy_nohit(&dad_npc, SPEED_SLOWEST, YUUDownstairs_Cupboard))
					dad_flag++;

			if(dad_flag==3)
				if(NPC_walk_to_xy_nohit(&dad_npc, SPEED_SLOWEST, YUUDownstairs_TableLeft))
					dad_flag++;

			if(dad_flag==4)
			{
				NPC_animate_stand_dir(&dad_npc, RIGHT);    //sit at table facing right
				dad_flag=5;
			}

			if(mom_flag==1)
				if(NPC_walk_to_xy_nohit(&mom_npc, SPEED_SLOW, YUUDownstairs_Stove))
					mom_flag++;//from kitchen stove

			if(mom_flag==2)
				if(NPC_walk_to_xy_nohit(&mom_npc, SPEED_SLOW, 31*8, 17*8)) //above table right chair
					mom_flag++;

			if(mom_flag==3)
				if(NPC_walk_to_xy_nohit(&mom_npc, SPEED_SLOW, YUUDownstairs_TableRight))
					mom_flag++;//walk to kitchen table right face left

			if(mom_flag==4)
			{
				NPC_animate_stand_dir(&mom_npc, LEFT);    //sit at table facing left
				mom_flag=5;
			}

			if(ACTION_npc(&dad_npc,"Talk To Dad")&&GLOBAL_text_engine_state==0)
			{
				TEXT_set_sprite_window(0,dad_npc,NULL);
				TEXT_set_sprite_window(1,mom_npc,NULL);
				TEXT_window("Have a seat, kiddo. Yuu shouldn't make his mother wait.");
			}

			if(ACTION_npc(&mom_npc,"Talk To Mom")&&GLOBAL_text_engine_state==0)
			{
				TEXT_set_sprite_window(0,mom_npc,NULL);
				TEXT_set_sprite_window(1,PLAYER_npc,NULL);
				TEXT_window("What is Yuu waiting for? Have a seat and enjoy my delicious creation!");
			}

			//TODO: if try to leave, say "get back here and eat dinner with your family.
		}



		static int sitting_down=0;

		//===============================================================================================
		if((CLOCK_hour==12+6&&CLOCK_minute<30)&&dad_flag==0&&sitting_down==0)
		{//===============================================================================================
			TEXT_set_sprite_window(0,dad_npc,NULL);
			TEXT_set_sprite_window(1,mom_npc,NULL);
			TEXT_window(
						"<NOCANCEL>There Yuu is. It's time to eat, Yuu knows. Your mother's been calling.<.>"
						"<1>Sit down so we can start!"
						);


			dad_flag=5;
		}
		//===============================================================================================
		if((CLOCK_hour>12+6||CLOCK_minute==30)&&sitting_down==0&&dad_flag!=1)
		{//===============================================================================================
			CLOCK_minute++;
			dad_flag=0;
		}
		//===============================================================================================
		if((CLOCK_hour>12+6||(CLOCK_hour==12+6&&CLOCK_minute>30))&&sitting_down==0)////////////////////////force you to sit down
		{//===============================================================================================
			if(dad_npc==NULL)
			{
				NPC_create_npc_xy_feet(&dad_npc,GFX_ADULT_dad, 16, 40, YUUDownstairs_TableLeft);
				dad_npc->non_walkable=1;
				NPC_animate_stand_dir(&dad_npc, RIGHT);
				dad_flag=0;
			}

			if(mom_npc==NULL)
			{
				NPC_create_npc_xy_feet(&mom_npc,GFX_ADULT_mom, 16, 40, YUUDownstairs_TableRight);
				mom_npc->non_walkable=1;
				NPC_animate_stand_dir(&mom_npc, LEFT);
				mom_flag=0;
			}

			if(dad_flag==0)
			{
				TEXT_set_sprite_window(0,dad_npc,NULL);
				TEXT_set_sprite_window(1,PLAYER_npc,NULL);
				TEXT_window("<NOCANCEL><HUGE>Sit down already!!<SHAKE1SEC><.><1><NORMAL>Got it! <.><SMALL>(Yikes!)");
				dad_flag++;
			}

			if(dad_flag==1)
				if(GLOBAL_text_engine_state==0)
					dad_flag=6;	//warping is fine, npc chase is too unreliable right now
		}

		if((dad_flag==6)||ACTION_range_xy_xy(22*8,19*8,24*8,20*8,"Sit Down"))
		{

			HARDWARE_stop_music();
			HARDWARE_play_music("dinnertime",64);

			//slowly rising tense music
			//clock ticking louder and louder


			sitting_down=1;
			GLOBAL_main_sprite_input_off=1;
			GLOBAL_main_sprite_standing=1;
			PLAYER_npc->MAP_x=22*8;
			PLAYER_npc->MAP_y=(16*8)-4;
			PLAYER_npc->walk_dir=DOWN;
			NPC_animate_stand_dir(&PLAYER_npc, DOWN);
			dad_flag=0;
			mom_flag=0;


			if(kitchen_tv_on==1)
			{
				kitchen_tv_on=0;
				HARDWARE_stop_sound("tv");
			}

			//put chair tiles behind yuu
			HARDWARE_map_2[HARDWARE_map_width_tiles*16+22] = HARDWARE_map_1[HARDWARE_map_width_tiles*16+22];
			HARDWARE_map_2[HARDWARE_map_width_tiles*16+23] = HARDWARE_map_1[HARDWARE_map_width_tiles*16+23];
			HARDWARE_map_2[HARDWARE_map_width_tiles*17+22] = HARDWARE_map_1[HARDWARE_map_width_tiles*17+22];
			HARDWARE_map_2[HARDWARE_map_width_tiles*17+23] = HARDWARE_map_1[HARDWARE_map_width_tiles*17+23];
			HARDWARE_map_1[HARDWARE_map_width_tiles*16+22] = 0;
			HARDWARE_map_1[HARDWARE_map_width_tiles*16+23] = 0;
			HARDWARE_map_1[HARDWARE_map_width_tiles*17+22] = 0;
			HARDWARE_map_1[HARDWARE_map_width_tiles*17+23] = 0;

			//remove kitchen wall
			int tx=0;
			int ty=0;
			for(ty=0;ty<3;ty++)
			for(tx=0;tx<12;tx++)
			{
				HARDWARE_map_1[HARDWARE_map_width_tiles*(20+ty)+(23+tx)] = 0;
				//missing shadow.. can fix this in the actual map.
				//edit: fixed.
				//HARDWARE_map_0[HARDWARE_map_width_tiles*(20+ty)+(23+tx)] = HARDWARE_map_0[HARDWARE_map_width_tiles*(22)+(22)];
			}

			//turn off metatiles so we can use the modified map
			metatile_map=0;
			delete_all_metatiles();

			//load the modified map
            HARDWARE_load_map(3,HARDWARE_map_3,HARDWARE_map_width_tiles*8,HARDWARE_map_height_tiles*8);
            HARDWARE_load_map(2,HARDWARE_map_2,HARDWARE_map_width_tiles*8,HARDWARE_map_height_tiles*8);
            HARDWARE_load_map(1,HARDWARE_map_1,HARDWARE_map_width_tiles*8,HARDWARE_map_height_tiles*8);
            HARDWARE_load_map(0,HARDWARE_map_0,HARDWARE_map_width_tiles*8,HARDWARE_map_height_tiles*8);


			/*HARDWARE_set_map_tile(1,2,22,16,HARDWARE_map_1[HARDWARE_map_width_tiles*16+22]);	//sitting in front of left chair
			HARDWARE_set_map_tile(1,2,23,16,HARDWARE_map_1[HARDWARE_map_width_tiles*16+23]);
			HARDWARE_set_map_tile(1,2,22,17,HARDWARE_map_1[HARDWARE_map_width_tiles*17+22]);
			HARDWARE_set_map_tile(1,2,23,17,HARDWARE_map_1[HARDWARE_map_width_tiles*17+23]);
			HARDWARE_set_map_tile(1,1,22,16,0);
			HARDWARE_set_map_tile(1,1,23,16,0);
			HARDWARE_set_map_tile(1,1,22,17,0);
			HARDWARE_set_map_tile(1,1,23,17,0);*/


			mom_npc->vbls=0;
			LETTERBOX_init(64,1);
			CAPTION_make_caption(NULL, 1, CAPTION_CENTERED_X, 40, 3, "Dinnertime", FONT_HUGE_ID, RED, CLEAR,1,1);

			//TODO: zoom in, 3x.


			//trapped upstairs

			//TODO: need to figure out a way to play MES
			//brothers room was locked before, so now you need to break in somehow.
			//find a coat hanger in your parents closet?
			//get the TISSUES AND LOTION (what did you think they were for?) to clean the cartridge.
			//warranty is voided now but it beats blowing on it
			//freeze the clock "i need to do something to pass the time." then jump to time allowed to go downstairs

			//also need to do the "i need to do somethign to pass the time" thing for the morning

			//also wake up to alarm clock after naked in school scene

			//dad apologizes, goes back to playing ping
			//sees your high score from this morning





		}

		if(sitting_down)
		{
			static int dinner_cycle=0;

			if(dinner_cycle==0)
				if(mom_npc->vbls>180)
					dinner_cycle++;

			if(dinner_cycle==1)
			{
				TEXT_set_sprite_window(0,dad_npc,NULL);
				TEXT_set_sprite_window(1,mom_npc,NULL);
				TEXT_window(
							"<NOCANCEL>Let's see what we have here.<.>"
							"Oh, squid lasagna! Looks, uh,<DELAY30> delicious!<.>"
							"And is this, um, mustard?<.>"
							"<1>Banana sauce.<.>"
							"<0>Ohh, right. Another hit by my famous gourmet chef!<.>"
							"<1>So you didn't find a job today, I take it?<.>"
							"<0>Erm..<DELAY30> I got some hot leads, don't worry a bit, hon.<.>"
							"In fact, the heads of IBW were so impressed, they assigned me some personal bodyguards to protect me on the way out.<.>"
							"You know how these big corporate meetings are, there's always so much paperwork and, um, forms to fill out. <.>"
							"Lots of pink tape or whatever. <.>"
							"Hoops to jump through, you know.<.>"
							"Don't worry about it, I'm sure I'll get a call back once they check out my resume, maybe even tonight!<.>"
							"<1>Oh, I see. I'm sure you tried your best.<.>"
							"Well, enjoy your meal!<.>"
							"<0><YUU><SMALL><GRAY>(Hmm..)<NORMAL><WHITE>"
							);
				mom_npc->vbls=0;
				dinner_cycle++;
			}

			if(dinner_cycle==2)
			{
				if(GLOBAL_text_engine_state!=0)
					mom_npc->vbls=0;
				else
					if(mom_npc->vbls>180)
						dinner_cycle++;
			}

			if(dinner_cycle==3)
			{
				TEXT_set_sprite_window(0,mom_npc,NULL);
				TEXT_set_sprite_window(1,PLAYER_npc,NULL);
				TEXT_window(
							"<NOCANCEL>So, how was school today?<.>"
							"<1>Me?<.>"
							"<0>Don't be stupid, of course I mean Yuu. Does anyone else here look like they go to school?<.>"
							"<1>Oh. Yeah, I guess it was fine.<.>"
							"<0>And did Yuu finish his homework?<.>"
							"<1>Hmm. I don't think we had any.<.>"
							"<0>What does Yuu mean, Yuu doesn't THINK? Did Yuu or didn't Yuu? Yes or no, it's a simple question.<.>"
							"Doesn't Yuu understand just how important his education is? <.>"
							"If Yuu forgets to do his homework ONE TIME, it goes on his permanent record FOREVER.<.>"
							"If that happens, Yuu will never get a job. Yuu will die lonely and homeless, forgotten in a dumpster. <.>"
							"And how exactly does Yuu think that's going to make ME look, as his mother?<.>"
							"<1><SMALL><GRAY>(I didn't know elementary school was so critical.. Scary!)<NORMAL><WHITE><.>"
							"Sorry...<NEXTLINE>I'm sure we didn't have any homework today. I'll keep up on it.<.>"
							"<SMALL><GRAY>(What's the deal with this tension, anyway?)<NORMAL><WHITE>"
							);
				mom_npc->vbls=0;
				dinner_cycle++;
			}

			if(dinner_cycle==4)
			{
				if(GLOBAL_text_engine_state!=0){mom_npc->vbls=0;}
				else
					if(mom_npc->vbls>200)
						dinner_cycle++;
			}

			if(dinner_cycle==5)
			{
				TEXT_set_sprite_window(0,mom_npc,NULL);
				TEXT_set_sprite_window(1,PLAYER_npc,NULL);

				if(talked_to_brother)
				{
					TEXT_window(
								"<NOCANCEL>*Ahem*<.>"
								"And just WHERE is your older brother? <.>"
								"I did NOT slave in the kitchen for 17 hours so he could skip out on our wonderful family meal!<.>"
								"<1>Uhh, he said something about a hot date.<.>"
								"<0>A what?<.>"
								"A DATE?!<.>"
								"Yuu means to tell me that he'd rather hang out with some bimbo than enjoy a hot home-cooked meal with his loving family?!<.>"
								"<1>I don't know.. I guess so.<DELAY30> Hey, what's a geek virus?<.>"
								"<0>Yuu GUESS?<SHAKE1SEC> Excuse me, young man? <DELAY30>Geek virus? <DELAY30>Does Yuu think this is a laughing matter? Is this some kind of joke to Yuu?<.>"
								"<NORMAL>Dear, do something about these children! They don't understand what's important in the world!<.>"
								"<1><DAD>Yuu had better not give your mother any back talk, son!<.>"
								"<0><YUU>What? Whoa, hold on! I didn't! I was just asking what a geek virus was! What's a geek virus?<.>"
								"<1>Oh, being sarcastic, wise guy?<.>"
								"<0>What? But I..<.>"
								"<1><HUGE>Just be quiet!<SHAKE1SEC> I don't need any excuses!<.>"
								"<NORMAL><0>I wasn't making an excuse! I was just asking what a geek virus was! What does sarcastic mean?<.>"
								"<1><HUGE>What IS IT with Yuu?! <SHAKE1SEC>THAT'S IT, <SHAKE1SEC>I'VE HAD ENOUGH! <SHAKE1SEC><.>"
								"I DON'T NEED THIS RIGHT NOW!<SHAKE1SEC><.>"
								"GO TO YOUR ROOM! <SHAKE1SEC><DELAY30><BOB>NOW!!!<SHAKE1SEC><SHAKE1SEC><.>"
								"<0><NORMAL><MOM>That's right! Yuu can't talk to his parents like that. I hope Yuu learned his lesson!"
								);
				}
				else
				{
					TEXT_window(
								"<NOCANCEL>*Ahem*<.>"
								"And just WHERE is your older brother? <.>"
								"I did NOT slave in the kitchen for 17 hours so he could skip out on our wonderful family meal!<.>"
								"<1>How am I supposed to know?<.>"
								"<0>What?<.>"
								"Yuu means to tell me that he doesn't even know where his brother is?!<.>"
								"<1>I don't know.. I guess not.<.>"
								"<0>Yuu GUESS?<SHAKE1SEC> Excuse me, young man? Does Yuu think this is a laughing matter? Is this some kind of joke to Yuu?<.>"
								"<NORMAL>Dear, do something about these children! They don't understand what's important in the world!<.>"
								"<1><DAD>Yuu had better not give your mother any back talk, son!<.>"
								"<0><YUU>What? Whoa, hold on! I didn't!<.>"
								"<1>Oh, being sarcastic, wise guy?<.>"
								"<0>What? But I..<.>"
								"<1><HUGE>Just be quiet!<SHAKE1SEC> I don't need any excuses!<.>"
								"<NORMAL><0>I wasn't making an excuse! What does sarcastic mean?<.>"
								"<1><HUGE>What IS IT with Yuu?! <SHAKE1SEC>THAT'S IT, <SHAKE1SEC>I'VE HAD ENOUGH! <SHAKE1SEC><.>"
								"I DON'T NEED THIS RIGHT NOW!<SHAKE1SEC><.>"
								"GO TO YOUR ROOM! <SHAKE1SEC><DELAY30><BOB>NOW!!!<SHAKE1SEC><SHAKE1SEC><.>"
								"<0><NORMAL><MOM>That's right! Yuu can't talk to his parents like that. I hope Yuu learned his lesson!"
								);


				}
				dinner_cycle++;
			}

			if(dinner_cycle==6)
				if(GLOBAL_text_engine_state==0)
				{
					HARDWARE_play_sound("doorsound",127,44100,0);

					if(LETTERBOX_sprites_exist)LETTERBOX_deinit();


					metatile_map=1;

					GLOBAL_main_sprite_input_off=0;

					MAP_change_map(MAP_bobsgame_TOWNYUUUpstairsYuusRoom,16,16);

					TEXT_set_sprite_window(0,PLAYER_npc,NULL);

					TEXT_window(
								"<NOCANCEL>What the?<.>"
								"What's the deal with them?<.>"
								"I wonder if something's wrong. They've been in a bad mood for awhile.<.>"
								"I'd better stay upstairs until things smooth over...<.>"
								"Man, this sucks. It's so boring up here. I wish I had something to do to pass the time.<.>"
								);

								//TODO: stop time.

					dinner_cycle++;

					return;
				}

			if(dinner_cycle==7&&GLOBAL_text_engine_state==0)
			{
				TEXT_set_sprite_window(0,dad_npc,NULL);
				TEXT_set_sprite_window(1,mom_npc,NULL);
				TEXT_window(
							"<NOCANCEL><0>That had better not be who I think it is coming down those stairs..<.>"
							"<1>GET BACK UP THERE!<SHAKE1SEC>"
							);
				dinner_cycle++;
			}

			if(dinner_cycle==8)
			{
				if(GLOBAL_text_engine_state==0)
				{
					HARDWARE_play_sound("doorsound",127,44100,0);
					GLOBAL_main_sprite_input_off=0;
					MAP_change_map(MAP_bobsgame_TOWNYUUUpstairsYuusRoom,16,16);
					TEXT_set_sprite_window(0,PLAYER_npc,NULL);
					TEXT_window(
								"<NOCANCEL>Hmm.. I guess I'm stuck up here for now."
								);
					dinner_cycle=7;
					return;
				}
			}
		}
	}
	//===============================================================================================
	if(CLOCK_hour>=12+8&&CLOCK_hour<12+10)	//8 pm to 10 pm===============================================================================================
	{//===============================================================================================
		if(dad_npc==NULL&&(CLOCK_hour==12+8||CLOCK_minute<55))
		{
			NPC_create_npc_xy_feet(&dad_npc,GFX_ADULT_dad, 16, 40, YUUDownstairs_Ping);
			dad_npc->non_walkable=1;
		}

		if(pingnpc==NULL&&(CLOCK_hour==12+8||CLOCK_minute<55))
			NPC_create_npc(&pingnpc,GFX_MISC_pingcontroller,32,64,45*8,30*8);

		//TODO: tv on loud. maybe flickering tv light. ping noises.

		if(ACTION_npc(&dad_npc,"Talk To Dad")&&GLOBAL_text_engine_state==0)
		{
			TEXT_set_sprite_window(0,dad_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			TEXT_window(
						"Hey, I guess we were a little hard on Yuu. It's alright as long as Yuu did his homework.<.>"
						"<1>I still don't have any.<.>"
						"<0>Oh, right. Well good job. <.>"
						"There're leftovers in the fridge if Yuu is hungry.<.>"
						"Oh, when your brother comes home tell him your mother and I want to have a talk with him.<.>"
						"Don't stay up too late.<.>"
						"We care about Yuu.<.>"
						"Hey, son.<.>"
						"<1>Yeah?<.>"
						"<0>Will Yuu get out of my way? I'm doing serious training here.<.>"
						"<1><SMALL>(For what?)<NORMAL>"
						);
		}

		if(dad_npc!=NULL)
		{	//===============================================================================================
			if(CLOCK_hour==12+9&&CLOCK_minute==55&&dad_flag==0)////////////////////////dad goto bed
			{//===============================================================================================
				CLOCK_minute++;
				dad_flag=1;

				if(pingnpc!=NULL)
				{
					NPC_delete_npc(&pingnpc);
					pingnpc=NULL;
				}
			}

			if(dad_flag==1)
				if(NPC_walk_to_xy_nohit(&dad_npc, SPEED_SLOWEST, YUUDownstairs_Ping))
					dad_flag=2;

			if(dad_flag==2)
			{
				TEXT_set_sprite_window(0,dad_npc,NULL);
				TEXT_set_sprite_window(1,PLAYER_npc,NULL);
				TEXT_window(
							"<NOCANCEL>Alright little guy, don't cause your mother any more trouble.<.>"
							"<1>Ok. Is everything alright?<.>"
							"<0>Everything is perfect. <.>"
							"I mean, I'm sure it'll work out. <.>"
							"Yuu shouldn't start worrying too.<.>"
							"<1><SMALL>(Hmm..)<NORMAL>"
							);
				dad_flag=3;
			}

			if(dad_flag==3)
				if(GLOBAL_text_engine_state==0)
					dad_flag++;

			if(dad_flag==4)
				if(NPC_walk_to_xy_nohit(&dad_npc, SPEED_SLOWEST, 41*8, 38*8))//going to bed
					dad_flag++;

			if(dad_flag==5)
				if(NPC_walk_to_xy_nohit(&dad_npc, SPEED_SLOWEST, 22*8, 38*8))
					dad_flag++;

			if(dad_flag==6)
				if(NPC_walk_to_xy_nohit(&dad_npc, SPEED_SLOWEST, 19*8, 34*8))
					dad_flag++;

			if(dad_flag==7)
				if(NPC_walk_to_xy_nohit(&dad_npc, SPEED_SLOWEST, YUUDownstairs_StairsBottom))
					dad_flag++;

			if(dad_flag==8)
				if(NPC_walk_to_xy_nohit(&dad_npc, SPEED_SLOWEST, YUUDownstairs_StairsTop))
					dad_flag++;

			if(dad_flag==9)
			{
				NPC_delete_npc(&dad_npc);
				dad_flag=0;
				dad_npc=NULL;
			}
		}

		//TODO: mom upstairs in the bedroom crying? "im sorry dear, were not mad at you, go and eat"
	}
	//===============================================================================================
	if(CLOCK_hour>=12+10&&CLOCK_hour<24)	//10 pm to 12 am===============================================================================================
	{//===============================================================================================


		//elopes to the city with friends sister? gets her pregnant?
		//mom gets put in a mental hospital in the city
		//dad is homeless? tournament villain?	the masked vagrant
		//dad upstairs
		//mom upstairs


		//cricket chirp
		sfx_crickets(16);

		//===============================================================================================
		if(CLOCK_hour==12+10&&CLOCK_minute==15&&brother_flag==0)// if 10:15 brother comes in the garage
		{//===============================================================================================
			if(brother_npc==NULL)
			{
				NPC_create_npc_xy_feet(&brother_npc,GFX_KID_brother, 16, 32, YUUDownstairs_GarageDoor);
				brother_npc->non_walkable=1;
				HARDWARE_play_sound("doorsound",127,44100,0);
				brother_flag=1;
				CLOCK_minute++;
			}
		}
		//===============================================================================================
		if((CLOCK_hour!=12+11||CLOCK_minute<55)&&brother_npc!=NULL)
		{//===============================================================================================
			if(brother_flag==1)
				if(GLOBAL_text_engine_state==0)
					brother_flag++;

			if(brother_flag==2)
				if(NPC_walk_to_xy_nohit(&brother_npc, SPEED_SLOWEST, YUUDownstairs_KitchenSink))
					brother_flag++;

			if(brother_flag==3)
				if(NPC_walk_to_xy_nohit(&brother_npc, SPEED_SLOWEST, YUUDownstairs_TableLeft))
					brother_flag++;

			if(brother_flag==4)
			{
				NPC_animate_stand_dir(&brother_npc, RIGHT);    //sit at table facing right
				brother_flag=0;
			}

			if(ACTION_npc(&brother_npc,"Talk To Brother")&&GLOBAL_text_engine_state==0)
			{
				TEXT_set_sprite_window(0,brother_npc,NULL);
				TEXT_set_sprite_window(1,PLAYER_npc,NULL);
				TEXT_window(
							"So how's it going, idiot? Did you have a nice wholesome family dinner? <DELAY30>*snicker*<.>"
							"Aw man, this girl is so hot. Yuu has got no idea.<.>"
							"And here Yuu is, stuck here with good ole' Ma and Pops.<.>"
							"I bet Yuu couldn't even bag an ugly chick, Yuu little dork.<.>"
							"<1>I don't think I'd try.<.>"
							"<0>That's what I mean, dork. Hey, Yuu didn't go in my room while I was gone, did Yuu?<.>"
							"<1>It's locked.<.>"
							"<0>Aha! That means Yuu tried! That's the last time I ever let Yuu borrow my stuff.<.>"
							"<1>You never let me anyway.<.>"
							"Oh yeah, Mom and Dad wanted to talk to you.<.>"
							"<0>What? Yuu didn't tell them where I was, did Yuu? <.>"
							"Don't tell me Yuu ratted me out? <.>"
							"I'll kill Yuu and make Yuu eat his own face, Yuu hears me?<.>"
							"<1>You didn't say it was a secret.<.>"
							"<0>What? Yuu has got no common sense, Yuu Bob-darned idiot. <.>"
							"I'll get Yuu for this!<.>"
							"Yuu is gonna pay big time, my dear little brother. <.>"
							"<HUGE>GET OUT OF MY FACE!<SHAKE1SEC>"
							);
				//TODO: knock yuu back 3 tiles
			}
		}

		if(brother_npc!=NULL)
		{	//===============================================================================================
			if(CLOCK_hour==12+11&&CLOCK_minute==55&&brother_flag==0)////////////////////////going upstairs
			{//===============================================================================================
				CLOCK_minute++;
				brother_flag=4;
				TEXT_set_sprite_window(0,brother_npc,NULL);
				TEXT_set_sprite_window(1,PLAYER_npc,NULL);
				TEXT_window(
							"<NOCANCEL>Don't forget, this means revenge. <.>"
							"I'll get Yuu good, it's payback time. <.>"
							"Yuu'll see, I'll remember this, Yuu little twerp. <.>"
							"Sleep well. Ahahahahahaha!<.>"
							"<1>Hey, how was I supposed to know? You didn't tell me.<.>"
							"<0>What a dork. I'm gonna knock some common sense into Yuu one of these days.<.>"
							"<HUGE>GET OUT OF MY FACE!<SHAKE1SEC>"
							);
			}

			if(brother_flag==4)
				if(GLOBAL_text_engine_state==0)
					brother_flag++;

			if(brother_flag==5)
				if(NPC_walk_to_xy_nohit(&brother_npc, SPEED_SLOWEST, 15*8, 35*8))
					brother_flag++;

			if(brother_flag==6)
				if(NPC_walk_to_xy_nohit(&brother_npc, SPEED_SLOWEST, YUUDownstairs_StairsBottom))
					brother_flag++;

			if(brother_flag==7)
				if(NPC_walk_to_xy_nohit(&brother_npc, SPEED_SLOWEST, YUUDownstairs_StairsTop))
					brother_flag++;

			if(brother_flag==8)
			{
				NPC_delete_npc(&brother_npc);
				brother_flag=0;
				brother_npc=NULL;
			}
		}
	}

	//=====================
//ACTIONS
//=====================
	if(walking_into_door(RANGE_YUUDownstairsToGarage))
	{
		MAP_change_map(MAP_bobsgame_TOWNYUUGarage,23,11);
		return;
	}


if(CLOCK_hour>=12+6&&CLOCK_hour<12+7)
{
	if(walking_into_door(RANGE_YUUDownstairsToUpstairs)&&GLOBAL_text_engine_state==0)
	{
		TEXT_set_sprite_window(0,dad_npc,NULL);
		TEXT_set_sprite_window(1,mom_npc,NULL);
		TEXT_window(
					"<NOCANCEL>Where is Yuu going, young man? Yuu heard us. It's time for dinner.<.>"
					"<1>Sit down so we can start!"
					);
		PLAYER_npc->MAP_y++;
	}
}
else
{

	if(walking_into_door(RANGE_YUUDownstairsToUpstairs))
	{
		MAP_change_map(MAP_bobsgame_TOWNYUUUpstairs,5,20);
		return;
	}
}

	if(walking_into_door(RANGE_YUUDownstairsToDownstairsBathroom))
	{
		MAP_change_map(MAP_bobsgame_TOWNYUUDownstairsBathroom,6,16);
		return;
	}



	if(ACTION_range_xy_xy(RANGE_YUUDownstairsToOUTSIDEBackyard,"Go outside."))
	{
		//===============================================================================================
		if(CLOCK_hour>=12+3&&CLOCK_hour<12+10)//TODO: make sure if not grounded, make sure not weekend.
		{//===============================================================================================
			//MAP_change_map(MAP_bobsgame_TOWNTown,525,463);return;

			if(CLOCK_hour<12+8&&GLOBAL_text_engine_state==0)
			{

				TEXT_set_sprite_window(0,PLAYER_npc,NULL);
				TEXT_window("I should wait until after dinner.");
			}

			if(CLOCK_hour>=12+8&&GLOBAL_text_engine_state==0)
			{

				TEXT_set_sprite_window(0,PLAYER_npc,NULL);
				TEXT_window("I'd better stay inside. I'm already in trouble.");
			}

		}
		else//===============================================================================================
		if(CLOCK_hour>=7&&CLOCK_hour<8&&GLOBAL_text_engine_state==0)//TODO: get to school in time game. or just directly jump to school grounds?
		{//===============================================================================================
			if(havelunch==1)
			{
				//MAP_change_map(MAP_bobsgame_TOWNTown,525,463);return;



						load_bob_scene_2();

						return;


			}
			else
			{
				TEXT_set_sprite_window(0,PLAYER_npc,NULL);
				TEXT_window("I should get my lunch first.");
			}
		}
		else//===============================================================================================
		if(CLOCK_hour>=6&&CLOCK_hour<7&&GLOBAL_text_engine_state==0)
		{//===============================================================================================
			TEXT_set_sprite_window(0,mom_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);

			TEXT_window(
						"Hold those horses, kiddo. Where is Yuu going?<.>"
						"<1>School.<.>"
						"<0>It's not time to leave, Yuu knows that. School isn't until 7:30.<.>"
						"Yuu doesn't even have his lunch yet!<.>"
						"<1>I'll be fine, don't worry.<.>"
						"<0>Well don't blame me if Yuu runs out of energy halfway through the day!"
						);
		}
		else//===============================================================================================
		if((CLOCK_hour<6)&&GLOBAL_text_engine_state==0)
		{//===============================================================================================
			TEXT_set_sprite_window(0,PLAYER_npc,NULL);
			TEXT_window("It's still dark out. I don't think I should leave.");
		}
		else//===============================================================================================
		if((CLOCK_hour>=12+10)&&GLOBAL_text_engine_state==0)
		{//===============================================================================================
			TEXT_set_sprite_window(0,PLAYER_npc,NULL);
			TEXT_window("I'm not allowed outside at night. The alarm will go off.");
		}

	}

	if(ACTION_range_xy_xy(RANGE_YUUDownstairsToOUTSIDEFrontyard,"Go outside."))
	{	//===============================================================================================
		if(CLOCK_hour>=12+3&&CLOCK_hour<12+10)//TODO: make sure if not grounded, make sure not weekend.
		{//===============================================================================================



			//MAP_change_map(MAP_bobsgame_TOWNTown,506,504);return;

			if(CLOCK_hour<12+8&&GLOBAL_text_engine_state==0)
			{

				TEXT_set_sprite_window(0,PLAYER_npc,NULL);
				TEXT_window("I should wait until after dinner.");
			}

			if(CLOCK_hour>=12+8&&GLOBAL_text_engine_state==0)
			{

				TEXT_set_sprite_window(0,PLAYER_npc,NULL);
				TEXT_window("I'd better stay inside. I'm already in trouble.");
			}



		}
		else//===============================================================================================
		if(CLOCK_hour>=7&&CLOCK_hour<8&&GLOBAL_text_engine_state==0)//TODO: get to school in time game. or just directly jump to school grounds?
		{//===============================================================================================
			if(havelunch==1)
			{
				//MAP_change_map(MAP_bobsgame_TOWNTown,506,504);return;


					load_bob_scene_2();

					return;



			}
			else
			{
				TEXT_set_sprite_window(0,PLAYER_npc,NULL);
				TEXT_window("I should get my lunch first.");
			}

		}
		else//===============================================================================================
		if(CLOCK_hour>=6&&CLOCK_hour<7&&GLOBAL_text_engine_state==0)
		{//===============================================================================================
			TEXT_set_sprite_window(0,mom_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);

			TEXT_window(
						"Hold those horses, kiddo. Where is Yuu going?<.>"
						"<1>School.<.>"
						"<0>It's not time to leave, Yuu knows that. School isn't until 7:30.<.>"
						"Yuu doesn't even have his lunch yet!<.>"
						"<1>I'll be fine, don't worry.<.>"
						"<0>Well don't blame me if Yuu runs out of energy halfway through the day!"
						);
		}
		else//===============================================================================================
		if((CLOCK_hour<6)&&GLOBAL_text_engine_state==0)
		{//===============================================================================================
			TEXT_set_sprite_window(0,PLAYER_npc,NULL);
			TEXT_window("It's still dark out. I don't think I should leave.");
		}
		else//===============================================================================================
		if((CLOCK_hour>=12+10)&&GLOBAL_text_engine_state==0)
		{//===============================================================================================
			TEXT_set_sprite_window(0,PLAYER_npc,NULL);
			TEXT_window("I'm not allowed outside at night. The alarm will go off.");
		}
	}


	if(walking_into_door(RANGE_YUUDownstairsToBasement))
	{
		MAP_change_map(MAP_bobsgame_TOWNYUUBasement,5,9);
		return;
	}


}

void bobsgame_TOWNYUUDownstairs_Map_Stop_Function()
{
	NPC_delete_all_npcs();
	mom_npc=NULL;
	dad_npc=NULL;
	brother_npc=NULL;
	dad_flag=0;
	mom_flag=0;
	brother_flag=0;
	batterynpc=NULL;
	lunchnpc=NULL;
	dinnernpc=NULL;
	plate1=NULL;
	plate2=NULL;
	plate3=NULL;
	plate4=NULL;
	pingnpc=NULL;
	kitchen_tv_on=0;
	HARDWARE_stop_sound("tv");
}

void bobsgame_TOWNYUUDownstairs_Map_VBL_Function()
{

}

void bobsgame_TOWNYUUDownstairs_Map_HBL_Function()
{

}

///===============================================================================================================================================================================================
//YUUUpstairs
///===============================================================================================================================================================================================
void bobsgame_TOWNYUUUpstairs_Map_Load_Function()
{
//RANGE_YUUUpstairsToDownstairs 2*8,21*8,8*8,22*8
//RANGE_YUUUpstairsToYuusRoom 47*8,8*8,51*8,9*8
//RANGE_YUUUpstairsToBrothersRoom 24*8,8*8,28*8,9*8
//RANGE_YUUUpstairsToParentsRoom 11*8,16*8,15*8,17*8
//RANGE_YUUUpstairsToUpstairsBathroom 52*8,16*8,56*8,17*8
//RANGE_YUUUpstairsToBabyRoom 34*8,16*8,38*8,17*8
}

void bobsgame_TOWNYUUUpstairs_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//==============================================================================================================================
//YUUUPSTAIRS MAP RUN
//==============================================================================================================================


	if(CLOCK_hour<5)
	{
		CLOCK_paused=1;
	}

	if(CLOCK_hour>=5&&CLOCK_hour<6)//midnight to 6 am=====================================================================================================
	{
		//5:50 parents come out of room go downstairs //15,14 6,13 5,23
		if(CLOCK_hour==5&&CLOCK_minute==58&&mom_flag==0&&dad_flag==0)
		{
			if(mom_npc==NULL)
			{
				NPC_create_npc_xy_feet(&mom_npc,GFX_ADULT_mom, 16, 40,	15*8, 14*8);
				mom_npc->non_walkable=1;
				mom_flag=1;
			}

			if(dad_npc==NULL)
			{
				NPC_create_npc_xy_feet(&dad_npc,GFX_ADULT_dad, 16, 40,	15*8, 12*8);
				dad_npc->non_walkable=1;
				dad_flag=1;
			}

			CLOCK_minute++;

			HARDWARE_play_sound("doorsound",127,44100,0);
		}

		if(mom_npc!=NULL)
		{
			if(mom_flag==1)
				if(NPC_walk_to_xy_nohit(&mom_npc, SPEED_SLOW, 6*8, 13*8))
					mom_flag++;

			if(mom_flag==2)
				if(NPC_walk_to_xy_nohit(&mom_npc, SPEED_SLOW, 5*8, 23*8))
				{
					mom_flag++;
				}

			if(mom_flag==3)
			{
				if(mom_npc!=NULL)
					NPC_delete_npc(&mom_npc);    //delete

				mom_flag=0;

				mom_npc=NULL;
			}
		}

		if(dad_npc!=NULL)
		{
			if(dad_flag==1)
				if(NPC_walk_to_xy_nohit(&dad_npc, SPEED_SLOWEST, 6*8, 13*8))
					dad_flag++;

			if(dad_flag==2)
				if(NPC_walk_to_xy_nohit(&dad_npc, SPEED_SLOWEST, 5*8, 23*8))
				{
					dad_flag++;
				}

			if(dad_flag==3)
			{
				if(dad_npc!=NULL)
					NPC_delete_npc(&dad_npc);    //delete

				dad_flag=0;

				dad_npc=NULL;
			}
		}
	}

	if(CLOCK_hour>=6&&CLOCK_hour<7)//6 am to 7 am=====================================================================================================
	{
		CLOCK_paused=1;
	}

	if(CLOCK_hour>=7&&CLOCK_hour<8)//7 am to 8 am=====================================================================================================
	{
		CLOCK_paused=1;
	}

	if(CLOCK_hour>=8&&CLOCK_hour<10)//8 am to 10 am=====================================================================================================
	{

	}

	if(CLOCK_hour>=10&&CLOCK_hour<12)//10 am to 12 pm=====================================================================================================
	{
		//TODO: brother comes out of room, goes downstairs
	}

	if(CLOCK_hour>=12&&CLOCK_hour<12+2)//12 am to 2 pm=====================================================================================================
	{

	}

	if(CLOCK_hour>=12+2&&CLOCK_hour<12+4)//2 pm to 4 pm=====================================================================================================
	{
		//2:00 mom comes from downstairs, goes into bathroom, goes into room.	//5,23 6,13 56,14

		if(CLOCK_hour==12+2&&CLOCK_minute<15)
		{
			if(CLOCK_hour==12+2&&CLOCK_minute==0&&mom_flag==0)
			{
				if(mom_npc==NULL)
				{
					NPC_create_npc_xy_feet(&mom_npc,GFX_ADULT_mom, 16, 40,	5*8, 23*8);
					mom_npc->non_walkable=1;
					mom_flag=1;
					CLOCK_minute++;
				}
			}

			if(mom_npc!=NULL)
			{
				if(mom_flag==1)
					if(NPC_walk_to_xy_nohit(&mom_npc, SPEED_SLOWEST, 6*8, 13*8))
						mom_flag++;

				if(mom_flag==2)
					if(NPC_walk_to_xy_nohit(&mom_npc, SPEED_SLOWEST, 56*8, 14*8))
					{
						NPC_animate_stand_dir(&mom_npc, DOWN);
						mom_flag++;
					}

				//TODO: cant go in bathroom
				if(mom_flag==3)
				{
					mom_flag++;
					HARDWARE_play_sound("doorsound",127,44100,0);
				}

				if(mom_flag==4)
				{
					if(mom_npc!=NULL)
						NPC_delete_npc(&mom_npc);    //delete, go in room

					mom_flag=0;

					mom_npc=NULL;
				}
			}
		}

		//2:15 comes out of bathroom goes in room	56,14 15,14
		if(CLOCK_hour==12+2&&CLOCK_minute>=15)
		{
			if(CLOCK_hour==12+2&&CLOCK_minute==15&&mom_flag==0)
			{
				HARDWARE_play_sound("doorsound",127,44100,0);

				if(mom_npc==NULL)
				{
					NPC_create_npc_xy_feet(&mom_npc,GFX_ADULT_mom, 16, 40,	56*8, 14*8);
					mom_npc->non_walkable=1;
					mom_flag=1;
					CLOCK_minute++;
				}
			}

			if(mom_npc!=NULL)
			{
				if(mom_flag==1)
					if(NPC_walk_to_xy_nohit(&mom_npc, SPEED_SLOWEST, 15*8, 14*8))
					{
						NPC_animate_stand_dir(&mom_npc, DOWN);
						mom_flag++;
					}

				if(mom_flag==2)
				{
					mom_flag++;
					HARDWARE_play_sound("doorsound",127,44100,0);
				}

				if(mom_flag==3)
				{
					if(mom_npc!=NULL)
						NPC_delete_npc(&mom_npc);    //delete, go in room

					mom_flag=0;

					mom_npc=NULL;
				}
			}
		}

		//3:55 comes out of room goes downstairs //15,14 6,13 5,23
		if(CLOCK_hour==12+3&&CLOCK_minute>=56)
		{
			if(CLOCK_hour==12+3&&CLOCK_minute==56&&mom_flag==0)
			{
				HARDWARE_play_sound("doorsound",127,44100,0);

				if(mom_npc==NULL)
				{
					NPC_create_npc_xy_feet(&mom_npc,GFX_ADULT_mom, 16, 40,	15*8, 14*8);
					mom_npc->non_walkable=1;
					mom_flag=1;
					CLOCK_minute++;
				}
			}

			if(mom_npc!=NULL)
			{
				if(mom_flag==1)
					if(NPC_walk_to_xy_nohit(&mom_npc, SPEED_SLOWEST, 6*8, 13*8))
						mom_flag++;

				if(mom_flag==2)
					if(NPC_walk_to_xy_nohit(&mom_npc, SPEED_SLOWEST, 5*8, 23*8))
					{
						mom_flag++;
					}

				if(mom_flag==3)
				{
					if(mom_npc!=NULL)
						NPC_delete_npc(&mom_npc);    //delete, go downstairs

					mom_flag=0;

					mom_npc=NULL;
				}
			}
		}
	}

	if(CLOCK_hour>=12+4&&CLOCK_hour<12+6)//4 pm to 6 pm=====================================================================================================
	{
		//nothing
		CLOCK_paused=1;
	}

	if(CLOCK_hour>=12+6&&CLOCK_hour<12+8)//6 pm to 8 pm=====================================================================================================
	{
		CLOCK_paused=1;
	}

	if(CLOCK_hour>=12+8&&CLOCK_hour<12+10)//8 pm to 10 pm=====================================================================================================
	{
		//8:00 mom comes up stairs goes into bedroom crying //5,23 6,13 15,14 doorsound

		if(CLOCK_hour==12+8&&CLOCK_minute==0&&mom_flag==0)
		{
			if(mom_npc==NULL)
			{
				NPC_create_npc_xy_feet(&mom_npc,GFX_ADULT_mom, 16, 40,	5*8, 23*8);
				mom_npc->non_walkable=1;
				mom_flag=1;
				CLOCK_minute++;
			}
		}

		if(mom_npc!=NULL)
		{
			if(mom_flag==1)
				if(NPC_walk_to_xy_nohit(&mom_npc, SPEED_SLOWEST, 6*8, 13*8))
					mom_flag++;

			if(mom_flag==2)
				if(NPC_walk_to_xy_nohit(&mom_npc, SPEED_SLOWEST, 15*8, 14*8))
				{
					NPC_animate_stand_dir(&mom_npc, DOWN);
					mom_flag++;
				}

			if(mom_flag==3)
			{
				mom_flag++;
				HARDWARE_play_sound("doorsound",127,44100,0);
			}

			if(mom_flag==4)
			{
				if(mom_npc!=NULL)
					NPC_delete_npc(&mom_npc);    //delete, go in room

				mom_flag=0;

				mom_npc=NULL;
			}
		}

		//9:55 dad comes up stairs goes into bedroom	//5,23 6,13 15,14
		if(CLOCK_hour==12+9&&CLOCK_minute==56&&dad_flag==0)
		{
			if(dad_npc==NULL)
			{
				NPC_create_npc_xy_feet(&dad_npc,GFX_ADULT_dad, 16, 40,	5*8, 23*8);
				dad_npc->non_walkable=1;
				dad_flag=1;
				CLOCK_minute++;
			}
		}

		if(dad_npc!=NULL)
		{
			if(dad_flag==1)
				if(NPC_walk_to_xy_nohit(&dad_npc, SPEED_SLOWEST, 6*8, 13*8))
					dad_flag++;

			if(dad_flag==2)
				if(NPC_walk_to_xy_nohit(&dad_npc, SPEED_SLOWEST, 15*8, 14*8))
				{
					NPC_animate_stand_dir(&dad_npc, DOWN);
					dad_flag++;
				}

			if(dad_flag==3)
			{
				dad_flag++;
				HARDWARE_play_sound("doorsound",127,44100,0);
			}

			if(dad_flag==4)
			{
				if(dad_npc!=NULL)
					NPC_delete_npc(&dad_npc);    //delete, go in room

				dad_flag=0;

				dad_npc=NULL;
			}
		}
	}

	if(CLOCK_hour>=12+10&&CLOCK_hour<24)//10 pm to 12 am=====================================================================================================
	{
		//11:55 brother comes upstairs, unlocks door, goes into his room	//5,23 6,13 27,13 27,9,pause a minute,doorknob sound,delete
		if(CLOCK_hour==12+11&&CLOCK_minute==56&&brother_flag==0)
		{
			if(brother_npc==NULL)
			{
				NPC_create_npc_xy_feet(&brother_npc,GFX_KID_brother, 16, 32,	5*8, 23*8);
				brother_npc->non_walkable=1;
				brother_flag=1;
				CLOCK_minute++;
			}
		}

		if(brother_npc!=NULL)
		{
			if(brother_flag==1)
				if(NPC_walk_to_xy_nohit(&brother_npc, SPEED_SLOWEST, 6*8, 13*8))
					brother_flag++;

			if(brother_flag==2)
				if(NPC_walk_to_xy_nohit(&brother_npc, SPEED_SLOWEST, 27*8, 9*8))
				{
					NPC_animate_stand_dir(&brother_npc, UP);
					brother_flag++;
					HARDWARE_play_sound("keyjingle",127,44100,0);
				}

			if(brother_flag==3)
				if(brother_npc->vbls>120)
					brother_flag++;

			if(brother_flag==4)
			{
				brother_flag++;
				HARDWARE_play_sound("doorsound",127,44100,0);
			}

			if(brother_flag==5)
			{
				if(brother_npc!=NULL)
					NPC_delete_npc(&brother_npc);    //delete, go in room

				brother_flag=0;

				brother_npc=NULL;
			}
		}
	}

//=====================
//ACTIONS
//=====================


	if(walking_into_door(RANGE_YUUUpstairsToDownstairs))
	{
		MAP_change_map(MAP_bobsgame_TOWNYUUDownstairs,5,27);
		return;
	}

	if(walking_into_door(RANGE_YUUUpstairsToYuusRoom))
	{
		MAP_change_map(MAP_bobsgame_TOWNYUUUpstairsYuusRoom,20,21);
		return;
	}


static int unlockdoor=0;

	if(ACTION_range_xy_xy(RANGE_YUUUpstairsToBrothersRoom,"Go in Older Brother's Room"))
	{
		if(ITEM_have(&LockPick)==0||unlockdoor!=0)
		{
			if(CLOCK_hour<10)
			{
				TEXT_set_sprite_window(0,PLAYER_npc,NULL);
				TEXT_window("It's locked.<.> He's sleeping, he'll wake up if I try to get in.");
			}
			else
			{

				TEXT_set_sprite_window(0,PLAYER_npc,NULL);
				TEXT_window("It's locked.<.> I wonder if there's a way to get in...");
			}

		}
		else
		{

			TEXT_set_sprite_window(0,PLAYER_npc,NULL);
			TEXT_window("Let's try this...");

			unlockdoor=1;

		}
	}

	if(unlockdoor==1&&GLOBAL_text_engine_state==0)
	{
		unlockdoor=2;
		HARDWARE_play_sound("buzz",64,44100,0);
		PLAYER_npc->vbls=0;

	}

	if(unlockdoor==2)
	{
		while(PLAYER_npc->vbls<60)whilefix();
		if(PLAYER_npc->vbls>60)
		{
			unlockdoor=0;
			HARDWARE_play_sound("doorsound",64,44100,0);
			MAP_change_map(MAP_bobsgame_TOWNYUUUpstairsBrothersRoom,26,21);
			return;
		}

	}




	if(ACTION_range_xy_xy(RANGE_YUUUpstairsToParentsRoom,"Go in Parent's Room"))
	{
		if(CLOCK_hour<6||(CLOCK_hour==5&&CLOCK_minute<57)||CLOCK_hour>12+10)
		{
			TEXT_set_sprite_window(0,PLAYER_npc,NULL);
			TEXT_window("They're sleeping. I don't want to wake them up.");
		}
		else
		{
			MAP_change_map(MAP_bobsgame_TOWNYUUUpstairsParentsRoom,6,9);
			return;
		}

	}

	if(walking_into_door(RANGE_YUUUpstairsToUpstairsBathroom))
	{
		MAP_change_map(MAP_bobsgame_TOWNYUUUpstairsBathroom,9,9);
		return;
	}

	if(ACTION_range_xy_xy(RANGE_YUUUpstairsToBabyRoom,"Go in Kid's Room"))
	{


		if(CLOCK_hour<12+6||CLOCK_hour>=12+8)
		{
			if(CLOCK_hour<8||CLOCK_hour>12+10)
			{
				TEXT_set_sprite_window(0,PLAYER_npc,NULL);
				TEXT_window("He's sleeping. I don't want to wake him up.");
			}
			else
			{
				TEXT_set_sprite_window(0,PLAYER_npc,NULL);
				TEXT_window("He's studying. I don't want to disturb him.");
			}

		}
		else
		if(CLOCK_hour>=12+6&&CLOCK_hour<12+8)
		{

			{

				HARDWARE_play_sound("knockknock",64,44100,0);
				MAP_change_map(MAP_bobsgame_TOWNYUUUpstairsBabyRoom,9,9);
				return;
			}

		}



	}
}

void bobsgame_TOWNYUUUpstairs_Map_Stop_Function()
{
	NPC_delete_all_npcs();
	mom_npc=NULL;
	dad_npc=NULL;
	brother_npc=NULL;
	dad_flag=0;
	mom_flag=0;
	brother_flag=0;
	CLOCK_paused=0;
}

void bobsgame_TOWNYUUUpstairs_Map_VBL_Function()
{

}

void bobsgame_TOWNYUUUpstairs_Map_HBL_Function()
{

}

///===============================================================================================================================================================================================
//YUUUpstairsYuusRoom
///===============================================================================================================================================================================================
void bobsgame_TOWNYUUUpstairsYuusRoom_Map_Load_Function()
{
//RANGE_YUUYuusRoomToUpstairs 18*8,22*8,22*8,23*8
//RANGE_TurnOnMES 14*8,11*8,18*8,12*8
}

void bobsgame_TOWNYUUUpstairsYuusRoom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//==============================================================================================================================
//YUUUpstairsYuusRoom MAP RUN
//==============================================================================================================================

static int sleeping=1;//1;

//RAMIO_won=1;
//CLOCK_hour=12+6;CLOCK_minute=35;

if(GAME_playing_ramio==0)
{

	if(CLOCK_hour>=6)
	if(sleeping>=5)CLOCK_paused=1;



	if(CLOCK_hour>=6&&CLOCK_hour<12+6)
	{

		HARDWARE_play_music("nice",48);

		//birds chirping
		sfx_birds(16);
		//car horns
		sfx_carhorns(16);

	}
	if(CLOCK_hour>12+10||CLOCK_hour<6)
	{
		sfx_crickets(32);
		//sfx_clocktick(16);
	}

}



if(sleeping==1)
{
	CLOCK_hour=3;CLOCK_minute=0;

	if(!ITEM_have(&GameToy))ITEM_get_no_caption(&GameToy);
	if(!ITEM_have(&GameToyColors))ITEM_get_no_caption(&GameToyColors);
	//if(!ITEM_have(&LunchBag))ITEM_get_no_caption(&LunchBag);

	///main_sprite_toggle_shadow(0);

	GLOBAL_main_sprite_input_off=1;
	GLOBAL_main_sprite_standing=1;
	GLOBAL_main_sprite_actions_off=1;
	GLOBAL_main_sprite_fx_off=1;

	//yuu in bed
	PLAYER_npc->MAP_x=22*8;
	PLAYER_npc->MAP_y=(8*8);
	PLAYER_npc->layer=1;
	PLAYER_npc->walk_dir=RIGHT;
	NPC_animate_stand_dir(&PLAYER_npc, RIGHT);

	sleeping=2;
}

if(sleeping==2)
{
	if(!(CLOCK_hour==5&&CLOCK_minute==55))
	{
		static int v=0;
		if(vbl_5_var!=v)
		{
			v=vbl_5_var;

			CLOCK_minute++;
			CLOCK_moving=true;
			CLOCK_update_clock();
		}

		if(BUTTON_LEFT_PRESSED)PLAYER_npc->walk_dir=LEFT;
		if(BUTTON_RIGHT_PRESSED)PLAYER_npc->walk_dir=RIGHT;


		PLAYER_animate_turn_if_needed();


	}
	else
	{
		sleeping=3;
		//alarm clock go off
		HARDWARE_play_sound("alarmclock",64,44100,1);

		PLAYER_npc->vbls=0;
	}
}

if(sleeping==3)
{

	if(PLAYER_npc->vbls>120)
	{

		//dialogue
		TEXT_set_sprite_window(0,PLAYER_npc,NULL);
		TEXT_window("Unnngh...<.>Nnnnnnn...<.>What?<DELAY30> Huh?");
		sleeping=4;
	}


}

if(sleeping==4&&GLOBAL_text_engine_state==0)
{

	//roll out of bed
	if(NPC_walk_to_xy_nohit(&PLAYER_npc,SPEED_SLOWEST,27*8,11*8))sleeping=5;


}

if(sleeping==5)
{

	CLOCK_paused=1;

	//turn shadow on
	///main_sprite_toggle_shadow(1);

	//turn controls on
	GLOBAL_main_sprite_input_off=0;
	GLOBAL_main_sprite_standing=1;
	GLOBAL_main_sprite_actions_off=0;
	GLOBAL_main_sprite_fx_off=0;

	sleeping=6;

}

if(sleeping==6)
{
	if(ACTION_range_xy_xy(27*8,8*8,29*8,10*8,"Turn off Alarm Clock"))
	{
		//have to turn off clock
		HARDWARE_stop_sound("alarmclock");
		sleeping=7;

		TEXT_set_sprite_window(0,PLAYER_npc,NULL);
		TEXT_window("Whew. That's better.<.>Wait a second... <DELAY30>5 AM?<.>What the heck?");
	}
}

//brother tells you he changed your alarm

//TODO:under sheets
//TODO:in underwear

//TODO:have to put clothes on
//TODO:speed is very low
//TODO:set status
//TODO:have to pee




	if(nes_turned_on==1&&tv_npc==NULL)
		NPC_create_npc(&tv_npc,GFX_MISC_tv2x1mesflash,16,8,14*8,8*8);

	if(nes_turned_on==1&&tv_npc!=NULL)
	{
		if(tv_npc->vbl_animation_timer>50)
			NPC_animate_cycle_through_frames_now(&tv_npc,2);
	}

	if(nes_turned_on==0&&tv_npc!=NULL)
	{
		NPC_delete_npc(&tv_npc);
		tv_npc=NULL;
	}



static int nes_cleaned=0;


	if(GLOBAL_text_engine_state==0)
	{
		//CAPTION_make_caption(NULL, 1,PLAYER_npc->screen_x,PLAYER_npc->screen_y-10,2,"Hmm.. How do I fix it?",FONT_SMALL_ID,WHITE,BLACK);

		if(nes_turned_on==0)
		{
			if(ACTION_range_xy_xy(RANGE_TurnOnMES,"Turn on MES"))
			{

				if(ITEM_have(&CannedAir)==0)
				{
					TEXT_set_sprite_window(0,PLAYER_npc,NULL);    //blow into mic!! game turns on :)
					TEXT_window("Sigh... It always does that.<.>I wonder if there's anything I can do to fix it.");
					nes_turned_on=1;
				}
				else
				if(ITEM_have(&CannedAir)==1)
				{
					if(RAMIO_won==1)
					{
						TEXT_set_sprite_window(0,PLAYER_npc,NULL);    //blow into mic!! game turns on :)
						TEXT_window("I've played enough for now, I'll save the rest for later.<.>I should go see what's going on downstairs.");
					}
					else
					{

						TEXT_set_sprite_window(0,PLAYER_npc,NULL);
						TEXT_window("Alright, let's see if this helps.");
						HARDWARE_play_sound("cannedair",64,44100,0);
						nes_cleaned=1;
					}

				}

			}
		}
		else
		{
			if(ACTION_range_xy_xy(RANGE_TurnOnMES,"Turn off MES"))
			{
				nes_turned_on=0;

				while (BUTTON_ACTION_HELD&&MAIN_QUIT==false)
				{
					whilefix();
				}
			}
		}


		if(nes_cleaned&&GLOBAL_text_engine_state==0&&RAMIO_won==0&&GAME_playing_ramio==0)
		{
			//no bird sounds, no music, no car horns.

			GLOBAL_main_sprite_input_off=1;
			GLOBAL_main_sprite_standing=1;
			GLOBAL_main_sprite_actions_off=1;

			//yuu facing tv
			PLAYER_npc->MAP_x=14*8;
			PLAYER_npc->MAP_y=(8*8);
			PLAYER_npc->walk_dir=UP;
			NPC_animate_stand_dir(&PLAYER_npc, UP);


			//TODO: remove controller tile from desk

			//TODO: in brothers room, play consoles "i'd better not touch these, he's gonna know


			//TODO: holding controller, flashing light in front of tv



			nes_turned_on=0;

			CLOCK_paused=1;

			load_tv_fullscreen();


			HARDWARE_play_music("ramio",64);
			GAME_playing_ramio=1;





		}


		static int dad_rush_in=0;

		if(GAME_playing_ramio==0&&RAMIO_won==1&&dad_rush_in==0)
		{
			HARDWARE_play_music("chase",64);
			//play door sound
			HARDWARE_play_sound("doorsound",64,44100,0);
			dad_rush_in=1;
		}

		if(dad_rush_in==1)
		{

			//dad runs in the door
			if(dad_npc==NULL)
			{
				NPC_create_npc_xy_feet(&dad_npc,GFX_ADULT_dad, 16, 40,20*8,22*8);
			}

			if(dad_npc!=NULL)
			{

				static int cycle=0;

				if(cycle==0)
				{
					if(NPC_walk_to_xy_nohit(&dad_npc,SPEED_FAST,15*8,14*8))cycle=1;
				}
				if(cycle==1)
				{
					//dad face up

					NPC_animate_stand_dir(&dad_npc,UP);

					//yuu face down

					PLAYER_npc->walk_dir=DOWN;
					NPC_animate_stand_dir(&PLAYER_npc, DOWN);


					cycle=2;

				}
				if(cycle==2)
				{
						TEXT_set_sprite_window(0,dad_npc,NULL);
						TEXT_set_sprite_window(1,PLAYER_npc,NULL);
						TEXT_window("<NOCANCEL><HUGE>Yuu! Hey! Yuu!<.>"
									"<1><NORMAL>Uh oh.<.>"
									"<0><SMALL>*huff* <DELAY30>*gasp*<.>"
									"<NORMAL>That..<DELAY30> was that...<.>"
									"<1>Huh?<.>"
									"<0>Was that Yuu?!<.>"
									"<1>Eh?<.>"
									"<0><HUGE>Yuu!<.>"
									"Did Yuu play <YELLOW>PING<WHITE>?!<.>"
									"<1><SMALL><GRAY>Oh no....<NORMAL><WHITE><.>"
									"Sigh. <DELAY30>Yes, I did. I'm sorry. I won't do it again.<.>"
									"<0><HUGE>What?!<SHAKE1SEC> NO!<SHAKE1SEC><.>"
									"<NORMAL>Yuu has to! Yuu doesn't understand!<.>"
									"<1>What?<.>"
									"<0>That high score! Yuu beat that high score!<.>"
									"<1>Oh. I'm sorry I beat your score, Dad.<.>"
									"<0>MY score?! Yuu thinks that was MY score?!<.>"
									"That's the world record! Yuu beat it on the first try!<.>"
									"<1>So.. you're not mad at me?<.>"
									"<0>What?! I could never be mad at Yuu!<.>"
									"....<.>Oh, right. <.>I'm sorry.<.>It's not Yuu I'm mad at.<.>"
									"We're in a little bit of trouble.<.>Yuu shouldn't worry about it.<.>"
									"It's not...<DELAY30> It's no big... <DELAY30> ...<.>"
									"<SMALL><GRAY><DELAY30>*sob*<SHAKE1SEC><WHITE><NORMAL><.><BOB>We're totally screwed!<NORMAL><SHAKE1SEC><.>"
									"I don't know what to do!<.>There's nothing I can do!<.>"
									"But... <DELAY30>Yuu!<SHAKE1SEC> Yuu can save us! <DELAY30>Yuu has to save us!<SHAKE1SEC><.>"
									"Yuu can do it! I know Yuu can!"
						);

					cycle=3;
				}
				if(cycle==3&&GLOBAL_text_engine_state==0)
				{
					cycle=4;

					load_bob_scene_3();
					return;
				}

			}

		}
	}

//=====================
//ACTIONS
//=====================

	if(sleeping==6)
	{

		if(ACTION_range_xy_xy(RANGE_YUUYuusRoomToUpstairs,"Leave Room"))
		{
			TEXT_set_sprite_window(0,PLAYER_npc,NULL);
			TEXT_window("I have to turn off that alarm!");
		}
	}
	else
	{
		if(walking_into_door(RANGE_YUUYuusRoomToUpstairs))
		{
			MAP_change_map(MAP_bobsgame_TOWNYUUUpstairs,49,9);
			return;
		}
	}

}

void bobsgame_TOWNYUUUpstairsYuusRoom_Map_Stop_Function()
{
	tv_npc=NULL;
	NPC_delete_all_npcs();
	CLOCK_paused=0;
}

void bobsgame_TOWNYUUUpstairsYuusRoom_Map_VBL_Function()
{

}

void bobsgame_TOWNYUUUpstairsYuusRoom_Map_HBL_Function()
{

}

///===============================================================================================================================================================================================
//YUUUpstairsBabyRoom
///===============================================================================================================================================================================================
void bobsgame_TOWNYUUUpstairsBabyRoom_Map_Load_Function()
{
//RANGE_YUUBabyRoomToUpstairs 7*8,8*8,11*8,9*8
}

void bobsgame_TOWNYUUUpstairsBabyRoom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}


CLOCK_paused=1;


if(littlebro_npc==NULL)
{


	NPC_create_npc_xy_feet(&littlebro_npc,GFX_KID_littlebrother, 16, 32,12*8, 18*8);
	NPC_animate_stand_dir(&littlebro_npc,DOWN);

}

static int done=0;
if(littlebro_npc!=NULL)
{

	if(ACTION_npc(&littlebro_npc,"Talk To Little Brother")&&GLOBAL_text_engine_state==0)
	{

		if(ITEM_have(&SuperGlue)&&ITEM_have(&ElectricToothbrush)&&ITEM_have(&CoatHanger))
		{

			TEXT_set_sprite_window(0,PLAYER_npc,NULL);
			TEXT_set_sprite_window(1,littlebro_npc,NULL);
			TEXT_window("<1>Good.<.>Here.<.>Get Out.<.>"
			);
			done=1;
		}
		else
		if(done==0)
		{

			TEXT_set_sprite_window(0,PLAYER_npc,NULL);
			TEXT_set_sprite_window(1,littlebro_npc,NULL);
			TEXT_window("Hey, uh. Whatcha reading?<.>"
						"<1>Advanced Mechanical Engineering Volume 3.<.>"
						"<0>Uh... Sounds exciting.<.>"
						"<1>I'm reading. Will Yuu leave me alone, please?<.>"
						"<0>Yeah, I just needed some advice on how to unlock a door.<.>"
						"<1>Bring me an agitator, adhesive, and a slim, rigid wire.<.>"
						"<0>Right."
						);
		}
		else
		if(done==2)
		{
			TEXT_set_sprite_window(0,PLAYER_npc,NULL);
			TEXT_set_sprite_window(1,littlebro_npc,NULL);
			TEXT_window("<1>Get Out.<.>Please.<.>"
						"<0>Okay. Thanks."
			);
		}
	}


if(done==1&&GLOBAL_text_engine_state==0)
{

ITEM_remove(&SuperGlue);
ITEM_remove(&CoatHanger);
ITEM_remove(&ElectricToothbrush);
ITEM_get(&LockPick);

	done=2;
}





}



//some kid, never mention him.
//hey, can i have that ???
//always reading "i'm reading, leave me alone"
//books pile up
//books: basic mathematics
//basic physics
//model rockets
//economics
//investing
//mutual funds
//space: a primer
//advanced mathematics
//circuit design 101
//the complete works of albert einstein
//time travel
//quantum mechanics
//package for ??? the writings blurred "oh thats mine" comes downstairs
//building something
//room full of wires
//room full of tubes
//the door wont open
//completely empty room, sandwich crusts?
//materializes somewhere, teenager steps out, hands you something vital, thanks for the ???, i think you need this
//=====================
//ACTIONS
//=====================
	if(walking_into_door(RANGE_YUUBabyRoomToUpstairs))
	{
		MAP_change_map(MAP_bobsgame_TOWNYUUUpstairs,36,15);
		return;
	}
}

void bobsgame_TOWNYUUUpstairsBabyRoom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
	CLOCK_paused=0;
}

void bobsgame_TOWNYUUUpstairsBabyRoom_Map_VBL_Function()
{

}

void bobsgame_TOWNYUUUpstairsBabyRoom_Map_HBL_Function()
{

}

///===============================================================================================================================================================================================
//YUUUpstairsBrothersRoom
///===============================================================================================================================================================================================
void bobsgame_TOWNYUUUpstairsBrothersRoom_Map_Load_Function()
{
//RANGE_YUUBrothersRoomToUpstairs 24*8,22*8,28*8,23*8
}

void bobsgame_TOWNYUUUpstairsBrothersRoom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

CLOCK_paused=1;

//==============================================================================================================================
//YUUUpstairsBrothersRoom MAP RUN
//==============================================================================================================================
//usually locked, unless hes home
//if hes home, hes in his chair playing wii
//at midnight, locked again.
	//brother in chair at 17,14 facing up
	//tv screen at 16,16 3 x 2
	if(CLOCK_hour>0&&CLOCK_hour<2)//midnight to 2 am=====================================================================================================
	{
		//1:00 kicked out
	}

	if(CLOCK_hour>=12+10&&CLOCK_hour<24)//10 pm to 12 am=====================================================================================================
	{
		//11:57 allowed in
	}


	static int getair=0;


	if(ACTION_range_xy_xy(16*8,10*8,20*8,12*8,"Look At Shelf"))
	{

		if(getair==0)
		{
			TEXT_set_sprite_window(0,PLAYER_npc,NULL);
			TEXT_window("<0>Let's see...<.>Cleaning supplies...<.>Ah! Perfect!<.>This is exactly what I need."
			);
			getair=1;
		}
		else
		if(getair==2)
		{
			TEXT_set_sprite_window(0,PLAYER_npc,NULL);
			TEXT_window("<0>There's nothing else I want.<.>He's going to notice if I take any of his games.<.>Maybe some other time."
			);

		}
	}


	if(getair==1&&GLOBAL_text_engine_state==0)
	{
		getair=2;
		ITEM_get(&CannedAir);
	}


	//=====================
//ACTIONS
//=====================
	if(walking_into_door(RANGE_YUUBrothersRoomToUpstairs))
	{
		MAP_change_map(MAP_bobsgame_TOWNYUUUpstairs,26,9);
		return;
	}
}

void bobsgame_TOWNYUUUpstairsBrothersRoom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
	CLOCK_paused=0;
}

void bobsgame_TOWNYUUUpstairsBrothersRoom_Map_VBL_Function()
{

}

void bobsgame_TOWNYUUUpstairsBrothersRoom_Map_HBL_Function()
{

}

///===============================================================================================================================================================================================
//YUUUpstairsBathroom
///===============================================================================================================================================================================================
void bobsgame_TOWNYUUUpstairsBathroom_Map_Load_Function()
{
//RANGE_YUUUpstairsBathroomToUpstairs 7*8,8*8,11*8,9*8
}

void bobsgame_TOWNYUUUpstairsBathroom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

CLOCK_paused=1;


if(CLOCK_hour>=12+6&&CLOCK_hour<12+8)
{

	static int gottoothbrush=0;

	if(gottoothbrush==0)
	{


		if(ACTION_range_xy_xy(11*8,9*8,13*8,12*8,"Take Electric Toothbrush"))
		{

			gottoothbrush=1;
		}

	}
	else
	if(gottoothbrush==1)
	{
		if(GLOBAL_text_engine_state==0)
		{
			ITEM_get(&ElectricToothbrush);
			gottoothbrush=2;
		}
	}
}






//locked medicine cabinet at 12,12
//pills
//use toilet to relieve stats	12,21 12,20
//use shower to improve smell	6,13-6,21
//=====================
//ACTIONS
//=====================
	if(walking_into_door(RANGE_YUUUpstairsBathroomToUpstairs))
	{
		MAP_change_map(MAP_bobsgame_TOWNYUUUpstairs,54,15);
		return;
	}
}

void bobsgame_TOWNYUUUpstairsBathroom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
	CLOCK_paused=0;
}

void bobsgame_TOWNYUUUpstairsBathroom_Map_VBL_Function()
{

}

void bobsgame_TOWNYUUUpstairsBathroom_Map_HBL_Function()
{

}

///===============================================================================================================================================================================================
//YUUUpstairsParentsRoom
///===============================================================================================================================================================================================
void bobsgame_TOWNYUUUpstairsParentsRoom_Map_Load_Function()
{
//RANGE_YUUParentsRoomToUpstairs 4*8,8*8,8*8,9*8
//sometimes mom is here crying
//sometimes mom is passed out on the bed
//sometimes tv is on
//sometimes dad and mom are here
}

void bobsgame_TOWNYUUUpstairsParentsRoom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//==============================================================================================================================
//YUUUpstairsYuusRoom MAP RUN
//==============================================================================================================================
	//tv at 14,6 3x2
	if(CLOCK_hour>0&&CLOCK_hour<6)//midnight to 6 am=====================================================================================================
	{
		//parents sleeping
	}

	if(CLOCK_hour>=6&&CLOCK_hour<7)//6 am to 7 am=====================================================================================================
	{
		CLOCK_paused=1;
	}

	if(CLOCK_hour>=7&&CLOCK_hour<8)//7 am to 8 am=====================================================================================================
	{
		CLOCK_paused=1;
	}

	if(CLOCK_hour>=8&&CLOCK_hour<10)//8 am to 10 am=====================================================================================================
	{

	}

	if(CLOCK_hour>=10&&CLOCK_hour<12)//10 am to 12 pm=====================================================================================================
	{

	}

	if(CLOCK_hour>=12&&CLOCK_hour<12+2)//12 am to 2 pm=====================================================================================================
	{

	}

	if(CLOCK_hour>=12+2&&CLOCK_hour<12+4)//2 pm to 4 pm=====================================================================================================
	{
CLOCK_paused=1;
	}

	if(CLOCK_hour>=12+4&&CLOCK_hour<12+6)//4 pm to 6 pm=====================================================================================================
	{
CLOCK_paused=1;
	}

	if(CLOCK_hour>=12+6&&CLOCK_hour<12+8)//6 pm to 8 pm=====================================================================================================
	{
			CLOCK_paused=1;


			static int gothanger=0;

			if(gothanger==0)
			{


				if(ACTION_range_xy_xy(3*8,18*8,7*8,20*8,"Look in Closet"))
				{
					TEXT_set_sprite_window(0,PLAYER_npc,NULL);
					TEXT_window("Just shoeboxes and hangers. Nothing special.<.>"
								"I guess I'll take a hanger."
								);
					gothanger=1;
				}

			}
			else
			if(gothanger==1)
			{
				if(GLOBAL_text_engine_state==0)
				{
					ITEM_get(&CoatHanger);
					gothanger=2;
				}
			}


	}

	if(CLOCK_hour>=12+8&&CLOCK_hour<12+10)//8 pm to 10 pm=====================================================================================================
	{
CLOCK_paused=1;
	}

	if(CLOCK_hour>=12+10&&CLOCK_hour<24)//10 pm to 12 am=====================================================================================================
	{
CLOCK_paused=1;
	}





	//=====================
//ACTIONS
//=====================
	if(walking_into_door(RANGE_YUUParentsRoomToUpstairs))
	{
		MAP_change_map(MAP_bobsgame_TOWNYUUUpstairs,13,15);
		return;
	}
}

void bobsgame_TOWNYUUUpstairsParentsRoom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
	CLOCK_paused=0;
}

void bobsgame_TOWNYUUUpstairsParentsRoom_Map_VBL_Function()
{

}

void bobsgame_TOWNYUUUpstairsParentsRoom_Map_HBL_Function()
{

}

///===============================================================================================================================================================================================
//YUUBasement
///===============================================================================================================================================================================================
void bobsgame_TOWNYUUBasement_Map_Load_Function()
{
//RANGE_YUUBasementToDownstairs 3*8,8*8,7*8,9*8
}

void bobsgame_TOWNYUUBasement_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//==============================================================================================================================
//YUUBASEMENTYuusRoom MAP RUN
//==============================================================================================================================
	//if sunday, mom doing laundry
	//washing machine noise
	if(CLOCK_hour>0&&CLOCK_hour<6)//midnight to 6 am=====================================================================================================
	{
		CLOCK_paused=1;
	}

	if(CLOCK_hour>=6&&CLOCK_hour<7)//6 am to 7 am=====================================================================================================
	{
		CLOCK_paused=1;
	}

	if(CLOCK_hour>=7&&CLOCK_hour<8)//7 am to 8 am=====================================================================================================
	{
		CLOCK_paused=1;
	}

	if(CLOCK_hour>=8&&CLOCK_hour<10)//8 am to 10 am=====================================================================================================
	{

	}

	if(CLOCK_hour>=10&&CLOCK_hour<12)//10 am to 12 pm=====================================================================================================
	{

	}

	if(CLOCK_hour>=12&&CLOCK_hour<12+2)//12 am to 2 pm=====================================================================================================
	{

	}

	if(CLOCK_hour>=12+2&&CLOCK_hour<12+4)//2 pm to 4 pm=====================================================================================================
	{
CLOCK_paused=1;
	}

	if(CLOCK_hour>=12+4&&CLOCK_hour<12+6)//4 pm to 6 pm=====================================================================================================
	{
		CLOCK_paused=1;
	}

	if(CLOCK_hour>=12+6&&CLOCK_hour<12+8)//6 pm to 8 pm=====================================================================================================
	{
		CLOCK_paused=1;
	}

	if(CLOCK_hour>=12+8&&CLOCK_hour<12+10)//8 pm to 10 pm=====================================================================================================
	{
		CLOCK_paused=1;
	}

	if(CLOCK_hour>=12+10&&CLOCK_hour<24)//10 pm to 12 am=====================================================================================================
	{
		CLOCK_paused=1;
	}

	//=====================
//ACTIONS
//=====================
	if(walking_into_door(RANGE_YUUBasementToDownstairs))
	{
		MAP_change_map(MAP_bobsgame_TOWNYUUDownstairs,5,14);
		return;
	}
}

void bobsgame_TOWNYUUBasement_Map_Stop_Function()
{
	NPC_delete_all_npcs();
	CLOCK_paused=0;
}

void bobsgame_TOWNYUUBasement_Map_VBL_Function()
{

}

void bobsgame_TOWNYUUBasement_Map_HBL_Function()
{

}

///===============================================================================================================================================================================================
//YUUGarage
///===============================================================================================================================================================================================
void bobsgame_TOWNYUUGarage_Map_Load_Function()
{
//RANGE_YUUGarageToDownstairs 25*8,10*8,26*8,14*8
//RANGE_YUUGarageToAttic 4*8,10*8,8*8,11*8
}

void bobsgame_TOWNYUUGarage_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

	static NPC* garagecar_npc = NULL;
	static NPC* garagetruck_npc = NULL;

	CLOCK_paused=1;



	if(CLOCK_hour<6||(CLOCK_hour==6&&CLOCK_minute<30)||CLOCK_hour>=12+6)
	{
		// car npc

		if(garagecar_npc==NULL)
		{
			NPC_create_npc(&garagecar_npc,GFX_CAR_car,64,64,13*8,14*8);

			garagecar_npc->randomcolorset[0]=1;
			NPC_set_car_anim_frame_now(&garagecar_npc,UP);
			garagecar_npc->non_walkable=1;
			garagecar_npc->animation_off=1;
			garagecar_npc->scale=1.5f;
		}
	}


	if(CLOCK_hour<12+4||(CLOCK_hour>12+10)||(CLOCK_hour==10&&CLOCK_minute>=15))
	{
		// car npc
		if(garagetruck_npc==NULL)
		{
			NPC_create_npc(&garagetruck_npc,GFX_CAR_truck,64,64,5*8,11*8-4);

			garagetruck_npc->randomcolorset[0]=2;
			NPC_set_car_anim_frame_now(&garagetruck_npc,UP);
			garagetruck_npc->non_walkable=1;
			garagetruck_npc->animation_off=1;
			garagetruck_npc->scale=1.5f;
		}
	}



//sometimes car is here	2 cars?
//attic stairs down/up
//=====================
//ACTIONS
//=====================
	if(walking_into_door(RANGE_YUUGarageToDownstairs))
	{
		MAP_change_map(MAP_bobsgame_TOWNYUUDownstairs,2,11);
		return;
	}

	if(ACTION_range_xy_xy(RANGE_YUUGarageToAttic, "Go in Attic"))
	{
		MAP_change_map(MAP_bobsgame_TOWNYUUAttic,5,12);
		return;
	}
}

void bobsgame_TOWNYUUGarage_Map_Stop_Function()
{
	NPC_delete_all_npcs();
	CLOCK_paused=0;
}

void bobsgame_TOWNYUUGarage_Map_VBL_Function()
{

}

void bobsgame_TOWNYUUGarage_Map_HBL_Function()
{

}

///===============================================================================================================================================================================================
//YUUAttic
///===============================================================================================================================================================================================
void bobsgame_TOWNYUUAttic_Map_Load_Function()
{
//RANGE_YUUAtticToGarage 4*8,14*8,7*8,15*8
}

void bobsgame_TOWNYUUAttic_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}



	CLOCK_paused=1;



static int stage=0;
//get coat hanger from attic
if(stage==0)
{
	TEXT_set_sprite_window(0,PLAYER_npc,NULL);
	TEXT_window("Wow! I've never been up here before! I bet there's something cool in here!");
	stage=1;
}

if(stage==1&&GLOBAL_text_engine_state==0)
{

	if(ACTION_range_xy_xy(9*8,19*8,12*8,21*8,"Look through boxes"))
	{
		stage=2;
	}

}

if(stage==2)
{
		//turn off sprite controls
		GLOBAL_main_sprite_input_off=1;
		GLOBAL_main_sprite_actions_off=1;

		HARDWARE_play_music("tetrid_doublespeed",32);
		stage=3;
}

if(stage==3)
{

	//move npc from box to box while increasing clock time


		//turn on clock time
		CLOCK_paused=0;

static int cycle=0;

if(cycle==0)
{
//18,19, up

	PLAYER_npc->MAP_x=18*8;
	PLAYER_npc->MAP_y=17*8;
	PLAYER_npc->walk_dir=UP;
	NPC_animate_stand_dir(&PLAYER_npc, UP);

if(PLAYER_npc->vbls>5){cycle=r(5);PLAYER_npc->vbls=0;}
}
else
if(cycle==1)
{
	PLAYER_npc->MAP_x=20*8;
	PLAYER_npc->MAP_y=20*8;
	PLAYER_npc->walk_dir=RIGHT;
	NPC_animate_stand_dir(&PLAYER_npc, RIGHT);

if(PLAYER_npc->vbls>5){cycle=r(5);PLAYER_npc->vbls=0;}
}
else
if(cycle==2)
{
//20,20,right
	PLAYER_npc->MAP_x=22*8;
	PLAYER_npc->MAP_y=12*8;
	PLAYER_npc->walk_dir=DOWN;
	NPC_animate_stand_dir(&PLAYER_npc, DOWN);
if(PLAYER_npc->vbls>5){cycle=r(5);PLAYER_npc->vbls=0;}
}
else
if(cycle==3)
{
	PLAYER_npc->MAP_x=9*8;
	PLAYER_npc->MAP_y=11*8;
	PLAYER_npc->walk_dir=RIGHT;
	NPC_animate_stand_dir(&PLAYER_npc, RIGHT);

if(PLAYER_npc->vbls>5){cycle=r(5);PLAYER_npc->vbls=0;}
}
else
if(cycle==4)
{
	PLAYER_npc->MAP_x=16*8;
	PLAYER_npc->MAP_y=13*8;
	PLAYER_npc->walk_dir=LEFT;
	PLAYER_npc->layer=1;
	NPC_animate_stand_dir(&PLAYER_npc, LEFT);

if(PLAYER_npc->vbls>5){cycle=r(5);PLAYER_npc->vbls=0;}
}




	if(!(CLOCK_hour==12+5&&CLOCK_minute==55))
	{
		static int v=0;
		if(vbl_var!=v)
		{
			v=vbl_var;

			CLOCK_minute++;
			CLOCK_moving=true;
			CLOCK_update_clock();
		}

	}
	else
	stage=4;




}

if(stage==4)
{

	PLAYER_npc->MAP_x=8*8;
	PLAYER_npc->MAP_y=14*8;
	PLAYER_npc->walk_dir=RIGHT;
	NPC_animate_stand_dir(&PLAYER_npc, RIGHT);


		//clock off
		CLOCK_paused=1;

		TEXT_set_sprite_window(0,PLAYER_npc,NULL);
		TEXT_window("Well, there's nothing useful.<.>"
					"Mostly bowling shoes and umbrellas.<.>"
					"I did find some Super Glue though."
					);

HARDWARE_play_music("nice",32);
		stage=5;
}

if(stage==5&&GLOBAL_text_engine_state==0)
{
	ITEM_get(&SuperGlue);
	GLOBAL_main_sprite_input_off=0;
	GLOBAL_main_sprite_actions_off=0;
	stage=6;
}


//cant go upstairs








//=====================
//ACTIONS
//=====================
	if(walking_into_door(RANGE_YUUAtticToGarage))
	{
		MAP_change_map(MAP_bobsgame_TOWNYUUGarage,5,11);
		return;
	}
}

void bobsgame_TOWNYUUAttic_Map_Stop_Function()
{
	NPC_delete_all_npcs();
	CLOCK_paused=0;
}

void bobsgame_TOWNYUUAttic_Map_VBL_Function()
{

}

void bobsgame_TOWNYUUAttic_Map_HBL_Function()
{

}

///===============================================================================================================================================================================================
//YUUDownstairsBathroom
///===============================================================================================================================================================================================
void bobsgame_TOWNYUUDownstairsBathroom_Map_Load_Function()
{
//RANGE_YUUDownstairsBathroomToDownstairs 4*8,17*8,8*8,18*8
//RANGE_YUUMirrorEffect 6*8,11*8,11*8,13*8
//DO SPRITE MIRRORING ABOVE LAYER 3
}

void bobsgame_TOWNYUUDownstairsBathroom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}


CLOCK_paused=1;


//mirror effect
//use toilet to relieve stats
//=====================
//ACTIONS
//=====================
	if(walking_into_door(RANGE_YUUDownstairsBathroomToDownstairs))
	{
		MAP_change_map(MAP_bobsgame_TOWNYUUDownstairs,28,36);
		return;
	}

	if(walking_into_door(RANGE_YUUMirrorEffect))
	{
		//MIRROR EFFECT
	}
}

void bobsgame_TOWNYUUDownstairsBathroom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
	CLOCK_paused=0;
}

void bobsgame_TOWNYUUDownstairsBathroom_Map_VBL_Function()
{

}

void bobsgame_TOWNYUUDownstairsBathroom_Map_HBL_Function()
{

}



