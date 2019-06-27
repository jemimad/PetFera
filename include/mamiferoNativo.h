#ifndef _MAMIFERO_NATIVO_
#define _MAMIFERO_NATIVO_

#include <iostream>
#include "mamifero.h"
#include "animalNativo.h"
/**@file mamiferoNativo.cpp */
/**@author Carmem Stanie, Italo Luiz e Jemima Dias */
/**@data 27/06/2019 */
/**@brief declação da classe mamiferoNativo com herança da classe Mamifero e animal Nativo*/
class MamiferoNativo : public Mamifero, public AnimalNativo{
	protected: 
		ostream& listar_animais(ostream& os) const;
		ofstream& salvar_animais(ofstream& out) const;


	public:
		MamiferoNativo(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, string cor_pelo, string autorizacao_ibama, string uf_origem);
		MamiferoNativo();
		~MamiferoNativo();
		
		//void abstract();

		string getAutorizacaoIbama();
		//friend ostream& operator<<(ostream& os,  MamiferoNativo& mn);

};

#endif