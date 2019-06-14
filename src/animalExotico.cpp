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
