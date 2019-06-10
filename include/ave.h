#ifndef _AVE_
#define _AVE_

#include <iostream>
#include "animal.h"


class Ave : public Animal{
	protected:
		double m_tamanho_bico_cm;
		double m_envergadura_asas;
		ostream& listar_animais(ostream& os) const;

	public:

		Ave(int id, string classe, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, double tamanho_bico_cm, double envergadura_asas);
		Ave();
		~Ave();
};

ostream& Ave::listar_animais(ostream& os) const{
	os << "ID:" << m_id << "\nClasse: " << m_classe << "\nNome Científico: " <<  
	m_nome_cientifico << "\nSexo: " << m_sexo << "\nTamanho em metros: " << m_tamanho << 
	"\nDieta: " << m_dieta << "\nID Veterinário: " << m_tem_veterinario << 
	"\nID Tratador: " << m_tem_tratador << "\nNome de Batismo: " << m_nome_batismo << 
	"\nTamanho do Bico em cm: " << m_tamanho_bico_cm << "\nEnvergadura das Asas: " <<
	m_envergadura_asas << "\n\n";

	return os;
}


#endif