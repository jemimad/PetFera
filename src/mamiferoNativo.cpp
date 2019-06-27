#include "mamiferoNativo.h"
/**@brief implementação do construtor e destrutor de mamiferonativo */
MamiferoNativo::MamiferoNativo(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, string cor_pelo, string autorizacao_ibama, string uf_origem):
			Mamifero(id, classe, classificacao, nome_cientifico, sexo, tamanho, dieta, tem_veterinario, tem_tratador, nome_batismo, cor_pelo),
			AnimalNativo(autorizacao_ibama, uf_origem){
}

MamiferoNativo::~MamiferoNativo(){}
/**@brief sobrecarga de operador de inserção para listagem e para salvar no arquivo*/
ostream& MamiferoNativo::listar_animais(ostream& os) const{
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
	" |	Cor do Pelo: " << m_cor_pelo <<
	" | Autorização do IBAMA: " << m_autorizacao_ibama <<   
	" | UF de Origem: " << m_uf_origem << " |\n\n";

	return os;
}

ofstream& MamiferoNativo::salvar_animais(ofstream& out) const{
	out << m_id << ";" << m_classe << ";" << m_classificacao << ";" <<  m_nome_cientifico << ";" << m_sexo 
	<< ";" << m_tamanho << ";" << m_dieta << ";" << m_tem_veterinario << ";" << m_tem_tratador 
	<< ";" << m_nome_batismo << ";" << m_cor_pelo << 
	";" << m_autorizacao_ibama << ";" << m_uf_origem << "\n";

	return out;
}
/**@brief metodo get da classe mamiferonativo */
string MamiferoNativo::getAutorizacaoIbama(){
	return m_autorizacao_ibama;
}