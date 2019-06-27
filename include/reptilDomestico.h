#ifndef _REPTIL_DOMESTICO_
#define _REPTIL_DOMESTICO_

#include <iostream>
#include <string>

#include "reptil.h"
/**@file reptilDomestico.cpp */
/**@author Carmem Stanie, Italo Luiz e Jemima Dias */
/**@data 27/06/2019 */
/**@brief declação da classe ReptilDomestico com herança da classe Reptil*/
class ReptilDomestico : public Reptil{
	protected:
		ostream& listar_animais(ostream& os) const;
		ofstream& salvar_animais(ofstream& out) const;


	public:
		ReptilDomestico(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, bool venenoso, string tipo_veneno);
		ReptilDomestico();
		~ReptilDomestico();
};


#endif