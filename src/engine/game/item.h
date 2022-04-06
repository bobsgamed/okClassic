//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================
#ifndef ITEM_H
#define ITEM_H
//==============================================================================


struct ITEM
{
	char name[256];
	char description[2048];
	int amount;
};



//================
//defines
//================



//================
//variables
//================

extern ITEM* pocket[5];
extern int ITEM_items_in_pocket;



extern ITEM SuperGlue;
extern ITEM GameToyColors;
extern ITEM ElectricToothbrush;
extern ITEM LunchBag;
extern ITEM CoatHanger;
extern ITEM CannedAir;
extern ITEM LockPick;

extern ITEM GameToy;
extern ITEM Batteries;


//================
//prototypes
//================


bool ITEM_get(ITEM* item);
void ITEM_remove(ITEM* item);
bool ITEM_have(ITEM* item);
bool ITEM_get_no_caption(ITEM* item);

void ITEM_init_item_list();



/*
ITEM OrangeHandCleaner;
ITEM FakeTanningLotion;
ITEM SaunaJoggingSuit;
ITEM AbCrusher;
ITEM FleaCollar;
ITEM BaconShapedDogTreats;
ITEM HamsterBedding;
ITEM AquariumPebbles;
ITEM Fishbowl;
ITEM FuzzyGripTape;
ITEM HotGlueGun;
ITEM RazorBlade;
ITEM DisposableCamera;

ITEM SafetyGlasses;
ITEM FishingLine;
ITEM BowlingBallCleaner;
ITEM BikeTirePump;
ITEM YogaVideo;
ITEM WorkoutBall;
ITEM PuzzleCube;
ITEM BubbleMachine;
ITEM BouncyBall;
ITEM ActionFigure;
ITEM TradingCardGame;
ITEM PaperShredder;
ITEM BoardGame;
ITEM StickyStars;
ITEM TurkeyBaster;
ITEM Mothballs;
ITEM DigitalScale;
ITEM Chopsticks;
ITEM GripSqueezer;
ITEM MysteriousBalloon;
ITEM EggshellFoamPadding;
ITEM SevenPoundCanOfPudding;
ITEM Cane;
ITEM Bathrobe;
ITEM CookieScentedCandle;
ITEM FaceLotion;
ITEM FaceCleaner;
ITEM RustRemover;
ITEM Matchbook;
ITEM HairDye;
ITEM HairCurlers;
ITEM SwirlyStraw;
ITEM Clothespin;
ITEM FabricSoftenerSheet;
ITEM RubberGloves;
ITEM Tickets;
ITEM MichaelBoltanCD;
ITEM BugSpray;
ITEM FlyPaper;
ITEM GardenShears;
ITEM Sunglasses;
ITEM TikiTorch;
ITEM DaleUrnheartCalendar;
ITEM TrashyRomanceNovel;
ITEM JoggersDailyMagazine;
ITEM CoinCollectorDailyMagazine;
ITEM ModelRailroadManiac;
ITEM MachoGunMagazine;
ITEM RealMansHuntingMagazine;
ITEM TeenieBopMagazine;
ITEM Tampons;
ITEM DentureAdhesive;
ITEM MiniFlossers;
ITEM StretchBandageWrap;
ITEM NoseHairTrimmer;
ITEM RollOnDeodorant;
ITEM SprayDeodorant;
ITEM GelShoeInsoles;
ITEM CornCushions;
ITEM Eyedrops;

ITEM EarwaxRemovalKit;
ITEM CottonSwabs;
ITEM EyelashCurler;
ITEM Mascara;
ITEM Lipstick;
ITEM DigitalWatch;
ITEM FakeExpensiveWatch;
ITEM LintRoller;
ITEM MaternityBra;
ITEM MemoryFoamPillow;
ITEM ChipClip;
ITEM NonSlipBathtubMat;
ITEM FlipFlopSandals;
ITEM Flippers;
ITEM SpaceJumpBoots;
ITEM MoonBoots;
ITEM PinkHippoAlarmClock;
ITEM SuxBox;

ITEM Snowsuit;
ITEM GlowingTriangleThingy;
ITEM TreasureMap;
ITEM RocketSkates;
ITEM SillyPutty;
ITEM StickyHand;
ITEM BabyShutUps;
ITEM SugarStix;
ITEM PotionolPM;
ITEM ToiletPaperTube;
ITEM Flashlight;
*/




//==============================================================================
#endif
//==============================================================================

