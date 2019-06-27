#include "animalNativo.h"
/**@brief Implementação do construtor de animalNativo */
AnimalNativo::AnimalNativo(string autorizacao_ibama, string uf_origem):
				AnimalSilvestre(autorizacao_ibama),m_uf_origem(uf_origem){
}
/**@brief implementação do destrutor de animal nativo */
AnimalNativo::~AnimalNativo(){}
/**@brief metodos get's e set's de animal nativo */
void AnimalNativo::setUfOrigem(string uf_origem){
	m_uf_origem = m_uf_origem;
}



string AnimalNativo::getUfOrigem(){
	return m_uf_origem;
}

void AnimalNativo::setAutorizacaoIbama(string autorizacao_ibama){
	m_autorizacao_ibama = autorizacao_ibama;
}