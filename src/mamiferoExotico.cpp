#include "mamiferoExotico.h"

MamiferoExotico::MamiferoExotico(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, string cor_pelo, string autorizacao_ibama, string pais_origem, string cidade_origem):
			Mamifero(id, classe, classificacao, nome_cientifico, sexo, tamanho, dieta, tem_veterinario, tem_tratador, nome_batismo, cor_pelo),
			AnimalExotico(autorizacao_ibama, pais_origem, cidade_origem){
}

MamiferoExotico::~MamiferoExotico(){}

ostream& MamiferoExotico::listar_animais(ostream& os) const{
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
	" | Cor do Pelo: " << m_cor_pelo <<
	" | Autorização do IBAMA: " << m_autorizacao_ibama <<   
	" | País de Origem: " << m_pais_origem << 
	" | Cidade de Origem: " << m_cidade_origem << " |\n\n";

	return os;
}

ofstream& MamiferoExotico::salvar_animais(ofstream& out) const{
	out << m_id << ";" << m_classe << ";" << m_classificacao << ";" <<  m_nome_cientifico << ";" << m_sexo 
	<< ";" << m_tamanho << ";" << m_dieta << ";" << m_tem_veterinario << ";" << m_tem_tratador 
	<< ";" << m_nome_batismo << ";" << m_cor_pelo << 
	";" << m_autorizacao_ibama << ";" << m_pais_origem << ";" << m_cidade_origem << "\n";

	return out;
}