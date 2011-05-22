#include "thashcalendario.h"
#include "string.h"


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
	bool insertado = false;
	int pos=H(cal);
	
	if (tabla!=NULL && Tamanyo()>0)
	{
		tabla[pos].Insertar(cal);
		insertado=true;
	}
	
	return insertado;
}

int
THASHCalendario::H(const TCalendario c ) const 
{
	int a_colocar;
	
	a_colocar=c.Dia()*1000000+c.Mes()*10000+c.Anyo();
	
	return a_colocar % Tamanyo();
}

bool
THASHCalendario::Borrar( const TCalendario &cal)
{
	bool insertado = false;
	int pos=H(cal);
	
	if (tabla!=NULL && Tamanyo()>0)
	{
		tabla[pos].Borrar(cal);
		insertado=true;
	}
	
	return insertado;
}

bool
THASHCalendario::Buscar( const TCalendario &cal)
{
	bool insertado = false;
	int pos=H(cal);
	
	if (tabla!=NULL && Tamanyo()>0)
	{
		tabla[pos].Buscar(cal);
		insertado=true;
	}
	
	return insertado;
}

int
THASHCalendario::Tamanyo() const 
{
	return tamanyo;
}

int
THASHCalendario::NElementos() const
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
THASHCalendario::Lista() const
{
	TListaCalendario listaRes;
	
	//~ int totalElem = 0;
	//~ totalElem = tabla.NElementos();
	//~ 
	//~ TListaPos lPos;
	//~ 
	//~ for(int i=0; i < tamanyo; i++)
	//~ {
		//~ for( lPos = tabla[i].Primera(); !lPos.EsVacia() ; lPos.Siguiente() )
		//~ {
			//~ listaRes.Insertar(tabla[i].Obtener(lPos));
		//~ }
	//~ }
	//~ 
	//~ return listaRes;
	
	for (int i = 0; i < Tamanyo(); i++)
	{
		listaRes=listaRes+tabla[i];//el operador suma de las listas lo permite.
	}
	
	return listaRes;
	
}

int*
THASHCalendario::BuscarLista(const TListaCalendario& lista)const 
{
	int *result= new int[lista.Longitud()];
	TListaCalendario tabla_en_lista=Lista();
	TListaPos actual=lista.Primera();
	TListaPos actual_tabla=tabla_en_lista.Primera(); //volcamos tabla a una lista
	
	int pos_en_lista=1;
	int pos_en_listatabla=1;
	
	while (!actual.EsVacia() && Tamanyo()>0)
	{
		if(tabla_en_lista.Buscar(lista.Obtener(actual)))//Entra si es encontrado en la tabla
		{
			while(!actual_tabla.EsVacia())
			{
				if (lista.Obtener(actual)==tabla_en_lista.Obtener(actual_tabla))
				{
					result[pos_en_lista]=pos_en_listatabla;
					actual_tabla=actual_tabla.Siguiente();
					pos_en_listatabla++;
				}
				else
				{
					actual_tabla=actual_tabla.Siguiente();
					pos_en_listatabla++;
				}
				
			}
			
		}
		else//No esta en la tabla hash
		{
			result[pos_en_lista]=0;
		}
		pos_en_lista++;
		actual=actual.Siguiente();
	}
	
	return result;
}
