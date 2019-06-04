#ifndef _MAMIFERO_EXOTICO_
#define _MAMIFERO_EXOTICO_

#include <iostream>
#include "mamifero.h"
#include "animalExotico"

class MamiferoExotico : public Mamifero, AnimalExotico{
	public:
		MamiferoExotico();
		~MamiferoExotico();
};



#endif