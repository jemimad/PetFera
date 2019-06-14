#include "reptilExotico.h"

ReptilExotico::ReptilExotico(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, bool venenoso, string tipo_veneno, string autorizacao_ibama, string pais_origem, string cidade_origem): 
			Reptil(id, classe,  classificacao, nome_cientifico, sexo, tamanho, dieta, tem_veterinario, tem_tratador, nome_batismo,
			venenoso,tipo_veneno),
			AnimalExotico(autorizacao_ibama, pais_origem, cidade_origem){
}

ReptilExotico::~ReptilExotico(){}

ostream& ReptilExotico::listar_animais(ostream& os) const{
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
	"\nVenenoso: " << m_venenoso << 
	"\nTipo de veneno: " << m_tipo_veneno <<  
	"\nAutorização do IBAMA: " << m_autorizacao_ibama << 
	"\nPaís de Origem: " << m_pais_origem << 
	"\nCidade de Origem: " << m_cidade_origem << "\n\n";

	return os;
}

ofstream& ReptilExotico::salvar_animais(ofstream& out) const{
	out << m_id << ";" << m_classe << ";" << m_classificacao << ";" << m_nome_cientifico << ";" << m_sexo 
	<< ";" << m_tamanho << ";" << m_dieta << ";" << m_tem_veterinario << ";" << m_tem_tratador 
	<< ";" << m_nome_batismo << ";" << m_venenoso << ";" << m_tipo_veneno << 
	";" << m_autorizacao_ibama << ";" << m_pais_origem << ";" << m_cidade_origem <<"\n";

	return out;
}