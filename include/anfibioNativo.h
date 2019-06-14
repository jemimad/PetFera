#ifndef _ANFIBIO_NATIVO_
#define _ANFIBIO_NATIVO_

#include <iostream>
#include "anfibio.h"
#include "animalNativo.h"

class AnfibioNativo : public Anfibio, AnimalNativo{
	protected: 
		ostream& listar_animais(ostream& os) const;
		ofstream& salvar_animais(ofstream& out) const;
		
	public:
		AnfibioNativo(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, int total_mudas, string autorizacao_ibama, string uf_origem);
		AnfibioNativo();
		~AnfibioNativo();
};


#endif