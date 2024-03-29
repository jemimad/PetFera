#ifndef _AVE_EXOTICO_
#define _AVE_EXOTICO_

#include <iostream>
#include "ave.h"
#include "animalExotico.h"
/**@file aveExotico.cpp */
/**@author Carmem Stanie, Italo Luiz e Jemima Dias */
/**@data 27/06/2019 */
/**@brief declação da classe aveExotico com herança da classe Ave e AnimalExotico*/
class AveExotico : public Ave, public AnimalExotico{
	protected:
		ostream& listar_animais(ostream& os) const;
		ofstream& salvar_animais(ofstream& out) const;

	public:
		AveExotico(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, double tamanho_bico_cm, double envergadura_asas, 
			string autorizacao_ibama, string pais_origem, string cidade_origem);
		AveExotico();
		~AveExotico();
		void abstract();
};


#endif