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

	public:

		Veterinario(int id, string funcao, string nome, string cpf, short idade, char tipoSanguineo,
					char fatorRH, string especialidade, string cmrv);		
		Veterinario();
		~Veterinario();
		string getFuncao();


};

ostream& Veterinario::listar(ostream& os) const{
	os << "ID:" << m_id << "\nFunção: " << m_funcao << "\nNome: " <<  
	m_nome << "\nCPF: " << m_cpf << "\nIdade: " << m_idade << 
	"\nTipo Sanguineo: " << m_tipoSanguineo << "\nFator RH: " << 
	m_fatorRH << "\nEspecialidade: " << m_especialidade << 
	"\nCMRV: " << m_cmrv << "\n\n";

	return os;
}

string Veterinario::getFuncao(){
	return "Veterinario";
}



#endif