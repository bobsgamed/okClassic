//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================

#include "../../main.h"


#define RANGE_OUTSIDECityToINSIDEHourlyMotel 107*8,38*8,111*8,39*8
#define RANGE_OUTSIDECityToINSIDEPawnShop 132*8,38*8,140*8,39*8
#define RANGE_OUTSIDECityToINSIDECasino1 187*8,38*8,193*8,39*8
#define RANGE_OUTSIDECityToINSIDECasino2 195*8,38*8,201*8,39*8
#define RANGE_OUTSIDECityToINSIDECasino3 203*8,38*8,209*8,39*8
#define RANGE_OUTSIDECityToINSIDECasino4 211*8,38*8,217*8,39*8
#define RANGE_OUTSIDECityToINSIDETheCafe 260*8,38*8,268*8,39*8
#define RANGE_OUTSIDECityToINSIDEGroovyClub 322*8,36*8,328*8,37*8
#define RANGE_OUTSIDECityToINSIDEPoolHall 390*8,38*8,398*8,39*8
#define RANGE_OUTSIDECityToINSIDELaundromat 438*8,38*8,446*8,39*8
#define RANGE_OUTSIDECityToINSIDEApartmentMainOffice 495*8,38*8,503*8,39*8
#define RANGE_OUTSIDECityToINSIDEBobsApt 525*8,14*8,529*8,15*8
#define RANGE_OUTSIDECityToINSIDENeighborApt 500*8,14*8,504*8,15*8
#define RANGE_OUTSIDECityToINSIDEDeli 556*8,38*8,564*8,39*8
#define RANGE_OUTSIDECityToINSIDEPartyStore 601*8,38*8,609*8,39*8
#define RANGE_OUTSIDECityToINSIDEOffice 706*8,38*8,714*8,39*8
#define RANGE_OUTSIDECityToINSIDEStadium1 754*8,38*8,762*8,39*8
#define RANGE_OUTSIDECityToINSIDEStadium2 765*8,38*8,773*8,39*8
#define RANGE_OUTSIDECityToINSIDEStadium3 776*8,38*8,784*8,39*8
#define RANGE_OUTSIDECityToINSIDEStadium4 787*8,38*8,795*8,39*8
#define RANGE_OUTSIDECityToINSIDEStadium5 825*8,38*8,833*8,39*8
#define RANGE_OUTSIDECityToINSIDEStadium6 836*8,38*8,844*8,39*8
#define RANGE_OUTSIDECityToINSIDEStadium7 847*8,38*8,855*8,39*8
#define RANGE_OUTSIDECityToINSIDEStadium8 858*8,38*8,866*8,39*8
#define RANGE_OUTSIDECityToINSIDEStadium9 897*8,38*8,905*8,39*8
#define RANGE_OUTSIDECityToINSIDEStadium10 908*8,38*8,916*8,39*8
#define RANGE_OUTSIDECityToINSIDEStadium11 919*8,38*8,927*8,39*8
#define RANGE_OUTSIDECityToINSIDEStadium12 930*8,38*8,938*8,39*8
#define RANGE_OUTSIDECityToINSIDEHotel1 1019*8,38*8,1025*8,39*8
#define RANGE_OUTSIDECityToINSIDEHotel2 1027*8,38*8,1033*8,39*8
#define RANGE_OUTSIDECityToINSIDECityHall1 1072*8,38*8,1078*8,39*8
#define RANGE_OUTSIDECityToINSIDECityHall2 1080*8,38*8,1086*8,39*8
#define RANGE_OUTSIDECityToINSIDEMuseum1 1180*8,37*8,1186*8,38*8
#define RANGE_OUTSIDECityToINSIDEMuseum2 1188*8,37*8,1194*8,38*8
#define RANGE_OUTSIDECityToINSIDEHospital1 1252*8,38*8,1260*8,39*8
#define RANGE_OUTSIDECityToINSIDEHospital2 1262*8,38*8,1270*8,39*8
#define RANGE_OUTSIDECityToINSIDEHospital3 1272*8,38*8,1280*8,39*8
#define RANGE_OUTSIDECityToINSIDEPoliceStation 1339*8,38*8,1347*8,39*8
#define RANGE_OUTSIDECityToINSIDEFireDepartment 1391*8,38*8,1399*8,39*8
#define RANGE_OUTSIDECityToINSIDEBank 1442*8,32*8,1450*8,33*8
#define RANGE_OUTSIDECityToINSIDEFancyRestaurant 1502*8,37*8,1506*8,38*8
#define RANGE_OUTSIDECityToINSIDEFashion 1547*8,37*8,1567*8,38*8
#define RANGE_OUTSIDECityToINSIDEElevatedLifeplaceElevator 1591*8,37*8,1595*8,38*8
#define RANGE_OUTSIDECityToINSIDEElevatedLifeplaceMainOffice 1625*8,38*8,1633*8,39*8

//========================================================
//City
//========================================================
void bobsgame_CITYCity_Map_Load_Function()
{
//RANGE_OUTSIDECityToINSIDEHourlyMotel 107*8,38*8,111*8,39*8
//RANGE_OUTSIDECityToINSIDEPawnShop 132*8,38*8,140*8,39*8
//RANGE_OUTSIDECityToINSIDECasino1 187*8,38*8,193*8,39*8
//RANGE_OUTSIDECityToINSIDECasino2 195*8,38*8,201*8,39*8
//RANGE_OUTSIDECityToINSIDECasino3 203*8,38*8,209*8,39*8
//RANGE_OUTSIDECityToINSIDECasino4 211*8,38*8,217*8,39*8
//RANGE_OUTSIDECityToINSIDETheCafe 260*8,38*8,268*8,39*8
//RANGE_OUTSIDECityToINSIDEGroovyClub 322*8,36*8,328*8,37*8
//RANGE_OUTSIDECityToINSIDEPoolHall 390*8,38*8,398*8,39*8
//RANGE_OUTSIDECityToINSIDELaundromat 438*8,38*8,446*8,39*8
//RANGE_OUTSIDECityToINSIDEApartmentMainOffice 495*8,38*8,503*8,39*8
//RANGE_OUTSIDECityToINSIDEBobsApt 525*8,14*8,529*8,15*8
//RANGE_OUTSIDECityToINSIDENeighborApt 500*8,14*8,504*8,15*8
//RANGE_OUTSIDECityToINSIDEDeli 556*8,38*8,564*8,39*8
//RANGE_OUTSIDECityToINSIDEPartyStore 601*8,38*8,609*8,39*8
//RANGE_OUTSIDECityToINSIDEOffice 706*8,38*8,714*8,39*8
//RANGE_OUTSIDECityToINSIDEStadium1 754*8,38*8,762*8,39*8
//RANGE_OUTSIDECityToINSIDEStadium2 765*8,38*8,773*8,39*8
//RANGE_OUTSIDECityToINSIDEStadium3 776*8,38*8,784*8,39*8
//RANGE_OUTSIDECityToINSIDEStadium4 787*8,38*8,795*8,39*8
//RANGE_OUTSIDECityToINSIDEStadium5 825*8,38*8,833*8,39*8
//RANGE_OUTSIDECityToINSIDEStadium6 836*8,38*8,844*8,39*8
//RANGE_OUTSIDECityToINSIDEStadium7 847*8,38*8,855*8,39*8
//RANGE_OUTSIDECityToINSIDEStadium8 858*8,38*8,866*8,39*8
//RANGE_OUTSIDECityToINSIDEStadium9 897*8,38*8,905*8,39*8
//RANGE_OUTSIDECityToINSIDEStadium10 908*8,38*8,916*8,39*8
//RANGE_OUTSIDECityToINSIDEStadium11 919*8,38*8,927*8,39*8
//RANGE_OUTSIDECityToINSIDEStadium12 930*8,38*8,938*8,39*8
//RANGE_OUTSIDECityToINSIDEHotel1 1019*8,38*8,1025*8,39*8
//RANGE_OUTSIDECityToINSIDEHotel2 1027*8,38*8,1033*8,39*8
//RANGE_OUTSIDECityToINSIDECityHall1 1072*8,38*8,1078*8,39*8
//RANGE_OUTSIDECityToINSIDECityHall2 1080*8,38*8,1086*8,39*8
//RANGE_OUTSIDECityToINSIDEMuseum1 1180*8,37*8,1186*8,38*8
//RANGE_OUTSIDECityToINSIDEMuseum2 1188*8,37*8,1194*8,38*8
//RANGE_OUTSIDECityToINSIDEHospital1 1252*8,38*8,1260*8,39*8
//RANGE_OUTSIDECityToINSIDEHospital2 1262*8,38*8,1270*8,39*8
//RANGE_OUTSIDECityToINSIDEHospital3 1272*8,38*8,1280*8,39*8
//RANGE_OUTSIDECityToINSIDEPoliceStation 1339*8,38*8,1347*8,39*8
//RANGE_OUTSIDECityToINSIDEFireDepartment 1391*8,38*8,1399*8,39*8
//RANGE_OUTSIDECityToINSIDEBank 1442*8,32*8,1450*8,33*8
//RANGE_OUTSIDECityToINSIDEFancyRestaurant 1502*8,37*8,1506*8,38*8
//RANGE_OUTSIDECityToINSIDEFashion 1547*8,37*8,1567*8,38*8
//RANGE_OUTSIDECityToINSIDEElevatedLifeplaceElevator 1591*8,37*8,1595*8,38*8
//RANGE_OUTSIDECityToINSIDEElevatedLifeplaceMainOffice 1625*8,38*8,1633*8,39*8
}

void bobsgame_CITYCity_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}

//==============================================================================================================================================
//line of cars.
//==============================================================================================================================================
//cars are created as needed, maybe move slowly. only a few cars need to be onscreen at any given time. maybe like 7 at most
//lots of honking, screaming

//4,64 to 1676, 64


//when screen is created, create cars at touchmapcam_x, +13, +13

static NPC* cars_npcs[7]={NULL,NULL,NULL,NULL,NULL,NULL,NULL};

int c=0;
for(c=0;c<7;c++)
{

	if(cars_npcs[c]==NULL)
	{
		int rightmost=(MAP_cam_x)-64;

		int num;for(num=0;num<7;num++)if(cars_npcs[num]!=NULL)if(cars_npcs[num]->MAP_x>rightmost)rightmost=cars_npcs[num]->MAP_x;

		if(rightmost+90<=MAP_cam_x+GAME_VIEWPORT_WIDTH_PIXELS)NPC_create_car(&cars_npcs[c],rightmost+90,(58+((r(3))-1))*8, LEFT);

		if(cars_npcs[c]!=NULL)cars_npcs[c]->walking_speed=SPEED_SLOW+r(SPEED_SLOW-SPEED_FASTEST);
	}

	if(cars_npcs[c]!=NULL)
	{

		int leftmost=c;
		int l;for(l=0;l<7;l++)if(cars_npcs[l]!=NULL)if(cars_npcs[l]->MAP_x<cars_npcs[leftmost]->MAP_x)leftmost=l;


		if(leftmost==c)
		{
			//if its too slow speed up

			if(cars_npcs[c]->MAP_x>MAP_cam_x+8&&cars_npcs[c]->walking_speed>SPEED_NORMAL)cars_npcs[c]->walking_speed=SPEED_NORMAL-(r(SPEED_FAST/2));

			//if its the leftest and theres a gap between the left and the car go left
			if(cars_npcs[c]->AI==0||cars_npcs[c]->MAP_x>MAP_cam_x-20)NPC_walk_to_xy_nohit_pushmain(&cars_npcs[c],cars_npcs[c]->walking_speed,cars_npcs[c]->MAP_x-1,-1);

			if(cars_npcs[c]->AI==0&&cars_npcs[c]->MAP_x==MAP_cam_x-20)
			{
				cars_npcs[c]->AI=1;
				cars_npcs[c]->vbls=r(240);
				cars_npcs[c]->MAP_x--;
			}
			if(cars_npcs[c]->AI==1){if(cars_npcs[c]->vbls>180){cars_npcs[c]->AI=0;}}


			//if its more than 2 tiles from left side, make a car on the left
			if(cars_npcs[c]->MAP_x>MAP_cam_x+16)
			{
				for(l=0;l<7;l++)
				{
					if(cars_npcs[l]==NULL)
					{
						NPC_create_car(&cars_npcs[l],((MAP_cam_x)-80),(58+((r(3))-1))*8, LEFT);
						cars_npcs[l]->vbls=r(60);
						cars_npcs[l]->walking_speed=SPEED_SLOW+r(SPEED_SLOW-SPEED_FASTEST);
						cars_npcs[l]->AI=1;
						leftmost=l;
						break;
					}
				}
			}
		}
		else
		{
			int leftleast=leftmost;
			int f=0;
			for(f=0;f<7;f++)
				if(cars_npcs[f]!=NULL)
					if(cars_npcs[f]->MAP_x<cars_npcs[c]->MAP_x&&cars_npcs[f]->MAP_x>cars_npcs[leftleast]->MAP_x)
						leftleast=f;
			//if(cars_npcs[c]->cycle==0)
			{
				if(cars_npcs[c]->MAP_x>cars_npcs[leftleast]->MAP_x+90)
				{
					if((cars_npcs[c]->MAP_x-(cars_npcs[leftleast]->MAP_x+90))>8&&cars_npcs[c]->walking_speed>SPEED_NORMAL)cars_npcs[c]->walking_speed=SPEED_NORMAL-(r(SPEED_FAST/2));
					else if((cars_npcs[c]->MAP_x-(cars_npcs[leftleast]->MAP_x+90))==8)cars_npcs[c]->walking_speed=SPEED_SLOWER+r(SPEED_SLOWER-SPEED_FASTEST);

					NPC_walk_to_xy_nohit_pushmain(&cars_npcs[c],cars_npcs[c]->walking_speed,cars_npcs[c]->MAP_x-1,-1);
				}
				else if(cars_npcs[c]->walking_speed<SPEED_SLOWEST)cars_npcs[c]->walking_speed=SPEED_SLOWEST+r(SPEED_SLOW-SPEED_FASTEST);//{cars_npcs[c]->cycle=1;cars_npcs[c]->vbl_timer=r(10);}
			}
			//if(cars_npcs[c]->cycle==1){if(cars_npcs[c]->vbl_timer>20){cars_npcs[c]->cycle=0;}}
		}

		if(MAP_is_xyxy_within_screen_by_amt(cars_npcs[c]->MAP_x-16,-1,cars_npcs[c]->MAP_x+90+16,-1,64)==0)
		{
			NPC_delete_npc(&cars_npcs[c]);

			//if(c==leftmost)
			//{
				//for(l=0;l<7;l++)if(cars_npcs[l]!=NULL)leftmost=l;
				//if(cars_npcs[leftmost]!=NULL)for(l=0;l<7;l++)if(cars_npcs[l]!=NULL)if(cars_npcs[l]->MAP_x<cars_npcs[leftmost]->MAP_x)leftmost=l;
				//if(cars_npcs[leftmost]!=NULL){cars_npcs[leftmost]->cycle=1;cars_npcs[leftmost]->vbl_timer=r(10);cars_npcs[leftmost]->walking_speed=SPEED_FAST;}
			//}
		}
	}
}













//==============================================================================================================================================
//people walking on the sidewalks
//==============================================================================================================================================

//TODO: less people when its raining





//special people.





//==============================================================================================================================================
//apartment stairs
//==============================================================================================================================================



//==============================================================================================================================================
//connect to apartment roof
//==============================================================================================================================================










//==============================================================================================================================================
//alleys
//==============================================================================================================================================










































	if(walking_into_door(RANGE_OUTSIDECityToINSIDEHourlyMotel))
	{
		MAP_change_map(MAP_bobsgame_CITYHourlyMotel,22,65);return;
	}
	if(walking_into_door(RANGE_OUTSIDECityToINSIDEPawnShop))
	{
		MAP_change_map(MAP_bobsgame_CITYPawnShop,14,43);return;
	}
	if(walking_into_door(RANGE_OUTSIDECityToINSIDECasino1))
	{
		MAP_change_map(MAP_bobsgame_CITYCasinoEntrance,36,48);return;
	}
	if(walking_into_door(RANGE_OUTSIDECityToINSIDECasino2))
	{
		MAP_change_map(MAP_bobsgame_CITYCasinoEntrance,44,48);return;
	}
	if(walking_into_door(RANGE_OUTSIDECityToINSIDECasino3))
	{
		MAP_change_map(MAP_bobsgame_CITYCasinoEntrance,52,48);return;
	}
	if(walking_into_door(RANGE_OUTSIDECityToINSIDECasino4))
	{
		MAP_change_map(MAP_bobsgame_CITYCasinoEntrance,60,48);return;
	}
	if(walking_into_door(RANGE_OUTSIDECityToINSIDETheCafe))
	{
		MAP_change_map(MAP_bobsgame_CITYTheCafeEntrance,9,17);return;
	}
	if(walking_into_door(RANGE_OUTSIDECityToINSIDEGroovyClub))
	{
		MAP_change_map(MAP_bobsgame_CITYGroovyClubEntrance,12,24);return;
	}
	if(walking_into_door(RANGE_OUTSIDECityToINSIDEPoolHall))
	{
		MAP_change_map(MAP_bobsgame_CITYPoolHall,32,61);return;
	}
	if(walking_into_door(RANGE_OUTSIDECityToINSIDELaundromat))
	{
		MAP_change_map(MAP_bobsgame_CITYLaundromat,36,46);return;
	}
	if(walking_into_door(RANGE_OUTSIDECityToINSIDEApartmentMainOffice))
	{
		MAP_change_map(MAP_bobsgame_CITYAptMainOffice,36,33);return;
	}
	if(walking_into_door(RANGE_OUTSIDECityToINSIDEBobsApt))
	{
		MAP_change_map(MAP_bobsgame_CITYBobsAptInside,19,33);return;
	}
	if(walking_into_door(RANGE_OUTSIDECityToINSIDENeighborApt))
	{
		MAP_change_map(MAP_bobsgame_CITYNeighborAptInside,19,33);return;
	}
	if(walking_into_door(RANGE_OUTSIDECityToINSIDEDeli))
	{
		MAP_change_map(MAP_bobsgame_CITYDeli,22,41);return;
	}
	if(walking_into_door(RANGE_OUTSIDECityToINSIDEPartyStore))
	{
		MAP_change_map(MAP_bobsgame_CITYPartyStore,33,40);return;
	}
	if(walking_into_door(RANGE_OUTSIDECityToINSIDEOffice))
	{
		MAP_change_map(MAP_bobsgame_CITYOfficeEntrance,32,42);return;
	}
	if(walking_into_door(RANGE_OUTSIDECityToINSIDEStadium1))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumLobby,12,30);return;
	}
	if(walking_into_door(RANGE_OUTSIDECityToINSIDEStadium2))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumLobby,23,30);return;
	}
	if(walking_into_door(RANGE_OUTSIDECityToINSIDEStadium3))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumLobby,34,30);return;
	}
	if(walking_into_door(RANGE_OUTSIDECityToINSIDEStadium4))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumLobby,45,30);return;
	}
	if(walking_into_door(RANGE_OUTSIDECityToINSIDEStadium5))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumLobby,83,30);return;
	}
	if(walking_into_door(RANGE_OUTSIDECityToINSIDEStadium6))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumLobby,94,30);return;
	}
	if(walking_into_door(RANGE_OUTSIDECityToINSIDEStadium7))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumLobby,105,30);return;
	}
	if(walking_into_door(RANGE_OUTSIDECityToINSIDEStadium8))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumLobby,116,30);return;
	}
	if(walking_into_door(RANGE_OUTSIDECityToINSIDEStadium9))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumLobby,155,30);return;
	}
	if(walking_into_door(RANGE_OUTSIDECityToINSIDEStadium10))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumLobby,166,30);return;
	}
	if(walking_into_door(RANGE_OUTSIDECityToINSIDEStadium11))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumLobby,177,30);return;
	}
	if(walking_into_door(RANGE_OUTSIDECityToINSIDEStadium12))
	{
		MAP_change_map(MAP_bobsgame_CITYStadiumLobby,188,30);return;
	}
	if(walking_into_door(RANGE_OUTSIDECityToINSIDEHotel1))
	{
		MAP_change_map(MAP_bobsgame_CITYHotelEntrance,72,59);return;
	}
	if(walking_into_door(RANGE_OUTSIDECityToINSIDEHotel2))
	{
		MAP_change_map(MAP_bobsgame_CITYHotelEntrance,80,59);return;
	}
	if(walking_into_door(RANGE_OUTSIDECityToINSIDECityHall1))
	{
		MAP_change_map(MAP_bobsgame_CITYCityHallEntrance,25,45);return;
	}
	if(walking_into_door(RANGE_OUTSIDECityToINSIDECityHall2))
	{
		MAP_change_map(MAP_bobsgame_CITYCityHallEntrance,33,45);return;
	}
	if(walking_into_door(RANGE_OUTSIDECityToINSIDEMuseum1))
	{
		MAP_change_map(MAP_bobsgame_CITYMuseumLobby,10,23);return;
	}
	if(walking_into_door(RANGE_OUTSIDECityToINSIDEMuseum2))
	{
		MAP_change_map(MAP_bobsgame_CITYMuseumLobby,18,23);return;
	}
	if(walking_into_door(RANGE_OUTSIDECityToINSIDEHospital1))
	{
		MAP_change_map(MAP_bobsgame_CITYHospitalEntrance,18,41);return;
	}
	if(walking_into_door(RANGE_OUTSIDECityToINSIDEHospital2))
	{
		MAP_change_map(MAP_bobsgame_CITYHospitalEntrance,28,41);return;
	}
	if(walking_into_door(RANGE_OUTSIDECityToINSIDEHospital3))
	{
		MAP_change_map(MAP_bobsgame_CITYHospitalEntrance,38,41);return;
	}
	if(walking_into_door(RANGE_OUTSIDECityToINSIDEPoliceStation))
	{
		MAP_change_map(MAP_bobsgame_CITYPoliceStationLobby,20,21);return;
	}
	if(walking_into_door(RANGE_OUTSIDECityToINSIDEFireDepartment))
	{
		MAP_change_map(MAP_bobsgame_CITYFireDepartmentGarage,37,53);return;
	}
	if(walking_into_door(RANGE_OUTSIDECityToINSIDEBank))
	{
		MAP_change_map(MAP_bobsgame_CITYBankEntrance,37,41);return;
	}
	if(walking_into_door(RANGE_OUTSIDECityToINSIDEFancyRestaurant))
	{
		MAP_change_map(MAP_bobsgame_CITYFancyRestaurantEntrance,30,24);return;
	}
	if(walking_into_door(RANGE_OUTSIDECityToINSIDEFashion))
	{
		MAP_change_map(MAP_bobsgame_CITYFashionStore,17,53);return;
	}
	if(walking_into_door(RANGE_OUTSIDECityToINSIDEElevatedLifeplaceElevator))
	{
		MAP_change_map(MAP_bobsgame_CITYElevatedLifeplaceElevator,5,18);return;
	}
	if(walking_into_door(RANGE_OUTSIDECityToINSIDEElevatedLifeplaceMainOffice))
	{
		MAP_change_map(MAP_bobsgame_CITYElevatedLifeplace,42,42);return;
	}
	}

void bobsgame_CITYCity_Map_Stop_Function()
{

}

void bobsgame_CITYCity_Map_VBL_Function()
{

}

void bobsgame_CITYCity_Map_HBL_Function()
{

}


//========================================================
//CITYAptRoof
//========================================================
void bobsgame_CITYAptRoof_Map_Load_Function()
{

}

void bobsgame_CITYAptRoof_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}
}

void bobsgame_CITYAptRoof_Map_Stop_Function()
{

}

void bobsgame_CITYAptRoof_Map_VBL_Function()
{

}

void bobsgame_CITYAptRoof_Map_HBL_Function()
{

}

//========================================================
//CITYAlleys
//========================================================
void bobsgame_CITYAlleys_Map_Load_Function()
{

}

void bobsgame_CITYAlleys_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}
}

void bobsgame_CITYAlleys_Map_Stop_Function()
{

}

void bobsgame_CITYAlleys_Map_VBL_Function()
{

}

void bobsgame_CITYAlleys_Map_HBL_Function()
{

}



