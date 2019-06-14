#include "anfibioExotico.h"


AnfibioExotico::AnfibioExotico(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, int total_mudas, string autorizacao_ibama, string pais_origem, string cidade_origem): 
			Anfibio(id, classe, classificacao, nome_cientifico, sexo, tamanho, dieta, tem_veterinario, tem_tratador, nome_batismo, total_mudas),
			AnimalExotico(autorizacao_ibama, pais_origem, cidade_origem){
}

AnfibioExotico::~AnfibioExotico(){}

ostream& AnfibioExotico::listar_animais(ostream& os) const{
	os << "ID:" << m_id << 
	"\nClasse: " << m_classe << 
	"\nClassificação: " << m_classificacao << 
	"\nNome Científico: " <<  m_nome_cientifico << 
	"\nSexo: " << m_sexo << 
	"\nTamanho em metros: " << m_tamanho << 
	"\nDieta: " << m_dieta << 
	"\nID Veterinário: " << m_tem_veterinario << 
	"\nID Tratador: " << m_tem_tratador << 
	"\nNome de Batismo: " << m_nome_batismo << 
	"\nTotal de Mudas: " << m_total_mudas << 
	"\nAutorização do IBAMA: " << m_autorizacao_ibama << 
	"\nPaís de Origem: " << m_pais_origem << 
	"\nCidade de Origem: " << m_cidade_origem << "\n\n";

	return os;
}

ofstream& AnfibioExotico::salvar_animais(ofstream& out) const{
	out << m_id << ";" << m_classe << ";" << ";" << m_classificacao << ";" <<  m_nome_cientifico << ";" << m_sexo 
	<< ";" << m_tamanho << ";" << m_dieta << ";" << m_tem_veterinario << ";" << m_tem_tratador 
	<< ";" << m_nome_batismo << ";" << m_total_mudas <<
	";" << m_autorizacao_ibama << ";" << m_pais_origem << ";" << m_cidade_origem << "\n";

	return out;
}