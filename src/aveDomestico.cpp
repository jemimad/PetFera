#include "aveDomestico.h"
/**@brief Implementação do construtor de avedomestica */
AveDomestico::AveDomestico(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, double tamanho_bico_cm, double envergadura_asas):
			Ave(id, classe, classificacao, nome_cientifico, sexo, tamanho, dieta, tem_veterinario, tem_tratador, nome_batismo, tamanho_bico_cm, envergadura_asas){
}
/**@brief Implementação do destrutor de avedomestica */
AveDomestico::~AveDomestico(){}
/**@brief sobrecarga de operador de inserção para listagem e para salvar no arquivo*/
ostream& AveDomestico::listar_animais(ostream& os) const{
	os << "| ID: " << m_id << 
    " | Classe: " << m_classe << 
    " | Classificação: "<< m_classificacao << 
    " | Nome Científico: " <<  m_nome_cientifico << 
    " | Sexo: " << m_sexo << 
    " | Tamanho em metros: " << m_tamanho << 
    " | Dieta: " << m_dieta << 
    " | ID Veterinário: " << m_tem_veterinario << 
    " | ID Tratador: " << m_tem_tratador << 
    " | Nome de Batismo: " << m_nome_batismo << 
    " | Tamanho do Bico em cm: " << m_tamanho_bico_cm <<
	" | Envergadura das Asas: " << m_envergadura_asas << "\n\n";

	return os;
}

ofstream& AveDomestico::salvar_animais(ofstream& out) const{
	out << m_id << ";" << m_classe << ";" << m_classificacao << ";" <<  m_nome_cientifico << ";" << m_sexo 
	<< ";" << m_tamanho << ";" << m_dieta << ";" << m_tem_veterinario << ";" << m_tem_tratador 
	<< ";" << m_nome_batismo << ";" << m_tamanho_bico_cm << ";" << m_envergadura_asas << 
	";" << "\n";

	return out;
}