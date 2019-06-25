#ifndef _AVE_DOMESTICO_
#define _AVE_DOMESTICO_

#include <iostream>
#include "ave.h"


class AveDomestico : public Ave{
	protected:
		ostream& listar_animais(ostream& os) const;
		ofstream& salvar_animais(ofstream& out) const;


	public:
		AveDomestico(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, double tamanho_bico_cm, double envergadura_asas);
		AveDomestico();
		~AveDomestico();
};



#endif