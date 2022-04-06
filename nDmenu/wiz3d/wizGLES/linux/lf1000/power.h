#ifndef _POWER_H_
#define _POWER_H_

/* map battery levels to Brio Messages */
#define ADC_MAX_BATTERY_MV	8000	/* max expected battery value	*/
#define ADC_LOW_BATTERY_MV	4100	/* low battery			*/
#define ADC_CRITICAL_BATTERY_MV 4000	/* critical low battery		*/

/* Power definitions are borrowed from Brio2's System/Include/PowerTypes.h */

struct tPowerData {
	unsigned int powerState;
} __attribute__((packed));

#define kPowerNull		0
#define kPowerExternal		1
#define kPowerBattery		2
#define kPowerLowBattery	3
#define kPowerShutdown	 	4
#define kPowerCriticalBattery	5

/* return one of the above power states */
int lf1000_get_power_state(void);

/* return battery reading in millivolts */
int lf1000_get_battery_mv(void);

#endif
