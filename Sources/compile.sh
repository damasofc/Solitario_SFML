g++ -c main.cpp game.cpp carta.cpp as.cpp tabla.cpp tablanormal.cpp mazo.cpp
g++ main.o game.o tabla.o tablanormal.o carta.o as.o mazo.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
rm -rf *.o
./sfml-app