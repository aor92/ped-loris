#include "tlistacalendario.h"

/**********Inicio TNodoCalendario**********************/
TNodoCalendario::TNodoCalendario():TCalendario()
{
	siguiente=NULL;
}
	
TNodoCalendario::TNodoCalendario(TNodoCalendario& nodo)
{
	if (siguiente!=NULL)
	{
		delete siguiente;
	}
	
	c=nodo.c;
	siguiente=nodo.siguiente;
}
	
TNodoCalendario::~TNodoCalendario()
{
		siguiente=NULL;
}

TNodoCalendario& 
TNodoCalendario::operator=(TNodoCalendario& nodo)
{
	if (siguiente!=NULL)
	{
		delete siguiente;
	}
	
		if (this!=NULL)
		{
			c=nodo.c;
			siguiente=nodo.siguiente;
		}
		
}

/**********Fin TNodoCalendario**********************/
/**********Inicio TListaPos**********************/

TListaPos::TListaPos()
{
		pos=NULL;
}

TListaPos::TListaPos(TListaPos& iter)
{
	if (pos!=NULL)
	{
		delete pos;
	}
	else
	{
		pos=iter.pos;
	}
}

TListaPos::~TListaPos()
{
		pos=NULL;
}
	
TListaPos&
TListaPos::operator=(TListaPos& iter)
{
		if (pos!=NULL)
		{
			delete pos;
		}
		
		if (this!=NULL)
		{
			pos=iter.pos;
		}
		
		return *this;
}
	
bool
TListaPos::operator==(TListaPos& iter)
{
		return pos==iter.pos;
}
			
bool
TListaPos::operator!=(TListaPos& iter)
{
		return !(pos==iter.pos);
}
			
TListaPos
TListaPos::Siguiente()
{
	TListaPos aux;
	
	if (pos!=NULL)
	{
		aux = pos->siguiente;
	}
	
	return aux;
}

bool
TListaPos::EsVacia()
{
	return pos==NULL;
}

/**********Fin TListaPos***************************/
/**********Inicio TListaCalendario**********************/

TListaCalendario::TListaCalendario()
{
	primero = NULL;
}

TListaCalendario::TListaCalendario(TListaCalendario& lista)
{
	
	if( this != &p)
	{

		primero = new TNodoCalendario(*p.primero);
		TListaPos ant;
		ant.pos = p.primero;
		TListaPos sig;
		sig.pos = p.primero;
		sig.pos = sig.pos->siguiente;

		//if( p.primero->siguiente != NULL )
		if( sig.pos != NULL )
		{
			//TListaNodo *ant = p.primero;
			//TListaNodo *sig = p.primero->siguiente;
			while(  sig.pos != NULL )
			{
				ant.pos->siguiente = new TNodoCalendario(*sig.pos);
				ant.pos = sig.pos;
				sig.pos = sig.pos->siguiente;
				if( sig.pos == NULL ) ultimo = ant.pos;
			}
			ant.pos = NULL;
			sig.pos = NULL;
		}
	}
}

TListaCalendario::~TListaCalendario()
{
if ( primero != NULL)
	{
		TNodoCalendario *ant = primero;
		if ( primero->siguiente != NULL )
		{
			TNodoCalendario *sig = primero->siguiente;
			while( sig != NULL )
			{
				delete ant;
				ant = sig;
				sig = sig->siguiente;
			}
			sig = NULL;
		}
		else
		{
			delete ant;
		}
		ant = NULL;
		primero = NULL;
		ultimo = NULL;
	}	
}

TListaCalendario& 
TListaCalendario::operator=(const TListaCalendario &lista)
{
		
	if( this != &lista)
	{
		TListaPos ant;
		TListaPos sig;
		TListaPos antp;
		TListaPos sigp;

		this->~TListaPoro();//Comprobar

		ant.pos = lista.primero;

		while( ant.pos != NULL )
		{
				this->Insertar(ant.pos->c);
				ant.pos = ant.pos->siguiente;
		}
	}
}
	
bool
TListaCalendario::operator==(const TListaCalendario &lista) const
{
	TNodoCalendario *aux1 = primero;
	TNodoCalendario *aux2 = lista.primero;
	int longitud = 0, longitudaux = 0;
	bool igual = true;
	
	longitud = Longitud();
	longitudaux = lista.Longitud();

	if( longitud != longitudaux )
	{
		igual = false;
	}
	else
	{
		while( aux1 != NULL && aux2 != NULL && igual )
		{
			if( aux1->c != aux2->c)
			{
				igual = false;
			}
			else
			{
				aux1 = aux1->siguiente;
				aux2 = aux2->siguiente;
				
			}
		}
	}


	return igual;
}

TListaCalendario
TListaCalendario::operator+ (TListaCalendario &)
{}
		
TListaCalendario
TListaCalendario::operator- (TListaCalendario &)
{}
		
Bool
TListaCalendario::Insertar(TCalendario &)
{}
		
bool
TListaCalendario::Borrar(TCalendario &)
{}
		
bool
TListaCalendario::Borrar (TListaPos &)
{}
	
bool 
TListaCalendario::Borrar(int,int,int)
{}

bool
TListaCalendario::EsVacia()
{}

TCalendario
TListaCalendario::Obtener(TListaPos &)
{}
		
bool 
TListaCalendario::Buscar(TCalendario &)
{}
		
Int
TListaCalendario Longitud()
{
	int lon = 0;
	TListaPos aux;
	aux.pos = primero;

	while( aux.pos != NULL )
	{
		lon++;
		aux.pos = aux.pos->siguiente;
	}

	return lon;	
}
		
TListaPos
TListaCalendario::Primera()
{
	TListaPos aux;
	
	if( !this->EsVacia() )
	{
		aux.pos = primero;
	}

	return aux;
}

TListaPos
TListaCalendario::Ultima()
{
	TListaPos aux, ant;
	aux.pos = primero;
	
	if( !this->EsVacia() )
	{
		ant = pos;
		while( aux.pos != NULL )
		{
			aux.pos = aux.pos->siguiente;
		}
	}

	return ant;
}
	
TListaCalendario
TListaCalendario::SumarSubl (int, int, TListaCalendario&, int, int)
{}
		
TListaCalendario
TListaCalendario::ExtraerRango (int , int )
{}
