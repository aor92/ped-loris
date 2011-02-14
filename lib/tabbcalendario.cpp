#include "tabbcalendario.h"

TNodoABB::TNodoABB()
{}

TNodoABB::TNodoABB( const TNodoABB &nodo )
{
	item = nodo.item;
	iz = nodo.iz;
	de = nodo.de;
}

TNodoABB::~TNodoABB()
{
	Eliminar(*this);
	
	/*if( iz != NULL ) delete iz;
	if( de != NULL ) delete de;
	iz = de = NULL;*/
}

void 
TNodoABB::Eliminar( TNodoABB &n)
{
	if( n.iz.raiz != NULL )
	{
		Eliminar( *n.iz.raiz );
	}
	if( n.de.raiz != NULL )
	{
		Eliminar( *n.de.raiz);
	}
	n.iz.raiz = NULL;
	n.de.raiz = NULL;
	item.~TCalendario();
}

TNodoABB&
TNodoABB::operator =(const TNodoABB &nodo )
{
	if( this != &nodo )
	{
		item = nodo.item;
		de = nodo.de;
		iz = nodo.iz;
	}
}

	//////////////////////////////////////////////////////////////////////
///////////////////////////ABBCALENDARIO//////////////////////////////////////  *3* 
	//////////////////////////////////////////////////////////////////////

TABBCalendario::TABBCalendario()
{
	raiz = NULL;
}

TABBCalendario::~TABBCalendario()
{
	if( raiz != NULL )
	{
		delete raiz;
		raiz = NULL;
	}
}

TABBCalendario::TABBCalendario(const TABBCalendario &a )
{
	if( a.raiz != NULL )
	{
		raiz = new TNodoABB( *a.raiz );
	}
	else
	{
		raiz = NULL;
	}
}

TABBCalendario&
TABBCalendario::operator =(const TABBCalendario& a )
{
	if( this != &a)
	{
		this->~TABBCalendario();
		
		if( a.raiz != NULL )
		{
			raiz = new TNodoABB(*a.raiz);
		}
		
	}
	
	return *this;
}

bool
TABBCalendario::operator ==( const TABBCalendario& a )
{	
	bool igual = false;
	
	return igual;	
}

bool
TABBCalendario::EsVacio() const
{
	bool vacio = true;
	
	if( raiz != NULL ) vacio = false;
	
	return vacio;
}
