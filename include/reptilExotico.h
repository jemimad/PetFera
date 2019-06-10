#ifndef _REPTIL_EXOTICO_
#define _REPTIL_EXOTICO_

#include <iostream>
#include <string>

#include "reptil.h"
#include "animalExotico.h"

class ReptilExotico : public Reptil, AnimalExotico{
	protected: 
		ostream& listar_animais(ostream& os) const;

	public:
		ReptilExotico(int id, string classe, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, bool venenoso, string tipo_veneno, string autorizacao_ibama, string pais_origem, 
			string cidade_origem);
		ReptilExotico();
		~ReptilExotico();
};

ostream& ReptilExotico::listar_animais(ostream& os) const{
	os << "ID:" << m_id << "\nClasse: " << m_classe << "\nNome Científico: " <<  
	m_nome_cientifico << "\nSexo: " << m_sexo << "\nTamanho em metros: " << m_tamanho << 
	"\nDieta: " << m_dieta << "\nID Veterinário: " << m_tem_veterinario << 
	"\nID Tratador: " << m_tem_tratador << "\nNome de Batismo: " << m_nome_batismo << 
	"\nVenenoso: " << m_venenoso << "\nTipo de veneno: " << m_tipo_veneno << 
	"\nAutorização do IBAMA: " << m_autorizacao_ibama << "\nPaís de Origem: " << m_pais_origem << 
	"\nCidade de Origem: " << m_cidade_origem << "\n\n";

	return os;
}

#endif