#ifndef _ANFIBIO_
#define _ANFIBIO_

#include <iostream>
#include "animal.h"

class Anfibio : public Animal{
	protected:
		int m_total_de_mudas;
		//date m_ultima_muda; procurar classe date
	public:

		Anfibio();
		~Anfibio();
};



#endif