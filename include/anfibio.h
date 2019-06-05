#ifndef _ANFIBIO_
#define _ANFIBIO_

#include <iostream>
#include "animal.h"

class Anfibio : public Animal{
	protected:
		int m_total_mudas;
		//date m_ultima_muda; procurar classe date
	public:

		Anfibio(int id, string classe, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, int total_mudas);
		Anfibio();
		~Anfibio();
};



#endif