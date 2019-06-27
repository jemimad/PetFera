#ifndef _ANIMAL_SILVESTRE_
#define _ANIMAL_SILVESTRE_

#include <iostream>
#include <string>

using namespace std;
/**@file animalSilvestre.cpp */
/**@author Carmem Stanie, Italo Luiz e Jemima Dias */
/**@data 27/06/2019 */
/**@brief declação da classe AnimalSilvestre e de seus metodos */
class AnimalSilvestre{
	protected:
		string m_autorizacao_ibama;
	public:

		AnimalSilvestre(string autorizacao_ibama);
		AnimalSilvestre();
		~AnimalSilvestre();

		virtual string getAutorizacaoIbama() = 0;
		void setAutorizacaoIbama(string autorizacao_ibama);
};

#endif