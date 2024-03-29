#ifndef _ANFIBIO_
#define _ANFIBIO_

#include <iostream>
#include <fstream>
#include "animal.h"
/**@file anfibio.cpp */
/**@author Carmem Stanie, Italo Luiz e Jemima Dias */
/**@data 27/06/2019 */
/**@brief declação da classe anfibio com herança da classe animal */
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

		void setTotalMudas(int total_mudas_);
		int getTotalMudas();

};

#endif