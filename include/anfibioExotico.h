#ifndef _ANFIBIO_EXOTICO_
#define _ANFIBIO_EXOTICO_

#include <iostream>
#include "anfibio.h"
#include "animalExotico.h"
/**@file anfibioExotico.cpp */
/**@author Carmem Stanie, Italo Luiz e Jemima Dias */
/**@data 27/06/2019 */
/**@brief declação da classe anfibioExotico com herança da classe anfibio e Animal Exotico */
class AnfibioExotico : public Anfibio, public AnimalExotico{
	protected: 
		ostream& listar_animais(ostream& os) const;
		ofstream& salvar_animais(ofstream& out) const;

	public:
		AnfibioExotico(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, int total_mudas, string autorizacao_ibama, string pais_origem, string cidade_origem);
		AnfibioExotico();
		~AnfibioExotico();

};

#endif
