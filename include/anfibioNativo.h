#ifndef _ANFIBIO_NATIVO_
#define _ANFIBIO_NATIVO_

#include <iostream>
#include "anfibio.h"
#include "animalNativo.h"

class AnfibioNativo : public Anfibio, AnimalNativo{
	public:
		AnfibioNativo(int id, string classe, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, int total_mudas, string autorizacao_ibama, string uf_origem);
		AnfibioNativo();
		~AnfibioNativo();
};



#endif
