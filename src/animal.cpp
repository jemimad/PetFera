#include <iostream>
#include "animal.h"

Animal::Animal(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo): m_id(id), m_classe(classe), m_classificacao(classificacao), m_nome_cientifico(nome_cientifico),
			m_sexo(sexo), m_tamanho(tamanho), m_dieta(dieta), m_tem_veterinario(tem_veterinario),
			m_tem_tratador(tem_tratador), m_nome_batismo(nome_batismo){
}

Animal::~Animal(){}

ostream& operator<<(ostream& os, const Animal& a){
	return a.listar_animais(os);
}

ofstream& operator<<(ofstream& out, const Animal& a){
	return a.salvar_animais(out);
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
//

string Animal::getClasse(){
	return m_classe;
}

char Animal::getSexo(){
	return m_sexo;
}

string Animal::getClassificacao(){
	return m_classificacao;
}

string Animal::getNomeCientifico(){
	return m_nome_cientifico;
}


double Animal::getTamanho(){
	return m_tamanho;
}

string Animal::getDieta(){
	return m_dieta;
}

int Animal::getIdVeterinario(){
	return m_tem_veterinario;
}

int Animal::getIdTratador(){
	return m_tem_tratador;
}

string Animal::getNomeBatismo(){
	return m_nome_batismo;
}