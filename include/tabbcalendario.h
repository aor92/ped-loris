#ifndef __TABBCALENDARIO_H
#define __TABBCALENDARIO_H

#include <iostream>
#include "tcalendario.h"
#include "tvectorcalendario.h"
#include "tpilacalendario.h"
#include "tlistacalendario.h"

using namespace std;

class TNodoABB;

class TABBCalendario
{
	friend class TNodoABB;
	
	friend ostream& operator<<(ostream&,const TABBCalendario&);
	
	private:
	
		TNodoABB* raiz;
		void InordenAux(TVectorCalendario&, int&) const;
		void PreordenAux(TVectorCalendario&, int&) const;
		void PostordenAux(TVectorCalendario&, int&) const;
		
		
	
	public:
	
		TABBCalendario();
		~TABBCalendario();
		TABBCalendario(const TABBCalendario&);
		TABBCalendario& operator=(const TABBCalendario&);
		bool operator==(const TABBCalendario&);
		bool EsVacio() const;
		bool Insertar(const TCalendario&);
		//bool Borrar(const TCalendario&);
		bool Buscar(const TCalendario&)const;
		TCalendario Raiz() const;
		int Altura() const;
		int Nodos() const;
		int NodosHoja() const;
		TVectorCalendario Inorden();
		TVectorCalendario Preorden();
		TVectorCalendario Postorden();
		/*TABBCalendario operator+(const TABBCalendario&);
		TABBCalendario operator-(const TABBCalendario&);
		int* BuscarLista(const TListaCandario&) const;*/
};

class TNodoABB
{
	friend class TABBCalendario;
	private:
		// Elemento (etiqueta) del nodo
		TCalendario item;
		// Subárbol izquierdo y derecho
		TABBCalendario iz;
		TABBCalendario de;
		//~ bool operator==(const TNodoABB&);
		
		void Eliminar( TNodoABB &);
	
	public:
		TNodoABB();
		TNodoABB(const TNodoABB&);
		~TNodoABB();
		TNodoABB& operator=(const TNodoABB&);
};



#endif
