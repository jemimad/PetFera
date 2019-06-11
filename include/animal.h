#ifndef _ANIMAL_
#define _ANIMAL_

#include <iostream>
#include <string>
#include <fstream>

class Animal{
	protected:
		int m_id;
		string m_classe;
		string m_nome_cientifico;
		char m_sexo;
		double m_tamanho;
		string m_dieta;
		int m_tem_veterinario;
		int m_tem_tratador;
		string m_nome_batismo;

		virtual ostream& listar_animais(ostream& os) const = 0;
		virtual ofstream& salvar_animais(ofstream& out) const = 0;


	public:

		Animal();
		Animal(int id, string classe, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo);
		~Animal();


		virtual string getClasse() = 0;
		virtual char getSexo() = 0;
		
		int getId();
		string getNomeCientifico();
		double getTamanho();
		string getDieta();
		string getNomeBatismo();

		friend ostream& operator<<(ostream& os, const Animal& a);
		friend ofstream& operator<<(ofstream& out, const Animal& a);
};

ostream& operator<<(ostream& os, const Animal& a){
	return a.listar_animais(os);
}

ofstream& operator<<(ofstream& out, const Animal& a){
	return a.salvar_animais(out);
}



#endif
