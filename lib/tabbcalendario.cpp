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
	this->~TABBCalendario();
	if(this!=&acopiar)
	{
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
	bool borrado = false;

	TNodoABB *padre = NULL; /* Para controlar si estamos en la raiz, y si no es asi saber el nodo anterior */
	TNodoABB *actual; /* Nodo que estamos analizando en el momento */
	TNodoABB *nodoAux; /* Nodo auxiliar que nos servirá para el intercambio de nodos */
	TCalendario aux; /* TPoro auxiliar que nos servirá para el intercambio de nodos */

	actual = raiz;
	while(actual != NULL && !borrado) /* Búsqueda si el arbol está vacio no esta el item */
	{
		if(obj == actual -> item) /* Si hemos encontrado el item */
		{
			if(actual -> iz.EsVacio() && actual -> de.EsVacio()) /* Si es una hoja */
			{
				/* Si 'Padre' es NULL, el nodo raíz es el único del árbol,
				por lo tanto el puntero al árbol debe ser NULL */
				if(padre != NULL)
				{
					/* Si la rama de es la no vacia es la que debemos borrar */
					if(padre -> de.raiz == actual) padre -> de.raiz = NULL;
					/* Si la rama iz es la no vacia es la que debemos borrar */
					else if(padre -> iz.raiz == actual) padre -> iz.raiz = NULL;
				}
				if(padre == NULL) /* Si es la raiz */
				{
					delete raiz;
					raiz = NULL;
					borrado = true;
					actual = raiz;
				}
				if(actual != NULL) delete actual; // Borrar el nodo
					
				actual = NULL;
				borrado = true;
			}
			else /* El nodo no es un nodo hoja */
			{
				/* Buscar nodo */
				/* Buscamos el 'nodo' más a la izquierda del árbol derecho de raíz o el más a */
				/* la derecha del árbol izquierdo. Hay que tener en cuenta que puede que sólo */
				/* exista uno de esos árboles. Al mismo tiempo, actualizamos 'Padre' para que */
				/* apunte al padre de 'nodo'. */
				padre = actual;
				/* Si el hijoDe no esta vacio y el hijoIZ si, sustituir por el hijoDE */
				if(!actual -> de.EsVacio() && actual -> iz.EsVacio())
				{
					nodoAux = actual -> de.raiz;
				}
				/* Si el hijoIZ no esta vacio y el hijoDE si, sustituir por el hijoIZ */
				else if(actual -> de.EsVacio() && !actual -> iz.EsVacio())
				{
					nodoAux = actual -> iz.raiz;
				}
				else if(!actual -> iz.EsVacio())
				{
					nodoAux = actual -> iz.raiz;
					while(!nodoAux -> de.EsVacio())
					{
						padre = nodoAux;
						nodoAux = nodoAux -> de.raiz;
					}
				}
				/* Intercambio */
				aux = actual -> item; /* Intercambiamos los elementos de los nodos raíz y 'nodo' */
				actual -> item = nodoAux -> item;
				nodoAux -> item = aux;
				actual = nodoAux;
			}
		}
		else /* Si no hemos encontrado el item */
		{
			padre = actual;
			 /* Si el elemento es mayor que el actual continuaremos buscando por el lado de */
			if(obj > actual -> item) actual = actual -> de.raiz;
			/* Si el elemento es menor que el actual continuaremos buscando por el lado iz */
			else if(obj< actual -> item) actual = actual -> iz.raiz;
		}
	}

	return borrado;
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
TABBCalendario::Buscar(const TCalendario &obj)const
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
	int a1=0,a2=0;
	if(raiz!= NULL)
	{
		a1=(raiz->iz).Altura();
		a2=(raiz->de).Altura();
		return (1 + (a1 < a2 ? a2 : a1));
	}
	else return 0;
}

int 
TABBCalendario::Nodos() const
{
	   
	int n = 0;
	if (raiz != NULL)
	{
			n = 1 + raiz->iz.Nodos() + raiz->de.Nodos();
	}
	return n;
}

int
TABBCalendario::NodosHoja()const
{
	int n = 0;
	if (raiz != NULL)
	{
		if (raiz->iz.raiz == NULL && raiz->de.raiz == NULL)
		{
				n = 1;
		}
		else
		{
				n = raiz->iz.NodosHoja() + raiz->de.NodosHoja();
		}
	}
	return n;
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
	int* tmp=NULL;
	
	if(!lista.EsVacia())
	{
	tmp=new int[lista.Longitud()];
	int i=0;
	TVectorCalendario v=Inorden();
	bool salir=false;
	while(!actual.EsVacia())
	{
		
			for (int j = 1; j <= v.Tamano() && !salir; j++)
			{
				if(v[j].Anyo()==lista.Obtener(actual).Anyo())
				{
					if (v[j-1].Anyo() == 1900)//caso particular de un tad ??
					{
						tmp[i]=0;
					}
					else{
					tmp[i]=v[j-1].Anyo();
					salir=true;
				}
				}
				else
				{
					tmp[i]=0;
				}
				
			}
			
		anterior=actual;
		actual=actual.Siguiente();
		i++;
		salir=false;
	}
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
