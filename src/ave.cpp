#include "ave.h"

/**@brief Implementação do construtor de ave */
Ave::Ave(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, double tamanho_bico_cm, double envergadura_asas): 
			Animal(id, classe, classificacao, nome_cientifico, sexo, tamanho, dieta, tem_veterinario, tem_tratador, nome_batismo),
			m_tamanho_bico_cm(tamanho_bico_cm), m_envergadura_asas(envergadura_asas){
}
/**@brief Implemnetação do destrutor de ave */
Ave::~Ave(){}
/**@brief Implementação metodos set's e get's de ave */
void Ave::setTamanhoBico(double tamanho_bico_cm_){
	m_tamanho_bico_cm = tamanho_bico_cm_;
}

void Ave::setEnvergaduraAsas(double envergadura_asas_){
	m_envergadura_asas = envergadura_asas_;
}

double Ave::getTamanhoBico(){
	return m_tamanho_bico_cm;
}

double Ave::getEnvergaduraAsas(){
	return m_envergadura_asas;
}