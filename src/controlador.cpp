#include <string>
#include <map>
#include <utility>
#include <iterator>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "../include/animal.h"
#include "../include/funcionario.h"
#include "../include/controlador.h"

#include "construtores.cpp"

using namespace std;
using std::string;


//ENUM 
enum Classes{
    Classe_invalida,
    Mamifero,
    Anfibio,
    Reptil,
    Ave
};

Classes resolveOption(string input) {
    if( input == "Mammalia" || input == "mammalia") return Mamifero;
    if( input == "Amphibia" || input == "amphibia") return Anfibio;
    if( input == "Reptilia" || input == "reptilia") return Reptil;
    if( input == "Ave" || input == "ave") return Ave;
    return Classe_invalida;
 }


/*Essa função vai servir pra ler os dados dos arquivos (tanto de animais quanto de funcionarios)
e guardar esses dados no map, como objeto, para que as operações possam ser realizadas neles.
Não ta dando certo pois: tem que saber como pega cada palavra entre os ; e salva no atributo certo
pra poder construir o objeto certo e depois guardar o objeto certo no map.*/
void Controlador::abrirPetshop(){
	ifstream inputfile_animais;
	string linha;
	inputfile_animais.open("animais.csv");

	if(inputfile_animais.is_open()){
		while(getline(inputfile_animais, linha)){
			cout << linha << endl;
		}
		inputfile_animais.close();
	}else{
		cout << "Arquivo vazio ou inexistente" << endl;
	}

	ifstream inputfile_funcionarios;
	inputfile_funcionarios.open("funcionarios.csv");
	stringstream ss;

	int id;
	string nome, cpf, especialidade, funcao;
	short idade;
	char tipoSanguineo;
	char fatorRH;
	string valor;

	if(inputfile_funcionarios.is_open()){
		while(getline(inputfile_funcionarios, valor)){
			ss << valor;
			ss >> id >> funcao >> nome >>  cpf >> idade >>
				tipoSanguineo >> fatorRH >> especialidade;
			
			cout << valor << endl;
		} 
		inputfile_funcionarios.close();
	}else{
		cout << "Arquivo vazio ou inexistente" << endl;
	}
}

/*Essa função retorna falso se o ID estiver indisponível (já existir um funcionário com esse id)*/
bool Controlador::verificarIdFuncionario(int id){
	map<int, Funcionario*>::iterator it;

  	it = lista_funcionarios.find(id);
	if (it != lista_funcionarios.end()){
		return false;
	} 
	return true;
}

void Controlador::salvarDadosFuncionarios(){
	ofstream outfile; 
	outfile.open("funcionarios.csv");

	for(auto it = lista_funcionarios.begin(); it != lista_funcionarios.end(); it++){
        outfile << *it->second;
    }

	outfile.close();
	cout << "Funcionário adicionado com sucesso!" << endl;
}


void Controlador::addFuncionario(int opc){


	int id;
	string nome, cpf, especialidade;
	short idade;
	char tipoSanguineo;
	char fatorRH;
	bool id_disponivel = true;

	cout << "ID: " << endl;
	cin >> id;
	
	id_disponivel = verificarIdFuncionario(id);
	while(id_disponivel == false){
		cout << "Já existe um funcionário com esse ID, escolha um outro." << endl;
		cin >> id;
		id_disponivel = verificarIdFuncionario(id);
	}


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

		cout << "Nivel de Segurança:\n"
		<<"0 - Aves\n" 
		<<"1 - Aves, Mamíferos e Répteis\n"
		<<"2 - Animais venenosos\n" << endl;
		cin >> nivelSeguranca;

		Funcionario* func = new Tratador(id, funcao, nome, cpf, idade, tipoSanguineo, 
							fatorRH, especialidade, nivelSeguranca);
		lista_funcionarios.insert({id, func});
		

	} else {
		string cmrv;
		string funcao = "Veterinario";

		cout << "CMRV: " << endl;
		cin >> cmrv;

		Funcionario* func = new Veterinario(id, funcao, nome, cpf, idade, 
							tipoSanguineo, fatorRH, especialidade, cmrv);
		lista_funcionarios.insert({id, func});
	}

	salvarDadosFuncionarios();
}


void Controlador::listarFuncionarios(int opc){
	map<int, Funcionario*>::iterator it;

	switch(opc){
		case 1:{
			for(it = lista_funcionarios.begin(); it != lista_funcionarios.end(); it++){
				if(it->second->getFuncao() == "Tratador"){
					cout << *it->second;
				}
			}
			break;
		}
		case 2:{
			for(it = lista_funcionarios.begin(); it != lista_funcionarios.end(); it++){
				if(it->second->getFuncao() == "Veterinario"){
					cout << *it->second;
				}
			}
			break;
		}

		case 3:{
			for(it = lista_funcionarios.begin(); it != lista_funcionarios.end(); it++){
				cout << *it->second;
			}
			break;
		}
		default:{
			cout << "Essa opção não existe, tente novamente";
			break;	
		}
	}	
}


void Controlador::consultarFuncionario(){
	map<int, Funcionario*>::iterator it_func;
	int id;
	
	cout << "Digite o ID do usuário que você deseja consultar" << endl;
	cin >> id;


  	it_func = lista_funcionarios.find(id);
	if (it_func != lista_funcionarios.end()){
		cout << *it_func->second;

	} else {
		cout << "Não foi encontrado Funcionário com esse id" << endl;
	}
}

/*Não foi apagado funcionário diretamente do arquivo, aqui, porque todas as operações vao
ser feitas no map. Ou seja, ao fim do programa (ou ao fim dessa função), o map vai ser
percorrido de modo que seus dados sejam salvos no arquivo, sobrescrevendo os que ja existem
e assim atualizando os dados que foram modificados.*/
void Controlador::removerFuncionario(){
	map<int, Funcionario*>::iterator it_func;
	int id;
	
	cout << "Digite o ID do usuário que você deseja remover" << endl;
	cin >> id;


  	it_func = lista_funcionarios.find(id);
	if (it_func != lista_funcionarios.end()){
		lista_funcionarios.erase(id);
		cout << "Funcionário Removido" << endl; 

	} else {
		cout << "Não foi encontrado Funcionário com esse id" << endl;
	}
}

	



//ANIMAL
bool Controlador::verificarIdAnimal(int id){
	map<int, Animal*>::iterator it;

  	it = lista_animais.find(id);
	if (it != lista_animais.end()){
		return false;
	} 
	return true;
}

void Controlador::salvarDadosAnimais(){
	//preenchendo arquivo de animais
	ofstream outfile_; 
	outfile_.open("animais.csv");

    for(auto it = lista_animais.begin(); it != lista_animais.end(); it++){
        outfile_ << *it->second;
    }

	outfile_.close();
	cout << "Animal adicionado com sucesso!" << endl;
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
	bool id_disponivel = true;
	int opc;

	//Silvestre:
	string autorizacao_ibama;



	cout << "ID: " << endl;
	cin >> id;
	
	id_disponivel = verificarIdAnimal(id);
	while(id_disponivel == false){
		cout << "Já existe um animal com esse ID, escolha um outro." << endl;
		cin >> id;
		id_disponivel = verificarIdAnimal(id);
	}

	cout << "Classe:\n"
	<<"Amphibia, Ave, Reptilia ou Mammalia" << endl;
	cin >> classe;

	cout << "Nome Científico: " << endl;
	cin >> nome_cientifico;

	cout << "Sexo: " << endl;
	cin >> sexo;

	cout << "Tamanho: " << endl;
	cin >> tamanho;

	cout << "Dieta: " << endl;
	cin >> dieta;

	cout << "ID do Veterinário: \n(Se o animal não possuir Veterinário, digite 0)" << endl;
	cin >> tem_veterinario;

	cout << "ID do Tratador: \n(Se o animal não possuir Tratador, digite 0)" << endl;
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


        cout << "Cadastro efetuado com sucesso!!" << endl;
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
    		char venenoso;
			string tipo_veneno;

			cout << "É venenoso? S/N" << endl;
			cin >> venenoso;

			if(venenoso == 'S' or venenoso == 's'){
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

	salvarDadosAnimais();
} 

void Controlador::listarAnimais(int opc){
	map<int, Animal*>::iterator it;
	string opc_classe;
	char opc_sexo;
	//fazer um tolower aqui

	switch(opc){
		case 1:
			cout << "--------- Listagem por classe ----------\n " <<
					"Insira a classe dos animais a serem listados:\n" <<
					"Amphibia, Ave, Reptilia ou Mammalia\n";
			cin >> opc_classe;

			for(it = lista_animais.begin(); it != lista_animais.end(); it++){
				if(it->second->getClasse() == opc_classe){
					cout << "\n" << *it->second;	
				}
			}
		break;

		case 2:
			cout << "--------- Listagem por sexo ----------\n " << endl;
			cout << "M ou F\n";
			cin >> opc_sexo;

			for(it = lista_animais.begin(); it != lista_animais.end(); it++){
				if(it->second->getSexo() == opc_sexo){
					cout << "\n" << *it->second;	
				}
			}
		break;

		case 3:
			for(it = lista_animais.begin(); it != lista_animais.end(); it++){
				cout << "\n" << *it->second;	
			}
		break;

		default:
			cout << "Essa opção não existe no menu." << endl;
		break;
	}
}


void Controlador::removerAnimal(){
	map<int, Animal*>::iterator it_animal;
	int id;
	
	cout << "Digite o ID do animal que você deseja remover" << endl;
	cin >> id;

  	it_animal = lista_animais.find(id);
	if (it_animal != lista_animais.end()){
		lista_funcionarios.erase(id);
		cout << "Animal Removido" << endl; 

	} else {
		cout << "Não foi encontrado Animal com esse id" << endl;
	}
}

void Controlador::consultarAnimal(){
	map<int, Animal*>::iterator it_animal;
	int id;
	
	cout << "Digite o ID do animal que você deseja consultar" << endl;
	cin >> id;
  	it_animal = lista_animais.find(id);

	if (it_animal != lista_animais.end()){
		cout << *it_animal->second;
	} else {
		cout << "Não foi encontrado Animal com esse id" << endl;
	}
}

