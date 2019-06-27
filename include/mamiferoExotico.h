#ifndef _MAMIFERO_EXOTICO_
#define _MAMIFERO_EXOTICO_

#include <iostream>
#include "mamifero.h"
#include "animalExotico.h"
/**@file mamiferoExotico.cpp */
/**@author Carmem Stanie, Italo Luiz e Jemima Dias */
/**@data 27/06/2019 */
/**@brief declação da classe mamiferoExotico com herança da classe Mamifero e animalExotico*/
class MamiferoExotico : public Mamifero, public AnimalExotico{
	protected: 
		ostream& listar_animais(ostream& os) const;
		ofstream& salvar_animais(ofstream& out) const;
	public:

		MamiferoExotico(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, string cor_pelo, string autorizacao_ibama, string pais_origem, string cidade_origem);
		MamiferoExotico();
		~MamiferoExotico();
		void abstract();
};


#endif