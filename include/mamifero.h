#ifndef _MAMIFERO_
#define _MAMIFERO_

#include <iostream>
#include <string>

#include "animal.h"

class Mamifero : public Animal{
	protected:
		string m_cor_pelo;
		ostream& listar_animais(ostream& os) const = 0;
		ofstream& salvar_animais(ofstream& out) const = 0;

	public:

		Mamifero(int id, string classe, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, string cor_pelo);
		Mamifero();
		~Mamifero();

		string getClasse();
		char getSexo();
};

string Mamifero::getClasse(){
	return "Mammalia";
}

char Mamifero::getSexo(){
	return m_sexo;
}



#endif
