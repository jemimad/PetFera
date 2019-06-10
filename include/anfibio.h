#ifndef _ANFIBIO_
#define _ANFIBIO_

#include <iostream>
#include "animal.h"

class Anfibio : public Animal{
	protected:
		int m_total_mudas;
		ostream& listar_animais(ostream& os) const;
		//date m_ultima_muda; procurar classe date
	public:

		Anfibio(int id, string classe, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, int total_mudas);
		Anfibio();
		~Anfibio();
};

ostream& Anfibio::listar_animais(ostream& os) const{
	os << "ID:" << m_id << "\nClasse: " << m_classe << "\nNome Científico: " <<  
	m_nome_cientifico << "\nSexo: " << m_sexo << "\nTamanho em metros: " << m_tamanho << 
	"\nDieta: " << m_dieta << "\nID Veterinário: " << m_tem_veterinario << 
	"\nID Tratador: " << m_tem_tratador << "\nNome de Batismo: " << m_nome_batismo << 
	"\nTotal de Mudas: " << m_total_mudas << "\n\n";

	return os;
}

#endif