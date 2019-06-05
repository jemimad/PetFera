#ifndef _ANFIBIO_EXOTICO_
#define _ANFIBIO_EXOTICO_

#include <iostream>
#include "anfibio.h"
#include "animalExotico.h"


class AnfibioExotico : public Anfibio, AnimalExotico{
	public:
		AnfibioExotico(int id, string classe, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, int total_mudas, string autorizacao_ibama, string pais_origem, string cidade_origem);
		AnfibioExotico();
		~AnfibioExotico();
};



#endif
