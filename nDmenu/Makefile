TARGET = 2DTutorial
OBJS = DGE_Entry.o

# for cygwin
# CROSS_COMPILE = arm-linux-

CC = $(CROSS_COMPILE)gcc
CPP = $(CROSS_COMPILE)g++
SDK_HOME = C:/GPH_SDK

ifeq ($(CROSS_COMPILE),arm-linux-)
BIN = .target/$(TARGET).gpe
INCS = -I$(SDK_HOME)/DGE/include -I$(SDK_HOME)/DGE/include/SDL -I$(SDK_HOME)/include
CFLAGS = -Wall -O3 -fexceptions -fomit-frame-pointer -fPIC
LIBS = -L$(SDK_HOME)/DGE/lib/target -L$(SDK_HOME)/lib/target \
		-lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lDGE -lglport -lopengles_lite -lpng -lz -lts -lsmpeg –lfreetype
LFLAGS = -s
else
BIN = .host/$(TARGET).exe
INCS = -I$(SDK_HOME)/DGE/include -I$(SDK_HOME)/DGE/include/SDL -I$(SDK_HOME)/include
CFLAGS = -g -Wall -fexceptions
LIBS = -L$(SDK_HOME)/DGE/lib/host -L$(SDK_HOME)/lib/host \
		-lmingw32 -lDGE -lopengl32 -lSDLmain -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
endif


.c.o:
	$(CC) $(INCS) $(CFLAGS) -c $< -o $@


.cpp.o:
	$(CPP) $(INCS) $(CFLAGS) -c $< -o $@


$(BIN): $(OBJS)
	$(CPP) $(OBJS) -o $@ $(LIBS) $(LFLAGS)


all host target: $(BIN)

clean cleanhost cleantarget:
	f $(OBJS) $(BIN)
