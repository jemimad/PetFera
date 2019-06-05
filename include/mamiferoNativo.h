#ifndef _MAMIFERO_NATIVO_
#define _MAMIFERO_NATIVO_

#include <iostream>
#include "mamifero.h"
#include "animalNativo.h"

class MamiferoNativo : public Mamifero, AnimalNativo{
	public:
		MamiferoNativo(int id, string classe, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, string cor_pelo, string autorizacao_ibama, string uf_origem);
		MamiferoNativo();
		~MamiferoNativo();

		friend ostream& operator<<(ostream& os,  MamiferoNativo& mn);

};


//SOBRECARGA(
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
}


#endif