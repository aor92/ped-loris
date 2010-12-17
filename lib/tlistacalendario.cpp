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
	if (pos!=NULL)
	{
		
	}
	
}

bool
TListaPos::EsVacia()
{
	return pos==NULL;
}

/**********Fin TListaPos***************************/
/**********Inicio TListaCalendario**********************/

TListaCalendario::TListaCalendario():TNodoCalendario()
{}

TListaCalendario::TListaCalendario(TListaCalendario& lista)
{
}

TListaCalendario::~TListaCalendario()
{}

TListaCalendario& 
TListaCalendario::operator=(TListaCalendario &)
{}
	
bool
TListaCalendario::operator==(TListaCalendario &)
{}

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
{}
		
TListaPos
TListaCalendario::Primera()
{}

TListaPos
TListaCalendario::Ultima()
{}
	
TListaCalendario
TListaCalendario::SumarSubl (int, int, TListaCalendario&, int, int)
{}
		
TListaCalendario
TListaCalendario::ExtraerRango (int , int )
{}
