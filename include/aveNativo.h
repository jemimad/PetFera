#ifndef _AVE_NATIVO_
#define _AVE_NATIVO_

#include <iostream>
#include "ave.h"
#include "animalNativo.h"
/**@file aveNativo.cpp */
/**@author Carmem Stanie, Italo Luiz e Jemima Dias */
/**@data 27/06/2019 */
/**@brief declação da classe aveNativo com herança da classe Ave e AveNativo*/
class AveNativo : public Ave, public AnimalNativo{
	protected:
		ostream& listar_animais(ostream& os) const;
		ofstream& salvar_animais(ofstream& out) const;


	public:
		AveNativo(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, double tamanho_bico_cm, double envergadura_asas, string autorizacao_ibama, string uf_origem);
		AveNativo();
		~AveNativo();
		//void abstract();

		string getAutorizacaoIbama();

};


#endif