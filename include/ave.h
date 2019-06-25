#ifndef _AVE_
#define _AVE_

#include <iostream>
#include "animal.h"


class Ave : public Animal{
	protected:
		double m_tamanho_bico_cm;
		double m_envergadura_asas;
		ostream& listar_animais(ostream& os) const = 0;
		ofstream& salvar_animais(ofstream& out) const = 0;

	public:

		Ave(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, double tamanho_bico_cm, double envergadura_asas);
		Ave();
		~Ave();

		void setTamanhoBico(double tamanho_bico_cm_);
		void setEnvergaduraAsas(double envergadura_asas_);
		double getTamanhoBico();
		double getEnvergaduraAsas();

};



#endif