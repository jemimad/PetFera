#ifndef _MAMIFERO_NATIVO_
#define _MAMIFERO_NATIVO_

#include <iostream>
#include "mamifero.h"
#include "animalNativo.h"

class MamiferoNativo : public Mamifero, AnimalNativo{
	protected: 
		ostream& listar_animais(ostream& os) const;
		ofstream& salvar_animais(ofstream& out) const;


	public:
		MamiferoNativo(int id, string classe, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, string cor_pelo, string autorizacao_ibama, string uf_origem);
		MamiferoNativo();
		~MamiferoNativo();

		//friend ostream& operator<<(ostream& os,  MamiferoNativo& mn);

};

ostream& MamiferoNativo::listar_animais(ostream& os) const{
	os << "ID:" << m_id << "\nClasse: " << m_classe << "\nNome Científico: " <<  
	m_nome_cientifico << "\nSexo: " << m_sexo << "\nTamanho em metros: " << m_tamanho << 
	"\nDieta: " << m_dieta << "\nID Veterinário: " << m_tem_veterinario << 
	"\nID Tratador: " << m_tem_tratador << "\nNome de Batismo: " << m_nome_batismo << 
	"\nCor do Pelo: " << m_cor_pelo << "\nAutorização do IBAMA: " << m_autorizacao_ibama << 
	"\nUF de Origem: " << m_uf_origem << "\n\n";

	return os;
}

ofstream& MamiferoNativo::salvar_animais(ofstream& out) const{
	out << m_id << ";" << m_classe << ";" <<  m_nome_cientifico << ";" << m_sexo 
	<< ";" << m_tamanho << ";" << m_dieta << ";" << m_tem_veterinario << ";" << m_tem_tratador 
	<< ";" << m_nome_batismo << ";" << m_cor_pelo << 
	";" << m_autorizacao_ibama << ";" << m_uf_origem << "\n";

	return out;
}
/*
ostream& operator<<(ostream& o,  MamiferoNativo& mn){
	o << "ID:" << mn.m_id << 
	"\nClasse" << mn.m_classe << 
	"\nNome: " <<  mn.m_nome_cientifico << 
	"\nSexo: " << mn.m_sexo << 
	"\nTamanho: " << mn.m_tamanho << 
	"\nDieta: " << mn.m_dieta << 
	"\nPossui veterinário: " << mn.m_tem_veterinario << 
	"\nPossui tratador: " << mn.m_tem_tratador << 
	"\nNome Batismo: " << mn.m_nome_batismo <<
	"\nCor do pelo: " << mn.m_cor_pelo <<
	"\nAutorização IBAMA: " << mn.m_autorizacao_ibama <<
	"\nUF de Origem: " << mn.m_uf_origem;

	return o;
}*/




#endif