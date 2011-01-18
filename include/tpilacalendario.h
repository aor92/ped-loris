#ifndef TPILACALENDARIO_H_
#define TPILACALENDARIO_H_

#include "tvectorcalendario.h"
/** \file tpilacalendario.h
 *
 * \brief Estructura de la clase TPilaCalendario.
 *
 * Definiciones de métodos y atributos de clase TPilaCalendario.
 */

/** \brief Clase TPilaCalendario.
 *
 * Estructura de la clase TPilaCalendario.
 *
 */
class TPilaCalendario
{
	
	
	/** \brief Sobrecarga del operador "<<", función amiga.
	 *
	 * Función amiga que se encarga de mostrar por pantalla, en un formato determinado un TPilaCalendario que le pasemos.
	 *
	 * \param os Ostream donde guardaremos la informacion que queremos mostrar.
	 * \param pila TPilaCalendario que queremos mostrar.
	 *
	 * \return La funcion devuelve un ostream&.
	 */
	friend ostream& operator<<(ostream &, const TPilaCalendario &);
	
	public:
		
		/** \brief Constructor por defecto.
		 *
		 * Constructor por defecto que inicializa un TPilaCalendario vacio, de dimension 10.
		 */
		TPilaCalendario();
		
		/** \brief Destructor de la clase.
		 *
		 * Destructor de la clase, borra la memoria.
		 */
		~TPilaCalendario();
		
		/** \brief Constructor de copia.
		 *
		 * Constructor de copia de TPilaCalendario.
		 * \param pila TPilaCalendario desde el que copiamos a la nueva TPilaCalendario.
		 */
		TPilaCalendario(const TPilaCalendario&);
		
		/** \brief Sobrecarga del operador asignacion.
		 *
		 *
		 * Asignamos el contenido del parámetro al objeto que llama al método.
		 * \param pila TPilaCalendario del cual asignamos.
		 * \return Devuelve un TPilaCalendario&.
		 */
		TPilaCalendario& operator=(const TPilaCalendario&);
		
		/** \brief Método Apilar.
		 *
		 * Devuelve true si se apila correctamente el TCalendario que le pasamos por parámetro.
		 * \param cal TCalendario que vamos a apilar.
		 * \return Devuelve un bool.
		 */
		bool Apilar(const TCalendario&);
		
		/** \brief Método Desapilar.
		 *
		 * Devuelve true si se desapila correctamente el elemento de la cima de la pila.
		 * \return Devuelve un bool.
		 */
		bool Desapilar();
		
		/** \brief Sobrecarga del operador igualdad.
		 *
		 * Devuelve true si las dos TPilaCalendario son iguales.
		 * \param pila TPilaCalendario del cual comprobamos que es igual.
		 * \return Devuelve un bool.
		 */
		bool operator==(const TPilaCalendario&);
		
		/** \brief Sobrecarga del operador desigualdad.
		 *
		 * Devuelve true si las dos TPilaCalendario NO son iguales.
		 * \param pila TPilaCalendario del cual comprobamos que es distinta.
		 * \return Devuelve un bool.
		 */
		bool operator!=(const TPilaCalendario&);
		
		/** \brief Método EsVacia.
		 *
		 * Devuelve true si la pila está vacía.
		 * \return Devuelve un bool.
		 */
		bool EsVacia();
		
		/** \brief Método Cima.
		 *
		 * Devuelve el elemento TCalendario que ocupa la cima de la pila, si esta está vacía devuelve un TCalendario vacio.
		 * \return Devuelve un TCalendario.
		 */
		TCalendario Cima();
		
		/** \brief Método Longitud.
		 *
		 * Devuelve el número total de elementos en la pila.
		 * \return Devuelve un int.
		 */
		int Longitud()const;
		
		/** \brief Método NoVacios.
		 *
		 * Devuelve el número total de elementos en la pila no vacios.
		 * \return Devuelve un int.
		 */
		int NoVacios()const;
		
		/** \brief Sobrecarga del operador resta.
		 *
		 * Devuelve una pila nueva, hecha a partir de los elementos de la pila que llama al método y no están en la pila que le pasamos.
		 * \param pila TPilaCalendario del cual comprobamos que es igual.
		 * \return Devuelve un TPilaCalendario.
		 */
		TPilaCalendario operator-(const TPilaCalendario&);
	
	private:
	
		/** \brief TVectorCalendario v.
		 *
		 * Conforma la estructura interna de almacenamiento del TPilaCalendario.
		 */
		TVectorCalendario v;
		
		/** \brief Entero posicion.
		 *
		 * Indicará la posición del vector interno v dónde se encuentra la cima de la pila.
		 */
		int posicion;
	
};
#endif
