#ifndef _REPTIL_EXOTICO_
#define _REPTIL_EXOTICO_

#include <iostream>
#include <string>

#include "reptil.h"
#include "animalExotico.h"
/**@file reptilExotico.cpp */
/**@author Carmem Stanie, Italo Luiz e Jemima Dias */
/**@data 27/06/2019 */
/**@brief declação da classe ReptilExotico com herança da classe Reptil e animalExotico*/
class ReptilExotico : public Reptil, public AnimalExotico{
	protected: 
		ostream& listar_animais(ostream& os) const;
		ofstream& salvar_animais(ofstream& out) const;

	public:
		ReptilExotico(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, bool venenoso, string tipo_veneno, string autorizacao_ibama, string pais_origem, 
			string cidade_origem);
		ReptilExotico();
		~ReptilExotico();
		//void abstract();

		//string getAutorizacaoIbama();

};


#endif