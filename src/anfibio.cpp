#include "anfibio.h"
/**@brief Implementação do construtor de anfibio*/
Anfibio::Anfibio(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, int total_mudas): 
			Animal(id, classe, classificacao, nome_cientifico, sexo, tamanho, dieta, tem_veterinario, tem_tratador, nome_batismo),
			m_total_mudas(total_mudas){
}

Anfibio::~Anfibio(){}
/**@brief Destrutor de anfibio */
/**@brief Implementação dos metodos get e set de TotalMudas */
void Anfibio::setTotalMudas(int total_mudas_){
	m_total_mudas = total_mudas_; 
}

int Anfibio::getTotalMudas(){
	return m_total_mudas;
}