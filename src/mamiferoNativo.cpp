#include "mamiferoNativo.h"

MamiferoNativo::MamiferoNativo(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, string cor_pelo, string autorizacao_ibama, string uf_origem):
			Mamifero(id, classe, classificacao, nome_cientifico, sexo, tamanho, dieta, tem_veterinario, tem_tratador, nome_batismo, cor_pelo),
			AnimalNativo(autorizacao_ibama, uf_origem){
}

MamiferoNativo::~MamiferoNativo(){}

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
/*
ostream& operator<<(ostream& o,  MamiferoNativo& mn){
	o << "ID:" << mn.m_id << 
	"\nClasse" << mn.m_classe << 
	"\nNome: " <<  mn.m_nome_cientifico << 
	"\nSexo: " << mn.m_sexo << 
	"\nTamanho: " << mn.m_tamanho << 
	"\nDieta: " << mn.m_dieta << 
	"\nPossui veterinário: " << mn.m_tem_veterinario << 
	"\nPossui tratador: " << mn.m_tem_tratador << 
	"\nNome Batismo: " << mn.m_nome_batismo <<
	"\nCor do pelo: " << mn.m_cor_pelo <<
	"\nAutorização IBAMA: " << mn.m_autorizacao_ibama <<
	"\nUF de Origem: " << mn.m_uf_origem;

	return o;
}*/