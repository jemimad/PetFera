#ifndef _CONTROLADOR_
#define _CONTROLADOR_
#include <iostream>
#include <string>
#include <map>


using std::string;
using std::map;

class Controlador{
	private:
		void exibirMenuAnimais();
		void exibirMenuFuncionarios();
		bool verificarIdFuncionario(int id);
		bool verificarIdAnimal(int id);

	protected:
		map<int, Funcionario*> lista_funcionarios;
		map<int, Animal*> lista_animais;

	public:
		void abrirPetshop();
		void exibirMenu();
		void salvarDadosAnimais();
		void salvarDadosFuncionarios();

		void addFuncionario(int opc);
		void listarFuncionarios(int opc);
		void removerFuncionario();
		void consultarFuncionario();

		void addAnimal();
		void listarAnimais(int opc);
		void removerAnimal();
		void consultarAnimal();

		~Controlador();
		Controlador();
	
	
};


#endif