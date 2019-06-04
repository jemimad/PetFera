#ifndef _FUNCIONARIO_
#define _FUNCIONARIO_
#include <iostream>
#include <string>
#include <map>


class Funcionario{

	protected:
		int m_id;
		string m_funcao;
		string m_nome;
		string m_cpf;
		short m_idade;
		short m_tipoSanguineo;
		char m_fatorRH;
		string m_especialidade;
		map<int, Funcionario*> lista_funcionarios;

	public:

		Funcionario();
		Funcionario(int id, string funcao, string nome, string cpf, short idade, short tipoSanguineo,
					char fatorRH, string m_especialidade);
		~Funcionario();
	
};



#endif

