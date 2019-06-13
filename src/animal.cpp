#include <iostream>
#include "../include/animal/animal.h"

string Animal::getClasse(){
	return m_classe;
}

char Animal::getSexo(){
	return m_sexo;
}

string Animal::getClassificacao(){
	return m_classificacao;
}

void Animal::setId(int id){
	m_id = id;
}

void Animal::setClasse(string classe){
	m_classe = classe;
}

void Animal::setClassificacao(string classificacao){
	m_classificacao = classificacao;
}

void Animal::setNomeCientifico(string nome_cientifico){
	m_nome_cientifico = nome_cientifico;
}

void Animal::setSexo(char sexo){
	m_sexo = sexo;
}

void Animal::setTamanho(double tamanho){
	m_tamanho = tamanho;
}

void Animal::setDieta(string dieta){
	m_dieta = dieta;
}

void Animal::setIdVeterinario(int tem_veterinario){
	m_tem_veterinario = tem_veterinario;
}

void Animal::setIdTratador(int tem_tratador){
	m_tem_tratador = tem_tratador;
}

void Animal::setNomeBatismo(string nome_batismo){
	m_nome_batismo = nome_batismo;
}