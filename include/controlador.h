#ifndef _CONTROLADOR_
#define _CONTROLADOR_
#include <iostream>
#include <string>
#include <map>


using std::string;
using std::map;

class Controlador{

	protected:
		map<int, Funcionario*> lista_funcionarios;
		map<int, Animal*> lista_animais;

		bool verificarId(int id);

	public:
		void abrirPetshop();

		void addFuncionario(int opc);
		void exibirMenu();
		void listarFuncionarios(int opc);
		void removerFuncionario();

		void addAnimal();
		void listarAnimais();
		void removerAnimal();
		//void listarDadosFuncionarios();
	

		~Controlador();
		Controlador();
		friend ostream& operator<<(ostream& os,  Funcionario& func);
	
};


/*//SOBRECARGA(
ostream& operator<<(ostream& o,  Funcionario& func){
	o << "ID:" << func.m_id << "\nNome: " <<  func.m_nome << "\nCPF: " <<
	func.m_cpf << "\nIdade: " << func.m_idade << "\nTipo Sanguineo: " <<
	func.m_tipoSanguineo << "\nFator RH: " << func.m_fatorRH <<
	"\nEspecialidade: " << func.m_especialidade;
 
	return o;
}*/


#endif