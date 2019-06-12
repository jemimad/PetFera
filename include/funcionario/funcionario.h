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

		virtual ostream& listar(ostream&) const = 0;
		virtual ofstream& salvar(ofstream&) const = 0;

	public:

		Funcionario();
		Funcionario(int id, string funcao, string nome, string cpf, short idade, short tipoSanguineo,
					char fatorRH, string m_especialidade);
		~Funcionario();


		virtual string getFuncao() = 0;
		friend ostream& operator<<(ostream& os, const Funcionario& f);
		friend ofstream& operator<<(ofstream& out, const Funcionario& f);
};

ostream& operator<<(ostream& os, const Funcionario& f){
	return f.listar(os);
}

ofstream& operator<<(ofstream& out, const Funcionario& f){
	return f.salvar(out);
}

#endif
