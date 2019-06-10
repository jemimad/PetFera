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
		cout << "Não foi possível abrir o arquivo" << endl;
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
		cout << "Não foi possível abrir o arquivo" << endl;
	}
}


bool Controlador::verificarId(int id){
	map<int, Funcionario*>::iterator it;

  	it = lista_funcionarios.find(id);
	if (it != lista_funcionarios.end()){
		return false;
	} 
	return true;
}


void Controlador::addFuncionario(int opc){
	ofstream outfile; 
	outfile.open("funcionarios.csv", ios::app);

	int id;
	string nome, cpf, especialidade;
	short idade;
	char tipoSanguineo;
	char fatorRH;
	bool id_disponivel = true;

	cout << "ID: " << endl;
	cin >> id;
	
	id_disponivel = verificarId(id);
	while(id_disponivel == false){
		cout << "Já existe um funcionário com esse ID, escolha um outro." << endl;
		cin >> id;
		id_disponivel = verificarId(id);
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
		
   		
		outfile << id << ";" << funcao << ";" << nome << ";" 
				<< cpf << ";" << idade << ";" << tipoSanguineo 
				<< ";" << fatorRH << ";" << especialidade << ";"
				<< nivelSeguranca << endl;
		
			cout << "Tratador adicionado com sucesso!" << endl;

	} else {
		string cmrv;
		string funcao = "Veterinario";

		cout << "CMRV: " << endl;
		cin >> cmrv;

		Funcionario* func = new Veterinario(id, funcao, nome, cpf, idade, 
							tipoSanguineo, fatorRH, especialidade, cmrv);
		lista_funcionarios.insert({id, func});

		outfile << id << ";" << funcao << ";" << nome << ";" 
			<< cpf << ";" << idade << ";" << tipoSanguineo 
			<< ";" << fatorRH << ";" << especialidade << ";"
			<< cmrv << endl;

		cout << "Veterinário adicionado com sucesso!" << endl;	
	}
	outfile.close();
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

	//iniciando arquivo
	ofstream outfile_; 
	outfile_.open("animais.csv", ios::app);

	cout << "ID: " << endl;
	cin >> id;

	cout << "Classe:\n "
	<<"Amphibia, Reptilia, Ave ou Mammalia" << endl;
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

	ofstream outfile; 
   	outfile.open("animais.csv", ios::app); 
	   
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

				if (outfile_.is_open() && outfile_.good()){ // verificamos se está tudo bem
					outfile_ << id << ";" << classe << ";" << nome_cientifico << ";" 
						<< sexo << ";" << tamanho << ";" << dieta << ";" << tem_veterinario 
						<< ";" << tem_tratador << ";" << nome_batismo << ";" << cor_pelo
						<< ";" << autorizacao_ibama << ";" << uf_origem << endl;
				}
			} else {

				Animal* animal = new MamiferoExotico(id, classe, nome_cientifico, sexo, tamanho,
													dieta, tem_veterinario, tem_tratador, nome_batismo, 
													cor_pelo, autorizacao_ibama, pais_origem, cidade_origem);
				lista_animais.insert({id, animal});

				if (outfile_.is_open() && outfile_.good()){ // verificamos se está tudo bem
					outfile_ << id << ";" << classe << ";" << nome_cientifico << ";" 
						<< sexo << ";" << tamanho << ";" << dieta << ";" << tem_veterinario 
						<< ";" << tem_tratador << ";" << nome_batismo << ";" << cor_pelo
						<< ";" << autorizacao_ibama << ";" << pais_origem << ";" << cidade_origem << endl;
				}		
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

				if (outfile_.is_open() && outfile_.good()){ // verificamos se está tudo bem
					outfile_ << id << ";" << classe << ";" << nome_cientifico << ";" 
						<< sexo << ";" << tamanho << ";" << dieta << ";" << tem_veterinario 
						<< ";" << tem_tratador << ";" << nome_batismo << ";" << total_de_mudas
						<< ";" << autorizacao_ibama << ";" << uf_origem << endl;
				}
			} else {

				Animal* animal = new AnfibioExotico(id, classe, nome_cientifico, sexo, tamanho,
													dieta, tem_veterinario, tem_tratador, nome_batismo, 
													total_de_mudas, autorizacao_ibama, pais_origem, cidade_origem);
				lista_animais.insert({id, animal});

				if (outfile_.is_open() && outfile_.good()){ // verificamos se está tudo bem
					outfile_ << id << ";" << classe << ";" << nome_cientifico << ";" 
						<< sexo << ";" << tamanho << ";" << dieta << ";" << tem_veterinario 
						<< ";" << tem_tratador << ";" << nome_batismo << ";" << total_de_mudas
						<< ";" << autorizacao_ibama << ";" << pais_origem << ";" << cidade_origem << endl;
				}	
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

				if (outfile_.is_open() && outfile_.good()){ // verificamos se está tudo bem
					outfile_ << id << ";" << classe << ";" << nome_cientifico << ";" 
						<< sexo << ";" << tamanho << ";" << dieta << ";" << tem_veterinario 
						<< ";" << tem_tratador << ";" << nome_batismo << ";" << venenoso << ";" << tipo_veneno 
						<< ";" << autorizacao_ibama << ";" << uf_origem << endl;
				}	
				

			} else {

				Animal* animal = new ReptilExotico(id, classe, nome_cientifico, sexo, tamanho,
													dieta, tem_veterinario, tem_tratador, nome_batismo, 
													venenoso, tipo_veneno, autorizacao_ibama, pais_origem, cidade_origem);
				lista_animais.insert({id, animal});

				if (outfile_.is_open() && outfile_.good()){ // verificamos se está tudo bem
					outfile_ << id << ";" << classe << ";" << nome_cientifico << ";" 
						<< sexo << ";" << tamanho << ";" << dieta << ";" << tem_veterinario 
						<< ";" << tem_tratador << ";" << nome_batismo << ";" << venenoso << ";" << tipo_veneno
						<< ";" << autorizacao_ibama << ";" << pais_origem << ";" << cidade_origem << endl;
				}	
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

				if (outfile_.is_open() && outfile_.good()){   
					outfile_ << id << ";" << classe << ";" << nome_cientifico << ";" 
						<< sexo << ";" << tamanho << ";" << dieta << ";" << tem_veterinario 
						<< ";" << tem_tratador << ";" << nome_batismo << ";" << tamanho_bico_cm 
						<< ";" << envergadura_asas << ";" << autorizacao_ibama << ";" << uf_origem << endl;
				}	
				

			} else {

				Animal* animal = new AveExotico(id, classe, nome_cientifico, sexo, tamanho,
												dieta, tem_veterinario, tem_tratador, nome_batismo, 
												tamanho_bico_cm, envergadura_asas, autorizacao_ibama, pais_origem, cidade_origem);
				lista_animais.insert({id, animal});
				
				if (outfile_.is_open() && outfile_.good()){ 
					outfile_ << id << ";" << classe << ";" << nome_cientifico << ";" 
						<< sexo << ";" << tamanho << ";" << dieta << ";" << tem_veterinario 
						<< ";" << tem_tratador << ";" << nome_batismo << ";" << tamanho_bico_cm 
						<< ";" << envergadura_asas << ";" << autorizacao_ibama << ";" << pais_origem 
						<< ";" << cidade_origem << endl;
				}		
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

	outfile_.close();
	cout << "Animal adicionado com sucesso!" << endl;


} 

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

void Controlador::removerAnimal(){
	map<int, Animal*>::iterator it_animal;
	int id;
	
	cout << "Digite o ID do animal que você deseja remover" << endl;
	cin >> id;

  	it_animal = lista_animais.find(id);
	if (it_animal != lista_animais.end()){
		lista_funcionarios.erase(id);
		cout << "Funcionário Removido" << endl; 

	} else {
		cout << "Não foi encontrado Funcionário com esse id" << endl;
	}
}