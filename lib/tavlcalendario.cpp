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
	fe=0;
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
TNodoAVL::operator=(const TNodoAVL & n )
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
	if(this!=&avl)
	{
		Copiar(avl);
	}
	
	return (*this);
}

void 
TAVLCalendario::Copiar(const TAVLCalendario &acopiar)
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

bool 
TAVLCalendario::operator==( TAVLCalendario & de)const 
{
	if((raiz!=NULL && de.raiz==NULL) || (raiz==NULL && de.raiz!=NULL))
	{
		return false;
	}
	else if(raiz==NULL && de.raiz==NULL) return true;
	else if(raiz->item!=de.raiz->item) return false;
	else return(raiz->de==de.raiz->de && raiz->iz==de.raiz->iz);	
}

bool 
TAVLCalendario::operator!=( TAVLCalendario &a)const 
{
	return !(operator==(a));
}

bool
TAVLCalendario::EsVacio() const
{
	return raiz==NULL;
}

int 
TAVLCalendario::Nodos() const
{
	int num=0;
		if (raiz!=NULL)
		{
			num=1;
			if(!(raiz->iz).EsVacio()) num=num+raiz->iz.Nodos();
			if(!(raiz->de).EsVacio()) num=num+raiz->de.Nodos();
		}
	return num;
}

int 
TAVLCalendario::NodosHoja()const
{
	if (EsVacio() && raiz->iz.EsVacio() && raiz->de.EsVacio() )
	{
		return 1;
	}
	else raiz->iz.NodosHoja() + raiz->de.NodosHoja();
}

int
TAVLCalendario::Altura() const
{
	int hd=0;
	int hi=0;
	
	if (EsVacio())
	{
		return hd+hi;
	}
	else
	{
		hd+=1+raiz->de.Altura();
		hi+=1+raiz->iz.Altura();
	}
	
}


TVectorCalendario 
TAVLCalendario::Inorden() const
{
	int pos=1;
	TVectorCalendario v(Nodos());
	InordenAux(v,pos);
	return v;
}

void
TAVLCalendario::InordenAux(TVectorCalendario& v, int& pos) const
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
TAVLCalendario::Preorden() const
{
	int pos=1;
	TVectorCalendario v(Nodos());
	PreordenAux(v,pos);
	return v;
}

void
TAVLCalendario::PreordenAux(TVectorCalendario& v, int& pos)const 
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
TAVLCalendario::Postorden() const
{
	int pos=1;
	TVectorCalendario v(Nodos());
	PostordenAux(v,pos);
	return v;
}

void
TAVLCalendario::PostordenAux(TVectorCalendario& v, int& pos) const
{
	if(!EsVacio())
	{
		raiz->iz.PostordenAux(v,pos);
		raiz->de.PostordenAux(v,pos);
		v[pos]=Raiz();
		pos++;
	}
}

bool 
TAVLCalendario::Buscar(TCalendario &obj)
{
		if (!EsVacio()) return false;
		else if (obj>raiz->item)
		{
			return raiz->de.Buscar(obj);
		}
		else if (obj<raiz->item)
		{
			return raiz->iz.Buscar(obj);
		}
		else if (obj==raiz->item) return true;
			
}

bool 
TAVLCalendario::Insertar(const TCalendario &c)
{
        bool ret = false;
        if (raiz != NULL)
        {
                if (raiz->item == c)
                {
                        ret = false;
                }
                else
                {
                        if (raiz->item > c)
                        {
                                ret = raiz->iz.Insertar(c);
                        }
                        else
                        {
                                ret = raiz->de.Insertar(c);
                        }
                }
        }
        else
        {       
                ret = true;
                raiz = new TNodoAVL();
                raiz->item = c;
        }
        Equilibrar();
        return ret;
}

void
TAVLCalendario::Equilibrar()
{
	TNodoAVL *aux;
        raiz->fe = raiz->de.Altura() - raiz->iz.Altura();       
        if (raiz->fe > 1)
        {
                if (raiz->de.raiz->fe >= 0)
                {
                        aux = raiz->de.raiz;
                        raiz->de.raiz = raiz->de.raiz->iz.raiz;
                        aux->iz.raiz = raiz;
                        raiz = aux;                     
                }
                else
                {
                        aux = raiz->de.raiz;
                        raiz->de.raiz = aux->iz.raiz->iz.raiz;
                        aux->iz.raiz->iz.raiz = raiz;
                        raiz = aux->iz.raiz;
                        aux->iz.raiz = raiz->de.raiz;
                        raiz->de.raiz = aux;
                }
                raiz->fe = raiz->de.Altura() - raiz->iz.Altura();
                if (raiz->iz.raiz != NULL)
                {
                        raiz->iz.raiz->fe = raiz->iz.raiz->de.Altura() - raiz->iz.raiz->iz.Altura();                    
                }
                if (raiz->de.raiz != NULL)
                {
                        raiz->de.raiz->fe = raiz->de.raiz->de.Altura() - raiz->de.raiz->iz.Altura();
                }
                                
        }
        else if (raiz->fe < -1)
        {
                if (raiz->iz.raiz->fe <= 0)
                {
                        aux = raiz->iz.raiz;
                        raiz->iz.raiz = raiz->iz.raiz->de.raiz;
                        aux->de.raiz = raiz;
                        raiz = aux;
                }
                else
                { 
                        aux = raiz->iz.raiz;
                        raiz->iz.raiz = aux->de.raiz->de.raiz;
                        aux->de.raiz->de.raiz = raiz;
                        raiz = aux->de.raiz;
                        aux->de.raiz = raiz->iz.raiz;
                        raiz->iz.raiz = aux;                                                    
                }
                raiz->fe = raiz->de.Altura() - raiz->iz.Altura();
                raiz->iz.raiz->fe = raiz->iz.raiz->de.Altura() - raiz->iz.raiz->iz.Altura();
                raiz->de.raiz->fe = raiz->de.raiz->de.Altura() - raiz->de.raiz->iz.Altura();
        }
	
}

TCalendario 
TAVLCalendario::Raiz() const
{
		if (raiz!=NULL)
		{
			return raiz->item;
		}
}
