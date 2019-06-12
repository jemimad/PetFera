#ifndef _ANFIBIO_
#define _ANFIBIO_

#include <iostream>
#include "../animal/animal.h"

class Anfibio : public Animal{
	protected:
		int m_total_mudas;
		ostream& listar_animais(ostream& os) const = 0;
		ofstream& salvar_animais(ofstream& out) const = 0;
		//date m_ultima_muda; procurar classe date
	public:

		Anfibio(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, int total_mudas);
		Anfibio();
		~Anfibio();
};

#endif