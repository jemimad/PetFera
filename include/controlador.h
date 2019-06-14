#ifndef _CONTROLADOR_
#define _CONTROLADOR_
#include <iostream>
#include <string>
#include <map>
#include <string>
#include <map>
#include <utility>
#include <iterator>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "animal.h"
#include "funcionario.h"

using namespace std;
using std::map;

class Controlador{
	private:
		//Função para exibir o menu de animais. Não recebe parâmetro.
		void exibirMenuAnimais();
		
		//Função para exibir o menu de funcionários. Não recebe parâmetro.
		void exibirMenuFuncionarios();

		//Função para verificar se o id inserido para o funcionário já existe. Recebe como parâmetro um id.
		bool verificarIdFuncionario(int id);

		//Função para verificar se o id inserido para o animal já existe. Recebe como parâmetro um id.
		bool verificarIdAnimal(int id);

	protected:
		//Map de funcionários. Insere uma chave (id) e um ponteiro para um objeto da classe Funcionário.
		map<int, Funcionario*> lista_funcionarios;

		//Map de animais. Insere uma chave (id) e um ponteiro para um objeto da classe Animal. 
		map<int, Animal*> lista_animais;

	public:
		
		void abrirPetshop();
		
		//Função para exibir o menu. Não recebe parâmetro.
		void exibirMenu();
		
		//Função para salvar os dados dos animais. Não recebe parâmetro.
		void salvarDadosAnimais();

		//Função para salvar os dados dos funcionários. Não recebe parâmetro.
		void salvarDadosFuncionarios();

		//Função para adicionar funcionário. Recebe como parâmetro a opção de qual funcionário inserir vinda do menu.
		void addFuncionario(int opc);

		//Função para listar funcionário. Recebe como parâmetro a opção de listagem vinda do menu.
		void listarFuncionarios(int opc);

		//Função para remover funcionário. Não recebe parâmetro.
		void removerFuncionario();

		//Função para consultar funcionário. 
		bool consultarFuncionario(int id);

		//Função para editar funcionário. Não recebe parâmetro.
		void editarFuncionario();

		//Função para adicionar animal. Não recebe parâmetro.
		void addAnimal();

		//Função para listar animais. Recebe como parâmetro a opção de listagem vinda do menu.
		void listarAnimais(int opc);

		//Função para remover animal. Não recebe parâmetro.
		void removerAnimal();

		//Função para consultar animal. 
		void consultarAnimal(int id);

		//Função para editar animal. Não recebe parâmetro.
		void editarAnimal();

		//Destrutor da classe controladora.
		~Controlador();

		//Construtor da classe controladora.
		Controlador();
	
	
};


#endif