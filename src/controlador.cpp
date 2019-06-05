#include <string>
#include <map>
#include <utility>
#include <iterator>

#include "../include/animal.h"
#include "../include/funcionario.h"
#include "../include/controlador.h"

#include "construtores.cpp"
using namespace std;
using std::string;


//
enum Classes{
    Classe_invalida,
    Mamifero,
    Anfibio,
    Reptil,
    Ave
};

Classes resolveOption(string input) {
    if( input == "Mamifero" || input == "mamifero" || input == "Mamífero") return Mamifero;
    if( input == "Anfibio" || input == "anfibio" || input == "Anfíbio") return Anfibio;
    if( input == "Reptil" || input == "reptil" || input == "Réptil") return Reptil;
    if( input == "Ave" || input == "ave" || input == "AVE") return Ave;

    return Classe_invalida;
 }


void Controlador::addFuncionario(int opc){
	int id;
	string nome, cpf, especialidade;
	short idade;
	char tipoSanguineo;
	char fatorRH;

	cout << "ID: " << endl;
	cin >> id;

	cout << "Nome: " << endl;
	cin.ignore();
	getline(cin, nome);

	cout << "CPF: " << endl;
	cin >> cpf;

	cout << "Idade: " << endl;
	cin >> idade;

	cout << "Tipo Sanguineo: " << endl;
	cin >> tipoSanguineo;

	cout << "Fator RH: " << endl;
	cin >> fatorRH;

	cout << "Especialidade: " << endl;
	cin >> especialidade;

	if(opc == 1){
		int nivelSeguranca;
		string funcao = "Tratador";

		cout << "Nivel de Segurança: " << endl;
		cin >> nivelSeguranca;

		Funcionario* func = new Tratador(id, funcao, nome, cpf, idade, tipoSanguineo, 
							fatorRH, especialidade, nivelSeguranca);
		lista_funcionarios.insert({id, func});
		cout << "Tratador adicionado com sucesso!" << endl;

	} else {
		string cmrv;
		string funcao = "Veterinario";

		cout << "CMRV: " << endl;
		cin >> cmrv;

		Funcionario* func = new Veterinario(id, funcao, nome, cpf, idade, 
							tipoSanguineo, fatorRH, especialidade, cmrv);
		lista_funcionarios.insert({id, func});
		cout << "Veterinário adicionado com sucesso!" << endl;
	}
}


/*void Controlador::removerFuncionario(){
}*/


//	AJEITAR USANDO FUNCTOR
void Controlador::listarFuncionarios(int opc){
	map<int, Funcionario*>::iterator it;

	if(opc == 1){
		for(it = lista_funcionarios.begin(); it != lista_funcionarios.end(); it++){
			Funcionario* func = it->second;
			//if(it->m_funcao == "Tratador"){

				//Tratador t = *(it);
				//aqui tem que fazer um cast
			//lalalalalal
				//TA IMPRIMINDO O ENDEREÇO
				cout << func;
			//}
		}

	}
}


void Controlador::addAnimal(){
	int id;
	string classe;
	string nome_cientifico;
	char sexo;
	double tamanho;
	string dieta;
	int tem_veterinario;
	int tem_tratador;
	string nome_batismo;
	
	//Nativo
	string uf_origem;

	//Exotico 
	string pais_origem;
	string cidade_origem;

	bool nativo;
	int opc;

	//Silvestre:
	string autorizacao_ibama;

	cout << "ID: " << endl;
	cin >> id;

	cout << "Classe: " << endl;
	cin >> classe;

	cout << "Nome Científico: " << endl;
	cin >> nome_cientifico;

	cout << "Sexo: " << endl;
	cin >> sexo;

	cout << "Tamanho: " << endl;
	cin >> tamanho;

	cout << "Dieta: " << endl;
	cin >> dieta;

	cout << "Possui veterinário? 0 - Não | 1 - Sim  " << endl;
	cin >> tem_veterinario;

	cout << "Possui tratador? 0 - Não | 1 - Sim " << endl;
	cin >> tem_tratador;

	cout << "Nome de batismo: " << endl;
	cin >> nome_batismo;

	cout << "Autorização do IBAMA: " << endl;
	cin >> autorizacao_ibama;

	cout << "Este animal é:" << endl << 
		"1- Nativo" << endl <<
		"2- Exotico" << endl;
	cin >> opc;



	switch(opc){
		case 1: {
			cout << "UF de Origem:" << endl;
			cin >> uf_origem;

			nativo = true;

			break;
		}
		case 2: {	
			cout << "País de Origem:" << endl;
			cin >> pais_origem;

			cout << "Cidade de Origem:" << endl;
			cin >> cidade_origem;

			nativo = false;

			break;	
		}
	}




	switch(resolveOption(classe)){
	    case Mamifero: {
	       	string cor_pelo;
			cout << "Cor do Pelo:" << endl;
			cin >> cor_pelo;

			if(nativo == true){
				Animal* animal = new MamiferoNativo(id, classe, nome_cientifico, sexo, tamanho, 
													dieta, tem_veterinario, tem_tratador, nome_batismo,
													cor_pelo, autorizacao_ibama, uf_origem);
				lista_animais.insert({id, animal});
				

			} else {

				Animal* animal = new MamiferoExotico(id, classe, nome_cientifico, sexo, tamanho,
													dieta, tem_veterinario, tem_tratador, nome_batismo, 
													cor_pelo, autorizacao_ibama, pais_origem, cidade_origem);
				lista_animais.insert({id, animal});
			}
	
	    	break;
	    }

	    case Anfibio: {
	        int total_de_mudas;
			cout << "Total de Mudas:" << endl;
			cin >> total_de_mudas;	

			if(nativo == true){
				Animal* animal = new AnfibioNativo(id, classe, nome_cientifico, sexo, tamanho, 
													dieta, tem_veterinario, tem_tratador, nome_batismo,
													total_de_mudas, autorizacao_ibama, uf_origem);
				lista_animais.insert({id, animal});
				

			} else {

				Animal* animal = new AnfibioExotico(id, classe, nome_cientifico, sexo, tamanho,
													dieta, tem_veterinario, tem_tratador, nome_batismo, 
													total_de_mudas, autorizacao_ibama, pais_origem, cidade_origem);
				lista_animais.insert({id, animal});
			}


	    	break;
	    }

        case Reptil: {
       		bool venenoso;
			string tipo_veneno;

			cout << "É venenoso? True/False" << endl;
			cin >> venenoso;

			if(venenoso == true){
				cout << "Tipo de veneno" << endl;
				cin >> tipo_veneno;
			} else {
				tipo_veneno = "Não possui veneno.";
			}

			if(nativo == true){
				Animal* animal = new ReptilNativo(id, classe, nome_cientifico, sexo, tamanho, 
											dieta, tem_veterinario, tem_tratador, nome_batismo,
											venenoso, tipo_veneno, autorizacao_ibama, uf_origem);
				lista_animais.insert({id, animal});
				

			} else {

				Animal* animal = new ReptilExotico(id, classe, nome_cientifico, sexo, tamanho,
													dieta, tem_veterinario, tem_tratador, nome_batismo, 
													venenoso, tipo_veneno, autorizacao_ibama, pais_origem, cidade_origem);
				lista_animais.insert({id, animal});
			}
        	break;
   		}

        case Ave: {
        	double tamanho_bico_cm;
			double envergadura_asas;

			cout << "Tamanho do bico (em cm)" << endl;
			cin >> tamanho_bico_cm;				

			cout << "Envergadura das asas" << endl;
			cin >> envergadura_asas;

			if(nativo == true){
				Animal* animal = new AveNativo(id, classe, nome_cientifico, sexo, tamanho, 
											dieta, tem_veterinario, tem_tratador, nome_batismo,
											tamanho_bico_cm, envergadura_asas, autorizacao_ibama, uf_origem);
				lista_animais.insert({id, animal});
				

			} else {

				Animal* animal = new AveExotico(id, classe, nome_cientifico, sexo, tamanho,
												dieta, tem_veterinario, tem_tratador, nome_batismo, 
												tamanho_bico_cm, envergadura_asas, autorizacao_ibama, pais_origem, cidade_origem);
				lista_animais.insert({id, animal});
			}
        	break;
    	}

    	case Classe_invalida: {
  			cout << "Essa classe não existe!" << endl;
        	break;
    	}

    	default: {
        break;
    	}
	}

	
	cout << "Animal adicionado com sucesso!" << endl;


} 

//	AJEITAR USANDO FUNCTOR
void Controlador::listarAnimais(){
	map<int, Animal*>::iterator it;

		for(it = lista_animais.begin(); it != lista_animais.end(); it++){
			Animal* animal = it->second;
			//if(it->m_funcao == "Tratador"){

				//Tratador t = *(it);
				//aqui tem que fazer um cast
			//lalalalalal
				//TA IMPRIMINDO O ENDEREÇO
				cout << animal;
			//}
		}

	}

