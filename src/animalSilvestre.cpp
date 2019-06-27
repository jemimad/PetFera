#include "animalSilvestre.h"
/**@brief Implementação Construtor de animal silvestre */
AnimalSilvestre::AnimalSilvestre(string autorizacao_ibama):m_autorizacao_ibama(autorizacao_ibama){
}
/**@brief Implementação do destrutor de animal silvestre*/
AnimalSilvestre::~AnimalSilvestre(){}
/**@brief metodo set de animal silvestre */
void AnimalSilvestre::setAutorizacaoIbama(string autorizacao_ibama){
	m_autorizacao_ibama = autorizacao_ibama;
}