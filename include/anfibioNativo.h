#ifndef _ANFIBIO_NATIVO_
#define _ANFIBIO_NATIVO_

#include <iostream>
#include "anfibio.h"
#include "animalNativo.h"

class AnfibioNativo : public Anfibio, AnimalNativo{
	public:
		AnfibioNativo();
		~AnfibioNativo();
};



#endif
