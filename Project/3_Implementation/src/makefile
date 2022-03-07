#Main application file name
MAIN_APP = Smart_Vacuum_cleaner
#Main hex file path in windows format
MAIN_HEX_PATH = E:\Ajii mobile\l&T\M2\M2_EmbSys\Project\3_Implementation\src\SVC.ino\$(MAIN_APP).hex


ifdef OS
   RM = del /q
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	  EXEC = out
   endif
endif

# Compiler and other Section
CC = avr-gcc
OBJCOPY = avr-objcopy.exe

#Options for avr-gcc
CFLAGS = -g -Os -o

#Linking options for avr-gcc
LFLAGS = -Os -mmcu=atmega8 -o

#Options for HEX file generation
HFLAGS = -j .text -j .data -O ihex

# Sources files needed for building the application 
SRC = src/$(MAIN_APP).c	src/SVC.ino


# The headers files needed for building the application
INCLUDE = -I. 


# commands Section
Burn : Build
	$(AVRDUDE) $(DUDEFLAGS)

Build : $(MAIN_APP).elf
	$(OBJCOPY) $(HFLAGS) $< $(MAIN_APP).hex
	
$(MAIN_APP).elf: $(MAIN_APP).o
	$(CC) $(SRC) $(INCLUDE) $(LFLAGS) $@
	
$(MAIN_APP).o:$(SRC)
	$(CC) $^ $(INCLUDE) $(CFLAGS) $@