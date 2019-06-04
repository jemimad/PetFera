#ifndef _REPTIL_
#define _REPTIL_

#include <iostream>
#include <string>

#include "animal.h"

class Reptil : public Animal{
	protected:
		bool m_venenoso;
		string m_tipo_veneno;
	public:
		Reptil();
		~Reptil();
};