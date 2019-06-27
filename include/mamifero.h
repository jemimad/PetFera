#ifndef _MAMIFERO_
#define _MAMIFERO_

#include <iostream>
#include <string>

#include "animal.h"
/**@file mamifero.cpp */
/**@author Carmem Stanie, Italo Luiz e Jemima Dias */
/**@data 27/06/2019 */
/**@brief declação da classe mamifero com herança da classe Animal*/
class Mamifero : public Animal{
	protected:
		string m_cor_pelo;
		ostream& listar_animais(ostream& os) const = 0;
		ofstream& salvar_animais(ofstream& out) const = 0;

	public:

		Mamifero(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, string cor_pelo);
		Mamifero();
		~Mamifero();

		void setCorPelo(string cor_pelo_);
		string getCorPelo();

};


#endif
