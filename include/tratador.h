#ifndef _TRATADOR_
#define _TRATADOR_
#include <iostream>
#include "funcionario.h"

class Tratador : public Funcionario{

	protected:
		int m_nivelSeguranca;
		ostream& listar(ostream& os) const;
		ofstream& salvar(ofstream& out) const;

	public:
		Tratador(int id, string funcao, string nome, string cpf, short idade, char tipoSanguineo,
				char fatorRH, string especialidade, int nivelSeguranca);

		Tratador();
		~Tratador();

		string getFuncao();
		int getNivelSeguranca();
		
		void setNivelSeguranca(int nivelSeguranca_);



};

#endif
