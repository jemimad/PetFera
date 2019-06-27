#ifndef _REPTIL_NATIVO_
#define _REPTIL_NATIVO_

#include <iostream>
#include <string>

#include "reptil.h"
#include "animalNativo.h"
/**@file reptilNativo.cpp */
/**@author Carmem Stanie, Italo Luiz e Jemima Dias */
/**@data 27/06/2019 */
/**@brief declação da classe ReptilNativo com herança da classe Reptil e animalNativo*/
class ReptilNativo : public Reptil, public AnimalNativo{
	protected:
		ostream& listar_animais(ostream& os) const;
		ofstream& salvar_animais(ofstream& out) const;


	public:
		ReptilNativo(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, bool venenoso, string tipo_veneno, string autorizacao_ibama, string uf_origem);
		ReptilNativo();
		~ReptilNativo();
		//void abstract();
		string getAutorizacaoIbama();

};

#endif