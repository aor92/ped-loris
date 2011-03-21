#include "tavlcalendario.h"


TNodoAVL::TNodoAVL()
{}

TNodoAVL::TNodoAVL( const TNodoAVL &n)
{
	item = n.item;
	iz = n.iz;
	de = n.de;
}

TNodoAVL::~TNodoAVL()
{
	//Funcion auxiliar?
}

void 
TNodoAVL::Eliminar( TNodoAVL &n)
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

TNodoAVL &
TNodoAVL::operator =(const TNodoAVL & n )
{
	if( this != &n)
	{
		item = n.item;
		iz = n.iz;
		de = n.de;
	}
}

////////////////////////////////////////////////////
/////////////AVLSTART//////////////////

TAVLCalendario::TAVLCalendario()
{}

TAVLCalendario::TAVLCalendario(const TAVLCalendario &avl )
{
	if( avl.raiz != NULL )
	{
		raiz = new TNodoAVL( *avl.raiz );
	}
	else
	{
		raiz = NULL;
	}
}

TAVLCalendario&
TAVLCalendario::operator=(const TAVLCalendario& avl)
{
	this->~TAVLCalendario();
	if(this!=&acopiar)
	{
		Copiar(acopiar);
	}
	
	return (*this);
}

void 
TABBCalendario::Copiar(const TAVLCalendario &acopiar)
{
	if (acopiar.raiz!=NULL)
	{
		TNodoAVL *aux=new TNodoAVL();
		aux->item=acopiar.raiz->item;
		raiz=aux;
		(raiz->iz).Copiar(acopiar.raiz->iz);
		(raiz->de).Copiar(acopiar.raiz->de);
	}
	else raiz=NULL;
}

TAVLCalendario::~TAVLCalendario()
{
	if( raiz != NULL )
	{
		delete raiz;
		raiz = NULL;
	}
}
