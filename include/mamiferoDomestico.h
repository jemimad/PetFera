#ifndef _MAMIFERO_DOMESTICO_
#define _MAMIFERO_DOMESTICO_

#include <iostream>
#include "mamifero.h"
/**@file mamiferoDomestico.cpp */
/**@author Carmem Stanie, Italo Luiz e Jemima Dias */
/**@data 27/06/2019 */
/**@brief declação da classe mamiferoDomestico com herança da classe Mamifero*/
class MamiferoDomestico : public Mamifero{
	protected: 
		ostream& listar_animais(ostream& os) const;
		ofstream& salvar_animais(ofstream& out) const;
	public:

		MamiferoDomestico(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, string cor_pelo);
		MamiferoDomestico();
		~MamiferoDomestico();
};

#endif