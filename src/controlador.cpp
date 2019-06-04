#include <string>
#include <map>
#include <utility>
#include <iterator>
//#include "../include/animal.h"
#include "../include/funcionario.h"
#include "../include/tratador.h"
#include "../include/veterinario.h"
#include "../include/controlador.h"

#include "../include/animal.h"


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


//CONSTRUTORES

Controlador::Controlador(){}

Funcionario::Funcionario(int id, string funcao, string nome, string cpf, short idade, short tipoSanguineo,
					char fatorRH, string especialidade):m_id(id), m_funcao(funcao), m_nome(nome), m_cpf(cpf),
					m_idade(idade), m_tipoSanguineo(tipoSanguineo), m_fatorRH(fatorRH),
					m_especialidade(especialidade){

	//Funcionario(nome):m_nome(nome);
	//lista_funcionarios.insert(pair<int, func>(chave, objeto));
}

Tratador::Tratador(int id, string funcao, string nome, string cpf, short idade, char tipoSanguineo,
					char fatorRH, string especialidade, int nivelSeguranca):
					Funcionario(id, funcao, nome, cpf, idade, 
					tipoSanguineo, fatorRH, especialidade), 
					m_nivelSeguranca(nivelSeguranca){
}


Veterinario::Veterinario(int id, string funcao, string nome, string cpf, short idade, char tipoSanguineo,
					char fatorRH, string especialidade, string cmrv):
					Funcionario(id, funcao, nome, cpf, idade, 
					tipoSanguineo, fatorRH, especialidade),  
					m_cmrv(cmrv){
}



Animal::Animal(int id, string classe, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo): m_id(id), m_classe(classe), m_nome_cientifico(nome_cientifico),
			m_sexo(sexo), m_tamanho(tamanho), m_dieta(dieta), m_tem_veterinario(tem_veterinario),
			m_tem_tratador(tem_tratador), m_nome_batismo(nome_batismo){
}


//DESTRUTORES

Funcionario::~Funcionario(){}
Tratador::~Tratador(){}
Veterinario::~Veterinario(){}
Controlador::~Controlador(){}
Animal::~Animal(){}


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

		Funcionario* func = new Tratador(id, funcao, nome, cpf, idade, tipoSanguineo, fatorRH, especialidade, nivelSeguranca);
		lista_funcionarios.insert({id, func});
		cout << "Tratador adicionado com sucesso!" << endl;

	} else {
		string cmrv;
		string funcao = "Veterinario";

		cout << "CMRV: " << endl;
		cin >> cmrv;

		Funcionario* func = new Veterinario(id, funcao, nome, cpf, idade, tipoSanguineo, fatorRH, especialidade, cmrv);
		lista_funcionarios.insert({id, func});
		cout << "Veterinário adicionado com sucesso!" << endl;
	}
}


/*void Controlador::removerFuncionario(){
}*/

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
	//Veterinario veterinario;
	//Tratador tratador;
	string nome_batismo;

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

	/*cout << "ID do Veterinario: " << endl;
	cin >> veterinario;
	cout << "ID do Tratador: " << endl;
	cin >> tratador;*/

	cout << "Nome de batismo: " << endl;
	cin >> nome_batismo;


	switch(resolveOption(classe)){
	    case Mamifero: {
	       	string cor_pelo;
			cout << "Cor do Pelo:" << endl;
			cin >> cor_pelo;
	    	break;
	    }

	    case Anfibio: {
	        int total_de_mudas;
			cout << "Total de Mudas:" << endl;
			cin >> total_de_mudas;	        
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
			}
        	break;
   		}

        case Ave: {
        	double tamanho_do_bico_cm;
			double envergadura_das_asas;

			cout << "Tamanho do bico (em cm)" << endl;
			cin >> tamanho_do_bico_cm;				

			cout << "Envergadura das asas" << endl;
			cin >> envergadura_das_asas;
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

	cout << "Este animal é:" << endl << 
		"1- Nativo" << endl <<
		"2- Exotico" << endl;
	cin >> opc;
	switch(opc){
		case 1: {
			string uf_origem;
			string autorizacao;

			cout << "UF de Origem" << endl;
			cin >> uf_origem;

			cout << "Autorização" << endl;
			cin >> autorizacao;

			break;
		}
		case 2: {
			string pais_origem;
			cout << "País de Origem" << endl;
			cin >> pais_origem;

			break;	
		}
	}

	cout << "Autorização do IBAMA: " << endl;
	cin >> autorizacao_ibama;

	cout << "FIM";


} 