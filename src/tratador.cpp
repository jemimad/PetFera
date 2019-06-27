#include "tratador.h"
/**@brief implementação do construtor e destrutor da classe tratador */
Tratador::Tratador(int id, string funcao, string nome, string cpf, short idade, char tipoSanguineo,
					char fatorRH, string especialidade, int nivelSeguranca):
					Funcionario(id, funcao, nome, cpf, idade, 
					tipoSanguineo, fatorRH, especialidade), 
					m_nivelSeguranca(nivelSeguranca){
}

Tratador::~Tratador(){}
/**@brief sobrecarga de operador de inserção para listagem e para salvar no arquivo*/
ostream& Tratador::listar(ostream& os) const{
	os << "| ID: " << m_id << 
    " | Função: " << m_funcao << 
    " | Nome: "<< m_nome << 
    " | CPF: " <<  m_cpf<< 
    " | Idade: " << m_idade << 
    " | Tipo Sanguíneo: " << m_tipoSanguineo << 
    " | Fator RH: " << m_fatorRH << 
    " | Especialidade: " << m_especialidade << 
    " | Nível de Segurança: " << m_nivelSeguranca <<  "|\n\n";

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
/**@brief implementação dos metodos get's e set's de tratador */
string Tratador::getFuncao(){
	return "Tratador";
}


void Tratador::setNivelSeguranca(int nivelSeguranca_){
	m_nivelSeguranca = nivelSeguranca_;
}

int Tratador::getNivelSeguranca(){
	return m_nivelSeguranca;
}