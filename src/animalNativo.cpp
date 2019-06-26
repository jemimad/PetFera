#include "animalNativo.h"

AnimalNativo::AnimalNativo(string autorizacao_ibama, string uf_origem):
				AnimalSilvestre(autorizacao_ibama),m_uf_origem(uf_origem){
}

AnimalNativo::~AnimalNativo(){}

void AnimalNativo::setUfOrigem(string uf_origem){
	m_uf_origem = m_uf_origem;
}



string AnimalNativo::getUfOrigem(){
	return m_uf_origem;
}

void AnimalNativo::setAutorizacaoIbama(string autorizacao_ibama){
	m_autorizacao_ibama = autorizacao_ibama;
}