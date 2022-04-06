/* LF1000 Power Driver
 *
 * power_ioctl.h -- Supported ioctl commands.
 *
 * Scott Esters
 * LeapFrog Enterprises
 */

#ifndef POWER_IOCTL_H
#define POWER_IOCTL_H

#define POWER_IOC_MAGIC	'p'

#define POWER_IOCT_SHUTDOWN          _IO(POWER_IOC_MAGIC, 1)
#define POWER_IOCQ_SHUTDOWN_TIME_MS _IOR(POWER_IOC_MAGIC, 2, int)
#define POWER_IOCT_SHUTDOWN_TIME_MS _IOW(POWER_IOC_MAGIC, 3, int)
#define POWER_IOCT_RESET	     _IO(POWER_IOC_MAGIC, 4)
#define POWER_IOCQ_STATUS	    _IOR(POWER_IOC_MAGIC, 5, int)
#define POWER_IOCQ_GET_BATTERY_MV   _IOR(POWER_IOC_MAGIC, 6, int)
#define POWER_IOCT_SYSTEM_RESET	     _IO(POWER_IOC_MAGIC, 7)
#define POWER_IOCT_SYSTEM_SHUTDOWN   _IO(POWER_IOC_MAGIC, 8)

#define POWER_IOCQ_DAEMON_SHUTDOWN_TIME_MS _IOR(POWER_IOC_MAGIC,  9, int)
#define POWER_IOCT_DAEMON_SHUTDOWN_TIME_MS _IOW(POWER_IOC_MAGIC, 10, int)
#define POWER_IOCQ_GET_BATTERY_STATE       _IOR(POWER_IOC_MAGIC, 11, int)

/*
 * Captured system power-off status codes
 */ 

/* initial power-on of system, (ie. batteries replaced) */
#define POWER_COLDSTART         0

/*
 * driver did not set power down reason such as a hardware reset.
 * Note that this differs from first power-on coldstart
 */
#define POWER_UNDEFINED         1

/* off button pressed, normal application shutdown */
#define POWER_SHUTDOWN_NORMAL   2

/* shutdown button pressed, shutdown timer expired */
#define POWER_SHUTDOWN_TIMER    3

/* hardware reset button pressed */
#define POWER_HARD_RESET        4

/* software reset requested */
#define POWER_SOFT_RESET        5

/* shutdown button pressed, timer running	*/
#define POWER_SHUTDOWN_PENDING	6

/* request user-space shutdown start	*/
#define POWER_SHUTDOWN_REQ_START 7

/* request user-space reboot start	*/
#define POWER_RESET_REQ_START	 8

/* reset requested, timer fired */
#define POWER_RESET_TIMER	 9
#endif
