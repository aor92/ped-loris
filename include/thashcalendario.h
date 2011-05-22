#ifndef __THASHCALENDARIO_H
#define __THASHCALENDARIO_H

#include <iostream>
#include "tcalendario.h"
#include "tlistacalendario.h"

class THASHCalendario
{
	private:
		
		int tamanyo;
		TListaCalendario *tabla;
		
		int H(const TCalendario) const;
	
	public:
	
		THASHCalendario();
		THASHCalendario(int);
		THASHCalendario(const THASHCalendario&);
		~THASHCalendario();
		THASHCalendario & operator=( const THASHCalendario &);
		bool operator==(const THASHCalendario&);
		// Devuelve true si la tabla está vacía, false en caso contrario
		bool EsVacia();
		// Inserta el elemento en la tabla
		bool Insertar( const TCalendario &);
		// Busca y borra el elemento de la tabla
		bool Borrar( const TCalendario &);
		// Devuelve TRUE si el elemento está en la tabla, FALSE en caso contrario
		bool Buscar( const TCalendario &);
		// Devuelve el tamaño de la tabla
		int Tamanyo() const;
		// Devuelve el número de elementos en la tabla
		int NElementos() const;
		// Devuelve todos los elementos de la tabla en una lista ordenada
		TListaCalendario Lista() const;
		// Búsqueda en un HASH a través de una lista auxiliar
		int* BuscarLista( const TListaCalendario &) const;

};


#endif
