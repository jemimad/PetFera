#ifndef _REPTIL_EXOTICO_
#define _REPTIL_EXOTICO_

#include <iostream>
#include <string>

#include "reptil.h"
#include "animalExotico.h"

class ReptilExotico : public Reptil, AnimalExotico{
	public:
		ReptilExotico(int id, string classe, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, bool venenoso, string tipo_veneno, string autorizacao_ibama, string pais_origem, string cidade_origem);
		ReptilExotico();
		~ReptilExotico();
};

#endif