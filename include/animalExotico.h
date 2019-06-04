#ifndef _ANIMAL_EXOTICO_
#define _ANIMAL_EXOTICO_

#include<iostream>
#include "animalSilvestre.h"

class AnimalExotico : public AnimalSilvestre{
	protected:
		string m_pais_origem;
	public:
		AnimalExotico();
		~AnimalExotico();
};

#endif