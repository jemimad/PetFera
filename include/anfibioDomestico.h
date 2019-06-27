#ifndef _ANFIBIO_DOMESTICO_
#define _ANFIBIO_DOMESTICO_

#include "anfibio.h"
/**@file anfibioDomestico.cpp */
/**@author Carmem Stanie, Italo Luiz e Jemima Dias */
/**@data 27/06/2019 */
/**@brief declação da classe anfibioDomestico com herança da classe anfibio */
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

#endif
