DIR_FONTS = ./Fonts
DIR_SRC = ./src
DIR_OBJ = ./obj

OBJ_C = $(wildcard ${DIR_FONTS}/*.c ${DIR_SRC}/*.c)
OBJ_O = $(patsubst %.c,${DIR_OBJ}/%.o,$(notdir ${OBJ_C}))

TARGET = main
#BIN_TARGET = ${DIR_OBJ}/${TARGET}

CC = gcc

DEBUG = -g -O0 -Wall
CFLAGS += $(DEBUG)

USELIB = USE_BCM2835_LIB
# USELIB = USE_WIRINGPI_LIB
# USELIB = USE_DEV_LIB
DEBUG = -D $(USELIB)
ifeq ($(USELIB), USE_BCM2835_LIB)
    LIB = -lbcm2835 -lm 
else ifeq ($(USELIB), USE_WIRINGPI_LIB)
    LIB = -lwiringPi -lm 
endif

${TARGET}:${OBJ_O}
	$(CC) $(CFLAGS) $(OBJ_O) -o $@ $(LIB)

${DIR_OBJ}/%.o : $(DIR_SRC)/%.c
	$(CC) $(CFLAGS) -c  $< -o $@ $(LIB)

${DIR_OBJ}/%.o:$(DIR_FONTS)/%.c
	$(CC) $(CFLAGS) -c  $< -o $@ 
	
clean :
	rm $(DIR_OBJ)/*.* 
	rm $(TARGET) 
