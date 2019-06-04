#ifndef _ANIMAL_NATIVO_
#define _ANIMAL_NATIVO_

#include <iostream>
#include "animalSilvestre.h"

class AnimalNativo : public AnimalSilvestre{
	protected:
		string m_uf_origem;
		string m_autorizacao;
	public:
		AnimalNativo();
		~AnimalNativo();
};

#endif