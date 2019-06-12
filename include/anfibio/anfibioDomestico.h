#ifndef _ANFIBIO_DOMESTICO_
#define _ANFIBIO_DOMESTICO_

#include <iostream>
#include "anfibio.h"



class AnfibioDomestico : public Anfibio{
	protected: 
		ostream& listar_animais(ostream& os) const;
		ofstream& salvar_animais(ofstream& out) const;

	public:
		AnfibioDomestico(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, int total_mudas);
		AnfibioDomestico();
		~AnfibioDomestico();
};

ostream& AnfibioDomestico::listar_animais(ostream& os) const{
	os << "ID:" << m_id << 
	"\nClasse: " << m_classe << 
	"\nClassificação: "<< m_classificacao << 
	"\nNome Científico: " <<  m_nome_cientifico << 
	"\nSexo: " << m_sexo << 
	"\nTamanho em metros: " << m_tamanho << 
	"\nDieta: " << m_dieta << 
	"\nID Veterinário: " << m_tem_veterinario << 
	"\nID Tratador: " << m_tem_tratador << 
	"\nNome de Batismo: " << m_nome_batismo << 
	"\nTotal de Mudas: " << m_total_mudas << "\n\n";

	return os;
}

ofstream& AnfibioDomestico::salvar_animais(ofstream& out) const{
	out << m_id << ";" << m_classe << ";"  << m_classificacao << ";" <<  m_nome_cientifico << ";" << m_sexo 
	<< ";" << m_tamanho << ";" << m_dieta << ";" << m_tem_veterinario << ";" << m_tem_tratador 
	<< ";" << m_nome_batismo << ";" << m_total_mudas << "\n";

	return out;
}




#endif
