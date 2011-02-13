#unclude "tabbcalendario.h"
#include "tcalendario.h"


TNodoABB::TNodoABB()
{
	iz = de = NULL;
}

TNodoABB::TNodoABB( const TNodoABB &nodo )
{
	item = nodo.item;
	
	if( nodo.iz != NULL) iz = nodo.iz;
	if( nodo.de != NULL) de = nodo.de;
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
	if( n.iz.nodo != NULL )
	{
		Eliminar( *n.iz.nodo );
	}
	if( n.de.nodo != NULL )
	{
		Eliminar( *n.de.nodo);
	}
	n.iz.nodo = NULL;
	n.de.nodo = NULL;
	item.~TCalendario();
}

TNodoABB&
TNodoABB::operator =(const TNodoABB &nodo )
{
	if( nodo != &this )
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
