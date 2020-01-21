#system, window, graphics, network and audio
SYSTEM := -lsfml-system
WINDOW := -lsfml-window
GRAFICS := -lsfml-graphics
NETWORK := -lsfml-network
AUDIO := -lsfml-audio

#link all
LINK_SFML = $(SYSTEM) $(WINDOW) $(GRAFICS) $(NETWORK) $(AUDIO)

#cartelle progetto
H = ./header/
S = ./src/
U = ./utils/
O = ./output/

#comando per compilare
CC = g++
LINK = g++
CFLAGS = -c -std=c++11
COMPILE = $(CC) $(CFLAGS)

#insieme di oggetti che vogliono essere lanciati (chiamati da main)
OBJ = $(O)utils.o $(O)Punto.o $(O)ColoreRGB.o $(O)Button.o \
	$(O)Faccia.o $(O)Cubo.o $(O)visualeMenu.o $(O)visualeCubo.o \
	$(O)Gioco.o $(O)main.o

all: app
#lancia l'app in automatico
	./$<

#cose per gestire oggetti di base
$(O)utils.o: $(U)utils.cpp $(H)utils.hpp
	$(COMPILE) $(U)utils.cpp -o $(O)utils.o

$(O)Punto.o: $(U)Punto.cpp $(H)Punto.hpp
	$(COMPILE) $(U)Punto.cpp -o $(O)Punto.o

$(O)ColoreRGB.o: $(U)ColoreRGB.cpp $(H)ColoreRGB.hpp
	$(COMPILE) $(U)ColoreRGB.cpp -o $(O)ColoreRGB.o

$(O)Button.o: $(U)Button.cpp $(H)Button.hpp
	$(COMPILE) $(U)Button.cpp -o $(O)Button.o

# cose per gestire visuali
$(O)Faccia.o: $(S)Faccia.cpp $(H)Faccia.hpp
	$(COMPILE) $(S)Faccia.cpp -o $(O)Faccia.o

$(O)Cubo.o: $(S)Cubo.cpp $(H)Cubo.hpp
	$(COMPILE) $(S)Cubo.cpp -o $(O)Cubo.o

$(O)visualeMenu.o: $(U)visualeMenu.cpp $(H)visualeMenu.hpp
	$(COMPILE) $(U)visualeMenu.cpp -o $(O)visualeMenu.o

$(O)visualeCubo.o: $(S)visualeCubo.cpp $(H)visualeCubo.hpp
	$(COMPILE) $(S)visualeCubo.cpp -o $(O)visualeCubo.o

$(O)Gioco.o: $(S)Gioco.cpp $(H)Gioco.hpp
	$(COMPILE) $(S)Gioco.cpp -o $(O)Gioco.o

$(O)main.o: $(U)main.cpp $(H)Gioco.hpp
	$(COMPILE) $(U)main.cpp -o $(O)main.o

#link all into an executable
app: $(OBJ)
#	linkiamo tutti gli object e la grafica SFML
	$(LINK) $(OBJ) -o app $(LINK_SFML)

#clean target
.PHONY: clean

clean:
	rm -rf $(O)*.o app $(S)*.o
