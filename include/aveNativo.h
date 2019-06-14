#ifndef _AVE_NATIVO_
#define _AVE_NATIVO_

#include <iostream>
#include "ave.h"
#include "animalNativo.h"

class AveNativo : public Ave, AnimalNativo{
	protected:
		ostream& listar_animais(ostream& os) const;
		ofstream& salvar_animais(ofstream& out) const;


	public:
		AveNativo(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, double tamanho_bico_cm, double envergadura_asas, string autorizacao_ibama, string uf_origem);
		AveNativo();
		~AveNativo();
};


#endif