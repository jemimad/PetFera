#ifndef _ANFIBIO_EXOTICO_
#define _ANFIBIO_EXOTICO_

#include <iostream>
#include "anfibio.h"
#include "animalExotico.h"


class AnfibioExotico : public Anfibio, AnimalExotico{
	public:
		AnfibioNativo();
		~AnfibioExotico();
};



#endif
