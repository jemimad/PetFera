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
		void setNivelSeguranca(int nivelSeguranca_);



};


//SOBRECARGA(
ostream& Tratador::listar(ostream& os) const{
	os << "ID:" << m_id << "\nFunção: " << m_funcao << "\nNome: " <<  
	m_nome << "\nCPF: " << m_cpf << "\nIdade: " << m_idade << 
	"\nTipo Sanguineo: " << m_tipoSanguineo << "\nFator RH: " << 
	m_fatorRH << "\nEspecialidade: " << m_especialidade << 
	"\nNível de Seguranca: " << m_nivelSeguranca << "\n\n";

	return os;
}

ofstream& Tratador::salvar(ofstream& out) const{
	out <<  m_id << ";" << m_funcao << ";" <<  
	m_nome << ";" << m_cpf << ";" << m_idade << 
	";" << m_tipoSanguineo << ";" << 
	m_fatorRH << ";" << m_especialidade << 
	";" << m_nivelSeguranca << "\n";

	return out;
}



string Tratador::getFuncao(){
	return "Tratador";
}


void Tratador::setNivelSeguranca(int nivelSeguranca_){
	m_nivelSeguranca = nivelSeguranca_;
}

#endif
