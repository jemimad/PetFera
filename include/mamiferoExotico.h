#ifndef _MAMIFERO_EXOTICO_
#define _MAMIFERO_EXOTICO_

#include <iostream>
#include "mamifero.h"
#include "animalExotico.h"

class MamiferoExotico : public Mamifero, AnimalExotico{
	public:

		MamiferoExotico(int id, string classe, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, string cor_pelo, string autorizacao_ibama, string pais_origem, string cidade_origem);
		MamiferoExotico();
		~MamiferoExotico();
};



#endif