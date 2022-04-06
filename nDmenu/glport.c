/*Wiz to drive in the OpenGL-ES lite is a library for the library glport.
The current firmware version as the previous build from the source by including glport.cpp function the way
Libglport.so well as using a shared library will run.
Let's examine the contents, but must, as a simple
If you are using the previous method (built-in source and those that build) and see the memory allocation
If you are joteuldeut. Only 2D memory to keep it a multiple of 4. (4,8,12,16,,,)
And the Wiz in 3D is a total of 16 megabytes of memory to allocate.
*/

# Define lf_linux
//# Define __int64 long long

# Include
# Include
# Include
# Include
# Include
# Include
# Include
# Include
# Include
# Include
//# Include
# Include

# Include "egltypes.h"
# Include "libogl.h"
# Include "pollux_fb_ioctl.h"

# Define VID_RGBFMT_R5G6B5 0x4432
# Define WIZ_3D 0x11
/*Wiz is used to distinguish whether or F300.
If waenya ~ Wiz
Screen to prevent tiering frame buffer 240*320 because the need settinghae.
F300 is the frame buffer 320*240 because the setting is not required. Actually define where as big as
Kernel for the unit to be set to static so here is the declaration.
*/

# Define P_3DE 2
# Define DEV_NAME "/dev/ga3d"
# Define MEM_NAME "/dev/mem"
# Define PHYS_ADDR 0xc001a000

// Assign the texture somehow takes more memory because it must allocate a lot more 2D.
/*1D with 4 MB of memory allows him*/
# Define MEM1_PHYS 0x03000000
# Define mem1size 0x00400000 // 4MB
# Define mem1virt (void*) 0xb1000000

/*2D set to 12 megabytes of memory gives*/
# Define MEM2_PHYS (MEM1_PHYS + mem1size)
# Define mem2size (mem1size + 0x00800000) // 12MB
# Define mem2virt (void*) ((unsigned int) mem1virt + mem1size)
# Define FB_DEV_PATH "/ dev/fb0"

# Define DISPLAY__00 0
# Define DISPLAY__90 1
# Define DISPLAY_180 2
# Define DISPLAY_270 3

# Define SCALE 1000

static int fd_mem;
static int fd_dev;

static void *p3DE = NULL;
static int len3DE;

static void *mem1 = NULL;
static void *mem2 = NULL;

static int FSAAval;
static FB_RGBSET rgbset;
static unsigned int DevEnable [3];
static int fb_fd;

static int g_FSAAEnb = 0;

// Using namespace std;

/********************************************************************************/
void OS_InitFakeOS (void)
{
}

NativeWindowType OS_CreateWindow ()
{
return (NativeWindowType) malloc (16*1024);
}

unsigned int OS_GetTickCount (void)
{
struct timeval time;

gettimeofday (& time, 0);
return (time.tv_sec*SCALE + time.tv_usec / (1000000/SCALE));
}

void OS_GetWindowSize (void*hNativeWnd, int *width, int *height)
{
GLESOAL_GetWindowSize (width, height);
}

void OS_Sleep (unsigned int milliseconds)
{
GLESOAL_Sleep (milliseconds);
}

int GLESOAL_GetDisplayDirection (void)
{
static int g_DisplayDirection = -1;
if (g_DisplayDirection> = 0) return g_DisplayDirection;

int fb_fd;
unsigned char num_bd;
unsigned int send [2];

fb_fd = open (FB_DEV_PATH, O_RDWR);

// Here's a portion of the frame buffer setting! 320 240 *If you set wijeuil haejum
ioctl (fb_fd, FBIO_GET_3D_NUMBER, & num_bd);
if (num_bd == WIZ_3D) // 240 *320 (only Wiz)
{
send [0] = LCD_DIRECTION_OFF_CMD;
send [1] = 0;
ioctl (fb_fd, FBIO_LCD_CHANGE_CONTROL, send);
g_DisplayDirection = DISPLAY__90;
}
else // 320*240 (F300, N35)
g_DisplayDirection = DISPLAY__00;

close (fb_fd);

return g_DisplayDirection;
}

// Initialize the most important part of OpenGL ES
GLESOALbool GLESOAL_Initalize (___OAL_MEMORY_INFORMATION__ *pMemoryInfomation, int FSAAEnb)
{
g_FSAAEnb = FSAAEnb;

int psize = getpagesize ();
int xlayer;
unsigned int send [2];

unsigned char *mapped_mem = NULL;

fb_fd = open (FB_DEV_PATH, O_RDWR);
if (fb_fd <0) {
printf ("error: failed to open" FB_DEV_PATH "\ n");
exit (0);
}

// Initialize the screen before the spots (?) Helps to eliminate some of
// LCD Standby Mode On one screen kkeojunda
send [0] = LCD_POWER_DOWN_ON_CMD;
send [1] = 0;
ioctl (fb_fd, FBIO_LCD_CHANGE_CONTROL, send);

switch (GLESOAL_GetDisplayDirection ())
{
case DISPLAY__00:
break;
case DISPLAY__90:
break;
case DISPLAY_180:
//???
break;
case DISPLAY_270:
//???
break;
}

// Open 3D register set driver
len3DE = P_3DE *psize;

if ((fd_dev = open (DEV_NAME, O_RDWR | O_SYNC)) <0) {
perror ("open" DEV_NAME "failed");
exit (-1);
}

if ((fd_mem = open (MEM_NAME, O_RDWR | O_SYNC)) <0) {
perror ("open" MEM_NAME "failed");
exit (-1);
}
// Allocate memory, let a bitch ~ ~!
mapped_mem = mmap (NULL, (240*320*2), PROT_READ | PROT_WRITE, MAP_SHARED, fd_mem, 0x2A00000);
memset (mapped_mem, 0x00, (240*320*2));
munmap (mapped_mem, (240*320*2));

// Map 3D register set into user space
p3DE = mmap (0, len3DE, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_LOCKED | MAP_POPULATE, fd_dev, PHYS_ADDR);
if ((int) p3DE == -1) {
p3DE = NULL;
munmap (p3DE, len3DE);
printf ("mmap 0x% 08x failed \ n", PHYS_ADDR);
exit (-1);
}
memset (p3DE, 0x00, len3DE);
// Map 1D and 2D mem heaps
mem1 = mmap (mem1virt, mem1size, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_LOCKED | MAP_POPULATE, fd_mem, MEM1_PHYS);
if ((int) mem1 == -1) {
munmap (p3DE, len3DE);
printf ("mmap 0x% 08x failed \ n", MEM1_PHYS);
exit (-1);
}
memset (mem1, 0x00, mem1size);

mem2 = mmap (mem2virt, mem2size, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_LOCKED | MAP_POPULATE, fd_mem, MEM2_PHYS);
if ((int) mem2 == -1) {
munmap (p3DE, len3DE);
munmap (mem1, mem1size);
printf ("mmap 0x% 08x failed \ n", MEM2_PHYS);
exit (-1);
}

memset (mem2, 0x00, mem2size);

// LCD Standby Mode Off kyeojunda prepared to redraw the screen is pretty low.
send [0] = LCD_POWER_DOWN_OFF_CMD;
send [1] = 0;
ioctl (fb_fd, FBIO_LCD_CHANGE_CONTROL, send);
// Pass back mappings to ME OGL callback
pMemoryInfomation-> VirtualAddressOf3DCore = (unsigned int) p3DE;

pMemoryInfomation-> Memory1D_NumberOfHeaps = 1;
pMemoryInfomation-> Memory2D_NumberOfHeaps = 1;

pMemoryInfomation-> Memory1D_Heaps [0]. VirtualAddress = (unsigned int) mem1;
pMemoryInfomation-> Memory1D_Heaps [0]. PhysicalAddress = MEM1_PHYS;
pMemoryInfomation-> Memory1D_Heaps [0]. SizeInMbyte = (mem1size-0x100000)>> 20;

pMemoryInfomation-> Memory2D_Heaps [0]. VirtualAddress = (unsigned int) mem2;
pMemoryInfomation-> Memory2D_Heaps [0]. PhysicalAddress = MEM2_PHYS;
pMemoryInfomation-> Memory2D_Heaps [0]. SizeInMbyte = mem2size>> 20;

printf ("FSAAEnb:% d \ n", FSAAEnb);

rgbset.Layer = 0;
rgbset.Addrs = 0;
rgbset.Left = 0;
rgbset.Top = 0;
rgbset.HStride = 2;
rgbset.VStride = 4096;
rgbset.enable3D = 1;
rgbset.Bakcol = 0x0;
rgbset.Mlc_dev = 1;
switch (GLESOAL_GetDisplayDirection ())
{
case DISPLAY__00:
rgbset.Right = 320;
rgbset.Bottom = 240;
printf ("DISPLAY__00 \ n");
break;
case DISPLAY__90:
rgbset.Right = 240;
rgbset.Bottom = 320;
printf ("DISPLAY__90 \ n");
break;
case DISPLAY_180:
rgbset.Right = 320;
rgbset.Bottom = 240;
printf ("DISPLAY_180 \ n");
break;
case DISPLAY_270:
rgbset.Right = 240;
rgbset.Bottom = 320;
printf ("DISPLAY_270 \ n");
break;
}
ioctl (fb_fd, FBIO_RGB_CONTROL, & rgbset);

return 1;
}

// OpenGL-ES a part of shutdown processing
void GLESOAL_Finalize (void)
{
unsigned int send [2];

// LCD Standby Mode On-screen, first kkeojugo
send [0] = LCD_POWER_DOWN_ON_CMD;
send [1] = 0;
ioctl (fb_fd, FBIO_LCD_CHANGE_CONTROL, send);

DevEnable [0] = 0; // layer
DevEnable [1] = 0; // on
DevEnable [2] = 1; // mlc_dev
ioctl (fb_fd, FBIO_DEVICE_ENABLE, DevEnable);
printf ("--- 1 \ n ");
DevEnable [0] = 1; // RGB 0 layer
DevEnable [1] = 0; // off
DevEnable [2] = 1; // mlc_dev
ioctl (fb_fd, FBIO_DEVICE_ENABLE, DevEnable);
printf ("--- 2 \ n ");
DevEnable [0] = 2; // yuv layer
DevEnable [1] = 0; // off
DevEnable [2] = 1; // mlc_dev
ioctl (fb_fd, FBIO_DEVICE_ENABLE, DevEnable);
printf ("--- 3 \ n ");

// Too late to disable 3D layer? NOT (FSAA not active) 3D layer also kkeojugo
rgbset.enable3D = 0;
ioctl (fb_fd, FBIO_RGB_CONTROL, & rgbset);

// Allocate memory for things that will release
munmap (p3DE, len3DE);
munmap (mem1, mem1size);
munmap (mem2, mem2size);

close (fd_mem);

switch (GLESOAL_GetDisplayDirection ())
{
case DISPLAY__00:
break;
case DISPLAY__90:
send [0] = LCD_DIRECTION_ON_CMD;
ioctl (fb_fd, FBIO_LCD_CHANGE_CONTROL, send);
break;
case DISPLAY_180:
//???
break;
case DISPLAY_270:
//???
break;
}

// LCD Standby Mode Off kyeojunda ready hoping to redraw the screen
send [0] = LCD_POWER_DOWN_OFF_CMD;
send [1] = 0;
ioctl (fb_fd, FBIO_LCD_CHANGE_CONTROL, send);

close (fb_fd);
}

// Edit by ByunDragon 2009.09.24
void GLESOAL_SwapBufferCallback (void)
{

DevEnable [0] = 0; // layer
DevEnable [1] = 1; // on
DevEnable [2] = 1; // mlc_dev
ioctl (fb_fd, FBIO_DEVICE_ENABLE, DevEnable);
}

//------------------------------------------------ ----------------------------
void GLESOAL_SetWindow (void *pNativeWindow)
{
}

//------------------------------------------------ ------------------------------

// Extern void GLESOAL_GetWindowSize (int *pWidth, int *pHeight);
void GLESOAL_GetWindowSize (int *pWidth, int *pHeight)
{
*PWidth = 320;
*PHeight = 240;
}

//------------------------------------------------ ------------------------------
void GLESOAL_WaitForDisplayAddressPatched (void)
{
/*
if (! g_FSAAEnb) {return;}
// @ Todo: FSAA implementation
*/
DevEnable [0] = 0; // layer
DevEnable [1] = 1; // on
DevEnable [2] = 1; // mlc_dev
while (ioctl (fb_fd, FBIO_DIRTFLAG, DevEnable)) usleep (10);
}

//------------------------------------------------ ------------------------------
void GLESOAL_SetDisplayAddress (const unsigned int DisplayBufferPhysicalAddress)
{
if (! g_FSAAEnb) {return;}
// @ Todo: FSAA implementation
}

//------------------------------------------------ ------------------------------
void GLESOAL_Sleep (unsigned long Milliseconds)
{
Milliseconds *= 1000;
if (Milliseconds == 0)
Milliseconds = 1;
usleep (Milliseconds);
}
