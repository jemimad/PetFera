#Makefile for "petfera" C++ application
#Created by Carmem Stefanie, Italo Luis, Jemima Dias - 15/06/2019

#Variáveis 
PROG= petfera
CC = g++
CPPFLAGS= -O0 -g -Wall -std=c++11 -I/usr/petfera/include
OBJS = ./obj

OBJS= main.o animal.o animalSilvestre.o funcionario.o anfibio.o anfibioDomestico.o anfibioExotico.o anfibioNativo.o animalExotico.o animalNativo.o ave.o aveDomestico.o aveExotico.o aveNativo.o controlador.o mamifero.o mamiferoDomestico.o mamiferoExotico.o mamiferoNativo.o menu.o reptil.o reptilDomestico.o reptilExotico.o reptilNativo.o tratador.o veterinario.o

$(PROG): $(OBJS)
	$(CC) $(CPPFLAGS) -o $(PROG) $(OBJS)

main.o:
	$(CC) $(CPPFLAGS) -c main.cpp

animal.o:
	$(CC) $(CPPFLAGS) -c animal.cpp

animalSilvestre.o:
	$(CC) $(CPPFLAGS) -c animalSilvestre.cpp
	
funcionario.o:
	$(CC) $(CPPFLAGS) -c funcionario.cpp

anfibio.o:
	$(CC) $(CPPFLAGS) -c anfibio.cpp

anfibioDomestico.o:
	$(CC) $(CPPFLAGS) -c anfibioDomestico.cpp

anfibioExotico.o:
	$(CC) $(CPPFLAGS) -c anfibioExotico.cpp

anfibioNativo.o:
	$(CC) $(CPPFLAGS) -c anfibioNativo.cpp

animalExotico.o:
	$(CC) $(CPPFLAGS) -c animalExotico.cpp

animalNativo.o:
	$(CC) $(CPPFLAGS) -c animalNativo.cpp

ave.o:
	$(CC) $(CPPFLAGS) -c ave.cpp

aveDomestico.o:
	$(CC) $(CPPFLAGS) -c aveDomestico.cpp

aveExotico.o:
	$(CC) $(CPPFLAGS) -c aveExotico.cpp

aveNativo.o:
	$(CC) $(CPPFLAGS) -c aveNativo.cpp

controlador.o:
	$(CC) $(CPPFLAGS) -c controlador.cpp

mamifero.o: 
	$(CC) $(CPPFLAGS) -c mamifero.cpp

mamiferoDomestico.o:
	$(CC) $(CPPFLAGS) -c mamiferoDomestico.cpp

mamiferoExotico.o:
	$(CC) $(CPPFLAGS) -c mamiferoExotico.cpp

mamiferoNativo.o:
	$(CC) $(CPPFLAGS) -c mamiferoNativo.cpp

menu.o: 
	$(CC) $(CPPFLAGS) -c menu.cpp

reptil.o:
	$(CC) $(CPPFLAGS) -c reptil.cpp

reptilDomestico.o:
	$(CC) $(CPPFLAGS) -c reptilDomestico.cpp

reptilExotico.o:
	$(CC) $(CPPFLAGS) -c reptilExotico.cpp

reptilNativo.o:
	$(CC) $(CPPFLAGS) -c reptilNativo.cpp

tratador.o:
	$(CC) $(CPPFLAGS) -c tratador.cpp

veterinario.o:
	$(CC) $(CPPFLAGS) -c veterinario.cpp

clean:
	rm -f core $(PROG) $(OBJS)

