#ifndef _REPTIL_NATIVO_
#define _REPTIL_NATIVO_

#include <iostream>
#include <string>

#include "reptil.h"
#include "animalNativo.h"

class ReptilNativo : public Reptil, AnimalNativo{
	protected:
		ostream& listar_animais(ostream& os) const;


	public:
		ReptilNativo(int id, string classe, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, bool venenoso, string tipo_veneno, string autorizacao_ibama, string uf_origem);
		ReptilNativo();
		~ReptilNativo();
};

ostream& ReptilNativo::listar_animais(ostream& os) const{
	os << "ID:" << m_id << "\nClasse: " << m_classe << "\nNome Científico: " <<  
	m_nome_cientifico << "\nSexo: " << m_sexo << "\nTamanho em metros: " << m_tamanho << 
	"\nDieta: " << m_dieta << "\nID Veterinário: " << m_tem_veterinario << 
	"\nID Tratador: " << m_tem_tratador << "\nNome de Batismo: " << m_nome_batismo << 
	"\nVenenoso: " << m_venenoso << "\nTipo de veneno: " << m_tipo_veneno << 
	"\nAutorização do IBAMA: " << m_autorizacao_ibama << "\nUF de Origem: " << m_uf_origem << "\n\n";

	return os;
}


#endif