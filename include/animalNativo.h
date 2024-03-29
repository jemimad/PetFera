#ifndef _ANIMAL_NATIVO_
#define _ANIMAL_NATIVO_

#include <iostream>
#include "animalSilvestre.h"

using namespace std;
/**@file animalNativo.cpp */
/**@author Carmem Stanie, Italo Luiz e Jemima Dias */
/**@data 27/06/2019 */
/**@brief declação da classe animalNativo com herança da classe AnimalSilvestre */
class AnimalNativo : public AnimalSilvestre{
	protected:
		string m_uf_origem;
	public:

		AnimalNativo(string autorizacao_ibama, string uf_origem);
		AnimalNativo();
		~AnimalNativo();

		string getAutorizacaoIbama() = 0; 
		string getUfOrigem();
		
		void setUfOrigem(string uf_origem);
		void setAutorizacaoIbama(string autorizacao_ibama);

		//virtual void abstract() = 0;
};

#endif