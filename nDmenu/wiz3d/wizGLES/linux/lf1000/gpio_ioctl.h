#ifndef GPIO_IOCTL_H
#define GPIO_IOCTL_H

#define GPIO_IOC_MAGIC   'g'

/* port can be 0 for A, 1 for B, 2 for C */
struct outvalue_cmd {
	unsigned char port;
	unsigned int pin;
	unsigned char value;
};

struct outenb_cmd {
	unsigned char port;
	unsigned int pin;
	unsigned char value;
};

struct invalue_cmd {
	unsigned char port;
	unsigned int pin;
	unsigned int value;
};

/* func can be 0 for gpio, 1 for alt1, or 2 for alt2 */
struct func_cmd {
	unsigned char port;
	unsigned int pin;
	unsigned int func;
};

union gpio_cmd {
	struct outvalue_cmd outvalue;
	struct outenb_cmd outenb;
	struct invalue_cmd invalue;
	struct func_cmd func;
};

/* supported ioctls */

#define GPIO_IOCSOUTVAL		_IOW(GPIO_IOC_MAGIC, 0, struct outvalue_cmd *)
#define GPIO_IOCSOUTENB		_IOW(GPIO_IOC_MAGIC, 1, struct outenb_cmd *)
#define GPIO_IOCXINVAL		_IOWR(GPIO_IOC_MAGIC, 2, struct invalue_cmd *)
#define GPIO_IOCSFUNC		_IOW(GPIO_IOC_MAGIC, 3, struct func_cmd *)

#endif
