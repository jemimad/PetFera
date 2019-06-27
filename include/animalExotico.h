#ifndef _ANIMAL_EXOTICO_
#define _ANIMAL_EXOTICO_

#include <iostream>
#include "animalSilvestre.h"
/**@file animalExotico.cpp */
/**@author Carmem Stanie, Italo Luiz e Jemima Dias */
/**@data 27/06/2019 */
/**@brief declação da classe animalExotico com herança da classe animal Silvestre */
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
		void setAutorizacaoIbama(string autorizacao_ibama);
		
		string getAutorizacaoIbama();
		string getPaisOrigem();
		string getCidadeOrigem();

		//virtual void abstract() = 0;
};

#endif