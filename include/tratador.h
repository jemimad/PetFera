#ifndef _TRATADOR_
#define _TRATADOR_
#include <iostream>

#include "funcionario.h"
class Tratador : public Funcionario{

	protected:
		int m_nivelSeguranca;


	public:
		Tratador(int id, string funcao, string nome, string cpf, short idade, char tipoSanguineo,
				char fatorRH, string especialidade, int nivelSeguranca);

		Tratador();
		~Tratador();

		friend ostream& operator<<(ostream& os,  Tratador& t);


};


//SOBRECARGA(
ostream& operator<<(ostream& o,  Tratador& t){
	o << "ID:" << t.m_id << "\nFuncao" << t.m_funcao << "\nNome: " <<  
	t.m_nome << "\nCPF: " << t.m_cpf << "\nIdade: " << t.m_idade << 
	"\nTipo Sanguineo: " << t.m_tipoSanguineo << "\nFator RH: " << 
	t.m_fatorRH << "\nEspecialidade: " << t.m_especialidade << 
	"\nNível de Seguranca: " << t.m_nivelSeguranca;

	return o;
}



#endif
