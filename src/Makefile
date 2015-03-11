# Course: Object Oriented Programming
# Practical 9
# Author: Ravi Hammond
# Student ID: 1672048
# Description: Makefile for Border Class Example

all: Assignment.o Border.o Dobstacle.o Gobstacle.o Game.o Gradient.o Obstacle.o Player.o Slider.o Textblock.o Textline.o Trail.o Powerup.o Invincible.o Multiplier.o Points.o Highscorelist.o Score.o Shield.o
	g++ Assignment.o Border.o Dobstacle.o Gobstacle.o Game.o Gradient.o Obstacle.o Player.o Slider.o Textblock.o Textline.o Trail.o Powerup.o Invincible.o Multiplier.o Points.o Highscorelist.o Score.o Shield.o -o assignment -lncurses -pthread

install: all
	mv assignment ../installed

Assignment.o: Assignment.cpp
	g++ -c Assignment.cpp -o Assignment.o

Score.o: Score.cpp Score.h
	g++ -c Score.cpp -o Score.o

Highscorelist.o: Highscorelist.cpp Highscorelist.h
	g++ -c Highscorelist.cpp -o Highscorelist.o

Shield.o: Shield.cpp Shield.h
	g++ -c Shield.cpp -o Shield.o

Multiplier.o: Multiplier.cpp Multiplier.h
	g++ -c Multiplier.cpp -o Multiplier.o

Points.o: Points.cpp Points.h
	g++ -c Points.cpp -o Points.o

Invincible.o: Invincible.cpp Invincible.h
	g++ -c Invincible.cpp -o Invincible.o

Powerup.o: Powerup.cpp Border.h
	g++ -c Powerup.cpp -o Powerup.o

Border.o: Border.cpp Border.h
	g++ -c Border.cpp -o Border.o

Gobstacle.o: Gobstacle.cpp Gobstacle.h
	g++ -c Gobstacle.cpp -o Gobstacle.o

Dobstacle.o: Dobstacle.cpp Dobstacle.h
	g++ -c Dobstacle.cpp -o Dobstacle.o

Game.o: Game.cpp Game.h
	g++ -c Game.cpp -o Game.o

Gradient.o: Gradient.cpp Gradient.h
	g++ -c Gradient.cpp -o Gradient.o

Obstacle.o: Obstacle.cpp Obstacle.h
	g++ -c Obstacle.cpp -o Obstacle.o

Player.o: Player.cpp Player.h
	g++ -c Player.cpp -o Player.o

Slider.o: Slider.cpp Slider.h
	g++ -c Slider.cpp -o Slider.o

Textblock.o: Textblock.cpp Textblock.h
	g++ -c Textblock.cpp -o Textblock.o

Textline.o: Textline.cpp Textline.h
	g++ -c Textline.cpp -o Textline.o

Trail.o: Trail.cpp Trail.h
	g++ -c Trail.cpp -o Trail.o

clean:
	rm -f *.o assignment