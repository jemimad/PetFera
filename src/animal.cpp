#include <iostream>
#include "animal.h"

Animal::Animal():;

Animal::Animal(int id, string classe, string nome_cientifico,char sexo, 
			double tamanho, string dieta, Veterinario veterinario, Tratador tratador,
			string nome_batismo): m_id(id), m_classe(classe), m_nome_cientifico(nome_cientifico),
			m_sexo(sexo), m_tamanho(tamanho), m_dieta(dieta), m_veterinario(veterinario),
			m_tratador(tratador), m_nome_batismo(nome_batismo){
}

Animal::~Animal(){
}

int Animal::getId(){
	return m_id;
}

string Animal::getClasse(){
	return m_classe;
}

string Animal::getNomeCientifico(){
	return m_nome_cientifico;
}

char Animal::getSexo(){
	return m_sexo;
}

double Animal::getTamanho(){
	return m_tamanho;
}

string Animal::getDieta(){
	return m_dieta;
}

string Animal::getNomeBatismo(){
	return m_nome_batismo;
}

//não botei get pra Tratador ou Veterinario porque na minha cabeça não fazia sentido