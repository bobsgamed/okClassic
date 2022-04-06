//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================
#ifndef START_H
#define START_H
//==============================================================================



//================
//defines
//================
//MR CART FRAMES
#define BLANK			0
#define NORMAL			1
#define MILDINTEREST	2  //innocent lifted eyebrows "oh?" (not suspicious)
#define INTERESTED		3  //mildy surprised "oooh!"
#define IMPRESSED	 	4  //surprised "whoa!"
#define VERYIMPRESSED	5  //pixel pupils
#define HARDBLINK	 	6  //hard blink,disbelief
#define SHOCKED			7  //outlined eyes,anime shock,mouth open
#define SCRAMBLED	 	8  //googley eyed confused
#define DIZZY		 	9  //spiral eyes
#define DEAD		 	10 //xed eyes,tongue out
#define DROOL			11 //drool smile,wants something
#define EYEFLUTTER		12 //kisses,flattery,eye flutter
#define FRIENDLYSMILE 	13 //"hi there!"
#define WINK		 	14 //slight grin
#define GRIN		 	15 //giddy grin "hee hee"
#define LAUGHING	 	16 //rotl,closed grinning eyes
#define EVILGRIN	 	17 //slightly evil grin or evil laugh
#define REDEYEGRIN		18 //scary maniacal demon eye grin
#define CURIOUS			19 //mildy skeptical "eh?" very mild sneer
#define DOUBT			20 //slight doubt,one eyebrow "hmmmmm"
#define SKEPTICAL		21 //surprised "whaaaaat?" one eye smaller
#define ROLLINGEYES		22 //"puh-leeze"
#define SIGHBLINK		23 //eyes closed mouth raised a little
#define MOPE			24 //depressed,eyes looking down,slight frown
#define REGRETFUL		25 //slightly angry,eyes down,mean eyebrows
#define BLUSHGRIN		26 //sheepish grin,embarrassed
#define CRYING		 	27 //nooooooooooo
#define WORRIED			28 //really worried
#define SCARED			29 //watery anime eyes,really terrified
#define HURT			30 //hurt suspicious eyes
#define BITTER			31 //resentful half eyes closed look
#define SNEER			32 //disgusted
#define ANGRYSNEER		33 //"fine then!"
#define BLEAH			34 //sticking out tongue "bleah!"
#define GLARE			35 //psycho glare,angry stare RRRRRR
#define REDEYEFURIOUS	36 //demon eyes,engry
#define SUNGLASSES	 	37 //"oh yeah"
#define FAIRY			38 //"hey!"
#define PIRATE			39 //YARR




//================
//variables
//================


extern int current_mod;
extern int mods[128];



//================
//prototypes
//================



void start_screen_vbl();

void start_screen_timer();

void start_screen_deinit();
void start_screen_main();
void start_screen_init();




//==============================================================================
#endif
//==============================================================================
