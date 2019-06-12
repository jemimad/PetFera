#ifndef _AVE_NATIVO_
#define _AVE_NATIVO_

#include <iostream>
#include "ave.h"
#include "../animal/animalNativo.h"

class AveNativo : public Ave, AnimalNativo{
	protected:
		ostream& listar_animais(ostream& os) const;
		ofstream& salvar_animais(ofstream& out) const;


	public:
		AveNativo(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, double tamanho_bico_cm, double envergadura_asas, string autorizacao_ibama, string uf_origem);
		AveNativo();
		~AveNativo();
};

ostream& AveNativo::listar_animais(ostream& os) const{
	
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
	"\nTamanho do Bico em cm: " << m_tamanho_bico_cm << 
	"\nEnvergadura das Asas: " << m_envergadura_asas << 
	"\nAutorização do IBAMA: " << m_autorizacao_ibama << 
	"\nUF de Origem: " << m_uf_origem << "\n\n";

	return os;
}

ofstream& AveNativo::salvar_animais(ofstream& out) const{
	out << m_id << ";" << m_classe << ";" << m_classificacao << ";" << m_nome_cientifico << ";" << m_sexo 
	<< ";" << m_tamanho << ";" << m_dieta << ";" << m_tem_veterinario << ";" << m_tem_tratador 
	<< ";" << m_nome_batismo << ";" << m_tamanho_bico_cm << ";" << m_envergadura_asas << 
	";" << m_autorizacao_ibama << ";" << m_uf_origem << "\n";

	return out;
}

#endif