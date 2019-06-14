#include <iostream>
#include "funcionario.h"

Funcionario::Funcionario(int id, string funcao, string nome, string cpf, short idade, short tipoSanguineo,
					char fatorRH, string especialidade):m_id(id), m_funcao(funcao), m_nome(nome), m_cpf(cpf),
					m_idade(idade), m_tipoSanguineo(tipoSanguineo), m_fatorRH(fatorRH),
					m_especialidade(especialidade){
}

Funcionario::~Funcionario(){}

ostream& operator<<(ostream& os, const Funcionario& f){
	return f.listar(os);
}

ofstream& operator<<(ofstream& out, const Funcionario& f){
	return f.salvar(out);
}

void Funcionario::setNome(string nome_){
	m_nome = nome_;
}

void Funcionario::setCpf(string cpf_){
	m_cpf = cpf_;
}

void Funcionario::setIdade(short idade_){
	m_idade = idade_;
}

void Funcionario::setTipoSanguineo(short tipoSanguineo_){
	m_tipoSanguineo = tipoSanguineo_;
}

void Funcionario::setFatorRh(char fatorRH_){
	m_fatorRH = fatorRH_;
}

void Funcionario::setEspecialidade(string especialidade_){
	m_especialidade = especialidade_;
}