#include "thashcalendario.h"


THASHCalendario::THASHCalendario()
{
	tamanyo = 0;
	tabla = NULL;
}

THASHCalendario::THASHCalendario(int t)
{
	if( t <= 0 )
	{
		tamanyo = 0;
		tabla = NULL;
	}
	else
	{
		tamanyo = t;
		tabla = new TListaCalendario[t];
	}
}
