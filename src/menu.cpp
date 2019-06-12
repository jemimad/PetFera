#include <iostream>

#include <stdlib.h>
using namespace std;
#include "controlador.cpp"

void Controlador::exibirMenu(){
	int opc_Menu_Principal;


	cout << "--------- PetFera ----------\n "<<
			"1 - Setor de Animais\n " <<
			"2 - Setor de Funcionários\n " << 
			"3 - Sair" << endl;
	cin >> opc_Menu_Principal;

	switch (opc_Menu_Principal){
		case 1:
			exibirMenuAnimais();
			
		case 2:
			exibirMenuFuncionarios();
		break;

		case 3:
			salvarDadosAnimais();
			salvarDadosFuncionarios();
			exit(0);
		break;

		default:
			cout << "Não existe essa opção no menu." << endl;
	}		

	exibirMenu();

}

void Controlador::exibirMenuAnimais(){
	int opc_Menu_Animal, opc_Menu_Animal_Listagem;

	cout << "--------- Animais ----------\n " <<
					"1 - Adicionar animal\n " <<
					"2 - Remover animal\n " <<
					"3 - Consultar animal\n " <<
					"4 - Listagem de animais\n " <<
					"5 - Alterar dados de um animal\n " 
					"6 - Voltar ao menu principal" << endl;
	cin >> opc_Menu_Animal;
	switch (opc_Menu_Animal){
		case 1:
			cout << "--------- Adicionar animal----------\n " <<
				"Informe os dados sobre o seu animal:" << endl;
			addAnimal();
			exibirMenuAnimais();
		break;

		case 2:
			cout << "--------- Remover animal ----------\n " <<
				"Insira o id do animal a ser removido:" << endl;
			removerAnimal();
			exibirMenuAnimais();
		break;

		case 3:
			cout << "--------- Consultar animal ----------\n " <<
				"Insira o id do animal a ser consultado:" << endl;
			consultarAnimal();
			exibirMenuAnimais();
		break;

		case 4:
			cout << "--------- Listagem de animais ----------\n " <<
					"1 - Listagem por classe\n " <<
					"2 - Listagem por sexo\n " << 
					"3 - Listagem por classificação\n" <<
					"4 - Listagem geral\n" << endl;
			cin >> opc_Menu_Animal_Listagem;
			listarAnimais(opc_Menu_Animal_Listagem);
			exibirMenuAnimais();
		break;
		case 5:
			cout << "--------- Alterar dados de um animal ----------\n " <<
				"Insira o id do animal a ser alterado:" << endl;
		break;
		
		case 6:
			exibirMenu();
		break;
		
		default:
			cout << "Não existe essa opção no menu." << endl;
			exibirMenuAnimais();
		break;

	}
}

void Controlador::exibirMenuFuncionarios(){
	int opc_Menu_Funcionario,opc_Menu_Funcionario_add, opc_Menu_Funcionario_Listagem, opc_Menu_Funcionario_Listagem_Funcao;

	cout << "--------- Funcionários ----------\n " <<
			"1- Adicionar funcionário\n " <<
			"2- Remover funcionário\n " <<
			"3- Consultar funcionário\n " <<
			"4- Listagem de funcionários\n " <<
			"5- Alterar dados de funcionários\n " <<
			"6- Voltar ao menu principal\n " << endl;
	cin >> opc_Menu_Funcionario;

	switch (opc_Menu_Funcionario){
		case 1:
			cout << "--------- Adicionar funcionário ----------\n " <<
					"1- Adicionar tratador\n " <<
					"2- Adicionar veterinário" << endl;
			cin >> opc_Menu_Funcionario_add;
			switch (opc_Menu_Funcionario_add){
				case 1:
					cout << "--------- Adicionar tratador ----------\n " <<
						"Insira os dados sobre o tratador:" << endl;
					addFuncionario(1);
				break;

				case 2:
					cout << "--------- Adicionar veterinário----------\n " <<
							"Insira os dados sobre o veterinário:" << endl;
					addFuncionario(2);
				break;

				default:
					cout << "Essa opção não existe no Menu, tente novamente" << endl;
					exibirMenuFuncionarios();
				break;
			}
		break;
			
		case 2:
			cout << "--------- Remover funcionário ----------\n " << endl;
			removerFuncionario();
		break;
			
		case 3:
			cout << "--------- Consultar funcionário ----------\n " << endl;
			consultarFuncionario();
		break;
			
		case 4:
			cout << "--------- Listagem de funcionários ----------\n" <<
				"1- Listagem por função\n" <<
				"2- Listagem geral" << endl;
			cin >> opc_Menu_Funcionario_Listagem;

			switch (opc_Menu_Funcionario_Listagem){
				case 1:
					cout << "--------- Listagem por função ----------\n"  <<
						"1 - Tratador\n" <<
						"2 - Veterinário" << endl;
					cin >> opc_Menu_Funcionario_Listagem_Funcao;
					listarFuncionarios(opc_Menu_Funcionario_Listagem_Funcao);
				break;
					
				case 2:
					cout << "--------- Listagem geral ----------\n ";
					listarFuncionarios(3);
				break;

				default:
					cout << "Não existe essa opção no menu." << endl;
					exibirMenuFuncionarios();
				break;
			}
		break;
			
		case 5:
			cout << "--------- Alterar dados de um Funcionário  ----------\n " << endl;
						
		break;
		
		case 6:
			exibirMenu();
		break;	
		
		default:
			cout << "Não existe essa opção no menu." << endl;
			exibirMenuFuncionarios();
		break;
	}
}