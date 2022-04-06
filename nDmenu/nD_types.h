
//===============================================================================
//TYPES
//===============================================================================

typedef uint8_t		uint8;
typedef uint16_t	uint16;
typedef uint32_t	uint32;
typedef uint64_t	uint64;

typedef int8_t		int8;
typedef int16_t		int16;
typedef int32_t		int32;
typedef int64_t		int64;

typedef float		float32;
typedef double		float64;

typedef volatile uint8_t	vuint8;
typedef volatile uint16_t	vuint16;
typedef volatile uint32_t	vuint32;
typedef volatile uint64_t	vuint64;

typedef volatile int8_t		vint8;
typedef volatile int16_t	vint16;
typedef volatile int32_t	vint32;
typedef volatile int64_t	vint64;

typedef volatile float32        vfloat32;
typedef volatile float64        vfloat64;

typedef uint8_t		byte;

typedef uint8_t		u8;
typedef uint16_t	u16;
typedef uint32_t	u32;
typedef uint64_t	u64;

typedef int8_t		s8;
typedef int16_t		s16;
typedef int32_t		s32;
typedef int64_t		s64;

typedef volatile u8          vu8;
typedef volatile u16         vu16;
typedef volatile u32         vu32;
typedef volatile u64         vu64;

typedef volatile s8           vs8;
typedef volatile s16          vs16;
typedef volatile s32          vs32;
typedef volatile s64          vs64;


#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef true
#define true TRUE
#endif

#ifndef false
#define false FALSE
#endif

#ifndef NULL
#define NULL ((void*)0)
#endif

#ifndef null
#define null NULL
#endif

//#ifndef BOOL
//typedef u8 BOOL;
//#endif

#ifndef bool
#define bool BOOL
#endif

#define BIT(n) (1 << (n))

