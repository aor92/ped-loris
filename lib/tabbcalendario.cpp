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

bool 
TABBCalendario::Insertar(const TCalendario& nuevo)
{
	TNodoABB* aux=new TNodoABB();
	
	if (raiz==NULL) 
	{
		raiz=aux;
		raiz->item=nuevo;
		return true;
	}
	else if (nuevo>raiz->item) 
	{
		raiz->de.Insertar(nuevo);
	}
	else if(nuevo<raiz->item) 
	{
		raiz->iz.Insertar(nuevo);
	}
	else return false;
}


bool
TABBCalendario::Buscar(const TCalendario& find)const
{
		if (EsVacio())
		{
			return false;
		}
		else if (raiz->item==find)
		{
			return true;
		}
		else if (raiz->item>find)
		{
			raiz->de.Buscar(find);
		}
		else if (raiz->item<find)
		{
			raiz->iz.Buscar(find);
		}
}


TCalendario
TABBCalendario::Raiz()const
{
	TCalendario aux;

	if (!EsVacio())
	{
		aux=raiz->item;
	}
	
	return aux;
}

int
TABBCalendario::Altura()const 
{
	int hi=0;
	int hd=0;
	
	if (EsVacio())
	{
		return hi+hd;
	}
	else
	{
		hd+=1+raiz->de.Altura();
		hi+=1+raiz->iz.Altura();
	}
}

int 
TABBCalendario::Nodos() const
{
	int n=0;
	
	if (EsVacio())
	{
		return n;
	}
	
	if(!raiz->de.EsVacio())
	{
		n+=1+raiz->de.Nodos();
	}
	
	if (!raiz->iz.EsVacio())
	{
		n+=1+raiz->iz.Nodos();
	}
}

int
TABBCalendario::NodosHoja()const
{
	int hoja=0;
	
	if (EsVacio())
	{
		return hoja;
	}
	else if (raiz->de.EsVacio() && raiz->iz.EsVacio())
	{
		hoja++;
	}
	else 
	{
		raiz->de.NodosHoja()+raiz->iz.NodosHoja();
	}
	
}

TVectorCalendario 
TABBCalendario::Inorden()
{
	int pos=1;
	TVectorCalendario v(Nodos());
	InordenAux(v,pos);
}

void
TABBCalendario::InordenAux(TVectorCalendario& v, int& pos) const
{
	if(!EsVacio())
	{
		raiz->iz.InordenAux(v,pos);
		v[pos]=Raiz();
		pos++;
		raiz->de.InordenAux(v,pos);
	}
}

TVectorCalendario
TABBCalendario::Preorden()
{
	int pos=1;
	TVectorCalendario v(Nodos());
	PreordenAux(v,pos);
}

void
TABBCalendario::PreordenAux(TVectorCalendario& v, int& pos)const 
{
	if(!EsVacio())
	{
		v[pos]=Raiz();
		pos++;
		raiz->iz.PreordenAux(v,pos);
		raiz->de.PreordenAux(v,pos);
	}
}

TVectorCalendario
TABBCalendario::Postorden()
{
	int pos=1;
	TVectorCalendario v(Nodos());
	PostordenAux(v,pos);
}

void
TABBCalendario::PostordenAux(TVectorCalendario& v, int& pos) const
{
	if(!EsVacio())
	{
		raiz->iz.PostordenAux(v,pos);
		raiz->de.PostordenAux(v,pos);
		v[pos]=Raiz();
		pos++;
	}
}
