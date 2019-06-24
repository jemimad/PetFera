#include "anfibioDomestico.h"

AnfibioDomestico::AnfibioDomestico(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
            double tamanho, string dieta, int tem_veterinario, int tem_tratador,
            string nome_batismo, int total_mudas):
            Anfibio(id, classe, classificacao, nome_cientifico, sexo, tamanho, dieta, tem_veterinario, tem_tratador, nome_batismo, total_mudas){
}

AnfibioDomestico::~AnfibioDomestico(){}

ostream& AnfibioDomestico::listar_animais(ostream& os) const{
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
    " | Total de Mudas: " << m_total_mudas << "|\n\n";

    return os;
}

ofstream& AnfibioDomestico::salvar_animais(ofstream& out) const{
    out << m_id << ";" << m_classe << ";"  << m_classificacao << ";" <<  m_nome_cientifico << ";" << m_sexo 
    << ";" << m_tamanho << ";" << m_dieta << ";" << m_tem_veterinario << ";" << m_tem_tratador 
    << ";" << m_nome_batismo << ";" << m_total_mudas << "\n";

    return out;
}