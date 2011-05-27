#ifndef __TAVLCALENDARIO_H
#define __TAVLCALENDARIO_H

/** \file tavlcalendario.h
* 	\brief Este fichero contiene la clase tavlcalendario
*
* 	En el fichero se incluyen los encabezados de las funciones de la clase tcalendario asi como miembros y 
* 	declaraciones
*/

#include <iostream>
#include "tcalendario.h"
#include "tvectorcalendario.h"
#include "tpilacalendario.h"
#include "tlistacalendario.h"

using namespace std;

class TNodoAVL;

/** \brief Clase tavlcalendario
*
* 	La clase tavlcalendario es un clase que contiene un arbol balanceado de tcalendarios
*/
class TAVLCalendario
{
	friend class TNodoAVL;
	friend ostream& operator<<(ostream&,const TAVLCalendario&);
	
	private:
		
		/** \brief raiz
		* Raiz del arbol AVL*/
		TNodoAVL *raiz;
		
		/** \brief Auxiliar de Inorden
		*  Asigna las posiciones al vector siguiendo el algoritmo inorden
		*  \param v Vector donde almacenamos el nuevo orden
		* 	\param pos entero que marca la posicion en el vector
		*/
		void InordenAux(TVectorCalendario &, int&) const;
		
		/** \brief Auxiliar de Preorden
		*  Asigna las posiciones al vector siguiendo el algoritmo preorden
		*  \param v Vector donde almacenamos el nuevo orden
		* 	\param pos entero que marca la posicion en el vector
		*/
		void PreordenAux(TVectorCalendario &, int&) const;
		
		/** \brief Auxiliar de Preorden
		*  Asigna las posiciones al vector siguiendo el algoritmo postorden
		*  \param v Vector donde almacenamos el nuevo orden
		* 	\param pos entero que marca la posicion en el vector
		*/
		void PostordenAux(TVectorCalendario &, int&) const;
		
		/** \brief Funcion auxiliar para el borrado Eliminar
		*  Borra el contenido del arbol de forma recursiva
		*  \param n Nodo con el que recorremos el arbol a borrar
		*/
		void Eliminar( TNodoAVL &);
		
		/** \brief Funcion auxiliar para la copia Copiar
		*  Copia el contenido del arbol de forma recursiva
		*  \param acopiar Arbol que queremos copiar
		*/
		void Copiar(const TAVLCalendario & );
		
		/** \brief Metodo para equilibrar el arbol siguiendo el comportamiento AVL
		*  Equilibra el arbol
		*/
		void Equilibrar();
		
	
	public:
	
		/** \brief Constructor por defecto.
		 *
		 * Constructor por defecto que inicializa según el formato especificado los componentes del TavlCalendario.
		 */
		TAVLCalendario();
		
		/** \brief Constructor de copia.
		 *
		 * Constructor de copia de TAVLCalendario.
		 * \param avl TAVLCalendario desde el que copiamos al nuevo TAVLCalendario.
		 */
		TAVLCalendario(const TAVLCalendario &);
		
		/** \brief Destructor de TAVLCalendario
		*   Destruye el arbol
		*/
		~ TAVLCalendario ();
		
		/** \brief Operador de asignacion de la clase AVLCalendario
		*  Asigna los valores de un AVLcalendario a otro
		*  \param avl AVL desde el que se asigna
		*/
		TAVLCalendario& operator=(const TAVLCalendario &);
		
		/** \brief Operador comparacion(igualdad) de AVL's
		*  Devuelve true si el contenido de los dos arboles es el mismo
		*  \param de AVLcalendario de la derecha de la comparación
		*/
		bool operator==( const TAVLCalendario &) const;
		
		/** \brief Operador comparacion(distinto) de AVL's
		*  Devuelve true si el contenido de los arboles no es el mismo
		*  \param a calendario de la derecha de la comparación
		*/
		bool operator!=( const TAVLCalendario &) const;
		
		/** \brief Metodo EsVacio()
		*  Devuelve true si el arbol no contiene ningun elemento
		*/
		bool EsVacio() const;
		
		/** \brief Metodo Insertar de AVL
		*  Introduce el elemento pasado al metodo en el arboll de forma ordenada. Nos devuelve un bool
		*  \param c Calendario a insertar en el arbol
		*/
		bool Insertar(const TCalendario &);
		
		/** \brief Metodo Buscar de AVL
		* 	Busca un Calendario en el AVL que llama al metodo. Devuelve un bool
		*  \param obj Calendario que queremos buscar en el AVL
		*/
		bool Buscar( const TCalendario&);
		
		/** \brief Metodo Altura de AVL
		*  Devuelve un entero indicando la altura que tiene el AVL en ese momento.
		*/
		int Altura() const ;
		
		/** \brief Metodo Nodos de AVL
		*  Devuelve un entero con el numero de Nodos del arbol.
		*/
		int Nodos() const;
		
		/** \brief Metodo Nodos de AVL
		*  Devuelve un entero con el numero de Nodos hoja del arbol.
		*/
		int NodosHoja() const;
		
		/** \brief Metodo Inorden de AVL
		*  Devuelve un vector con el contenido del arbol siguiendo el esquema inorden
		*/
		TVectorCalendario Inorden() const;
		
		/** \brief Metodo Preorden de AVL
		*  Devuelve un vector con el contenido del arbol siguiendo el esquema Preorden
		*/
		TVectorCalendario Preorden() const;
		
		/** \brief Metodo Postorden de AVL
		*  Devuelve un vector con el contenido del arbol siguiendo el esquema Postorden
		*/
		TVectorCalendario Postorden() const;
		
		/** \brief Metodo Borrar de AVL
		*  Devuelve bool, borra el calendario que le pasamos por argumento si este existe en el AVL
		*  \param obj Calendario que queremos borrar en el AVL
		*/
		bool Borrar( const TCalendario &);
		
		/** \brief Metodo Borrar de AVL
		*  Devuelve la raiz del arbol AVL
		*/
		TCalendario Raiz() const;
	
		

};

/** \brief Clase tnodoavl
*
* 	La clase tnodoavl conforma los nodos del avlcalendario
*/
class TNodoAVL
{
	friend class TAVLCalendario;
	
	
	
	private:
		
		/** \brief item
		* item que contiene el nodo, en este caso un tcalendario*/
		TCalendario item;
		
		/** \brief iz
		* rama izquierda del nodo*/
		TAVLCalendario iz;
		
		/** \brief de
		* rama derecha del nodo*/
		TAVLCalendario de;
		
		/** \brief fe
		* factor de equilibrio*/
		int fe;
		
		
		/** \brief Funcion auxiliar para eliminar
		*  Elimina el contenido del nodo de forma recursiva
		*  \param n nodo que toca borrar y a partir del que recorremos de forma recursiva
		*/
		void Eliminar(TNodoAVL &);
		
	public:
	
		/** \brief Constructor por defecto del tnodoAVL
		*  Crea un nodo vacio
		*/
		TNodoAVL ();
		
		/** \brief Constructor de copia de nodoAVL
		*  Creamos un nuevo nodo a partir de otro.
		*  \param n nodo desde el que creamos a su imagen
		*/
		TNodoAVL (const TNodoAVL &);
		
		
		/** \brief Destructor de tnodoavl
		*  Elimina el contenido del nodo
		*/
		~TNodoAVL ();
		
		/** \brief Funcion de asignacion
		*  Copia el contenido del nodo pasado por parametro al que llama el operador
		*  \param n nodo desde el que asignamos
		*/
		TNodoAVL & operator=( const TNodoAVL &);

};
#endif
