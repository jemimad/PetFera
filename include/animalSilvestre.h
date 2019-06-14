#ifndef _ANIMAL_SILVESTRE_
#define _ANIMAL_SILVESTRE_

#include <iostream>
#include <string>

using namespace std;

class AnimalSilvestre{
	protected:
		string m_autorizacao_ibama;
	public:

		AnimalSilvestre(string autorizacao_ibama);
		AnimalSilvestre();
		~AnimalSilvestre();

		void setAutorizacaoIbama(string autorizacao_ibama);
};

#endif