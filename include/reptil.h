#ifndef _REPTIL_
#define _REPTIL_

#include <iostream>
#include <string>

#include "animal.h"
/**@file reptil.cpp */
/**@author Carmem Stanie, Italo Luiz e Jemima Dias */
/**@data 27/06/2019 */
/**@brief declação da classe Reptil com herança da classe Animal*/
class Reptil : public Animal{
	protected:
		bool m_venenoso;
		string m_tipo_veneno;
		ostream& listar_animais(ostream& os) const = 0;
		ofstream& salvar_animais(ofstream& out) const = 0;
	public:
		Reptil(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, bool venenoso, string tipo_veneno);
		Reptil();
		~Reptil();

		void setVenenoso(bool venenoso_);
		void setTipoVeneno(string tipo_veneno_);
		bool getVenenoso();
		string getTipoVeneno();

};

#endif