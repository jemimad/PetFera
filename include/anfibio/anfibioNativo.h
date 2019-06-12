#ifndef _ANFIBIO_NATIVO_
#define _ANFIBIO_NATIVO_

#include <iostream>
#include "anfibio.h"
#include "../animal/animalNativo.h"

class AnfibioNativo : public Anfibio, AnimalNativo{
	protected: 
		ostream& listar_animais(ostream& os) const;
		ofstream& salvar_animais(ofstream& out) const;


	public:
		AnfibioNativo(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, int total_mudas, string autorizacao_ibama, string uf_origem);
		AnfibioNativo();
		~AnfibioNativo();
};

ostream& AnfibioNativo::listar_animais(ostream& os) const{
	os << "ID:" << m_id << 
	"\nClasse: " << m_classe << 
	"\nClassificação: " << m_classificacao << 
	"\nNome Científico: " <<  m_nome_cientifico << 
	"\nSexo: " << m_sexo << 
	"\nTamanho em metros: " << m_tamanho << 
	"\nDieta: " << m_dieta << 
	"\nID Veterinário: " << m_tem_veterinario << 
	"\nID Tratador: " << m_tem_tratador << 
	"\nNome de Batismo: " << m_nome_batismo << 
	"\nTotal de Mudas: " << m_total_mudas << 
	"\nAutorização do IBAMA: " << m_autorizacao_ibama << 
	"\nUF de Origem: " << m_uf_origem << "\n\n";

	return os;
}

ofstream& AnfibioNativo::salvar_animais(ofstream& out) const{
	out << m_id << ";" << m_classe << ";" << m_classificacao << ";" << m_nome_cientifico << ";" << m_sexo <<
	";" << m_tamanho << ";" << m_dieta << ";" << m_tem_veterinario << ";" << m_tem_tratador <<
	";" << m_nome_batismo << ";" << m_total_mudas << ";" << m_autorizacao_ibama << 
	";" << m_uf_origem << "\n";

	return out;
}


#endif
