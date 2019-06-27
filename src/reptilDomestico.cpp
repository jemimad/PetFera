#include "reptilDomestico.h"
/**@brief implementação do construtor e destrutor de reptil domestico */
ReptilDomestico::ReptilDomestico(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, bool venenoso, string tipo_veneno):
			Reptil(id, classe, classificacao, nome_cientifico, sexo, tamanho, dieta, tem_veterinario, tem_tratador, nome_batismo, venenoso, tipo_veneno){
}

ReptilDomestico::~ReptilDomestico(){}
/**@brief sobrecarga de operador de inserção para listagem e para salvar no arquivo*/
ostream& ReptilDomestico::listar_animais(ostream& os) const{
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
	" | Venenoso: " << m_venenoso <<
	" | Tipo de veneno: " << m_tipo_veneno << "|\n\n";

	return os;
}

ofstream& ReptilDomestico::salvar_animais(ofstream& out) const{
	out << m_id << ";" << m_classe << ";" << m_classificacao << ";" <<  m_nome_cientifico << ";" << m_sexo 
	<< ";" << m_tamanho << ";" << m_dieta << ";" << m_tem_veterinario << ";" << m_tem_tratador 
	<< ";" << m_nome_batismo << ";" << m_venenoso << ";" << m_tipo_veneno  << "\n";

	return out;
}