#ifndef _ANFIBIO_DOMESTICO_
#define _ANFIBIO_DOMESTICO_

#include <iostream>
#include "anfibio.h"

class AnfibioDomestico : public Anfibio{
	protected: 
		ostream& listar_animais(ostream& os) const;
		ofstream& salvar_animais(ofstream& out) const;

	public:
		AnfibioDomestico(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, int total_mudas);
		AnfibioDomestico();
		~AnfibioDomestico();
};

#endif
