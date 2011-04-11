#ifndef __THASHCALENDARIO_H
#define __THASHCALENDARIO_H

#include <iostream>
#include "tcalendario.h"
#include "tlistacalendario.h"

class THASHCalendario
{
	private:
		
		int tamanyo;
		TListaCalendario *tabla;
	
	public:
	
		THASHCalendario();
		THASHCalendario(int);
		THASHCalendario(const THASHCalendario&);
		~THASHCalendario();
};


#endif
