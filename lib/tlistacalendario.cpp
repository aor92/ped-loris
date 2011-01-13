#include "tlistacalendario.h"

/**********Inicio TNodoCalendario**********************/
TNodoCalendario::TNodoCalendario()
{
	siguiente=NULL;
}
	
TNodoCalendario::TNodoCalendario(const TNodoCalendario& nodo)
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
TNodoCalendario::operator=(const TNodoCalendario& nodo)
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

TListaPos::TListaPos(const TListaPos& iter)
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
TListaPos::operator=(const TListaPos& iter)
{
		//~ if (pos!=NULL)
		//~ {
			//~ delete pos;
		//~ }
		
		if (this!=NULL)
		{
			pos=iter.pos;
		}
		
		return *this;
}
	
bool
TListaPos::operator==(const TListaPos& iter) const
{
		return pos==iter.pos;
}
			
bool
TListaPos::operator!=(TListaPos& iter) const
{
		return !(pos==iter.pos);
}
			
TListaPos
TListaPos::Siguiente() const 
{
	TListaPos aux;
	
	aux.pos= pos->siguiente;

	return aux;
}

bool
TListaPos::EsVacia() const
{
	return pos==NULL;
}

/**********Fin TListaPos***************************/
/**********Inicio TListaCalendario**********************/

TListaCalendario::TListaCalendario()
{
	primero = NULL;
}

TListaCalendario::TListaCalendario(const TListaCalendario& lista)
{
	TListaPos sig;
	TListaPos ant;
	
	if( this != &lista)
	{

		primero = new TNodoCalendario(*lista.primero);
		ant = lista.Primera();
		sig = lista.Primera();
		sig = sig.Siguiente();

		//if( p.primero->siguiente != NULL )
		if( sig.pos != NULL )
		{
			//TListaNodo *ant = p.primero;
			//TListaNodo *sig = p.primero->siguiente;
			while( sig.pos != NULL )
			{
				ant.Siguiente(); 
				ant.pos= new TNodoCalendario(*sig.pos);
				ant = sig;
				sig = sig.Siguiente();
			}
		}
	}
}

TListaCalendario::~TListaCalendario()
{
	TNodoCalendario *c=NULL;
	
	while(!EsVacia())
	{
		c=primero;
		primero=primero->siguiente;
		delete c;
	}
}

TListaCalendario& 
TListaCalendario::operator=(const TListaCalendario &lista)
{
	TListaPos ant;
	//borrar parte izquierda, antes de hacer nada
	if( this != &lista)
	{
		ant= lista.Primera();

		while( !ant.EsVacia())
		{
				this->Insertar(Obtener(ant));
				ant= ant.Siguiente();
		}
	}
}
	
bool
TListaCalendario::operator==(const TListaCalendario &lista) const
{
	TListaPos aux1 = Primera();
	TListaPos aux2 = lista.Primera();
	int longitud = 0;
	int longitudaux = 0;
	bool igual = true;
	
	longitud = Longitud();
	longitudaux = lista.Longitud();

	if( longitud != longitudaux )
	{
		igual = false;
	}
	else
	{
		while( !aux1.EsVacia() && !aux2.EsVacia() && igual )
		{
			if( Obtener(aux1) != Obtener(aux2))
			{
				igual = false;
			}
			else
			{
				aux1 = aux1.Siguiente();
				aux2 = aux2.Siguiente();
				
			}
		}
	}


	return igual;
}

TListaCalendario
TListaCalendario::operator+ (const TListaCalendario &lista)
{
	TListaPos aux;
	aux= lista.Primera();
	TListaCalendario listaAux(*this);
	
	
	while(!aux.EsVacia())
	{
		listaAux.Insertar(Obtener(aux));
		
		aux= aux.Siguiente();
	}
	
	return listaAux;
}
		
TListaCalendario
TListaCalendario::operator- (const TListaCalendario &)
{
	TListaCalendario listaAux(*this);
	TListaPos aux;

	while(!aux.EsVacia())
	{
		listaAux.Borrar(Obtener(aux));
		
		aux = aux.Siguiente();
	}
	
	return listaAux;
}
		
bool
TListaCalendario::Insertar(const TCalendario &c)
{
	bool insertado = false;
	TListaPos post;
	TListaPos ant;
	
	if(EsVacia())
	{
		TNodoCalendario *nodoaux = new TNodoCalendario();
		nodoaux->c = c;
		primero = nodoaux;
		insertado = true;
	}
	else if(!Buscar(c))
	{
		post=Primera();
		
		while( !insertado && !post.EsVacia())
		{
			if( c < Obtener(post))
			{
				insertado = true;
			}
			else
			{
				ant = post;
				post= post.Siguiente();
			}
			
		}
		
		if( insertado || ant == Ultima() )// && ant == ultima() quitado
		{
			if( ant.EsVacia()) //Insertamos primero
			{
				TNodoCalendario *nodoaux = new TNodoCalendario();
				nodoaux->c = c;
				//~ primero->siguiente = nodoaux;
				nodoaux->siguiente = post.pos;
				primero = nodoaux;
				
			}
			else if( ant == Ultima()) // Por enmedio final, felicidad
			{
				TNodoCalendario *nodoaux = new TNodoCalendario();
				nodoaux->c = c;
				nodoaux->siguiente = NULL;
				//~ ant.pos=nodoaux;
				ant.pos->siguiente = nodoaux;
				insertado = true;
			}
			else
			{
				TNodoCalendario *nodoaux = new TNodoCalendario;
				nodoaux->c = c;
				nodoaux->siguiente = post.pos;
				//~ ant.pos= nodoaux;
				ant.pos->siguiente = nodoaux;
				
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
	post = Primera();
	
	if( !EsVacia() )
	{
		if( Buscar(c) )
		{
			
			//~ cout << "Entra en borrar" << endl;
			if( c == Obtener(Primera())) // Primera posicion
			{
				//~ cout << "Entra en borrar primera posicion" << endl;
				primero = primero->siguiente;
				delete post.pos;
				borrado = true;
			}
			else
			{
				//~ cout << "Entra en borrado por enmedio" << endl;
				ant = post;
				post = post.Siguiente();
				
				while( !borrado && !post.EsVacia() ) // Enmedio
				{
					//~ cout << "Se mete en bucle while" << endl;
					if( c == Obtener(post))
					{
						ant.pos->siguiente = post.pos->siguiente;
						delete post.pos;
						borrado = true;
					}
					else
					{
						ant = post;
						post= post.Siguiente();
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
	post= Primera();
	
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
				post = post.Siguiente();
				
				while( !borrado && !post.EsVacia()) // Enmedio
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
				post = post.Siguiente();
				
				while( post.pos != NULL ) // Recorremos toda la lista
				{
					if( !noBorra && c > post.pos->c )
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
TListaCalendario::EsVacia() const
{
	return primero == NULL;
}

TCalendario
TListaCalendario::Obtener(const TListaPos &p) const
{
	if(!p.EsVacia()) return p.pos->c;
}
		
bool 
TListaCalendario::Buscar( const TCalendario &c) const
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
		
int
TListaCalendario::Longitud() const
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
TListaCalendario::Primera() const
{
	TListaPos aux;
	
	if( !this->EsVacia() )
	{
		aux.pos = primero;
	}

	return aux;
}

TListaPos
TListaCalendario::Ultima() const
{
	TListaPos aux, ant;
	aux.pos = primero;
	
	if( !this->EsVacia() )
	{
		
		while( aux.pos != NULL )
		{
			ant = aux;
			aux.pos = aux.pos->siguiente;
		}
	}

	return ant;
}
	
TListaCalendario
TListaCalendario::SumarSubl (const int ini1,const  int fi1,const  TListaCalendario& lo, const int ini2, const int fi2)
{
	TListaCalendario aux1;
	TListaCalendario aux2;
	TListaPos p1;
		p1.pos=primero;
	TListaPos p2;
		p2.pos=lo.primero;
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
	TListaPos p1;
	int iter=0;
	p1.pos=primero;
	bool salir=false;
	TListaCalendario aux1;
	
	if (ini1>fi1)
	{
		if (ini1<=0)
		{
			while (!EsVacia() && iter<=fi1)
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

ostream & operator<<( ostream &os, const TListaCalendario &lista )
{
		TListaPos aux;
		aux = lista.Primera();
		
		os << "<";
		while( !aux.EsVacia() )
		{
			os << lista.Obtener(aux);
			aux = aux.Siguiente();
			if( !aux.EsVacia() ) os << " ";
		}
		os << ">";
	
	
	return os;
}
