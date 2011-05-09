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

THASHCalendario::~THASHCalendario()
{
	for (int i = 0; i < tamanyo; i++)
	{
		delete &tabla[i];
	}
	
	tamanyo = 0;
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

THASHCalendario &
THASHCalendario::operator=(const THASHCalendario& hash)
{
	if (this!=&hash)
	{
		tamanyo= hash.tamanyo;
		tabla= new TListaCalendario[tamanyo];
		for (int i = 0; i < tamanyo; i++)
		{
			tabla[i]= hash.tabla[i];
		}
	}
}

bool
THASHCalendario::operator==(const THASHCalendario& hash)
{
	bool igual = true;
	
	if( tamanyo == hash.tamanyo)
	{
		bool flag = true;
		
		for(int i = 0; i < tamanyo && flag; i++)
		{
			if( &tabla[i] != &hash.tabla[i])
			{
				igual = false;
				flag = false;
			}
		}
	}
	else igual = false;
	
	
	return igual;
}

bool 
THASHCalendario::EsVacia()
{
		return (tabla==NULL);
}

bool
THASHCalendario::Insertar( const TCalendario &cal)
{
	
}

bool
THASHCalendario::Borrar( const TCalendario &cal)
{
}

bool
THASHCalendario::Buscar( const TCalendario &cal)
{
}

int
THASHCalendario::Tamanyo()
{
	return tamanyo;
}

int
THASHCalendario::NElementos()
{
	int sumares = 0;
	
	for (int i = 0; i < tamanyo; i++)
	{
		//~ tabla[i]=cop.tabla[i];
		sumares += tabla[i].Longitud();                              
	}
	
	return sumares;
}

TListaCalendario
THASHCalendario::Lista()
{
	TListaCalendario listaRes;
	
	int totalElem = 0;
	//~ totalElem = tabla.NElementos();
	
	TListaPos lPos;
	
	for(int i=0; i < tamanyo; i++)
	{
		for()
		{
		}
	}
	
	return listaRes;
}
