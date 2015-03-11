all: Test.o Border.o Dobstacle.o Gobstacle.o Game.o Gradient.o Obstacle.o Player.o Slider.o Textblock.o Textline.o Trail.o Powerup.o Invincible.o Multiplier.o Points.o Highscorelist.o Score.o Shield.o
	g++ Test.o Border.o Dobstacle.o Gobstacle.o Game.o Gradient.o Obstacle.o Player.o Slider.o Textblock.o Textline.o Trail.o Powerup.o Invincible.o Multiplier.o Points.o Highscorelist.o Score.o Shield.o -o test -lncurses -pthread

install: all
	mv test ../installed

Test.o: Test.cpp
	g++ -c Test.cpp -o Test.o

Score.o: ../src/Score.cpp ../src/Score.h
	g++ -c ../src/Score.cpp -o Score.o

Highscorelist.o: ../src/Highscorelist.cpp ../src/Highscorelist.h
	g++ -c ../src/Highscorelist.cpp -o Highscorelist.o

Shield.o: ../src/Shield.cpp ../src/Shield.h
	g++ -c ../src/Shield.cpp -o Shield.o

Multiplier.o: ../src/Multiplier.cpp ../src/Multiplier.h
	g++ -c ../src/Multiplier.cpp -o Multiplier.o

Points.o: ../src/Points.cpp ../src/Points.h
	g++ -c ../src/Points.cpp -o Points.o

Invincible.o: ../src/Invincible.cpp ../src/Invincible.h
	g++ -c ../src/Invincible.cpp -o Invincible.o

Powerup.o: ../src/Powerup.cpp ../src/Border.h
	g++ -c ../src/Powerup.cpp -o Powerup.o

Border.o: ../src/Border.cpp ../src/Border.h
	g++ -c ../src/Border.cpp -o Border.o

Gobstacle.o: ../src/Gobstacle.cpp ../src/Gobstacle.h
	g++ -c ../src/Gobstacle.cpp -o Gobstacle.o

Dobstacle.o: ../src/Dobstacle.cpp ../src/Dobstacle.h
	g++ -c ../src/Dobstacle.cpp -o Dobstacle.o

Game.o: ../src/Game.cpp ../src/Game.h
	g++ -c ../src/Game.cpp -o Game.o

Gradient.o: ../src/Gradient.cpp ../src/Gradient.h
	g++ -c ../src/Gradient.cpp -o Gradient.o

Obstacle.o: ../src/Obstacle.cpp ../src/Obstacle.h
	g++ -c ../src/Obstacle.cpp -o Obstacle.o

Player.o: ../src/Player.cpp ../src/Player.h
	g++ -c ../src/Player.cpp -o Player.o

Slider.o: ../src/Slider.cpp ../src/Slider.h
	g++ -c ../src/Slider.cpp -o Slider.o

Textblock.o: ../src/Textblock.cpp ../src/Textblock.h
	g++ -c ../src/Textblock.cpp -o Textblock.o

Textline.o: ../src/Textline.cpp ../src/Textline.h
	g++ -c ../src/Textline.cpp -o Textline.o

Trail.o: ../src/Trail.cpp ../src/Trail.h
	g++ -c ../src/Trail.cpp -o Trail.o

clean:
	rm -f *.o test