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
TABBCalendario::Borrar(const TCalendario &c )
{
	bool borrado = false;
	
	if( raiz = NULL )
	{
		borrado = false;
	}
	else if ( raiz->item < c )
	{
		if( raiz->de.Borrar(c) )
			borrado = true;
	}
	else if ( raiz->item > c )
	{
		if( raiz->iz.Borrar(c) )
			borrado = true;
	}
	else
	{
		TNodoABB *aux;
		
		if( raiz->iz.raiz ==NULL )
		{
			aux = raiz;
			raiz = raiz->de.raiz;
			aux->de.raiz = NULL;
			delete aux;
			aux = NULL;
			borrado = true;
		}
		else if( raiz->de.raiz == NULL)
		{
			aux = raiz;
			raiz = raiz->iz.raiz;
			aux->iz.raiz = NULL;
			delete aux;
			aux = NULL;
			borrado = true;
		}
		else
		{
			this->IntercambiarBorrar();
			borrado = true;
		}
	}
	return borrado;
}

void
TABBCalendario::IntercambiarBorrar()
{
	TNodoABB *ant, *post, *nodoactual;
	
	nodoactual = raiz;
	ant = raiz;
	post = raiz->iz.raiz;
	
	if(post->de.raiz == NULL)
	{
			nodoactual->item = post->item;
			nodoactual->iz.raiz = post->iz.raiz;
	}
	else
	{
		while( post->de.raiz != NULL )
		{
			ant = post;
			post = post->de.raiz;
		}
		ant->de.raiz = post->iz.raiz;
		nodoactual->item = post->item;
	}
	
	delete post;
	ant = NULL;
	post = NULL;
	nodoactual = NULL;
	
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
TABBCalendario::Inorden() const
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
TABBCalendario::Preorden() const
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
TABBCalendario::Postorden() const
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

TABBCalendario
TABBCalendario::operator+( const TABBCalendario & ar)
{
	TABBCalendario aux(*this);
	TVectorCalendario v = Inorden();
	
	for( int i=1; i < v.Tamano(); i++ )	
	{
		Insertar(v[i]);
	}
	
	return aux;
}

TABBCalendario
TABBCalendario::operator-( const TABBCalendario & ar )
{
	TABBCalendario aux(*this);
	TVectorCalendario v = Inorden();
	
	for( int i = 1; i < v.Tamano(); i++ )
	{
		if( ar.Buscar( v[i]) )
		{
			aux.Insertar(v[i]);
		}
	}
	
	return aux;
}

int *
TABBCalendario::BuscarLista( const TListaCalendario& lc ) const
{
	int* resultado = new int[lc.Longitud()];
	
	TVectorCalendario ino = Inorden();
	
	int i = 1;
	TListaPos p;
	p = lc.Primera();
	
	for( ; p != lc.Ultima() ; p = p.Siguiente() )
	{
		if( Buscar( lc.Obtener(p) ) )
		{
			int j = 0;
			for( int k = 1; k < ino.Tamano(); k++)
			{
				if(ino[i] == lc.Obtener(p) )
				{
					if(  i-1 > 0 )
					{
						resultado[j] = ino[i-1].Anyo();//Meter el año no el calendario
						j++;
					}
				}
			}
		}
		else
		{
			resultado[i] = 0;
		}
		
		i++;
	}
	
	return resultado;
}
