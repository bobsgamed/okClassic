//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================



#include "../../main.h"


//========================================================
//CastRoom
//========================================================
void bobsgame_MISCCastRoom_Map_Load_Function()
{

}

void bobsgame_MISCCastRoom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

	static char ctextvar0[256];
	static char ctextvar1[256];
	static char ctextvar2[256];
	static char ctextvar3[256];

	static CAPTION* castcaption[4]={NULL,NULL,NULL,NULL};
	static char* ctext[4] = {ctextvar0,ctextvar1,ctextvar2,ctextvar3};


	static NPC* NAME_npc[4] = {NULL,NULL,NULL,NULL};
	static NPC* NAME2_npc[4] = {NULL,NULL,NULL,NULL};



	//static NPC* sp1_npc = NULL;
	//static NPC* sp2_npc = NULL;
	static int c=0;
	static GFX* gfx[4]={NULL,NULL,NULL,NULL};
	static GFX* gfx2[4]={NULL,NULL,NULL,NULL};
	//int* gfx3=NULL;
	static int sizey[4]={32,32,32,32};
	static int npcs[4]={1,1,1,1};


	static int r=0;
	int t=60;


	//static int increment_c=1;



		if(NAME_npc[r]==NULL&&NAME2_npc[r]==NULL&&c<126)
		{
					//if(c== 1){gfx[r]=youngyuu;strcpy(ctext[r],"Young Yuu");}
					//if(c== 2){gfx[r]=youngfriend;strcpy(ctext[r],"The Annoying Neighbor Kid");}
					//if(c== 5){gfx[r]=youngbrother;strcpy(ctext[r],"");}
					//if(c== 7){gfx[r]=youngsister;strcpy(ctext[r],"The Neighbor Kid's Sister");}
					//if(c==37){gfx[r]=youngdad;strcpy(ctext[r],"");}
					//if(c==40){gfx[r]=youngmom;strcpy(ctext[r],"");}
					//if(c==34){gfx[r]=japaneseboy;strcpy(ctext[r],"The Japanese Prodigy");}
					npcs[r]=1;


					if(c==  0){gfx[r]=GFX_KID_yuu;strcpy(ctext[r],"Yuu");}

					if(c==  1){gfx[r]=GFX_ADULT_dad;strcpy(ctext[r],"Yuu's Parents");
								gfx2[r]=GFX_ADULT_mom;npcs[r]=2;}

					if(c==  2){gfx[r]=GFX_KID_brother;strcpy(ctext[r],"Yuu's Older Brother");}
					if(c==  3){gfx[r]=GFX_KID_littlebrother;strcpy(ctext[r],"Yuu's Little Brother");}

					if(c==  4){gfx[r]=GFX_KID_notfriend;strcpy(ctext[r],"The Neighbor Kid");}
					if(c==  5){gfx[r]=GFX_ADULT_friendsdad;strcpy(ctext[r],"The Neighbor Kid's Parents");
								gfx2[r]=GFX_ADULT_friendsmom;npcs[r]=2;}

					if(c==  6){gfx[r]=GFX_KID_sister;strcpy(ctext[r],"The Neighbor Kid's Sister");}
					if(c==  7){gfx[r]=GFX_ADULT_sleazyunclebob;strcpy(ctext[r],"The Neighbor Kid's Lazy Uncle");}



					if(c== 8){gfx[r]=GFX_KID_skaterboy;strcpy(ctext[r],"The Skaters");
								gfx2[r]=GFX_KID_skatergirl;npcs[r]=2;}

					if(c== 9){gfx[r]=GFX_KID_emoboy;strcpy(ctext[r],"The Sceners");
								gfx2[r]=GFX_KID_emogirl;npcs[r]=2;}


					if(c== 10){gfx[r]=GFX_KID_gothboy;strcpy(ctext[r],"The Goths");
								gfx2[r]=GFX_KID_gothgirl;npcs[r]=2;}


					if(c== 11){gfx[r]=GFX_KID_nerdboy;strcpy(ctext[r],"The Nerds");
								gfx2[r]=GFX_KID_nerdgirl;npcs[r]=2;}


					if(c== 12){gfx[r]=GFX_KID_jockboy;strcpy(ctext[r],"The Jocks");
								gfx2[r]=GFX_KID_jockgirl;npcs[r]=2;}


					if(c== 13){gfx[r]=GFX_KID_punkboy;strcpy(ctext[r],"The Punks");
								gfx2[r]=GFX_KID_punkgirl;npcs[r]=2;}

					if(c== 14){gfx[r]=GFX_KID_conceitedboy;strcpy(ctext[r],"The Rich Kids");
								gfx2[r]=GFX_KID_conceitedgirl;npcs[r]=2;}

					if(c== 15){gfx[r]=GFX_KID_pudgyboy;strcpy(ctext[r],"The Pudgy Kids");
								gfx2[r]=GFX_KID_pudgygirl;npcs[r]=2;}

					if(c== 16){gfx[r]=GFX_KID_uglyboy;strcpy(ctext[r],"The Pimply Kids");
								gfx2[r]=GFX_KID_uglygirl;npcs[r]=2;}


					if(c== 17){gfx[r]=GFX_KID_scrawnyboy;strcpy(ctext[r],"The Scrawny Kid");}
					if(c== 18){gfx[r]=GFX_KID_foreignboy;strcpy(ctext[r],"The Foreign Exchange Student");}


					if(c== 19){gfx[r]=GFX_KID_bully;strcpy(ctext[r],"The Bully That Was Held Back A Year");}
					if(c== 20){gfx[r]=GFX_KID_greaserboy;strcpy(ctext[r],"The \"Gangsta\" Kid");}
					if(c== 21){gfx[r]=GFX_KID_thugboy;strcpy(ctext[r],"The \"Thug\" Kid");}

					//if(c== 33){gfx[r]=bladerboy_GFX;strcpy(ctext[r],"The Blader");}

					//if(c== 34){gfx[r]=GFX_KID_baby;strcpy(ctext[r],"The Baby");}


					if(c== 22){gfx[r]=GFX_ADULT_janitor;strcpy(ctext[r],"The \"Custodial Technician\"");}
					if(c== 23){gfx[r]=GFX_ADULT_librarian;strcpy(ctext[r],"The Librarian");}
					if(c== 24){gfx[r]=GFX_ADULT_nurse;strcpy(ctext[r],"The School Nurse");}
					if(c== 25){gfx[r]=GFX_ADULT_secretary;strcpy(ctext[r],"The Secretary");}
					if(c== 26){gfx[r]=GFX_ADULT_principal;strcpy(ctext[r],"The Completely Incompetent Principal");}
					if(c== 27){gfx[r]=GFX_ADULT_hallmonitor;strcpy(ctext[r],"The Hall Monitor That Absolutely Loathes Children");}


					if(c== 28){gfx[r]=GFX_ADULT_givenupteacher;strcpy(ctext[r],			"The Teacher Who Has Long Since Given Up Trying At All");}
					if(c== 29){gfx[r]=GFX_ADULT_maleangryteacher;strcpy(ctext[r],			"The Teacher Who Thinks Kids These Days Just Need Discipline");}
					if(c== 30){gfx[r]=GFX_ADULT_malesadteacher;strcpy(ctext[r],			"The Very Sad Teacher That Takes A Lot Of Antidepressants");}
					if(c== 31){gfx[r]=GFX_ADULT_femaleangryteacher;strcpy(ctext[r],		"The Very Bitter Teacher Who Enjoys Giving F's");}
					if(c== 32){gfx[r]=GFX_ADULT_femalesadteacher;strcpy(ctext[r],			"The Teacher That Breaks Down Into Tears Several Times A Week");}
					if(c== 33){gfx[r]=GFX_ADULT_grannycluelessteacher;strcpy(ctext[r],		"The Granny Teacher That Has No Clue What Is Going On");}
					if(c== 34){gfx[r]=GFX_ADULT_pcteacher;strcpy(ctext[r],					"The Teacher Who Has Wisely Learned To Completely Ignore Everything");}
					if(c== 35){gfx[r]=GFX_ADULT_crossingguard;strcpy(ctext[r],				"The Crossing Guard That Sometimes Lets Cars Pass A Little Too Early For Certain Kids");}

					if(c== 36){gfx[r]=GFX_ADULT_crazylady;strcpy(ctext[r],					"The Crazy Lady Who Lives Next Door With About A Hundred Cats");}
					//if(c== 50){gfx[r]=dogwalker_GFX;strcpy(ctext[r],"The Very Sleepy Man Who Walks His Dog In The Morning And Lets It Poop On Other People's Lawns");}
					if(c== 37){gfx[r]=GFX_ADULT_spandexjogger;strcpy(ctext[r],				"The Irritatingly Upbeat Morning Person Who Goes Jogging In Spandex Shorts At 4 AM");}
					if(c== 38){gfx[r]=GFX_ADULT_shoppinglady;strcpy(ctext[r],				"The Cranky Woman Who Shoves People Out Of The Way To Get The Last Roll Of Discount Toilet Paper");}
					if(c== 39){gfx[r]=GFX_ADULT_mailman;strcpy(ctext[r],					"The Red-Headed Mailman Who Helps Neighbors Mingle By Delivering Mail To The Wrong House");}
					if(c== 40){gfx[r]=GFX_ADULT_doortodoorsalesman;strcpy(ctext[r],		"The Door-To-Door Salesman Who Will Probably Try To Get You Involved In His Pyramid Scheme");}

					if(c== 41){gfx[r]=GFX_ADULT_mayor;strcpy(ctext[r],						"The Town Mayor That Is Usually Involved In A Scandal When He Is Not On Vacation");}
					if(c== 42){gfx[r]=GFX_ADULT_pizzaguy;strcpy(ctext[r],					"The Pizza Delivery Man Who Eats Your Breadsticks If You Did Not Tip Him Last Time");}
					if(c== 43){gfx[r]=GFX_KID_paperboy;strcpy(ctext[r],					"The Paperboy Who Conveniently Leaves The Newspaper In The Middle Of The Lawn");}
					if(c== 44){gfx[r]=GFX_ADULT_firefighter;strcpy(ctext[r],				"The FireFighter Who Is Secretly A Pyromaniac And Sometimes Misaims The Hose On Purpose");}
					if(c== 45){gfx[r]=GFX_ADULT_securityguard;strcpy(ctext[r],				"The Security Guard Who Has No Way To Defend Himself And Provides No Actual Security");}
					if(c== 46){gfx[r]=GFX_ADULT_townsheriff;strcpy(ctext[r],				"The Town Sheriff Who Always Smells Like Whiskey And Does Not Stop For Traffic Lights");}

					if(c== 47){gfx[r]=GFX_ADULT_policeofficermale;strcpy(ctext[r],			"The Police Officers That Really Want To Try Out The New Stun Guns That Came In");
								gfx2[r]=GFX_ADULT_policeofficerfemale;npcs[r]=2;}

					if(c== 48){gfx[r]=GFX_ADULT_swat;strcpy(ctext[r],						"A Riot Policeman Who Randomly Pepper Sprays People To Start A Riot So That He Can Work Overtime");}
					if(c== 49){gfx[r]=GFX_ADULT_privateeye;strcpy(ctext[r],				"Private Eye Who Has Been Tracking Down Someone That Does Not Exist For Several Years Due To A Typo");}


					if(c== 50){gfx[r]=GFX_ADULT_newsreportermale;strcpy(ctext[r],			"A Television Reporter With A Feathered Toupee That Takes Everything Way Too Seriously");}
					if(c== 51){gfx[r]=GFX_ADULT_newsreporterfemale;strcpy(ctext[r],		"A Television Reporter With Unnaturally White Teeth Who Is Always Unconvincingly Cheerful");}
					if(c== 52){gfx[r]=GFX_ADULT_cameraguy;strcpy(ctext[r],					"The Camera Guy That Cuts People Off During Interviews To Make Them Look Stupid");}

					if(c== 53){gfx[r]=GFX_ADULT_familydoctordentist;strcpy(ctext[r],		"The Family Doctor Who Tells People To Remove Their Clothes And Then Goes On A Lunch Break");}
					if(c== 54){gfx[r]=GFX_ADULT_surgeon;strcpy(ctext[r],					"A Surgeon Who Enjoys His Work A Little Too Much To Be Considered Healthy");}
					if(c== 55){gfx[r]=GFX_ADULT_hospitaldirector;strcpy(ctext[r],					"The Hospital Director Who Has An Extreme Fear Of Germs");}
					if(c== 56){gfx[r]=GFX_ADULT_paramedic;strcpy(ctext[r],					"A Paramedic Who Hangs Out At Beaches Hoping To Give CPR To Hot Bikini Babes");}
					if(c== 57){gfx[r]=GFX_ADULT_diseased;strcpy(ctext[r],					"A Very Sick Man Who Takes A Lot Of Medication Which Is Actually What Is Making Him Very Sick");}
					if(c== 58){gfx[r]=GFX_ADULT_crippled;strcpy(ctext[r],					"A Man Pretending To Be Injured For Legal Purposes");}
					if(c== 59){gfx[r]=GFX_ADULT_psychiatrist;strcpy(ctext[r],				"An Antisocial Psychiatrist Who Becomes Depressed When His Patients Are Happy");}

					if(c== 60){gfx[r]=GFX_ADULT_madscientist;strcpy(ctext[r],				"The Mad Scientist That Discovered Time Travel Years Ago But Nobody Can Understand His Designs");}
					if(c== 61){gfx[r]=GFX_ADULT_timetraveler;strcpy(ctext[r],				"An Insane Man Who Claims He Came From The Future And Needs A Device To Save The World");}
					if(c== 62){gfx[r]=GFX_ADULT_professor;strcpy(ctext[r],					"The Professor That Is A World Expert On BioGeolistry Or Something And Lives With His Mother");}

					if(c== 63){gfx[r]=GFX_ADULT_farmer;strcpy(ctext[r],					"The Farmer Who Is Trying To Grow The World's Largest Eggplant And Has A Lottery Addiction");}
					if(c== 64){gfx[r]=GFX_ADULT_deliicecreamman;strcpy(ctext[r],			"The Deli Guy Who Mumbles While Cutting Lunchmeat And Creeps Everyone Out A Little");}
					if(c== 65){gfx[r]=GFX_ADULT_hotdogvendor;strcpy(ctext[r],				"A Hot Dog Vendor That Has Not Changed The Water In Ten Years Which Is Why They Are So Delicious");}
					if(c== 66){gfx[r]=GFX_ADULT_trafficcharityguy;strcpy(ctext[r],			"The Guy Who Stands In Traffic And Collects Money For What May Or May Not Be A Charitable Cause");}
					if(c== 67){gfx[r]=GFX_ADULT_magazinevendor;strcpy(ctext[r],			"The Magazine Vendor That Genuinely Believes Every Word Of The Tabloids");}
					if(c== 68){gfx[r]=GFX_ADULT_constructionworker;strcpy(ctext[r],		"The Construction Worker That Whistles While He Works And Gives A Lot Of People The Wrong Idea");}

					if(c== 69){gfx[r]=GFX_ADULT_businessguy;strcpy(ctext[r],				"The Very Famous Lawyer Duo Who Have Never Lost A Case Because They Are Naturally Compulsive Liars");
								gfx2[r]=GFX_ADULT_businesswoman;npcs[r]=2;}

					if(c== 70){gfx[r]=GFX_ADULT_richnerdguy;strcpy(ctext[r],				"The Very Rich Guy Who Buys A New Car Every Day Because The Old One Ran Out Of Gas");}

					if(c== 71){gfx[r]=GFX_ADULT_officeworkermale;strcpy(ctext[r],			"The Office Workers That Are Very Good At Switching Between A Spreadsheet Program And Solitaire");
								gfx2[r]=GFX_ADULT_officeworkerfemale;npcs[r]=2;}

					if(c== 72){gfx[r]=GFX_ADULT_skinnymeekcoder;strcpy(ctext[r],			"The IT Guys That Make Six Figures To Surf The Web All Day And Then Spend It On Robot Dogs And Pizza");
								gfx2[r]=GFX_ADULT_fatmeekcoder;npcs[r]=2;}

					if(c==73){gfx[r]=GFX_ADULT_photographer;strcpy(ctext[r],				"A Photographer Who Takes Out-Of-Focus Black And White Pictures Of Trees And Sells Them To Magazines");}
					if(c==74){gfx[r]=GFX_ADULT_mime;strcpy(ctext[r],						"The Mime That Has A Brilliant Idea That Could End All Human Suffering");}
					if(c==75){gfx[r]=GFX_ADULT_guitarguy;strcpy(ctext[r],					"The Lovesick Guitarist Who Sings Very Bad Songs About His Ex-Girlfriend And Will Probably Get Signed");}
					if(c==76){gfx[r]=GFX_ADULT_magician;strcpy(ctext[r],					"The Magician That Actually Has Telekinesis But Nobody Will Believe Him");}
					if(c==77){gfx[r]=GFX_ADULT_clown;strcpy(ctext[r],						"Man With Extremely Bad Fashion Sense Who Wonders Why He Gets Invited To So Many Birthday Parties");}

					if(c==78){gfx[r]=GFX_ADULT_sandwichadguy;strcpy(ctext[r],				"The Employee That Was So Useless He Is Being Paid To Do The Job Of A Piece Of Wood");}
					if(c==79){gfx[r]=GFX_ADULT_flyerguy;strcpy(ctext[r],					"The Man Who Hands Out Litter");}
					if(c==80){gfx[r]=GFX_ADULT_picketer;strcpy(ctext[r],					"A Man Who Really Wants Everybody To Know He Does Not Like Something");}

					if(c== 81){gfx[r]=GFX_ADULT_bigwig;strcpy(ctext[r],					"The Very Powerful And Sweaty Business Executive");}
					if(c== 82){gfx[r]=GFX_ADULT_wealthylady;strcpy(ctext[r],				"A Very Wealthy Woman That Finds A Reason To Complain About Every Single Thing She Sees");}

					if(c==83){gfx[r]=GFX_ADULT_wealthygirl;strcpy(ctext[r],				"A Very Wealthy Young Woman Who Will Have You Know Her Father Is A Very Important Man");}
					if(c==84){gfx[r]=GFX_ADULT_wealthyguy;strcpy(ctext[r],				"A Very Wealthy Young Man Who Probably Did Not Study His Way Into An Ivy League University");}
					if(c==85){gfx[r]=GFX_ADULT_president;strcpy(ctext[r],					"The President Of The Secret World Government That Definitely Does Not Exist");}
					if(c==86){gfx[r]=GFX_ADULT_army;strcpy(ctext[r],						"The High Ranking Military Officer With Anger Management Issues");}
					if(c==87){gfx[r]=GFX_ADULT_astronaut;strcpy(ctext[r],					"An Astronaut Who Says He Has Seen Aliens And Is Clearly Completely Insane");}
					if(c==88){gfx[r]=GFX_ADULT_alien;strcpy(ctext[r],						"A Cute Doggy");}

					if(c==89){gfx[r]=GFX_ADULT_cia;strcpy(ctext[r],						"A Man Who Has Been Sitting In A Delivery Van Outside For A Week");}
					//if(c== 97){gfx[r]=contortionistbountyhunter_GFX;strcpy(ctext[r],"The Contortionist Woman Who Can Roll Herself Into A Ball");}




					if(c==90){gfx[r]=GFX_ADULT_biker;strcpy(ctext[r],						"A Very Tough Looking Man Who Rides A Motorcycle And Cries After A Few Drinks");}
					if(c==91){gfx[r]=GFX_ADULT_thug;strcpy(ctext[r],						"The Very Tough Young Man Who Brags He Has Never Lost A Fight But Has Actually Never Been In One");}
					if(c==92){gfx[r]=GFX_ADULT_shadywatchdealer;strcpy(ctext[r],			"A Man Who Sells Genuine Luxury Watches At A Special Price Just For You");}
					if(c==93){gfx[r]=GFX_ADULT_dealer;strcpy(ctext[r],					"A Man Who Is Trying To Give Out Small Change In Bags For Some Reason");}
					if(c==94){gfx[r]=GFX_ADULT_pickpocket;strcpy(ctext[r],				"A Clumsy Man Who Often Bumps Into Wealthy-Looking Strangers");}
					if(c==95){gfx[r]=GFX_ADULT_prothief;strcpy(ctext[r],					"A Man Who Seems To Know A Lot About Security Alarm Systems");}
					if(c==96){gfx[r]=GFX_ADULT_pawnshopguy;strcpy(ctext[r],				"A Foreign Man With A Heavy Accent Who Wants To Loan You Money");}
					if(c==97){gfx[r]=GFX_ADULT_mafiaguy;strcpy(ctext[r],					"A Foreign Man With A Heavy Accent Who Wants His Money Back");}
					if(c==98){gfx[r]=GFX_ADULT_crimeboss;strcpy(ctext[r],					"A Very Nice Foreign Man Who Gives His Enemies A Friendly Kiss To Make Up With Them");}


					if(c==99){gfx[r]=GFX_ADULT_bankrobber;strcpy(ctext[r],					"The Party Animal Who Wants Everyone To Put Their Hands In The Air And Get Down On The Floor");}
					//if(c==131){gfx[r]=GFX_ADULT_convict;strcpy(ctext[r]," ");}
					if(c==100){gfx[r]=GFX_ADULT_escapedconvict;strcpy(ctext[r],				"A Large Man In Handcuffs Who Really Wants To Borrow Your Clothes");}
					if(c==101){gfx[r]=GFX_ADULT_prostitute;strcpy(ctext[r],					"A Very Outgoing Young Woman With Terrible Fashion Sense Who Seems To Be Trying To Hitch A Ride");}

					if(c==102){gfx[r]=GFX_ADULT_hustler;strcpy(ctext[r],						"The Young Woman's Very Unfriendly Boyfriend With Even Worse Fashion Sense");}
					//if(c==137){gfx[r]=dancer_GFX;strcpy(ctext[r],"A Young Woman Who Is Dancing Her Way Into Show Business");}

					if(c==103){gfx[r]=GFX_ADULT_mechanic;strcpy(ctext[r],					"The Mechanic Who Can Find $10,000 Of Absolutely Necessary Repairs On A Brand New Car");}
					if(c==104){gfx[r]=GFX_ADULT_terrorist;strcpy(ctext[r],					"A Man Who Is Definitely Not Suspicious At All And Is Doing Nothing Unusual");}
					if(c==105){gfx[r]=GFX_ADULT_quack;strcpy(ctext[r],						"A Doctor Who Will Prescribe Pain Medication For Any Reason And Is Probably Not Really A Doctor");}
					if(c==106){gfx[r]=GFX_ADULT_hobo;strcpy(ctext[r],						"A Man Who Drinks Cleaning Solvent From A Paper Bag And Yells At People In A Foreign Language");}
					if(c==107){gfx[r]=GFX_ADULT_beggar;strcpy(ctext[r],					"A Man Who Only Needs 50 More Cents For A Bus Ticket For The Last Several Years");}

					if(c==108){gfx[r]=GFX_ADULT_samurai;strcpy(ctext[r],					"The Wandering Samurai Who Is Beginning To Regret His Career Choice");}
					if(c==109){gfx[r]=GFX_ADULT_ninja;strcpy(ctext[r],						"The Very Obvious Ninja Who Prides Himself On His Ability To Hide In Plain Sight");}
					if(c==110){gfx[r]=GFX_ADULT_karateguy;strcpy(ctext[r],					"The Over Enthusiastic Karate Student Who Consistently Fails At Breaking Bricks With His Head");}
					if(c==111){gfx[r]=GFX_ADULT_kungfumaster;strcpy(ctext[r],				"The Martial Arts Master Who Is Really Only Very Good At Saying \"Waaah!\"");}
					if(c==112){gfx[r]=GFX_ADULT_wiseman;strcpy(ctext[r],					"A Very Wise-Looking Man Who Gives Very Cryptic Advice That Usually Makes No Sense");}

					if(c==113){gfx[r]=GFX_ADULT_momo;strcpy(ctext[r],						"The Guy Who Has Been Waiting For Disco To Come Back For Most Of His Life");}
					if(c==114){gfx[r]=GFX_ADULT_oldmomo;strcpy(ctext[r],					"The Disco Guy's Twin Whose Life Was Ruined By Being Constantly Mistaken For His Very Embarrassing Brother");}
					if(c==115){gfx[r]=GFX_ADULT_transvestite;strcpy(ctext[r],				"A Bearded Individual In A Dress That Nobody Is Quite Sure Whether To Call Sir Or Madam");}
					if(c==116){gfx[r]=GFX_ADULT_cultenlister;strcpy(ctext[r],				"A Very Friendly Man Who Really Wants You To Join His Forehead Drilling Club");}
					if(c==117){gfx[r]=GFX_ADULT_hermit;strcpy(ctext[r],					"The Heavily Bearded Forest Hermit Who Has Been Hiding From His Wife In The Backyard For A Decade");}
					if(c==118){gfx[r]=GFX_ADULT_tinfoilhatman;strcpy(ctext[r],				"A Very Paranoid Man Who Wears A Metal Hat To Keep Out The Mind Rays And Probably Drinks Too Much Coffee");}
					if(c==119){gfx[r]=GFX_ADULT_monk;strcpy(ctext[r],						"The Hooded Monk Who Has Not Yet Achieved Enlightenment But Is Pretty Sure He Will Soon");}
					if(c==120){gfx[r]=GFX_ADULT_islandhermit;strcpy(ctext[r],				"The Man Who Thinks He Is Stranded On A Deserted Island But Is Actually A Mile From Home");}

					if(c==121){gfx[r]=GFX_ADULT_ghost;strcpy(ctext[r],						"A Translucent Man Who Materializes At Night And Says He Is Suspicious Of The New Maid");}
					if(c==122){gfx[r]=GFX_ADULT_superhero;strcpy(ctext[r],					"A Caped Man In Spandex Who May Or May Not Have Any Actual Super Powers");}
					//if(c==144){gfx[r]=robot_GFX;strcpy(ctext[r],"The Very Loud And Completely Useless $1,000,000 Chunk Of Metal");}
					if(c==123){gfx[r]=GFX_ADULT_bubbleheadcyborg;strcpy(ctext[r],			"A Man With A Very Cool Futuristic Transplanted Head Who Wonders Why He Can't Get A Girlfriend");}

					//if(c==146){gfx[r]=buddy_GFX;strcpy(ctext[r]," ");}
					if(c==124){gfx[r]=GFX_ADULT_bob;strcpy(ctext[r],						"Some Dude Who Locked Himself In A Room For Five Years And Made A Really Awesome Video Game");}
					if(c==125){gfx[r]=GFX_ADULT_bob;strcpy(ctext[r],						"copyright 2003-2011 robert pelloni. bobsgame.com");}



					if(gfx[r]->adult==1)sizey[r]=40;
					else sizey[r]=32;

					c++;
		}



//figure out the size of the image
//create giant rgba array
//cap the screen at certain points and add to array
//output array as image

		int half_screen_width = MAP_cam_x+(GAME_VIEWPORT_WIDTH_PIXELS/2);
		int bottom_off_screen = MAP_cam_y+GAME_VIEWPORT_HEIGHT_PIXELS-32;
		int half_screen_height = MAP_cam_y+(GAME_VIEWPORT_HEIGHT_PIXELS/2);

		if(NAME_npc[r]==NULL&&NAME2_npc[r]==NULL)
		{


			int font = FONT_SMALL_ID;
			int px = CAPTION_get_pixel_length((char*)ctext[r],font)/2;
			if(c==1||c==145)px=px*2;
			int cx= 0;



			if(npcs[r]==2)
			{
				NPC_create_npc_xy_feet(&NAME_npc[r],gfx[r],16,sizey[r],half_screen_width-32+4,0);
				NAME_npc[r]->layer=2;
				NAME_npc[r]->non_walkable=1;
				NAME_npc[r]->scale=2;
				NPC_animate_stand_dir(&NAME_npc[r],DOWN);
				NAME_npc[r]->walking_speed = SPEED_NORMAL;
				NAME_npc[r]->AI=0;

				NPC_create_npc_xy_feet(&NAME2_npc[r],gfx2[r],16,sizey[r],half_screen_width+16+4,0);
				NAME2_npc[r]->layer=2;
				NAME2_npc[r]->non_walkable=1;
				NAME2_npc[r]->scale=2;
				NPC_animate_stand_dir(&NAME2_npc[r],DOWN);
				NAME2_npc[r]->walking_speed = SPEED_NORMAL;
				NAME2_npc[r]->AI=0;

				cx=((14*8+16/2)-((px+8)/2))+8;

			}
			else

			{
				NPC_create_npc_xy_feet(&NAME_npc[r],gfx[r],16,sizey[r],half_screen_width-8,-64);
				NAME_npc[r]->layer=2;
				NAME_npc[r]->non_walkable=1;
				NAME_npc[r]->scale=2;
				NPC_animate_stand_dir(&NAME_npc[r],DOWN);
				NAME_npc[r]->walking_speed = SPEED_NORMAL;
				NAME_npc[r]->AI=0;

				cx=((14*8+16/2)-((px+8)/2))+12; //center
			}

			//if(castcaption[r]==NULL)CAPTION_make_caption(&castcaption[r],1,cx,-24,-1,(char*)ctext[r],FONT_SMALL_ID,WHITE,BLACK,1,1);
			if(castcaption[r]==NULL)CAPTION_make_caption(&castcaption[r],1,CAPTION_CENTERED_X,-24,-1,(char*)ctext[r],FONT_SMALL_ID,WHITE,BLACK,1,1);

		}

		//if(c>49)
		t=0;//140; //time to pause in middle
		//else
		//if(c>39)
		//t=100;
		//else t=60;


	int s=0;
	for(s=0;s<2;s++)
	{




		if(npcs[s]==2)
		{

				if(NAME_npc[s]!=NULL)
				{
					int cy=NAME_npc[s]->screen_y+NAME_npc[s]->size_y*2+4;
					if(castcaption[s]!=NULL){castcaption[s]->screen_y = cy;}

					if(NAME_npc[s]->AI== 0){if(NPC_walk_to_xy_nohit(&NAME_npc[s],NAME_npc[s]->walking_speed,half_screen_width-32+4,half_screen_height)==1){NAME_npc[s]->AI=1;NAME_npc[s]->vbls=0;}}
					else if(NAME_npc[s]->AI== 1){if(NAME_npc[s]->vbls>t){append_screen=1;NAME_npc[s]->AI=2;NAME_npc[s]->vbls=0;if(r==0)r=1;else r=0;}}
					else if(NAME_npc[s]->AI== 2){if(NPC_walk_to_xy_nohit(&NAME_npc[s],NAME_npc[s]->walking_speed,half_screen_width-32+4,bottom_off_screen)==1){NAME_npc[s]->AI=3;NAME_npc[s]->vbls=0;}}
					else if(NAME_npc[s]->AI== 3){NPC_delete_npc(&NAME_npc[s]); NPC_delete_npc(&NAME2_npc[s]); CAPTION_delete_caption(castcaption[s]);}
				}

				if(NAME2_npc[s]!=NULL)
				{
					if(NAME2_npc[s]->AI== 0){if(NPC_walk_to_xy_nohit(&NAME2_npc[s],NAME2_npc[s]->walking_speed,half_screen_width+16+4,half_screen_height)==1){NAME2_npc[s]->AI=1;NAME2_npc[s]->vbls=0;}}
					else if(NAME2_npc[s]->AI== 1){if(NAME2_npc[s]->vbls>t){NAME2_npc[s]->vbls=0;NAME2_npc[s]->AI=2;}}
					else if(NAME2_npc[s]->AI== 2){if(NPC_walk_to_xy_nohit(&NAME2_npc[s],NAME2_npc[s]->walking_speed,half_screen_width+16+4,bottom_off_screen)==1){NAME2_npc[s]->AI=3;NAME2_npc[s]->vbls=0;}}
					else if(NAME2_npc[s]->AI== 3){NPC_delete_npc(&NAME2_npc[s]);}
				}
		}
		else
		{
				if(NAME_npc[s]!=NULL)
				{
					int cy=NAME_npc[s]->screen_y+NAME_npc[s]->size_y*2+4;
					if(castcaption[s]!=NULL){castcaption[s]->screen_y = cy;}

					if(NAME_npc[s]->AI== 0){if(NPC_walk_to_xy_nohit(&NAME_npc[s],NAME_npc[s]->walking_speed,half_screen_width-8,half_screen_height)==1){NAME_npc[s]->AI=1;NAME_npc[s]->vbls=0;}}
					else if(NAME_npc[s]->AI== 1){if(NAME_npc[s]->vbls>t){append_screen=1;NAME_npc[s]->vbls=0;NAME_npc[s]->AI=2;if(r==0)r=1;else r=0;}}
					else if(NAME_npc[s]->AI== 2){if(NPC_walk_to_xy_nohit(&NAME_npc[s],NAME_npc[s]->walking_speed,half_screen_width-8,bottom_off_screen)==1){NAME_npc[s]->AI=3;NAME_npc[s]->vbls=0;}}
					else if(NAME_npc[s]->AI== 3){NPC_delete_npc(&NAME_npc[s]); CAPTION_delete_caption(castcaption[s]);}

				}

				if(NAME2_npc[s]!=NULL){NPC_delete_npc(&NAME2_npc[s]);}
		}
	}




}

void bobsgame_MISCCastRoom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_MISCCastRoom_Map_VBL_Function()
{

}

void bobsgame_MISCCastRoom_Map_HBL_Function()
{

}

