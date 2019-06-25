#ifndef _ANIMAL_NATIVO_
#define _ANIMAL_NATIVO_

#include <iostream>
#include "animalSilvestre.h"

using namespace std;

class AnimalNativo : public AnimalSilvestre{
	protected:
		string m_uf_origem;
	public:

		AnimalNativo(string autorizacao_ibama, string uf_origem);
		AnimalNativo();
		~AnimalNativo();

		string getAutorizacaoIbama();
		string getUfOrigem();
		void setUfOrigem(string uf_origem);

		//virtual void abstract() = 0;
};

#endif