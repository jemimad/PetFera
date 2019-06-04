#ifndef _REPTIL_EXOTICO_
#define _REPTIL_EXOTICO_

#include <iostream>
#include <string>

#include "reptil.h"
#include "animalExotico.h"

class ReptilExotico : public Reptil, AnimalExotico{
	public:
		ReptilExotico();
		~ReptilExotico();
};

#endif