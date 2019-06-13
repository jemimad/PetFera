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

		void setPaisOrigem(string pais_origem);
		void setCidadeOrigem(string cidade_origem);
};


void AnimalExotico::setPaisOrigem(string pais_origem){
	m_pais_origem = pais_origem;
}

void AnimalExotico::setCidadeOrigem(string cidade_origem){
	m_cidade_origem = cidade_origem;
}

#endif