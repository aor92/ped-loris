#include "tlistacalendario.h"

/**********Inicio TNodoCalendario**********************/
TNodoCalendario::TNodoCalendario()
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
		aux = pos.Siguiente();
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

TListaCalendario::TListaCalendario( const TListaCalendario& lista)
{
	
	if( this != &lista)
	{

		primero = new TNodoCalendario(*lista.primero);
		TListaPos ant;
		ant = lista.Primera();
		TListaPos sig;
		sig = lista.Primera();
		sig = sig.Siguiente();

		//if( p.primero->siguiente != NULL )
		if( sig.pos != NULL )
		{
			//TListaNodo *ant = p.primero;
			//TListaNodo *sig = p.primero->siguiente;
			while(  sig.pos != NULL )
			{
				ant.Siguiente(); = new TNodoCalendario(*sig.pos);
				ant = sig;
				sig = sig.Siguiente();
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
TListaCalendario::operator+ (TListaCalendario &lista)
{
	TListaPos aux;
	aux.pos = lista.primero;
	TListaCalendario listaAux(*this);
	
	
	while( aux.pos != NULL )
	{
		listaAux.Insertar( aux.pos->c );
		
		aux.pos = auxSiguiente();
	}
	
	return listaAux;
}
		
TListaCalendario
TListaCalendario::operator- (TListaCalendario &)
{
	TListaCalendario listaAux(*this);
	TListaPos aux;

	while( aux.pos != NULL )
	{
		listaAux.Borrar(aux.pos->c );
		
		aux.pos = aux.Siguiente();
	}
	
	return listaAux;
}
		
bool
TListaCalendario::Insertar( const TCalendario &c)
{
	bool insertado = false;
	TListaPos post, ant;
	
	if( EsVacia() )
	{
		TNodoCalendario *nodoaux = new TNodoCalendario;
		nodoaux->c = c;
		primero = nodoaux;
		insertado = true;
	}
	else( !Buscar(c) )
	{
		post.pos = primero;
		
		
		while( !insertado && post.pos != NULL )
		{
			if( c < post.pos->c )
			{
				insertado = true;
			}
			else
			{
				ant = post;
				post.pos = post.pos->siguiente;
			}
			
		}
		
		if( insertado && ant == Ultima() )
		{
			if( ant.pos == NULL ) //Insertamos primero
			{
				TNodoCalendario *nodoaux = new TNodoCalendario;
				nodoaux->c = c;
				nodoaux->siguiente = post.pos;
				primero = nodoaux;
			}
			else if( ant == Ultima()) // Por enmedio final, felicidad
			{
				TNodoCalendario *nodoaux = new TNodoCalendario;
				nodoaux->c = c;
				nodoaux->siguiente = NULL;
				ant.pos->siguiente = nodoaux;
				
				insertado = true;
			}
			else
			{
				TNodoCalendario *nodoaux = new TNodoCalendario;
				nodoaux->c = c;
				nodoaux->siguiente = post.pos;
				ant.pos = nodoaux;
			}
		}
		
	}
	
	return insertado;
}
		
bool
TListaCalendario::Borrar( const TCalendario &c)
{
	bool borrado = false;
	
	TListaPos post, ant;
	post.pos = primero;
	
	if( !EsVacia() )
	{
		if( Buscar(c) )
		{
			if( c == primero->c ) // Primera posicion
			{
				primero = primero->siguiente;
				delete post.pos;
			}
			else
			{
				ant = post;
				post = post->siguiente;
				
				while( !borrado && post.pos != NULL ) // Enmedio
				{
					if( c == post->c )
					{
						ant.pos->siguiente = post.pos->siguiente;
						delete post.pos;
						borrado = true;
					}
					else
					{
						ant = post;
						post.pos = post.pos->siguiente;
					}
				}
			}
		}
	}
	
	
	return borrado;
}
		
bool
TListaCalendario::Borrar ( const TListaPos &p)
{
	bool borrado = false;
	
	TListaPos post, ant;
	post.pos = primero;
	
	if( !EsVacia() )
	{
		
			if( p == post ) // Primera posicion
			{
				primero = primero->siguiente;
				delete post.pos;
			}
			else
			{
				ant = post;
				post = post->siguiente;
				
				while( !borrado && post.pos != NULL ) // Enmedio
				{
					if( p == post )
					{
						ant.pos->siguiente = post.pos->siguiente;
						delete post.pos;
						borrado = true;
					}
					else
					{
						ant = post;
						post.pos = post.pos->siguiente;
					}
				}
			}
	}
	
	return borrado;
}
	
bool 
TListaCalendario::Borrar(const int d, const int m , const int a)
{
	bool borrado = false;
	bool noBorra = false;
	
	TCalendario c(d,m,a,"");
	
	TListaPos post, ant;
	post.pos = primero;
	
	if( !EsVacia() )
	{
		
			if( c > primero->c ) // Primera posicion
			{
				primero = primero->siguiente;
				delete post.pos;
				borrado = true;
			}
			else
			{
				ant = post;
				post = post->siguiente;
				
				while( post.pos != NULL ) // Recorremos toda la lista
				{
					if( !noBorra && c > post->c )
					{
						ant.pos->siguiente = post.pos->siguiente;
						delete post.pos;
						borrado = true;
						ant = post;
						post.pos = post.pos->siguiente;
						borrado = true;
					}
					else
					{
						noBorra = true;
					}
				}
			}
	}
	
	return borrado;
}

bool
TListaCalendario::EsVacia()
{
	return primero == NULL;
}

TCalendario
TListaCalendario::Obtener(TListaPos &)
{}
		
bool 
TListaCalendario::Buscar( const TCalendario &c)
{
	bool encontrado = false;
	
	TListaPos aux;
	
	if( !EsVacia() )
	{
		aux.pos = primero;
		
		while( !encontrado && aux.pos != NULL )
		{
			if( aux.pos->c == c ) encontrado = true;
			else
			{
				aux.pos = aux.pos->siguiente;
			}
		}
		
	}

	return encontrado;
}
		
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
TListaCalendario::SumarSubl (const int ini1,const  int fi1,const  TListaCalendario& lo, const int ini2, const int fi2)
{
	TListaCalendario aux1;
	TListaPos p1.pos=primero;
	TListaPos p2.pos=lo.primero;
	int iter=1;
	int iter2=1;
	bool salir=false;
	bool salir2=false;
	
	while (!EsVacia() && !salir)
	{
		p1.pos=p1.pos->siguiente;
		iter++;
		if (iter==ini1)
		{
			salir=true;
		}
		
	}
	
	while (!EsVacia() && (iter<Longitud() && iter<=fi1))
	{
		aux1.Insertar(p1.pos->c);
		p1.pos=p1.pos->siguiente;
	}
	
	//segunda lista
	salir=false;
	while (!lo.EsVacia() && !salir)
	{
		p2.pos=p2.pos->siguiente;
		iter2++;
		if (iter2==ini2)
		{
			salir=true;
		}
		
	}
	
	while (!lo.EsVacia() && (iter2<lo.Longitud() && iter2<=fi2))
	{
		aux2.Insertar(p2.pos->c);
		p2.pos=p2.pos->siguiente;
	}
	
	
	return aux1+aux2;
}
		
TListaCalendario
TListaCalendario::ExtraerRango (const int ini1,const int fi1)
{
	TListaCalendario aux;
	TListaPos p1.pos=primero;
	
	if (n1>n2)
	{
		if (ini1<=0)
		{
			while (!EsVacia() && iter<=fi1))
			{
				iter++;
				aux1.Insertar(p1.pos->c);
				p1.pos=p1.pos->siguiente;
			}
			
		}
		
		while (!EsVacia() && !salir)
		{
			p1.pos=p1.pos->siguiente;
			iter++;
			if (iter==ini1)
			{
				salir=true;
			}
			
		}
		
		if (iter==ini1)
		{
			aux1.Insertar(p1.pos->c);
			Borrar(p1);
		}
		else while (!EsVacia() && (iter<Longitud() && iter<=fi1))
		{
			aux1.Insertar(p1.pos->c);
			p1.pos=p1.pos->siguiente;
		}
	}
		

	return aux;
}
