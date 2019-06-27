#include <iostream>
#include "menu.h"
/**
 * @file main.cpp
 * @brief Programa PetFera C++
 * @author Carmem Stefanie, Italo Luiz, Jemima Dias
 * @date 26/06/2019
 */
int main(){

	Controlador petfera;

	petfera.abrirPetshop();/**@brief criação de um petshop */
	petfera.exibirMenu();/**@brief Exibição do menu do petshop*/


	return 0;
}
