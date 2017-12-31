playGame: playGame.cpp GoldMine.o Box.o
	g++ Box.o GoldMine.o playGame.cpp -o playGame
GoldMine.o: Box.o GoldMine.cpp
	g++ -c GoldMine.cpp
Box.o: Box.cpp
	g++ -c Box.cpp
clean:
	rm -rf playGame *o