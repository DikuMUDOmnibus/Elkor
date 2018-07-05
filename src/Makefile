CC      = gcc
NOCRYPT =
DBUGFLG = -DREQUESTS
C_FLAGS = $(OPT_FLAG) -O -g3 -Wall -Wuninitialized $(PROF) $(NOCRYPT) $(DBUGFLG) -DSMAUG $(SOLARIS_FLAG)
L_FLAGS = $(OPT_FLAG) $(PROF) $(SOLARIS_LINK) $(NEED_CRYPT)

C_FILES = act_comm.c comm.c handler.c magic.c special.c \
	act_info.c const.c interp.c monk.c update.c \
	act_move.c db.c kav_fight.c ninja.c \
	act_obj.c demon.c kav_info.c rot_wiz.c wizutil.c \
	act_wiz.c drow.c kav_wiz.c \
	clan.c fight.c mage.c save.c vic.c

O_FILES = act_comm.o comm.o  handler.o   magic.o    special.o \
	act_info.o const.o interp.o    monk.o    update.o \
	act_move.o db.o    kav_fight.o ninja.o \
	act_obj.o  demon.o kav_info.o  rot_wiz.o wizutil.o \
	act_wiz.o  drow.o  kav_wiz.o    clan.o \
	fight.o    mage.o  save.o vic.o

H_FILES = merc.h player.h 

all:
	make merc

merc: $(O_FILES)
	rm -f merc
	$(CC) $(L_FLAGS) -o merc $(O_FILES)
	chmod g+w $(O_FILES)

.c.o: merc.h
	$(CC) -c $(C_FLAGS) $<

