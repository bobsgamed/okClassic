
//==========================================================================================================================
//SPRITE
//==========================================================================================================================
#ifndef SPRITES_H
#define SPRITES_H
//==============================================================================

	struct GFX
	{
		char FileName[128];
		int* indexed_gfx_data;
		int data_size_x;
		int data_size_y;

		int texture_size_x;
		int texture_size_y;

		int IndexInCachedTextureIDArray;

		bool shadow; //this is used to decide whether the texture gfx will be generated with a shadow or not

		bool hq2x; //this is needed because sprites can have their own scaling, and hq2x textures are all drawn at 0.5x by default and need the hq2x palette

		bool kid;//set on load based on size, used because kids/adults/cars need a larger texture for shadows, since the kid already fills a 32*64 texture, it creates a 32*128 one instead

		bool adult;

		bool car;
		bool bike;//car or bike will generate random alternate colors from the texture by messing with color channels. when creating a car or bike sprite, set the frame accordingly to choose a color

		bool generic;//this should somehow generate random color sets of clothing from the greyscale people. not sure how yet, especially with hq2x, i would need to output with outfit colors and then manually adjust the hq2x palette.

		int content_size_x;
		int content_size_y;

	}; //this replaces gfx data

	//const GFX GFX_INIT = {"hello",NULL,0,0,-1,0};


	struct SPRITE
	{
		GLuint texture_id;

		GFX* gfx;

		int alpha;
		int layer;
		float scale;
		int screen_x;
		int screen_y;

		//bool draw_full_texture;

		int draw_size_x;
		int draw_size_y;//this is used to determine whether the shadow is clipped or not




		//cached or volatile? probably dont need this


		//PLAYER_gfx_slot_alpha need alpha, but it should just be per sprite, shouldnt it?

		//car
		//kid
		//bike

		//GFX struct? //if i store the gfx in here, i wont need to send in the GFX for every update_gfx_slot, i can just use NULL!



		//frames
		//layer/priority

		//zoom/scale
		//screenx
		//screeny
		//alpha?


	}; //this replaces sprite id and gfx slot, the only reason for having this is so i can index them in an array and z-order them, and then draw them in order during render



//================
//defines
//================



//================
//variables
//================


extern int* GAME_original_SPRITE_PALETTE;
extern unsigned short GAME_temp_SPRITE_PALETTE[256];
extern SPRITE* HARDWARE_sprites[256];




extern GFX* TEXT_GFX[2];//={&VAR_GFX_TEXT[0],&VAR_GFX_TEXT[1]};
extern GFX* TEXTANSWER_GFX;//=&VAR_GFX_TEXTANSWER;
extern GFX* CAPTION_GFX[16];//={&VAR_GFX_CAPTION[0],&VAR_GFX_CAPTION[1],&VAR_GFX_CAPTION[2],&VAR_GFX_CAPTION[3],&VAR_GFX_CAPTION[4],&VAR_GFX_CAPTION[5],&VAR_GFX_CAPTION[6],&VAR_GFX_CAPTION[7],&VAR_GFX_CAPTION[8],&VAR_GFX_CAPTION[9],&VAR_GFX_CAPTION[10],&VAR_GFX_CAPTION[11],&VAR_GFX_CAPTION[12],&VAR_GFX_CAPTION[13],&VAR_GFX_CAPTION[14],&VAR_GFX_CAPTION[15]};
extern GFX* TEXTSPRITEWINDOW_GFX[2];//={&VAR_GFX_TEXTSPRITEWINDOW[0],&VAR_GFX_TEXTSPRITEWINDOW[1]};
extern GFX* PINGPADDLE_GFX;//=&VAR_GFX_PINGPADDLE;
extern GFX* PINGBALL_GFX;//=&VAR_GFX_PINGBALL;



extern GFX* TEXT_button_icon_GFX;//=&VAR_GFX_TEXT_button_icon;
extern GFX* TEXT_button_icon_underneath_GFX;//=&VAR_GFX_TEXT_button_icon_underneath;
extern GFX* TEXTANSWER_cursor_GFX;//=&VAR_GFX_TEXTANSWER_answerbox_cursor;



extern GFX* RAMIO_brickblock_gfx_GFX;//=&VAR_GFX_RAMIO_brickblock_gfx;
extern GFX* RAMIO_moneyblock_gfx_GFX;//=&VAR_GFX_RAMIO_moneyblock_gfx;
extern GFX* RAMIO_money_gfx_GFX;//=&VAR_GFX_RAMIO_money_gfx;
extern GFX* RAMIO_boba_gfx_GFX;//=&VAR_GFX_RAMIO_boba_gfx;
extern GFX* RAMIO_guy_gfx_GFX;//=&VAR_GFX_RAMIO_guy_gfx;



extern GFX* TEXT_keyboard_GFX;//=&VAR_GFX_TEXT_keyboard;
extern GFX* TEXT_keyboard_caps_GFX;//=&VAR_GFX_TEXT_keyboard_caps;
extern GFX* TEXT_numpad_GFX;//=&VAR_GFX_TEXT_numpad;
extern GFX* TEXT_keypressed_icon_GFX;//=&VAR_GFX_TEXT_keypressed_icon;
extern GFX* LETTERBOX_sprite_GFX;//=&VAR_GFX_LETTERBOX_sprite;

//extern GFX* shadow_GFX;//=&VAR_GFX_shadow;
//extern GFX* click_GFX;//=&VAR_GFX_click;


extern GFX* GFX_KID_yuu;//=&VAR_GFX_yuu;
extern GFX* GFX_KID_yuurunning;//=&VAR_GFX_yuurunning;


extern GFX* GFX_KID_youngyuu;//=&VAR_GFX_youngyuu;
extern GFX* GFX_KID_youngyuurunning;//=&VAR_GFX_youngyuurunning;


extern GFX* GFX_KID_youngfriend;//=&VAR_GFX_youngfriend;
extern GFX* GFX_KID_youngbrother;//=&VAR_GFX_youngbrother;
extern GFX* GFX_KID_baby;//=&VAR_GFX_baby;

extern GFX* GFX_ADULT_youngdad;//=&VAR_GFX_youngdad;
extern GFX* GFX_ADULT_youngmom;//=&VAR_GFX_youngmom;

extern GFX* GFX_KID_babyredhair;//=&VAR_GFX_babyredhair;
extern GFX* GFX_KID_brother;//=&VAR_GFX_brother;
extern GFX* GFX_KID_littlebrother;//=&VAR_GFX_littlebrother;


extern GFX* GFX_ADULT_bob;//=&VAR_GFX_bob;
extern GFX* GFX_ADULT_bobscary;//=&VAR_GFX_bobscary;

extern GFX* GFX_ADULT_dad;//=&VAR_GFX_dad;
extern GFX* GFX_ADULT_mom;//=&VAR_GFX_mom;


extern GFX* GFX_CAR_car;//=&VAR_GFX_car;
extern GFX* GFX_CAR_truck;//=&VAR_GFX_truck;

//extern GFX* getmycolorsright_GFX;//=&VAR_GFX_getmycolorsright;
//extern GFX* GENERIChaireyescolors_GFX;//=&VAR_GFX_GENERIChaireyescolors;
//extern GFX* GENERICshirtpantsshoescolors_GFX;//=&VAR_GFX_GENERICshirtpantsshoescolors;
//extern GFX* GENERICskincolors_GFX;//=&VAR_GFX_GENERICskincolors;
//extern GFX* GENERICcarcolors_GFX;//=&VAR_GFX_GENERICcarcolors;

extern GFX* GFX_MISC_dinner;//=&VAR_GFX_dinner;
extern GFX* GFX_MISC_plate;//=&VAR_GFX_plate;
extern GFX* GFX_MISC_lunchbag;//=&VAR_GFX_lunchbag;
extern GFX* GFX_MISC_coffeeandnewspaper;//=&VAR_GFX_coffeeandnewspaper;
extern GFX* GFX_MISC_tv3x2videogame;//=&VAR_GFX_tv3x2videogame;
extern GFX* GFX_MISC_sparks;//=&VAR_GFX_sparks;
extern GFX* GFX_MISC_electricshock;//=&VAR_GFX_electricshock;
extern GFX* GFX_MISC_batteries;//=&VAR_GFX_batteries;
extern GFX* GFX_MISC_pingcontroller;//=&VAR_GFX_pingcontroller;
extern GFX* GFX_MISC_tv2x1mesflash;//=&VAR_GFX_tv2x1mesflash;

//extern GFX* spotlight_GFX;//=&VAR_GFX_spotlight;


extern GFX* GFX_KID_notfriend;//=&VAR_GFX_notfriend;
extern GFX* GFX_KID_youngsister;//=&VAR_GFX_youngsister;
extern GFX* GFX_KID_sister;//=&VAR_GFX_sister;




extern GFX* GFX_KID_bully;//=&VAR_GFX_bully;
extern GFX* GFX_KID_skaterboy;//=&VAR_GFX_skaterboy;
extern GFX* GFX_KID_bladerboy;//=&VAR_GFX_bladerboy;
extern GFX* GFX_KID_gothboy;//=&VAR_GFX_gothboy;
extern GFX* GFX_KID_punkboy;//=&VAR_GFX_punkboy;
extern GFX* GFX_KID_emoboy;//=&VAR_GFX_emoboy;
extern GFX* GFX_KID_greaserboy;//=&VAR_GFX_greaserboy;
extern GFX* GFX_KID_jockboy;//=&VAR_GFX_jockboy;
extern GFX* GFX_KID_pudgyboy;//=&VAR_GFX_pudgyboy;
extern GFX* GFX_KID_nerdboy;//=&VAR_GFX_nerdboy;
extern GFX* GFX_KID_thugboy;//=&VAR_GFX_thugboy;
extern GFX* GFX_KID_conceitedboy;//=&VAR_GFX_conceitedboy;
extern GFX* GFX_KID_uglyboy;//=&VAR_GFX_uglyboy;
extern GFX* GFX_KID_scrawnyboy;//=&VAR_GFX_scrawnyboy;
extern GFX* GFX_KID_uglygirl;//=&VAR_GFX_uglygirl;
extern GFX* GFX_KID_pudgygirl;//=&VAR_GFX_pudgygirl;
extern GFX* GFX_KID_gothgirl;//=&VAR_GFX_gothgirl;
extern GFX* GFX_KID_nerdgirl;//=&VAR_GFX_nerdgirl;
extern GFX* GFX_KID_conceitedgirl;//=&VAR_GFX_conceitedgirl;
extern GFX* GFX_KID_punkgirl;//=&VAR_GFX_punkgirl;
extern GFX* GFX_KID_emogirl;//=&VAR_GFX_emogirl;
extern GFX* GFX_KID_skatergirl;//=&VAR_GFX_skatergirl;
extern GFX* GFX_KID_jockgirl;//=&VAR_GFX_jockgirl;
extern GFX* GFX_KID_paperboy;//=&VAR_GFX_paperboy;
extern GFX* GFX_KID_foreignboy;//=&VAR_GFX_foreignboy;
extern GFX* GFX_KID_japaneseboy;//=&VAR_GFX_japaneseboy;

extern GFX* GFX_ANIMAL_cat;//=&VAR_GFX_cat;
extern GFX* GFX_ANIMAL_puppy;//=&VAR_GFX_puppy;
extern GFX* GFX_ANIMAL_skunk;//=&VAR_GFX_skunk;
extern GFX* GFX_ANIMAL_bird;//=&VAR_GFX_bird;
extern GFX* GFX_ANIMAL_turtle;//=&VAR_GFX_turtle;
extern GFX* GFX_ANIMAL_hamster;//=&VAR_GFX_hamster;
extern GFX* GFX_ANIMAL_squirrel;//=&VAR_GFX_squirrel;
extern GFX* GFX_ANIMAL_rat;//=&VAR_GFX_rat;
extern GFX* GFX_ANIMAL_ant;//=&VAR_GFX_ant;
extern GFX* GFX_ANIMAL_fly;//=&VAR_GFX_fly;
extern GFX* GFX_ANIMAL_snake;//=&VAR_GFX_snake;


extern GFX* GFX_KID_GENERICboy1;//=&VAR_GFX_GENERICboy1;
extern GFX* GFX_KID_GENERICboy2;//=&VAR_GFX_GENERICboy2;
extern GFX* GFX_KID_GENERICboy3;//=&VAR_GFX_GENERICboy3;
extern GFX* GFX_KID_GENERICboy4;//=&VAR_GFX_GENERICboy4;
//extern GFX* GFX_KID_GENERICboy5;//=&VAR_GFX_GENERICboy5;
extern GFX* GFX_KID_GENERICgirl1;//=&VAR_GFX_GENERICgirl1;
extern GFX* GFX_KID_GENERICgirl2;//=&VAR_GFX_GENERICgirl2;
extern GFX* GFX_KID_GENERICgirl3;//=&VAR_GFX_GENERICgirl3;
extern GFX* GFX_KID_GENERICgirl4;//=&VAR_GFX_GENERICgirl4;
extern GFX* GFX_KID_GENERICgirl5;//=&VAR_GFX_GENERICgirl5;
extern GFX* GFX_KID_GENERICgirl6;//=&VAR_GFX_GENERICgirl6;
extern GFX* GFX_KID_GENERIClittleboy1;//=&VAR_GFX_GENERIClittleboy1;
extern GFX* GFX_KID_GENERIClittleboy2;//=&VAR_GFX_GENERIClittleboy2;
extern GFX* GFX_KID_GENERIClittleboy3;//=&VAR_GFX_GENERIClittleboy3;
extern GFX* GFX_KID_GENERICpudgylittleboy;//=&VAR_GFX_GENERICpudgylittleboy;
extern GFX* GFX_KID_GENERIClittlegirl1;//=&VAR_GFX_GENERIClittlegirl1;
extern GFX* GFX_KID_GENERIClittlegirl2;//=&VAR_GFX_GENERIClittlegirl2;
extern GFX* GFX_KID_GENERIClittlegirl3;//=&VAR_GFX_GENERIClittlegirl3;


extern GFX* GFX_ADULT_friendsdad;//=&VAR_GFX_friendsdad;
extern GFX* GFX_ADULT_friendsmom;//=&VAR_GFX_friendsmom;

extern GFX* GFX_ADULT_crazylady;//=&VAR_GFX_crazylady;
extern GFX* GFX_ADULT_librarian;//=&VAR_GFX_librarian;
extern GFX* GFX_ADULT_secretary;//=&VAR_GFX_secretary;
extern GFX* GFX_ADULT_nurse;//=&VAR_GFX_nurse;
extern GFX* GFX_ADULT_hallmonitor;//=&VAR_GFX_hallmonitor;
extern GFX* GFX_ADULT_principal;//=&VAR_GFX_principal;
extern GFX* GFX_ADULT_janitor;//=&VAR_GFX_janitor;
extern GFX* GFX_ADULT_momo;//=&VAR_GFX_momo;
extern GFX* GFX_ADULT_oldmomo;//=&VAR_GFX_oldmomo;
extern GFX* GFX_ADULT_sleazyunclebob;//=&VAR_GFX_sleazyunclebob;
extern GFX* GFX_ADULT_givenupteacher;//=&VAR_GFX_givenupteacher;
extern GFX* GFX_ADULT_maleangryteacher;//=&VAR_GFX_maleangryteacher;
extern GFX* GFX_ADULT_malesadteacher;//=&VAR_GFX_malesadteacher;
extern GFX* GFX_ADULT_femaleangryteacher;//=&VAR_GFX_femaleangryteacher;
extern GFX* GFX_ADULT_femalesadteacher;//=&VAR_GFX_femalesadteacher;
extern GFX* GFX_ADULT_grannycluelessteacher;//=&VAR_GFX_grannycluelessteacher;
extern GFX* GFX_ADULT_pcteacher;//=&VAR_GFX_pcteacher;
extern GFX* GFX_ADULT_crossingguard;//=&VAR_GFX_crossingguard;
extern GFX* GFX_ADULT_mailman;//=&VAR_GFX_mailman;
extern GFX* GFX_ADULT_doortodoorsalesman;//=&VAR_GFX_doortodoorsalesman;
extern GFX* GFX_ADULT_firefighter;//=&VAR_GFX_firefighter;
extern GFX* GFX_ADULT_securityguard;//=&VAR_GFX_securityguard;
extern GFX* GFX_ADULT_townsheriff;//=&VAR_GFX_townsheriff;
extern GFX* GFX_ADULT_policeofficermale;//=&VAR_GFX_policeofficermale;
extern GFX* GFX_ADULT_policeofficerfemale;//=&VAR_GFX_policeofficerfemale;
extern GFX* GFX_ADULT_swat;//=&VAR_GFX_swat;
extern GFX* GFX_ADULT_privateeye;//=&VAR_GFX_privateeye;
extern GFX* GFX_ADULT_cia;//=&VAR_GFX_cia;
extern GFX* GFX_ADULT_newsreportermale;//=&VAR_GFX_newsreportermale;
extern GFX* GFX_ADULT_newsreporterfemale;//=&VAR_GFX_newsreporterfemale;
extern GFX* GFX_ADULT_cameraguy;//=&VAR_GFX_cameraguy;
extern GFX* GFX_ADULT_familydoctordentist;//=&VAR_GFX_familydoctordentist;
extern GFX* GFX_ADULT_surgeon;//=&VAR_GFX_surgeon;
extern GFX* GFX_ADULT_hospitaldirector;//=&VAR_GFX_hospitaldirector;
extern GFX* GFX_ADULT_paramedic;//=&VAR_GFX_paramedic;
extern GFX* GFX_ADULT_psychiatrist;//=&VAR_GFX_psychiatrist;
extern GFX* GFX_ADULT_madscientist;//=&VAR_GFX_madscientist;
extern GFX* GFX_ADULT_professor;//=&VAR_GFX_professor;
extern GFX* GFX_ADULT_dogwalker;//=&VAR_GFX_dogwalker;
extern GFX* GFX_ADULT_spandexjogger;//=&VAR_GFX_spandexjogger;
extern GFX* GFX_ADULT_shoppinglady;//=&VAR_GFX_shoppinglady;
extern GFX* GFX_ADULT_farmer;//=&VAR_GFX_farmer;
extern GFX* GFX_ADULT_deliicecreamman;//=&VAR_GFX_deliicecreamman;
extern GFX* GFX_ADULT_hotdogvendor;//=&VAR_GFX_hotdogvendor;
extern GFX* GFX_ADULT_trafficcharityguy;//=&VAR_GFX_trafficcharityguy;
extern GFX* GFX_ADULT_magazinevendor;//=&VAR_GFX_magazinevendor;
extern GFX* GFX_ADULT_constructionworker;//=&VAR_GFX_constructionworker;
extern GFX* GFX_ADULT_businessguy;//=&VAR_GFX_businessguy;
extern GFX* GFX_ADULT_businesswoman;//=&VAR_GFX_businesswoman;
extern GFX* GFX_ADULT_richnerdguy;//=&VAR_GFX_richnerdguy;
extern GFX* GFX_ADULT_officeworkermale;//=&VAR_GFX_officeworkermale;
extern GFX* GFX_ADULT_officeworkerfemale;//=&VAR_GFX_officeworkerfemale;
extern GFX* GFX_ADULT_skinnymeekcoder;//=&VAR_GFX_skinnymeekcoder;
extern GFX* GFX_ADULT_fatmeekcoder;//=&VAR_GFX_fatmeekcoder;
extern GFX* GFX_ADULT_wealthylady;//=&VAR_GFX_wealthylady;
extern GFX* GFX_ADULT_bigwig;//=&VAR_GFX_bigwig;
extern GFX* GFX_ADULT_wealthygirl;//=&VAR_GFX_wealthygirl;
extern GFX* GFX_ADULT_wealthyguy;//=&VAR_GFX_wealthyguy;
extern GFX* GFX_ADULT_mayor;//=&VAR_GFX_mayor;
extern GFX* GFX_ADULT_photographer;//=&VAR_GFX_photographer;
extern GFX* GFX_ADULT_pizzaguy;//=&VAR_GFX_pizzaguy;
extern GFX* GFX_ADULT_mime;//=&VAR_GFX_mime;
extern GFX* GFX_ADULT_guitarguy;//=&VAR_GFX_guitarguy;
extern GFX* GFX_ADULT_magician;//=&VAR_GFX_magician;
extern GFX* GFX_ADULT_clown;//=&VAR_GFX_clown;
extern GFX* GFX_ADULT_sandwichadguy;//=&VAR_GFX_sandwichadguy;
extern GFX* GFX_ADULT_flyerguy;//=&VAR_GFX_flyerguy;
extern GFX* GFX_ADULT_picketer;//=&VAR_GFX_picketer;
extern GFX* GFX_ADULT_samurai;//=&VAR_GFX_samurai;
extern GFX* GFX_ADULT_ninja;//=&VAR_GFX_ninja;
extern GFX* GFX_ADULT_karateguy;//=&VAR_GFX_karateguy;
extern GFX* GFX_ADULT_kungfumaster;//=&VAR_GFX_kungfumaster;
extern GFX* GFX_ADULT_wiseman;//=&VAR_GFX_wiseman;
extern GFX* GFX_ADULT_hermit;//=&VAR_GFX_hermit;
extern GFX* GFX_ADULT_tinfoilhatman;//=&VAR_GFX_tinfoilhatman;
extern GFX* GFX_ADULT_monk;//=&VAR_GFX_monk;
extern GFX* GFX_ADULT_shadywatchdealer;//=&VAR_GFX_shadywatchdealer;
extern GFX* GFX_ADULT_pickpocket;//=&VAR_GFX_pickpocket;
extern GFX* GFX_ADULT_prothief;//=&VAR_GFX_prothief;
extern GFX* GFX_ADULT_pawnshopguy;//=&VAR_GFX_pawnshopguy;
extern GFX* GFX_ADULT_mafiaguy;//=&VAR_GFX_mafiaguy;
extern GFX* GFX_ADULT_crimeboss;//=&VAR_GFX_crimeboss;
extern GFX* GFX_ADULT_biker;//=&VAR_GFX_biker;
extern GFX* GFX_ADULT_dealer;//=&VAR_GFX_dealer;
extern GFX* GFX_ADULT_bankrobber;//=&VAR_GFX_bankrobber;
extern GFX* GFX_ADULT_convict;//=&VAR_GFX_convict;
extern GFX* GFX_ADULT_escapedconvict;//=&VAR_GFX_escapedconvict;
extern GFX* GFX_ADULT_prostitute;//=&VAR_GFX_prostitute;
extern GFX* GFX_ADULT_hustler;//=&VAR_GFX_hustler;
extern GFX* GFX_ADULT_dancer;//=&VAR_GFX_dancer;
extern GFX* GFX_ADULT_thug;//=&VAR_GFX_thug;
extern GFX* GFX_ADULT_mechanic;//=&VAR_GFX_mechanic;
extern GFX* GFX_ADULT_diseased;//=&VAR_GFX_diseased;
extern GFX* GFX_ADULT_crippled;//=&VAR_GFX_crippled;
extern GFX* GFX_ADULT_hobo;//=&VAR_GFX_hobo;
extern GFX* GFX_ADULT_beggar;//=&VAR_GFX_beggar;
extern GFX* GFX_ADULT_terrorist;//=&VAR_GFX_terrorist;
extern GFX* GFX_ADULT_cultenlister;//=&VAR_GFX_cultenlister;
extern GFX* GFX_ADULT_alien;//=&VAR_GFX_alien;
extern GFX* GFX_ADULT_ghost;//=&VAR_GFX_ghost;
extern GFX* GFX_ADULT_superhero;//=&VAR_GFX_superhero;
extern GFX* GFX_ADULT_timetraveler;//=&VAR_GFX_timetraveler;
extern GFX* GFX_ADULT_robot;//=&VAR_GFX_robot;
extern GFX* GFX_ADULT_bubbleheadcyborg;//=&VAR_GFX_bubbleheadcyborg;
extern GFX* GFX_ADULT_quack;//=&VAR_GFX_quack;
extern GFX* GFX_ADULT_army;//=&VAR_GFX_army;
extern GFX* GFX_ADULT_transvestite;//=&VAR_GFX_transvestite;
extern GFX* GFX_ADULT_astronaut;//=&VAR_GFX_astronaut;
extern GFX* GFX_ADULT_buddy;//=&VAR_GFX_buddy;


extern GFX* GFX_ADULT_islandhermit;//=&VAR_GFX_islandhermit;
extern GFX* GFX_ADULT_president;//=&VAR_GFX_president;
extern GFX* GFX_ADULT_contortionistbountyhunter;//=&VAR_GFX_contortionistbountyhunter;


extern GFX* GFX_ADULT_GENERICsuitguy;//=&VAR_GFX_GENERICsuitguy;
extern GFX* GFX_ADULT_GENERICbaldsuitguy;//=&VAR_GFX_GENERICbaldsuitguy;
extern GFX* GFX_ADULT_GENERICbaldingmanashirt;//=&VAR_GFX_GENERICbaldingmanashirt;
extern GFX* GFX_ADULT_GENERICbaldingmantshirt;//=&VAR_GFX_GENERICbaldingmantshirt;
extern GFX* GFX_ADULT_GENERICmanlongsleeves;//=&VAR_GFX_GENERICmanlongsleeves;
extern GFX* GFX_ADULT_GENERICbeardbaldingtshirt;//=&VAR_GFX_GENERICbeardbaldingtshirt;
extern GFX* GFX_ADULT_GENERICwomanbobcut;//=&VAR_GFX_GENERICwomanbobcut;
extern GFX* GFX_ADULT_GENERICwomanbun;//=&VAR_GFX_GENERICwomanbun;
extern GFX* GFX_ADULT_GENERICwomanlonghair;//=&VAR_GFX_GENERICwomanlonghair;
extern GFX* GFX_ADULT_GENERICwomanfancyhairblouse;//=&VAR_GFX_GENERICwomanfancyhairblouse;
extern GFX* GFX_ADULT_GENERICmanbeardbaldingtshirt2;//=&VAR_GFX_GENERICmanbeardbaldingtshirt2;
extern GFX* GFX_ADULT_GENERICmangrayhairsuit;//=&VAR_GFX_GENERICmangrayhairsuit;
extern GFX* GFX_ADULT_GENERICmangrayhairbigheadsuit;//=&VAR_GFX_GENERICmangrayhairbigheadsuit;
extern GFX* GFX_ADULT_GENERICwomangrayhairdress;//=&VAR_GFX_GENERICwomangrayhairdress;
extern GFX* GFX_ADULT_GENERICwomangrayhairmakeupdress;//=&VAR_GFX_GENERICwomangrayhairmakeupdress;
extern GFX* GFX_ADULT_GENERICwomanwhitehair;//=&VAR_GFX_GENERICwomanwhitehair;

extern GFX* GFX_CAR_motorcycle;//=&VAR_GFX_motorcycle;
extern GFX* GFX_CAR_policecar;//=&VAR_GFX_policecar;
extern GFX* GFX_CAR_mafiacar;//=&VAR_GFX_mafiacar;
extern GFX* GFX_CAR_van;//=&VAR_GFX_van;

extern GFX* GFX_CAR_suv;//=&VAR_GFX_suv;
extern GFX* GFX_CAR_ferrari;//=&VAR_GFX_ferrari;
extern GFX* GFX_CAR_skycar;//=&VAR_GFX_skycar;
extern GFX* GFX_CAR_tvvan;//=&VAR_GFX_tvvan;
extern GFX* GFX_CAR_ambulance;//=&VAR_GFX_ambulance;
extern GFX* GFX_CAR_tank;//=&VAR_GFX_tank;
extern GFX* GFX_CAR_icecreamtruck;//=&VAR_GFX_icecreamtruck;
extern GFX* GFX_CAR_helicopter;//=&VAR_GFX_helicopter;
extern GFX* GFX_CAR_minivan;//=&VAR_GFX_minivan;
extern GFX* GFX_CAR_ufo;//=&VAR_GFX_ufo;

extern GFX* GFX_ANIMAL_bigdog;//=&VAR_GFX_bigdog;

extern GFX* GFX_MISC_shoppingcart;//=&VAR_GFX_shoppingcart;
extern GFX* GFX_MISC_lawnmower;//=&VAR_GFX_lawnmower;

extern GFX* GFX_CAR_bicycle;//=&VAR_GFX_bicycle;
//extern GFX* amrposter_GFX;//=&VAR_GFX_amrposter;





extern GFX* GFX_OUTSIDE_lawnchairfaceright;//=&VAR_GFX_lawnchairfaceright;
extern GFX* GFX_OUTSIDE_lawnchairfaceleft;//=&VAR_GFX_lawnchairfaceleft;
extern GFX* GFX_OUTSIDE_lawnchairfacedown;//=&VAR_GFX_lawnchairfacedown;
extern GFX* GFX_OUTSIDE_lawnbenchfacedown;//=&VAR_GFX_lawnbenchfacedown;
extern GFX* GFX_OUTSIDE_gardenhosecoil;//=&VAR_GFX_gardenhosecoil;
extern GFX* GFX_OUTSIDE_grillfaceleft;//=&VAR_GFX_grillfaceleft;
extern GFX* GFX_OUTSIDE_schoolxingsign;//=&VAR_GFX_schoolxingsign;
extern GFX* GFX_OUTSIDE_stopsignfaceup;//=&VAR_GFX_stopsignfaceup;
extern GFX* GFX_OUTSIDE_stopsignfacedown;//=&VAR_GFX_stopsignfacedown;
extern GFX* GFX_OUTSIDE_schoolflag;//=&VAR_GFX_schoolflag;
extern GFX* GFX_OUTSIDE_stainedglasswindow;//=&VAR_GFX_stainedglasswindow;
extern GFX* GFX_OUTSIDE_disorderofbobsign;//=&VAR_GFX_disorderofbobsign;
extern GFX* GFX_OUTSIDE_trafficlightfaceup;//=&VAR_GFX_trafficlightfaceup;
extern GFX* GFX_OUTSIDE_pizzasigndoorwide;//=&VAR_GFX_pizzasigndoorwide;
extern GFX* GFX_OUTSIDE_pizzasignwindow1;//=&VAR_GFX_pizzasignwindow1;
extern GFX* GFX_OUTSIDE_pizzasignwindow2;//=&VAR_GFX_pizzasignwindow2;
extern GFX* GFX_OUTSIDE_pizzasignwindow3;//=&VAR_GFX_pizzasignwindow3;
extern GFX* GFX_OUTSIDE_coffeecafesign;//=&VAR_GFX_coffeecafesign;
extern GFX* GFX_OUTSIDE_departmentsign;//=&VAR_GFX_departmentsign;
extern GFX* GFX_OUTSIDE_storedeptsign;//=&VAR_GFX_storedeptsign;
extern GFX* GFX_OUTSIDE_gasstationsign;//=&VAR_GFX_gasstationsign;
extern GFX* GFX_OUTSIDE_clubhouseboarded;//=&VAR_GFX_clubhouseboarded;
extern GFX* GFX_OUTSIDE_groceryexpresssignstacked;//=&VAR_GFX_groceryexpresssignstacked;
extern GFX* GFX_OUTSIDE_grocerysign;//=&VAR_GFX_grocerysign;
extern GFX* GFX_OUTSIDE_expresssign;//=&VAR_GFX_expresssign;
extern GFX* GFX_OUTSIDE_tacoburgersign;//=&VAR_GFX_tacoburgersign;
extern GFX* GFX_OUTSIDE_gamestoresign;//=&VAR_GFX_gamestoresign;
extern GFX* GFX_OUTSIDE_electronicssign;//=&VAR_GFX_electronicssign;
extern GFX* GFX_OUTSIDE_clinicsign;//=&VAR_GFX_clinicsign;
extern GFX* GFX_OUTSIDE_beautysalonstacked;//=&VAR_GFX_beautysalonstacked;
extern GFX* GFX_OUTSIDE_beautysalonsign;//=&VAR_GFX_beautysalonsign;
extern GFX* GFX_OUTSIDE_tanningsign;//=&VAR_GFX_tanningsign;
extern GFX* GFX_OUTSIDE_nailssign;//=&VAR_GFX_nailssign;
extern GFX* GFX_OUTSIDE_hairsign;//=&VAR_GFX_hairsign;
extern GFX* GFX_OUTSIDE_musicstoresign;//=&VAR_GFX_musicstoresign;
extern GFX* GFX_OUTSIDE_cdssign;//=&VAR_GFX_cdssign;
extern GFX* GFX_OUTSIDE_recordssign;//=&VAR_GFX_recordssign;
extern GFX* GFX_OUTSIDE_pets4lessdoorsign;//=&VAR_GFX_pets4lessdoorsign;
extern GFX* GFX_OUTSIDE_cutesign;//=&VAR_GFX_cutesign;
extern GFX* GFX_OUTSIDE_cheapsign;//=&VAR_GFX_cheapsign;
extern GFX* GFX_OUTSIDE_arcadesign;//=&VAR_GFX_arcadesign;
extern GFX* GFX_OUTSIDE_videorentsign;//=&VAR_GFX_videorentsign;
extern GFX* GFX_OUTSIDE_videorentsignstacked;//=&VAR_GFX_videorentsignstacked;
extern GFX* GFX_OUTSIDE_movietheatresign;//=&VAR_GFX_movietheatresign;
extern GFX* GFX_OUTSIDE_movietheatresignstacked;//=&VAR_GFX_movietheatresignstacked;
extern GFX* GFX_OUTSIDE_bookstoresign;//=&VAR_GFX_bookstoresign;
extern GFX* GFX_OUTSIDE_schoolsign;//=&VAR_GFX_schoolsign;
extern GFX* GFX_OUTSIDE_city50milesstreetsign;//=&VAR_GFX_city50milesstreetsign;
extern GFX* GFX_OUTSIDE_townstreetsign;//=&VAR_GFX_townstreetsign;
extern GFX* GFX_OUTSIDE_suburblanesign;//=&VAR_GFX_suburblanesign;




//extern GFX* mrcart_GFX;//=&VAR_GFX_mrcart;

//extern GFX* dogwalk1sprite_GFX;//=&VAR_GFX_dogwalk1sprite;
extern GFX* GFX_MISC_drums;//=&VAR_GFX_drums;
extern GFX* GFX_MISC_fountainwater;//=&VAR_GFX_fountainwater;
extern GFX* GFX_MISC_golfball;//=&VAR_GFX_golfball;
extern GFX* GFX_MISC_golfclub;//=&VAR_GFX_golfclub;
extern GFX* GFX_MISC_museumsheet;//=&VAR_GFX_museumsheet;
extern GFX* GFX_MISC_jewelsparkle;//=&VAR_GFX_jewelsparkle;
extern GFX* GFX_MISC_bighead;//=&VAR_GFX_bighead;

extern GFX* GFX_MISC_bigscreen_scanlines;//=&VAR_GFX_bigscreen_scanlines;



//================
//prototypes
//================


void HARDWARE_set_sprite_y(SPRITE* sprite, int screen_y);

SPRITE* HARDWARE_create_sprite(GFX* gfx, int gfx_index, int layer, float scale, int screen_x, int screen_y, int alpha);
void HARDWARE_update_sprite_texture(SPRITE* sprite, int gfx_index);
void HARDWARE_set_sprite_xy(SPRITE* sprite, int screen_x, int screen_y);
void HARDWARE_delete_sprite(SPRITE* sprite);
void HARDWARE_load_sprite_palette(int* palette);

void HARDWARE_init_arrays();
void HARDWARE_init_gfx_data();




//==============================================================================
#endif
//==============================================================================
