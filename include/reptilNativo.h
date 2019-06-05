#ifndef _REPTIL_NATIVO_
#define _REPTIL_NATIVO_

#include <iostream>
#include <string>

#include "reptil.h"
#include "animalNativo.h"

class ReptilNativo : public Reptil, AnimalNativo{
	public:
		ReptilNativo(int id, string classe, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, bool venenoso, string tipo_veneno, string autorizacao_ibama, string uf_origem);
		ReptilNativo();
		~ReptilNativo();
};

#endif