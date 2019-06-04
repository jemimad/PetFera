#ifndef _MAMIFERO_
#define _MAMIFERO_

#include <iostream>
#include <string>

#include "animal.h"

class Mamifero : public Animal{
	protected:
		string m_cor_pelo;
	public:
		Mamifero();
		~Mamifero();
};



#endif
