OPTS = -Wall -O2

all: CasualMockSkirmish

CasualMockSkirmish: print.o skirmish.o start.o user_input.o warrior.o warrior/bandit.o warrior/basilisk.o warrior/dragon.o warrior/dwarf.o warrior/ghost.o warrior/goblin.o warrior/grunt.o warrior/knight.o warrior/mammoth.o warrior/ogre.o warrior/serpent.o warrior/snowman.o warrior/sorcerer.o warrior/troll.o warrior/witch.o warrior/wolf.o
	g++ $? -o CasualMockSkirmish
	strip CasualMockSkirmish

print.o:
	g++ ${OPTS} -c print.cpp

skirmish.o:
	g++ ${OPTS} -c skirmish.cpp

start.o:
	g++ ${OPTS} -c start.cpp

user_input.o:
	g++ ${OPTS} -c user_input.cpp

warrior.o:
	g++ ${OPTS} -c warrior.cpp

warrior/bandit.o:
	g++ ${OPTS} -c warrior/bandit.cpp -o $@

warrior/basilisk.o:
	g++ ${OPTS} -c warrior/basilisk.cpp -o $@

warrior/dragon.o:
	g++ ${OPTS} -c warrior/dragon.cpp -o $@

warrior/dwarf.o:
	g++ ${OPTS} -c warrior/dwarf.cpp -o $@

warrior/ghost.o:
	g++ ${OPTS} -c warrior/ghost.cpp -o $@

warrior/goblin.o:
	g++ ${OPTS} -c warrior/goblin.cpp -o $@

warrior/grunt.o:
	g++ ${OPTS} -c warrior/grunt.cpp -o $@

warrior/knight.o:
	g++ ${OPTS} -c warrior/knight.cpp -o $@

warrior/mammoth.o:
	g++ ${OPTS} -c warrior/mammoth.cpp -o $@

warrior/ogre.o:
	g++ ${OPTS} -c warrior/ogre.cpp -o $@

warrior/serpent.o:
	g++ ${OPTS} -c warrior/serpent.cpp -o $@

warrior/snowman.o:
	g++ ${OPTS} -c warrior/snowman.cpp -o $@

warrior/sorcerer.o:
	g++ ${OPTS} -c warrior/sorcerer.cpp -o $@

warrior/troll.o:
	g++ ${OPTS} -c warrior/troll.cpp -o $@

warrior/witch.o:
	g++ ${OPTS} -c warrior/witch.cpp -o $@

warrior/wolf.o:
	g++ ${OPTS} -c warrior/wolf.cpp -o $@

clean:
	rm CasualMockSkirmish print.o skirmish.o start.o user_input.o warrior.o warrior/dragon.o warrior/dwarf.o warrior/goblin.o warrior/grunt.o warrior/knight.o warrior/mammoth.o warrior/ogre.o warrior/sorcerer.o warrior/troll.o warrior/wolf.o
