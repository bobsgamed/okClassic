

#include "../../main.h"
//#include "item.h"

ITEM* pocket[5];
int ITEM_items_in_pocket=0;

ITEM SuperGlue;
ITEM GameToyColors;
ITEM ElectricToothbrush;
ITEM LunchBag;
ITEM CoatHanger;
ITEM CannedAir;
ITEM LockPick;

ITEM GameToy;
ITEM Batteries;


//=========================================================================================================================
bool ITEM_get(ITEM* item)
{//=========================================================================================================================
	if(ITEM_items_in_pocket<5)
	{
		pocket[ITEM_items_in_pocket]=item;
		ITEM_items_in_pocket++;
		char n[50] = "Yuu got ";
		strcat(n,item->name);
		strcat(n,"!");

		if(PLAYER_npc!=NULL)
		{
			CAPTION_make_caption(NULL,1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,5,n,FONT_OUTLINED_ID,LIGHTGREEN,BLACK,1,1);
		}
		else
		{
			CAPTION_make_caption(NULL,1,CAPTION_CENTERED_SCREEN,-1,5,n,FONT_OUTLINED_ID,LIGHTGREEN,BLACK,1,1);
		}
		HARDWARE_play_sound("gotitem",64,44100,0);
		return 1;
 	}
	else
	{
		char n[50] = "Yuu can't fit ";
		strcat(n,item->name);
		strcat(n," in his pocket.");
		CAPTION_make_caption(NULL,1,32,64,5,n,FONT_TINY_ID,RED,BLACK,1,1);
		return 0;
	}

	//if have backpack
	return 0;
}

//=========================================================================================================================
bool ITEM_get_no_caption(ITEM* item)
{//=========================================================================================================================
	if(ITEM_items_in_pocket<5)
	{
		pocket[ITEM_items_in_pocket]=item;
		ITEM_items_in_pocket++;
		char n[50] = "Yuu got ";
		strcat(n,item->name);
		strcat(n,"!");
		//CAPTION_make_caption(NULL,1,CAPTION_CENTERED_OVER_SPRITE,PLAYER_npc->screen_y-10,5,n,FONT_OUTLINED_ID,LIGHTGREEN,BLACK,1,1);
		return 1;
 	}
	else
	{
		char n[50] = "Yuu can't fit ";
		strcat(n,item->name);
		strcat(n," in his pocket.");
		//CAPTION_make_caption(NULL,1,32,64,5,n,FONT_TINY_ID,RED,BLACK,1,1);
		return 0;
	}

	//if have backpack
	return 0;
}

//=========================================================================================================================
void ITEM_remove(ITEM* item)
{//=========================================================================================================================
	int x=0;
	for(x=0;x<ITEM_items_in_pocket;x++)
	{
		if(pocket[x]==item)
		{
			int y=0;
			for(y=x;y<ITEM_items_in_pocket-1;y++)pocket[y]=pocket[y+1];
			pocket[ITEM_items_in_pocket-1]=NULL;
			ITEM_items_in_pocket--;

			x=ITEM_items_in_pocket+2;
			break;
		}
	}

}
//=========================================================================================================================
bool ITEM_have(ITEM* item)
{//=========================================================================================================================
	int x=0;
	for(x=0;x<ITEM_items_in_pocket;x++)
	{
		if(pocket[x]==item)
		{
			return 1;
		}
	}

	return 0;
}

//=========================================================================================================================
void ITEM_put_in_locker()
{//=========================================================================================================================

}
//=========================================================================================================================
void ITEM_get_from_locker()
{//=========================================================================================================================

}
//=========================================================================================================================
void ITEM_put_in_closet()
{//=========================================================================================================================

}
//=========================================================================================================================
void ITEM_get_from_closet()
{//=========================================================================================================================

}


//=========================================================================================================================
void ITEM_init_item_list()
{//=========================================================================================================================
/*
OrangeHandCleaner.amount=0;
OrangeHandCleaner.name = "Orange Hand Cleaner";
OrangeHandCleaner.description = "Gritty pumice hand cleaner with an orange-y chemical scent. It almost makes you want to taste it...";
///////////////

FakeTanningLotion.amount=0;
FakeTanningLotion.name = "Fake Tanning Lotion";
FakeTanningLotion.description = "A specially formulated dye to enhance your skin color. Impress the ladies with an artificial hue! (Just don't get wet..)";
///////////////

SaunaJoggingSuit.amount=0;
SaunaJoggingSuit.name = "Sauna Jogging Suit";
SaunaJoggingSuit.description = "A workout suit that traps in body heat and moisture. Raise your body temperature to lethal levels and sweat away that fat! Seems like a good idea, right?";
///////////////

AbCrusher.amount=0;
AbCrusher.name = "Ab Crusher";
AbCrusher.description = "An overpriced wheel with handles, theoretically designed to make abdominal workouts fun and exciting. Also designed to fold up and easily fit in the closet, where it will stay indefinitely.";
///////////////

FleaCollar.amount=0;
FleaCollar.name = "Flea Collar";
FleaCollar.description = "A chemically treated dog collar for the lazy owner that doesn't want to give Rover a bath. Also great for lazy owners that don't want to give themselves a bath.";
//////////////

BaconShapedDogTreats.amount=0;
BaconShapedDogTreats.name = "Bacon Shaped Dog Treats";
BaconShapedDogTreats.description = "Scrumptious morsels manufactured to look like REAL BACON! Obviously designed by Poison Control Centers to bring in more business, since dogs don't know what bacon looks like, and small children do!";
///////////////

HamsterBedding.amount=0;
HamsterBedding.name = "Hamster Bedding";
HamsterBedding.description = "Aromatic, absorbent sawdust that disguises the stink of hamster droppings with the overwhelming stink of cedar! I wonder why he keeps trying to get out of his cage?";
///////////////

AquariumPebbles.amount=0;
AquariumPebbles.name = "Aquarium Pebbles";
AquariumPebbles.description = "Small artificial stones for aquarium decoration, for merely several times the cost of actual pebbles!";
//////////////

Fishbowl.amount=0;
Fishbowl.name = "Fishbowl";
Fishbowl.description = "A round glass prison of doom for our friendly aquatic pals. Fill it with designer artificial rocks and shake it up for a spectacular snow-globe effect!";
///////////////

FuzzyGripTape.amount=0;
FuzzyGripTape.name = "Fuzzy Grip Tape";
FuzzyGripTape.description = "Unfortunately not developed by lazy highly-paid engineers at NASA as the common myth states, but lazy highly-paid NASA engineers probably use it instead of tying their shoes.";
///////////////

HotGlueGun.amount=0;
HotGlueGun.name = "Hot Glue Gun";
HotGlueGun.description = "A far more convenient adhesive than normal glue, as long as you don't mind waiting around for it to heat up. Good for insulating wires and causing first-degree burns.";
///////////////

RazorBlade.amount=0;
RazorBlade.name = "Razor Blade";
RazorBlade.description = "A very sharp piece of metal with practically no handle. Comes with a free bonus package of adhesive bandages!";
///////////////

DisposableCamera.amount=0;
DisposableCamera.name = "Disposable Camera";
DisposableCamera.description = "A fantastic way of keeping priceless memories undeveloped in a junk drawer for decades!";
///////////////


///////////////

SafetyGlasses.amount=0;
SafetyGlasses.name = "Safety Glasses";
SafetyGlasses.description = "Cheap protective unstylish eyewear made of bulky, blurry plastic. You may not be able to see what you're doing, but at least it won't get in your eyes!";
///////////////

FishingLine.amount=0;
FishingLine.name = "Fishing Line";
FishingLine.description = "Very strong, easily tangled nylon string conveniently rolled into a circular package that it will never fit back into.";
///////////////

BowlingBallCleaner.amount=0;
BowlingBallCleaner.name = "Bowling Ball Cleaner";
BowlingBallCleaner.description = "For the bowling maniac in everybody! Doesn't help roll a perfect game, but your gutterballs have never been this shiny!";
///////////////

BikeTirePump.amount=0;
BikeTirePump.name = "Bike Tire Pump";
BikeTirePump.description = "A flimsy tire pump that lets half of the air back out while you try to wrestle the nozzle off of the air spout.";
///////////////

YogaVideo.amount=0;
YogaVideo.name = "Yoga Video";
YogaVideo.description = "A new-age hobby borrowed from the Orient for bored housewives trying to annoy their husband. Learn to stretch in embarrassing ways while following the guidance of a genuine, authentic Caucasian yoga master!";
///////////////

WorkoutBall.amount=0;
WorkoutBall.name = "Workout Ball";
WorkoutBall.description = "A very large inflatable rubber ball, somehow useful for aerobic exercise.";
///////////////

PuzzleCube.amount=0;
PuzzleCube.name = "Puzzle Cube";
PuzzleCube.description = "Nobody can solve it without replacing the stickers, except for some crazy guy who can do it in 8 seconds. That guy is awesome. Sort of.";
///////////////

BubbleMachine.amount=0;
BubbleMachine.name = "Bubble Machine";
BubbleMachine.description = "Just pour in liquid bubble solution and save the trouble of exhaling! Drive the dog insane without the slightest effort.";
///////////////

BouncyBall.amount=0;
BouncyBall.name = "Bouncy Ball";
BouncyBall.description = "Made of a space-age material that defies the laws of gravity. Secretly left on Earth by aliens attempting to stifle human knowledge, setting back modern Physics hundreds of years.";
///////////////

ActionFigure.amount=0;
ActionFigure.name = "Action Figure";
ActionFigure.description = "A molded piece of plastic, extremely overpriced and marketed through children's television shows. Limited edition in shiny eye-catching packaging that subconsciously induces a state of whiny, screaming begging in all children who glance at it.";
///////////////

TradingCardGame.amount=0;
TradingCardGame.name = "Trading Card Game";
TradingCardGame.description = "Very addictive and expensive video-game themed collectible card game. Sold in decks and drug-like \"boost\" packs, milking the kids for ever last cent of allowance. Coming Soon: BUTTON MASH CCG! Can YUU collect every rare foil card?!";
//////////////

PaperShredder.amount=0;
PaperShredder.name = "Paper Shredder";
PaperShredder.description = "The best way to dispose of confidential documents that nobody cares about, one sheet at a time. Advertised to handle 20 sheets at once without jamming. Coincidentally tested with molecule-thin super-paper.";
///////////////

BoardGame.amount=0;
BoardGame.name = "Board Game";
BoardGame.description = "Great fun for the whole family! Comes with pieces already missing, for the parent's relief. Everyone gets sick of it halfway through anyway.";
///////////////

StickyStars.amount=0;
StickyStars.name = "Sticky Stars";
StickyStars.description = "Motivational tool for teachers to hold over hyperactive kids who like shiny things. Nobody ever actually gets one.";
///////////////

TurkeyBaster.amount=0;
TurkeyBaster.name = "Turkey Baster";
TurkeyBaster.description = "A gigantic eyedropper, useful for absolutely nothing.";
///////////////

Mothballs.amount=0;
Mothballs.name = "Mothballs";
Mothballs.description = "Small foam balls saturated with the scent of old ladies. Great for keeping stale clothes smelling even staler.";
///////////////

DigitalScale.amount=0;
DigitalScale.name = "Digital Scale";
DigitalScale.description = "A modern scale, accurate to 3 decimal points, that shows a completely different weight each time you step on it.";
///////////////

Chopsticks.amount=0;
Chopsticks.name = "Chopsticks";
Chopsticks.description = "A pair of wooden disposable chopsticks, guaranteed to break unevenly.";
///////////////

GripSqueezer.amount=0;
GripSqueezer.name = "Grip Squeezer";
GripSqueezer.description = "Tone those hand muscles to sexy proportions. For the obsessive weight-lifting enthusiast.";
///////////////

MysteriousBalloon.amount=0;
MysteriousBalloon.name = "Mysterious Balloon";
MysteriousBalloon.description = "This balloon is oddly shaped, and kind of slimy. I don't think you should touch that.";
///////////////

EggshellFoamPadding.amount=0;
EggshellFoamPadding.name = "Eggshell Foam Padding";
EggshellFoamPadding.description = "Yellowed mattress padding that increases comfort by 0%.";
///////////////

SevenPoundCanOfPudding.amount=0;
SevenPoundCanOfPudding.name = "7 Pound Can of Pudding";
SevenPoundCanOfPudding.description = "Bulk tapioca pudding. Can you eat the whole can in one sitting?";
///////////////

Cane.amount=0;
Cane.name = "Cane";
Cane.description = "A walking aid for the elderly. Also suitable for teenagers pretending to be a dandy-man.";
///////////////

Bathrobe.amount=0;
Bathrobe.name = "Bathrobe";
Bathrobe.description = "An unnecessary item of clothing for the 10 seconds between the bathroom and closet. Worn by sleazy, lazy game developers. Goes well with a pink light bulb.";
///////////////

CookieScentedCandle.amount=0;
CookieScentedCandle.name = "Cookie Scented Candle";
CookieScentedCandle.description = "A candle that smells like freshly-baked cookies. The wick must be dug out of the wax with a knife after each use.";
///////////////

FaceLotion.amount=0;
FaceLotion.name = "Face Lotion";
FaceLotion.description = "Moisturizer to replenish skin dried out from harsh cleaners.";
///////////////

FaceCleaner.amount=0;
FaceCleaner.name = "Face Cleaner";
FaceCleaner.description = "Cleaner to remove greasy moisturizers.";
///////////////

RustRemover.amount=0;
RustRemover.name = "Rust Remover";
RustRemover.description = "Watch rust vanish before your very eyes! Caution: Highly corrosive. Do not use on metal.";
///////////////

Matchbook.amount=0;
Matchbook.name = "Matchbook";
Matchbook.description = "A book of safety matches. Good for clearing out a stinky bathroom. Keep out of reach of children.";
///////////////

HairDye.amount=0;
HairDye.name = "Hair Dye";
HairDye.description = "Permanent, odor-free, \"Natural Blue-Black\" colored dye- Great for gray coverage! Lasts 10 washes. Use in ventilated area. Not recommended for use on gray hair.";
///////////////

HairCurlers.amount=0;
HairCurlers.name = "Hair Curlers";
HairCurlers.description = "The perfect fashion accessory for insane middle-aged housewives and grannies. Theoretically curls hair, but recommended for permanent wear.";
///////////////

SwirlyStraw.amount=0;
SwirlyStraw.name = "Swirly Straw";
SwirlyStraw.description = "A reusable drinking straw twisted in wacky, fun shapes. Consuming liquid has never been so exciting!!! Impossible to clean.";
///////////////

Clothespin.amount=0;
Clothespin.name = "Clothespin";
Clothespin.description = "For hanging clothes on a clothesline. Waterproof for when it rains. Also used for clamping your nose shut in stinky situations.";
///////////////

FabricSoftenerSheet.amount=0;
FabricSoftenerSheet.name = "Fabric Softener Sheet";
FabricSoftenerSheet.description = "Prevent static cling and give your clothes a fresh scent. Usually gets stuck in your shirt and falls out in an embarrassing public situation.";
///////////////

RubberGloves.amount=0;
RubberGloves.name = "Rubber Gloves";
RubberGloves.description = "Thick waterproof dishwashing gloves. Your hands somehow are always wet anyway when you take them off. Impossible to put back on.";
///////////////

Tickets.amount=0;
Tickets.name = "Tickets";
Tickets.description = "A roll of numbered tear-off tickets. Probably used for a raffle.";
///////////////

MichaelBoltanCD.amount=0;
MichaelBoltanCD.name = "Michael Boltan CD";
MichaelBoltanCD.description = "A contemporary album of smooth, easy-listening tunes. Each beautifully crafted song will take you on a journey to a new world, higher and higher, much like an elevator.";
///////////////

BugSpray.amount=0;
BugSpray.name = "Bug Spray";
BugSpray.description = "A bottle of putrid liquid that does nothing to repel insects. Smells like camping.";
///////////////

FlyPaper.amount=0;
FlyPaper.name = "Fly Paper";
FlyPaper.description = "A sticky, scented piece of paper to trap buzzing pests. The perfect decoration for a classy joint.";
///////////////

GardenShears.amount=0;
GardenShears.name = "Garden Shears";
GardenShears.description = "Gigantic scissors that could take your hand off. The weapon of choice for every seemingly-innocent nice old lady.";
///////////////

Sunglasses.amount=0;
Sunglasses.name = "Sunglasses";
Sunglasses.description = "A pair of brand-name sunglasses that make you think you look cool. Nobody else thinks so. Recommended for indoor use for even more fake-cool factor.";
///////////////

TikiTorch.amount=0;
TikiTorch.name = "Tiki Torch";
TikiTorch.description = "A lawn decoration that goes exceptionally well with trailer homes.";
///////////////

DaleUrnheartCalendar.amount=0;
DaleUrnheartCalendar.name = "Dale Urnheart Calendar";
DaleUrnheartCalendar.description = "Keep track of the days passed since the legend himself took the big drive. Life just isn't the same.";
///////////////

TrashyRomanceNovel.amount=0;
TrashyRomanceNovel.name = "Trashy Romance Novel";
TrashyRomanceNovel.description = "\"As he tightly pulled her close, she began to blush and pressed her reddening ear to his glistening, heaving chest. His heart was beating with a passion that drove her into the very heights of desire. Her hand..\" This is ridiculous.";
///////////////

JoggersDailyMagazine.amount=0;
JoggersDailyMagazine.name = "Joggers Daily Magazine";
JoggersDailyMagazine.description = "\"15 new ways to sculpt those calves! We review major shoe inserts inside! Are you wearing the right shorts?\" Fascinating.";
///////////////

CoinCollectorDailyMagazine.amount=0;
CoinCollectorDailyMagazine.name = "Coin Collector Daily Magazine";
CoinCollectorDailyMagazine.description = "\"The Hottest Coins This Month! Do You Have A Hidden Treasure In Your Collection?\" Interesting. Well, maybe not in the way they intend, anyway.";
///////////////

ModelRailroadManiac.amount=0;
ModelRailroadManiac.name = "Model Railroad Maniac";
ModelRailroadManiac.description = "\"Trainspotting FEVER! Experience the excitement of logging passing trains!\" These guys are hilariously amazing. Respect to you, rail otaku.";
///////////////

MachoGunMagazine.amount=0;
MachoGunMagazine.name = "Macho Gun Magazine";
MachoGunMagazine.description = "How many guns does one man need?! Nevermind. Best not to bother anyone buying these.";
///////////////

RealMansHuntingMagazine.amount=0;
RealMansHuntingMagazine.name = "Real Man's Hunting Magazine";
RealMansHuntingMagazine.description = "There's a scratch and sniff advertisement for beef jerky. I'm hungry. Oh, and one for deer urine. I'm not hungry.";
///////////////

TeenieBopMagazine.amount=0;
TeenieBopMagazine.name = "Teenie Bop Magazine";
TeenieBopMagazine.description = "Oooooooh... Kyle is such a hottie! I just, like, NEED to buy some of that lip gloss!";
///////////////

Tampons.amount=0;
Tampons.name = "Tampons";
Tampons.description = "Not sure what these are for. Odor absorbing and twice the capacity of the leading competing brand, though.";
///////////////

DentureAdhesive.amount=0;
DentureAdhesive.name = "Denture Adhesive";
DentureAdhesive.description = "Mint flavored glue for old people's mouths. Does it glue their mouth shut if they use too much?";
///////////////

MiniFlossers.amount=0;
MiniFlossers.name = "Mini Flossers";
MiniFlossers.description = "Miniature disposable flossing tools for people without fingers.";
///////////////

StretchBandageWrap.amount=0;
StretchBandageWrap.name = "Stretch Bandage Wrap";
StretchBandageWrap.description = "Perfect for faking an injury to explain calling in yesterday.";
///////////////

NoseHairTrimmer.amount=0;
NoseHairTrimmer.name = "Nose Hair Trimmer";
NoseHairTrimmer.description = "A rotating blade for shoving up your nose. The more popular alternative to braiding.";
///////////////

RollOnDeodorant.amount=0;
RollOnDeodorant.name = "Roll-On Deodorant";
RollOnDeodorant.description = "More convenient than those pesky sprays. Never take a shower again!";
///////////////

SprayDeodorant.amount=0;
SprayDeodorant.name = "Spray Deodorant";
SprayDeodorant.description = "More convenient than those pesky tubes. Never change your clothes again!";
///////////////

GelShoeInsoles.amount=0;
GelShoeInsoles.name = "Gel Shoe Insoles";
GelShoeInsoles.description = "The package says the gel massages your feet as you walk. Bet it just squishes a little and gives you a foot cramp.";
///////////////

CornCushions.amount=0;
CornCushions.name = "Corn Cushions";
CornCushions.description = "Small circular pads to put on your disgusting, revolting foot sore.";
///////////////

Eyedrops.amount=0;
Eyedrops.name = "Eyedrops";
Eyedrops.description = "A bottle of mysterious chemicals to put into your eyes that remove redness and lubricate. The bottle says it's perfectly safe.";
///////////////


///////////////

EarwaxRemovalKit.amount=0;
EarwaxRemovalKit.name = "Earwax Removal Kit";
EarwaxRemovalKit.description = "Candle-making wick and instructions included.";
///////////////

CottonSwabs.amount=0;
CottonSwabs.name = "Cotton Swabs";
CottonSwabs.description = "Do not use in ear. Great for... swabbing things! Apply make-up! Clean delicate equipment! Really!";
///////////////

EyelashCurler.amount=0;
EyelashCurler.name = "Eyelash Curler";
EyelashCurler.description = "A creepy mechanical contraption to hold to your eye and squeeze. Makes seduction easy! Never work again!";
///////////////

Mascara.amount=0;
Mascara.name = "Mascara";
Mascara.description = "A black substance to coat eyelashes. Trick them into thinking you're good-looking! Never work again!";
///////////////

Lipstick.amount=0;
Lipstick.name = "Lipstick";
Lipstick.description = "A red substance to coat lips. Deceive them into thinking you're healthy and youthful. Never work again!";
///////////////

DigitalWatch.amount=0;
DigitalWatch.name = "Digital Watch";
DigitalWatch.description = "Submersible to 2000 meters. Scratch resistant to anything that isn't sharp. The alarm randomly goes off in movie theaters.";
///////////////

FakeExpensiveWatch.amount=0;
FakeExpensiveWatch.name = "Fake Expensive Watch";
FakeExpensiveWatch.description = "Impressive looking fake diamonds and gold. Hey, the numbers aren't even in the right order.";
///////////////

LintRoller.amount=0;
LintRoller.name = "Lint Roller";
LintRoller.description = "A roll of sticky tape to remove flaws like dog hair and lint from clothing. It'll never remove your personality flaws like obsessive perfectionism.";
///////////////

MaternityBra.amount=0;
MaternityBra.name = "Maternity Bra";
MaternityBra.description = "Wowza. This gigantic thing's got holes in it. Lucky little tyke.";
///////////////

MemoryFoamPillow.amount=0;
MemoryFoamPillow.name = "Memory Foam Pillow";
MemoryFoamPillow.description = "A fancy pillow that your head sinks into like a cloud, only to wake up suffocating and drenched in sweat.";
///////////////

ChipClip.amount=0;
ChipClip.name = "Chip Clip";
ChipClip.description = "A clip you remember to put on the bag of chips after it's already gone stale.";
///////////////

NonSlipBathtubMat.amount=0;
NonSlipBathtubMat.name = "Non-Slip Bathtub Mat";
NonSlipBathtubMat.description = "For the person afraid of showering \"on the edge.\"";
///////////////

FlipFlopSandals.amount=0;
FlipFlopSandals.name = "Flip-Flop Sandals";
FlipFlopSandals.description = "The finest in quality fashion footwear.";
///////////////

Flippers.amount=0;
Flippers.name = "Flippers";
Flippers.description = "Improve your swimming speed by 200%. Decrease your walking speed by 500%.";
///////////////

SpaceJumpBoots.amount=0;
SpaceJumpBoots.name = "Space Jump Boots";
SpaceJumpBoots.description = "They give you the ability to repeatedly jump indefinitely. The HIGH JUMP boots make you jump higher. Get your own franchise right, idiots.";
///////////////

MoonBoots.amount=0;
MoonBoots.name = "Moon Boots";
MoonBoots.description = "These boots with rubber strips give the illusion of jumping higher. They also make you look stupid and fall over.";
///////////////

PinkHippoAlarmClock.amount=0;
PinkHippoAlarmClock.name = "Pink Hippo Alarm Clock";
PinkHippoAlarmClock.description = "The most irritating device ever invented by mankind will start your morning off with pure hatred for the universe.";
///////////////

SuxBox.amount=0;
SuxBox.name = "SuxBox";
SuxBox.description = "This huge, gaudy computer with a brick-shaped controller, overmarketed into existence by a SOFTware company, seemingly violates anti-monopoly laws. It sometimes sets on fire, and is somehow very popular. Many quality games for the system were bribed by deep pockets.";
///////////////



Snowsuit.amount=0;
Snowsuit.name = "Snowsuit";
Snowsuit.description = "This enchanted magical item provides mysterious protection from coldness damage.";
///////////////

GlowingTriangleThingy.amount=0;
GlowingTriangleThingy.name = "Glowing Triangle Thingy";
GlowingTriangleThingy.description = "A glowing arrangement of golden mystical triangles with seemingly unimaginable power. This seems important somehow.";
///////////////

TreasureMap.amount=0;
TreasureMap.name = "Treasure Map";
TreasureMap.description = "An old, tattered piece of yellowed paper with a handmade map of the area drawn on it. There is a faded X mark where the local BobMart now stands. Figures.";
///////////////

RocketSkates.amount=0;
RocketSkates.name = "Rocket Skates";
RocketSkates.description = "A pair of roller skates with a miniature jet engine attached to each foot. Looks like the most incredibly fun death trap ever invented.";
///////////////

SillyPutty.amount=0;
SillyPutty.name = "Silly Putty";
SillyPutty.description = "An egg shaped container with foul-smelling plastic putty inside. Can be used to copy newsprint, or get stuck on the carpet.";
///////////////

StickyHand.amount=0;
StickyHand.name = "Sticky Hand";
StickyHand.description = "A stretchy, sticky, transparent rubber hand that leaves oily residue on everything it touches. Becomes covered in dirt and useless almost immediately.";
///////////////

BabyShutUps.amount=0;
BabyShutUps.name = "Baby Shut-Ups";
BabyShutUps.description = "An infant pacifier laced with a mild tranquilizer. Absolutely brilliant! They should have thought of this sooner.";
///////////////

SugarStix.amount=0;
SugarStix.name = "Sugar Stix";
SugarStix.description = "Designed in the former Soviet Union as a convoluted Communist plot to increase the activity of America's most destructive force: hyperactive children. Take it down from the inside...";
///////////////

PotionolPM.amount=0;
PotionolPM.name = "Potion-ol PM";
PotionolPM.description = "A pain reliever tablet with a light sleeping aid that restores HP and knocks you out cold.";
///////////////

ToiletPaperTube.amount=0;
ToiletPaperTube.name = "Toilet Paper Tube";
ToiletPaperTube.description = "An empty roll of toilet paper. Does it smell weird, or is that your imagination?";


Flashlight.amount=0;
Flashlight.name = "Flashlight";
Flashlight.description = "Great for when the power goes out, if only you could see where you put it.";
*/




GameToyColors.amount=0;
strcpy(GameToyColors.name,"GameToy Colors");
strcpy(GameToyColors.description,"It's a slight improvement over the original GameToy, with basic color support. Unfortunately, only 6 games use them.");



LunchBag.amount=0;
strcpy(LunchBag.name,"Lunch Bag");
strcpy(LunchBag.description,"It's a peanut butter sandwich again. The bread is transparent and goopy where the jelly is bleeding through.");


Batteries.amount=0;
strcpy(Batteries.name,"Batteries");
strcpy(Batteries.description,"If you press hard enough to break your fingers, the built in tester always says full regardless of charge!");
//gives you a handy readout- that
GameToy.amount=0;
strcpy(GameToy.name,"GameToy");
strcpy(GameToy.description,"This ancient toaster-sized handheld system is the shining point of a whole generation's childhood.");// The screen is tiny and hideous. Can stop bullets. It's kind of sticky.";
///////////////


LockPick.amount=0;
strcpy(LockPick.name,"Auto Lockpick");
strcpy(LockPick.description,"It's actually just a coat hanger glued to an electric toothbrush, but it should do the trick.");



SuperGlue.amount=0;
strcpy(SuperGlue.name,"Super Glue");
strcpy(SuperGlue.description,"Fast acting adhesive that instantly bonds skin to anything. Smells horrible.");


ElectricToothbrush.amount=0;
strcpy(ElectricToothbrush.name,"Electric Toothbrush");
strcpy(ElectricToothbrush.description,"For the on-the-go person too busy to rotate their hand. The next best thing since automatic toilet paper!");


CoatHanger.amount=0;
strcpy(CoatHanger.name,"Coat Hanger");
strcpy(CoatHanger.description,"It's a coat hanger.");



CannedAir.amount=0;
strcpy(CannedAir.name,"Canned Air");
strcpy(CannedAir.description,"Used primarily for spraying freezing liquid at people. Sometimes used to clean electronics, for those too lazy to breathe.");


}








