#ifndef _VETERINARIO_
#define _VETERINARIO_
#include <iostream>
#include <string>
using std::string;

#include "funcionario.h"

class Veterinario : public Funcionario{
	protected:
		string m_cmrv;
		ostream& listar(ostream& os) const;
		ofstream& salvar(ofstream& out) const;

	public:

		Veterinario(int id, string funcao, string nome, string cpf, short idade, char tipoSanguineo,
					char fatorRH, string especialidade, string cmrv);		
		Veterinario();
		~Veterinario();

		string getFuncao();
		void setCMRV(string cmrv_);


};

#endif