#include "anfibioExotico.h"

/**@brief Implementação do construtor de anfibioExotico*/
AnfibioExotico::AnfibioExotico(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, int total_mudas, string autorizacao_ibama, string pais_origem, string cidade_origem): 
			Anfibio(id, classe, classificacao, nome_cientifico, sexo, tamanho, dieta, tem_veterinario, tem_tratador, nome_batismo, total_mudas),
			AnimalExotico(autorizacao_ibama, pais_origem, cidade_origem){
}
/**@brief Destrutor da classe AnfibioExotico */
AnfibioExotico::~AnfibioExotico(){}
/**@brief sobrecarga de operador de inserção para listagem e para salvar no arquivo*/
ostream& AnfibioExotico::listar_animais(ostream& os) const{
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
    " | Total de Mudas: " << m_total_mudas <<
	" | Autorizacao IBAMA: " << m_autorizacao_ibama <<
	" | Pais de Origem: " << m_pais_origem <<
	" | Cidade de Origem: " << m_cidade_origem << "|\n\n";
	
	return os;
}

ofstream& AnfibioExotico::salvar_animais(ofstream& out) const{
	out << m_id << ";" << m_classe << ";" << ";" << m_classificacao << ";" <<  m_nome_cientifico << ";" << m_sexo 
	<< ";" << m_tamanho << ";" << m_dieta << ";" << m_tem_veterinario << ";" << m_tem_tratador 
	<< ";" << m_nome_batismo << ";" << m_total_mudas <<
	";" << m_autorizacao_ibama << ";" << m_pais_origem << ";" << m_cidade_origem << "\n";

	return out;
}

