#ifndef _ANFIBIO_NATIVO_
#define _ANFIBIO_NATIVO_

#include <iostream>
#include "anfibio.h"
#include "animalNativo.h"

class AnfibioNativo : public Anfibio, AnimalNativo{
	protected: 
		ostream& listar_animais(ostream& os) const;

	public:
		AnfibioNativo(int id, string classe, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, int total_mudas, string autorizacao_ibama, string uf_origem);
		AnfibioNativo();
		~AnfibioNativo();
};

ostream& AnfibioNativo::listar_animais(ostream& os) const{
	os << "ID:" << m_id << "\nClasse: " << m_classe << "\nNome Científico: " <<  
	m_nome_cientifico << "\nSexo: " << m_sexo << "\nTamanho em metros: " << m_tamanho << 
	"\nDieta: " << m_dieta << "\nID Veterinário: " << m_tem_veterinario << 
	"\nID Tratador: " << m_tem_tratador << "\nNome de Batismo: " << m_nome_batismo << 
	"\nTotal de Mudas: " << m_total_mudas << "\nAutorização do IBAMA: " << m_autorizacao_ibama << 
	"\nUF de Origem: " << m_uf_origem << "\n\n";

	return os;
}



#endif
