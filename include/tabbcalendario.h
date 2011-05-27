#ifndef __TABBCALENDARIO_H
#define __TABBCALENDARIO_H


/** \file tabbcalendario.h
* 	\brief Este fichero contiene la clase tabbcalendario
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

class TNodoABB;

/** \brief Clase tabbcalendario
*
* 	La clase tabbcalendario es un clase que contiene un arbol binario
*/
class TABBCalendario
{
	friend class TNodoABB;
	
	
	friend ostream& operator<<(ostream&,const TABBCalendario&);
	
	private:
	
		/** \brief raiz
		* Raiz del arbol*/
		TNodoABB* raiz;
		
		/** \brief Auxiliar de Inorden
		*  Asigna las posiciones al vector siguiendo el algoritmo inorden
		*  \param v Vector donde almacenamos el nuevo orden
		* 	\param pos entero que marca la posicion en el vector
		*/
		void InordenAux(TVectorCalendario&, int&) const;
		
		/** \brief Auxiliar de Preorden
		*  Asigna las posiciones al vector siguiendo el algoritmo preorden
		*  \param v Vector donde almacenamos el nuevo orden
		* 	\param pos entero que marca la posicion en el vector
		*/
		void PreordenAux(TVectorCalendario&, int&) const;
		
		/** \brief Auxiliar de Preorden
		*  Asigna las posiciones al vector siguiendo el algoritmo postorden
		*  \param v Vector donde almacenamos el nuevo orden
		* 	\param pos entero que marca la posicion en el vector
		*/
		void PostordenAux(TVectorCalendario&, int&) const;
		
		/** \brief Funcion auxiliar para el borrado
		*  Borra el contenido del nodo que debemos intercambiar con otro, siguiendo el modelo abb
		*/
		void IntercambiarBorrar();
		
		/** \brief Funcion auxiliar para la copia Copiar
		*  Copia el contenido del arbol de forma recursiva
		*  \param acopiar Arbol que queremos copiar
		*/
		void Copiar(const TABBCalendario &acopiar);
		
		/** \brief Funcion auxiliar mayor
		*  Devuelve el hijo mayor de un arbol/subarbol o nodo.
		*/
		TCalendario mayor()const;
	
	public:
		
		/** \brief Constructor por defecto.
		 *
		 * Constructor por defecto que inicializa según el formato especificado los componentes del TabbCalendario.
		 */
		TABBCalendario();
		
		/** \brief Destructor de TABBCalendario
		*   Destruye el arbol
		*/
		~TABBCalendario();
		
		/** \brief Constructor de copia.
		 *
		 * Constructor de copia de TABBCalendario.
		 * \param avl TAVLCalendario desde el que copiamos al nuevo TABBCalendario.
		 */
		TABBCalendario(const TABBCalendario&);
		
		/** \brief Operador de asignacion de la clase
		*  Asigna los valores de un ABBcalendario a otro
		*  \param acopiar ABB desde el que se asigna
		*/
		TABBCalendario& operator=(const TABBCalendario&);
		
		/** \brief Operador comparacion(igualdad) de ABB's
		*  Devuelve true si el contenido de los dos arboles es el mismo
		*  \param der ABBcalendario de la derecha de la comparación
		*/
		bool operator==(const TABBCalendario&)const;
		
		/** \brief Metodo EsVacio()
		*  Devuelve true si el arbol no contiene ningun elemento
		*/
		bool EsVacio() const;
		
		/** \brief Metodo Insertar de ABB
		*  Introduce el elemento pasado al metodo en el arboll de forma ordenada. Nos devuelve un bool
		*  \param nuevo Calendario a insertar en el arbol
		*/
		bool Insertar(const TCalendario&);
		
		/** \brief Metodo Borrar
		*  Devuelve bool, borra el calendario que le pasamos por argumento si este existe en el ABB
		*  \param obj Calendario que queremos borrar en el ABB
		*/
		bool Borrar(const TCalendario&);
		
		/** \brief Metodo Buscar
		* 	Busca un Calendario en el ABB que llama al metodo. Devuelve un bool
		*  \param obj Calendario que queremos buscar
		*/
		bool Buscar(const TCalendario&)const;
		
		/** \brief Metodo Raiz
		*  Devuelve la raiz del arbol
		*/
		TCalendario Raiz() const;
		
		/** \brief Metodo Altura
		*  Devuelve un entero indicando la altura que tiene el arbol en ese momento.
		*/
		int Altura() const;
		
		/** \brief Metodo Nodos 
		*  Devuelve un entero con el numero de Nodos del arbol.
		*/
		int Nodos() const;
		
		/** \brief Metodo Nodos 
		*  Devuelve un entero con el numero de Nodos hoja del arbol.
		*/
		int NodosHoja() const;
		
		/** \brief Metodo Inorden 
		*  Devuelve un vector con el contenido del arbol siguiendo el esquema inorden
		*/
		TVectorCalendario Inorden() const;
		
		/** \brief Metodo Preorden 
		*  Devuelve un vector con el contenido del arbol siguiendo el esquema Preorden
		*/
		TVectorCalendario Preorden() const;
		
		/** \brief Metodo Postorden 
		*  Devuelve un vector con el contenido del arbol siguiendo el esquema Postorden
		*/
		TVectorCalendario Postorden() const;
		
		/** \brief Operador suma de ABB
		* 	Crea un nuevo ABB con los elementos de los dos arboles que intervienen en el operador
		*  \param ar Arbol que le pasamos
		*/
		TABBCalendario operator+(const TABBCalendario&)const;
		
		/** \brief Operador resta de ABB
		* 	Crea un nuevo ABB con los elementos del arbol de la izquierda menos los de la derecha
		*  \param ar Arbol que le pasamos
		*/
		TABBCalendario operator-(const TABBCalendario&)const;
		
		/** \brief Metodo buscarlista
		* 	Devuelve un int* de enteros segun si encuentra los calendarios en la lista que le pasamos por parametro.
		*  \param lista A partir de ella buscamos en el arbol
		*/
		int* BuscarLista(const TListaCalendario&) const;
};


/** \brief Clase tnodoabb
*
* 	La clase tnodoabb conforma los nodos del abbcalendario
*/
class TNodoABB
{
	friend class TABBCalendario;
	private:
		
		
		/** \brief item
		* item que contiene el nodo, en este caso un tcalendario*/
		TCalendario item;
		
		/** \brief iz
		* rama izquierda del nodo*/
		TABBCalendario iz;
		
		/** \brief de
		* rama derecha del nodo*/
		TABBCalendario de;
		//~ bool operator==(const TNodoABB&);
		
		/** \brief Funcion auxiliar para eliminar
		*  Elimina el contenido del nodo de forma recursiva
		*  \param n nodo que toca borrar y a partir del que recorremos de forma recursiva
		*/
		void Eliminar( TNodoABB &);
		
	
	public:
	
		/** \brief Constructor por defecto del tnodoABB
		*  Crea un nodo vacio
		*/
		TNodoABB();
		
		/** \brief Constructor de copia de nodoABB
		*  Creamos un nuevo nodo a partir de otro.
		*  \param nodo Nodo desde el que creamos a su imagen
		*/
		TNodoABB(const TNodoABB&);
		
		/** \brief Destructor de tnodoabb
		*  Elimina el contenido del nodo
		*/
		~TNodoABB();
		
		/** \brief Funcion de asignacion
		*  Copia el contenido del nodo pasado por parametro al que llama el operador
		*  \param n nodo desde el que asignamos
		*/
		TNodoABB& operator=(const TNodoABB&);
};



#endif
