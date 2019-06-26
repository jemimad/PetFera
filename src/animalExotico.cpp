#include "animalExotico.h"

AnimalExotico::AnimalExotico(string autorizacao_ibama, string pais_origem, string cidade_origem):
				AnimalSilvestre(autorizacao_ibama),m_pais_origem(pais_origem),m_cidade_origem(cidade_origem){
}

AnimalExotico::~AnimalExotico(){}

void AnimalExotico::setPaisOrigem(string pais_origem){
	m_pais_origem = pais_origem;
}

void AnimalExotico::setCidadeOrigem(string cidade_origem){
	m_cidade_origem = cidade_origem;
}

string AnimalExotico::getAutorizacaoIbama(){
	return m_autorizacao_ibama;
}

string AnimalExotico::getPaisOrigem(){
	return m_pais_origem;
}

string AnimalExotico::getCidadeOrigem(){
	return m_cidade_origem;
}

void AnimalExotico::setAutorizacaoIbama(string autorizacao_ibama){
	m_autorizacao_ibama = autorizacao_ibama;
}