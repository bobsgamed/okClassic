#define	lf_linux
#define	__int64	long long

#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include <sys/time.h>
#include "GL/gl.h"
#include "GL/egl.h"
#include "GL/libogl.h"
//#include "Fake_OS.h"

#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

//#define LCD_DIRECTION_240320_TO_320240   //only wiz

#include "linux/lf1000/pollux_fb_ioctl.h"

#define VID_RGBFMT_R5G6B5       0x4432

//#include <iostream>

using namespace std;

void OS_InitFakeOS( void )
{
}

NativeWindowType OS_CreateWindow() { return (NativeWindowType)malloc( 16*1024);}

unsigned int OS_GetTickCount( void ) {
#define	SCALE	1000
struct timeval time;

    gettimeofday( &time, 0);
    return (time.tv_sec*SCALE+time.tv_usec/(1000000/SCALE));
}

extern void GLESOAL_GetWindowSize( int* pWidth, int* pHeight );
void OS_GetWindowSize( NativeWindowType hNativeWnd, int* width, int* height)
{
    GLESOAL_GetWindowSize( width, height );
}

void OS_Sleep( unsigned int milliseconds )
{
    GLESOAL_Sleep( milliseconds );
}


#define P_3DE		2
#define	DEV_NAME	"/dev/ga3d"
#define	MEM_NAME	"/dev/mem"
#define	PHYS_ADDR	0xc001a000

static int   fd_mem;
static int   fd_dev;

static void* p3DE = NULL;
static int   len3DE;

static void* mem1 = NULL;
#define	MEM1_PHYS	0x03000000
#define	mem1size	0x00800000
#define	mem1virt	(void*)0xb1000000

static void* mem2 = NULL;
#define	MEM2_PHYS	( MEM1_PHYS + mem1size)
#define	mem2size	mem1size
#define	mem2virt	(void*)((unsigned int)mem1virt + mem1size)

static int FSAAval;
static FB_RGBSET rgbset;
static unsigned int DevEnable[3];
static int fb_fd;
#define FB_DEV_PATH "/dev/fb0"




GLESOALbool GLESOAL_Initalize( ___OAL_MEMORY_INFORMATION__* pMemoryInfomation, int FSAAEnb)
{
	int psize = getpagesize();
	int xlayer;
    unsigned int send[2];

    fb_fd = open( FB_DEV_PATH , O_RDWR);
	if(fb_fd < 0) {
	    printf("error: failed to open " FB_DEV_PATH  "\n");
		exit( 0);
	}

#ifdef LCD_DIRECTION_240320_TO_320240
    send[0] = LCD_DIRECTION_ON_CMD;
    ioctl(fb_fd, FBIO_LCD_CHANGE_CONTROL, send);
#endif


    // Open 3D register set driver
    len3DE = P_3DE * psize;

    if (( fd_dev = open( DEV_NAME, O_RDWR|O_SYNC))<0) {
		perror("open " DEV_NAME " failed");
		exit(-1);
    }

    if (( fd_mem = open( MEM_NAME, O_RDWR|O_SYNC))<0) {
		perror("open " MEM_NAME " failed");
		exit(-1);
    }

    // Map 3D register set into user space
    p3DE = mmap( 0, len3DE, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_LOCKED | MAP_POPULATE, fd_dev, PHYS_ADDR);
    if( (int)p3DE == -1) {
		p3DE = NULL;
		munmap( p3DE, len3DE);
		printf("mmap 0x%08x failed\n", PHYS_ADDR);
		exit(-1);
    }

    // Map 1D and 2D mem heaps
    mem1 = mmap( mem1virt, mem1size, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_LOCKED | MAP_POPULATE, fd_mem, MEM1_PHYS);
    if( (int)mem1 == -1) {
		munmap( p3DE, len3DE);
		printf("mmap 0x%08x failed\n", MEM1_PHYS);
		exit(-1);
    }

    mem2 = mmap( mem2virt, mem2size, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_LOCKED | MAP_POPULATE, fd_mem, MEM2_PHYS);
    if( (int)mem2 == -1) {
		munmap( p3DE, len3DE);
		munmap( mem1, mem1size);
		printf("mmap 0x%08x failed\n", MEM2_PHYS);
		exit(-1);
    }

    // Pass back mappings to ME OGL callback
    pMemoryInfomation->VirtualAddressOf3DCore	= (unsigned int)p3DE;
    pMemoryInfomation->Memory1D_VirtualAddress	= (unsigned int)mem1;
    pMemoryInfomation->Memory1D_PhysicalAddress	= MEM1_PHYS;
    pMemoryInfomation->Memory1D_SizeInMbyte	= (mem1size-0x100000) >> 20;
    pMemoryInfomation->Memory2D_VirtualAddress	= (unsigned int)mem2;
    pMemoryInfomation->Memory2D_PhysicalAddress	= MEM2_PHYS;
    pMemoryInfomation->Memory2D_SizeInMbyte	= mem2size >> 20;

    //printf("FSAAEnb: %d\n", FSAAEnb );

    return 1;
}

void GLESOAL_Finalize( void )
{
    unsigned int send[2];

	// Too late to disable 3D layer? NOT (FSAA not active)
    rgbset.enable3D = 0;
    ioctl(fb_fd, FBIO_RGB_CONTROL, &rgbset);

    DevEnable[0] = 0;	// layer
	DevEnable[1] = 0;	// on
	DevEnable[2] = 1;	// mlc_dev

    ioctl(fb_fd, FBIO_DEVICE_ENABLE, DevEnable);

    munmap( p3DE, len3DE);
    munmap( mem1, mem1size);
    munmap( mem2, mem2size);
    close(fd_mem);

#ifdef LCD_DIRECTION_240320_TO_320240
    send[0] = LCD_DIRECTION_OFF_CMD;
    ioctl(fb_fd, FBIO_LCD_CHANGE_CONTROL, send);
#endif

    close(fb_fd);
}

//------------------------------------------------------------------------------
void GLESOAL_SwapBufferCallback( void )
{
	int layer;
	int response;
	static int once = 0;

    rgbset.Layer = 0;
	rgbset.Addrs = 0;
	rgbset.Left = 0;
	rgbset.Top = 0;
	rgbset.Right = 320;
	rgbset.Bottom = 240;
    //rgbset.Right = 240;
//	rgbset.Bottom = 320;

	rgbset.HStride = 2;
	rgbset.VStride = 4096;
	rgbset.enable3D = 1;
	rgbset.Bakcol = 0x0;
	rgbset.Mlc_dev = 1;
    ioctl(fb_fd, FBIO_RGB_CONTROL, &rgbset);

    DevEnable[0] = 0;	// layer
	DevEnable[1] = 1;	// on
	DevEnable[2] = 1;	// mlc_dev
    ioctl(fb_fd, FBIO_DEVICE_ENABLE, DevEnable);
}

//------------------------------------------------------------------------------
void GLESOAL_SetWindow    ( void* pNativeWindow  )
{
}

//------------------------------------------------------------------------------
void GLESOAL_GetWindowSize( int* pWidth, int* pHeight )
{
    *pWidth  = 320;
    *pHeight = 240;
}

//------------------------------------------------------------------------------
void GLESOAL_WaitForDisplayAddressPatched( void )
{

    DevEnable[0] = 0;	// layer
	DevEnable[1] = 1;	// on
	DevEnable[2] = 1;	// mlc_dev

    while( ioctl(fb_fd, FBIO_GET_DIRTFLAG, DevEnable) ) usleep(10);
}

//------------------------------------------------------------------------------
void GLESOAL_SetDisplayAddress( const unsigned int DisplayBufferPhysicalAddress )
{
    rgbset.Layer = 0;
	rgbset.Addrs = DisplayBufferPhysicalAddress;
	rgbset.Left = 0;
	rgbset.Top = 0;
	rgbset.Right = 320;
	rgbset.Bottom = 240;
	//rgbset.Right = 240;
	//rgbset.Bottom = 320;
	rgbset.HStride = 2;
	rgbset.VStride = 4096;
	rgbset.enable3D = 1;
	rgbset.Bakcol = 0x0;
	rgbset.Mlc_dev = 1;
    ioctl(fb_fd, FBIO_RGB_CONTROL, &rgbset);

    DevEnable[0] = 0;	// layer
	DevEnable[1] = 1;	// on
	DevEnable[2] = 1;	// mlc_dev
    ioctl(fb_fd, FBIO_DEVICE_ENABLE, DevEnable);
}

//------------------------------------------------------------------------------
void GLESOAL_Sleep( unsigned long Milliseconds )
{
	Milliseconds *= 1000;
    if (Milliseconds == 0)
        Milliseconds = 1;
    usleep( Milliseconds );
}


//----
int GLESOAL_GetDisplayDirection(void)
{
	return 0;
}

