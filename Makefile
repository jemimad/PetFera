#Pastas
INC = ./include
SRC = ./src
OBJ = ./obj
BIN = ./bin

#Variáveis 
CC = g++ 
CFLAGS = -O0 -Wall -std=c++11 -I$(INC)

OBJECTS = $(OBJ)/animalSilvestre.o $(OBJ)/funcionario.o $(OBJ)/main.o $(OBJ)/anfibio.o $(OBJ)/anfibioDomestico.o $(OBJ)/anfibioExotico.o $(OBJ)/anfibioNativo.o $(OBJ)/animal.o $(OBJ)/animalExotico.o
        $(OBJ)/animalNativo.o $(OBJ)/ave.o $(OBJ)/aveDomestico.o $(OBJ)/aveExotico.o $(OBJ)/aveNativo.o $(OBJ)/controlador.o $(OBJ)/mamifero.o $(OBJ)/mamiferoDomestico.o $(OBJ)/mamiferoExotico.o
        $(OBJ)/mamiferoNativo.o $(OBJ)/menu.o $(OBJ)/reptil.o $(OBJ)/reptilDomestico.o $(OBJ)/reptilExotico.o $(OBJ)/reptilNativo.o $(OBJ)/tratador.o $(OBJ)/veterinario.o

PROG = $(BIN)/petfera

all: $(OBJECTS) $(BIN)/petfera
        $(CC) $(CFLAGS) -o $(PROG) $(OBJECTS)

$(OBJ)/animalSilvestre.o: $(INC)/animalSilvestre.h
        $(CC) $(CFLAGS) -c $(SRC)/animalSilvestre.cpp -o $@

$(OBJ)/funcionario.o: $(INC)/funcionario.h
        $(CC) $(CFLAGS) -c $(SRC)/funcionario.cpp -o $@ 

$(OBJ)/main.o: $(INC)/main.cpp
        $(CC) $(CFLAGS) -c $(SRC)/main.cpp -o $@   

$(OBJ)/anfibio.o: $(INC)/anfibio.h
        $(CC) $(CFLAGS) -c $(SRC)/anfibio.cpp -o $@

$(OBJ)/anfibioDomestico.o: $(INC)/anfibioDomestico.h
        $(CC) $(CFLAGS) -c $(SRC)/anfibioDomestico.cpp -o $@

$(OBJ)/anfibioExotico.o: $(INC)/anfibioExotico.h
        $(CC) $(CFLAGS) -c $(SRC)/anfibioExotico.cpp -o $@

$(OBJ)/anfibioNativo.o: $(INC)/anfibioNativo.h
        $(CC) $(CFLAGS) -c $(SRC)/anfibioNativo.cpp -o $@

$(OBJ)/animal.o: $(INC)/animal.h
        $(CC) $(CFLAGS) -c $(SRC)/animal.cpp -o $@      

$(OBJ)/animalExotico.o: $(INC)/animalExotico.h
        $(CC) $(CFLAGS) -c $(SRC)/animalExotico.cpp -o $@

$(OBJ)/animalNativo.o: $(INC)/animalNativo.h
        $(CC) $(CFLAGS) -c $(SRC)/animalNativo.cpp -o $@

$(OBJ)/ave.o: $(INC)/ave.h
        $(CC) $(CFLAGS) -c $(SRC)/ave.cpp -o $@

$(OBJ)/aveDomestico.o: $(INC)/aveDomestico.h
        $(CC) $(CFLAGS) -c $(SRC)/aveDomestico -o $@

$(OBJ)/aveExotico.o: $(INC)/aveExotico.h
        $(CC) $(CFLAGS) -c $(SRC)/aveExotico-o $@

$(OBJ)/aveNativo.o: $(INC)/aveNativo.h
        $(CC) $(CFLAGS) -c $(SRC)/aveNativo -o $@

$(OBJ)/controlador.o: $(INC)/controlador.h
        $(CC) $(CFLAGS) -c $(SRC)/controlador.cpp -o $@

$(OBJ)/funcionario.o: $(INC)/funcionario.h
        $(CC) $(CFLAGS) -c $(SRC)/funcionario -o $@

$(OBJ)/mamifero.o: $(INC)/mamifero.h
        $(CC) $(CFLAGS) -c $(SRC)/mamifero.cpp -o $@

$(OBJ)/mamiferoDomestico.o: $(INC)/mamiferoDomestico.h
        $(CC) $(CFLAGS) -c $(SRC)/mamiferoDomestico.cpp -o $@

$(OBJ)/mamiferoExotico.o: $(INC)/mamiferoExotico.h
        $(CC) $(CFLAGS) -c $(SRC)/mamiferoExotico.cpp -o $@

$(OBJ)/mamiferoNativo.o: $(INC)/mamiferoNativo.h
        $(CC) $(CFLAGS) -c $(SRC)/mamiferoNativo.cpp -o $@

$(OBJ)/menu.o: $(INC)/menu.h
        $(CC) $(CFLAGS) -c $(SRC)/menu.cpp -o $@

$(OBJ)/reptil.o: $(INC)/reptil.h
        $(CC) $(CFLAGS) -c $(SRC)/reptil.cpp -o $@

$(OBJ)/reptilDomestico.o: $(INC)/reptilDomestico.h
        $(CC) $(CFLAGS) -c $(SRC)/reptilDomestico.cpp -o $@

$(OBJ)/reptilExotico.o: $(INC)/reptilExotico.h
        $(CC) $(CFLAGS) -c $(SRC)/reptilExotico.cpp -o $@

$(OBJ)/reptilNativo.o: $(INC)/reptilNativo.h
        $(CC) $(CFLAGS) -c $(SRC)/reptilNativo.cpp -o $@

$(OBJ)/tratador.o: $(INC)/tratador.h
        $(CC) $(CFLAGS) -c $(SRC)/tratador.cpp -o $@

$(OBJ)/veterinario.o: $(INC)/veterinario.h
        $(CC) $(CFLAGS) -c $(SRC)/veterinario.cpp -o $@

clean:
        rm -f $(PROG) $(OBJECTS)

