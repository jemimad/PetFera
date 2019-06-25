#include "reptil.h" 

Reptil::Reptil(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, bool venenoso, string tipo_veneno): 
			Animal(id, classe, classificacao, nome_cientifico, sexo, tamanho, dieta, tem_veterinario, tem_tratador, nome_batismo),
			m_venenoso(venenoso), m_tipo_veneno(tipo_veneno){
}

Reptil::~Reptil(){}

void Reptil::setVenenoso(bool venenoso_){
	m_venenoso = venenoso_;
}

void Reptil::setTipoVeneno(string tipo_veneno_){
	m_tipo_veneno = tipo_veneno_;
}


bool Reptil::getVenenoso(){
	return m_venenoso;
}

string Reptil::getTipoVeneno(){
	return m_tipo_veneno;
}