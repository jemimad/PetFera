#ifndef _MAMIFERO_NATIVO_
#define _MAMIFERO_NATIVO_

#include <iostream>
#include "mamifero.h"
#include "animalNativo"

class MamiferoNativo : public Mamifero, AnimalNativo{
	public:
		MamiferoNativo();
		~MamiferoNativo();
};



#endif