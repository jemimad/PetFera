#ifndef _REPTIL_NATIVO_
#define _REPTIL_NATIVO_

#include <iostream>
#include <string>

#include "reptil.h"
#include "animalNativo.h"

class ReptilNativo : public Reptil, AnimalNativo{
	public:
		ReptilNativo();
		~ReptilNativo();
};

#endif