#include "veterinario.h"

Veterinario::Veterinario(int id, string funcao, string nome, string cpf, short idade, char tipoSanguineo,
					char fatorRH, string especialidade, string cmrv):
					Funcionario(id, funcao, nome, cpf, idade, 
					tipoSanguineo, fatorRH, especialidade),  
					m_cmrv(cmrv){
}

Veterinario::~Veterinario(){}

ostream& Veterinario::listar(ostream& os) const{
	os << "| ID: " << m_id << 
    " | Função: " << m_funcao << 
    " | Nome: " <<  m_nome << 
    " | CPF: " << m_cpf << 
    " | Idade: " << m_idade << 
    " |	Tipo Sanguíneo: " << m_tipoSanguineo << 
    " | Fator RH: " << m_fatorRH << 
    " | Especialidade: " << m_especialidade << 
    " | CMRV " << m_cmrv << "|\n\n";

	return os;
}

ofstream& Veterinario::salvar(ofstream& out) const{
	out <<  m_id << ";" << m_funcao << ";" <<  
	m_nome << ";" << m_cpf << ";" << m_idade << 
	";" << m_tipoSanguineo << ";" << 
	m_fatorRH << ";" << m_especialidade << 
	";" << m_cmrv << "\n";

	return out;
}

string Veterinario::getFuncao(){
	return "Veterinario";
}

void Veterinario::setCMRV(string cmrv_){
	m_cmrv = cmrv_;
}

string Veterinario::getCMRV(){
	return m_cmrv;
}