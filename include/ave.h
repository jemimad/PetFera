#ifndef _AVE_
#define _AVE_

#include <iostream>
#include "animal.h"


class Ave : public Animal{
	protected:
		double m_tamanho_do_bico_cm;
		double m_envergadura_das_asas;
	public:
		Ave();
		~Ave();
};



#endif