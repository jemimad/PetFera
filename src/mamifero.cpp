#include "mamifero.h"
/**@brief Implementação do construtor de mamifero */
Mamifero::Mamifero(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, string cor_pelo): 
			Animal(id, classe, classificacao, nome_cientifico, sexo, tamanho, dieta, tem_veterinario, tem_tratador, nome_batismo),
			m_cor_pelo(cor_pelo){
}
/**@brief Implementação do destrutor de mamifero */
Mamifero::~Mamifero(){}
/**@brief metodos get e set de mamifero */
void Mamifero::setCorPelo(string cor_pelo_){
	m_cor_pelo = cor_pelo_;
}

string Mamifero::getCorPelo(){
	return m_cor_pelo;
}

