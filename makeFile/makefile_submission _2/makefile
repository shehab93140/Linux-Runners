SHELL=cmd
FCPU = 16000000           # clock  
SRCS = $(wildcard *.c)    # variable which contain all the c files 
OBJS=${SRCS:%.c=%.o}     #replace  all  files.c to files.o
DEPS=${SRCS:%.c=%.d}	 #replace  all  files.c to files.d
TARGET=application.exe
HEX=${TARGET:%.exe=%.hex}	#replace  files.exe to files.hex
MAPS=${TARGET:%.exe=%.map}	#replace  files.exe to files.map
BINS=${TARGET:%.exe=%.bin}	#replace  files.exe to files.bin
CC = avr-gcc                 #compiler name 
CP = gcc
CFLAGS = -Wall -c        #activate the warning flag 
DFLAGS = -MMD -MF  ${@:%.o=%.d}  # to generate the dependencies file   and replace $@ --> main.o  to main.d 

all: ${TARGET}          

${TARGET}: ${OBJS}               #like main.o:main.c  // # gcc main.c -o main.o
	${CP} ${OBJS} -o ${TARGET}

${TARGET}: ${SRCS}               #like main.o:main.c  // # gcc main.c -o main.o 
	$(CC) -Wall -Os -std=c99 -D F_CPU=$(FCPU) -mmcu=atmega32 $(SRCS) -o $(BINS) -Xlinker -Map=$(MAPS)
	avr-objcopy -j .text -j .data -O ihex $(BINS) $(HEX)
	avr-size -B $(BINS)

%.o:%.c                                # //static pattern rule $<   -->  main.c    $@   --> main.o // and display warning and dependencies 
	${CC} ${CFLAGS} $< -o $@ ${DFLAGS} 
flash: $(HEX)
	avrdude -p atmega32 -c usbasp -U flash:w:$(HEX):i -F -P usb
clean: 
	del ${TARGET} ${OBJS} ${DEPS}  ${MAPS} ${BINS} ${HEX}
-include ${DEPS}
