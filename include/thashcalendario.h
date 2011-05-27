#ifndef __THASHCALENDARIO_H
#define __THASHCALENDARIO_H

/** \file thashcalendario.h
* 	\brief Este fichero contiene la clase thashcalendario
*
* 	En el fichero se incluyen los encabezados de las funciones de la clase tcalendario asi como miembros y 
* 	declaraciones
*/

#include <iostream>
#include "tcalendario.h"
#include "tlistacalendario.h"


/** \brief Clase thashcalendario
*
* 	La clase thashcalendario es un clase que contiene una tabla hash de listas
*/
class THASHCalendario
{
	private:
		
		/** \brief tamanyo
		* tamanyo de la tabla hash*/
		int tamanyo;
		
		
		/** \brief tabla
		* lista de listascalendario que conforma la estructura interna de la tabla hash*/
		TListaCalendario *tabla;
		
		/** \brief Auxiliar de insercion de la tabla hash H
		*  Calcula H
		*  \param c Calendario desde el que calcularemos H
		*/
		int H(const TCalendario) const;
	
	public:
	
		friend ostream& operator<<( ostream&, THASHCalendario &);
		
		/** \brief Constructor por defecto.
		 *
		 * Constructor por defecto que inicializa por defecto la tabla hash
		 */
		THASHCalendario();
		
		/** \brief Constructor sobrecargado.
		 *
		 * Constructor sobrecargado en tamaño
		 * \param t Entero que indica el tamanyo
		 */
		THASHCalendario(int);
		
		/** \brief Constructor de copia.
		 *
		 * Constructor de copia de THASHCalendario.
		 * \param cop Thash desde el que copiamos
		 */
		THASHCalendario(const THASHCalendario&);
		
		/** \brief Destructor
		*   Destruye la tabla hash
		*/
		~THASHCalendario();
		
		/** \brief Operador de asignacion 
		*  Asigna los valores de un hash a otro
		*  \param hash THASHC desde el que se asigna
		*/
		THASHCalendario & operator=( const THASHCalendario &);
		
		/** \brief Operador comparacion(igualdad)
		*  Devuelve true si el contenido es el mismo
		*  \param hahs HASH con la que comparamos
		*/
		bool operator==(const THASHCalendario&);
		
		
		/** \brief Metodo EsVacia()
		*  Devuelve true si la tabla esta vacia.
		*/
		bool EsVacia();
		
		
		/** \brief Metodo Insertar
		*  Introduce el elemento pasado al metodo en la tabla, devuelve un bool.
		*  \param cal Calendario a insertar en la tabla
		*/
		bool Insertar( const TCalendario &);
		
		
		/** \brief Metodo Borrar
		*  Devuelve bool, borra el calendario que le pasamos por argumento si este existe en la hash
		*  \param cal Calendario que queremos borrar
		*/
		bool Borrar( const TCalendario &);
		
		
		/** \brief Metodo Buscar
		* 	Busca un Calendario en la HASH que llama al metodo. Devuelve un bool
		*  \param cal Calendario que queremos buscar 
		*/
		bool Buscar( const TCalendario &);
		
		
		/** \brief Metodo Tamanyo
		*  Devuelve un entero indicando el tamaño de la tabla hashcalendario
		*/
		int Tamanyo() const;
		
		
		/** \brief Metodo NElementos
		*  Devuelve un entero indicando el numero de elementos de la hash.
		*/
		int NElementos() const;
		
		
		/** \brief Metodo Lista
		*  Devuelve una TListaCalendario con los elementos de la hash
		*/
		TListaCalendario Lista() const;
		
		
		/** \brief Metodo Buscar de AVL
		* 	Busca elemntos de la lista que le pasamos por parametro, devolviendo otra con el numero de orden de estos si se encuentran en el arbol.
		*  \param lista TListaCalendario que le pasamos para buscar
		*/
		int* BuscarLista( const TListaCalendario &) const;

};


#endif
