//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================



#include "../../main.h"



NPC* batterynpc=NULL;
int battery_quest=0;

NPC* tv_npc=NULL;
NPC* sparks_npc=NULL;


CAPTION* boxcaption = NULL;



#define RANGE_INTRODownstairsToUpstairs 2*8,26*8,8*8,27*8
#define RANGE_INTRODownstairsToBasement 3*8,15*8,7*8,16*8
#define RANGE_INTRODownstairsToDownstairsBathroom 27*8,35*8,31*8,36*8
#define RANGE_INTRODownstairsToGarage 1*8,10*8,2*8,14*8
#define RANGE_INTRODownstairsToINTROOUTSIDEBackyard 30*8,8*8,34*8,9*8
#define RANGE_box1 24*8,40*8,27*8,42*8
#define RANGE_box2 32*8,36*8,35*8,38*8
#define RANGE_box3 34*8,40*8,36*8,42*8
#define RANGE_box4 37*8,37*8,40*8,40*8
#define RANGE_box5 37*8,31*8,38*8,35*8
#define RANGE_box6 56*8,26*8,57*8,28*8
#define RANGE_box7 36*8,12*8,38*8,14*8
#define RANGE_box8 41*8,29*8,43*8,31*8
#define RANGE_box9 45*8,27*8,47*8,30*8
#define RANGE_box10 51*8,27*8,53*8,30*8
#define RANGE_box11 48*8,27*8,50*8,31*8
#define RANGE_box12 14*8,16*8,17*8,18*8
#define RANGE_box13 19*8,17*8,22*8,19*8
#define RANGE_box14 21*8,14*8,24*8,16*8
#define RANGE_box15 30*8,20*8,32*8,21*8
#define RANGE_box16 56*8,14*8,58*8,17*8
#define RANGE_INTROUpstairsToUpstairsBathroom 52*8,16*8,56*8,17*8
#define RANGE_INTROUpstairsToParentsRoom 11*8,16*8,15*8,17*8
#define RANGE_INTROUpstairsToBabyRoom 34*8,16*8,38*8,17*8
#define RANGE_INTROUpstairsToYuusRoom 47*8,8*8,51*8,9*8
#define RANGE_INTROUpstairsToBrothersRoom 24*8,8*8,28*8,9*8
#define RANGE_INTROUpstairsToDownstairs 2*8,21*8,8*8,24*8
#define RANGE_box17 17*8,9*8,19*8,11*8
#define RANGE_box18 18*8,14*8,21*8,16*8
#define RANGE_box19 24*8,14*8,26*8,16*8
#define RANGE_box20 40*8,13*8,43*8,16*8
#define RANGE_box21 43*8,9*8,46*8,11*8
#define RANGE_INTROYuusRoomToUpstairs 18*8,22*8,22*8,23*8
#define RANGE_box22 2*8,11*8,31*8,15*8
#define RANGE_INTROBabyRoomToUpstairs 7*8,8*8,11*8,9*8
#define RANGE_box23 3*8,9*8,5*8,12*8
#define RANGE_INTROBrothersRoomToUpstairs 24*8,22*8,28*8,23*8
#define RANGE_box24 24*8,12*8,27*8,14*8
#define RANGE_box25 22*8,10*8,24*8,11*8
#define RANGE_INTROUpstairsBathroomToUpstairs 7*8,8*8,11*8,9*8
#define RANGE_box26 7*8,15*8,10*8,17*8
#define RANGE_box27 7*8,17*8,9*8,19*8
#define RANGE_INTROParentsRoomToUpstairs 4*8,8*8,8*8,9*8
#define RANGE_box28 2*8,12*8,5*8,13*8
#define RANGE_INTROBasementToDownstairs 3*8,8*8,7*8,9*8
#define RANGE_box29 10*8,33*8,13*8,36*8
#define RANGE_box30 19*8,25*8,21*8,27*8
#define RANGE_box31 23*8,25*8,25*8,27*8
#define RANGE_box32 21*8,34*8,23*8,36*8
#define RANGE_box33 31*8,33*8,34*8,36*8
#define RANGE_box34 31*8,27*8,33*8,30*8
#define RANGE_box35 41*8,27*8,44*8,30*8
#define RANGE_box36 34*8,20*8,37*8,22*8
#define RANGE_box37 39*8,21*8,41*8,23*8
#define RANGE_box38 44*8,20*8,47*8,22*8
#define RANGE_box39 55*8,32*8,57*8,33*8
#define RANGE_INTROGarageToDownstairs 25*8,10*8,26*8,14*8
#define RANGE_INTROGarageToAttic 4*8,10*8,8*8,11*8
#define RANGE_box40 16*8,16*8,19*8,18*8
#define RANGE_box41 9*8,14*8,10*8,16*8
#define RANGE_box42 15*8,11*8,18*8,13*8
#define RANGE_box43 18*8,9*8,21*8,11*8
#define RANGE_box44 22*8,26*8,23*8,27*8
#define RANGE_box45 22*8,21*8,25*8,22*8
#define RANGE_box46 22*8,23*8,23*8,25*8
#define RANGE_box47 16*8,26*8,19*8,29*8
#define RANGE_box48 8*8,23*8,11*8,25*8
#define RANGE_box49 14*8,26*8,15*8,29*8
#define RANGE_box50 11*8,24*8,14*8,26*8
#define RANGE_box51 5*8,26*8,8*8,28*8
#define RANGE_INTRODownstairsBathroomToDownstairs 4*8,17*8,8*8,18*8
#define RANGE_INTROMirrorEffect 6*8,11*8,11*8,13*8
#define RANGE_box52 2*8,11*8,4*8,12*8
#define RANGE_INTROAtticToGarage 4*8,14*8,7*8,15*8

//========================================================
//INTRODownstairs
//========================================================
void bobsgame_INTRODownstairs_Map_Load_Function()
{
//RANGE_INTRODownstairsToUpstairs 2*8,26*8,8*8,27*8
//RANGE_INTRODownstairsToBasement 3*8,15*8,7*8,16*8
//RANGE_INTRODownstairsToDownstairsBathroom 27*8,35*8,31*8,36*8
//RANGE_INTRODownstairsToGarage 1*8,10*8,2*8,14*8
//RANGE_INTRODownstairsToINTROOUTSIDEBackyard 30*8,8*8,34*8,9*8
//RANGE_box1 24*8,40*8,27*8,42*8
//RANGE_box2 32*8,36*8,35*8,38*8
//RANGE_box3 34*8,40*8,36*8,42*8
//RANGE_box4 37*8,37*8,40*8,40*8
//RANGE_box5 37*8,31*8,38*8,35*8
//RANGE_box6 56*8,26*8,57*8,28*8
//RANGE_box7 36*8,12*8,38*8,14*8
//RANGE_box8 41*8,29*8,43*8,31*8
//RANGE_box9 45*8,27*8,47*8,30*8
//RANGE_box10 51*8,27*8,53*8,30*8
//RANGE_box11 48*8,27*8,50*8,31*8
//RANGE_box12 15*8,15*8,16*8,16*8
//RANGE_box13 19*8,17*8,22*8,19*8
//RANGE_box14 21*8,14*8,24*8,16*8
//RANGE_box15 30*8,20*8,32*8,21*8
//RANGE_box16 56*8,14*8,58*8,17*8
	//dad playing ping
	//mom unpacking boxes

	if(battery_quest<4)
	{
		HARDWARE_play_music("g65_theme",32);
	}


}


void bobsgame_INTRODownstairs_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}
	if(mom_npc==NULL)
	{
		NPC_create_npc_xy_feet(&mom_npc,GFX_ADULT_youngmom, 16, 40,19*8,12*8);
		mom_npc->non_walkable=1;
	}
	static NPC* pingcontrollernpc=NULL;
	if(pingcontrollernpc==NULL)
	{
		NPC_create_npc(&pingcontrollernpc,GFX_MISC_pingcontroller,32,64,48*8,33*8);
	}



	if(GLOBAL_text_engine_state!=0&&(TEXT_textbox[0].sprite_window_npc==mom_npc||TEXT_textbox[1].sprite_window_npc==mom_npc))NPC_stare_at_npc(&PLAYER_npc,&mom_npc);



	if(mom_flag==0)if(NPC_walk_to_xy_nohit(&mom_npc, SPEED_SLOWEST, 15*8, 14*8)==(1)){NPC_animate_stand_dir(&mom_npc, DOWN);mom_npc->vbls=0;mom_flag++;}
	if(mom_flag==1)if(mom_npc->vbls>60)mom_flag++;	//TODO: shuffling noises?
	if(mom_flag==2)if(NPC_walk_to_xy_nohit(&mom_npc, SPEED_SLOWEST, 12*8, 12*8)==(1)){NPC_animate_stand_dir(&mom_npc, UP);mom_npc->vbls=0;mom_flag++;} //TODO: cupboard sound
	if(mom_flag==3)if(mom_npc->vbls>120)mom_flag++;
	if(mom_flag==4)if(NPC_walk_to_xy_nohit(&mom_npc, SPEED_SLOWEST, 15*8, 14*8)==(1)){NPC_animate_stand_dir(&mom_npc, DOWN);mom_npc->vbls=0;mom_flag++;}
	if(mom_flag==5)if(mom_npc->vbls>60)mom_flag++;	//TODO: shuffling noises
	if(mom_flag==6)if(NPC_walk_to_xy_nohit(&mom_npc, SPEED_SLOWEST, 23*8, 12*8)==(1)){NPC_animate_stand_dir(&mom_npc, UP);mom_npc->vbls=0;mom_flag++;} //TODO: drawer noise
	if(mom_flag==7)if(mom_npc->vbls>120)mom_flag=0;
	if(ACTION_npc(&mom_npc,"Talk To Mom")&&GLOBAL_text_engine_state==0)
	{
		TEXT_set_sprite_window(0,mom_npc,NULL);
		TEXT_set_sprite_window(1,PLAYER_npc,NULL);
		if(battery_quest==0)
		{
			TEXT_window("<NOCANCEL>Hey there, champ. Finished unpacking?<.>"
						"<1>Yeah. Can I go outside now?<.>"
						"<0>I guess so, if <PURPLE>Yuu<WHITE> finished.<.>"
						"<1>Alright!<.>"
						"<0>Oh, wait. I changed my mind.<.>"
						"Find something for me.<.>"
						"<1>*sigh*<.>"
						"<0>I need some <RED>batteries.<WHITE> Go find some for me.<.>"
						"I think I saw some in the garage.<.>"
						"Or maybe the basement.<.>"
						"Somewhere, anyway. Hurry up!");
			battery_quest=1;
		}
		else
		if(battery_quest>0&&battery_quest<6)
		TEXT_window("Did <PURPLE>Yuu<WHITE> find the <RED>batteries<WHITE> yet? <.>"
					"Maybe I saw them in the basement... <.>"
					"And tell your <RED>GFX_KID_brother<WHITE> to turn that volume down, I can hear it from all the way down here.");
		else
		if(battery_quest==6)
		{
			TEXT_window("Did <PURPLE>Yuu<WHITE> find the <RED>batteries<WHITE> yet? <.>"
					"<1>Almost!<.>"
					"<0>Good! Thanks for telling your brother to turn the volume down. It's much better now.<.>"
					"<1>No problem!<.>"
					);

		}

		if(battery_quest==7)
		{
			TEXT_window("<NOCANCEL><1>I found them.<.>"
						"<0>Oh! Great! I knew they were in the garage!<.>"
						"<1>Yeah...<.>So what did you need them for, anyway?<.>"
						"<0>Here. I found this when I was unpacking.<.>"
						"<1>Is that a <BLUE>GameToy<WHITE>? Wow, ancient.<.>"
						"<0>It's from when <PURPLE>Yuu<WHITE> was born.<.>"
						"<1>What?<.>"
						"<0>Yeah...<PAUSE>Um...<PAUSE>We're still not entirely sure how.. <PAUSE>nevermind.<.>"
						"It must have been some kind of prank.<.>"
						"Anyway, let's see if it works.");
			battery_quest=8;
		}
		else
		if(battery_quest==11||battery_quest==12)
		{
			TEXT_window("Isn't technology wonderful? I feel so much better!<.>"
						"Go make a new friend!<.>"
						"<1>Is this even going to work?<.>"
						"<0>Of course it will, honey! Just be yourself and smile.<.>"
						"And if that doesn't work, say your uncle owns an amusement park.");
			battery_quest=12;
		}
	}



	if(battery_quest==8&&GLOBAL_text_engine_state==0)
	{
		HARDWARE_play_sound("gtbling",127,44100,0);
		ITEM_remove(&Batteries);
		load_gametoy_broken();
		TEXT_window("<NOCANCEL>*bling*<DELAY1SEC> Great! It works!<.>"
					"Oh. Well, sort of.<.>"
					"Hold on, let's try again.<.>"
					);
		battery_quest=9;
	}


	if(battery_quest==9&&GLOBAL_text_engine_state==0)
	{


		unload_gametoy_broken();
		HARDWARE_play_sound("gtbling",127,44100,0);
		load_gametoy();

		TEXT_window("<NOCANCEL>*bling*<DELAY1SEC> There we go.<.>"
					"I've got a plan. I saw a kid next door about your age, I bet <PURPLE>Yuu<WHITE> and him could be friends!<.>"
					"<1>...<.>"
					"<0>These things link together, right? Just play a game against him, and <PURPLE>Yuu<WHITE> will be friends!<.>"
					"<1>I don't... think it works that way.<PAUSE><NEXTLINE>And besides, what makes you think he'll have one?<.>"
					"<0>Of course he will! They sold more of these than the actual population, every person has at least two or three.<.>"
					"If he says he doesn't have one, just tell him to look in his closet. He'll find one!<.>"
					"<1>Uhh.. Sure.<.>"
					"Ok, whatever. So I can go outside now?<.>"
					"<0>*Sigh* I suppose so. Only if <PURPLE>Yuu<WHITE> stays nearby. I don't want <PURPLE>Yuu<WHITE> to get lost!<.>"
					"<1>I won't. I'm only going next door, remember?<.>"
					"<0>Promise?<.>"
					"<1>Promise.<.>"
					"<0>Alright, I trust <PURPLE>Yuu.<WHITE><.>"
					"Come here.<.>"
					"<1>?<.>"
					"<0>*Snap* There.<.>"
					"Just to be sure, I went ahead and ordered this off of the <PINK>Overprotective Mothers Daytime Talk Show.<WHITE><.>"
					"It's like an electric dog leash, but for your precious children!<.>"
					"<1>What?! That's ridiculous!<.>"
					"<0>I know! Totally rad, right?<.>"
					"<1>I mean it's absurd.<.>"
					"<0>Right on! I knew <PURPLE>Yuu<WHITE> would like it!<.>"
					"Now if <PURPLE>Yuu<WHITE> tries to walk too far, <PURPLE>Yuu<WHITE> will get electrocuted with a paralyzing shock.<.>"
					"Doesn't <PURPLE>Yuu<WHITE> feel much safer now?<.>"
					"<1>No. Not at all.<.>"
					"Please take this off of me.<.>"
					"<0>Ohohoho! <PURPLE>Yuu<WHITE> will get used to it.<.>"
					"And just think, even if <PURPLE>Yuu<WHITE> gets kidnapped or something..<.>"
					"Well, at least we won't have to pay the ransom.<.>"
					"Go have fun now!<.>"
					"But not too far!");
		battery_quest=10;
	}

	if(battery_quest==10&&GLOBAL_text_engine_state==0)
	{

		unload_gametoy();
		battery_quest=11;
		ITEM_get(&GameToy);

	}




		if(dad_npc==NULL){NPC_create_npc_xy_feet(&dad_npc,GFX_ADULT_youngdad, 16, 40, 51*8,35*8);dad_npc->non_walkable=1;NPC_animate_stand_dir(&dad_npc, DOWN);}
	if(ACTION_npc(&dad_npc,"Talk To Dad")&&GLOBAL_text_engine_state==0)
	{
		TEXT_set_sprite_window(0,dad_npc,NULL);
		TEXT_set_sprite_window(1,PLAYER_npc,NULL);
		TEXT_window("Hey, what's up, kiddo?<.>"
					"<1>I finished unpacking, I'm bored.<.>"
					"<0>Mmmhmm. Sounds important. <.>"
					"Go ask your mother.<.>"
					"Shoot! Missed! <.>"
					"<1><YELLOW>Ping<WHITE> again? How are you not bored with that?<.>"
					"<0>Shh! Keep your voice down. And don't knock <YELLOW>Ping<WHITE>.<.>"
					"This game is a legend. <PAUSE>There's more depth to it than <PURPLE>Yuu<WHITE> can even begin to imagine.<.>"
					"For instance, did <PURPLE>Yuu<WHITE> know that the dot represents a <GREEN>warrior of the light?<WHITE><.>"
					"He's always marching towards the <BLUE>Dark Lord's castle,<WHITE> see that line at the top?<.>"
					"But the <BLUE>Dark Lord,<WHITE> in his unmerciful cruelty, always knocks him away before he can save the world.<.>"
					"It's up to the player to restore his rightful direction, as represented by the line at the bottom.<.>"
					"See? It's actually the first RPG, or whatever kids like <PURPLE>Yuu<WHITE> call it these days.<.>"
					"<PURPLE>Yuu<WHITE> doesn't need all those flashy graphics for classics like this, <PURPLE>Yuu<WHITE> just needs imagination.<.>"
					"<1>You just made that up, and it's the most stupid thing I've ever heard.<.>"
					"<1><MOM><SMALL>(From kitchen) <HUGE><NEXTLINE>Dear, are you almost finished unpacking over there?<.>"
					"<0><HUGE>Uh, yeah, honey!<PAUSE> Almost! <SMALL>uh..<.>"
					"<SMALL>Psst. <PAUSE> Hey <PURPLE>Yuu<WHITE>. <PAUSE>Go distract her, will <PURPLE>Yuu?<WHITE><.>"
					"<NORMAL><1><YUU>Got it.");
	}
	if(battery_quest>=5)
	{
		if(brother_npc==NULL){NPC_create_npc_xy_feet(&brother_npc,GFX_KID_youngbrother, 16, 32,	48*8, 35*8);brother_npc->non_walkable=1;NPC_animate_stand_dir(&brother_npc, RIGHT);}
			if((ACTION_npc(&brother_npc,"Talk To Brother")||battery_quest==5)&&GLOBAL_text_engine_state==0)
			{
				if(battery_quest==5)battery_quest=6;
				TEXT_set_sprite_window(0,brother_npc,NULL);
				TEXT_set_sprite_window(1,dad_npc,NULL);
				TEXT_window("<NOCANCEL><0>Dad! What kind of house IS this?!<.>The wiring is bad or something!<.><1>Mmmhmm. <.>Sounds important. <.>Go ask your mother.");
			}
	}

	if(battery_quest==6)
	{
		cameraman->walking_speed=SPEED_FASTEST;

	}

//=================================================================================================================
//ACTIONS
//=================================================================================================================
	if(walking_into_door(RANGE_INTRODownstairsToUpstairs))
	{
		MAP_change_map(MAP_bobsgame_INTROUpstairs,5,20);return;
	}
	if(walking_into_door(RANGE_INTRODownstairsToBasement))
	{
		//HARDWARE_set_music_volume(127);
		HARDWARE_stop_music();

		MAP_change_map(MAP_bobsgame_INTROBasement,5,9);return;
	}
	if(walking_into_door(RANGE_INTRODownstairsToDownstairsBathroom))
	{
		//HARDWARE_set_music_volume(127);
		HARDWARE_stop_music();

		MAP_change_map(MAP_bobsgame_INTRODownstairsBathroom,6,16);return;
	}
	if(walking_into_door(RANGE_INTRODownstairsToGarage))
	{

		//HARDWARE_set_music_volume(127);
		HARDWARE_stop_music();
		MAP_change_map(MAP_bobsgame_INTROGarage,23,11);return;
	}
	if(ACTION_range_xy_xy(RANGE_INTRODownstairsToINTROOUTSIDEBackyard,"Go outside."))
	{
		if(battery_quest==11||battery_quest==12)
		{
			//PLAYER_npc->gfx_filename = yuu;
				//MAP_change_map(MAP_bobsgame_TOWNYUUUpstairsYuusRoom,20,21);return;


			//HARDWARE_set_music_volume(127);
			HARDWARE_stop_music();

			MAP_change_map(MAP_bobsgame_INTROTown,244,84);return;
		}
		else
		if(GLOBAL_text_engine_state==0)
		{
			TEXT_set_sprite_window(0,mom_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			//NPC_animate_set_direction_now(&PLAYER_npc,DOWN);
			//facing_direction=DOWN;
			if(battery_quest==0)TEXT_window("Hold on there, little guy. Did <PURPLE>Yuu<WHITE> finish unpacking?<.>"
											"<1>Yes.<.>"
											"<0>Oh.<DELAY1SEC> Well, don't think <PURPLE>Yuu<WHITE> can just wander around in a strange neighborhood all alone,<PAUSE> at least not without asking first.");
			else TEXT_window("And just where does <PURPLE>Yuu<WHITE> think he's going?<.>"
							"<1>...Outside?<.>"
							"<0>And did <PURPLE>Yuu<WHITE> find what I asked for?<.>"
							"<1>I thought maybe you would've forgotten by now.<.>"
							"<0>Very funny. I don't think so, young man. Get back to searching. <.>"
							"<PURPLE>Yuu<WHITE> had better check every square inch of this house. I'm sure I saw them somewhere, maybe in my bedroom? <.>"
							"No, that's not right. The bathroom? The basement? Hmm.");
		}
	}
		if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box1,"Look in box")&&boxcaption==NULL)CAPTION_make_caption(&boxcaption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES,"Toilet paper, laxatives...",FONT_SMALL_ID,WHITE,BLACK,1,1);

		if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box2,"Look in box")&&boxcaption==NULL)CAPTION_make_caption(&boxcaption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES,"Onions, dried beetles...",FONT_SMALL_ID,WHITE,BLACK,1,1);

		if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box3,"Look in box")&&boxcaption==NULL)CAPTION_make_caption(&boxcaption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES,"Candles, rope...",FONT_SMALL_ID,WHITE,BLACK,1,1);

		if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box4,"Look in box")&&boxcaption==NULL)CAPTION_make_caption(&boxcaption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES,"Pictures, vases...",FONT_SMALL_ID,WHITE,BLACK,1,1);

		if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box5,"Look in box")&&boxcaption==NULL)CAPTION_make_caption(&boxcaption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES,"Fish.",FONT_SMALL_ID,WHITE,BLACK,1,1);

		if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box6,"Look in box")&&boxcaption==NULL)CAPTION_make_caption(&boxcaption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES,"Blankets, underwear...",FONT_SMALL_ID,WHITE,BLACK,1,1);

		if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box7,"Look in box")&&boxcaption==NULL)CAPTION_make_caption(&boxcaption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES,"Tennis rackets, goldfish bowls..",FONT_SMALL_ID,WHITE,BLACK,1,1);

		if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box8,"Look in box")&&boxcaption==NULL)CAPTION_make_caption(&boxcaption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES,"Can't open it. Probably golf equipment.",FONT_SMALL_ID,WHITE,BLACK,1,1);

		if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box9,"Look in box")&&boxcaption==NULL)CAPTION_make_caption(&boxcaption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES,"Can't open it. Probably Sewing Machines.",FONT_SMALL_ID,WHITE,BLACK,1,1);

		if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box10,"Look in box")&&boxcaption==NULL)CAPTION_make_caption(&boxcaption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES,"Can't open it. Smells like gasoline.",FONT_SMALL_ID,WHITE,BLACK,1,1);

		if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box11,"Look in box")&&boxcaption==NULL)CAPTION_make_caption(&boxcaption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES,"Can't open it. Sounds like umbrellas.",FONT_SMALL_ID,WHITE,BLACK,1,1);

		if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box12,"Look in box")&&boxcaption==NULL)CAPTION_make_caption(&boxcaption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES,"Chicken sandwiches.",FONT_SMALL_ID,WHITE,BLACK,1,1);

		if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box13,"Look in box")&&boxcaption==NULL)CAPTION_make_caption(&boxcaption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES,"Plates, spoons.",FONT_SMALL_ID,WHITE,BLACK,1,1);

		if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box14,"Look in box")&&boxcaption==NULL)CAPTION_make_caption(&boxcaption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES,"Spatula, pots and pans.",FONT_SMALL_ID,WHITE,BLACK,1,1);

		if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box15,"Look in box")&&boxcaption==NULL)CAPTION_make_caption(&boxcaption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES,"Sporks.",FONT_SMALL_ID,WHITE,BLACK,1,1);

		if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box16,"Look in box")&&boxcaption==NULL)CAPTION_make_caption(&boxcaption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES,"Really ugly wallpaper.",FONT_SMALL_ID,WHITE,BLACK,1,1);
}
void bobsgame_INTRODownstairs_Map_Stop_Function()
{
	NPC_delete_all_npcs();
	mom_npc=NULL;
	dad_npc=NULL;
	brother_npc=NULL;
	dad_flag=0;
	mom_flag=0;
	brother_flag=0;



}
void bobsgame_INTRODownstairs_Map_VBL_Function()
{

}

void bobsgame_INTRODownstairs_Map_HBL_Function()
{

}

//========================================================
//INTROUpstairs
//========================================================
void bobsgame_INTROUpstairs_Map_Load_Function()
{
//RANGE_INTROUpstairsToUpstairsBathroom 52*8,16*8,56*8,17*8
//RANGE_INTROUpstairsToParentsRoom 11*8,16*8,15*8,17*8
//RANGE_INTROUpstairsToBabyRoom 34*8,16*8,38*8,17*8
//RANGE_INTROUpstairsToYuusRoom 47*8,8*8,51*8,9*8
//RANGE_INTROUpstairsToBrothersRoom 24*8,8*8,28*8,9*8
//RANGE_INTROUpstairsToDownstairs 2*8,21*8,8*8,22*8
//RANGE_box17 17*8,9*8,19*8,11*8
//RANGE_box18 18*8,14*8,21*8,16*8
//RANGE_box19 24*8,14*8,26*8,16*8
//RANGE_box20 40*8,13*8,43*8,16*8
//RANGE_box21 43*8,9*8,46*8,11*8
//maybe make box to trap brother in room




if(battery_quest<4)
{
	HARDWARE_play_music("g65_theme",48);

}


}
void bobsgame_INTROUpstairs_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//=================================================================================================================
//ACTIONS
//=================================================================================================================
	if(walking_into_door(RANGE_INTROUpstairsToUpstairsBathroom))
	{


		HARDWARE_stop_music();
		MAP_change_map(MAP_bobsgame_INTROUpstairsBathroom,9,9);return;

	}


	if(walking_into_door(RANGE_INTROUpstairsToParentsRoom))
	{


		HARDWARE_stop_music();
		MAP_change_map(MAP_bobsgame_INTROUpstairsParentsRoom,6,9);return;


	}


	if(walking_into_door(RANGE_INTROUpstairsToBabyRoom))
	{


		HARDWARE_stop_music();
		MAP_change_map(MAP_bobsgame_INTROUpstairsBabyRoom,9,9);return;
	}


	if(walking_into_door(RANGE_INTROUpstairsToYuusRoom))
	{


		HARDWARE_stop_music();
		MAP_change_map(MAP_bobsgame_INTROUpstairsYuusRoom,20,21);return;
	}


	if(walking_into_door(RANGE_INTROUpstairsToBrothersRoom))
	{



		MAP_change_map(MAP_bobsgame_INTROUpstairsBrothersRoom,26,21);return;
	}



	if(walking_into_door(RANGE_INTROUpstairsToDownstairs))
	{



		MAP_change_map(MAP_bobsgame_INTRODownstairs,5,27);return;
	}
		if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box17,"Look in box")&&boxcaption==NULL)CAPTION_make_caption(&boxcaption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES,"Shirts, socks.",FONT_SMALL_ID,WHITE,BLACK,1,1);
		if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box18,"Look in box")&&boxcaption==NULL)CAPTION_make_caption(&boxcaption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES,"Wigs.",FONT_SMALL_ID,WHITE,BLACK,1,1);
		if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box19,"Look in box")&&boxcaption==NULL)CAPTION_make_caption(&boxcaption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES,"Ties, belt buckles.",FONT_SMALL_ID,WHITE,BLACK,1,1);
		if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box20,"Look in box")&&boxcaption==NULL)CAPTION_make_caption(&boxcaption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES,"Bowling shoes.",FONT_SMALL_ID,WHITE,BLACK,1,1);
		if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box21,"Look in box")&&boxcaption==NULL)CAPTION_make_caption(&boxcaption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES,"Hair curlers. Toilet plungers.",FONT_SMALL_ID,WHITE,BLACK,1,1);
}
void bobsgame_INTROUpstairs_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_INTROUpstairs_Map_VBL_Function()
{

}

void bobsgame_INTROUpstairs_Map_HBL_Function()
{

}

//========================================================
//INTROUpstairsYuusRoom
//========================================================
void bobsgame_INTROUpstairsYuusRoom_Map_Load_Function()
{
//RANGE_INTROYuusRoomToUpstairs 18*8,22*8,22*8,23*8
//RANGE_box22 2*8,11*8,31*8,15*8
//boxes
//FF INTRO	just kidding
//HEALTH WARNINGS
//HOSPITAL CUTSCENE IN B+W, 1989	thats great, honey! hold that pose! cant you smile? someone get her some makeup! SHUT UP!!!! what is he holding?!-> "what should we name him" "write a video game"
//A LONG, LONG TIME AGO THERE WAS NOTHING
//CREDIT SCREEN, INTRO OVER CITY
//MOVING TRUCK
//INTRO
//NO MR CART
//SPECIAL OUTSIDE
//CLOCK IS ????? DAY IS ?????
//INTRO MR CART QUESTIONS
//SCHOOL DREAM

	HARDWARE_play_music("birds_horns",64);



}




void bobsgame_INTROUpstairsYuusRoom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}





	static int did_intro=0;
	static CAPTION* movingdaycaption=NULL;

	if(did_intro==0)
	{
		TEXT_set_sprite_window(0,PLAYER_npc,NULL);
		TEXT_set_sprite_window(1,PLAYER_npc,NULL);

		LETTERBOX_init(64,1);
		if(movingdaycaption==NULL)CAPTION_make_caption(&movingdaycaption, 1, CAPTION_CENTERED_X, 20, -1, "MOVING DAY", FONT_HUGE_ID, WHITE, CLEAR,1,1);
		TEXT_window("<NOCANCEL>Alright! Done unpacking. Let's go see what's going on.");
		did_intro=1;

	}

	if(did_intro==1&&GLOBAL_text_engine_state==0)
	{

		if(LETTERBOX_sprites_exist)LETTERBOX_deinit();
		if(movingdaycaption!=NULL)CAPTION_delete_caption(movingdaycaption);
		did_intro=2;
	}


	/*if(did_intro==0&&GLOBAL_text_engine_state==0)
	{
		GLOBAL_main_sprite_input_off=1;
		did_intro=3;
		load_gametoy_fullscreen();
		tetrid=1;


	}*/





	//=================================================================================================================
//ACTIONS
//=================================================================================================================
	if(walking_into_door(RANGE_INTROYuusRoomToUpstairs))
	{
		MAP_change_map(MAP_bobsgame_INTROUpstairs,49,9);return;
	}

	//if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box22,"Look in box")&&boxcaption==NULL)CAPTION_make_caption(&boxcaption, 1,CAPTION_CENTERED,PLAYER_npc->screen_y-10,CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES,"Empty.",FONT_SMALL_ID,WHITE,BLACK,1,1); //gdc
}
void bobsgame_INTROUpstairsYuusRoom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
	HARDWARE_stop_music();

}
void bobsgame_INTROUpstairsYuusRoom_Map_VBL_Function()
{

}

void bobsgame_INTROUpstairsYuusRoom_Map_HBL_Function()
{

}

//========================================================
//INTROUpstairsBabyRoom
//========================================================
void bobsgame_INTROUpstairsBabyRoom_Map_Load_Function()
{
//RANGE_INTROBabyRoomToUpstairs 7*8,8*8,11*8,9*8
//RANGE_box23 3*8,9*8,5*8,12*8
}
void bobsgame_INTROUpstairsBabyRoom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

	static NPC* babyred_npc = NULL;

	if(babyred_npc==NULL)
	{
		NPC_create_npc(&babyred_npc,GFX_KID_babyredhair,16,32,15*8,8*8);
		///babyred_npc->shadow=0;
		NPC_animate_cycle_through_frames_now(&babyred_npc,4);
	}

	if(NPC_in_range_of_area_xyxy_in_direction_by_amount(&PLAYER_npc,14*8,9*8,15*8,17*8,PLAYER_npc->anim_dir,7))
	{
		if(babyred_npc->vbl_animation_timer>10)
		{
			NPC_animate_cycle_through_frames_now(&babyred_npc,4);
			//if(babyred_npc->anim_frame_count==1||babyred_npc->anim_frame_count==3)babyred_npc->MAP_y--;
			//else babyred_npc->MAP_y++;
		}
	}
 	if(ACTION_range_xy_xy(14*8,9*8,15*8,17*8,"Talk To Baby")&&GLOBAL_text_engine_state==0)
	{
		TEXT_set_sprite_window(0,PLAYER_npc,NULL);
		TEXT_set_sprite_window(1,babyred_npc,NULL);
		TEXT_window("Hey little guy. <.>You'd be a lot cuter if you weren't so stinky.<.><1>*Gurgle*");
	}
		if(ACTION_range_xy_xy(8*8,17*8,10*8,18*8,"Look at stuff")&&GLOBAL_text_engine_state==0)
	{
		TEXT_set_sprite_window(0,PLAYER_npc,NULL);
		TEXT_set_sprite_window(1,babyred_npc,NULL);
		TEXT_window("Diapers.. Baby powder..<.>\"Baby shut-ups?\"<.>\"Pacifiers laced with a light tranquilizer- No more sleepless nights!\"<.>Wow. They can sell these?");
	}
//=================================================================================================================
//ACTIONS
//=================================================================================================================
	if(walking_into_door(RANGE_INTROBabyRoomToUpstairs))
	{
		MAP_change_map(MAP_bobsgame_INTROUpstairs,36,15);return;
	}
	if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box23,"Look in box")&&boxcaption==NULL)CAPTION_make_caption(&boxcaption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES,"Diapers.",FONT_SMALL_ID,WHITE,BLACK,1,1);

}
void bobsgame_INTROUpstairsBabyRoom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_INTROUpstairsBabyRoom_Map_VBL_Function()
{

}

void bobsgame_INTROUpstairsBabyRoom_Map_HBL_Function()
{

}

//========================================================
//INTROUpstairsBrothersRoom
//========================================================
void bobsgame_INTROUpstairsBrothersRoom_Map_Load_Function()
{
//RANGE_INTROBrothersRoomToUpstairs 24*8,22*8,28*8,23*8
//RANGE_box24 24*8,12*8,27*8,14*8
//RANGE_box25 22*8,10*8,24*8,11*8


	if(battery_quest<3)
	{
		HARDWARE_play_music("g65_theme",64);
	}

}

void bobsgame_INTROUpstairsBrothersRoom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}




	//static NPC* tv_npc = NULL;
	static NPC* batteries_npc = NULL;
	if(battery_quest<3)
	{



		if(tv_npc==NULL)NPC_create_npc(&tv_npc,GFX_MISC_tv3x2videogame,32,16,6*8,10*8);
		if(batteries_npc==NULL)NPC_create_npc_xy_feet(&batteries_npc,GFX_MISC_batteries, 16, 16,	10*8, (19*8));
		if(brother_npc==NULL){NPC_create_npc_xy_feet(&brother_npc,GFX_KID_youngbrother, 16, 32,	8*8, (19*8)-4);brother_npc->non_walkable=1;NPC_animate_stand_dir(&brother_npc, UP);}

		//TODO:video game noise
		if(tv_npc->vbl_animation_timer>10)NPC_animate_cycle_through_frames_now(&tv_npc,6);
		if(ACTION_range_xy_xy(21*8,11*8,22*8,17*8,"Talk To Brother")&&GLOBAL_text_engine_state==0)
		{
			TEXT_set_sprite_window(0,brother_npc,NULL);
			TEXT_set_sprite_window(1,PLAYER_npc,NULL);
			if(battery_quest==0)
			{
				TEXT_window("<1>Hey, aren't you supposed to be unpacking?<.><0>What does it look like I'm doing, dork?<.><1>Playing a video game?<.><0>Yeah, and just how did <PURPLE>Yuu<WHITE> think I did that without unpacking it?<.>Get a brain, loser.<.>Get out of my face!");
			}
			else
			if(battery_quest==1)
			{
				TEXT_window("<NOCANCEL><1>Hey, aren't those batteries over there?<.><0>No. Get out.<.><1>On the floor, right there.<.><0>Oh.<.>Maybe. And?<.><1>Mom needs them. Can you hand them over?<.><0>What? Is <PURPLE>Yuu<WHITE> stupid or something? Can't <PURPLE>Yuu<WHITE> see I'm on the last level?<.>Don't break my concentration. Get out of my face!");
				battery_quest=2;
			}
			else
			if(battery_quest==2)
			{
				TEXT_window("<1>I really need those batteries. Just pause it or something.<.><0><HUGE>NO!<SHAKE1SEC><NORMAL><.><1>Well then I'll just grab them...<.><0>Don't even think about it. I will punch <PURPLE>Yuu<WHITE> in the face.<.><HUGE>GET OUT OF MY ROOM!<SHAKE1SEC>");
			}
		}
	}
	if(battery_quest==6)
	{
		if(batteries_npc==NULL){NPC_create_npc_xy_feet(&batteries_npc,GFX_MISC_batteries, 16, 16,	21*8, (13*8));}
		if(ACTION_xy(21*8,14*8,"Take Batteries")){NPC_delete_npc(&batteries_npc);battery_quest=7;ITEM_get(&Batteries);}
	}
	//=================================================================================================================
//ACTIONS
//=================================================================================================================
	if(walking_into_door(RANGE_INTROBrothersRoomToUpstairs))
	{
		MAP_change_map(MAP_bobsgame_INTROUpstairs,26,9);return;
	}

		if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box24,"Look in box")&&boxcaption==NULL)CAPTION_make_caption(&boxcaption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES,"Posters. CD's.",FONT_SMALL_ID,WHITE,BLACK,1,1);
		if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box25,"Look in box")&&boxcaption==NULL)CAPTION_make_caption(&boxcaption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES,"Tissues and lotion.",FONT_SMALL_ID,WHITE,BLACK,1,1);
}
void bobsgame_INTROUpstairsBrothersRoom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
	brother_npc=NULL;
	tv_npc=NULL;

}
void bobsgame_INTROUpstairsBrothersRoom_Map_VBL_Function()
{

}

void bobsgame_INTROUpstairsBrothersRoom_Map_HBL_Function()
{

}

//========================================================
//INTROUpstairsBathroom
//========================================================
void bobsgame_INTROUpstairsBathroom_Map_Load_Function()
{
//RANGE_INTROUpstairsBathroomToUpstairs 7*8,8*8,11*8,9*8
//RANGE_box26 7*8,15*8,10*8,17*8
//RANGE_box27 7*8,17*8,9*8,19*8
}

void bobsgame_INTROUpstairsBathroom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//=================================================================================================================
//ACTIONS
//=================================================================================================================
	if(walking_into_door(RANGE_INTROUpstairsBathroomToUpstairs))
	{
		MAP_change_map(MAP_bobsgame_INTROUpstairs,54,15);return;
	}

	if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box26,"Look in box")&&boxcaption==NULL)CAPTION_make_caption(&boxcaption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES,"Cotton swabs. Toilet cleaner.",FONT_SMALL_ID,WHITE,BLACK,1,1);
	if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box27,"Look in box")&&boxcaption==NULL)CAPTION_make_caption(&boxcaption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES,"Bandages. Medicine. Pipe cleaners?",FONT_SMALL_ID,WHITE,BLACK,1,1);
}
void bobsgame_INTROUpstairsBathroom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_INTROUpstairsBathroom_Map_VBL_Function()
{

}

void bobsgame_INTROUpstairsBathroom_Map_HBL_Function()
{

}

//========================================================
//INTROUpstairsParentsRoom
//========================================================
void bobsgame_INTROUpstairsParentsRoom_Map_Load_Function()
{
//RANGE_INTROParentsRoomToUpstairs 4*8,8*8,8*8,9*8
//RANGE_box28 2*8,12*8,5*8,13*8
}

void bobsgame_INTROUpstairsParentsRoom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//=================================================================================================================
//ACTIONS
//=================================================================================================================
	if(walking_into_door(RANGE_INTROParentsRoomToUpstairs))
	{
		MAP_change_map(MAP_bobsgame_INTROUpstairs,13,15);return;
	}
	if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box28,"Look in box")&&boxcaption==NULL)CAPTION_make_caption(&boxcaption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES,"Luggage. Upholstery Cleaner.",FONT_SMALL_ID,WHITE,BLACK,1,1);
}
void bobsgame_INTROUpstairsParentsRoom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_INTROUpstairsParentsRoom_Map_VBL_Function()
{

}

void bobsgame_INTROUpstairsParentsRoom_Map_HBL_Function()
{

}

//========================================================
//INTROBasement
//========================================================
void bobsgame_INTROBasement_Map_Load_Function()
{
//RANGE_INTROBasementToDownstairs 3*8,8*8,7*8,9*8
//RANGE_box29 10*8,33*8,13*8,36*8
//RANGE_box30 19*8,25*8,21*8,27*8
//RANGE_box31 23*8,25*8,25*8,27*8
//RANGE_box32 21*8,34*8,23*8,36*8
//RANGE_box33 31*8,33*8,34*8,36*8
//RANGE_box34 31*8,27*8,33*8,30*8
//RANGE_box35 41*8,27*8,44*8,30*8
//RANGE_box36 34*8,20*8,37*8,22*8
//RANGE_box37 39*8,21*8,41*8,23*8
//RANGE_box38 44*8,20*8,47*8,22*8
//RANGE_box39 55*8,32*8,57*8,33*8
}

void bobsgame_INTROBasement_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}


	if(sparks_npc==NULL)NPC_create_npc(&sparks_npc,GFX_MISC_sparks,16,16,58*8,16*8);

	if(ACTION_xy((58*8)+4,17*8,"Look at Power Box"))
	{
		if(battery_quest==2)
		{
			//if power box flipped, brother screams noooooooooooooooooo

				TEXT_set_sprite_window(0,PLAYER_npc,NULL);
				TEXT_window("<NOCANCEL>Let's see.. <.>Upstairs.. <.>*flip*<.>");

				if(brother_npc==NULL){NPC_create_npc_xy_feet(&brother_npc,GFX_KID_youngbrother, 16, 32,	0*8, (0*8));}

				battery_quest=3;
		}
		else
		{
			TEXT_set_sprite_window(0,PLAYER_npc,NULL);
			TEXT_window("The box says High Voltage. I'd better not touch it unless I need to.");
		}
	}

	if(battery_quest==3&&GLOBAL_text_engine_state==0)
	{
							{
								HARDWARE_create_brightened_palette(HARDWARE_map_palette,(int*)&GAME_temp_TILESET_PALETTE,-15);
								//GAME_temp_TILESET_PALETTE[246]=RGB(0,0,0);

								HARDWARE_load_bg_palette((int*)&GAME_temp_TILESET_PALETTE);
								HARDWARE_reload_bg_textures();


						}
		TEXT_set_sprite_window(0,PLAYER_npc,NULL);
		TEXT_set_sprite_window(1,brother_npc,NULL); //TODO: BROTHER NPC MIGhT NOT BE INITIALIZED HERE
		TEXT_window("<NOCANCEL><SMALL><1><CAM0>(Brother from upstairs)<HUGE><NEXTLINE>Aaahhh!!<SHAKE2SEC><BOB><NEXTLINE>NOOOOOOOOO!!!!!<SHAKE2SEC><PAUSE><0><NORMAL>Ehehehe..");
		battery_quest=4;
	}

	if(battery_quest==4&&GLOBAL_text_engine_state==0)
	{


				HARDWARE_create_brightened_palette(HARDWARE_map_palette,(int*)&GAME_temp_TILESET_PALETTE,0);
				//GAME_temp_TILESET_PALETTE[246]=RGB(0,0,0);

				HARDWARE_load_bg_palette((int*)&GAME_temp_TILESET_PALETTE);
				HARDWARE_reload_bg_textures();



			battery_quest=5;
			if(brother_npc!=NULL){NPC_delete_npc(&brother_npc);brother_npc=NULL;}


	}

	if(sparks_npc->vbl_animation_timer>10+(r(20)))NPC_animate_cycle_through_frames_now(&sparks_npc,4);
//=================================================================================================================
//ACTIONS
//=================================================================================================================
	if(walking_into_door(RANGE_INTROBasementToDownstairs))
	{
		MAP_change_map(MAP_bobsgame_INTRODownstairs,5,14);return;
	}

		if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box29,"Look in box")&&boxcaption==NULL&&GLOBAL_text_engine_state==0)
		{
			TEXT_set_sprite_window(0,PLAYER_npc,NULL);
			TEXT_window("Empty..<.>Wait, there's something cylindrical and shiny caught under the flap.<.>Oh, it's a socket wrench.");
		}

		if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box30,"Look in box")&&boxcaption==NULL&&GLOBAL_text_engine_state==0)
		{
			TEXT_set_sprite_window(0,PLAYER_npc,NULL);
			TEXT_window("What's this? Round and metal!<.>Oh, a flashlight.<.>And it's empty.");
		}

		if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box31,"Look in box")&&boxcaption==NULL)CAPTION_make_caption(&boxcaption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES,"Detergent. Fabric softener.",FONT_SMALL_ID,WHITE,BLACK,1,1);

		if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box32,"Look in box")&&boxcaption==NULL)CAPTION_make_caption(&boxcaption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES,"Parachutes.",FONT_SMALL_ID,WHITE,BLACK,1,1);

		if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box33,"Look in box")&&boxcaption==NULL)CAPTION_make_caption(&boxcaption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES,"Vacuum Cleaners.",FONT_SMALL_ID,WHITE,BLACK,1,1);

		if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box34,"Look in box")&&boxcaption==NULL)CAPTION_make_caption(&boxcaption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES,"Mattress coils.",FONT_SMALL_ID,WHITE,BLACK,1,1);

		if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box35,"Look in box")&&boxcaption==NULL)CAPTION_make_caption(&boxcaption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES,"Weightlifting set.",FONT_SMALL_ID,WHITE,BLACK,1,1);

		if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box36,"Look in box")&&boxcaption==NULL)CAPTION_make_caption(&boxcaption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES,"Inflatable rafts.",FONT_SMALL_ID,WHITE,BLACK,1,1);

		if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box37,"Look in box")&&boxcaption==NULL)CAPTION_make_caption(&boxcaption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES,"Old magazines.",FONT_SMALL_ID,WHITE,BLACK,1,1);

		if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box38,"Look in box")&&boxcaption==NULL)CAPTION_make_caption(&boxcaption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES,"Camping stove. Tent.",FONT_SMALL_ID,WHITE,BLACK,1,1);

		if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box39,"Look in box")&&boxcaption==NULL)CAPTION_make_caption(&boxcaption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES,"Can't reach it.",FONT_SMALL_ID,WHITE,BLACK,1,1);
}
void bobsgame_INTROBasement_Map_Stop_Function()
{
	NPC_delete_all_npcs();
	sparks_npc=NULL;
}
void bobsgame_INTROBasement_Map_VBL_Function()
{

}

void bobsgame_INTROBasement_Map_HBL_Function()
{

}

//========================================================
//INTROGarage
//========================================================
void bobsgame_INTROGarage_Map_Load_Function()
{
//RANGE_INTROGarageToDownstairs 25*8,10*8,26*8,14*8
//RANGE_INTROGarageToAttic 4*8,10*8,8*8,11*8
//RANGE_box40 16*8,16*8,19*8,18*8
//RANGE_box41 7*8,15*8,9*8,17*8
//RANGE_box42 15*8,11*8,18*8,13*8
//RANGE_box43 18*8,9*8,21*8,11*8
//RANGE_box44 22*8,26*8,23*8,27*8
//RANGE_box45 22*8,21*8,25*8,22*8
//RANGE_box46 22*8,23*8,23*8,25*8
//RANGE_box47 16*8,26*8,19*8,29*8
//RANGE_box48 8*8,23*8,11*8,25*8
//RANGE_box49 14*8,26*8,15*8,29*8
//RANGE_box50 11*8,24*8,14*8,26*8
//RANGE_box51 5*8,26*8,8*8,28*8
}
void bobsgame_INTROGarage_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//=================================================================================================================
//ACTIONS
//=================================================================================================================
	if(walking_into_door(RANGE_INTROGarageToDownstairs))
	{
		MAP_change_map(MAP_bobsgame_INTRODownstairs,2,11);return;
	}
	if(ACTION_range_xy_xy(RANGE_INTROGarageToAttic, "Go in Attic"))
	{
		MAP_change_map(MAP_bobsgame_INTROAttic,5,12);return;
	}

	if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box40,"Look in box")&&boxcaption==NULL)CAPTION_make_caption(&boxcaption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES,"Cardboard boxes.",FONT_SMALL_ID,WHITE,BLACK,1,1);

	if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box41,"Look in box")&&boxcaption==NULL)CAPTION_make_caption(&boxcaption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES,"Fishing rods.",FONT_SMALL_ID,WHITE,BLACK,1,1);

	if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box42,"Look in box")&&boxcaption==NULL)CAPTION_make_caption(&boxcaption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES,"Tennis rackets.",FONT_SMALL_ID,WHITE,BLACK,1,1);

	if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box43,"Look in box")&&boxcaption==NULL)CAPTION_make_caption(&boxcaption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES,"Tools. Car wax.",FONT_SMALL_ID,WHITE,BLACK,1,1);

	if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box44,"Look in box")&&boxcaption==NULL)CAPTION_make_caption(&boxcaption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES,"Severed head.",FONT_SMALL_ID,WHITE,BLACK,1,1);

	if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box45,"Look in box")&&boxcaption==NULL)CAPTION_make_caption(&boxcaption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES,"Paint. Antifreeze.",FONT_SMALL_ID,WHITE,BLACK,1,1);

	if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box46,"Look in box")&&boxcaption==NULL)CAPTION_make_caption(&boxcaption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES,"Swords.",FONT_SMALL_ID,WHITE,BLACK,1,1);

	if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box47,"Look in box")&&boxcaption==NULL)CAPTION_make_caption(&boxcaption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES,"Fertilizer.",FONT_SMALL_ID,WHITE,BLACK,1,1);

	if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box48,"Look in box")&&boxcaption==NULL)CAPTION_make_caption(&boxcaption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES,"Gardening tools.",FONT_SMALL_ID,WHITE,BLACK,1,1);

	if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box49,"Look in box")&&boxcaption==NULL)CAPTION_make_caption(&boxcaption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES,"Spackle. Caulk.",FONT_SMALL_ID,WHITE,BLACK,1,1);

	if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box50,"Look in box")&&boxcaption==NULL)CAPTION_make_caption(&boxcaption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES,"Garbage bags, snowsuits.",FONT_SMALL_ID,WHITE,BLACK,1,1);

	if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box51,"Look in box")&&boxcaption==NULL)CAPTION_make_caption(&boxcaption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES,"Holiday decorations. Model trains.",FONT_SMALL_ID,WHITE,BLACK,1,1);
}
void bobsgame_INTROGarage_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_INTROGarage_Map_VBL_Function()
{

}

void bobsgame_INTROGarage_Map_HBL_Function()
{

}

//========================================================
//INTRODownstairsBathroom
//========================================================
void bobsgame_INTRODownstairsBathroom_Map_Load_Function()
{
//RANGE_INTRODownstairsBathroomToDownstairs 4*8,17*8,8*8,18*8
//RANGE_INTROMirrorEffect 6*8,11*8,11*8,13*8
//RANGE_box52 2*8,11*8,4*8,12*8
//DO SPRITE MIRRORING ABOVE LAYER 3
}
void bobsgame_INTRODownstairsBathroom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//=================================================================================================================
//ACTIONS
//=================================================================================================================
	if(walking_into_door(RANGE_INTRODownstairsBathroomToDownstairs))
	{
		MAP_change_map(MAP_bobsgame_INTRODownstairs,29,36);return;
	}
	if(walking_into_door(RANGE_INTROMirrorEffect))
	{

	}

	if(boxcaption==NULL)if(ACTION_range_xy_xy(RANGE_box52,"Look in box")&&boxcaption==NULL)CAPTION_make_caption(&boxcaption, 1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,CAPTION_DELETE_WHEN_MAIN_SPRITE_MOVES,"Toilet paper. Air fresheners.",FONT_SMALL_ID,WHITE,BLACK,1,1);
}
void bobsgame_INTRODownstairsBathroom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_INTRODownstairsBathroom_Map_VBL_Function()
{

}

void bobsgame_INTRODownstairsBathroom_Map_HBL_Function()
{

}

//========================================================
//INTROAttic
//========================================================
void bobsgame_INTROAttic_Map_Load_Function()
{
//RANGE_INTROAtticToGarage 4*8,14*8,7*8,15*8
}

void bobsgame_INTROAttic_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//=================================================================================================================
//ACTIONS
//=================================================================================================================
	if(walking_into_door(RANGE_INTROAtticToGarage))
	{
		MAP_change_map(MAP_bobsgame_INTROGarage,5,11);return;
	}
}
void bobsgame_INTROAttic_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_INTROAttic_Map_VBL_Function()
{

}

void bobsgame_INTROAttic_Map_HBL_Function()
{

}



