#include <string>
#include <map>
#include <utility>
#include <iterator>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "animal.cpp"
#include "funcionario.cpp"
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

enum AtributosAnimal{
	Nome_cientifico,
	Sexo,
	Tamanho,
	Dieta,
	Id_veterinario,
	Id_tratador,
	Nome_batismo,
	Autorizacao_ibama,
	UF_origem,
	Pais_origem,
	Cidade_origem,
	Cor_pelo,
	Tamanho_bico,
	Envergadura_asas,
	Venenoso,
	Tipo_veneno,
	Total_mudas,
	Atributo_invalido
};

AtributosAnimal verificarAtributoAnimal(string input){
	if(input == "nomecientifico" || input == "Nomecientico") return Nome_cientifico;
	if(input == "sexo" || input == "Sexo") return Sexo;
	if(input == "tamanho" || input == "Tamanho") return Tamanho;
	if(input == "dieta" || input == "Dieta") return Dieta;
	if(input == "idveterinario" || input == "Idveterinario") return Id_veterinario;
	if(input == "idtratador" || input == "Idtratador") return Id_tratador;
	if(input == "nomebatismo" || input == "Nomebatismo") return Nome_batismo;
	if(input == "autorizacaoibama" || input == "Autorizacaoibama") return Autorizacao_ibama;
	if(input == "uforigem" || input == "UForigem") return UF_origem;
	if(input == "paisorigem" || input == "Paisorigem") return Pais_origem;
	if(input == "cidadeorigem" || input == "Cidadeorigem") return Cidade_origem;
	if(input == "cordopelo" || input == "corpelo" || input == "CordoPelo") return Cor_pelo;
	if(input == "tamanhodobico" || input == "tamanhodobicocm") return Tamanho_bico;
	if(input == "envergadurasas" || input == "envergaduradasasas" || input == "Envergadurasas") return Envergadura_asas;
	if(input == "venenoso" || input == "Venenoso") return Venenoso;
	if(input == "tipoveneno" || input == "Tipoveneno") return Tipo_veneno;
	if(input == "totaldemudas" || input == "totalmudas" || input == "Totalmudas") return Total_mudas;

	return Atributo_invalido;
}

enum AtributosFuncionario{
	Nome,
	CPF,
	Idade,
	Tipo_sanguineo,
	Fator_RH,
	Especialidade,
	Nivel_seguranca,
	CMRV,
	Atributo_inval
};

AtributosFuncionario verificarAtributoFuncionario(string input){
	if(input == "Nome" || input == "nome") return Nome;
	if(input == "CPF" || input == "cpf") return CPF;
	if(input == "Idade" || input == "idade") return Idade;
	if(input == "tiposanguineo" || input == "Tiposanguineo") return Tipo_sanguineo;
	if(input == "fatorrh" || input == "Fatorrh") return Fator_RH;
	if(input == "especialidade" || input == "Especialidade") return Especialidade;
	if(input == "nivelseguranca" || input == "Nivelseguranca") return Nivel_seguranca;
	if(input == "CMRV" || input == "cmrv") return CMRV;

	return Atributo_inval;
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

	//return it == lista_funcionarios.end();
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

	//salvarDadosFuncionarios();
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


bool Controlador::consultarFuncionario(int id){
	map<int, Funcionario*>::iterator it_func;

  	it_func = lista_funcionarios.find(id);
	if (it_func != lista_funcionarios.end()){
		cout << *it_func->second;
		return true;

	} else {
		cout << "Não foi encontrado Funcionário com esse id" << endl;
	}

	return false;
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

void Controlador::editarFuncionario(){
	map<int, Funcionario*>::iterator it;

	int id;
	string atributo;
	bool id_existente;

	cout << "Indique o ID do Funcionário que você deseja alterar" << endl;
	cin >> id;

	cout << "-----------------------------------------\n";
	id_existente = consultarFuncionario(id);
	cout << "-----------------------------------------\n";

	if(id_existente){
		cout << "Indique qual campo você deseja modificar o valor\n" <<
			"(Para campos com nomes compostos (como 'Nivel de Seguranca')," <<
			"insira-os sem espaçamento ('nomedeseguranca'))\n" <<
			"OBS: Atributos 'ID' e 'Funcao'" << endl;

		cin >> atributo;

		it = lista_funcionarios.find(id);

		string nome_;
		string cpf_;
		string especialidade_;
		string cmrv_;

		switch(verificarAtributoFuncionario(atributo)){
			case Nome:
				cout << "Nome: ";
				cin >> nome_;
				it->second->setNome(nome_);
			break;

			case CPF:
				cout << "CPF: ";
				cin >> cpf_;
				it->second->setCpf(cpf_);
			break;

			case Idade:
				short idade_;
				cout << "Idade: ";
				cin >> idade_;
				it->second->setIdade(idade_);
			break;

			case Tipo_sanguineo:
				short tipoSanguineo_;
				cout << "Tipo Sanguineo: ";
				cin >> tipoSanguineo_;
				it->second->setTipoSanguineo(tipoSanguineo_);			
			break;

			case Fator_RH:
				char fatorRH_;
				cout << "Fator RH: ";
				cin >> fatorRH_;
				it->second->setFatorRh(fatorRH_);			
			break;

			case Especialidade:
				cout << "Especialidade: ";
				cin >> especialidade_;
				it->second->setEspecialidade(especialidade_);
			break;

			case Nivel_seguranca:
				short nivelSeguranca_;
				cout << "Nivel de Segurança: ";
				cin >> nivelSeguranca_;
				dynamic_cast<Tratador*>(it->second)->setNivelSeguranca(nivelSeguranca_);
			break;

			case CMRV:
				cout << "CMRV: ";
				cin >> cmrv_;
				dynamic_cast<Veterinario*>(it->second)->setCMRV(cmrv_);
			break;

			case Atributo_inval:
				cout << "Esse atributo não existe ou não pode ser modificado, tente novamente" << endl;
			break;
		}
	}
}

	



//***************************** ANIMAL *****************************


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
	cout << "Os dados dos animais foram salvos com sucesso!" << endl;
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

	string classificacao;
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

	cout << "Tamanho em metros: " << endl;
	cin >> tamanho;

	cout << "Dieta: " << endl;
	cin >> dieta;

	cout << "ID do Veterinário: \n(Se o animal não possuir Veterinário, digite 0)" << endl;
	cin >> tem_veterinario;

	cout << "ID do Tratador: \n(Se o animal não possuir Tratador, digite 0)" << endl;
	cin >> tem_tratador;

	cout << "Nome de batismo: " << endl;
	cin >> nome_batismo;

	cout << "Este animal é:" << endl << 
		"\n1- Nativo" <<
		"\n2- Exotico" << 
		"\n3- Doméstico" << endl;
	cin >> opc;

	switch(opc){
		case 1: {
			cout << "Autorização do IBAMA: " << endl;
			cin >> autorizacao_ibama;

			cout << "UF de Origem:" << endl;
			cin >> uf_origem;

			classificacao = "Nativo";

			break;
		}
		case 2: {
			cout << "Autorização do IBAMA: " << endl;
			cin >> autorizacao_ibama;

			cout << "País de Origem:" << endl;
			cin >> pais_origem;

			cout << "Cidade de Origem:" << endl;
			cin >> cidade_origem;

			classificacao = "Exotico";

			break;	
		}

		case 3:
			classificacao = "Domestico";
		break;
	}
	   
	switch(resolveOption(classe)){
	    case Mamifero: {
	       	string cor_pelo;
			cout << "Cor do Pelo:" << endl;
			cin >> cor_pelo;

			if(classificacao == "Nativo"){
				Animal* animal = new MamiferoNativo(id, classe, classificacao, nome_cientifico, sexo, tamanho, 
													dieta, tem_veterinario, tem_tratador, nome_batismo,
													cor_pelo, autorizacao_ibama, uf_origem);
				lista_animais.insert({id, animal});


        	cout << "Cadastro efetuado com sucesso!!" << endl;
			} else if (classificacao == "Exotico") {

				Animal* animal = new MamiferoExotico(id, classe, classificacao, nome_cientifico, sexo, tamanho,
													dieta, tem_veterinario, tem_tratador, nome_batismo, 
													cor_pelo, autorizacao_ibama, pais_origem, cidade_origem);
				lista_animais.insert({id, animal});
			}

			else {
				Animal* animal = new MamiferoDomestico(id, classe, classificacao, nome_cientifico, sexo, tamanho,
													dieta, tem_veterinario, tem_tratador, nome_batismo, cor_pelo);
				lista_animais.insert({id, animal});
			}
	
	    	break;
	    }

	    case Anfibio: {
	        int total_de_mudas;
			cout << "Total de Mudas:" << endl;
			cin >> total_de_mudas;	

			if(classificacao == "Nativo"){
				Animal* animal = new AnfibioNativo(id, classe, classificacao, nome_cientifico, sexo, tamanho, 
													dieta, tem_veterinario, tem_tratador, nome_batismo,
													total_de_mudas, autorizacao_ibama, uf_origem);
				lista_animais.insert({id, animal});

			} else if (classificacao == "Exotico") {

				Animal* animal = new AnfibioExotico(id, classe, classificacao, nome_cientifico, sexo, tamanho,
													dieta, tem_veterinario, tem_tratador, nome_batismo, 
													total_de_mudas, autorizacao_ibama, pais_origem, cidade_origem);
				lista_animais.insert({id, animal});
			}

			else {
				Animal* animal = new AnfibioDomestico(id, classe, classificacao, nome_cientifico, sexo, tamanho,
													dieta, tem_veterinario, tem_tratador, nome_batismo, 
													total_de_mudas);
				lista_animais.insert({id, animal});
			}


	    	break;
	    }

        case Reptil: {
    		char venenoso;
			string tipo_veneno;

			cout << "É venenoso? S/N" << endl;
			cin >> venenoso;

			if(venenoso == 'S' || venenoso == 's'){
				cout << "Tipo de veneno" << endl;
				cin >> tipo_veneno;
			} else {
				tipo_veneno = "Não possui veneno.";
			}

			if(classificacao == "Nativo"){
				Animal* animal = new ReptilNativo(id, classe, classificacao, nome_cientifico, sexo, tamanho, 
											dieta, tem_veterinario, tem_tratador, nome_batismo,
											venenoso, tipo_veneno, autorizacao_ibama, uf_origem);
				lista_animais.insert({id, animal});

			} else if (classificacao == "Exotico")  {

				Animal* animal = new ReptilExotico(id, classe, classificacao, nome_cientifico, sexo, tamanho,
													dieta, tem_veterinario, tem_tratador, nome_batismo, 
													venenoso, tipo_veneno, autorizacao_ibama, pais_origem, cidade_origem);
				lista_animais.insert({id, animal});

			} else {
				Animal* animal = new ReptilDomestico(id, classe, classificacao, nome_cientifico, sexo, tamanho,
													dieta, tem_veterinario, tem_tratador, nome_batismo, 
													venenoso, tipo_veneno);
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

			if(classificacao == "Nativo"){
				Animal* animal = new AveNativo(id, classe, classificacao, nome_cientifico, sexo, tamanho, 
											dieta, tem_veterinario, tem_tratador, nome_batismo,
											tamanho_bico_cm, envergadura_asas, autorizacao_ibama, uf_origem);
				lista_animais.insert({id, animal});


			} else if (classificacao == "Exotico")   {

				Animal* animal = new AveExotico(id, classe, classificacao, nome_cientifico, sexo, tamanho,
												dieta, tem_veterinario, tem_tratador, nome_batismo, 
												tamanho_bico_cm, envergadura_asas, autorizacao_ibama, pais_origem, cidade_origem);
				lista_animais.insert({id, animal});	

			} else {
				Animal* animal = new AveDomestico(id, classe, classificacao, nome_cientifico, sexo, tamanho,
												dieta, tem_veterinario, tem_tratador, nome_batismo, 
												tamanho_bico_cm, envergadura_asas);
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

	//salvarDadosAnimais();
} 

void Controlador::listarAnimais(int opc){
	map<int, Animal*>::iterator it;
	string opc_classe, opc_classificacao;
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
			cout << "--------- Listagem por classificação ----------\n " <<
					"Insira a classificação dos animais a serem listados:\n" <<
					"Nativo, Exotico ou Domestico\n";
			cin >> opc_classificacao;

			for(it = lista_animais.begin(); it != lista_animais.end(); it++){
				if(it->second->getClassificacao() == opc_classificacao){
					cout << "\n" << *it->second;	
				}
			}
		break;


		case 4:
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

void Controlador::consultarAnimal(int id){
	map<int, Animal*>::iterator it_animal;

  	it_animal = lista_animais.find(id);

	if (it_animal != lista_animais.end()){
		cout << *it_animal->second;
	} else {
		cout << "Não foi encontrado Animal com esse id" << endl;
	}
}

void Controlador::editarAnimal(){
	map<int, Animal*>::iterator it;

	int id;
	string atributo;
	cin >> id;

	cout << "-----------------------------------------\n";
	consultarAnimal(id);
	cout << "-----------------------------------------\n";
	cout << "Indique qual campo você deseja modificar o valor\n" <<
			"(Para campos com nomes compostos (como 'Nome Científico')," <<
			"insira-os sem espaçamento ('nomecientico'))\n" <<
			"OBS: Atributos 'ID', 'Classe' e 'Classificacao' não podem ser alterados." << endl;

	cin >> atributo;

	it = lista_animais.find(id);

	//não sei porque nao deixou declarar dentro
	string nome_cientifico_;
	string dieta_;
	string nome_batismo_;
	string autorizacao_ibama_;
	string uf_origem_;
	string pais_origem_;
	string cidade_origem_;
	string cor_pelo_;
	string tipo_veneno_;


	switch(verificarAtributoAnimal(atributo)){		
		case Nome_cientifico:
			cout << "Nome Científico: ";
			cin >> nome_cientifico_; 

			it->second->setNomeCientifico(nome_cientifico_);
		break;
		
		case Sexo:
			char sexo_;
			cout << "Sexo: ";
			cin >> sexo_;

			it->second->setSexo(sexo_);
		break;

		case Tamanho:
			int tamanho_;
			cout << "Tamanho: ";
			cin >> tamanho_;
			it->second->setTamanho(tamanho_);
		break;

		case Dieta:
			cout << "Dieta: ";
			cin >> dieta_;
			it->second->setDieta(dieta_);
		break;

		case Id_veterinario:
			int id_veterinario_;
			cout << "ID Veterinario: ";
			cin >> id_veterinario_;
			it->second->setIdVeterinario(id_veterinario_);
		break;

		case Id_tratador:
			int id_tratador_;
			cout << "ID Tratador: ";
			cin >> id_tratador_;
			it->second->setIdTratador(id_tratador_);
		break;

		case Nome_batismo:
			cout << "Nome de Batismo: ";
			cin >> nome_batismo_;
			it->second->setNomeBatismo(nome_batismo_);
		break;

		case Autorizacao_ibama:
			cout << "Autorização do Ibama: ";
			cin >> autorizacao_ibama_;
			dynamic_cast<AnimalSilvestre*>(it->second)->setAutorizacaoIbama(autorizacao_ibama_);
		break;

		case UF_origem:
			cout << "UF de Origem: ";
			cin >> uf_origem_;
			dynamic_cast<AnimalNativo*>(it->second)->setUfOrigem(uf_origem_);
		break;

		case Pais_origem:
			cout << "Pais de Origem: ";
			cin >> pais_origem_;
			dynamic_cast<AnimalExotico*>(it->second)->setPaisOrigem(pais_origem_);
		break;

		case Cidade_origem:
			cout << "Cidade de Origem: ";
			cin >> cidade_origem_;
			dynamic_cast<AnimalExotico*>(it->second)->setCidadeOrigem(cidade_origem_);
		break;

		case Cor_pelo:
			cout << "Cor do Pelo: ";
			cin >> cor_pelo_;

			if(it->second->getClassificacao() == "Nativo"){
				dynamic_cast<MamiferoNativo*>(it->second)->setCorPelo(cor_pelo_);
			} else if (it->second->getClassificacao() == "Exotico"){
				dynamic_cast<MamiferoExotico*>(it->second)->setCorPelo(cor_pelo_);
			} else {
				dynamic_cast<MamiferoDomestico*>(it->second)->setCorPelo(cor_pelo_);
			}
		break;

		case Tamanho_bico:
			double tamanho_bico_cm_;
			cout << "Tamanho do bico em cm: ";
			cin >> tamanho_bico_cm_;

			if(it->second->getClassificacao() == "Nativo"){
				dynamic_cast<AveNativo*>(it->second)->setTamanhoBico(tamanho_bico_cm_);
			} else if (it->second->getClassificacao() == "Exotico"){
				dynamic_cast<AveExotico*>(it->second)->setTamanhoBico(tamanho_bico_cm_);
			} else {
				dynamic_cast<AveDomestico*>(it->second)->setTamanhoBico(tamanho_bico_cm_);
			}
			
		break;

		case Envergadura_asas:
			double envergadura_asas_;
			cout << "Envergadura das asas: ";
			cin >> envergadura_asas_;

			if(it->second->getClassificacao() == "Nativo"){
				dynamic_cast<AveNativo*>(it->second)->setEnvergaduraAsas(envergadura_asas_);
			} else if (it->second->getClassificacao() == "Exotico"){
				dynamic_cast<AveExotico*>(it->second)->setEnvergaduraAsas(envergadura_asas_);
			} else {
				dynamic_cast<AveDomestico*>(it->second)->setEnvergaduraAsas(envergadura_asas_);
			}
		break;

		case Venenoso:
			bool venenoso_;
			char opc_v;
			cout << "É venenoso? S/N ";
			cin >> opc_v;

			if(opc_v == 'S' || opc_v == 's'){
				venenoso_ = true;
				cout << "Tipo de Veneno: ";
				cin >> tipo_veneno_;
			} else {
				venenoso_ = false;
			}

			if(it->second->getClassificacao() == "Nativo"){
				dynamic_cast<ReptilNativo*>(it->second)->setVenenoso(venenoso_);
			} else if (it->second->getClassificacao() == "Exotico"){
				dynamic_cast<ReptilExotico*>(it->second)->setVenenoso(venenoso_);
			} else {
				dynamic_cast<ReptilDomestico*>(it->second)->setVenenoso(venenoso_);
			}

			if(venenoso_ == true){
				if(it->second->getClassificacao() == "Nativo"){
					dynamic_cast<ReptilNativo*>(it->second)->setTipoVeneno(tipo_veneno_);
				} else if (it->second->getClassificacao() == "Exotico"){
					dynamic_cast<ReptilExotico*>(it->second)->setTipoVeneno(tipo_veneno_);
				} else {
					dynamic_cast<ReptilDomestico*>(it->second)->setTipoVeneno(tipo_veneno_);
				}	
			}
		break;

		case Tipo_veneno:
			cout << "Tipo de Veneno: ";
			cin >> tipo_veneno_;

			if(it->second->getClassificacao() == "Nativo"){
				dynamic_cast<ReptilNativo*>(it->second)->setTipoVeneno(tipo_veneno_);
			} else if (it->second->getClassificacao() == "Exotico"){
				dynamic_cast<ReptilExotico*>(it->second)->setTipoVeneno(tipo_veneno_);
			} else {
				dynamic_cast<ReptilDomestico*>(it->second)->setTipoVeneno(tipo_veneno_);
			}
		break;

		case Total_mudas:
			int total_mudas_;
			cout << "Total de mudas: ";
			cin >> total_mudas_;

			if(it->second->getClassificacao() == "Nativo"){
				dynamic_cast<AnfibioNativo*>(it->second)->setTotalMudas(total_mudas_);
			} else if (it->second->getClassificacao() == "Exotico"){
				dynamic_cast<AnfibioExotico*>(it->second)->setTotalMudas(total_mudas_);
			} else {
				dynamic_cast<AnfibioDomestico*>(it->second)->setTotalMudas(total_mudas_);
			}
		break;

		case Atributo_invalido:
			cout << "Esse atributo não existe ou não pode ser modificado, tente novamente" << endl;
		break;	
	}
}