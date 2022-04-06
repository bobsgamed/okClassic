//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================




#include "../../main.h"





NPC* schoolflag_npc 			= NULL;
NPC* schoolxingsign1_npc	= NULL;
NPC* schoolxingsign2_npc	= NULL;
NPC* clinicsign1_npc 		= NULL;
NPC* clinicsign2_npc 		= NULL;
NPC* disorderofbobsign_npc	= NULL;
NPC* stainedglasswindow1_npc 		= NULL;
NPC* stainedglasswindow2_npc 		= NULL;
NPC* stainedglasswindow3_npc 		= NULL;
NPC* stainedglasswindow4_npc 		= NULL;
NPC* stainedglasswindow5_npc 		= NULL;
NPC* stainedglasswindow6_npc 		= NULL;
NPC* tacoburgersign1_npc	= NULL;
NPC* tacoburgersign2_npc	= NULL;
NPC* tacoburgersign3_npc	= NULL;
NPC* trafficlightfaceup1_npc 		= NULL;
NPC* trafficlightfaceup2_npc 		= NULL;
NPC* townstreetsign1_npc	= NULL;
NPC* townstreetsign2_npc	= NULL;
NPC* gasstationsign1_npc	= NULL;
NPC* gasstationsign2_npc	= NULL;
NPC* gasstationsign3_npc	= NULL;
NPC* city50milessign1_npc	= NULL;
NPC* city50milessign2_npc	= NULL;
NPC* coffeecafesign1_npc	= NULL;
NPC* coffeecafesign2_npc	= NULL;
NPC* bookstoresign1_npc 	= NULL;
NPC* bookstoresign2_npc 	= NULL;
NPC* pizzasign1_npc 			= NULL;
NPC* pizzasign2_npc 			= NULL;
NPC* pizzasign3_npc 			= NULL;
NPC* pizzasign4_npc 			= NULL;
NPC* pizzasign5_npc 			= NULL;
NPC* beautysalon1_npc 		= NULL;
NPC* beautysalon2_npc 		= NULL;
NPC* tanningsign_npc 		= NULL;
NPC* nailssign_npc 			= NULL;
NPC* hairsign_npc 			= NULL;
NPC* pets4lesssign_npc 		= NULL;
NPC* cutesign_npc 			= NULL;
NPC* cheapsign_npc 			= NULL;
NPC* departmentsign1_npc	= NULL;
NPC* departmentsign2_npc	= NULL;
NPC* grocerysign1_npc 		= NULL;
NPC* grocerysign2_npc 		= NULL;
NPC* grocerysign3_npc 		= NULL;
NPC* electronicssign_npc	= NULL;
NPC* videosign1_npc 			= NULL;
NPC* videosign2_npc 			= NULL;
NPC* videosign3_npc 			= NULL;
NPC* videosign4_npc 			= NULL;
NPC* gamestoresign_npc 		= NULL;
NPC* arcadesign1_npc 		= NULL;
NPC* arcadesign2_npc 		= NULL;
NPC* arcadesign3_npc 		= NULL;
NPC* arcadesign4_npc 		= NULL;
NPC* arcadesign5_npc 		= NULL;
NPC* arcadesign6_npc 		= NULL;
NPC* musicsign1_npc 			= NULL;
NPC* musicsign2_npc 			= NULL;
NPC* musicsign3_npc 			= NULL;
NPC* musicsign4_npc 			= NULL;
NPC* musicsign5_npc 			= NULL;
NPC* musicsign6_npc 			= NULL;
NPC* movietheatresign1_npc	= NULL;
NPC* movietheatresign2_npc	= NULL;
NPC* stopsign1_npc 			= NULL;
NPC* stopsign2_npc 			= NULL;
NPC* stopsign3_npc 			= NULL;
NPC* townstreetsign3_npc	= NULL;
NPC* townstreetsign4_npc	= NULL;
NPC* suburblanesign1_npc	= NULL;
NPC* suburblanesign2_npc	= NULL;
NPC* schoolsign1_npc		= NULL;
NPC* schoolsign2_npc		= NULL;
NPC* stopsign4_npc		 = NULL;
NPC* gardenhose1_npc		= NULL;
NPC* grill1_npc				= NULL;
NPC* lawnbenchfacedown1_npc	= NULL;
NPC* lawnbenchfacedown2_npc	= NULL;
NPC* lawnchairfaceright1_npc	= NULL;
NPC* lawnchairfaceleft1_npc	= NULL;
NPC* gardenhose2_npc		= NULL;
NPC* lawnchairfacedown3_npc	= NULL;
NPC* grill2_npc			 = NULL;
NPC* lawnchairfaceright2_npc	= NULL;
NPC* lawnchairfaceleft2_npc	= NULL;
NPC* gardenhose3_npc		= NULL;
NPC* lawnchairfaceright3_npc	= NULL;
NPC* lawnchairfaceleft3_npc	= NULL;
NPC* lawnchairfacedown4_npc	= NULL;
NPC* grill3_npc			= NULL;
NPC* schoolxingsign3_npc = NULL;
NPC* schoolxingsign4_npc = NULL;

NPC* car_npc[16] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};



int mailman_came_today=0;
int icecreamman_came_today=0;
int jogger_came_today=0;
int dogwalker_came_today=0;

int hit_by_car=0;
int hit_direction_x=0;
int hit_direction_y=0;
int car_init=0;


NPC* crossingguard_npc=NULL;
NPC* randomcrosswalkkid1_npc = NULL;
NPC* randomcrosswalkkid2_npc = NULL;
NPC* randomcrosswalkkid3_npc = NULL;
NPC* randomcrosswalkkid4_npc = NULL;



NPC* droppedoffkid_npc=NULL;
NPC* dropoffcar_npc=NULL;
NPC* bikerackbikes[5] = {NULL,NULL,NULL,NULL,NULL};


NPC* mailman_npc = NULL;

NPC* icecreamtruck_npc = NULL;
NPC* jogger_npc = NULL;






NPC* randomcrowd_npcs[60] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};



#define RANGE_OUTSIDETownPlaygroundToSCHOOLEntranceHallwayLeft 95*8,266*8,103*8,267*8
#define RANGE_OUTSIDETownPlaygroundToSCHOOLEntranceHallwayRight 194*8,266*8,202*8,267*8
#define RANGE_OUTSIDETownToSCHOOLEntranceHallwayLeft 230*8,274*8,238*8,275*8
#define RANGE_OUTSIDETownToSCHOOLEntranceHallwayMiddle 239*8,274*8,247*8,275*8
#define RANGE_OUTSIDETownToSCHOOLEntranceHallwayRight 248*8,274*8,256*8,275*8
#define RANGE_OUTSIDETownToTOWNDoctorsOfficeEntrance 400*8,299*8,404*8,300*8
#define RANGE_OUTSIDETownToTOWNChurch 494*8,291*8,502*8,292*8
#define RANGE_OUTSIDETownToTOWNTacoBurger 574*8,291*8,582*8,292*8
#define RANGE_OUTSIDETownToTOWNGasStation 710*8,226*8,718*8,227*8
#define RANGE_OUTSIDETownToTOWNCoffeeShop 783*8,262*8,787*8,263*8
#define RANGE_OUTSIDETownToTOWNBookstore 797*8,263*8,805*8,264*8
#define RANGE_OUTSIDETownToTOWNPizzaPlace 848*8,263*8,852*8,264*8
#define RANGE_OUTSIDETownToTOWNBeautySalon 891*8,263*8,899*8,264*8
#define RANGE_OUTSIDETownToTOWNPets4Less 925*8,263*8,929*8,264*8
#define RANGE_OUTSIDETownToTOWNDepartmentStore1 970*8,228*8,978*8,229*8
#define RANGE_OUTSIDETownToTOWNDepartmentStore2 981*8,228*8,989*8,229*8
#define RANGE_OUTSIDETownToTOWNDepartmentStore3 992*8,228*8,1000*8,229*8
#define RANGE_OUTSIDETownToTOWNDepartmentStore4 1003*8,228*8,1011*8,229*8
#define RANGE_OUTSIDETownToTOWNGroceryStoreLeftExit 1055*8,229*8,1063*8,230*8
#define RANGE_OUTSIDETownToTOWNGroceryStoreRightEntrance 1117*8,229*8,1125*8,230*8
#define RANGE_OUTSIDETownToTOWNElectronicsStore 1159*8,262*8,1167*8,263*8
#define RANGE_OUTSIDETownToTOWNGameStore 1244*8,263*8,1252*8,264*8
#define RANGE_OUTSIDETownToTOWNArcade 1276*8,262*8,1284*8,263*8
#define RANGE_OUTSIDETownToTOWNRecordStore 1369*8,263*8,1373*8,264*8
#define RANGE_OUTSIDETownToTOWNMovieTheatreLobbyLeft 1461*8,228*8,1467*8,229*8
#define RANGE_OUTSIDETownToTOWNMovieTheatreLobbyMiddle 1469*8,228*8,1475*8,229*8
#define RANGE_OUTSIDETownToTOWNMovieTheatreLobbyRight 1477*8,228*8,1483*8,229*8
#define RANGE_OUTSIDETownToHOUSEFriendsHouseFrontDoor 319*8,503*8,323*8,504*8
#define RANGE_OUTSIDETownToHOUSEFriendsHouseBackDoor 335*8,464*8,339*8,465*8
#define RANGE_OUTSIDETownToHOUSECrazyHouseFrontDoor 445*8,503*8,449*8,504*8
#define RANGE_OUTSIDETownToHOUSECrazyHouseBackDoor 437*8,464*8,441*8,465*8
#define RANGE_OUTSIDETownToHOUSEYuuHouseFrontDoor 504*8,503*8,508*8,504*8
#define RANGE_OUTSIDETownToHOUSEYuuHouseBackDoor 523*8,464*8,527*8,465*8
#define RANGE_OUTSIDETownToClubHouse 411*8,614*8,415*8,615*8
#define RANGE_OUTSIDETownToToolShed 546*8,436*8,552*8,437*8
#define RANGE_OUTSIDETownToTOWNVideoRent 1195*8,263*8,1199*8,264*8


//========================================================
//Town
//========================================================
void bobsgame_TOWNTown_Map_Load_Function()
{
/*

NPC_create_sprite(&schoolflag,32,32,2104,2056);
NPC_create_sprite(&schoolxingsign,32,32,2432,2560);
NPC_create_sprite(&schoolxingsign,32,32,2696,2560);
NPC_create_sprite(&clinicsign,64,32,3304,2448);
NPC_create_sprite(&clinicsign,64,32,3192,2320);
NPC_create_sprite(&disorderofbobsign,64,64,3960,2216);
NPC_create_sprite(&stainedglasswindow,32,32,3832,2288);
NPC_create_sprite(&stainedglasswindow,32,32,3864,2288);
NPC_create_sprite(&stainedglasswindow,32,32,3896,2288);
NPC_create_sprite(&stainedglasswindow,32,32,4048,2288);
NPC_create_sprite(&stainedglasswindow,32,32,4080,2288);
NPC_create_sprite(&stainedglasswindow,32,32,4112,2288);
NPC_create_sprite(&tacoburgersign,64,32,4424,2256);
NPC_create_sprite(&tacoburgersign,64,32,4512,2256);
NPC_create_sprite(&tacoburgersign,64,32,4600,2256);
NPC_create_sprite(&trafficlightfaceup,32,32,5184,2632);
NPC_create_sprite(&trafficlightfaceup,32,32,5352,2544);
NPC_create_sprite(&townstreetsign,64,32,5552,2552);
NPC_create_sprite(&townstreetsign,64,32,5064,2552);
NPC_create_sprite(&gasstationsign,64,32,5648,2224);
NPC_create_sprite(&gasstationsign,64,32,5880,2224);
NPC_create_sprite(&gasstationsign,64,32,5680,1752);
NPC_create_sprite(&city50milesstreetsign,64,32,5472,1736);
NPC_create_sprite(&city50milesstreetsign,64,32,5040,1744);
NPC_create_sprite(&coffeecafesign,64,32,6120,2032);
NPC_create_sprite(&coffeecafesign,64,32,6264,2032);
NPC_create_sprite(&bookstoresign,64,32,6392,2040);
NPC_create_sprite(&bookstoresign,64,32,6488,2040);
NPC_create_sprite(&pizzasigndoorwide,64,32,6624,2032);
NPC_create_sprite(&pizzasigndoorwide,64,32,6768,2032);
NPC_create_sprite(&pizzasignwindow1,32,32,6632,2064);
NPC_create_sprite(&pizzasignwindow2,32,32,6688,2064);
NPC_create_sprite(&pizzasignwindow3,32,32,6744,2064);
NPC_create_sprite(&beautysalonstacked,32,16,6944,2072);
NPC_create_sprite(&beautysalonsign,64,32,7136,2056);
NPC_create_sprite(&tanningsign,32,8,6984,2072);
NPC_create_sprite(&nailssign,16,8,7024,2072);
NPC_create_sprite(&hairsign,16,8,7064,2072);
NPC_create_sprite(&pets4lessdoorsign,32,16,7400,2032);
NPC_create_sprite(&cutesign,32,8,7264,2072);
NPC_create_sprite(&cheapsign,32,8,7320,2080);
NPC_create_sprite(&departmentsign,64,32,7872,1744);
NPC_create_sprite(&storedeptsign,32,16,7928,1744);
NPC_create_sprite(&groceryexpresssignstacked,64,32,8688,1744);
NPC_create_sprite(&grocerysign,64,32,9128,1752);
NPC_create_sprite(&expresssign,64,32,9176,1752);
NPC_create_sprite(&electronicssign,64,32,9280,2048);
NPC_create_sprite(&videorentsignstacked,16,16,9512,2072);
NPC_create_sprite(&videorentsign,32,8,9560,2064);
NPC_create_sprite(&videorentsignstacked,16,16,9672,2072);
NPC_create_sprite(&videorentsignstacked,16,16,9768,2088);
NPC_create_sprite(&gamestoresign,64,32,9960,2048);
NPC_create_sprite(&arcadesign,32,8,10224,2040);
NPC_create_sprite(&arcadesign,32,8,10408,2072);
NPC_create_sprite(&arcadesign,32,8,10504,2072);
NPC_create_sprite(&arcadesign,32,8,10600,2072);
NPC_create_sprite(&arcadesign,32,8,10696,2072);
NPC_create_sprite(&arcadesign,32,8,10792,2072);
NPC_create_sprite(&musicstoresign,64,32,10944,2056);
NPC_create_sprite(&musicstoresign,64,32,11128,2048);
NPC_create_sprite(&cdssign,16,8,11128,2056);
NPC_create_sprite(&recordssign,32,8,11152,2056);
NPC_create_sprite(&recordssign,32,8,11008,2088);
NPC_create_sprite(&cdssign,16,8,11000,2072);
NPC_create_sprite(&movietheatresign,64,32,11744,1760);
NPC_create_sprite(&movietheatresignstacked,32,16,12304,1760);
NPC_create_sprite(&stopsignfaceup,32,32,288,4112);
NPC_create_sprite(&stopsignfaceup,32,32,12120,4128);
NPC_create_sprite(&stopsignfacedown,32,32,12336,2864);
NPC_create_sprite(&townstreetsign,64,32,12112,2752);
NPC_create_sprite(&townstreetsign,64,32,496,2760);
NPC_create_sprite(&suburblanesign,64,32,496,4256);
NPC_create_sprite(&suburblanesign,64,32,12112,4256);
NPC_create_sprite(&schoolsign,32,8,1928,2144);
NPC_create_sprite(&schoolsign,32,8,2112,2512);
NPC_create_sprite(&stopsignfacedown,32,32,504,2856);
NPC_create_sprite(&gardenhosecoil,32,32,2296,3656);
NPC_create_sprite(&lawnbenchfacedown,64,32,2432,3584);
NPC_create_sprite(&lawnbenchfacedown,64,32,2496,3584);
NPC_create_sprite(&lawnchairfaceright,32,32,2416,3656);
NPC_create_sprite(&lawnchairfaceleft,32,32,2512,3656);
NPC_create_sprite(&grillfaceleft,32,64,2592,3576);
NPC_create_sprite(&gardenhosecoil,32,32,3152,3672);
NPC_create_sprite(&lawnchairfaceright,32,32,3496,3560);
NPC_create_sprite(&lawnchairfaceleft,32,32,3576,3560);
NPC_create_sprite(&lawnchairfacedown,32,32,3536,3528);
NPC_create_sprite(&grillfaceleft,32,64,3592,3632);
NPC_create_sprite(&gardenhosecoil,32,32,3928,3688);
NPC_create_sprite(&lawnchairfacedown,32,32,4064,3632);
NPC_create_sprite(&lawnchairfaceright,32,32,4024,3656);
NPC_create_sprite(&lawnchairfaceleft,32,32,4104,3656);
NPC_create_sprite(&grillfaceleft,32,64,4408,3632);
NPC_create_sprite(&schoolxingsign,32,32,2016,2760);
NPC_create_sprite(&schoolxingsign,32,32,1856,2552);

*/

//RANGE_OUTSIDETownPlaygroundToSCHOOLEntranceHallwayLeft 95*8,266*8,103*8,267*8
//RANGE_OUTSIDETownPlaygroundToSCHOOLEntranceHallwayRight 194*8,266*8,202*8,267*8
//RANGE_OUTSIDETownToSCHOOLEntranceHallwayLeft 230*8,274*8,238*8,275*8
//RANGE_OUTSIDETownToSCHOOLEntranceHallwayMiddle 239*8,274*8,247*8,275*8
//RANGE_OUTSIDETownToSCHOOLEntranceHallwayRight 248*8,274*8,256*8,275*8
//RANGE_OUTSIDETownToTOWNDoctorsOfficeEntrance 400*8,299*8,404*8,300*8
//RANGE_OUTSIDETownToTOWNChurch 494*8,291*8,502*8,292*8
//RANGE_OUTSIDETownToTOWNTacoBurger 574*8,291*8,582*8,292*8
//RANGE_OUTSIDETownToTOWNGasStation 710*8,226*8,718*8,227*8
//RANGE_OUTSIDETownToTOWNCoffeeShop 783*8,262*8,787*8,263*8
//RANGE_OUTSIDETownToTOWNBookstore 797*8,263*8,805*8,264*8
//RANGE_OUTSIDETownToTOWNPizzaPlace 848*8,263*8,852*8,264*8
//RANGE_OUTSIDETownToTOWNBeautySalon 891*8,263*8,899*8,264*8
//RANGE_OUTSIDETownToTOWNPets4Less 925*8,263*8,929*8,264*8
//RANGE_OUTSIDETownToTOWNDepartmentStore1 970*8,228*8,978*8,229*8
//RANGE_OUTSIDETownToTOWNDepartmentStore2 981*8,228*8,989*8,229*8
//RANGE_OUTSIDETownToTOWNDepartmentStore3 992*8,228*8,1000*8,229*8
//RANGE_OUTSIDETownToTOWNDepartmentStore4 1003*8,228*8,1011*8,229*8
//RANGE_OUTSIDETownToTOWNGroceryStoreLeftExit 1055*8,229*8,1063*8,230*8
//RANGE_OUTSIDETownToTOWNGroceryStoreRightEntrance 1117*8,229*8,1125*8,230*8
//RANGE_OUTSIDETownToTOWNElectronicsStore 1159*8,262*8,1167*8,263*8
//RANGE_OUTSIDETownToTOWNGameStore 1244*8,263*8,1252*8,264*8
//RANGE_OUTSIDETownToTOWNArcade 1276*8,262*8,1284*8,263*8
//RANGE_OUTSIDETownToTOWNRecordStore 1369*8,263*8,1373*8,264*8
//RANGE_OUTSIDETownToTOWNMovieTheatreLobbyLeft 1461*8,228*8,1467*8,229*8
//RANGE_OUTSIDETownToTOWNMovieTheatreLobbyMiddle 1469*8,228*8,1475*8,229*8
//RANGE_OUTSIDETownToTOWNMovieTheatreLobbyRight 1477*8,228*8,1483*8,229*8
//RANGE_OUTSIDETownToHOUSEFriendsHouseFrontDoor 319*8,503*8,323*8,504*8
//RANGE_OUTSIDETownToHOUSEFriendsHouseBackDoor 335*8,464*8,339*8,465*8
//RANGE_OUTSIDETownToHOUSECrazyHouseFrontDoor 445*8,503*8,449*8,504*8
//RANGE_OUTSIDETownToHOUSECrazyHouseBackDoor 437*8,464*8,441*8,465*8
//RANGE_OUTSIDETownToHOUSEYuuHouseFrontDoor 504*8,503*8,508*8,504*8
//RANGE_OUTSIDETownToHOUSEYuuHouseBackDoor 523*8,464*8,527*8,465*8
//RANGE_OUTSIDETownToClubHouse 411*8,614*8,415*8,615*8
//RANGE_OUTSIDETownToToolShed 546*8,436*8,552*8,437*8
//RANGE_OUTSIDETownToTOWNVideoRent 1195*8,263*8,1199*8,264*8
}

void bobsgame_TOWNTown_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}
//==============================================================================================================================
//OUTSIDE MAP RUN
//==============================================================================================================================


	NPC_create_npc_if_within_range_else_delete(&schoolflag_npc, GFX_OUTSIDE_schoolflag, 32, 32, 2104, 2056);
	NPC_create_always_on_top_npc_if_within_range_else_delete(&schoolxingsign1_npc,GFX_OUTSIDE_schoolxingsign,32,32,2432,2560);//on top
	NPC_create_always_on_top_npc_if_within_range_else_delete(&schoolxingsign2_npc,GFX_OUTSIDE_schoolxingsign,32,32,2696,2560);//on top
	NPC_create_npc_if_within_range_else_delete(&clinicsign1_npc,GFX_OUTSIDE_clinicsign,64,16,3304,2448);
	NPC_create_npc_if_within_range_else_delete(&clinicsign2_npc,GFX_OUTSIDE_clinicsign,64,16,3192,2320);
	NPC_create_npc_if_within_range_else_delete(&disorderofbobsign_npc,GFX_OUTSIDE_disorderofbobsign,64,64,3960,2216);
	NPC_create_npc_if_within_range_else_delete(&stainedglasswindow1_npc,GFX_OUTSIDE_stainedglasswindow,32,32,3832,2288);
	NPC_create_npc_if_within_range_else_delete(&stainedglasswindow2_npc,GFX_OUTSIDE_stainedglasswindow,32,32,3864,2288);
	NPC_create_npc_if_within_range_else_delete(&stainedglasswindow3_npc,GFX_OUTSIDE_stainedglasswindow,32,32,3896,2288);
	NPC_create_npc_if_within_range_else_delete(&stainedglasswindow4_npc,GFX_OUTSIDE_stainedglasswindow,32,32,4048,2288);
	NPC_create_npc_if_within_range_else_delete(&stainedglasswindow5_npc,GFX_OUTSIDE_stainedglasswindow,32,32,4080,2288);
	NPC_create_npc_if_within_range_else_delete(&stainedglasswindow6_npc,GFX_OUTSIDE_stainedglasswindow,32,32,4112,2288);
	NPC_create_npc_if_within_range_else_delete(&tacoburgersign1_npc,GFX_OUTSIDE_tacoburgersign,64,16,4424,2256);
	NPC_create_npc_if_within_range_else_delete(&tacoburgersign2_npc,GFX_OUTSIDE_tacoburgersign,64,16,4512,2256);
	NPC_create_npc_if_within_range_else_delete(&tacoburgersign3_npc,GFX_OUTSIDE_tacoburgersign,64,16,4600,2256);
	NPC_create_always_on_top_npc_if_within_range_else_delete(&trafficlightfaceup1_npc,GFX_OUTSIDE_trafficlightfaceup,32,32,5184,2632);//on top
	NPC_create_always_on_top_npc_if_within_range_else_delete(&trafficlightfaceup2_npc,GFX_OUTSIDE_trafficlightfaceup,32,32,5352,2544);//on top
	NPC_create_always_on_top_npc_if_within_range_else_delete(&townstreetsign1_npc,GFX_OUTSIDE_townstreetsign,64,16,5552,2552);//on top
	NPC_create_always_on_top_npc_if_within_range_else_delete(&townstreetsign2_npc,GFX_OUTSIDE_townstreetsign,64,16,5064,2552);//on top
	NPC_create_npc_if_within_range_else_delete(&gasstationsign1_npc,GFX_OUTSIDE_gasstationsign,64,16,5648,2224);
	NPC_create_npc_if_within_range_else_delete(&gasstationsign2_npc,GFX_OUTSIDE_gasstationsign,64,16,5880,2224);
	NPC_create_npc_if_within_range_else_delete(&gasstationsign3_npc,GFX_OUTSIDE_gasstationsign,64,16,5680,1752);
	NPC_create_always_on_top_npc_if_within_range_else_delete(&city50milessign1_npc,GFX_OUTSIDE_city50milesstreetsign,64,32,5472,1736);//on top
	NPC_create_always_on_top_npc_if_within_range_else_delete(&city50milessign2_npc,GFX_OUTSIDE_city50milesstreetsign,64,32,5040,1744);//on top
	NPC_create_npc_if_within_range_else_delete(&coffeecafesign1_npc,GFX_OUTSIDE_coffeecafesign,64,32,6120,2032);
	NPC_create_npc_if_within_range_else_delete(&coffeecafesign2_npc,GFX_OUTSIDE_coffeecafesign,64,32,6264,2032);
	NPC_create_npc_if_within_range_else_delete(&bookstoresign1_npc,GFX_OUTSIDE_bookstoresign,64,8,6392,2040);
	NPC_create_npc_if_within_range_else_delete(&bookstoresign2_npc,GFX_OUTSIDE_bookstoresign,64,8,6488,2040);
	NPC_create_npc_if_within_range_else_delete(&pizzasign1_npc,GFX_OUTSIDE_pizzasigndoorwide,64,32,6624,2032);
	NPC_create_npc_if_within_range_else_delete(&pizzasign2_npc,GFX_OUTSIDE_pizzasigndoorwide,64,32,6768,2032);
	NPC_create_npc_if_within_range_else_delete(&pizzasign3_npc,GFX_OUTSIDE_pizzasignwindow1,32,32,6632,2064);
	NPC_create_npc_if_within_range_else_delete(&pizzasign4_npc,GFX_OUTSIDE_pizzasignwindow2,32,32,6688,2064);
	NPC_create_npc_if_within_range_else_delete(&pizzasign5_npc,GFX_OUTSIDE_pizzasignwindow3,32,32,6744,2064);
	NPC_create_npc_if_within_range_else_delete(&beautysalon1_npc,GFX_OUTSIDE_beautysalonstacked,32,16,6944,2072);
	NPC_create_npc_if_within_range_else_delete(&beautysalon2_npc,GFX_OUTSIDE_beautysalonsign,64,8,7136,2056);
	NPC_create_npc_if_within_range_else_delete(&tanningsign_npc,GFX_OUTSIDE_tanningsign,32,8,6984,2072);
	NPC_create_npc_if_within_range_else_delete(&nailssign_npc,GFX_OUTSIDE_nailssign,16,8,7024,2072);
	NPC_create_npc_if_within_range_else_delete(&hairsign_npc,GFX_OUTSIDE_hairsign,16,8,7064,2072);
	NPC_create_npc_if_within_range_else_delete(&pets4lesssign_npc,GFX_OUTSIDE_pets4lessdoorsign,32,16,7400,2032);
	NPC_create_npc_if_within_range_else_delete(&cutesign_npc,GFX_OUTSIDE_cutesign,32,8,7264,2072);
	NPC_create_npc_if_within_range_else_delete(&cheapsign_npc,GFX_OUTSIDE_cheapsign,32,8,7320,2080);
	NPC_create_npc_if_within_range_else_delete(&departmentsign1_npc,GFX_OUTSIDE_departmentsign,64,16,7872,1744);
	NPC_create_npc_if_within_range_else_delete(&departmentsign2_npc,GFX_OUTSIDE_storedeptsign,32,16,7936,1744);
	NPC_create_npc_if_within_range_else_delete(&grocerysign1_npc,GFX_OUTSIDE_groceryexpresssignstacked,64,32,8688,1744);
	NPC_create_npc_if_within_range_else_delete(&grocerysign2_npc,GFX_OUTSIDE_grocerysign,64,16,9128,1752);
	NPC_create_npc_if_within_range_else_delete(&grocerysign3_npc,GFX_OUTSIDE_expresssign,64,16,9176,1752);
	NPC_create_npc_if_within_range_else_delete(&electronicssign_npc,GFX_OUTSIDE_electronicssign,64,8,9280,2048);
	NPC_create_npc_if_within_range_else_delete(&videosign1_npc,GFX_OUTSIDE_videorentsignstacked,16,16,9512,2072);
	NPC_create_npc_if_within_range_else_delete(&videosign2_npc,GFX_OUTSIDE_videorentsign,32,8,9560,2064);
	NPC_create_npc_if_within_range_else_delete(&videosign3_npc,GFX_OUTSIDE_videorentsignstacked,16,16,9672,2072);
	NPC_create_npc_if_within_range_else_delete(&videosign4_npc,GFX_OUTSIDE_videorentsignstacked,16,16,9768,2088);
	NPC_create_npc_if_within_range_else_delete(&gamestoresign_npc,GFX_OUTSIDE_gamestoresign,64,8,9960,2048);
	NPC_create_npc_if_within_range_else_delete(&arcadesign1_npc,GFX_OUTSIDE_arcadesign,32,8,10224,2040);
	NPC_create_npc_if_within_range_else_delete(&arcadesign2_npc,GFX_OUTSIDE_arcadesign,32,8,10408,2072);
	NPC_create_npc_if_within_range_else_delete(&arcadesign3_npc,GFX_OUTSIDE_arcadesign,32,8,10504,2072);
	NPC_create_npc_if_within_range_else_delete(&arcadesign4_npc,GFX_OUTSIDE_arcadesign,32,8,10600,2072);
	NPC_create_npc_if_within_range_else_delete(&arcadesign5_npc,GFX_OUTSIDE_arcadesign,32,8,10696,2072);
	NPC_create_npc_if_within_range_else_delete(&arcadesign6_npc,GFX_OUTSIDE_arcadesign,32,8,10792,2072);
	NPC_create_npc_if_within_range_else_delete(&musicsign1_npc,GFX_OUTSIDE_musicstoresign,64,8,10944,2056);
	NPC_create_npc_if_within_range_else_delete(&musicsign2_npc,GFX_OUTSIDE_musicstoresign,64,8,11128,2048);
	NPC_create_npc_if_within_range_else_delete(&musicsign3_npc,GFX_OUTSIDE_cdssign,16,8,11128,2056);
	NPC_create_npc_if_within_range_else_delete(&musicsign4_npc,GFX_OUTSIDE_recordssign,32,8,11152,2056);
	NPC_create_npc_if_within_range_else_delete(&musicsign5_npc,GFX_OUTSIDE_recordssign,32,8,11008,2088);
	NPC_create_npc_if_within_range_else_delete(&musicsign6_npc,GFX_OUTSIDE_cdssign,16,8,11000,2072);
	NPC_create_npc_if_within_range_else_delete(&movietheatresign1_npc,GFX_OUTSIDE_movietheatresign,64,8,11748,1760);
	NPC_create_npc_if_within_range_else_delete(&movietheatresign2_npc,GFX_OUTSIDE_movietheatresignstacked,32,16,12304,1760);
	NPC_create_always_on_top_npc_if_within_range_else_delete(&stopsign1_npc,GFX_OUTSIDE_stopsignfaceup,32,32,288,4112);//on top
	NPC_create_always_on_top_npc_if_within_range_else_delete(&stopsign2_npc,GFX_OUTSIDE_stopsignfaceup,32,32,12120,4128);//on top
	NPC_create_always_on_top_npc_if_within_range_else_delete(&stopsign3_npc,GFX_OUTSIDE_stopsignfacedown,32,32,12336,2864);//on top
	NPC_create_always_on_top_npc_if_within_range_else_delete(&townstreetsign3_npc,GFX_OUTSIDE_townstreetsign,64,16,12112,2752);//on top
	NPC_create_always_on_top_npc_if_within_range_else_delete(&townstreetsign4_npc,GFX_OUTSIDE_townstreetsign,64,16,496,2760);//on top
	NPC_create_always_on_top_npc_if_within_range_else_delete(&suburblanesign1_npc,GFX_OUTSIDE_suburblanesign,64,16,496,4256);//on top
	NPC_create_always_on_top_npc_if_within_range_else_delete(&suburblanesign2_npc,GFX_OUTSIDE_suburblanesign,64,16,12112,4256);//on top
	NPC_create_npc_if_within_range_else_delete(&schoolsign1_npc, GFX_OUTSIDE_schoolsign,32,8,1928,2144);
	NPC_create_npc_if_within_range_else_delete(&schoolsign2_npc,GFX_OUTSIDE_schoolsign,32,8,2112,2512);
	NPC_create_always_on_top_npc_if_within_range_else_delete(&stopsign4_npc,GFX_OUTSIDE_stopsignfacedown,32,32,504,2856);//on top
	NPC_create_npc_if_within_range_else_delete(&gardenhose1_npc,GFX_OUTSIDE_gardenhosecoil,32,32,2296,3656);
	NPC_create_npc_if_within_range_else_delete(&grill1_npc,GFX_OUTSIDE_grillfaceleft,32,64,2592,3568);
	NPC_create_npc_if_within_range_else_delete(&lawnbenchfacedown1_npc,GFX_OUTSIDE_lawnbenchfacedown,64,32,2432,3576);
	NPC_create_npc_if_within_range_else_delete(&lawnbenchfacedown2_npc,GFX_OUTSIDE_lawnbenchfacedown,64,32,2496,3576);
	NPC_create_npc_if_within_range_else_delete(&lawnchairfaceright1_npc,GFX_OUTSIDE_lawnchairfaceright,32,32,2416,3656);
	NPC_create_npc_if_within_range_else_delete(&lawnchairfaceleft1_npc,GFX_OUTSIDE_lawnchairfaceleft,32,32,2512,3656);
	NPC_create_npc_if_within_range_else_delete(&gardenhose2_npc,GFX_OUTSIDE_gardenhosecoil,32,32,3152,3672);
	NPC_create_npc_if_within_range_else_delete(&lawnchairfacedown3_npc,GFX_OUTSIDE_lawnchairfacedown,32,32,3536,3536);
	NPC_create_npc_if_within_range_else_delete(&grill2_npc,GFX_OUTSIDE_grillfaceleft,32,64,3592,3632);
	NPC_create_npc_if_within_range_else_delete(&lawnchairfaceright2_npc,GFX_OUTSIDE_lawnchairfaceright,32,32,3496,3560);
	NPC_create_npc_if_within_range_else_delete(&lawnchairfaceleft2_npc,GFX_OUTSIDE_lawnchairfaceleft,32,32,3576,3560);
	NPC_create_npc_if_within_range_else_delete(&gardenhose3_npc,GFX_OUTSIDE_gardenhosecoil,32,32,3928,3688);
	NPC_create_npc_if_within_range_else_delete(&lawnchairfaceright3_npc,GFX_OUTSIDE_lawnchairfaceright,32,32,4024,3656);
	NPC_create_npc_if_within_range_else_delete(&lawnchairfaceleft3_npc,GFX_OUTSIDE_lawnchairfaceleft,32,32,4104,3656);
	NPC_create_npc_if_within_range_else_delete(&lawnchairfacedown4_npc,GFX_OUTSIDE_lawnchairfacedown,32,32,4064,3632);
	NPC_create_npc_if_within_range_else_delete(&grill3_npc,GFX_OUTSIDE_grillfaceleft,32,64,4408,3632);
	NPC_create_always_on_top_npc_if_within_range_else_delete(&schoolxingsign3_npc,GFX_OUTSIDE_schoolxingsign,32,32,2016,2760);//on top
	NPC_create_always_on_top_npc_if_within_range_else_delete(&schoolxingsign4_npc,GFX_OUTSIDE_schoolxingsign,32,32,1856,2552);//on top

	if(car_init==0)
	{
		hit_by_car += NPC_car_clockwise(&car_npc[0],SPEED_CAR,&hit_direction_x,&hit_direction_y);
		if(car_npc[0]!=NULL)if(car_npc[0]->AI!=0)hit_by_car += NPC_car_counterclockwise(&car_npc[1],SPEED_CAR,&hit_direction_x,&hit_direction_y);
		if(car_npc[1]!=NULL)if(car_npc[1]->AI!=0)hit_by_car += NPC_car_clockwise(&car_npc[2],SPEED_CAR,&hit_direction_x,&hit_direction_y);
		if(car_npc[2]!=NULL)if(car_npc[2]->AI!=0)hit_by_car += NPC_car_counterclockwise(&car_npc[3],SPEED_CAR,&hit_direction_x,&hit_direction_y);
		if(car_npc[3]!=NULL)if(car_npc[3]->AI!=0)hit_by_car += NPC_car_clockwise(&car_npc[4],SPEED_CAR,&hit_direction_x,&hit_direction_y);
		if(car_npc[4]!=NULL)if(car_npc[4]->AI!=0)hit_by_car += NPC_car_counterclockwise(&car_npc[5],SPEED_CAR,&hit_direction_x,&hit_direction_y);
		if(car_npc[5]!=NULL)if(car_npc[5]->AI!=0)hit_by_car += NPC_car_clockwise(&car_npc[6],SPEED_CAR,&hit_direction_x,&hit_direction_y);
		if(car_npc[6]!=NULL)if(car_npc[6]->AI!=0)hit_by_car += NPC_car_counterclockwise(&car_npc[7],SPEED_CAR,&hit_direction_x,&hit_direction_y);
		if(car_npc[7]!=NULL)if(car_npc[7]->AI!=0)hit_by_car += NPC_car_clockwise(&car_npc[8],SPEED_CAR,&hit_direction_x,&hit_direction_y);
		if(car_npc[8]!=NULL)if(car_npc[8]->AI!=0)hit_by_car += NPC_car_counterclockwise(&car_npc[9],SPEED_CAR,&hit_direction_x,&hit_direction_y);
		if(car_npc[9]!=NULL)if(car_npc[9]->AI!=0)hit_by_car += NPC_car_clockwise(&car_npc[10],SPEED_CAR,&hit_direction_x,&hit_direction_y);
		if(car_npc[10]!=NULL)if(car_npc[10]->AI!=0)hit_by_car += NPC_car_counterclockwise(&car_npc[11],SPEED_CAR,&hit_direction_x,&hit_direction_y);
		if(car_npc[11]!=NULL)if(car_npc[11]->AI!=0)hit_by_car += NPC_car_clockwise(&car_npc[12],SPEED_CAR,&hit_direction_x,&hit_direction_y);
		if(car_npc[12]!=NULL)if(car_npc[12]->AI!=0)hit_by_car += NPC_car_counterclockwise(&car_npc[13],SPEED_CAR,&hit_direction_x,&hit_direction_y);
		if(car_npc[13]!=NULL)if(car_npc[13]->AI!=0)hit_by_car += NPC_car_clockwise(&car_npc[14],SPEED_CAR,&hit_direction_x,&hit_direction_y);
		if(car_npc[14]!=NULL)
		{
			if(car_npc[14]->AI!=0)hit_by_car += NPC_car_counterclockwise(&car_npc[15],SPEED_CAR,&hit_direction_x,&hit_direction_y);
			car_init=1;
		}
	}
	else
	if(hit_by_car==0)
	{
		hit_by_car += NPC_car_clockwise(&car_npc[0],SPEED_CAR,&hit_direction_x,&hit_direction_y);
		if(car_npc[0]!=NULL)hit_by_car += NPC_car_counterclockwise(&car_npc[1],SPEED_CAR,&hit_direction_x,&hit_direction_y);
		if(car_npc[1]!=NULL)hit_by_car += NPC_car_clockwise(&car_npc[2],SPEED_CAR,&hit_direction_x,&hit_direction_y);
		if(car_npc[2]!=NULL)hit_by_car += NPC_car_counterclockwise(&car_npc[3],SPEED_CAR,&hit_direction_x,&hit_direction_y);
		if(car_npc[3]!=NULL)hit_by_car += NPC_car_clockwise(&car_npc[4],SPEED_CAR,&hit_direction_x,&hit_direction_y);
		if(car_npc[4]!=NULL)hit_by_car += NPC_car_counterclockwise(&car_npc[5],SPEED_CAR,&hit_direction_x,&hit_direction_y);
		if(car_npc[5]!=NULL)hit_by_car += NPC_car_clockwise(&car_npc[6],SPEED_CAR,&hit_direction_x,&hit_direction_y);
		if(car_npc[6]!=NULL)hit_by_car += NPC_car_counterclockwise(&car_npc[7],SPEED_CAR,&hit_direction_x,&hit_direction_y);
		if(car_npc[7]!=NULL)hit_by_car += NPC_car_clockwise(&car_npc[8],SPEED_CAR,&hit_direction_x,&hit_direction_y);
		if(car_npc[8]!=NULL)hit_by_car += NPC_car_counterclockwise(&car_npc[9],SPEED_CAR,&hit_direction_x,&hit_direction_y);
		if(car_npc[9]!=NULL)hit_by_car += NPC_car_clockwise(&car_npc[10],SPEED_CAR,&hit_direction_x,&hit_direction_y);
		if(car_npc[10]!=NULL)hit_by_car += NPC_car_counterclockwise(&car_npc[11],SPEED_CAR,&hit_direction_x,&hit_direction_y);
		if(car_npc[11]!=NULL)hit_by_car += NPC_car_clockwise(&car_npc[12],SPEED_CAR,&hit_direction_x,&hit_direction_y);
		if(car_npc[12]!=NULL)hit_by_car += NPC_car_counterclockwise(&car_npc[13],SPEED_CAR,&hit_direction_x,&hit_direction_y);
		if(car_npc[13]!=NULL)hit_by_car += NPC_car_clockwise(&car_npc[14],SPEED_CAR,&hit_direction_x,&hit_direction_y);
		if(car_npc[14]!=NULL)hit_by_car += NPC_car_counterclockwise(&car_npc[15],SPEED_CAR,&hit_direction_x,&hit_direction_y);
	}
	if(hit_by_car>0)
	{
		static int count=0;
		if(count==0)HARDWARE_play_sound("carhit",127,44100,0);
		if(count<500)
		{
			count++;
			if(NPC_check_hit_move_pixel(&PLAYER_npc,hit_direction_x)==true){if(hit_direction_x==LEFT)cameraman->MAP_x--;else cameraman->MAP_x++;}
			if(NPC_check_hit_move_pixel(&PLAYER_npc,hit_direction_y)==true){if(hit_direction_y==UP)cameraman->MAP_y--;else cameraman->MAP_y++;}
		}
		else
		{
			yuu_is_dead=1;
			hit_by_car=0;
			count=0;
		}
	}
//===DONE========================================================
	//limit npcs tracked by area.
	//support cars coming in/ out of city,
	//support random cars coming down street,
	//support getting hit by car
	//support palette changes on time
	//support crosswalks
	//cars dont cross if crossing guard is in the crosswalk.
	//functional stop signs (pause at stop sign for a moment)
//=================================================================
	//TODO: traffic lights
	//TODO: animate movie theatre blinkenlights
	//TODO: lights in windows based on time, also open signs and neon signs turn off
	//TODO: raining light, raining heavy, windy
	//TODO: trees moving in the wind
	//TODO: litter and leaves, crap blowing around
	//TODO: grass animation
	//TODO: feet underneath grass
	//TODO: no footsteps on grass, maybe shshhh sound.
	//TODO: forest and pond, animate water
	//TODO: animate water in crazylady pool
	//TODO: animals
	//TODO: police car patrols
	//TODO: complete mailman support, ice cream man support, jogger/dogwalker. have them go into houses. ice cream man has to come to window.
	//TODO: need mansion change
	//TODO: need to support generic houses
//===========================================================================================================================================
//SCHOOL MORNING
//===========================================================================================================================================
//===================================================================================================
//  CROSSING GUARD FOR MORNING KIDS
//===================================================================================================


	//crossing guard 242,276 7:00 comes from inside school,
	//walks to road 239,353
	if(CLOCK_hour==7)
	{
		if(CLOCK_minute==0)
		{
			HARDWARE_play_sound("doorsound",127,44100,0);
			if(crossingguard_npc==NULL)
			{
				NPC_create_npc_xy_feet(&crossingguard_npc,GFX_ADULT_crossingguard, 16, 40,242*8, 276*8);crossingguard_npc->non_walkable=1;
				crossingguard_npc->AI=1;
				CLOCK_minute++;
			}
		}
		if(CLOCK_hour==7&&CLOCK_minute>0&&CLOCK_minute<35)
		{
			if(crossingguard_npc==NULL)
			{
				NPC_create_npc_xy_feet(&crossingguard_npc,GFX_ADULT_crossingguard, 16, 40,242*8, 276*8);
				crossingguard_npc->non_walkable=1;
				crossingguard_npc->AI=1;
			}
			//she says "move along kids"
			if(ACTION_npc(&crossingguard_npc,"Talk To Crossing Guard")&&GLOBAL_text_engine_state==0)
			{
				TEXT_set_sprite_window(0,crossingguard_npc,NULL);
				TEXT_set_sprite_window(1,PLAYER_npc,NULL);
				TEXT_window("Move along, kids. Hey, it's Yuu. Yuu can stand here if he wants, that's just fine with me. *chuckle*<.>Troublemaker.");
			}
			if(crossingguard_npc!=NULL)
			{
				if(crossingguard_npc->AI==1)
				{
					if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&crossingguard_npc, SPEED_NORMAL, 239*8, 353*8)==(1))
					{
						//NPC_animate_set_direction_now(&crossingguard_npc, DOWN);
						if(MAP_is_xy_within_screen_by_amt(239*8,353*8,GAME_VIEWPORT_WIDTH_PIXELS))
						{
							if(randomcrosswalkkid1_npc==NULL)NPC_create_random_CHILD_xy_feet(&randomcrosswalkkid1_npc,MAP_cam_x-64-32,356*8);
							if(randomcrosswalkkid2_npc==NULL)NPC_create_random_CHILD_xy_feet(&randomcrosswalkkid2_npc,MAP_cam_x-64,358*8);
							if(randomcrosswalkkid3_npc==NULL)NPC_create_random_CHILD_xy_feet(&randomcrosswalkkid3_npc,MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+64+32,356*8);
							if(randomcrosswalkkid4_npc==NULL)NPC_create_random_CHILD_xy_feet(&randomcrosswalkkid4_npc,MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+64,358*8);
						}
							//kids generated outside screen bounds, walk to road
							//if within range, create kid npcs at screen-64 and screen+width+64 197, 356    297,359
							//kids walk to 244,355, in front of street, line up form a crowd
							//if there is a crowd here,
						if(randomcrosswalkkid1_npc!=NULL&&randomcrosswalkkid2_npc!=NULL&&randomcrosswalkkid3_npc!=NULL&&randomcrosswalkkid4_npc!=NULL)
							if(
								NPC_walk_to_xy_nohit_avoidothers_pushmain(&randomcrosswalkkid1_npc, SPEED_NORMAL, 242*8, 354*8)
								+NPC_walk_to_xy_nohit_avoidothers_pushmain(&randomcrosswalkkid2_npc, SPEED_NORMAL, 244*8, 355*8)
								+NPC_walk_to_xy_nohit_avoidothers_pushmain(&randomcrosswalkkid3_npc, SPEED_NORMAL, 246*8, 357*8)
								+NPC_walk_to_xy_nohit_avoidothers_pushmain(&randomcrosswalkkid4_npc, SPEED_NORMAL, 248*8, 356*8)
								==4
								)
								crossingguard_npc->AI++;
					}
				}
				if(crossingguard_npc->AI==2)
				{
					if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&crossingguard_npc, SPEED_NORMAL, 240*8, 339*8)==(1))
					{
						//NPC_animate_set_direction_now(&crossingguard_npc, RIGHT);
						if(randomcrosswalkkid1_npc==NULL)NPC_create_random_CHILD_xy_feet(&randomcrosswalkkid1_npc,MAP_cam_x-64-32,356*8);
						if(randomcrosswalkkid2_npc==NULL)NPC_create_random_CHILD_xy_feet(&randomcrosswalkkid2_npc,MAP_cam_x-64,358*8);
						if(randomcrosswalkkid3_npc==NULL)NPC_create_random_CHILD_xy_feet(&randomcrosswalkkid3_npc,MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+64+32,356*8);
						if(randomcrosswalkkid4_npc==NULL)NPC_create_random_CHILD_xy_feet(&randomcrosswalkkid4_npc,MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+64,358*8);
						//she walks in road, 240,339, face right put up sign
						//cars stop
						//kids walk across the street
						if(
							NPC_walk_to_xy_nohit_avoidothers_pushmain(&randomcrosswalkkid1_npc, SPEED_NORMAL, 242*8, 328*8)
							+NPC_walk_to_xy_nohit_avoidothers_pushmain(&randomcrosswalkkid2_npc, SPEED_NORMAL, 244*8, 326*8)
							+NPC_walk_to_xy_nohit_avoidothers_pushmain(&randomcrosswalkkid3_npc, SPEED_NORMAL, 246*8, 327*8)
							+NPC_walk_to_xy_nohit_avoidothers_pushmain(&randomcrosswalkkid4_npc, SPEED_NORMAL, 248*8, 329*8)
							==4
							)
							crossingguard_npc->AI=3;
					}
				}


				if(crossingguard_npc->AI==3)
				{

						if(randomcrosswalkkid1_npc==NULL)NPC_create_random_CHILD_xy_feet(&randomcrosswalkkid1_npc,MAP_cam_x-64-32,358*6);
						if(randomcrosswalkkid2_npc==NULL)NPC_create_random_CHILD_xy_feet(&randomcrosswalkkid2_npc,MAP_cam_x-64,358*8);
						if(randomcrosswalkkid3_npc==NULL)NPC_create_random_CHILD_xy_feet(&randomcrosswalkkid3_npc,MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+64+32,358*6);
						if(randomcrosswalkkid4_npc==NULL)NPC_create_random_CHILD_xy_feet(&randomcrosswalkkid4_npc,MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+64,358*8);
						//kids cross, walk into school. 243,324, split at stairs, half to 235 306 half to 251, 306
						if(
							NPC_walk_to_xy_nohit_avoidothers_pushmain(&randomcrosswalkkid1_npc, SPEED_NORMAL, 236*8, 323*8)
							+NPC_walk_to_xy_nohit_avoidothers_pushmain(&randomcrosswalkkid2_npc, SPEED_NORMAL, 238*8, 322*8)
							+NPC_walk_to_xy_nohit_avoidothers_pushmain(&randomcrosswalkkid3_npc, SPEED_NORMAL, 248*8, 323*8)
							+NPC_walk_to_xy_nohit_avoidothers_pushmain(&randomcrosswalkkid4_npc, SPEED_NORMAL, 250*8, 322*8)
							==4
							)
							crossingguard_npc->AI=4;
				}

				if(crossingguard_npc->AI==4)
				{
					//kids go in school 242,276
					if(randomcrosswalkkid1_npc!=NULL)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&randomcrosswalkkid1_npc, SPEED_NORMAL, 234*8, 276*8)==(1))NPC_fade_out_and_delete(&randomcrosswalkkid1_npc);
					if(randomcrosswalkkid2_npc!=NULL)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&randomcrosswalkkid2_npc, SPEED_NORMAL, 241*8, 276*8)==(1))NPC_fade_out_and_delete(&randomcrosswalkkid2_npc);
					if(randomcrosswalkkid3_npc!=NULL)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&randomcrosswalkkid3_npc, SPEED_NORMAL, 244*8, 276*8)==(1))NPC_fade_out_and_delete(&randomcrosswalkkid3_npc);
					if(randomcrosswalkkid4_npc!=NULL)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&randomcrosswalkkid4_npc, SPEED_NORMAL, 252*8, 276*8)==(1))NPC_fade_out_and_delete(&randomcrosswalkkid4_npc);
					if(
						randomcrosswalkkid1_npc==NULL&&
						randomcrosswalkkid2_npc==NULL&&
						randomcrosswalkkid3_npc==NULL&&
						randomcrosswalkkid4_npc==NULL
					)
					crossingguard_npc->AI=1;
				}



			}
		}
		if(CLOCK_hour==7&&CLOCK_minute>=35)// at 7:35 walk back into school, delete.
		{
			if(randomcrosswalkkid1_npc!=NULL){if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&randomcrosswalkkid1_npc, SPEED_NORMAL, 234*8, 276*8)==(1))NPC_fade_out_and_delete(&randomcrosswalkkid1_npc);}
			if(randomcrosswalkkid2_npc!=NULL){if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&randomcrosswalkkid2_npc, SPEED_NORMAL, 242*8, 276*8)==(1))NPC_fade_out_and_delete(&randomcrosswalkkid2_npc);}
			if(randomcrosswalkkid3_npc!=NULL){if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&randomcrosswalkkid3_npc, SPEED_NORMAL, 244*8, 276*8)==(1))NPC_fade_out_and_delete(&randomcrosswalkkid3_npc);}
			if(randomcrosswalkkid4_npc!=NULL){if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&randomcrosswalkkid4_npc, SPEED_NORMAL, 252*8, 276*8)==(1))NPC_fade_out_and_delete(&randomcrosswalkkid4_npc);}

			if(crossingguard_npc!=NULL)
			{
				if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&crossingguard_npc, SPEED_SLOWEST, 242*8, 276*8)==(1))
				{
					NPC_fade_out_and_delete(&crossingguard_npc);
				}
			}
		}
	}

//===================================================================================================
// RANDOMLY GENERATED ENTERING KIDS
//===================================================================================================


static NPC* enterkids[20] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};

	if(CLOCK_hour==7)
	{
	//support school outside in the morning, bell ringing, children crowds
	//7:00 kids appear offscreen and walk into the school


		int c=0;
		if(CLOCK_minute<30)
		{

			static int last_vbl_10_var=0;

			if(MAP_is_xy_within_screen_by_amt(242*8,276*8,64))
			{
				for(c=0;c<20;c++)
				if(enterkids[c]==NULL&&last_vbl_10_var!=vbl_10_var)
				{

					last_vbl_10_var=vbl_10_var;

					int randnum=r(3);

					if(MAP_is_xy_within_screen_by_amt(238*8,322*8,64))
					{
						if(randnum==0){NPC_create_random_CHILD_xy_feet(&enterkids[c],MAP_cam_x-16,322*8);enterkids[c]->AI=0;}
						if(randnum==1){NPC_create_random_CHILD_xy_feet(&enterkids[c],MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16,322*8);enterkids[c]->AI=1;}
						if(randnum==2){NPC_create_random_CHILD_xy_feet(&enterkids[c],308*8,(288+r(10))*8);enterkids[c]->AI=4;}

					}
					else
					{
						if(randnum==0){NPC_create_random_CHILD_xy_feet(&enterkids[c],(236+r(4))*8,322*8);enterkids[c]->AI=2;}
						if(randnum==1){NPC_create_random_CHILD_xy_feet(&enterkids[c],(248+r(5))*8,322*8);enterkids[c]->AI=3;}
						if(randnum==2){NPC_create_random_CHILD_xy_feet(&enterkids[c],308*8,(288+r(10))*8);enterkids[c]->AI=4;}

					}

					enterkids[c]->walking_speed = SPEED_NORMAL+r(SPEED_SLOWEST-SPEED_FASTEST);


				}
			}
		}

		for(c=0;c<20;c++)
		if(enterkids[c]!=NULL)
		{


			//if door is on screen and sidewalk isnt, some start from the sidewalk 236, 322  251, 322, walk up to 295. select a door, walk into door, fade out

			//if sidewalk is on screen, start kids from sides of screen on sidewalk, walk to stairs, walk up stairs

			//some start from right, 308, 288-298, choose a door, walk to x,-1, walk to x,y, fade out

			//from sidewalk
				 if(enterkids[c]->AI==0){if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&enterkids[c], enterkids[c]->walking_speed, 236*8, -1)){enterkids[c]->AI = 2;}}
			else if(enterkids[c]->AI==1){if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&enterkids[c], enterkids[c]->walking_speed, 248*8, -1)){enterkids[c]->AI = 3;}}

			else if(enterkids[c]->AI==2){if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&enterkids[c], enterkids[c]->walking_speed, -1, 305*8)){enterkids[c]->AI = r(3)+5;}}
			else if(enterkids[c]->AI==3){if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&enterkids[c], enterkids[c]->walking_speed, -1, 305*8)){enterkids[c]->AI = r(3)+5;}}

			//from right
			else if(enterkids[c]->AI==4){if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&enterkids[c], enterkids[c]->walking_speed, 252*8, -1)){enterkids[c]->AI = r(3)+5;}}



			else if(enterkids[c]->AI==5){if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&enterkids[c], enterkids[c]->walking_speed, 234*8, 276*8))NPC_fade_out_and_delete(&enterkids[c]);}
			else if(enterkids[c]->AI==6){if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&enterkids[c], enterkids[c]->walking_speed, 243*8, 276*8))NPC_fade_out_and_delete(&enterkids[c]);}
			else if(enterkids[c]->AI==7){if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&enterkids[c], enterkids[c]->walking_speed, 252*8, 276*8))NPC_fade_out_and_delete(&enterkids[c]);}



		}

		if(CLOCK_minute==30)
		{
			//TODO: loitering kids walk inside school
			HARDWARE_play_sound("schoolbell",127,44100,0);
			CLOCK_minute++;
		}
	}//end if clock hour ==7




//===================================================================================================
// UNIQUE/CLIQUE KIDS ARE LOITERING
//===================================================================================================
//TODO: make loitering non-random kids that you can talk to, in cliques.
//bully
//greaserboy
//jockboy
//thugboy
//
//conceitedgirl
//jockgirl
//skatergirl
//emogirl
//punkgirl
//gothgirl
//
//skaterboy
//bladerboy
//gothboy
//punkboy
//emoboy
//conceitedboy
//
//pudgyboy
//nerdboy
//uglyboy
//scrawnyboy
//uglygirl
//pudgygirl
//nerdgirl
//
//===================================================================================================
// CARS DROP KIDS OFF FOR SCHOOL
//===================================================================================================
	//if in range of parking lot, have car appear below screen,
	//drive to sidewalk, stop
	//create random kid next to car play door sound
	//kid walk into school, or offcam
	//car drives up, if screen not in range of car, car deletes, start over


//TODO: make many cars lined up, also for kids exiting school.



	if(CLOCK_hour==7&&CLOCK_minute<30)
	{
		if(MAP_is_xy_within_screen_by_amt(312*8,287*8,64)) //parking lot coords  312 287
		{


			if(droppedoffkid_npc==NULL)
			{
				if(dropoffcar_npc==NULL)
				{
					NPC_create_car(&dropoffcar_npc,308*8,MAP_cam_y+GAME_VIEWPORT_HEIGHT_PIXELS+32, UP);//create car offscreen coords 308, touchmap y
				}


				if(dropoffcar_npc!=NULL)
				{
					if(NPC_walk_to_xy_nohit_pushmain(&dropoffcar_npc, SPEED_FAST, 312*8, 286*8)==(1))//sidewalk coords 308, 293
					{
						NPC_create_random_CHILD_xy_feet(&droppedoffkid_npc,308*8,293*8);//next to car coords 306 293
						droppedoffkid_npc->walking_speed = SPEED_NORMAL;
						droppedoffkid_npc->AI = 0;

						dropoffcar_npc->AI = 0;

						//doorsound
						HARDWARE_play_sound("doorsound",63,44100,0);
					}
				}


			}
		}
	}


	if(dropoffcar_npc!=NULL)
	{
		//stop here for a minute, move offscreen
		if(dropoffcar_npc->AI==0){dropoffcar_npc->vbls=0;dropoffcar_npc->AI=1;}
		if(dropoffcar_npc->AI==1&&dropoffcar_npc->vbls>60)
			if(
				(NPC_walk_to_xy_nohit_pushmain(&dropoffcar_npc, SPEED_FAST, 312*8, 205*8)//upper parking lot 308, 205
					&&MAP_is_xy_within_screen_by_amt(dropoffcar_npc->MAP_x,dropoffcar_npc->MAP_y,64)==0)

				||MAP_is_xy_within_screen_by_amt(dropoffcar_npc->MAP_x,dropoffcar_npc->MAP_y,64)==0)
					{NPC_delete_npc(&dropoffcar_npc);}
	}




	if(droppedoffkid_npc!=NULL)//if kid walks into school or is offcamera delete
	{

		if(droppedoffkid_npc->AI==0)
		{
			if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&droppedoffkid_npc, droppedoffkid_npc->walking_speed, 252*8, -1))droppedoffkid_npc->AI=1;
		}

		if(droppedoffkid_npc->AI==1)
		{
			if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&droppedoffkid_npc, droppedoffkid_npc->walking_speed, 252*8, 276*8))
			{
				NPC_fade_out_and_delete(&droppedoffkid_npc);
			}
		}

	}

	if(droppedoffkid_npc!=NULL&&dropoffcar_npc==NULL)
	{
		if(MAP_is_xy_within_screen_by_amt(droppedoffkid_npc->MAP_x,droppedoffkid_npc->MAP_y,64)==0)NPC_delete_npc(&droppedoffkid_npc);
	}







//===================================================================================================
//school done (for morning.)
//===================================================================================================
//===================================================================================================
// BIKE RACK BIKES
//===================================================================================================
	//bikes in the bike rack between 7 and 4:30
	if(CLOCK_hour>=7&&CLOCK_hour<=12+4&&(CLOCK_hour!=12+4||CLOCK_minute<=30))
	{
		NPC_create_bicycle_if_within_range_else_delete(&bikerackbikes[0],272*8,279*8+2,UP);
		NPC_create_bicycle_if_within_range_else_delete(&bikerackbikes[1],277*8,279*8,UP);
		NPC_create_bicycle_if_within_range_else_delete(&bikerackbikes[2],284*8,279*8+2,UP);
		//NPC_create_bicycle_if_within_range_else_delete(&bikerackbikes[3],289*8,279*8,UP);
		NPC_create_bicycle_if_within_range_else_delete(&bikerackbikes[4],292*8,279*8,UP);
	}
	else
	{
		int c=0;
		for(c=0;c<5;c++)if(bikerackbikes[c]!=NULL){NPC_delete_npc(&bikerackbikes[c]);}
	}
//===================================================================================================
// PARKING LOT CARS
//===================================================================================================

static NPC* schoolparkinglotcars[8]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};

	//parking lot full, if in range. only between 6:30 am and 5 pm.
	if(CLOCK_hour>=6&&CLOCK_hour<=12+5&&(CLOCK_hour!=6||CLOCK_minute>=30))
	{
		NPC_create_car_if_within_range_else_delete(&schoolparkinglotcars[0],332*8,200*8,RIGHT);
		//NPC_create_car_if_within_range_else_delete(&schoolparkinglotcars[1],333*8,212*8,RIGHT);
		NPC_create_car_if_within_range_else_delete(&schoolparkinglotcars[2],331*8,225*8,LEFT);
		NPC_create_car_if_within_range_else_delete(&schoolparkinglotcars[3],332*8,238*8,RIGHT);
		//NPC_create_car_if_within_range_else_delete(&schoolparkinglotcars[4],332*8,251*8,RIGHT);
		NPC_create_car_if_within_range_else_delete(&schoolparkinglotcars[5],331*8,265*8,RIGHT);
		//NPC_create_car_if_within_range_else_delete(&schoolparkinglotcars[6],332*8,277*8,LEFT);
		NPC_create_car_if_within_range_else_delete(&schoolparkinglotcars[7],333*8,290*8,RIGHT);
	}
	else
	{
		int c=0;
		for(c=0;c<8;c++)if(schoolparkinglotcars[c]!=NULL){NPC_delete_npc(&schoolparkinglotcars[c]);}
	}
//===========================================================================================================================================
//SCHOOL AFTERNOON
//===========================================================================================================================================
//===================================================================================================
// KIDS FLOOD OUT OF SCHOOL ENTRANCE
//===================================================================================================
	int c=0;



static NPC* exitkids[30] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};

		//if within door range, create kids at entrance, all 3 doors
	//random walk offscreen, if get offscreen delete
	//else stop at steps, sidewalk
	if(CLOCK_hour==12+4&&CLOCK_minute>=30)
	{
		if(CLOCK_minute==30)
		{
			HARDWARE_play_sound("schoolbell",127,44100,0);
			CLOCK_minute++;
		}
		if(MAP_is_xy_within_screen_by_amt(242*8,276*8,64))
		{

			static int last_vbl_10=0;

			for(c=0;c<20;c++)
			if(exitkids[c]==NULL&&last_vbl_10!=vbl_10_var)
			{
				last_vbl_10=vbl_10_var;

				int cycle=r(3);
				if(cycle==0)NPC_create_random_CHILD_xy_feet(&exitkids[c],234*8,275*8);
				if(cycle==1)NPC_create_random_CHILD_xy_feet(&exitkids[c],243*8,275*8);
				if(cycle==2)NPC_create_random_CHILD_xy_feet(&exitkids[c],252*8,275*8);
				exitkids[c]->walking_speed = SPEED_NORMAL+r(SPEED_SLOWER-SPEED_FASTEST);
				exitkids[c]->AI=0;
				exitkids[c]->alpha=0;
			}
		}
	}
	//TODO: need murmuring when in range
	//TODO: need kids to not just disappear at the parking lot. walk into a school bus?

	for(c=0;c<20;c++)
	if(exitkids[c]!=NULL)
	{
		//fade in
		if(exitkids[c]->AI<11&&exitkids[c]->alpha<255)NPC_set_alpha(&exitkids[c],exitkids[c]->alpha+1);


		//walk right
			 if(exitkids[c]->AI==0){exitkids[c]->AI = (r(8))+1;}


		else if(exitkids[c]->AI==1){if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&exitkids[c], exitkids[c]->walking_speed, 262*8, 293*8)){exitkids[c]->AI = 9;}}
		else if(exitkids[c]->AI==2){if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&exitkids[c], exitkids[c]->walking_speed, 265*8, 295*8)){exitkids[c]->AI = 9;}}
		else if(exitkids[c]->AI==3){if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&exitkids[c], exitkids[c]->walking_speed, 260*8, 289*8)){exitkids[c]->AI = 9;}}
		else if(exitkids[c]->AI==4){if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&exitkids[c], exitkids[c]->walking_speed, 266*8, 297*8)){exitkids[c]->AI = 9;}}

		else if(exitkids[c]->AI==5){if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&exitkids[c], exitkids[c]->walking_speed, 237*8, 321*8)){exitkids[c]->AI = r(2)+10;}}
		else if(exitkids[c]->AI==6){if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&exitkids[c], exitkids[c]->walking_speed, 235*8, 322*8)){exitkids[c]->AI = r(2)+10;}}
		else if(exitkids[c]->AI==7){if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&exitkids[c], exitkids[c]->walking_speed, 252*8, 323*8)){exitkids[c]->AI = r(2)+10;}}
		else if(exitkids[c]->AI==8){if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&exitkids[c], exitkids[c]->walking_speed, 254*8, 322*8)){exitkids[c]->AI = r(2)+10;}}


		else if(exitkids[c]->AI==9){if((MAP_is_xy_within_screen_by_amt(exitkids[c]->MAP_x,exitkids[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&exitkids[c], exitkids[c]->walking_speed, 308*8, -1)){NPC_delete_npc(&exitkids[c]);}}


		else if(exitkids[c]->AI==10){if((MAP_is_xy_within_screen_by_amt(exitkids[c]->MAP_x,exitkids[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&exitkids[c], exitkids[c]->walking_speed, 500*8, 322*8)){NPC_delete_npc(&exitkids[c]);}}
		else if(exitkids[c]->AI==11){if((MAP_is_xy_within_screen_by_amt(exitkids[c]->MAP_x,exitkids[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&exitkids[c], exitkids[c]->walking_speed, 67*8, 322*8)){NPC_delete_npc(&exitkids[c]);}}


	}
//===================================================================================================
// CROSSING GUARD KIDS EXITING
//===================================================================================================
	//crossing guard again, other side this time
	//if at crosswalk range, create kids come down to steps from offscreen, group at crosswalk
	//crossing guard 242,276 7:00 comes from inside school,
	//walks to road




	if(CLOCK_hour==12+4)
	{

		if(CLOCK_hour==12+4&&CLOCK_minute>=30&&CLOCK_minute<55)
		{

			if(crossingguard_npc==NULL)
			{
				NPC_create_npc_xy_feet(&crossingguard_npc,GFX_ADULT_crossingguard,16,40,242*8,276*8);//middle door 242,276
				crossingguard_npc->non_walkable=1;
				crossingguard_npc->AI=0;
			}


			//she says "move along kids"
			if(ACTION_npc(&crossingguard_npc,"Talk To Crossing Guard")&&GLOBAL_text_engine_state==0)
			{
				TEXT_set_sprite_window(0,crossingguard_npc,NULL);
				TEXT_set_sprite_window(1,PLAYER_npc,NULL);
				TEXT_window("Wait until it's safe, kids. <.>Oh, Yuu can go right ahead.<.>*chuckle*");
			}


			if(crossingguard_npc!=NULL)
			{


				if(crossingguard_npc->AI==0)
				{
					if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&crossingguard_npc, SPEED_NORMAL, 239*8, 328*8)==(1))//walk to road 239,328
					{
						if(MAP_is_xy_within_screen_by_amt(239*8,328*8,64))//within range of road 239, 328
						{
							if(randomcrosswalkkid1_npc==NULL){NPC_create_random_CHILD_xy_feet(&randomcrosswalkkid1_npc,235*8,276*8);}
							if(randomcrosswalkkid2_npc==NULL){NPC_create_random_CHILD_xy_feet(&randomcrosswalkkid2_npc,237*8,276*8);}
							if(randomcrosswalkkid3_npc==NULL){NPC_create_random_CHILD_xy_feet(&randomcrosswalkkid3_npc,251*8,276*8);}
							if(randomcrosswalkkid4_npc==NULL){NPC_create_random_CHILD_xy_feet(&randomcrosswalkkid4_npc,253*8,276*8);}
						}

						//kids generated outside screen bounds, walk to road
						if(randomcrosswalkkid1_npc!=NULL&&randomcrosswalkkid2_npc!=NULL&&randomcrosswalkkid3_npc!=NULL&&randomcrosswalkkid4_npc!=NULL)
							if(
								NPC_walk_to_xy_nohit_avoidothers_pushmain(&randomcrosswalkkid1_npc, SPEED_NORMAL, 235*8, 321*8)
								+NPC_walk_to_xy_nohit_avoidothers_pushmain(&randomcrosswalkkid2_npc, SPEED_NORMAL, 237*8, 321*8)
								+NPC_walk_to_xy_nohit_avoidothers_pushmain(&randomcrosswalkkid3_npc, SPEED_NORMAL, 251*8, 321*8)
								+NPC_walk_to_xy_nohit_avoidothers_pushmain(&randomcrosswalkkid4_npc, SPEED_NORMAL, 253*8, 321*8)
								==4
								)
								crossingguard_npc->AI++;
					}
				}


				if(crossingguard_npc->AI==1)
				{
					if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&crossingguard_npc, SPEED_NORMAL, 239*8, 328*8)==(1))//walk to road 239,328
					{
						if(MAP_is_xy_within_screen_by_amt(239*8,328*8,64))//within range of road 239, 328
						{
							if(randomcrosswalkkid1_npc==NULL){NPC_create_random_CHILD_xy_feet(&randomcrosswalkkid1_npc,235*8,276*8);}
							if(randomcrosswalkkid2_npc==NULL){NPC_create_random_CHILD_xy_feet(&randomcrosswalkkid2_npc,237*8,276*8);}
							if(randomcrosswalkkid3_npc==NULL){NPC_create_random_CHILD_xy_feet(&randomcrosswalkkid3_npc,251*8,276*8);}
							if(randomcrosswalkkid4_npc==NULL){NPC_create_random_CHILD_xy_feet(&randomcrosswalkkid4_npc,253*8,276*8);}
						}
						//kids generated outside screen bounds, walk to road
						if(randomcrosswalkkid1_npc!=NULL&&randomcrosswalkkid2_npc!=NULL&&randomcrosswalkkid3_npc!=NULL&&randomcrosswalkkid4_npc!=NULL)
							if(
								NPC_walk_to_xy_nohit_avoidothers_pushmain(&randomcrosswalkkid1_npc, SPEED_NORMAL, 242*8, 326*8)
								+NPC_walk_to_xy_nohit_avoidothers_pushmain(&randomcrosswalkkid2_npc, SPEED_NORMAL, 244*8, 324*8)
								+NPC_walk_to_xy_nohit_avoidothers_pushmain(&randomcrosswalkkid3_npc, SPEED_NORMAL, 246*8, 325*8)
								+NPC_walk_to_xy_nohit_avoidothers_pushmain(&randomcrosswalkkid4_npc, SPEED_NORMAL, 247*8, 327*8)
								==4
								)
								crossingguard_npc->AI++;
					}
				}



				if(crossingguard_npc->AI==2)
				{
					if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&crossingguard_npc, SPEED_NORMAL, 240*8, 339*8)==(1))
					{

						if(MAP_is_xy_within_screen_by_amt(239*8,328*8,64))//within range of road 239, 328
						{
							if(randomcrosswalkkid1_npc==NULL){NPC_create_random_CHILD_xy_feet(&randomcrosswalkkid1_npc,235*8,276*8);}
							if(randomcrosswalkkid2_npc==NULL){NPC_create_random_CHILD_xy_feet(&randomcrosswalkkid2_npc,237*8,276*8);}
							if(randomcrosswalkkid3_npc==NULL){NPC_create_random_CHILD_xy_feet(&randomcrosswalkkid3_npc,251*8,276*8);}
							if(randomcrosswalkkid4_npc==NULL){NPC_create_random_CHILD_xy_feet(&randomcrosswalkkid4_npc,253*8,276*8);}
						}

						//NPC_animate_set_direction_now(&crossingguard_npc, RIGHT);
						//she walks in road, 240,339, face right put up sign
						//cars stop
						//kids walk across the street
						if(randomcrosswalkkid1_npc!=NULL&&randomcrosswalkkid2_npc!=NULL&&randomcrosswalkkid3_npc!=NULL&&randomcrosswalkkid4_npc!=NULL)
						if(
							NPC_walk_to_xy_nohit_avoidothers_pushmain(&randomcrosswalkkid1_npc, SPEED_NORMAL, 241*8, 355*8)
							+NPC_walk_to_xy_nohit_avoidothers_pushmain(&randomcrosswalkkid2_npc, SPEED_NORMAL, 243*8, 357*8)
							+NPC_walk_to_xy_nohit_avoidothers_pushmain(&randomcrosswalkkid3_npc, SPEED_NORMAL, 245*8, 358*8)
							+NPC_walk_to_xy_nohit_avoidothers_pushmain(&randomcrosswalkkid4_npc, SPEED_NORMAL, 247*8, 356*8)
							==4
							)
							crossingguard_npc->AI=3;
					}
				}

				if(crossingguard_npc->AI==3)
				{
					if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&crossingguard_npc, SPEED_NORMAL, 239*8, 328*8)==(1))
					{
						//crossing guard walks back up to road
						crossingguard_npc->AI=4;
					}
				}

				if(crossingguard_npc->AI==4)
				{
					//kids walk half left, half right. delete if offscreen.
					if(randomcrosswalkkid1_npc!=NULL)if((MAP_is_xy_within_screen_by_amt(randomcrosswalkkid1_npc->MAP_x,randomcrosswalkkid1_npc->MAP_y,64)==0)){NPC_delete_npc(&randomcrosswalkkid1_npc);}
					if(randomcrosswalkkid2_npc!=NULL)if((MAP_is_xy_within_screen_by_amt(randomcrosswalkkid2_npc->MAP_x,randomcrosswalkkid2_npc->MAP_y,64)==0)){NPC_delete_npc(&randomcrosswalkkid2_npc);}
					if(randomcrosswalkkid3_npc!=NULL)if((MAP_is_xy_within_screen_by_amt(randomcrosswalkkid3_npc->MAP_x,randomcrosswalkkid3_npc->MAP_y,64)==0)){NPC_delete_npc(&randomcrosswalkkid3_npc);}
					if(randomcrosswalkkid4_npc!=NULL)if((MAP_is_xy_within_screen_by_amt(randomcrosswalkkid4_npc->MAP_x,randomcrosswalkkid4_npc->MAP_y,64)==0)){NPC_delete_npc(&randomcrosswalkkid4_npc);}


					if(randomcrosswalkkid1_npc!=NULL){if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&randomcrosswalkkid1_npc, SPEED_NORMAL, 67*8, 357*8))NPC_fade_out_and_delete(&randomcrosswalkkid1_npc);}
					if(randomcrosswalkkid2_npc!=NULL){if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&randomcrosswalkkid2_npc, SPEED_NORMAL, 69*8, 355*8))NPC_fade_out_and_delete(&randomcrosswalkkid2_npc);}
					if(randomcrosswalkkid3_npc!=NULL){if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&randomcrosswalkkid3_npc, SPEED_NORMAL, 500*8, 357*8))NPC_fade_out_and_delete(&randomcrosswalkkid3_npc);}
					if(randomcrosswalkkid4_npc!=NULL){if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&randomcrosswalkkid4_npc, SPEED_NORMAL, 502*8, 355*8))NPC_fade_out_and_delete(&randomcrosswalkkid4_npc);}



					if(
						randomcrosswalkkid1_npc==NULL&&
						randomcrosswalkkid2_npc==NULL&&
						randomcrosswalkkid3_npc==NULL&&
						randomcrosswalkkid4_npc==NULL
					)
					crossingguard_npc->AI=0;
				}

			}

		}

	}




	if(CLOCK_hour>12+4||(CLOCK_hour==4&&CLOCK_minute>=55))
	{

		//kids delete if offscreen. if onscreen, fade out, delete
		if(randomcrosswalkkid1_npc!=NULL){if(MAP_is_xy_within_screen_by_amt(randomcrosswalkkid1_npc->MAP_x,randomcrosswalkkid1_npc->MAP_y,64)==0){NPC_delete_npc(&randomcrosswalkkid1_npc);}else{NPC_fade_out_and_delete(&randomcrosswalkkid1_npc);}}
		if(randomcrosswalkkid2_npc!=NULL){if(MAP_is_xy_within_screen_by_amt(randomcrosswalkkid2_npc->MAP_x,randomcrosswalkkid2_npc->MAP_y,64)==0){NPC_delete_npc(&randomcrosswalkkid2_npc);}else{NPC_fade_out_and_delete(&randomcrosswalkkid2_npc);}}
		if(randomcrosswalkkid3_npc!=NULL){if(MAP_is_xy_within_screen_by_amt(randomcrosswalkkid3_npc->MAP_x,randomcrosswalkkid3_npc->MAP_y,64)==0){NPC_delete_npc(&randomcrosswalkkid3_npc);}else{NPC_fade_out_and_delete(&randomcrosswalkkid3_npc);}}
		if(randomcrosswalkkid4_npc!=NULL){if(MAP_is_xy_within_screen_by_amt(randomcrosswalkkid4_npc->MAP_x,randomcrosswalkkid4_npc->MAP_y,64)==0){NPC_delete_npc(&randomcrosswalkkid4_npc);}else{NPC_fade_out_and_delete(&randomcrosswalkkid4_npc);}}

		//crossing guard delete
		if(crossingguard_npc!=NULL)
		{
			if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&crossingguard_npc, SPEED_SLOWEST, 242*8, 276*8)==(1))
			{
				NPC_fade_out_and_delete(&crossingguard_npc);
			}
		}
	}
//===================================================================================================
// CARS PICKING UP KIDS
//===================================================================================================
	//if at parking lot, kids get created offscreen left, walk to sidewalk, get picked up.




static NPC* pickedupkid_npc=NULL;
static NPC* pickupcar_npc=NULL;

	if(CLOCK_hour==12+4&&CLOCK_minute>=30)
	{
		if(MAP_is_xy_within_screen_by_amt(312*8,287*8,64)) //parking lot coords  312 287
		{
			if(pickupcar_npc==NULL)
			{
				if(pickedupkid_npc==NULL)
				{
					NPC_create_random_CHILD_xy_feet(&pickedupkid_npc,MAP_cam_x-32,293*8);
					pickedupkid_npc->walking_speed = SPEED_NORMAL;
				}
				if(pickedupkid_npc!=NULL)
				{
					if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&pickedupkid_npc, SPEED_NORMAL, 307*8, 293*8))//sidewalk coords 308, 293
					{
						NPC_create_car(&pickupcar_npc,308*8,MAP_cam_y-64, DOWN);//create car offscreen coords 308, touchmap y
					}
				}
			}
		}
	}


	if(pickupcar_npc!=NULL)
	{
		if(pickupcar_npc->AI==0)
		{
			if(NPC_walk_to_xy_nohit_pushmain(&pickupcar_npc, SPEED_FAST, 312*8, 288*8))
			{
				pickupcar_npc->vbls=0;
				pickupcar_npc->AI=1;
			}
		}
		if(pickupcar_npc->AI==1&&pickupcar_npc->vbls>60)
		{
			pickupcar_npc->AI=2;
		}

		if(pickupcar_npc->AI==2)
		{
			//if car is next to kid
			if(pickedupkid_npc!=NULL)
			{
				NPC_walk_to_xy_nohit_avoidothers_pushmain(&pickedupkid_npc, SPEED_SLOW, 309*8, 293*8);
				NPC_fade_out_and_delete(&pickedupkid_npc);
			}

			if(pickedupkid_npc==NULL)
			{
				//doorsound
				HARDWARE_play_sound("doorsound",127,44100,0);
				pickupcar_npc->AI=3;
			}
		}
		if(pickupcar_npc->AI==3)
		{
			if(NPC_walk_to_xy_nohit_pushmain(&pickupcar_npc, SPEED_FAST, 312*8, 320*8)
				&&MAP_is_xy_within_screen_by_amt(pickupcar_npc->MAP_x,pickupcar_npc->MAP_y,0)==0)
					{NPC_delete_npc(&pickupcar_npc);}
		}
	}
//===================================================================================================
// END SCHOOL. SCHOOL IS DONE.
//===================================================================================================
//===================================================================================================
// MAILMAN
//===================================================================================================
	//support mailman
	//10:00 walks to mailbox very fast. 492, 539
	//if not in range, and 10, draw here
	//else if in range, draw y, screen+x
	//if follow him, he goes to neighbors mailbox   //385, 539
	//delete if offscreen.
		//mailbox should say "pizza ad delivery box. gets filled daily by a mysterious government organization to remind you
	//that not only do they know where you live, they can come and get you at any time. have a nice day, and remember, paying someone
	//to take an envelope across the entire country costs as much as a gumball."
	//can only catch him on saturday unless youre skipped school
	//"hey can i have some cool mail?"
	//sure, kiddo. here.
	//got neighbors credit card


	//start -1, 531
	//488, 531 driveway
	//walk down to 488 540
	//walk to mailbox 492 540 face up, animate slowly
	//walk back to driveway 488 540
	//walk to sidewalk 488 531
	//walk to next driveway 389, 531
	//walk to street 389 540
	//walk to next mailbox 386 540
	//face up, animate slowly
	//delete when offscreen



	if(CLOCK_hour==10&&CLOCK_minute>0&&CLOCK_minute<30)
	{
		if(mailman_npc==NULL&&MAP_is_xy_within_screen_by_amt(492*8,540*8,64)==0&&mailman_came_today==0&&CLOCK_day!=SUNDAY)//only weekdays, only once a day
		{
			NPC_create_npc_xy_feet(&mailman_npc,GFX_ADULT_mailman, 16, 40,492*8,540*8);
			mailman_npc->non_walkable=1;
			mailman_npc->AI=4;
			NPC_animate_stand_dir(&mailman_npc, UP);
			mailman_came_today=1;
			mailman_npc->layer=1;
		}
		if(mailman_npc==NULL&&MAP_is_xy_within_screen_by_amt(492*8,540*8,64)&&mailman_came_today==0&&CLOCK_day!=SUNDAY)//only weekdays, only once a day
		{
			NPC_create_npc_xy_feet(&mailman_npc,GFX_ADULT_mailman, 16, 40,MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16, 531*8);
			mailman_npc->non_walkable=1;
			mailman_npc->AI=1;
			mailman_came_today=1;
		}
		if(mailman_npc!=NULL)
		{
			if(mailman_npc->AI==1)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&mailman_npc, SPEED_SLOW, 488*8, 531*8)){mailman_npc->AI++;}
			if(mailman_npc->AI==2)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&mailman_npc, SPEED_SLOW, 488*8, 540*8)){mailman_npc->AI++;}
			if(mailman_npc->AI==3)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&mailman_npc, SPEED_SLOW, 492*8, 540*8)){mailman_npc->layer=1;mailman_npc->AI++;NPC_animate_stand_dir(&mailman_npc, UP);mailman_npc->vbls=0;}
			if(mailman_npc->AI==4)if(mailman_npc->vbls>180){mailman_npc->AI++;mailman_npc->vbls=0;}
			if(mailman_npc->AI==5&&GLOBAL_text_engine_state==0)if(mailman_npc->vbls>180){mailman_npc->AI++;mailman_npc->vbls=0;mailman_npc->layer=2;}
			if(mailman_npc->AI==6&&GLOBAL_text_engine_state==0)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&mailman_npc, SPEED_SLOW, 488*8, 540*8)){mailman_npc->AI++;}
			if(mailman_npc->AI==7&&GLOBAL_text_engine_state==0)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&mailman_npc, SPEED_SLOW, 488*8, 531*8)){mailman_npc->AI++;}
			if(mailman_npc->AI==8&&GLOBAL_text_engine_state==0)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&mailman_npc, SPEED_SLOW, 389*8, 531*8)){mailman_npc->AI++;}
			if(mailman_npc->AI==9&&GLOBAL_text_engine_state==0)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&mailman_npc, SPEED_SLOW, 389*8, 540*8)){mailman_npc->AI++;}
			if(mailman_npc->AI==10&&GLOBAL_text_engine_state==0)if(NPC_walk_to_xy_nohit_avoidothers_pushmain(&mailman_npc, SPEED_SLOW, 386*8, 540*8)){mailman_npc->layer=1;NPC_animate_stand_dir(&mailman_npc, UP);mailman_npc->AI++;mailman_npc->vbls=0;}
			if(mailman_npc->AI==11)if(MAP_is_xy_within_screen_by_amt(mailman_npc->MAP_x,mailman_npc->MAP_y,64)==0){NPC_delete_npc(&mailman_npc);}

			if(ACTION_npc(&mailman_npc,"Talk To Pizza Ad Delivery Man")&&GLOBAL_text_engine_state==0)
			{
				TEXT_set_sprite_window(0,mailman_npc,NULL);
				TEXT_set_sprite_window(1,PLAYER_npc,NULL);
				TEXT_window("What does Yuu want, punk?!<.>"
								"I have pepper spray, Yuu knows!<.>"
								"Oh. Yuu lives here, right?<.>"
								"I remember delivering those magazines with blacked out plastic wrappers.<.>"
								"<1>Those are my brother's!<.>"
								"<0>Yeah, clever disguise. *snicker*<.>"
								"So what did Yuu want?<.><1>"
								"Any cool mail for me?<.>"
								"<0>Uhh, sure.<.>Here. Whatever."

								);
				//TODO: get item "neighbors credit card"
				//he tells you an ongoing saga of postcards between the crazy lady and janitor?
				//oh herbert, how i long for your sweet embrace once more
			}
		}
	}
	else
	if(mailman_npc!=NULL){if(MAP_is_xy_within_screen_by_amt(mailman_npc->MAP_x,mailman_npc->MAP_y,64)==0){NPC_delete_npc(&mailman_npc);}}
//===================================================================================================
// ICE CREAM MAN
//===================================================================================================
	//support ice cream man
	//if get within range onscreen, slow down, stop?
	//talk to ice cream man
	//"hey buddy what can i get you?"
		//left street top lane 83*8 546*8
	//right street top lane 1524*8,546*8
	if(CLOCK_hour==12+5&&CLOCK_minute>0&&CLOCK_minute<30)
	{
		if(icecreamtruck_npc==NULL&&MAP_is_xy_within_screen_by_amt(1524*8,540*8,64)==0&&icecreamman_came_today==0&&CLOCK_day!=SUNDAY)//only weekdays, only once a day
		{
			NPC_create_npc(&icecreamtruck_npc,GFX_CAR_icecreamtruck,64,64,1524*8,540*8);
			NPC_set_car_anim_frame_now(&icecreamtruck_npc,2);
			icecreamtruck_npc->non_walkable=1;
			icecreamtruck_npc->animation_off=1;
			icecreamtruck_npc->scale=1.5f;
			icecreamtruck_npc->hitsize_x = 96;
			icecreamtruck_npc->hitsize_y = 36;
			icecreamtruck_npc->size_x = 96;
			icecreamtruck_npc->size_y = 64;
			icecreamtruck_npc->walking_speed=SPEED_NORMAL;
			icecreamman_came_today=1;
			//5:00 pm very slowly travels down road, playing music
		}
		if(icecreamtruck_npc!=NULL)
		{
			static int icecreamsoundvbl=0;
			//if get within range of a lot, hear music
			if(NPC_in_range_of_npc_by_amount(&PLAYER_npc,&icecreamtruck_npc,256)&&(icecreamsoundvbl!=vbl_60_var)){HARDWARE_play_sound("icecreambell",96,44100,0);icecreamsoundvbl=vbl_60_var;}
			if(!NPC_in_range_of_npc_by_amount(&PLAYER_npc,&icecreamtruck_npc,96))NPC_walk_to_xy_nohit_pushmain(&icecreamtruck_npc, icecreamtruck_npc->walking_speed, 83*8, 540*8);
			else
			if(!NPC_in_range_of_npc_by_amount(&PLAYER_npc,&icecreamtruck_npc,64))NPC_walk_to_xy_nohit_pushmain(&icecreamtruck_npc, SPEED_SLOW, 83*8, 540*8);
			else
			{
				if(ACTION_npc(&icecreamtruck_npc,"Talk To Ice Cream Man")&&GLOBAL_text_engine_state==0)
				{
					TEXT_set_sprite_window(0,PLAYER_npc,NULL);
					TEXT_set_sprite_window(1,PLAYER_npc,NULL);
					TEXT_window("Whatcha want, little dude?<.>Oh..<.>Yuu probably wanted ice cream, right?<.><1>What? What else would I want?<.><0>*snort*<.>Sorry man, I'm like, all out of that stuff.<.>Tell your big bro to catch me later, alright?");
					//TODO: need to fix bell/music
					//TODO: need to make guy inside truck come to window. can only talk to him.
					//TODO: make other cars stop.
					//TODO: maybe flash lights when stopped? oh animation frame with guy in window, lights flashing.
					//buy ice cream from him.
				}
			}
		}
	}
	else
	if(icecreamtruck_npc!=NULL)if(MAP_is_xy_within_screen_by_amt(icecreamtruck_npc->MAP_x,icecreamtruck_npc->MAP_y,64)==0||NPC_walk_to_xy_nohit_pushmain(&icecreamtruck_npc, SPEED_SLOW, 83*8, 546*8)){NPC_delete_npc(&icecreamtruck_npc);}
//===================================================================================================
// JOGGER
//===================================================================================================
		//support jogger
	//6:00 am-6:30
	if(CLOCK_hour==6&&CLOCK_minute>0&&CLOCK_minute<30)
	{
		if(jogger_npc==NULL&&MAP_is_xy_within_screen_by_amt(492*8,531*8,64)&&jogger_came_today==0&&CLOCK_day!=SUNDAY)//only weekdays, only once a day
		{
			NPC_create_npc_xy_feet(&jogger_npc,GFX_ADULT_spandexjogger, 16, 40,MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS+16, 531*8);
			jogger_npc->non_walkable=1;
			jogger_came_today=1;
		}
		if(jogger_npc!=NULL)
		{
			if(GLOBAL_text_engine_state==0)if(NPC_walk_to_xy_nohit_pushmain(&jogger_npc, SPEED_NORMAL, 83*8, 531*8)==(1))if(MAP_is_xy_within_screen_by_amt(jogger_npc->MAP_x,jogger_npc->MAP_y,64)==0){NPC_delete_npc(&jogger_npc);}
			if(GLOBAL_text_engine_state!=0&&NPC_should_animate(&jogger_npc))NPC_animate_dir(&jogger_npc,LEFT);
			if(ACTION_npc(&jogger_npc,"Talk To Jogging Guy")&&GLOBAL_text_engine_state==0)
			{
				TEXT_set_sprite_window(0,jogger_npc,NULL);
				TEXT_set_sprite_window(1,PLAYER_npc,NULL);
				TEXT_window("Huff... Huff.. <.>Morning!<.><1>Hey, nice pants.<.><0>Thanks for noticing! Yuu can really see the muscles ripple through this material, right?<.><1>Umm.. Is that a good thing?<.><0>What?<.>Yuu're a jogger too, right? Why else would Yuu be out here so early?<.>Didn't Yuu see the review in the new Jogging Maniac Monthly?<.>Hey, Yuu aren't making fun of me, are Yuu?<.><1>Uhh.. No, not really.<.>I mean, I don't jog.<.>I don't think I could. How can you get up so early to run like that?<.><0>Well, you know how you kinda feel bad about yourself when you see a go-getter like myself grabbing life by the horns?<.><1>Yeah, it makes me feel awful and lazy.. I could never do it.<.><0>See, now that's the secret. Once Yuu do it a few times, it becomes easy. Really gets Yuu started, wakes Yuu up. <.>You're ready to tackle the day after taking on something difficult first thing in the morning.<.>And now all Yuu jerks feel bad about yourselves because of me! It really makes it worth it, Yuu know?<.><1>But I like sleeping in sometimes. Don't you ever want to enjoy your morning?<.><0>Shut up! Shut up, Yuu! That's the nature of DISCIPLINE! <.>Yuu can never enjoy yourself again or Yuu'll lose it! <.>And that's why Yuu must all pay! <.>Huff.. Huff.. I've gotta get moving, keep my heart rate up, people to intimidate, Yuu know.<.><1><SMALL>(That guy's pretty weird.)");
				//TODO:maybe if talk to him a few more times, get jogger maniac monthly?
				//ahhaa maybe have to jog with him
			}
		}
	}
	else
	if(jogger_npc!=NULL)if(MAP_is_xy_within_screen_by_amt(jogger_npc->MAP_x,jogger_npc->MAP_y,64)==0){NPC_delete_npc(&jogger_npc);}
//===================================================================================================
// DOG WALKER
//===================================================================================================

static NPC* dogwalker_npc = NULL;
static NPC* bigdog_npc = NULL;

	//dog walker 7:00 am-7:30
	if(CLOCK_hour==7&&CLOCK_minute>0&&CLOCK_minute<30)
	{

		if(dogwalker_npc==NULL&&MAP_is_xy_within_screen_by_amt(492*8,530*8,64)&&dogwalker_came_today==0&&CLOCK_day!=SUNDAY)//only weekdays, only once a day
		{
			NPC_create_npc_xy_feet(&dogwalker_npc,GFX_ADULT_dogwalker, 16, 40,MAP_cam_x-32, 530*8);
			dogwalker_npc->non_walkable=1;
			dogwalker_npc->walking_speed=SPEED_SLOW;
			NPC_set_anim_frame_now(&dogwalker_npc,8*RIGHT);
			//dogwalker_npc->size_x = 64;
			//dogwalker_npc->size_y = 32;
			//dogwalker_npc->hitsize_x = 64;
			//dogwalker_npc->hitsize_y = 10;
			dogwalker_came_today=1;
		}

		if(dogwalker_npc!=NULL)
		{

			if(bigdog_npc==NULL)
			{
				NPC_create_npc_xy_feet(&bigdog_npc,GFX_ANIMAL_bigdog, 64, 64,dogwalker_npc->MAP_x+32+16, dogwalker_npc->MAP_y+64+16+3);
				bigdog_npc->non_walkable=1;
				bigdog_npc->walking_speed=SPEED_FAST;
				NPC_set_anim_frame_now(&bigdog_npc,8*RIGHT);
				//bigdog_npc->animation_off=1;

				bigdog_npc->size_x = 32;
				bigdog_npc->size_y = 24;
				bigdog_npc->hitsize_x = 32;
				bigdog_npc->hitsize_y = 8;
				///bigdog_npc->shadow = 1;

			}


			if(GLOBAL_text_engine_state==0)
			{

				NPC_walk_to_xy_nohit(&bigdog_npc,dogwalker_npc->walking_speed, dogwalker_npc->MAP_x+32, dogwalker_npc->MAP_y+32+8+3);

				if(NPC_walk_to_xy_nohit(&dogwalker_npc, dogwalker_npc->walking_speed, 1524*8, 530*8))
				{
					if(MAP_is_xy_within_screen_by_amt(dogwalker_npc->MAP_x,dogwalker_npc->MAP_y,64)==0)
					{
						if(dogwalker_npc!=NULL)NPC_delete_npc(&dogwalker_npc);
						if(bigdog_npc!=NULL)NPC_delete_npc(&bigdog_npc);
					}
				}
			}


			if(ACTION_npc(&dogwalker_npc,"Talk To Dog Walker")&&GLOBAL_text_engine_state==0)
			{
				TEXT_set_sprite_window(0,dogwalker_npc,NULL);
				TEXT_set_sprite_window(1,PLAYER_npc,NULL);
				TEXT_window("Whoa, hold on there, Rover.<.>Whatcha need, kid?<.><1>Nice dog.<.><0>Yeah? That's all Yuu want to say?<.><1>Well, yeah.<.><0>I'm no sucker, kid. I can tell when I'm being threatened.<.><1>What? I just said nice dog.<.><0>...<.>Yuu didn't see that, alright?<.>Okay, look here. <.>This grass by the street is public property. That means it belongs to all of us, right?<.>Those fire hydrants could use a good washing anyway. They should pay me for my services.<.>...<.>Look, If Yuu say anything, I'm gonna tell em' Yuu did it, and everyone will laugh at Yuu. Got it, runt?<.>Let's go, Rover. I don't like the looks of this guy. He's probably some sort of criminal.<.>Get off my case, alright! Just take it, Yuu little blackmailer!");
				//TODO: get ?? wallet? cash?
				//TODO: dog noises? bark? pant?
				//and this grass needs to be fertilized, right? who do you think paid for those nutrients?
				//maybe make poop on the grass. on the sidewalk? its not my fault he missed.
				dogwalker_npc->walking_speed = SPEED_FASTEST;
			}

		}

	}
	else
	{
		if(dogwalker_npc!=NULL)if(MAP_is_xy_within_screen_by_amt(dogwalker_npc->MAP_x,dogwalker_npc->MAP_y,64)==0){NPC_delete_npc(&dogwalker_npc);}

		if(bigdog_npc!=NULL)if(MAP_is_xy_within_screen_by_amt(bigdog_npc->MAP_x,bigdog_npc->MAP_y,64)==0){NPC_delete_npc(&bigdog_npc);}
	}
//===================================================================================================
// TOWN
//===================================================================================================
//===================================================================================================
// CLINIC PARKING LOT
//===================================================================================================
	//support cars in parking lots, 8am to 9pm
	//only created on load, only offscreen.
	//if you stand there and watch, stays empty.
	//maybe "if NOT in range, and past time, draw here. then keep here.
	//clinic parking lot
	//375, 243
	//256
	//269
	//281



	static NPC* clinicparkinglotcars[4] = {NULL,NULL,NULL,NULL};


	NPC_create_car_if_within_range_else_delete(&clinicparkinglotcars[0],375*8,243*8,RIGHT);
	NPC_create_car_if_within_range_else_delete(&clinicparkinglotcars[1],376*8,256*8,RIGHT);
	NPC_create_car_if_within_range_else_delete(&clinicparkinglotcars[2],374*8,269*8,LEFT);
	NPC_create_car_if_within_range_else_delete(&clinicparkinglotcars[3],375*8,281*8,RIGHT);


	static NPC* ambulancecar = NULL;

	if(MAP_is_xy_within_screen_by_amt(375*8+96/2,293*8+96/2,128)==1)
	{
		if(ambulancecar==NULL)
		{
			NPC_create_npc(&ambulancecar,GFX_CAR_ambulance,64,64,376*8,294*8);
			NPC_set_car_anim_frame_now(&ambulancecar,LEFT);
			ambulancecar->non_walkable=1;
			ambulancecar->animation_off=1;
			ambulancecar->scale=1.5f;
		}
	}
	else
	if(ambulancecar!=NULL)
	{
		NPC_delete_npc(&ambulancecar);
	}




static NPC* clinic_npcs[5] = {NULL,NULL,NULL,NULL,NULL};

	if(MAP_is_xy_within_screen_by_amt(403*8,301*8,64))
	{

		static int last_vbl_30=0;


		for(c=0;c<5;c++)
		if(clinic_npcs[c]==NULL&&last_vbl_30!=vbl_30_var)
		{

			last_vbl_30=vbl_30_var;

			int cycle=r(6);
			if(cycle==0)NPC_create_random_ADULT_xy_feet(&clinic_npcs[c],(403)*8,301*8);
			if(cycle==1)NPC_create_random_ADULT_xy_feet(&clinic_npcs[c],(403)*8,301*8);
			if(cycle==2)NPC_create_random_ADULT_xy_feet(&clinic_npcs[c],(403)*8,301*8);
			if(cycle==3)NPC_create_random_ADULT_xy_feet(&clinic_npcs[c],383*8,283*8);
			if(cycle==4)NPC_create_random_ADULT_xy_feet(&clinic_npcs[c],378*8,271*8);
			if(cycle==5)NPC_create_random_ADULT_xy_feet(&clinic_npcs[c],383*8,256*8);
			clinic_npcs[c]->walking_speed = SPEED_NORMAL+r(SPEED_SLOWEST-SPEED_FASTEST);
			if(cycle<3)clinic_npcs[c]->AI=0;
			if(cycle>=3)clinic_npcs[c]->AI=10;
			clinic_npcs[c]->alpha=0;

		}
	}

	for(c=0;c<5;c++)
	if(clinic_npcs[c]!=NULL)
	{

		if(clinic_npcs[c]->AI<16&&clinic_npcs[c]->alpha<255)NPC_set_alpha(&clinic_npcs[c],clinic_npcs[c]->alpha+1);

		if(clinic_npcs[c]->AI==0){if((MAP_is_xy_within_screen_by_amt(clinic_npcs[c]->MAP_x,clinic_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&clinic_npcs[c], clinic_npcs[c]->walking_speed, -1, 307*8)){clinic_npcs[c]->AI=1+r(3);}}
		//out
		else if(clinic_npcs[c]->AI==1){if((MAP_is_xy_within_screen_by_amt(clinic_npcs[c]->MAP_x,clinic_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&clinic_npcs[c], clinic_npcs[c]->walking_speed, 394*8, -1)){clinic_npcs[c]->AI+=3;}}
		else if(clinic_npcs[c]->AI==2){if((MAP_is_xy_within_screen_by_amt(clinic_npcs[c]->MAP_x,clinic_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&clinic_npcs[c], clinic_npcs[c]->walking_speed, 395*8, -1)){clinic_npcs[c]->AI+=3;}}
		else if(clinic_npcs[c]->AI==3){if((MAP_is_xy_within_screen_by_amt(clinic_npcs[c]->MAP_x,clinic_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&clinic_npcs[c], clinic_npcs[c]->walking_speed, 396*8, -1)){clinic_npcs[c]->AI+=3;}}

		else if(clinic_npcs[c]->AI==4){if((MAP_is_xy_within_screen_by_amt(clinic_npcs[c]->MAP_x,clinic_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&clinic_npcs[c], clinic_npcs[c]->walking_speed, -1, 279*8)){clinic_npcs[c]->AI+=3;}}
		else if(clinic_npcs[c]->AI==5){if((MAP_is_xy_within_screen_by_amt(clinic_npcs[c]->MAP_x,clinic_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&clinic_npcs[c], clinic_npcs[c]->walking_speed, -1, 267*8)){clinic_npcs[c]->AI+=3;}}
		else if(clinic_npcs[c]->AI==6){if((MAP_is_xy_within_screen_by_amt(clinic_npcs[c]->MAP_x,clinic_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&clinic_npcs[c], clinic_npcs[c]->walking_speed, -1, 253*8)){clinic_npcs[c]->AI+=3;}}

		else if(clinic_npcs[c]->AI==7){if((MAP_is_xy_within_screen_by_amt(clinic_npcs[c]->MAP_x,clinic_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&clinic_npcs[c], clinic_npcs[c]->walking_speed, 383*8, 283*8)){clinic_npcs[c]->AI=16;}}
		else if(clinic_npcs[c]->AI==8){if((MAP_is_xy_within_screen_by_amt(clinic_npcs[c]->MAP_x,clinic_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&clinic_npcs[c], clinic_npcs[c]->walking_speed, 378*8, 271*8)){clinic_npcs[c]->AI=16;}}
		else if(clinic_npcs[c]->AI==9){if((MAP_is_xy_within_screen_by_amt(clinic_npcs[c]->MAP_x,clinic_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&clinic_npcs[c], clinic_npcs[c]->walking_speed, 383*8, 256*8)){clinic_npcs[c]->AI=16;}}

		//in
		else if(clinic_npcs[c]->AI==10){if((MAP_is_xy_within_screen_by_amt(clinic_npcs[c]->MAP_x,clinic_npcs[c]->MAP_y,GAME_VIEWPORT_WIDTH_PIXELS/2)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&clinic_npcs[c], clinic_npcs[c]->walking_speed, 393*8, -1)){clinic_npcs[c]->AI+=1+r(2);}}

		else if(clinic_npcs[c]->AI==11){if((MAP_is_xy_within_screen_by_amt(clinic_npcs[c]->MAP_x,clinic_npcs[c]->MAP_y,GAME_VIEWPORT_WIDTH_PIXELS/2)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&clinic_npcs[c], clinic_npcs[c]->walking_speed, -1, 305*8)){clinic_npcs[c]->AI+=2;}}
		else if(clinic_npcs[c]->AI==12){if((MAP_is_xy_within_screen_by_amt(clinic_npcs[c]->MAP_x,clinic_npcs[c]->MAP_y,GAME_VIEWPORT_WIDTH_PIXELS/2)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&clinic_npcs[c], clinic_npcs[c]->walking_speed, -1, 306*8)){clinic_npcs[c]->AI+=2;}}

		else if(clinic_npcs[c]->AI==13){if((MAP_is_xy_within_screen_by_amt(clinic_npcs[c]->MAP_x,clinic_npcs[c]->MAP_y,GAME_VIEWPORT_WIDTH_PIXELS/2)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&clinic_npcs[c], clinic_npcs[c]->walking_speed, 402*8, -1)){clinic_npcs[c]->AI=15;}}
		else if(clinic_npcs[c]->AI==14){if((MAP_is_xy_within_screen_by_amt(clinic_npcs[c]->MAP_x,clinic_npcs[c]->MAP_y,GAME_VIEWPORT_WIDTH_PIXELS/2)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&clinic_npcs[c], clinic_npcs[c]->walking_speed, 403*8, -1)){clinic_npcs[c]->AI=15;}}

		else if(clinic_npcs[c]->AI==15){if((MAP_is_xy_within_screen_by_amt(clinic_npcs[c]->MAP_x,clinic_npcs[c]->MAP_y,GAME_VIEWPORT_WIDTH_PIXELS/2)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&clinic_npcs[c], clinic_npcs[c]->walking_speed, 403*8, 301*8)){clinic_npcs[c]->AI=16;}}

		else if(clinic_npcs[c]->AI==16){NPC_fade_out_and_delete(&clinic_npcs[c]);}


	}






//===================================================================================================
// CHURCH PARKING LOT
//===================================================================================================
	//church
	//454 208
	//221
	//234
	//248
	//261
	//273

	static NPC* churchparkinglotcars[6] = {NULL,NULL,NULL,NULL,NULL,NULL};


	NPC_create_car_if_within_range_else_delete(&churchparkinglotcars[0],454*8,208*8,LEFT);
	NPC_create_car_if_within_range_else_delete(&churchparkinglotcars[1],454*8,221*8,RIGHT);
	//NPC_create_car_if_within_range_else_delete(&churchparkinglotcars[2],453*8,234*8,RIGHT);
	NPC_create_car_if_within_range_else_delete(&churchparkinglotcars[3],454*8,248*8,RIGHT);
	NPC_create_car_if_within_range_else_delete(&churchparkinglotcars[4],454*8,260*8,RIGHT);
	NPC_create_car_if_within_range_else_delete(&churchparkinglotcars[5],453*8,273*8,RIGHT);


	//TODO: people loitering on sunday


static NPC* church_npcs[5] = {NULL,NULL,NULL,NULL,NULL};

	if(MAP_is_xy_within_screen_by_amt(498*8,293*8,64))
	{

		static int last_vbl_30=0;


		for(c=0;c<5;c++)
		if(church_npcs[c]==NULL&&last_vbl_30!=vbl_30_var)
		{

			last_vbl_30=vbl_30_var;

			int cycle=r(6);
			if(cycle==0)NPC_create_random_ADULT_xy_feet(&church_npcs[c],(499)*8,293*8);
			if(cycle==1)NPC_create_random_ADULT_xy_feet(&church_npcs[c],(499)*8,293*8);
			if(cycle==2)NPC_create_random_ADULT_xy_feet(&church_npcs[c],(499)*8,293*8);
			if(cycle==3)NPC_create_random_ADULT_xy_feet(&church_npcs[c],461*8,275*8);
			if(cycle==4)NPC_create_random_ADULT_xy_feet(&church_npcs[c],461*8,262*8);
			if(cycle==5)NPC_create_random_ADULT_xy_feet(&church_npcs[c],461*8,250*8);
			church_npcs[c]->walking_speed = SPEED_NORMAL+r(SPEED_SLOWEST-SPEED_FASTEST);
			if(cycle<3)church_npcs[c]->AI=0;
			if(cycle>=3)church_npcs[c]->AI=10;
			church_npcs[c]->alpha=0;

		}
	}

	for(c=0;c<5;c++)
	if(church_npcs[c]!=NULL)
	{

		if(church_npcs[c]->AI<16&&church_npcs[c]->alpha<255)NPC_set_alpha(&church_npcs[c],church_npcs[c]->alpha+1);

		if(church_npcs[c]->AI==0){if((MAP_is_xy_within_screen_by_amt(church_npcs[c]->MAP_x,church_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&church_npcs[c], church_npcs[c]->walking_speed, -1, 298*8)){church_npcs[c]->AI=1+r(3);}}
		//out
		else if(church_npcs[c]->AI==1){if((MAP_is_xy_within_screen_by_amt(church_npcs[c]->MAP_x,church_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&church_npcs[c], church_npcs[c]->walking_speed, 470*8, -1)){church_npcs[c]->AI+=3;}}
		else if(church_npcs[c]->AI==2){if((MAP_is_xy_within_screen_by_amt(church_npcs[c]->MAP_x,church_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&church_npcs[c], church_npcs[c]->walking_speed, 472*8, -1)){church_npcs[c]->AI+=3;}}
		else if(church_npcs[c]->AI==3){if((MAP_is_xy_within_screen_by_amt(church_npcs[c]->MAP_x,church_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&church_npcs[c], church_npcs[c]->walking_speed, 471*8, -1)){church_npcs[c]->AI+=3;}}

		else if(church_npcs[c]->AI==4){if((MAP_is_xy_within_screen_by_amt(church_npcs[c]->MAP_x,church_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&church_npcs[c], church_npcs[c]->walking_speed, -1, 272*8)){church_npcs[c]->AI+=3;}}
		else if(church_npcs[c]->AI==5){if((MAP_is_xy_within_screen_by_amt(church_npcs[c]->MAP_x,church_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&church_npcs[c], church_npcs[c]->walking_speed, -1, 260*8)){church_npcs[c]->AI+=3;}}
		else if(church_npcs[c]->AI==6){if((MAP_is_xy_within_screen_by_amt(church_npcs[c]->MAP_x,church_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&church_npcs[c], church_npcs[c]->walking_speed, -1, 248*8)){church_npcs[c]->AI+=3;}}

		else if(church_npcs[c]->AI==7){if((MAP_is_xy_within_screen_by_amt(church_npcs[c]->MAP_x,church_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&church_npcs[c], church_npcs[c]->walking_speed, 461*8, 275*8)){church_npcs[c]->AI=16;}}
		else if(church_npcs[c]->AI==8){if((MAP_is_xy_within_screen_by_amt(church_npcs[c]->MAP_x,church_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&church_npcs[c], church_npcs[c]->walking_speed, 461*8, 262*8)){church_npcs[c]->AI=16;}}
		else if(church_npcs[c]->AI==9){if((MAP_is_xy_within_screen_by_amt(church_npcs[c]->MAP_x,church_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&church_npcs[c], church_npcs[c]->walking_speed, 461*8, 250*8)){church_npcs[c]->AI=16;}}

		//in
		else if(church_npcs[c]->AI==10){if((MAP_is_xy_within_screen_by_amt(church_npcs[c]->MAP_x,church_npcs[c]->MAP_y,GAME_VIEWPORT_WIDTH_PIXELS/2)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&church_npcs[c], church_npcs[c]->walking_speed, 471*8, -1)){church_npcs[c]->AI+=1+r(2);}}

		else if(church_npcs[c]->AI==11){if((MAP_is_xy_within_screen_by_amt(church_npcs[c]->MAP_x,church_npcs[c]->MAP_y,GAME_VIEWPORT_WIDTH_PIXELS/2)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&church_npcs[c], church_npcs[c]->walking_speed, -1, 299*8)){church_npcs[c]->AI+=2;}}
		else if(church_npcs[c]->AI==12){if((MAP_is_xy_within_screen_by_amt(church_npcs[c]->MAP_x,church_npcs[c]->MAP_y,GAME_VIEWPORT_WIDTH_PIXELS/2)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&church_npcs[c], church_npcs[c]->walking_speed, -1, 300*8)){church_npcs[c]->AI+=2;}}

		else if(church_npcs[c]->AI==13){if((MAP_is_xy_within_screen_by_amt(church_npcs[c]->MAP_x,church_npcs[c]->MAP_y,GAME_VIEWPORT_WIDTH_PIXELS/2)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&church_npcs[c], church_npcs[c]->walking_speed, 497*8, -1)){church_npcs[c]->AI=15;}}
		else if(church_npcs[c]->AI==14){if((MAP_is_xy_within_screen_by_amt(church_npcs[c]->MAP_x,church_npcs[c]->MAP_y,GAME_VIEWPORT_WIDTH_PIXELS/2)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&church_npcs[c], church_npcs[c]->walking_speed, 496*8, -1)){church_npcs[c]->AI=15;}}

		else if(church_npcs[c]->AI==15){if((MAP_is_xy_within_screen_by_amt(church_npcs[c]->MAP_x,church_npcs[c]->MAP_y,GAME_VIEWPORT_WIDTH_PIXELS/2)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&church_npcs[c], church_npcs[c]->walking_speed, 497*8, 293*8)){church_npcs[c]->AI=16;}}

		else if(church_npcs[c]->AI==16){NPC_fade_out_and_delete(&church_npcs[c]);}


	}





//===================================================================================================
// FAST FOOD PARKING LOT
//===================================================================================================
	//fast food cars
	//611,210
	//612,223
	//611,236
	//612,249
	//612,262
	//612,276

	static NPC* fastfoodparkinglotcars[7] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL};


	NPC_create_car_if_within_range_else_delete(&fastfoodparkinglotcars[0],611*8,210*8,RIGHT);
	NPC_create_car_if_within_range_else_delete(&fastfoodparkinglotcars[1],612*8,223*8,LEFT);
	NPC_create_car_if_within_range_else_delete(&fastfoodparkinglotcars[2],611*8,249*8,RIGHT);
	NPC_create_car_if_within_range_else_delete(&fastfoodparkinglotcars[3],611*8,262*8,RIGHT);
	NPC_create_car_if_within_range_else_delete(&fastfoodparkinglotcars[4],610*8,275*8,LEFT);
	NPC_create_car_if_within_range_else_delete(&fastfoodparkinglotcars[5],611*8,288*8,RIGHT);
	NPC_create_car_if_within_range_else_delete(&fastfoodparkinglotcars[6],611*8,300*8,RIGHT);
//===================================================================================================
// FAST FOOD DRIVE THROUGH CAR
//===================================================================================================
	//cars come in at 594,317
	//to 594,221 set left
	//539,221 going left. maybe pause at 560?? drive thru
	//set down, goto 539,265, stop at window going down.
	//goto 539,317 delete if offscreen

	static NPC* fastfoodcar_npc=NULL;


	if(MAP_is_xy_within_screen_by_amt(594*8,265*8,64))
	{
		if(fastfoodcar_npc==NULL)NPC_create_car(&fastfoodcar_npc,592*8,MAP_cam_y+GAME_VIEWPORT_HEIGHT_PIXELS+64, UP);//create car offscreen coords 308, touchmap y
	}

	if(fastfoodcar_npc!=NULL)
	{
		if(fastfoodcar_npc->AI==0)
		{
			if(NPC_walk_to_xy_stop_for_other_npcs_amt(&fastfoodcar_npc, SPEED_NORMAL, 596*8, 210*8,16))
			{
				NPC_set_car_anim_frame_now(&fastfoodcar_npc,LEFT);
				fastfoodcar_npc->vbls=0;
				fastfoodcar_npc->AI++;
				fastfoodcar_npc->layer=3;
			}
		}
		if(fastfoodcar_npc->AI==1)
		{
			if(NPC_walk_to_xy_stop_for_other_npcs_amt(&fastfoodcar_npc, SPEED_NORMAL, 560*8, 218*8,16))
			{
				fastfoodcar_npc->AI++;
				fastfoodcar_npc->vbls=0;
				if(MAP_is_xy_within_screen_by_amt(560*8,218*8,64))HARDWARE_play_sound("fastfooddrivethru",127,44100,0);
			}
		}
		if(fastfoodcar_npc->AI==2)if(fastfoodcar_npc->vbls>180)fastfoodcar_npc->AI++;
		if(fastfoodcar_npc->AI==3)
		{
			if(NPC_walk_to_xy_stop_for_other_npcs_amt(&fastfoodcar_npc, SPEED_NORMAL, 545*8, 218*8,16))
			{
				NPC_set_car_anim_frame_now(&fastfoodcar_npc,DOWN);
				fastfoodcar_npc->vbls=0;
				fastfoodcar_npc->AI++;
				fastfoodcar_npc->layer=2;
			}
		}
		if(fastfoodcar_npc->AI==4)if(NPC_walk_to_xy_stop_for_other_npcs_amt(&fastfoodcar_npc, SPEED_NORMAL,543*8, 265*8,16)){fastfoodcar_npc->AI++;fastfoodcar_npc->vbls=0;}
		if(fastfoodcar_npc->AI==5)if(fastfoodcar_npc->vbls>180)fastfoodcar_npc->AI++;
		if(fastfoodcar_npc->AI==6)
		{
			if(NPC_walk_to_xy_stop_for_other_npcs_amt(&fastfoodcar_npc, SPEED_NORMAL, 543*8, 317*8,16)
				&&MAP_is_xy_within_screen_by_amt(fastfoodcar_npc->MAP_x,fastfoodcar_npc->MAP_y,64)==0)
					{NPC_delete_npc(&fastfoodcar_npc);}
		}

	}


//===================================================================================================
// PEOPLE COMING IN AND OUT OF TACOBURGER
//===================================================================================================


static NPC* tacoburger_npcs[5] = {NULL,NULL,NULL,NULL,NULL};

	if(MAP_is_xy_within_screen_by_amt(579*8,292*8,64))
	{

		static int last_vbl_30=0;


		for(c=0;c<5;c++)
		if(tacoburger_npcs[c]==NULL&&last_vbl_30!=vbl_30_var)
		{

			last_vbl_30=vbl_30_var;

			int cycle=r(6);
			if(cycle==0)NPC_create_random_ADULT_xy_feet(&tacoburger_npcs[c],(579)*8,292*8);
			if(cycle==1)NPC_create_random_ADULT_xy_feet(&tacoburger_npcs[c],(579)*8,292*8);
			if(cycle==2)NPC_create_random_ADULT_xy_feet(&tacoburger_npcs[c],(579)*8,292*8);
			if(cycle==3)NPC_create_random_ADULT_xy_feet(&tacoburger_npcs[c],618*8,302*8);
			if(cycle==4)NPC_create_random_ADULT_xy_feet(&tacoburger_npcs[c],618*8,291*8);
			if(cycle==5)NPC_create_random_ADULT_xy_feet(&tacoburger_npcs[c],614*8,278*8);
			tacoburger_npcs[c]->walking_speed = SPEED_NORMAL+r(SPEED_SLOWEST-SPEED_FASTEST);
			if(cycle<3)tacoburger_npcs[c]->AI=0;
			if(cycle>=3)tacoburger_npcs[c]->AI=10;
			tacoburger_npcs[c]->alpha=0;

		}
	}

	for(c=0;c<5;c++)
	if(tacoburger_npcs[c]!=NULL)
	{

		if(tacoburger_npcs[c]->AI<16&&tacoburger_npcs[c]->alpha<255)NPC_set_alpha(&tacoburger_npcs[c],tacoburger_npcs[c]->alpha+1);

		if(tacoburger_npcs[c]->AI==0){if((MAP_is_xy_within_screen_by_amt(tacoburger_npcs[c]->MAP_x,tacoburger_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&tacoburger_npcs[c], tacoburger_npcs[c]->walking_speed, -1, 296*8)){tacoburger_npcs[c]->AI=1+r(3);}}
		//out
		else if(tacoburger_npcs[c]->AI==1){if((MAP_is_xy_within_screen_by_amt(tacoburger_npcs[c]->MAP_x,tacoburger_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&tacoburger_npcs[c], tacoburger_npcs[c]->walking_speed, 607*8, -1)){tacoburger_npcs[c]->AI+=3;}}
		else if(tacoburger_npcs[c]->AI==2){if((MAP_is_xy_within_screen_by_amt(tacoburger_npcs[c]->MAP_x,tacoburger_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&tacoburger_npcs[c], tacoburger_npcs[c]->walking_speed, 608*8, -1)){tacoburger_npcs[c]->AI+=3;}}
		else if(tacoburger_npcs[c]->AI==3){if((MAP_is_xy_within_screen_by_amt(tacoburger_npcs[c]->MAP_x,tacoburger_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&tacoburger_npcs[c], tacoburger_npcs[c]->walking_speed, 609*8, -1)){tacoburger_npcs[c]->AI+=3;}}

		else if(tacoburger_npcs[c]->AI==4){if((MAP_is_xy_within_screen_by_amt(tacoburger_npcs[c]->MAP_x,tacoburger_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&tacoburger_npcs[c], tacoburger_npcs[c]->walking_speed, -1, 302*8)){tacoburger_npcs[c]->AI+=3;}}
		else if(tacoburger_npcs[c]->AI==5){if((MAP_is_xy_within_screen_by_amt(tacoburger_npcs[c]->MAP_x,tacoburger_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&tacoburger_npcs[c], tacoburger_npcs[c]->walking_speed, -1, 291*8)){tacoburger_npcs[c]->AI+=3;}}
		else if(tacoburger_npcs[c]->AI==6){if((MAP_is_xy_within_screen_by_amt(tacoburger_npcs[c]->MAP_x,tacoburger_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&tacoburger_npcs[c], tacoburger_npcs[c]->walking_speed, -1, 278*8)){tacoburger_npcs[c]->AI+=3;}}

		else if(tacoburger_npcs[c]->AI==7){if((MAP_is_xy_within_screen_by_amt(tacoburger_npcs[c]->MAP_x,tacoburger_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&tacoburger_npcs[c], tacoburger_npcs[c]->walking_speed, 618*8, 302*8)){tacoburger_npcs[c]->AI=16;}}
		else if(tacoburger_npcs[c]->AI==8){if((MAP_is_xy_within_screen_by_amt(tacoburger_npcs[c]->MAP_x,tacoburger_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&tacoburger_npcs[c], tacoburger_npcs[c]->walking_speed, 618*8, 291*8)){tacoburger_npcs[c]->AI=16;}}
		else if(tacoburger_npcs[c]->AI==9){if((MAP_is_xy_within_screen_by_amt(tacoburger_npcs[c]->MAP_x,tacoburger_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&tacoburger_npcs[c], tacoburger_npcs[c]->walking_speed, 614*8, 278*8)){tacoburger_npcs[c]->AI=16;}}
		//in
		else if(tacoburger_npcs[c]->AI==10){if((MAP_is_xy_within_screen_by_amt(tacoburger_npcs[c]->MAP_x,tacoburger_npcs[c]->MAP_y,GAME_VIEWPORT_WIDTH_PIXELS/2)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&tacoburger_npcs[c], tacoburger_npcs[c]->walking_speed, 607*8, -1)){tacoburger_npcs[c]->AI+=1+r(2);}}

		else if(tacoburger_npcs[c]->AI==11){if((MAP_is_xy_within_screen_by_amt(tacoburger_npcs[c]->MAP_x,tacoburger_npcs[c]->MAP_y,GAME_VIEWPORT_WIDTH_PIXELS/2)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&tacoburger_npcs[c], tacoburger_npcs[c]->walking_speed, -1, 296*8)){tacoburger_npcs[c]->AI+=2;}}
		else if(tacoburger_npcs[c]->AI==12){if((MAP_is_xy_within_screen_by_amt(tacoburger_npcs[c]->MAP_x,tacoburger_npcs[c]->MAP_y,GAME_VIEWPORT_WIDTH_PIXELS/2)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&tacoburger_npcs[c], tacoburger_npcs[c]->walking_speed, -1, 294*8)){tacoburger_npcs[c]->AI+=2;}}

		else if(tacoburger_npcs[c]->AI==13){if((MAP_is_xy_within_screen_by_amt(tacoburger_npcs[c]->MAP_x,tacoburger_npcs[c]->MAP_y,GAME_VIEWPORT_WIDTH_PIXELS/2)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&tacoburger_npcs[c], tacoburger_npcs[c]->walking_speed, 576*8, -1)){tacoburger_npcs[c]->AI=15;}}
		else if(tacoburger_npcs[c]->AI==14){if((MAP_is_xy_within_screen_by_amt(tacoburger_npcs[c]->MAP_x,tacoburger_npcs[c]->MAP_y,GAME_VIEWPORT_WIDTH_PIXELS/2)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&tacoburger_npcs[c], tacoburger_npcs[c]->walking_speed, 577*8, -1)){tacoburger_npcs[c]->AI=15;}}

		else if(tacoburger_npcs[c]->AI==15){if((MAP_is_xy_within_screen_by_amt(tacoburger_npcs[c]->MAP_x,tacoburger_npcs[c]->MAP_y,GAME_VIEWPORT_WIDTH_PIXELS/2)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&tacoburger_npcs[c], tacoburger_npcs[c]->walking_speed, 577*8, 292*8)){tacoburger_npcs[c]->AI=16;}}

		else if(tacoburger_npcs[c]->AI==16){NPC_fade_out_and_delete(&tacoburger_npcs[c]);}


	}



//===================================================================================================
// GAS STATION PARKING LOT PUMP CARS
//===================================================================================================
		//730,237 face left
	//696 278
	//696 253
	//713 257
	//713, 283
	//726,274 face down
	//726,248 face down
	//744 282
	//744 250
	static NPC* gasstationcars[9] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};

	NPC_create_car_if_within_range_else_delete(&gasstationcars[0],730*8,234*8,LEFT);
	//NPC_create_car_if_within_range_else_delete(&gasstationcars[1],696*8,278*8,UP);
	NPC_create_car_if_within_range_else_delete(&gasstationcars[2],696*8,253*8,UP);
	//NPC_create_car_if_within_range_else_delete(&gasstationcars[3],711*8,279*8,DOWN);
	NPC_create_car_if_within_range_else_delete(&gasstationcars[4],713*8,257*8,DOWN);
	NPC_create_car_if_within_range_else_delete(&gasstationcars[5],726*8,274*8,UP);
	//NPC_create_car_if_within_range_else_delete(&gasstationcars[6],726*8,248*8,UP);
	NPC_create_car_if_within_range_else_delete(&gasstationcars[7],742*8,277*8,DOWN);
	NPC_create_car_if_within_range_else_delete(&gasstationcars[8],744*8,250*8,DOWN);
	//===================================================================================================
// GAS STATION RANDOM GUYS GOING IN AND OUT
//===================================================================================================
//713,228

static NPC* gasstation_npcs[10] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};

	if(MAP_is_xy_within_screen_by_amt(713*8,228*8,64))
	{

		static int last_vbl_30=0;


		for(c=0;c<10;c++)
		if(gasstation_npcs[c]==NULL&&last_vbl_30!=vbl_30_var)
		{

			last_vbl_30=vbl_30_var;

			int cycle=r(6);
			if(cycle==0)NPC_create_random_ADULT_xy_feet(&gasstation_npcs[c],(713)*8,228*8);
			if(cycle==1)NPC_create_random_ADULT_xy_feet(&gasstation_npcs[c],(713)*8,228*8);
			if(cycle==2)NPC_create_random_ADULT_xy_feet(&gasstation_npcs[c],(713)*8,228*8);
			if(cycle==3)NPC_create_random_ADULT_xy_feet(&gasstation_npcs[c],696*8,257*8);
			if(cycle==4)NPC_create_random_ADULT_xy_feet(&gasstation_npcs[c],722*8,264*8);
			if(cycle==5)NPC_create_random_ADULT_xy_feet(&gasstation_npcs[c],726*8,279*8);
			gasstation_npcs[c]->walking_speed = SPEED_NORMAL+r(SPEED_SLOWEST-SPEED_FASTEST);
			if(cycle<3)gasstation_npcs[c]->AI=0;
			if(cycle>=3)gasstation_npcs[c]->AI=7;
			gasstation_npcs[c]->alpha=0;

		}
	}
	for(c=0;c<10;c++)
	if(gasstation_npcs[c]!=NULL)
	{
		if(gasstation_npcs[c]->AI<11&&gasstation_npcs[c]->alpha<255)NPC_set_alpha(&gasstation_npcs[c],gasstation_npcs[c]->alpha+1);

		if(gasstation_npcs[c]->AI==0){if((MAP_is_xy_within_screen_by_amt(gasstation_npcs[c]->MAP_x,gasstation_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&gasstation_npcs[c], gasstation_npcs[c]->walking_speed, -1, 240*8)){gasstation_npcs[c]->AI=1+r(3);}}
		//out
		else if(gasstation_npcs[c]->AI==1){if((MAP_is_xy_within_screen_by_amt(gasstation_npcs[c]->MAP_x,gasstation_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&gasstation_npcs[c], gasstation_npcs[c]->walking_speed, 696*8, -1)){gasstation_npcs[c]->AI+=3;}}
		else if(gasstation_npcs[c]->AI==2){if((MAP_is_xy_within_screen_by_amt(gasstation_npcs[c]->MAP_x,gasstation_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&gasstation_npcs[c], gasstation_npcs[c]->walking_speed, 722*8, -1)){gasstation_npcs[c]->AI+=3;}}
		else if(gasstation_npcs[c]->AI==3){if((MAP_is_xy_within_screen_by_amt(gasstation_npcs[c]->MAP_x,gasstation_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&gasstation_npcs[c], gasstation_npcs[c]->walking_speed, 726*8, -1)){gasstation_npcs[c]->AI+=3;}}

		else if(gasstation_npcs[c]->AI==4){if((MAP_is_xy_within_screen_by_amt(gasstation_npcs[c]->MAP_x,gasstation_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&gasstation_npcs[c], gasstation_npcs[c]->walking_speed, 696*8, 257*8)){gasstation_npcs[c]->AI=11;}}
		else if(gasstation_npcs[c]->AI==5){if((MAP_is_xy_within_screen_by_amt(gasstation_npcs[c]->MAP_x,gasstation_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&gasstation_npcs[c], gasstation_npcs[c]->walking_speed, 722*8, 264*8)){gasstation_npcs[c]->AI=11;}}
		else if(gasstation_npcs[c]->AI==6){if((MAP_is_xy_within_screen_by_amt(gasstation_npcs[c]->MAP_x,gasstation_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&gasstation_npcs[c], gasstation_npcs[c]->walking_speed, 726*8, 279*8)){gasstation_npcs[c]->AI=11;}}

		//in
		else if(gasstation_npcs[c]->AI==7){if((MAP_is_xy_within_screen_by_amt(gasstation_npcs[c]->MAP_x,gasstation_npcs[c]->MAP_y,GAME_VIEWPORT_WIDTH_PIXELS/2)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&gasstation_npcs[c], gasstation_npcs[c]->walking_speed, -1, 242*8)){gasstation_npcs[c]->AI+=1+r(2);}}

		else if(gasstation_npcs[c]->AI==8){if((MAP_is_xy_within_screen_by_amt(gasstation_npcs[c]->MAP_x,gasstation_npcs[c]->MAP_y,GAME_VIEWPORT_WIDTH_PIXELS/2)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&gasstation_npcs[c], gasstation_npcs[c]->walking_speed, 715*8, -1)){gasstation_npcs[c]->AI=10;}}
		else if(gasstation_npcs[c]->AI==9){if((MAP_is_xy_within_screen_by_amt(gasstation_npcs[c]->MAP_x,gasstation_npcs[c]->MAP_y,GAME_VIEWPORT_WIDTH_PIXELS/2)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&gasstation_npcs[c], gasstation_npcs[c]->walking_speed, 717*8, -1)){gasstation_npcs[c]->AI=10;}}

		else if(gasstation_npcs[c]->AI==10){if((MAP_is_xy_within_screen_by_amt(gasstation_npcs[c]->MAP_x,gasstation_npcs[c]->MAP_y,GAME_VIEWPORT_WIDTH_PIXELS/2)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&gasstation_npcs[c], gasstation_npcs[c]->walking_speed, 715*8, 228*8)){gasstation_npcs[c]->AI=11;}}

		else if(gasstation_npcs[c]->AI==11){NPC_fade_out_and_delete(&gasstation_npcs[c]);}


	}





	//===================================================================================================
// SHOPPING CENTER LEFT PARKING LOT
//===================================================================================================
	//shopping center cars
	//767,278
	//781
	//796
	//809
	//823
	//838
	//852
	//866
	//880
	//894
	//908
	//922
	static NPC* shoppingcenterleftcars[12] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};


	NPC_create_car_if_within_range_else_delete(&shoppingcenterleftcars[0],766*8,281*8,UP);
	//NPC_create_car_if_within_range_else_delete(&shoppingcenterleftcars[1],780*8,280*8,UP);
	NPC_create_car_if_within_range_else_delete(&shoppingcenterleftcars[2],794*8,279*8,UP);
	//NPC_create_car_if_within_range_else_delete(&shoppingcenterleftcars[3],808*8,279*8,DOWN);
	NPC_create_car_if_within_range_else_delete(&shoppingcenterleftcars[4],822*8,280*8,UP);
	NPC_create_car_if_within_range_else_delete(&shoppingcenterleftcars[5],836*8,280*8,UP);
	//NPC_create_car_if_within_range_else_delete(&shoppingcenterleftcars[6],850*8,281*8,UP);
	NPC_create_car_if_within_range_else_delete(&shoppingcenterleftcars[7],864*8,280*8,DOWN);
	//NPC_create_car_if_within_range_else_delete(&shoppingcenterleftcars[8],878*8,281*8,UP);
	NPC_create_car_if_within_range_else_delete(&shoppingcenterleftcars[9],893*8,280*8,UP);
	//NPC_create_car_if_within_range_else_delete(&shoppingcenterleftcars[10],906*8,280*8,DOWN);
	//NPC_create_car_if_within_range_else_delete(&shoppingcenterleftcars[11],920*8,280*8,DOWN);
	//===================================================================================================
// DEPARTMENT AND GROCERY STORE PARKING LOT
//===================================================================================================
	//955 257
	//955.271
	//955.284
	//975.284
	//975.271
	//975.257
	//1004.257
	//1004.271
	//1004.284
	//1024.284
	//1024.270
	//1024.257
	//1053.257
	//1053.271
	//1053.284
	//1074.284
	//1074.271
	//1074.257
	//1102.257
	//1102.271
	//1102.284
	//1122.284
	//1122.271
	//1122.257

static NPC* departmentstoreparkinglotcars[24]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};


	NPC_create_car_if_within_range_else_delete(&departmentstoreparkinglotcars[0],955*8,257*8,LEFT);
	NPC_create_car_if_within_range_else_delete(&departmentstoreparkinglotcars[1],955*8,271*8,LEFT);
	//NPC_create_car_if_within_range_else_delete(&departmentstoreparkinglotcars[2],955*8,284*8,RIGHT);
	NPC_create_car_if_within_range_else_delete(&departmentstoreparkinglotcars[3],975*8,284*8,LEFT);
	//NPC_create_car_if_within_range_else_delete(&departmentstoreparkinglotcars[4],975*8,271*8,RIGHT);
	NPC_create_car_if_within_range_else_delete(&departmentstoreparkinglotcars[5],975*8,257*8,RIGHT);
	//NPC_create_car_if_within_range_else_delete(&departmentstoreparkinglotcars[6],1004*8,257*8,LEFT);
	NPC_create_car_if_within_range_else_delete(&departmentstoreparkinglotcars[7],1004*8,271*8,LEFT);
	//NPC_create_car_if_within_range_else_delete(&departmentstoreparkinglotcars[8],1004*8,284*8,RIGHT);
	NPC_create_car_if_within_range_else_delete(&departmentstoreparkinglotcars[9],1024*8,284*8,LEFT);
	NPC_create_car_if_within_range_else_delete(&departmentstoreparkinglotcars[10],1024*8,270*8,RIGHT);
	//NPC_create_car_if_within_range_else_delete(&departmentstoreparkinglotcars[11],1024*8,257*8,LEFT);
	NPC_create_car_if_within_range_else_delete(&departmentstoreparkinglotcars[12],1053*8,257*8,LEFT);
	NPC_create_car_if_within_range_else_delete(&departmentstoreparkinglotcars[13],1053*8,271*8,RIGHT);
	//NPC_create_car_if_within_range_else_delete(&departmentstoreparkinglotcars[14],1053*8,284*8,RIGHT);
	NPC_create_car_if_within_range_else_delete(&departmentstoreparkinglotcars[15],1074*8,284*8,LEFT);
	NPC_create_car_if_within_range_else_delete(&departmentstoreparkinglotcars[16],1074*8,271*8,LEFT);
	//NPC_create_car_if_within_range_else_delete(&departmentstoreparkinglotcars[17],1074*8,257*8,RIGHT);
	NPC_create_car_if_within_range_else_delete(&departmentstoreparkinglotcars[18],1102*8,257*8,LEFT);
	NPC_create_car_if_within_range_else_delete(&departmentstoreparkinglotcars[19],1102*8,271*8,LEFT);
	//NPC_create_car_if_within_range_else_delete(&departmentstoreparkinglotcars[20],1102*8,284*8,RIGHT);
	NPC_create_car_if_within_range_else_delete(&departmentstoreparkinglotcars[21],1122*8,284*8,LEFT);
	NPC_create_car_if_within_range_else_delete(&departmentstoreparkinglotcars[22],1122*8,271*8,RIGHT);
	//NPC_create_car_if_within_range_else_delete(&departmentstoreparkinglotcars[23],1122*8,257*8,LEFT);
//===================================================================================================
// DEPARTMENT STORE RANDOM GUYS GOING IN AND OUT
//===================================================================================================
	static NPC* deptstore_npcs[15]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	//971,230
	//982
	//993
	//1004
	if(MAP_is_xy_within_screen_by_amt(990*8,230*8,64))
	{

		static int last_vbl_30=0;

		for(c=0;c<15;c++)
		if(deptstore_npcs[c]==NULL&&last_vbl_30!=vbl_30_var)
		{
			last_vbl_30=vbl_30_var;
			int cycle=r(7);

			if(cycle==0)NPC_create_random_ADULT_xy_feet(&deptstore_npcs[c],(975)*8,230*8);
			if(cycle==1)NPC_create_random_ADULT_xy_feet(&deptstore_npcs[c],(986)*8,230*8);
			if(cycle==2)NPC_create_random_ADULT_xy_feet(&deptstore_npcs[c],(997)*8,230*8);
			if(cycle==3)NPC_create_random_ADULT_xy_feet(&deptstore_npcs[c],(1008)*8,230*8);

			if(cycle==4)NPC_create_random_ADULT_xy_feet(&deptstore_npcs[c],982*8,260*8);
			if(cycle==5)NPC_create_random_ADULT_xy_feet(&deptstore_npcs[c],1008*8,274*8);
			if(cycle==6)NPC_create_random_ADULT_xy_feet(&deptstore_npcs[c],995*8,MAP_cam_y+GAME_VIEWPORT_HEIGHT_PIXELS+32);

			deptstore_npcs[c]->walking_speed = SPEED_NORMAL+r(SPEED_SLOWEST-SPEED_FASTEST);

			if(cycle<4)deptstore_npcs[c]->AI=0;
			if(cycle>=4)deptstore_npcs[c]->AI=4;

			deptstore_npcs[c]->alpha=0;
		}
	}
	for(c=0;c<15;c++)
	if(deptstore_npcs[c]!=NULL)
	{

		if(deptstore_npcs[c]->AI<9&&deptstore_npcs[c]->alpha<255)NPC_set_alpha(&deptstore_npcs[c],deptstore_npcs[c]->alpha+1);

		if(deptstore_npcs[c]->AI==0){if((MAP_is_xy_within_screen_by_amt(deptstore_npcs[c]->MAP_x,deptstore_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&deptstore_npcs[c], deptstore_npcs[c]->walking_speed, -1, 245*8)){deptstore_npcs[c]->AI=1+r(3);}}
		//out
		else if(deptstore_npcs[c]->AI==1){if((MAP_is_xy_within_screen_by_amt(deptstore_npcs[c]->MAP_x,deptstore_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&deptstore_npcs[c], deptstore_npcs[c]->walking_speed, 960*8, 260*8)){deptstore_npcs[c]->AI=9;}}
		else if(deptstore_npcs[c]->AI==2){if((MAP_is_xy_within_screen_by_amt(deptstore_npcs[c]->MAP_x,deptstore_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&deptstore_npcs[c], deptstore_npcs[c]->walking_speed, 982*8, 260*8)){deptstore_npcs[c]->AI=9;}}
		else if(deptstore_npcs[c]->AI==3){if((MAP_is_xy_within_screen_by_amt(deptstore_npcs[c]->MAP_x,deptstore_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&deptstore_npcs[c], deptstore_npcs[c]->walking_speed, 1008*8, 274*8)){deptstore_npcs[c]->AI=9;}}

		//in
		else if(deptstore_npcs[c]->AI==4){if((MAP_is_xy_within_screen_by_amt(deptstore_npcs[c]->MAP_x,deptstore_npcs[c]->MAP_y,GAME_VIEWPORT_WIDTH_PIXELS/2)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&deptstore_npcs[c], deptstore_npcs[c]->walking_speed, -1, 255*8)){deptstore_npcs[c]->AI=5+r(4);}}


		else if(deptstore_npcs[c]->AI==5){if((MAP_is_xy_within_screen_by_amt(deptstore_npcs[c]->MAP_x,deptstore_npcs[c]->MAP_y,GAME_VIEWPORT_WIDTH_PIXELS/2)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&deptstore_npcs[c], deptstore_npcs[c]->walking_speed, 973*8, 230*8)){deptstore_npcs[c]->AI=9;}}
		else if(deptstore_npcs[c]->AI==6){if((MAP_is_xy_within_screen_by_amt(deptstore_npcs[c]->MAP_x,deptstore_npcs[c]->MAP_y,GAME_VIEWPORT_WIDTH_PIXELS/2)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&deptstore_npcs[c], deptstore_npcs[c]->walking_speed, 984*8, 230*8)){deptstore_npcs[c]->AI=9;}}
		else if(deptstore_npcs[c]->AI==7){if((MAP_is_xy_within_screen_by_amt(deptstore_npcs[c]->MAP_x,deptstore_npcs[c]->MAP_y,GAME_VIEWPORT_WIDTH_PIXELS/2)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&deptstore_npcs[c], deptstore_npcs[c]->walking_speed, 995*8, 230*8)){deptstore_npcs[c]->AI=9;}}
		else if(deptstore_npcs[c]->AI==8){if((MAP_is_xy_within_screen_by_amt(deptstore_npcs[c]->MAP_x,deptstore_npcs[c]->MAP_y,GAME_VIEWPORT_WIDTH_PIXELS/2)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&deptstore_npcs[c], deptstore_npcs[c]->walking_speed, 1006*8, 230*8)){deptstore_npcs[c]->AI=9;}}

		else if(deptstore_npcs[c]->AI==9){NPC_fade_out_and_delete(&deptstore_npcs[c]);}

	}




//TODO: cars driving slowly around parking lots
//TODO: shopping carts in front of certain stores, people pushing shopping carts, shopping cart lanes


//===================================================================================================
// GROCERY STORE RANDOM GUYS GOING IN AND OUT
//===================================================================================================

	static NPC* grocerystoreexiting_npcs[15]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};

	//groc exit
	//1056.230
	if(MAP_is_xy_within_screen_by_amt(1056*8,230*8,64))
	{

		static int lastex_sec=0;

		for(c=0;c<15;c++)
		if(grocerystoreexiting_npcs[c]==NULL&&lastex_sec!=vbl_30_var)
		{
			lastex_sec=vbl_30_var;
			int cycle=r(4);
			if(cycle==0)NPC_create_random_ADULT_xy_feet(&grocerystoreexiting_npcs[c],(1059+r(3))*8,230*8);
			if(cycle==1)NPC_create_random_ADULT_xy_feet(&grocerystoreexiting_npcs[c],(1059+r(3))*8,230*8);
			if(cycle==2)NPC_create_random_ADULT_xy_feet(&grocerystoreexiting_npcs[c],(1059+r(3))*8,230*8);
			if(cycle==3)NPC_create_random_ADULT_xy_feet(&grocerystoreexiting_npcs[c],(1059+r(3))*8,230*8);
			grocerystoreexiting_npcs[c]->walking_speed = SPEED_NORMAL+r(SPEED_SLOWEST-SPEED_FASTEST);
			grocerystoreexiting_npcs[c]->AI=0;
			grocerystoreexiting_npcs[c]->alpha=0;
		}

	}


	for(c=0;c<15;c++)
	if(grocerystoreexiting_npcs[c]!=NULL)
	{
		if(grocerystoreexiting_npcs[c]->AI<7&&grocerystoreexiting_npcs[c]->alpha<255)NPC_set_alpha(&grocerystoreexiting_npcs[c],grocerystoreexiting_npcs[c]->alpha+1);
		if(grocerystoreexiting_npcs[c]->AI==0){if((MAP_is_xy_within_screen_by_amt(grocerystoreexiting_npcs[c]->MAP_x,grocerystoreexiting_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&grocerystoreexiting_npcs[c], grocerystoreexiting_npcs[c]->walking_speed, -1, 245*8)){grocerystoreexiting_npcs[c]->AI=1+r(4);}}
		else if(grocerystoreexiting_npcs[c]->AI==1){if((MAP_is_xy_within_screen_by_amt(grocerystoreexiting_npcs[c]->MAP_x,grocerystoreexiting_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&grocerystoreexiting_npcs[c], grocerystoreexiting_npcs[c]->walking_speed, 1060*8, 260*8)){grocerystoreexiting_npcs[c]->AI=7;}}
		else if(grocerystoreexiting_npcs[c]->AI==2){if((MAP_is_xy_within_screen_by_amt(grocerystoreexiting_npcs[c]->MAP_x,grocerystoreexiting_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&grocerystoreexiting_npcs[c], grocerystoreexiting_npcs[c]->walking_speed, 1030*8, 273*8)){grocerystoreexiting_npcs[c]->AI=7;}}
		else if(grocerystoreexiting_npcs[c]->AI==3){if((MAP_is_xy_within_screen_by_amt(grocerystoreexiting_npcs[c]->MAP_x,grocerystoreexiting_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&grocerystoreexiting_npcs[c], grocerystoreexiting_npcs[c]->walking_speed, 1080*8, 255*8)){grocerystoreexiting_npcs[c]->AI=5;}}
		else if(grocerystoreexiting_npcs[c]->AI==4){if((MAP_is_xy_within_screen_by_amt(grocerystoreexiting_npcs[c]->MAP_x,grocerystoreexiting_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&grocerystoreexiting_npcs[c], grocerystoreexiting_npcs[c]->walking_speed, 1045*8, 255*8)){grocerystoreexiting_npcs[c]->AI=6;}}

		else if(grocerystoreexiting_npcs[c]->AI==5){if((MAP_is_xy_within_screen_by_amt(grocerystoreexiting_npcs[c]->MAP_x,grocerystoreexiting_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&grocerystoreexiting_npcs[c], grocerystoreexiting_npcs[c]->walking_speed, 1080*8, 273*8)){grocerystoreexiting_npcs[c]->AI=7;}}
		else if(grocerystoreexiting_npcs[c]->AI==6){if((MAP_is_xy_within_screen_by_amt(grocerystoreexiting_npcs[c]->MAP_x,grocerystoreexiting_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&grocerystoreexiting_npcs[c], grocerystoreexiting_npcs[c]->walking_speed, 1058*8, 273*8)){grocerystoreexiting_npcs[c]->AI=7;}}
		else if(grocerystoreexiting_npcs[c]->AI==7){NPC_fade_out_and_delete(&grocerystoreexiting_npcs[c]);}
	}






	static NPC* grocerystoreentering_npcs[15]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};


	//ent 1118.230
	if(MAP_is_xy_within_screen_by_amt(1118*8,230*8,64))
	{

		static int lastent_sec=0;

		for(c=0;c<15;c++)
		if(grocerystoreentering_npcs[c]==NULL&&lastent_sec!=vbl_30_var)
		{
			lastent_sec=vbl_30_var;
			int cycle=(r(4));
			if(cycle==0)NPC_create_random_ADULT_xy_feet(&grocerystoreentering_npcs[c],1095*8,MAP_cam_y+GAME_VIEWPORT_HEIGHT_PIXELS+32);
			if(cycle==1)NPC_create_random_ADULT_xy_feet(&grocerystoreentering_npcs[c],1140*8,MAP_cam_y+GAME_VIEWPORT_HEIGHT_PIXELS+32);

			if(cycle==2)NPC_create_random_ADULT_xy_feet(&grocerystoreentering_npcs[c],1107*8,260*8);
			if(cycle==3)NPC_create_random_ADULT_xy_feet(&grocerystoreentering_npcs[c],1130*8,273*8);
			grocerystoreentering_npcs[c]->walking_speed = SPEED_NORMAL+r(SPEED_SLOWEST-SPEED_FASTEST);
			grocerystoreentering_npcs[c]->AI=r(3);
			grocerystoreentering_npcs[c]->alpha=0;

		}

	}


	for(c=0;c<15;c++)
	if(grocerystoreentering_npcs[c]!=NULL)
	{

		if(grocerystoreentering_npcs[c]->AI<7&&grocerystoreentering_npcs[c]->alpha<255)NPC_set_alpha(&grocerystoreentering_npcs[c],grocerystoreentering_npcs[c]->alpha+1);
		if(grocerystoreentering_npcs[c]->AI==0){if((MAP_is_xy_within_screen_by_amt(grocerystoreentering_npcs[c]->MAP_x,grocerystoreentering_npcs[c]->MAP_y,GAME_VIEWPORT_WIDTH_PIXELS/2)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&grocerystoreentering_npcs[c], grocerystoreentering_npcs[c]->walking_speed, -1, 255*8)){grocerystoreentering_npcs[c]->AI=3+r(3);}}
		if(grocerystoreentering_npcs[c]->AI==1){if((MAP_is_xy_within_screen_by_amt(grocerystoreentering_npcs[c]->MAP_x,grocerystoreentering_npcs[c]->MAP_y,GAME_VIEWPORT_WIDTH_PIXELS/2)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&grocerystoreentering_npcs[c], grocerystoreentering_npcs[c]->walking_speed, -1, 250*8)){grocerystoreentering_npcs[c]->AI=3+r(3);}}
		if(grocerystoreentering_npcs[c]->AI==2){if((MAP_is_xy_within_screen_by_amt(grocerystoreentering_npcs[c]->MAP_x,grocerystoreentering_npcs[c]->MAP_y,GAME_VIEWPORT_WIDTH_PIXELS/2)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&grocerystoreentering_npcs[c], grocerystoreentering_npcs[c]->walking_speed, -1, 253*8)){grocerystoreentering_npcs[c]->AI=3+r(3);}}
		if(grocerystoreentering_npcs[c]->AI==3){if((MAP_is_xy_within_screen_by_amt(grocerystoreentering_npcs[c]->MAP_x,grocerystoreentering_npcs[c]->MAP_y,GAME_VIEWPORT_WIDTH_PIXELS/2)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&grocerystoreentering_npcs[c], grocerystoreentering_npcs[c]->walking_speed, 1120*8, -1)){grocerystoreentering_npcs[c]->AI=6;}}
		if(grocerystoreentering_npcs[c]->AI==4){if((MAP_is_xy_within_screen_by_amt(grocerystoreentering_npcs[c]->MAP_x,grocerystoreentering_npcs[c]->MAP_y,GAME_VIEWPORT_WIDTH_PIXELS/2)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&grocerystoreentering_npcs[c], grocerystoreentering_npcs[c]->walking_speed, 1123*8, -1)){grocerystoreentering_npcs[c]->AI=6;}}
		if(grocerystoreentering_npcs[c]->AI==5){if((MAP_is_xy_within_screen_by_amt(grocerystoreentering_npcs[c]->MAP_x,grocerystoreentering_npcs[c]->MAP_y,GAME_VIEWPORT_WIDTH_PIXELS/2)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&grocerystoreentering_npcs[c], grocerystoreentering_npcs[c]->walking_speed, 1125*8, -1)){grocerystoreentering_npcs[c]->AI=6;}}
		else if(grocerystoreentering_npcs[c]->AI==6){if((MAP_is_xy_within_screen_by_amt(grocerystoreentering_npcs[c]->MAP_x,grocerystoreentering_npcs[c]->MAP_y,GAME_VIEWPORT_WIDTH_PIXELS/2)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&grocerystoreentering_npcs[c], grocerystoreentering_npcs[c]->walking_speed, 1122*8, 230*8)){grocerystoreentering_npcs[c]->AI=7;}}
		else if(grocerystoreentering_npcs[c]->AI==7){NPC_fade_out_and_delete(&grocerystoreentering_npcs[c]);}

	}




//===================================================================================================
// SHOPPING CENTER RIGHT PARKING LOT
//===================================================================================================
	//1162.282
	//1176.282
	//1190.282
	//1204.282
	//1218.282
	//1232.282
	//1246.282
	//1260.282
	//1274.282
	//1288.282
	//1302.282
	//1316.282
	//1330.282
	//1344.282
	//1358.282
	//1372.282
	//1386.282
	static NPC* rightshoppingcenterparkinglotcars[17]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	NPC_create_car_if_within_range_else_delete(&rightshoppingcenterparkinglotcars[0],1161*8,280*8,UP);
	NPC_create_car_if_within_range_else_delete(&rightshoppingcenterparkinglotcars[1],1176*8,281*8,UP);
	//NPC_create_car_if_within_range_else_delete(&rightshoppingcenterparkinglotcars[2],1190*8,282*8,DOWN);
	NPC_create_car_if_within_range_else_delete(&rightshoppingcenterparkinglotcars[3],1203*8,280*8,DOWN);
	NPC_create_car_if_within_range_else_delete(&rightshoppingcenterparkinglotcars[4],1217*8,280*8,UP);
	NPC_create_car_if_within_range_else_delete(&rightshoppingcenterparkinglotcars[5],1232*8,281*8,DOWN);
	//NPC_create_car_if_within_range_else_delete(&rightshoppingcenterparkinglotcars[6],1246*8,282*8,UP);
	NPC_create_car_if_within_range_else_delete(&rightshoppingcenterparkinglotcars[7],1260*8,280*8,UP);
	//NPC_create_car_if_within_range_else_delete(&rightshoppingcenterparkinglotcars[8],1274*8,282*8,DOWN);
	NPC_create_car_if_within_range_else_delete(&rightshoppingcenterparkinglotcars[9],1287*8,280*8,DOWN);
	NPC_create_car_if_within_range_else_delete(&rightshoppingcenterparkinglotcars[10],1301*8,281*8,UP);
	//NPC_create_car_if_within_range_else_delete(&rightshoppingcenterparkinglotcars[11],1316*8,282*8,DOWN);
	NPC_create_car_if_within_range_else_delete(&rightshoppingcenterparkinglotcars[12],1330*8,280*8,UP);
	NPC_create_car_if_within_range_else_delete(&rightshoppingcenterparkinglotcars[13],1343*8,280*8,UP);
	//NPC_create_car_if_within_range_else_delete(&rightshoppingcenterparkinglotcars[14],1358*8,282*8,DOWN);
	NPC_create_car_if_within_range_else_delete(&rightshoppingcenterparkinglotcars[15],1372*8,281*8,DOWN);
	//NPC_create_car_if_within_range_else_delete(&rightshoppingcenterparkinglotcars[16],1386*8,282*8,UP);
//===================================================================================================
// MOVIE THEATRE PARKING LOT
//===================================================================================================
//1424.259
//274
//287
//1444.259
//274
//287
//1474.259
//274
//287
//1494.259
//274
//287
//1523.259
//274
//287
	static NPC* movietheatreparkinglotcars[15]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	NPC_create_car_if_within_range_else_delete(&movietheatreparkinglotcars[ 0],1424*8,259*8,LEFT);
	NPC_create_car_if_within_range_else_delete(&movietheatreparkinglotcars[ 1],1424*8,274*8,RIGHT);
	NPC_create_car_if_within_range_else_delete(&movietheatreparkinglotcars[ 2],1424*8,287*8,LEFT);
	//NPC_create_car_if_within_range_else_delete(&movietheatreparkinglotcars[ 3],1444*8,259*8,RIGHT);
	NPC_create_car_if_within_range_else_delete(&movietheatreparkinglotcars[ 4],1444*8,274*8,LEFT);
	NPC_create_car_if_within_range_else_delete(&movietheatreparkinglotcars[ 5],1444*8,287*8,RIGHT);
	//NPC_create_car_if_within_range_else_delete(&movietheatreparkinglotcars[ 6],1474*8,259*8,RIGHT);
	NPC_create_car_if_within_range_else_delete(&movietheatreparkinglotcars[ 7],1473*8,274*8,LEFT);
	NPC_create_car_if_within_range_else_delete(&movietheatreparkinglotcars[ 8],1473*8,287*8,RIGHT);
	NPC_create_car_if_within_range_else_delete(&movietheatreparkinglotcars[ 9],1493*8,259*8,RIGHT);
	//NPC_create_car_if_within_range_else_delete(&movietheatreparkinglotcars[10],1494*8,274*8,LEFT);
	NPC_create_car_if_within_range_else_delete(&movietheatreparkinglotcars[11],1494*8,287*8,RIGHT);
	//NPC_create_car_if_within_range_else_delete(&movietheatreparkinglotcars[12],1523*8,259*8,LEFT);
	NPC_create_car_if_within_range_else_delete(&movietheatreparkinglotcars[13],1522*8,274*8,RIGHT);
	NPC_create_car_if_within_range_else_delete(&movietheatreparkinglotcars[14],1522*8,287*8,LEFT);
//===================================================================================================
// MOVIE THEATRE PEOPLE
//===================================================================================================
//1462.230
//1470
//1478
	static NPC* movietheatre_npcs[20]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};

	if(MAP_is_xy_within_screen_by_amt(1470*8,230*8,GAME_VIEWPORT_WIDTH_PIXELS/4))
	{

		static int last_sec=0;

		for(c=0;c<20;c++)
		if(movietheatre_npcs[c]==NULL&&last_sec!=vbl_30_var)
		{

			last_sec=vbl_30_var;
			int cycle=r(6);
			if(cycle==0)NPC_create_random_ADULT_OR_CHILD_xy_feet(&movietheatre_npcs[c],(1463+r(3))*8,230*8);
			if(cycle==1)NPC_create_random_ADULT_OR_CHILD_xy_feet(&movietheatre_npcs[c],(1471+r(3))*8,230*8);
			if(cycle==2)NPC_create_random_ADULT_OR_CHILD_xy_feet(&movietheatre_npcs[c],(1479+r(3))*8,230*8);
			if(cycle==3)NPC_create_random_ADULT_OR_CHILD_xy_feet(&movietheatre_npcs[c],1463*8,MAP_cam_y+GAME_VIEWPORT_HEIGHT_PIXELS+40);
			if(cycle==4)NPC_create_random_ADULT_OR_CHILD_xy_feet(&movietheatre_npcs[c],1456*8,MAP_cam_y+GAME_VIEWPORT_HEIGHT_PIXELS+40);
			if(cycle==5)NPC_create_random_ADULT_OR_CHILD_xy_feet(&movietheatre_npcs[c],1470*8,MAP_cam_y+GAME_VIEWPORT_HEIGHT_PIXELS+40);
			movietheatre_npcs[c]->walking_speed = SPEED_NORMAL+r(SPEED_SLOWEST-SPEED_FASTEST);
			//movietheatre_npcs[c]->cycle=cycle;
			if(cycle<3)movietheatre_npcs[c]->AI=0;
			if(cycle>=3)movietheatre_npcs[c]->AI=5+r(3);
			movietheatre_npcs[c]->alpha=0;

		}

	}


	for(c=0;c<20;c++)
	if(movietheatre_npcs[c]!=NULL)
	{

		if(movietheatre_npcs[c]->AI<8&&movietheatre_npcs[c]->alpha<255)NPC_set_alpha(&movietheatre_npcs[c],movietheatre_npcs[c]->alpha+1);
		//out
		else if(movietheatre_npcs[c]->AI==0){if((MAP_is_xy_within_screen_by_amt(movietheatre_npcs[c]->MAP_x,movietheatre_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&movietheatre_npcs[c], movietheatre_npcs[c]->walking_speed, -1, 249*8)){movietheatre_npcs[c]->AI=1+r(4);}}
		else if(movietheatre_npcs[c]->AI==1){if((MAP_is_xy_within_screen_by_amt(movietheatre_npcs[c]->MAP_x,movietheatre_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&movietheatre_npcs[c], movietheatre_npcs[c]->walking_speed, 1450*8, 277*8)){movietheatre_npcs[c]->AI=8;}}
		else if(movietheatre_npcs[c]->AI==2){if((MAP_is_xy_within_screen_by_amt(movietheatre_npcs[c]->MAP_x,movietheatre_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&movietheatre_npcs[c], movietheatre_npcs[c]->walking_speed, 1478*8, 277*8)){movietheatre_npcs[c]->AI=8;}}
		else if(movietheatre_npcs[c]->AI==3){if((MAP_is_xy_within_screen_by_amt(movietheatre_npcs[c]->MAP_x,movietheatre_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&movietheatre_npcs[c], movietheatre_npcs[c]->walking_speed, 1429*8, 260*8)){movietheatre_npcs[c]->AI=8;}}
		else if(movietheatre_npcs[c]->AI==4){if((MAP_is_xy_within_screen_by_amt(movietheatre_npcs[c]->MAP_x,movietheatre_npcs[c]->MAP_y,64)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&movietheatre_npcs[c], movietheatre_npcs[c]->walking_speed, 1499*8, 260*8)){movietheatre_npcs[c]->AI=8;}}
		//in
		else if(movietheatre_npcs[c]->AI==5){if((MAP_is_xy_within_screen_by_amt(movietheatre_npcs[c]->MAP_x,movietheatre_npcs[c]->MAP_y,GAME_VIEWPORT_WIDTH_PIXELS/2)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&movietheatre_npcs[c], movietheatre_npcs[c]->walking_speed, 1465*8, 230*8)){movietheatre_npcs[c]->AI=8;}}
		else if(movietheatre_npcs[c]->AI==6){if((MAP_is_xy_within_screen_by_amt(movietheatre_npcs[c]->MAP_x,movietheatre_npcs[c]->MAP_y,GAME_VIEWPORT_WIDTH_PIXELS/2)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&movietheatre_npcs[c], movietheatre_npcs[c]->walking_speed, 1473*8, 230*8)){movietheatre_npcs[c]->AI=8;}}
		else if(movietheatre_npcs[c]->AI==7){if((MAP_is_xy_within_screen_by_amt(movietheatre_npcs[c]->MAP_x,movietheatre_npcs[c]->MAP_y,GAME_VIEWPORT_WIDTH_PIXELS/2)==0)||NPC_walk_to_xy_nohit_avoidothers_pushmain(&movietheatre_npcs[c], movietheatre_npcs[c]->walking_speed, 1481*8, 230*8)){movietheatre_npcs[c]->AI=8;}}
		else if(movietheatre_npcs[c]->AI==8){NPC_fade_out_and_delete(&movietheatre_npcs[c]);}

	}

//===================================================================================================
// RANDOM CROWD ALL HAS TO BE IN ONE FUNCTION OR THEY DELETE EACH OTHER. //maybe add in global variable "crowd running"
//===================================================================================================
	//shopping center left sidewalk range x y 758,264		937,274
	//shopping center right crowd in  1150.265   1406.278

	if(CLOCK_hour>10&&CLOCK_hour<12+8)
	{
		if(MAP_is_xyxy_within_screen_by_amt(758*8,264*8,937*8,274*8,64))NPC_random_crowd_left_right_xyxy(758*8,264*8,937*8,274*8,30);//left shopping center
		else
		//if(MAP_is_xyxy_within_screen_by_amt(1490*8,230*8,1500*8,240*8,64))NPC_random_crowd_left_right_xyxy(1400*8,230*8,1540*8,244*8,10);//movie theatre small crowd 1400.230->1540.242
		//else
		NPC_random_crowd_left_right_xyxy(1150*8,264*8,1406*8,278*8,30);//right shopping center

		//TODO: handle this better :)


		//groc/dept small crowd 933.231->1155.244
		//gas station small crowd 699.228->762.237
		//taco burger small crowd 548.295->589.302
	}
	else
	NPC_fade_out_random_crowd();


//TODO: taco burger people created offscreen, go in/come out of 576.293
//TODO: church people come from parking lot 451.300 walk to 498.300 sidewalk go in door 496.293 only people in suits?
//TODO: clinic from parklot 375.307 to 401.307 sidewalk up to door 402.302
//TODO: support different places open at different times. open signs change. color inside window changes.

//support wind, transparent sprite? z order above, maybe very slight variations on color that wave? or a swirl?
//litter/leaves blowing
//grass animation
//support footsteps grass/dirt sound
//support grass footprints
//birds chirping,
//horns honking.
//footsteps for crowds of people.
//support rain, thunder, lightning

//school opens at 7
//most shops open at 10

	if(walking_into_door(640*8,1*8,680*8,2*8))
	{
		MAP_change_map(MAP_bobsgame_CITYCity,1000,50);return;
	}

	if(walking_into_door(RANGE_OUTSIDETownPlaygroundToSCHOOLEntranceHallwayLeft))
	{
		MAP_change_map(MAP_bobsgame_SCHOOLEntranceHallway,10,40);return;
	}
	if(walking_into_door(RANGE_OUTSIDETownPlaygroundToSCHOOLEntranceHallwayRight))
	{
		MAP_change_map(MAP_bobsgame_SCHOOLEntranceHallway,109,40);return;
	}
	if(walking_into_door(RANGE_OUTSIDETownToSCHOOLEntranceHallwayLeft))
	{
		MAP_change_map(MAP_bobsgame_SCHOOLEntranceHallway,145,48);return;
	}
	if(walking_into_door(RANGE_OUTSIDETownToSCHOOLEntranceHallwayMiddle))
	{
		MAP_change_map(MAP_bobsgame_SCHOOLEntranceHallway,153,48);return;
	}
	if(walking_into_door(RANGE_OUTSIDETownToSCHOOLEntranceHallwayRight))
	{
		MAP_change_map(MAP_bobsgame_SCHOOLEntranceHallway,163,48);return;
	}
	if(walking_into_door(RANGE_OUTSIDETownToTOWNDoctorsOfficeEntrance))
	{
		MAP_change_map(MAP_bobsgame_TOWNDoctorsOfficeEntrance,6,28);return;
	}
	if(walking_into_door(RANGE_OUTSIDETownToTOWNChurch))
	{
		MAP_change_map(MAP_bobsgame_TOWNChurch,21,62);return;
	}
	if(walking_into_door(RANGE_OUTSIDETownToTOWNTacoBurger))
	{
		MAP_change_map(MAP_bobsgame_TOWNTacoBurger,28,53);return;
	}
	if(walking_into_door(RANGE_OUTSIDETownToTOWNGasStation))
	{
		MAP_change_map(MAP_bobsgame_TOWNGasStation,15,41);return;
	}
	//if between 7 pm and 6 am, else text window "theres a sign on the door, were only open at night. sorry early birds, night owls only."
	if(walking_into_door(RANGE_OUTSIDETownToTOWNCoffeeShop))
	{
		MAP_change_map(MAP_bobsgame_TOWNCoffeeShop,26,65);return;
	}
		if(walking_into_door(RANGE_OUTSIDETownToTOWNBookstore))
	{
		MAP_change_map(MAP_bobsgame_TOWNBookstore,7,50);return;
	}
	if(walking_into_door(RANGE_OUTSIDETownToTOWNPizzaPlace))
	{
		MAP_change_map(MAP_bobsgame_TOWNPizzaPlace,26,31);return;
	}
	if(walking_into_door(RANGE_OUTSIDETownToTOWNBeautySalon))
	{
		MAP_change_map(MAP_bobsgame_TOWNBeautySalon,31,40);return;
	}
	if(walking_into_door(RANGE_OUTSIDETownToTOWNPets4Less))
	{
		MAP_change_map(MAP_bobsgame_TOWNPets4Less,25,51);return;
	}
	if(walking_into_door(RANGE_OUTSIDETownToTOWNDepartmentStore1))
	{
		MAP_change_map(MAP_bobsgame_TOWNDepartmentStore,40,78);return;
	}
	if(walking_into_door(RANGE_OUTSIDETownToTOWNDepartmentStore2))
	{
		MAP_change_map(MAP_bobsgame_TOWNDepartmentStore,51,78);return;
	}
	if(walking_into_door(RANGE_OUTSIDETownToTOWNDepartmentStore3))
	{
		MAP_change_map(MAP_bobsgame_TOWNDepartmentStore,62,78);return;
	}
	if(walking_into_door(RANGE_OUTSIDETownToTOWNDepartmentStore4))
	{
		MAP_change_map(MAP_bobsgame_TOWNDepartmentStore,73,78);return;
	}
	if(walking_into_door(RANGE_OUTSIDETownToTOWNGroceryStoreLeftExit))
	{
		MAP_change_map(MAP_bobsgame_TOWNGroceryStore,14,88);return;
	}
	if(walking_into_door(RANGE_OUTSIDETownToTOWNGroceryStoreRightEntrance))
	{
		MAP_change_map(MAP_bobsgame_TOWNGroceryStore,76,88);return;
	}
	if(walking_into_door(RANGE_OUTSIDETownToTOWNElectronicsStore))
	{
		MAP_change_map(MAP_bobsgame_TOWNElectronicsStore,7,51);return;
	}
	if(walking_into_door(RANGE_OUTSIDETownToTOWNGameStore))
	{
		MAP_change_map(MAP_bobsgame_TOWNGameStore,23,42);return;
	}
	if(walking_into_door(RANGE_OUTSIDETownToTOWNArcade))
	{
		MAP_change_map(MAP_bobsgame_TOWNArcade,8,31);return;
	}
	if(walking_into_door(RANGE_OUTSIDETownToTOWNRecordStore))
	{
		MAP_change_map(MAP_bobsgame_TOWNRecordStore,11,46);return;
	}
	if(walking_into_door(RANGE_OUTSIDETownToTOWNMovieTheatreLobbyLeft))
	{
		MAP_change_map(MAP_bobsgame_TOWNMovieTheatreLobby,17,33);return;
	}
	if(walking_into_door(RANGE_OUTSIDETownToTOWNMovieTheatreLobbyMiddle))
	{
		MAP_change_map(MAP_bobsgame_TOWNMovieTheatreLobby,25,33);return;
	}
	if(walking_into_door(RANGE_OUTSIDETownToTOWNMovieTheatreLobbyRight))
	{
		MAP_change_map(MAP_bobsgame_TOWNMovieTheatreLobby,33,33);return;
	}
	if(walking_into_door(RANGE_OUTSIDETownToHOUSEFriendsHouseFrontDoor))
	{
		MAP_change_map(MAP_bobsgame_TOWNFRIENDDownstairs,33,41);return;
	}
	if(walking_into_door(RANGE_OUTSIDETownToHOUSEFriendsHouseBackDoor))
	{
		MAP_change_map(MAP_bobsgame_TOWNFRIENDDownstairs,49,9);return;
	}
	if(walking_into_door(RANGE_OUTSIDETownToHOUSECrazyHouseFrontDoor))
	{
		MAP_change_map(MAP_bobsgame_TOWNCRAZYDownstairs,37,36);return;
	}
	if(walking_into_door(RANGE_OUTSIDETownToHOUSECrazyHouseBackDoor))
	{
		MAP_change_map(MAP_bobsgame_TOWNCRAZYDownstairs,24,9);return;
	}
	if(walking_into_door(RANGE_OUTSIDETownToHOUSEYuuHouseFrontDoor))
	{
		MAP_change_map(MAP_bobsgame_TOWNYUUDownstairs,13,41);return;
	}
	if(walking_into_door(RANGE_OUTSIDETownToHOUSEYuuHouseBackDoor))
	{
		MAP_change_map(MAP_bobsgame_TOWNYUUDownstairs,32,9);return;
	}
	if(walking_into_door(RANGE_OUTSIDETownToClubHouse))
	{
		MAP_change_map(MAP_bobsgame_TOWNClubHouse,12,21);return;
	}
	if(walking_into_door(RANGE_OUTSIDETownToToolShed))
	{
		MAP_change_map(MAP_bobsgame_TOWNYUUBackyardToolShed,6,17);return;
	}
	if(walking_into_door(RANGE_OUTSIDETownToTOWNVideoRent))
	{
		MAP_change_map(MAP_bobsgame_TOWNVideoRent,11,36);return;
	}



	if(ACTION_range_xy_xy(55*8,577*8,58*8,578*8,"Read Sign"))
	{
	//Read Sign
		TEXT_set_sprite_window(0,PLAYER_npc,NULL);
		TEXT_set_sprite_window(1,littlebro_npc,NULL);
		TEXT_window("The sign reads \"Somewhat Disoriented Forest.\"");
	}

}
void bobsgame_TOWNTown_Map_Stop_Function()
{
 NPC_delete_all_npcs();
 car_init=0;
}
void bobsgame_TOWNTown_Map_VBL_Function()
{

}

void bobsgame_TOWNTown_Map_HBL_Function()
{

}






