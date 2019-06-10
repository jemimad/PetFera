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
		bool verificarId(int id);

	protected:
		map<int, Funcionario*> lista_funcionarios;
		map<int, Animal*> lista_animais;

	public:
		void abrirPetshop();

		void addFuncionario(int opc);
		void exibirMenu();
		void listarFuncionarios(int opc);
		void removerFuncionario();
		void consultarFuncionario();

		void addAnimal();
		void listarAnimais();
		void removerAnimal();

		~Controlador();
		Controlador();
	
	
};


#endif