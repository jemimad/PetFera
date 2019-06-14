#include "veterinario.h"

Veterinario::Veterinario(int id, string funcao, string nome, string cpf, short idade, char tipoSanguineo,
					char fatorRH, string especialidade, string cmrv):
					Funcionario(id, funcao, nome, cpf, idade, 
					tipoSanguineo, fatorRH, especialidade),  
					m_cmrv(cmrv){
}

Veterinario::~Veterinario(){}

ostream& Veterinario::listar(ostream& os) const{
	os << "ID:" << m_id << "\nFunção: " << m_funcao << "\nNome: " <<  
	m_nome << "\nCPF: " << m_cpf << "\nIdade: " << m_idade << 
	"\nTipo Sanguineo: " << m_tipoSanguineo << "\nFator RH: " << 
	m_fatorRH << "\nEspecialidade: " << m_especialidade << 
	"\nCMRV: " << m_cmrv << "\n\n";

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