#ifndef _REPTIL_
#define _REPTIL_

#include <iostream>
#include <string>

#include "animal.h"

class Reptil : public Animal{
	protected:
		bool m_venenoso;
		string m_tipo_veneno;
		ostream& listar_animais(ostream& os) const;
	public:
		Reptil(int id, string classe, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, bool venenoso, string tipo_veneno);
		Reptil();
		~Reptil();
};

ostream& Reptil::listar_animais(ostream& os) const{
	os << "ID:" << m_id << "\nClasse: " << m_classe << "\nNome Científico: " <<  
	m_nome_cientifico << "\nSexo: " << m_sexo << "\nTamanho em metros: " << m_tamanho << 
	"\nDieta: " << m_dieta << "\nID Veterinário: " << m_tem_veterinario << 
	"\nID Tratador: " << m_tem_tratador << "\nNome de Batismo: " << m_nome_batismo << 
	"\nVenenoso: " << m_venenoso << "\nTipo de veneno: " <<
	m_tipo_veneno << "\n\n";

	return os;
}

#endif