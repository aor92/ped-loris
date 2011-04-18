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

THASHCalendario::THASHCalendario(const THASHCalendario& cop)
{
	if (this!=&cop)
	{
		tamanyo=cop.tamanyo;
		tabla= new TListaCalendario[tamanyo];
		for (int i = 0; i < tamanyo; i++)
		{
			tabla[i]=cop.tabla[i];
		}
		
	}
}
