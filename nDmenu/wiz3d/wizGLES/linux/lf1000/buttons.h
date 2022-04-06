#ifndef _BUTTONS_H_
#define _BUTTONS_H_

/* Each button that is pushed generates a button event.  This button event is
 * characterized by two u32s.  button_state represents whether a button is
 * currently pressed, and button_trans represents whether a button changed
 * state during this event.
 */

struct button_event {
	unsigned int button_state;
	unsigned int button_trans;
} __attribute__((packed));

/* button definitions used to set the button member of the button_event.  These
 * (except for kButtonNull) are borrowed from Brio2's
 * System/Include/ButtonTypes.h.  The mappings from gpio pin to these button
 * values is hard-coded in the driver.  If necessary, we can create a means for
 * the user to choose the key mappings.
 * 
 * Although not a button, the headphone jack detect event is handled just like a button
 * press.  This event may be moved to the OSS sound system later.
 */

#define kButtonNull		(0)
#define kButtonUpKey		(1 << 0)
#define kButtonDownKey		(1 << 1)
#define kButtonRightKey		(1 << 2)
#define kButtonLeftKey		(1 << 3)
#define kButtonAKey		(1 << 4)
#define kButtonBKey		(1 << 5)
#define kButtonLeftShoulderKey	(1 << 6)
#define kButtonRightShoulderKey	(1 << 7)
#define kButtonMenuKey		(1 << 8)
#define kButtonHintKey		(1 << 9)
#define kButtonPauseKey		(1 << 10)
#define kButtonBrightnessKey	(1 << 11)
#define kHeadphoneJackDetect	(1 << 12)
#define kCartridgeDetect	(1 << 13)

#endif
