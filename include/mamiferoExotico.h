#ifndef _MAMIFERO_EXOTICO_
#define _MAMIFERO_EXOTICO_

#include <iostream>
#include "mamifero.h"
#include "animalExotico.h"

class MamiferoExotico : public Mamifero, AnimalExotico{
	protected: 
		ostream& listar_animais(ostream& os) const;

	public:

		MamiferoExotico(int id, string classe, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, string cor_pelo, string autorizacao_ibama, string pais_origem, string cidade_origem);
		MamiferoExotico();
		~MamiferoExotico();
};

ostream& MamiferoExotico::listar_animais(ostream& os) const{
	os << "ID:" << m_id << "\nClasse: " << m_classe << "\nNome Científico: " <<  
	m_nome_cientifico << "\nSexo: " << m_sexo << "\nTamanho em metros: " << m_tamanho << 
	"\nDieta: " << m_dieta << "\nID Veterinário: " << m_tem_veterinario << 
	"\nID Tratador: " << m_tem_tratador << "\nNome de Batismo: " << m_nome_batismo << 
	"\nCor do Pelo: " << m_cor_pelo << "\nAutorização do IBAMA: " << m_autorizacao_ibama << 
	"\nPaís de Origem: " << m_pais_origem << "\nCidade de Origem: " << m_cidade_origem << "\n\n";
	return os;
}



#endif