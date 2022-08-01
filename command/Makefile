# commands/Makefile

#ENTRYPOINT	= 0x1000
HD		= ../80m.img

ASM		= nasm
DASM		= objdump
CC		= gcc
LD		= ld
ASMFLAGS	= -I ../include/ -f elf
CFLAGS		= -I ../include/ -c -fno-builtin -fno-stack-protector -Wall
MYCFLAGS	= -I ../include/ -I ../include/sys -c -fno-builtin -fno-stack-protector -Wall
LDFLAGS		= -Ttext 0x1000
DASMFLAGS	= -D
LIB		= ../lib/orangescrt.a
BIN		= 2048 caculator print pwd saolei mytest hannoi mergeten

# All Phony Targets
.PHONY : everything final clean realclean disasm all install

# Default starting position
everything : $(BIN)

install : all clean
	cp ../kernel.bin ./ -v
	#tar vcf inst.tar kernel.bin $(BIN) print
	#dd if=inst.tar of=$(HD) seek=`echo "obase=10;ibase=16;(\`egrep -e '^ROOT_BASE' ../boot/include/load.inc | sed -e 's/.*0x//g'\`+\`egrep -e '#define[[:space:]]*INSTALL_START_SECT' ../include/sys/config.h | sed -e 's/.*0x//g'\`)*200" | bc` bs=1 count=`ls -l inst.tar | awk -F " " '{print $$5}'` conv=notrunc

all : realclean everything laststep

final : all clean

clean :
	rm -f *.o

realclean :
	rm -f $(BIN) print *.o

kernel.bin :
	cp ../kernel.bin ./

start.o : start.asm
	$(ASM) $(ASMFLAGS) -o $@ $<

caculator.o: caculator.c ../include/type.h ../include/stdio.h
	$(CC) $(CFLAGS) -o $@ $<

caculator : caculator.o start.o $(LIB)
	$(LD) $(LDFLAGS) -o $@ $?

pwd.o: pwd.c ../include/type.h ../include/stdio.h
	$(CC) $(CFLAGS) -o $@ $<

pwd : pwd.o start.o $(LIB)
	$(LD) $(LDFLAGS) -o $@ $?

print.o : print.c ../include/type.h ../include/stdio.h
	$(CC) $(CFLAGS) -o $@ $<

print : print.o start.o $(LIB)
	$(LD) $(LDFLAGS) -o $@ $?

2048.o : 2048.c ../include/type.h ../include/stdio.h
	$(CC) $(CFLAGS) -o $@ $<

2048 : 2048.o start.o $(LIB)
	$(LD) $(LDFLAGS) -o $@ $?

saolei.o : saolei.c ../include/type.h ../include/stdio.h
	$(CC) $(CFLAGS) -o $@ $<

saolei : saolei.o start.o $(LIB)
	$(LD) $(LDFLAGS) -o $@ $?

mytest.o : mytest.c ../include/type.h ../include/stdio.h
	$(CC) $(MYCFLAGS) -o $@ $<

mytest : mytest.o start.o $(LIB)
	$(LD) $(LDFLAGS) -o $@ $?

hannoi.o : hannoi.c ../include/type.h ../include/stdio.h
	$(CC) $(CFLAGS) -o $@ $<

hannoi : hannoi.o start.o $(LIB)
	$(LD) $(LDFLAGS) -o $@ $?

mergeten.o : mergeten.c ../include/type.h ../include/stdio.h
	$(CC) $(CFLAGS) -o $@ $<

mergeten : mergeten.o start.o $(LIB)
	$(LD) $(LDFLAGS) -o $@ $?

laststep : 
	tar vcf inst.tar kernel.bin caculator print 2048 saolei mytest hannoi mergeten
	dd if=inst.tar of=$(HD) seek=`echo "obase=10;ibase=16;(\`egrep -e '^ROOT_BASE' ../boot/include/load.inc | sed -e 's/.*0x//g'\`+\`egrep -e '#define[[:space:]]*INSTALL_START_SECT' ../include/sys/config.h | sed -e 's/.*0x//g'\`)*200" | bc` bs=1 count=`ls -l inst.tar | awk -F " " '{print $$5}'` conv=notrunc

