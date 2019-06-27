#ifndef _ANFIBIO_NATIVO_
#define _ANFIBIO_NATIVO_

#include <iostream>
#include "anfibio.h"
#include "animalNativo.h"
/**@file anfibioNativo.cpp */
/**@author Carmem Stanie, Italo Luiz e Jemima Dias */
/**@data 27/06/2019 */
/**@brief declação da classe anfibioNativo com herança da classe anfibio e animal nativo */
class AnfibioNativo : public Anfibio, public AnimalNativo{
	protected: 
		ostream& listar_animais(ostream& os) const;
		ofstream& salvar_animais(ofstream& out) const;
		
	public:
		AnfibioNativo(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, int total_mudas, string autorizacao_ibama, string uf_origem);
		AnfibioNativo();
		~AnfibioNativo();

		string getAutorizacaoIbama();


};


#endif