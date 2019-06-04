#ifndef _VETERINARIO_
#define _VETERINARIO_
#include <iostream>
#include <string>
using std::string;

#include "funcionario.h"

class Veterinario : public Funcionario{

	protected:
		string m_cmrv;

	public:

		Veterinario(int id, string funcao, string nome, string cpf, short idade, char tipoSanguineo,
					char fatorRH, string especialidade, string cmrv);		
		Veterinario();
		~Veterinario();

		friend ostream& operator<<(ostream& os,  Veterinario& v);

	private:
		string cmrv;
};


//SOBRECARGA(
ostream& operator<<(ostream& o,  Veterinario& v){
	o << "ID:" << v.m_id << "\nFuncao" << v.m_funcao << "\nNome: " <<  
	v.m_nome << "\nCPF: " << v.m_cpf << "\nIdade: " << v.m_idade << 
	"\nTipo Sanguineo: " << v.m_tipoSanguineo << "\nFator RH: " << 
	v.m_fatorRH << "\nEspecialidade: " << v.m_especialidade << 
	"\nCMRV: " << v.m_cmrv;

	return o;
}



#endif