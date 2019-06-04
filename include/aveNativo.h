#ifndef _AVE_NATIVO_
#define _AVE_NATIVO_

#include <iostream>
#include "ave.h"
#include "animalNativo.h"

class AveNativo : public Animal, AnimalNativo{
	public:
		AveNativo();
		~AveNativo();
};



#endif