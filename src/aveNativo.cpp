#include "aveNativo.h"
/**@brief implementação do construtor de avenativo*/
AveNativo::AveNativo(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, double tamanho_bico_cm, double envergadura_asas, string autorizacao_ibama, string uf_origem): 
			Ave(id, classe, classificacao, nome_cientifico, sexo, tamanho, dieta, tem_veterinario, tem_tratador, nome_batismo, tamanho_bico_cm, envergadura_asas),
			AnimalNativo(autorizacao_ibama, uf_origem){
}
/**@brief implementação do destrutor de avenativo */
AveNativo::~AveNativo(){}
/**@brief sobrecarga de operador de inserção para listagem e para salvar no arquivo*/
ostream& AveNativo::listar_animais(ostream& os) const{
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
	" | Envergadura das Asas: " << m_envergadura_asas <<
	" | Autorizacao IBAMA: " << m_autorizacao_ibama <<
	" | UF de Origem: " << m_uf_origem << "|\n\n";

	return os;
}

ofstream& AveNativo::salvar_animais(ofstream& out) const{
	out << m_id << ";" << m_classe << ";" << m_classificacao << ";" << m_nome_cientifico << ";" << m_sexo 
	<< ";" << m_tamanho << ";" << m_dieta << ";" << m_tem_veterinario << ";" << m_tem_tratador 
	<< ";" << m_nome_batismo << ";" << m_tamanho_bico_cm << ";" << m_envergadura_asas << 
	";" << m_autorizacao_ibama << ";" << m_uf_origem << "\n";

	return out;
}
/**@brief metodo get de ave nativo */
string AveNativo::getAutorizacaoIbama(){
	return m_autorizacao_ibama;
}