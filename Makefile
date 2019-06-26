PROG = PetFera
CC = g++
CPPFLAGS = -O0 -g -Wall -std=c++11 -I./include

SRC = ./src
INC = ./include
BIN = ./bin
OBJ = ./obj
# LDFLAGS = -Lsrc -lmylib
all: mkdirs $(PROG)

mkdirs:
	@mkdir -p $(OBJ)
	@mkdir -p $(BIN)

OBJS = $(OBJ)/anfibio.o $(OBJ)/anfibioExotico.o $(OBJ)/anfibioNativo.o $(OBJ)/animal.o $(OBJ)/animalExotico.o $(OBJ)/animalNativo.o $(OBJ)/animalSilvestre.o $(OBJ)/ave.o $(OBJ)/aveExotico.o $(OBJ)/aveNativo.o $(OBJ)/funcionario.o $(OBJ)/main.o $(OBJ)/mamifero.o $(OBJ)/mamiferoExotico.o $(OBJ)/mamiferoNativo.o $(OBJ)/reptil.o $(OBJ)/reptilExotico.o $(OBJ)/reptilNativo.o $(OBJ)/controlador.o $(OBJ)/tratador.o $(OBJ)/veterinario.o $(OBJ)/anfibioDomestico.o $(OBJ)/aveDomestico.o $(OBJ)/mamiferoDomestico.o $(OBJ)/reptilDomestico.o

$(PROG) : $(OBJS)
	@$(CC) $(CPPFLAGS) -o $(PROG) $(OBJS)

$(OBJ)/anfibio.o : $(SRC)/anfibio.cpp $(INC)/anfibio.h
	@$(CC) $(CPPFLAGS) -c $(SRC)/anfibio.cpp -o $(OBJ)/anfibio.o

$(OBJ)/anfibioExotico.o : $(SRC)/anfibioExotico.cpp $(INC)/anfibioExotico.h
	@$(CC) $(CPPFLAGS) -c $(SRC)/anfibioExotico.cpp -o $(OBJ)/anfibioExotico.o

$(OBJ)/anfibioNativo.o : $(SRC)/anfibioNativo.cpp $(INC)/anfibioNativo.h
	@$(CC) $(CPPFLAGS) -c $(SRC)/anfibioNativo.cpp -o $(OBJ)/anfibioNativo.o

$(OBJ)/animal.o : $(SRC)/animal.cpp $(INC)/animal.h
	@$(CC) $(CPPFLAGS) -c $(SRC)/animal.cpp -o $(OBJ)/animal.o

$(OBJ)/animalExotico.o : $(SRC)/animalExotico.cpp $(INC)/animalExotico.h
	@$(CC) $(CPPFLAGS) -c $(SRC)/animalExotico.cpp -o $(OBJ)/animalExotico.o

$(OBJ)/animalNativo.o : $(SRC)/animalNativo.cpp $(INC)/animalNativo.h
	@$(CC) $(CPPFLAGS) -c $(SRC)/animalNativo.cpp -o $(OBJ)/animalNativo.o

$(OBJ)/animalSilvestre.o : $(SRC)/animalSilvestre.cpp $(INC)/animalSilvestre.h
	@$(CC) $(CPPFLAGS) -c $(SRC)/animalSilvestre.cpp -o $(OBJ)/animalSilvestre.o

$(OBJ)/ave.o : $(SRC)/ave.cpp $(INC)/ave.h
	@$(CC) $(CPPFLAGS) -c $(SRC)/ave.cpp -o $(OBJ)/ave.o

$(OBJ)/aveExotico.o : $(SRC)/aveExotico.cpp $(INC)/aveExotico.h
	@$(CC) $(CPPFLAGS) -c $(SRC)/aveExotico.cpp -o $(OBJ)/aveExotico.o

$(OBJ)/aveNativo.o : $(SRC)/aveNativo.cpp $(INC)/aveNativo.h
	@$(CC) $(CPPFLAGS) -c $(SRC)/aveNativo.cpp -o $(OBJ)/aveNativo.o

$(OBJ)/funcionario.o : $(SRC)/funcionario.cpp $(INC)/funcionario.h
	@$(CC) $(CPPFLAGS) -c $(SRC)/funcionario.cpp -o $(OBJ)/funcionario.o

$(OBJ)/main.o : $(SRC)/main.cpp $(INC)/menu.h
	@$(CC) $(CPPFLAGS) -c $(SRC)/main.cpp -o $(OBJ)/main.o

$(OBJ)/mamifero.o : $(SRC)/mamifero.cpp $(INC)/mamifero.h
	@$(CC) $(CPPFLAGS) -c $(SRC)/mamifero.cpp -o $(OBJ)/mamifero.o

$(OBJ)/mamiferoExotico.o : $(SRC)/mamiferoExotico.cpp $(INC)/mamiferoExotico.h
	@$(CC) $(CPPFLAGS) -c $(SRC)/mamiferoExotico.cpp -o $(OBJ)/mamiferoExotico.o

$(OBJ)/mamiferoNativo.o : $(SRC)/mamiferoNativo.cpp $(INC)/mamiferoNativo.h
	@$(CC) $(CPPFLAGS) -c $(SRC)/mamiferoNativo.cpp -o $(OBJ)/mamiferoNativo.o

$(OBJ)/reptil.o : $(SRC)/reptil.cpp $(INC)/reptil.h
	@$(CC) $(CPPFLAGS) -c $(SRC)/reptil.cpp -o $(OBJ)/reptil.o

$(OBJ)/reptilExotico.o : $(SRC)/reptilExotico.cpp $(INC)/reptilExotico.h
	@$(CC) $(CPPFLAGS) -c $(SRC)/reptilExotico.cpp -o $(OBJ)/reptilExotico.o

$(OBJ)/reptilNativo.o : $(SRC)/reptilNativo.cpp $(INC)/reptilNativo.h
	@$(CC) $(CPPFLAGS) -c $(SRC)/reptilNativo.cpp -o $(OBJ)/reptilNativo.o

$(OBJ)/controlador.o : $(SRC)/controlador.cpp $(INC)/controlador.h
	@$(CC) $(CPPFLAGS) -c $(SRC)/controlador.cpp -o $(OBJ)/controlador.o

$(OBJ)/tratador.o : $(SRC)/tratador.cpp $(INC)/tratador.h
	@$(CC) $(CPPFLAGS) -c $(SRC)/tratador.cpp -o $(OBJ)/tratador.o

$(OBJ)/veterinario.o : $(SRC)/veterinario.cpp $(INC)/veterinario.h
	@$(CC) $(CPPFLAGS) -c $(SRC)/veterinario.cpp -o $(OBJ)/veterinario.o

$(OBJ)/anfibioDomestico.o : $(SRC)/anfibioDomestico.cpp $(INC)/anfibioDomestico.h
	@$(CC) $(CPPFLAGS) -c $(SRC)/anfibioDomestico.cpp -o $(OBJ)/anfibioDomestico.o

$(OBJ)/aveDomestico.o : $(SRC)/aveDomestico.cpp $(INC)/aveDomestico.h
	@$(CC) $(CPPFLAGS) -c $(SRC)/aveDomestico.cpp -o $(OBJ)/aveDomestico.o

$(OBJ)/mamiferoDomestico.o : $(SRC)/mamiferoDomestico.cpp $(INC)/mamiferoDomestico.h
	@$(CC) $(CPPFLAGS) -c $(SRC)/mamiferoDomestico.cpp -o $(OBJ)/mamiferoDomestico.o

$(OBJ)/reptilDomestico.o : $(SRC)/reptilDomestico.cpp $(INC)/reptilDomestico.h
	@$(CC) $(CPPFLAGS) -c $(SRC)/reptilDomestico.cpp -o $(OBJ)/reptilDomestico.o

clean :
	@rm -f core $(BIN)/$(PROG) $(OBJS)

run :
	@./PetFera