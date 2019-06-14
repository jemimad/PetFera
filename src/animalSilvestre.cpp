#include "animalSilvestre.h"

AnimalSilvestre::AnimalSilvestre(string autorizacao_ibama):m_autorizacao_ibama(autorizacao_ibama){
}

AnimalSilvestre::~AnimalSilvestre(){}

void AnimalSilvestre::setAutorizacaoIbama(string autorizacao_ibama){
	m_autorizacao_ibama = autorizacao_ibama;
}