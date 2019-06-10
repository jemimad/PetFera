/*#include <fstream>
 #include <iostream>
 #include <string>

using namespace std;

 int main (){
    string classe;
    int id;
   ofstream outfile; // cria o objeto ofstream (arquivo pra escrita)
   outfile.open("teste.csv"); 
   if (outfile.is_open() && outfile.good()){ 
      cout << "Writing to the file" << endl;
      cout << "===================" << endl; 
      cout << "Enter class name: "; 
      getline(cin, classe); 
      cout << "Enter number of students: "; 
      cin >> id;
      cin.ignore();

      outfile << classe << ";" << id << ";" << endl; 
      outfile.close(); // fecha o arquivo
    }
    //VOU TESTAR ESSE CÓDIGO ESPERE
    //não, vou compartilhar tela
    //AMIGA EU QUERO Q VC BOTA PRA VC VER FUNCIONANDO COMO É PQ EU JÁ VI
   ifstream infile; // objeto pra leitura

   infile.open("joao.doc ");  // lê arquivo

   if (infile.is_open() && infile.good()){ //verificamos se está tudo bem
   cout << "Reading from the file" << endl; 
      cout << "=====================" << endl; 
      getline(infile, data);// uma linha
      cout << data << endl; 
      getline(infile, data); //outra linha
      cout << data << endl; 
      infile.close(); // fecha arquivo

      // rodem esse arquivo se acharem melhor p entender ai no sublime ou repl.it
      // agora tem q ver como vai ser pra separar pelo ";" mas eu acho que a
      // parte da escrita já podemos tentar

      //se fizer algo tipo
      outfile << id << ";" << nome << ";" //etc
      //erá que dá?
      //aconselho copiar o código e testar aí
      //com esse exemplo mais besta
      //se funcionar a gente já usa aqui
      //eu acho que sim
      // mas no caso seria assim
      // cin >> data;
      // note que data que recebe as coisas e depois mandamos data para o arquivo
      // talvez nesse caso foi preciso de data mas no nosso talvez não
      // a gente pode mandar já direto da forma como você disse.
      // tenta fazer isso aí no repl
          }
   return 0;
}

//ele leu data porque ta pedindo pro usuario, mas no nosso caso o usuario 
//ja digitou os dado la tudo feito um condenado
//beleza teste aí acho q funciona como vc disse

//vou botar e aí voce roda 
*/