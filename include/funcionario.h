#ifndef _FUNCIONARIO_
#define _FUNCIONARIO_
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;
/**@file funcionario.cpp */
/**@author Carmem Stanie, Italo Luiz e Jemima Dias */
/**@data 27/06/2019 */
/**@brief declação da classe Funcionario e implementação de seus metodos*/
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

		void setNome(string nome_);
		void setCpf(string cpf_);
		void setIdade(short idade_);
		void setTipoSanguineo(short tipoSanguineo_);
		void setFatorRh(char fatorRH_);
		void setEspecialidade(string especialidade_);

		string getNome();
		string getCpf();
		int getIdade();
		char getTipoSanguineo();
		char getFatorRh();
		string getEspecialidade();

		virtual string getFuncao() = 0;
		friend ostream& operator<<(ostream& os, const Funcionario& f);
		friend ofstream& operator<<(ofstream& out, const Funcionario& f);
};

#endif