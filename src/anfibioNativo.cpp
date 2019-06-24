#include "anfibioNativo.h"

AnfibioNativo::AnfibioNativo(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, int total_mudas, string autorizacao_ibama, string uf_origem): 
			Anfibio(id, classe, classificacao, nome_cientifico, sexo, tamanho, dieta, tem_veterinario, tem_tratador, nome_batismo, total_mudas),
			AnimalNativo(autorizacao_ibama, uf_origem){
}


AnfibioNativo::~AnfibioNativo(){}

ostream& AnfibioNativo::listar_animais(ostream& os) const{
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
	" | UF de Origem: " << m_uf_origem << "|\n\n";
	
	return os;
}

ofstream& AnfibioNativo::salvar_animais(ofstream& out) const{
	out << m_id << ";" << m_classe << ";" << m_classificacao << ";" << m_nome_cientifico << ";" << m_sexo <<
	";" << m_tamanho << ";" << m_dieta << ";" << m_tem_veterinario << ";" << m_tem_tratador <<
	";" << m_nome_batismo << ";" << m_total_mudas << ";" << m_autorizacao_ibama << 
	";" << m_uf_origem << "\n";

	return out;
}
