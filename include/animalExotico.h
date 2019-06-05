#ifndef _ANIMAL_EXOTICO_
#define _ANIMAL_EXOTICO_

#include<iostream>
#include "animalSilvestre.h"

class AnimalExotico : public AnimalSilvestre{
	protected:
		string m_pais_origem;
		string m_cidade_origem;
	public:

		AnimalExotico(string autorizacao_ibama, string pais_origem, string cidade_origem);
		AnimalExotico();
		~AnimalExotico();
};

#endif