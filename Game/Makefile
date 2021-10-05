OPTS = -Wall -O2

all: CasualMockSkirmish

CasualMockSkirmish: dragon.o dwarf.o goblin.o grunt.o knight.o mammoth.o ogre.o print.o skirmish.o sorcerer.o start.o troll.o user_input.o warrior.o wolf.o
    g++ dragon.o dwarf.o goblin.o grunt.o knight.o mammoth.o ogre.o print.o skirmish.o sorcerer.o start.o troll.o user_input.o warrior.o wolf.o -o CasualMockSkirmish
	strip CasualMockSkirmish

dragon.o:
	g++ ${OPTS} -c dragon.cpp

dwarf.o:
	g++ ${OPTS} -c dwarf.cpp

goblin.o:
	g++ ${OPTS} -c goblin.cpp

grunt.o:
	g++ ${OPTS} -c grunt.cpp

knight.o:
	g++ ${OPTS} -c knight.cpp

mammoth.o:
	g++ ${OPTS} -c mammoth.cpp

ogre.o:
	g++ ${OPTS} -c ogre.cpp

print.o:
	g++ ${OPTS} -c print.cpp

skirmish.o:
	g++ ${OPTS} -c skirmish.cpp

sorcerer.o:
    g++ ${OPTS} -c sorcerer.cpp

start.o:
	g++ ${OPTS} -c start.cpp

troll.o:
	g++ ${OPTS} -c troll.cpp

user_input.o:
	g++ ${OPTS} -c user_input.cpp

warrior.o:
	g++ ${OPTS} -c warrior.cpp

wolf.o:
	g++ ${OPTS} -c wolf.cpp

clean:
    rm CasualMockSkirmish dragon.o dwarf.o goblin.o grunt.o knight.o mammoth.o ogre.o print.o skirmish.o sorcerer.o start.o troll.o user_input.o warrior.o wolf.o

