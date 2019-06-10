#ifndef _MAMIFERO_
#define _MAMIFERO_

#include <iostream>
#include <string>

#include "animal.h"

class Mamifero : public Animal{
	protected:
		string m_cor_pelo;
		ostream& listar_animais(ostream& os) const;
	public:

		Mamifero(int id, string classe, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, string cor_pelo);
		Mamifero();
		~Mamifero();
};

ostream& Mamifero::listar_animais(ostream& os) const{
	os << "ID:" << m_id << "\nClasse: " << m_classe << "\nNome Científico: " <<  
	m_nome_cientifico << "\nSexo: " << m_sexo << "\nTamanho em metros: " << m_tamanho << 
	"\nDieta: " << m_dieta << "\nID Veterinário: " << m_tem_veterinario << 
	"\nID Tratador: " << m_tem_tratador << "\nNome de Batismo: " << m_nome_batismo << 
	"\nCor do Pelo: " << m_cor_pelo << "\n\n";

	return os;
}

#endif
