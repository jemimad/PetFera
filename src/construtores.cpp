#include "../include/funcionario/tratador.h"
#include "../include/funcionario/veterinario.h"

#include "../include/animal/animal.h"

#include "../include/mamifero/mamiferoExotico.h"
#include "../include/mamifero/mamiferoNativo.h"
#include "../include/mamifero/mamiferoDomestico.h"

#include "../include/anfibio/anfibioExotico.h"
#include "../include/anfibio/anfibioNativo.h"
#include "../include/anfibio/anfibioDomestico.h"

#include "../include/reptil/reptilExotico.h"
#include "../include/reptil/reptilNativo.h"
#include "../include/reptil/reptilDomestico.h"

#include "../include/ave/aveExotico.h"
#include "../include/ave/aveNativo.h"
#include "../include/ave/aveDomestico.h"


//CONSTRUTORES PRONTO.
Controlador::Controlador(){}

Funcionario::Funcionario(int id, string funcao, string nome, string cpf, short idade, short tipoSanguineo,
					char fatorRH, string especialidade):m_id(id), m_funcao(funcao), m_nome(nome), m_cpf(cpf),
					m_idade(idade), m_tipoSanguineo(tipoSanguineo), m_fatorRH(fatorRH),
					m_especialidade(especialidade){
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


/*------------------------------------ANIMAL----------------------------------------*/
Animal::Animal(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo): m_id(id), m_classe(classe), m_classificacao(classificacao), m_nome_cientifico(nome_cientifico),
			m_sexo(sexo), m_tamanho(tamanho), m_dieta(dieta), m_tem_veterinario(tem_veterinario),
			m_tem_tratador(tem_tratador), m_nome_batismo(nome_batismo){
}

AnimalSilvestre::AnimalSilvestre(string autorizacao_ibama):m_autorizacao_ibama(autorizacao_ibama){
}

AnimalExotico::AnimalExotico(string autorizacao_ibama, string pais_origem, string cidade_origem):
				AnimalSilvestre(autorizacao_ibama),m_pais_origem(pais_origem),m_cidade_origem(cidade_origem){
}

AnimalNativo::AnimalNativo(string autorizacao_ibama, string uf_origem):
				AnimalSilvestre(autorizacao_ibama),m_uf_origem(uf_origem){
}



/*------------------------------------MAMÍFERO---------------------------------------*/
Mamifero::Mamifero(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, string cor_pelo): 
			Animal(id, classe, classificacao, nome_cientifico, sexo, tamanho, dieta, tem_veterinario, tem_tratador, nome_batismo),
			m_cor_pelo(cor_pelo){
}


MamiferoNativo::MamiferoNativo(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, string cor_pelo, string autorizacao_ibama, string uf_origem):
			Mamifero(id, classe, classificacao, nome_cientifico, sexo, tamanho, dieta, tem_veterinario, tem_tratador, nome_batismo, cor_pelo),
			AnimalNativo(autorizacao_ibama, uf_origem){
}

MamiferoExotico::MamiferoExotico(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, string cor_pelo, string autorizacao_ibama, string pais_origem, string cidade_origem):
			Mamifero(id, classe, classificacao, nome_cientifico, sexo, tamanho, dieta, tem_veterinario, tem_tratador, nome_batismo, cor_pelo),
			AnimalExotico(autorizacao_ibama, pais_origem, cidade_origem){
}

MamiferoDomestico::MamiferoDomestico(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, string cor_pelo):
			Mamifero(id, classe, classificacao, nome_cientifico, sexo, tamanho, dieta, tem_veterinario, tem_tratador, nome_batismo, cor_pelo){
}
			




/*------------------------------------ANFIBIO---------------------------------------*/
Anfibio::Anfibio(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, int total_mudas): 
			Animal(id, classe, classificacao, nome_cientifico, sexo, tamanho, dieta, tem_veterinario, tem_tratador, nome_batismo),
			m_total_mudas(total_mudas){
}

AnfibioNativo::AnfibioNativo(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, int total_mudas, string autorizacao_ibama, string uf_origem): 
			Anfibio(id, classe, classificacao, nome_cientifico, sexo, tamanho, dieta, tem_veterinario, tem_tratador, nome_batismo, total_mudas),
			AnimalNativo(autorizacao_ibama, uf_origem){
}


AnfibioExotico::AnfibioExotico(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, int total_mudas, string autorizacao_ibama, string pais_origem, string cidade_origem): 
			Anfibio(id, classe, classificacao, nome_cientifico, sexo, tamanho, dieta, tem_veterinario, tem_tratador, nome_batismo, total_mudas),
			AnimalExotico(autorizacao_ibama, pais_origem, cidade_origem){
}

AnfibioDomestico::AnfibioDomestico(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, int total_mudas):
			Anfibio(id, classe, classificacao, nome_cientifico, sexo, tamanho, dieta, tem_veterinario, tem_tratador, nome_batismo, total_mudas){
}




/*------------------------------------REPTIL---------------------------------------*/
Reptil::Reptil(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, bool venenoso, string tipo_veneno): 
			Animal(id, classe, classificacao, nome_cientifico, sexo, tamanho, dieta, tem_veterinario, tem_tratador, nome_batismo),
			m_venenoso(venenoso), m_tipo_veneno(tipo_veneno){
}

ReptilNativo::ReptilNativo(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, bool venenoso, string tipo_veneno, string autorizacao_ibama, string uf_origem): 
			Reptil(id, classe, classificacao, nome_cientifico, sexo, tamanho, dieta, tem_veterinario, tem_tratador, nome_batismo,
			venenoso,tipo_veneno),
			AnimalNativo(autorizacao_ibama, uf_origem){
}

ReptilExotico::ReptilExotico(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, bool venenoso, string tipo_veneno, string autorizacao_ibama, string pais_origem, string cidade_origem): 
			Reptil(id, classe,  classificacao, nome_cientifico, sexo, tamanho, dieta, tem_veterinario, tem_tratador, nome_batismo,
			venenoso,tipo_veneno),
			AnimalExotico(autorizacao_ibama, pais_origem, cidade_origem){
}

ReptilDomestico::ReptilDomestico(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, bool venenoso, string tipo_veneno):
			Reptil(id, classe, classificacao, nome_cientifico, sexo, tamanho, dieta, tem_veterinario, tem_tratador, nome_batismo, venenoso, tipo_veneno){
}




/*------------------------------------AVE---------------------------------------*/
Ave::Ave(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, double tamanho_bico_cm, double envergadura_asas): 
			Animal(id, classe, classificacao, nome_cientifico, sexo, tamanho, dieta, tem_veterinario, tem_tratador, nome_batismo),
			m_tamanho_bico_cm(tamanho_bico_cm), m_envergadura_asas(envergadura_asas){
}


AveNativo::AveNativo(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, double tamanho_bico_cm, double envergadura_asas, string autorizacao_ibama, string uf_origem): 
			Ave(id, classe, classificacao, nome_cientifico, sexo, tamanho, dieta, tem_veterinario, tem_tratador, nome_batismo, tamanho_bico_cm, envergadura_asas),
			AnimalNativo(autorizacao_ibama, uf_origem){
}

AveExotico::AveExotico(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, double tamanho_bico_cm, double envergadura_asas, string autorizacao_ibama, string pais_origem, string cidade_origem): 
			Ave(id, classe, classificacao, nome_cientifico, sexo, tamanho, dieta, tem_veterinario, tem_tratador, nome_batismo, tamanho_bico_cm, envergadura_asas),
			AnimalExotico(autorizacao_ibama, pais_origem, cidade_origem){
}

AveDomestico::AveDomestico(int id, string classe, string classificacao, string nome_cientifico,char sexo, 
			double tamanho, string dieta, int tem_veterinario, int tem_tratador,
			string nome_batismo, double tamanho_bico_cm, double envergadura_asas):
			Ave(id, classe, classificacao, nome_cientifico, sexo, tamanho, dieta, tem_veterinario, tem_tratador, nome_batismo, tamanho_bico_cm, envergadura_asas){
}





//DESTRUTORES
Controlador::~Controlador(){}


Funcionario::~Funcionario(){}
Tratador::~Tratador(){}
Veterinario::~Veterinario(){}


Animal::~Animal(){}
AnimalSilvestre::~AnimalSilvestre(){}
AnimalExotico::~AnimalExotico(){}
AnimalNativo::~AnimalNativo(){}


Mamifero::~Mamifero(){}
MamiferoExotico::~MamiferoExotico(){}
MamiferoNativo::~MamiferoNativo(){}
MamiferoDomestico::~MamiferoDomestico(){}

Anfibio::~Anfibio(){}
AnfibioExotico::~AnfibioExotico(){}
AnfibioNativo::~AnfibioNativo(){}
AnfibioDomestico::~AnfibioDomestico(){}

Reptil::~Reptil(){}
ReptilExotico::~ReptilExotico(){}
ReptilNativo::~ReptilNativo(){}
ReptilDomestico::~ReptilDomestico(){}

Ave::~Ave(){}
AveExotico::~AveExotico(){}
AveNativo::~AveNativo(){}
AveDomestico::~AveDomestico(){}


