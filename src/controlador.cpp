#include "controlador.h"
#include "anfibio.h"
#include "anfibioDomestico.h"
#include "anfibioExotico.h"
#include "anfibioNativo.h"
#include "animal.h"
#include "animalExotico.h"
#include "animalNativo.h"
#include "animalSilvestre.h"
#include "ave.h"
#include "aveDomestico.h"
#include "aveExotico.h"
#include "aveNativo.h"
#include "funcionario.h"
#include "mamifero.h"
#include "mamiferoDomestico.h"
#include "mamiferoExotico.h"
#include "mamiferoNativo.h"
#include "reptil.h"
#include "reptilDomestico.h"
#include "reptilExotico.h"
#include "reptilNativo.h"
#include "tratador.h"
#include "veterinario.h"


using namespace std;
/**@sa Classes resolveOption */
/**@brief Uso do enum para criação de classe de variaveis*/ 
enum Classes{
    Classe_invalida,
    Mamifero,
    Anfibio,
    Reptil,
    Ave
};
/**@brief implementação da classe enum Classes para comparar as variaveis com o valor inserido pelo usuario*/
Classes resolveOption(string input) {
    if( input == "Mammalia" || input == "mammalia") return Mamifero;
    if( input == "Amphibia" || input == "amphibia") return Anfibio;
    if( input == "Reptilia" || input == "reptilia") return Reptil;
    if( input == "Ave" || input == "ave") return Ave;
    return Classe_invalida;
}


/**@brief Função para ler o arquivo dos animais cadastrados dentro do arquivo do petshop */
void Controlador::lerAnimais(){
	//abriu o arquivo
	ifstream inputfile_animais;
	inputfile_animais.open("data/animais.csv");/**@brief abertura do arquivo */
	
	//ANIMAL
	string classe, classificacao, sexo, nome_cientifico, dieta, nome_batismo;
	int id, id_veterinario, id_tratador;
	double tamanho;

	/**@brief Anfibio */
	int total_mudas;

	/**@brief AVE */
	double tamanho_bico_cm, envergadura_asas;

	/**@brief MAMIFERO */
	string cor_pelo;

	/**@brief REPTIL */
	bool venenoso;
	string tipo_veneno, verificar_veneno;

	/**@brief NATIVO */
	string uf_origem;

	/**@brief EXOTICO*/
	string pais_origem, cidade_origem;

	/**@brief SILVESTRE */
	string autorizacao_ibama;

	/**@brief LEITURA */
	vector<string> att;
	string linha;
	string ops;

	/**@brief posiciona o ponteiro no final do arquivo */
	inputfile_animais.seekg(0,ios::end);
	/**@brief recebe o tamanho do arquivo*/
    int size = inputfile_animais.tellg();
	/**@brief posiciona o ponteiro no inicio do arquivo*/
	inputfile_animais.seekg(0, ios::beg);
    /**@brief se o arquivo está aberto direitinho e não está vazio, entra*/
	if(inputfile_animais.is_open() && size > 0){
		/**@brief enquanto não chegar no fim do arquivo, vai:*/
		while(!inputfile_animais.eof()){
			/**@brief limpar o vetor(pra caso já exista algo nele)*/
			att.clear();

			/**@brief pegar linha do arquivo*/
			getline(inputfile_animais, linha);

			/**@brief jogar a linha pro stringstream pra poder dividir em palavras*/
			stringstream atributos_animal(linha);

			/**@brief vai percorrer a linha inteira salvando os dados (que estão separados por ;) em um vetor de strings*/
			while(getline(atributos_animal, ops, ';')){
				att.push_back(ops);		
			}

			/**@brief vai distribuir os valores nas variaveis certas pra poder passar pro construtor*/
			id = stoi(att[0]);
			classe = att[1];
			classificacao = att[2];
			nome_cientifico = att[3];
			sexo = att[4];
			tamanho = stod(att[5]); 
			dieta = att[6];
			id_veterinario = stoi(att[7]);
			id_tratador = stoi(att[8]);
			nome_batismo = att[9];

			/**@brief Conversão de um string para char */
			char sexo_aux = sexo[0];
			/**@brief Condicional para saber que tipo de anfibio esta sendo selecionado */
			if(classe == "Amphibia"){	
				total_mudas = stoi(att[10]);

				if(classificacao == "Nativo"){
					autorizacao_ibama = att[11];
					uf_origem = att[12];
				
					Animal* anfnat = new AnfibioNativo(id, classe, classificacao, nome_cientifico, sexo_aux, tamanho, 
											dieta, id_veterinario, id_tratador, nome_batismo, total_mudas,
											autorizacao_ibama, uf_origem);
					lista_animais.insert({id, anfnat});
				
				} else if (classificacao == "Exotico"){
					autorizacao_ibama = att[11];
					pais_origem = att[12];
					cidade_origem = att[13];

					Animal* anfexot = new AnfibioExotico(id, classe, classificacao, nome_cientifico, sexo_aux, tamanho, 
										dieta, id_veterinario, id_tratador, nome_batismo, total_mudas,
										autorizacao_ibama, pais_origem, cidade_origem);
					lista_animais.insert({id, anfexot});
				} else {
				
					Animal* anfdom = new AnfibioDomestico(id, classe, classificacao, nome_cientifico, sexo_aux, tamanho, 
										dieta, id_veterinario, id_tratador, nome_batismo, total_mudas);
					lista_animais.insert({id, anfdom});
				}	
			}
			/**@brief Condicional para saber que tipo de ave esta sendo selecionado */
			if(classe == "Ave"){
				tamanho_bico_cm = stod(att[10]);
				envergadura_asas = stod(att[11]);

				if(classificacao == "Nativo"){
					autorizacao_ibama = att[12];
					uf_origem = att[13];
				
					Animal* avenat = new AveNativo(id, classe, classificacao, nome_cientifico, sexo_aux, tamanho, 
											dieta, id_veterinario, id_tratador, nome_batismo, tamanho_bico_cm, 
											envergadura_asas, autorizacao_ibama, uf_origem);
					lista_animais.insert({id, avenat});
				
				} else if (classificacao == "Exotico"){
					autorizacao_ibama = att[12];
					pais_origem = att[13];
					cidade_origem = att[14];

					Animal* aveexot = new AveExotico(id, classe, classificacao, nome_cientifico, sexo_aux, tamanho, 
										dieta, id_veterinario, id_tratador, nome_batismo,  tamanho_bico_cm, 
										envergadura_asas, autorizacao_ibama, pais_origem, cidade_origem);
					lista_animais.insert({id, aveexot});
				} else {
				
					Animal* avedom = new AveDomestico(id, classe, classificacao, nome_cientifico, sexo_aux, tamanho, 
										dieta, id_veterinario, id_tratador, nome_batismo, tamanho_bico_cm, envergadura_asas);
					lista_animais.insert({id, avedom});
				}	
			}
			/**@brief Condicional para saber que tipo de mammalia esta sendo selecionado */
			if(classe == "Mammalia"){
				cor_pelo = att[10];

				if(classificacao == "Nativo"){
					autorizacao_ibama = att[11];
					uf_origem = att[12];
				
					Animal* maminat = new MamiferoNativo(id, classe, classificacao, nome_cientifico, sexo_aux, tamanho, 
											dieta, id_veterinario, id_tratador, nome_batismo, cor_pelo,
											autorizacao_ibama, uf_origem);
					lista_animais.insert({id, maminat});
				
				} else if (classificacao == "Exotico"){
					autorizacao_ibama = att[11];
					pais_origem = att[12];
					cidade_origem = att[13];

					Animal* mamiexot = new MamiferoExotico(id, classe, classificacao, nome_cientifico, sexo_aux, tamanho, 
										dieta, id_veterinario, id_tratador, nome_batismo, cor_pelo,
										autorizacao_ibama, pais_origem, cidade_origem);
					lista_animais.insert({id, mamiexot});
				} else {
				
					Animal* mamidom = new MamiferoDomestico(id, classe, classificacao, nome_cientifico, sexo_aux, tamanho, 
										dieta, id_veterinario, id_tratador, nome_batismo, cor_pelo);
					lista_animais.insert({id, mamidom});
				}	
			}
			/**@brief Condicional para saber que tipo de reptilia esta sendo selecionado */
			if(classe == "Reptilia"){
				verificar_veneno = att[10];
				if(verificar_veneno == "true" || verificar_veneno == "s"){
					venenoso = true;
				} else {
					venenoso = false;
				}

				tipo_veneno = att[11];

				if(classificacao == "Nativo"){
					autorizacao_ibama = att[12];
					uf_origem = att[13];
				
					Animal* repnat = new ReptilNativo(id, classe, classificacao, nome_cientifico, sexo_aux, tamanho, 
											dieta, id_veterinario, id_tratador, nome_batismo, venenoso, tipo_veneno,
											autorizacao_ibama, uf_origem);
					lista_animais.insert({id, repnat});
				
				} else if (classificacao == "Exotico"){
					autorizacao_ibama = att[12];
					pais_origem = att[13];
					cidade_origem = att[14];

					Animal* repexot = new ReptilExotico(id, classe, classificacao, nome_cientifico, sexo_aux, tamanho, 
										dieta, id_veterinario, id_tratador, nome_batismo, venenoso, tipo_veneno,
										autorizacao_ibama, pais_origem, cidade_origem);
					lista_animais.insert({id, repexot});
				} else {
				
					Animal* repdom = new ReptilDomestico(id, classe, classificacao, nome_cientifico, sexo_aux, tamanho, 
										dieta, id_veterinario, id_tratador, nome_batismo, venenoso, tipo_veneno);
					lista_animais.insert({id, repdom});
				}	



			}
		}
	}else{
		cout << "Arquivo de Animais está vazio ou é inexistente" << endl;
	}
	/**@brief fechamento do arquivo*/
	inputfile_animais.close();
}
/**@brief função para ler a lista de funcionarios dentro do arquivo*/
void Controlador::lerFuncionarios(){
	/**@brief abrir o arquivo */
	ifstream inputfile_funcionarios;
	inputfile_funcionarios.open("data/funcionarios.csv");
	
	/**@brief Funcionario*/
	string funcao, nome, cpf,  tipoSanguineo, fatorRH, especialidade;
	int id, idade;

	/**@brief Veterinario */
	string cmrv;

	/**@brief Tratador */
	int nivelSeguranca;

	/**@brief Leitura*/
	vector<string> att;
	string linha;
	string ops;
	/**@details seekg ta posicionando do final do arquivo, tellg verifica o tamanho do arquivo se for igual a 0 o seekg(beg) posifiona de volta no inicio */
	inputfile_funcionarios.seekg(0,ios::end);
    int size = inputfile_funcionarios.tellg();
	inputfile_funcionarios.seekg(0, ios::beg);

	if(inputfile_funcionarios.is_open() && size > 0){
		
		while(!inputfile_funcionarios.eof()){
			att.clear();
			getline(inputfile_funcionarios, linha);
			stringstream atributos_animal(linha);

			while(getline(atributos_animal, ops, ';')){
				att.push_back(ops);		
			}

			id = stoi(att[0]);
			funcao = att[1];
			nome = att[2];
			cpf = att[3];
			idade = stoi(att[4]);
			tipoSanguineo = att[5]; 
			fatorRH = att[6];
			especialidade = att[7];

			/**@brief converter string para char */
			char tp_aux = tipoSanguineo[0];
			char frh_aux = fatorRH[0];
			/**@brief verificação de função do funcionario */
			if(funcao == "Tratador"){	
				nivelSeguranca = stoi(att[8]);

				Funcionario* functrat = new Tratador(id, funcao, nome, cpf, idade, tp_aux, frh_aux, especialidade, nivelSeguranca);
				lista_funcionarios.insert({id, functrat});
			}
			if(funcao == "Veterinario"){
				cmrv = att[8];

				Funcionario* funcvet = new Veterinario(id, funcao, nome, cpf, idade, tp_aux, frh_aux, especialidade, cmrv);
				lista_funcionarios.insert({id, funcvet});
			}
		}

	}else{
		cout << "Arquivo de Funcionários está vazio ou é inexistente" << endl;
	}

	inputfile_funcionarios.close();

}

 /**@brief função para abertura do petshop */
void Controlador::abrirPetshop(){
	lerAnimais();
	lerFuncionarios();
}
/**@brief Função para verificação do id dos funcionarios */
bool Controlador::verificarIdFuncionario(int id){
	map<int, Funcionario*>::iterator it;
	/**@brief uso do iterador para achar e verificar se o id ja é existe */
  	it = lista_funcionarios.find(id);
	if (it != lista_funcionarios.end()){
		return false;
	} 
	return true;

}
/**@brief função para salvar os dados dos funcionarios no arquivo do petshop */
void Controlador::salvarDadosFuncionarios(){
	ofstream outfile; 
	/**@brief abertura do arquivo da lista de funcionarios */
	outfile.open("data/funcionarios.csv");
	/**@brief salvar os funcionarios dentro do arquivo e fechamento do arquivo */
	for(auto it = lista_funcionarios.begin(); it != lista_funcionarios.end(); it++){
        outfile << *it->second;
    }

	outfile.close();
	cout << "Os dados dos funcionários foram salvos com sucesso!" << endl;
}
/**@brief funçaõ para adicionar um novo funcionario */
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
	/**@brief verificar se o id escolhido estar disponivel para uso*/
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

	/**@brief verificador se o funcionario é tratador ou vetarinario e atribuir os atributos corretos ao funcionario */
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

/**@brief função para a listagem do funcionarios existentes */
void Controlador::listarFuncionarios(int opc){
	map<int, Funcionario*>::iterator it;
	/**@brief verificar a opção inserida pelo usuario para mostrar ao usuario a opção escolhida */
	switch(opc){
		case 1:{
			/**@brief percorrendo o map para verificação dos funcionarios do tipo tratador */
			for(it = lista_funcionarios.begin(); it != lista_funcionarios.end(); it++){
				if(it->second->getFuncao() == "Tratador"){
					cout << *it->second;
				}
			}
			break;
		}
		case 2:{
			/**@brief percorrendo o map para verificação dos funcionarios do tipo veterinario*/
			for(it = lista_funcionarios.begin(); it != lista_funcionarios.end(); it++){
				if(it->second->getFuncao() == "Veterinario"){
					cout << *it->second;
				}
			}
			break;
		}

		case 3:{
			/**@brief percorrendo o map para listagem de todos os funcionarios */
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

/**@brief função para consulta de funcionario por id */
bool Controlador::consultarFuncionario(int id){
	map<int, Funcionario*>::iterator it_func;
	/**@brief iterador para procurar pelo id inserido pelo usuario */
  	it_func = lista_funcionarios.find(id);
	if (it_func != lista_funcionarios.end()){
		cout << *it_func->second;
		return true;

	} else {
		cout << "Não foi encontrado Funcionário com esse id" << endl;
	}

	return false;
}

/**@brief Função para remoção do funcionario */
void Controlador::removerFuncionario(){
	map<int, Funcionario*>::iterator it_func;
	int id;
	
	cout << "Digite o ID do usuário que você deseja remover" << endl;
	cin >> id;

	/**@brief iterador para percorrer o map a procura do id inserido pelo usuario e erase para excluir o funcionario do map */
  	it_func = lista_funcionarios.find(id);
	if (it_func != lista_funcionarios.end()){
		lista_funcionarios.erase(id);
		cout << "Funcionário Removido" << endl; 

	} else {
		cout << "Não foi encontrado Funcionário com esse id" << endl;
	}
}


/**@brief Função para edição dos atributos de funcionario */
void Controlador::editarFuncionario(){
	map<int, Funcionario*>::iterator it;
	
	int id;
	string novo_valor;

	cout << "Indique o ID do Funcionário que você deseja alterar" << endl;
	cin >> id;

	/**@brief iterador para procurar o id do funcionario inserido pelo usuario */
	it = lista_funcionarios.find(id);	
	if(it == lista_funcionarios.end()){
		cout << "Não foi encontrado nenhum Funcionário com esse ID" << endl;
	} else {
		cout << "Se quiser manter o valor já salvo, insira -" << endl;
		/**@brief opção para o usuario editar os atributos do funcionario */
		cout << "Nome: [" << it->second->getNome() << "]: ";
		cin >> novo_valor;
		if(novo_valor != "-"){
			it->second->setNome(novo_valor);
		}

		cout << "CPF: [" << it->second->getCpf() << "]: ";
		cin >> novo_valor;
		if(novo_valor != "-"){
			it->second->setCpf(novo_valor);
		}

		cout << "Idade: [" << it->second->getIdade() << "]: ";
		cin >> novo_valor;
		if(novo_valor != "-"){
			it->second->setIdade(stoi(novo_valor));
		}

		cout << "Tipo Sanguineo: [" << it->second->getTipoSanguineo() << "]: ";
		cin >> novo_valor;
		if(novo_valor != "-"){
			char tp_aux = novo_valor[0];
			it->second->setTipoSanguineo(tp_aux);
		}

		cout << "Fator RH: [" << it->second->getFatorRh() << "]: ";
		cin >> novo_valor;
		if(novo_valor != "-"){
			char frh_aux = novo_valor[0];
			it->second->setFatorRh(frh_aux);
		}

		cout << "Especialidade: [" << it->second->getEspecialidade() << "]: ";
		cin >> novo_valor;
		if(novo_valor != "-"){
			it->second->setEspecialidade(novo_valor);
		}

		if(it->second->getFuncao() == "Tratador"){
			cout << "Nivel de Segurança: [" << dynamic_cast<Tratador*>(it->second)->getNivelSeguranca() << "]: ";
			cin >> novo_valor;
			if(novo_valor != "-"){
				dynamic_cast<Tratador*>(it->second)->setNivelSeguranca(stoi(novo_valor));
			}
		} else {
			cout << "CMRV: [" << dynamic_cast<Veterinario*>(it->second)->getCMRV() << "]: ";
			cin >> novo_valor;
			if(novo_valor != "-"){
				dynamic_cast<Veterinario*>(it->second)->setCMRV(novo_valor);
			}
		}

		cout << "Usuário editado com sucesso!" << endl;
	}
}

	



//***************************** ANIMAL *****************************

/**@brief Função para verificar id do animal */
bool Controlador::verificarIdAnimal(int id){
	map<int, Animal*>::iterator it;
	/**@brief um iterador percorrer o map de animal e verifica se o id ja esta em uso e retorna ao usuario true ou false */
  	it = lista_animais.find(id);
	if (it != lista_animais.end()){
		return false;
	} 
	return true;
}
/**@brief Função para salvar os animais no arquivo */
void Controlador::salvarDadosAnimais(){
	/**@brief abertura do arquivo para salvar a lista de animais */
	ofstream outfile_; 
	outfile_.open("data/animais.csv");
	/**@brief enquanto o map não chegar ao fim ele vai salvar os animais no arquivo*/
    for(auto it = lista_animais.begin(); it != lista_animais.end(); it++){
        outfile_ << *it->second;
    }
	/**@brief fechamento do arquivo */
	outfile_.close();
	cout << "Os dados dos animais foram salvos com sucesso!" << endl;
}
/**@brief função para adicionar um novo animal*/
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
	
	/**@brief Nativo */
	string uf_origem;

	/**@brief Exotico */
	string pais_origem;
	string cidade_origem;

	string classificacao;
	bool id_disponivel = true;
	int opc;

	/**@brief Silvestre */
	string autorizacao_ibama;



	cout << "ID: " << endl;
	cin >> id;
	/**@brief verificar se o id inserido pelo funcionario ja estar em uso */
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
			/**@brief verifica o tipo de animal escolhido para inserir e instancia usando o construtor da classe Mamifero*/
			if(classificacao == "Nativo"){
				Animal* animal = new MamiferoNativo(id, classe, classificacao, nome_cientifico, sexo, tamanho, 
													dieta, tem_veterinario, tem_tratador, nome_batismo,
													cor_pelo, autorizacao_ibama, uf_origem);
				lista_animais.insert({id, animal});

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
	/**@brief verifica o tipo de animal escolhido para inserir e instancia usando o construtor da classe Anfibio*/
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
		/**@brief verifica o tipo de animal escolhido para inserir e instancia usando o construtor da classe Reptil*/
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
		/**@brief verifica o tipo de animal escolhido para inserir e instancia usando o construtor da classe Ave*/
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
/**@brief Função para listagem dos animais existentes no petshop */
void Controlador::listarAnimais(int opc){
	map<int, Animal*>::iterator it;
	string opc_classe, opc_classificacao;
	char opc_sexo;

	/**@brief switch para verificar de que formar o usuario quer que lister os animais, procurando dentro do map pelas opção escolhida pelo usuario */
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
/**@brief função para remoção do animal do map */
void Controlador::removerAnimal(){
	map<int, Animal*>::iterator it_animal;
	int id;
	
	cout << "Digite o ID do animal que você deseja remover" << endl;
	cin >> id;
	/**@brief um iterador vai procurar dentro do map pelo id inserido pelo usuario se o id for encontrado o map ira da erase no mesmo */
  	it_animal = lista_animais.find(id);
	if (it_animal != lista_animais.end()){

		//delete  it_animal->second;
		lista_animais.erase(id);
		cout << "Animal Removido" << endl; 


	} else {
		cout << "Não foi encontrado Animal com esse id" << endl;
	}
}
/**@brief função para consultar animal*/
void Controlador::consultarAnimal(int id){
	map<int, Animal*>::iterator it_animal;

  	it_animal = lista_animais.find(id);
	/**@brief iterador ira percorrer o map a procura do animal com id inserido pelo usuario*/
	if (it_animal != lista_animais.end()){
		cout << *it_animal->second;
	} else {
		cout << "Não foi encontrado Animal com esse id" << endl;
	}
}
	/**@brief Função para editar os atributos de um animal existente */
void Controlador::editarAnimal(){
	map<int, Animal*>::iterator it;

	int id;
	string novo_valor;

	cout << "Indique o ID do Animal que você deseja alterar" << endl;
	cin >> id;
	/**@brief um iterador ira procurar pelo id inserido pelo usuario se o animal for encontrado o usuario podera alterar qualquer atribudo se o valor inserido pelo usuario for igual a "-" o valor atual permanecerar*/
	it = lista_animais.find(id);	
	if(it == lista_animais.end()){
		cout << "Não foi encontrado nenhum Animal com esse ID" << endl;
	} else {
		cout << "Se quiser manter o valor já salvo, insira -" << endl;

		cout << "Nome Científico: [" << it->second->getNomeCientifico() << "]: ";
		cin >> novo_valor;
		if(novo_valor != "-"){
			it->second->setNomeCientifico(novo_valor);
		}

		cout << "Sexo: [" << it->second->getSexo() << "]: ";
		cin >> novo_valor;
		if(novo_valor != "-"){
			char sx_aux = novo_valor[0];
			it->second->setSexo(sx_aux);
		}

		cout << "Tamanho: [" << it->second->getTamanho() << "]: ";
		cin >> novo_valor;
		if(novo_valor != "-"){
			it->second->setTamanho(stod(novo_valor));
		}

		cout << "Dieta: [" << it->second->getDieta() << "]: ";
		cin >> novo_valor;
		if(novo_valor != "-"){
			it->second->setDieta(novo_valor);
		}

		cout << "ID  Veterinario: [" << it->second->getIdVeterinario() << "]: ";
		cin >> novo_valor;
		if(novo_valor != "-"){
			it->second->setIdVeterinario(stoi(novo_valor));
		}

		cout << "ID Tratador: [" << it->second->getIdTratador() << "]: ";
		cin >> novo_valor;
		if(novo_valor != "-"){
			it->second->setIdTratador(stoi(novo_valor));
		}

		cout << "Nome Batismo: [" << it->second->getNomeBatismo() << "]: ";
		cin >> novo_valor;
		if(novo_valor != "-"){
			it->second->setNomeBatismo(novo_valor);
		}

		string classe = it->second->getClasse();
		/**@brief verificação se a classe foi alterada se foi alterada o usuario deve entrar com os atributos especificos de determinada classe*/
		if(classe == "Amphibia"){
			cout << "Total de Mudas: [" << reinterpret_cast<AnfibioDomestico*>(it->second)->getTotalMudas() << "]: ";
			cin >> novo_valor;
			if(novo_valor != "-"){
				reinterpret_cast<AnfibioDomestico*>(it->second)->setTotalMudas(stoi(novo_valor));
			}

			if(it->second->getClassificacao() == "Nativo"){
				AnfibioNativo* anf_nativo = reinterpret_cast<AnfibioNativo*>(it->second);
				
				cout << "Autorização Ibama: [" << anf_nativo->getAutorizacaoIbama() << "]: ";
				cin >> novo_valor;
				if(novo_valor != "-"){
					anf_nativo->setAutorizacaoIbama(novo_valor);
				}



				cout << "UF de Origem: [" << anf_nativo->getUfOrigem() << "]: ";
				cin >> novo_valor;
				if(novo_valor != "-"){
					anf_nativo->setUfOrigem(novo_valor);
				}
			} 

			if(it->second->getClassificacao() == "Exotico"){
				AnfibioExotico* anf_exot = reinterpret_cast<AnfibioExotico*>(it->second);
				cout << "Autorização Ibama: [" << anf_exot->getAutorizacaoIbama() << "]: ";
				cin >> novo_valor;
				if(novo_valor != "-"){
					anf_exot->setAutorizacaoIbama(novo_valor);
				}

				cout << "Pais de Origem: [" << anf_exot->getPaisOrigem() << "]: ";
				cin >> novo_valor;
				if(novo_valor != "-"){
					anf_exot->setPaisOrigem(novo_valor);
				}
				
				cout << "Cidade de Origem: [" << anf_exot->getCidadeOrigem() << "]: ";
				cin >> novo_valor;
				if(novo_valor != "-"){
					anf_exot->setCidadeOrigem(novo_valor);
				}
			} 
		}

		else if(classe == "Ave"){
			cout << "Tamanho do bico em cm: [" << reinterpret_cast<AveDomestico*>(it->second)->getTamanhoBico() << "]: ";
			cin >> novo_valor;
			if(novo_valor != "-"){
				reinterpret_cast<AveDomestico*>(it->second)->setTamanhoBico(stod(novo_valor));
			}

			cout << "Envergadura das asas: [" << reinterpret_cast<AveDomestico*>(it->second)->getEnvergaduraAsas() << "]: ";
			cin >> novo_valor;
			if(novo_valor != "-"){
				reinterpret_cast<AveDomestico*>(it->second)->setEnvergaduraAsas(stod(novo_valor));
			}

			if(it->second->getClassificacao() == "Nativo"){
				AveNativo* ave_nat = reinterpret_cast<AveNativo*>(it->second);
				cout << "Autorização Ibama: [" << ave_nat->getAutorizacaoIbama() << "]: ";
				cin >> novo_valor;
				if(novo_valor != "-"){
					ave_nat->setAutorizacaoIbama(novo_valor);
				}

				cout << "UF de Origem: [" << ave_nat->getUfOrigem() << "]: ";
				cin >> novo_valor;
				if(novo_valor != "-"){
					ave_nat->setUfOrigem(novo_valor);
				}
			} 

			if(it->second->getClassificacao() == "Exotico"){
				AveExotico* ave_exot = reinterpret_cast<AveExotico*>(it->second);
				cout << "Autorização Ibama: [" << ave_exot->getAutorizacaoIbama() << "]: ";
				cin >> novo_valor;
				if(novo_valor != "-"){
					ave_exot->setAutorizacaoIbama(novo_valor);
				}

				cout << "Pais de Origem: [" << ave_exot->getPaisOrigem() << "]: ";
				cin >> novo_valor;
				if(novo_valor != "-"){
					ave_exot->setPaisOrigem(novo_valor);
				}
				
				cout << "Cidade de Origem: [" << ave_exot->getCidadeOrigem() << "]: ";
				cin >> novo_valor;
				if(novo_valor != "-"){
					ave_exot->setCidadeOrigem(novo_valor);
				}
			} 
		}

		else if(classe == "Mammalia"){
			cout << "Cor do pelo: [" << reinterpret_cast<MamiferoDomestico*>(it->second)->getCorPelo() << "]: ";
			cin >> novo_valor;
			if(novo_valor != "-"){
				reinterpret_cast<MamiferoDomestico*>(it->second)->setCorPelo(novo_valor);
			}

			if(it->second->getClassificacao() == "Nativo"){
				MamiferoNativo* mam_nat = reinterpret_cast<MamiferoNativo*>(it->second);
				cout << "Autorização Ibama: [" << mam_nat->getAutorizacaoIbama() << "]: ";
				cin >> novo_valor;
				if(novo_valor != "-"){
					mam_nat->setAutorizacaoIbama(novo_valor);
				}

				cout << "UF de Origem: [" << mam_nat->getUfOrigem() <<": ";
				cin >> novo_valor;
				if(novo_valor != "-"){
					mam_nat->setUfOrigem(novo_valor);
				}
			} 

			if(it->second->getClassificacao() == "Exotico"){
				MamiferoExotico* mam_exot = reinterpret_cast<MamiferoExotico*>(it->second);
				cout << "Autorização Ibama: [" << mam_exot->getAutorizacaoIbama() << "]: ";
				cin >> novo_valor;
				if(novo_valor != "-"){
					mam_exot->setAutorizacaoIbama(novo_valor);
				}

				cout << "Pais de Origem: [" << mam_exot->getPaisOrigem() << "]: ";
				cin >> novo_valor;
				if(novo_valor != "-"){
					mam_exot->setPaisOrigem(novo_valor);
				}
				
				cout << "Cidade de Origem: [" << mam_exot->getCidadeOrigem() << "]: ";
				cin >> novo_valor;
				if(novo_valor != "-"){
					mam_exot->setCidadeOrigem(novo_valor);
				}
			} 
		}

		else if(classe == "Reptilia"){
			cout << "Venenoso (S/N): [" << reinterpret_cast<ReptilDomestico*>(it->second)->getVenenoso() << "]: ";
			cin >> novo_valor;
			if(novo_valor != "-"){
				if(novo_valor == "S"){
					bool v_aux = true;
					reinterpret_cast<ReptilDomestico*>(it->second)->setVenenoso(v_aux);	
				} else {
					bool v_aux = false;
					reinterpret_cast<ReptilDomestico*>(it->second)->setVenenoso(v_aux);	
				}	
			}

			cout << "Tipo de Veneno: [" << reinterpret_cast<ReptilDomestico*>(it->second)->getTipoVeneno() << "]: ";
			cin >> novo_valor;
			if(novo_valor != "-"){
				reinterpret_cast<ReptilDomestico*>(it->second)->setTipoVeneno(novo_valor);
			}

			if(it->second->getClassificacao() == "Nativo"){
				ReptilNativo* rep_nat = reinterpret_cast<ReptilNativo*>(it->second);
				cout << "Autorização Ibama: [" << rep_nat->getAutorizacaoIbama() << "]: ";
				cin >> novo_valor;
				if(novo_valor != "-"){
					rep_nat->setAutorizacaoIbama(novo_valor);
				}

				cout << "UF de Origem: [" << rep_nat->getUfOrigem() << "]: ";
				cin >> novo_valor;
				if(novo_valor != "-"){
					rep_nat->setUfOrigem(novo_valor);
				}
			} 

			if(it->second->getClassificacao() == "Exotico"){
				ReptilExotico* rep_exot = reinterpret_cast<ReptilExotico*>(it->second);
				cout << "Autorização Ibama: [" << rep_exot->getAutorizacaoIbama() << "]: ";
				cin >> novo_valor;
				if(novo_valor != "-"){
					rep_exot->setAutorizacaoIbama(novo_valor);
				}

				cout << "Pais de Origem: [" << rep_exot->getPaisOrigem() << "]: ";
				cin >> novo_valor;
				if(novo_valor != "-"){
					rep_exot->setPaisOrigem(novo_valor);
				}
				
				cout << "Cidade de Origem: [" << rep_exot->getCidadeOrigem() << "]: ";
				cin >> novo_valor;
				if(novo_valor != "-"){
					rep_exot->setCidadeOrigem(novo_valor);
				}
			} 
		}

		cout << "Animal editado com sucesso!" << endl;
	}
}
	

/**@brief  Construtor e Destrutor do controlador.*/
Controlador::Controlador(){}
Controlador::~Controlador(){}