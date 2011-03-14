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
TABBCalendario::operator=(const TABBCalendario &acopiar)
{
	if(this!=&acopiar)
	{
		this->~TABBCalendario();
		Copiar(acopiar);
	}
	
	return (*this);
}

void 
TABBCalendario::Copiar(const TABBCalendario &acopiar)
{
	if (acopiar.raiz!=NULL)
	{
		TNodoABB *aux=new TNodoABB();
		aux->item=acopiar.raiz->item;
		raiz=aux;
		(raiz->iz).Copiar(acopiar.raiz->iz);
		(raiz->de).Copiar(acopiar.raiz->de);
	}
	else raiz=NULL;
}

bool 
TABBCalendario::operator==(const TABBCalendario& der)const
{
	if((raiz!=NULL && der.raiz==NULL) || (raiz==NULL && der.raiz!=NULL))
	{
		return false;
	}
	else if(raiz==NULL && der.raiz==NULL) return true;
	else if(raiz->item!=der.raiz->item) return false;
	else return(raiz->de==der.raiz->de && raiz->iz==der.raiz->iz);
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
	if (raiz==NULL)
	{
		TNodoABB* aux=new TNodoABB();
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
TABBCalendario::Borrar(const TCalendario &obj )
{
	if(raiz!=NULL)
	{  
		if (raiz->item<obj) return(raiz->de).Borrar(obj);
		else if (raiz->item>obj) return(raiz->iz).Borrar(obj);
		else if (raiz->item==obj) 
		{
			TABBCalendario aux(*this);
			if (raiz->iz.raiz==NULL) raiz=raiz->de.raiz;
			else if (raiz->de.raiz==NULL) raiz=raiz->iz.raiz;
			else
			{
				raiz->item=mayor();
				raiz->de.Borrar(raiz->item);
			}
			return true;
		}
		else return false;
	}
	else return false;
}

TCalendario 
TABBCalendario::mayor()const
{
	if(raiz->de.raiz!=NULL) return raiz->de.mayor();
	else return raiz->item;
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
TABBCalendario::Buscar(const TCalendario& obj)const
{
	if (raiz==NULL) return false;
	else if (obj>raiz->item) return (raiz->de).Buscar(obj);
	else if (obj<raiz->item) return (raiz->iz).Buscar(obj);
	else return true;
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
	int num=0;
	if(raiz!=NULL)
	{
		num=1;
		if(!(raiz->iz).EsVacio()) num=num+raiz->iz.Nodos();
		if(!(raiz->de).EsVacio()) num=num+raiz->de.Nodos();
	}
	return num;
}

int
TABBCalendario::NodosHoja()const
{
	if (!EsVacio() && raiz->iz.EsVacio() && raiz->de.EsVacio())
		return 1;
	else
		return raiz->iz.NodosHoja() + raiz->de.NodosHoja();
}

TVectorCalendario 
TABBCalendario::Inorden() const
{
	int pos=1;
	TVectorCalendario v(Nodos());
	InordenAux(v,pos);
	return v;
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
	return v;
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
	return v;
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
TABBCalendario::operator+( const TABBCalendario & ar) const
{
	TABBCalendario tmp(*this);
	TVectorCalendario  vec(ar.Inorden());
	for(int i=1;i<=vec.Ocupadas();i++)
	{
		tmp.Insertar(vec[i]);
	}
	
	return tmp;
}

TABBCalendario
TABBCalendario::operator-( const TABBCalendario & ar ) const
{
	TABBCalendario devo;
	TVectorCalendario tmp(this->Inorden());
	for(int i=1;i<=tmp.Tamano();i++)
	{
		if(!ar.Buscar(tmp[i])) 
		{
			devo.Insertar(tmp[i]);
		}
	}
	return devo;
}

int *
TABBCalendario::BuscarLista( const TListaCalendario& lista ) const
{
	TListaPos actual=lista.Primera(),anterior;
	int* tmp=new int[lista.Longitud()];
	int i=0;
	
	while(!actual.EsVacia())
	{
		if(Buscar(lista.Obtener(actual)) && !anterior.EsVacia())
		{
			tmp[i]=(lista.Obtener(actual)).Anyo();
		}
		else
		{
			tmp[i]=0;
		}
		anterior=actual;
		actual=actual.Siguiente();
		i++;
	}
	return tmp;
}

ostream &
operator <<( ostream& os, const TABBCalendario& abb )
{
	TVectorCalendario v = abb.Inorden();
	os << v;
	
	return os;
}
