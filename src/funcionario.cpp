#include <iostream>
#include "../include/funcionario/funcionario.h"

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